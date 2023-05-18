-- Euphoria 2.5
-- The Interpreter Back-End

-- This back-end is written in Euphoria. It uses the same front-end
-- as the official RDS Euphoria interpreter, and it executes the same IL
-- opcodes. Because it's written in Euphoria, this back-end is very 
-- simple, much simpler than the back-end used in the 
-- official RDS interpreter. 

-- Using the Euphoria to C Translator, or the Binder, you can convert 
-- this 100% Euphoria-coded interpreter into a .exe. The Translator 
-- will boost its speed considerably, though it will still be slower 
-- than the official RDS interpreter. The official interpreter has a 
-- carefully hand-coded back-end written in C.

include dll.e
include file.e
include global.e
include opnames.e
include misc.e as misc
include reswords.e as r
-- we handle these operations specially because they refer to routine ids
-- in the user program, not the interpreter itself. We can't just let 
-- Euphoria do the work.
constant M_CALL_BACK = 52,	
	 M_CRASH_ROUTINE = 66,
	 M_CRASH_MESSAGE = 37,
	 M_CRASH_FILE = 57
	 
constant C_MY_ROUTINE = 1,
	 C_USER_ROUTINE = 2,
	 C_NUM_ARGS = 3

object crash_msg
crash_msg = 0

-- begin mwl
integer in_trace
in_trace = 0
global sequence call_backs, call_back_code
-- end mwl
global symtab_index t_id, t_arglist, t_return_val, call_back_routine

-- mwl: made this global for embedding
global sequence crash_list  -- list of routine id's to call if there's a fatal crash
crash_list = {}

integer crash_count
crash_count = 0

-- only need one set of temps for call-backs
t_id = tmp_alloc()
t_arglist = tmp_alloc()
t_return_val = tmp_alloc()

-- dummy call-back routine
call_back_routine = NewEntry("_call_back_", 0, 0, r:PROC, 0, 0, 0)
SymTab[call_back_routine] = SymTab[call_back_routine] & 
			    repeat(0, SIZEOF_ROUTINE_ENTRY - 
			    length(SymTab[call_back_routine]))

call_back_code = {CALL_FUNC,
		  t_id,
		  t_arglist,
		  t_return_val,
		  CALL_BACK_RETURN
		 }

SymTab[call_back_routine][S_CODE] = call_back_code

integer TraceOn
TraceOn = FALSE

integer pc, a, b, c, d, target, len, keep_running
integer lhs_seq_index -- index of lhs sequence
sequence lhs_subs -- first n-1 LHS subscripts before final subscript or slice
global sequence val

sequence call_stack -- subroutine call stack

-- Stack Frames

-- 1. recursive call (routine is already active):

-- arg1 arg2 arg3 ... private1 private2 ... temp1 temp2 ... 
--                              ... previous_stack_size caller_pc current_sub

-- 2. non-recursive call:

-- previous_stack_size caller_pc current_sub

integer err_file
sequence err_file_name
err_file_name = "ex.err" 
err_file = -1
procedure open_err_file()
-- open ex.err  
	if err_file != -1 then
		return
	end if
	err_file = open(err_file_name, "w")
	if err_file = -1 then
	puts(2, "Can't open " & err_file_name & '\n')
	if debugger > 0 then
		c_proc( cleanup_cb, {} )
	end if
	abort(1)
	end if
end procedure

procedure both_puts(object s)
-- print to both screen and error file  
	if atom(crash_msg) then
	puts(2, s)
	end if
	puts(err_file, s)
end procedure

procedure both_printf(sequence format, sequence items)
-- print to both screen and error file  
	if atom(crash_msg) then
	printf(2, format, items)
	end if
	printf(err_file, format, items)
end procedure

-- begin mwl
function find_gline(symtab_index sub, integer pc)
-- return the file name and line that matches pc in sub
	sequence linetab, s
	integer line
	s = SymTab[sub]
	linetab = SymTab[sub][S_LINETAB]
	line = 1

	for i = 1 to length(linetab) do

		if linetab[i] >= pc or linetab[i] = -2 then

		    line = i-1
		    while line > 1 and linetab[line] = -1 do
				line -= 1
		    end while
		    exit
		end if
	end for

	return SymTab[sub][S_FIRSTLINE] + line - 1

end function
-- end mwl

function find_line(symtab_index sub, integer pc)
-- return the file name and line that matches pc in sub
	sequence linetab
	integer line, gline
	
	linetab = SymTab[sub][S_LINETAB]
	line = 1
	for i = 1 to length(linetab) do
		if linetab[i] >= pc or linetab[i] = -2 then
		    line = i-1
		    while line > 1 and linetab[line] = -1 do
				line -= 1
		    end while
		    exit
		end if
	end for
	gline = SymTab[sub][S_FIRSTLINE] + line - 1
	return {file_name[slist[gline][LOCAL_FILE_NO]], slist[gline][LINE]}
end function

procedure show_var(symtab_index x)
-- display a variable name and value
	
	puts(err_file, "    " & SymTab[x][S_NAME] & " = ")
	if equal(val[x], NOVALUE) then
	puts(err_file, "<no value>")
	else
	misc:pretty_print(err_file, val[x], 
	{1, 2, length(SymTab[x][S_NAME]) + 7, 78, "%d", "%.10g", 32, 127, 500})
	end if
	puts(err_file, '\n')
end procedure

global procedure dump_slist()
	integer fn
	fn = open("slist.txt", "w")
	for i = 1 to length(slist) do
		if sequence(slist[i]) then
			if atom(slist[i][SRC]) then
				slist[i][SRC] = fetch_line( slist[i][SRC] )
			end if
			print(fn, i & slist[i]) puts(fn, "\n")			
		end if
	end for
	close(fn)
end procedure

procedure trace_back(sequence msg)
-- display the call stack and variables after a crash
	symtab_index sub, v
	integer levels, prev_file_no, sp
	-- begin mwl
	integer gline
	-- end mwl
--dump_slist()

	levels = 1
	if atom(slist[$]) then
	slist = s_expand(slist)
	end if
	while length(call_stack) and TRUE do

		sub = call_stack[$]
		
		if levels = 1 then
		    puts(2, '\n')
		
		elsif sub != call_back_routine then
		    both_puts("... called from ")
		    -- pc points to statement after the subroutine call
		end if
	
		if sub = call_back_routine then
		    if crash_count > 0 then
				both_puts("^^^ called to handle run-time crash\n")
				exit
		    else
				both_puts("^^^ call-back from ")
				if EWINDOWS then
				    both_puts("Windows\n")
				else    
				    both_puts("external program\n")
				end if
		    end if
		
		else
		    both_printf("%s:%d ", find_line(sub, pc)) 

		    if not equal(SymTab[sub][S_NAME], "_toplevel_") then
				if SymTab[sub][S_TOKEN] = r:PROC then
				    both_puts("in procedure ")
				elsif SymTab[sub][S_TOKEN] = r:FUNC then
				    both_puts("in function ")
				elsif SymTab[sub][S_TOKEN] = TYPE then
				    both_puts("in type ")
				end if
	
				both_printf("%s()", {SymTab[sub][S_NAME]})
		    end if
	    
		    both_puts("\n")
	    
		    if levels = 1 then
				if sequence(crash_msg) then
				    clear_screen()
				    puts(2, crash_msg)
				end if
				both_puts(msg & '\n')
		    end if

		    if length(call_stack) < 2 then
				both_puts('\n')
				exit
		    end if

if 0 then
		    -- display parameters and private vars
		    v = SymTab[sub][S_NEXT]
		    sp = call_stack[$-2]+1
		    while v != 0 and 
			(SymTab[v][S_SCOPE] = SC_PRIVATE or 
			SymTab[v][S_SCOPE] = SC_LOOP_VAR) do
				show_var(v)
				if SymTab[sub][S_ACTIVE] > 1 then
				    -- recursive call, restore private var
				    val[v] = call_stack[sp]
				    sp += 1
				end if
				v = SymTab[v][S_NEXT]
		    end while
end if
		    SymTab[sub][S_ACTIVE] -= 1
		end if
	
		puts(err_file, '\n')

		-- stacked pc points to next statement after the call (so subtract 1)
		pc = call_stack[$-1] - 1
		call_stack = call_stack[1..call_stack[$-2]]
		levels += 1
	end while
	
	puts(2, "--> see " & err_file_name & '\n')
	
	puts(err_file, "\n\nGlobal & Local Variables\n")
	prev_file_no = -1
	v = SymTab[TopLevelSub][S_NEXT]
	while v do
		if SymTab[v][S_TOKEN] = VARIABLE and 
		   SymTab[v][S_MODE] = M_NORMAL and
		   find(SymTab[v][S_SCOPE], {SC_LOCAL, SC_GLOBAL, SC_GLOOP_VAR}) then
			    if SymTab[v][S_FILE_NO] != prev_file_no then
					prev_file_no = SymTab[v][S_FILE_NO]
					puts(err_file, "\n " & file_name[prev_file_no] & ":\n")
			    end if
			    show_var(v)
		end if
		v = SymTab[v][S_NEXT]
	end while
	
	-- begin mwl
	if full_debug and length(traced_lines) then
	puts( err_file, "\n\nTraced lines leading up to the failure:\n\n" )
	for i = 1 to length(traced_lines) do
		gline = traced_lines[i]
		if atom(slist[gline][SRC] ) then
			slist[gline][SRC] = fetch_line( slist[gline][SRC] )
		end if
		printf( err_file, "%s:%d\t%s\n", { file_name[slist[gline][LOCAL_FILE_NO]],
			slist[gline][LINE], slist[gline][SRC]})
	end for
	end if	  
	-- end mwl
	
	puts(err_file, '\n')
	close(err_file)
end procedure

-- begin mwl
-- made global so it can be used in callbacks.e
global integer forward_general_callback, forward_machine_callback

function call_crash_routines_for_real(sequence routine, sequence args)
-- call the user's function from an external source

	val[t_id] = routine[C_USER_ROUTINE]
	val[t_arglist] = args
	
	-- create a stack frame
	call_stack = call_stack & {length(call_stack), pc, call_back_routine} 

	Code = call_back_code 
	pc = 1 
	
	if EMBEDDED then
		call_proc( forward_eval_exec, {})
	else
		call_proc( forward_do_exec, {})
	end if
	
	
	-- remove the stack frame
	pc = call_stack[$-1]
	call_stack = call_stack[1..$-3]
	
	-- restore
	Code = SymTab[call_stack[$]][S_CODE]
	
	return val[t_return_val]
end function

include get.e
procedure call_crash_routines()
-- call all the routines in the crash list  
	object quit

	if crash_count > 0 then
	return
	end if
	
	crash_count += 1
	
	-- call them in reverse order
	err_file_name = "ex_crash.err"
	
	for i = length(crash_list) to 1 by -1 do
		-- do callback to get addr
		quit = call_func(forward_general_callback, 
				{{0, crash_list[i], 1}, {0}})
		if not equal(quit, 0) then
		    return -- don't call the others
		end if
	end for
end procedure
-- end mwl

procedure quit_after_error()
-- final termination    
	-- begin mwl
	if debugger > 0 then
		if cleanup_cb > 0 then
			c_proc( cleanup_cb, {})
		end if		
	end if

	-- end mwl
	if EWINDOWS then
	puts(2, "\nPress Enter...\n")
	if getc(0) then
	end if
	end if
	abort(1)
end procedure

procedure RTFatalType(integer x)
-- handle a fatal run-time type-check error 
	sequence msg, v
	sequence vname
	
	open_err_file()
	a = Code[x]
	vname = SymTab[a][S_NAME]
	msg = sprintf("type_check error\n%s is ", {vname}) 
	v = sprint(val[a])
	if length(v) > 70 - length(vname) then
	v = v[1..70 - length(vname)]
	while length(v) and not find(v[$], ",}")  do
	    v = v[1..$-1]
	end while
	v = v & " ..."
	end if
	trace_back(msg & v)
	call_crash_routines()

	quit_after_error()
end procedure

procedure RTFatal(sequence msg)
-- handle a fatal run-time error    

	-- begin mwl
	if find( 1, eval_stack ) then
		-- not really fatal...
		eval_error[$] = msg
		return
	end if
	-- end mwl

	open_err_file()
	trace_back(msg)
	call_crash_routines() 
	quit_after_error()

end procedure

procedure RTInternal(sequence msg)
-- Internal errors in back-end
	puts(2, '\n' & msg & '\n')
	? 1/0
end procedure

file trace_file
trace_file = -1

integer trace_line
trace_line = 0

procedure one_trace_line(sequence line)
-- write one fixed-width 79-char line to ctrace.out
	if ELINUX then
	printf(trace_file, "%-78.78s\n", {line})
	else
	printf(trace_file, "%-77.77s\r\n", {line})
	end if
end procedure

global procedure load_debugger()
	if platform() = DOS32 then
		debugger = 0
	elsif no_source = 0 or full_debug then
		
		debugger = open_dll(debugger_name)
		if debugger > 0 then
			-- debugger exists, so initialize it
			if platform() = LINUX  then
				update_vars = define_c_proc( debugger, "_1update_vars", {})
				debug_main = define_c_func( debugger, "_1initialize", {E_SEQUENCE, E_SEQUENCE}, E_ATOM )
				set_object_cb = define_c_proc( debugger, "_1set_object", {E_OBJECT})
				display_var_cb = define_c_proc( debugger, "_1display_var", {E_INTEGER})
				erase_privates_cb = define_c_proc( debugger, "_1erase_privates", {E_INTEGER})
				erase_symbol_cb = define_c_proc( debugger, "_1erase_symbol", {E_INTEGER})
				cleanup_cb = define_c_proc( debugger, "_1cleanup_debugger", {})
				hide_debugger = define_c_proc( debugger, "_1hide_debugger", {})
				get_object_cb = define_c_func( debugger, "_1get_object", {}, E_OBJECT )
				debug_out = define_c_proc( debugger, "_1debug_out", {E_OBJECT} )
			else
				update_vars = define_c_proc( debugger, "update_vars", {})
				debug_main = define_c_func( debugger, "initialize", {E_SEQUENCE, E_SEQUENCE}, E_ATOM )
				set_object_cb = define_c_proc( debugger, "set_object", {E_OBJECT})
				display_var_cb = define_c_proc( debugger, "display_var", {E_INTEGER})
				erase_privates_cb = define_c_proc( debugger, "erase_privates", {E_INTEGER})
				erase_symbol_cb = define_c_proc( debugger, "erase_symbol", {E_INTEGER})
				cleanup_cb = define_c_proc( debugger, "cleanup_debugger", {})
				hide_debugger = define_c_proc( debugger, "hide_debugger", {})
				get_object_cb = define_c_func( debugger, "get_object", {}, E_OBJECT )
				debug_out = define_c_proc( debugger, "debug_out", {E_OBJECT} )
			end if

			trace_func = define_c_proc( "", 
				c_func( debug_main, {{get_value_cb, get_symbols_cb, get_line_cb, 
					get_lines_cb, set_break_cb, get_files_cb, set_trace_cb, current_sub_cb,
					get_pc_cb, set_values_cb, set_debug_io_cb}, 
					source_name}), {E_INTEGER})

			if trace_func = -1 then
				debugger = 0
			end if
		else
			debugger = 0
			printf( 1, "debugger %s failed to open\n", {debugger_name} )
		end if
	end if
	-- end mwl
end procedure

procedure opSTARTLINE()
-- Start of a line. Use for diagnostics.
	-- begin mwl
	integer gline, sub
	-- end mwl
	sequence line
	integer w

	if TraceOn	= 3 then
		if trace_file = -1 then
		    trace_file = open("ctrace.out", "wb")
		    if trace_file = -1 then
			RTFatal("Couldn't open ctrace.out")
			return
		    end if
		end if

		a = Code[pc+1]
		
--		if atom(slist[a][SRC]) then
--			slist[a][SRC] = fetch_line( slist[a][SRC] )
--		end if

		if atom(slist[$]) then
			slist = s_expand(slist)
		end if
		line = sprintf("%.20s:%d\t%.80s",
			       {name_ext(file_name[slist[a][LOCAL_FILE_NO]]),
				slist[a][LINE],
				fetch_line(slist[a][SRC])})
		trace_line += 1
		if trace_line >= 500 then
		    -- wrap around to start of file
		    trace_line = 0
		    one_trace_line("")
		    one_trace_line("               ")
		    flush(trace_file)
		    if seek(trace_file, 0) then
		    end if
		end if
	
		one_trace_line(line)
		one_trace_line("")
		one_trace_line("=== THE END ===")
		one_trace_line("")
		one_trace_line("")
		one_trace_line("")
		flush(trace_file)
		w = where(trace_file)
		if seek(trace_file, w-79*5) then -- back up 5 lines
		end if

	end if  
	
	-- begin mwl
	sub = call_stack[$]

	gline = find_gline(sub, pc)
	if length(traced_lines) = 10 then
		traced_lines[1..9] = traced_lines[2..10]
		traced_lines[10] = gline
	else
		traced_lines &= gline
	end if

	if TraceOn and debugger = -1 then
		load_debugger()
	end if
	
	if debugger > 0 then
	if ((TraceOn and TraceOn < 3) or find( gline, break_points )) and in_trace < 2 then
		-- breakpoint:

		if not TraceOn then
			TraceOn = 1
		end if
		in_trace = 1
		c_proc( trace_func, {gline})
		in_trace = 0
	end if          
	end if
	-- end mwl
	pc += 2
end procedure

-- begin mwl

procedure pass_by_reference( integer sub )
	integer top
	object by_ref
	sequence arg_ref

	if length(call_stack) <= 3 then
		return
	end if

	sub = Code[pc+1]
	arg_ref = SymTab[sub][S_BYREF]
	by_ref = call_stack[$-3]
	if atom(by_ref) then
		return
	end if
	for i = 1 to length(by_ref) do
		if length(SymTab[by_ref[i]]) > 5 then
			val[by_ref[i]] = val[arg_ref[i]]
		end if
		
	end for

end procedure
-- end mwl

procedure opPROC()	
-- Normal subroutine call
	integer n, arg, sub, top
	-- begin mwl
	sequence by_ref, arg_ref
	by_ref = {}
	-- end mwl
	
	-- make a procedure or function/type call
	sub = Code[pc+1] -- subroutine
	arg = SymTab[sub][S_NEXT] 
	n = SymTab[sub][S_NUM_ARGS]
	SymTab[sub][S_ACTIVE] += 1
	top = length(call_stack)
	
	-- begin mwl
	arg_ref = SymTab[sub][S_BYREF]
	pass_by_reference( sub )
	-- end mwl
	
	if SymTab[sub][S_ACTIVE] > 1 then
		-- recursive: push the params, privates and temps
		--- save and set args
		for i = 1 to n do
		    call_stack = append(call_stack, val[arg])   
		    val[arg] = val[Code[pc+1+i]]
		    -- begin mwl
		    if find( arg, arg_ref ) then
		    	by_ref &= Code[pc+1+i]
		    end if
		    -- end mwl
		    
		    arg = SymTab[arg][S_NEXT]
		end for
		
		-- save privates
		while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
		    call_stack = append(call_stack, val[arg])   
		    val[arg] = NOVALUE  
		    arg = SymTab[arg][S_NEXT]
		end while
	
		-- save temps
		arg = SymTab[sub][S_TEMPS]
		while arg != 0 do
		    call_stack = append(call_stack, val[arg])   
		    val[arg] = NOVALUE
		    arg = SymTab[arg][S_NEXT]
		end while
		
		-- begin mwl
		-- save default goto info
		call_stack = append( call_stack, SymTab[sub][S_GOTO][G_DEFAULT] )
		-- end mwl
	else	
		-- non recursive, no need to push privates or temps
		-- copy args
		for i = 1 to n do
		    val[arg] = val[Code[pc+1+i]]
		    -- begin mwl
		    if find( arg, arg_ref ) then
		    	by_ref &= Code[pc+1+i]
		    end if
		    -- end mwl
		    arg = SymTab[arg][S_NEXT]
		end for
	end if
	
	-- begin mwl
	-- save the by_ref info
	call_stack = append( call_stack, by_ref )
	-- end mwl
	
	call_stack = append(call_stack, top)	

	pc = pc + 2 + n
	if SymTab[sub][S_TOKEN] != r:PROC then
		pc += 1
	end if
	
	call_stack = append(call_stack, pc) 
	call_stack = append(call_stack, sub)
	
	Code = SymTab[sub][S_CODE]
	pc = 1 
end procedure

integer result
result = 0
object result_val

procedure opRETURNP()	
-- return from procedure (or function)
	integer sub, arg, top, base
	-- begin mwl
	sequence by_ref, arg_ref
	--end mwl
	
	sub = Code[pc+1]
	arg = SymTab[sub][S_NEXT]
	SymTab[sub][S_ACTIVE] -= 1
	top = call_stack[$-2]
	
	-- begin mwl
	pass_by_reference( sub )
	-- end mwl
	
	if SymTab[sub][S_ACTIVE] > 0 then
		-- restore the parameters and privates
		base = top+1
		while arg and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
		    val[arg] = call_stack[base]
		    base += 1
		    arg = SymTab[arg][S_NEXT]
		end while
		
		-- restore the temps
		arg = SymTab[sub][S_TEMPS]
		while arg != 0 do
		    val[arg] = call_stack[base]
		    base += 1
		    arg = SymTab[arg][S_NEXT]
		end while
		
		-- begin mwl
		-- restore the goto default
		SymTab[sub][S_GOTO][G_DEFAULT] = call_stack[base]
		base += 1
		-- end mwl
	else
		-- don't restore the privates or temps
		-- but set privates to NOVALUE
		while arg and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
		    val[arg] = NOVALUE
		    arg = SymTab[arg][S_NEXT]
		end while
	
	end if
	
	pc = call_stack[$-1]
	call_stack = call_stack[1..top]
	
	Code = SymTab[call_stack[$]][S_CODE]
	
	if result then
	val[Code[result]] = result_val
	result = 0
	end if
end procedure

procedure opRETURNF()  
-- return from function
	result_val = val[Code[pc+2]]
	result = call_stack[$-1] - 1
	opRETURNP()
end procedure

procedure opCALL_BACK_RETURN()
-- force return from do_exec()
	keep_running = FALSE  
end procedure
		
procedure opBADRETURNF()  
-- shouldn't reach here
	RTFatal("attempt to exit a function without returning a value")  
	return
end procedure

procedure opRETURNT()	
-- return from top-level "procedure"
	pc += 1
	if pc > length(Code) then
	keep_running = FALSE  -- we've reached the end of the code
	end if
end procedure
	
procedure opRHS_SUBS() 
-- subscript a sequence to get the value of the element
-- RHS_SUBS_CHECK, RHS_SUBS, RHS_SUBS_I
	object sub, x
	
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	x = val[a]
	sub = val[b]
	if atom(x) then
	RTFatal("attempt to subscript an atom\n(reading from it)")
	return
	end if
	if sequence(sub) then
	RTFatal("subscript must be an atom\n(reading an element of a sequence)")
	return
	end if
	if sub < 1 or sub > length(x) then
	RTFatal(
	sprintf(
	"subscript value %d is out of bounds, reading from a sequence of length %d", 
	{sub, length(x)}))
	return
	end if
	val[target] = x[sub]
	pc += 4
end procedure
	
procedure opIF()
	a = Code[pc+1]
	if val[a] = 0 then
	pc = Code[pc+2]
	else
	pc += 3
	end if
end procedure
	    
procedure opINTEGER_CHECK()
	a = Code[pc+1]
	if not integer(val[a]) then
	RTFatalType(pc+1)
	return
	end if
	pc += 2
end procedure
	    
procedure opATOM_CHECK()
	a = Code[pc+1]
	if not atom(val[a]) then
	RTFatalType(pc+1)
	return
	end if
	pc += 2
end procedure
	      
procedure opSEQUENCE_CHECK()
	a = Code[pc+1]
	if not sequence(val[a]) then
	RTFatalType(pc+1)
	return
	end if
	pc += 2
end procedure

procedure opASSIGN()  
-- ASSIGN, ASSIGN_I 
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = val[a]
	pc += 3
end procedure
		
procedure opELSE()	
-- ELSE, EXIT, ENDWHILE 
-- mwl: GOTO_STATIC
	pc = Code[pc+1]
end procedure

procedure opRIGHT_BRACE()  -- form a sequence of any length 
	sequence x
	
	len = Code[pc+1]
	x = {}
	for i = pc+len+1 to pc+2 by -1 do
	-- last one comes first
	x = append(x, val[Code[i]])
	end for
	target = Code[pc+len+2]
	val[target] = x
	pc += 3 + len
end procedure
	    
--procedure opRIGHT_BRACE_N()  
-- form a sequence of any length 
--    sequence x
--    
--    len = Code[pc+1]
--    x = {}
--    for i = pc+len+1 to pc+2 by -1 do
--	-- last one comes first
--	x = append(x, val[Code[i]])
--    end for
--    target = Code[pc+len+2]
--    val[target] = x
--    pc += 3 + len
--end procedure

procedure opRIGHT_BRACE_2()   
-- form a sequence of length 2 (slightly faster than above)
	target = Code[pc+3]
	-- the second one comes first
	val[target] = {val[Code[pc+2]], val[Code[pc+1]]}
	pc += 4
end procedure

procedure opPLUS1() 
--PLUS1, PLUS1_I
	a = Code[pc+1]
	-- [2] is not used
	target = Code[pc+3] 
	val[target] = val[a] + 1
	pc += 4
end procedure
	
procedure opGLOBAL_INIT_CHECK()  
-- GLOBAL_INIT_CHECK, PRIVATE_INIT_CHECK 
	a = Code[pc+1]
	if equal(val[a], NOVALUE) then
	RTFatal("not initialized") -- ??
	return
	end if
	pc += 2
end procedure
	    
procedure opWHILE() 	
-- sometimes emit.c optimizes this away
	a = Code[pc+1]
	if val[a] = 0 then
	pc = Code[pc+2]
	else
	pc += 3
	end if
end procedure

function var_subs(object x, sequence subs)
-- subscript x with the list of subscripts in subs
	if atom(x) then
	RTFatal("attempt to subscript an atom\n(reading from it)")
	return 0
	end if
	for i = 1 to length(subs) do
	if subs[i] > length(x) or subs[i] < 1 then
	    RTFatal(
	    sprintf("subscript value %d is out of bounds, reading from a sequence of length %d",
		{subs[i], length(x)}))
		return 0
	end if
	x = x[subs[i]]
	end for
	return x
end function

function var_slice(object x, sequence subs, atom lower, atom upper)
-- slice x after subscripting a variable number of times
	if atom(x) then
	RTFatal("attempt to subscript an atom\n(reading from it)")
	return 0
	end if
	for i = 1 to length(subs) do
	if subs[i] > length(x) or subs[i] < 1 then
	    RTFatal(
	    sprintf("subscript value %d is out of bounds, reading from a sequence of length %d",
		{subs[i], length(x)}))
		return 0
	end if
	x = x[subs[i]] 
	end for
	return x[lower..upper]
end function

procedure opLENGTH()
-- operand should be a sequence 
object x
	a = Code[pc+1]
	target = Code[pc+2]

	if atom(val[a]) then
x = val[a]
	RTFatal("length of an atom is not defined")
	return
	end if
	val[target] = length(val[a])
	pc += 3
end procedure

-- Note: Multiple LHS subscripts, and $ within those subscripts,
-- is handled much more efficiently in the hand-coded C interpreter,
-- and in code translated to C, where C pointers can be used effectively.

procedure opPLENGTH()
-- Needed for some LHS uses of $. Operand should be a val index of a sequence,
-- with subscripts. 
	a = Code[pc+1]
	target = Code[pc+2]
	lhs_seq_index = val[a][1]
	lhs_subs = val[a][2..$]
	val[target] = length(var_subs(val[lhs_seq_index], lhs_subs))
	pc += 3
end procedure

procedure opLHS_SUBS() 
-- LHS = "Left Hand Side" of assignment
-- Handle one LHS subscript, when there are multiple LHS subscripts.
	
	a = Code[pc+1] -- base var sequence, or a temp that contains
		   -- {base index, subs1, subs2... so far}
	b = Code[pc+2] -- subscript
	target = Code[pc+3] -- temp for storing result
	
	-- a is a "pointer" to the result of previous subscripting
	val[target] = append(val[a], val[b])
	pc += 5
end procedure

procedure opLHS_SUBS1() 
-- Handle first LHS subscript, when there are multiple LHS subscripts.
	a = Code[pc+1] -- base var sequence, or a temp that contains
		   -- {base index, subs1, subs2... so far}
	b = Code[pc+2] -- subscript
	target = Code[pc+3] -- temp for storing result
	
	-- a is the base var
	val[target] = {a, val[b]}
	pc += 5
end procedure

procedure opLHS_SUBS1_COPY() 
-- Handle first LHS subscript, when there are multiple LHS subscripts.
-- In tricky situations (in the C-coded back-end) a copy of the sequence 
-- is made into a temp. 
	
	a = Code[pc+1] -- base var sequence
		   
	b = Code[pc+2] -- subscript
	
	target = Code[pc+3] -- temp for storing result
	
	c = Code[pc+4] -- temp to hold base sequence while it's manipulated
	
	val[c] = val[a]
	
	-- a is the base var
	val[target] = {c, val[b]}
	
	pc += 5
end procedure

procedure lhs_check_subs(object seq, object subs)
-- see if seq[subs] = ... is legal  
	if atom(seq) then
	RTFatal("attempt to subscript an atom\n(assigning to it)")
	return
	end if
	if sequence(subs) then
	RTFatal(
	sprintf(
	"subscript must be an atom\n(assigning to a sequence of length %d)",
	length(seq)))
	return
	end if
	if subs < 1 or subs > length(seq) then
	RTFatal(
	sprintf(
	"subscript value %d is out of bounds, assigning to a sequence of length %d",
	{subs, length(seq)}))
	return
	end if
end procedure

procedure lhs_check_slice(object seq, object lower, object upper, object rhs)
-- check for a valid assignment to a slice
	atom len
	
	if sequence(lower) then
	RTFatal("slice lower index is not an atom")
	return
	end if
	if lower < 1 then
	RTFatal("slice lower index is less than 1")
	return
	end if
	
	if sequence(upper) then
	RTFatal("slice upper index is not an atom")
	return
	end if
	if upper < 0 then
	RTFatal("slice upper index is less than 0")
	return
	end if
	
	len = upper - lower + 1
	
	if len < 0 then
	RTFatal("slice length is less than 0")
	return
	end if
	
	if sequence(rhs) and length(rhs) != len then
	RTFatal("lengths do not match on assignment to slice")
	return
	end if

	if atom(seq) then
	RTFatal("attempt to slice an atom")
	return
	end if
	
	if lower > length(seq) + 1 or (len > 0 and lower > length(seq)) then
	RTFatal("slice starts past end of sequence")
	return
	end if
	
	if upper > length(seq) then
	RTFatal("slice ends past end of sequence")
	return
	end if
end procedure

function assign_subs(sequence x, sequence subs, object rhs_val)
-- assign a value to a subscripted sequence (any number of subscripts >= 1)
	lhs_check_subs(x, subs[1])
	if length(subs) = 1 then
	x[subs[1]] = rhs_val
	else
	x[subs[1]] = assign_subs(x[subs[1]], subs[2..$], rhs_val)
	end if
	return x
end function			

function assign_slice(sequence x, sequence subs, atom lower, atom upper, object rhs_val)
-- assign a value to a subscripted/sliced sequence 
-- (any number of subscripts >= 1, then one slice)
	-- should check slice too
	lhs_check_subs(x, subs[1])
	if length(subs) = 1 then
	lhs_check_slice(x[subs[1]],lower,upper,rhs_val)
	x[subs[1]][lower..upper] = rhs_val
	else
	x[subs[1]] = assign_slice(x[subs[1]], subs[2..$], lower, upper, rhs_val)
	end if
	return x
end function			

procedure opASSIGN_SUBS() -- also ASSIGN_SUBS_CHECK, ASSIGN_SUBS_I
-- LHS single subscript and assignment
	object x, subs

	a = Code[pc+1]	-- the sequence
	b = Code[pc+2]	-- the subscript
	if sequence(val[b]) then
	RTFatal("subscript must be an atom\n(assigning to subscript of a sequence)")
	return
	end if
	c = Code[pc+3]	-- the RHS value
	x = val[a] -- avoid lingering ref count on val[a]
	lhs_check_subs(x, val[b])
	x = val[c]
	subs = val[b]
	val[a][subs] = x  -- single LHS subscript
	pc += 4
end procedure

procedure opPASSIGN_SUBS()
-- final LHS subscript and assignment after a series of subscripts
	a = Code[pc+1]
	b = Code[pc+2]	-- subscript
	if sequence(val[b]) then
	RTFatal("subscript must be an atom\n(assigning to subscript of a sequence)")        
	return
	end if
	c = Code[pc+3]	-- RHS value
	
	-- multiple LHS subscript case
	lhs_seq_index = val[a][1]
	lhs_subs = val[a][2..$]    
	val[lhs_seq_index] = assign_subs(val[lhs_seq_index], 
					 lhs_subs & val[b], 
					 val[c])
	pc += 4
end procedure

procedure opASSIGN_OP_SUBS()  
-- var[subs] op= expr
	object x
	
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	-- var with one subscript
	lhs_subs = {}
	x = val[a]
	val[target] = var_subs(x, lhs_subs & val[b])
	pc += 4
end procedure

procedure opPASSIGN_OP_SUBS()  
-- var[subs] ... [subs] op= expr
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	-- temp with multiple subscripts
	lhs_seq_index = val[a][1]
	lhs_subs = val[a][2..$]
	Code[pc+9] = Code[pc+1] -- patch upcoming op
	val[target] = var_subs(val[lhs_seq_index], lhs_subs & val[b])
	pc += 4
end procedure

procedure opASSIGN_OP_SLICE()  
-- var[i..j] op= expr
	object x

	a = Code[pc+1]
	x = val[a]
	b = Code[pc+2]
	if val[b] > length(x) or val[b] < 1 then
	RTFatal(
	sprintf("subscript value %d is out of bounds, reading from a sequence of length %d",
		{val[b], length(x)}))
	return
	end if
	c = Code[pc+3]
	target = Code[pc+4]
	val[target] = var_slice(x, {}, val[b], val[c])
	pc += 5
end procedure


procedure opPASSIGN_OP_SLICE()
-- var[subs] ... [i..j] op= expr
    object x

    a = Code[pc+1]
    x = val[a]
    b = Code[pc+2]
    c = Code[pc+3]
    target = Code[pc+4]
    lhs_seq_index = x[1]
    lhs_subs = x[2..$]
    Code[pc+10] = Code[pc+1]
    val[target] = var_slice(val[lhs_seq_index], lhs_subs, val[b], val[c])
    pc += 5
end procedure

    
procedure opASSIGN_SLICE()	 
-- var[i..j] = expr
	object x
	
	a = Code[pc+1]	-- sequence
	b = Code[pc+2]	-- 1st index
	c = Code[pc+3]	-- 2nd index
	d = Code[pc+4]	-- rhs value to assign
	
	x = val[a] -- avoid lingering ref count on val[a]
	lhs_check_slice(x,val[b],val[c],val[d])
	x = val[d]
	val[a][val[b]..val[c]] = x
	pc += 5
end procedure

procedure opPASSIGN_SLICE()   
-- var[x] ... [i..j] = expr
	a = Code[pc+1]	-- sequence
	b = Code[pc+2]	-- 1st index
	c = Code[pc+3]	-- 2nd index
	d = Code[pc+4]	-- rhs value to assign
	
	lhs_seq_index = val[a][1]
	lhs_subs = val[a][2..$]
	val[lhs_seq_index] = assign_slice(val[lhs_seq_index],
				      lhs_subs,
				      val[b], val[c], val[d])
	pc += 5
end procedure

procedure opRHS_SLICE() 
-- rhs slice of a sequence a[i..j] 
	object x
	
	a = Code[pc+1]	-- sequence
	b = Code[pc+2]	-- 1st index
	c = Code[pc+3]	-- 2nd index
	target = Code[pc+4]  
	x = val[a]
	val[target] = x[val[b]..val[c]]   -- need checks here!
	pc += 5
end procedure

procedure opTYPE_CHECK() 
-- type check for a user-defined type
-- this always follows a type-call
	if val[Code[pc-1]] = 0 then
	RTFatalType(pc-2)
	return
	end if
	pc += 1
end procedure
	    
procedure opIS_AN_INTEGER()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = integer(val[a])
	pc += 3
end procedure

procedure opIS_AN_ATOM()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = atom(val[a])
	pc += 3
end procedure
		
procedure opIS_A_SEQUENCE() 
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = sequence(val[a])
	pc += 3
end procedure
	    
procedure opIS_AN_OBJECT()
	target = Code[pc+2]
	val[target] = 1
	pc += 3
end procedure
		
	-- ---------- start of unary ops ----------------- 

procedure opSQRT() 
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = sqrt(val[a])
	pc += 3
end procedure

procedure opSIN()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = sin(val[a])
	pc += 3
end procedure

procedure opCOS()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = cos(val[a])
	pc += 3
end procedure

procedure opTAN()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = tan(val[a])
	pc += 3
end procedure

procedure opARCTAN()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = arctan(val[a])
	pc += 3
end procedure

procedure opLOG()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = log(val[a])
	pc += 3
end procedure

procedure opNOT_BITS()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = not_bits(val[a])
	pc += 3
end procedure

procedure opFLOOR()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = floor(val[a])
	pc += 3
end procedure

procedure opNOT_IFW()
	a = Code[pc+1]
	if val[a] = 0 then
	pc += 3
	else
	pc = Code[pc+2]
	end if
end procedure
	    
procedure opNOT()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = not val[a]
	pc += 3
end procedure
	    
procedure opUMINUS()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = -val[a]
	pc += 3
end procedure
	    
procedure opRAND()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = rand(val[a])
	pc += 3
end procedure
	    
procedure opDIV2()	
-- like unary op, but pc+=4
	a = Code[pc+1]
	-- Code[pc+2] not used
	target = Code[pc+3]
	val[target] = val[a] / 2
	pc += 4 
end procedure
	    
procedure opFLOOR_DIV2()
	a = Code[pc+1]
	-- Code[pc+2] not used
	target = Code[pc+3]
	val[target] = floor(val[a] / 2)
	pc += 4 
end procedure
		
	----------- start of binary ops ----------
	    
procedure opGREATER_IFW()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] > val[b] then
	pc += 4
	else
	pc = Code[pc+3]
	end if
end procedure
	
procedure opNOTEQ_IFW()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] != val[b] then
	pc += 4
	else
	pc = Code[pc+3]
	end if
end procedure
	
procedure opLESSEQ_IFW()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] <= val[b] then
	pc += 4
	else
	pc = Code[pc+3]
	end if
end procedure
	
procedure opGREATEREQ_IFW()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] >= val[b] then
	pc += 4
	else
	pc = Code[pc+3]
	end if
end procedure
	
procedure opEQUALS_IFW()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] = val[b] then
	pc += 4
	else
	pc = Code[pc+3]
	end if
end procedure
	
procedure opLESS_IFW()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] < val[b] then
	pc += 4
	else
	pc = Code[pc+3]
	end if
end procedure
	    
	-- other binary ops
	
procedure opMULTIPLY()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] * val[b]
	pc += 4
end procedure
	    
procedure opPLUS() 
-- PLUS, PLUS_I
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] + val[b]
	pc += 4
end procedure
	
procedure opMINUS() 
-- MINUS, MINUS_I
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] - val[b]
	pc += 4
end procedure
	    
procedure opOR()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] or val[b]
	pc += 4
end procedure
	
procedure opXOR()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] xor val[b]
	pc += 4
end procedure
	
procedure opAND()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] and val[b]
	pc += 4
end procedure
	    
procedure opDIVIDE()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	if equal(val[b], 0) then
	RTFatal("attempt to divide by 0")
	return
	end if
	val[target] = val[a] / val[b]
	pc += 4
end procedure

procedure opREMAINDER()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	if equal(val[b], 0) then
	RTFatal("Can't get remainder of a number divided by 0")
	return
	end if
	val[target] = remainder(val[a], val[b])
	pc += 4
end procedure
	    
procedure opFLOOR_DIV()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	if equal(val[b], 0) then
	RTFatal("attempt to divide by 0")
	return
	end if
	val[target] = floor(val[a] / val[b])
	pc += 4
end procedure
	    
procedure opAND_BITS()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = and_bits(val[a], val[b])
	pc += 4
end procedure
	
procedure opOR_BITS()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = or_bits(val[a], val[b])
	pc += 4
end procedure
	
procedure opXOR_BITS()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = xor_bits(val[a], val[b])
	pc += 4
end procedure
	    
procedure opPOWER()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = power(val[a], val[b])
	pc += 4
end procedure
	    
procedure opLESS()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] < val[b]
	pc += 4
end procedure
	
procedure opGREATER()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] > val[b]
	pc += 4
end procedure
	
procedure opEQUALS()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] = val[b]
	pc += 4
end procedure
	
procedure opNOTEQ()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] != val[b]
	pc += 4
end procedure
	
procedure opLESSEQ()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] <= val[b]
	pc += 4
end procedure
	
procedure opGREATEREQ()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] >= val[b]
	pc += 4
end procedure
	    
-- short-circuit ops 

procedure opSC1_AND()
	a = Code[pc+1]
	b = Code[pc+2]
	if atom(val[a]) then
	if val[a] = 0 then
	    val[b] = 0
	    pc = Code[pc+3]
	    return
	end if
	else
	RTFatal("true/false condition must be an ATOM")
	return
	end if
	pc += 4
end procedure

procedure opSC1_AND_IF() 
-- no need to store 0   
	a = Code[pc+1]
	b = Code[pc+2]
	if atom(val[a]) then
	if val[a] = 0 then
	    pc = Code[pc+3]
	    return
	end if
	else
	RTFatal("true/false condition must be an ATOM")
	return
	end if
	pc += 4
end procedure

procedure opSC1_OR()
	a = Code[pc+1]
	b = Code[pc+2]
	if atom(val[a]) then
	if val[a] != 0 then
	    val[b] = 1
	    pc = Code[pc+3]
	    return
	end if
	else
	RTFatal("true/false condition must be an ATOM")
	return
	end if
	pc += 4
end procedure
		
procedure opSC1_OR_IF()
-- no need to store 1
	a = Code[pc+1]
	b = Code[pc+2]
	if atom(val[a]) then
	if val[a] != 0 then
	    val[b] = 1
	    pc = Code[pc+3]
	    return
	end if
	else
	RTFatal("true/false condition must be an ATOM")
	return
	end if
	pc += 4
end procedure
		
procedure opSC2_OR() 
-- SC2_OR,  SC2_AND 
-- short-circuit op
	a = Code[pc+1]
	b = Code[pc+2]
	if atom(val[a]) then
	val[b] = val[a] 
	else
	RTFatal("true/false condition must be an ATOM")
	return
	end if
	pc += 3
end procedure

-- for loops 
	    
procedure opFOR()  
-- FOR, FOR_I 
-- enter into a for loop    
	integer increment, limit, initial, loopvar, jump
	
	increment = Code[pc+1]
	limit = Code[pc+2]
	initial = Code[pc+3]
	-- ignore current_sub = Code[pc+4] - we don't patch the ENDFOR
	-- so recursion is not a problem
	loopvar = Code[pc+5]
	jump = Code[pc+6]
	
	if sequence(val[initial]) then
	RTFatal("for-loop variable is not an atom")
	return
	end if
	if sequence(val[limit]) then
	RTFatal("for-loop limit is not an atom")
	return
	end if
	if sequence(val[increment]) then
	RTFatal("for-loop increment is not an atom")
	return
	end if
	
	pc += 7 -- to enter into the loop
	
	if val[increment] >= 0 then
	-- going up
	if val[initial] > val[limit] then
	    pc = jump -- quit immediately, 0 iterations
	end if
	else
	-- going down
	if val[initial] < val[limit] then
	    pc = jump -- quit immediately, 0 iterations
	end if
	end if

	val[loopvar] = val[initial] -- initialize loop var
	
end procedure

procedure opENDFOR_GENERAL() 
-- ENDFOR_INT_UP, ENDFOR_UP, ENDFOR_INT_DOWN1,
-- ENDFOR_INT_DOWN, ENDFOR_DOWN, ENDFOR_GENERAL
-- end of for loop: drop out of the loop, or go back to the top
	integer loopvar
	atom increment, limit, next
	
	limit = val[Code[pc+2]]
	increment = val[Code[pc+4]]
	loopvar = Code[pc+3]
	next = val[loopvar] + increment
	
	if increment >= 0 then
	-- up loop
	if next > limit then
	    pc += 5 -- exit loop
	else
	    val[loopvar] = next
	    pc = Code[pc+1] -- loop again
	end if
	else	
	-- down loop
	if next < limit then
	    pc += 5 -- exit loop
	else
	    val[loopvar] = next
	    pc = Code[pc+1] -- loop again
	end if
	end if
end procedure

procedure opENDFOR_INT_UP1() 
-- ENDFOR_INT_UP1
-- faster: end of for loop with known +1 increment
-- exit or go back to the top
-- (loop var might not be integer, but that doesn't matter here)
	integer loopvar
	atom limit, next
	
	limit = val[Code[pc+2]]
	loopvar = Code[pc+3]
	next = val[loopvar] + 1
	
	-- up loop
	if next > limit then
	pc += 5 -- exit loop
	else
	val[loopvar] = next
	pc = Code[pc+1] -- loop again
	end if
end procedure

function RTLookup(sequence name, integer file, symtab_index proc, integer stlen)
-- Look up a name (routine or var) in the symbol table at runtime.
--   The name must have been defined earlier in the source than
--   where we are currently executing. The name may be a simple "name"
--   or "ns:name". Speed is not too critical. This lookup is only used 
--   in interactive trace mode, and in looking up routine id's, 
--   which should normally only be done once for an indirectly-callable 
--   routine.
	symtab_index s, global_found
	integer colon, stop
	integer p
	integer ns
	integer ns_file

	if proc = 0 then
	return 0
	end if
	
	-- don't look further than you'd be allowed to at compile-time:
	-- begin mwl
	-- added for eval...
	if proc = TopLevelSub or proc = eval_sym then 	
		stop = 0
	else
		stop = SymTab[proc][S_NEXT]
	end if
	-- end mwl
	colon = find(':', name)
	
	if colon then
	-- look up "ns : name"
	
	-- trim off any trailing whitespace from ns
	p = colon-1
	while p >= 1 and (name[p] = ' ' or name[p] = '\t') do
	    p -= 1
	end while
	name = name[1..p] 
	
	ns = 1
	
	-- trim off any leading whitespace from ns
	while ns <= length(name) and (name[ns] = ' ' or name[ns] = '\t') do
	    ns += 1
	end while
	
	if ns > length(name) then
	    return 0
	end if

	-- step 1: look up NAMESPACE symbol 
	s = SymTab[TopLevelSub][S_NEXT]
	-- begin mwl
	while s != stop and length( SymTab[s] ) >= S_NEXT do
	-- end mwl
	    if file = SymTab[s][S_FILE_NO] and 
		SymTab[s][S_TOKEN] = NAMESPACE and 
		equal(ns, SymTab[s][S_NAME]) then
		exit
	    end if
	    s = SymTab[s][S_NEXT]
	end while
	
	if s = 0 then
	    return 0
	end if
	
	ns_file = SymTab[s][S_OBJ]
	
	name = name[colon+1..$]
	
	-- trim off any leading whitespace from name
	while length(name) and (name[1] = ' ' or name[1] = '\t') do
	    name = name[2..$]
	end while
	
	-- find global name in ns file 
	s = SymTab[TopLevelSub][S_NEXT]
	while s != stop do
	    if SymTab[s][S_FILE_NO] = ns_file and 
		SymTab[s][S_SCOPE] = SC_GLOBAL and 
		equal(name, SymTab[s][S_NAME]) then
		return s
	    end if
	    s = SymTab[s][S_NEXT]
	end while
	return 0
	
	else 
	-- look up simple unqualified routine name

	if proc != TopLevelSub then  
	    -- inside a routine - check PRIVATEs and LOOP_VARs
	    s = SymTab[proc][S_NEXT]
	    while s and (SymTab[s][S_SCOPE] = SC_PRIVATE or 
			 SymTab[s][S_SCOPE] = SC_LOOP_VAR) do
		if equal(name, SymTab[s][S_NAME]) then
		    return s           
		end if
		s = SymTab[s][S_NEXT]
	    end while
	end if

	-- try to match a LOCAL or GLOBAL routine in the same source file
	s = SymTab[TopLevelSub][S_NEXT]
	-- begin mwl
	while s != stop and length(SymTab[s]) >= S_NEXT do
	-- end mwl
	    if SymTab[s][S_FILE_NO] = file and 
		(SymTab[s][S_SCOPE] = SC_LOCAL or 
		 SymTab[s][S_SCOPE] = SC_GLOBAL or 
		(proc = TopLevelSub and SymTab[s][S_SCOPE] = SC_GLOOP_VAR)) and
			equal(name, SymTab[s][S_NAME]) then  
			-- shouldn't really be able to see GLOOP_VARs unless we are
			-- currently inside the loop - only affects interactive var display
			return s
	    end if
	    s = SymTab[s][S_NEXT]
	end while 
	
	-- try to match a single earlier GLOBAL symbol
	global_found = FALSE
	s = SymTab[TopLevelSub][S_NEXT]
	-- begin mwl
	while s != stop and length(SymTab[s]) >= S_NEXT do
	-- end mwl
	    if SymTab[s][S_SCOPE] = SC_GLOBAL and 
	       equal(name, SymTab[s][S_NAME]) then
		if not global_found then
		    global_found = s
		else
		    return 0 -- 2nd global with same name
		end if
	    end if
	    s = SymTab[s][S_NEXT]
	end while 
	return global_found
	
	end if
end function

function RTLookupVar(sequence name, integer file, symtab_index proc, integer stlen)
-- Look up a name (routine or var) in the symbol table at runtime.
--   The name must have been defined earlier in the source than
--   where we are currently executing. The name may be a simple "name"
--   or "ns:name". Speed is not too critical. This lookup is only used 
--   in interactive trace mode, and in looking up routine id's, 
--   which should normally only be done once for an indirectly-callable 
--   routine.
	symtab_index s, global_found
	integer colon, stop
	integer p
	integer ns
	integer ns_file

	if proc = 0 then
	return 0
	end if
	

	-- begin mwl
	-- allow forward variable referencing
	-- if not, the you couldn't see stuff created by eval...
	-- Besides, why not?  It doesn't have to be RDS compatible.
	stop = 0
	-- end mwl
	colon = find(':', name)
	
	if colon then
	-- look up "ns : name"
	
	-- trim off any trailing whitespace from ns
	p = colon-1
	while p >= 1 and (name[p] = ' ' or name[p] = '\t') do
	    p -= 1
	end while
	name = name[1..p] 
	
	ns = 1
	
	-- trim off any leading whitespace from ns
	while ns <= length(name) and (name[ns] = ' ' or name[ns] = '\t') do
	    ns += 1
	end while
	
	if ns > length(name) then
	    return 0
	end if

	-- step 1: look up NAMESPACE symbol 
	s = SymTab[TopLevelSub][S_NEXT]
	-- begin mwl
	while s != stop and length( SymTab[s] ) >= S_NEXT do
	-- end mwl
	    if file = SymTab[s][S_FILE_NO] and 
		SymTab[s][S_TOKEN] = NAMESPACE and 
		equal(ns, SymTab[s][S_NAME]) then
		exit
	    end if
	    s = SymTab[s][S_NEXT]
	end while
	
	if s = 0 then
	    return 0
	end if
	
	ns_file = SymTab[s][S_OBJ]
	
	name = name[colon+1..$]
	
	-- trim off any leading whitespace from name
	while length(name) and (name[1] = ' ' or name[1] = '\t') do
	    name = name[2..$]
	end while
	
	-- find global name in ns file 
	s = SymTab[TopLevelSub][S_NEXT]
	while s != stop do
	    if SymTab[s][S_FILE_NO] = ns_file and 
		SymTab[s][S_SCOPE] = SC_GLOBAL and 
		equal(name, SymTab[s][S_NAME]) then
		return s
	    end if
	    s = SymTab[s][S_NEXT]
	end while
	return 0
	
	else 
	-- look up simple unqualified routine name

	if proc != TopLevelSub then  

	    -- inside a routine - check PRIVATEs and LOOP_VARs
	    s = SymTab[proc][S_NEXT]
	    while s and (SymTab[s][S_SCOPE] = SC_PRIVATE or 
			 SymTab[s][S_SCOPE] = SC_LOOP_VAR) do
		if equal(name, SymTab[s][S_NAME]) then
		    return s           
		end if
		s = SymTab[s][S_NEXT]
	    end while
	end if

	-- try to match a LOCAL or GLOBAL routine in the same source file
	s = SymTab[TopLevelSub][S_NEXT]
	-- begin mwl
	while s != stop and length(SymTab[s]) >= S_NEXT do

	    if (SymTab[s][S_FILE_NO] = file or SymTab[s][S_FILE_NO] = eval_file) and 
	-- end mwl
		(SymTab[s][S_SCOPE] = SC_LOCAL or 
		 SymTab[s][S_SCOPE] = SC_GLOBAL or 
		(proc = TopLevelSub and SymTab[s][S_SCOPE] = SC_GLOOP_VAR)) and
			equal(name, SymTab[s][S_NAME]) then  
			-- shouldn't really be able to see GLOOP_VARs unless we are
			-- currently inside the loop - only affects interactive var display

			return s
	    end if
	    s = SymTab[s][S_NEXT]
	end while 
	
	-- try to match a single earlier GLOBAL symbol
	global_found = FALSE
	s = SymTab[TopLevelSub][S_NEXT]
	-- begin mwl
	while s != stop and length(SymTab[s]) >= S_NEXT do
	-- end mwl
	    if SymTab[s][S_SCOPE] = SC_GLOBAL and 
	       equal(name, SymTab[s][S_NAME]) then
		if not global_found then
		    global_found = s
		else
		    return 0 -- 2nd global with same name
		end if
	    end if
	    s = SymTab[s][S_NEXT]
	end while 

	return global_found
	
	end if
end function

-- mwl: made e_routine global
global sequence e_routine -- list of routines with a routine id assigned to them
e_routine = {}

procedure opCALL_PROC() 
-- CALL_PROC, CALL_FUNC - call via routine id
	integer cf, top, n, arg
	symtab_index sub
	-- begin mwl
	sequence by_ref, arg_ref
	-- end mwl

	cf = Code[pc] = CALL_FUNC
	top = length(call_stack)
	
	a = Code[pc+1]	-- routine id
	if val[a] < 0 or val[a] >= length(e_routine) then
		RTFatal("invalid routine id")
		return
	end if

	sub = e_routine[val[a]+1]
	b = Code[pc+2]	-- argument list
		
	if cf then
		if SymTab[sub][S_TOKEN] = r:PROC then
		    RTFatal(sprintf("%s() does not return a value", SymTab[sub][S_NAME]))
		    return
		end if
	else
		if SymTab[sub][S_TOKEN] != r:PROC then
		    RTFatal(sprintf("the value returned by %s() must be assigned or used",
				    SymTab[sub][S_NAME]))
			return
		end if
	end if
	if atom(val[b]) then
		RTFatal("argument list must be a sequence")
		return
	end if
	
	if SymTab[sub][S_NUM_ARGS] != length(val[b]) then
		RTFatal(sprintf("call to %s() via routine-id should pass %d arguments, not %d",
			{SymTab[sub][S_NAME], SymTab[sub][S_NUM_ARGS], length(val[b])}))
		 return
	end if

	-- begin mwl
	by_ref = {}
--	pass_by_reference( sub )
--	arg_ref = SymTab[sub][S_BYREF]
	-- end mwl
	
	n = SymTab[sub][S_NUM_ARGS]
	arg = SymTab[sub][S_NEXT]
	SymTab[sub][S_ACTIVE] += 1
	
	if SymTab[sub][S_ACTIVE] > 1 then
		-- recursive: push the params, privates and temps
		for i = 1 to n do
		    call_stack = append(call_stack, val[arg])
		    val[arg] = val[b][i]
		    -- begin mwl
--		    if find( arg, arg_ref ) then
--		    	by_ref &= Code[pc+1+i]
--		    end if
		    -- end mwl
		    arg = SymTab[arg][S_NEXT]
		end for
		
		-- save the privates
		while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
		    call_stack = append(call_stack, val[arg])
		    val[arg] = NOVALUE
		    arg = SymTab[arg][S_NEXT]
		end while
		
		-- save temps
		arg = SymTab[sub][S_TEMPS]
		while arg != 0 do
		    call_stack = append(call_stack, val[arg])
		    val[arg] = NOVALUE
		    arg = SymTab[arg][S_NEXT]
		end while

		-- begin mwl
		-- save default goto info
		call_stack = append( call_stack, SymTab[sub][S_GOTO][G_DEFAULT] )
		-- end mwl
		
	else
		-- don't push
		-- save and copy the args
		for i = 1 to n do

		    val[arg] = val[b][i]
		    -- begin mwl
--		    if find( arg, arg_ref ) then
--		    	by_ref &= Code[pc+1+i]
--		    end if
		    -- end mwl
		    arg = SymTab[arg][S_NEXT]
		end for
	end if

	-- begin mwl
	-- save the by_ref info
	call_stack = append( call_stack, by_ref )
	-- end mwl	

	call_stack = append(call_stack, top)	

	pc += 3 + cf
	
	call_stack = append(call_stack, pc) 
	call_stack = append(call_stack, sub)
	
	Code = SymTab[sub][S_CODE]
	pc = 1
end procedure

procedure opROUTINE_ID()
-- get the routine id for a routine name    
-- routine id's start at 0 (for compatibility with C-coded back-end)
	integer sub, fn, p, stlen
	object name

	sub = Code[pc+1]   -- CurrentSub
	stlen = Code[pc+2]	-- s.t. length
	name = val[Code[pc+3]]	-- routine name sequence
	fn = Code[pc+4]    -- file number
	target = Code[pc+5]
	pc += 6
	if atom(name) then
		val[target] = -1
		return
	end if
	p = RTLookup(name, fn, sub, stlen)
	if p = 0 or not find(SymTab[p][S_TOKEN], {r:PROC, r:FUNC, TYPE}) 
	-- begin mwl
	or (not FORWARD_ROUTINE_ID and p > stlen )
	-- end mwl
	then
		val[target] = -1  -- name is not a routine
		return
	end if
	for i = 1 to length(e_routine) do
		if e_routine[i] = p then
		    val[target] = i - 1 -- routine was already assigned an id
		    return
		end if
	end for 
	e_routine = append(e_routine, p)
	val[target] = length(e_routine) - 1
end procedure
	    
procedure opAPPEND()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = append(val[a], val[b])
	pc += 4
end procedure

procedure opPREPEND() 
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = prepend(val[a], val[b])
	pc += 4
end procedure

procedure opCONCAT()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = val[a] & val[b]
	pc += 4
end procedure
	    
procedure opCONCAT_N()
-- concatenate 3 or more items
	integer n
	object x
	
	n = Code[pc+1] -- number of items
	-- operands are in reverse order
	x = val[Code[pc+2]] -- last one
	for i = pc+3 to pc+n+1 do
		x = val[Code[i]] & x
	end for
	target = Code[pc+n+2]
	val[target] = x
	pc += n+3
end procedure
	    
procedure opREPEAT()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = repeat(val[a], val[b])
	pc += 4
end procedure

procedure opDATE()
	target = Code[pc+1]
	val[target] = date()
	pc += 2
end procedure

procedure opTIME()
	target = Code[pc+1]
	val[target] = time()
	pc += 2
end procedure

procedure opSPACE_USED() -- RDS DEBUG only
	pc += 2
end procedure

procedure opNOP2()	 
-- space filler
	pc+= 2
end procedure

procedure opPOSITION()
	a = Code[pc+1]
	b = Code[pc+2]
	position(val[a], val[b])  -- error checks
	pc += 3
end procedure
	    
procedure opEQUAL()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = equal(val[a], val[b])
	pc += 4
end procedure
		
procedure opCOMPARE()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = compare(val[a], val[b])
	pc += 4
end procedure

procedure opFIND()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = find(val[a], val[b])
	pc += 4
end procedure

-- begin mwl
procedure opFIND_FROM()
	sequence s

	c = val[Code[pc+3]]
	target = Code[pc+4]
	s = val[Code[pc+2]][c..$]
	b = find( val[Code[pc+1]], s )
	if b then
		b += c - 1
	end if
	val[target] = b
	pc += 5
end procedure

procedure opMATCH_FROM()
	sequence s

	c = val[Code[pc+3]]
	target = Code[pc+4]
	s = val[Code[pc+2]][c..$]
	b = match( val[Code[pc+1]], s )
	if b then
		b += c - 1
	end if
	val[target] = b
	pc += 5
end procedure

-- end mwl

procedure opMATCH()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = match(val[a], val[b])
	pc += 4
end procedure

procedure opPEEK4U()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = peek4u(val[a])
	pc += 3
end procedure
	
procedure opPEEK4S()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = peek4s(val[a])
	pc += 3
end procedure
	
procedure opPEEK()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = peek(val[a])
	pc += 3
end procedure

procedure opPOKE()
	a = Code[pc+1]
	b = Code[pc+2]
	poke(val[a], val[b])
	pc += 3
end procedure
	
procedure opPOKE4()
	a = Code[pc+1]
	b = Code[pc+2]
	poke4(val[a], val[b])
	pc += 3
end procedure

procedure opMEM_COPY()
	a = Code[pc+1]
	b = Code[pc+2]
	c = Code[pc+3]
	mem_copy(val[a], val[b], val[c])
	pc += 4
end procedure
	    
procedure opMEM_SET()
	a = Code[pc+1]
	b = Code[pc+2]
	c = Code[pc+3]
	mem_set(val[a], val[b], val[c])
	pc += 4
end procedure
	    
procedure opPIXEL()
	a = Code[pc+1]
	b = Code[pc+2]
	pixel(val[a], val[b])
	pc += 3
end procedure
	    
procedure opGET_PIXEL()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = get_pixel(val[a])
	pc += 3
end procedure
	  
procedure opCALL()
	a = Code[pc+1]
	call(val[a])
	pc += 2
end procedure

procedure opSYSTEM()
	a = Code[pc+1]
	b = Code[pc+2]
	system(val[a], val[b])
	pc += 3
end procedure
		
procedure opSYSTEM_EXEC()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = system_exec(val[a], val[b])
	pc += 4
end procedure
		
-- I/O routines

procedure opOPEN()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = open(val[a], val[b])
	pc += 4
end procedure

procedure opCLOSE()
	a = Code[pc+1]
	close(val[a])
	pc += 2
end procedure
	      
procedure opABORT()
	if debugger > 0 then
		c_proc( cleanup_cb, {} )
	end if
	abort(val[Code[pc+1]])
end procedure

procedure opGETC()	-- read a character from a file 
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = getc(val[a])
	pc += 3
end procedure
 
procedure opGETS()	
-- read a line from a file
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = gets(val[a])
	pc += 3
end procedure

procedure opGET_KEY() 
-- read an immediate key (if any) from the keyboard 
-- or return -1 
	target = Code[pc+1]
	val[target] = get_key()
	pc += 2
end procedure

procedure opCLEAR_SCREEN()
	clear_screen()
	pc += 1
end procedure

procedure opPUTS()
	a = Code[pc+1]
	b = Code[pc+2]
	puts(val[a], val[b])
	pc += 3
end procedure

procedure opQPRINT()
-- Code[pc+1] not used
	a = Code[pc+2]
	? val[a]
	pc += 3
end procedure
	
procedure opPRINT()
	a = Code[pc+1]
	b = Code[pc+2]
	print(val[a], val[b])
	pc += 3
end procedure

procedure opPRINTF()
	-- printf 
	a = Code[pc+1]
	b = Code[pc+2]
	c = Code[pc+3]
	printf(val[a], val[b], val[c])
	pc += 4
end procedure

-- begin mwl

-- moved this from just above do_exec():
global sequence operation, illegal_eval
illegal_eval = {}
procedure opILLEGAL()
	eval_error[$] = "illegal call within an eval"
end procedure

-- used to send output to the debugger rather than 
-- stdio
procedure debugger_io( object a )
	c_proc( debug_out, {a} )
end procedure

procedure opPUTS_debug()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] = 1 then
		debugger_io( val[b] )
	else
		puts(val[a], val[b])
	end if
	
	pc += 3
end procedure

procedure opQPRINT_debug()
-- Code[pc+1] not used
	a = Code[pc+2]
	
	debugger_io( pretty_sprint(val[a]) )

	pc += 3
end procedure
	
procedure opPRINT_debug()
	a = Code[pc+1]
	b = Code[pc+2]
	if val[a] = 1 then
		debugger_io( pretty_sprint( val[b] ) )
	else
		print(val[a], val[b])
	end if
	
	pc += 3
end procedure

procedure opPRINTF_debug()
	-- printf 
	a = Code[pc+1]
	b = Code[pc+2]
	c = Code[pc+3]
	if val[a] = 1 then
		debugger_io( sprintf( val[b], val[c] ) )
	else
		printf(val[a], val[b], val[c])
	end if
	
	pc += 4
end procedure

function set_debug_io( integer setting )
	if setting then
		-- set STDOUT to go to the debugger
		operation[PUTS]   = routine_id("opPUTS_debug")
		operation[PRINTF] = routine_id("opPRINTF_debug")
		operation[PRINT]  = routine_id("opPRINT_debug")
		operation[QPRINT] = routine_id("opQPRINT_debug")
	else
		-- STDOUT goes to the real STDOUT
		operation[PUTS]   = routine_id("opPUTS")
		operation[PRINTF] = routine_id("opPRINTF")
		operation[PRINT]  = routine_id("opPRINT")
		operation[QPRINT] = routine_id("opQPRINT")
	end if
	return 0
end function
set_debug_io_cb = call_back( routine_id("set_debug_io") )

-- end mwl

procedure opSPRINTF()
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = sprintf(val[a], val[b])
	pc += 4
end procedure

procedure opCOMMAND_LINE()
	sequence cmd
	
	target = Code[pc+1]
	cmd = command_line()
	-- drop second word for better compatibility
	if length(cmd) > 2 then
	cmd = {cmd[1]} & cmd[3..$]
	end if
	val[target] = cmd
	pc += 2
end procedure

procedure opGETENV()
	a = Code[pc+1]
	target = Code[pc+2]
	val[target] = getenv(val[a])
	pc += 3
end procedure

procedure opC_PROC()
	a = Code[pc+1]
	b = Code[pc+2]
	c_proc(val[a], val[b])	-- callback could happen here
	pc += 3
end procedure
	  
procedure opC_FUNC()
	integer target
	
	a = Code[pc+1]
	b = Code[pc+2]
	target = Code[pc+3]
	val[target] = c_func(val[a], val[b])  -- callback could happen here
	pc += 4 
end procedure

procedure opTRACE()
	TraceOn = val[Code[pc+1]]
	if TraceOn = 0 and debugger > 0 then
		-- hide the debugger
		c_proc( hide_debugger, {})
	end if
	pc += 2  -- turn on/off tracing
end procedure

-- other tracing/profiling ops - ignored
procedure opPROFILE() 
-- PROFILE, DISPLAY_VAR, ERASE_PRIVATE_NAMES, ERASE_SYMBOL
-- ops not implemented, ignore
	pc += 2
end procedure

-- begin mwl
procedure opDISPLAY_VAR()
	if TraceOn = 0 or TraceOn > 2 or not debugger or in_trace > 1 then
		pc += 2
		return
	end if
	c_proc( display_var_cb, {Code[pc+1]})
	pc += 2
end procedure

procedure opERASE_PRIVATE_NAMES()
	if TraceOn = 0 or TraceOn > 2 or not debugger or in_trace > 1 then
		pc += 2
		return
	end if
	c_proc( erase_privates_cb, {Code[pc+1]})
	pc += 2
end procedure

procedure opERASE_SYMBOL()
	if TraceOn = 0 or TraceOn > 2 or not debugger or in_trace > 1 then
		pc += 2
		return
	end if
	c_proc( erase_symbol_cb, {Code[pc+1]})
	pc += 2
end procedure

global procedure set_object( object obj )
	c_proc( set_object_cb, {obj})

end procedure

global function get_files( )
	set_object(file_name)
	return 0
end function
get_files_cb = call_back( routine_id("get_files") )

global function get_value( sequence var )
	object v
	v = 0
	return v
end function
get_value_cb = call_back( routine_id("get_value") )

global function get_symbols( )
	set_object( {SymTab, val} )
	return 0
end function
get_symbols_cb = call_back( routine_id("get_symbols"))

global function set_values( integer sym )
	val[sym] = c_func( get_object_cb, {}) 
	return 0
end function
set_values_cb = call_back( routine_id("set_values") )


global function get_line( integer line )
	if line > 0 and line <= length( slist ) then
		if atom(slist[line][SRC]) then
			slist[line][SRC] = fetch_line( slist[line][SRC] )
		end if
		set_object( slist[line] )
		return 0
	end if
	set_object( {0,0,0,0} )
end function
get_line_cb = call_back( routine_id("get_line"))

global function get_lines( atom line1, atom line2 )

	if atom(slist[$]) then
		slist = s_expand( slist )
	end if
	
	if line1 < 1 then
		set_object( {} )
		return 0
	end if
	
	if line2 = #FFFFFFFF then
		line2 = length(slist)
	end if
	
	if line1 > line2 then
		set_object({})
		return 0
	end if

	for i = line1 to line2 do
		if atom(slist[i][SRC]) then
			slist[i][SRC] = fetch_line(slist[i][SRC])
		end if
	end for
	set_object( slist[line1..line2] )
	return 0
end function
get_lines_cb = call_back( routine_id("get_lines"))

global function get_pc()
	return pc
end function
get_pc_cb = call_back(routine_id("get_pc"))

global function set_break( atom line, atom break )
	integer ix

	ix = find( line, break_points )
	if break then
		if not ix then
			break_points &= line
		end if
	elsif ix then
		break_points = break_points[1..ix-1] & break_points[ix+1..$]
	end if

	return 0
end function
set_break_cb = call_back( routine_id("set_break"))

global function set_trace( integer on )
	if on = 4 then
		TraceOn = 0
		debugger = 0
		-- call cleanup, too!
		c_proc( cleanup_cb, {})
		
	elsif on = 5 then
		-- aborting
		RTFatal( "program aborted" )
		return 5
	else
		TraceOn = on
	end if
	return on
end function
set_trace_cb = call_back( routine_id("set_trace"))

global function current_sub()
	return call_stack[$]
end function
current_sub_cb = call_back( routine_id("current_sub") )
-- end mwl

procedure opUPDATE_GLOBALS()
-- for interactive trace
	pc += 1
	
	-- begin mwl
	if TraceOn > 0 and TraceOn < 3 and debugger then
	c_proc( update_vars, {})
	end if
end procedure

-- begin mwl

global function find_label( sequence gotos, sequence label )
	integer ix
	
	ix = find( label, gotos[G_LABEL] )
	if ix then
		-- found a static label
		return ix
	end if
	
	-- there weren't any static labels, so look for a dynamic label
	for i = 1 to length(gotos[G_LABEL]) do
		if length(gotos[G_LABEL][i]) = 3 and label[1] = gotos[G_LABEL][i][1] 
		and equal( val[gotos[G_LABEL][i][3]], label[2] ) then
				
			return i
		end if
	end for
	
	ix = find( label[1], gotos[G_DEFAULT][1] )
	if ix then
		-- there's a default label set
		label[2] = gotos[G_DEFAULT][2][ix]
		
		-- prevents infinite recursion:
		gotos[G_DEFAULT][1] = {}
		
		return find_label( gotos, label )
		
	end if
	return 0
end function

procedure opDEFAULT_GOTO()
-- DEFAULT_GOTO, file, label
	integer file, ix, sub, fx
	object label
	sequence gotos
	file = Code[pc+1]
	label = val[Code[pc+2]]
	sub = call_stack[$]
	gotos = SymTab[sub][S_GOTO]
	
	fx = find( file, gotos[G_DEFAULT][1] )
	if not fx then
		gotos[G_DEFAULT][1] &= file
		gotos[G_DEFAULT][2] = append( gotos[G_DEFAULT][2], label )
	else
		gotos[G_DEFAULT][2][fx] = label
	end if
	SymTab[sub][S_GOTO] = gotos
	pc += 3
end procedure

procedure opIS_GOTO()
-- IS_GOTO, file, label, assignto
	integer file, ix, sub
	sequence label, gotos

	file = Code[pc+1]
	label = {file, val[Code[pc+2]]}
	sub = call_stack[$]
	gotos = SymTab[sub][S_GOTO]
	
	-- don't want default gotos messing things up:
	gotos[G_DEFAULT][1] = {}
	
	ix = find_label( gotos, label )
	if ix then
		-- found a static label
		val[Code[pc+3]] = 1

	else 
		val[Code[pc+3]] = 0
	end if
	
	pc += 4
end procedure

include sprint.e
procedure opGOTO()
	object label
	object gotos
	integer gx, sub, ix, fx
	
	ix = Code[pc+1]
	sub = call_stack[$]
	fx = Code[pc+2]
	gotos = SymTab[sub][S_GOTO]
	if atom(gotos) then
		RTFatal("invalid goto target")
		return
	end if
	
	label = {fx, val[ix] }
	
	gx = find_label( gotos, label )

	if not gx then
		
		if Code[pc+3] then
			-- with strict_goto
			RTFatal("invalid goto target: " & pretty_source(label[2]) )
			return
		
		else
			pc += 4
		end if
	
	else
		pc = gotos[2][gx]
			
	end if
		
	
	
end procedure



procedure eval_exec()
-- execute IL code, starting at start_pc 
	integer op
	keep_running = TRUE

	while keep_running and length(eval_error[$]) = 0 do 
		op = Code[pc]
		call_proc(operation[op], {}) -- opcodes start at 1
	end while
	keep_running = TRUE -- so higher-level do_exec() will keep running
end procedure
forward_eval_exec = routine_id("eval_exec")
procedure opEVAL()
	sequence eval_code
	integer ix, new_syms, pc_start, top, temp_top, gline, eval_target,
		with_trace, start_line


	a = Code[pc+1]
	top = length(call_stack)
	if atom(val[a]) then
		RTFatal("parameter to eval must be a sequence")
		return
	end if
	top = length(call_stack)
	if call_stack[$] != TopLevelSub then
		HidePrivates( call_stack[$], 0 )
	end if
	
	eval_code = val[a]
	target = Code[pc+2]
	eval_target = target
	eval_stack &= 1
	eval_error = append( eval_error, "" )

	gline = find_gline( call_stack[$], pc )
	if atom(slist[$]) then
		slist = s_expand( slist )
	end if
	start_line = length(slist)
	eval_file_no &= slist[gline][LOCAL_FILE_NO]
	with_trace = and_bits( slist[gline][OPTIONS], SOP_TRACE )

	slist &= 0
	-- add file+Symtab entry if required...
	ix = find( "_eval_", file_name )
	if not ix then --equal( file_name[$], "_eval_") then
		file_name = append(file_name, "_eval_")
		current_file_no = length(file_name)
		eval_file = current_file_no
		line_number = 0
		SymTab[eval_sym][S_FIRSTLINE] = length(slist)+1
	end if
	
	-- parse the code into lines
	ix = find( '\n', eval_code )
	eval_buffer = {}
	while ix do
		eval_buffer = append( eval_buffer, eval_code[1..ix-1] )
		eval_code = eval_code[ix+1..$]
		ix = find( '\n', eval_code )
	end while
	if length(eval_code) then
		eval_buffer = append( eval_buffer, eval_code )
	end if

	read_line()

	CurrentSub = eval_sym
	
	new_syms = length( SymTab )
	if sequence(SymTab[eval_sym][S_CODE]) then
		pc_start = length( SymTab[eval_sym][S_CODE] ) + 1
	else
		pc_start = 1
	end if
	temp_top = TopLevelSub
	TopLevelSub = eval_sym
	
	if atom(SymTab[eval_sym][S_CODE]) then
		Code = {}
		LineTable = {}
	else
		Code = SymTab[eval_sym][S_CODE]
		if length(Code) then
			SymTab[eval_sym][S_LINETAB] = SymTab[eval_sym][S_LINETAB][1..$-1]
			LineTable = SymTab[eval_sym][S_LINETAB]			
		else
			LineTable = {}
		end if
	end if
	call_proc( forward_putback,{0})
	parser()

	
	SymTab[eval_sym][S_CODE] = Code
	if atom(SymTab[eval_sym][S_LINETAB]) then
		SymTab[eval_sym][S_LINETAB] = repeat( -1, length(Code))
	end if
	TopLevelSub = temp_top

	val &= repeat( 0, length(SymTab) - new_syms )
	for i = new_syms + 1 to length(SymTab) do
		val[i] = SymTab[i][S_OBJ]
	end for
	call_stack = append(call_stack, top)
	call_stack = append(call_stack, pc) 
	call_stack = append(call_stack, eval_sym )
	Code = SymTab[eval_sym][S_CODE]
	pc = pc_start
	if not length(eval_error[$]) then
		-- parsing was successful

--	    call_proc( forward_do_exec, {})
		eval_exec()

	else 
		eval_stack[$] = 0
	end if
	
	if not with_trace then
		-- delete the from the buffers in memory, since there was no trace
		-- this should help prevent memory 'leaks'
		SymTab[eval_sym][S_CODE] = Code[1..pc_start - 1]
		SymTab[eval_sym][S_LINETAB] = LineTable[1..pc_start-1]
		rollback_source( start_line )
	end if
	target = eval_target
	pc = call_stack[$-1] + 3
	call_stack = call_stack[1..$-3]
	if call_stack[$] != TopLevelSub then
		HidePrivates( call_stack[$], 1 )
	end if
	Code = SymTab[call_stack[top]][S_CODE]		
	LineTable = SymTab[call_stack[top]][S_LINETAB]

	val[target] = eval_stack[$]
	eval_stack = eval_stack[1..$-1]
	eval_error = eval_error[1..$-1]
	eval_file_no = eval_file_no[1..$-1]

end procedure

procedure opEMBEDDED_PROCEDURE_CALL()
	integer rid
	sequence params
	object void
	sequence mycode
	integer mypc

	rid = val[Code[pc+1]]
	params = val[Code[pc+2]]
	mycode = Code
	mypc = pc
	if rid > 0 then
		call_proc( rid, params )
	else
		-- this is really a dll, so have to do special callback...
		the_object = params
		c_proc( embedded_call_back, {-rid, 0})
	end if

	-- The embedded routine could have called something else
	-- in the embedded script, so we need to make sure Code
	-- and pc get reset
	Code = mycode
	pc = mypc + 3
end procedure

procedure opEMBEDDED_FUNCTION_CALL()
	integer rid, target, mypc
	sequence params, mycode
	
	rid = val[Code[pc+1]]
	params = val[Code[pc+2]]
	target = Code[pc + 3]
	mycode = Code
	mypc = pc
	if rid > 0 then
		val[target] = call_func( rid, params )
	else
		-- this is really a dll, so have to do special callback...
		the_object = params
		c_proc( embedded_call_back, { -rid, 1 })
		val[target] = the_object
	end if

	-- The embedded routine could have called something else
	-- in the embedded script, so we need to make sure Code
	-- and pc get reset	
	Code = mycode
	pc = mypc + 4
end procedure

sequence last_eval_error
global function get_eval_err()
	return last_eval_error
end function

global function do_eval_exec( sequence eval_code )
	integer ix, new_syms, pc_start, top, temp_top, gline, eval_target,
		with_trace, start_line


--	a = Code[pc+1]
--	top = length(call_stack)
--	if atom(val[a]) then
--		RTFatal("parameter to eval must be a sequence")
--	end if
--	top = length(call_stack)
--	if call_stack[$] != TopLevelSub then
--		HidePrivates( call_stack[$], 0 )
--	end if
	
--	target = Code[pc+2]
--	eval_target = target

	eval_stack &= 1
	eval_error = append( eval_error, "" )

--	gline = find_gline( call_stack[$], pc )


	if length(slist) then
		if atom(slist[$]) then
			slist = s_expand( slist )
		end if
		start_line = length(slist)
--		eval_file_no &= slist[gline][LOCAL_FILE_NO]
		with_trace = and_bits( slist[start_line-1][OPTIONS], SOP_TRACE )

		slist &= 0
	else
		start_line = 0
		with_trace = 1
	end if
	-- add file+Symtab entry if required...
	ix = find( "_eval_", file_name )
	if not ix then --equal( file_name[$], "_eval_") then
		file_name = append(file_name, "_eval_")
		current_file_no = length(file_name)
		eval_file = current_file_no
		line_number = 0
		SymTab[eval_sym][S_FIRSTLINE] = length(slist)+1
		
	end if
	
	-- parse the code into lines

	ix = find( '\n', eval_code )
	eval_buffer = {}
	while ix do
		eval_buffer = append( eval_buffer, eval_code[1..ix-1] )
		eval_code = eval_code[ix+1..$]
		ix = find( '\n', eval_code )
	end while
	if length(eval_code) then
		eval_buffer = append( eval_buffer, eval_code )
	end if
	if not length( eval_buffer ) then
		eval_target = eval_stack[$]
		eval_stack = eval_stack[1..$-1]
		eval_error = eval_error[1..$-1]
--		eval_file_no = eval_file_no[1..$-1]
		return 1
	end if
	read_line()

	CurrentSub = eval_sym
	
	new_syms = length( SymTab )
	if sequence(SymTab[eval_sym][S_CODE]) then
		pc_start = length( SymTab[eval_sym][S_CODE] ) + 1
	else
		pc_start = 1
	end if
	temp_top = TopLevelSub
	TopLevelSub = eval_sym
	
	if atom(SymTab[eval_sym][S_CODE]) then
		Code = {}
		LineTable = {}
	else
		Code = SymTab[eval_sym][S_CODE]
		if length(Code) then
			SymTab[eval_sym][S_LINETAB] = SymTab[eval_sym][S_LINETAB][1..$-1]
			LineTable = SymTab[eval_sym][S_LINETAB]			
		else
			LineTable = {}
		end if
	end if

	call_proc( forward_putback,{0})
	parser()
	if not length(eval_error[$]) then	
		SymTab[eval_sym][S_CODE] = Code
		if atom(SymTab[eval_sym][S_LINETAB]) then
			SymTab[eval_sym][S_LINETAB] = repeat( -1, length(Code))
		end if
		TopLevelSub = temp_top
	
		val &= repeat( 0, length(SymTab) - new_syms )
		for i = new_syms + 1 to length(SymTab) do
			val[i] = SymTab[i][S_OBJ]
		end for
		call_stack = append(call_stack, 0)
		call_stack = append(call_stack, 0) 
		call_stack = append(call_stack, eval_sym )
		Code = SymTab[eval_sym][S_CODE]
		pc = pc_start

		-- parsing was successful
		eval_exec()

	
		if not with_trace then
			-- delete the from the buffers in memory, since there was no trace
			-- this should help prevent memory 'leaks'
			SymTab[eval_sym][S_CODE] = Code[1..pc_start - 1]
			SymTab[eval_sym][S_LINETAB] = LineTable[1..pc_start-1]
			if start_line then
				rollback_source( start_line )
			end if
			
		end if

--	pc = call_stack[$-1] + 3
		call_stack = call_stack[1..$-3]
--	if call_stack[$] != TopLevelSub then
--		HidePrivates( call_stack[$], 1 )
--	end if
--	Code = SymTab[call_stack[top]][S_CODE]		
--	LineTable = SymTab[call_stack[top]][S_LINETAB]
	end if
	eval_target = eval_stack[$]
	eval_stack = eval_stack[1..$-1]
	last_eval_error = eval_error[$]
	eval_error = eval_error[1..$-1]
--	eval_file_no = eval_file_no[1..$-1]
	if TraceOn and debugger > 0 then
		c_proc( hide_debugger, {} )
	end if

	return length(last_eval_error) = 0
end function

sequence embed_table

constant 
PARAM_ABBREV = "ais",
PARAM_NAME = { "atom", "integer", "sequence" }
function embed_params_to_string( sequence params )
	sequence string
	integer ix
	string = ""
	for i = 1 to length(params) do
		ix = find( params[i], PARAM_ABBREV )
		if ix then
			string &= sprintf( "%s p%d", {PARAM_NAME[ix], i})
		else
			string &= sprintf( "object p%d", i )
		end if
		if i != length(params) then
			string &= ','
		end if
	end for
	return string
end function

function embed_params_to_call_params( sequence params )
	sequence string

	string = ""
	for i = 1 to length(params) do
		string &= sprintf( "p%d", {i})
		if i != length(params) then
			string &= ','
		end if
	end for
	return string
end function



constant PROC_OR_FUNC = { "procedure", "function", "", "return " }
global function embed_routine_exec( sequence name, integer rid, sequence params, integer is_func )
		  
	return do_eval_exec( sprintf("global %s %s(%s)\n\t%sembedded_%s_call(%d,{%s})\nend %s\n",
		{ PROC_OR_FUNC[is_func+1], name, embed_params_to_string(params), 
		  PROC_OR_FUNC[is_func+3], 
		  PROC_OR_FUNC[is_func+1], rid, embed_params_to_call_params(params), 
		  PROC_OR_FUNC[is_func+1] }))

end function

procedure opEVAL_ERROR()
	val[Code[pc+1]] = geval_error
	pc += 2
end procedure

global sequence e_variable
e_variable = {}
procedure opVAR_ID()
-- get the routine id for a routine name    
-- routine id's start at 0 (for compatibility with C-coded back-end)
	integer sub, fn, p, stlen
	object name
	
	sub = Code[pc+1]   -- CurrentSub
	stlen = Code[pc+2]	-- s.t. length
	name = val[Code[pc+3]]	-- routine name sequence
	fn = Code[pc+4]    -- file number
	target = Code[pc+5]
	pc += 6
	if atom(name) then
		val[target] = -1
		return
	end if

	p = RTLookupVar(name, fn, sub, stlen)
	if p = 0 or find(SymTab[p][S_TOKEN], {r:PROC, r:FUNC, TYPE}) then
		val[target] = -1  -- name is not a variable
		return
	end if
	for i = 1 to length(e_variable) do
		if e_variable[i] = p then
		    val[target] = i - 1 -- routine was already assigned an id
		    return
		end if
	end for 
	e_variable = append(e_variable, p)
	val[target] = length(e_variable) - 1	
end procedure

procedure opREAD_VAR()

	a = val[Code[pc+1]] + 1
	if a < 1 or a > length(e_variable) then
		RTFatal( "Invalid variable_id" )
		return
	end if
	a = e_variable[a]
	target = Code[pc+2]
	val[target] = val[a]
	pc += 3
end procedure

procedure opWRITE_VAR()
	a = Code[pc+1]
	target = e_variable[val[a]+1]
	b = Code[pc+2]
	val[target] = val[b]
	pc += 3
end procedure

constant
VAR_SCOPE = { "", "Loop", "Private", "Global loop", "Local", "Global", "Predefined",
	"Keyword", "Undefined", "Multiply defined"}

procedure opDUMP_VARS()
--  { file_name, scope, name, variable_id }
	sequence vars, entry
	target = Code[pc+1]
	vars = {}
	for sym = TopLevelSub + 2 to length(SymTab) do
		entry = SymTab[sym]
		if length(entry) = SIZEOF_VAR_ENTRY and entry[S_VTYPE] then

			vars = append( vars, { file_name[entry[S_FILE_NO]], VAR_SCOPE[entry[S_SCOPE]],
				entry[S_NAME], SymTab[entry[S_VTYPE]][S_NAME],find( sym, e_variable ) - 1 })
		end if
	end for
	val[target] = vars
	pc += 2
end procedure

-- end mwl

procedure do_exec()
-- execute IL code, starting at start_pc 
	integer op
	keep_running = TRUE
	while keep_running do 
	op = Code[pc]
-- ? {call_stack[$], pc, length(Code)}
	call_proc(operation[op], {}) -- opcodes start at 1
	end while
	keep_running = TRUE -- so higher-level do_exec() will keep running

end procedure
-- begin mwl

forward_do_exec = routine_id("do_exec")
-- end mwl

-- intermediate call back routines

-- begin mwl
--function general_callback(sequence routine, sequence args)
-- call the user's function from an external source
-- (interface for Euphoria-coded call-backs)

function general_callback( atom cbx, atom ptr )
	sequence args, routine
	if in_trace then
		in_trace += 1
	end if
	routine = call_backs[cbx]
	args = peek4u( ptr & call_backs[cbx][C_NUM_ARGS] )

	val[t_id] = routine[C_USER_ROUTINE]
	val[t_arglist] = args
	

	-- create a stack frame
	call_stack = call_stack & {length(call_stack), pc, call_back_routine} 

	Code = call_back_code 
	pc = 1 
	
	if EMBEDDED then
		eval_exec()
	else
		do_exec()
	end if
	

	-- remove the stack frame
	pc = call_stack[$-1]
	call_stack = call_stack[1..$-3]
	
	-- restore
	Code = SymTab[call_stack[$]][S_CODE]
 	if in_trace then
 		in_trace -= 1
 	end if
	return val[t_return_val]
end function

forward_general_callback = routine_id("general_callback")

function machine_callback(atom cbx, atom ptr)
-- call the user's function from an external source
-- (interface for machine-coded call-backs)
	sequence rtn_def, args

	rtn_def = call_backs[cbx]
	args = peek4u(ptr & call_backs[cbx][C_NUM_ARGS])

	return general_callback(rtn_def, args)
end function

call_backs = {}

constant cb_std = {
	#89,#E0,				--    0: mov eax, esp
	#83,#C0,#04,			--    2: add eax, 4
	#50,					--    5: push eax
	#68,#00,#00,#00,#00,	--    6: push dword rid (7)
	#FF,#15,#00,#00,#00,#00,--    B: call near dword ptr [pfunc] (13)
	#C2,#00,#00,			--   11: ret bytes (18)
	#00,#00,#00,#00},		--   14: function pointer (20)

cb_cdecl= {
	#89,#E0,				--    0: mov eax, esp
	#83,#C0,#04,			--    2: add eax, 4
	#50,					--    5: push eax
	#68,#00,#00,#00,#00,	--    6: push dword rid (7)
	#FF,#15,#00,#00,#00,#00,--    B: call near dword ptr [pfunc] (13)
	#83, #C4, #08,			--   11: sub esp, 8
	#C3,#00,#00,			--   14: ret bytes 
	#00,#00,#00,#00}        --   17: function pointer (23)

procedure do_callback(integer b)
-- handle callback()
	symtab_index r
	integer id, convention
	atom asm
	object x

	-- val[b] is:  routine id or {'+', routine_id}
	x = val[b]
	if atom(x) then
		id = x
		convention = 0
	else
		convention = x[1]
		id = x[2]
	end if
	-- begin mwl
	-- routine_id's are zero-based    
	if id < 0 or id >= length(e_routine) then
		RTFatal("Invalid routine id")
		return
	end if		
	
	r = e_routine[id+1]
	-- end mwl
	if platform() = WIN32 and not convention then
	-- stdcall
	    asm = allocate( length(cb_std) )
	    poke( asm, cb_std ) 
	    poke4( asm + 7, length(call_backs) + 1 )
	    poke4( asm + 13, asm + 20 )
	    poke( asm + 18, SymTab[r][S_NUM_ARGS] * 4 )
		poke4( asm + 20, call_back( routine_id("machine_callback") ) )
	
	else
	-- cdecl
	    asm = allocate( length(cb_cdecl) )  
	    poke( asm, cb_cdecl )
	    poke4( asm + 7, length(call_backs) + 1 )
	    poke4( asm + 13, asm + 23 )
		poke4( asm + 23, call_back( '+' & routine_id("machine_callback") ) )
	end if

	val[target] = asm
	call_backs = append( call_backs, { r, id, SymTab[r][S_NUM_ARGS] })
end procedure	 
-- end mwl


procedure do_crash_routine(integer b)
-- add a crash routine to the list
	object x
	
	x = val[b]
	-- begin mwl
	-- routine_id's are zero-based
	if atom(x) and x >= 0 and x < length(e_routine) then
	-- end mwl
		crash_list &= x 
	else
		RTFatal("crash routine requires a valid routine id")
		return
	end if
end procedure

procedure opMACHINE_FUNC()
	a = Code[pc+1]
	b = Code[pc+2] 
	target = Code[pc+3]
	pc += 4
	-- handle CALL_BACK specially
	if val[a] = M_CALL_BACK then
	-- routine id's must be handled at our level
	do_callback(b)  
	else
	val[target] = machine_func(val[a], val[b])
	end if
end procedure

procedure opMACHINE_PROC()
	object v
	
	a = Code[pc+1]
	b = Code[pc+2]
	v = val[a]
	-- some things must be handled at our level, not a lower level
	if v = M_CRASH_ROUTINE then
	-- routine id's must be handled at our level
	do_crash_routine(b) 
	
	elsif v = M_CRASH_MESSAGE then
	crash_msg = val[b]
	
	elsif v = M_CRASH_FILE and sequence(val[b]) then
	err_file_name = val[b]  
	else
	machine_proc(val[a], val[b]) 
	end if
	pc += 3
end procedure

-- This is for debugging only:
--include print.e
--

procedure save_il()
	integer st

	puts(2,"save il\n")
	printf(2,"%s.sym", {source_name})
	st = open( sprintf("%s.sym", {source_name}), "w" )

	
	for j = 1 to length( SymTab ) do
		print( st, j & SymTab[j] ) puts( st, "\n" )
	end for
	close( st )

end procedure


global procedure InitBackEnd()
-- initialize Interpreter   
	sequence name
	-- begin mwl
--    save_il()
	-- end mwl
	-- set up val
	val = repeat(0, length(SymTab))
	for i = 1 to length(SymTab) do
	val[i] = SymTab[i][S_OBJ] -- might be NOVALUE
	end for
	
	-- set up operations
	operation = repeat(-1, length(opnames))
	
	for i = 1 to length(opnames) do
	name = opnames[i]
	-- some similar ops are handled by a common routine
	if find(name, {"RHS_SUBS_CHECK", "RHS_SUBS_I"}) then
	    name = "RHS_SUBS"
	elsif find(name, {"ASSIGN_SUBS_CHECK", "ASSIGN_SUBS_I"}) then
	    name = "ASSIGN_SUBS"
	elsif equal(name, "ASSIGN_I") then
	    name = "ASSIGN"
	elsif find(name, {"EXIT", "ENDWHILE", "GOTO_STATIC"}) then
	    name = "ELSE"
	elsif equal(name, "PLUS1_I") then
	    name = "PLUS1"      
	elsif equal(name, "PRIVATE_INIT_CHECK") then
	    name = "GLOBAL_INIT_CHECK"
	elsif equal(name, "PLUS_I") then
	    name = "PLUS"
	elsif equal(name, "MINUS_I") then
	    name = "MINUS"
	elsif equal(name, "FOR_I") then
	    name = "FOR"
	elsif find(name, {"ENDFOR_UP", "ENDFOR_DOWN", 
			  "ENDFOR_INT_UP", "ENDFOR_INT_DOWN",
			  "ENDFOR_INT_DOWN1"}) then
	    name = "ENDFOR_GENERAL"
	elsif equal(name, "CALL_FUNC") then
	    name = "CALL_PROC"
-- begin mwl
--	elsif find(name, {"DISPLAY_VAR", "ERASE_PRIVATE_NAMES", 
--			  "ERASE_SYMBOL"}) then
--	    name = "PROFILE"
-- end mwl
	elsif equal(name, "SC2_AND") then
	    name = "SC2_OR"
	elsif find(name, {"SC2_NULL", "ASSIGN_SUBS2", "PLATFORM",
			  "END_PARAM_CHECK", "NOPWHILE", "NOP1"}) then 
	    -- never emitted
	    name = "NOP2" 
	elsif equal(name, "GREATER_IFW_I") then
	    name = "GREATER_IFW"
	elsif equal(name, "LESS_IFW_I") then
	    name = "LESS_IFW"
	elsif equal(name, "EQUALS_IFW_I") then
	    name = "EQUALS_IFW"
	elsif equal(name, "NOTEQ_IFW_I") then
	    name = "NOTEQ_IFW"
	elsif equal(name, "GREATEREQ_IFW_I") then
	    name = "GREATEREQ_IFW"
	elsif equal(name, "LESSEQ_IFW_I") then
	    name = "LESSEQ_IFW"
	end if
	
	operation[i] = routine_id("op" & name)
	if operation[i] = -1 then
	    RTInternal("no routine id for op" & name)
	end if
	end for
end procedure


call_stack = {}
global procedure Execute(symtab_index proc, integer start_index)
-- top level executor 
	CurrentSub = proc
	call_stack = {CurrentSub}
	pc = start_index
	do_exec()

end procedure

Execute_id = routine_id("Execute")

function crash( object c )
	sequence entry
	if length(file_name) then
		

		puts(2, "OOEU has crashed...\n")
	
		if not bound then
			puts( 2, "Dumping symbol table...\n" )
			save_il()
		end if
		-- make sure this gets called, also, perhaps an error report on 
		-- where in the executing file things died...
		if length(slist) and atom(slist[$]) then
			slist = s_expand(slist)
		end if
		
		if length(call_stack) and call_stack[$] and length(SymTab[call_stack[$]]) = SIZEOF_ROUTINE_ENTRY and
		sequence( SymTab[call_stack[$]][S_LINETAB] ) then
			printf(2, "\n%s: %d\nLine:\n%s\n", find_line( call_stack[$], pc ) & {ThisLine})	
		else
			printf(2, "\n%s: %d\nLine:\n%s\n", {file_name[current_file_no], slist[$][2],ThisLine})	
		end if
		
		if execute then
			open_err_file()
			if length(call_stack) then
				trace_back("")
			end if
			call_crash_routines()
		elsif preprocess then
			call_proc( POST_PROCESS_RID, {})
		end if
	end if
	if debugger > 0 then
		c_proc( cleanup_cb, {})
	end if
	return 0
end function
crash_file("ooeu.err")
crash_routine(routine_id("crash"))

global procedure BackEnd(atom ignore)
-- The Interpreter back end
	Execute(TopLevelSub, 1)
	
end procedure

-- dummy routines, not used
global procedure OutputIL()
end procedure

global function extract_options(sequence s)
	return s
end function
