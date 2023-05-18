// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17opRETURNP()
{
    int _sub;
    int _arg;
    int _top;
    int _base;
    int _by_ref = 0;
    int _arg_ref = 0;
    int _7457 = 0;
    int _7451 = 0;
    int _7456 = 0;
    int _0, _1, _2, _3;
    

    // 	sub = Code[pc+1]
    _7451 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _sub = (int)*(((s1_ptr)_2)->base + _7451);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	arg = SymTab[sub][S_NEXT]
    _2 = (int)SEQ_PTR(_7SymTab);
    _7451 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7451);
    _2 = (int)SEQ_PTR(_7451);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	SymTab[sub][S_ACTIVE] -= 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _7457 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_7457);
    _0 = _7457;
    if (IS_ATOM_INT(_7457)) {
        _7457 = _7457 - 1;
        if ((long)((unsigned long)_7457 +(unsigned long) HIGH_BITS) >= 0)
            _7457 = NewDouble((double)_7457);
    }
    else {
        _7457 = binary_op(MINUS, _7457, 1);
    }
    DeRef(_0);
    Ref(_7457);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _7457;
    DeRef(_1);

    // 	top = call_stack[$-2]
    DeRef(_7457);
    _7457 = SEQ_PTR(_17call_stack)->length;
    _7457 = _7457 - 2;
    _2 = (int)SEQ_PTR(_17call_stack);
    _top = (int)*(((s1_ptr)_2)->base + _7457);
    if (!IS_ATOM_INT(_top))
        _top = (long)DBL_PTR(_top)->dbl;

    // 	pass_by_reference( sub )
    _17pass_by_reference(_sub);

    // 	if SymTab[sub][S_ACTIVE] > 0 then
    _2 = (int)SEQ_PTR(_7SymTab);
    _7457 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7457);
    _0 = _7457;
    _2 = (int)SEQ_PTR(_7457);
    _7457 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_7457);
    DeRef(_0);
    if (binary_op_a(LESSEQ, _7457, 0))
        goto L1;

    // 		base = top+1
    _base = _top + 1;

    // 		while arg and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L2:
    if (_arg == 0) {
        goto L3;
    }
    DeRef(_7456);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7456 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7456);
    _0 = _7456;
    _2 = (int)SEQ_PTR(_7456);
    _7456 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_7456);
    DeRef(_0);
    _0 = _7456;
    if (IS_ATOM_INT(_7456)) {
        _7456 = (_7456 <= 3);
    }
    else {
        _7456 = binary_op(LESSEQ, _7456, 3);
    }
    DeRef(_0);
L4:
    if (_7456 <= 0) {
        if (_7456 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_7456) && DBL_PTR(_7456)->dbl == 0.0)
                goto L3;
        }
    }

    // 		    val[arg] = call_stack[base]
    DeRef(_7456);
    _2 = (int)SEQ_PTR(_17call_stack);
    _7456 = (int)*(((s1_ptr)_2)->base + _base);
    Ref(_7456);
    Ref(_7456);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _7456;
    DeRef(_1);

    // 		    base += 1
    _base = _base + 1;

    // 		    arg = SymTab[arg][S_NEXT]
    DeRef(_7456);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7456 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7456);
    _2 = (int)SEQ_PTR(_7456);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto L2;
L3:

    // 		arg = SymTab[sub][S_TEMPS]
    DeRef(_7456);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7456 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7456);
    _2 = (int)SEQ_PTR(_7456);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		while arg != 0 do
L5:
    if (_arg == 0)
        goto L6;

    // 		    val[arg] = call_stack[base]
    DeRef(_7456);
    _2 = (int)SEQ_PTR(_17call_stack);
    _7456 = (int)*(((s1_ptr)_2)->base + _base);
    Ref(_7456);
    Ref(_7456);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _7456;
    DeRef(_1);

    // 		    base += 1
    _base = _base + 1;

    // 		    arg = SymTab[arg][S_NEXT]
    DeRef(_7456);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7456 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7456);
    _2 = (int)SEQ_PTR(_7456);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto L5;
L6:

    // 		SymTab[sub][S_GOTO][G_DEFAULT] = call_stack[base]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(object_ptr)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(object_ptr)_3 = MAKE_SEQ(_2);
    }
    _3 = (int)(24 + ((s1_ptr)_2)->base);
    DeRef(_7451);
    _2 = (int)SEQ_PTR(_17call_stack);
    _7451 = (int)*(((s1_ptr)_2)->base + _base);
    Ref(_7451);
    Ref(_7451);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = _7451;
    DeRef(_1);

    // 		base += 1
    _base = _base + 1;
    goto L7;
L1:

    // 		while arg and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L8:
    if (_arg == 0) {
        goto L9;
    }
    DeRef(_7457);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7457 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7457);
    _0 = _7457;
    _2 = (int)SEQ_PTR(_7457);
    _7457 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_7457);
    DeRef(_0);
    _0 = _7457;
    if (IS_ATOM_INT(_7457)) {
        _7457 = (_7457 <= 3);
    }
    else {
        _7457 = binary_op(LESSEQ, _7457, 3);
    }
    DeRef(_0);
LA:
    if (_7457 <= 0) {
        if (_7457 == 0) {
            goto L9;
        }
        else {
            if (!IS_ATOM_INT(_7457) && DBL_PTR(_7457)->dbl == 0.0)
                goto L9;
        }
    }

    // 		    val[arg] = NOVALUE
    RefDS(_7NOVALUE);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _7NOVALUE;
    DeRef(_1);

    // 		    arg = SymTab[arg][S_NEXT]
    DeRef(_7457);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7457 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7457);
    _2 = (int)SEQ_PTR(_7457);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto L8;
L9:
L7:

    // 	pc = call_stack[$-1]
    DeRef(_7457);
    _7457 = SEQ_PTR(_17call_stack)->length;
    _7457 = _7457 - 1;
    _2 = (int)SEQ_PTR(_17call_stack);
    _17pc = (int)*(((s1_ptr)_2)->base + _7457);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;

    // 	call_stack = call_stack[1..top]
    rhs_slice_target = (object_ptr)&_17call_stack;
    RHS_Slice((s1_ptr)_17call_stack, 1, _top);

    // 	Code = SymTab[call_stack[$]][S_CODE]
    _7457 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _7457 = (int)*(((s1_ptr)_2)->base + _7457);
    Ref(_7457);
    _0 = _7457;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_7457))
        _7457 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7457)->dbl));
    else
        _7457 = (int)*(((s1_ptr)_2)->base + _7457);
    Ref(_7457);
    DeRef(_0);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_7457);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	if result then
    if (_17result == 0)
        goto LB;

    // 	val[Code[result]] = result_val
    DeRef(_7457);
    _2 = (int)SEQ_PTR(_7Code);
    _7457 = (int)*(((s1_ptr)_2)->base + _17result);
    Ref(_7457);
    Ref(_17result_val);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7457))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7457)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _7457);
    _1 = *(int *)_2;
    *(int *)_2 = _17result_val;
    DeRef(_1);

    // 	result = 0
    _17result = 0;
LB:

    // end procedure
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRef(_7457);
    DeRef(_7451);
    DeRef(_7456);
    return 0;
    ;
}


int _17opRETURNF()
{
    int _7500 = 0;
    int _0, _1, _2;
    

    // 	result_val = val[Code[pc+2]]
    _7500 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _7500 = (int)*(((s1_ptr)_2)->base + _7500);
    Ref(_7500);
    DeRef(_17result_val);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_7500))
        _17result_val = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7500)->dbl));
    else
        _17result_val = (int)*(((s1_ptr)_2)->base + _7500);
    Ref(_17result_val);

    // 	result = call_stack[$-1] - 1
    DeRef(_7500);
    _7500 = SEQ_PTR(_17call_stack)->length;
    _7500 = _7500 - 1;
    _2 = (int)SEQ_PTR(_17call_stack);
    _7500 = (int)*(((s1_ptr)_2)->base + _7500);
    Ref(_7500);
    if (IS_ATOM_INT(_7500)) {
        _17result = _7500 - 1;
    }
    else {
        _17result = binary_op(MINUS, _7500, 1);
    }
    if (!IS_ATOM_INT(_17result)) {
        _1 = (long)(DBL_PTR(_17result)->dbl);
        DeRefDS(_17result);
        _17result = _1;
    }

    // 	opRETURNP()
    _17opRETURNP();

    // end procedure
    DeRef(_7500);
    return 0;
    ;
}


int _17opCALL_BACK_RETURN()
{
    int _0, _1, _2;
    

    // 	keep_running = FALSE  
    _17keep_running = 0;

    // end procedure
    return 0;
    ;
}


int _17opBADRETURNF()
{
    int _0, _1, _2;
    

    // 	RTFatal("attempt to exit a function without returning a value")  
    RefDS(_7507);
    _17RTFatal(_7507);

    // 	return
    return 0;

    // end procedure
    return 0;
    ;
}


int _17opRETURNT()
{
    int _7508;
    int _0, _1, _2;
    

    // 	pc += 1
    _17pc = _17pc + 1;

    // 	if pc > length(Code) then
    _7508 = SEQ_PTR(_7Code)->length;
    if (_17pc <= _7508)
        goto L1;

    // 	keep_running = FALSE  -- we've reached the end of the code
    _17keep_running = 0;
L1:

    // end procedure
    return 0;
    ;
}


int _17opRHS_SUBS()
{
    int _sub = 0;
    int _x = 0;
    int _7525 = 0;
    int _7511 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7511 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7511);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _7511 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7511);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _7511 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7511);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	x = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	sub = val[b]
    _2 = (int)SEQ_PTR(_17val);
    _sub = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_sub);

    // 	if atom(x) then
    _7511 = IS_ATOM(_x);
    if (_7511 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(reading from it)")
    RefDS(_7520);
    _17RTFatal(_7520);

    // 	return
    DeRef(_sub);
    DeRef(_x);
    return 0;
L1:

    // 	if sequence(sub) then
    DeRef(_7511);
    _7511 = IS_SEQUENCE(_sub);
    if (_7511 == 0)
        goto L2;

    // 	RTFatal("subscript must be an atom\n(reading an element of a sequence)")
    RefDS(_7522);
    _17RTFatal(_7522);

    // 	return
    DeRef(_sub);
    DeRef(_x);
    DeRef(_7525);
    return 0;
L2:

    // 	if sub < 1 or sub > length(x) then
    DeRef(_7511);
    if (IS_ATOM_INT(_sub)) {
        _7511 = (_sub < 1);
    }
    else {
        _7511 = binary_op(LESS, _sub, 1);
    }
    if (IS_ATOM_INT(_7511)) {
        if (_7511 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_7511)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef(_7525);
    _7525 = SEQ_PTR(_x)->length;
    if (IS_ATOM_INT(_sub)) {
        _7525 = (_sub > _7525);
    }
    else {
        _7525 = binary_op(GREATER, _sub, _7525);
    }
L4:
    if (_7525 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_7525) && DBL_PTR(_7525)->dbl == 0.0)
            goto L5;
    }
L3:

    // 	RTFatal(
    DeRef(_7525);
    _7525 = SEQ_PTR(_x)->length;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _sub;
    Ref(_sub);
    ((int *)_2)[2] = _7525;
    _7525 = MAKE_SEQ(_1);
    _0 = _7525;
    _7525 = EPrintf(-9999999, _7527, _7525);
    DeRefDS(_0);
    RefDS(_7525);
    _17RTFatal(_7525);

    // 	return
    DeRef(_sub);
    DeRef(_x);
    DeRefDSi(_7525);
    DeRef(_7511);
    return 0;
L5:

    // 	val[target] = x[sub]
    DeRef(_7525);
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_sub))
        _7525 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_sub)->dbl));
    else
        _7525 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7525);
    Ref(_7525);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7525;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_sub);
    DeRef(_x);
    DeRef(_7525);
    DeRef(_7511);
    return 0;
    ;
}


int _17opIF()
{
    int _7533 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7533 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7533);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_17val);
    _7533 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7533);
    if (binary_op_a(NOTEQ, _7533, 0))
        goto L1;

    // 	pc = Code[pc+2]
    DeRef(_7533);
    _7533 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _7533);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
    goto L2;
L1:

    // 	pc += 3
    _17pc = _17pc + 3;
L2:

    // end procedure
    DeRef(_7533);
    return 0;
    ;
}


int _17opINTEGER_CHECK()
{
    int _7540 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7540 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7540);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if not integer(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _7540 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7540);
    _0 = _7540;
    if (IS_ATOM_INT(_7540))
        _7540 = 1;
    else if (IS_ATOM_DBL(_7540))
        _7540 = IS_ATOM_INT(DoubleToInt(_7540));
    else
        _7540 = 0;
    DeRef(_0);
    if (_7540 != 0)
        goto L1;

    // 	RTFatalType(pc+1)
    _7540 = _17pc + 1;
    if (_7540 > MAXINT)
        _7540 = NewDouble((double)_7540);
    Ref(_7540);
    _17RTFatalType(_7540);

    // 	return
    DeRef(_7540);
    return 0;
L1:

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_7540);
    return 0;
    ;
}


int _17opATOM_CHECK()
{
    int _7547 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7547 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7547);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if not atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _7547 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7547);
    _0 = _7547;
    _7547 = IS_ATOM(_7547);
    DeRef(_0);
    if (_7547 != 0)
        goto L1;

    // 	RTFatalType(pc+1)
    _7547 = _17pc + 1;
    if (_7547 > MAXINT)
        _7547 = NewDouble((double)_7547);
    Ref(_7547);
    _17RTFatalType(_7547);

    // 	return
    DeRef(_7547);
    return 0;
L1:

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_7547);
    return 0;
    ;
}


int _17opSEQUENCE_CHECK()
{
    int _7554 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7554 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7554);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if not sequence(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _7554 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7554);
    _0 = _7554;
    _7554 = IS_SEQUENCE(_7554);
    DeRef(_0);
    if (_7554 != 0)
        goto L1;

    // 	RTFatalType(pc+1)
    _7554 = _17pc + 1;
    if (_7554 > MAXINT)
        _7554 = NewDouble((double)_7554);
    Ref(_7554);
    _17RTFatalType(_7554);

    // 	return
    DeRef(_7554);
    return 0;
L1:

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_7554);
    return 0;
    ;
}


int _17opASSIGN()
{
    int _7561 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7561 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7561);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7561 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7561);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _7561 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7561);
    Ref(_7561);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7561;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7561);
    return 0;
    ;
}


int _17opELSE()
{
    int _7567;
    int _0, _1, _2;
    

    // 	pc = Code[pc+1]
    _7567 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _7567);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;

    // end procedure
    return 0;
    ;
}


int _17opRIGHT_BRACE()
{
    int _x = 0;
    int _7569 = 0;
    int _7573 = 0;
    int _0, _1, _2;
    

    // 	len = Code[pc+1]
    _7569 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17len = (int)*(((s1_ptr)_2)->base + _7569);
    if (!IS_ATOM_INT(_17len))
        _17len = (long)DBL_PTR(_17len)->dbl;

    // 	x = {}
    RefDS(_39);
    _x = _39;

    // 	for i = pc+len+1 to pc+2 by -1 do
    _7569 = _17pc + _17len;
    if ((long)((unsigned long)_7569 + (unsigned long)HIGH_BITS) >= 0) 
        _7569 = NewDouble((double)_7569);
    _0 = _7569;
    if (IS_ATOM_INT(_7569)) {
        _7569 = _7569 + 1;
        if (_7569 > MAXINT)
            _7569 = NewDouble((double)_7569);
    }
    else
        _7569 = binary_op(PLUS, 1, _7569);
    DeRef(_0);
    _7573 = _17pc + 2;
    if ((long)((unsigned long)_7573 + (unsigned long)HIGH_BITS) >= 0) 
        _7573 = NewDouble((double)_7573);
    { int _i;
        Ref(_7569);
        _i = _7569;
L1:
        if (binary_op_a(LESS, _i, _7573))
            goto L2;

        // 	x = append(x, val[Code[i]])
        DeRef(_7569);
        _2 = (int)SEQ_PTR(_7Code);
        if (!IS_ATOM_INT(_i))
            _7569 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _7569 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7569);
        _0 = _7569;
        _2 = (int)SEQ_PTR(_17val);
        if (!IS_ATOM_INT(_7569))
            _7569 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7569)->dbl));
        else
            _7569 = (int)*(((s1_ptr)_2)->base + _7569);
        Ref(_7569);
        DeRef(_0);
        Ref(_7569);
        Append(&_x, _x, _7569);

        // 	end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + -1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, -1);
        }
        DeRef(_0);
        goto L1;
L2:
        ;
        DeRef(_i);
    }

    // 	target = Code[pc+len+2]
    DeRef(_7569);
    _7569 = _17pc + _17len;
    if ((long)((unsigned long)_7569 + (unsigned long)HIGH_BITS) >= 0) 
        _7569 = NewDouble((double)_7569);
    _0 = _7569;
    if (IS_ATOM_INT(_7569)) {
        _7569 = _7569 + 2;
    }
    else {
        _7569 = NewDouble(DBL_PTR(_7569)->dbl + (double)2);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_7Code);
    if (!IS_ATOM_INT(_7569))
        _17target = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7569)->dbl));
    else
        _17target = (int)*(((s1_ptr)_2)->base + _7569);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = x
    RefDS(_x);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _x;
    DeRef(_1);

    // 	pc += 3 + len
    DeRef(_7569);
    _7569 = 3 + _17len;
    if ((long)((unsigned long)_7569 + (unsigned long)HIGH_BITS) >= 0) 
        _7569 = NewDouble((double)_7569);
    if (IS_ATOM_INT(_7569)) {
        _17pc = _17pc + _7569;
    }
    else {
        _17pc = NewDouble((double)_17pc + DBL_PTR(_7569)->dbl);
    }
    if (!IS_ATOM_INT(_17pc)) {
        _1 = (long)(DBL_PTR(_17pc)->dbl);
        DeRefDS(_17pc);
        _17pc = _1;
    }

    // end procedure
    DeRefDS(_x);
    DeRef(_7569);
    DeRef(_7573);
    return 0;
    ;
}


int _17opRIGHT_BRACE_2()
{
    int _7587 = 0;
    int _7582 = 0;
    int _0, _1, _2;
    

    // 	target = Code[pc+3]
    _7582 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7582);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = {val[Code[pc+2]], val[Code[pc+1]]}
    _7582 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _7582 = (int)*(((s1_ptr)_2)->base + _7582);
    Ref(_7582);
    _0 = _7582;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_7582))
        _7582 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7582)->dbl));
    else
        _7582 = (int)*(((s1_ptr)_2)->base + _7582);
    Ref(_7582);
    DeRef(_0);
    _7587 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _7587 = (int)*(((s1_ptr)_2)->base + _7587);
    Ref(_7587);
    _0 = _7587;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_7587))
        _7587 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7587)->dbl));
    else
        _7587 = (int)*(((s1_ptr)_2)->base + _7587);
    Ref(_7587);
    DeRef(_0);
    _0 = _7587;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7582;
    Ref(_7582);
    ((int *)_2)[2] = _7587;
    Ref(_7587);
    _7587 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7587);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7587;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDS(_7587);
    DeRef(_7582);
    return 0;
    ;
}


int _17opPLUS1()
{
    int _7592 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7592 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7592);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+3] 
    _7592 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7592);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] + 1
    _2 = (int)SEQ_PTR(_17val);
    _7592 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7592);
    _0 = _7592;
    if (IS_ATOM_INT(_7592)) {
        _7592 = _7592 + 1;
        if (_7592 > MAXINT)
            _7592 = NewDouble((double)_7592);
    }
    else
        _7592 = binary_op(PLUS, 1, _7592);
    DeRef(_0);
    Ref(_7592);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7592;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_7592);
    return 0;
    ;
}


int _17opGLOBAL_INIT_CHECK()
{
    int _7599 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7599 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7599);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if equal(val[a], NOVALUE) then
    _2 = (int)SEQ_PTR(_17val);
    _7599 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7599);
    _0 = _7599;
    if (_7599 == _7NOVALUE)
        _7599 = 1;
    else if (IS_ATOM_INT(_7599) && IS_ATOM_INT(_7NOVALUE))
        _7599 = 0;
    else
        _7599 = (compare(_7599, _7NOVALUE) == 0);
    DeRef(_0);
    if (_7599 == 0)
        goto L1;

    // 	RTFatal("not initialized") -- ??
    RefDS(_7603);
    _17RTFatal(_7603);

    // 	return
    return 0;
L1:

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_7599);
    return 0;
    ;
}


int _17opWHILE()
{
    int _7605 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7605 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7605);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_17val);
    _7605 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7605);
    if (binary_op_a(NOTEQ, _7605, 0))
        goto L1;

    // 	pc = Code[pc+2]
    DeRef(_7605);
    _7605 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _7605);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
    goto L2;
L1:

    // 	pc += 3
    _17pc = _17pc + 3;
L2:

    // end procedure
    DeRef(_7605);
    return 0;
    ;
}


int _17var_subs(int _x, int _subs)
{
    int _7615 = 0;
    int _7614 = 0;
    int _7612;
    int _0, _1, _2;
    

    // 	if atom(x) then
    _7612 = IS_ATOM(_x);
    if (_7612 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(reading from it)")
    RefDS(_7520);
    _17RTFatal(_7520);

    // 	return 0
    DeRef(_x);
    DeRefDS(_subs);
    return 0;
L1:

    // 	for i = 1 to length(subs) do
    _7612 = SEQ_PTR(_subs)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _7612)
            goto L3;

        // 	if subs[i] > length(x) or subs[i] < 1 then
        DeRef(_7614);
        _2 = (int)SEQ_PTR(_subs);
        _7614 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7614);
        DeRef(_7615);
        _7615 = SEQ_PTR(_x)->length;
        if (IS_ATOM_INT(_7614)) {
            _7615 = (_7614 > _7615);
        }
        else {
            _7615 = binary_op(GREATER, _7614, _7615);
        }
        if (IS_ATOM_INT(_7615)) {
            if (_7615 != 0) {
                goto L4;
            }
        }
        else {
            if (DBL_PTR(_7615)->dbl != 0.0) {
                goto L4;
            }
        }
        DeRef(_7614);
        _2 = (int)SEQ_PTR(_subs);
        _7614 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7614);
        _0 = _7614;
        if (IS_ATOM_INT(_7614)) {
            _7614 = (_7614 < 1);
        }
        else {
            _7614 = binary_op(LESS, _7614, 1);
        }
        DeRef(_0);
L5:
        if (_7614 == 0) {
            goto L6;
        }
        else {
            if (!IS_ATOM_INT(_7614) && DBL_PTR(_7614)->dbl == 0.0)
                goto L6;
        }
L4:

        // 	    RTFatal(
        DeRef(_7614);
        _2 = (int)SEQ_PTR(_subs);
        _7614 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7614);
        DeRef(_7615);
        _7615 = SEQ_PTR(_x)->length;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _7614;
        Ref(_7614);
        ((int *)_2)[2] = _7615;
        _7615 = MAKE_SEQ(_1);
        _0 = _7615;
        _7615 = EPrintf(-9999999, _7527, _7615);
        DeRefDS(_0);
        RefDS(_7615);
        _17RTFatal(_7615);

        // 		return 0
        DeRef(_x);
        DeRefDS(_subs);
        DeRefDSi(_7615);
        DeRef(_7614);
        return 0;
L6:

        // 	x = x[subs[i]]
        DeRef(_7615);
        _2 = (int)SEQ_PTR(_subs);
        _7615 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7615);
        _0 = _x;
        _2 = (int)SEQ_PTR(_x);
        if (!IS_ATOM_INT(_7615))
            _x = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7615)->dbl));
        else
            _x = (int)*(((s1_ptr)_2)->base + _7615);
        Ref(_x);
        DeRef(_0);

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	return x
    DeRefDS(_subs);
    DeRef(_7615);
    DeRef(_7614);
    return _x;
    ;
}


int _17var_slice(int _x, int _subs, int _lower, int _upper)
{
    int _7629 = 0;
    int _7628 = 0;
    int _7626;
    int _0, _1, _2;
    

    // 	if atom(x) then
    _7626 = IS_ATOM(_x);
    if (_7626 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(reading from it)")
    RefDS(_7520);
    _17RTFatal(_7520);

    // 	return 0
    DeRef(_x);
    DeRefDS(_subs);
    DeRef(_lower);
    DeRef(_upper);
    return 0;
L1:

    // 	for i = 1 to length(subs) do
    _7626 = SEQ_PTR(_subs)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _7626)
            goto L3;

        // 	if subs[i] > length(x) or subs[i] < 1 then
        DeRef(_7628);
        _2 = (int)SEQ_PTR(_subs);
        _7628 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7628);
        DeRef(_7629);
        _7629 = SEQ_PTR(_x)->length;
        if (IS_ATOM_INT(_7628)) {
            _7629 = (_7628 > _7629);
        }
        else {
            _7629 = binary_op(GREATER, _7628, _7629);
        }
        if (IS_ATOM_INT(_7629)) {
            if (_7629 != 0) {
                goto L4;
            }
        }
        else {
            if (DBL_PTR(_7629)->dbl != 0.0) {
                goto L4;
            }
        }
        DeRef(_7628);
        _2 = (int)SEQ_PTR(_subs);
        _7628 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7628);
        _0 = _7628;
        if (IS_ATOM_INT(_7628)) {
            _7628 = (_7628 < 1);
        }
        else {
            _7628 = binary_op(LESS, _7628, 1);
        }
        DeRef(_0);
L5:
        if (_7628 == 0) {
            goto L6;
        }
        else {
            if (!IS_ATOM_INT(_7628) && DBL_PTR(_7628)->dbl == 0.0)
                goto L6;
        }
L4:

        // 	    RTFatal(
        DeRef(_7628);
        _2 = (int)SEQ_PTR(_subs);
        _7628 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7628);
        DeRef(_7629);
        _7629 = SEQ_PTR(_x)->length;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _7628;
        Ref(_7628);
        ((int *)_2)[2] = _7629;
        _7629 = MAKE_SEQ(_1);
        _0 = _7629;
        _7629 = EPrintf(-9999999, _7527, _7629);
        DeRefDS(_0);
        RefDS(_7629);
        _17RTFatal(_7629);

        // 		return 0
        DeRef(_x);
        DeRefDS(_subs);
        DeRef(_lower);
        DeRef(_upper);
        DeRefDSi(_7629);
        DeRef(_7628);
        return 0;
L6:

        // 	x = x[subs[i]] 
        DeRef(_7629);
        _2 = (int)SEQ_PTR(_subs);
        _7629 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7629);
        _0 = _x;
        _2 = (int)SEQ_PTR(_x);
        if (!IS_ATOM_INT(_7629))
            _x = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7629)->dbl));
        else
            _x = (int)*(((s1_ptr)_2)->base + _7629);
        Ref(_x);
        DeRef(_0);

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	return x[lower..upper]
    rhs_slice_target = (object_ptr)&_7629;
    RHS_Slice((s1_ptr)_x, _lower, _upper);
    DeRef(_x);
    DeRefDS(_subs);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_7628);
    return _7629;
    ;
}


int _17opLENGTH()
{
    int _x = 0;
    int _7641 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7641 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7641);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7641 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7641);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _7641 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7641);
    _0 = _7641;
    _7641 = IS_ATOM(_7641);
    DeRef(_0);
    if (_7641 == 0)
        goto L1;

    // x = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	RTFatal("length of an atom is not defined")
    RefDS(_7648);
    _17RTFatal(_7648);

    // 	return
    DeRef(_x);
    return 0;
L1:

    // 	val[target] = length(val[a])
    DeRef(_7641);
    _2 = (int)SEQ_PTR(_17val);
    _7641 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7641);
    _0 = _7641;
    _7641 = SEQ_PTR(_7641)->length;
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7641;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_x);
    return 0;
    ;
}


int _17opPLENGTH()
{
    int _7659 = 0;
    int _7652 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7652 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7652);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7652 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7652);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_17val);
    _7652 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7652);
    _2 = (int)SEQ_PTR(_7652);
    _17lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_17lhs_seq_index))
        _17lhs_seq_index = (long)DBL_PTR(_17lhs_seq_index)->dbl;

    // 	lhs_subs = val[a][2..$]
    DeRef(_7652);
    _2 = (int)SEQ_PTR(_17val);
    _7652 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7652);
    _7659 = SEQ_PTR(_7652)->length;
    rhs_slice_target = (object_ptr)&_17lhs_subs;
    RHS_Slice((s1_ptr)_7652, 2, _7659);

    // 	val[target] = length(var_subs(val[lhs_seq_index], lhs_subs))
    _2 = (int)SEQ_PTR(_17val);
    _7659 = (int)*(((s1_ptr)_2)->base + _17lhs_seq_index);
    Ref(_7659);
    Ref(_7659);
    RefDS(_17lhs_subs);
    _0 = _7659;
    _7659 = _17var_subs(_7659, _17lhs_subs);
    DeRef(_0);
    _0 = _7659;
    _7659 = SEQ_PTR(_7659)->length;
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7659;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7652);
    return 0;
    ;
}


int _17opLHS_SUBS()
{
    int _7672 = 0;
    int _7665 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1] -- base var sequence, or a temp that contains
    _7665 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7665);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2] -- subscript
    _7665 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7665);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3] -- temp for storing result
    _7665 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7665);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = append(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _7665 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7665);
    _2 = (int)SEQ_PTR(_17val);
    _7672 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7672);
    Ref(_7672);
    Append(&_7672, _7665, _7672);
    RefDS(_7672);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7672;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRefDS(_7672);
    DeRef(_7665);
    return 0;
    ;
}


int _17opLHS_SUBS1()
{
    int _7675 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1] -- base var sequence, or a temp that contains
    _7675 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7675);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2] -- subscript
    _7675 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7675);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3] -- temp for storing result
    _7675 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7675);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = {a, val[b]}
    _2 = (int)SEQ_PTR(_17val);
    _7675 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7675);
    _0 = _7675;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _17a;
    ((int *)_2)[2] = _7675;
    Ref(_7675);
    _7675 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7675);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7675;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRefDS(_7675);
    return 0;
    ;
}


int _17opLHS_SUBS1_COPY()
{
    int _7684 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1] -- base var sequence
    _7684 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7684);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2] -- subscript
    _7684 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7684);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3] -- temp for storing result
    _7684 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7684);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	c = Code[pc+4] -- temp to hold base sequence while it's manipulated
    _7684 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7684);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	val[c] = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _7684 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7684);
    Ref(_7684);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17c);
    _1 = *(int *)_2;
    *(int *)_2 = _7684;
    DeRef(_1);

    // 	val[target] = {c, val[b]}
    DeRef(_7684);
    _2 = (int)SEQ_PTR(_17val);
    _7684 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7684);
    _0 = _7684;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _17c;
    ((int *)_2)[2] = _7684;
    Ref(_7684);
    _7684 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7684);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7684;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRefDS(_7684);
    return 0;
    ;
}


int _17lhs_check_subs(int _seq, int _subs)
{
    int _7704 = 0;
    int _7696 = 0;
    int _0, _1, _2;
    

    // 	if atom(seq) then
    _7696 = IS_ATOM(_seq);
    if (_7696 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(assigning to it)")
    RefDS(_7697);
    _17RTFatal(_7697);

    // 	return
    DeRef(_seq);
    DeRef(_subs);
    return 0;
L1:

    // 	if sequence(subs) then
    DeRef(_7696);
    _7696 = IS_SEQUENCE(_subs);
    if (_7696 == 0)
        goto L2;

    // 	RTFatal(
    _7696 = SEQ_PTR(_seq)->length;
    _7696 = EPrintf(-9999999, _7699, _7696);
    RefDS(_7696);
    _17RTFatal(_7696);

    // 	return
    DeRef(_seq);
    DeRef(_subs);
    DeRefDSi(_7696);
    DeRef(_7704);
    return 0;
L2:

    // 	if subs < 1 or subs > length(seq) then
    DeRef(_7696);
    if (IS_ATOM_INT(_subs)) {
        _7696 = (_subs < 1);
    }
    else {
        _7696 = binary_op(LESS, _subs, 1);
    }
    if (IS_ATOM_INT(_7696)) {
        if (_7696 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_7696)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef(_7704);
    _7704 = SEQ_PTR(_seq)->length;
    if (IS_ATOM_INT(_subs)) {
        _7704 = (_subs > _7704);
    }
    else {
        _7704 = binary_op(GREATER, _subs, _7704);
    }
L4:
    if (_7704 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_7704) && DBL_PTR(_7704)->dbl == 0.0)
            goto L5;
    }
L3:

    // 	RTFatal(
    DeRef(_7704);
    _7704 = SEQ_PTR(_seq)->length;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _subs;
    Ref(_subs);
    ((int *)_2)[2] = _7704;
    _7704 = MAKE_SEQ(_1);
    _0 = _7704;
    _7704 = EPrintf(-9999999, _7706, _7704);
    DeRefDS(_0);
    RefDS(_7704);
    _17RTFatal(_7704);

    // 	return
    DeRef(_seq);
    DeRef(_subs);
    DeRefDSi(_7704);
    DeRef(_7696);
    return 0;
L5:

    // end procedure
    DeRef(_seq);
    DeRef(_subs);
    DeRef(_7704);
    DeRef(_7696);
    return 0;
    ;
}


int _17lhs_check_slice(int _seq, int _lower, int _upper, int _rhs)
{
    int _len = 0;
    int _7735 = 0;
    int _7710 = 0;
    int _7724 = 0;
    int _0, _1, _2;
    

    // 	if sequence(lower) then
    _7710 = IS_SEQUENCE(_lower);
    if (_7710 == 0)
        goto L1;

    // 	RTFatal("slice lower index is not an atom")
    RefDS(_7711);
    _17RTFatal(_7711);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    return 0;
L1:

    // 	if lower < 1 then
    if (binary_op_a(GREATEREQ, _lower, 1))
        goto L2;

    // 	RTFatal("slice lower index is less than 1")
    RefDS(_7713);
    _17RTFatal(_7713);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
L2:

    // 	if sequence(upper) then
    DeRef(_7710);
    _7710 = IS_SEQUENCE(_upper);
    if (_7710 == 0)
        goto L3;

    // 	RTFatal("slice upper index is not an atom")
    RefDS(_7715);
    _17RTFatal(_7715);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7724);
    return 0;
L3:

    // 	if upper < 0 then
    if (binary_op_a(GREATEREQ, _upper, 0))
        goto L4;

    // 	RTFatal("slice upper index is less than 0")
    RefDS(_7717);
    _17RTFatal(_7717);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
L4:

    // 	len = upper - lower + 1
    DeRef(_7710);
    if (IS_ATOM_INT(_upper) && IS_ATOM_INT(_lower)) {
        _7710 = _upper - _lower;
        if ((long)((unsigned long)_7710 +(unsigned long) HIGH_BITS) >= 0)
            _7710 = NewDouble((double)_7710);
    }
    else {
        _7710 = binary_op(MINUS, _upper, _lower);
    }
    DeRef(_len);
    if (IS_ATOM_INT(_7710)) {
        _len = _7710 + 1;
        if (_len > MAXINT)
            _len = NewDouble((double)_len);
    }
    else
        _len = binary_op(PLUS, 1, _7710);

    // 	if len < 0 then
    if (binary_op_a(GREATEREQ, _len, 0))
        goto L5;

    // 	RTFatal("slice length is less than 0")
    RefDS(_7721);
    _17RTFatal(_7721);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
L5:

    // 	if sequence(rhs) and length(rhs) != len then
    DeRef(_7710);
    _7710 = IS_SEQUENCE(_rhs);
    if (_7710 == 0) {
        goto L6;
    }
    DeRef(_7724);
    _7724 = SEQ_PTR(_rhs)->length;
    if (IS_ATOM_INT(_len)) {
        _7724 = (_7724 != _len);
    }
    else {
        _7724 = ((double)_7724 != DBL_PTR(_len)->dbl);
    }
L7:
    if (_7724 == 0)
        goto L6;

    // 	RTFatal("lengths do not match on assignment to slice")
    RefDS(_7726);
    _17RTFatal(_7726);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
L6:

    // 	if atom(seq) then
    DeRef(_7724);
    _7724 = IS_ATOM(_seq);
    if (_7724 == 0)
        goto L8;

    // 	RTFatal("attempt to slice an atom")
    RefDS(_7728);
    _17RTFatal(_7728);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    return 0;
L8:

    // 	if lower > length(seq) + 1 or (len > 0 and lower > length(seq)) then
    DeRef(_7724);
    _7724 = SEQ_PTR(_seq)->length;
    _7724 = _7724 + 1;
    if (IS_ATOM_INT(_lower)) {
        _7724 = (_lower > _7724);
    }
    else {
        _7724 = binary_op(GREATER, _lower, _7724);
    }
    if (IS_ATOM_INT(_7724)) {
        if (_7724 != 0) {
            goto L9;
        }
    }
    else {
        if (DBL_PTR(_7724)->dbl != 0.0) {
            goto L9;
        }
    }
    DeRef(_7710);
    if (IS_ATOM_INT(_len)) {
        _7710 = (_len > 0);
    }
    else {
        _7710 = (DBL_PTR(_len)->dbl > (double)0);
    }
    if (_7710 == 0) {
        _7710 = 0;
        goto LA;
    }
    DeRef(_7735);
    _7735 = SEQ_PTR(_seq)->length;
    if (IS_ATOM_INT(_lower)) {
        _7735 = (_lower > _7735);
    }
    else {
        _7735 = binary_op(GREATER, _lower, _7735);
    }
    if (IS_ATOM_INT(_7735))
        _7710 = (_7735 != 0);
    else
        _7710 = DBL_PTR(_7735)->dbl != 0.0;
LA:
LB:
    if (_7710 == 0)
        goto LC;
L9:

    // 	RTFatal("slice starts past end of sequence")
    RefDS(_7737);
    _17RTFatal(_7737);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
LC:

    // 	if upper > length(seq) then
    DeRef(_7735);
    _7735 = SEQ_PTR(_seq)->length;
    if (binary_op_a(LESSEQ, _upper, _7735))
        goto LD;

    // 	RTFatal("slice ends past end of sequence")
    RefDS(_7740);
    _17RTFatal(_7740);

    // 	return
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
LD:

    // end procedure
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_7735);
    DeRef(_7710);
    DeRef(_7724);
    return 0;
    ;
}


int _17assign_subs(int _x, int _subs, int _rhs_val)
{
    int _7750 = 0;
    int _7748 = 0;
    int _7746 = 0;
    int _7741 = 0;
    int _0, _1, _2;
    

    // 	lhs_check_subs(x, subs[1])
    _2 = (int)SEQ_PTR(_subs);
    _7741 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7741);
    RefDS(_x);
    Ref(_7741);
    _17lhs_check_subs(_x, _7741);

    // 	if length(subs) = 1 then
    DeRef(_7741);
    _7741 = SEQ_PTR(_subs)->length;
    if (_7741 != 1)
        goto L1;

    // 	x[subs[1]] = rhs_val
    _2 = (int)SEQ_PTR(_subs);
    _7741 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7741);
    Ref(_rhs_val);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7741))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7741)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _7741);
    _1 = *(int *)_2;
    *(int *)_2 = _rhs_val;
    DeRef(_1);
    goto L2;
L1:

    // 	x[subs[1]] = assign_subs(x[subs[1]], subs[2..$], rhs_val)
    DeRef(_7741);
    _2 = (int)SEQ_PTR(_subs);
    _7741 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7741);
    DeRef(_7746);
    _2 = (int)SEQ_PTR(_subs);
    _7746 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7746);
    _0 = _7746;
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_7746))
        _7746 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7746)->dbl));
    else
        _7746 = (int)*(((s1_ptr)_2)->base + _7746);
    Ref(_7746);
    DeRef(_0);
    DeRef(_7748);
    _7748 = SEQ_PTR(_subs)->length;
    rhs_slice_target = (object_ptr)&_7748;
    RHS_Slice((s1_ptr)_subs, 2, _7748);
    Ref(_rhs_val);
    DeRef(_7750);
    _7750 = _rhs_val;
    Ref(_7746);
    RefDS(_7748);
    Ref(_7750);
    _0 = _7750;
    _7750 = _17assign_subs(_7746, _7748, _7750);
    DeRef(_0);
    RefDS(_7750);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7741))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7741)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _7741);
    _1 = *(int *)_2;
    *(int *)_2 = _7750;
    DeRef(_1);
L2:

    // 	return x
    DeRefDS(_subs);
    DeRef(_rhs_val);
    DeRef(_7750);
    DeRef(_7748);
    DeRef(_7746);
    DeRef(_7741);
    return _x;
    ;
}


int _17assign_slice(int _x, int _subs, int _lower, int _upper, int _rhs_val)
{
    int _7767 = 0;
    int _7766 = 0;
    int _7765 = 0;
    int _7763 = 0;
    int _7752 = 0;
    int _7759 = 0;
    int _0, _1, _2, _3;
    

    // 	lhs_check_subs(x, subs[1])
    _2 = (int)SEQ_PTR(_subs);
    _7752 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7752);
    RefDS(_x);
    Ref(_7752);
    _17lhs_check_subs(_x, _7752);

    // 	if length(subs) = 1 then
    DeRef(_7752);
    _7752 = SEQ_PTR(_subs)->length;
    if (_7752 != 1)
        goto L1;

    // 	lhs_check_slice(x[subs[1]],lower,upper,rhs_val)
    _2 = (int)SEQ_PTR(_subs);
    _7752 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7752);
    _0 = _7752;
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_7752))
        _7752 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7752)->dbl));
    else
        _7752 = (int)*(((s1_ptr)_2)->base + _7752);
    Ref(_7752);
    DeRef(_0);
    Ref(_7752);
    Ref(_lower);
    Ref(_upper);
    Ref(_rhs_val);
    _17lhs_check_slice(_7752, _lower, _upper, _rhs_val);

    // 	x[subs[1]][lower..upper] = rhs_val
    DeRef(_7752);
    _2 = (int)SEQ_PTR(_subs);
    _7752 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7752);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7752))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7752)->dbl));
    else
        _3 = (int)(_7752 + ((s1_ptr)_2)->base);
    assign_slice_seq = (s1_ptr *)_3;
    AssignSlice(_lower, _upper, _rhs_val);
    goto L2;
L1:

    // 	x[subs[1]] = assign_slice(x[subs[1]], subs[2..$], lower, upper, rhs_val)
    DeRef(_7759);
    _2 = (int)SEQ_PTR(_subs);
    _7759 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7759);
    DeRef(_7752);
    _2 = (int)SEQ_PTR(_subs);
    _7752 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7752);
    _0 = _7752;
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_7752))
        _7752 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7752)->dbl));
    else
        _7752 = (int)*(((s1_ptr)_2)->base + _7752);
    Ref(_7752);
    DeRef(_0);
    DeRef(_7763);
    _7763 = SEQ_PTR(_subs)->length;
    rhs_slice_target = (object_ptr)&_7763;
    RHS_Slice((s1_ptr)_subs, 2, _7763);
    Ref(_lower);
    DeRef(_7765);
    _7765 = _lower;
    Ref(_upper);
    DeRef(_7766);
    _7766 = _upper;
    Ref(_rhs_val);
    DeRef(_7767);
    _7767 = _rhs_val;
    Ref(_7752);
    RefDS(_7763);
    Ref(_7765);
    Ref(_7766);
    Ref(_7767);
    _0 = _7767;
    _7767 = _17assign_slice(_7752, _7763, _7765, _7766, _7767);
    DeRef(_0);
    RefDS(_7767);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7759))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7759)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _7759);
    _1 = *(int *)_2;
    *(int *)_2 = _7767;
    DeRef(_1);
L2:

    // 	return x
    DeRefDS(_subs);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs_val);
    DeRef5(_7767, _7766, _7765, _7763, _7752);
    DeRef(_7759);
    return _x;
    ;
}


int _17opASSIGN_SUBS()
{
    int _x = 0;
    int _subs = 0;
    int _7769 = 0;
    int _0, _1, _2, _3;
    

    // 	a = Code[pc+1]	-- the sequence
    _7769 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7769);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]	-- the subscript
    _7769 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7769);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if sequence(val[b]) then
    _2 = (int)SEQ_PTR(_17val);
    _7769 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7769);
    _0 = _7769;
    _7769 = IS_SEQUENCE(_7769);
    DeRef(_0);
    if (_7769 == 0)
        goto L1;

    // 	RTFatal("subscript must be an atom\n(assigning to subscript of a sequence)")
    RefDS(_7775);
    _17RTFatal(_7775);

    // 	return
    return 0;
L1:

    // 	c = Code[pc+3]	-- the RHS value
    DeRef(_7769);
    _7769 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7769);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	x = val[a] -- avoid lingering ref count on val[a]
    DeRef(_x);
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	lhs_check_subs(x, val[b])
    _2 = (int)SEQ_PTR(_17val);
    _7769 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7769);
    Ref(_x);
    Ref(_7769);
    _17lhs_check_subs(_x, _7769);

    // 	x = val[c]
    DeRef(_x);
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_x);

    // 	subs = val[b]
    DeRef(_subs);
    _2 = (int)SEQ_PTR(_17val);
    _subs = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_subs);

    // 	val[a][subs] = x  -- single LHS subscript
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _3 = (int)(_17a + ((s1_ptr)_2)->base);
    Ref(_x);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_subs))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_subs)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _subs);
    _1 = *(int *)_2;
    *(int *)_2 = _x;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_x);
    DeRef(_subs);
    DeRef(_7769);
    return 0;
    ;
}


int _17opPASSIGN_SUBS()
{
    int _7801 = 0;
    int _7785 = 0;
    int _7796 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7785 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7785);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]	-- subscript
    _7785 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7785);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if sequence(val[b]) then
    _2 = (int)SEQ_PTR(_17val);
    _7785 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7785);
    _0 = _7785;
    _7785 = IS_SEQUENCE(_7785);
    DeRef(_0);
    if (_7785 == 0)
        goto L1;

    // 	RTFatal("subscript must be an atom\n(assigning to subscript of a sequence)")        
    RefDS(_7775);
    _17RTFatal(_7775);

    // 	return
    return 0;
L1:

    // 	c = Code[pc+3]	-- RHS value
    DeRef(_7785);
    _7785 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7785);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_17val);
    _7785 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7785);
    _2 = (int)SEQ_PTR(_7785);
    _17lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_17lhs_seq_index))
        _17lhs_seq_index = (long)DBL_PTR(_17lhs_seq_index)->dbl;

    // 	lhs_subs = val[a][2..$]    
    DeRef(_7785);
    _2 = (int)SEQ_PTR(_17val);
    _7785 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7785);
    DeRef(_7796);
    _7796 = SEQ_PTR(_7785)->length;
    rhs_slice_target = (object_ptr)&_17lhs_subs;
    RHS_Slice((s1_ptr)_7785, 2, _7796);

    // 	val[lhs_seq_index] = assign_subs(val[lhs_seq_index], 
    _2 = (int)SEQ_PTR(_17val);
    _7796 = (int)*(((s1_ptr)_2)->base + _17lhs_seq_index);
    Ref(_7796);
    DeRef(_7785);
    _2 = (int)SEQ_PTR(_17val);
    _7785 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7785);
    if (IS_SEQUENCE(_17lhs_subs) && IS_ATOM(_7785)) {
        Ref(_7785);
        Append(&_7785, _17lhs_subs, _7785);
    }
    else if (IS_ATOM(_17lhs_subs) && IS_SEQUENCE(_7785)) {
    }
    else {
        Concat((object_ptr)&_7785, _17lhs_subs, (s1_ptr)_7785);
    }
    DeRef(_7801);
    _2 = (int)SEQ_PTR(_17val);
    _7801 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7801);
    Ref(_7796);
    RefDS(_7785);
    Ref(_7801);
    _0 = _7801;
    _7801 = _17assign_subs(_7796, _7785, _7801);
    DeRef(_0);
    RefDS(_7801);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17lhs_seq_index);
    _1 = *(int *)_2;
    *(int *)_2 = _7801;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDS(_7801);
    DeRefDS(_7785);
    DeRef(_7796);
    return 0;
    ;
}


int _17opASSIGN_OP_SUBS()
{
    int _x = 0;
    int _7804 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7804 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7804);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _7804 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7804);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _7804 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7804);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	lhs_subs = {}
    RefDS(_39);
    DeRef(_17lhs_subs);
    _17lhs_subs = _39;

    // 	x = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	val[target] = var_subs(x, lhs_subs & val[b])
    _2 = (int)SEQ_PTR(_17val);
    _7804 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7804);
    if (IS_SEQUENCE(_17lhs_subs) && IS_ATOM(_7804)) {
        Ref(_7804);
        Append(&_7804, _17lhs_subs, _7804);
    }
    else if (IS_ATOM(_17lhs_subs) && IS_SEQUENCE(_7804)) {
    }
    else {
        Concat((object_ptr)&_7804, _17lhs_subs, (s1_ptr)_7804);
    }
    Ref(_x);
    RefDS(_7804);
    _0 = _7804;
    _7804 = _17var_subs(_x, _7804);
    DeRefDS(_0);
    Ref(_7804);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7804;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_x);
    DeRef(_7804);
    return 0;
    ;
}


int _17opPASSIGN_OP_SUBS()
{
    int _7824 = 0;
    int _7815 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7815 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7815);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _7815 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7815);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _7815 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7815);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_17val);
    _7815 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7815);
    _2 = (int)SEQ_PTR(_7815);
    _17lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_17lhs_seq_index))
        _17lhs_seq_index = (long)DBL_PTR(_17lhs_seq_index)->dbl;

    // 	lhs_subs = val[a][2..$]
    DeRef(_7815);
    _2 = (int)SEQ_PTR(_17val);
    _7815 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7815);
    _7824 = SEQ_PTR(_7815)->length;
    rhs_slice_target = (object_ptr)&_17lhs_subs;
    RHS_Slice((s1_ptr)_7815, 2, _7824);

    // 	Code[pc+9] = Code[pc+1] -- patch upcoming op
    _7824 = _17pc + 9;
    if ((long)((unsigned long)_7824 + (unsigned long)HIGH_BITS) >= 0) 
        _7824 = NewDouble((double)_7824);
    DeRef(_7815);
    _7815 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _7815 = (int)*(((s1_ptr)_2)->base + _7815);
    Ref(_7815);
    Ref(_7815);
    _2 = (int)SEQ_PTR(_7Code);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7Code = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7824))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7824)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _7824);
    _1 = *(int *)_2;
    *(int *)_2 = _7815;
    DeRef(_1);

    // 	val[target] = var_subs(val[lhs_seq_index], lhs_subs & val[b])
    DeRef(_7815);
    _2 = (int)SEQ_PTR(_17val);
    _7815 = (int)*(((s1_ptr)_2)->base + _17lhs_seq_index);
    Ref(_7815);
    DeRef(_7824);
    _2 = (int)SEQ_PTR(_17val);
    _7824 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7824);
    if (IS_SEQUENCE(_17lhs_subs) && IS_ATOM(_7824)) {
        Ref(_7824);
        Append(&_7824, _17lhs_subs, _7824);
    }
    else if (IS_ATOM(_17lhs_subs) && IS_SEQUENCE(_7824)) {
    }
    else {
        Concat((object_ptr)&_7824, _17lhs_subs, (s1_ptr)_7824);
    }
    Ref(_7815);
    RefDS(_7824);
    _0 = _7824;
    _7824 = _17var_subs(_7815, _7824);
    DeRefDS(_0);
    Ref(_7824);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7824;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_7824);
    DeRef(_7815);
    return 0;
    ;
}


int _17opASSIGN_OP_SLICE()
{
    int _x = 0;
    int _7834 = 0;
    int _7840 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7834 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7834);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	x = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	b = Code[pc+2]
    _7834 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7834);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[b] > length(x) or val[b] < 1 then
    _2 = (int)SEQ_PTR(_17val);
    _7834 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7834);
    _7840 = SEQ_PTR(_x)->length;
    if (IS_ATOM_INT(_7834)) {
        _7840 = (_7834 > _7840);
    }
    else {
        _7840 = binary_op(GREATER, _7834, _7840);
    }
    if (IS_ATOM_INT(_7840)) {
        if (_7840 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_7840)->dbl != 0.0) {
            goto L1;
        }
    }
    DeRef(_7834);
    _2 = (int)SEQ_PTR(_17val);
    _7834 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7834);
    _0 = _7834;
    if (IS_ATOM_INT(_7834)) {
        _7834 = (_7834 < 1);
    }
    else {
        _7834 = binary_op(LESS, _7834, 1);
    }
    DeRef(_0);
L2:
    if (_7834 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7834) && DBL_PTR(_7834)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	RTFatal(
    DeRef(_7834);
    _2 = (int)SEQ_PTR(_17val);
    _7834 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7834);
    DeRef(_7840);
    _7840 = SEQ_PTR(_x)->length;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7834;
    Ref(_7834);
    ((int *)_2)[2] = _7840;
    _7840 = MAKE_SEQ(_1);
    _0 = _7840;
    _7840 = EPrintf(-9999999, _7527, _7840);
    DeRefDS(_0);
    RefDS(_7840);
    _17RTFatal(_7840);

    // 	return
    DeRef(_x);
    DeRefDSi(_7840);
    DeRef(_7834);
    return 0;
L3:

    // 	c = Code[pc+3]
    DeRef(_7840);
    _7840 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7840);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	target = Code[pc+4]
    _7840 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7840);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = var_slice(x, {}, val[b], val[c])
    _2 = (int)SEQ_PTR(_17val);
    _7840 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7840);
    DeRef(_7834);
    _2 = (int)SEQ_PTR(_17val);
    _7834 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7834);
    Ref(_x);
    RefDS(_39);
    Ref(_7840);
    Ref(_7834);
    _0 = _7834;
    _7834 = _17var_slice(_x, _39, _7840, _7834);
    DeRef(_0);
    Ref(_7834);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7834;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRef(_x);
    DeRef(_7834);
    DeRef(_7840);
    return 0;
    ;
}


