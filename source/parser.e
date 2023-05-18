-- Euphoria 2.5
-- Parser
include reswords.e as r
constant UNDEFINED = -999
constant DEFAULT_SAMPLE_SIZE = 25000  -- for time profile

global integer max_stack_per_call  -- max stack required per (recursive) call 

global integer sample_size         -- profile_time sample size 
sample_size = 0

max_stack_per_call = 1

--*****************
-- Local variables 
--*****************
sequence branch_list
branch_list = {}

integer short_circuit     -- are we doing short-circuit code? 
			  -- > 0 means yes - if/elsif/while but not
			  -- in args, subscripts, slices, {,,}. 
short_circuit = 0
boolean short_circuit_B   -- are we in the skippable part of a short
short_circuit_B = FALSE   -- circuit expression? given short_circuit is TRUE.
			   
integer SC1_patch        -- place to patch jump address for SC1 ops 
integer SC1_type         -- OR or AND 
integer start_index      -- start of current top level command 

-- begin mwl
-- made global 
global object backed_up_tok  -- place to back up a token 
-- end mwl
integer FuncReturn    -- TRUE if a function return appeared 
integer param_num     -- number of parameters and private variables
		      -- in current procedure 
sequence elist        -- back-patch list for end if label 
sequence exit_list    -- stack of exits to back-patch 
integer loop_nest     -- current number of nested loops 
integer stmt_nest     -- nesting level of statement lists 
global sequence init_stack   -- var init stack 

-- Expression statistics:
integer side_effect_calls -- number of calls to functions with side-effects
side_effect_calls = 0     -- on local/global variables

integer factors           -- number of factors parsed
factors = 0

integer lhs_subs_level    -- number of levels of subscripting of lhs var on RHS
lhs_subs_level = -1

symtab_index left_sym  -- var used on LHS of assignment
left_sym = 0

procedure EndLineTable()
-- put marker at end of current line number table 

    LineTable = append(LineTable, -2)
end procedure

procedure CreateTopLevel()
-- sets symbol table fields for the top level procedure 
    SymTab[TopLevelSub][S_NUM_ARGS] = 0
    SymTab[TopLevelSub][S_TEMPS] = 0
    SymTab[TopLevelSub][S_CODE] = {}
    SymTab[TopLevelSub][S_LINETAB] = {}
    SymTab[TopLevelSub][S_FIRSTLINE] = 1
    SymTab[TopLevelSub][S_REFLIST] = {}
    SymTab[TopLevelSub][S_NREFS] = 1
end procedure

-- begin mwl: made global
global procedure EnterTopLevel()
-- end mwl
-- prepare to put code into the top level procedure 
    if CurrentSub then
	EndLineTable()
	SymTab[CurrentSub][S_LINETAB] = LineTable
	SymTab[CurrentSub][S_CODE] = Code
    end if
    LineTable = SymTab[TopLevelSub][S_LINETAB]
    Code = SymTab[TopLevelSub][S_CODE]
    previous_op = -1
    CurrentSub = TopLevelSub
end procedure

-- begin mwl: made global
global procedure LeaveTopLevel()
-- end mwl
-- prepare to resume compiling normal subprograms 
    LastLineNumber = -1
    SymTab[TopLevelSub][S_LINETAB] = LineTable
    SymTab[TopLevelSub][S_CODE] = Code
    LineTable = {}
    Code = {}
    previous_op = -1
end procedure

global procedure InitParser()
    elist = {}
    exit_list = {}
    init_stack = {}
    CurrentSub = 0
    CreateTopLevel()
    EnterTopLevel()
    backed_up_tok = UNDEFINED
    loop_nest = 0
    stmt_nest = 0
end procedure

procedure NotReached(integer tok, sequence keyword)
-- Issue warning about code that can't be executed 
    if not find(tok, {END, ELSE, ELSIF, END_OF_FILE}) then
	Warning(sprintf("%s:%d - statement after %s will never be executed", 
		{name_ext(file_name[current_file_no]), line_number, keyword}))
    end if
end procedure

procedure InitCheck(symtab_index sym, integer ref)
-- emit INIT_CHECK opcode if we aren't sure if a var has been
-- initialized yet. ref is TRUE if this is a read of this var 
    if SymTab[sym][S_MODE] = M_NORMAL and 
       SymTab[sym][S_SCOPE] != SC_LOOP_VAR and 
       SymTab[sym][S_SCOPE] != SC_GLOOP_VAR then
	if (SymTab[sym][S_SCOPE] != SC_PRIVATE and 
	   equal(SymTab[sym][S_OBJ], NOVALUE)) or 
	   (SymTab[sym][S_SCOPE] = SC_PRIVATE and 
	   SymTab[sym][S_VARNUM] >= SymTab[CurrentSub][S_NUM_ARGS]) then
	    if SymTab[sym][S_INITLEVEL] = -1 then
		if ref then
		    if SymTab[sym][S_SCOPE] = SC_GLOBAL or 
		       SymTab[sym][S_SCOPE] = SC_LOCAL then
			emit_op(GLOBAL_INIT_CHECK) -- will become NOP2
		    else
			emit_op(PRIVATE_INIT_CHECK)
		    end if
		    emit_addr(sym)
		end if
		if short_circuit <= 0 or short_circuit_B = FALSE then
		    init_stack = append(init_stack, sym)
		    SymTab[sym][S_INITLEVEL] = stmt_nest
		end if
	    end if
	    -- else we know that it must be initialized at this point 
	end if
	-- else ignore parameters, already initialized global/locals 
    end if
    -- else .. ignore loop vars, constants 
end procedure

procedure InitDelete()
-- remove vars whose nesting level is 
-- now too high from the init stack 
    while length(init_stack) and 
	  SymTab[init_stack[$]][S_INITLEVEL] > stmt_nest do
	SymTab[init_stack[$]][S_INITLEVEL] = -1
	init_stack = init_stack[1..$-1]
    end while
end procedure

procedure emit_forward_addr() 
-- emit blank forward address and add this branch point to the list 
-- for later straightening 
    emit_addr(0)
    branch_list = append(branch_list, length(Code))
end procedure

procedure StraightenBranches()
-- Straighten branches within the current subprogram (or top-level)
    integer br 
    integer target
    
    if TRANSLATE then
	return -- do it in back-end
    end if
    for i = length(branch_list) to 1 by -1 do
	target = Code[branch_list[i]]
	if target <= length(Code) then
	    br = Code[target]
	    if br = ELSE or br = ENDWHILE or br = EXIT then
		backpatch(branch_list[i], Code[target+1])
	    end if
	end if
    end for
    branch_list = {}
end procedure

procedure AppendEList(integer addr)
-- add address to list requiring back-patch at end of if statement 
    elist = append(elist, addr)
end procedure

procedure AppendXList(integer addr)
-- add exit location to list requiring back-patch at end of loop 
    exit_list = append(exit_list, addr)
end procedure

procedure PatchEList(integer base)
-- back-patch jump offsets for jumps to end of if-statement 
    integer elist_top
    
    elist_top = length(elist)
    while elist_top > base do
	backpatch(elist[elist_top], length(Code)+1)
	elist_top -= 1
    end while
    elist = elist[1..base]
end procedure

procedure PatchXList(integer base)
-- back-patch jump offsets for jumps to end of loop 
    integer exit_top
    
    exit_top = length(exit_list)
    while exit_top > base do
	backpatch(exit_list[exit_top], length(Code)+1)
	exit_top -= 1
    end while
    exit_list = exit_list[1..base] 
end procedure
-- begin mwl
-- made object
procedure putback(object t ) --token t) 
-- end mwl
  -- push a scanner token back onto the input stream    

--    if t[T_SYM] and length(SymTab[t[T_SYM]]) >= S_NAME then
--    	printf(2, "putback: %d %s\n", {t[T_ID], SymTab[t[T_SYM]][S_NAME]})
--    else
--    	printf(2, "putback: %d\n", {t[T_ID]})
--    end if
    backed_up_tok = t
end procedure

-- begin mwl
forward_putback = routine_id("putback")

procedure cache_line()
	-- some logical lines span physical lines, so we have to be able to 
	-- remember this for preprocessing
	integer ix, jx, line, tx
--printf(1, "Caching: %d: %s", {length(slist)-1, ThisLine}) ? -1 & start_line


	
	if start_line[$] != length(slist) - 1 then
		start_line &= length(slist) - 1
		if length(start_line) > 2 then
			start_line_token &= length(line_tokens)
		else
			start_line_token &= 1
		end if
		
	end if

	remember_line &= 1	

end procedure

procedure release_line()
	integer ix, tx

	remember_line = remember_line[1..$-1]

	if not remember_line[$] then
		start_line = {0} -- start_line[1..$-1]
		start_line_token = {0} --start_line_token[1..$-1]
	end if
end procedure

function line_num( integer tok )
	for i = length(start_line_token) to 2 by -1 do
		if tok >= start_line_token[i] then
			return start_line[i]
		end if
	end for
	return length(slist) - atom( slist[$] )
end function

integer replacing_full_line
replacing_full_line = 0
global procedure full_line()
	replacing_full_line = 1
end procedure

function token_text( integer tok1 )
	integer lx
	sequence line, bounds
	
	lx = line_num( tok1 )
	if atom(slist[$]) then
		slist = s_expand( slist )
	end if
	if atom(slist[lx][SRC]) then
		slist[lx][SRC] = fetch_line(slist[lx][SRC])
	end if
	
	line = slist[lx]
	bounds = token_boundaries[tok1]
	return line[SRC][bounds[1]..bounds[2]-1]
end function


-- This eats the dot in dot notation when accessing a
-- 'sequence of' member
procedure eat_token()
	sequence bounds

	if not length(token_boundaries) then
		bp -= 1
		return
	end if
	bounds = token_boundaries[$]
	bp -= bounds[2] - bounds[1]
	token_boundaries = token_boundaries[1..$-1]
	line_tokens = line_tokens[1..$-1]

end procedure

global procedure replace_tokens( integer tok1, integer tok2, sequence text )
	sequence line, bounds
	integer old_len, new_len, lx1, lx2, lx

	lx1 = line_num( tok1 )
	lx2 = line_num( tok2 )
	if tok1 > length(token_boundaries) or tok2 > length(token_boundaries) then
		InternalErr( "invalid tokens in replace_tokens()" )
	end if

	if atom(slist[$]) then
		slist = s_expand( slist )
	end if
	
	if atom(slist[lx1][SRC]) then
		slist[lx1][SRC] = fetch_line(slist[lx1][SRC])
	end if

	line = slist[lx1][SRC]

	if lx1 = lx2 then
		line = slist[lx1][SRC]

		old_len = token_boundaries[tok2][2] - token_boundaries[tok1][1]
		new_len = length(text)
				
--		printf(rn, "new_len - old: %d\n", {new_len-old_len})
--		puts(rn, "token_boundaries=")Print(rn, token_boundaries ) puts(rn, "\n")
--		puts(rn, "line_tokens=")Print(rn, line_tokens)puts(rn, "\n")
--		puts(rn, "start_line=")Print(rn, start_line)puts(rn, "\n")
--		puts(rn, "start_line_token=")Print(rn, start_line_token)puts(rn, "\n")
--		printf(rn, "tok1=%d tok2=%d\n", {tok1, tok2})
--		puts(rn, "token_boundaries[tok2][2] & length(line) ")
--		Print(rn, token_boundaries[tok2][2] & length(line)) puts(rn,"\n")
		bounds = token_boundaries[tok1] & token_boundaries[tok2]
		if bounds[$] = -1 then
			bounds[$] = bounds[$-1]
		end if
		line = line[1..token_boundaries[tok1][1]-1] & text & 
			line[token_boundaries[tok2][2]..$]
--		line = line[bounds[1]..bounds[2]-1] & text & line[bounds[4]..$]

		
		if lx2 = length(slist) then
			
			if replacing_full_line = 0 then
				token_boundaries[tok2..$] += new_len - old_len -- (tok2 = length(token_boundaries))
				
			else
				token_boundaries[tok2..$] += new_len - old_len
			end if

		else
			lx2 = find( lx2, start_line )
			token_boundaries[tok2..start_line_token[lx2+1]-1] += new_len - old_len 
--			Print(rn, token_boundaries ) puts(rn, "2\n")
	
		end if
		
		slist[lx1][SRC] = line
	else
		-- split across multiple lines
		line = line[1..token_boundaries[tok1][1]-1] & text
		slist[lx1][SRC] = line

		for i = tok1 + 1 to tok2 do
			slist[line_num(i)][SRC][token_boundaries[i][1]..token_boundaries[i][2]] = ' '
		end for
		
	end if

	if not find( current_file_no, processed_files ) then
		processed_files &= current_file_no
	end if
	replacing_full_line = 0
	slist &= 0
end procedure
-- end mwl

function next_token() 
-- read next scanner token
    token t
    -- begin mwl
    integer offset
    if length(eval_error[$]) then
    	return {END_OF_FILE, 0}
    end if
    -- end mwl
    if atom(backed_up_tok) then
	 t = Scanner() 
	 -- begin mwl
	 if preprocess then
	 	token_boundaries[$][2] = bp 
	 	if length(token_boundaries) > 1 then
	 		offset = token_boundaries[$][1] - token_boundaries[$-1][2]
	 		if offset < 0 then
--	 			printf(rn, "offset = %d ", offset) Print(rn, token_boundaries[$-1..$] )puts(rn,"\n")
	 			token_boundaries[$] -= (offset)- token_ws[$] --+ whitespace_count
	 			
	 		end if
	 	end if
	 	line_tokens = append( line_tokens, t )
	 end if
	 -- end mwl
    else     
	 t = backed_up_tok 
	 backed_up_tok = UNDEFINED 
    end if 
    return t
end function

integer forward_expr

function Expr_list()
-- parse a (possibly empty) list of expressions 
    token tok
    integer n

    tok = next_token()
    putback(tok)
    if tok[T_ID] = RIGHT_BRACE then
	return 0
    else 
	n = 0
	short_circuit -= 1
	while TRUE do 
	    call_proc(forward_expr, {})
	    n += 1
	    tok = next_token()
	    if tok[T_ID] != COMMA then
		exit
	    end if
	end while  
	short_circuit += 1
    end if
    putback(tok)
    return n
end function

procedure tok_match(integer tok)
-- match token or else syntax error 
    token t
    sequence expected, actual

    t = next_token()
    if t[T_ID] != tok then
	expected = LexName(tok)
	actual = LexName(t[T_ID])
	CompileErr(sprintf(
		   "Syntax error - expected to see possibly %s, not %s", 
		   {expected, actual}))
	return
    end if
end procedure

function UndefinedVar(symtab_index s)
-- report a possibly undefined or multiply-defined symbol 
    symtab_index dup
    sequence errmsg
    
    if SymTab[s][S_SCOPE] = SC_UNDEFINED then

	CompileErr(sprintf("%s has not been declared", {SymTab[s][S_NAME]}))
    return 1
    elsif SymTab[s][S_SCOPE] = SC_MULTIPLY_DEFINED then
	errmsg = sprintf("A namespace qualifier is needed to resolve %s.\n%s is defined as a global symbol in:\n", 
			 {SymTab[s][S_NAME], SymTab[s][S_NAME]})
	-- extended error message  
	for i = length(dup_globals) to 1 by -1 do
	    dup = dup_globals[i]
	    errmsg &= "    " & file_name[SymTab[dup][S_FILE_NO]] & "\n"
	end for
	
	CompileErr(errmsg)
	return 1
    end if
    return 0
end function

procedure WrongNumberArgs(symtab_index subsym, sequence only)
-- issue message for wrong number of arguments
    sequence plural

    if SymTab[subsym][S_NUM_ARGS] = 1 then
	plural = ""
    else
	plural = "s"
    end if
    CompileErr(sprintf("%s takes %s%d argument%s", 
	       {SymTab[subsym][S_NAME], only, 
		SymTab[subsym][S_NUM_ARGS], plural}))
end procedure

procedure ParseArgs(symtab_index subsym)
-- parse arguments for a function, type or procedure call 
    integer n
    token tok

    n = SymTab[subsym][S_NUM_ARGS]
    short_circuit -= 1
    for i = 1 to n do
	call_proc(forward_expr, {})
	if i != n then 
	    tok = next_token()
	    if tok[T_ID] != COMMA then
		if tok[T_ID] = RIGHT_ROUND then
		    WrongNumberArgs(subsym, "")
		else 
		    putback(tok)
		    tok_match(COMMA)
		end if
	    end if
	end if
    end for
    tok = next_token()
    short_circuit += 1
    if tok[T_ID] != RIGHT_ROUND then
	if tok[T_ID] = COMMA then
	    WrongNumberArgs(subsym, "only ")
	else 
	    putback(tok)
	    tok_match(RIGHT_ROUND)
	end if
    end if
end procedure

-- begin mwl
-- begin mwl
function TypeLCD( symtab_index t1, symtab_index t2 )
	symtab_index s
	
	if t1 = t2 then
		return t1
	end if
	
	-- is t1 a sub-type of t2?
	s = t2
	while s != t1 do
		if find( s, {integer_type, atom_type, sequence_type, object_type}) then
			exit
		elsif length( SymTab[s] ) > S_VTYPE then
			exit
		else
			s = SymTab[s][S_VTYPE]
		end if
	end while
	
	if s = t1 then
		return s
	end if
	
	-- is t2 a sub-type of t1
	s = t1
	while s != t2 do
		if find( s, {integer_type, atom_type, sequence_type, object_type}) then
			exit
		elsif length( SymTab[s] ) > S_VTYPE then
			exit
		else
			s = SymTab[s][S_VTYPE]
		end if
	end while
	
	if s = t2 then
		return s
	end if
	
	-- there is no discernable LCD between these two,
	-- so the answer is object
	return object_type
end function

function token_type( token tok )
	symtab_index the_type
	object obj
	if find( tok[T_ID], {TYPE, QUALIFIED_TYPE})  then
		-- treat as object
		the_type = object_type
	
	elsif find( tok[T_ID], {r:FUNC, QUALIFIED_FUNC}) then
		if SymTab[tok[T_SYM]][S_OBJ] = NOVALUE then
			the_type = object_type
		else
			the_type = SymTab[tok[T_SYM]][S_OBJ]
		end if
	elsif tok[T_ID] = ATOM then
		the_type = atom_type
		
	elsif find(tok[T_ID], {STRING, LEFT_BRACE}) then
		-- treat as sequence
		the_type = sequence_type
	else
		the_type = SymTab[tok[T_SYM]][S_VTYPE]
		if not the_type then
			-- a constant
			obj = SymTab[tok[T_SYM]][S_OBJ]
			if sequence( obj ) then
				return sequence_type
			elsif integer( obj ) then
				return integer_type
			else return atom_type
			end if
		end if
--		if not find( the_type, {integer_type, atom_type, sequence_type, object_type}) then
--			if not find( the_type, class_table[CLASS_SYM] ) then
--			-- class types are OK
--				the_type = object_type
--			end if
--			
--		end if		
	end if
	
	return the_type
end function

procedure validate_current_term( token tok)
	integer tok_type

	tok[T_SYM] = token_type( tok )
	if not term_stack[$][T_ID] then
		term_stack[$] = tok
		
	else
		tok_type = tok[T_SYM]
		term_stack[$][T_SYM] = TypeLCD( term_stack[$][T_SYM], tok_type )
	end if
end procedure
-- end mwl

procedure Factor()
-- parse a factor in an expression 
    token tok
    integer id, n, scope, opcode, e
    integer save_factors, save_lhs_subs_level, minus_term
    symtab_index sym
	-- begin mwl
	integer rid, arg, seq_of
	object routine
	-- end mwl
	
    factors += 1
    tok = next_token()
    id = tok[T_ID]
    -- begin mwl
	minus_term = 0
	seq_of = 0
	-- end mwl
    if id = VARIABLE or id = QUALIFIED_VARIABLE then
		sym = tok[T_SYM]
		if UndefinedVar(sym) then
			return
		end if

	    -- begin mwl
	    -- have to remember what the types are for each argument
	    -- being passed to the method, so we'll make our best
	    -- guess
	    if parse_method_stack[$] then
			validate_current_term( tok )
	    end if
		-- end mwl
		    
		SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)

		tok = next_token()
		-- begin mwl
		
		if tok[T_ID] = DOT_NOTATION then
			-- a method that's a function, or maybe just data member...
			current_instance &= sym
			InitCheck(sym, TRUE)

			call_proc( forward_method_func, {tok})
			tok = next_token()
			if tok[T_ID] != LEFT_SQUARE then
				putback(tok)
				current_instance = current_instance[1..$-1]
--				short_circuit += 1
				return
			end if
			
			
			if parse_method_stack[$] then
				term_stack[$-1][T_SYM] = object_type
				parse_method_stack &= 0
				minus_term = 1
				current_instance = current_instance[1..$-1]
			end if
			
			
		else

			current_sequence = append(current_sequence, sym)
		
			InitCheck(sym, TRUE)
			emit_opnd(sym)
		end if
			
		if sym = left_sym then
		    lhs_subs_level = 0 -- start counting subscripts
		end if
		
		short_circuit -= 1
		if tok[T_ID] = LEFT_SQUARE then
		if parse_method_stack[$] then
			term_stack[$][2] = object_type
		end if

		if is_sequenceof( left_sym ) then
			current_instance &= left_sym
			seq_of = 1
		elsif is_sequenceof( sym ) then
			current_instance &= sym
			seq_of = 1
		else
--			printf(2, "Not sequence of: %d %d", {left_sym, sym})
		end if			
		end if
		-- end mwl
		
		
		while tok[T_ID] = LEFT_SQUARE do
		    if lhs_subs_level >= 0 then
				lhs_subs_level += 1
		    end if
		    save_factors = factors
		    save_lhs_subs_level = lhs_subs_level
		    -- begin mwl
		    -- have to remember to keep parse_method_stack current
		    parse_method_stack &= 0
		    current_instance &= 0
		    call_proc(forward_expr, {})
		    current_instance = current_instance[1..$-1]
		    parse_method_stack = parse_method_stack[1..$-1]
		    -- end mwl
		    tok = next_token()
		    if tok[T_ID] = SLICE then
				call_proc(forward_expr, {})
				emit_op(RHS_SLICE)
				tok_match(RIGHT_SQUARE)
				tok = next_token()

				exit
		    else 
				putback(tok)
				tok_match(RIGHT_SQUARE)

				current_sequence = current_sequence[1..$-1]
			
				emit_op(RHS_SUBS) -- current_sequence will be updated
		    end if
		    factors = save_factors
		    lhs_subs_level = save_lhs_subs_level
		    tok = next_token()
		end while
		
		-- begin mwl
		-- check for sequence of + dot notation
		if is_sequenceof( current_instance[$] ) then

			if tok[T_ID] = DOT_NOTATION then
				putback({VARIABLE, current_instance[$]})
				current_instance = current_instance[1..$-1]
				eat_token()
				Factor()
			else
				putback(tok)
			end if
		else
			putback(tok)
		end if
		-- end mwl
		current_sequence = current_sequence[1..$-1]
		short_circuit += 1

		-- begin mwl
		if minus_term then
			parse_method_stack = parse_method_stack[1..$-1]
			
		end if
    elsif id = DOLLAR then

		if length(current_sequence) then
		-- begin mwl
		-- delay emitting the dollar sign until we can get back to Method/Func 
		-- because members haven't been emitted yet

			if member_stack[$] or current_instance[$] then
				member_stack &= -0.5
			else
				emit_op(DOLLAR)
			end if		
		    
		-- end mwl
		else
		    CompileErr("'$' must only appear between '[' and ']'")
		    return
		end if
	
    elsif id = ATOM then
		emit_opnd(tok[T_SYM])

		-- begin mwl
		if parse_method_stack[$] then
			validate_current_term( tok )
		end if
		-- end mwl

    elsif id = LEFT_BRACE then
		-- begin mwl
		-- should be a sequence...
		
		if parse_method_stack[$] then
			validate_current_term( tok )
		end if
		parse_method_stack &= 0
		-- end mwl
		n = Expr_list()
		tok_match(RIGHT_BRACE)
		op_info1 = n
		emit_op(RIGHT_BRACE_N)
		
		-- begin mwl
		parse_method_stack = parse_method_stack[1..$-1]
		-- end mwl

    elsif id = STRING then
		emit_opnd(tok[T_SYM])
		-- begin mwl
		if parse_method_stack[$] then
			validate_current_term( tok )
		end if
		-- end mwl
    elsif id = LEFT_ROUND then
		call_proc(forward_expr, {})
		tok_match(RIGHT_ROUND)

    elsif find(id, {r:FUNC, QUALIFIED_FUNC, TYPE, QUALIFIED_TYPE}) then
    	-- begin mwl
		add_ref( tok )
		
		if parse_method_stack[$] then
			validate_current_term( tok )
		end if
		if find( tok[T_SYM], class_table[CLASS_SYM]) then
			-- it's a class, so do a function method
			sym = tok[T_SYM]
			tok = next_token()
			-- begin mwl
			
			if tok[T_ID] = DOT_NOTATION then
				-- a method that's a function
				current_instance &= sym
				call_proc( forward_method_func, {tok})
				
				if seq_of then
					seq_of = 0
					
					current_instance = current_instance[1..$-2]
					
				else
					current_instance = current_instance[1..$-1]
				end if
--				current_sequence = append( current_sequence, object_type )
--				short_circuit += 1
				return
			else
				-- could be a constructor...
				putback( tok )
				
				call_proc( forward_method_func, {{id, sym}})
--				CompileErr( "expected a method here" )
				return
			end if
		else
		
			parse_method_stack &= 0
			if preprocess then
				-- try to fix routine_id's to eliminate @'s for preprocessing convenience
				
				if SymTab[tok[T_SYM]][S_OPCODE] = ROUTINE_ID then
		
					cache_line()
					rid = 1

				else
					rid = 0
				end if
			else
				rid = 0
			end if
			-- end mwl
			e = SymTab[tok[T_SYM]][S_EFFECT]
			if e then
			    -- the routine we are calling has side-effects
			    if e = E_ALL_EFFECT or tok[T_SYM] > left_sym then
				-- it can access the LHS var (it uses indirect calls or comes later)
				side_effect_calls = or_bits(side_effect_calls, e)
			    end if
			    
			    SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
								   e)
			    
			    if short_circuit > 0 and short_circuit_B and
				      find(id, {r:FUNC, QUALIFIED_FUNC}) then
				Warning(sprintf(
				"%.99s:%d - call to %s() might be short-circuited", 
				{file_name[current_file_no], line_number, 
				 SymTab[tok[T_SYM]][S_NAME]}))
			    end if
			end if
			tok_match(LEFT_ROUND)
			scope = SymTab[tok[T_SYM]][S_SCOPE]
			opcode = SymTab[tok[T_SYM]][S_OPCODE]
			ParseArgs(tok[T_SYM])
			-- begin mwl
			parse_method_stack = parse_method_stack[1..$-1]
		    if rid then
		    	arg = Pop()
		    	Push( arg )
		    	routine = SymTab[arg][S_OBJ]
		    	if sequence( routine ) then
		    		-- it's a literal, so we can process the token...
		    		for i = 1 to length(routine) do
		    			if find(routine[i], "@!") then
		    				routine[i] = '_'
		    			end if
		    		end for
		    		replace_tokens( length(line_tokens) - 1, length(line_tokens) - 1, '"' & routine & '"' )
		    	end if
		    	
		    	release_line()
		    end if
		    -- end mwl			
			-- end mwl
			if scope = SC_PREDEF then
			    emit_op(opcode)
			else 
			    op_info1 = tok[T_SYM]
			    emit_op(r:PROC)
			    if not TRANSLATE then 
				if OpTrace then
				    emit_op(UPDATE_GLOBALS)
				end if
			    end if      
			end if
		end if
-- begin mwl
	elsif id = CLASS then
		if parse_method_stack[$] then
			validate_current_term( tok )
		else
			CompileErr(sprintf(
				   "Syntax error - expected to see an expression, not %s",
				   {LexName(id)}))		
		end if
-- end mwl
    else 
		CompileErr(sprintf(
			   "Syntax error - expected to see an expression, not %s",
			   {LexName(id)}))
		return
    end if
    
    -- begin mwl
    if seq_of then
    	current_instance = current_instance[1..$-1]
    end if
    if minus_term = 1 then
		-- subscripting a member causes extra term_stack issues...
		if length(term_stack) > 1 then
--		term_stack[$-1] = term_stack[$]
--		term_stack = term_stack[1..$-1]    				
		end if
    end if
    -- end mwl
end procedure


procedure UFactor()
-- parse an optional unary op applied to a factor 
    token tok

    tok = next_token()
    
    if tok[T_ID] = MINUS then
	Factor()
	emit_op(UMINUS)
    
    elsif tok[T_ID] = NOT then
	Factor()
	emit_op(NOT)
    
    elsif tok[T_ID] = PLUS then
	Factor()
    
    else 
	putback(tok)
	Factor()
    
    end if
end procedure

function term()
-- parse a term in an expression 
    token tok

    UFactor()   
    tok = next_token() 
    while tok[T_ID] = MULTIPLY or tok[T_ID] = DIVIDE do
	UFactor() 
	emit_op(tok[T_ID]) 
	tok = next_token() 
    end while
    return tok
end function

function aexpr()   
-- Parse an arithmetic expression 
    token tok
    integer id
    
    tok = term()
    while tok[T_ID] = PLUS or tok[T_ID] = MINUS do
	id = tok[T_ID]
	tok = term()
	emit_op(id) 
    end while
    return tok
end function

function cexpr()   
-- Parse a concatenation expression 
    token tok
    integer concat_count
    
    tok = aexpr()
    concat_count = 0 
    while tok[T_ID] = CONCAT do
	tok = aexpr()
	concat_count += 1 
    end while
    
    if concat_count = 1 then
	emit_op(CONCAT)
    
    elsif concat_count > 1 then
	op_info1 = concat_count+1 
	emit_op(CONCAT_N) 
    end if      
    
    -- begin mwl
    -- this will always be a sequence
    if parse_method_stack[$] and concat_count then
    	term_stack[current_term][T_SYM] = sequence_type
    end if
    -- end mwl
    return tok
end function

-- Parse a relational expression 
function rexpr()   
    token tok
    integer id
    -- begin mwl
    symtab_index sym
    -- end mwl
    
    tok = cexpr()
    while tok[T_ID] <= GREATER and tok[T_ID] >= LESS do
		id = tok[T_ID]
		tok = cexpr()
	
	    -- begin mwl
	    -- this will be an integer if it's not object, sequence, UDT or (maybe) class
	    if parse_method_stack[$] then
	    	sym = term_stack[current_term][T_SYM]
    		while not find( sym, {integer_type, atom_type, object_type, sequence_type}) and
    		length(SymTab[sym]) <= S_VTYPE do
    			sym = SymTab[sym][S_VTYPE]
    		end while
    		
	    	if find(sym, {integer_type, atom_type}) then
	    		term_stack[current_term][T_SYM] = integer_type
	    		
	    	elsif sym = object_type or length(SymTab[sym]) > S_VTYPE then
	    		term_stack[current_term][T_SYM] = object_type
	    		
	    	end if
	    end if
	    -- end mwl
	
		emit_op(id)
    end while
    return tok
end function

-- begin mwl
function MethodArg( symtab_index sym )
	integer ix
	sequence a

	ix = find( sym, {integer_type, object_type, atom_type, sequence_type})
	if ix then
		a = "ioas"
		return {{a[ix]}}
	end if
	
	ix = find( sym, class_table[CLASS_SYM] )
	if ix then
		return { '@' & class_table[CLASS_NAME][ix] & '@' }
	else
		-- User defined type:
		return { '!' & SymTab[sym][S_NAME] & '!' }
--		return {"o"}
	end if
end function
-- end mwl

procedure Expr()
-- Parse a general expression 
-- Use either short circuit or full evaluation. 
    token tok
    integer id
    integer patch

    id = -1
    patch = 0
    while TRUE do 

	if id != -1 and id != XOR and short_circuit > 0 then
	    if id = OR then
		emit_op(SC1_OR)
	    else
		emit_op(SC1_AND)
	    end if
	    patch = length(Code)+1
	    emit_forward_addr()
	    short_circuit_B = TRUE
	end if
	-- begin mwl
	if parse_method_stack[$] then
		term_stack = append( term_stack, {0,0})
		current_term += 1
	end if
	-- end mwl

	tok = rexpr()
	
	-- begin mwl
	if parse_method_stack[$] = 1 then
		method_args[current_method] &= MethodArg( term_stack[$][T_SYM] )
		term_stack = term_stack[1..$-1]
		current_term -= 1
	elsif parse_method_stack[$] then

		term_stack = term_stack[1..$-1]
		current_term -= 1
	end if

	
	if id != -1 then
	    if id != XOR and short_circuit > 0 then
		if tok[T_ID] != THEN and tok[T_ID] != DO then
		    if id = OR then
			emit_op(SC2_OR)
		    else
			emit_op(SC2_AND)
		    end if
		else 
		    SC1_type = id -- if/while/elsif must patch
		    emit_op(SC2_NULL)
		end if
		if TRANSLATE then
		    emit_op(NOP1)   -- to get label here
		end if
		backpatch(patch, length(Code)+1)
	    else 
		emit_op(id)
	    end if
	end if
	id = tok[T_ID]
	if id != OR and id != AND and id != XOR then
	    exit
	end if
    end while
    putback(tok)
    SC1_patch = patch -- extra line
end procedure

forward_expr = routine_id("Expr")

-- begin mwl
function real_type( symtab_index var )
	integer ix
	ix = find( var, class_table[CLASS_SYM] )
	while ix do
		var = class_table[CLASS_VARTYPE][ix]
		ix = find( var, class_table[CLASS_SYM] )
	end while
	return var
end function
-- end mwl

procedure TypeCheck(symtab_index var)
-- emit code to type-check a var (after it has been assigned-to) 
    symtab_index which_type
	
	-- begin mwl
    which_type = real_type( SymTab[var][S_VTYPE] )
    -- end mwl
    
    if TRANSLATE then
	if OpTypeCheck then
	    if which_type != object_type then
		if SymTab[which_type][S_EFFECT] then
		    -- only call user-defined types that have side-effects
		    emit_opnd(var)
		    op_info1 = which_type
		    emit_op(r:PROC)
		    emit_op(TYPE_CHECK)
		end if
	    end if
	end if      
    
    else
	if OpTypeCheck then
	    if which_type != object_type then
		if which_type = integer_type then
		    op_info1 = var
		    emit_op(INTEGER_CHECK)
		
		elsif which_type = sequence_type then
		    op_info1 = var
		    emit_op(SEQUENCE_CHECK)
		
		elsif which_type = atom_type then
		    op_info1 = var
		    emit_op(ATOM_CHECK)
		
		else 
		    -- user-defined 
		    if SymTab[SymTab[which_type][S_NEXT]][S_VTYPE] = 
		       integer_type then
			op_info1 = var
			emit_op(INTEGER_CHECK) -- need integer conversion 
		    end if
		    emit_opnd(var)
		    op_info1 = which_type
		    emit_op(r:PROC)
		    emit_op(TYPE_CHECK)
		end if
	    end if
	end if
    end if

    if TRANSLATE or not OpTypeCheck then
	op_info1 = var
	if which_type = sequence_type or
	    SymTab[SymTab[which_type][S_NEXT]][S_VTYPE] = sequence_type then 
	    -- check sequences anyway, so we can avoid it on subscripting etc. 
	    emit_op(SEQUENCE_CHECK)
	    
	elsif which_type = integer_type or
		 SymTab[SymTab[which_type][S_NEXT]][S_VTYPE] = integer_type then
		 -- check integers too 
	    emit_op(INTEGER_CHECK)
	end if
    end if
end procedure

procedure Assignment(token left_var) 
-- parse an assignment statement 
    token tok
    integer subs, slice, assign_op, subs1_patch
    boolean dangerous  -- tricky subscripted assignment
    -- begin mwl
	sequence members, pdec, cg, cs
	integer class, tok1, tok2, len_member_stack, tokm, tokn, mis, seq_of

	seq_of = 0
	cg = cg_stack
	cs = current_sequence

	if preprocess then
		cache_line()
	end if

	-- end mwl

    left_sym = left_var[T_SYM]
	len_member_stack = length(member_stack)
--  	if sequence_of_class( sym_to_class( SymTab[left_sym][S_VTYPE] ) ) then
--		seq_of = 1
--		current_instance &= left_sym
--	end if  
    -- end mwl
		if UndefinedVar(left_sym) then
			return
		end if   
	
    if SymTab[left_sym][S_SCOPE] = SC_LOOP_VAR or 
       SymTab[left_sym][S_SCOPE] = SC_GLOOP_VAR then
		CompileErr("may not assign to a for-loop variable")
		if preprocess then
			release_line()
		end if
	    return
    elsif SymTab[left_sym][S_MODE] = M_CONSTANT then
		CompileErr("may not change the value of a constant")
		if preprocess then
			release_line()
		end if
	    return
    elsif SymTab[left_sym][S_SCOPE] = SC_LOCAL or 
		SymTab[left_sym][S_SCOPE] = SC_GLOBAL then
		-- this helps us to optimize things below
		SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
					 power(2, remainder(left_sym, E_SIZE)))
    end if
    
    SymTab[left_sym][S_USAGE] = or_bits(SymTab[left_sym][S_USAGE], U_WRITTEN)
    
    tok = next_token()
    	-- begin mwl
    if tok[T_ID] = DOT_NOTATION then

   		current_instance &= left_sym
    	
    	if preprocess then
    		tok1 = length(line_tokens) - 1	
    	end if
    	
	    while tok[T_ID] = DOT_NOTATION do
			tok = next_token()
			-- do we need to hide the member/method?
			hide_member[$] &= tok[T_SYM]
			member_stack &= is_member( tok )
			if member_stack[$] = 0 then
				member_stack = member_stack[1..$-1]

				call_proc( forward_method, {tok})
				current_instance = current_instance[1..$-1]
				if preprocess then
					release_line()
				end if
				return

			end if
			tok = next_token()
	    end while
	    
    	if preprocess then
    		pdec = SymTab[current_instance[$]][S_NAME]
    		for m = 2 to length(member_stack) do
    			class = member_table[MEMBER_CLASS][member_stack[m]]
    			pdec &= sprintf( "[%s_MEMBER_%s]", 
    				{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[m]]})
    			
    		end for
    		tok2 = tok1 + (length(member_stack)-1) * 2
    		replace_tokens( tok1, tok2, pdec )
    	end if
	    
	else
		current_instance &= 0
    end if
	-- end mwl
    subs = 0
    slice = FALSE

    dangerous = FALSE
    side_effect_calls = 0
    
    -- Process LHS subscripts and slice
    -- begin mwl
    if member_stack[$] then
    	emit_opnd( current_instance[$] )
    	left_sym = current_instance[$]
    else
	    emit_opnd(left_sym)    
	end if
	
	
	
    current_sequence = append(current_sequence, left_sym)


    -- add the member subscripts:    
    for m = 2 to length(member_stack) do

		if lhs_ptr then
		    -- multiple lhs subscripts, evaluate first n-1 of them with this
		    current_sequence = current_sequence[1..$-1]
		    if subs = 1 then
				-- first subscript of 2 or more
				subs1_patch = length(Code)+1
				emit_op(LHS_SUBS1) -- creates new current_sequence
						   -- opcode might be patched (below)
		    else    
				emit_op(LHS_SUBS) -- creates new current_sequence
		    end if
		end if
		subs += 1
		emit_opnd( member_table[MEMBER_SYM][member_stack[m]] )

		lhs_ptr = TRUE   
    end for
    
    

    -- end mwl
    
    while tok[T_ID] = LEFT_SQUARE do

		if lhs_ptr then
		    -- multiple lhs subscripts, evaluate first n-1 of them with this
		    current_sequence = current_sequence[1..$-1]
		    	    
		    if subs = 1 then
				-- first subscript of 2 or more

				subs1_patch = length(Code)+1
				emit_op(LHS_SUBS1) -- creates new current_sequence
						   -- opcode might be patched (below)

		    else    
				emit_op(LHS_SUBS) -- creates new current_sequence

		    end if
		end if

		subs += 1
		if subs = 1 then
		    InitCheck(left_sym, TRUE) 
		end if
		Expr() 

		-- begin mwl
		-- This is to catch sequence of usage:
		--     Object.Member[1].Method()
		
		if current_instance[$] then
			member_stack &= - Pop()
			Push( - member_stack[$] )
		end if

		-- end mwl
		
		tok = next_token()
		if tok[T_ID] = SLICE then
		    Expr()
		    slice = TRUE
		    tok_match(RIGHT_SQUARE)
		    tok = next_token()
		    exit  -- no further subs or slices allowed 
		else 
		    putback(tok)
		    tok_match(RIGHT_SQUARE)
		    
		end if
		tok = next_token()
		lhs_ptr = TRUE
    end while
    
    -- begin mwl
    if tok[T_ID] = DOT_NOTATION then
    	-- check for 'sequence of'
		-- Doesn't have to be left_sym.  Could also be a member...
		if length(member_stack) > 1 then
			mis = member_is_sequenceof( member_stack[$-1] )
		else
			-- this can occur where Object[sub].member happens

			mis = 0		

		end if

    	if is_sequenceof( left_sym ) or mis  then

    		if subs > 1 then
				-- multiple subscripts, so we have to peel off the
				-- LHS_SUBS code that has been emitted
				if not mis then
					current_instance &= 0
				end if
    			
    			
    			if previous_op = DOLLAR then
    				Code = Code[1..$-3]
    				
    				-- We don't need this value, so it can go away:
    				tok2 = Pop()
    			end if
    			
    			for i = 2 to subs do
    				if not mis then
    					member_stack &= - Code[$-2]
    					current_instance[$] = Code[$-3]
    				end if
    				
					Code = Code[1..$-5]    				
    			end for
				
				if not mis then
	    			if previous_op = DOLLAR then
	    				member_stack &= -0.5
	    			else
		    			member_stack &= -Pop()
	    			end if
	    		else
	    			mis = Pop() + Pop()		
				end if

    			
    			-- We don't need this value, so it can go away:
    			tok2 = Pop()
    			
    		elsif subs = 1 then
    			-- Only one subscript, so we can just grab what we need off
    			-- of the cg_stack:

    			if previous_op = DOLLAR then
    				member_stack &= -0.5
    			else
    				member_stack &= -Pop()	
    			end if

--				mis = Pop()
    			current_instance &= Pop()


    		else
    			current_instance &= left_sym	
    		end if

	    	if preprocess then
	    		tok1 = length(line_tokens) - 1	
	    	end if

		    while tok[T_ID] = DOT_NOTATION do
		    	if not var_class( current_instance[$] ) then
		    		-- sequence of with subscripts fools us here...
		    		current_instance[$] = current_sequence[$]
		    	end if
				tok = next_token()
				hide_member[$] &= tok[T_SYM]
				member_stack &= is_member( tok )
				if member_stack[$] = 0 then
					member_stack = member_stack[1..$-1]
					call_proc( forward_method, {tok})
					if seq_of then
						current_instance = current_instance[1..$-2]
					else
						current_instance = current_instance[1..$-1]
					end if
					
					lhs_ptr = FALSE
					if preprocess then
						release_line()
					end if
					
					return
				end if
				tok = next_token()

		    end while
		    
	    	if preprocess then
	    	-- bet this doesn't work:
	    		pdec = SymTab[current_instance[$]][S_NAME]

	    		tokm = tok1 - 2
	    		
	    		for m = 2 to length(member_stack) do
	    			if member_stack[m] > 0 then
		    			class = member_table[MEMBER_CLASS][member_stack[m]]
		    			pdec &= sprintf( "[%s_MEMBER_%s]", 
		    				{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[m]]})
		    			tokn += 2
		    		else
		    			-- it's negative, which means it's a subscript or a dollar sign, so
		    			-- we don't actually need to replace the contents
						tokn = tokm
						pdec &= token_text(tokn)
						while line_tokens[tokn][T_ID] != RIGHT_SQUARE do
							tokn += 1
							pdec &= token_text(tokn)
						end while
						tokm = tokn
						tok1 -= 3
	    			end if
	    			
	    		end for

				tok2 = tokn --tok1 + (length(member_stack)-1) * 2
				replace_tokens( tok1, tok2, pdec )
		    	
	    	end if
	    	
			-- need to emit subscripts....
	    	emit_opnd( current_instance[$] )

	    	for m = 2 to length(member_stack) do
--	    		if m > 2 then
--	    			emit_opnd( current_sequence[$] )
--	    		end if
	    		if member_stack[m] > 0 then
	    			emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
--	    			emit_op( LHS_SUBS )
	    		elsif integer( member_stack[m] ) then
	    			emit_opnd( -member_stack[m] )
--	    			emit_op( LHS_SUBS )
	    		else
	    			emit_op( DOLLAR )
--	    			emit_op( LHS_SUBS )
	    		end if
	    		
--			    current_sequence = current_sequence[1..$-1]
			    if subs = 1 then
					-- first subscript of 2 or more
	
					subs1_patch = length(Code)+1
					emit_op(LHS_SUBS1) -- creates new current_sequence
							   -- opcode might be patched (below)

			    elsif m < length(member_stack) then
					emit_op(LHS_SUBS) -- creates new current_sequence

			    end if
			    subs += 1

	    	end for
	    	
	    else
		    lhs_ptr = FALSE
			if preprocess then
				release_line()
			end if
	    	return
	    end if
    end if
    -- end mwl
    
    lhs_ptr = FALSE
    
    assign_op = tok[T_ID]
    if not find(assign_op, {EQUALS, PLUS_EQUALS, MINUS_EQUALS, MULTIPLY_EQUALS, 
			    DIVIDE_EQUALS, CONCAT_EQUALS}) then
		CompileErr("Syntax error - expected to see =, +=, -=, *=, /= or &=")
		if preprocess then
			release_line()
		end if
		return
    end if

	-- begin mwl
    -- have to add this to 'buffer' so that Method/MethodFunc
    -- don't think there's an 'active' member
    member_stack &= 0
    -- end mwl
    
    if subs = 0 then
	-- not subscripted 
	if assign_op = EQUALS then
	    Expr() -- RHS expression
	    InitCheck(left_sym, FALSE)
	else 
	    InitCheck(left_sym, TRUE)
	    SymTab[left_sym][S_USAGE] = or_bits(SymTab[left_sym][S_USAGE], U_READ)
	    emit_opnd(left_sym)
	    Expr() -- RHS expression
	    emit_assign_op(assign_op)
	end if

	emit_op(ASSIGN)
	TypeCheck(left_sym)

    else 
	-- subscripted 
	factors = 0
	lhs_subs_level = -1
	Expr() -- RHS expression
	
	if subs > 1 then
	    if SymTab[left_sym][S_SCOPE] != SC_PRIVATE and
	       and_bits(side_effect_calls, 
			power(2, remainder(left_sym, E_SIZE))) then
		-- this var might be overwritten by a function call while
		-- we are executing this statement
		dangerous = TRUE
	    end if
	    
	    if factors = 1 and 
	       lhs_subs_level >= 0 and 
	       lhs_subs_level < subs+slice then
		-- must avoid a possible circular reference
		dangerous = TRUE  
	    end if
	    
	    if dangerous then
		-- Patch earlier op so it will copy lhs var to 
		-- a temp to avoid any problem.
		-- (This danger became greater when we implemented $ for 2.5,
		-- and had to interleave LHS subscripting with expression
		-- evaluation).
		backpatch(subs1_patch, LHS_SUBS1_COPY)
	    end if
	end if
	
	if slice then 
	    if assign_op != EQUALS then
		if subs = 1 then
		    emit_op(ASSIGN_OP_SLICE)
		else    
		    emit_op(PASSIGN_OP_SLICE)
		end if
		emit_assign_op(assign_op)
	    end if
	    if subs = 1 then
		emit_op(ASSIGN_SLICE)
	    else    
		emit_op(PASSIGN_SLICE)
	    end if
	else 
	    if assign_op = EQUALS then
		if subs = 1 then
		    emit_op(ASSIGN_SUBS)
		else
		    emit_op(PASSIGN_SUBS)
		end if
	    else 
		if subs = 1 then
		    emit_op(ASSIGN_OP_SUBS)
		else
		    emit_op(PASSIGN_OP_SUBS)
		end if
		emit_assign_op(assign_op)
		if subs = 1 then
		    emit_op(ASSIGN_SUBS2)
		else    
		    emit_op(PASSIGN_SUBS)
		end if
	    end if
	end if
	
	if subs > 1 then
	    if dangerous then
		-- copy temp back into lhs var
		emit_opnd(left_sym)
		emit_opnd(lhs_subs1_copy_temp) -- will be freed 
		emit_op(ASSIGN)
	    else
		TempFree(lhs_subs1_copy_temp)
	    end if
	end if
	
	if OpTypeCheck and SymTab[left_sym][S_VTYPE] != sequence_type then
	    TypeCheck(left_sym)
	end if
    end if

    current_sequence = current_sequence[1..$-1]
    -- begin mwl
    current_instance = current_instance[1..$-1]
    member_stack = member_stack[1..len_member_stack]
	if preprocess then
		release_line()
	end if
    -- end mwl
    if not TRANSLATE then
	if OpTrace then 
	    emit_op(DISPLAY_VAR)
	    emit_addr(left_sym)
	end if
    end if
    
    -- begin mwl
    if seq_of then
	    current_instance = current_instance[1..$-1]
	    seq_of = Pop()
    end if
	
	-- These two lines are ugly, ugly hacks.  There is a 
	-- leak somewhere.
	cg_stack = cg
	current_sequence = cs

    -- end mwl
end procedure

procedure Return_statement()
-- Parse a return statement 
    token tok
    
    if CurrentSub = TopLevelSub then
	CompileErr("return must be inside a procedure or function")
	return
    end if
    if not TRANSLATE then    
	if OpTrace then
	    emit_op(ERASE_PRIVATE_NAMES)
	    emit_addr(CurrentSub)
	end if
    end if
    if SymTab[CurrentSub][S_TOKEN] != r:PROC then
	Expr()
	FuncReturn = TRUE
	emit_op(RETURNF)
    else 
	emit_op(RETURNP)
    end if
    tok = next_token()
    putback(tok)
    NotReached(tok[T_ID], "return")
end procedure

procedure Exit_statement()
-- Parse an exit statement 
    token tok
    
    if loop_nest = 0 then
	CompileErr("exit statement must be inside a loop")
	return
    end if
    emit_op(EXIT)
    AppendXList(length(Code)+1)
    emit_forward_addr()     -- to be back-patched 
    tok = next_token()
    putback(tok)
    NotReached(tok[T_ID], "exit")
end procedure

integer forward_Statement_list 

procedure If_statement()
-- parse an if statement with optional elsif's and optional else 
    token tok
    integer prev_false 
    integer prev_false2
    integer elist_base

    elist_base = length(elist)
    short_circuit += 1
    short_circuit_B = FALSE
    SC1_type = 0
    Expr()
    emit_op(IF)
    prev_false = length(Code)+1
    prev_false2 = 0
    emit_forward_addr() -- to be patched 
    if SC1_type = OR then
		backpatch(SC1_patch-3, SC1_OR_IF)
		if TRANSLATE then
		    emit_op(NOP1)  -- to get label here
		end if
		backpatch(SC1_patch, length(Code)+1)
    elsif SC1_type = AND then
		backpatch(SC1_patch-3, SC1_AND_IF)
		prev_false2 = SC1_patch
    end if
    short_circuit -= 1
    tok_match(THEN)
    call_proc(forward_Statement_list, {})
    tok = next_token()

    while tok[T_ID] = ELSIF do
		emit_op(ELSE)
		AppendEList(length(Code)+1)
		emit_forward_addr()  -- to be patched 
		if TRANSLATE then
		    emit_op(NOP1)
		end if
		backpatch(prev_false, length(Code)+1)
		if prev_false2 != 0 then
		    backpatch(prev_false2, length(Code)+1)
		end if
		StartSourceLine(TRUE)
		short_circuit += 1
		short_circuit_B = FALSE
		SC1_type = 0
		Expr()
		emit_op(IF)
		prev_false = length(Code)+1
		prev_false2 = 0
		emit_forward_addr() -- to be patched 
		if SC1_type = OR then
		    backpatch(SC1_patch-3, SC1_OR_IF)
		    if TRANSLATE then
			emit_op(NOP1)
		    end if
		    backpatch(SC1_patch, length(Code)+1)
		elsif SC1_type = AND then
		    backpatch(SC1_patch-3, SC1_AND_IF)
		    prev_false2 = SC1_patch
		end if
		short_circuit -= 1
		tok_match(THEN)
		call_proc(forward_Statement_list, {})
		tok = next_token()
    end while

    if tok[T_ID] = ELSE then 
		StartSourceLine(FALSE)
		emit_op(ELSE)
		AppendEList(length(Code)+1)
		emit_forward_addr() -- to be patched 
		if TRANSLATE then
		    emit_op(NOP1)
		end if
		backpatch(prev_false, length(Code)+1)
		if prev_false2 != 0 then
		    backpatch(prev_false2, length(Code)+1)
		end if
		call_proc(forward_Statement_list, {})
	
    else 
		putback(tok)
		if TRANSLATE then
		    emit_op(NOP1)
		end if
		backpatch(prev_false, length(Code)+1)
		if prev_false2 != 0 then
		    backpatch(prev_false2, length(Code)+1)
		end if
    end if
   
    tok_match(END) 
    tok_match(IF)
    
    if TRANSLATE then
	if length(elist) > elist_base then
	    emit_op(NOP1)  -- to emit label here
	end if
    end if
    PatchEList(elist_base)
end procedure


procedure While_statement()
-- Parse a while loop 
    integer bp1 
    integer bp2
    integer exit_base

    if TRANSLATE then
		emit_op(NOPWHILE)
    end if

    
    bp1 = length(Code)+1
    short_circuit += 1
    short_circuit_B = FALSE
    SC1_type = 0
    Expr()
    tok_match(DO)
    optimized_while = FALSE
    emit_op(WHILE)
    short_circuit -= 1

    if not optimized_while then
		-- WHILE was emitted or combined into IFW op 
		bp2 = length(Code)+1
		emit_forward_addr() -- will be patched 
    else -- WHILE TRUE was optimized to nothing 
		bp2 = 0
    end if

    
    loop_nest += 1
    exit_base = length(exit_list)
    if SC1_type = OR then
		backpatch(SC1_patch-3, SC1_OR_IF)
		if TRANSLATE then
		    emit_op(NOP1)
		end if
		backpatch(SC1_patch, length(Code)+1)
    elsif SC1_type = AND then
		backpatch(SC1_patch-3, SC1_AND_IF)
		AppendXList(SC1_patch)
    end if


    -- begin mwl
    loop_stack &= WHILE
    loop_sym_stack &= 0
    loop_bp_stack &= {{bp1, bp2}}
    -- end mwl
	    
    call_proc(forward_Statement_list, {})
    tok_match(END)
    tok_match(WHILE)
    StartSourceLine(TRUE)
    emit_op(ENDWHILE)
    loop_nest -= 1
    emit_addr(bp1)
    
    if TRANSLATE then
		emit_op(NOP1)
    end if
    if bp2 != 0 then
		backpatch(bp2, length(Code)+1)
    end if
    
    PatchXList(exit_base)

    -- begin mwl
    loop_stack = loop_stack[1..$-1]
    loop_sym_stack = loop_sym_stack[1..$-1]
    loop_bp_stack = loop_bp_stack[1..$-1]
    -- ene mwl
end procedure

function SetPrivateScope(symtab_index s, symtab_index type_sym, integer n)
-- establish private scope for variable s in SymTab 
-- (index may be changed - new value is returned) 
    integer hashval, scope
    symtab_index t
    
    scope = SymTab[s][S_SCOPE]
    
    if find(scope, {SC_PRIVATE, SC_LOOP_VAR}) then
	DefinedYet(s)
	return s

    elsif find(scope, {SC_UNDEFINED, SC_MULTIPLY_DEFINED}) then
	SymTab[s][S_SCOPE] = SC_PRIVATE
	SymTab[s][S_VARNUM] = n
	SymTab[s][S_VTYPE] = type_sym
	return s

    elsif find(scope, {SC_LOCAL, SC_GLOBAL, SC_PREDEF}) then
	hashval = SymTab[s][S_HASHVAL]
	t = buckets[hashval]
	buckets[hashval] = NewEntry(SymTab[s][S_NAME], n, SC_PRIVATE, 
				    VARIABLE, hashval, t, type_sym)
	return buckets[hashval]
    else
	InternalErr("SetPS")
	
    end if
    
    return 0
end function

procedure For_statement()
-- Parse a for statement 
    integer bp1
    integer exit_base
    token tok, loop_var
    symtab_index loop_var_sym
    boolean def1

    loop_var = next_token()
    if not find(loop_var[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC}) then
		CompileErr("a loop variable name is expected here")
		return
    end if
    
    add_ref(loop_var)
    tok_match(EQUALS)
    Expr()
    tok_match(TO)
    loop_nest += 1
    exit_base = length(exit_list)    
    Expr()
    tok = next_token()
    if tok[T_ID] = BY then
		Expr()
		def1 = FALSE
    else 
		emit_opnd(NewIntSym(1))
		putback(tok)
		def1 = TRUE
    end if

    loop_var_sym = loop_var[T_SYM]
    if CurrentSub = TopLevelSub then
		DefinedYet(loop_var_sym)
		SymTab[loop_var_sym][S_SCOPE] = SC_GLOOP_VAR
		SymTab[loop_var_sym][S_VTYPE] = object_type
    else 

		loop_var_sym = SetPrivateScope(loop_var_sym, object_type, param_num)
		param_num += 1
		SymTab[loop_var_sym][S_SCOPE] = SC_LOOP_VAR
    end if
    
    SymTab[loop_var_sym][S_USAGE] = or_bits(SymTab[loop_var_sym][S_USAGE], 
					  or_bits(U_READ, U_WRITTEN))

    op_info1 = loop_var_sym
 
    emit_op(FOR)

    emit_addr(loop_var_sym)
    tok_match(DO)
    bp1 = length(Code)+1
    emit_addr(0) -- will be patched - don't straighten 

    -- begin mwl
    loop_stack &= FOR
    loop_sym_stack &= loop_var_sym
    loop_bp_stack &= bp1
    -- end mwl
    

    if not TRANSLATE then
	if OpTrace then
	    emit_op(DISPLAY_VAR)
	    emit_addr(loop_var_sym)
	end if
    end if

    call_proc(forward_Statement_list, {})

    tok_match(END)
    tok_match(FOR)
    StartSourceLine(TRUE)
    op_info1 = loop_var_sym
    op_info2 = bp1 + 1

    if def1 then
		emit_op(ENDFOR_INT_UP1) -- (loop var might not be integer)
    else
		emit_op(ENDFOR_GENERAL) -- will be set at runtime by FOR op 
    end if
    
    backpatch(bp1, length(Code)+1)
    PatchXList(exit_base)
    loop_nest -= 1
    
    if not TRANSLATE then
	if OpTrace then
	    emit_op(ERASE_SYMBOL)
	    emit_addr(loop_var_sym)
	end if
    end if  
    Hide(loop_var_sym)
    -- begin mwl
    loop_stack = loop_stack[1..$-1]
    loop_sym_stack = loop_sym_stack[1..$-1]
    loop_bp_stack = loop_bp_stack[1..$-1]
    -- end mwl
end procedure

-- begin mwl
procedure Goto_Label()
-- Parse a goto label that starts with a ':'
	token tok
	symtab_index ix, id
	object label
	
	if preprocess then
		CompileErr("goto not allowed in preprocessing")
	end if
	
	Expr()
	
--	tok = next_token()
--	id = tok[T_ID]
--	ix = tok[T_SYM]
	if atom(SymTab[CurrentSub][S_GOTO]) then
		SymTab[CurrentSub][S_GOTO] = { {}, {}, {{},{}}}
	end if
--	
--	if find( id, {ATOM, STRING, CONSTANT}) then
--		label = { current_file_no, SymTab[ix][S_OBJ]}
--
--	elsif id = VARIABLE then
--		UndefinedVar(ix)
--		label = { current_file_no, NOVALUE, ix }		
--	
--	elsif id = LEFT_BRACE then
--		putback( tok )
--		Expr()
		
		-- now have to use the value put there by the expression...
		ix = Pop()
		if compare(SymTab[ix][S_OBJ], NOVALUE) then
			-- the expression was evaluated at compile time, so it can be 
			-- used as a static label
			label = { current_file_no, SymTab[ix][S_OBJ] }
		else
			-- The expression needs to be evaluated at run time.
			-- Don't allow it to be reused, or the label will disappear.
			-- Should this be a warning?
			SymTab[ix][S_SCOPE] = IN_USE 
			label = { current_file_no, NOVALUE, ix } 		
		end if
--	else
--		CompileErr( sprintf("Expected a literal, constant or variable, not a %s", {LexName(id)}))
--		return
--		
--	end if

	if find( label, SymTab[CurrentSub][S_GOTO][G_LABEL] ) then
		CompileErr( "Duplicate goto label" )
		return
	else
		SymTab[CurrentSub][S_GOTO][G_LABEL] = append( SymTab[CurrentSub][S_GOTO][G_LABEL], label )
		SymTab[CurrentSub][S_GOTO][G_PC] &= length(Code) + 1
	end if	
end procedure

procedure Goto_Statement()
-- Parses a goto statement.
	integer addr, ix, file
	StartSourceLine(TRUE)
	emit_opnd( current_file_no )
	Expr()
	addr = Pop()
	
	if sequence( SymTab[CurrentSub][S_GOTO] ) then
		ix = find( {current_file_no, SymTab[addr][S_OBJ]}, SymTab[CurrentSub][S_GOTO][G_LABEL] )
		if ix then
			-- Can optimize to a static goto.
			-- Take the file off the stack because we're going to 
			-- emit the exact PC value to jump to.
			file = Pop()
			emit_opnd( CurrentSub )
			emit_opnd( SymTab[CurrentSub][S_GOTO][G_PC][ix] )
			emit_op( GOTO_STATIC )
			return		
		end if
	end if
	
	Push(addr)

	-- emit_op() will update goto_patch_stack so that we can try to optimize
	-- the goto when we're done parsing the current SubProgram.  The label
	-- could be forward-referenced here, so we wouldn't know about it yet.
	emit_op( GOTO )		
	
end procedure

procedure Continue_statement()
	token tok
	integer bp1, bp2
	sequence s
	if preprocess then
		CompileErr("continue not allowed in preprocessing")
	end if
		
	if not loop_stack[$] then
		CompileErr( "continue must be inside of loop" )

	elsif loop_stack[$] = FOR then
		-- This stuff was basically copied from the For_statement() parsing.
		-- It acts like an "end for" happens here
	    StartSourceLine(TRUE)
	    op_info1 = loop_sym_stack[$]
	    op_info2 = loop_bp_stack[$] + 1
		s = Pop() & Pop()
		Push( s[2] )
		Push( s[1] )
	    emit_op(ENDFOR_GENERAL) -- will be set at runtime by FOR op
		Push( s[2] )
		Push( s[1] )
	    emit_op(EXIT)
	    AppendXList(length(Code)+1)
	    emit_forward_addr()     -- to be back-patched 
	    tok = next_token()
	    putback(tok)
	    
	elsif loop_stack[$] = WHILE then
		-- Just acts like an "end while", which simply jumps back to
		-- the beginning of the while-loop.
		bp1 = loop_bp_stack[$][1]
		bp2 = loop_bp_stack[$][1]
	    StartSourceLine(TRUE)
	    emit_op(ENDWHILE)
	    emit_addr(bp1)
	    	
	end if

end procedure
-- end mwl

procedure Global_declaration(symtab_index type_ptr, integer is_global)
-- parse a command-level variable or constant declaration 
-- type_ptr is NULL if constant 
    token tok
    symtab_index sym
    integer h

	-- begin mwl
	integer class
	
	if type_ptr = sequence_type then
		-- Check for 'sequence of'
		if preprocess then
			cache_line()
		end if
		tok = next_token()
		if tok[T_ID] != OF then
			putback(tok)
		else

			if find(type_ptr, {atom_type, integer_type}) then
				CompileErr("illegal use of 'of'")
				if preprocess then
					release_line()
				end if
				return
			end if			
			
			-- next token should be a valid class name:		
			tok = next_token()
			class = find( tok[T_SYM], class_table[CLASS_SYM] )
			if not class then
				CompileErr("of must be followed by a euclass name")
				if preprocess then
					release_line()
				end if
				return
			end if
			class = sequence_of_class( class )
			type_ptr = class_table[CLASS_SYM][class] 
			if preprocess then
				replace_tokens( length(line_tokens) - 2, length(line_tokens), "sequence" )
			end if
		end if

--	end if
	
	elsif preprocess then
		cache_line()
		if type_ptr and find( type_ptr, class_table[CLASS_SYM] ) then
			replace_tokens( length(line_tokens)-1, length(line_tokens)-1,
				SymTab[real_type(type_ptr)][S_NAME] )
		end if
	end if
	-- end mwl

    while TRUE do 
		tok = next_token()
		-- begin mwl
		-- added class:
		if not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, CLASS}) then
		-- end mwl
		    CompileErr("a name is expected here")
			if preprocess then
				release_line()
			end if
		    return
		end if
		sym = tok[T_SYM]
		DefinedYet(sym)
		if find(SymTab[sym][S_SCOPE], {SC_GLOBAL, SC_PREDEF}) then
		    h = SymTab[sym][S_HASHVAL]
		    -- create a new entry at beginning of this hash chain 
		    sym = NewEntry(SymTab[sym][S_NAME], 0, 0, VARIABLE, h, buckets[h], 0) 
		    buckets[h] = sym
		    -- more fields set below: 
		end if
		if is_global then
		    SymTab[sym][S_SCOPE] = SC_GLOBAL 
		else    
		    SymTab[sym][S_SCOPE] = SC_LOCAL
		end if
		if type_ptr = 0 then
		    -- CONSTANT 
		    SymTab[sym][S_MODE] = M_CONSTANT 
		    -- temporarily hide sym so it can't be used in defining itself 
		    buckets[SymTab[sym][S_HASHVAL]] = SymTab[sym][S_SAMEHASH]
		    tok_match(EQUALS)
		    StartSourceLine(FALSE)
		    emit_opnd(sym)
		    Expr()  -- no new symbols can be defined in here 
		    buckets[SymTab[sym][S_HASHVAL]] = sym
		    SymTab[sym][S_USAGE] = U_WRITTEN     
		    emit_op(ASSIGN)
		else 
		    -- variable 
		    SymTab[sym][S_MODE] = M_NORMAL
		    if SymTab[type_ptr][S_TOKEN] = OBJECT then
				SymTab[sym][S_VTYPE] = object_type
		    else 
				SymTab[sym][S_VTYPE] = type_ptr
		    end if
		end if
		tok = next_token()
		if tok[T_ID] != COMMA then
		    exit
		end if
    end while 
    putback(tok)
    -- begin mwl
	if preprocess then
		release_line()
	end if
	-- end mwl
end procedure

procedure Private_declaration(symtab_index type_sym)
-- parse a private declaration of one or more variables 
    token tok, tok2
    symtab_index sym    
	integer of_, class
	tok2 = {0,type_sym}
	-- begin mwl

	if preprocess then
	cache_line()
	if type_sym and find( type_sym, class_table[CLASS_SYM]) then
		replace_tokens( length(line_tokens), length(line_tokens), 
			SymTab[real_type(type_sym)][S_NAME] )
	end if
	end if
	of_ = 0
	if type_sym = sequence_type then

		tok = next_token()
		if tok[T_ID] != OF then
			putback(tok)
		else
			of_ = 2
			-- next token should be a valid class name:		
			tok = next_token()
			class = find( tok[T_SYM], class_table[CLASS_SYM] )
			if not class then
				CompileErr("'of' must be followed by a euclass name")
				if preprocess then
					release_line()
				end if
				return
			end if
			class = sequence_of_class( class )
			type_sym = class_table[CLASS_SYM][class] 
			if preprocess then
				replace_tokens( length(line_tokens) - 2, length(line_tokens), "sequence" )
			end if
		end if
		
	end if
	-- end mwl			
    while TRUE do 
		tok = next_token()
		if not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, NAMESPACE}) then
			-- begin mwl			
			if tok[T_ID] = DOT_NOTATION then
				current_instance &= tok2[T_SYM]
				exit
			else
			    CompileErr("a variable name is expected here")
			    if preprocess then
			    	release_line()
			    end if
			    return
			end if
			-- end mwl
		else
		end if
		
		
		tok2 = tok
		sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
		param_num += 1
		tok = next_token()
		if tok[T_ID] != COMMA then
		    exit
		end if
    end while 
    if preprocess then
    	release_line()
    end if
    putback(tok)
end procedure

-- begin mwl
procedure Member_declaration(symtab_index type_sym)
-- parse a member declaration of one or more variables 
    token tok, tok2
    symtab_index sym
    integer members, count, member
    sequence replacement
    integer class, of_
    
    if preprocess then
    	cache_line()
    end if
    
    members = member_count( current_class )
    count = 0
	tok2 = {0,type_sym}
	of_ = 0
	if type_sym = sequence_type then

		tok = next_token()
		if tok[T_ID] != OF then
			putback(tok)
		else
			of_ = 2
			-- next token should be a valid class name:		
			tok = next_token()
			class = find( tok[T_SYM], class_table[CLASS_SYM] )
			if not class then
				CompileErr("'of' must be followed by a euclass name")
				if preprocess then
					release_line()
				end if
				return
			end if
			class = sequence_of_class( class )
			type_sym = class_table[CLASS_SYM][class] 
		end if
		
	end if
	
    while TRUE do 
		tok = next_token()
		if not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, NAMESPACE}) then
		    CompileErr("a variable name is expected here")
			if preprocess then
				release_line()
			end if
		    return
		end if

		if preprocess then
			if count then
				replacement = ""
			else
				
				if SymTab[class_table[CLASS_SYM][current_class]][S_SCOPE] = GLOBAL then
					replacement = "global constant "
				else
					replacement = "constant "
				end if
				
			end if

			-- EUCLASSNAME_MEMBER_MEMBERNAME = member
			members += 1
			replacement &= sprintf("%s_MEMBER_%s = %d", 
				{SymTab[class_table[CLASS_SYM][current_class]][S_NAME],
				SymTab[tok[T_SYM]][S_NAME], members})
			if count then
				replace_tokens( length(line_tokens), length(line_tokens), replacement )
			else
				replace_tokens( length(line_tokens)-1-of_, length(line_tokens), replacement )
			end if
			
			count += 1
		end if

		if SymTab[tok[T_SYM]][S_SCOPE] != SC_UNDEFINED then
			tok = keyfind( SymTab[tok[T_SYM]][S_NAME] & 127, -1 )
			SymTab[tok[T_SYM]][S_NAME] = SymTab[tok[T_SYM]][S_NAME][1..$-1]
			--SymTab[tok[T_SYM]][S_NAME] &= -1
		end if

		
		
		SymTab[tok[T_SYM]][S_VTYPE] = type_sym
		member = add_member( tok[T_SYM] )
		
		-- decorate the name:
		SymTab[tok[T_SYM]][S_NAME] &= "@" & SymTab[class_table[CLASS_SYM][current_class]][S_NAME]
		
		tok2 = tok
		-- sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
		
		tok = next_token()
		if tok[T_ID] != COMMA then
		    exit
		end if
    end while
	if preprocess then
		release_line()
	end if
    putback(tok)
end procedure
-- end mwl

procedure Procedure_call(token tok)
-- parse a procedure call statement 
    integer n, scope, opcode
    token temp_tok
    symtab_index s
	
    s = tok[T_SYM] 
    n = SymTab[s][S_NUM_ARGS]
    scope = SymTab[s][S_SCOPE]
    opcode = SymTab[s][S_OPCODE]
	
	-- begin mwl
	add_ref( tok )

    tok_match(LEFT_ROUND)

    if SymTab[s][S_EFFECT] then
		SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
						       SymTab[s][S_EFFECT])
    end if
    ParseArgs(s)
    
    if scope = SC_PREDEF then
		emit_op(opcode)
		if opcode = ABORT then
		    temp_tok = next_token()
		    putback(temp_tok)
		    NotReached(temp_tok[T_ID], "abort()")
		end if
    else 
		op_info1 = s
		emit_op(r:PROC)
		if not TRANSLATE then
		    if OpTrace then
			emit_op(UPDATE_GLOBALS)
		    end if
		end if  
    end if

end procedure

procedure Print_statement()
-- parse a '?' print statement 

    emit_opnd(NewIntSym(1)) -- stdout 

    Expr()
    emit_op(QPRINT)
    SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
					   E_OTHER_EFFECT)
end procedure

procedure Statement_list()
-- Parse a list of statements 
    token tok
    integer id

    stmt_nest += 1
    while TRUE do 
	tok = next_token()
	id = tok[T_ID]
	
	if id = VARIABLE or id = QUALIFIED_VARIABLE then
		-- begin mwl
		StartSourceLine(TRUE)

		if length(current_instance) and current_instance[$] then
			-- really a procedure or function call
			call_proc( forward_method, { tok } )
			current_instance = current_instance[1..$-1]
		else
		    
		    Assignment(tok)
		end if
		-- end mwl
	    
	elsif id = r:PROC or id = QUALIFIED_PROC then
	    StartSourceLine(TRUE)
	    Procedure_call(tok)
	    
	elsif id = IF then
	    StartSourceLine(TRUE)
	    If_statement()
	    
	elsif id = FOR then
	    StartSourceLine(TRUE)
	    For_statement()
	    
	elsif id = RETURN then
	    StartSourceLine(TRUE)
	    Return_statement()
	    
	elsif id = EXIT then
	    StartSourceLine(TRUE)
	    Exit_statement()
	    
	elsif id = WHILE then
	    StartSourceLine(TRUE)
	    While_statement()
	    
	elsif id = QUESTION_MARK then
	    StartSourceLine(TRUE)
	    Print_statement()

	-- begin mwl
	elsif id = DOT_NOTATION then 
		tok = next_token()
		hide_member[$] &= tok[T_SYM]
		StartSourceLine( TRUE )
		call_proc( forward_method, { tok } )
		current_instance = current_instance[1..$-1]
	elsif id = TYPE and find( tok[T_SYM], class_table[CLASS_SYM] ) then
		StartSourceLine(TRUE)
		current_instance &= tok[T_SYM]
		tok = next_token()
		if tok[T_ID] != DOT_NOTATION then
			CompileErr( "Missing method call")
			return
		end if
		tok = next_token()
		call_proc( forward_method, {tok} )
		current_instance = current_instance[1..$-1]
	elsif id = CONTINUE then
		Continue_statement()
	elsif id = COLON then
		Goto_Label()
	
	elsif id = GOTO then
		Goto_Statement()
	-- end mwl

	else 
	    putback(tok)
	    stmt_nest -= 1
	    InitDelete()
	    return
	
	end if
    end while
end procedure

forward_Statement_list = routine_id("Statement_list")

function pp_decorate( sequence pdec )

	for d = 1 to length(pdec) do
		if find(pdec[d], "@!") then
			pdec[d] = '_'
		end if
	end for
	return pdec
end function

global function find_label( sequence gotos, sequence label )
-- Finds a goto label.  First looks for a static label, and then
-- checks the dynamic labels.
	integer ix
	
	ix = find( label, gotos[G_LABEL] )
	if ix then
		-- found a static label
		return ix
	end if
	
	-- there weren't any static labels, so look for a dynamic label
	for i = 1 to length(gotos[G_LABEL]) do
		if length(gotos[G_LABEL][i]) = 3 and label[1] = gotos[G_LABEL][i][1] 
		and equal( SymTab[gotos[G_LABEL][i][3]][S_OBJ], label[2] ) then
				
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

procedure PatchGotos()
-- Optimize gotos if the goto target and label are both known at 
-- compile time.  This saves having to look up the label at 
-- run time.
	sequence patch_list
	integer  pc, file, ix
	object label, gotos
	
	if not length(goto_back_patch) then
		return
	end if
	
	patch_list = goto_back_patch[$]
	
	-- gotos could be an atom here if no gotos are defined.  In that case,
	-- patch_list will be empty, so we'll never go into the for-loop and
	-- try to subscript an atom.
	gotos = SymTab[CurrentSub][S_GOTO]
	if atom(gotos) then
		-- need to make this a sequence...
		SymTab[CurrentSub][S_GOTO] = {{},{},{}}
	end if
	for i = 1 to length( patch_list ) do
		pc = patch_list[i]
		label = Code[pc+1]

		if length(SymTab[label]) < SIZEOF_VAR_ENTRY or SymTab[label][S_MODE] = M_CONSTANT and
		compare(SymTab[label][S_OBJ], NOVALUE) then
			file  = Code[pc+2]
			label = SymTab[label][S_OBJ]
			ix = find_label( gotos, {file, label})
			if ix then
				-- can patch this to a static goto
				Code[pc]   = GOTO_STATIC
				Code[pc+1] = gotos[G_PC][ix]
				Code[pc+2] = CurrentSub
			end if			
		end if

	end for
	goto_back_patch = goto_back_patch[1..$-1]
end procedure

procedure SubProg(integer prog_type, integer is_global)
-- parse a function, type or procedure 
-- global is 1 if it's global 
    integer h, pt, is_constructor, cached
    symtab_index p, type_sym, sym
    token tok, prog_name
	-- begin mwl
	sequence decorated, pdec, by_ref
	integer class, seq_of_class, ix, tok1, tok2, is_ref
	
	hide_member = append( hide_member, {} )
	by_ref = {}
    -- end mwl
    goto_back_patch = append( goto_back_patch, {} )
	LeaveTopLevel()
	
	if preprocess then
		cache_line()
	end if
	
	-- begin mwl
	if current_class then
		tok = next_token()
		if tok[T_ID] = MULTIPLY then
			by_ref &= 0
		else
			putback( tok )
		end if
	end if
	-- end mwl
	
    prog_name = next_token()
    if not find(prog_name[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC}) then
		CompileErr("a name is expected here")
		if preprocess then
			release_line()
		end if
		return
    end if
    p = prog_name[T_SYM] 

	-- begin mwl
	is_constructor = 0
	if current_class then
		
		if find( prog_type, {CLASS, TYPE}) then
			CompileErr( "cannot declare a class or a type from within a class" )
			if preprocess then
				release_line()
			end if
			return
		end if
		
		-- it could have the same name as some other symbol, in which case we need to
		-- make a new one...
		decorated = SymTab[p][S_NAME]
		if length(SymTab[p]) = SIZEOF_ROUTINE_ENTRY then
			tok = keyfind( decorated & 127, -1 )
			p = tok[T_SYM]
		end if
		
		if compare( decorated, class_table[CLASS_NAME][current_class] ) then
			-- it's a normal method
			decorated &= '@' & class_table[CLASS_NAME][current_class] & '@'
		
		else
			-- same name as the class, so it must be a constructor, which
			-- doesn't have the extra 'this' param passed
			if prog_type = PROCEDURE then
				-- it has to be a function!
				CompileErr( "a constructor must be a function" )
				if preprocess then
					release_line()
				end if
				return
				
			end if
			is_constructor = 1
			decorated &= '@'
			
		end if
		

	else 
		DefinedYet(p)
	end if
	-- end mwl
	
    if prog_type = PROCEDURE then
		pt = r:PROC
    elsif prog_type = FUNCTION then
		pt = r:FUNC
    else        
		pt = TYPE
    end if
    
    if find(SymTab[p][S_SCOPE], {SC_PREDEF, SC_GLOBAL}) then
	-- redefine by creating new symbol table entry 
		if SymTab[p][S_SCOPE] = SC_PREDEF then  -- only warn about overriding predefined
		    Warning(sprintf("built-in routine %s() redefined", 
				    {SymTab[p][S_NAME]}))
		end if
		h = SymTab[p][S_HASHVAL]
		sym = buckets[h]
		p = NewEntry(SymTab[p][S_NAME], 0, 0, pt, h, sym, 0) 
		buckets[h] = p
    end if
    CurrentSub = p
    temps_allocated = 0

    if is_global then
		SymTab[p][S_SCOPE] = SC_GLOBAL
	-- begin mwl
	elsif current_class and pt != CLASS then
		-- make the routine have the same scope as the class
		SymTab[p][S_SCOPE] = SymTab[class_table[CLASS_SYM][current_class]][S_SCOPE]
	-- end mwl
    else
		SymTab[p][S_SCOPE] = SC_LOCAL
    end if
		
    SymTab[p][S_TOKEN] = pt
    
    if length(SymTab[p]) < SIZEOF_ROUTINE_ENTRY then
		-- expand var entry to routine entry
		SymTab[p] = SymTab[p] & repeat(0, SIZEOF_ROUTINE_ENTRY - 
					       length(SymTab[p]))
    end if

    SymTab[p][S_CODE] = 0
    SymTab[p][S_LINETAB] = 0
    SymTab[p][S_EFFECT] = E_PURE
    SymTab[p][S_REFLIST] = {}
    
    SymTab[p][S_FIRSTLINE] = gline_number
    SymTab[p][S_TEMPS] = 0
    -- begin mwl
    SymTab[p][S_BYREF] = {}
    -- end mwl
    StartSourceLine(FALSE)  
    tok_match(LEFT_ROUND)
    
    param_num = 0
    
    -- begin mwl
    if current_class and prog_type != CLASS and not is_constructor then
    	-- patch in the 'this' variable
    	type_sym = class_table[CLASS_SYM][current_class]

		tok = keyfind( "this", -1 )
		
		sym = SetPrivateScope( tok[T_SYM], type_sym, param_num )
		SymTab[sym][S_USAGE] = U_WRITTEN

		if length( by_ref ) then
			by_ref[1] = tok[T_SYM]
		end if
		
--		SymTab[p][S_NEXT] = sym
		
		param_num += 1
    end if
	tok = next_token()
    -- end mwl
    
    while tok[T_ID] != RIGHT_ROUND do
		-- parse the parameter declarations
		if tok[T_ID] != TYPE and tok[T_ID] != QUALIFIED_TYPE then
		    if tok[T_ID] = VARIABLE or tok[T_ID] = QUALIFIED_VARIABLE then
				if UndefinedVar(tok[T_SYM]) then
					return
				end if		    

		    end if
		    CompileErr("a type is expected here")            
			if preprocess then
				release_line()
			end if
		    return
		end if
		type_sym = tok[T_SYM]
		tok = next_token()
		-- begin mwl
		is_ref = 0
		
		if tok[T_ID] = MULTIPLY then
			is_ref = 1
			tok = next_token()
		end if
		
		-- add 'sequence of' handling
		if type_sym = sequence_type and tok[T_ID] = OF then

			tok = next_token()

			class = find( tok[T_SYM], class_table[CLASS_SYM] )
			if not class then
				CompileErr("expected a class name")
				if preprocess then
					release_line()
				end if
				return
			end if
			class = sequence_of_class( class )
			type_sym = class_table[CLASS_SYM][class]
			tok = next_token()

			if tok[T_ID] = MULTIPLY then
				is_ref = 1
				tok = next_token()
			end if

		-- end mwl
		elsif not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, NAMESPACE}) then
		    CompileErr("a parameter name is expected here")
			if preprocess then
				release_line()
			end if
		    return
		end if

		-- begin mwl
		sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
		SymTab[sym][S_USAGE] = U_WRITTEN 
		if prog_type = CLASS then
			SymTab[p][S_VTYPE] = type_sym
			SymTab[sym][S_NAME] &= " dummy variable for euclass declaration"
		end if

		if is_ref then
			by_ref &= sym
		end if

		-- end mwl
		param_num += 1

		-- begin mwl
		if current_class then

			if type_sym = atom_type then
				decorated &= 'a'
			elsif type_sym = integer_type then
				decorated &= 'i'
			elsif type_sym = sequence_type then
				decorated &= 's'
			elsif type_sym = object_type then
				decorated &= 'o'
			elsif find( type_sym, class_table[CLASS_SYM]) then
				-- for classes...
				decorated &= '@' & SymTab[SymTab[sym][S_VTYPE]][S_NAME] & '@'
			
			else
				-- UDTs
				
				decorated &= '!' & SymTab[SymTab[sym][S_VTYPE]][S_NAME] & '!'
			end if
		end if
		-- end mwl
		    
		tok = next_token()
		if tok[T_ID] = COMMA then
		    tok = next_token()
		    if tok[T_ID] = RIGHT_ROUND then
				CompileErr("expected to see a parameter declaration, not ')'")
				if preprocess then
					release_line()
				end if
				return
		    end if
		elsif tok[T_ID] != RIGHT_ROUND then
		    CompileErr("badly-formed list of parameters - expected ',' or ')'")
				if preprocess then
					release_line()
				end if
		    return
		end if


    end while
	
	-- begin mwl
	SymTab[p][S_BYREF] = by_ref
	if preprocess then
		if length(by_ref) then
			CompileErr("cannot use pass by reference when proprocessing")
		end if
	if current_class then
		ix = 1
		for t = length(line_tokens) to 1 by -1 do
			if equal( line_tokens[t], {0,0} ) then
				ix = t + 1
				exit
			end if
		end for
		for t = ix to length( line_tokens ) do
--			printf(1, "Token: %d '%s'\n", {t, token_text(t)})
			if find( line_tokens[t][1], {PROCEDURE, FUNCTION})  then
				if not is_global and SymTab[p][S_SCOPE] = SC_GLOBAL then
					-- make it global, because the class is global
					if line_tokens[t][1] = PROCEDURE then
						replace_tokens( t, t, "global procedure")
					else
						replace_tokens( t, t, "global function")
					end if
				end if
				pdec = pp_decorate( decorated )
				if is_constructor then
					pdec &= "( "
					
				else
					pdec &= "( object this"
					if param_num > 1 then
						pdec &= ", "
					else 
						pdec &= 32
					end if	
				
				end if
--				printf( 1,"%d %s => %s\n", {t, decorated, pdec})
				full_line()
				replace_tokens( t + 1, t + 2, pdec )
				
			elsif line_tokens[t][T_ID] = TYPE and line_tokens[t-1][T_ID] != FUNCTION then
				class = find( line_tokens[t][T_SYM], class_table[CLASS_SYM])
				if class then
					-- a class type is here in the parameter declaration
					full_line()
					if line_tokens[t-1][T_ID] != OF then
--						printf( 1, "\t%d %s => %s\n", {t,token_text(t),SymTab[real_type(line_tokens[t][2])][S_NAME]})
						replace_tokens( t, t, SymTab[real_type(line_tokens[t][2])][S_NAME] )
					else
						replace_tokens( t-2, t, "sequence" )
					end if
				
--				elsif line_tokens[t+1][T_ID] = OF then
--					replace_tokens( t, t+1, "" )
				end if 
			end if
		end for

		
	end if
	end if
	-- end mwl
    SymTab[p][S_NUM_ARGS] = param_num
    if TRANSLATE then
		if param_num > max_params then
		    max_params = param_num
		end if
		num_routines += 1
    end if
    if SymTab[p][S_TOKEN] = TYPE and param_num != 1 then
--		CompileErr("types must have exactly one parameter")
	-- begin mwl
		CompileErr("types and classes must have exactly one parameter")
		if preprocess then
			release_line()
		end if
		return
	elsif prog_type = CLASS then
		-- the class table will remember the actual variable type
		current_class = new_class( p )
		seq_of_class = sequence_of_class( current_class )
		if preprocess then
			-- comment out the class declaration:
--			cache_line()
			for class_token = 1 to length(line_tokens) do
				if line_tokens[class_token][T_ID] = CLASS then

					if is_global then
						pdec = "-- global euclass"
					else
						pdec = "-- euclass"
					end if
					replace_tokens( class_token - is_global, class_token, pdec)
				end if
			end for
		end if
    end if

	-- defined return types:
	-- function foo()
	if pt = r:FUNC then
--		if preprocess then
--			cache_line()
--		end if
		
		tok = next_token()
		if tok[T_ID] = COLON then
			tok1 = length(line_tokens)
			tok = next_token()
			
			tok2 = tok1 + 1
			if not find( tok[T_ID], { TYPE, QUALIFIED_TYPE, CLASS }) then
				CompileErr( "expected a type or a class" )
				if preprocess then
					release_line()
				end if
				return
			end if
			if tok[T_SYM] = sequence_type then
				tok = next_token()
				if tok[T_ID] = OF then
					tok = next_token()
					if not sym_to_class( tok[T_SYM] ) then
						CompileErr( "expected a class" )
				if preprocess then
					release_line()
				end if
						return
					end if
					SymTab[p][S_OBJ] = class_table[CLASS_SYM][sequence_of_class( sym_to_class( tok[T_SYM]) )]
					tok2 += 2
				else
					putback( tok )
					SymTab[p][S_OBJ] = sequence_type

				end if
			else
				SymTab[p][S_OBJ] = tok[T_SYM]
			end if
			
			if preprocess then
				replace_tokens( tok1, tok2, "" )
			end if			


		else

			putback( tok )
		end if
--		if preprocess then
--			cache_line()
--		end if
	end if
    
    if preprocess then
    	release_line()
    end if
    
    tok = next_token()
    -- parameters are numbered: 0, 1, ... num_args-1 
    -- other privates are numbered: num_args, num_args+1, ... 


    while tok[T_ID] = TYPE or tok[T_ID] = QUALIFIED_TYPE do
		-- parse the next private variable declaration

		if prog_type = CLASS then
			Member_declaration( tok[T_SYM] )
		else
			Private_declaration(tok[T_SYM])
		end if
		
		tok = next_token()

    end while

	if prog_type != CLASS then
	-- end mwl
	
	    -- start of executable code for subprogram: 
	    -- p->u.subp.entry = length(Code)+1 

	    -- code to perform type checks on all the parameters 
	    sym = SymTab[p][S_NEXT]
	    for i = 1 to SymTab[p][S_NUM_ARGS] do
			TypeCheck(sym)
			sym = SymTab[sym][S_NEXT]
	    end for	
	    
	    if not TRANSLATE then
		if OpTrace then
		    -- clear any private names from screen 
		    emit_op(ERASE_PRIVATE_NAMES)
		    emit_addr(p)
		    -- display initial values of all the parameters 
		    sym = SymTab[p][S_NEXT]
		    for i = 1 to SymTab[p][S_NUM_ARGS] do
			emit_op(DISPLAY_VAR)
			emit_addr(sym)
			sym = SymTab[sym][S_NEXT]
		    end for
		    -- globals may have changed 
		    emit_op(UPDATE_GLOBALS)
		end if
	    end if
	    putback(tok)
	
	    FuncReturn = FALSE
	    -- begin mwl
	    if current_class then

	    	SymTab[p][S_NAME] = decorated
	    	
	    	-- now make sure method is unique
			if find( decorated, method_table[METHOD_NAME] ) then
				CompileErr( sprintf("method '%s' already defined", {decorated}) )
				if preprocess then
					release_line()
				end if
				return
			end if
	    	add_method( p )
	    end if

	    -- end mwl
	    Statement_list()
	    -- begin mwl

	    if prog_type != CLASS then
	    	tok_match(END)
	    else
	    	putback(tok)
	    end if
	    -- end mwl

	    ExitScope()
	    tok_match(prog_type)
	    -- begin mwl
	    if prog_type != PROCEDURE and prog_type != CLASS then
	    -- end mwl
			if not FuncReturn then
			    if prog_type = FUNCTION then
					CompileErr("no value returned from function")
				if preprocess then
					release_line()
				end if
					return
			    else
					CompileErr("type must return true / false value")
				if preprocess then
					release_line()
				end if
					return
			    end if
			end if
			emit_op(BADRETURNF) -- function/type shouldn't reach here 
    
	    else 
			StartSourceLine(TRUE)
			if not TRANSLATE then
			    if OpTrace then
					emit_op(ERASE_PRIVATE_NAMES)
					emit_addr(p)
			    end if
			end if      
			emit_op(RETURNP)
			if TRANSLATE then
			    emit_op(BADRETURNF) -- just to mark end of procedure
			end if  
	    end if
    
	    if temps_allocated + param_num > max_stack_per_call then 
			max_stack_per_call = temps_allocated + param_num
	    end if
	-- begin mwl
	else
		putback(tok)
		ExitScope()
		EnterTopLevel()
	end if
    -- begin mwl
    if current_class then
	    if prog_type != CLASS then
		    StraightenBranches()
		    EnterTopLevel()
	    end if
    else
		PatchGotos()
	    StraightenBranches()
	    EnterTopLevel()
    end if
    

    -- end mwl

end procedure

global procedure InitGlobals()
-- initialize global variables 
    ResetTP()
    OpTypeCheck = TRUE
    OpWarning = TRUE
    
    -- begin mwl
    OpStrictGoto = FALSE
    -- end mwl
end procedure

procedure not_supported_compile(sequence feature)
-- Report that a compile-time feature is not supported in this platform
    CompileErr(sprintf("%s is not supported in Euphoria for %s", 
		  {feature, version_name}))  
end procedure

sequence mix_msg
mix_msg = "can't mix profile and profile_time"

procedure SetWith(integer on_off)
-- set a with/without option 
    sequence option
    token tok
    
    option = StringToken()
    
    if equal(option, "type_check") then
	OpTypeCheck = on_off

    elsif equal(option, "profile") then
	if not TRANSLATE and not BIND then
	    OpProfileStatement = on_off
	    if OpProfileStatement then
		if AnyTimeProfile then
		    Warning(mix_msg)
		    OpProfileStatement = FALSE
		else
		    AnyStatementProfile = TRUE
		end if
	    end if
	end if
    
    elsif equal(option, "profile_time") then
	if not TRANSLATE and not BIND then
	    if not EDOS then
		if on_off then
		    not_supported_compile("profile_time")
		end if
	    end if
	    OpProfileTime = on_off
	    if OpProfileTime then
		if AnyStatementProfile then
		    Warning(mix_msg)
		    OpProfileTime = FALSE
		end if
		tok = next_token()
		if tok[T_ID] = ATOM then
		    if integer(SymTab[tok[T_SYM]][S_OBJ]) then
			sample_size = SymTab[tok[T_SYM]][S_OBJ]
		    else
			sample_size = -1
		    end if
		    if sample_size < 1 and OpProfileTime then
			CompileErr("sample size must be a positive integer")
				if preprocess then
					release_line()
				end if
			return
		    end if
		else 
		    putback(tok)
		    sample_size = DEFAULT_SAMPLE_SIZE
		end if
		if OpProfileTime then
		    if EDOS then
			AnyTimeProfile = TRUE
		    end if
		end if
	    end if
	end if  
    
    elsif equal(option, "trace") then
	if not BIND 
	then 
	    OpTrace = on_off
	end if
    
    elsif equal(option, "warning") then
	OpWarning = on_off
    
    -- begin mwl
    elsif equal(option, "strict_goto") then
    	OpStrictGoto = on_off
    -- end mwl
    elsif on_off and option[1] >= '0' and option[1] <= '9' then
	-- Ignore numeric stamp - not supported anymore
    
    else 
	CompileErr("unknown with/without option")
	return
    
    end if
end procedure

procedure ExecCommand()
-- execute a top-level command  
    if TRANSLATE then
	emit_op(RETURNT)
    end if
    StraightenBranches()  -- straighten top-level
end procedure

-- begin mwl

procedure ParseMethodArgs(token method)
-- parse arguments for a method call 
    integer ix, current
    token tok
    sequence decorated
	symtab_index subsym, class

	subsym = method[T_SYM]
	current = current_instance[$]
	if current then
		class = SymTab[current_instance[$]][S_VTYPE]
	else
		-- it's a constructor, so the name of the token is the name
		-- of the class
		class = find( SymTab[subsym][S_NAME], class_table[CLASS_NAME] )
		if not class then
			CompileErr( sprintf( "%s is undefined", {SymTab[subsym][S_NAME]}))
			return
		end if
		class = class_table[CLASS_SYM][class]
	end if
	
	ix = find( class, class_table[CLASS_SYM] )
	if not ix then
		class = current_instance[$]
		ix = find( class, class_table[CLASS_SYM] )

		if not ix then
			CompileErr( "invalid class instance" )
			return
		end if
		
	end if

	if current_instance[$] then
		decorated = SymTab[subsym][S_NAME] & '@' & class_table[CLASS_NAME][ix] & '@'
		
	else
		decorated = SymTab[subsym][S_NAME] & '@'
	
	end if

	tok = next_token()
	if tok[T_ID] != RIGHT_ROUND then
		putback(tok)
	end if
	
    short_circuit -= 1
	current_instance &= 0

    while tok[T_ID] != RIGHT_ROUND do

		call_proc(forward_expr, {})
	    tok = next_token()
	    if tok[T_ID] != COMMA then
		if tok[T_ID] != RIGHT_ROUND then
		    putback(tok)
		    tok_match(COMMA)
		end if
		end if
		
	end while
	current_instance = current_instance[1..$-1]
    short_circuit += 1
end procedure

function class_base_type( sequence name)
	integer class, ix
	sequence types
	name = name[2..$-1]  -- strip off leading and trailing '@'
	class = find( name, class_table[CLASS_NAME] )
	if not class then
		return ""
	end if
	while class_table[CLASS_PARENT][class] do
		class = class_table[CLASS_PARENT][class]
	end while
	ix = find( class_table[CLASS_VARTYPE][class], {atom_type, integer_type, object_type, sequence_type})
	if not ix then
		ix = 3
	end if
	types = {"a","i","o","s"}
	return types[ix]
end function

-- return 1 for equal types
-- return 0 for compatible
-- return "" for incompatible
-- a1 is the calling argument
-- a2 is what the routine wants
function ArgLCD( sequence a1, sequence a2 )
	integer c, d
	symtab_index sym
	sequence base_type
	
	if equal( a1, a2 ) then
		return 1
	
	elsif equal( a2, "o" ) then
		return 0
	
	elsif a2[1] = '@' then --length( a2 ) > 1 then
		-- a2 is a class...
		if length(a1) = 1 then
			-- have to find out what type 
			a2 = class_base_type( a2 )
			if equal( a1, a2 ) then
				-- same base type
				return 0
			end if
			
			if atom( ArgLCD(a1, a2)) then
				return 0
			end if
			return {}
		end if
		c = find( a1[2..$-1], class_table[CLASS_NAME] )
		if not c then
			CompileErr(sprintf("invalid class: '%s'",{a1}))
			return 0
		end if
		a2 = a2[2..$-1]
		while c and compare( a2, class_table[CLASS_NAME][c] ) do
			c = class_table[CLASS_PARENT][c]
		end while
		if c then
			return 0
		else
			return ""
		end if
	
	elsif a2[1] = '!' then
		-- a2 is a UDT
		return 0
	elsif a1[1] = '@' then --length( a1 ) > 1 then
		-- a1 is a class, but the function didn't call for that...
		c = find( a1[2..$-1], class_table[CLASS_NAME] )
		sym = class_table[CLASS_SYM][c]
		sym = real_type( sym )
		-- Can't tell on a UDT...
		if length( SymTab[sym] ) > S_VTYPE then return 0 end if
		c = match( a2, "iaso" )
		if sym = integer_type then
			
			if c = 1 then return 1	
			elsif c = 2 then return 0
			elsif c = 4 then return 0
			else return {}
			end if
		
		elsif sym = atom_type then
			if c = 1 then return 0
			elsif c = 2 then return 1
			elsif c = 4 then return 0
			else return {}
			end if
		
		elsif sym = sequence_type then
			if c = 3 then return 1
			elsif c = 4 then return 0
			else return {}
			end if
		end if
		
	elsif a1[1] = '!' then
		-- a1 is a UDT
		return 0
		
	else
		c = match( a1, "iaso" )
		d = match( a2, "iaso" )
		if c = d then return 1 end if
		if d = 2 then
			-- atom
			if c = 1 then return 1
			elsif c = 4 then return 0
			else return {}
			end if
		elsif d = 1 then
			-- integer
			if c = 4 then return 0
			elsif c = 2 then return 0
			else return {}
			end if
		else
			-- sequence
			if c < 3 then return {}
			elsif c = 4 then return 0
			else return 1
			end if
			
		end if
	end if
end function

include sort.e

function PolyMorph( integer class_  )
	symtab_index csym
	sequence mlist, real_list, temp_list, candidates, ma_list, methods, name
	integer ok, parent

	if class_table[CLASS_NAME][class_][1] = '_' then
		class_ = class_table[CLASS_SEQUENCEOF][class_]
	end if
	csym = class_table[CLASS_SYM][class_]

    mlist = class_table[CLASS_METHOD][class_]
    real_list = method_args[$]
    candidates = {}
    methods = method_table[METHOD_NAME]
	name = method_name[$] & '@'

    for m = 1 to length(mlist) do
    	if match( name, methods[mlist[m]]) = 1 then
    	
	    	temp_list = real_list
	    	ma_list = method_table[METHOD_ARGLIST][mlist[m]]
	    	if length(temp_list) = length(ma_list) then
		    	ok = 1
		    	for arg = 1 to length(temp_list) do
		    		-- see if the individual args are compatible
		    		temp_list[arg] = ArgLCD( temp_list[arg], ma_list[arg] )
		    		if sequence( temp_list[arg] ) then
		    			ok = 0
		    			exit
		    		end if
		    	end for
		    	if ok then
		    		candidates = append( candidates, {0, mlist[m]})
		    		for q = 1 to length(real_list) do
		    			candidates[$][1] += temp_list[q]
		    		end for
		    	end if    		
		    end if
    	end if
    end for

    if length( candidates ) > 1 then
    	candidates = sort( candidates )
    	if not candidates[$][1] then
			Warning(sprintf("%s:%d - ambiguous method call", 
				{name_ext(file_name[current_file_no]), line_number}))    		    		
    	end if
    elsif not length( candidates ) then
    	-- look in sub classes next
    	parent = class_table[CLASS_PARENT][class_]
    	if not parent then
    		CompileErr(sprintf( "method '%s' does not exist", {SymTab[method_stack[current_method][T_SYM]][S_NAME]}))
    		return 0
    	else
    		return PolyMorph( parent )
    	end if
    	
    end if
    

    return method_table[METHOD_SYM][candidates[$][2]]
end function

function MethodSlice( token tok )
    integer save_factors, save_lhs_subs_level

	while tok[T_ID] = LEFT_SQUARE do
	    if lhs_subs_level >= 0 then
			lhs_subs_level += 1
	    end if
	    save_factors = factors
	    save_lhs_subs_level = lhs_subs_level
	    -- begin mwl
	    -- have to remember to keep parse_method_stack current
	    parse_method_stack &= 0
	    call_proc(forward_expr, {})
	    parse_method_stack = parse_method_stack[1..$-1]
	    -- end mwl
	    tok = next_token()
	    if tok[T_ID] = SLICE then
			call_proc(forward_expr, {})
			emit_op(RHS_SLICE)
--			PopMember()
			tok_match(RIGHT_SQUARE)
			tok = next_token()

			exit
	    else 
			putback(tok)
			tok_match(RIGHT_SQUARE)
			if member_stack[$] = -0.5 then
--				member_stack = member_stack[1..$-1]
--				PopMember()
--				member_stack &= -0.5
			else
				PopMember()
			end if
--			current_sequence = current_sequence[1..$-1]
--			PopMember()
--			emit_op(RHS_SUBS) -- current_sequence will be updated
	    end if
	    factors = save_factors
	    lhs_subs_level = save_lhs_subs_level
	    tok = next_token()
	end while
	return tok
end function

function read_backwards( integer tok1 )
	integer brackets

	brackets = line_tokens[tok1][T_ID] = RIGHT_SQUARE
	while tok1 and brackets do
		tok1 -= 1
		brackets += line_tokens[tok1][T_ID] = RIGHT_SQUARE
		brackets -= line_tokens[tok1][T_ID] = LEFT_SQUARE
	end while
	return tok1 - 1
end function
function num_zeroes( sequence s )
	integer z
	z = 0
	for i = 1 to length(s) do
		if equal( s[i], 0 ) then
			z += 1
		end if
	end for
	return z
end function

procedure MethodFunc( token tok )
-- parse a method call statement 
    integer scope, opcode, class, e, real_instance, tok1, member, tok2, last_member,
    	len_member_stack, first_member, ppoff, orig_member_stack
    symtab_index s, sym, csym
	sequence pdec, first_arg, member_subs, pargs, pop
    integer save_factors, save_lhs_subs_level

	if preprocess then
		cache_line()
	end if

	parse_method_stack &= 1
	
	if tok[T_ID] = DOT_NOTATION then
		tok = next_token()
	end if

	last_member = 0
	len_member_stack = length(member_stack)
	orig_member_stack = len_member_stack
	-- tok1 is the method name, so we need to capture the
	-- instance and the dot to replace them
	tok1 = length(line_tokens) - 2

	member = is_member( tok )
	if member then
		
		tok[T_SYM] = member_table[MEMBER_SYM][member]
		member_stack &= member
		
		-- make sure we get them all, then do a RHS_SUBS...
		tok = next_token()
		while find(tok[T_ID], {DOT_NOTATION, LEFT_SQUARE}) do
			if tok[T_ID] = DOT_NOTATION then
				while tok[T_ID] = DOT_NOTATION do
					tok = next_token()
					last_member = member
					member = is_member( tok )
					member_stack &= member
					if member then
						
						tok = next_token()
						if member_is_sequenceof( member ) then
							if tok[T_ID] = LEFT_SQUARE then
								-- handle the subscripting right here
								tok = MethodSlice( tok )
							end if
						end if
					else
						exit
					end if
					
				end while
			else
				-- This happens when we encounter a square bracket
				tok = MethodSlice( tok )
			end if
		end while
		
		if member_stack[$] then
		-- ended with an actual member, not method
		    sym = current_instance[$]
		    first_member = length(member_stack)
		    while first_member and member_stack[first_member] do
		    	first_member -= 1
		    end while
		    first_member += ( member_stack[first_member] = 0 )
		    
		    if not find( sym, class_table[CLASS_SYM] ) then
		    -- the 'current_instance' is a real instance
				-- OK, ended with a member, so do the RHS_SUBS
				if not is_sequenceof( current_instance[$] ) then
					-- if it's a 'sequence of' the current_sequence should already
					-- have been emitted during subscripting
					emit_opnd( current_instance[$] )
				end if

				for m = first_member to length(member_stack) do
				
				    if lhs_subs_level >= 0 then
						lhs_subs_level += 1
				    end if
				    if member_stack[m] > 0 then
				    	emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
				    	emit_op( RHS_SUBS )

				    elsif integer( member_stack[m] ) then
				    	emit_opnd( - member_stack[m] )				
						emit_op( RHS_SUBS )
						
				    else
				    	emit_op( DOLLAR )
				    	emit_op( RHS_SUBS )
				
				    end if

				end for

		    	if preprocess then
		    		if line_tokens[tok1][T_ID] = RIGHT_SQUARE then
		    			pdec = ""
		    		else
		    			pdec = SymTab[current_instance[$]][S_NAME]
		    		end if
		    		tok2 = tok1
		    		
		    		for m = first_member to length(member_stack) do
		    			if member_stack[m] > 0 then
			    			class = member_table[MEMBER_CLASS][member_stack[m]]
			    			pdec &= sprintf( "[%s_MEMBER_%s]", 
			    				{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[m]]})		    				
			    			tok2 += 2
			    		else
			    			pdec &= sprintf("[%s]", {token_text( tok2 + 2 )})
			    			tok2 += 3
		    			end if
		    		end for
		    		if line_tokens[tok1][T_ID] = RIGHT_SQUARE then
		    			tok1 += 1
		    		end if
		    		replace_tokens( tok1, tok2, pdec )
		    		
		    	end if
		    	
		    	putback(tok)
		    	if tok[T_ID] = LEFT_SQUARE and member_is_sequenceof( member_stack[$] ) then
		    		Factor()
		    	else
		    		if member_stack[$] > 0 then
		    			term_stack[$][T_SYM] = member_table[MEMBER_VARTYPE][member_stack[$]]
		    			
		    		elsif integer( member_stack[$] ) then
		    			-- it's a subscript from a 'sequence of'
		    			class = member_table[MEMBER_VARTYPE][member_stack[$-1]]
		    			class = class_table[CLASS_SEQUENCEOF][find( class, class_table[CLASS_SYM] )]
		    			term_stack[$][T_SYM] = class_table[CLASS_SYM][class]
		    		else

		    			-- DOLLAR, so look for the previous member...
		    			if integer( member_stack[$-1] ) then
		    			if member_stack[$-1] > 0 then
		    				-- a real member
		    				term_stack[$][T_SYM] = member_table[MEMBER_VARTYPE][member_stack[$-1]]
		    			else
			    			-- it's a subscript from a 'sequence of'
			    			class = member_table[MEMBER_VARTYPE][member_stack[$-2]]
			    			class = class_table[CLASS_SEQUENCEOF][find( class, class_table[CLASS_SYM] )]
			    			term_stack[$][T_SYM] = class_table[CLASS_SYM][class]		    				
		    			end if
		    			end if
		    			
		    		end if
		    		
		    		
		    	end if
		    	member_stack = member_stack[1..len_member_stack]
		    	parse_method_stack = parse_method_stack[1..$-1]
		    	if preprocess then
		    		release_line()
		    	end if
				return
			else
				-- of the form: Class.Member so return the 'constant' value
				
				emit_opnd( member_table[MEMBER_SYM][member_stack[$]] )
				if preprocess then
					class = member_table[MEMBER_CLASS][member_stack[$]]
					pdec = sprintf( "%s_MEMBER_%s", 
						{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[$]]})
					tok2 = tok1 + (length(member_stack)-orig_member_stack) * 2
					if tok2 = tok1 then
						tok2 += 2
					end if
					replace_tokens( tok1, tok2, pdec )
					release_line()
				end if
				member_stack = member_stack[1..len_member_stack]
				putback( tok )
				parse_method_stack = parse_method_stack[1..$-1]
				
				return
			end if

		end if
		
	end if	

	term_stack[$][T_SYM] = object_type
    method_stack &= {tok}
    
    method_args &= { {} }
    method_name = append( method_name,  SymTab[tok[T_SYM]][S_NAME] )

    -- prevent an erroneous warning:
    SymTab[tok[T_SYM]][S_USAGE] = or_bits( U_READ, U_WRITTEN )
    
    current_method += 1
    parse_method_stack[$] = 1

    tok_match(LEFT_ROUND)
    s = tok[T_SYM] 
	member_subs = {}

    -- first, send the 'this' as an argument
    if last_member then

    	if is_sequenceof( current_instance[$] ) then
    		emit_opnd( current_sequence[$] )
    	else
    		emit_opnd( current_instance[$] )
    	end if

    	for m = 2 to length(member_stack)-1 do
		    if lhs_subs_level >= 0 then
				lhs_subs_level += 1
		    end if
		    if member_stack[m] > 0 then
		    	emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
		    	emit_op( RHS_SUBS )
		    elsif integer( member_stack[m] ) then
				if member_stack[m] < 0 then
			    	emit_opnd( -member_stack[m] )
			    	emit_op( RHS_SUBS )

				end if
		    else
		    	emit_op( DOLLAR )
		    	emit_op( RHS_SUBS )
		    end if
    		
    	end for
    	-- This is for preprocessing purposes:
    	real_instance = length(member_stack) + 2
		member_subs = member_stack[2..$-1]
    elsif member_stack[$] then
    	-- the 'this' is really going to be a subscript operation...
    	if is_sequenceof( current_instance[$] ) then
    		emit_opnd( current_sequence[$] )
    	else
    		emit_opnd( current_instance[$] )
    	end if
    	for m = 2 to length(member_stack) do
    		if m > 2 then
    			emit_opnd( current_sequence[$] )
    		end if
    		if member_stack[m] > 0 then
    			emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
    			emit_op( RHS_SUBS )
    		elsif integer( member_stack[m] ) then
    			emit_opnd( - member_stack[m] )
    			emit_op( RHS_SUBS )
    		else
    			emit_op( DOLLAR )
    			emit_op( RHS_SUBS )
    		end if
    		

    	end for
		
    	sym = current_sequence[$]
    	current_sequence = current_sequence[1..$-1]
    	real_instance = 3
    	if preprocess then
    		first_arg = SymTab[current_instance[$]][S_NAME]
    		class = find( SymTab[current_instance[$]][S_VTYPE], class_table[CLASS_SYM] )
   			for m = 2 to length(member_stack) do
   				first_arg &= sprintf("[%s_MEMBER_%s]", 
   					{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[m]] })
   				class = find( member_table[MEMBER_VARTYPE][member_stack[m]], class_table[CLASS_SYM] )
   				real_instance += 2
   				tok1 -= 2
   			end for
    	end if
    	
    else
	    sym = current_instance[$]
	    if sym and not find( sym, class_table[CLASS_SYM] ) then
	    -- the 'current_instance' is a real instance
	    	if preprocess then
	    		first_arg = SymTab[sym][S_NAME]
	    	end if
	   		SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)
			InitCheck(sym, TRUE)
	    	if is_sequenceof( sym ) then
	    		emit_opnd( current_sequence[$] )
	    	else
	    		emit_opnd( sym )
	    	end if
			real_instance = 3
		else
		-- the 'current_instance' is really a class, so the first parameter
		-- will be treated as the class, or it's just a constructor, so there
		-- isn't a 'this' parameter
			real_instance = 0
			
	    end if
    end if
    len_member_stack = length(member_stack)
    member_stack &= 0
--	member_stack = {0}
    ParseMethodArgs(tok)
    member_stack = member_stack[1..len_member_stack]

    -- now, find the actual method
    if last_member then
    	-- it was a nested call, so the class is based on the final 
    	-- member:

		csym = member_table[MEMBER_VARTYPE][last_member]
		class = find( csym, class_table[CLASS_SYM] )
		if not class then
			CompileErr( sprintf("member '%s' does not have methods",{method_table[METHOD_NAME][last_member]}))
			if preprocess then
				release_line()
			end if
			return 
		end if

    elsif find( sym, class_table[CLASS_SYM] ) then

    	if not length(method_args[$]) then
    		CompileErr( "method function requires a 'this' parameter" )
			if preprocess then
				release_line()
			end if
    		return
    	end if
    	
    	-- remove 'this' unless a constructor called as Class.Class( ... )
		if compare( SymTab[sym][S_NAME], SymTab[s][S_NAME] ) then
	    	method_args[$] = method_args[$][2..$]			
		end if

    	class = find( sym, class_table[CLASS_SYM] )

    else
	    -- now, find the actual method
	    -- IZEL: trying to fix this...
	    class = 0

	    if num_zeroes( current_instance ) < num_zeroes( member_stack ) then
	    	-- there was an additional zero added due to assignment, so we might
	    	-- be looking at a member constructor..Simple case, we can just
	    	-- look at the next member, but what if it's really a nested call?
	    	-- Object.Member = Member( Object.Something() )
	    	-- Check to make sure that member_stack[[$] = 0 and [$-1] != 0,
	    	-- and then look to see if the Symtab[s][S_NAME] matches the name
	    	-- of the member...

	    	if member_stack[$] = 0 and member_stack[$-1] != 0 then
	    		csym = SymTab[current_instance[$]][S_VTYPE]
	    		class = find( csym, class_table[CLASS_SYM] )
	    		
	    		csym = member_stack[$-1]
	    		csym = member_table[MEMBER_SYM][csym]
	    		csym = SymTab[csym][S_VTYPE]

	    		class = find( csym, class_table[CLASS_SYM] )
				if class then
		    		if class_table[CLASS_NAME][class][1] = '_' then
		    			class = sequence_of_class( class )
		    		end if
	
		    		if compare( class_table[CLASS_NAME][class], SymTab[s][S_NAME] ) then
		    			class = 0
		    			
		    		else
		    			-- have to Pop() off the this variable, since a constructor doesn't need it
						
		    			pop = {Pop(), Pop()}
		    			Push( pop[1] )
		    			
		    		end if					
				end if
	    		
	    	end if
	    end if
	    
	    if not class then
	    	-- This is correct for a constructor...
	    	if not real_instance then
		    	csym = tok[T_SYM]  
		    	
			    if current_instance[$] then
			    	-- it's a casted method call
			    	
			    	if find( csym, class_table[CLASS_SYM] ) then -- length(member_stack) > 1 and member_stack[$-1] then
			    		-- Need the class of the member
						cg_stack[$-1] = Pop()
	
			    	else
		    			csym = SymTab[current_instance[$]][S_VTYPE]	
			    	end if		    	
			    	
			    end if
			    
			else
				csym = SymTab[sym][S_VTYPE]
	    	end if
			class = find( csym, class_table[CLASS_SYM] )
	    end if
	    
	    -- but what about the case of Object.Member = Member() ???

    end if

    s = PolyMorph( class )
    if preprocess then
    
    	pdec = pp_decorate( SymTab[s][S_NAME]) & "( "
    	if real_instance then
    		-- have to add the first argument

			if line_tokens[tok1][T_ID] = RIGHT_SQUARE then
				tok2 = tok1 - read_backwards( tok1 )
				tok1 -= tok2
				ppoff = tok2
	    		for i = 0 to tok2 do
	    			pdec &= token_text( i + tok1 )
	    		end for	
	    	else
	    		tok2 = 0
	    		ppoff = 0
	    		if line_tokens[tok1][T_SYM] then
	    			pdec &= SymTab[line_tokens[tok1][T_SYM]][S_NAME]
	    		else
	    			-- it's a constructor for a member
	    			tok1 += 1
	    			real_instance = 1
	    		end if
	    		
			end if
    		
    		for i = 1 to length(member_subs) do
    			member = member_subs[i]
    			if member > 0 then
	    			class = member_table[MEMBER_CLASS][member]
	    			pdec &= sprintf("[%s_MEMBER_%s]", 
	    				{class_table[CLASS_NAME][class],member_table[MEMBER_NAME][member]})
	    			ppoff += 2
	
	    		else
	    			ppoff += 2
	    			pdec &= sprintf("[%s]",{token_text(tok1+ppoff)})
	    			ppoff += 1

    			end if
    		end for
    		if SymTab[s][S_NUM_ARGS] > 1 then
    			pdec &= ", "
    		end if
    	else
    		tok2 = 0
    		real_instance = 3
    		if not current_instance[$] then
    			tok1 += 1
    			real_instance -= 2
    		end if
    	end if

--    	for j = tok1 to tok1 + real_instance + tok2  do
--    		puts(1, token_text( j ))
--    	end for

		replace_tokens( tok1, tok1 + real_instance + tok2 + 2 * (tok2 > 0 )*0, pdec )
		
    	release_line()
		
    end if
    
    add_ref( {r:FUNC, s} )
    method_name = method_name[1..$-1]

	-- end mwl
	e = SymTab[s][S_EFFECT]
	if e then
	    -- the routine we are calling has side-effects
	    if e = E_ALL_EFFECT or s > left_sym then
		-- it can access the LHS var (it uses indirect calls or comes later)
		side_effect_calls = or_bits(side_effect_calls, e)
	    end if
	    
	    SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT], e)
	    
	    if short_circuit > 0 and short_circuit_B then -- and
--		      find(id, {FUNC, QUALIFIED_FUNC}) then
		Warning(sprintf(
		"%.99s:%d - call to %s() might be short-circuited", 
		{file_name[current_file_no], line_number, 
		 SymTab[s][S_NAME]}))
	    end if
	end if

	scope = SymTab[s][S_SCOPE]
	opcode = SymTab[s][S_OPCODE]

	if scope = SC_PREDEF then
	    emit_op(opcode)
	else 
	    op_info1 = s
	    emit_op(r:PROC)
	    if not TRANSLATE then 
		if OpTrace then
		    emit_op(UPDATE_GLOBALS)
		end if
	    end if      
	end if
    method_args = method_args[1..$-1]
    method_stack = method_stack[1..$-1]
    member_stack = member_stack[1..orig_member_stack]
    current_method -= 1
    parse_method_stack = parse_method_stack[1..$-1]

end procedure
forward_method_func = routine_id("MethodFunc")

procedure Method( token tok )
-- parse a method call statement 
    integer scope, opcode, class, tok1, tok2, real_instance, member, last_member, ix
    token temp_tok, ppoff
    symtab_index s, sym, csym
    sequence pdec, first_arg

	if preprocess then
		cache_line()
	end if
	member = is_member( tok )
	if member then
		tok[T_SYM] = member_table[MEMBER_SYM][member]
		-- really an assignment?
		member_stack &= member
		Assignment( tok )
--		current_instance = current_instance[1..$-1]
				if preprocess then
					release_line()
				end if
		return
	end if
	-- tok1 is the method name, so we need to capture the
	-- instance and the dot to replace them
	tok1 = length(line_tokens) - 2
	
    method_stack &= {tok}
    method_args &= { {} }
    method_name = append( method_name, SymTab[tok[T_SYM]][S_NAME] )
    
    -- prevent an erroneous warning:
    SymTab[tok[T_SYM]][S_USAGE] = or_bits( U_READ, U_WRITTEN )
    
    current_method += 1
    parse_method_stack &= 1

    tok_match(LEFT_ROUND)
    s = tok[T_SYM] 
    
    -- first, send the 'this' as an argument
    if member_stack[$] then
    	-- the 'this' is really going to be a subscript operation...
    	emit_opnd( current_instance[$] )

    	for m = 2 to length(member_stack) do
    		if m > 2 then
    			emit_opnd( current_sequence[$] )
    		end if
    		if member_stack[m] > 0 then
    			emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
    			emit_op( RHS_SUBS )
    		elsif integer( member_stack[m] ) then
    			emit_opnd( -member_stack[m] )
    			emit_op( RHS_SUBS )
    		else
    			emit_op( DOLLAR )
    			emit_op( RHS_SUBS )
    		end if

    	end for

		
    	sym = current_sequence[$]
    	current_sequence = current_sequence[1..$-1]
    	real_instance = 3
    	if preprocess then
    		first_arg = ""
    		if is_sequenceof( current_instance[$] ) then
    			-- have to count backwards through the subscripts...
    			first_arg = sprintf("[%s]", {token_text( length(line_tokens) - (length(member_stack)-1)*2 - 2 )})
    			tok1 -= 3
    			real_instance += 3
    			member_stack = member_stack[1..$-1]
    		end if
    		first_arg = SymTab[current_instance[$]][S_NAME] & first_arg
   			for m = 2 to length(member_stack) do
   				if member_stack[m] > 0 then
   					-- Member
	   				class = member_table[MEMBER_CLASS][member_stack[m]]
	   				first_arg &= sprintf("[%s_MEMBER_%s]", 
	   					{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[m]] })   					
   				else
   					-- DOLLAR or subscript
   					-- Don't need to replace it with anything
   					first_arg &= sprintf("[%s]", {token_text( length(line_tokens) - (length(member_stack)-1)*2 - 2 )})
   				end if
   				
   				real_instance += 2
   				tok1 -= 2
   			end for
    	end if
    	
    else

	    sym = current_instance[$]
	    if not find( sym, class_table[CLASS_SYM] ) then
	    -- the 'current_instance' is a real instance
	    	if preprocess then
	    		real_instance = 3
	    		first_arg = ""
	    		if is_sequenceof( current_instance[$] ) then
	    			-- have to count backwards through the subscripts...
	    			first_arg = sprintf("[%s]", {token_text( tok1 - 1)})
	    			tok1 -= 3
	    			real_instance += 3
	    		end if
	    		first_arg = SymTab[current_instance[$]][S_NAME] & first_arg
	   			for m = 2 to length(member_stack) do
	   				class = member_table[MEMBER_CLASS][member_stack[m]]
	   				first_arg &= sprintf("[%s_MEMBER_%s]", 
	   					{ class_table[CLASS_NAME][class], member_table[MEMBER_NAME][member_stack[m]] })
	   				
	   				real_instance += 2
	   				tok1 -= 2
	   			end for
	    	end if
	   		SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)
			InitCheck(sym, TRUE)
			emit_opnd(sym)

		else
		-- the 'current_instance' is really a class, so the first parameter
		-- will be treated as the class
			real_instance = 0
	    end if
    end if
    
    ix = length( member_stack )
    while ix and member_stack[ix] < 0 do
    	ix -= 1
    end while
    if ix then
    	last_member = member_stack[ix]
    end if
    
    
	member_stack = {0}
    ParseMethodArgs(tok)
    
    if last_member then
    	-- it was a nested call, so the class is based on the final 
    	-- member:
		csym = member_table[MEMBER_VARTYPE][last_member]
		class = find( csym, class_table[CLASS_SYM] )
		if not class then
			CompileErr( sprintf("member '%s' does not have methods",{method_table[METHOD_NAME][last_member]}))
				if preprocess then
					release_line()
				end if
			return 
		end if
    elsif find( sym, class_table[CLASS_SYM] ) then
    	if not length(method_args[$]) then
    		CompileErr( "method procedure requires a 'this' parameter" )
				if preprocess then
					release_line()
				end if
    		return
    	end if
    	method_args[$] = method_args[$][2..$]
    	class = find( current_instance[$], class_table[CLASS_SYM] )
    else
	    -- now, find the actual method
	    csym = SymTab[current_instance[$]][S_VTYPE]
	    class = find( csym, class_table[CLASS_SYM] )    	    	
    end if
    
    s = PolyMorph( class )
    if preprocess then
 
    	pdec = pp_decorate( SymTab[s][S_NAME]) & "( "
    	if real_instance then
    		-- have to add the first argument
    		pdec &= first_arg -- SymTab[line_tokens[tok1][T_SYM]][S_NAME]
    		if SymTab[s][S_NUM_ARGS] > 1 then
    			pdec &= ", "
    		end if
    		replace_tokens( tok1, tok1 + real_instance, pdec )
    	else
    		replace_tokens( tok1, tok1 + 3, pdec )
    	end if
		
    	release_line()
    end if
    add_ref( {r:PROC, s} )
	method_name = method_name[1..$-1]
    scope = SymTab[s][S_SCOPE]
    opcode = SymTab[s][S_OPCODE]
    if SymTab[s][S_EFFECT] then
		SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
					       SymTab[s][S_EFFECT])
    end if
    
    if scope = SC_PREDEF then
		emit_op(opcode)
		if opcode = ABORT then
		    temp_tok = next_token()
		    putback(temp_tok)
		    NotReached(temp_tok[T_ID], "abort()")
		end if
    else 
	op_info1 = s
	emit_op(r:PROC)
	if not TRANSLATE then
	    if OpTrace then
		emit_op(UPDATE_GLOBALS)
	    end if
	end if  
    end if
    method_args = method_args[1..$-1]
    method_stack = method_stack[1..$-1]
    current_method -= 1
    parse_method_stack = parse_method_stack[1..$-1]
end procedure
forward_method = routine_id("Method")
-- end mwl

global procedure parser()
-- top level of the parser - command level 
    token tok, tok2
    integer id
    
    tok = next_token()
    while TRUE do  -- infinite loop until scanner aborts
	start_index = length(Code)+1
	id = tok[T_ID]

	if id = VARIABLE or id = QUALIFIED_VARIABLE then
		-- begin mwl
		if length(current_instance) and current_instance[$] then
			-- really a procedure or function call
			StartSourceLine(FALSE)
			Method(tok)
			current_instance = current_instance[1..$-1]
			ExecCommand()
		else
		    StartSourceLine(TRUE)
		    Assignment(tok)
		    ExecCommand()
		end if
		-- end mwl
		
	-- begin mwl
	-- added class
	elsif find(id, {PROCEDURE, FUNCTION, TYPE_DECL, CLASS}) then
	-- end mwl
		if current_instance[$] then
			StartSourceLine(TRUE)
			Method( tok )
			current_instance = current_instance[1..$-1]
		else
			SubProg(id, 0)

		end if
	    

	elsif id = GLOBAL then
	    tok = next_token()
	    id = tok[T_ID]
	    if id = TYPE then
	    	-- begin mwl
	    	if current_class then
	    		Member_declaration( tok[T_SYM] )
	    	else
	    		Global_declaration(tok[T_SYM], 1)
	    	end if
			-- end mwl
	    elsif id = CONSTANT then
			Global_declaration(0, 1)
			ExecCommand()
		-- begin mwl
		-- added CLASS
	    elsif find(id, {PROCEDURE, FUNCTION, TYPE_DECL, CLASS}) then
	    -- end mwl

			SubProg(id, 1)
	    else 
			if id = VARIABLE or id = QUALIFIED_VARIABLE then
			    if UndefinedVar(tok[T_SYM]) then
			    	return
			    end if
			end if
			CompileErr(
				"'global' must be followed by:\n     <a type>, 'constant', 'procedure', 'type' or 'function'")
			return
	    end if
		
	elsif id = TYPE or id = QUALIFIED_TYPE then
		-- begin mwl

		tok2 = next_token()

		if tok2[T_ID] = DOT_NOTATION then

			StartSourceLine(TRUE)
			current_instance &= {tok[T_SYM]}
		else
			putback(tok2)
			if current_class then
				Member_declaration( tok[T_SYM] )
			else
				Global_declaration(tok[T_SYM], 0)
			end if
			
		end if
		-- end mwl
	    

	elsif id = CONSTANT then
	    Global_declaration(0, 0)
	    ExecCommand()

	elsif id = IF then
	    StartSourceLine(TRUE)
	    If_statement()
	    ExecCommand()

	elsif id = FOR then
	    StartSourceLine(TRUE)
	    For_statement()
	    ExecCommand()

	elsif id = WHILE then
	    StartSourceLine(TRUE)
	    While_statement()
	    ExecCommand()

	elsif id = r:PROC or id = QUALIFIED_PROC then
	    -- begin mwl
		if length(current_instance) and current_instance[$] then
			-- really a procedure or function call
			StartSourceLine(TRUE)
			Method(tok)
			ExecCommand()
			current_instance = current_instance[1..$-1]
		else
		    StartSourceLine(TRUE)
		    Procedure_call(tok)
		    ExecCommand()
		end if
	    -- end mwl
	elsif id = r:FUNC or id = QUALIFIED_FUNC then
	    CompileErr("function result must be assigned or used")
	    return
		
	elsif id = RETURN then
	    Return_statement() -- will fail - not allowed at top level

	elsif id = EXIT then
	    CompileErr("exit must be inside a loop")                 
	    return

	elsif id = INCLUDE then
	    IncludeScan()

	elsif id = WITH then
	    SetWith(TRUE)

	elsif id = WITHOUT then
	    SetWith(FALSE)

	elsif id = END_OF_FILE then
	    if IncludePop() then
		read_line()
	    else
		exit -- all finished
	    end if
	
	elsif id = QUESTION_MARK then
	    StartSourceLine(TRUE)
	    Print_statement()
	    ExecCommand()
	    
	elsif id = ILLEGAL_CHAR then
	    CompileErr("illegal character")
	    return

	-- begin mwl
	elsif id = END then
		if current_class then

			tok_match(CLASS)
			if preprocess then
				cache_line()
				replace_tokens( length(line_tokens)-1, length(line_tokens)-1, "--end")
				release_line()
			end if

			current_class = 0
			
		else
			CompileErr("syntax error")
			return
		end if
		
	elsif id = CONTINUE then
		Continue_statement()
	
	elsif id = GOTO then
		Goto_Statement()
		
	elsif id = COLON then
		Goto_Label()
		
	-- end mwl
	else 
	    CompileErr("unknown command")
	    return

	end if
	-- begin mwl
	-- bail out if parse error inside of an eval...
	if length(eval_error[$]) then
		exit
	end if
	-- end mwl
	tok = next_token()
    end while 
    
    -- begin mwl
    -- now convert the 'instances' to whatever types they should be

    for i = 1 to length(SymTab) do
    	if length(SymTab[i]) >= 14 then
	    	id = find( SymTab[i][S_VTYPE], class_table[CLASS_SYM])
			while id do
				SymTab[i][S_VTYPE] = class_table[CLASS_VARTYPE][id]
				id = find( SymTab[i][S_VTYPE], class_table[CLASS_SYM])
			end while    		
    	end if
    end for
    PatchGotos()
    -- end mwl
    
    emit_op(RETURNT)
    StraightenBranches()
    SymTab[TopLevelSub][S_CODE] = Code
    EndLineTable()
    SymTab[TopLevelSub][S_LINETAB] = LineTable
end procedure
