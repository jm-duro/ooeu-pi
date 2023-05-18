// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16Return_statement()
{
    int _tok = 0;
    int _4517 = 0;
    int _0, _1, _2;
    

    //     if CurrentSub = TopLevelSub then
    if (_7CurrentSub != _7TopLevelSub)
        goto L1;

    // 	CompileErr("return must be inside a procedure or function")
    RefDS(_4518);
    _9CompileErr(_4518);

    // 	return
    return 0;
L1:

    //     if not TRANSLATE then    

    // 	if OpTrace then
    if (_7OpTrace == 0)
        goto L2;

    // 	    emit_op(ERASE_PRIVATE_NAMES)
    _15emit_op(88);

    // 	    emit_addr(CurrentSub)
    _15emit_addr(_7CurrentSub);
L2:
L3:

    //     if SymTab[CurrentSub][S_TOKEN] != r:PROC then
    DeRef(_4517);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4517 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4517);
    _0 = _4517;
    _2 = (int)SEQ_PTR(_4517);
    _4517 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4517);
    DeRef(_0);
    if (binary_op_a(EQUALS, _4517, 27))
        goto L4;

    // 	Expr()
    _16Expr();

    // 	FuncReturn = TRUE
    _16FuncReturn = 1;

    // 	emit_op(RETURNF)
    _15emit_op(28);
    goto L5;
L4:

    // 	emit_op(RETURNP)
    _15emit_op(29);
L5:

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    //     NotReached(tok[T_ID], "return")
    DeRef(_4517);
    _2 = (int)SEQ_PTR(_tok);
    _4517 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4517);
    Ref(_4517);
    RefDS(_808);
    _16NotReached(_4517, _808);

    // end procedure
    DeRefDS(_tok);
    DeRef(_4517);
    return 0;
    ;
}


int _16Exit_statement()
{
    int _tok = 0;
    int _4525 = 0;
    int _0, _1, _2;
    

    //     if loop_nest = 0 then
    if (_16loop_nest != 0)
        goto L1;

    // 	CompileErr("exit statement must be inside a loop")
    RefDS(_4526);
    _9CompileErr(_4526);

    // 	return
    return 0;
L1:

    //     emit_op(EXIT)
    _15emit_op(61);

    //     AppendXList(length(Code)+1)
    DeRef(_4525);
    _4525 = SEQ_PTR(_7Code)->length;
    _4525 = _4525 + 1;
    _16AppendXList(_4525);

    //     emit_forward_addr()     -- to be back-patched 
    _16emit_forward_addr();

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    //     NotReached(tok[T_ID], "exit")
    _2 = (int)SEQ_PTR(_tok);
    _4525 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4525);
    Ref(_4525);
    RefDS(_826);
    _16NotReached(_4525, _826);

    // end procedure
    DeRefDS(_tok);
    DeRef(_4525);
    return 0;
    ;
}


int _16If_statement()
{
    int _tok = 0;
    int _prev_false;
    int _prev_false2;
    int _elist_base;
    int _4531 = 0;
    int _0, _1, _2;
    

    //     elist_base = length(elist)
    _elist_base = SEQ_PTR(_16elist)->length;

    //     short_circuit += 1
    _16short_circuit = _16short_circuit + 1;

    //     short_circuit_B = FALSE
    _16short_circuit_B = 0;

    //     SC1_type = 0
    _16SC1_type = 0;

    //     Expr()
    _16Expr();

    //     emit_op(IF)
    _15emit_op(20);

    //     prev_false = length(Code)+1
    _4531 = SEQ_PTR(_7Code)->length;
    _prev_false = _4531 + 1;

    //     prev_false2 = 0
    _prev_false2 = 0;

    //     emit_forward_addr() -- to be patched 
    _16emit_forward_addr();

    //     if SC1_type = OR then
    if (_16SC1_type != 9)
        goto L1;

    // 		backpatch(SC1_patch-3, SC1_OR_IF)
    _4531 = _16SC1_patch - 3;
    _15backpatch(_4531, 149);

    // 		if TRANSLATE then

    // 		backpatch(SC1_patch, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_16SC1_patch, _4531);
    goto L2;
L1:

    //     elsif SC1_type = AND then
    if (_16SC1_type != 8)
        goto L3;

    // 		backpatch(SC1_patch-3, SC1_AND_IF)
    DeRef(_4531);
    _4531 = _16SC1_patch - 3;
    _15backpatch(_4531, 148);

    // 		prev_false2 = SC1_patch
    _prev_false2 = _16SC1_patch;
L3:
L2:

    //     short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    //     tok_match(THEN)
    _16tok_match(409);

    //     call_proc(forward_Statement_list, {})
    _0 = (int)_00[_16forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     while tok[T_ID] = ELSIF do
L4:
    DeRef(_4531);
    _2 = (int)SEQ_PTR(_tok);
    _4531 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4531);
    if (binary_op_a(NOTEQ, _4531, 413))
        goto L5;

    // 		emit_op(ELSE)
    _15emit_op(23);

    // 		AppendEList(length(Code)+1)
    DeRef(_4531);
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _16AppendEList(_4531);

    // 		emit_forward_addr()  -- to be patched 
    _16emit_forward_addr();

    // 		if TRANSLATE then

    // 		backpatch(prev_false, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_prev_false, _4531);

    // 		if prev_false2 != 0 then
    if (_prev_false2 == 0)
        goto L6;

    // 		    backpatch(prev_false2, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_prev_false2, _4531);
L6:

    // 		StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 		short_circuit += 1
    _16short_circuit = _16short_circuit + 1;

    // 		short_circuit_B = FALSE
    _16short_circuit_B = 0;

    // 		SC1_type = 0
    _16SC1_type = 0;

    // 		Expr()
    _16Expr();

    // 		emit_op(IF)
    _15emit_op(20);

    // 		prev_false = length(Code)+1
    DeRef(_4531);
    _4531 = SEQ_PTR(_7Code)->length;
    _prev_false = _4531 + 1;

    // 		prev_false2 = 0
    _prev_false2 = 0;

    // 		emit_forward_addr() -- to be patched 
    _16emit_forward_addr();

    // 		if SC1_type = OR then
    if (_16SC1_type != 9)
        goto L7;

    // 		    backpatch(SC1_patch-3, SC1_OR_IF)
    _4531 = _16SC1_patch - 3;
    _15backpatch(_4531, 149);

    // 		    if TRANSLATE then

    // 		    backpatch(SC1_patch, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_16SC1_patch, _4531);
    goto L8;
L7:

    // 		elsif SC1_type = AND then
    if (_16SC1_type != 8)
        goto L9;

    // 		    backpatch(SC1_patch-3, SC1_AND_IF)
    DeRef(_4531);
    _4531 = _16SC1_patch - 3;
    _15backpatch(_4531, 148);

    // 		    prev_false2 = SC1_patch
    _prev_false2 = _16SC1_patch;
L9:
L8:

    // 		short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    // 		tok_match(THEN)
    _16tok_match(409);

    // 		call_proc(forward_Statement_list, {})
    _0 = (int)_00[_16forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     end while
    goto L4;
L5:

    //     if tok[T_ID] = ELSE then 
    DeRef(_4531);
    _2 = (int)SEQ_PTR(_tok);
    _4531 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4531);
    if (binary_op_a(NOTEQ, _4531, 23))
        goto LA;

    // 		StartSourceLine(FALSE)
    _15StartSourceLine(0);

    // 		emit_op(ELSE)
    _15emit_op(23);

    // 		AppendEList(length(Code)+1)
    DeRef(_4531);
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _16AppendEList(_4531);

    // 		emit_forward_addr() -- to be patched 
    _16emit_forward_addr();

    // 		if TRANSLATE then

    // 		backpatch(prev_false, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_prev_false, _4531);

    // 		if prev_false2 != 0 then
    if (_prev_false2 == 0)
        goto LB;

    // 		    backpatch(prev_false2, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_prev_false2, _4531);
LB:

    // 		call_proc(forward_Statement_list, {})
    _0 = (int)_00[_16forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );
    goto LC;
LA:

    // 		putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		if TRANSLATE then

    // 		backpatch(prev_false, length(Code)+1)
    DeRef(_4531);
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_prev_false, _4531);

    // 		if prev_false2 != 0 then
    if (_prev_false2 == 0)
        goto LD;

    // 		    backpatch(prev_false2, length(Code)+1)
    _4531 = SEQ_PTR(_7Code)->length;
    _4531 = _4531 + 1;
    _15backpatch(_prev_false2, _4531);
LD:
LC:

    //     tok_match(END) 
    _16tok_match(402);

    //     tok_match(IF)
    _16tok_match(20);

    //     if TRANSLATE then

    //     PatchEList(elist_base)
    _16PatchEList(_elist_base);

    // end procedure
    DeRef(_tok);
    DeRef(_4531);
    return 0;
    ;
}


int _16While_statement()
{
    int _bp1;
    int _bp2;
    int _exit_base;
    int _4579 = 0;
    int _0, _1, _2;
    

    //     if TRANSLATE then

    //     bp1 = length(Code)+1
    _4579 = SEQ_PTR(_7Code)->length;
    _bp1 = _4579 + 1;

    //     short_circuit += 1
    _16short_circuit = _16short_circuit + 1;

    //     short_circuit_B = FALSE
    _16short_circuit_B = 0;

    //     SC1_type = 0
    _16SC1_type = 0;

    //     Expr()
    _16Expr();

    //     tok_match(DO)
    _16tok_match(410);

    //     optimized_while = FALSE
    _15optimized_while = 0;

    //     emit_op(WHILE)
    _15emit_op(47);

    //     short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    //     if not optimized_while then
    if (_15optimized_while != 0)
        goto L1;

    // 		bp2 = length(Code)+1
    _4579 = SEQ_PTR(_7Code)->length;
    _bp2 = _4579 + 1;

    // 		emit_forward_addr() -- will be patched 
    _16emit_forward_addr();
    goto L2;
L1:

    // 		bp2 = 0
    _bp2 = 0;
L2:

    //     loop_nest += 1
    _16loop_nest = _16loop_nest + 1;

    //     exit_base = length(exit_list)
    _exit_base = SEQ_PTR(_16exit_list)->length;

    //     if SC1_type = OR then
    if (_16SC1_type != 9)
        goto L3;

    // 		backpatch(SC1_patch-3, SC1_OR_IF)
    DeRef(_4579);
    _4579 = _16SC1_patch - 3;
    _15backpatch(_4579, 149);

    // 		if TRANSLATE then

    // 		backpatch(SC1_patch, length(Code)+1)
    _4579 = SEQ_PTR(_7Code)->length;
    _4579 = _4579 + 1;
    _15backpatch(_16SC1_patch, _4579);
    goto L4;
L3:

    //     elsif SC1_type = AND then
    if (_16SC1_type != 8)
        goto L5;

    // 		backpatch(SC1_patch-3, SC1_AND_IF)
    DeRef(_4579);
    _4579 = _16SC1_patch - 3;
    _15backpatch(_4579, 148);

    // 		AppendXList(SC1_patch)
    _16AppendXList(_16SC1_patch);
L5:
L4:

    //     loop_stack &= WHILE
    Append(&_7loop_stack, _7loop_stack, 47);

    //     loop_sym_stack &= 0
    Append(&_7loop_sym_stack, _7loop_sym_stack, 0);

    //     loop_bp_stack &= {{bp1, bp2}}
    DeRef(_4579);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _bp1;
    ((int *)_2)[2] = _bp2;
    _4579 = MAKE_SEQ(_1);
    _0 = _4579;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_4579);
    *((int *)(_2+4)) = _4579;
    _4579 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Concat((object_ptr)&_7loop_bp_stack, _7loop_bp_stack, (s1_ptr)_4579);

    //     call_proc(forward_Statement_list, {})
    _0 = (int)_00[_16forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    //     tok_match(END)
    _16tok_match(402);

    //     tok_match(WHILE)
    _16tok_match(47);

    //     StartSourceLine(TRUE)
    _15StartSourceLine(1);

    //     emit_op(ENDWHILE)
    _15emit_op(22);

    //     loop_nest -= 1
    _16loop_nest = _16loop_nest - 1;

    //     emit_addr(bp1)
    _15emit_addr(_bp1);

    //     if TRANSLATE then

    //     if bp2 != 0 then
    if (_bp2 == 0)
        goto L6;

    // 		backpatch(bp2, length(Code)+1)
    DeRefDS(_4579);
    _4579 = SEQ_PTR(_7Code)->length;
    _4579 = _4579 + 1;
    _15backpatch(_bp2, _4579);
L6:

    //     PatchXList(exit_base)
    _16PatchXList(_exit_base);

    //     loop_stack = loop_stack[1..$-1]
    DeRef(_4579);
    _4579 = SEQ_PTR(_7loop_stack)->length;
    _4579 = _4579 - 1;
    rhs_slice_target = (object_ptr)&_7loop_stack;
    RHS_Slice((s1_ptr)_7loop_stack, 1, _4579);

    //     loop_sym_stack = loop_sym_stack[1..$-1]
    _4579 = SEQ_PTR(_7loop_sym_stack)->length;
    _4579 = _4579 - 1;
    rhs_slice_target = (object_ptr)&_7loop_sym_stack;
    RHS_Slice((s1_ptr)_7loop_sym_stack, 1, _4579);

    //     loop_bp_stack = loop_bp_stack[1..$-1]
    _4579 = SEQ_PTR(_7loop_bp_stack)->length;
    _4579 = _4579 - 1;
    rhs_slice_target = (object_ptr)&_7loop_bp_stack;
    RHS_Slice((s1_ptr)_7loop_bp_stack, 1, _4579);

    // end procedure
    return 0;
    ;
}


int _16SetPrivateScope(int _s, int _type_sym, int _n)
{
    int _hashval;
    int _scope;
    int _t;
    int _4618 = 0;
    int _4612 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     scope = SymTab[s][S_SCOPE]
    _2 = (int)SEQ_PTR(_7SymTab);
    _4612 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4612);
    _2 = (int)SEQ_PTR(_4612);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    //     if find(scope, {SC_PRIVATE, SC_LOOP_VAR}) then
    DeRef(_4612);
    _4612 = find(_scope, _1416);
    if (_4612 == 0)
        goto L1;

    // 	DefinedYet(s)
    _11DefinedYet(_s);

    // 	return s
    return _s;
    goto L2;
L1:

    //     elsif find(scope, {SC_UNDEFINED, SC_MULTIPLY_DEFINED}) then
    DeRef(_4612);
    _4612 = find(_scope, _4615);
    if (_4612 == 0)
        goto L3;

    // 	SymTab[s][S_SCOPE] = SC_PRIVATE
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[s][S_VARNUM] = n
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 12);
    _1 = *(int *)_2;
    *(int *)_2 = _n;
    DeRef(_1);

    // 	SymTab[s][S_VTYPE] = type_sym
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_sym;
    DeRef(_1);

    // 	return s
    DeRef(_4618);
    return _s;
    goto L2;
L3:

    //     elsif find(scope, {SC_LOCAL, SC_GLOBAL, SC_PREDEF}) then
    DeRef(_4618);
    _4618 = find(_scope, _4623);
    if (_4618 == 0)
        goto L4;

    // 	hashval = SymTab[s][S_HASHVAL]
    _2 = (int)SEQ_PTR(_7SymTab);
    _4618 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4618);
    _2 = (int)SEQ_PTR(_4618);
    _hashval = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_hashval))
        _hashval = (long)DBL_PTR(_hashval)->dbl;

    // 	t = buckets[hashval]
    _2 = (int)SEQ_PTR(_11buckets);
    _t = (int)*(((s1_ptr)_2)->base + _hashval);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    // 	buckets[hashval] = NewEntry(SymTab[s][S_NAME], n, SC_PRIVATE, 
    DeRef(_4618);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4618 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4618);
    _0 = _4618;
    _2 = (int)SEQ_PTR(_4618);
    _4618 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4618);
    DeRef(_0);
    Ref(_4618);
    _0 = _4618;
    _4618 = _11NewEntry(_4618, _n, 3, -100, _hashval, _t, _type_sym);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _hashval);
    _1 = *(int *)_2;
    *(int *)_2 = _4618;
    DeRef(_1);

    // 	return buckets[hashval]
    _2 = (int)SEQ_PTR(_11buckets);
    _4618 = (int)*(((s1_ptr)_2)->base + _hashval);
    Ref(_4618);
    DeRef(_4612);
    return _4618;
    goto L2;
L4:

    // 	InternalErr("SetPS")
    RefDS(_4632);
    _9InternalErr(_4632);
L2:

    //     return 0
    DeRef(_4618);
    DeRef(_4612);
    return 0;
    ;
}


int _16For_statement()
{
    int _bp1;
    int _exit_base;
    int _tok = 0;
    int _loop_var = 0;
    int _loop_var_sym;
    int _def1;
    int _4659 = 0;
    int _4657 = 0;
    int _4635 = 0;
    int _4633 = 0;
    int _0, _1, _2, _3;
    

    //     loop_var = next_token()
    _loop_var = _16next_token();

    //     if not find(loop_var[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC}) then
    _2 = (int)SEQ_PTR(_loop_var);
    _4633 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4633);
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    _4635 = MAKE_SEQ(_1);
    _0 = _4635;
    _4635 = find(_4633, _4635);
    DeRefDSi(_0);
    if (_4635 != 0)
        goto L1;

    // 		CompileErr("a loop variable name is expected here")
    RefDS(_4638);
    _9CompileErr(_4638);

    // 		return
    DeRefDS(_loop_var);
    DeRef(_4633);
    return 0;
L1:

    //     add_ref(loop_var)
    RefDS(_loop_var);
    _11add_ref(_loop_var);

    //     tok_match(EQUALS)
    _16tok_match(3);

    //     Expr()
    _16Expr();

    //     tok_match(TO)
    _16tok_match(403);

    //     loop_nest += 1
    _16loop_nest = _16loop_nest + 1;

    //     exit_base = length(exit_list)    
    _exit_base = SEQ_PTR(_16exit_list)->length;

    //     Expr()
    _16Expr();

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     if tok[T_ID] = BY then
    DeRef(_4635);
    _2 = (int)SEQ_PTR(_tok);
    _4635 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4635);
    if (binary_op_a(NOTEQ, _4635, 404))
        goto L2;

    // 		Expr()
    _16Expr();

    // 		def1 = FALSE
    _def1 = 0;
    goto L3;
L2:

    // 		emit_opnd(NewIntSym(1))
    _0 = _4635;
    _4635 = _11NewIntSym(1);
    DeRef(_0);
    _15emit_opnd(_4635);

    // 		putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		def1 = TRUE
    _def1 = 1;
L3:

    //     loop_var_sym = loop_var[T_SYM]
    _2 = (int)SEQ_PTR(_loop_var);
    _loop_var_sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_loop_var_sym))
        _loop_var_sym = (long)DBL_PTR(_loop_var_sym)->dbl;

    //     if CurrentSub = TopLevelSub then
    if (_7CurrentSub != _7TopLevelSub)
        goto L4;

    // 		DefinedYet(loop_var_sym)
    _11DefinedYet(_loop_var_sym);

    // 		SymTab[loop_var_sym][S_SCOPE] = SC_GLOOP_VAR
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 4;
    DeRef(_1);

    // 		SymTab[loop_var_sym][S_VTYPE] = object_type
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _11object_type;
    DeRef(_1);
    goto L5;
L4:

    // 		loop_var_sym = SetPrivateScope(loop_var_sym, object_type, param_num)
    _loop_var_sym = _16SetPrivateScope(_loop_var_sym, _11object_type, _16param_num);
    if (!IS_ATOM_INT(_loop_var_sym)) {
        _1 = (long)(DBL_PTR(_loop_var_sym)->dbl);
        DeRefDS(_loop_var_sym);
        _loop_var_sym = _1;
    }

    // 		param_num += 1
    _16param_num = _16param_num + 1;

    // 		SymTab[loop_var_sym][S_SCOPE] = SC_LOOP_VAR
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);
L5:

    //     SymTab[loop_var_sym][S_USAGE] = or_bits(SymTab[loop_var_sym][S_USAGE], 
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    DeRef(_4657);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4657 = (int)*(((s1_ptr)_2)->base + _loop_var_sym);
    Ref(_4657);
    _0 = _4657;
    _2 = (int)SEQ_PTR(_4657);
    _4657 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4657);
    DeRef(_0);
    DeRef(_4659);
    _4659 = (1 | 2);
    if (IS_ATOM_INT(_4657)) {
        _4659 = (_4657 | _4659);
    }
    else {
        _4659 = binary_op(OR_BITS, _4657, _4659);
    }
    Ref(_4659);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _4659;
    DeRef(_1);

    //     op_info1 = loop_var_sym
    _15op_info1 = _loop_var_sym;

    //     emit_op(FOR)
    _15emit_op(21);

    //     emit_addr(loop_var_sym)
    _15emit_addr(_loop_var_sym);

    //     tok_match(DO)
    _16tok_match(410);

    //     bp1 = length(Code)+1
    DeRef(_4659);
    _4659 = SEQ_PTR(_7Code)->length;
    _bp1 = _4659 + 1;

    //     emit_addr(0) -- will be patched - don't straighten 
    _15emit_addr(0);

    //     loop_stack &= FOR
    Append(&_7loop_stack, _7loop_stack, 21);

    //     loop_sym_stack &= loop_var_sym
    Append(&_7loop_sym_stack, _7loop_sym_stack, _loop_var_sym);

    //     loop_bp_stack &= bp1
    Append(&_7loop_bp_stack, _7loop_bp_stack, _bp1);

    //     if not TRANSLATE then

    // 	if OpTrace then
    if (_7OpTrace == 0)
        goto L6;

    // 	    emit_op(DISPLAY_VAR)
    _15emit_op(87);

    // 	    emit_addr(loop_var_sym)
    _15emit_addr(_loop_var_sym);
L6:
L7:

    //     call_proc(forward_Statement_list, {})
    _0 = (int)_00[_16forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    //     tok_match(END)
    _16tok_match(402);

    //     tok_match(FOR)
    _16tok_match(21);

    //     StartSourceLine(TRUE)
    _15StartSourceLine(1);

    //     op_info1 = loop_var_sym
    _15op_info1 = _loop_var_sym;

    //     op_info2 = bp1 + 1
    _15op_info2 = _bp1 + 1;

    //     if def1 then
    if (_def1 == 0)
        goto L8;

    // 		emit_op(ENDFOR_INT_UP1) -- (loop var might not be integer)
    _15emit_op(54);
    goto L9;
L8:

    // 		emit_op(ENDFOR_GENERAL) -- will be set at runtime by FOR op 
    _15emit_op(39);
L9:

    //     backpatch(bp1, length(Code)+1)
    DeRef(_4659);
    _4659 = SEQ_PTR(_7Code)->length;
    _4659 = _4659 + 1;
    _15backpatch(_bp1, _4659);

    //     PatchXList(exit_base)
    _16PatchXList(_exit_base);

    //     loop_nest -= 1
    _16loop_nest = _16loop_nest - 1;

    //     if not TRANSLATE then

    // 	if OpTrace then
    if (_7OpTrace == 0)
        goto LA;

    // 	    emit_op(ERASE_SYMBOL)
    _15emit_op(90);

    // 	    emit_addr(loop_var_sym)
    _15emit_addr(_loop_var_sym);
LA:
LB:

    //     Hide(loop_var_sym)
    _11Hide(_loop_var_sym);

    //     loop_stack = loop_stack[1..$-1]
    DeRef(_4659);
    _4659 = SEQ_PTR(_7loop_stack)->length;
    _4659 = _4659 - 1;
    rhs_slice_target = (object_ptr)&_7loop_stack;
    RHS_Slice((s1_ptr)_7loop_stack, 1, _4659);

    //     loop_sym_stack = loop_sym_stack[1..$-1]
    _4659 = SEQ_PTR(_7loop_sym_stack)->length;
    _4659 = _4659 - 1;
    rhs_slice_target = (object_ptr)&_7loop_sym_stack;
    RHS_Slice((s1_ptr)_7loop_sym_stack, 1, _4659);

    //     loop_bp_stack = loop_bp_stack[1..$-1]
    _4659 = SEQ_PTR(_7loop_bp_stack)->length;
    _4659 = _4659 - 1;
    rhs_slice_target = (object_ptr)&_7loop_bp_stack;
    RHS_Slice((s1_ptr)_7loop_bp_stack, 1, _4659);

    // end procedure
    DeRef(_tok);
    DeRef(_loop_var);
    DeRef(_4657);
    DeRef(_4635);
    DeRef(_4633);
    return 0;
    ;
}


int _16Goto_Label()
{
    int _tok = 0;
    int _ix;
    int _id;
    int _label = 0;
    int _4714 = 0;
    int _4686 = 0;
    int _4687 = 0;
    int _4682 = 0;
    int _0, _1, _2, _3;
    

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 		CompileErr("goto not allowed in preprocessing")
    RefDS(_4681);
    _9CompileErr(_4681);
L1:

    // 	Expr()
    _16Expr();

    // 	if atom(SymTab[CurrentSub][S_GOTO]) then
    DeRef(_4682);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4682 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4682);
    _0 = _4682;
    _2 = (int)SEQ_PTR(_4682);
    _4682 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4682);
    DeRef(_0);
    _0 = _4682;
    _4682 = IS_ATOM(_4682);
    DeRef(_0);
    if (_4682 == 0)
        goto L2;

    // 		SymTab[CurrentSub][S_GOTO] = { {}, {}, {{},{}}}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    DeRef(_4687);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _39;
    RefDS(_39);
    ((int *)_2)[2] = _39;
    RefDS(_39);
    _4687 = MAKE_SEQ(_1);
    _0 = _4687;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDSn(_39, 2);
    *((int *)(_2+4)) = _39;
    *((int *)(_2+8)) = _39;
    RefDS(_4687);
    *((int *)(_2+12)) = _4687;
    _4687 = MAKE_SEQ(_1);
    DeRefDS(_0);
    RefDS(_4687);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _4687;
    DeRef(_1);
L2:

    // 		ix = Pop()
    _ix = _15Pop();

    // 		if compare(SymTab[ix][S_OBJ], NOVALUE) then
    DeRef(_4687);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4687 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_4687);
    _0 = _4687;
    _2 = (int)SEQ_PTR(_4687);
    _4687 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4687);
    DeRef(_0);
    _0 = _4687;
    if (IS_ATOM_INT(_4687) && IS_ATOM_INT(_7NOVALUE))
        _4687 = (_4687 < _7NOVALUE) ? -1 : (_4687 > _7NOVALUE);
    else
        _4687 = compare(_4687, _7NOVALUE);
    DeRef(_0);
    if (_4687 == 0)
        goto L3;

    // 			label = { current_file_no, SymTab[ix][S_OBJ] }
    _2 = (int)SEQ_PTR(_7SymTab);
    _4687 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_4687);
    _0 = _4687;
    _2 = (int)SEQ_PTR(_4687);
    _4687 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4687);
    DeRef(_0);
    DeRef(_label);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7current_file_no;
    ((int *)_2)[2] = _4687;
    Ref(_4687);
    _label = MAKE_SEQ(_1);
    goto L4;
L3:

    // 			SymTab[ix][S_SCOPE] = IN_USE 
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_ix + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 			label = { current_file_no, NOVALUE, ix } 		
    _0 = _label;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _7current_file_no;
    RefDS(_7NOVALUE);
    *((int *)(_2+8)) = _7NOVALUE;
    *((int *)(_2+12)) = _ix;
    _label = MAKE_SEQ(_1);
    DeRef(_0);
L4:

    // 	if find( label, SymTab[CurrentSub][S_GOTO][G_LABEL] ) then
    DeRef(_4686);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4686 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4686);
    _0 = _4686;
    _2 = (int)SEQ_PTR(_4686);
    _4686 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4686);
    DeRef(_0);
    _0 = _4686;
    _2 = (int)SEQ_PTR(_4686);
    _4686 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4686);
    DeRef(_0);
    _0 = _4686;
    _4686 = find(_label, _4686);
    DeRef(_0);
    if (_4686 == 0)
        goto L5;

    // 		CompileErr( "Duplicate goto label" )
    RefDS(_4703);
    _9CompileErr(_4703);

    // 		return
    DeRef(_tok);
    DeRefDS(_label);
    DeRef(_4714);
    DeRef(_4687);
    DeRef(_4682);
    return 0;
    goto L6;
L5:

    // 		SymTab[CurrentSub][S_GOTO][G_LABEL] = append( SymTab[CurrentSub][S_GOTO][G_LABEL], label )
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(object_ptr)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(object_ptr)_3 = MAKE_SEQ(_2);
    }
    _3 = (int)(24 + ((s1_ptr)_2)->base);
    DeRef(_4682);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4682 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4682);
    _0 = _4682;
    _2 = (int)SEQ_PTR(_4682);
    _4682 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4682);
    DeRef(_0);
    _0 = _4682;
    _2 = (int)SEQ_PTR(_4682);
    _4682 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4682);
    DeRef(_0);
    RefDS(_label);
    Append(&_4682, _4682, _label);
    RefDS(_4682);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4682;
    DeRef(_1);

    // 		SymTab[CurrentSub][S_GOTO][G_PC] &= length(Code) + 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(object_ptr)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(object_ptr)_3 = MAKE_SEQ(_2);
    }
    _3 = (int)(24 + ((s1_ptr)_2)->base);
    DeRef(_4686);
    _4686 = SEQ_PTR(_7Code)->length;
    _4686 = _4686 + 1;
    DeRef(_4714);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _4714 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4714);
    if (IS_SEQUENCE(_4714) && IS_ATOM(_4686)) {
        Append(&_4714, _4714, _4686);
    }
    else if (IS_ATOM(_4714) && IS_SEQUENCE(_4686)) {
    }
    else {
        Concat((object_ptr)&_4714, _4714, (s1_ptr)_4686);
    }
    RefDS(_4714);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _4714;
    DeRef(_1);
L6:

    // end procedure
    DeRef(_tok);
    DeRef(_label);
    DeRef(_4714);
    DeRef(_4686);
    DeRef(_4687);
    DeRef(_4682);
    return 0;
    ;
}


int _16Goto_Statement()
{
    int _addr;
    int _ix;
    int _file;
    int _4723 = 0;
    int _4716 = 0;
    int _0, _1, _2;
    

    // 	StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	emit_opnd( current_file_no )
    _15emit_opnd(_7current_file_no);

    // 	Expr()
    _16Expr();

    // 	addr = Pop()
    _addr = _15Pop();

    // 	if sequence( SymTab[CurrentSub][S_GOTO] ) then
    _2 = (int)SEQ_PTR(_7SymTab);
    _4716 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4716);
    _0 = _4716;
    _2 = (int)SEQ_PTR(_4716);
    _4716 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4716);
    DeRef(_0);
    _0 = _4716;
    _4716 = IS_SEQUENCE(_4716);
    DeRef(_0);
    if (_4716 == 0)
        goto L1;

    // 		ix = find( {current_file_no, SymTab[addr][S_OBJ]}, SymTab[CurrentSub][S_GOTO][G_LABEL] )
    _2 = (int)SEQ_PTR(_7SymTab);
    _4716 = (int)*(((s1_ptr)_2)->base + _addr);
    Ref(_4716);
    _0 = _4716;
    _2 = (int)SEQ_PTR(_4716);
    _4716 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4716);
    DeRef(_0);
    _0 = _4716;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7current_file_no;
    ((int *)_2)[2] = _4716;
    Ref(_4716);
    _4716 = MAKE_SEQ(_1);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4723 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4723);
    _0 = _4723;
    _2 = (int)SEQ_PTR(_4723);
    _4723 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4723);
    DeRef(_0);
    _0 = _4723;
    _2 = (int)SEQ_PTR(_4723);
    _4723 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4723);
    DeRef(_0);
    _ix = find(_4716, _4723);

    // 		if ix then
    if (_ix == 0)
        goto L2;

    // 			file = Pop()
    _file = _15Pop();

    // 			emit_opnd( CurrentSub )
    _15emit_opnd(_7CurrentSub);

    // 			emit_opnd( SymTab[CurrentSub][S_GOTO][G_PC][ix] )
    DeRef(_4723);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4723 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4723);
    _0 = _4723;
    _2 = (int)SEQ_PTR(_4723);
    _4723 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4723);
    DeRef(_0);
    _0 = _4723;
    _2 = (int)SEQ_PTR(_4723);
    _4723 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4723);
    DeRef(_0);
    _0 = _4723;
    _2 = (int)SEQ_PTR(_4723);
    _4723 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_4723);
    DeRef(_0);
    Ref(_4723);
    _15emit_opnd(_4723);

    // 			emit_op( GOTO_STATIC )
    _15emit_op(176);

    // 			return		
    DeRefDS(_4716);
    DeRef(_4723);
    return 0;
L2:
L1:

    // 	Push(addr)
    _15Push(_addr);

    // 	emit_op( GOTO )		
    _15emit_op(175);

    // end procedure
    DeRef(_4723);
    DeRef(_4716);
    return 0;
    ;
}


int _16Continue_statement()
{
    int _tok = 0;
    int _bp1;
    int _bp2;
    int _s = 0;
    int _4746 = 0;
    int _4733 = 0;
    int _0, _1, _2;
    

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 		CompileErr("continue not allowed in preprocessing")
    RefDS(_4732);
    _9CompileErr(_4732);
L1:

    // 	if not loop_stack[$] then
    DeRef(_4733);
    _4733 = SEQ_PTR(_7loop_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_stack);
    _4733 = (int)*(((s1_ptr)_2)->base + _4733);
    if (_4733 != 0)
        goto L2;

    // 		CompileErr( "continue must be inside of loop" )
    RefDS(_4736);
    _9CompileErr(_4736);
    goto L3;
L2:

    // 	elsif loop_stack[$] = FOR then
    DeRef(_4733);
    _4733 = SEQ_PTR(_7loop_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_stack);
    _4733 = (int)*(((s1_ptr)_2)->base + _4733);
    if (_4733 != 21)
        goto L4;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    op_info1 = loop_sym_stack[$]
    _4733 = SEQ_PTR(_7loop_sym_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_sym_stack);
    _15op_info1 = (int)*(((s1_ptr)_2)->base + _4733);

    // 	    op_info2 = loop_bp_stack[$] + 1
    _4733 = SEQ_PTR(_7loop_bp_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_bp_stack);
    _4733 = (int)*(((s1_ptr)_2)->base + _4733);
    Ref(_4733);
    if (IS_ATOM_INT(_4733)) {
        _15op_info2 = _4733 + 1;
    }
    else
        _15op_info2 = 1+(long)(DBL_PTR(_4733)->dbl);

    // 		s = Pop() & Pop()
    _0 = _4733;
    _4733 = _15Pop();
    DeRef(_0);
    _0 = _4746;
    _4746 = _15Pop();
    DeRef(_0);
    Concat((object_ptr)&_s, _4733, (s1_ptr)_4746);

    // 		Push( s[2] )
    _2 = (int)SEQ_PTR(_s);
    _4746 = (int)*(((s1_ptr)_2)->base + 2);
    _15Push(_4746);

    // 		Push( s[1] )
    _2 = (int)SEQ_PTR(_s);
    _4746 = (int)*(((s1_ptr)_2)->base + 1);
    _15Push(_4746);

    // 	    emit_op(ENDFOR_GENERAL) -- will be set at runtime by FOR op
    _15emit_op(39);

    // 		Push( s[2] )
    _2 = (int)SEQ_PTR(_s);
    _4746 = (int)*(((s1_ptr)_2)->base + 2);
    _15Push(_4746);

    // 		Push( s[1] )
    _2 = (int)SEQ_PTR(_s);
    _4746 = (int)*(((s1_ptr)_2)->base + 1);
    _15Push(_4746);

    // 	    emit_op(EXIT)
    _15emit_op(61);

    // 	    AppendXList(length(Code)+1)
    _4746 = SEQ_PTR(_7Code)->length;
    _4746 = _4746 + 1;
    _16AppendXList(_4746);

    // 	    emit_forward_addr()     -- to be back-patched 
    _16emit_forward_addr();

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 	    putback(tok)
    RefDS(_tok);
    _16putback(_tok);
    goto L3;
L4:

    // 	elsif loop_stack[$] = WHILE then
    DeRef(_4746);
    _4746 = SEQ_PTR(_7loop_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_stack);
    _4746 = (int)*(((s1_ptr)_2)->base + _4746);
    if (_4746 != 47)
        goto L5;

    // 		bp1 = loop_bp_stack[$][1]
    _4746 = SEQ_PTR(_7loop_bp_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_bp_stack);
    _4746 = (int)*(((s1_ptr)_2)->base + _4746);
    Ref(_4746);
    _2 = (int)SEQ_PTR(_4746);
    _bp1 = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_bp1))
        _bp1 = (long)DBL_PTR(_bp1)->dbl;

    // 		bp2 = loop_bp_stack[$][1]
    DeRef(_4746);
    _4746 = SEQ_PTR(_7loop_bp_stack)->length;
    _2 = (int)SEQ_PTR(_7loop_bp_stack);
    _4746 = (int)*(((s1_ptr)_2)->base + _4746);
    Ref(_4746);
    _2 = (int)SEQ_PTR(_4746);
    _bp2 = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_bp2))
        _bp2 = (long)DBL_PTR(_bp2)->dbl;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    emit_op(ENDWHILE)
    _15emit_op(22);

    // 	    emit_addr(bp1)
    _15emit_addr(_bp1);
L5:
L3:

    // end procedure
    DeRef(_tok);
    DeRefi(_s);
    DeRef(_4746);
    DeRef(_4733);
    return 0;
    ;
}


int _16Global_declaration(int _type_ptr, int _is_global)
{
    int _tok = 0;
    int _sym;
    int _h;
    int _class;
    int _4790 = 0;
    int _4764 = 0;
    int _4773 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_type_ptr)) {
        _1 = (long)(DBL_PTR(_type_ptr)->dbl);
        DeRefDS(_type_ptr);
        _type_ptr = _1;
    }

    // 	if type_ptr = sequence_type then
    if (_type_ptr != _11sequence_type)
        goto L1;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L2;

    // 			cache_line()
    _16cache_line();
L2:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] != OF then
    DeRef(_4764);
    _2 = (int)SEQ_PTR(_tok);
    _4764 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4764);
    if (binary_op_a(EQUALS, _4764, 424))
        goto L3;

    // 			putback(tok)
    RefDS(_tok);
    _16putback(_tok);
    goto L4;
L3:

    // 			if find(type_ptr, {atom_type, integer_type}) then
    DeRef(_4764);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _11atom_type;
    ((int *)_2)[2] = _11integer_type;
    _4764 = MAKE_SEQ(_1);
    _0 = _4764;
    _4764 = find(_type_ptr, _4764);
    DeRefDSi(_0);
    if (_4764 == 0)
        goto L5;

    // 				CompileErr("illegal use of 'of'")
    RefDS(_4770);
    _9CompileErr(_4770);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L6;

    // 					release_line()
    _16release_line();
L6:

    // 				return
    DeRef(_tok);
    DeRef(_4790);
    DeRef(_4764);
    DeRef(_4773);
    return 0;
L5:

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 			class = find( tok[T_SYM], class_table[CLASS_SYM] )
    DeRef(_4764);
    _2 = (int)SEQ_PTR(_tok);
    _4764 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4764);
    DeRef(_4773);
    _2 = (int)SEQ_PTR(_7class_table);
    _4773 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4773);
    _class = find(_4764, _4773);

    // 			if not class then
    if (_class != 0)
        goto L7;

    // 				CompileErr("of must be followed by a euclass name")
    RefDS(_4776);
    _9CompileErr(_4776);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L8;

    // 					release_line()
    _16release_line();
L8:

    // 				return
    DeRef(_tok);
    DeRef(_4790);
    DeRef(_4764);
    DeRef(_4773);
    return 0;
L7:

    // 			class = sequence_of_class( class )
    _class = _11sequence_of_class(_class);

    // 			type_ptr = class_table[CLASS_SYM][class] 
    DeRef(_4773);
    _2 = (int)SEQ_PTR(_7class_table);
    _4773 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4773);
    _2 = (int)SEQ_PTR(_4773);
    _type_ptr = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_type_ptr))
        _type_ptr = (long)DBL_PTR(_type_ptr)->dbl;

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L4;

    // 				replace_tokens( length(line_tokens) - 2, length(line_tokens), "sequence" )
    DeRefDS(_4773);
    _4773 = SEQ_PTR(_7line_tokens)->length;
    _4773 = _4773 - 2;
    DeRef(_4764);
    _4764 = SEQ_PTR(_7line_tokens)->length;
    RefDS(_850);
    _16replace_tokens(_4773, _4764, _850);
L9:
LA:
    goto L4;
L1:

    // 	elsif preprocess then
    if (_7preprocess == 0)
        goto LB;

    // 		cache_line()
    _16cache_line();

    // 		if type_ptr and find( type_ptr, class_table[CLASS_SYM] ) then
    if (_type_ptr == 0) {
        goto LC;
    }
    DeRef(_4773);
    _2 = (int)SEQ_PTR(_7class_table);
    _4773 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4773);
    _0 = _4773;
    _4773 = find(_type_ptr, _4773);
    DeRefDS(_0);
LD:
    if (_4773 == 0)
        goto LC;

    // 			replace_tokens( length(line_tokens)-1, length(line_tokens)-1,
    DeRef(_4773);
    _4773 = SEQ_PTR(_7line_tokens)->length;
    _4773 = _4773 - 1;
    DeRef(_4764);
    _4764 = SEQ_PTR(_7line_tokens)->length;
    _4764 = _4764 - 1;
    _0 = _4790;
    _4790 = _16real_type(_type_ptr);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4790 = (int)*(((s1_ptr)_2)->base + _4790);
    Ref(_4790);
    _0 = _4790;
    _2 = (int)SEQ_PTR(_4790);
    _4790 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4790);
    DeRef(_0);
    Ref(_4790);
    _16replace_tokens(_4773, _4764, _4790);
LC:
LB:
L4:

    //     while TRUE do 
LE:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, CLASS}) then
    DeRef(_4790);
    _2 = (int)SEQ_PTR(_tok);
    _4790 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4790);
    _0 = _4764;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    *((int *)(_2+20)) = 421;
    _4764 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4764;
    _4764 = find(_4790, _4764);
    DeRefDSi(_0);
    if (_4764 != 0)
        goto LF;

    // 		    CompileErr("a name is expected here")
    RefDS(_4798);
    _9CompileErr(_4798);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L10;

    // 				release_line()
    _16release_line();
L10:

    // 		    return
    DeRef(_tok);
    DeRef(_4790);
    DeRef(_4764);
    DeRef(_4773);
    return 0;
LF:

    // 		sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 		DefinedYet(sym)
    _11DefinedYet(_sym);

    // 		if find(SymTab[sym][S_SCOPE], {SC_GLOBAL, SC_PREDEF}) then
    DeRef(_4764);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4764 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4764);
    _0 = _4764;
    _2 = (int)SEQ_PTR(_4764);
    _4764 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4764);
    DeRef(_0);
    _0 = _4764;
    _4764 = find(_4764, _2508);
    DeRef(_0);
    if (_4764 == 0)
        goto L11;

    // 		    h = SymTab[sym][S_HASHVAL]
    _2 = (int)SEQ_PTR(_7SymTab);
    _4764 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4764);
    _2 = (int)SEQ_PTR(_4764);
    _h = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 		    sym = NewEntry(SymTab[sym][S_NAME], 0, 0, VARIABLE, h, buckets[h], 0) 
    DeRef(_4764);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4764 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4764);
    _0 = _4764;
    _2 = (int)SEQ_PTR(_4764);
    _4764 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4764);
    DeRef(_0);
    DeRef(_4790);
    _2 = (int)SEQ_PTR(_11buckets);
    _4790 = (int)*(((s1_ptr)_2)->base + _h);
    Ref(_4790);
    Ref(_4764);
    Ref(_4790);
    _sym = _11NewEntry(_4764, 0, 0, -100, _h, _4790, 0);

    // 		    buckets[h] = sym
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _h);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);
L11:

    // 		if is_global then
    if (_is_global == 0)
        goto L12;

    // 		    SymTab[sym][S_SCOPE] = SC_GLOBAL 
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 6;
    DeRef(_1);
    goto L13;
L12:

    // 		    SymTab[sym][S_SCOPE] = SC_LOCAL
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);
L13:

    // 		if type_ptr = 0 then
    if (_type_ptr != 0)
        goto L14;

    // 		    SymTab[sym][S_MODE] = M_CONSTANT 
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 		    buckets[SymTab[sym][S_HASHVAL]] = SymTab[sym][S_SAMEHASH]
    DeRef(_4764);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4764 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4764);
    _0 = _4764;
    _2 = (int)SEQ_PTR(_4764);
    _4764 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4764);
    DeRef(_0);
    DeRef(_4790);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4790 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4790);
    _0 = _4790;
    _2 = (int)SEQ_PTR(_4790);
    _4790 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_4790);
    DeRef(_0);
    Ref(_4790);
    _2 = (int)SEQ_PTR(_11buckets);
    if (!IS_ATOM_INT(_4764))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4764)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _4764);
    _1 = *(int *)_2;
    *(int *)_2 = _4790;
    DeRef(_1);

    // 		    tok_match(EQUALS)
    _16tok_match(3);

    // 		    StartSourceLine(FALSE)
    _15StartSourceLine(0);

    // 		    emit_opnd(sym)
    _15emit_opnd(_sym);

    // 		    Expr()  -- no new symbols can be defined in here 
    _16Expr();

    // 		    buckets[SymTab[sym][S_HASHVAL]] = sym
    DeRef(_4790);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4790 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4790);
    _0 = _4790;
    _2 = (int)SEQ_PTR(_4790);
    _4790 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4790);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_11buckets);
    if (!IS_ATOM_INT(_4790))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4790)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _4790);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);

    // 		    SymTab[sym][S_USAGE] = U_WRITTEN     
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 		    emit_op(ASSIGN)
    _15emit_op(18);
    goto L15;
L14:

    // 		    SymTab[sym][S_MODE] = M_NORMAL
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 		    if SymTab[type_ptr][S_TOKEN] = OBJECT then
    DeRef(_4790);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4790 = (int)*(((s1_ptr)_2)->base + _type_ptr);
    Ref(_4790);
    _0 = _4790;
    _2 = (int)SEQ_PTR(_4790);
    _4790 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4790);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _4790, 414))
        goto L16;

    // 				SymTab[sym][S_VTYPE] = object_type
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _11object_type;
    DeRef(_1);
    goto L17;
L16:

    // 				SymTab[sym][S_VTYPE] = type_ptr
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_ptr;
    DeRef(_1);
L17:
L15:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] != COMMA then
    DeRef(_4790);
    _2 = (int)SEQ_PTR(_tok);
    _4790 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4790);
    if (binary_op_a(EQUALS, _4790, -30))
        goto LE;

    // 		    exit
    goto L18;
L19:

    //     end while 
    goto LE;
L18:

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1A;

    // 		release_line()
    _16release_line();
L1A:

    // end procedure
    DeRef(_tok);
    DeRef(_4790);
    DeRef(_4764);
    DeRef(_4773);
    return 0;
    ;
}


int _16Private_declaration(int _type_sym)
{
    int _tok = 0;
    int _tok2 = 0;
    int _sym;
    int _of_;
    int _class;
    int _4836 = 0;
    int _4842 = 0;
    int _4838 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_type_sym)) {
        _1 = (long)(DBL_PTR(_type_sym)->dbl);
        DeRefDS(_type_sym);
        _type_sym = _1;
    }

    // 	tok2 = {0,type_sym}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _type_sym;
    _tok2 = MAKE_SEQ(_1);

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 	cache_line()
    _16cache_line();

    // 	if type_sym and find( type_sym, class_table[CLASS_SYM]) then
    if (_type_sym == 0) {
        goto L2;
    }
    _2 = (int)SEQ_PTR(_7class_table);
    _4838 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4838);
    _0 = _4838;
    _4838 = find(_type_sym, _4838);
    DeRefDS(_0);
L3:
    if (_4838 == 0)
        goto L2;

    // 		replace_tokens( length(line_tokens), length(line_tokens), 
    DeRef(_4838);
    _4838 = SEQ_PTR(_7line_tokens)->length;
    DeRef(_4836);
    _4836 = SEQ_PTR(_7line_tokens)->length;
    _0 = _4842;
    _4842 = _16real_type(_type_sym);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4842 = (int)*(((s1_ptr)_2)->base + _4842);
    Ref(_4842);
    _0 = _4842;
    _2 = (int)SEQ_PTR(_4842);
    _4842 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4842);
    DeRef(_0);
    Ref(_4842);
    _16replace_tokens(_4838, _4836, _4842);
L2:
L1:

    // 	of_ = 0
    _of_ = 0;

    // 	if type_sym = sequence_type then
    if (_type_sym != _11sequence_type)
        goto L4;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] != OF then
    DeRef(_4842);
    _2 = (int)SEQ_PTR(_tok);
    _4842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4842);
    if (binary_op_a(EQUALS, _4842, 424))
        goto L5;

    // 			putback(tok)
    RefDS(_tok);
    _16putback(_tok);
    goto L6;
L5:

    // 			of_ = 2
    _of_ = 2;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 			class = find( tok[T_SYM], class_table[CLASS_SYM] )
    DeRef(_4842);
    _2 = (int)SEQ_PTR(_tok);
    _4842 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4842);
    DeRef(_4836);
    _2 = (int)SEQ_PTR(_7class_table);
    _4836 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4836);
    _class = find(_4842, _4836);

    // 			if not class then
    if (_class != 0)
        goto L7;

    // 				CompileErr("'of' must be followed by a euclass name")
    RefDS(_4854);
    _9CompileErr(_4854);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L8;

    // 					release_line()
    _16release_line();
L8:

    // 				return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_4836);
    DeRef(_4842);
    DeRef(_4838);
    return 0;
L7:

    // 			class = sequence_of_class( class )
    _class = _11sequence_of_class(_class);

    // 			type_sym = class_table[CLASS_SYM][class] 
    DeRef(_4836);
    _2 = (int)SEQ_PTR(_7class_table);
    _4836 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4836);
    _2 = (int)SEQ_PTR(_4836);
    _type_sym = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L9;

    // 				replace_tokens( length(line_tokens) - 2, length(line_tokens), "sequence" )
    DeRefDS(_4836);
    _4836 = SEQ_PTR(_7line_tokens)->length;
    _4836 = _4836 - 2;
    DeRef(_4842);
    _4842 = SEQ_PTR(_7line_tokens)->length;
    RefDS(_850);
    _16replace_tokens(_4836, _4842, _850);
L9:
L6:
L4:

    //     while TRUE do 
LA:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, NAMESPACE}) then
    DeRef(_4842);
    _2 = (int)SEQ_PTR(_tok);
    _4842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4842);
    _0 = _4836;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    *((int *)(_2+20)) = 523;
    _4836 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4836;
    _4836 = find(_4842, _4836);
    DeRefDSi(_0);
    if (_4836 != 0)
        goto LB;

    // 			if tok[T_ID] = DOT_NOTATION then
    _2 = (int)SEQ_PTR(_tok);
    _4836 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4836);
    if (binary_op_a(NOTEQ, _4836, 423))
        goto LC;

    // 				current_instance &= tok2[T_SYM]
    DeRef(_4836);
    _2 = (int)SEQ_PTR(_tok2);
    _4836 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4836);
    if (IS_SEQUENCE(_7current_instance) && IS_ATOM(_4836)) {
        Ref(_4836);
        Append(&_7current_instance, _7current_instance, _4836);
    }
    else if (IS_ATOM(_7current_instance) && IS_SEQUENCE(_4836)) {
    }
    else {
        Concat((object_ptr)&_7current_instance, _7current_instance, (s1_ptr)_4836);
    }

    // 				exit
    goto LD;
    goto LE;
LC:

    // 			    CompileErr("a variable name is expected here")
    RefDS(_4870);
    _9CompileErr(_4870);

    // 			    if preprocess then
    if (_7preprocess == 0)
        goto LF;

    // 			    	release_line()
    _16release_line();
LF:

    // 			    return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_4836);
    DeRef(_4842);
    DeRef(_4838);
    return 0;
L10:
    goto LE;
LB:
LE:

    // 		tok2 = tok
    RefDS(_tok);
    DeRef(_tok2);
    _tok2 = _tok;

    // 		sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
    DeRef(_4836);
    _2 = (int)SEQ_PTR(_tok);
    _4836 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4836);
    Ref(_4836);
    _sym = _16SetPrivateScope(_4836, _type_sym, _16param_num);
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 		param_num += 1
    _16param_num = _16param_num + 1;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 		if tok[T_ID] != COMMA then
    DeRef(_4836);
    _2 = (int)SEQ_PTR(_tok);
    _4836 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4836);
    if (binary_op_a(EQUALS, _4836, -30))
        goto LA;

    // 		    exit
    goto LD;
L11:

    //     end while 
    goto LA;
LD:

    //     if preprocess then
    if (_7preprocess == 0)
        goto L12;

    //     	release_line()
    _16release_line();
L12:

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // end procedure
    DeRefDS(_tok);
    DeRef(_tok2);
    DeRef(_4836);
    DeRef(_4842);
    DeRef(_4838);
    return 0;
    ;
}


int _16Member_declaration(int _type_sym)
{
    int _tok = 0;
    int _tok2 = 0;
    int _sym;
    int _members;
    int _count;
    int _member;
    int _replacement = 0;
    int _class;
    int _of_;
    int _4885 = 0;
    int _4877 = 0;
    int _4937 = 0;
    int _4934 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_type_sym)) {
        _1 = (long)(DBL_PTR(_type_sym)->dbl);
        DeRefDS(_type_sym);
        _type_sym = _1;
    }

    //     if preprocess then
    if (_7preprocess == 0)
        goto L1;

    //     	cache_line()
    _16cache_line();
L1:

    //     members = member_count( current_class )
    _members = _11member_count(_7current_class);

    //     count = 0
    _count = 0;

    // 	tok2 = {0,type_sym}
    DeRef(_tok2);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _type_sym;
    _tok2 = MAKE_SEQ(_1);

    // 	of_ = 0
    _of_ = 0;

    // 	if type_sym = sequence_type then
    if (_type_sym != _11sequence_type)
        goto L2;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] != OF then
    DeRef(_4877);
    _2 = (int)SEQ_PTR(_tok);
    _4877 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4877);
    if (binary_op_a(EQUALS, _4877, 424))
        goto L3;

    // 			putback(tok)
    RefDS(_tok);
    _16putback(_tok);
    goto L4;
L3:

    // 			of_ = 2
    _of_ = 2;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 			class = find( tok[T_SYM], class_table[CLASS_SYM] )
    DeRef(_4877);
    _2 = (int)SEQ_PTR(_tok);
    _4877 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4877);
    DeRef(_4885);
    _2 = (int)SEQ_PTR(_7class_table);
    _4885 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4885);
    _class = find(_4877, _4885);

    // 			if not class then
    if (_class != 0)
        goto L5;

    // 				CompileErr("'of' must be followed by a euclass name")
    RefDS(_4854);
    _9CompileErr(_4854);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L6;

    // 					release_line()
    _16release_line();
L6:

    // 				return
    DeRef(_tok);
    DeRef(_tok2);
    DeRefi(_replacement);
    DeRef(_4885);
    DeRef(_4877);
    DeRef(_4937);
    DeRef(_4934);
    return 0;
L5:

    // 			class = sequence_of_class( class )
    _class = _11sequence_of_class(_class);

    // 			type_sym = class_table[CLASS_SYM][class] 
    DeRef(_4885);
    _2 = (int)SEQ_PTR(_7class_table);
    _4885 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4885);
    _2 = (int)SEQ_PTR(_4885);
    _type_sym = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;
L4:
L2:

    //     while TRUE do 
L7:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, NAMESPACE}) then
    DeRef(_4885);
    _2 = (int)SEQ_PTR(_tok);
    _4885 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4885);
    _0 = _4877;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    *((int *)(_2+20)) = 523;
    _4877 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4877;
    _4877 = find(_4885, _4877);
    DeRefDSi(_0);
    if (_4877 != 0)
        goto L8;

    // 		    CompileErr("a variable name is expected here")
    RefDS(_4870);
    _9CompileErr(_4870);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L9;

    // 				release_line()
    _16release_line();
L9:

    // 		    return
    DeRef(_tok);
    DeRef(_tok2);
    DeRefi(_replacement);
    DeRef(_4885);
    DeRef(_4877);
    DeRef(_4937);
    DeRef(_4934);
    return 0;
L8:

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LA;

    // 			if count then
    if (_count == 0)
        goto LB;

    // 				replacement = ""
    RefDS(_39);
    DeRefi(_replacement);
    _replacement = _39;
    goto LC;
LB:

    // 				if SymTab[class_table[CLASS_SYM][current_class]][S_SCOPE] = GLOBAL then
    DeRef(_4877);
    _2 = (int)SEQ_PTR(_7class_table);
    _4877 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4877);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_4877);
    _4877 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_4877);
    DeRefDS(_0);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4877))
        _4877 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4877)->dbl));
    else
        _4877 = (int)*(((s1_ptr)_2)->base + _4877);
    Ref(_4877);
    DeRef(_0);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_4877);
    _4877 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4877);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _4877, 411))
        goto LD;

    // 					replacement = "global constant "
    RefDS(_4901);
    DeRefi(_replacement);
    _replacement = _4901;
    goto LE;
LD:

    // 					replacement = "constant "
    RefDS(_4902);
    DeRefi(_replacement);
    _replacement = _4902;
LE:
LC:

    // 			members += 1
    _members = _members + 1;

    // 			replacement &= sprintf("%s_MEMBER_%s = %d", 
    DeRef(_4877);
    _2 = (int)SEQ_PTR(_7class_table);
    _4877 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4877);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_4877);
    _4877 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_4877);
    DeRefDS(_0);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4877))
        _4877 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4877)->dbl));
    else
        _4877 = (int)*(((s1_ptr)_2)->base + _4877);
    Ref(_4877);
    DeRef(_0);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_4877);
    _4877 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4877);
    DeRef(_0);
    DeRef(_4885);
    _2 = (int)SEQ_PTR(_tok);
    _4885 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4885);
    _0 = _4885;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4885))
        _4885 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4885)->dbl));
    else
        _4885 = (int)*(((s1_ptr)_2)->base + _4885);
    Ref(_4885);
    DeRef(_0);
    _0 = _4885;
    _2 = (int)SEQ_PTR(_4885);
    _4885 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4885);
    DeRef(_0);
    _0 = _4885;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4877);
    *((int *)(_2+4)) = _4877;
    Ref(_4885);
    *((int *)(_2+8)) = _4885;
    *((int *)(_2+12)) = _members;
    _4885 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4885;
    _4885 = EPrintf(-9999999, _4904, _4885);
    DeRefDS(_0);
    Concat((object_ptr)&_replacement, _replacement, (s1_ptr)_4885);

    // 			if count then
    if (_count == 0)
        goto LF;

    // 				replace_tokens( length(line_tokens), length(line_tokens), replacement )
    DeRefDSi(_4885);
    _4885 = SEQ_PTR(_7line_tokens)->length;
    DeRef(_4877);
    _4877 = SEQ_PTR(_7line_tokens)->length;
    RefDS(_replacement);
    _16replace_tokens(_4885, _4877, _replacement);
    goto L10;
LF:

    // 				replace_tokens( length(line_tokens)-1-of_, length(line_tokens), replacement )
    DeRef(_4877);
    _4877 = SEQ_PTR(_7line_tokens)->length;
    _4877 = _4877 - 1;
    _4877 = _4877 - _of_;
    DeRef(_4885);
    _4885 = SEQ_PTR(_7line_tokens)->length;
    RefDS(_replacement);
    _16replace_tokens(_4877, _4885, _replacement);
L10:

    // 			count += 1
    _count = _count + 1;
LA:

    // 		if SymTab[tok[T_SYM]][S_SCOPE] != SC_UNDEFINED then
    DeRef(_4885);
    _2 = (int)SEQ_PTR(_tok);
    _4885 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4885);
    _0 = _4885;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4885))
        _4885 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4885)->dbl));
    else
        _4885 = (int)*(((s1_ptr)_2)->base + _4885);
    Ref(_4885);
    DeRef(_0);
    _0 = _4885;
    _2 = (int)SEQ_PTR(_4885);
    _4885 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4885);
    DeRef(_0);
    if (binary_op_a(EQUALS, _4885, 9))
        goto L11;

    // 			tok = keyfind( SymTab[tok[T_SYM]][S_NAME] & 127, -1 )
    DeRef(_4885);
    _2 = (int)SEQ_PTR(_tok);
    _4885 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4885);
    _0 = _4885;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4885))
        _4885 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4885)->dbl));
    else
        _4885 = (int)*(((s1_ptr)_2)->base + _4885);
    Ref(_4885);
    DeRef(_0);
    _0 = _4885;
    _2 = (int)SEQ_PTR(_4885);
    _4885 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4885);
    DeRef(_0);
    if (IS_SEQUENCE(_4885) && IS_ATOM(127)) {
        Append(&_4885, _4885, 127);
    }
    else if (IS_ATOM(_4885) && IS_SEQUENCE(127)) {
    }
    else {
        Concat((object_ptr)&_4885, _4885, (s1_ptr)127);
    }
    RefDS(_4885);
    _0 = _tok;
    _tok = _11keyfind(_4885, -1);
    DeRefDS(_0);

    // 			SymTab[tok[T_SYM]][S_NAME] = SymTab[tok[T_SYM]][S_NAME][1..$-1]
    DeRefDS(_4885);
    _2 = (int)SEQ_PTR(_tok);
    _4885 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4885);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_4885))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4885)->dbl));
    else
        _3 = (int)(_4885 + ((s1_ptr)_2)->base);
    DeRef(_4934);
    _2 = (int)SEQ_PTR(_tok);
    _4934 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4934);
    _0 = _4934;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4934))
        _4934 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4934)->dbl));
    else
        _4934 = (int)*(((s1_ptr)_2)->base + _4934);
    Ref(_4934);
    DeRef(_0);
    _0 = _4934;
    _2 = (int)SEQ_PTR(_4934);
    _4934 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4934);
    DeRef(_0);
    DeRef(_4937);
    _4937 = SEQ_PTR(_4934)->length;
    _4937 = _4937 - 1;
    rhs_slice_target = (object_ptr)&_4937;
    RHS_Slice((s1_ptr)_4934, 1, _4937);
    RefDS(_4937);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _4937;
    DeRef(_1);
L11:

    // 		SymTab[tok[T_SYM]][S_VTYPE] = type_sym
    DeRef(_4937);
    _2 = (int)SEQ_PTR(_tok);
    _4937 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4937);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_4937))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4937)->dbl));
    else
        _3 = (int)(_4937 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_sym;
    DeRef(_1);

    // 		member = add_member( tok[T_SYM] )
    DeRef(_4934);
    _2 = (int)SEQ_PTR(_tok);
    _4934 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4934);
    Ref(_4934);
    _member = _11add_member(_4934);

    // 		SymTab[tok[T_SYM]][S_NAME] &= "@" & SymTab[class_table[CLASS_SYM][current_class]][S_NAME]
    DeRef(_4934);
    _2 = (int)SEQ_PTR(_tok);
    _4934 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4934);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_4934))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4934)->dbl));
    else
        _3 = (int)(_4934 + ((s1_ptr)_2)->base);
    DeRef(_4877);
    _2 = (int)SEQ_PTR(_7class_table);
    _4877 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4877);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_4877);
    _4877 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_4877);
    DeRefDS(_0);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4877))
        _4877 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4877)->dbl));
    else
        _4877 = (int)*(((s1_ptr)_2)->base + _4877);
    Ref(_4877);
    DeRef(_0);
    _0 = _4877;
    _2 = (int)SEQ_PTR(_4877);
    _4877 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4877);
    DeRef(_0);
    if (IS_SEQUENCE(_4948) && IS_ATOM(_4877)) {
        Ref(_4877);
        Append(&_4877, _4948, _4877);
    }
    else if (IS_ATOM(_4948) && IS_SEQUENCE(_4877)) {
    }
    else {
        Concat((object_ptr)&_4877, _4948, (s1_ptr)_4877);
    }
    DeRef(_4885);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _4885 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4885);
    if (IS_SEQUENCE(_4885) && IS_ATOM(_4877)) {
    }
    else if (IS_ATOM(_4885) && IS_SEQUENCE(_4877)) {
        Ref(_4885);
        Prepend(&_4885, _4877, _4885);
    }
    else {
        Concat((object_ptr)&_4885, _4885, (s1_ptr)_4877);
    }
    RefDS(_4885);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _4885;
    DeRef(_1);

    // 		tok2 = tok
    RefDS(_tok);
    DeRef(_tok2);
    _tok2 = _tok;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 		if tok[T_ID] != COMMA then
    DeRefDS(_4885);
    _2 = (int)SEQ_PTR(_tok);
    _4885 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4885);
    if (binary_op_a(EQUALS, _4885, -30))
        goto L7;

    // 		    exit
    goto L12;
L13:

    //     end while
    goto L7;
L12:

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L14;

    // 		release_line()
    _16release_line();
L14:

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // end procedure
    DeRefDS(_tok);
    DeRef(_tok2);
    DeRefi(_replacement);
    DeRef(_4885);
    DeRef(_4877);
    DeRef(_4937);
    DeRef(_4934);
    return 0;
    ;
}


