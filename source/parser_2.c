// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16Procedure_call(int _tok)
{
    int _n;
    int _scope;
    int _opcode;
    int _temp_tok = 0;
    int _s;
    int _4972 = 0;
    int _4970 = 0;
    int _4959 = 0;
    int _0, _1, _2, _3;
    

    //     s = tok[T_SYM] 
    _2 = (int)SEQ_PTR(_tok);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     n = SymTab[s][S_NUM_ARGS]
    _2 = (int)SEQ_PTR(_7SymTab);
    _4959 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4959);
    _2 = (int)SEQ_PTR(_4959);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     scope = SymTab[s][S_SCOPE]
    DeRef(_4959);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4959 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4959);
    _2 = (int)SEQ_PTR(_4959);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    //     opcode = SymTab[s][S_OPCODE]
    DeRef(_4959);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4959 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4959);
    _2 = (int)SEQ_PTR(_4959);
    _opcode = (int)*(((s1_ptr)_2)->base + 19);
    if (!IS_ATOM_INT(_opcode))
        _opcode = (long)DBL_PTR(_opcode)->dbl;

    // 	add_ref( tok )
    RefDS(_tok);
    _11add_ref(_tok);

    //     tok_match(LEFT_ROUND)
    _16tok_match(-26);

    //     if SymTab[s][S_EFFECT] then
    DeRef(_4959);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4959 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4959);
    _0 = _4959;
    _2 = (int)SEQ_PTR(_4959);
    _4959 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_4959);
    DeRef(_0);
    if (_4959 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_4959) && DBL_PTR(_4959)->dbl == 0.0)
            goto L1;
    }

    // 		SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4970 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4970);
    _0 = _4970;
    _2 = (int)SEQ_PTR(_4970);
    _4970 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_4970);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4972 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_4972);
    _0 = _4972;
    _2 = (int)SEQ_PTR(_4972);
    _4972 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_4972);
    DeRef(_0);
    _0 = _4972;
    if (IS_ATOM_INT(_4970) && IS_ATOM_INT(_4972)) {
        _4972 = (_4970 | _4972);
    }
    else {
        _4972 = binary_op(OR_BITS, _4970, _4972);
    }
    DeRef(_0);
    Ref(_4972);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _4972;
    DeRef(_1);
L1:

    //     ParseArgs(s)
    _16ParseArgs(_s);

    //     if scope = SC_PREDEF then
    if (_scope != 7)
        goto L2;

    // 		emit_op(opcode)
    _15emit_op(_opcode);

    // 		if opcode = ABORT then
    if (_opcode != 126)
        goto L3;

    // 		    temp_tok = next_token()
    _0 = _temp_tok;
    _temp_tok = _16next_token();
    DeRef(_0);

    // 		    putback(temp_tok)
    RefDS(_temp_tok);
    _16putback(_temp_tok);

    // 		    NotReached(temp_tok[T_ID], "abort()")
    DeRef(_4972);
    _2 = (int)SEQ_PTR(_temp_tok);
    _4972 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4972);
    Ref(_4972);
    RefDS(_4979);
    _16NotReached(_4972, _4979);
L4:
    goto L3;
L2:

    // 		op_info1 = s
    _15op_info1 = _s;

    // 		emit_op(r:PROC)
    _15emit_op(27);

    // 		if not TRANSLATE then

    // 		    if OpTrace then
    if (_7OpTrace == 0)
        goto L5;

    // 			emit_op(UPDATE_GLOBALS)
    _15emit_op(89);
L5:
L6:
L3:

    // end procedure
    DeRefDS(_tok);
    DeRef(_temp_tok);
    DeRef(_4972);
    DeRef(_4970);
    DeRef(_4959);
    return 0;
    ;
}


int _16Print_statement()
{
    int _4984 = 0;
    int _4981;
    int _0, _1, _2, _3;
    

    //     emit_opnd(NewIntSym(1)) -- stdout 
    _4981 = _11NewIntSym(1);
    _15emit_opnd(_4981);

    //     Expr()
    _16Expr();

    //     emit_op(QPRINT)
    _15emit_op(36);

    //     SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4984 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4984);
    _0 = _4984;
    _2 = (int)SEQ_PTR(_4984);
    _4984 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_4984);
    DeRef(_0);
    _0 = _4984;
    if (IS_ATOM_INT(_4984)) {
        _4984 = (_4984 | 536870912);
    }
    else {
        _4984 = binary_op(OR_BITS, _4984, 536870912);
    }
    DeRef(_0);
    Ref(_4984);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _4984;
    DeRef(_1);

    // end procedure
    DeRef(_4984);
    return 0;
    ;
}


int _16Statement_list()
{
    int _tok = 0;
    int _id;
    int _4992 = 0;
    int _4987 = 0;
    int _5014 = 0;
    int _0, _1, _2;
    

    //     stmt_nest += 1
    _16stmt_nest = _16stmt_nest + 1;

    //     while TRUE do 
L1:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	if id = VARIABLE or id = QUALIFIED_VARIABLE then
    DeRef(_4987);
    _4987 = (_id == -100);
    if (_4987 != 0) {
        goto L2;
    }
    DeRef(_4992);
    _4992 = (_id == 515);
L3:
    if (_4992 == 0)
        goto L4;
L2:

    // 		StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 		if length(current_instance) and current_instance[$] then
    DeRef(_4992);
    _4992 = SEQ_PTR(_7current_instance)->length;
    if (_4992 == 0) {
        goto L5;
    }
    DeRef(_4987);
    _4987 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4987 = (int)*(((s1_ptr)_2)->base + _4987);
    Ref(_4987);
L6:
    if (_4987 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_4987) && DBL_PTR(_4987)->dbl == 0.0)
            goto L5;
    }

    // 			call_proc( forward_method, { tok } )
    _0 = _4987;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _4987 = MAKE_SEQ(_1);
    DeRef(_0);
    _1 = (int)SEQ_PTR(_4987);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 			current_instance = current_instance[1..$-1]
    DeRefDS(_4987);
    _4987 = SEQ_PTR(_7current_instance)->length;
    _4987 = _4987 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4987);
    goto L1;
L5:

    // 		    Assignment(tok)
    RefDS(_tok);
    _16Assignment(_tok);
L7:
    goto L1;
L4:

    // 	elsif id = r:PROC or id = QUALIFIED_PROC then
    DeRef(_4987);
    _4987 = (_id == 27);
    if (_4987 != 0) {
        goto L8;
    }
    DeRef(_4992);
    _4992 = (_id == 525);
L9:
    if (_4992 == 0)
        goto LA;
L8:

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    Procedure_call(tok)
    RefDS(_tok);
    _16Procedure_call(_tok);
    goto L1;
LA:

    // 	elsif id = IF then
    if (_id != 20)
        goto LB;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    If_statement()
    _16If_statement();
    goto L1;
LB:

    // 	elsif id = FOR then
    if (_id != 21)
        goto LC;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    For_statement()
    _16For_statement();
    goto L1;
LC:

    // 	elsif id = RETURN then
    if (_id != 412)
        goto LD;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    Return_statement()
    _16Return_statement();
    goto L1;
LD:

    // 	elsif id = EXIT then
    if (_id != 61)
        goto LE;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    Exit_statement()
    _16Exit_statement();
    goto L1;
LE:

    // 	elsif id = WHILE then
    if (_id != 47)
        goto LF;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    While_statement()
    _16While_statement();
    goto L1;
LF:

    // 	elsif id = QUESTION_MARK then
    if (_id != -31)
        goto L10;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    Print_statement()
    _16Print_statement();
    goto L1;
L10:

    // 	elsif id = DOT_NOTATION then 
    if (_id != 423)
        goto L11;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		hide_member[$] &= tok[T_SYM]
    DeRef(_4992);
    _4992 = SEQ_PTR(_7hide_member)->length;
    DeRef(_4987);
    _2 = (int)SEQ_PTR(_tok);
    _4987 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4987);
    DeRef(_5014);
    _2 = (int)SEQ_PTR(_7hide_member);
    _5014 = (int)*(((s1_ptr)_2)->base + _4992);
    Ref(_5014);
    if (IS_SEQUENCE(_5014) && IS_ATOM(_4987)) {
        Ref(_4987);
        Append(&_5014, _5014, _4987);
    }
    else if (IS_ATOM(_5014) && IS_SEQUENCE(_4987)) {
        Ref(_5014);
        Prepend(&_5014, _4987, _5014);
    }
    else {
        Concat((object_ptr)&_5014, _5014, (s1_ptr)_4987);
    }
    RefDS(_5014);
    _2 = (int)SEQ_PTR(_7hide_member);
    _2 = (int)(((s1_ptr)_2)->base + _4992);
    _1 = *(int *)_2;
    *(int *)_2 = _5014;
    DeRef(_1);

    // 		StartSourceLine( TRUE )
    _15StartSourceLine(1);

    // 		call_proc( forward_method, { tok } )
    _0 = _5014;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _5014 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _1 = (int)SEQ_PTR(_5014);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 		current_instance = current_instance[1..$-1]
    DeRefDS(_5014);
    _5014 = SEQ_PTR(_7current_instance)->length;
    _5014 = _5014 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _5014);
    goto L1;
L11:

    // 	elsif id = TYPE and find( tok[T_SYM], class_table[CLASS_SYM] ) then
    DeRef(_5014);
    _5014 = (_id == 504);
    if (_5014 == 0) {
        goto L12;
    }
    DeRef(_4987);
    _2 = (int)SEQ_PTR(_tok);
    _4987 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4987);
    DeRef(_4992);
    _2 = (int)SEQ_PTR(_7class_table);
    _4992 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4992);
    _0 = _4992;
    _4992 = find(_4987, _4992);
    DeRefDS(_0);
L13:
    if (_4992 == 0)
        goto L12;

    // 		StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 		current_instance &= tok[T_SYM]
    DeRef(_4992);
    _2 = (int)SEQ_PTR(_tok);
    _4992 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4992);
    if (IS_SEQUENCE(_7current_instance) && IS_ATOM(_4992)) {
        Ref(_4992);
        Append(&_7current_instance, _7current_instance, _4992);
    }
    else if (IS_ATOM(_7current_instance) && IS_SEQUENCE(_4992)) {
    }
    else {
        Concat((object_ptr)&_7current_instance, _7current_instance, (s1_ptr)_4992);
    }

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 		if tok[T_ID] != DOT_NOTATION then
    DeRef(_4992);
    _2 = (int)SEQ_PTR(_tok);
    _4992 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4992);
    if (binary_op_a(EQUALS, _4992, 423))
        goto L14;

    // 			CompileErr( "Missing method call")
    RefDS(_5030);
    _9CompileErr(_5030);

    // 			return
    DeRefDS(_tok);
    DeRef(_4992);
    DeRef(_4987);
    DeRef(_5014);
    return 0;
L14:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		call_proc( forward_method, {tok} )
    _0 = _4992;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _4992 = MAKE_SEQ(_1);
    DeRef(_0);
    _1 = (int)SEQ_PTR(_4992);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 		current_instance = current_instance[1..$-1]
    DeRefDS(_4992);
    _4992 = SEQ_PTR(_7current_instance)->length;
    _4992 = _4992 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4992);
    goto L1;
L12:

    // 	elsif id = CONTINUE then
    if (_id != 425)
        goto L15;

    // 		Continue_statement()
    _16Continue_statement();
    goto L1;
L15:

    // 	elsif id = COLON then
    if (_id != -23)
        goto L16;

    // 		Goto_Label()
    _16Goto_Label();
    goto L1;
L16:

    // 	elsif id = GOTO then
    if (_id != 175)
        goto L17;

    // 		Goto_Statement()
    _16Goto_Statement();
    goto L1;
L17:

    // 	    putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 	    stmt_nest -= 1
    _16stmt_nest = _16stmt_nest - 1;

    // 	    InitDelete()
    _16InitDelete();

    // 	    return
    DeRefDS(_tok);
    DeRef(_4992);
    DeRef(_4987);
    DeRef(_5014);
    return 0;
L18:

    //     end while
    goto L1;
L19:

    // end procedure
    DeRef(_tok);
    DeRef(_4992);
    DeRef(_4987);
    DeRef(_5014);
    return 0;
    ;
}


int _16pp_decorate(int _pdec)
{
    int _5043 = 0;
    int _5042;
    int _0, _1, _2;
    

    // 	for d = 1 to length(pdec) do
    _5042 = SEQ_PTR(_pdec)->length;
    { int _d;
        _d = 1;
L1:
        if (_d > _5042)
            goto L2;

        // 		if find(pdec[d], "@!") then
        DeRef(_5043);
        _2 = (int)SEQ_PTR(_pdec);
        _5043 = (int)*(((s1_ptr)_2)->base + _d);
        Ref(_5043);
        _0 = _5043;
        _5043 = find(_5043, _4013);
        DeRef(_0);
        if (_5043 == 0)
            goto L3;

        // 			pdec[d] = '_'
        _2 = (int)SEQ_PTR(_pdec);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _pdec = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _d);
        _1 = *(int *)_2;
        *(int *)_2 = 95;
        DeRef(_1);
L3:

        // 	end for
        _d = _d + 1;
        goto L1;
L2:
        ;
    }

    // 	return pdec
    DeRef(_5043);
    return _pdec;
    ;
}


int _16find_label(int _gotos, int _label)
{
    int _ix;
    int _5054 = 0;
    int _5049 = 0;
    int _5055 = 0;
    int _5045 = 0;
    int _0, _1, _2, _3;
    

    // 	ix = find( label, gotos[G_LABEL] )
    _2 = (int)SEQ_PTR(_gotos);
    _5045 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5045);
    _ix = find(_label, _5045);

    // 	if ix then
    if (_ix == 0)
        goto L1;

    // 		return ix
    DeRefDS(_gotos);
    DeRefDS(_label);
    DeRef(_5045);
    return _ix;
L1:

    // 	for i = 1 to length(gotos[G_LABEL]) do
    DeRef(_5045);
    _2 = (int)SEQ_PTR(_gotos);
    _5045 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5045);
    _0 = _5045;
    _5045 = SEQ_PTR(_5045)->length;
    DeRef(_0);
    { int _i;
        _i = 1;
L2:
        if (_i > _5045)
            goto L3;

        // 		if length(gotos[G_LABEL][i]) = 3 and label[1] = gotos[G_LABEL][i][1] 
        DeRef(_5049);
        _2 = (int)SEQ_PTR(_gotos);
        _5049 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5049);
        _0 = _5049;
        _2 = (int)SEQ_PTR(_5049);
        _5049 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5049);
        DeRef(_0);
        _0 = _5049;
        _5049 = SEQ_PTR(_5049)->length;
        DeRef(_0);
        _5049 = (_5049 == 3);
        if (_5049 == 0) {
            _5049 = 0;
            goto L4;
        }
        DeRef(_5054);
        _2 = (int)SEQ_PTR(_label);
        _5054 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5054);
        DeRef(_5055);
        _2 = (int)SEQ_PTR(_gotos);
        _5055 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5055);
        _0 = _5055;
        _2 = (int)SEQ_PTR(_5055);
        _5055 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5055);
        DeRef(_0);
        _0 = _5055;
        _2 = (int)SEQ_PTR(_5055);
        _5055 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5055);
        DeRef(_0);
        _0 = _5055;
        if (IS_ATOM_INT(_5054) && IS_ATOM_INT(_5055)) {
            _5055 = (_5054 == _5055);
        }
        else {
            _5055 = binary_op(EQUALS, _5054, _5055);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5055))
            _5049 = (_5055 != 0);
        else
            _5049 = DBL_PTR(_5055)->dbl != 0.0;
L4:
        if (_5049 == 0) {
            goto L5;
        }
        DeRef(_5054);
        _2 = (int)SEQ_PTR(_gotos);
        _5054 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5054);
        _0 = _5054;
        _2 = (int)SEQ_PTR(_5054);
        _5054 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5054);
        DeRef(_0);
        _0 = _5054;
        _2 = (int)SEQ_PTR(_5054);
        _5054 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5054);
        DeRef(_0);
        _0 = _5054;
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_5054))
            _5054 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5054)->dbl));
        else
            _5054 = (int)*(((s1_ptr)_2)->base + _5054);
        Ref(_5054);
        DeRef(_0);
        _0 = _5054;
        _2 = (int)SEQ_PTR(_5054);
        _5054 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5054);
        DeRef(_0);
        DeRef(_5049);
        _2 = (int)SEQ_PTR(_label);
        _5049 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5049);
        _0 = _5049;
        if (_5054 == _5049)
            _5049 = 1;
        else if (IS_ATOM_INT(_5054) && IS_ATOM_INT(_5049))
            _5049 = 0;
        else
            _5049 = (compare(_5054, _5049) == 0);
        DeRef(_0);
L6:
        if (_5049 == 0)
            goto L5;

        // 			return i
        DeRefDS(_gotos);
        DeRefDS(_label);
        DeRef(_5054);
        DeRef(_5049);
        DeRef(_5055);
        DeRef(_5045);
        return _i;
L5:

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	ix = find( label[1], gotos[G_DEFAULT][1] )
    DeRef(_5049);
    _2 = (int)SEQ_PTR(_label);
    _5049 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5049);
    DeRef(_5054);
    _2 = (int)SEQ_PTR(_gotos);
    _5054 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5054);
    _0 = _5054;
    _2 = (int)SEQ_PTR(_5054);
    _5054 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5054);
    DeRef(_0);
    _ix = find(_5049, _5054);

    // 	if ix then
    if (_ix == 0)
        goto L7;

    // 		label[2] = gotos[G_DEFAULT][2][ix]
    DeRef(_5054);
    _2 = (int)SEQ_PTR(_gotos);
    _5054 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5054);
    _0 = _5054;
    _2 = (int)SEQ_PTR(_5054);
    _5054 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5054);
    DeRef(_0);
    _0 = _5054;
    _2 = (int)SEQ_PTR(_5054);
    _5054 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_5054);
    DeRef(_0);
    Ref(_5054);
    _2 = (int)SEQ_PTR(_label);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _label = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5054;
    DeRef(_1);

    // 		gotos[G_DEFAULT][1] = {}
    _2 = (int)SEQ_PTR(_gotos);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _gotos = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    // 		return find_label( gotos, label )
    RefDS(_gotos);
    DeRef(_5049);
    _5049 = _gotos;
    RefDS(_label);
    DeRef(_5054);
    _5054 = _label;
    RefDS(_5049);
    RefDS(_5054);
    _0 = _5054;
    _5054 = _16find_label(_5049, _5054);
    DeRefDS(_0);
    DeRefDS(_gotos);
    DeRefDS(_label);
    DeRefDS(_5049);
    DeRef(_5055);
    DeRef(_5045);
    return _5054;
L7:

    // 	return 0
    DeRefDS(_gotos);
    DeRefDS(_label);
    DeRef(_5054);
    DeRef(_5049);
    DeRef(_5055);
    DeRef(_5045);
    return 0;
    ;
}


int _16PatchGotos()
{
    int _patch_list = 0;
    int _pc;
    int _file;
    int _ix;
    int _label = 0;
    int _gotos = 0;
    int _5079 = 0;
    int _5087 = 0;
    int _5088 = 0;
    int _0, _1, _2, _3;
    

    // 	if not length(goto_back_patch) then
    _5079 = SEQ_PTR(_7goto_back_patch)->length;
    if (_5079 != 0)
        goto L1;

    // 		return
    return 0;
L1:

    // 	patch_list = goto_back_patch[$]
    DeRef(_5079);
    _5079 = SEQ_PTR(_7goto_back_patch)->length;
    DeRef(_patch_list);
    _2 = (int)SEQ_PTR(_7goto_back_patch);
    _patch_list = (int)*(((s1_ptr)_2)->base + _5079);
    Ref(_patch_list);

    // 	gotos = SymTab[CurrentSub][S_GOTO]
    _2 = (int)SEQ_PTR(_7SymTab);
    _5079 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_5079);
    DeRef(_gotos);
    _2 = (int)SEQ_PTR(_5079);
    _gotos = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_gotos);

    // 	if atom(gotos) then
    DeRef(_5079);
    _5079 = IS_ATOM(_gotos);
    if (_5079 == 0)
        goto L2;

    // 		SymTab[CurrentSub][S_GOTO] = {{},{},{}}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    _0 = _5088;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDSn(_39, 3);
    *((int *)(_2+4)) = _39;
    *((int *)(_2+8)) = _39;
    *((int *)(_2+12)) = _39;
    _5088 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_5088);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _5088;
    DeRef(_1);
L2:

    // 	for i = 1 to length( patch_list ) do
    DeRef(_5088);
    _5088 = SEQ_PTR(_patch_list)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _5088)
            goto L4;

        // 		pc = patch_list[i]
        _2 = (int)SEQ_PTR(_patch_list);
        _pc = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_pc))
            _pc = (long)DBL_PTR(_pc)->dbl;

        // 		label = Code[pc+1]
        DeRef(_5087);
        _5087 = _pc + 1;
        DeRef(_label);
        _2 = (int)SEQ_PTR(_7Code);
        _label = (int)*(((s1_ptr)_2)->base + _5087);
        Ref(_label);

        // 		if length(SymTab[label]) < SIZEOF_VAR_ENTRY or SymTab[label][S_MODE] = M_CONSTANT and
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_label))
            _5087 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_label)->dbl));
        else
            _5087 = (int)*(((s1_ptr)_2)->base + _label);
        Ref(_5087);
        _0 = _5087;
        _5087 = SEQ_PTR(_5087)->length;
        DeRef(_0);
        _5087 = (_5087 < 14);
        if (_5087 != 0) {
            _5087 = 1;
            goto L5;
        }
        DeRef(_5079);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_label))
            _5079 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_label)->dbl));
        else
            _5079 = (int)*(((s1_ptr)_2)->base + _label);
        Ref(_5079);
        _0 = _5079;
        _2 = (int)SEQ_PTR(_5079);
        _5079 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5079);
        DeRef(_0);
        _0 = _5079;
        if (IS_ATOM_INT(_5079)) {
            _5079 = (_5079 == 2);
        }
        else {
            _5079 = binary_op(EQUALS, _5079, 2);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5079))
            _5087 = (_5079 != 0);
        else
            _5087 = DBL_PTR(_5079)->dbl != 0.0;
L5:
        if (_5087 == 0) {
            goto L6;
        }
        DeRef(_5087);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_label))
            _5087 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_label)->dbl));
        else
            _5087 = (int)*(((s1_ptr)_2)->base + _label);
        Ref(_5087);
        _0 = _5087;
        _2 = (int)SEQ_PTR(_5087);
        _5087 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5087);
        DeRef(_0);
        _0 = _5087;
        if (IS_ATOM_INT(_5087) && IS_ATOM_INT(_7NOVALUE))
            _5087 = (_5087 < _7NOVALUE) ? -1 : (_5087 > _7NOVALUE);
        else
            _5087 = compare(_5087, _7NOVALUE);
        DeRef(_0);
L7:
        if (_5087 == 0)
            goto L6;

        // 			file  = Code[pc+2]
        DeRef(_5087);
        _5087 = _pc + 2;
        _2 = (int)SEQ_PTR(_7Code);
        _file = (int)*(((s1_ptr)_2)->base + _5087);
        if (!IS_ATOM_INT(_file))
            _file = (long)DBL_PTR(_file)->dbl;

        // 			label = SymTab[label][S_OBJ]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_label))
            _5087 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_label)->dbl));
        else
            _5087 = (int)*(((s1_ptr)_2)->base + _label);
        Ref(_5087);
        DeRef(_label);
        _2 = (int)SEQ_PTR(_5087);
        _label = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_label);

        // 			ix = find_label( gotos, {file, label})
        DeRef(_5087);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _file;
        ((int *)_2)[2] = _label;
        Ref(_label);
        _5087 = MAKE_SEQ(_1);
        Ref(_gotos);
        RefDS(_5087);
        _ix = _16find_label(_gotos, _5087);
        if (!IS_ATOM_INT(_ix)) {
            _1 = (long)(DBL_PTR(_ix)->dbl);
            DeRefDS(_ix);
            _ix = _1;
        }

        // 			if ix then
        if (_ix == 0)
            goto L8;

        // 				Code[pc]   = GOTO_STATIC
        _2 = (int)SEQ_PTR(_7Code);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7Code = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _pc);
        _1 = *(int *)_2;
        *(int *)_2 = 176;
        DeRef(_1);

        // 				Code[pc+1] = gotos[G_PC][ix]
        DeRefDS(_5087);
        _5087 = _pc + 1;
        if (_5087 > MAXINT)
            _5087 = NewDouble((double)_5087);
        DeRef(_5079);
        _2 = (int)SEQ_PTR(_gotos);
        _5079 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5079);
        _0 = _5079;
        _2 = (int)SEQ_PTR(_5079);
        _5079 = (int)*(((s1_ptr)_2)->base + _ix);
        Ref(_5079);
        DeRef(_0);
        Ref(_5079);
        _2 = (int)SEQ_PTR(_7Code);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7Code = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_5087))
            _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5087)->dbl));
        else
            _2 = (int)(((s1_ptr)_2)->base + _5087);
        _1 = *(int *)_2;
        *(int *)_2 = _5079;
        DeRef(_1);

        // 				Code[pc+2] = CurrentSub
        DeRef(_5079);
        _5079 = _pc + 2;
        _2 = (int)SEQ_PTR(_7Code);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7Code = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _5079);
        _1 = *(int *)_2;
        *(int *)_2 = _7CurrentSub;
        DeRef(_1);
L8:
L6:

        // 	end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    // 	goto_back_patch = goto_back_patch[1..$-1]
    DeRef(_5079);
    _5079 = SEQ_PTR(_7goto_back_patch)->length;
    _5079 = _5079 - 1;
    rhs_slice_target = (object_ptr)&_7goto_back_patch;
    RHS_Slice((s1_ptr)_7goto_back_patch, 1, _5079);

    // end procedure
    DeRef(_patch_list);
    DeRef(_label);
    DeRef(_gotos);
    DeRef(_5087);
    DeRef(_5088);
    return 0;
    ;
}


