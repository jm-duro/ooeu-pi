// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17opPASSIGN_OP_SLICE()
{
    int _x = 0;
    int _7874 = 0;
    int _7857 = 0;
    int _7870 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _7857 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7857);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    //     x = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    //     b = Code[pc+2]
    _7857 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7857);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    //     c = Code[pc+3]
    _7857 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7857);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    //     target = Code[pc+4]
    _7857 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7857);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    //     lhs_seq_index = x[1]
    _2 = (int)SEQ_PTR(_x);
    _17lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_17lhs_seq_index))
        _17lhs_seq_index = (long)DBL_PTR(_17lhs_seq_index)->dbl;

    //     lhs_subs = x[2..$]
    _7857 = SEQ_PTR(_x)->length;
    rhs_slice_target = (object_ptr)&_17lhs_subs;
    RHS_Slice((s1_ptr)_x, 2, _7857);

    //     Code[pc+10] = Code[pc+1]
    _7857 = _17pc + 10;
    if ((long)((unsigned long)_7857 + (unsigned long)HIGH_BITS) >= 0) 
        _7857 = NewDouble((double)_7857);
    _7870 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _7870 = (int)*(((s1_ptr)_2)->base + _7870);
    Ref(_7870);
    Ref(_7870);
    _2 = (int)SEQ_PTR(_7Code);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7Code = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7857))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7857)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _7857);
    _1 = *(int *)_2;
    *(int *)_2 = _7870;
    DeRef(_1);

    //     val[target] = var_slice(val[lhs_seq_index], lhs_subs, val[b], val[c])
    DeRef(_7870);
    _2 = (int)SEQ_PTR(_17val);
    _7870 = (int)*(((s1_ptr)_2)->base + _17lhs_seq_index);
    Ref(_7870);
    DeRef(_7857);
    _2 = (int)SEQ_PTR(_17val);
    _7857 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7857);
    _2 = (int)SEQ_PTR(_17val);
    _7874 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7874);
    Ref(_7870);
    RefDS(_17lhs_subs);
    Ref(_7857);
    Ref(_7874);
    _0 = _7874;
    _7874 = _17var_slice(_7870, _17lhs_subs, _7857, _7874);
    DeRef(_0);
    Ref(_7874);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7874;
    DeRef(_1);

    //     pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRef(_x);
    DeRef(_7874);
    DeRef(_7857);
    DeRef(_7870);
    return 0;
    ;
}


int _17opASSIGN_SLICE()
{
    int _x = 0;
    int _7893 = 0;
    int _7877 = 0;
    int _7887 = 0;
    int _7888 = 0;
    int _0, _1, _2, _3;
    

    // 	a = Code[pc+1]	-- sequence
    _7877 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7877);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]	-- 1st index
    _7877 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7877);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]	-- 2nd index
    _7877 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7877);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	d = Code[pc+4]	-- rhs value to assign
    _7877 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17d = (int)*(((s1_ptr)_2)->base + _7877);
    if (!IS_ATOM_INT(_17d))
        _17d = (long)DBL_PTR(_17d)->dbl;

    // 	x = val[a] -- avoid lingering ref count on val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	lhs_check_slice(x,val[b],val[c],val[d])
    _2 = (int)SEQ_PTR(_17val);
    _7877 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7877);
    _2 = (int)SEQ_PTR(_17val);
    _7887 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7887);
    _2 = (int)SEQ_PTR(_17val);
    _7888 = (int)*(((s1_ptr)_2)->base + _17d);
    Ref(_7888);
    Ref(_x);
    Ref(_7877);
    Ref(_7887);
    Ref(_7888);
    _17lhs_check_slice(_x, _7877, _7887, _7888);

    // 	x = val[d]
    DeRef(_x);
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17d);
    Ref(_x);

    // 	val[a][val[b]..val[c]] = x
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _3 = (int)(_17a + ((s1_ptr)_2)->base);
    DeRef(_7877);
    _2 = (int)SEQ_PTR(_17val);
    _7877 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7877);
    _2 = (int)SEQ_PTR(_17val);
    _7893 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7893);
    assign_slice_seq = (s1_ptr *)_3;
    AssignSlice(_7877, _7893, _x);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRef(_x);
    DeRef(_7893);
    DeRef(_7877);
    DeRef(_7887);
    DeRef(_7888);
    return 0;
    ;
}


int _17opPASSIGN_SLICE()
{
    int _7911 = 0;
    int _7910 = 0;
    int _7895 = 0;
    int _7906 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]	-- sequence
    _7895 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7895);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]	-- 1st index
    _7895 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7895);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]	-- 2nd index
    _7895 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7895);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	d = Code[pc+4]	-- rhs value to assign
    _7895 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17d = (int)*(((s1_ptr)_2)->base + _7895);
    if (!IS_ATOM_INT(_17d))
        _17d = (long)DBL_PTR(_17d)->dbl;

    // 	lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_17val);
    _7895 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7895);
    _2 = (int)SEQ_PTR(_7895);
    _17lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_17lhs_seq_index))
        _17lhs_seq_index = (long)DBL_PTR(_17lhs_seq_index)->dbl;

    // 	lhs_subs = val[a][2..$]
    DeRef(_7895);
    _2 = (int)SEQ_PTR(_17val);
    _7895 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7895);
    _7906 = SEQ_PTR(_7895)->length;
    rhs_slice_target = (object_ptr)&_17lhs_subs;
    RHS_Slice((s1_ptr)_7895, 2, _7906);

    // 	val[lhs_seq_index] = assign_slice(val[lhs_seq_index],
    _2 = (int)SEQ_PTR(_17val);
    _7906 = (int)*(((s1_ptr)_2)->base + _17lhs_seq_index);
    Ref(_7906);
    DeRef(_7895);
    _2 = (int)SEQ_PTR(_17val);
    _7895 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7895);
    _2 = (int)SEQ_PTR(_17val);
    _7910 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7910);
    _2 = (int)SEQ_PTR(_17val);
    _7911 = (int)*(((s1_ptr)_2)->base + _17d);
    Ref(_7911);
    Ref(_7906);
    RefDS(_17lhs_subs);
    Ref(_7895);
    Ref(_7910);
    Ref(_7911);
    _0 = _7911;
    _7911 = _17assign_slice(_7906, _17lhs_subs, _7895, _7910, _7911);
    DeRef(_0);
    RefDS(_7911);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17lhs_seq_index);
    _1 = *(int *)_2;
    *(int *)_2 = _7911;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRefDS(_7911);
    DeRef(_7910);
    DeRef(_7895);
    DeRef(_7906);
    return 0;
    ;
}


int _17opRHS_SLICE()
{
    int _x = 0;
    int _7924 = 0;
    int _7914 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]	-- sequence
    _7914 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7914);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]	-- 1st index
    _7914 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _7914);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]	-- 2nd index
    _7914 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _7914);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	target = Code[pc+4]  
    _7914 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7914);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	x = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_x);

    // 	val[target] = x[val[b]..val[c]]   -- need checks here!
    _2 = (int)SEQ_PTR(_17val);
    _7914 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_7914);
    _2 = (int)SEQ_PTR(_17val);
    _7924 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_7924);
    rhs_slice_target = (object_ptr)&_7924;
    RHS_Slice((s1_ptr)_x, _7914, _7924);
    RefDS(_7924);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7924;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRef(_x);
    DeRefDS(_7924);
    DeRef(_7914);
    return 0;
    ;
}


int _17opTYPE_CHECK()
{
    int _7927 = 0;
    int _0, _1, _2;
    

    // 	if val[Code[pc-1]] = 0 then
    _7927 = _17pc - 1;
    _2 = (int)SEQ_PTR(_7Code);
    _7927 = (int)*(((s1_ptr)_2)->base + _7927);
    Ref(_7927);
    _0 = _7927;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_7927))
        _7927 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7927)->dbl));
    else
        _7927 = (int)*(((s1_ptr)_2)->base + _7927);
    Ref(_7927);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _7927, 0))
        goto L1;

    // 	RTFatalType(pc-2)
    DeRef(_7927);
    _7927 = _17pc - 2;
    if ((long)((unsigned long)_7927 +(unsigned long) HIGH_BITS) >= 0)
        _7927 = NewDouble((double)_7927);
    Ref(_7927);
    _17RTFatalType(_7927);

    // 	return
    DeRef(_7927);
    return 0;
L1:

    // 	pc += 1
    _17pc = _17pc + 1;

    // end procedure
    DeRef(_7927);
    return 0;
    ;
}


int _17opIS_AN_INTEGER()
{
    int _7933 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7933 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7933);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7933 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7933);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = integer(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7933 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7933);
    _0 = _7933;
    if (IS_ATOM_INT(_7933))
        _7933 = 1;
    else if (IS_ATOM_DBL(_7933))
        _7933 = IS_ATOM_INT(DoubleToInt(_7933));
    else
        _7933 = 0;
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7933;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    return 0;
    ;
}


int _17opIS_AN_ATOM()
{
    int _7940 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7940 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7940);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7940 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7940);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = atom(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7940 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7940);
    _0 = _7940;
    _7940 = IS_ATOM(_7940);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7940;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    return 0;
    ;
}


int _17opIS_A_SEQUENCE()
{
    int _7947 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7947 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7947);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7947 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7947);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = sequence(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7947 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7947);
    _0 = _7947;
    _7947 = IS_SEQUENCE(_7947);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7947;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    return 0;
    ;
}


int _17opIS_AN_OBJECT()
{
    int _7954;
    int _0, _1, _2;
    

    // 	target = Code[pc+2]
    _7954 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7954);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = 1
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    return 0;
    ;
}


int _17opSQRT()
{
    int _7957 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7957 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7957);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7957 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7957);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = sqrt(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7957 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7957);
    _0 = _7957;
    if (IS_ATOM_INT(_7957))
        _7957 = e_sqrt(_7957);
    else
        _7957 = unary_op(SQRT, _7957);
    DeRef(_0);
    Ref(_7957);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7957;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7957);
    return 0;
    ;
}


int _17opSIN()
{
    int _7964 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7964 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7964);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7964 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7964);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = sin(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7964 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7964);
    _0 = _7964;
    if (IS_ATOM_INT(_7964))
        _7964 = e_sin(_7964);
    else
        _7964 = unary_op(SIN, _7964);
    DeRef(_0);
    Ref(_7964);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7964;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7964);
    return 0;
    ;
}


int _17opCOS()
{
    int _7971 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7971 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7971);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7971 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7971);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = cos(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7971 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7971);
    _0 = _7971;
    if (IS_ATOM_INT(_7971))
        _7971 = e_cos(_7971);
    else
        _7971 = unary_op(COS, _7971);
    DeRef(_0);
    Ref(_7971);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7971;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7971);
    return 0;
    ;
}


int _17opTAN()
{
    int _7978 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7978 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7978);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7978 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7978);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = tan(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7978 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7978);
    _0 = _7978;
    if (IS_ATOM_INT(_7978))
        _7978 = e_tan(_7978);
    else
        _7978 = unary_op(TAN, _7978);
    DeRef(_0);
    Ref(_7978);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7978;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7978);
    return 0;
    ;
}


int _17opARCTAN()
{
    int _7985 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7985 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7985);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7985 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7985);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = arctan(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7985 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7985);
    _0 = _7985;
    if (IS_ATOM_INT(_7985))
        _7985 = e_arctan(_7985);
    else
        _7985 = unary_op(ARCTAN, _7985);
    DeRef(_0);
    Ref(_7985);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7985;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7985);
    return 0;
    ;
}


int _17opLOG()
{
    int _7992 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7992 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7992);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7992 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7992);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = log(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7992 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7992);
    _0 = _7992;
    if (IS_ATOM_INT(_7992))
        _7992 = e_log(_7992);
    else
        _7992 = unary_op(LOG, _7992);
    DeRef(_0);
    Ref(_7992);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7992;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7992);
    return 0;
    ;
}


int _17opNOT_BITS()
{
    int _7999 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _7999 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7999);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _7999 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _7999);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = not_bits(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _7999 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7999);
    _0 = _7999;
    if (IS_ATOM_INT(_7999))
        _7999 = not_bits(_7999);
    else
        _7999 = unary_op(NOT_BITS, _7999);
    DeRef(_0);
    Ref(_7999);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _7999;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_7999);
    return 0;
    ;
}


int _17opFLOOR()
{
    int _8006 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8006 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8006);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _8006 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8006);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = floor(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _8006 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8006);
    _0 = _8006;
    if (IS_ATOM_INT(_8006))
        _8006 = e_floor(_8006);
    else
        _8006 = unary_op(FLOOR, _8006);
    DeRef(_0);
    Ref(_8006);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8006;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8006);
    return 0;
    ;
}


int _17opNOT_IFW()
{
    int _8013 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8013 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8013);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_17val);
    _8013 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8013);
    if (binary_op_a(NOTEQ, _8013, 0))
        goto L1;

    // 	pc += 3
    _17pc = _17pc + 3;
    goto L2;
L1:

    // 	pc = Code[pc+2]
    DeRef(_8013);
    _8013 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8013);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8013);
    return 0;
    ;
}


int _17opNOT()
{
    int _8020 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8020 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8020);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _8020 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8020);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = not val[a]
    _2 = (int)SEQ_PTR(_17val);
    _8020 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8020);
    _0 = _8020;
    if (IS_ATOM_INT(_8020)) {
        _8020 = (_8020 == 0);
    }
    else {
        _8020 = unary_op(NOT, _8020);
    }
    DeRef(_0);
    Ref(_8020);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8020;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8020);
    return 0;
    ;
}


int _17opUMINUS()
{
    int _8027 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8027 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8027);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _8027 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8027);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = -val[a]
    _2 = (int)SEQ_PTR(_17val);
    _8027 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8027);
    _0 = _8027;
    if (IS_ATOM_INT(_8027)) {
        if (_8027 == 0xC0000000)
            _8027 = (int)NewDouble((double)-0xC0000000);
        else
            _8027 = - _8027;
    }
    else {
        _8027 = unary_op(UMINUS, _8027);
    }
    DeRef(_0);
    Ref(_8027);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8027;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8027);
    return 0;
    ;
}


int _17opRAND()
{
    int _8034 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8034 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8034);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _8034 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8034);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = rand(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _8034 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8034);
    _0 = _8034;
    if (IS_ATOM_INT(_8034)) {
        _8034 = good_rand() % ((unsigned)_8034) + 1;
    }
    else {
        _8034 = unary_op(RAND, _8034);
    }
    DeRef(_0);
    Ref(_8034);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8034;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8034);
    return 0;
    ;
}


int _17opDIV2()
{
    int _8041 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8041 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8041);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+3]
    _8041 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8041);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] / 2
    _2 = (int)SEQ_PTR(_17val);
    _8041 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8041);
    _0 = _8041;
    if (IS_ATOM_INT(_8041)) {
        if (_8041 & 1) {
            _8041 = NewDouble((_8041 >> 1) + 0.5);
        }
        else
            _8041 = _8041 >> 1;
    }
    else {
        _8041 = binary_op(DIVIDE, _8041, 2);
    }
    DeRef(_0);
    Ref(_8041);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8041;
    DeRef(_1);

    // 	pc += 4 
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8041);
    return 0;
    ;
}


int _17opFLOOR_DIV2()
{
    int _8048 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8048 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8048);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+3]
    _8048 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8048);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = floor(val[a] / 2)
    _2 = (int)SEQ_PTR(_17val);
    _8048 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8048);
    _0 = _8048;
    if (IS_ATOM_INT(_8048)) {
        _8048 = _8048 >> 1;
    }
    else {
        _1 = binary_op(DIVIDE, _8048, 2);
        _8048 = unary_op(FLOOR, _1);
        DeRef(_1);
    }
    DeRef(_0);
    Ref(_8048);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8048;
    DeRef(_1);

    // 	pc += 4 
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8048);
    return 0;
    ;
}


int _17opGREATER_IFW()
{
    int _8060 = 0;
    int _8055 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8055 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8055);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8055 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8055);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] > val[b] then
    _2 = (int)SEQ_PTR(_17val);
    _8055 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8055);
    _2 = (int)SEQ_PTR(_17val);
    _8060 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8060);
    if (binary_op_a(LESSEQ, _8055, _8060))
        goto L1;

    // 	pc += 4
    _17pc = _17pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_8060);
    _8060 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8060);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8060);
    DeRef(_8055);
    return 0;
    ;
}


int _17opNOTEQ_IFW()
{
    int _8070 = 0;
    int _8065 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8065 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8065);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8065 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8065);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] != val[b] then
    _2 = (int)SEQ_PTR(_17val);
    _8065 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8065);
    _2 = (int)SEQ_PTR(_17val);
    _8070 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8070);
    if (binary_op_a(EQUALS, _8065, _8070))
        goto L1;

    // 	pc += 4
    _17pc = _17pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_8070);
    _8070 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8070);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8070);
    DeRef(_8065);
    return 0;
    ;
}


int _17opLESSEQ_IFW()
{
    int _8080 = 0;
    int _8075 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8075 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8075);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8075 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8075);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] <= val[b] then
    _2 = (int)SEQ_PTR(_17val);
    _8075 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8075);
    _2 = (int)SEQ_PTR(_17val);
    _8080 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8080);
    if (binary_op_a(GREATER, _8075, _8080))
        goto L1;

    // 	pc += 4
    _17pc = _17pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_8080);
    _8080 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8080);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8080);
    DeRef(_8075);
    return 0;
    ;
}


int _17opGREATEREQ_IFW()
{
    int _8091 = 0;
    int _8085 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8085 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8085);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8085 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8085);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] >= val[b] then
    _2 = (int)SEQ_PTR(_17val);
    _8085 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8085);
    _2 = (int)SEQ_PTR(_17val);
    _8091 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8091);
    if (binary_op_a(LESS, _8085, _8091))
        goto L1;

    // 	pc += 4
    _17pc = _17pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_8091);
    _8091 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8091);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8091);
    DeRef(_8085);
    return 0;
    ;
}


int _17opEQUALS_IFW()
{
    int _8101 = 0;
    int _8096 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8096 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8096);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8096 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8096);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] = val[b] then
    _2 = (int)SEQ_PTR(_17val);
    _8096 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8096);
    _2 = (int)SEQ_PTR(_17val);
    _8101 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8101);
    if (binary_op_a(NOTEQ, _8096, _8101))
        goto L1;

    // 	pc += 4
    _17pc = _17pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_8101);
    _8101 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8101);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8101);
    DeRef(_8096);
    return 0;
    ;
}


int _17opLESS_IFW()
{
    int _8111 = 0;
    int _8106 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8106 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8106);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8106 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8106);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] < val[b] then
    _2 = (int)SEQ_PTR(_17val);
    _8106 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8106);
    _2 = (int)SEQ_PTR(_17val);
    _8111 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8111);
    if (binary_op_a(GREATEREQ, _8106, _8111))
        goto L1;

    // 	pc += 4
    _17pc = _17pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_8111);
    _8111 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8111);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_8111);
    DeRef(_8106);
    return 0;
    ;
}


int _17opMULTIPLY()
{
    int _8123 = 0;
    int _8116 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8116 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8116);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8116 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8116);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8116 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8116);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] * val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8116 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8116);
    _2 = (int)SEQ_PTR(_17val);
    _8123 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8123);
    _0 = _8123;
    if (IS_ATOM_INT(_8116) && IS_ATOM_INT(_8123)) {
        if (_8116 == (short)_8116 && _8123 <= INT15 && _8123 >= -INT15)
            _8123 = _8116 * _8123;
        else
            _8123 = NewDouble(_8116 * (double)_8123);
    }
    else {
        _8123 = binary_op(MULTIPLY, _8116, _8123);
    }
    DeRef(_0);
    Ref(_8123);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8123;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8123);
    DeRef(_8116);
    return 0;
    ;
}


int _17opPLUS()
{
    int _8133 = 0;
    int _8126 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8126 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8126);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8126 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8126);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8126 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8126);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] + val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8126 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8126);
    _2 = (int)SEQ_PTR(_17val);
    _8133 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8133);
    _0 = _8133;
    if (IS_ATOM_INT(_8126) && IS_ATOM_INT(_8133)) {
        _8133 = _8126 + _8133;
        if ((long)((unsigned long)_8133 + (unsigned long)HIGH_BITS) >= 0) 
            _8133 = NewDouble((double)_8133);
    }
    else {
        _8133 = binary_op(PLUS, _8126, _8133);
    }
    DeRef(_0);
    Ref(_8133);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8133;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8133);
    DeRef(_8126);
    return 0;
    ;
}


int _17opMINUS()
{
    int _8143 = 0;
    int _8136 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8136 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8136);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8136 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8136);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8136 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8136);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] - val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8136 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8136);
    _2 = (int)SEQ_PTR(_17val);
    _8143 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8143);
    _0 = _8143;
    if (IS_ATOM_INT(_8136) && IS_ATOM_INT(_8143)) {
        _8143 = _8136 - _8143;
        if ((long)((unsigned long)_8143 +(unsigned long) HIGH_BITS) >= 0)
            _8143 = NewDouble((double)_8143);
    }
    else {
        _8143 = binary_op(MINUS, _8136, _8143);
    }
    DeRef(_0);
    Ref(_8143);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8143;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8143);
    DeRef(_8136);
    return 0;
    ;
}


int _17opOR()
{
    int _8153 = 0;
    int _8146 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8146 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8146);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8146 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8146);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8146 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8146);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] or val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8146 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8146);
    _2 = (int)SEQ_PTR(_17val);
    _8153 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8153);
    _0 = _8153;
    if (IS_ATOM_INT(_8146) && IS_ATOM_INT(_8153)) {
        _8153 = (_8146 != 0 || _8153 != 0);
    }
    else {
        _8153 = binary_op(OR, _8146, _8153);
    }
    DeRef(_0);
    Ref(_8153);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8153;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8153);
    DeRef(_8146);
    return 0;
    ;
}


int _17opXOR()
{
    int _8163 = 0;
    int _8156 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8156 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8156);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8156 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8156);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8156 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8156);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] xor val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8156 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8156);
    _2 = (int)SEQ_PTR(_17val);
    _8163 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8163);
    _0 = _8163;
    if (IS_ATOM_INT(_8156) && IS_ATOM_INT(_8163)) {
        _8163 = ((_8156 != 0) != (_8163 != 0));
    }
    else {
        _8163 = binary_op(XOR, _8156, _8163);
    }
    DeRef(_0);
    Ref(_8163);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8163;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8163);
    DeRef(_8156);
    return 0;
    ;
}


int _17opAND()
{
    int _8173 = 0;
    int _8166 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8166 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8166);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8166 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8166);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8166 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8166);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] and val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8166 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8166);
    _2 = (int)SEQ_PTR(_17val);
    _8173 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8173);
    _0 = _8173;
    if (IS_ATOM_INT(_8166) && IS_ATOM_INT(_8173)) {
        _8173 = (_8166 != 0 && _8173 != 0);
    }
    else {
        _8173 = binary_op(AND, _8166, _8173);
    }
    DeRef(_0);
    Ref(_8173);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8173;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8173);
    DeRef(_8166);
    return 0;
    ;
}


int _17opDIVIDE()
{
    int _8186 = 0;
    int _8176 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8176 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8176);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8176 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8176);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8176 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8176);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	if equal(val[b], 0) then
    _2 = (int)SEQ_PTR(_17val);
    _8176 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8176);
    _0 = _8176;
    if (_8176 == 0)
        _8176 = 1;
    else if (IS_ATOM_INT(_8176) && IS_ATOM_INT(0))
        _8176 = 0;
    else
        _8176 = (compare(_8176, 0) == 0);
    DeRef(_0);
    if (_8176 == 0)
        goto L1;

    // 	RTFatal("attempt to divide by 0")
    RefDS(_8184);
    _17RTFatal(_8184);

    // 	return
    return 0;
L1:

    // 	val[target] = val[a] / val[b]
    DeRef(_8176);
    _2 = (int)SEQ_PTR(_17val);
    _8176 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8176);
    DeRef(_8186);
    _2 = (int)SEQ_PTR(_17val);
    _8186 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8186);
    _0 = _8186;
    if (IS_ATOM_INT(_8176) && IS_ATOM_INT(_8186)) {
        _8186 = (_8176 % _8186) ? NewDouble((double)_8176 / _8186) : (_8176 / _8186);
    }
    else {
        _8186 = binary_op(DIVIDE, _8176, _8186);
    }
    DeRef(_0);
    Ref(_8186);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8186;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8186);
    DeRef(_8176);
    return 0;
    ;
}


int _17opREMAINDER()
{
    int _8199 = 0;
    int _8189 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8189 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8189);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8189 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8189);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8189 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8189);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	if equal(val[b], 0) then
    _2 = (int)SEQ_PTR(_17val);
    _8189 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8189);
    _0 = _8189;
    if (_8189 == 0)
        _8189 = 1;
    else if (IS_ATOM_INT(_8189) && IS_ATOM_INT(0))
        _8189 = 0;
    else
        _8189 = (compare(_8189, 0) == 0);
    DeRef(_0);
    if (_8189 == 0)
        goto L1;

    // 	RTFatal("Can't get remainder of a number divided by 0")
    RefDS(_8197);
    _17RTFatal(_8197);

    // 	return
    return 0;
L1:

    // 	val[target] = remainder(val[a], val[b])
    DeRef(_8189);
    _2 = (int)SEQ_PTR(_17val);
    _8189 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8189);
    DeRef(_8199);
    _2 = (int)SEQ_PTR(_17val);
    _8199 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8199);
    _0 = _8199;
    if (IS_ATOM_INT(_8189) && IS_ATOM_INT(_8199)) {
        _8199 = (_8189 % _8199);
    }
    else {
        _8199 = binary_op(REMAINDER, _8189, _8199);
    }
    DeRef(_0);
    Ref(_8199);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8199;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8199);
    DeRef(_8189);
    return 0;
    ;
}


int _17opFLOOR_DIV()
{
    int _8211 = 0;
    int _8202 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8202 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8202);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8202 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8202);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8202 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8202);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	if equal(val[b], 0) then
    _2 = (int)SEQ_PTR(_17val);
    _8202 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8202);
    _0 = _8202;
    if (_8202 == 0)
        _8202 = 1;
    else if (IS_ATOM_INT(_8202) && IS_ATOM_INT(0))
        _8202 = 0;
    else
        _8202 = (compare(_8202, 0) == 0);
    DeRef(_0);
    if (_8202 == 0)
        goto L1;

    // 	RTFatal("attempt to divide by 0")
    RefDS(_8184);
    _17RTFatal(_8184);

    // 	return
    return 0;
L1:

    // 	val[target] = floor(val[a] / val[b])
    DeRef(_8202);
    _2 = (int)SEQ_PTR(_17val);
    _8202 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8202);
    DeRef(_8211);
    _2 = (int)SEQ_PTR(_17val);
    _8211 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8211);
    _0 = _8211;
    if (IS_ATOM_INT(_8202) && IS_ATOM_INT(_8211)) {
        if (_8211 > 0 && _8202 >= 0) {
            _8211 = _8202 / _8211;
        }
        else {
            temp_dbl = floor((double)_8202 / (double)_8211);
            if (_8202 != MININT)
                _8211 = (long)temp_dbl;
            else
                _8211 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _8202, _8211);
        _8211 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);
    Ref(_8211);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8211;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8211);
    DeRef(_8202);
    return 0;
    ;
}


int _17opAND_BITS()
{
    int _8221 = 0;
    int _8214 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8214 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8214);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8214 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8214);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8214 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8214);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = and_bits(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8214 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8214);
    _2 = (int)SEQ_PTR(_17val);
    _8221 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8221);
    _0 = _8221;
    if (IS_ATOM_INT(_8214) && IS_ATOM_INT(_8221)) {
        _8221 = (_8214 & _8221);
    }
    else {
        _8221 = binary_op(AND_BITS, _8214, _8221);
    }
    DeRef(_0);
    Ref(_8221);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8221;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8221);
    DeRef(_8214);
    return 0;
    ;
}


int _17opOR_BITS()
{
    int _8231 = 0;
    int _8224 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8224 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8224);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8224 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8224);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8224 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8224);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = or_bits(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8224 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8224);
    _2 = (int)SEQ_PTR(_17val);
    _8231 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8231);
    _0 = _8231;
    if (IS_ATOM_INT(_8224) && IS_ATOM_INT(_8231)) {
        _8231 = (_8224 | _8231);
    }
    else {
        _8231 = binary_op(OR_BITS, _8224, _8231);
    }
    DeRef(_0);
    Ref(_8231);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8231;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8231);
    DeRef(_8224);
    return 0;
    ;
}


int _17opXOR_BITS()
{
    int _8241 = 0;
    int _8234 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8234 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8234);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8234 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8234);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8234 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8234);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = xor_bits(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8234 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8234);
    _2 = (int)SEQ_PTR(_17val);
    _8241 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8241);
    _0 = _8241;
    if (IS_ATOM_INT(_8234) && IS_ATOM_INT(_8241)) {
        _8241 = (_8234 ^ _8241);
    }
    else {
        _8241 = binary_op(XOR_BITS, _8234, _8241);
    }
    DeRef(_0);
    Ref(_8241);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8241;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8241);
    DeRef(_8234);
    return 0;
    ;
}


int _17opPOWER()
{
    int _8251 = 0;
    int _8244 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8244 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8244);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8244 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8244);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8244 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8244);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = power(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8244 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8244);
    _2 = (int)SEQ_PTR(_17val);
    _8251 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8251);
    _0 = _8251;
    if (IS_ATOM_INT(_8244) && IS_ATOM_INT(_8251)) {
        _8251 = power(_8244, _8251);
    }
    else {
        _8251 = binary_op(POWER, _8244, _8251);
    }
    DeRef(_0);
    Ref(_8251);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8251;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8251);
    DeRef(_8244);
    return 0;
    ;
}


int _17opLESS()
{
    int _8261 = 0;
    int _8254 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8254 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8254);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8254 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8254);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8254 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8254);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] < val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8254 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8254);
    _2 = (int)SEQ_PTR(_17val);
    _8261 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8261);
    _0 = _8261;
    if (IS_ATOM_INT(_8254) && IS_ATOM_INT(_8261)) {
        _8261 = (_8254 < _8261);
    }
    else {
        _8261 = binary_op(LESS, _8254, _8261);
    }
    DeRef(_0);
    Ref(_8261);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8261;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8261);
    DeRef(_8254);
    return 0;
    ;
}


int _17opGREATER()
{
    int _8271 = 0;
    int _8264 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8264 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8264);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8264 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8264);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8264 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8264);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] > val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8264 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8264);
    _2 = (int)SEQ_PTR(_17val);
    _8271 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8271);
    _0 = _8271;
    if (IS_ATOM_INT(_8264) && IS_ATOM_INT(_8271)) {
        _8271 = (_8264 > _8271);
    }
    else {
        _8271 = binary_op(GREATER, _8264, _8271);
    }
    DeRef(_0);
    Ref(_8271);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8271;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8271);
    DeRef(_8264);
    return 0;
    ;
}


int _17opEQUALS()
{
    int _8281 = 0;
    int _8274 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8274 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8274);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8274 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8274);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8274 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8274);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] = val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8274 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8274);
    _2 = (int)SEQ_PTR(_17val);
    _8281 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8281);
    _0 = _8281;
    if (IS_ATOM_INT(_8274) && IS_ATOM_INT(_8281)) {
        _8281 = (_8274 == _8281);
    }
    else {
        _8281 = binary_op(EQUALS, _8274, _8281);
    }
    DeRef(_0);
    Ref(_8281);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8281;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8281);
    DeRef(_8274);
    return 0;
    ;
}


int _17opNOTEQ()
{
    int _8291 = 0;
    int _8284 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8284 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8284);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8284 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8284);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8284 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8284);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] != val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8284 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8284);
    _2 = (int)SEQ_PTR(_17val);
    _8291 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8291);
    _0 = _8291;
    if (IS_ATOM_INT(_8284) && IS_ATOM_INT(_8291)) {
        _8291 = (_8284 != _8291);
    }
    else {
        _8291 = binary_op(NOTEQ, _8284, _8291);
    }
    DeRef(_0);
    Ref(_8291);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8291;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8291);
    DeRef(_8284);
    return 0;
    ;
}


int _17opLESSEQ()
{
    int _8301 = 0;
    int _8294 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8294 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8294);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8294 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8294);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8294 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8294);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] <= val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8294 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8294);
    _2 = (int)SEQ_PTR(_17val);
    _8301 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8301);
    _0 = _8301;
    if (IS_ATOM_INT(_8294) && IS_ATOM_INT(_8301)) {
        _8301 = (_8294 <= _8301);
    }
    else {
        _8301 = binary_op(LESSEQ, _8294, _8301);
    }
    DeRef(_0);
    Ref(_8301);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8301;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8301);
    DeRef(_8294);
    return 0;
    ;
}


int _17opGREATEREQ()
{
    int _8311 = 0;
    int _8304 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8304 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8304);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8304 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8304);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8304 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8304);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] >= val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8304 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8304);
    _2 = (int)SEQ_PTR(_17val);
    _8311 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8311);
    _0 = _8311;
    if (IS_ATOM_INT(_8304) && IS_ATOM_INT(_8311)) {
        _8311 = (_8304 >= _8311);
    }
    else {
        _8311 = binary_op(GREATEREQ, _8304, _8311);
    }
    DeRef(_0);
    Ref(_8311);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8311;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8311);
    DeRef(_8304);
    return 0;
    ;
}


int _17opSC1_AND()
{
    int _8314 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8314 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8314);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8314 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8314);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _8314 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8314);
    _0 = _8314;
    _8314 = IS_ATOM(_8314);
    DeRef(_0);
    if (_8314 == 0)
        goto L1;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_17val);
    _8314 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8314);
    if (binary_op_a(NOTEQ, _8314, 0))
        goto L2;

    // 	    val[b] = 0
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17b);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	    pc = Code[pc+3]
    DeRef(_8314);
    _8314 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8314);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;

    // 	    return
    return 0;
L3:
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_8324);
    _17RTFatal(_8324);

    // 	return
    DeRef(_8314);
    return 0;
L2:

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8314);
    return 0;
    ;
}


int _17opSC1_AND_IF()
{
    int _8326 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8326 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8326);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8326 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8326);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _8326 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8326);
    _0 = _8326;
    _8326 = IS_ATOM(_8326);
    DeRef(_0);
    if (_8326 == 0)
        goto L1;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_17val);
    _8326 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8326);
    if (binary_op_a(NOTEQ, _8326, 0))
        goto L2;

    // 	    pc = Code[pc+3]
    DeRef(_8326);
    _8326 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8326);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;

    // 	    return
    return 0;
L3:
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_8324);
    _17RTFatal(_8324);

    // 	return
    DeRef(_8326);
    return 0;
L2:

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8326);
    return 0;
    ;
}


