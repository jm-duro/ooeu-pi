// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _15emit_op(int _op)
{
    int _a;
    int _b;
    int _c;
    int _d;
    int _source;
    int _target;
    int _subsym;
    int _lhs_var;
    int _ib;
    int _ic;
    int _n;
    int _obj = 0;
    int _elements = 0;
    int _element_vals = 0;
    int _2832 = 0;
    int _3061 = 0;
    int _2875 = 0;
    int _2850 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }

    //     if length(eval_error[$]) then
    _2832 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _2832 = (int)*(((s1_ptr)_2)->base + _2832);
    RefDS(_2832);
    _0 = _2832;
    _2832 = SEQ_PTR(_2832)->length;
    DeRef1(_0);
    if (_2832 == 0)
        goto L1;

    //     	return
    return 0;
L1:

    //     if op = ASSIGN then
    if (_op != 18)
        goto L2;

    // 	source = Pop()
    _source = _15Pop();

    // 	target = Pop()
    _target = _15Pop();

    // 	if assignable then
    if (_15assignable == 0)
        goto L3;

    // 	    Code = Code[1..$-1] -- drop previous target
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 1;
    rhs_slice_target = (object_ptr)&_7Code;
    RHS_Slice((s1_ptr)_7Code, 1, _2832);

    // 	    op = previous_op -- keep same previous op 
    _op = _15previous_op;

    // 	    if IsInteger(target) then
    _2832 = _15IsInteger(_target);
    if (_2832 == 0)
        goto L4;

    // 		if previous_op = RHS_SUBS then
    if (_15previous_op != 25)
        goto L5;

    // 		    op = RHS_SUBS_I
    _op = 114;

    // 		    backpatch(length(Code) - 2, op)
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 2;
    _15backpatch(_2832, 114);
    goto L4;
L5:

    // 		elsif previous_op = PLUS1 then
    if (_15previous_op != 93)
        goto L6;

    // 		    op = PLUS1_I
    _op = 117;

    // 		    backpatch(length(Code) - 2, op)
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 2;
    _15backpatch(_2832, 117);
    goto L4;
L6:

    // 		elsif previous_op = PLUS or previous_op = MINUS then
    DeRef1(_2832);
    _2832 = (_15previous_op == 11);
    if (_2832 != 0) {
        goto L7;
    }
    DeRef1(_2850);
    _2850 = (_15previous_op == 10);
L8:
    if (_2850 == 0)
        goto L9;
L7:

    // 		    if IsInteger(Code[$]) and
    DeRef1(_2850);
    _2850 = SEQ_PTR(_7Code)->length;
    _2 = (int)SEQ_PTR(_7Code);
    _2850 = (int)*(((s1_ptr)_2)->base + _2850);
    Ref(_2850);
    Ref(_2850);
    _0 = _2850;
    _2850 = _15IsInteger(_2850);
    DeRef1(_0);
    if (_2850 == 0) {
        goto L4;
    }
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 1;
    _2 = (int)SEQ_PTR(_7Code);
    _2832 = (int)*(((s1_ptr)_2)->base + _2832);
    Ref(_2832);
    Ref(_2832);
    _0 = _2832;
    _2832 = _15IsInteger(_2832);
    DeRef1(_0);
LA:
    if (_2832 == 0)
        goto L4;

    // 			if previous_op = PLUS then
    if (_15previous_op != 11)
        goto LB;

    // 			    op = PLUS_I
    _op = 115;
    goto LC;
LB:

    // 			    op = MINUS_I
    _op = 116;
LC:

    // 			backpatch(length(Code) - 2, op)
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 2;
    _15backpatch(_2832, _op);
LD:
    goto L4;
L9:

    // 		    if IsInteger(source) then
    _0 = _2832;
    _2832 = _15IsInteger(_source);
    DeRef1(_0);
    if (_2832 == 0)
        goto L4;

    // 			op = ASSIGN_I -- fake to avoid subsequent check
    _op = 113;
LE:
LF:
L10:
    goto L4;
L3:

    // 	    if IsInteger(source) and IsInteger(target) then
    _0 = _2832;
    _2832 = _15IsInteger(_source);
    DeRef1(_0);
    if (_2832 == 0) {
        goto L11;
    }
    _0 = _2850;
    _2850 = _15IsInteger(_target);
    DeRef1(_0);
L12:
    if (_2850 == 0)
        goto L11;

    // 		op = ASSIGN_I
    _op = 113;
L11:

    // 	    if SymTab[source][S_MODE] = M_CONSTANT and 
    DeRef1(_2850);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2850 = (int)*(((s1_ptr)_2)->base + _source);
    Ref(_2850);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_2850);
    _2850 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    if (IS_ATOM_INT(_2850)) {
        _2850 = (_2850 == 2);
    }
    else {
        _2850 = binary_op(EQUALS, _2850, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2850)) {
        if (_2850 == 0) {
            goto L13;
        }
    }
    else {
        if (DBL_PTR(_2850)->dbl == 0.0) {
            goto L13;
        }
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _target);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2832);
    DeRef1(_0);
    _0 = _2832;
    if (IS_ATOM_INT(_2832)) {
        _2832 = (_2832 == 2);
    }
    else {
        _2832 = binary_op(EQUALS, _2832, 2);
    }
    DeRef1(_0);
L14:
    if (_2832 == 0) {
        goto L13;
    }
    else {
        if (!IS_ATOM_INT(_2832) && DBL_PTR(_2832)->dbl == 0.0)
            goto L13;
    }

    // 		SymTab[target][S_OBJ] = SymTab[source][S_OBJ]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_target + ((s1_ptr)_2)->base);
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _source);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2875);
    DeRef1(_0);
    Ref(_2875);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _2875;
    DeRef(_1);
L13:

    // 	    emit_opcode(op)
    _15emit_opcode(_op);

    // 	    emit_addr(source)
    _15emit_addr(_source);
L4:

    // 	assignable = FALSE
    _15assignable = 0;

    // 	emit_addr(target)
    _15emit_addr(_target);
    goto L15;
L2:

    //     elsif op = RHS_SUBS then
    if (_op != 25)
        goto L16;

    // 	b = Pop() -- subscript 
    _b = _15Pop();

    // 	c = Pop() -- sequence 
    _c = _15Pop();

    // 	target = NewTempSym() -- target 
    _target = _11NewTempSym();

    // 	if SymTab[c][S_MODE] = M_NORMAL then
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _2875, 1))
        goto L17;

    // 	    if SymTab[c][S_VTYPE] != sequence_type and 
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 != _11sequence_type);
    }
    else {
        _2875 = binary_op(NOTEQ, _2875, _11sequence_type);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 == 0) {
            goto L18;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl == 0.0) {
            goto L18;
        }
    }
    DeRef1(_2850);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2850 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2850);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_2850);
    _2850 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_2850))
        _2850 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2850)->dbl));
    else
        _2850 = (int)*(((s1_ptr)_2)->base + _2850);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_2850);
    _2850 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_2850))
        _2850 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2850)->dbl));
    else
        _2850 = (int)*(((s1_ptr)_2)->base + _2850);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_2850);
    _2850 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    if (IS_ATOM_INT(_2850)) {
        _2850 = (_2850 != _11sequence_type);
    }
    else {
        _2850 = binary_op(NOTEQ, _2850, _11sequence_type);
    }
    DeRef1(_0);
L19:
    if (_2850 == 0) {
        goto L18;
    }
    else {
        if (!IS_ATOM_INT(_2850) && DBL_PTR(_2850)->dbl == 0.0)
            goto L18;
    }

    // 		op = RHS_SUBS_CHECK
    _op = 92;
L1A:
    goto L18;
L17:

    // 	elsif SymTab[c][S_MODE] != M_CONSTANT or 
    DeRef1(_2850);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2850 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2850);
    _0 = _2850;
    _2 = (int)SEQ_PTR(_2850);
    _2850 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2850);
    DeRef1(_0);
    _0 = _2850;
    if (IS_ATOM_INT(_2850)) {
        _2850 = (_2850 != 2);
    }
    else {
        _2850 = binary_op(NOTEQ, _2850, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2850)) {
        if (_2850 != 0) {
            goto L1B;
        }
    }
    else {
        if (DBL_PTR(_2850)->dbl != 0.0) {
            goto L1B;
        }
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    _2875 = IS_SEQUENCE(_2875);
    DeRef1(_0);
    _2875 = (_2875 == 0);
L1C:
    if (_2875 == 0)
        goto L1D;
L1B:

    // 	    op = RHS_SUBS_CHECK
    _op = 92;
L1D:
L18:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	assignable = TRUE
    _15assignable = 1;

    // 	Push(target)
    _15Push(_target);

    // 	emit_addr(target)
    _15emit_addr(_target);

    // 	current_sequence = append(current_sequence, target)
    Append(&_15current_sequence, _15current_sequence, _target);
    goto L15;
L16:

    //     elsif op = r:PROC then  -- procedure, function and type calls
    if (_op != 27)
        goto L1E;

    // 		assignable = FALSE -- assume for now 
    _15assignable = 0;

    // 		subsym = op_info1
    _subsym = _15op_info1;

    // 		n = SymTab[subsym][S_NUM_ARGS]
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_2875);
    _2 = (int)SEQ_PTR(_2875);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 		if subsym = CurrentSub then
    if (_subsym != _7CurrentSub)
        goto L1F;

    // 		    for i = length(cg_stack)-n+1 to length(cg_stack) do
    DeRef1(_2875);
    _2875 = SEQ_PTR(_15cg_stack)->length;
    _2875 = _2875 - _n;
    if ((long)((unsigned long)_2875 +(unsigned long) HIGH_BITS) >= 0)
        _2875 = NewDouble((double)_2875);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = _2875 + 1;
        if (_2875 > MAXINT)
            _2875 = NewDouble((double)_2875);
    }
    else
        _2875 = binary_op(PLUS, 1, _2875);
    DeRef1(_0);
    DeRef1(_2850);
    _2850 = SEQ_PTR(_15cg_stack)->length;
    { int _i;
        Ref(_2875);
        _i = _2875;
L20:
        if (binary_op_a(GREATER, _i, _2850))
            goto L21;

        // 			if SymTab[cg_stack[i]][S_SCOPE] = SC_PRIVATE and 
        DeRef(_2875);
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!IS_ATOM_INT(_i))
            _2875 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2875 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2875);
        _0 = _2875;
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_2875))
            _2875 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2875)->dbl));
        else
            _2875 = (int)*(((s1_ptr)_2)->base + _2875);
        Ref(_2875);
        DeRef(_0);
        _0 = _2875;
        _2 = (int)SEQ_PTR(_2875);
        _2875 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_2875);
        DeRef(_0);
        _0 = _2875;
        if (IS_ATOM_INT(_2875)) {
            _2875 = (_2875 == 3);
        }
        else {
            _2875 = binary_op(EQUALS, _2875, 3);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_2875)) {
            if (_2875 == 0) {
                goto L22;
            }
        }
        else {
            if (DBL_PTR(_2875)->dbl == 0.0) {
                goto L22;
            }
        }
        DeRef(_2832);
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!IS_ATOM_INT(_i))
            _2832 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2832 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2832);
        _0 = _2832;
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_2832))
            _2832 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2832)->dbl));
        else
            _2832 = (int)*(((s1_ptr)_2)->base + _2832);
        Ref(_2832);
        DeRef(_0);
        _0 = _2832;
        _2 = (int)SEQ_PTR(_2832);
        _2832 = (int)*(((s1_ptr)_2)->base + 12);
        Ref(_2832);
        DeRef(_0);
        _0 = _2832;
        if (IS_ATOM_INT(_2832) && IS_ATOM_INT(_i)) {
            _2832 = (_2832 < _i);
        }
        else {
            _2832 = binary_op(LESS, _2832, _i);
        }
        DeRef(_0);
L23:
        if (_2832 == 0) {
            goto L22;
        }
        else {
            if (!IS_ATOM_INT(_2832) && DBL_PTR(_2832)->dbl == 0.0)
                goto L22;
        }

        // 			    emit_opcode(ASSIGN)
        _15emit_opcode(18);

        // 			    emit_addr(cg_stack[i])
        DeRef(_2832);
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!IS_ATOM_INT(_i))
            _2832 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2832 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2832);
        Ref(_2832);
        _15emit_addr(_2832);

        // 			    cg_stack[i] = NewTempSym()
        _0 = _2832;
        _2832 = _11NewTempSym();
        DeRef(_0);
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _15cg_stack = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_i))
            _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _2832;
        DeRef(_1);

        // 			    emit_addr(cg_stack[i])
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!IS_ATOM_INT(_i))
            _2832 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2832 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2832);
        Ref(_2832);
        _15emit_addr(_2832);
L22:

        // 		    end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef1(_0);
        goto L20;
L21:
        ;
        DeRef1(_i);
    }
L1F:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		emit_addr(subsym)
    _15emit_addr(_subsym);

    // 		for i = length(cg_stack)-n+1 to length(cg_stack) do 
    DeRef1(_2832);
    _2832 = SEQ_PTR(_15cg_stack)->length;
    _2832 = _2832 - _n;
    if ((long)((unsigned long)_2832 +(unsigned long) HIGH_BITS) >= 0)
        _2832 = NewDouble((double)_2832);
    _0 = _2832;
    if (IS_ATOM_INT(_2832)) {
        _2832 = _2832 + 1;
        if (_2832 > MAXINT)
            _2832 = NewDouble((double)_2832);
    }
    else
        _2832 = binary_op(PLUS, 1, _2832);
    DeRef1(_0);
    DeRef1(_2875);
    _2875 = SEQ_PTR(_15cg_stack)->length;
    { int _i;
        Ref(_2832);
        _i = _2832;
L24:
        if (binary_op_a(GREATER, _i, _2875))
            goto L25;

        // 		    emit_addr(cg_stack[i])
        DeRef(_2832);
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!IS_ATOM_INT(_i))
            _2832 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2832 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2832);
        Ref(_2832);
        _15emit_addr(_2832);

        // 		    TempFree(cg_stack[i])
        DeRef(_2832);
        _2 = (int)SEQ_PTR(_15cg_stack);
        if (!IS_ATOM_INT(_i))
            _2832 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2832 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2832);
        Ref(_2832);
        _15TempFree(_2832);

        // 		end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef1(_0);
        goto L24;
L25:
        ;
        DeRef1(_i);
    }

    // 		cg_stack = cg_stack[1..$-n]
    DeRef1(_2832);
    _2832 = SEQ_PTR(_15cg_stack)->length;
    _2832 = _2832 - _n;
    rhs_slice_target = (object_ptr)&_15cg_stack;
    RHS_Slice((s1_ptr)_15cg_stack, 1, _2832);

    // 		if SymTab[subsym][S_TOKEN] != r:PROC then
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_2832);
    DeRef1(_0);
    if (binary_op_a(EQUALS, _2832, 27))
        goto L15;

    // 		    assignable = TRUE
    _15assignable = 1;

    // 		    c = NewTempSym() -- put final result in temp 
    _c = _11NewTempSym();

    // 		    Push(c)
    _15Push(_c);

    // 		    emit_addr(c)
    _15emit_addr(_c);
L26:
    goto L15;
L1E:

    //     elsif find(op, {NOP1, NOP2, NOPWHILE, PRIVATE_INIT_CHECK, GLOBAL_INIT_CHECK,
    DeRef1(_2832);
    _2832 = find(_op, _2937);
    if (_2832 == 0)
        goto L27;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L27:

    //     elsif op = IF or op = WHILE then
    DeRef1(_2832);
    _2832 = (_op == 20);
    if (_2832 != 0) {
        goto L28;
    }
    DeRef1(_2875);
    _2875 = (_op == 47);
L29:
    if (_2875 == 0)
        goto L2A;
L28:

    // 	a = Pop()
    _a = _15Pop();

    // 	assignable = FALSE
    _15assignable = 0;

    // 	if previous_op >= LESS and previous_op <= NOT then
    DeRef1(_2875);
    _2875 = (_15previous_op >= 1);
    if (_2875 == 0) {
        goto L2B;
    }
    DeRef1(_2832);
    _2832 = (_15previous_op <= 7);
L2C:
    if (_2832 == 0)
        goto L2B;

    // 	    Code = Code[1..$-1] 
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 1;
    rhs_slice_target = (object_ptr)&_7Code;
    RHS_Slice((s1_ptr)_7Code, 1, _2832);

    // 	    if previous_op = NOT then
    if (_15previous_op != 7)
        goto L2D;

    // 		op = NOT_IFW
    _op = 108;

    // 		backpatch(length(Code) - 1, op)
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 1;
    _15backpatch(_2832, 108);
    goto L15;
L2D:

    // 		if IsInteger(Code[$-1]) and
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 1;
    _2 = (int)SEQ_PTR(_7Code);
    _2832 = (int)*(((s1_ptr)_2)->base + _2832);
    Ref(_2832);
    Ref(_2832);
    _0 = _2832;
    _2832 = _15IsInteger(_2832);
    DeRef1(_0);
    if (_2832 == 0) {
        goto L2E;
    }
    DeRef1(_2875);
    _2875 = SEQ_PTR(_7Code)->length;
    _2 = (int)SEQ_PTR(_7Code);
    _2875 = (int)*(((s1_ptr)_2)->base + _2875);
    Ref(_2875);
    Ref(_2875);
    _0 = _2875;
    _2875 = _15IsInteger(_2875);
    DeRef1(_0);
L2F:
    if (_2875 == 0)
        goto L2E;

    // 		    op = previous_op + LESS_IFW_I - LESS
    DeRef1(_2875);
    _2875 = _15previous_op + 119;
    if ((long)((unsigned long)_2875 + (unsigned long)HIGH_BITS) >= 0) 
        _2875 = NewDouble((double)_2875);
    if (IS_ATOM_INT(_2875)) {
        _op = _2875 - 1;
    }
    else {
        _op = NewDouble(DBL_PTR(_2875)->dbl - (double)1);
    }
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }
    goto L30;
L2E:

    // 		    op = previous_op + LESS_IFW - LESS
    DeRef1(_2875);
    _2875 = _15previous_op + 102;
    if ((long)((unsigned long)_2875 + (unsigned long)HIGH_BITS) >= 0) 
        _2875 = NewDouble((double)_2875);
    if (IS_ATOM_INT(_2875)) {
        _op = _2875 - 1;
    }
    else {
        _op = NewDouble(DBL_PTR(_2875)->dbl - (double)1);
    }
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }
L30:

    // 		backpatch(length(Code) - 2, op)
    DeRef1(_2875);
    _2875 = SEQ_PTR(_7Code)->length;
    _2875 = _2875 - 2;
    _15backpatch(_2875, _op);
L31:
    goto L15;
L2B:

    // 	elsif op = WHILE and    
    DeRef1(_2875);
    _2875 = (_op == 47);
    if (_2875 == 0) {
        _2875 = 0;
        goto L32;
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2832);
    DeRef1(_0);
    _0 = _2832;
    if (IS_ATOM_INT(_2832)) {
        _2832 = (_2832 == 2);
    }
    else {
        _2832 = binary_op(EQUALS, _2832, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2832))
        _2875 = (_2832 != 0);
    else
        _2875 = DBL_PTR(_2832)->dbl != 0.0;
L32:
    if (_2875 == 0) {
        DeRef1(_2832);
        _2832 = 0;
        goto L33;
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875))
        _2875 = 1;
    else if (IS_ATOM_DBL(_2875))
        _2875 = IS_ATOM_INT(DoubleToInt(_2875));
    else
        _2875 = 0;
    DeRef1(_0);
    _2832 = (_2875 != 0);
L33:
    if (_2832 == 0) {
        goto L34;
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2832);
    DeRef1(_0);
    _0 = _2832;
    if (_2832 == 0)
        _2832 = 1;
    else if (IS_ATOM_INT(_2832) && IS_ATOM_INT(0))
        _2832 = 0;
    else
        _2832 = (compare(_2832, 0) == 0);
    DeRef1(_0);
    _2832 = (_2832 == 0);
L35:
    if (_2832 == 0)
        goto L34;

    // 	    optimized_while = TRUE   -- while TRUE ... emit nothing
    _15optimized_while = 1;
    goto L15;
L34:

    // 	    emit_opcode(op)
    _15emit_opcode(_op);

    // 	    emit_addr(a)       
    _15emit_addr(_a);
L36:
    goto L15;
L2A:

    //     elsif op = INTEGER_CHECK then
    if (_op != 96)
        goto L37;

    // 	assignable = FALSE
    _15assignable = 0;

    // 	if previous_op = ASSIGN then 
    if (_15previous_op != 18)
        goto L38;

    // 	    c = Code[$-1]
    DeRef1(_2832);
    _2832 = SEQ_PTR(_7Code)->length;
    _2832 = _2832 - 1;
    _2 = (int)SEQ_PTR(_7Code);
    _c = (int)*(((s1_ptr)_2)->base + _2832);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    if not IsInteger(c) then
    _2832 = _15IsInteger(_c);
    if (_2832 != 0)
        goto L15;

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		emit_addr(op_info1)
    _15emit_addr(_15op_info1);
L39:
    goto L15;
L38:

    // 	elsif previous_op = -1 or 
    DeRef1(_2832);
    _2832 = (_15previous_op == -1);
    if (_2832 != 0) {
        goto L3A;
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_15op_result);
    _2875 = (int)*(((s1_ptr)_2)->base + _15previous_op);
    _2875 = (_2875 != 1);
L3B:
    if (_2875 == 0)
        goto L15;
L3A:

    // 	    emit_opcode(op)
    _15emit_opcode(_op);

    // 	    emit_addr(op_info1)
    _15emit_addr(_15op_info1);
L3C:
L3D:
    goto L15;
L37:

    //     elsif op = SEQUENCE_CHECK then
    if (_op != 97)
        goto L3E;

    // 	assignable = FALSE
    _15assignable = 0;

    // 	if previous_op = ASSIGN then
    if (_15previous_op != 18)
        goto L3F;

    // 	    c = Code[$-1]
    DeRef1(_2875);
    _2875 = SEQ_PTR(_7Code)->length;
    _2875 = _2875 - 1;
    _2 = (int)SEQ_PTR(_7Code);
    _c = (int)*(((s1_ptr)_2)->base + _2875);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    if SymTab[c][S_MODE] != M_CONSTANT or 
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 != 2);
    }
    else {
        _2875 = binary_op(NOTEQ, _2875, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 != 0) {
            goto L40;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl != 0.0) {
            goto L40;
        }
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2832);
    DeRef1(_0);
    _0 = _2832;
    _2832 = IS_SEQUENCE(_2832);
    DeRef1(_0);
    _2832 = (_2832 == 0);
L41:
    if (_2832 == 0)
        goto L15;
L40:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		emit_addr(op_info1)
    _15emit_addr(_15op_info1);
L42:
    goto L15;
L3F:

    // 	elsif previous_op = -1 or 
    DeRef1(_2832);
    _2832 = (_15previous_op == -1);
    if (_2832 != 0) {
        goto L43;
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_15op_result);
    _2875 = (int)*(((s1_ptr)_2)->base + _15previous_op);
    _2875 = (_2875 != 3);
L44:
    if (_2875 == 0)
        goto L15;
L43:

    // 	    emit_opcode(op)
    _15emit_opcode(_op);

    // 	    emit_addr(op_info1)
    _15emit_addr(_15op_info1);
L45:
L46:
    goto L15;
L3E:

    //     elsif op = ATOM_CHECK then
    if (_op != 101)
        goto L47;

    // 	assignable = FALSE
    _15assignable = 0;

    // 	if previous_op = ASSIGN then
    if (_15previous_op != 18)
        goto L48;

    // 	    c = Code[$-1]
    DeRef1(_2875);
    _2875 = SEQ_PTR(_7Code)->length;
    _2875 = _2875 - 1;
    _2 = (int)SEQ_PTR(_7Code);
    _c = (int)*(((s1_ptr)_2)->base + _2875);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    if (SymTab[c][S_MODE] != M_CONSTANT or not atom(SymTab[c][S_OBJ])) 
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 != 2);
    }
    else {
        _2875 = binary_op(NOTEQ, _2875, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 != 0) {
            DeRef1(_2875);
            _2875 = 1;
            goto L49;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl != 0.0) {
            DeRef1(_2875);
            _2875 = 1;
            goto L49;
        }
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2832);
    DeRef1(_0);
    _0 = _2832;
    _2832 = IS_ATOM(_2832);
    DeRef1(_0);
    _2832 = (_2832 == 0);
    DeRef1(_2875);
    _2875 = (_2832 != 0);
L49:
    if (_2875 == 0) {
        goto L15;
    }
    _0 = _2875;
    _2875 = _15IsInteger(_c);
    DeRef1(_0);
    _2875 = (_2875 == 0);
L4A:
    if (_2875 == 0)
        goto L15;

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		emit_addr(op_info1)
    _15emit_addr(_15op_info1);
L4B:
    goto L15;
L48:

    // 	elsif previous_op = -1 or 
    DeRef1(_2875);
    _2875 = (_15previous_op == -1);
    if (_2875 != 0) {
        goto L4C;
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_15op_result);
    _2832 = (int)*(((s1_ptr)_2)->base + _15previous_op);
    _2832 = (_2832 != 1);
    if (_2832 == 0) {
        _2832 = 0;
        goto L4D;
    }
    DeRef1(_2850);
    _2 = (int)SEQ_PTR(_15op_result);
    _2850 = (int)*(((s1_ptr)_2)->base + _15previous_op);
    _2850 = (_2850 != 4);
    _2832 = (_2850 != 0);
L4D:
L4E:
    if (_2832 == 0)
        goto L15;
L4C:

    // 	    emit_opcode(op)
    _15emit_opcode(_op);

    // 	    emit_addr(op_info1)
    _15emit_addr(_15op_info1);
L4F:
L50:
    goto L15;
L47:

    //     elsif op = RIGHT_BRACE_N then -- form a sequence of n items
    if (_op != 31)
        goto L51;

    // 	n = op_info1
    _n = _15op_info1;

    // 	elements = {}
    RefDS(_39);
    DeRef1(_elements);
    _elements = _39;

    // 	for i = 1 to n do
    DeRef1(_2850);
    _2850 = _n;
    { int _i;
        _i = 1;
L52:
        if (_i > _2850)
            goto L53;

        // 	    elements = append(elements, Pop())
        _0 = _2832;
        _2832 = _15Pop();
        DeRef(_0);
        Append(&_elements, _elements, _2832);

        // 	end for
        _i = _i + 1;
        goto L52;
L53:
        ;
    }

    // 	element_vals = good_string(elements)
    RefDS(_elements);
    _0 = _element_vals;
    _element_vals = _15good_string(_elements);
    DeRef1(_0);

    // 	if sequence(element_vals) then
    DeRef1(_2832);
    _2832 = IS_SEQUENCE(_element_vals);
    if (_2832 == 0)
        goto L54;

    // 	    c = NewStringSym(element_vals)  -- make a string literal
    Ref(_element_vals);
    _c = _11NewStringSym(_element_vals);

    // 	    assignable = FALSE
    _15assignable = 0;
    goto L55;
L54:

    // 	    if n = 2 then
    if (_n != 2)
        goto L56;

    // 		emit_opcode(RIGHT_BRACE_2) -- faster op for two items
    _15emit_opcode(85);
    goto L57;
L56:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		emit(n)
    _15emit(_n);
L57:

    // 	    for i = 1 to n do
    DeRef1(_2832);
    _2832 = _n;
    { int _i;
        _i = 1;
L58:
        if (_i > _2832)
            goto L59;

        // 		emit_addr(elements[i])
        DeRef(_2850);
        _2 = (int)SEQ_PTR(_elements);
        _2850 = (int)*(((s1_ptr)_2)->base + _i);
        _15emit_addr(_2850);

        // 	    end for
        _i = _i + 1;
        goto L58;
L59:
        ;
    }

    // 	    c = NewTempSym()
    _c = _11NewTempSym();

    // 	    emit_addr(c)
    _15emit_addr(_c);

    // 	    assignable = TRUE
    _15assignable = 1;
L55:

    // 	Push(c)
    _15Push(_c);
    goto L15;
L51:

    //     elsif op = ASSIGN_SUBS2 or -- can't change the op
    DeRef1(_2850);
    _2850 = (_op == 150);
    if (_2850 != 0) {
        _2850 = 1;
        goto L5A;
    }
    DeRef1(_2832);
    _2832 = (_op == 16);
    _2850 = (_2832 != 0);
L5A:
    if (_2850 != 0) {
        goto L5B;
    }
    DeRef1(_2850);
    _2850 = (_op == 164);
L5C:
    if (_2850 == 0)
        goto L5D;
L5B:

    // 	b = Pop() -- rhs value 
    _b = _15Pop();

    // 	a = Pop() -- subscript
    _a = _15Pop();

    // 	c = Pop() -- sequence 
    _c = _15Pop();

    // 	if op = ASSIGN_SUBS then
    if (_op != 16)
        goto L5E;

    // 	    if (previous_op != LHS_SUBS) and 
    DeRef1(_2850);
    _2850 = (_15previous_op != 95);
    if (_2850 == 0) {
        goto L5F;
    }
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2832 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2832);
    _0 = _2832;
    _2 = (int)SEQ_PTR(_2832);
    _2832 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2832);
    DeRef1(_0);
    _0 = _2832;
    if (IS_ATOM_INT(_2832)) {
        _2832 = (_2832 != 1);
    }
    else {
        _2832 = binary_op(NOTEQ, _2832, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2832)) {
        if (_2832 != 0) {
            DeRef1(_2832);
            _2832 = 1;
            goto L60;
        }
    }
    else {
        if (DBL_PTR(_2832)->dbl != 0.0) {
            DeRef1(_2832);
            _2832 = 1;
            goto L60;
        }
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 != _11sequence_type);
    }
    else {
        _2875 = binary_op(NOTEQ, _2875, _11sequence_type);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 == 0) {
            DeRef1(_2875);
            _2875 = 0;
            goto L61;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl == 0.0) {
            DeRef1(_2875);
            _2875 = 0;
            goto L61;
        }
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3061))
        _3061 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3061)->dbl));
    else
        _3061 = (int)*(((s1_ptr)_2)->base + _3061);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3061))
        _3061 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3061)->dbl));
    else
        _3061 = (int)*(((s1_ptr)_2)->base + _3061);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 != _11sequence_type);
    }
    else {
        _3061 = binary_op(NOTEQ, _3061, _11sequence_type);
    }
    DeRef1(_0);
    DeRef1(_2875);
    if (IS_ATOM_INT(_3061))
        _2875 = (_3061 != 0);
    else
        _2875 = DBL_PTR(_3061)->dbl != 0.0;
L61:
    DeRef1(_2832);
    _2832 = (_2875 != 0);
L60:
L62:
    if (_2832 == 0)
        goto L5F;

    // 		op = ASSIGN_SUBS_CHECK
    _op = 84;
    goto L63;
L5F:

    // 		if IsInteger(b) then
    _0 = _3061;
    _3061 = _15IsInteger(_b);
    DeRef1(_0);
    if (_3061 == 0)
        goto L64;

    // 		    op = ASSIGN_SUBS_I
    _op = 118;
L64:
L63:

    // 	    emit_opcode(op)
    _15emit_opcode(_op);
    goto L65;
L5E:

    // 	elsif op = PASSIGN_SUBS then
    if (_op != 164)
        goto L66;

    // 	    emit_opcode(PASSIGN_SUBS) -- always
    _15emit_opcode(164);
    goto L65;
L66:

    // 	    emit_opcode(ASSIGN_SUBS) -- always
    _15emit_opcode(16);
L65:

    // 	emit_addr(c) -- sequence
    _15emit_addr(_c);

    // 	emit_addr(a) -- subscript 
    _15emit_addr(_a);

    // 	emit_addr(b) -- rhs value
    _15emit_addr(_b);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L5D:

    //     elsif op = LHS_SUBS or op = LHS_SUBS1 or op = LHS_SUBS1_COPY then  
    DeRef1(_3061);
    _3061 = (_op == 95);
    if (_3061 != 0) {
        _3061 = 1;
        goto L67;
    }
    DeRef1(_2875);
    _2875 = (_op == 163);
    _3061 = (_2875 != 0);
L67:
    if (_3061 != 0) {
        goto L68;
    }
    DeRef1(_3061);
    _3061 = (_op == 168);
L69:
    if (_3061 == 0)
        goto L6A;
L68:

    // 	a = Pop() -- subs
    _a = _15Pop();

    // 	lhs_var = Pop() -- sequence
    _lhs_var = _15Pop();

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(lhs_var)
    _15emit_addr(_lhs_var);

    // 	emit_addr(a)
    _15emit_addr(_a);

    // 	if op = LHS_SUBS then
    if (_op != 95)
        goto L6B;

    // 	    TempKeep(lhs_var) -- should be lhs_target_temp
    _15TempKeep(_lhs_var);

    // 	    emit_addr(lhs_target_temp)
    _15emit_addr(_15lhs_target_temp);

    // 	    Push(lhs_target_temp)
    _15Push(_15lhs_target_temp);

    // 	    emit_addr(0) -- place holder 
    _15emit_addr(0);
    goto L6C;
L6B:

    // 	    lhs_target_temp = NewTempSym() -- use same temp for all subscripts
    _0 = _11NewTempSym();
    _15lhs_target_temp = _0;

    // 	    emit_addr(lhs_target_temp) -- target temp holds pointer to sequence
    _15emit_addr(_15lhs_target_temp);

    // 	    Push(lhs_target_temp)
    _15Push(_15lhs_target_temp);

    // 	    lhs_subs1_copy_temp = NewTempSym() -- place to copy (may be ignored)
    _0 = _11NewTempSym();
    _15lhs_subs1_copy_temp = _0;

    // 	    emit_addr(lhs_subs1_copy_temp)
    _15emit_addr(_15lhs_subs1_copy_temp);
L6C:

    // 	current_sequence = append(current_sequence, lhs_target_temp)
    Append(&_15current_sequence, _15current_sequence, _15lhs_target_temp);

    // 	assignable = FALSE  -- need to update current_sequence like in RHS_SUBS
    _15assignable = 0;
    goto L15;
L6A:

    //     elsif find(op, {RAND, PEEK, PEEK4S, PEEK4U, NOT_BITS, NOT}) then
    DeRef1(_3061);
    _3061 = find(_op, _3081);
    if (_3061 == 0)
        goto L6D;

    // 	cont11ii(op, TRUE)
    _15cont11ii(_op, 1);
    goto L15;
L6D:

    //     elsif op = UMINUS then
    if (_op != 12)
        goto L6E;

    // 	a = Pop()
    _a = _15Pop();

    // 	obj = SymTab[a][S_OBJ]
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_3061);
    DeRef1(_obj);
    _2 = (int)SEQ_PTR(_3061);
    _obj = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_obj);

    // 	if SymTab[a][S_MODE] = M_CONSTANT then
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3061);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _3061, 2))
        goto L6F;

    // 	    if integer(obj) then
    DeRef1(_3061);
    if (IS_ATOM_INT(_obj))
        _3061 = 1;
    else if (IS_ATOM_DBL(_obj))
        _3061 = IS_ATOM_INT(DoubleToInt(_obj));
    else
        _3061 = 0;
    if (_3061 == 0)
        goto L70;

    // 		if obj = MININT then
    if (binary_op_a(NOTEQ, _obj, -1073741824))
        goto L71;

    // 		    Push(NewDoubleSym(-MININT_VAL))
    if (-1073741824 == 0xC0000000)
        _3061 = (int)NewDouble((double)-0xC0000000);
    else
        _3061 = - -1073741824;
    Ref(_3061);
    _0 = _3061;
    _3061 = _11NewDoubleSym(_3061);
    DeRef1(_0);
    _15Push(_3061);
    goto L15;
L71:

    // 		    Push(NewIntSym(-obj))
    DeRef1(_3061);
    if (IS_ATOM_INT(_obj)) {
        if (_obj == 0xC0000000)
            _3061 = (int)NewDouble((double)-0xC0000000);
        else
            _3061 = - _obj;
    }
    else {
        _3061 = unary_op(UMINUS, _obj);
    }
    Ref(_3061);
    _0 = _3061;
    _3061 = _11NewIntSym(_3061);
    DeRef1(_0);
    _15Push(_3061);
L72:
    goto L15;
L70:

    // 	    elsif atom(obj) and obj != NOVALUE then
    DeRef1(_3061);
    _3061 = IS_ATOM(_obj);
    if (_3061 == 0) {
        goto L73;
    }
    DeRef1(_2875);
    _2875 = binary_op(NOTEQ, _obj, _7NOVALUE);
L74:
    if (_2875 == 0) {
        goto L73;
    }
    else {
        if (!IS_ATOM_INT(_2875) && DBL_PTR(_2875)->dbl == 0.0)
            goto L73;
    }

    // 		Push(NewDoubleSym(-obj)) 
    DeRef1(_2875);
    if (IS_ATOM_INT(_obj)) {
        if (_obj == 0xC0000000)
            _2875 = (int)NewDouble((double)-0xC0000000);
        else
            _2875 = - _obj;
    }
    else {
        _2875 = unary_op(UMINUS, _obj);
    }
    Ref(_2875);
    _0 = _2875;
    _2875 = _11NewDoubleSym(_2875);
    DeRef1(_0);
    _15Push(_2875);
    goto L15;
L73:

    // 		Push(a)
    _15Push(_a);

    // 		cont11ii(op, FALSE)   
    _15cont11ii(_op, 0);
L75:
    goto L15;
L6F:

    // 	    Push(a)
    _15Push(_a);

    // 	    cont11ii(op, FALSE)   
    _15cont11ii(_op, 0);
L76:
    goto L15;
L6E:

    //     elsif find(op, {IS_AN_INTEGER, IS_AN_ATOM, IS_A_SEQUENCE, IS_AN_OBJECT,
    DeRef1(_2875);
    _2875 = find(_op, _3101);
    if (_2875 == 0)
        goto L77;

    // 	cont11ii(op, FALSE)   
    _15cont11ii(_op, 0);
    goto L15;
L77:

    //     elsif op = ROUTINE_ID then
    if (_op != 136)
        goto L78;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	source = Pop()
    _source = _15Pop();

    // 	if TRANSLATE then

    // 	if BIND or not execute then
    if (0 != 0) {
        goto L79;
    }
    DeRef1(_3061);
    _3061 = (_7execute == 0);
L7A:
    if (_3061 == 0)
        goto L7B;
L79:

    // 	    MarkTargets(source, S_NREFS) 
    _11MarkTargets(_source, 11);
L7B:

    // 	emit_addr(CurrentSub)
    _15emit_addr(_7CurrentSub);

    // 	    emit_addr(length(SymTab))
    DeRef1(_3061);
    _3061 = SEQ_PTR(_7SymTab)->length;
    _15emit_addr(_3061);
L7C:

    // 	emit_addr(source)
    _15emit_addr(_source);

    // 	emit_addr(current_file_no)  -- necessary at top level
    _15emit_addr(_7current_file_no);

    // 	assignable = TRUE
    _15assignable = 1;

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	TempInteger(c) -- result will always be an integer
    _15TempInteger(_c);

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)
    _15emit_addr(_c);
    goto L15;
L78:

    //     elsif op = SC1_OR or op = SC1_AND then
    DeRef1(_3061);
    _3061 = (_op == 145);
    if (_3061 != 0) {
        goto L7D;
    }
    DeRef1(_2875);
    _2875 = (_op == 143);
L7E:
    if (_2875 == 0)
        goto L7F;
L7D:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(Pop())       
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L7F:

    //     elsif find(op, {SYSTEM, PUTS, PRINT, QPRINT, POSITION, MACHINE_PROC,
    DeRef1(_2875);
    _2875 = find(_op, _3115);
    if (_2875 == 0)
        goto L80;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	b = Pop()
    _b = _15Pop();

    // 	emit_addr(Pop())
    _2875 = _15Pop();
    _15emit_addr(_2875);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L80:

    //     elsif find(op, {EQUALS, LESS, GREATER, NOTEQ, LESSEQ, GREATEREQ,
    DeRef1(_2875);
    _2875 = find(_op, _3119);
    if (_2875 == 0)
        goto L81;

    // 	cont21ii(op, TRUE)  -- both integer args => integer result
    _15cont21ii(_op, 1);
    goto L15;
L81:

    //     elsif op = PLUS then
    if (_op != 11)
        goto L82;

    // 	b = Pop()
    _b = _15Pop();

    // 	a = Pop()
    _a = _15Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 1) then 
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 == 2);
    }
    else {
        _2875 = binary_op(EQUALS, _2875, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 == 0) {
            goto L83;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl == 0.0) {
            goto L83;
        }
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (_3061 == 1)
        _3061 = 1;
    else if (IS_ATOM_INT(_3061) && IS_ATOM_INT(1))
        _3061 = 0;
    else
        _3061 = (compare(_3061, 1) == 0);
    DeRef1(_0);
L84:
    if (_3061 == 0)
        goto L83;

    // 	    op = PLUS1
    _op = 93;

    // 	    emit_opcode(op)
    _15emit_opcode(93);

    // 	    emit_addr(a)
    _15emit_addr(_a);

    // 	    emit_addr(0)
    _15emit_addr(0);

    // 	    cont21d(op, a, b, FALSE)
    _15cont21d(93, _a, _b, 0);
    goto L15;
L83:

    // 	elsif SymTab[a][S_MODE] = M_CONSTANT and equal(SymTab[a][S_OBJ], 1) then
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 == 2);
    }
    else {
        _3061 = binary_op(EQUALS, _3061, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_3061)) {
        if (_3061 == 0) {
            goto L85;
        }
    }
    else {
        if (DBL_PTR(_3061)->dbl == 0.0) {
            goto L85;
        }
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (_2875 == 1)
        _2875 = 1;
    else if (IS_ATOM_INT(_2875) && IS_ATOM_INT(1))
        _2875 = 0;
    else
        _2875 = (compare(_2875, 1) == 0);
    DeRef1(_0);
L86:
    if (_2875 == 0)
        goto L85;

    // 	    op = PLUS1
    _op = 93;

    // 	    emit_opcode(op)
    _15emit_opcode(93);

    // 	    emit_addr(b)
    _15emit_addr(_b);

    // 	    emit_addr(0)
    _15emit_addr(0);

    // 	    cont21d(op, a, b, FALSE)
    _15cont21d(93, _a, _b, 0);
    goto L15;
L85:

    // 	    Push(a)
    _15Push(_a);

    // 	    Push(b)
    _15Push(_b);

    // 	    cont21ii(op, FALSE)
    _15cont21ii(_op, 0);
L87:
    goto L15;
L82:

    //     elsif op = MULTIPLY then
    if (_op != 13)
        goto L88;

    // 	b = Pop()
    _b = _15Pop();

    // 	a = Pop()
    _a = _15Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 == 2);
    }
    else {
        _2875 = binary_op(EQUALS, _2875, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 == 0) {
            goto L89;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl == 0.0) {
            goto L89;
        }
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (_3061 == 2)
        _3061 = 1;
    else if (IS_ATOM_INT(_3061) && IS_ATOM_INT(2))
        _3061 = 0;
    else
        _3061 = (compare(_3061, 2) == 0);
    DeRef1(_0);
L8A:
    if (_3061 == 0)
        goto L89;

    // 	    op = PLUS
    _op = 11;

    // 	    emit_opcode(op)
    _15emit_opcode(11);

    // 	    emit_addr(a)
    _15emit_addr(_a);

    // 	    emit_addr(a)
    _15emit_addr(_a);

    // 	    cont21d(op, a, b, FALSE)
    _15cont21d(11, _a, _b, 0);
    goto L15;
L89:

    // 	elsif SymTab[a][S_MODE] = M_CONSTANT and equal(SymTab[a][S_OBJ], 2) then
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 == 2);
    }
    else {
        _3061 = binary_op(EQUALS, _3061, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_3061)) {
        if (_3061 == 0) {
            goto L8B;
        }
    }
    else {
        if (DBL_PTR(_3061)->dbl == 0.0) {
            goto L8B;
        }
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _a);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (_2875 == 2)
        _2875 = 1;
    else if (IS_ATOM_INT(_2875) && IS_ATOM_INT(2))
        _2875 = 0;
    else
        _2875 = (compare(_2875, 2) == 0);
    DeRef1(_0);
L8C:
    if (_2875 == 0)
        goto L8B;

    // 	    op = PLUS
    _op = 11;

    // 	    emit_opcode(op)
    _15emit_opcode(11);

    // 	    emit_addr(b)
    _15emit_addr(_b);

    // 	    emit_addr(b)
    _15emit_addr(_b);

    // 	    cont21d(op, a, b, FALSE)
    _15cont21d(11, _a, _b, 0);
    goto L15;
L8B:

    // 	    Push(a)
    _15Push(_a);

    // 	    Push(b)
    _15Push(_b);

    // 	    cont21ii(op, FALSE)
    _15cont21ii(_op, 0);
L8D:
    goto L15;
L88:

    //     elsif op = DIVIDE then
    if (_op != 14)
        goto L8E;

    // 	b = Pop()
    _b = _15Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 == 2);
    }
    else {
        _2875 = binary_op(EQUALS, _2875, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 == 0) {
            goto L8F;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl == 0.0) {
            goto L8F;
        }
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (_3061 == 2)
        _3061 = 1;
    else if (IS_ATOM_INT(_3061) && IS_ATOM_INT(2))
        _3061 = 0;
    else
        _3061 = (compare(_3061, 2) == 0);
    DeRef1(_0);
L90:
    if (_3061 == 0)
        goto L8F;

    // 	    op = DIV2
    _op = 98;

    // 	    emit_opcode(op)
    _15emit_opcode(98);

    // 	    emit_addr(Pop()) -- n.b. "a" hasn't been set
    _0 = _3061;
    _3061 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_3061);

    // 	    a = 0
    _a = 0;

    // 	    emit_addr(0)
    _15emit_addr(0);

    // 	    cont21d(op, a, b, FALSE)  -- could have fractional result
    _15cont21d(98, 0, _b, 0);
    goto L15;
L8F:

    // 	    Push(b) 
    _15Push(_b);

    // 	    cont21ii(op, FALSE)
    _15cont21ii(_op, 0);
L91:
    goto L15;
L8E:

    //     elsif op = FLOOR then
    if (_op != 83)
        goto L92;

    // 	if previous_op = DIVIDE then
    if (_15previous_op != 14)
        goto L93;

    // 	    op = FLOOR_DIV
    _op = 63;

    // 	    backpatch(length(Code) - 3, op)
    DeRef1(_3061);
    _3061 = SEQ_PTR(_7Code)->length;
    _3061 = _3061 - 3;
    _15backpatch(_3061, 63);

    // 	    assignable = TRUE
    _15assignable = 1;
    goto L15;
L93:

    // 	elsif previous_op = DIV2 then
    if (_15previous_op != 98)
        goto L94;

    // 	    op = FLOOR_DIV2
    _op = 66;

    // 	    backpatch(length(Code) - 3, op)
    DeRef1(_3061);
    _3061 = SEQ_PTR(_7Code)->length;
    _3061 = _3061 - 3;
    _15backpatch(_3061, 66);

    // 	    assignable = TRUE
    _15assignable = 1;

    // 	    if IsInteger(Code[$-2]) then
    _3061 = SEQ_PTR(_7Code)->length;
    _3061 = _3061 - 2;
    _2 = (int)SEQ_PTR(_7Code);
    _3061 = (int)*(((s1_ptr)_2)->base + _3061);
    Ref(_3061);
    Ref(_3061);
    _0 = _3061;
    _3061 = _15IsInteger(_3061);
    DeRef1(_0);
    if (_3061 == 0)
        goto L15;

    // 		TempInteger(Top()) --mark temp as integer type
    _3061 = _15Top();
    Ref(_3061);
    _15TempInteger(_3061);
L95:
    goto L15;
L94:

    // 	    cont11ii(op, TRUE)
    _15cont11ii(_op, 1);
L96:
    goto L15;
L92:

    //     elsif find(op, {MINUS, APPEND, PREPEND, COMPARE, EQUAL, FIND, MATCH,
    DeRef1(_3061);
    _3061 = find(_op, _3177);
    if (_3061 == 0)
        goto L97;

    // 	cont21ii(op, FALSE)
    _15cont21ii(_op, 0);
    goto L15;
L97:

    //     elsif op = SC2_NULL then  -- correct the stack - we aren't emitting anything
    if (_op != 147)
        goto L98;

    // 	c = Pop()
    _c = _15Pop();

    // 	TempKeep(c)
    _15TempKeep(_c);

    // 	b = Pop()  -- remove SC1's temp
    _b = _15Pop();

    // 	Push(c)
    _15Push(_c);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L98:

    //     elsif op = SC2_AND or op = SC2_OR then
    DeRef1(_3061);
    _3061 = (_op == 144);
    if (_3061 != 0) {
        goto L99;
    }
    DeRef1(_2875);
    _2875 = (_op == 146);
L9A:
    if (_2875 == 0)
        goto L9B;
L99:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(Pop())       
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 	c = Pop()
    _c = _15Pop();

    // 	TempKeep(c)
    _15TempKeep(_c);

    // 	emit_addr(c) -- target
    _15emit_addr(_c);

    // 	TempInteger(c)
    _15TempInteger(_c);

    // 	Push(c)
    _15Push(_c);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L9B:

    //     elsif find(op, {MEM_COPY, MEM_SET, PRINTF}) then
    DeRef1(_2875);
    _2875 = find(_op, _3187);
    if (_2875 == 0)
        goto L9C;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	c = Pop()
    _c = _15Pop();

    // 	b = Pop()
    _b = _15Pop();

    // 	emit_addr(Pop())
    _2875 = _15Pop();
    _15emit_addr(_2875);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
L9C:

    //     elsif op = RHS_SLICE then -- rhs slice of a sequence a[i:j] 
    if (_op != 46)
        goto L9D;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	c = Pop()
    _c = _15Pop();

    // 	b = Pop()
    _b = _15Pop();

    // 	emit_addr(Pop())
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	assignable = TRUE
    _15assignable = 1;

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)
    _15emit_addr(_c);
    goto L15;
L9D:

    //     elsif op = CONCAT_N then     -- concatenate 3 or more items
    if (_op != 159)
        goto L9E;

    // 	n = op_info1  -- number of items to concatenate
    _n = _15op_info1;

    // 	emit_opcode(CONCAT_N)
    _15emit_opcode(159);

    // 	emit(n)
    _15emit(_n);

    // 	for i = 1 to n do 
    DeRef1(_2875);
    _2875 = _n;
    { int _i;
        _i = 1;
L9F:
        if (_i > _2875)
            goto LA0;

        // 	    emit_addr(Pop())  -- reverse order
        _0 = _3061;
        _3061 = _15Pop();
        DeRef(_0);
        _15emit_addr(_3061);

        // 	end for
        _i = _i + 1;
        goto L9F;
LA0:
        ;
    }

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	assignable = TRUE
    _15assignable = 1;

    // 	Push(c)
    _15Push(_c);
    goto L15;
L9E:

    //     elsif op = FOR then
    if (_op != 21)
        goto LA1;

    // 	c = Pop() -- increment 
    _c = _15Pop();

    // 	TempKeep(c)
    _15TempKeep(_c);

    // 	ic = IsInteger(c)
    _ic = _15IsInteger(_c);

    // 	if SymTab[c][S_MODE] = M_NORMAL and 
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 == 1);
    }
    else {
        _3061 = binary_op(EQUALS, _3061, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_3061)) {
        if (_3061 == 0) {
            DeRef1(_3061);
            _3061 = 0;
            goto LA2;
        }
    }
    else {
        if (DBL_PTR(_3061)->dbl == 0.0) {
            DeRef1(_3061);
            _3061 = 0;
            goto LA2;
        }
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 != 2);
    }
    else {
        _2875 = binary_op(NOTEQ, _2875, 2);
    }
    DeRef1(_0);
    DeRef1(_3061);
    if (IS_ATOM_INT(_2875))
        _3061 = (_2875 != 0);
    else
        _3061 = DBL_PTR(_2875)->dbl != 0.0;
LA2:
    if (_3061 == 0) {
        goto LA3;
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 != 4);
    }
    else {
        _3061 = binary_op(NOTEQ, _3061, 4);
    }
    DeRef1(_0);
LA4:
    if (_3061 == 0) {
        goto LA3;
    }
    else {
        if (!IS_ATOM_INT(_3061) && DBL_PTR(_3061)->dbl == 0.0)
            goto LA3;
    }

    // 	    emit_opcode(ASSIGN)
    _15emit_opcode(18);

    // 	    emit_addr(c)
    _15emit_addr(_c);

    // 	    c = NewTempSym()
    _c = _11NewTempSym();

    // 	    emit_addr(c)
    _15emit_addr(_c);
LA3:

    // 	b = Pop() -- limit 
    _b = _15Pop();

    // 	TempKeep(b)
    _15TempKeep(_b);

    // 	ib = IsInteger(b)
    _ib = _15IsInteger(_b);

    // 	if SymTab[b][S_MODE] = M_NORMAL and 
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 == 1);
    }
    else {
        _3061 = binary_op(EQUALS, _3061, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_3061)) {
        if (_3061 == 0) {
            DeRef1(_3061);
            _3061 = 0;
            goto LA5;
        }
    }
    else {
        if (DBL_PTR(_3061)->dbl == 0.0) {
            DeRef1(_3061);
            _3061 = 0;
            goto LA5;
        }
    }
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 != 2);
    }
    else {
        _2875 = binary_op(NOTEQ, _2875, 2);
    }
    DeRef1(_0);
    DeRef1(_3061);
    if (IS_ATOM_INT(_2875))
        _3061 = (_2875 != 0);
    else
        _3061 = DBL_PTR(_2875)->dbl != 0.0;
LA5:
    if (_3061 == 0) {
        goto LA6;
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (IS_ATOM_INT(_3061)) {
        _3061 = (_3061 != 4);
    }
    else {
        _3061 = binary_op(NOTEQ, _3061, 4);
    }
    DeRef1(_0);
LA7:
    if (_3061 == 0) {
        goto LA6;
    }
    else {
        if (!IS_ATOM_INT(_3061) && DBL_PTR(_3061)->dbl == 0.0)
            goto LA6;
    }

    // 	    emit_opcode(ASSIGN)
    _15emit_opcode(18);

    // 	    emit_addr(b)
    _15emit_addr(_b);

    // 	    b = NewTempSym()
    _b = _11NewTempSym();

    // 	    emit_addr(b)
    _15emit_addr(_b);
LA6:

    // 	a = Pop() -- initial value 
    _a = _15Pop();

    // 	if IsInteger(a) and ib and ic then
    _0 = _3061;
    _3061 = _15IsInteger(_a);
    DeRef1(_0);
    if (_3061 == 0) {
        _3061 = 0;
        goto LA8;
    }
    _3061 = (_ib != 0);
LA8:
    if (_3061 == 0) {
        goto LA9;
    }
LAA:
    if (_ic == 0)
        goto LA9;

    // 	    SymTab[op_info1][S_VTYPE] = integer_type
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_15op_info1 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _11integer_type;
    DeRef(_1);

    // 	    op = FOR_I
    _op = 125;
    goto LAB;
LA9:

    // 	    op = FOR
    _op = 21;
LAB:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	emit_addr(a)
    _15emit_addr(_a);

    // 	emit_addr(CurrentSub) -- in case recursion check is needed
    _15emit_addr(_7CurrentSub);

    // 	Push(b) 
    _15Push(_b);

    // 	Push(c) 
    _15Push(_c);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LA1:

    //     elsif op = ENDFOR_GENERAL or op = ENDFOR_INT_UP1 then  -- all ENDFORs  
    DeRef1(_2875);
    _2875 = (_op == 39);
    if (_2875 != 0) {
        goto LAC;
    }
    DeRef1(_3061);
    _3061 = (_op == 54);
LAD:
    if (_3061 == 0)
        goto LAE;
LAC:

    // 	emit_opcode(op) -- will be patched at runtime 
    _15emit_opcode(_op);

    // 	a = Pop() 
    _a = _15Pop();

    // 	emit_addr(op_info2) -- address of top of loop 
    _15emit_addr(_15op_info2);

    // 	emit_addr(Pop())    -- limit 
    _0 = _3061;
    _3061 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_3061);

    // 	emit_addr(op_info1) -- loop var 
    _15emit_addr(_15op_info1);

    // 	emit_addr(a)        -- increment - not always used - 
    _15emit_addr(_a);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LAE:

    //     elsif op = ASSIGN_OP_SUBS or op = PASSIGN_OP_SUBS then   
    DeRef1(_3061);
    _3061 = (_op == 151);
    if (_3061 != 0) {
        goto LAF;
    }
    DeRef1(_2875);
    _2875 = (_op == 166);
LB0:
    if (_2875 == 0)
        goto LB1;
LAF:

    // 	b = Pop()      -- rhs value, keep on stack 
    _b = _15Pop();

    // 	TempKeep(b)
    _15TempKeep(_b);

    // 	a = Pop()      -- subscript, keep on stack
    _a = _15Pop();

    // 	TempKeep(a)
    _15TempKeep(_a);

    // 	c = Pop()      -- lhs sequence, keep on stack
    _c = _15Pop();

    // 	TempKeep(c)
    _15TempKeep(_c);

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(c)  
    _15emit_addr(_c);

    // 	emit_addr(a)    
    _15emit_addr(_a);

    // 	d = NewTempSym()
    _d = _11NewTempSym();

    // 	emit_addr(d)   -- place to store result
    _15emit_addr(_d);

    // 	Push(c)
    _15Push(_c);

    // 	Push(a)
    _15Push(_a);

    // 	Push(d)
    _15Push(_d);

    // 	Push(b)
    _15Push(_b);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LB1:

    //     elsif op = ASSIGN_SLICE or op = PASSIGN_SLICE then
    DeRef1(_2875);
    _2875 = (_op == 45);
    if (_2875 != 0) {
        goto LB2;
    }
    DeRef1(_3061);
    _3061 = (_op == 165);
LB3:
    if (_3061 == 0)
        goto LB4;
LB2:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	b = Pop() -- rhs value
    _b = _15Pop();

    // 	a = Pop() -- 2nd subs
    _a = _15Pop();

    // 	c = Pop() -- 1st subs 
    _c = _15Pop();

    // 	emit_addr(Pop()) -- sequence
    _0 = _3061;
    _3061 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_3061);

    // 	emit_addr(c)
    _15emit_addr(_c);

    // 	emit_addr(a)  
    _15emit_addr(_a);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LB4:

    //     elsif op = ASSIGN_OP_SLICE or op = PASSIGN_OP_SLICE then  
    DeRef1(_3061);
    _3061 = (_op == 152);
    if (_3061 != 0) {
        goto LB5;
    }
    DeRef1(_2875);
    _2875 = (_op == 167);
LB6:
    if (_2875 == 0)
        goto LB7;
LB5:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	b = Pop()        -- rhs value not used
    _b = _15Pop();

    // 	TempKeep(b)
    _15TempKeep(_b);

    // 	a = Pop()        -- 2nd subs
    _a = _15Pop();

    // 	TempKeep(a)
    _15TempKeep(_a);

    // 	c = Pop()        -- 1st subs
    _c = _15Pop();

    // 	TempKeep(c)
    _15TempKeep(_c);

    // 	d = Pop()
    _d = _15Pop();

    // 	TempKeep(d)      -- sequence   
    _15TempKeep(_d);

    // 	emit_addr(d) 
    _15emit_addr(_d);

    // 	Push(d)
    _15Push(_d);

    // 	emit_addr(c) 
    _15emit_addr(_c);

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(a) 
    _15emit_addr(_a);

    // 	Push(a)
    _15Push(_a);

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)     -- place to store result
    _15emit_addr(_c);

    // 	Push(b)
    _15Push(_b);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LB7:

    //     elsif op = CALL_PROC or op = EMBEDDED_PROCEDURE_CALL then
    DeRef1(_2875);
    _2875 = (_op == 138);
    if (_2875 != 0) {
        goto LB8;
    }
    DeRef1(_3061);
    _3061 = (_op == 179);
LB9:
    if (_3061 == 0)
        goto LBA;
LB8:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	b = Pop()
    _b = _15Pop();

    // 	emit_addr(Pop())
    _0 = _3061;
    _3061 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_3061);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LBA:

    //     elsif op = CALL_FUNC or op = EMBEDDED_FUNCTION_CALL then
    DeRef1(_3061);
    _3061 = (_op == 139);
    if (_3061 != 0) {
        goto LBB;
    }
    DeRef1(_2875);
    _2875 = (_op == 180);
LBC:
    if (_2875 == 0)
        goto LBD;
LBB:

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	b = Pop()
    _b = _15Pop();

    // 	emit_addr(Pop())
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 	emit_addr(b)
    _15emit_addr(_b);

    // 	assignable = TRUE
    _15assignable = 1;

    // 	c = NewTempSym() 
    _c = _11NewTempSym();

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)
    _15emit_addr(_c);
    goto L15;
LBD:

    //     elsif op = RETURNP then
    if (_op != 29)
        goto LBE;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(CurrentSub)
    _15emit_addr(_7CurrentSub);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LBE:

    //     elsif op = RETURNF then
    if (_op != 28)
        goto LBF;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(CurrentSub)
    _15emit_addr(_7CurrentSub);

    // 	emit_addr(Pop())
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LBF:

    //     elsif op = RETURNT then
    if (_op != 34)
        goto LC0;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LC0:

    //     elsif find(op, {DATE, TIME, SPACE_USED, GET_KEY, COMMAND_LINE}) then
    DeRef1(_2875);
    _2875 = find(_op, _3278);
    if (_2875 == 0)
        goto LC1;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	assignable = TRUE
    _15assignable = 1;

    // 	if op = GET_KEY then  -- it's in op_result as integer
    if (_op != 79)
        goto LC2;

    // 	    TempInteger(c)
    _15TempInteger(_c);
LC2:

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)
    _15emit_addr(_c);
    goto L15;
LC1:

    //     elsif find(op, {CLOSE, ABORT, CALL}) then
    DeRef1(_2875);
    _2875 = find(_op, _3282);
    if (_2875 == 0)
        goto LC3;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(Pop())       
    _2875 = _15Pop();
    _15emit_addr(_2875);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LC3:

    //     elsif op = POWER then
    if (_op != 72)
        goto LC4;

    // 	b = Pop()
    _b = _15Pop();

    // 	a = Pop()
    _a = _15Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then 
    DeRef1(_2875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2875 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_2875);
    _0 = _2875;
    _2 = (int)SEQ_PTR(_2875);
    _2875 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2875);
    DeRef1(_0);
    _0 = _2875;
    if (IS_ATOM_INT(_2875)) {
        _2875 = (_2875 == 2);
    }
    else {
        _2875 = binary_op(EQUALS, _2875, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2875)) {
        if (_2875 == 0) {
            goto LC5;
        }
    }
    else {
        if (DBL_PTR(_2875)->dbl == 0.0) {
            goto LC5;
        }
    }
    DeRef1(_3061);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3061 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_3061);
    _0 = _3061;
    _2 = (int)SEQ_PTR(_3061);
    _3061 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3061);
    DeRef1(_0);
    _0 = _3061;
    if (_3061 == 2)
        _3061 = 1;
    else if (IS_ATOM_INT(_3061) && IS_ATOM_INT(2))
        _3061 = 0;
    else
        _3061 = (compare(_3061, 2) == 0);
    DeRef1(_0);
LC6:
    if (_3061 == 0)
        goto LC5;

    // 	    op = MULTIPLY
    _op = 13;

    // 	    emit_opcode(op)
    _15emit_opcode(13);

    // 	    emit_addr(a)
    _15emit_addr(_a);

    // 	    emit_addr(a)
    _15emit_addr(_a);

    // 	    cont21d(op, a, b, FALSE)
    _15cont21d(13, _a, _b, 0);
    goto L15;
LC5:

    // 	    Push(a)
    _15Push(_a);

    // 	    Push(b)
    _15Push(_b);

    // 	    cont21ii(op, FALSE)
    _15cont21ii(_op, 0);
LC7:
    goto L15;
LC4:

    //     elsif op = TYPE_CHECK then
    if (_op != 65)
        goto LC8;

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	c = Pop()       
    _c = _15Pop();

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LC8:

    //     elsif op = DOLLAR then
    if (_op != -22)
        goto LC9;

    // 	if lhs_ptr and length(current_sequence) = 1 then
    if (_15lhs_ptr == 0) {
        goto LCA;
    }
    DeRef1(_2875);
    _2875 = SEQ_PTR(_15current_sequence)->length;
    _2875 = (_2875 == 1);
LCB:
    if (_2875 == 0)
        goto LCA;

    // 	    emit_opcode(PLENGTH)
    _15emit_opcode(162);
    goto LCC;
LCA:

    // 	    emit_opcode(LENGTH) 
    _15emit_opcode(42);
LCC:

    // 	emit_addr(current_sequence[$])
    DeRef1(_2875);
    _2875 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _2875 = (int)*(((s1_ptr)_2)->base + _2875);
    Ref(_2875);
    Ref(_2875);
    _15emit_addr(_2875);

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	TempInteger(c)
    _15TempInteger(_c);

    // 	Push(c)
    _15Push(_c);

    // 	emit_addr(c)
    _15emit_addr(_c);
    goto L15;
LC9:

    //     elsif op = PLATFORM then -- always optimized - no code emitted 
    if (_op != 157)
        goto LCD;

    // 	if ELINUX then
    if (_7ELINUX == 0)
        goto LCE;

    // 	    n = 3
    _n = 3;
    goto LCF;
LCE:

    // 	elsif BIND then

    // 	elsif EDOS then        
    if (_7EDOS == 0)
        goto LD0;

    // 	    n = 1
    _n = 1;
    goto LCF;
LD0:

    // 	elsif EWINDOWS then
    if (_7EWINDOWS == 0)
        goto LD1;

    // 	    n = 2 
    _n = 2;
LD1:
LCF:

    // 	Push(NewIntSym(n))
    _0 = _2875;
    _2875 = _11NewIntSym(_n);
    DeRef1(_0);
    _15Push(_2875);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LCD:

    //     elsif op = PROFILE then
    if (_op != 153)
        goto LD2;

    // 	a = Pop()
    _a = _15Pop();

    // 	emit_opcode(op)
    _15emit_opcode(_op);

    // 	emit_addr(a)       
    _15emit_addr(_a);

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LD2:

    //     elsif op = TRACE then
    if (_op != 64)
        goto LD3;

    // 	a = Pop()
    _a = _15Pop();

    // 	if OpTrace then
    if (_7OpTrace == 0)
        goto LD4;

    // 	    emit_opcode(op)
    _15emit_opcode(_op);

    // 	    emit_addr(a)       
    _15emit_addr(_a);

    // 	    if TRANSLATE then
LD4:

    // 	assignable = FALSE
    _15assignable = 0;
    goto L15;
LD3:

    // 	elsif op = VAR_ID then
    if (_op != 171)
        goto LD5;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LD6;

    // 			CompileErr("var_id() not allowed in preprocessing")
    RefDS(_3314);
    _9CompileErr(_3314);
LD6:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		source = Pop()
    _source = _15Pop();

    // 		if TRANSLATE then

    // 		emit_addr(CurrentSub)
    _15emit_addr(_7CurrentSub);

    // 		    emit_addr(length(SymTab))
    DeRef1(_2875);
    _2875 = SEQ_PTR(_7SymTab)->length;
    _15emit_addr(_2875);
LD7:

    // 		emit_addr(source)
    _15emit_addr(_source);

    // 		emit_addr(current_file_no)  -- necessary at top level
    _15emit_addr(_7current_file_no);

    // 		assignable = TRUE
    _15assignable = 1;

    // 		c = NewTempSym()
    _c = _11NewTempSym();

    // 		TempInteger(c) -- result will always be an integer
    _15TempInteger(_c);

    // 		Push(c)
    _15Push(_c);

    // 		emit_addr(c)
    _15emit_addr(_c);
    goto L15;
LD5:

    // 	elsif op = READ_VAR then
    if (_op != 172)
        goto LD8;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LD9;

    // 			CompileErr("read_var() not allowed in preprocessing")
    RefDS(_3320);
    _9CompileErr(_3320);
LD9:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		emit_addr( Pop() )
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 		assignable = TRUE
    _15assignable = 1;

    // 		c = NewTempSym()
    _c = _11NewTempSym();

    // 		Push(c)
    _15Push(_c);

    // 		emit_addr(c)
    _15emit_addr(_c);
    goto L15;
LD8:

    // 	elsif op = WRITE_VAR then
    if (_op != 173)
        goto LDA;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LDB;

    // 			CompileErr("write_var() not allowed in preprocessing")
    RefDS(_3324);
    _9CompileErr(_3324);
LDB:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		b = Pop()
    _b = _15Pop();

    // 		emit_addr(Pop())
    _0 = _2875;
    _2875 = _15Pop();
    DeRef1(_0);
    _15emit_addr(_2875);

    // 		emit_addr(b)
    _15emit_addr(_b);

    // 		assignable = FALSE		
    _15assignable = 0;
    goto L15;
LDA:

    // 	elsif op = DUMP_VARS then
    if (_op != 174)
        goto LDC;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LDD;

    // 			CompileErr("dump_vars() not allowed in preprocessing")
    RefDS(_3328);
    _9CompileErr(_3328);
LDD:

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		a = NewTempSym() -- allocate *after* checking opnd types
    _a = _11NewTempSym();

    // 	    Push(a)
    _15Push(_a);

    // 	    emit_addr(a)
    _15emit_addr(_a);

    // 	    assignable = TRUE	
    _15assignable = 1;
    goto L15;
LDC:

    // 	elsif op = EVAL then
    if (_op != 169)
        goto LDE;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LDF;

    // 			CompileErr("eval() not allowed in preprocessing")
    RefDS(_3331);
    _9CompileErr(_3331);
LDF:

    // 		file_eval[current_file_no] = 1
    _2 = (int)SEQ_PTR(_7file_eval);
    _2 = (int)(((s1_ptr)_2)->base + _7current_file_no);
    *(int *)_2 = 1;

    // 		eval_used = 1
    _7eval_used = 1;

    // 		cont11ii(op, FALSE)   
    _15cont11ii(_op, 0);
    goto L15;
LDE:

    // 	elsif op = EVAL_ERROR then
    if (_op != 170)
        goto LE0;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LE1;

    // 			CompileErr("eval_error() not allowed in preprocessing")
    RefDS(_3333);
    _9CompileErr(_3333);
LE1:

    // 		file_eval[current_file_no] = 1
    _2 = (int)SEQ_PTR(_7file_eval);
    _2 = (int)(((s1_ptr)_2)->base + _7current_file_no);
    *(int *)_2 = 1;

    // 		eval_used = 1
    _7eval_used = 1;

    // 		emit_opcode(op)
    _15emit_opcode(_op);

    // 		a = NewTempSym() -- allocate *after* checking opnd types
    _a = _11NewTempSym();

    // 	    Push(a)
    _15Push(_a);

    // 	    emit_addr(a)
    _15emit_addr(_a);
    goto L15;
LE0:

    // 	elsif op = GOTO then
    if (_op != 175)
        goto LE2;

    // 		goto_back_patch[$] &= length(Code) + 1
    DeRef1(_2875);
    _2875 = SEQ_PTR(_7goto_back_patch)->length;
    DeRef1(_3061);
    _3061 = SEQ_PTR(_7Code)->length;
    _3061 = _3061 + 1;
    DeRef1(_2832);
    _2 = (int)SEQ_PTR(_7goto_back_patch);
    _2832 = (int)*(((s1_ptr)_2)->base + _2875);
    Ref(_2832);
    if (IS_SEQUENCE(_2832) && IS_ATOM(_3061)) {
        Append(&_2832, _2832, _3061);
    }
    else if (IS_ATOM(_2832) && IS_SEQUENCE(_3061)) {
    }
    else {
        Concat((object_ptr)&_2832, _2832, (s1_ptr)_3061);
    }
    RefDS(_2832);
    _2 = (int)SEQ_PTR(_7goto_back_patch);
    _2 = (int)(((s1_ptr)_2)->base + _2875);
    _1 = *(int *)_2;
    *(int *)_2 = _2832;
    DeRef(_1);

    // 		emit_opcode(GOTO)
    _15emit_opcode(175);

    // 		emit( Pop() )
    _0 = _2832;
    _2832 = _15Pop();
    DeRef1(_0);
    _15emit(_2832);

    // 		emit( Pop() )
    _2832 = _15Pop();
    _15emit(_2832);

    // 		emit( OpStrictGoto )
    _15emit(_7OpStrictGoto);
    goto L15;
LE2:

    // 	elsif op = GOTO_STATIC then
    if (_op != 176)
        goto LE3;

    // 		emit_opcode( GOTO_STATIC )
    _15emit_opcode(176);

    // 		emit( Pop() )
    _0 = _2832;
    _2832 = _15Pop();
    DeRef1(_0);
    _15emit(_2832);

    // 		emit( Pop() )
    _2832 = _15Pop();
    _15emit(_2832);

    // 		emit( NOP1 )
    _15emit(161);
    goto L15;
LE3:

    // 	elsif op = DEFAULT_GOTO then
    if (_op != 177)
        goto LE4;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LE5;

    // 			CompileErr("default_goto() not allowed in preprocessing" )
    RefDS(_3347);
    _9CompileErr(_3347);
LE5:

    // 		emit_opcode( op )
    _15emit_opcode(_op);

    // 		emit( current_file_no )
    _15emit(_7current_file_no);

    // 		emit( Pop() )
    _0 = _2832;
    _2832 = _15Pop();
    DeRef1(_0);
    _15emit(_2832);
    goto L15;
LE4:

    // 	elsif op = IS_GOTO then
    if (_op != 178)
        goto LE6;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LE7;

    // 			CompileErr("is_goto() not allowed in preprocessing" )
    RefDS(_3350);
    _9CompileErr(_3350);
LE7:

    // 		emit_opcode( op )
    _15emit_opcode(_op);

    // 		emit_opcode( current_file_no )
    _15emit_opcode(_7current_file_no);

    // 		emit_opcode( Pop() )
    _0 = _2832;
    _2832 = _15Pop();
    DeRef1(_0);
    _15emit_opcode(_2832);

    // 		a = NewTempSym()
    _a = _11NewTempSym();

    // 		Push(a)
    _15Push(_a);

    // 		emit_addr(a)
    _15emit_addr(_a);

    // 		assignable = TRUE
    _15assignable = 1;
    goto L15;
LE6:

    // 	elsif find( op, {FIND_FROM,MATCH_FROM}) then
    DeRef1(_2832);
    _2832 = find(_op, _3353);
    if (_2832 == 0)
        goto LE8;

    // 		if preprocess then
    if (_7preprocess == 0)
        goto LE9;

    // 			CompileErr("*_from() not allowed in preprocessing" )
    RefDS(_3355);
    _9CompileErr(_3355);
LE9:

    // 		emit_opcode( op )
    _15emit_opcode(_op);

    // 		a = Pop()
    _a = _15Pop();

    // 		b = Pop()
    _b = _15Pop();

    // 		c = Pop()
    _c = _15Pop();

    // 		emit_addr( c )
    _15emit_addr(_c);

    // 		emit_addr( b )
    _15emit_addr(_b);

    // 		emit_addr( a )
    _15emit_addr(_a);

    // 		a = NewTempSym()
    _a = _11NewTempSym();

    // 		TempInteger(a)
    _15TempInteger(_a);

    // 		Push(a)
    _15Push(_a);

    // 		emit_addr(a)
    _15emit_addr(_a);

    // 		assignable = FALSE
    _15assignable = 0;
    goto L15;
LE8:

    // 	InternalErr(sprintf("unknown opcode: %d", op))
    DeRef1(_2832);
    _2832 = EPrintf(-9999999, _3360, _op);
    RefDS(_2832);
    _9InternalErr(_2832);
L15:

    //     previous_op = op
    _15previous_op = _op;

    // end procedure
    DeRef1(_obj);
    DeRef1(_elements);
    DeRef1(_element_vals);
    DeRef(_2832);
    DeRef(_3061);
    DeRef(_2875);
    DeRef(_2850);
    return 0;
    ;
}


