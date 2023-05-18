// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _15Push(int _x)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     cg_stack = append(cg_stack, x)
    Append(&_15cg_stack, _15cg_stack, _x);

    // end procedure
    return 0;
    ;
}


int _15Top()
{
    int _2728 = 0;
    int _0, _1, _2;
    

    //     return cg_stack[$]
    _2728 = SEQ_PTR(_15cg_stack)->length;
    _2 = (int)SEQ_PTR(_15cg_stack);
    _2728 = (int)*(((s1_ptr)_2)->base + _2728);
    Ref(_2728);
    return _2728;
    ;
}


int _15Pop()
{
    int _t;
    int _2730 = 0;
    int _0, _1, _2, _3;
    

    //     t = cg_stack[$]
    _2730 = SEQ_PTR(_15cg_stack)->length;
    _2 = (int)SEQ_PTR(_15cg_stack);
    _t = (int)*(((s1_ptr)_2)->base + _2730);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    //     cg_stack = cg_stack[1..$-1]
    _2730 = SEQ_PTR(_15cg_stack)->length;
    _2730 = _2730 - 1;
    rhs_slice_target = (object_ptr)&_15cg_stack;
    RHS_Slice((s1_ptr)_15cg_stack, 1, _2730);

    //     if SymTab[t][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_7SymTab);
    _2730 = (int)*(((s1_ptr)_2)->base + _t);
    Ref(_2730);
    _0 = _2730;
    _2 = (int)SEQ_PTR(_2730);
    _2730 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2730);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _2730, 3))
        goto L1;

    // 	SymTab[t][S_SCOPE] = FREE -- mark it as being free
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_t + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L1:

    //     return t    
    DeRef(_2730);
    return _t;
    ;
}


int _15PopMember()
{
    int _x;
    int _2740 = 0;
    int _0, _1, _2;
    

    // 	member_stack &= - Pop()
    _2740 = _15Pop();
    if (_2740 == 0xC0000000)
        _2740 = (int)NewDouble((double)-0xC0000000);
    else
        _2740 = - _2740;
    Ref(_2740);
    Append(&_7member_stack, _7member_stack, _2740);

    // end procedure
    DeRef(_2740);
    return 0;
    ;
}


int _15TempKeep(int _x)
{
    int _2743 = 0;
    int _0, _1, _2, _3;
    

    //     if SymTab[x][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_7SymTab);
    _2743 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_2743);
    _0 = _2743;
    _2 = (int)SEQ_PTR(_2743);
    _2743 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2743);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _2743, 3))
        goto L1;

    // 	SymTab[x][S_SCOPE] = IN_USE
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_x + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_2743);
    return 0;
    ;
}


int _15TempFree(int _x)
{
    int _2748 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //    if SymTab[x][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_7SymTab);
    _2748 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_2748);
    _0 = _2748;
    _2 = (int)SEQ_PTR(_2748);
    _2748 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2748);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _2748, 3))
        goto L1;

    //        SymTab[x][S_SCOPE] = FREE 
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_x + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_2748);
    return 0;
    ;
}


int _15TempInteger(int _x)
{
    int _2753 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     if SymTab[x][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_7SymTab);
    _2753 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_2753);
    _0 = _2753;
    _2 = (int)SEQ_PTR(_2753);
    _2753 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2753);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _2753, 3))
        goto L1;

    // 	SymTab[x][S_USAGE] = T_INTEGER
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_x + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_2753);
    return 0;
    ;
}


int _15LexName(int _t)
{
    int _i;
    int _2761 = 0;
    int _2758;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_t)) {
        _1 = (long)(DBL_PTR(_t)->dbl);
        DeRefDS(_t);
        _t = _1;
    }

    //     i = 1
    _i = 1;

    //     while i <= length(token_name) and t != token_name[i][LEX_NUMBER] do
L1:
    _2758 = 64;
    _2758 = (_i <= 64);
    if (_2758 == 0) {
        goto L2;
    }
    DeRef(_2761);
    _2 = (int)SEQ_PTR(_15token_name);
    _2761 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_2761);
    _0 = _2761;
    _2 = (int)SEQ_PTR(_2761);
    _2761 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2761);
    DeRefDS(_0);
    _0 = _2761;
    if (IS_ATOM_INT(_2761)) {
        _2761 = (_t != _2761);
    }
    else {
        _2761 = binary_op(NOTEQ, _t, _2761);
    }
    DeRef(_0);
L3:
    if (_2761 <= 0) {
        if (_2761 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_2761) && DBL_PTR(_2761)->dbl == 0.0)
                goto L2;
        }
    }

    // 	i += 1
    _i = _i + 1;

    //     end while
    goto L1;
L2:

    //     if i > length(token_name) then
    DeRef(_2761);
    _2761 = 64;
    if (_i <= 64)
        goto L4;

    // 	return "this ..." -- try to avoid this case 
    RefDS(_2767);
    return _2767;
    goto L5;
L4:

    // 	return token_name[i][LEX_NAME]
    DeRef(_2761);
    _2 = (int)SEQ_PTR(_15token_name);
    _2761 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_2761);
    _0 = _2761;
    _2 = (int)SEQ_PTR(_2761);
    _2761 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2761);
    DeRefDS(_0);
    return _2761;
L5:
    ;
}


int _15InitEmit()
{
    int _0, _1, _2;
    

    //     cg_stack = {}
    RefDS(_39);
    DeRef(_15cg_stack);
    _15cg_stack = _39;

    // end procedure
    return 0;
    ;
}


int _15IsInteger(int _sym)
{
    int _mode;
    int _t;
    int _pt;
    int _2779 = 0;
    int _2770 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    //     mode = SymTab[sym][S_MODE]
    _2 = (int)SEQ_PTR(_7SymTab);
    _2770 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2770);
    _2 = (int)SEQ_PTR(_2770);
    _mode = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_mode))
        _mode = (long)DBL_PTR(_mode)->dbl;

    //     if mode = M_NORMAL then
    if (_mode != 1)
        goto L1;

    // 	t = SymTab[sym][S_VTYPE] 
    DeRef(_2770);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2770 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2770);
    _2 = (int)SEQ_PTR(_2770);
    _t = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    // 	if t = integer_type then
    if (_t != _11integer_type)
        goto L2;

    // 	    return TRUE
    DeRef(_2770);
    return 1;
L2:

    // 	if t then
    if (_t == 0)
        goto L3;

    // 	    pt = SymTab[t][S_NEXT]
    DeRef(_2770);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2770 = (int)*(((s1_ptr)_2)->base + _t);
    Ref(_2770);
    _2 = (int)SEQ_PTR(_2770);
    _pt = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_pt))
        _pt = (long)DBL_PTR(_pt)->dbl;

    // 	    if pt and SymTab[pt][S_VTYPE] = integer_type then
    if (_pt == 0) {
        goto L3;
    }
    DeRef(_2779);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2779 = (int)*(((s1_ptr)_2)->base + _pt);
    Ref(_2779);
    _0 = _2779;
    _2 = (int)SEQ_PTR(_2779);
    _2779 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2779);
    DeRef(_0);
    _0 = _2779;
    if (IS_ATOM_INT(_2779)) {
        _2779 = (_2779 == _11integer_type);
    }
    else {
        _2779 = binary_op(EQUALS, _2779, _11integer_type);
    }
    DeRef(_0);
L4:
    if (_2779 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_2779) && DBL_PTR(_2779)->dbl == 0.0)
            goto L3;
    }

    // 		return TRUE   -- usertype(integer x)
    DeRef(_2779);
    DeRef(_2770);
    return 1;
L5:
L6:
    goto L3;
L1:

    //     elsif mode = M_CONSTANT then
    if (_mode != 2)
        goto L7;

    // 	if integer(SymTab[sym][S_OBJ]) then  -- bug fixed: can't allow PLUS1_I op 
    DeRef(_2779);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2779 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2779);
    _0 = _2779;
    _2 = (int)SEQ_PTR(_2779);
    _2779 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2779);
    DeRef(_0);
    _0 = _2779;
    if (IS_ATOM_INT(_2779))
        _2779 = 1;
    else if (IS_ATOM_DBL(_2779))
        _2779 = IS_ATOM_INT(DoubleToInt(_2779));
    else
        _2779 = 0;
    DeRef(_0);
    if (_2779 == 0)
        goto L3;

    // 	    return TRUE
    DeRef(_2770);
    return 1;
L8:
    goto L3;
L7:

    //     elsif mode = M_TEMP then
    if (_mode != 3)
        goto L9;

    // 	if SymTab[sym][S_USAGE] = T_INTEGER then
    DeRef(_2779);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2779 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2779);
    _0 = _2779;
    _2 = (int)SEQ_PTR(_2779);
    _2779 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_2779);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _2779, 1))
        goto LA;

    // 	    return TRUE
    DeRef(_2779);
    DeRef(_2770);
    return 1;
LA:
L9:
L3:

    //     return FALSE
    DeRef(_2779);
    DeRef(_2770);
    return 0;
    ;
}


int _15emit(int _val)
{
    int _0, _1, _2;
    

    //     Code = append(Code, val)
    Append(&_7Code, _7Code, _val);

    // end procedure
    return 0;
    ;
}


int _15emit_opnd(int _opnd)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_opnd)) {
        _1 = (long)(DBL_PTR(_opnd)->dbl);
        DeRefDS(_opnd);
        _opnd = _1;
    }

    //     Push(opnd)
    _15Push(_opnd);

    //     previous_op = -1  -- N.B.
    _15previous_op = -1;

    // end procedure
    return 0;
    ;
}


int _15emit_addr(int _x)
{
    int _0, _1, _2;
    

    //     Code = append(Code, x)
    Ref(_x);
    Append(&_7Code, _7Code, _x);

    // end procedure
    DeRef(_x);
    return 0;
    ;
}


int _15emit_opcode(int _op)
{
    int _0, _1, _2;
    

    //     Code = append(Code, op)
    Append(&_7Code, _7Code, _op);

    // end procedure
    return 0;
    ;
}


int _15backpatch(int _index, int _val)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_index)) {
        _1 = (long)(DBL_PTR(_index)->dbl);
        DeRefDS(_index);
        _index = _1;
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }

    //     Code[index] = val
    _2 = (int)SEQ_PTR(_7Code);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7Code = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _index);
    _1 = *(int *)_2;
    *(int *)_2 = _val;
    DeRef(_1);

    // end procedure
    return 0;
    ;
}


int _15cont11ii(int _op, int _ii)
{
    int _t;
    int _source;
    int _c;
    int _2799;
    int _2798;
    int _2794;
    int _0, _1, _2;
    

    //     emit_opcode(op)
    _15emit_opcode(_op);

    //     source = Pop()
    _source = _15Pop();

    //     emit_addr(source)
    _15emit_addr(_source);

    //     assignable = TRUE
    _15assignable = 1;

    //     t = op_result[op]
    _2 = (int)SEQ_PTR(_15op_result);
    _t = (int)*(((s1_ptr)_2)->base + _op);

    //     if t = T_INTEGER or (ii and IsInteger(source)) then
    _2794 = (_t == 1);
    if (_2794 != 0) {
        goto L1;
    }
    if (_ii == 0) {
        _2798 = 0;
        goto L2;
    }
    _2799 = _15IsInteger(_source);
    _2798 = (_2799 != 0);
L2:
L3:
    if (_2798 == 0)
        goto L4;
L1:

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	TempInteger(c)
    _15TempInteger(_c);
    goto L5;
L4:

    // 	c = NewTempSym() -- allocate *after* checking opnd type
    _c = _11NewTempSym();
L5:

    //     Push(c)
    _15Push(_c);

    //     emit_addr(c)
    _15emit_addr(_c);

    // end procedure
    return 0;
    ;
}


int _15cont21d(int _op, int _a, int _b, int _ii)
{
    int _c;
    int _t;
    int _2805;
    int _2806;
    int _2802;
    int _0, _1, _2;
    

    //     assignable = TRUE
    _15assignable = 1;

    //     t = op_result[op]
    _2 = (int)SEQ_PTR(_15op_result);
    _t = (int)*(((s1_ptr)_2)->base + _op);

    //     if t = T_INTEGER or (ii and IsInteger(a) and IsInteger(b)) then
    _2802 = (_t == 1);
    if (_2802 != 0) {
        goto L1;
    }
    if (_ii == 0) {
        _2805 = 0;
        goto L2;
    }
    _2806 = _15IsInteger(_a);
    _2805 = (_2806 != 0);
L2:
    if (_2805 == 0) {
        _2806 = 0;
        goto L3;
    }
    _2805 = _15IsInteger(_b);
    _2806 = (_2805 != 0);
L3:
L4:
    if (_2806 == 0)
        goto L5;
L1:

    // 	c = NewTempSym()
    _c = _11NewTempSym();

    // 	TempInteger(c)
    _15TempInteger(_c);
    goto L6;
L5:

    // 	c = NewTempSym() -- allocate *after* checking opnd types
    _c = _11NewTempSym();
L6:

    //     Push(c)
    _15Push(_c);

    //     emit_addr(c)
    _15emit_addr(_c);

    // end procedure
    return 0;
    ;
}


int _15cont21ii(int _op, int _ii)
{
    int _a;
    int _b;
    int _0, _1, _2;
    

    //     b = Pop()
    _b = _15Pop();

    //     emit_opcode(op)
    _15emit_opcode(_op);

    //     a = Pop()
    _a = _15Pop();

    //     emit_addr(a)
    _15emit_addr(_a);

    //     emit_addr(b)
    _15emit_addr(_b);

    //     cont21d(op, a, b, ii)
    _15cont21d(_op, _a, _b, _ii);

    // end procedure
    return 0;
    ;
}


int _15good_string(int _elements)
{
    int _obj = 0;
    int _e;
    int _element_vals = 0;
    int _2830 = 0;
    int _2828 = 0;
    int _2813 = 0;
    int _2824;
    int _2814;
    int _0, _1, _2;
    

    //     if TRANSLATE and length(elements) > 10000 then
    if (0 == 0) {
        goto L1;
    }
    _2814 = SEQ_PTR(_elements)->length;
    _2814 = (_2814 > 10000);
L2:
    if (_2814 == 0)
        goto L1;

    // 	return -1 -- A huge string might upset the C compiler.
    DeRefDSi(_elements);
    DeRef(_obj);
    DeRef(_element_vals);
    DeRef(_2830);
    DeRef(_2828);
    DeRef(_2813);
    return -1;
L1:

    //     element_vals = {}
    RefDS(_39);
    DeRef(_element_vals);
    _element_vals = _39;

    //     for i = 1 to length(elements) do
    _2814 = SEQ_PTR(_elements)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _2814)
            goto L4;

        // 	e = elements[i]
        _2 = (int)SEQ_PTR(_elements);
        _e = (int)*(((s1_ptr)_2)->base + _i);

        // 	obj = SymTab[e][S_OBJ]
        DeRef(_2813);
        _2 = (int)SEQ_PTR(_7SymTab);
        _2813 = (int)*(((s1_ptr)_2)->base + _e);
        Ref(_2813);
        DeRef(_obj);
        _2 = (int)SEQ_PTR(_2813);
        _obj = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_obj);

        // 	if SymTab[e][S_MODE] = M_CONSTANT and
        DeRef(_2813);
        _2 = (int)SEQ_PTR(_7SymTab);
        _2813 = (int)*(((s1_ptr)_2)->base + _e);
        Ref(_2813);
        _0 = _2813;
        _2 = (int)SEQ_PTR(_2813);
        _2813 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_2813);
        DeRef(_0);
        _0 = _2813;
        if (IS_ATOM_INT(_2813)) {
            _2813 = (_2813 == 2);
        }
        else {
            _2813 = binary_op(EQUALS, _2813, 2);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_2813)) {
            if (_2813 == 0) {
                DeRef(_2813);
                _2813 = 0;
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_2813)->dbl == 0.0) {
                DeRef(_2813);
                _2813 = 0;
                goto L5;
            }
        }
        if (IS_ATOM_INT(_obj))
            _2824 = 1;
        else if (IS_ATOM_DBL(_obj))
            _2824 = IS_ATOM_INT(DoubleToInt(_obj));
        else
            _2824 = 0;
        DeRef(_2813);
        _2813 = (_2824 != 0);
L5:
        if (_2813 == 0) {
            goto L6;
        }
        DeRef(_2813);
        _2813 = (0 == 0);
        if (_2813 != 0) {
            _2813 = 1;
            goto L7;
        }
        DeRef(_2828);
        if (IS_ATOM_INT(_obj)) {
            _2828 = (_obj >= 1);
        }
        else {
            _2828 = binary_op(GREATEREQ, _obj, 1);
        }
        if (IS_ATOM_INT(_2828)) {
            if (_2828 == 0) {
                DeRef(_2828);
                _2828 = 0;
                goto L8;
            }
        }
        else {
            if (DBL_PTR(_2828)->dbl == 0.0) {
                DeRef(_2828);
                _2828 = 0;
                goto L8;
            }
        }
        DeRef(_2830);
        if (IS_ATOM_INT(_obj)) {
            _2830 = (_obj <= 255);
        }
        else {
            _2830 = binary_op(LESSEQ, _obj, 255);
        }
        DeRef(_2828);
        if (IS_ATOM_INT(_2830))
            _2828 = (_2830 != 0);
        else
            _2828 = DBL_PTR(_2830)->dbl != 0.0;
L8:
        DeRef(_2813);
        _2813 = (_2828 != 0);
L7:
L9:
        if (_2813 == 0)
            goto L6;

        // 	    element_vals = prepend(element_vals, obj)
        Ref(_obj);
        Prepend(&_element_vals, _element_vals, _obj);
        goto LA;
L6:

        // 	    return -1
        DeRefDSi(_elements);
        DeRef(_obj);
        DeRef(_element_vals);
        DeRef(_2830);
        DeRef(_2828);
        DeRef(_2813);
        return -1;
LA:

        //     end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    //     return element_vals
    DeRefDSi(_elements);
    DeRef(_obj);
    DeRef(_2830);
    DeRef(_2828);
    DeRef(_2813);
    return _element_vals;
    ;
}


