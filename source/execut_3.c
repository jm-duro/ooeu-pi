// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17opROUTINE_ID()
{
    int _sub;
    int _fn;
    int _p;
    int _stlen;
    int _name = 0;
    int _8824 = 0;
    int _8808 = 0;
    int _8826 = 0;
    int _0, _1, _2;
    

    // 	sub = Code[pc+1]   -- CurrentSub
    _8808 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _sub = (int)*(((s1_ptr)_2)->base + _8808);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	stlen = Code[pc+2]	-- s.t. length
    _8808 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _stlen = (int)*(((s1_ptr)_2)->base + _8808);
    if (!IS_ATOM_INT(_stlen))
        _stlen = (long)DBL_PTR(_stlen)->dbl;

    // 	name = val[Code[pc+3]]	-- routine name sequence
    _8808 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _8808 = (int)*(((s1_ptr)_2)->base + _8808);
    Ref(_8808);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8808))
        _name = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8808)->dbl));
    else
        _name = (int)*(((s1_ptr)_2)->base + _8808);
    Ref(_name);

    // 	fn = Code[pc+4]    -- file number
    DeRef(_8808);
    _8808 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _fn = (int)*(((s1_ptr)_2)->base + _8808);
    if (!IS_ATOM_INT(_fn))
        _fn = (long)DBL_PTR(_fn)->dbl;

    // 	target = Code[pc+5]
    _8808 = _17pc + 5;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8808);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	pc += 6
    _17pc = _17pc + 6;

    // 	if atom(name) then
    _8808 = IS_ATOM(_name);
    if (_8808 == 0)
        goto L1;

    // 		val[target] = -1
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 		return
    DeRef(_name);
    return 0;
L1:

    // 	p = RTLookup(name, fn, sub, stlen)
    Ref(_name);
    _p = _17RTLookup(_name, _fn, _sub, _stlen);

    // 	if p = 0 or not find(SymTab[p][S_TOKEN], {r:PROC, r:FUNC, TYPE}) 
    DeRef(_8808);
    _8808 = (_p == 0);
    if (_8808 != 0) {
        _8808 = 1;
        goto L2;
    }
    DeRef(_8824);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8824 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_8824);
    _0 = _8824;
    _2 = (int)SEQ_PTR(_8824);
    _8824 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_8824);
    DeRef(_0);
    _0 = _8826;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _8826 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _8826;
    _8826 = find(_8824, _8826);
    DeRefDSi(_0);
    _8826 = (_8826 == 0);
    _8808 = (_8826 != 0);
L2:
    if (_8808 != 0) {
        goto L3;
    }
    DeRef(_8824);
    _8824 = (0 == 0);
    if (_8824 == 0) {
        _8824 = 0;
        goto L4;
    }
    DeRef(_8808);
    _8808 = (_p > _stlen);
    _8824 = (_8808 != 0);
L4:
L5:
    if (_8824 == 0)
        goto L6;
L3:

    // 		val[target] = -1  -- name is not a routine
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 		return
    DeRef(_name);
    DeRef(_8824);
    DeRef(_8808);
    DeRef(_8826);
    return 0;
L6:

    // 	for i = 1 to length(e_routine) do
    DeRef(_8808);
    _8808 = SEQ_PTR(_17e_routine)->length;
    { int _i;
        _i = 1;
L7:
        if (_i > _8808)
            goto L8;

        // 		if e_routine[i] = p then
        DeRef(_8824);
        _2 = (int)SEQ_PTR(_17e_routine);
        _8824 = (int)*(((s1_ptr)_2)->base + _i);
        if (_8824 != _p)
            goto L9;

        // 		    val[target] = i - 1 -- routine was already assigned an id
        _8824 = _i - 1;
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _17target);
        _1 = *(int *)_2;
        *(int *)_2 = _8824;
        DeRef(_1);

        // 		    return
        DeRef(_name);
        DeRef(_8808);
        DeRef(_8826);
        return 0;
L9:

        // 	end for 
        _i = _i + 1;
        goto L7;
L8:
        ;
    }

    // 	e_routine = append(e_routine, p)
    Append(&_17e_routine, _17e_routine, _p);

    // 	val[target] = length(e_routine) - 1
    DeRef(_8824);
    _8824 = SEQ_PTR(_17e_routine)->length;
    _8824 = _8824 - 1;
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8824;
    DeRef(_1);

    // end procedure
    DeRef(_name);
    DeRef(_8808);
    DeRef(_8826);
    return 0;
    ;
}


int _17opAPPEND()
{
    int _8847 = 0;
    int _8840 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8840 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8840);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8840 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8840);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8840 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8840);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = append(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8840 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8840);
    _2 = (int)SEQ_PTR(_17val);
    _8847 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8847);
    Ref(_8847);
    Append(&_8847, _8840, _8847);
    RefDS(_8847);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8847;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDS(_8847);
    DeRef(_8840);
    return 0;
    ;
}


int _17opPREPEND()
{
    int _8857 = 0;
    int _8850 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8850 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8850);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8850 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8850);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8850 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8850);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = prepend(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8850 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8850);
    _2 = (int)SEQ_PTR(_17val);
    _8857 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8857);
    Ref(_8857);
    Prepend(&_8857, _8850, _8857);
    RefDS(_8857);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8857;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDS(_8857);
    DeRef(_8850);
    return 0;
    ;
}


int _17opCONCAT()
{
    int _8867 = 0;
    int _8860 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8860 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8860);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8860 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8860);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8860 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8860);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a] & val[b]
    _2 = (int)SEQ_PTR(_17val);
    _8860 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8860);
    _2 = (int)SEQ_PTR(_17val);
    _8867 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8867);
    if (IS_SEQUENCE(_8860) && IS_ATOM(_8867)) {
        Ref(_8867);
        Append(&_8867, _8860, _8867);
    }
    else if (IS_ATOM(_8860) && IS_SEQUENCE(_8867)) {
        Ref(_8860);
        Prepend(&_8867, _8867, _8860);
    }
    else {
        Concat((object_ptr)&_8867, _8860, (s1_ptr)_8867);
    }
    RefDS(_8867);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8867;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDS(_8867);
    DeRef(_8860);
    return 0;
    ;
}


int _17opCONCAT_N()
{
    int _n;
    int _x = 0;
    int _8870 = 0;
    int _8876 = 0;
    int _0, _1, _2;
    

    // 	n = Code[pc+1] -- number of items
    _8870 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _n = (int)*(((s1_ptr)_2)->base + _8870);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 	x = val[Code[pc+2]] -- last one
    _8870 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _8870 = (int)*(((s1_ptr)_2)->base + _8870);
    Ref(_8870);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8870))
        _x = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8870)->dbl));
    else
        _x = (int)*(((s1_ptr)_2)->base + _8870);
    Ref(_x);

    // 	for i = pc+3 to pc+n+1 do
    DeRef(_8870);
    _8870 = _17pc + 3;
    if ((long)((unsigned long)_8870 + (unsigned long)HIGH_BITS) >= 0) 
        _8870 = NewDouble((double)_8870);
    _8876 = _17pc + _n;
    if ((long)((unsigned long)_8876 + (unsigned long)HIGH_BITS) >= 0) 
        _8876 = NewDouble((double)_8876);
    _0 = _8876;
    if (IS_ATOM_INT(_8876)) {
        _8876 = _8876 + 1;
        if (_8876 > MAXINT)
            _8876 = NewDouble((double)_8876);
    }
    else
        _8876 = binary_op(PLUS, 1, _8876);
    DeRef(_0);
    { int _i;
        Ref(_8870);
        _i = _8870;
L1:
        if (binary_op_a(GREATER, _i, _8876))
            goto L2;

        // 		x = val[Code[i]] & x
        DeRef(_8870);
        _2 = (int)SEQ_PTR(_7Code);
        if (!IS_ATOM_INT(_i))
            _8870 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _8870 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8870);
        _0 = _8870;
        _2 = (int)SEQ_PTR(_17val);
        if (!IS_ATOM_INT(_8870))
            _8870 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8870)->dbl));
        else
            _8870 = (int)*(((s1_ptr)_2)->base + _8870);
        Ref(_8870);
        DeRef(_0);
        if (IS_SEQUENCE(_8870) && IS_ATOM(_x)) {
            Ref(_x);
            Append(&_x, _8870, _x);
        }
        else if (IS_ATOM(_8870) && IS_SEQUENCE(_x)) {
            Ref(_8870);
            Prepend(&_x, _x, _8870);
        }
        else {
            Concat((object_ptr)&_x, _8870, (s1_ptr)_x);
        }

        // 	end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef(_0);
        goto L1;
L2:
        ;
        DeRef(_i);
    }

    // 	target = Code[pc+n+2]
    DeRef(_8870);
    _8870 = _17pc + _n;
    if ((long)((unsigned long)_8870 + (unsigned long)HIGH_BITS) >= 0) 
        _8870 = NewDouble((double)_8870);
    _0 = _8870;
    if (IS_ATOM_INT(_8870)) {
        _8870 = _8870 + 2;
    }
    else {
        _8870 = NewDouble(DBL_PTR(_8870)->dbl + (double)2);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_7Code);
    if (!IS_ATOM_INT(_8870))
        _17target = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8870)->dbl));
    else
        _17target = (int)*(((s1_ptr)_2)->base + _8870);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = x
    Ref(_x);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _x;
    DeRef(_1);

    // 	pc += n+3
    DeRef(_8870);
    _8870 = _n + 3;
    if ((long)((unsigned long)_8870 + (unsigned long)HIGH_BITS) >= 0) 
        _8870 = NewDouble((double)_8870);
    if (IS_ATOM_INT(_8870)) {
        _17pc = _17pc + _8870;
    }
    else {
        _17pc = NewDouble((double)_17pc + DBL_PTR(_8870)->dbl);
    }
    if (!IS_ATOM_INT(_17pc)) {
        _1 = (long)(DBL_PTR(_17pc)->dbl);
        DeRefDS(_17pc);
        _17pc = _1;
    }

    // end procedure
    DeRef(_x);
    DeRef(_8870);
    DeRef(_8876);
    return 0;
    ;
}


int _17opREPEAT()
{
    int _8893 = 0;
    int _8886 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8886 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8886);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8886 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8886);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8886 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8886);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = repeat(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8886 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8886);
    _2 = (int)SEQ_PTR(_17val);
    _8893 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8893);
    _0 = _8893;
    _8893 = Repeat(_8886, _8893);
    DeRef(_0);
    RefDS(_8893);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8893;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDS(_8893);
    DeRef(_8886);
    return 0;
    ;
}


int _17opDATE()
{
    int _8896 = 0;
    int _0, _1, _2;
    

    // 	target = Code[pc+1]
    _8896 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8896);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = date()
    _8896 = Date();
    RefDS(_8896);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8896;
    DeRef(_1);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDSi(_8896);
    return 0;
    ;
}


int _17opTIME()
{
    int _8900 = 0;
    int _0, _1, _2;
    

    // 	target = Code[pc+1]
    _8900 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8900);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = time()
    _8900 = NewDouble(current_time());
    RefDS(_8900);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8900;
    DeRef(_1);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDS(_8900);
    return 0;
    ;
}


int _17opSPACE_USED()
{
    int _0, _1, _2;
    

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    return 0;
    ;
}


int _17opNOP2()
{
    int _0, _1, _2;
    

    // 	pc+= 2
    _17pc = _17pc + 2;

    // end procedure
    return 0;
    ;
}


int _17opPOSITION()
{
    int _8911 = 0;
    int _8906 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8906 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8906);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8906 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8906);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	position(val[a], val[b])  -- error checks
    _2 = (int)SEQ_PTR(_17val);
    _8906 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8906);
    _2 = (int)SEQ_PTR(_17val);
    _8911 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8911);
    Position(_8906, _8911);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8911);
    DeRef(_8906);
    return 0;
    ;
}


int _17opEQUAL()
{
    int _8920 = 0;
    int _8913 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8913 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8913);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8913 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8913);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8913 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8913);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = equal(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8913 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8913);
    _2 = (int)SEQ_PTR(_17val);
    _8920 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8920);
    _0 = _8920;
    if (_8913 == _8920)
        _8920 = 1;
    else if (IS_ATOM_INT(_8913) && IS_ATOM_INT(_8920))
        _8920 = 0;
    else
        _8920 = (compare(_8913, _8920) == 0);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8920;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8913);
    return 0;
    ;
}


int _17opCOMPARE()
{
    int _8930 = 0;
    int _8923 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8923 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8923);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8923 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8923);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8923 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8923);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = compare(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8923 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8923);
    _2 = (int)SEQ_PTR(_17val);
    _8930 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8930);
    _0 = _8930;
    if (IS_ATOM_INT(_8923) && IS_ATOM_INT(_8930))
        _8930 = (_8923 < _8930) ? -1 : (_8923 > _8930);
    else
        _8930 = compare(_8923, _8930);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8930;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8923);
    return 0;
    ;
}


int _17opFIND()
{
    int _8940 = 0;
    int _8933 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8933 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8933);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8933 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8933);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8933 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8933);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = find(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8933 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8933);
    _2 = (int)SEQ_PTR(_17val);
    _8940 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8940);
    _0 = _8940;
    _8940 = find(_8933, _8940);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8940;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8933);
    return 0;
    ;
}


int _17opFIND_FROM()
{
    int _s = 0;
    int _8951 = 0;
    int _8943 = 0;
    int _0, _1, _2;
    

    // 	c = val[Code[pc+3]]
    _8943 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _8943 = (int)*(((s1_ptr)_2)->base + _8943);
    Ref(_8943);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8943))
        _17c = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8943)->dbl));
    else
        _17c = (int)*(((s1_ptr)_2)->base + _8943);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	target = Code[pc+4]
    DeRef(_8943);
    _8943 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8943);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	s = val[Code[pc+2]][c..$]
    _8943 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _8943 = (int)*(((s1_ptr)_2)->base + _8943);
    Ref(_8943);
    _0 = _8943;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8943))
        _8943 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8943)->dbl));
    else
        _8943 = (int)*(((s1_ptr)_2)->base + _8943);
    Ref(_8943);
    DeRef(_0);
    _8951 = SEQ_PTR(_8943)->length;
    rhs_slice_target = (object_ptr)&_s;
    RHS_Slice((s1_ptr)_8943, _17c, _8951);

    // 	b = find( val[Code[pc+1]], s )
    _8951 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _8951 = (int)*(((s1_ptr)_2)->base + _8951);
    Ref(_8951);
    _0 = _8951;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8951))
        _8951 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8951)->dbl));
    else
        _8951 = (int)*(((s1_ptr)_2)->base + _8951);
    Ref(_8951);
    DeRef(_0);
    _17b = find(_8951, _s);

    // 	if b then
    if (_17b == 0)
        goto L1;

    // 		b += c - 1
    DeRef(_8951);
    _8951 = _17c - 1;
    if ((long)((unsigned long)_8951 +(unsigned long) HIGH_BITS) >= 0)
        _8951 = NewDouble((double)_8951);
    if (IS_ATOM_INT(_8951)) {
        _17b = _17b + _8951;
    }
    else {
        _17b = NewDouble((double)_17b + DBL_PTR(_8951)->dbl);
    }
    if (!IS_ATOM_INT(_17b)) {
        _1 = (long)(DBL_PTR(_17b)->dbl);
        DeRefDS(_17b);
        _17b = _1;
    }
L1:

    // 	val[target] = b
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _17b;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRef(_s);
    DeRef(_8951);
    DeRef(_8943);
    return 0;
    ;
}


int _17opMATCH_FROM()
{
    int _s = 0;
    int _8968 = 0;
    int _8960 = 0;
    int _0, _1, _2;
    

    // 	c = val[Code[pc+3]]
    _8960 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _8960 = (int)*(((s1_ptr)_2)->base + _8960);
    Ref(_8960);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8960))
        _17c = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8960)->dbl));
    else
        _17c = (int)*(((s1_ptr)_2)->base + _8960);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	target = Code[pc+4]
    DeRef(_8960);
    _8960 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8960);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	s = val[Code[pc+2]][c..$]
    _8960 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _8960 = (int)*(((s1_ptr)_2)->base + _8960);
    Ref(_8960);
    _0 = _8960;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8960))
        _8960 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8960)->dbl));
    else
        _8960 = (int)*(((s1_ptr)_2)->base + _8960);
    Ref(_8960);
    DeRef(_0);
    _8968 = SEQ_PTR(_8960)->length;
    rhs_slice_target = (object_ptr)&_s;
    RHS_Slice((s1_ptr)_8960, _17c, _8968);

    // 	b = match( val[Code[pc+1]], s )
    _8968 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _8968 = (int)*(((s1_ptr)_2)->base + _8968);
    Ref(_8968);
    _0 = _8968;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8968))
        _8968 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8968)->dbl));
    else
        _8968 = (int)*(((s1_ptr)_2)->base + _8968);
    Ref(_8968);
    DeRef(_0);
    _17b = e_match(_8968, _s);

    // 	if b then
    if (_17b == 0)
        goto L1;

    // 		b += c - 1
    DeRef(_8968);
    _8968 = _17c - 1;
    if ((long)((unsigned long)_8968 +(unsigned long) HIGH_BITS) >= 0)
        _8968 = NewDouble((double)_8968);
    if (IS_ATOM_INT(_8968)) {
        _17b = _17b + _8968;
    }
    else {
        _17b = NewDouble((double)_17b + DBL_PTR(_8968)->dbl);
    }
    if (!IS_ATOM_INT(_17b)) {
        _1 = (long)(DBL_PTR(_17b)->dbl);
        DeRefDS(_17b);
        _17b = _1;
    }
L1:

    // 	val[target] = b
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _17b;
    DeRef(_1);

    // 	pc += 5
    _17pc = _17pc + 5;

    // end procedure
    DeRef(_s);
    DeRef(_8968);
    DeRef(_8960);
    return 0;
    ;
}


int _17opMATCH()
{
    int _8984 = 0;
    int _8977 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8977 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8977);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8977 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8977);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _8977 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8977);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = match(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _8977 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8977);
    _2 = (int)SEQ_PTR(_17val);
    _8984 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8984);
    _0 = _8984;
    _8984 = e_match(_8977, _8984);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8984;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8977);
    return 0;
    ;
}


int _17opPEEK4U()
{
    int _8987 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8987 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8987);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _8987 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8987);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = peek4u(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _8987 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8987);
    _0 = _8987;
    if (IS_ATOM_INT(_8987)) {
        _8987 = *(unsigned long *)_8987;
        if ((unsigned)_8987 > (unsigned)MAXINT)
            _8987 = NewDouble((double)(unsigned long)_8987);
    }
    else if (IS_ATOM(_8987)) {
        _8987 = *(unsigned long *)(unsigned long)(DBL_PTR(_8987)->dbl);
        if ((unsigned)_8987 > (unsigned)MAXINT)
            _8987 = NewDouble((double)(unsigned long)_8987);
    }
    else {
        _1 = (int)SEQ_PTR(_8987);
        peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
        _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
        poke4_addr = (unsigned long *)NewS1(_2);
        _8987 = MAKE_SEQ(poke4_addr);
        poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
        while (--_2 >= 0) {
            poke4_addr++;
            _1 = (int)*peek4_addr++;
            if ((unsigned)_1 > (unsigned)MAXINT)
                _1 = NewDouble((double)(unsigned long)_1);
            *(int *)poke4_addr = _1;
        }
    }
    DeRef(_0);
    Ref(_8987);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8987;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8987);
    return 0;
    ;
}


int _17opPEEK4S()
{
    int _8994 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8994 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8994);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _8994 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _8994);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = peek4s(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _8994 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8994);
    _0 = _8994;
    if (IS_ATOM_INT(_8994)) {
        _8994 = *(unsigned long *)_8994;
        if (_8994 < MININT || _8994 > MAXINT)
            _8994 = NewDouble((double)(long)_8994);
    }
    else if (IS_ATOM(_8994)) {
        _8994 = *(unsigned long *)(unsigned long)(DBL_PTR(_8994)->dbl);
        if (_8994 < MININT || _8994 > MAXINT)
            _8994 = NewDouble((double)(long)_8994);
    }
    else {
        _1 = (int)SEQ_PTR(_8994);
        peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
        _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
        poke4_addr = (unsigned long *)NewS1(_2);
        _8994 = MAKE_SEQ(poke4_addr);
        poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
        while (--_2 >= 0) {
            poke4_addr++;
            _1 = (int)*peek4_addr++;
            if (_1 < MININT || _1 > MAXINT)
                _1 = NewDouble((double)(long)_1);
            *(int *)poke4_addr = _1;
        }
    }
    DeRef(_0);
    Ref(_8994);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _8994;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8994);
    return 0;
    ;
}


int _17opPEEK()
{
    int _9001 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9001 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9001);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _9001 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9001);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = peek(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9001 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9001);
    _0 = _9001;
    if (IS_ATOM_INT(_9001)) {
        _9001 = *(unsigned char *)_9001;
    }
    else if (IS_ATOM(_9001)) {
        _9001 = *(unsigned char *)(unsigned long)(DBL_PTR(_9001)->dbl);
    }
    else {
        _1 = (int)SEQ_PTR(_9001);
        poke_addr = (unsigned char *)get_pos_int("peek", *(((s1_ptr)_1)->base+1));
        _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
        poke4_addr = (unsigned long *)NewS1(_2);
        _9001 = MAKE_SEQ(poke4_addr);
        poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
        while (--_2 >= 0) {
            poke4_addr++;
            *(int *)poke4_addr = *poke_addr++;
        }
    }
    DeRef(_0);
    Ref(_9001);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9001;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9001);
    return 0;
    ;
}


int _17opPOKE()
{
    int _9013 = 0;
    int _9008 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9008 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9008);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9008 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9008);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	poke(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9008 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9008);
    _2 = (int)SEQ_PTR(_17val);
    _9013 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9013);
    if (IS_ATOM_INT(_9008))
        poke_addr = (unsigned char *)_9008;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_9008)->dbl);
    if (IS_ATOM_INT(_9013)) {
        *poke_addr = (unsigned char)_9013;
    }
    else if (IS_ATOM(_9013)) {
        *poke_addr = (signed char)DBL_PTR(_9013)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_9013);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *poke_addr++ = (unsigned char)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
            }
        }
    }

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9013);
    DeRef(_9008);
    return 0;
    ;
}


int _17opPOKE4()
{
    int _9020 = 0;
    int _9015 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9015 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9015);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9015 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9015);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	poke4(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9015 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9015);
    _2 = (int)SEQ_PTR(_17val);
    _9020 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9020);
    if (IS_ATOM_INT(_9015))
        poke4_addr = (unsigned long *)_9015;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9015)->dbl);
    if (IS_ATOM_INT(_9020)) {
        *poke4_addr = (unsigned long)_9020;
    }
    else if (IS_ATOM(_9020)) {
        *poke4_addr = (unsigned long)DBL_PTR(_9020)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_9020);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *(int *)poke4_addr++ = (unsigned long)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *(int *)poke4_addr++ = (unsigned long)DBL_PTR(_2)->dbl;
            }
        }
    }

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9020);
    DeRef(_9015);
    return 0;
    ;
}


int _17opMEM_COPY()
{
    int _9030 = 0;
    int _9029 = 0;
    int _9022 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9022 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9022);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9022 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9022);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]
    _9022 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _9022);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	mem_copy(val[a], val[b], val[c])
    _2 = (int)SEQ_PTR(_17val);
    _9022 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9022);
    _2 = (int)SEQ_PTR(_17val);
    _9029 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9029);
    _2 = (int)SEQ_PTR(_17val);
    _9030 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_9030);
    memory_copy(_9022, _9029, _9030);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9030);
    DeRef(_9029);
    DeRef(_9022);
    return 0;
    ;
}


int _17opMEM_SET()
{
    int _9040 = 0;
    int _9039 = 0;
    int _9032 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9032 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9032);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9032 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9032);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]
    _9032 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _9032);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	mem_set(val[a], val[b], val[c])
    _2 = (int)SEQ_PTR(_17val);
    _9032 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9032);
    _2 = (int)SEQ_PTR(_17val);
    _9039 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9039);
    _2 = (int)SEQ_PTR(_17val);
    _9040 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_9040);
    memory_set(_9032, _9039, _9040);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9040);
    DeRef(_9039);
    DeRef(_9032);
    return 0;
    ;
}


int _17opPIXEL()
{
    int _9047 = 0;
    int _9042 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9042 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9042);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9042 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9042);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	pixel(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9042 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9042);
    _2 = (int)SEQ_PTR(_17val);
    _9047 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9047);
    Pixel(_9042, _9047);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9047);
    DeRef(_9042);
    return 0;
    ;
}


int _17opGET_PIXEL()
{
    int _9049 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9049 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9049);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _9049 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9049);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = get_pixel(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9049 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9049);
    _0 = _9049;
    _9049 = Get_Pixel(_9049);
    DeRef(_0);
    Ref(_9049);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9049;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9049);
    return 0;
    ;
}


int _17opCALL()
{
    int _9056 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9056 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9056);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	call(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9056 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9056);
    if (IS_ATOM_INT(_9056))
        _0 = (int)_9056;
    else
        _0 = (int)(unsigned long)(DBL_PTR(_9056)->dbl);
    (*(void(*)())_0)();

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_9056);
    return 0;
    ;
}


int _17opSYSTEM()
{
    int _9065 = 0;
    int _9060 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9060 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9060);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9060 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9060);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	system(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9060 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9060);
    _2 = (int)SEQ_PTR(_17val);
    _9065 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9065);
    system_call(_9060, _9065);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9065);
    DeRef(_9060);
    return 0;
    ;
}


int _17opSYSTEM_EXEC()
{
    int _9074 = 0;
    int _9067 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9067 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9067);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9067 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9067);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _9067 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9067);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = system_exec(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9067 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9067);
    _2 = (int)SEQ_PTR(_17val);
    _9074 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9074);
    _0 = _9074;
    _9074 = system_exec_call(_9067, _9074);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9074;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9067);
    return 0;
    ;
}


int _17opOPEN()
{
    int _9084 = 0;
    int _9077 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9077 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9077);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9077 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9077);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _9077 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9077);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = open(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9077 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9077);
    _2 = (int)SEQ_PTR(_17val);
    _9084 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9084);
    _0 = _9084;
    _9084 = EOpen(_9077, _9084);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9084;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9077);
    return 0;
    ;
}


int _17opCLOSE()
{
    int _9087 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9087 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9087);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	close(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9087 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9087);
    if (IS_ATOM_INT(_9087))
        EClose(_9087);
    else
        EClose((int)DBL_PTR(_9087)->dbl);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_9087);
    return 0;
    ;
}


int _17opABORT()
{
    int _9091 = 0;
    int _0, _1, _2;
    

    // 	if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto L1;

    // 		c_proc( cleanup_cb, {} )
    call_c(0, _7cleanup_cb, _39);
L1:

    // 	abort(val[Code[pc+1]])
    DeRef(_9091);
    _9091 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9091 = (int)*(((s1_ptr)_2)->base + _9091);
    Ref(_9091);
    _0 = _9091;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9091))
        _9091 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9091)->dbl));
    else
        _9091 = (int)*(((s1_ptr)_2)->base + _9091);
    Ref(_9091);
    DeRef(_0);
    if (IS_ATOM_INT(_9091))
        UserCleanup(_9091);
    else
        UserCleanup((int)DBL_PTR(_9091)->dbl);

    // end procedure
    DeRef(_9091);
    return 0;
    ;
}


int _17opGETC()
{
    int _9095 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9095 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9095);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _9095 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9095);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = getc(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9095 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9095);
    _0 = _9095;
    if (_9095 != last_r_file_no) {
        last_r_file_ptr = which_file(_9095, EF_READ);
        if (IS_ATOM_INT(_9095))
            last_r_file_no = _9095;
        else
            last_r_file_no = NOVALUE;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _9095 = getc(xstdin);
        }
        else
            _9095 = getc(last_r_file_ptr);
    }
    else
        _9095 = getc(last_r_file_ptr);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9095;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    return 0;
    ;
}


int _17opGETS()
{
    int _9102 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9102 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9102);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _9102 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9102);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = gets(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9102 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9102);
    _0 = _9102;
    _9102 = EGets(_9102);
    DeRef(_0);
    Ref(_9102);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9102;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRefi(_9102);
    return 0;
    ;
}


int _17opGET_KEY()
{
    int _9109;
    int _0, _1, _2;
    

    // 	target = Code[pc+1]
    _9109 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9109);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = get_key()
    _9109 = get_key(0);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9109;
    DeRef(_1);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    return 0;
    ;
}


int _17opCLEAR_SCREEN()
{
    int _0, _1, _2;
    

    // 	clear_screen()
    ClearScreen();

    // 	pc += 1
    _17pc = _17pc + 1;

    // end procedure
    return 0;
    ;
}


int _17opPUTS()
{
    int _9119 = 0;
    int _9114 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9114 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9114);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9114 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9114);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	puts(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9114 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9114);
    _2 = (int)SEQ_PTR(_17val);
    _9119 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9119);
    EPuts(_9114, _9119);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9119);
    DeRef(_9114);
    return 0;
    ;
}


int _17opQPRINT()
{
    int _9121 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+2]
    _9121 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9121);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	? val[a]
    _2 = (int)SEQ_PTR(_17val);
    _9121 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9121);
    StdPrint(1, _9121, 1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9121);
    return 0;
    ;
}


int _17opPRINT()
{
    int _9130 = 0;
    int _9125 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9125 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9125);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9125 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9125);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	print(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9125 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9125);
    _2 = (int)SEQ_PTR(_17val);
    _9130 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9130);
    Ref(_9125);
    Ref(_9130);
    _5print(_9125, _9130);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9130);
    DeRef(_9125);
    return 0;
    ;
}


int _17opPRINTF()
{
    int _9140 = 0;
    int _9139 = 0;
    int _9132 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9132 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9132);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9132 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9132);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]
    _9132 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _9132);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	printf(val[a], val[b], val[c])
    _2 = (int)SEQ_PTR(_17val);
    _9132 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9132);
    _2 = (int)SEQ_PTR(_17val);
    _9139 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9139);
    _2 = (int)SEQ_PTR(_17val);
    _9140 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_9140);
    EPrintf(_9132, _9139, _9140);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9140);
    DeRef(_9139);
    DeRef(_9132);
    return 0;
    ;
}


int _17opILLEGAL()
{
    int _9142;
    int _0, _1, _2;
    

    // 	eval_error[$] = "illegal call within an eval"
    _9142 = SEQ_PTR(_7eval_error)->length;
    RefDS(_9143);
    _2 = (int)SEQ_PTR(_7eval_error);
    _2 = (int)(((s1_ptr)_2)->base + _9142);
    _1 = *(int *)_2;
    *(int *)_2 = _9143;
    DeRefDS(_1);

    // end procedure
    return 0;
    ;
}


int _17debugger_io(int _a)
{
    int _9144 = 0;
    int _0, _1, _2;
    

    // 	c_proc( debug_out, {a} )
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_a);
    *((int *)(_2+4)) = _a;
    _9144 = MAKE_SEQ(_1);
    call_c(0, _7debug_out, _9144);

    // end procedure
    DeRef(_a);
    DeRefDS(_9144);
    return 0;
    ;
}


int _17opPUTS_debug()
{
    int _9153 = 0;
    int _9145 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9145 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9145);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9145 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9145);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] = 1 then
    _2 = (int)SEQ_PTR(_17val);
    _9145 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9145);
    if (binary_op_a(NOTEQ, _9145, 1))
        goto L1;

    // 		debugger_io( val[b] )
    DeRef(_9145);
    _2 = (int)SEQ_PTR(_17val);
    _9145 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9145);
    Ref(_9145);
    _17debugger_io(_9145);
    goto L2;
L1:

    // 		puts(val[a], val[b])
    DeRef(_9145);
    _2 = (int)SEQ_PTR(_17val);
    _9145 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9145);
    DeRef(_9153);
    _2 = (int)SEQ_PTR(_17val);
    _9153 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9153);
    EPuts(_9145, _9153);
L2:

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9153);
    DeRef(_9145);
    return 0;
    ;
}


int _17opQPRINT_debug()
{
    int _9155 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+2]
    _9155 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9155);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	debugger_io( pretty_sprint(val[a]) )
    _2 = (int)SEQ_PTR(_17val);
    _9155 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9155);
    Ref(_9155);
    _0 = _9155;
    _9155 = _6pretty_sprint(_9155);
    DeRef(_0);
    RefDS(_9155);
    _17debugger_io(_9155);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRefDS(_9155);
    return 0;
    ;
}


int _17opPRINT_debug()
{
    int _9169 = 0;
    int _9160 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9160 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9160);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9160 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9160);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if val[a] = 1 then
    _2 = (int)SEQ_PTR(_17val);
    _9160 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9160);
    if (binary_op_a(NOTEQ, _9160, 1))
        goto L1;

    // 		debugger_io( pretty_sprint( val[b] ) )
    DeRef(_9160);
    _2 = (int)SEQ_PTR(_17val);
    _9160 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9160);
    Ref(_9160);
    _0 = _9160;
    _9160 = _6pretty_sprint(_9160);
    DeRef(_0);
    RefDS(_9160);
    _17debugger_io(_9160);
    goto L2;
L1:

    // 		print(val[a], val[b])
    DeRef(_9160);
    _2 = (int)SEQ_PTR(_17val);
    _9160 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9160);
    DeRef(_9169);
    _2 = (int)SEQ_PTR(_17val);
    _9169 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9169);
    Ref(_9160);
    Ref(_9169);
    _5print(_9160, _9169);
L2:

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9169);
    DeRef(_9160);
    return 0;
    ;
}


int _17opPRINTF_debug()
{
    int _9184 = 0;
    int _9171 = 0;
    int _9180 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9171 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9171);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9171 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9171);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c = Code[pc+3]
    _9171 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17c = (int)*(((s1_ptr)_2)->base + _9171);
    if (!IS_ATOM_INT(_17c))
        _17c = (long)DBL_PTR(_17c)->dbl;

    // 	if val[a] = 1 then
    _2 = (int)SEQ_PTR(_17val);
    _9171 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9171);
    if (binary_op_a(NOTEQ, _9171, 1))
        goto L1;

    // 		debugger_io( sprintf( val[b], val[c] ) )
    DeRef(_9171);
    _2 = (int)SEQ_PTR(_17val);
    _9171 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9171);
    _2 = (int)SEQ_PTR(_17val);
    _9180 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_9180);
    _0 = _9180;
    _9180 = EPrintf(-9999999, _9171, _9180);
    DeRef(_0);
    RefDS(_9180);
    _17debugger_io(_9180);
    goto L2;
L1:

    // 		printf(val[a], val[b], val[c])
    DeRef(_9180);
    _2 = (int)SEQ_PTR(_17val);
    _9180 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9180);
    DeRef(_9171);
    _2 = (int)SEQ_PTR(_17val);
    _9171 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9171);
    DeRef(_9184);
    _2 = (int)SEQ_PTR(_17val);
    _9184 = (int)*(((s1_ptr)_2)->base + _17c);
    Ref(_9184);
    EPrintf(_9180, _9171, _9184);
L2:

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9184);
    DeRef(_9171);
    DeRef(_9180);
    return 0;
    ;
}


int _17set_debug_io(int _setting)
{
    int _9187;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_setting)) {
        _1 = (long)(DBL_PTR(_setting)->dbl);
        DeRefDS(_setting);
        _setting = _1;
    }

    // 	if setting then
    if (_setting == 0)
        goto L1;

    // 		operation[PUTS]   = routine_id("opPUTS_debug")
    _9187 = CRoutineId(430, 17, _9186);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 44);
    *(int *)_2 = _9187;

    // 		operation[PRINTF] = routine_id("opPRINTF_debug")
    _9187 = CRoutineId(430, 17, _9188);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 38);
    *(int *)_2 = _9187;

    // 		operation[PRINT]  = routine_id("opPRINT_debug")
    _9187 = CRoutineId(430, 17, _9190);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 19);
    *(int *)_2 = _9187;

    // 		operation[QPRINT] = routine_id("opQPRINT_debug")
    _9187 = CRoutineId(430, 17, _9192);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 36);
    *(int *)_2 = _9187;
    goto L2;
L1:

    // 		operation[PUTS]   = routine_id("opPUTS")
    _9187 = CRoutineId(430, 17, _9194);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 44);
    *(int *)_2 = _9187;

    // 		operation[PRINTF] = routine_id("opPRINTF")
    _9187 = CRoutineId(430, 17, _9196);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 38);
    *(int *)_2 = _9187;

    // 		operation[PRINT]  = routine_id("opPRINT")
    _9187 = CRoutineId(430, 17, _9198);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 19);
    *(int *)_2 = _9187;

    // 		operation[QPRINT] = routine_id("opQPRINT")
    _9187 = CRoutineId(430, 17, _9200);
    _2 = (int)SEQ_PTR(_17operation);
    _2 = (int)(((s1_ptr)_2)->base + 36);
    *(int *)_2 = _9187;
L2:

    // 	return 0
    return 0;
    ;
}


int _17opSPRINTF()
{
    int _9212 = 0;
    int _9205 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9205 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9205);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9205 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9205);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _9205 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9205);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = sprintf(val[a], val[b])
    _2 = (int)SEQ_PTR(_17val);
    _9205 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9205);
    _2 = (int)SEQ_PTR(_17val);
    _9212 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9212);
    _0 = _9212;
    _9212 = EPrintf(-9999999, _9205, _9212);
    DeRef(_0);
    RefDS(_9212);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9212;
    DeRef(_1);

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRefDSi(_9212);
    DeRef(_9205);
    return 0;
    ;
}


int _17opCOMMAND_LINE()
{
    int _cmd = 0;
    int _9222 = 0;
    int _9215 = 0;
    int _0, _1, _2;
    

    // 	target = Code[pc+1]
    _9215 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9215);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	cmd = command_line()
    _cmd = Command_Line();

    // 	if length(cmd) > 2 then
    _9215 = SEQ_PTR(_cmd)->length;
    if (_9215 <= 2)
        goto L1;

    // 	cmd = {cmd[1]} & cmd[3..$]
    _2 = (int)SEQ_PTR(_cmd);
    _9215 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_9215);
    _0 = _9215;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_9215);
    *((int *)(_2+4)) = _9215;
    _9215 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _9222 = SEQ_PTR(_cmd)->length;
    rhs_slice_target = (object_ptr)&_9222;
    RHS_Slice((s1_ptr)_cmd, 3, _9222);
    Concat((object_ptr)&_cmd, _9215, (s1_ptr)_9222);
L1:

    // 	val[target] = cmd
    RefDS(_cmd);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _cmd;
    DeRef(_1);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDS(_cmd);
    DeRef(_9222);
    DeRef(_9215);
    return 0;
    ;
}


int _17opGETENV()
{
    int _9226 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9226 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9226);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = Code[pc+2]
    _9226 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9226);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = getenv(val[a])
    _2 = (int)SEQ_PTR(_17val);
    _9226 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9226);
    DeRef(_9226);
    _9226 = EGetEnv(_9226);
    Ref(_9226);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9226;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRefi(_9226);
    return 0;
    ;
}


int _17opC_PROC()
{
    int _9238 = 0;
    int _9233 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9233 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9233);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9233 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9233);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	c_proc(val[a], val[b])	-- callback could happen here
    _2 = (int)SEQ_PTR(_17val);
    _9233 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9233);
    _2 = (int)SEQ_PTR(_17val);
    _9238 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9238);
    call_c(0, _9233, _9238);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9238);
    DeRef(_9233);
    return 0;
    ;
}


int _17opC_FUNC()
{
    int _target;
    int _9247 = 0;
    int _9240 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9240 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9240);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _9240 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9240);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _9240 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _target = (int)*(((s1_ptr)_2)->base + _9240);
    if (!IS_ATOM_INT(_target))
        _target = (long)DBL_PTR(_target)->dbl;

    // 	val[target] = c_func(val[a], val[b])  -- callback could happen here
    _2 = (int)SEQ_PTR(_17val);
    _9240 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9240);
    _2 = (int)SEQ_PTR(_17val);
    _9247 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9247);
    _0 = _9247;
    _9247 = call_c(1, _9240, _9247);
    DeRef(_0);
    Ref(_9247);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _target);
    _1 = *(int *)_2;
    *(int *)_2 = _9247;
    DeRef(_1);

    // 	pc += 4 
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_9247);
    DeRef(_9240);
    return 0;
    ;
}


int _17opTRACE()
{
    int _9255;
    int _9250 = 0;
    int _0, _1, _2;
    

    // 	TraceOn = val[Code[pc+1]]
    _9250 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9250 = (int)*(((s1_ptr)_2)->base + _9250);
    Ref(_9250);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9250))
        _17TraceOn = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9250)->dbl));
    else
        _17TraceOn = (int)*(((s1_ptr)_2)->base + _9250);
    if (!IS_ATOM_INT(_17TraceOn))
        _17TraceOn = (long)DBL_PTR(_17TraceOn)->dbl;

    // 	if TraceOn = 0 and debugger > 0 then
    DeRef(_9250);
    _9250 = (_17TraceOn == 0);
    if (_9250 == 0) {
        goto L1;
    }
    if (IS_ATOM_INT(_7debugger)) {
        _9255 = (_7debugger > 0);
    }
    else {
        _9255 = (DBL_PTR(_7debugger)->dbl > (double)0);
    }
L2:
    if (_9255 == 0)
        goto L1;

    // 		c_proc( hide_debugger, {})
    call_c(0, _7hide_debugger, _39);
L1:

    // 	pc += 2  -- turn on/off tracing
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_9250);
    return 0;
    ;
}


int _17opPROFILE()
{
    int _0, _1, _2;
    

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    return 0;
    ;
}


int _17opDISPLAY_VAR()
{
    int _9260 = 0;
    int _9258;
    int _0, _1, _2;
    

    // 	if TraceOn = 0 or TraceOn > 2 or not debugger or in_trace > 1 then
    _9258 = (_17TraceOn == 0);
    if (_9258 != 0) {
        _9258 = 1;
        goto L1;
    }
    _9260 = (_17TraceOn > 2);
    _9258 = (_9260 != 0);
L1:
    if (_9258 != 0) {
        DeRef(_9260);
        _9260 = 1;
        goto L2;
    }
    if (IS_ATOM_INT(_7debugger)) {
        _9258 = (_7debugger == 0);
    }
    else {
        _9258 = unary_op(NOT, _7debugger);
    }
    _9260 = (_9258 != 0);
L2:
    if (_9260 != 0) {
        goto L3;
    }
    DeRef(_9260);
    _9260 = (_17in_trace > 1);
L4:
    if (_9260 == 0)
        goto L5;
L3:

    // 		pc += 2
    _17pc = _17pc + 2;

    // 		return
    DeRef(_9260);
    return 0;
L5:

    // 	c_proc( display_var_cb, {Code[pc+1]})
    DeRef(_9260);
    _9260 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9260 = (int)*(((s1_ptr)_2)->base + _9260);
    Ref(_9260);
    _0 = _9260;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9260);
    *((int *)(_2+4)) = _9260;
    _9260 = MAKE_SEQ(_1);
    DeRef(_0);
    call_c(0, _7display_var_cb, _9260);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDS(_9260);
    return 0;
    ;
}


