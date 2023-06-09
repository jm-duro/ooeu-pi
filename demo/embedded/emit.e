-- Euphoria 2.5
-- Routines to emit the IL opcode stream
include reswords.e as r

global integer op_info1, op_info2
global integer optimized_while

global integer trace_called 
trace_called = FALSE

global integer last_routine_id
last_routine_id = 0

global integer max_params   -- maximum number of parameters in user routines 
max_params = 0

global integer last_max_params
last_max_params = 0

global integer previous_op  -- the previous opcode emitted
previous_op = -1  

global sequence current_sequence  -- stack needed by $ operation
current_sequence = {}

global boolean lhs_ptr   -- are we parsing multiple LHS subscripts?
lhs_ptr = FALSE

-- temps needed for LHS subscripting
global symtab_index lhs_subs1_copy_temp,
		    lhs_target_temp      

-- Code generation Stack 
global sequence cg_stack -- expression stack 

boolean assignable   -- did previous op have a re-assignable result?
assignable = FALSE         

constant LEX_NUMBER = 1
constant LEX_NAME = 2

-- descriptive names for scanner tokens - keep up-to-date 
constant token_name = 
{ 
    {AND, "'and'"},
    {ATOM, "a number"},
    {BANG, "'!'"},
    {BY, "'by'"},
    {COLON, "':'"},
    {COMMA, "','"},
    {CONCAT, "'&'"},
    {CONSTANT, "'constant'"},
    {DIVIDE, "'/'"},
    {DO, "'do'"},
    {ELSE, "'else'"},
    {ELSIF, "'elsif'"},
    {END, "'end'"},
    {END_OF_FILE, "the end of file"},
    {EQUAL, "'='"},
    {EXIT, "'exit'"},
    {FOR, "'for'"},
    {r:FUNC, "a function"},
    {FUNCTION, "'function'"},
    {GLOBAL, "'global'"},
    {GREATER, "'>'"},
    {GREATEREQ, "'>='"},
    {IF,  "'if'"},
    {ILLEGAL_CHAR, "an illegal character"},
    {INCLUDE, "'include'"},
    {LEFT_BRACE, "'{'"},
    {LEFT_ROUND, "'('"},
    {LEFT_SQUARE, "'['"},
    {LESS, "'<'"},
    {LESSEQ, "'<='"},
    {MINUS, "'-'"},
    {MULTIPLY, "'*'"},
    {NAMESPACE, "a namespace qualifier"},
    {NEWLINE, "end-of-line"},
    {NOT, "'not'"},
    {NOTEQ, "'!='"},
    {OR, "'or'"},
    {PLUS, "'+'"},
    {r:PROC, "a procedure"},
    {PROCEDURE, "'procedure'"},
    {QUALIFIED_VARIABLE, "a variable"},
    {QUALIFIED_FUNC, "a function"},
    {QUALIFIED_PROC, "a procedure"},
    {QUALIFIED_TYPE, "a type"},
    {RIGHT_BRACE, "'}'"},
    {RIGHT_ROUND, "')'"},
    {RIGHT_SQUARE, "']'"},
    {RETURN, "'return'"},
    {SLICE, "a slice"},
    {STRING, "a character string"},
    {TO, "'to'"},
    {THEN, "'then'"},
    {TYPE, "a type"},
    {TYPE_DECL, "'type'"},
    {VARIABLE, "a variable"},
    {WITH, "'with'"},
    {WITHOUT, "'without'"},
    {WHILE, "'while'"},
    {'?', "'?'"}
    -- begin mwl
    ,
    {CLASS, "a euclass"},
    {DOT_NOTATION, "'.'"},
    {OF, "'of'"},
    {GOTO, "goto"},
    {GOTO_STATIC, "goto" }
    
    -- end mwl
} 

--begin mwl
--made this global
global procedure Push(symtab_index x) 
-- end mwl
-- Push element onto code gen stack 
    cg_stack = append(cg_stack, x)

end procedure

function Top() 
-- return top element on code gen stack 
    return cg_stack[$]
end function


-- begin mwl:
-- made this global
global function Pop()
-- end mwl
-- Pop top element from code gen stack 
    symtab_index t

    t = cg_stack[$]
    cg_stack = cg_stack[1..$-1]
    if SymTab[t][S_MODE] = M_TEMP then
	SymTab[t][S_SCOPE] = FREE -- mark it as being free
			-- n.b. we assume one copy of temp on stack 
			-- temps are normally not Popped & Pushed back on stack
			-- but see TempKeep() and TempFree() above 
    end if
    return t    
end function

-- begin mwl
-- Pops a subscript off the code gen stack and 
-- adds to the member_stack
-- Used for sequence of type members
global procedure PopMember()
	integer x
	member_stack &= - Pop()
	
	-- Also Pop the sequence off, since it will
	-- be handled by Method[Func]()
--	x = Pop()
end procedure
-- end mwl

procedure TempKeep(symtab_index x)
    if SymTab[x][S_MODE] = M_TEMP then
	SymTab[x][S_SCOPE] = IN_USE
    end if
end procedure

global procedure TempFree(symtab_index x)  
   if SymTab[x][S_MODE] = M_TEMP then
       SymTab[x][S_SCOPE] = FREE 
   end if
end procedure

procedure TempInteger(symtab_index x)  
    if SymTab[x][S_MODE] = M_TEMP then
	SymTab[x][S_USAGE] = T_INTEGER
    end if
end procedure


global function LexName(integer t)
-- returns token name given token number 
    integer i
    
    i = 1
    while i <= length(token_name) and t != token_name[i][LEX_NUMBER] do
	i += 1
    end while
    if i > length(token_name) then
	return "this ..." -- try to avoid this case 
    else
	return token_name[i][LEX_NAME]
    end if
end function

global procedure InitEmit()
-- initialize code emission 
    cg_stack = {}
end procedure

function IsInteger(symtab_index sym)
-- return TRUE if sym is known to be of integer type 
    integer mode
    symtab_index t, pt
    
    mode = SymTab[sym][S_MODE]
    if mode = M_NORMAL then
	t = SymTab[sym][S_VTYPE] 
	if t = integer_type then
	    return TRUE
	end if
	if t then
	    pt = SymTab[t][S_NEXT]
	    if pt and SymTab[pt][S_VTYPE] = integer_type then
		return TRUE   -- usertype(integer x)
	    end if
	end if
    
    elsif mode = M_CONSTANT then
	if integer(SymTab[sym][S_OBJ]) then  -- bug fixed: can't allow PLUS1_I op 
	    return TRUE
	end if
    
    elsif mode = M_TEMP then
	if SymTab[sym][S_USAGE] = T_INTEGER then
	    return TRUE
	end if
    end if
    
    return FALSE
end function

-- n.b. I don't enforce ATOM type unless type_check is on,
-- so it won't be proper to assume that a value is going
-- to be ATOM at run-time, based on type declarations or temp info. 
-- Therefore "IsAtom()" would be questionable except maybe for constants. 

procedure emit(integer val)
-- emit a value into the code stream 
    Code = append(Code, val)
end procedure

-- When looking at previous_op, make sure that there 
-- can be no jump around the previous op to the current op.
-- i.e. it is not always *really* the previous op executed 
-- - BE CAREFUL! Often there must be some expression (opnd)
-- prior to the current op.

global procedure emit_opnd(symtab_index opnd)
-- emit an operand into the IL  
    Push(opnd)
    previous_op = -1  -- N.B.
end procedure

global procedure emit_addr(atom x)
-- emit a long integer or an operand address into the IL
    Code = append(Code, x)
end procedure

procedure emit_opcode(integer op)
-- emit an opcode into the IL
    Code = append(Code, op)
end procedure

global procedure backpatch(integer index, integer val)
-- back patch a word of code 
    Code[index] = val
end procedure

sequence op_result  -- result types of operators
op_result = repeat(T_UNKNOWN, MAX_OPCODE)
-- the operation must *always* return this type, regardless of input
op_result[RIGHT_BRACE_N] = T_SEQUENCE
op_result[RIGHT_BRACE_2] = T_SEQUENCE
op_result[REPEAT] = T_SEQUENCE
op_result[APPEND] = T_SEQUENCE
op_result[RHS_SLICE] = T_SEQUENCE
op_result[CONCAT] = T_SEQUENCE
op_result[CONCAT_N] = T_SEQUENCE
op_result[PREPEND] = T_SEQUENCE
op_result[COMMAND_LINE] = T_SEQUENCE
op_result[SPRINTF] = T_SEQUENCE
op_result[ROUTINE_ID] = T_INTEGER
op_result[GETC] = T_INTEGER
op_result[OPEN] = T_INTEGER
op_result[LENGTH] = T_INTEGER   -- assume less than a billion
op_result[PLENGTH] = T_INTEGER  -- ""
op_result[IS_AN_OBJECT] = T_INTEGER
op_result[IS_AN_ATOM] = T_INTEGER
op_result[IS_A_SEQUENCE] = T_INTEGER
op_result[COMPARE] = T_INTEGER
op_result[EQUAL] = T_INTEGER
op_result[FIND] = T_INTEGER
op_result[MATCH]  = T_INTEGER
op_result[GET_KEY] = T_INTEGER
op_result[IS_AN_INTEGER] = T_INTEGER
op_result[ASSIGN_I] = T_INTEGER
op_result[RHS_SUBS_I] = T_INTEGER
op_result[PLUS_I] = T_INTEGER
op_result[MINUS_I] = T_INTEGER
op_result[PLUS1_I] = T_INTEGER
op_result[SYSTEM_EXEC] = T_INTEGER
op_result[TIME] = T_ATOM
-- begin mwl
op_result[EVAL] = T_INTEGER
op_result[EVAL_ERROR] = T_SEQUENCE
op_result[VAR_ID] = T_INTEGER
op_result[DUMP_VARS] = T_SEQUENCE
op_result[FIND_FROM] = T_INTEGER
op_result[MATCH_FROM] = T_INTEGER
-- end mwl

procedure cont11ii(integer op, boolean ii)
-- if ii is TRUE then integer arg always produces integer result
    integer t, source, c
    
    emit_opcode(op)
    source = Pop()
    emit_addr(source)
    assignable = TRUE
    t = op_result[op]

     -- for PEEK should really check for IsAtom(source)
    if t = T_INTEGER or (ii and IsInteger(source)) then
	c = NewTempSym()
	TempInteger(c)
    else 
	c = NewTempSym() -- allocate *after* checking opnd type
    end if
    Push(c)
    emit_addr(c)
end procedure

procedure cont21d(integer op, integer a, integer b, boolean ii)    
    integer c, t
    
    assignable = TRUE
    t = op_result[op]
    if t = T_INTEGER or (ii and IsInteger(a) and IsInteger(b)) then
	c = NewTempSym()
	TempInteger(c)
    else 
	c = NewTempSym() -- allocate *after* checking opnd types
    end if   
    Push(c)
    emit_addr(c)
end procedure
	
procedure cont21ii(integer op, boolean ii)
    integer a, b
    
    b = Pop()
    emit_opcode(op)
    a = Pop()
    emit_addr(a)
    emit_addr(b)
    cont21d(op, a, b, ii)
end procedure

function good_string(sequence elements)
-- are all elements suitable for a string?
    object obj
    symtab_index e
    sequence element_vals
    
    if TRANSLATE and length(elements) > 10000 then
	return -1 -- A huge string might upset the C compiler.
    end if
    element_vals = {}
    for i = 1 to length(elements) do
	e = elements[i]
	obj = SymTab[e][S_OBJ]
	if SymTab[e][S_MODE] = M_CONSTANT and
	   integer(obj) and 
	   (not TRANSLATE or 
	    (obj >= 1 and obj <= 255)) then
	    -- Non C chars are currently inconvenient in TRANSLATOR.
	    element_vals = prepend(element_vals, obj)
	else
	    return -1
	end if
    end for
    return element_vals
end function

global procedure emit_op(integer op)
-- Emit a postfix operator.
-- The cases have been sorted according to profile frequency.
-- About 60% of the time it's one of the first 6 cases.
-- You might get greater speed by converting the chain of elsif's 
-- to a single call_proc(), as in execute.e.
    symtab_index a, b, c, d, source, target, subsym
    symtab_index lhs_var
    integer ib, ic, n
    object obj
    sequence elements
    object element_vals
    
    -- begin mwl
    if length(eval_error[$]) then
    	return
    end if
    -- end mwl
    -- 1 input, 0 outputs, can combine with previous op 
    if op = ASSIGN then
	source = Pop()
	target = Pop()
	if assignable then
	    -- replace previous op (temp) target with ASSIGN target 
	    Code = Code[1..$-1] -- drop previous target
	    op = previous_op -- keep same previous op 
	    if IsInteger(target) then
		if previous_op = RHS_SUBS then
		    op = RHS_SUBS_I
		    backpatch(length(Code) - 2, op)

		elsif previous_op = PLUS1 then
		    op = PLUS1_I
		    backpatch(length(Code) - 2, op)
		
		elsif previous_op = PLUS or previous_op = MINUS then
		    if IsInteger(Code[$]) and
		       IsInteger(Code[$-1]) then
			if previous_op = PLUS then
			    op = PLUS_I
			else
			    op = MINUS_I
			end if
			backpatch(length(Code) - 2, op)
		    end if  
		
		else 
		    -- if target to-be-overwritten was integer then avoid
		    -- INTEGER_CHECK and ATOM_CHECK 
		    if IsInteger(source) then
			op = ASSIGN_I -- fake to avoid subsequent check
		    end if
		end if
	    end if
	
	else 
	    if IsInteger(source) and IsInteger(target) then
		op = ASSIGN_I
	    end if
	    if SymTab[source][S_MODE] = M_CONSTANT and 
	       SymTab[target][S_MODE] = M_CONSTANT then
		-- record: constant var=literal 
		-- for interpreter
		SymTab[target][S_OBJ] = SymTab[source][S_OBJ]
	    end if          
	    
	    emit_opcode(op)
	    emit_addr(source)
	
	end if
	
	assignable = FALSE
	emit_addr(target)

    elsif op = RHS_SUBS then
	b = Pop() -- subscript 
	c = Pop() -- sequence 
	target = NewTempSym() -- target 

	if SymTab[c][S_MODE] = M_NORMAL then
	    if SymTab[c][S_VTYPE] != sequence_type and 
	    SymTab[SymTab[SymTab[c][S_VTYPE]][S_NEXT]][S_VTYPE] != 
	    sequence_type then
		op = RHS_SUBS_CHECK
	    end if
	elsif SymTab[c][S_MODE] != M_CONSTANT or 
		 not sequence(SymTab[c][S_OBJ]) then
	    op = RHS_SUBS_CHECK
	end if
	emit_opcode(op)
	emit_addr(c)
	emit_addr(b)
	assignable = TRUE
	Push(target)
	emit_addr(target)
	current_sequence = append(current_sequence, target)
	
    elsif op = r:PROC then  -- procedure, function and type calls
		assignable = FALSE -- assume for now 
		subsym = op_info1
		n = SymTab[subsym][S_NUM_ARGS]
	    
		if subsym = CurrentSub then
		    -- calling ourself - parameter values may 
		    -- get overwritten before we can use them 
		    for i = length(cg_stack)-n+1 to length(cg_stack) do
			if SymTab[cg_stack[i]][S_SCOPE] = SC_PRIVATE and 
			   SymTab[cg_stack[i]][S_VARNUM] < i then
			    -- copy parameter to a temp 
			    emit_opcode(ASSIGN)
			    emit_addr(cg_stack[i])
			    cg_stack[i] = NewTempSym()
			    emit_addr(cg_stack[i])
			end if
		    end for
		end if
		emit_opcode(op)
		emit_addr(subsym)
		for i = length(cg_stack)-n+1 to length(cg_stack) do 
		    emit_addr(cg_stack[i])
		    TempFree(cg_stack[i])
		end for
	
		cg_stack = cg_stack[1..$-n]
	
		if SymTab[subsym][S_TOKEN] != r:PROC then
		    assignable = TRUE
		    c = NewTempSym() -- put final result in temp 
		    Push(c)
		    -- emit location to assign result to 
		    emit_addr(c)
		end if

    -- 0 inputs, 0 outputs - note: parser may emit an extra word 
    elsif find(op, {NOP1, NOP2, NOPWHILE, PRIVATE_INIT_CHECK, GLOBAL_INIT_CHECK,
		STARTLINE, CLEAR_SCREEN, EXIT, ENDWHILE, ELSE, 
		ERASE_PRIVATE_NAMES, BADRETURNF, ERASE_SYMBOL, UPDATE_GLOBALS, 
		DISPLAY_VAR, CALL_BACK_RETURN, END_PARAM_CHECK}) then
	emit_opcode(op)
	assignable = FALSE
    
    -- 1 input, 0 outputs - special 
    elsif op = IF or op = WHILE then
	a = Pop()
	assignable = FALSE
	-- AND and OR will have been short-circuited:
	if previous_op >= LESS and previous_op <= NOT then
	    Code = Code[1..$-1] 
	    if previous_op = NOT then
		op = NOT_IFW
		backpatch(length(Code) - 1, op)
	    
	    else 
		if IsInteger(Code[$-1]) and
		   IsInteger(Code[$]) then 
		    op = previous_op + LESS_IFW_I - LESS
		else
		    op = previous_op + LESS_IFW - LESS
		end if
		backpatch(length(Code) - 2, op)
	    end if
	
	elsif op = WHILE and    
		-- need extra code in parser to optimize IF/ELSIF too 
	      SymTab[a][S_MODE] = M_CONSTANT and
	      integer(SymTab[a][S_OBJ]) and 
	      not equal(SymTab[a][S_OBJ], 0) then
	    optimized_while = TRUE   -- while TRUE ... emit nothing
	
	else 
	    emit_opcode(op)
	    emit_addr(a)       
	 
	end if

    elsif op = INTEGER_CHECK then
	assignable = FALSE
	if previous_op = ASSIGN then 
	    c = Code[$-1]
	    if not IsInteger(c) then
		emit_opcode(op)
		emit_addr(op_info1)
	    end if
	elsif previous_op = -1 or 
	      op_result[previous_op] != T_INTEGER then  -- includes ASSIGN_I
	    emit_opcode(op)
	    emit_addr(op_info1)
	end if

    elsif op = SEQUENCE_CHECK then
	assignable = FALSE
	if previous_op = ASSIGN then
	    c = Code[$-1]
	    if SymTab[c][S_MODE] != M_CONSTANT or 
	       not sequence(SymTab[c][S_OBJ]) then
		emit_opcode(op)
		emit_addr(op_info1)
	    end if
	elsif previous_op = -1 or 
	      op_result[previous_op] != T_SEQUENCE then
	    emit_opcode(op)
	    emit_addr(op_info1)
	end if

    elsif op = ATOM_CHECK then
	assignable = FALSE
	if previous_op = ASSIGN then
	    c = Code[$-1]
	    if (SymTab[c][S_MODE] != M_CONSTANT or not atom(SymTab[c][S_OBJ])) 
	       and not IsInteger(c) then
		emit_opcode(op)
		emit_addr(op_info1)
	    end if
	elsif previous_op = -1 or 
	      (op_result[previous_op] != T_INTEGER and
	       op_result[previous_op] != T_ATOM) then
	    emit_opcode(op)
	    emit_addr(op_info1)
	end if

    elsif op = RIGHT_BRACE_N then -- form a sequence of n items
	n = op_info1
	-- could optimize if they are all constants with known values
	elements = {}
	for i = 1 to n do
	    elements = append(elements, Pop())
	end for
	element_vals = good_string(elements)
	
	if sequence(element_vals) then
	    c = NewStringSym(element_vals)  -- make a string literal
	    assignable = FALSE
	else 
	    if n = 2 then
		emit_opcode(RIGHT_BRACE_2) -- faster op for two items
	    else 
		emit_opcode(op)
		emit(n)
	    end if
	    
	    for i = 1 to n do
		emit_addr(elements[i])
	    end for
	    
	    c = NewTempSym()
	    emit_addr(c)
	    assignable = TRUE
	end if
	Push(c)

	-- 3 inputs, 0 outputs 
    elsif op = ASSIGN_SUBS2 or -- can't change the op
	  op = ASSIGN_SUBS or 
	  op = PASSIGN_SUBS then  -- can't change the op
	b = Pop() -- rhs value 
	a = Pop() -- subscript
	c = Pop() -- sequence 
	if op = ASSIGN_SUBS then
	    -- maybe change the op
	    if (previous_op != LHS_SUBS) and 
		(SymTab[c][S_MODE] != M_NORMAL or 
		(SymTab[c][S_VTYPE] != sequence_type and 
		SymTab[SymTab[SymTab[c][S_VTYPE]][S_NEXT]][S_VTYPE] != 
		sequence_type)) then
		op = ASSIGN_SUBS_CHECK
	    else 
		if IsInteger(b) then
		    op = ASSIGN_SUBS_I
		end if
	    end if
	    emit_opcode(op)
	
	elsif op = PASSIGN_SUBS then
	    emit_opcode(PASSIGN_SUBS) -- always
	    
	else 
	    emit_opcode(ASSIGN_SUBS) -- always
	
	end if
	
	emit_addr(c) -- sequence
	emit_addr(a) -- subscript 
	emit_addr(b) -- rhs value
	assignable = FALSE

    elsif op = LHS_SUBS or op = LHS_SUBS1 or op = LHS_SUBS1_COPY then  
	-- left hand side multiple subscripts, one step
	a = Pop() -- subs
	lhs_var = Pop() -- sequence
	emit_opcode(op)
	emit_addr(lhs_var)
	emit_addr(a)
	if op = LHS_SUBS then
	    TempKeep(lhs_var) -- should be lhs_target_temp
	    emit_addr(lhs_target_temp)
	    Push(lhs_target_temp)
	    emit_addr(0) -- place holder 
	else    
	    -- first LHS subscript 
	    -- Note: LHS_SUBS1 might be patched later to LHS_SUBS1_COPY
	    lhs_target_temp = NewTempSym() -- use same temp for all subscripts
	    emit_addr(lhs_target_temp) -- target temp holds pointer to sequence
	    Push(lhs_target_temp)
	    lhs_subs1_copy_temp = NewTempSym() -- place to copy (may be ignored)
	    emit_addr(lhs_subs1_copy_temp)
	end if
	current_sequence = append(current_sequence, lhs_target_temp)
	assignable = FALSE  -- need to update current_sequence like in RHS_SUBS
	
	-- 1 input, 1 output 
    elsif find(op, {RAND, PEEK, PEEK4S, PEEK4U, NOT_BITS, NOT}) then
	cont11ii(op, TRUE)
	    
    elsif op = UMINUS then
	-- check for constant folding 
	a = Pop()
	obj = SymTab[a][S_OBJ]
	if SymTab[a][S_MODE] = M_CONSTANT then
	    if integer(obj) then
		if obj = MININT then
		    Push(NewDoubleSym(-MININT_VAL))
		else
		    Push(NewIntSym(-obj))
		end if
	    elsif atom(obj) and obj != NOVALUE then
		-- N.B. a constant won't have its value set until
		-- the end of the  constant var=xxx, var=xxx, ...
		-- statement. Be careful in the future if we
		-- add any more constant folding besides unary minus. 
		Push(NewDoubleSym(-obj)) 
	    else
		Push(a)
		cont11ii(op, FALSE)   
	    end if 
	else
	    Push(a)
	    cont11ii(op, FALSE)   
	end if
    
    elsif find(op, {IS_AN_INTEGER, IS_AN_ATOM, IS_A_SEQUENCE, IS_AN_OBJECT,
		    LENGTH, GETC, SQRT, SIN, COS, TAN, ARCTAN, LOG, GETS, 
		    GET_PIXEL, GETENV}) then
	cont11ii(op, FALSE)   
	
	-- special 1 input, 1 output - also emits CurrentSub 
    elsif op = ROUTINE_ID then
	emit_opcode(op)
	source = Pop()
	if TRANSLATE then
	    emit_addr(num_routines-1)
	else
	if BIND or not execute then
	    -- note reference to this routine
	    MarkTargets(source, S_NREFS) 
	end if
	emit_addr(CurrentSub)
	    emit_addr(length(SymTab))
	end if
	emit_addr(source)
	emit_addr(current_file_no)  -- necessary at top level
	assignable = TRUE
	c = NewTempSym()
	TempInteger(c) -- result will always be an integer
	Push(c)
	emit_addr(c)
	    
	-- 1 input, 1 outputs with jump address that might be patched.
	-- Output value is not used by the next op, but same temp must
	-- be used by SC2 ops. 
    elsif op = SC1_OR or op = SC1_AND then
	emit_opcode(op)
	emit_addr(Pop())       
	c = NewTempSym()
	Push(c)
	emit_addr(c)
	assignable = FALSE
	-- jump address to follow 
	
	-- 2 inputs, 0 outputs 
    elsif find(op, {SYSTEM, PUTS, PRINT, QPRINT, POSITION, MACHINE_PROC,
		    C_PROC, PIXEL, POKE, POKE4}) then
	emit_opcode(op)
	b = Pop()
	emit_addr(Pop())
	emit_addr(b)
	assignable = FALSE
		
	-- 2 inputs, 1 output 
    elsif find(op, {EQUALS, LESS, GREATER, NOTEQ, LESSEQ, GREATEREQ,
		    AND, OR, XOR, REMAINDER, AND_BITS, OR_BITS, XOR_BITS}) then
	cont21ii(op, TRUE)  -- both integer args => integer result
	
    elsif op = PLUS then
	-- result could overflow int
	b = Pop()
	a = Pop()
	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 1) then 
	    op = PLUS1
	    emit_opcode(op)
	    emit_addr(a)
	    emit_addr(0)
	    cont21d(op, a, b, FALSE)
	elsif SymTab[a][S_MODE] = M_CONSTANT and equal(SymTab[a][S_OBJ], 1) then
	    op = PLUS1
	    emit_opcode(op)
	    emit_addr(b)
	    emit_addr(0)
	    cont21d(op, a, b, FALSE)
	else 
	    Push(a)
	    Push(b)
	    cont21ii(op, FALSE)
	end if
	
    elsif op = MULTIPLY then
	    -- result could overflow int
	b = Pop()
	a = Pop()
	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then
	    -- Note: x * 2.0 is just as fast as x + x when x is f.p. 
	    op = PLUS
	    emit_opcode(op)
	    emit_addr(a)
	    emit_addr(a)
	    cont21d(op, a, b, FALSE)
	    
	elsif SymTab[a][S_MODE] = M_CONSTANT and equal(SymTab[a][S_OBJ], 2) then
	    op = PLUS
	    emit_opcode(op)
	    emit_addr(b)
	    emit_addr(b)
	    cont21d(op, a, b, FALSE)
	    
	else 
	    Push(a)
	    Push(b)
	    cont21ii(op, FALSE)
	    
	end if
	    
    elsif op = DIVIDE then
	b = Pop()
	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then
	    op = DIV2
	    emit_opcode(op)
	    emit_addr(Pop()) -- n.b. "a" hasn't been set
	    a = 0
	    emit_addr(0)
	    cont21d(op, a, b, FALSE)  -- could have fractional result
	else 
	    Push(b) 
	    cont21ii(op, FALSE)
	end if
	
    elsif op = FLOOR then
	if previous_op = DIVIDE then
	    op = FLOOR_DIV
	    backpatch(length(Code) - 3, op)
	    assignable = TRUE
	
	elsif previous_op = DIV2 then
	    op = FLOOR_DIV2
	    backpatch(length(Code) - 3, op)
	    assignable = TRUE
	    if IsInteger(Code[$-2]) then
		TempInteger(Top()) --mark temp as integer type
	    end if
	else
	    cont11ii(op, TRUE)
	end if
	-- TRUE for FLOOR  
	-- but not FLOOR_DIV (x/-1)
	
    elsif find(op, {MINUS, APPEND, PREPEND, COMPARE, EQUAL, FIND, MATCH,
		    SYSTEM_EXEC, CONCAT, REPEAT, MACHINE_FUNC, C_FUNC,
		    OPEN, SPRINTF}) then
	cont21ii(op, FALSE)
	
    elsif op = SC2_NULL then  -- correct the stack - we aren't emitting anything
	c = Pop()
	TempKeep(c)
	b = Pop()  -- remove SC1's temp
	Push(c)
	assignable = FALSE
	    
    -- Same temp must be used by SC2 ops and SC1 ops. 
    elsif op = SC2_AND or op = SC2_OR then
	emit_opcode(op)
	emit_addr(Pop())       
	c = Pop()
	TempKeep(c)
	emit_addr(c) -- target
	TempInteger(c)
	Push(c)
	assignable = FALSE
	
    -- 3 inputs, 0 outputs 
    elsif find(op, {MEM_COPY, MEM_SET, PRINTF}) then
	emit_opcode(op)
	c = Pop()
	b = Pop()
	emit_addr(Pop())
	emit_addr(b)
	emit_addr(c)
	assignable = FALSE

    -- 3 inputs, 1 output 
    elsif op = RHS_SLICE then -- rhs slice of a sequence a[i:j] 
	emit_opcode(op)
	c = Pop()
	b = Pop()
	emit_addr(Pop())
	emit_addr(b)
	emit_addr(c)
	c = NewTempSym()
	assignable = TRUE
	Push(c)
	emit_addr(c)

    -- n inputs, 1 output 
    elsif op = CONCAT_N then     -- concatenate 3 or more items
	n = op_info1  -- number of items to concatenate
	emit_opcode(CONCAT_N)
	emit(n)
	for i = 1 to n do 
	    emit_addr(Pop())  -- reverse order
	end for
	c = NewTempSym()
	emit_addr(c)
	assignable = TRUE
	Push(c)
	    
    elsif op = FOR then

	c = Pop() -- increment 
	TempKeep(c)
	ic = IsInteger(c)
	if SymTab[c][S_MODE] = M_NORMAL and 
	    SymTab[c][S_SCOPE] != SC_LOOP_VAR and 
	    SymTab[c][S_SCOPE] != SC_GLOOP_VAR then
	    -- must make a copy in case var is modified 
	    emit_opcode(ASSIGN)
	    emit_addr(c)
	    c = NewTempSym()
	    emit_addr(c)
	end if
	b = Pop() -- limit 
	TempKeep(b)
	ib = IsInteger(b)
	if SymTab[b][S_MODE] = M_NORMAL and 
	    SymTab[b][S_SCOPE] != SC_LOOP_VAR and 
	    SymTab[b][S_SCOPE] != SC_GLOOP_VAR then
	    -- must make a copy in case var is modified 
	    emit_opcode(ASSIGN)
	    emit_addr(b)
	    b = NewTempSym()
	    emit_addr(b)
	end if
	a = Pop() -- initial value 
	if IsInteger(a) and ib and ic then
	    SymTab[op_info1][S_VTYPE] = integer_type
	    op = FOR_I
	else            
	    op = FOR
	end if
	emit_opcode(op)
	emit_addr(c)
	emit_addr(b)
	emit_addr(a)
	emit_addr(CurrentSub) -- in case recursion check is needed
	
	Push(b) 
	Push(c) 

	assignable = FALSE
	-- loop var, jump addr will follow 

    elsif op = ENDFOR_GENERAL or op = ENDFOR_INT_UP1 then  -- all ENDFORs  

	emit_opcode(op) -- will be patched at runtime 
	a = Pop() 
	emit_addr(op_info2) -- address of top of loop 
	emit_addr(Pop())    -- limit 
	emit_addr(op_info1) -- loop var 
	emit_addr(a)        -- increment - not always used - 
			    -- put it last - maybe different cache line 
	assignable = FALSE

    -- 3 inputs, 1 output 
    elsif op = ASSIGN_OP_SUBS or op = PASSIGN_OP_SUBS then   
	-- for x[i] op= expr 
	b = Pop()      -- rhs value, keep on stack 
	TempKeep(b)
	
	a = Pop()      -- subscript, keep on stack
	TempKeep(a)
	
	c = Pop()      -- lhs sequence, keep on stack
	TempKeep(c)
	
	emit_opcode(op)
	emit_addr(c)  
	emit_addr(a)    
	
	d = NewTempSym()
	emit_addr(d)   -- place to store result
	
	Push(c)
	Push(a)
	Push(d)
	Push(b)
	assignable = FALSE
	    
    -- 4 inputs, 0 outputs 
    elsif op = ASSIGN_SLICE or op = PASSIGN_SLICE then
	emit_opcode(op)
	b = Pop() -- rhs value
	a = Pop() -- 2nd subs
	c = Pop() -- 1st subs 
	emit_addr(Pop()) -- sequence
	emit_addr(c)
	emit_addr(a)  
	emit_addr(b)
	assignable = FALSE

    -- 4 inputs, 1 output 
    elsif op = ASSIGN_OP_SLICE or op = PASSIGN_OP_SLICE then  
	-- for x[i..j] op= expr 
	emit_opcode(op)
	    
	b = Pop()        -- rhs value not used
	TempKeep(b)
	    
	a = Pop()        -- 2nd subs
	TempKeep(a)
	    
	c = Pop()        -- 1st subs
	TempKeep(c)
	
	d = Pop()
	TempKeep(d)      -- sequence   
	
	emit_addr(d) 
	Push(d)
	
	emit_addr(c) 
	Push(c)
	    
	emit_addr(a) 
	Push(a)
	
	c = NewTempSym()
	Push(c)
	emit_addr(c)     -- place to store result
	
	Push(b)
	assignable = FALSE
	    
    -- special cases: 
    elsif op = CALL_PROC or op = EMBEDDED_PROCEDURE_CALL then
	emit_opcode(op)
	b = Pop()
	emit_addr(Pop())
	emit_addr(b)
	assignable = FALSE
	    
    elsif op = CALL_FUNC or op = EMBEDDED_FUNCTION_CALL then
	emit_opcode(op)
	b = Pop()
	emit_addr(Pop())
	emit_addr(b)
	assignable = TRUE
	c = NewTempSym() 
	Push(c)
	emit_addr(c)
	    
    elsif op = RETURNP then
	emit_opcode(op)
	emit_addr(CurrentSub)
	assignable = FALSE

    elsif op = RETURNF then
	emit_opcode(op)
	emit_addr(CurrentSub)
	emit_addr(Pop())
	assignable = FALSE

    elsif op = RETURNT then
	emit_opcode(op)
	assignable = FALSE

    elsif find(op, {DATE, TIME, SPACE_USED, GET_KEY, COMMAND_LINE}) then
	emit_opcode(op)
	c = NewTempSym()
	assignable = TRUE
	if op = GET_KEY then  -- it's in op_result as integer
	    TempInteger(c)
	end if
	Push(c)
	emit_addr(c)

    elsif find(op, {CLOSE, ABORT, CALL}) then
	emit_opcode(op)
	emit_addr(Pop())       
	assignable = FALSE
    
    elsif op = POWER then
	-- result could overflow int
	b = Pop()
	a = Pop()
	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then 
	    -- convert power(x,2) to x*x 
	    op = MULTIPLY
	    emit_opcode(op)
	    emit_addr(a)
	    emit_addr(a)
	    cont21d(op, a, b, FALSE)
	else 
	    Push(a)
	    Push(b)
	    cont21ii(op, FALSE)
	end if

	-- doesn't need 1 input, 0 outputs 
    elsif op = TYPE_CHECK then
	emit_opcode(op)
	c = Pop()       
	assignable = FALSE
	
    -- 0 inputs, 1 output, special op
    elsif op = DOLLAR then
	-- length of the current sequence (or pointer to current sequence)
	if lhs_ptr and length(current_sequence) = 1 then
	    emit_opcode(PLENGTH)
	else
	    emit_opcode(LENGTH) 
	end if
	
	emit_addr(current_sequence[$])
	c = NewTempSym()
	TempInteger(c)
	Push(c)
	emit_addr(c)
	
    -- 0 inputs, 1 output 
    elsif op = PLATFORM then -- always optimized - no code emitted 
	if ELINUX then
	    n = 3
	
	elsif BIND then
	    n = 1 + w32  -- set platform value based on bind option,
			 -- so one bind.il can serve DOS and Windows
	
	elsif EDOS then        
	    n = 1
	
	elsif EWINDOWS then
	    n = 2 
	
	end if
	
	Push(NewIntSym(n))
	assignable = FALSE
	
    -- 1 input, 0 outputs 
    elsif op = PROFILE then
	a = Pop()
	emit_opcode(op)
	emit_addr(a)       
	assignable = FALSE
	
    elsif op = TRACE then
	a = Pop()
	if OpTrace then
	    -- only emit trace op in a "with trace" section
	    emit_opcode(op)
	    emit_addr(a)       
	    if TRANSLATE then
		if not trace_called then
		    Warning("Statements have been inserted to trace execution of your program.")
		end if
		trace_called = TRUE
	    end if          
	end if
	assignable = FALSE
	
	-- begin mwl
	elsif op = VAR_ID then
		if preprocess then
			CompileErr("var_id() not allowed in preprocessing")
		end if
		-- This code lifted from ROUTINE_ID:
		emit_opcode(op)
		source = Pop()
		if TRANSLATE then
		    emit_addr(num_routines-1)
		else           
		emit_addr(CurrentSub)
		    emit_addr(length(SymTab))
		end if
		emit_addr(source)
		emit_addr(current_file_no)  -- necessary at top level
		assignable = TRUE
		c = NewTempSym()
		TempInteger(c) -- result will always be an integer
		Push(c)
		emit_addr(c)
	elsif op = READ_VAR then
		if preprocess then
			CompileErr("read_var() not allowed in preprocessing")
		end if
		emit_opcode(op)
		emit_addr( Pop() )
		assignable = TRUE
		c = NewTempSym()
		Push(c)
		emit_addr(c)
	elsif op = WRITE_VAR then
		if preprocess then
			CompileErr("write_var() not allowed in preprocessing")
		end if
		emit_opcode(op)
		b = Pop()
		emit_addr(Pop())
		emit_addr(b)
		assignable = FALSE		
	elsif op = DUMP_VARS then
		if preprocess then
			CompileErr("dump_vars() not allowed in preprocessing")
		end if
		emit_opcode(op)
		a = NewTempSym() -- allocate *after* checking opnd types
	    Push(a)
	    emit_addr(a)
	    assignable = TRUE	
	elsif op = EVAL then
		if preprocess then
			CompileErr("eval() not allowed in preprocessing")
		end if
		file_eval[current_file_no] = 1
		eval_used = 1
		cont11ii(op, FALSE)   
	elsif op = EVAL_ERROR then
		if preprocess then
			CompileErr("eval_error() not allowed in preprocessing")
		end if
		file_eval[current_file_no] = 1
		eval_used = 1
		emit_opcode(op)
		a = NewTempSym() -- allocate *after* checking opnd types

	    Push(a)
	    emit_addr(a)
	    
--		emit_addr(Pop())
	elsif op = GOTO then
		goto_back_patch[$] &= length(Code) + 1
		emit_opcode(GOTO)
		emit( Pop() )
		emit( Pop() )
		emit( OpStrictGoto )

	elsif op = GOTO_STATIC then
		emit_opcode( GOTO_STATIC )
		emit( Pop() )
		emit( Pop() )
		emit( NOP1 )
		
	elsif op = DEFAULT_GOTO then
		if preprocess then
			CompileErr("default_goto() not allowed in preprocessing" )
		end if
		emit_opcode( op )
		emit( current_file_no )
		emit( Pop() )
		
	elsif op = IS_GOTO then
		if preprocess then
			CompileErr("is_goto() not allowed in preprocessing" )
		end if
		emit_opcode( op )
		emit_opcode( current_file_no )
		emit_opcode( Pop() )
		a = NewTempSym()
		Push(a)
		emit_addr(a)
		assignable = TRUE
	
	elsif find( op, {FIND_FROM,MATCH_FROM}) then
		if preprocess then
			CompileErr("*_from() not allowed in preprocessing" )
		end if
		emit_opcode( op )
		a = Pop()
		b = Pop()
		c = Pop()
		emit_addr( c )
		emit_addr( b )
		emit_addr( a )
		a = NewTempSym()
		TempInteger(a)
		Push(a)
		emit_addr(a)
		assignable = FALSE
		
	-- end mwl
    else

	InternalErr(sprintf("unknown opcode: %d", op))

    end if
    
    previous_op = op
end procedure

global procedure emit_assign_op(integer op)
-- emit the appropriate assignment operator 
    if op = PLUS_EQUALS then
	emit_op(PLUS)
    elsif op = MINUS_EQUALS then
	emit_op(MINUS)
    elsif op = MULTIPLY_EQUALS then 
	emit_op(MULTIPLY)
    elsif op = DIVIDE_EQUALS then 
	emit_op(DIVIDE)
    elsif op = CONCAT_EQUALS then
	emit_op(CONCAT)
    end if
end procedure

global procedure StartSourceLine(integer sl)
-- record code offset at start of new source statement, 
-- optionally emit start of line op 
-- sl is true if we want a STARTLINE emitted as well 
    integer line_span

    if gline_number = LastLineNumber then
	if length(LineTable) then
	-- begin mwl
	-- This allows tracing of code on same line as then/else
	if sl = TRUE and not match( {STARTLINE, gline_number}, Code ) then
		emit_op( STARTLINE )
		emit_addr( gline_number )
	end if
	-- end mwl
	    return -- ignore duplicates 
	else
	    sl = FALSE -- top-level new statement to execute on same line
	end if
    end if
    LastLineNumber = gline_number

    -- add new line table entry 
    line_span = gline_number - SymTab[CurrentSub][S_FIRSTLINE]
    while length(LineTable) < line_span do
	LineTable = append(LineTable, -1) -- filler
    end while
    LineTable = append(LineTable, length(Code))
    
    if sl and (TRANSLATE or (OpTrace or OpProfileStatement)) then
	-- control point for tracing and profiling 
	emit_op(STARTLINE)
	emit_addr(gline_number)
    end if
end procedure
