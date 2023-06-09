without warning
include print.e
include sprint.e

global constant TRUE = 1, FALSE = 0
global constant INTERPRET = TRUE,
		TRANSLATE = FALSE,
		BIND = FALSE
include global.e
include reswords.e
include keylist.e
include reswords.e
include opnames.e
include error.e
include symtab.e

global function fetch_line( integer l )
	return ""
end function

include sequencef.e
integer out, pc, a, b, c, d, target, len, keep_running
sequence operation

with trace

function name_or_literal( integer sym )
	if length(SymTab[sym]) = 1 then
		return sprintf("[_deleted_:%d]", sym)

	elsif length(SymTab[sym]) >= SIZEOF_VAR_ENTRY then
		return sprintf("[%s:%d]", {SymTab[sym][S_NAME],sym})
	elsif SymTab[sym][S_MODE] = M_TEMP then
		return sprintf("[_temp_:%d]", sym)
	else
		return sprintf("[LIT %s:%d]",{ pretty_source(SymTab[sym][S_OBJ]), sym})
	end if
end function

function names( sequence n )
	sequence nl
	nl = {}
	for i = 1 to length(n) do
		nl = append( nl, name_or_literal(n[i]))
	end for
	return nl
end function

procedure il( sequence dsm, integer len )
	sequence format, code
	integer line, space

	format = "%6d: %03d"
	for i = 1 to len do
		format &= " %d"
	end for
	code = sprintf( format, pc & Code[pc..$] )
	line = 1
	while length(code) > 40 do

		for c = 40 to 1 by -1 do
			if code[c] = 32 then
				if line > 1 then
					code = "        " & code
					printf( out, "\n%-40s # ", {"        " & code[1..c]})
				else
					printf( out, "%-40s # ", {code[1..c]})
				end if
				
				line += 1
				code = code[c+1..$]
				exit
			end if
		end for
	end while
	if length(code) then
		if line > 1 then
			printf( out, "\n%-40s # ", {"        " & code})
		else
			printf( out, "%-40s # ", {code})
		end if
	end if
	line = 1
	while length(dsm) > 40 do
		space = 0
		for i = 40 to length(dsm) do
			if dsm[i] = 32 then
				if line > 1 then
					puts( out, repeat( 32, 41 ) & "#     " )
				end if
				puts( out, dsm[1..i] & "\n")
				dsm = dsm[i+1..$]
				line += 1
				space = 1
				exit
			end if
		end for
		if not space then
			exit
		end if
	end while
	if length(dsm) then
		if line > 1 then
			puts( out, repeat( 32, 41 ) & "#     " )
		end if
		puts( out, dsm & "\n")
	end if
	
end procedure

procedure trinary()
	il( sprintf( "%s: %s, %s, %s => %s", {opnames[Code[pc]]} & names(Code[pc+1..pc+4])), 4)
	pc += 5
end procedure

procedure ptrinary()
	il( sprintf( "%s: %s, %s, %s", {opnames[Code[pc]]} & names(Code[pc+1..pc+3])), 3)
	pc += 4	
end procedure

procedure binary()
	il( sprintf( "%s: %s, %s => %s", {opnames[Code[pc]]} & names(Code[pc+1..pc+3])), 3)
	pc += 4	
end procedure

procedure pbinary()
	il( sprintf( "%s: %s, %s", {opnames[Code[pc]]} & names(Code[pc+1..pc+2])), 2)
	pc += 3	
end procedure

procedure unary( )
	il( sprintf( "%s: %s => %s", {opnames[Code[pc]]} & names(Code[pc+1..pc+2])), 2)
	pc += 3
end procedure

procedure punary( )
	il( sprintf( "%s: %s ", {opnames[Code[pc]]} & names(Code[pc+1..pc+1])), 1)
	pc += 2
end procedure

procedure nonary()
	il( sprintf( "%s: %s", {opnames[Code[pc]], name_or_literal( Code[pc+1])}), 1)
	pc += 2
end procedure

procedure pnonary()
	il( sprintf( "%s:", {opnames[Code[pc]]}), 0)
	pc += 1
end procedure

procedure opSTARTLINE()
-- Start of a line. Use for diagnostics.
	object line
	sequence entry
	entry = slist[Code[pc+1]]
	line = entry[SRC]
	if atom(line) then
		line = ""
	else
		while length(line) and find( line[1], "\t " ) do
			line = line[2..$]
		end while
	end if
	il( sprintf( "%s: %s(%d)<<%s>>", {opnames[Code[pc]], file_name[entry[LOCAL_FILE_NO]],entry[LINE] ,line}), 1)
	
--	printf( out, "// %s(%d) %d: %s\n", {file_name[the_line[LOCAL_FILE_NO]], the_line[LINE], pc, line})
	pc += 2
end procedure
	
procedure opPROC()  -- Normal subroutine call
    integer n, arg, sub, top
    sequence dsm

    -- make a procedure or function/type call
    sub = Code[pc+1] -- subroutine
    n = SymTab[sub][S_NUM_ARGS]

    dsm = sprintf( "%s: %s",{opnames[Code[pc]],name_or_literal(sub)})

	for i = 1 to n do

		if i < n then
			dsm &= ", "
		end if
		arg = Code[pc + i + 1]
		dsm &= name_or_literal(arg)
	end for


    if SymTab[sub][S_TOKEN] != PROC then
    	dsm[1..4] = "FUNC"
    	dsm &= sprintf( " => %s", {name_or_literal(Code[pc + n + 2])})
		il( dsm, n + 2 )
	    pc += n + 3
	else
		il( dsm, n + 1 )
	    pc += n + 2
    end if
end procedure

integer result
result = 0
object result_val

procedure opRETURNP()   -- return from procedure (or function)
    integer sub, arg, top, base
    il( "RETURNP", 1 )
	pc += 2
end procedure

procedure opRETURNF()  
-- return from function
	result_val = Code[pc+2]
	il(	sprintf( "RETURNF: %s", {name_or_literal(result_val)}), 2)
	pc += 3
end procedure

procedure opCALL_BACK_RETURN()
--    keep_running = FALSE  -- force return from do_exec()
	il( "CALL_BACK_RETURN", 0 )
end procedure
		
procedure opBADRETURNF()  -- shouldn't reach here
	pnonary()
--    RTFatal("attempt to exit a function without returning a value")  -- end of a function
end procedure

procedure opRETURNT()   -- return from top-level "procedure"
	pnonary()
end procedure
	
procedure opRHS_SUBS() -- find(opcode, {RHS_SUBS_CHECK, RHS_SUBS,         
		       -- RHS_SUBS_I}) then
    object sub, x
    
    a = Code[pc+1]
    b = Code[pc+2]
    target = Code[pc+3]
    il( sprintf("%s: %s sub %s => %s",{opnames[Code[pc]]} & names({a,b,target})), 3 )
    
    pc += 4
end procedure
--	
procedure opIF()
    a = Code[pc+1]
    il(sprintf( "%s: %s = 0 goto %04d", {opnames[Code[pc]],name_or_literal(a), Code[pc+2]}),2)
    pc += 3
end procedure

procedure check()
	il( sprintf("%s: %s",{opnames[Code[pc]] ,name_or_literal(Code[pc+1])}), 1 )
	pc += 2
end procedure

procedure opINTEGER_CHECK()
	check()
end procedure
	    
procedure opATOM_CHECK()
	check()
end procedure
	      
procedure opSEQUENCE_CHECK()
	check()
end procedure
--
procedure opASSIGN()  -- or opASSIGN_I or SEQUENCE_COPY
    a = Code[pc+1]
    target = Code[pc+2]
    il( sprintf("%s => %s", names( {a,target} )), 2 )
    pc += 3
end procedure
--		
procedure opELSE()  -- or EXIT, ENDWHILE}) then
	il( sprintf("%s goto %04d", {opnames[Code[pc]], Code[pc+1]}),1 )
--    pc = Code[pc+1]
	pc += 2
end procedure

	    
procedure opRIGHT_BRACE()  -- form a sequence of any length 
    sequence x
    
    len = Code[pc+1]
	
    x = sprintf("RIGHT_BRACE: len %d", len)
    
    for i = pc+len+1 to pc+2 by -1 do
		-- last one comes first
		x &= sprintf(", %s",{name_or_literal(Code[i])})
    end for
    target = Code[pc+len+2]
    x &= sprintf(" => %s", {name_or_literal(target)})
    il( x, len + 2 )
    pc += 3 + len
end procedure

procedure opRIGHT_BRACE_2()   -- form a sequence of length 2
    target = Code[pc+3]
    il( sprintf("RIGHT_BRACE_2: %s, %s => %s", names( Code[pc+2] & Code[pc+1] & target )), 2)
    -- the second one comes first
    pc += 4
end procedure

procedure opPLUS1() --or opPLUS1_I then
    a = Code[pc+1]
    -- [2] is not used
    target = Code[pc+3] 
    il( sprintf("PLUS1: %s + 1 => %s", names( a & target )), 3 )
    pc += 4
end procedure
	
procedure opGLOBAL_INIT_CHECK()  --or PRIVATE_INIT_CHECK then
    a = Code[pc+1]
    il( sprintf("%s: %s", {opnames[Code[pc]],name_or_literal(a)}), 1 )
    pc += 2
end procedure
	    
procedure opWHILE()     -- sometimes emit.c optimizes this away
    a = Code[pc+1]
    il( sprintf("WHILE: %s goto %04d else goto %04d", {name_or_literal(a), pc+3, Code[pc+2]}), 2 )
    pc += 3
end procedure

procedure opLENGTH()
-- operand should be a sequence 
    a = Code[pc+1]
    target = Code[pc+2]
    il( sprintf("LENGTH: %s => %s", names(a&target)), 2 )
    
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
    il( sprintf("PLENGTH: %s => %s", names( a & target )), 2 )
    pc += 3
end procedure

procedure opLHS_SUBS() 
-- Handle one LHS subscript, when there are multiple LHS subscripts.
    
    a = Code[pc+1] -- base var sequence, or a temp that contains
		   -- {base index, subs1, subs2... so far}
    b = Code[pc+2] -- subscript
    target = Code[pc+3] -- temp for storing result
    
    il( sprintf("LHS_SUBS: %s, %s => %s", names( Code[pc+1..pc+3] )), 4 )
    -- a is a "pointer" to the result of previous subscripting
--    val[target] = append(val[a], val[b])
    pc += 5
end procedure
--
procedure opLHS_SUBS1() 
-- Handle first LHS subscript, when there are multiple LHS subscripts.
    
    a = Code[pc+1] -- base var sequence, or a temp that contains
		   -- {base index, subs1, subs2... so far}
    b = Code[pc+2] -- subscript
    target = Code[pc+3] -- temp for storing result
    il( sprintf("LHS_SUBS1: %s, %s => %s", names( Code[pc+1..pc+3] )), 4 )
    -- a is the base var
--    val[target] = {a, val[b]}
    pc += 5
end procedure

procedure opLHS_SUBS1_COPY() 
-- Handle first LHS subscript, when there are multiple LHS subscripts.
-- In tricky situations a copy of the sequence is made into a temp. 
-- (Protects against function call inside subscript expression.
-- In the C backend, it also prevents circular pointer references.)
    
    a = Code[pc+1] -- base var sequence
		   
    b = Code[pc+2] -- subscript
    
    target = Code[pc+3] -- temp for storing result
    
    c = Code[pc+4] -- temp to hold base sequence while it's manipulated
    il( sprintf("LHS_SUBS1_COPY: %s, %s => (%s) %s", names( Code[pc+1..pc+4] )), 4 )
--    val[c] = val[a]
    
    -- a is the base var
--    val[target] = {c, val[b]}
    
    pc += 5
end procedure
      

procedure opASSIGN_SUBS() -- also ASSIGN_SUBS_CHECK, ASSIGN_SUBS_I
-- LHS single subscript and assignment
    object x, subs

    a = Code[pc+1]  -- the sequence
    b = Code[pc+2]  -- the subscript
    c = Code[pc+3]  -- the RHS value
--    x = val[a]
--    lhs_check_subs(x, val[b])
--    x = val[c]
--    subs = val[b]
--    val[a][subs] = x  -- single LHS subscript
	il( sprintf("%s: %s, %s <= %s", {opnames[Code[pc]]} & names( Code[pc+1..pc+3] )), 3 )
    pc += 4
end procedure

procedure opPASSIGN_SUBS()
-- final LHS subscript and assignment after a series of subscripts
    a = Code[pc+1]
    b = Code[pc+2]  -- subscript
    c = Code[pc+3]  -- RHS value
    
    -- multiple LHS subscript case
--    lhs_seq_index = val[a][1]
--    lhs_subs = val[a][2..$]    
--    val[lhs_seq_index] = assign_subs(val[lhs_seq_index], 
--					 lhs_subs & val[b], 
--					 val[c])
	il( sprintf("PASSIGN_SUBS: %s, %s <= %s", names( Code[pc+1..pc+3] )), 3 )
    pc += 4
end procedure




procedure opASSIGN_OP_SUBS()  -- var[subs] op= expr
    object x
    
    a = Code[pc+1]
    b = Code[pc+2]
    target = Code[pc+3]
    -- var with one subscript
--    lhs_subs = {}
--    x = val[a]
--    val[target] = var_subs(x, lhs_subs & val[b])
	il( sprintf("ASSIGN_OP_SUBS: %s, %s => %s", names( Code[pc+1..pc+3] )), 3 )
    pc += 4
end procedure

procedure opPASSIGN_OP_SUBS()  -- var[subs] ... [subs] op= expr
    a = Code[pc+1]
    b = Code[pc+2]
    target = Code[pc+3]
    -- temp with multiple subscripts
--    lhs_seq_index = val[a][1]
--    lhs_subs = val[a][2..$]
	il( sprintf("PASSIGN_OP_SUBS: %s, %s => %s (patch %04dd => %d)", 
		names( Code[pc+1..pc+3] ) & pc+9 & Code[pc+1]), 3 )
    Code[pc+9] = Code[pc+1] -- patch upcoming op
--    val[target] = var_subs(val[lhs_seq_index], lhs_subs & val[b])
    pc += 4
end procedure

procedure opASSIGN_OP_SLICE()  --then  -- var[i..j] op= expr
    object x

    a = Code[pc+1]

    b = Code[pc+2]
    c = Code[pc+3]
    target = Code[pc+4]
    il( sprintf("ASSIGN_OP_SLICE: %s, %s, %s => %s", names(a&b&c&target)),4 )
--    val[target] = var_slice(x, {}, val[b], val[c])
    pc += 5
end procedure

procedure opPASSIGN_OP_SLICE()  --then  -- var[subs] ... [i..j] op= expr
    object x

    a = Code[pc+1]

    b = Code[pc+2]
    c = Code[pc+3]
    target = Code[pc+4]
    il( sprintf("PASSIGN_OP_SLICE: %s, %s, %s => %s (patch %04d => %d", 
    	names(a&b&c&target) & pc+10 & Code[pc+1]),4 )
    Code[pc+10] = Code[pc+1]

    pc += 5
end procedure
	    
procedure opASSIGN_SLICE()   -- var[i..j] = expr
    object x
    
    a = Code[pc+1]  -- sequence
    b = Code[pc+2]  -- 1st index
    c = Code[pc+3]  -- 2nd index
    d = Code[pc+4]  -- rhs value to assign
    il(sprintf("ASSIGN_SLICE: %s %s..%s => %s", names({a,b,c,d})),4)
    pc += 5
end procedure

procedure opPASSIGN_SLICE()   -- var[x] ... [i..j] = expr
    a = Code[pc+1]  -- sequence
    b = Code[pc+2]  -- 1st index
    c = Code[pc+3]  -- 2nd index
    d = Code[pc+4]  -- rhs value to assign
    il(sprintf("PASSIGN_SLICE: %s %s..%s => %s", names({a,b,c,d})),4)
    pc += 5
end procedure

procedure opRHS_SLICE() -- rhs slice of a sequence a[i..j] 
    object x
    
    a = Code[pc+1]  -- sequence
    b = Code[pc+2]  -- 1st index
    c = Code[pc+3]  -- 2nd index
    target = Code[pc+4]  
    il(sprintf("RHS_SLICE: %s %s..%s => %s", names({a,b,c,target})),4)
    pc += 5
end procedure

procedure opTYPE_CHECK() 

	pnonary()

end procedure

procedure is_an()
    a = Code[pc+1]
    target = Code[pc+2]
    il( sprintf("%s: %s %s",{ opnames[Code[pc]] } & names(a&target)), 2 )
    pc += 3
end procedure    
procedure opIS_AN_INTEGER()
    is_an()
end procedure

procedure opIS_AN_ATOM()
    is_an()
end procedure
		
procedure opIS_A_SEQUENCE() 
    is_an()
end procedure
	    
procedure opIS_AN_OBJECT()
    is_an()
end procedure
		
--	-- ---------- start of unary ops ----------------- 
--
procedure opSQRT() 
	unary()
end procedure

procedure opSIN()
	unary()
end procedure

procedure opCOS()
	unary()
end procedure

procedure opTAN()
	unary()
end procedure

procedure opARCTAN()
	unary()
end procedure

procedure opLOG()
	unary()
end procedure

procedure opNOT_BITS()
	unary()
end procedure

procedure opFLOOR()
	unary()
end procedure

procedure opNOT_IFW()
    a = Code[pc+1]
    il( sprintf( "NOT_IFW %s goto %04d else goto %04d", 
    	{name_or_literal(a), pc + 3, Code[pc+2]}), 2 )
    pc += 3
end procedure
	    
procedure opNOT()
	unary()
end procedure
	    
procedure opUMINUS()
	unary()
end procedure
	    
procedure opRAND()
	unary()
end procedure
	    
procedure opDIV2()  -- like unary, but pc+=4
	
    a = Code[pc+1]
    -- Code[pc+2] not used
    target = Code[pc+3]
    il( sprintf("DIV2: %s => %s",names( a & target )), 3 )
    pc += 4 
end procedure
	    
procedure opFLOOR_DIV2()
    a = Code[pc+1]
    -- Code[pc+2] not used
    target = Code[pc+3]
    il( sprintf("FLOOR_DIV2: %s => %s",names( a & target )), 3 )   
    pc += 4 
end procedure
		
--	----------- start of binary ops ----------
--	    
procedure opGREATER_IFW()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf( "GREATER_IFW %s > %s goto %04d else goto %04d", 
    	{name_or_literal(a),name_or_literal(b), pc + 4, Code[pc+3]}), 3 )
	pc += 4
end procedure
--	
procedure opNOTEQ_IFW()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf( "NOTEQ_IFW %s != %s goto %04d else goto %04d", 
    	{name_or_literal(a),name_or_literal(b), pc + 4, Code[pc+3]}), 3 )
	pc += 4
end procedure
	
procedure opLESSEQ_IFW()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf( "LESSEQ_IFW %s <= %s goto %04d else goto %04d", 
    	{name_or_literal(a),name_or_literal(b), pc + 4, Code[pc+3]}), 3 )
	pc += 4

end procedure
	
procedure opGREATEREQ_IFW()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf( "GREATEREQ_IFW %s > %s goto %04d else goto %04d", 
    	{name_or_literal(a),name_or_literal(b), pc + 4, Code[pc+3]}), 3 )
	pc += 4

end procedure
	
procedure opEQUALS_IFW()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf( "IFW %s = %s goto %04d else goto %04d", 
    	{name_or_literal(a),name_or_literal(b), pc + 4, Code[pc+3]}), 3 )
    pc += 4
end procedure
	
procedure opLESS_IFW()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf( "IFW %s < %s goto %04d else goto %04d", 
    	{name_or_literal(a),name_or_literal(b), pc + 4, Code[pc+3]}), 3 )
    pc += 4
end procedure


--	-- other binary ops
--	
procedure opMULTIPLY()
    binary()
end procedure
	    
procedure opPLUS() -- or opPLUS_I then
    binary()
end procedure
	
procedure opMINUS() -- or opMINUS_I then
    binary()
end procedure
	    
procedure opOR()
    binary()
end procedure
	
procedure opXOR()
    binary()
end procedure
	
procedure opAND()
    binary()
end procedure
	    
procedure opDIVIDE()
    binary()
end procedure

procedure opREMAINDER()
    binary()
end procedure
	    
procedure opFLOOR_DIV()
    binary()
end procedure
	    
procedure opAND_BITS()
    binary()
end procedure
	
procedure opOR_BITS()
    binary()
end procedure
	
procedure opXOR_BITS()
    binary()
end procedure
	    
procedure opPOWER()
    binary()
end procedure
	    
procedure opLESS()
    binary()
end procedure
	
procedure opGREATER()
    binary()
end procedure
	
procedure opEQUALS()
    binary()
end procedure
	
procedure opNOTEQ()
    binary()
end procedure
	
procedure opLESSEQ()
    binary()
end procedure
	
procedure opGREATEREQ()
    binary()
end procedure
	    
-- short-circuit ops 

procedure short_circuit()
    a = Code[pc+1]
    b = Code[pc+2]
    il( sprintf("%s: %s, %s, %04d", {opnames[Code[pc]]} & names(a&b) & Code[pc+3]), 3 )
    pc += 4
end procedure
procedure opSC1_AND()
	short_circuit()
end procedure

procedure opSC1_AND_IF() 
	short_circuit()
end procedure

procedure opSC1_OR()
	short_circuit()
end procedure
		
procedure opSC1_OR_IF()
	short_circuit()
end procedure
		
procedure opSC2_OR() -- or opSC2_AND 
-- short-circuit op
	pbinary()
end procedure

-- for loops 
	    
procedure opFOR()  -- or opFOR_I 
-- enter into a for loop    
    integer increment, limit, initial, loopvar, jump
    
    increment = Code[pc+1]
    limit = Code[pc+2]
    initial = Code[pc+3]
    -- ignore current_sub = Code[pc+4] - we don't patch the ENDFOR
    -- so recursion is not a problem
    loopvar = Code[pc+5]
    jump = Code[pc+6]
    
    il( sprintf("%s: inc %s, lim %s, initial %s, lv %s, jmp %04d",
    	{opnames[Code[pc]]} & names( Code[pc+1..pc+3] & Code[pc+5]) & Code[pc+6]), 6 )
    pc += 7
end procedure

procedure opENDFOR_GENERAL() -- ENDFOR_INT_UP,
			     -- ENDFOR_UP, ENDFOR_INT_DOWN1,
			     -- ENDFOR_INT_DOWN, ENDFOR_DOWN,
			     -- ENDFOR_GENERAL
-- end of for loop: exit or go back to the top
    il( sprintf("%s: top %04d lim %s, inc %s, lv %s",
    	{opnames[Code[pc]], Code[pc+1]} & names( Code[pc+2..pc+4] )), 4)
    pc += 5
end procedure

procedure opENDFOR_INT_UP1() -- ENDFOR_INT_UP1
-- faster: end of for loop with known +1 increment
-- exit or go back to the top
-- (loop var might not be integer, but that doesn't matter here)
    
    il( sprintf("ENDFOR_INT_UP1: top %04d, lim: %s, lv %s",
    	Code[pc+1] & names( Code[pc+2..pc+3] )), 4)
    pc += 5
end procedure

--
--
--sequence e_routine -- list of routines with a routine id assigned to them
--e_routine = {}
--
procedure opCALL_PROC() -- or opCALL_FUNC 
	sequence proc

    
    a = Code[pc+1]  -- routine id
    b = Code[pc+2]  -- argument list
    if Code[pc] = CALL_FUNC then
    	il( sprintf("%s: %s %s", {opnames[Code[pc]]} & names( a&b & Code[pc+3]) ), 3 )
    else
    	il( sprintf("%s: %s %s", {opnames[Code[pc]]} & names( a&b) ), 2 )
    end if
    
    
    pc += 3 + (Code[pc] = CALL_FUNC)

end procedure
	      
procedure opROUTINE_ID()
--    integer sub, fn, p
--    object name

--    sub = Code[pc+1]   -- CurrentSub
--    name = val[Code[pc+2]]  -- routine name sequence
--    fn = Code[pc+4]    -- file number
    target = Code[pc+5]
    il( sprintf("ROUTINE_ID: %s => %s", names( Code[pc+3] & target )), 5 )
    pc += 6
end procedure
	    
procedure opAPPEND()
	binary()
end procedure

procedure opPREPEND() 
	binary()

end procedure

procedure opCONCAT()
	binary()

end procedure
	    
procedure opCONCAT_N()
    -- concatenate 3 or more items
    integer n
    object x
    
    n = Code[pc+1] -- number of items
    -- operands are in reverse order
    x = sprintf("CONCAT_N: %d", Code[pc+1] )
    for i = pc+3 to pc+n+1 do
		x &= sprintf(", %s", {name_or_literal(Code[i])})
    end for
    target = Code[pc+n+2]
    il( sprintf( "%s => %s", {x, name_or_literal( target )}), n + 2 )

    pc += n+3
end procedure
	    
procedure opREPEAT()
	binary()

end procedure

procedure opDATE()
	nonary()
end procedure

procedure opTIME()
	nonary()
end procedure

procedure opSPACE_USED() -- RDS DEBUG only
	nonary()
--    pc += 2
end procedure

procedure opNOP2()   -- space filler
	nonary()
--    pc+= 2
end procedure

procedure opPOSITION()
	pbinary()
end procedure
	    
procedure opEQUAL()
	binary()
end procedure
		
procedure opCOMPARE()
	binary()
end procedure

procedure opFIND()
	binary()
end procedure

procedure opFIND_FROM()
	trinary()
end procedure

procedure opMATCH_FROM()
	trinary()
end procedure

procedure opMATCH()
	binary()
end procedure

procedure opPEEK4U()
	unary()
end procedure
	
procedure opPEEK4S()
	unary()
end procedure
	
procedure opPEEK()
	unary()
end procedure

procedure opPOKE()
	pbinary()
end procedure
	
procedure opPOKE4()
	pbinary()
end procedure

procedure opMEM_COPY()
	ptrinary()
end procedure
	    
procedure opMEM_SET()
	ptrinary()
end procedure
	    
procedure opPIXEL()
	pbinary()
end procedure
	    
procedure opGET_PIXEL()
	unary()
end procedure
	  
procedure opCALL()
	punary()
end procedure

procedure opSYSTEM()
	pbinary()
end procedure
		
procedure opSYSTEM_EXEC()
	binary()
end procedure
		
-- I/O routines

procedure opOPEN()
	binary()
end procedure

procedure opCLOSE()
	punary()
end procedure
	      
procedure opABORT()
	punary()
end procedure

procedure opGETC()  -- read a character from a file 
	unary()
end procedure
 
procedure opGETS()  -- read a line from a file */
	unary()
end procedure

procedure opGET_KEY() 
-- read an immediate key (if any) from the keyboard 
-- or return -1 
	nonary()
end procedure

procedure opCLEAR_SCREEN()
	pnonary()
end procedure

procedure opPUTS()
	pbinary()
end procedure
--
procedure opQPRINT()
-- Code[pc+1] not used
	
    a = Code[pc+2]
    il( sprintf( "QPRINT: %s",{name_or_literal( a )} ), 2 )
    pc += 3
end procedure
	
procedure opPRINT()
	pbinary()
end procedure

procedure opPRINTF()
    -- printf
    ptrinary() 
end procedure

procedure opSPRINTF()
	binary()
end procedure

procedure opCOMMAND_LINE()
    sequence cmd
    nonary()
end procedure

procedure opGETENV()
	unary()
end procedure

procedure opC_PROC()
	pbinary()
end procedure
	  
procedure opC_FUNC()
	binary()
end procedure
	    
procedure opTRACE()
	punary()
end procedure
--	    
-- other tracing/profiling ops - ignored
procedure opPROFILE() --or DISPLAY_VAR, ERASE_PRIVATE_NAMES, ERASE_SYMBOL
    -- NOT IMPLEMENTED, ignore
    punary()
--    pc += 2
end procedure

procedure opUPDATE_GLOBALS()
-- for interactive trace
	pnonary()
end procedure

-- begin mwl
procedure opEVAL()
	unary()
end procedure

procedure opEVAL_ERROR()
	nonary()
end procedure

procedure opVAR_ID()
--    integer sub, fn, p
--    object name

--    sub = Code[pc+1]   -- CurrentSub
--    name = val[Code[pc+2]]  -- routine name sequence
--    fn = Code[pc+4]    -- file number
    target = Code[pc+5]
    il( sprintf("VAR_ID: %s => %s", names( Code[pc+3] & target )), 5 )
    pc += 6
end procedure

procedure opREAD_VAR()
	unary()
end procedure

procedure opWRITE_VAR()
	pbinary()
end procedure

procedure opDUMP_VARS()
	nonary()
end procedure
-- end mwl


procedure opMACHINE_FUNC()
	binary()
end procedure

procedure opMACHINE_PROC()
    pbinary()
end procedure
with trace
procedure line_print( integer fn, object p )
	integer break, count
	if atom(p) then
		print(fn, p)
		return
	end if
	p = pretty_sprint( p )
	count = 0
	while length(p) > 95 do
		break = 95
		while break < length(p) and p[break] != ',' do
			break += 1
		end while
		if count then
			puts(fn, '\t')
		else
			count += 1
		end if
		
		puts(fn, p[1..break])
		p = p[break+1..$]
		if length(p) then
			puts(fn,"\n")
		end if
	end while
	
	if count then
		puts(fn, '\t')
	end if
	puts(fn, p )
end procedure

procedure opDEFAULT_GOTO()
-- DEFAULT_GOTO, file, label
	punary()
end procedure

procedure opIS_GOTO()
-- IS_GOTO, file, label
	unary()
end procedure

procedure opGOTO()
	il( sprintf( "%s: %s, file: %d strict: %d", 
		{opnames[Code[pc]]} & names(Code[pc+1..pc+1]) & Code[pc+2..pc+3]), 3)
	pc += 4
end procedure

procedure opGOTO_STATIC()
	integer sub, ix
	sequence gotos
	sub = Code[pc+2]
	gotos = SymTab[sub][S_GOTO]
	ix = find( Code[pc+1], gotos[G_PC] )
	il( sprintf( "%s: %s:%d Sub: %d UNUSED: %d",
		{opnames[Code[pc]], pretty_source(gotos[G_LABEL][ix][2])} & Code[pc+1..pc+3]), 3 )
	pc += 4
end procedure

procedure save_il( sequence name )
	integer st

	st = open( sprintf("%ssym", { name }), "wb" )

	for j = 1 to length( SymTab ) do
		print( st, j & SymTab[j] ) 
		puts( st, "\n" )
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
	elsif find(name, {"EXIT", "ENDWHILE"}) then
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
	elsif find(name, {"DISPLAY_VAR", "ERASE_PRIVATE_NAMES", 
			  "ERASE_SYMBOL"}) then
	    name = "PROFILE"
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
--	    RTInternal("no routine id for op" & name)
	end if
    end for
end procedure

function max( integer a, integer b )
	if a > b then
		return a
	end if
	return b
end function

procedure dis( integer sub )

	integer op, ix
	object gotos
	sequence label, sym
	
	printf( out, "\nSubProgram [%s:%05d]\n", {SymTab[sub][S_NAME], sub})
	Code = SymTab[sub][S_CODE]
	pc = 1
	gotos = SymTab[sub][S_GOTO]
	if atom(gotos) then
		gotos = {{},{}}
	end if
	while pc <= length(Code) do
		ix = find( pc, gotos[2] )
		if ix then
			-- a goto label
			if length(gotos[1][ix]) = 2 then
				-- can put the value in directly...
				label = pretty_source(gotos[1][ix][2])
			else
				label = name_or_literal( gotos[1][ix][3] )
--				sym = SymTab[gotos[1][ix][3]][S_NAME]
--				if length(sym) >=
--					-- it's a variable, so put the variable name in
--					label = 
--				else
--					-- just a temp...
--				end if
				
			end if
			printf( out, "%6s:%s# GOTO_LABEL: %s\n", 
				{ label, repeat(32, 40 - max(6, length(label))), label})
		end if
		op = Code[pc]
		call_proc(operation[op], {}) 
	end while
	printf( out, "End SubProgram [%s:%05d]\n", {SymTab[sub][S_NAME], sub})
end procedure

function crash( object c )
	save_il( "dis" )
	return 0
end function
crash_routine(routine_id("crash"))


include wildcard.e
procedure main()
	sequence cmd, file
	integer fn
	object void

	cmd = command_line()
	if length(cmd) < 3 then
		return
	end if
	
	file = cmd[3]
	if length(file) <= 3 or compare( lower(file[$-2..$]), ".oe" ) then
		file &= ".oe"
	end if
	
	fn = open( file, "rb" )
	void = tmp_alloc()
	void = tmp_alloc()
	void = tmp_alloc()
	void = NewEntry("_call_back_", 0, 0, PROC, 0, 0, 0)
	InitSymTab()
	
	SymTab = SymTab[1..$-2]
	SymTab &= read_symtab( fn )
	close(fn)

	out = open( file[1..$-2] & "dis", "w" )
	InitBackEnd()
	for i = 1 to length(SymTab) do
		if length(SymTab[i]) = SIZEOF_ROUTINE_ENTRY and sequence(SymTab[i][S_CODE]) then
			dis( i )
		else
			-- other symbols?
		end if
	end for
	save_il( file[1..$-2] )
end procedure
main()


