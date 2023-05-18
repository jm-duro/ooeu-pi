// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17opSC1_OR()
{
    int _8337 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8337 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8337);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8337 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8337);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _8337 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8337);
    _0 = _8337;
    _8337 = IS_ATOM(_8337);
    DeRef(_0);
    if (_8337 == 0)
        goto L1;

    // 	if val[a] != 0 then
    _2 = (int)SEQ_PTR(_17val);
    _8337 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8337);
    if (binary_op_a(EQUALS, _8337, 0))
        goto L2;

    // 	    val[b] = 1
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17b);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	    pc = Code[pc+3]
    DeRef(_8337);
    _8337 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8337);
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
    DeRef(_8337);
    return 0;
L2:

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8337);
    return 0;
    ;
}


int _17opSC1_OR_IF()
{
    int _8348 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8348 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8348);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8348 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8348);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _8348 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8348);
    _0 = _8348;
    _8348 = IS_ATOM(_8348);
    DeRef(_0);
    if (_8348 == 0)
        goto L1;

    // 	if val[a] != 0 then
    _2 = (int)SEQ_PTR(_17val);
    _8348 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8348);
    if (binary_op_a(EQUALS, _8348, 0))
        goto L2;

    // 	    val[b] = 1
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17b);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	    pc = Code[pc+3]
    DeRef(_8348);
    _8348 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8348);
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
    DeRef(_8348);
    return 0;
L2:

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_8348);
    return 0;
    ;
}


int _17opSC2_OR()
{
    int _8359 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _8359 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8359);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _8359 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8359);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _8359 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8359);
    _0 = _8359;
    _8359 = IS_ATOM(_8359);
    DeRef(_0);
    if (_8359 == 0)
        goto L1;

    // 	val[b] = val[a] 
    _2 = (int)SEQ_PTR(_17val);
    _8359 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8359);
    Ref(_8359);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17b);
    _1 = *(int *)_2;
    *(int *)_2 = _8359;
    DeRef(_1);
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_8324);
    _17RTFatal(_8324);

    // 	return
    DeRef(_8359);
    return 0;
L2:

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_8359);
    return 0;
    ;
}


int _17opFOR()
{
    int _increment;
    int _limit;
    int _initial;
    int _loopvar;
    int _jump;
    int _8367 = 0;
    int _8390 = 0;
    int _0, _1, _2;
    

    // 	increment = Code[pc+1]
    _8367 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _increment = (int)*(((s1_ptr)_2)->base + _8367);
    if (!IS_ATOM_INT(_increment))
        _increment = (long)DBL_PTR(_increment)->dbl;

    // 	limit = Code[pc+2]
    _8367 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _limit = (int)*(((s1_ptr)_2)->base + _8367);
    if (!IS_ATOM_INT(_limit))
        _limit = (long)DBL_PTR(_limit)->dbl;

    // 	initial = Code[pc+3]
    _8367 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _initial = (int)*(((s1_ptr)_2)->base + _8367);
    if (!IS_ATOM_INT(_initial))
        _initial = (long)DBL_PTR(_initial)->dbl;

    // 	loopvar = Code[pc+5]
    _8367 = _17pc + 5;
    _2 = (int)SEQ_PTR(_7Code);
    _loopvar = (int)*(((s1_ptr)_2)->base + _8367);
    if (!IS_ATOM_INT(_loopvar))
        _loopvar = (long)DBL_PTR(_loopvar)->dbl;

    // 	jump = Code[pc+6]
    _8367 = _17pc + 6;
    _2 = (int)SEQ_PTR(_7Code);
    _jump = (int)*(((s1_ptr)_2)->base + _8367);
    if (!IS_ATOM_INT(_jump))
        _jump = (long)DBL_PTR(_jump)->dbl;

    // 	if sequence(val[initial]) then
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_8367);
    _0 = _8367;
    _8367 = IS_SEQUENCE(_8367);
    DeRef(_0);
    if (_8367 == 0)
        goto L1;

    // 	RTFatal("for-loop variable is not an atom")
    RefDS(_8379);
    _17RTFatal(_8379);

    // 	return
    return 0;
L1:

    // 	if sequence(val[limit]) then
    DeRef(_8367);
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _limit);
    Ref(_8367);
    _0 = _8367;
    _8367 = IS_SEQUENCE(_8367);
    DeRef(_0);
    if (_8367 == 0)
        goto L2;

    // 	RTFatal("for-loop limit is not an atom")
    RefDS(_8382);
    _17RTFatal(_8382);

    // 	return
    DeRef(_8390);
    return 0;
L2:

    // 	if sequence(val[increment]) then
    DeRef(_8367);
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _increment);
    Ref(_8367);
    _0 = _8367;
    _8367 = IS_SEQUENCE(_8367);
    DeRef(_0);
    if (_8367 == 0)
        goto L3;

    // 	RTFatal("for-loop increment is not an atom")
    RefDS(_8385);
    _17RTFatal(_8385);

    // 	return
    DeRef(_8390);
    return 0;
L3:

    // 	pc += 7 -- to enter into the loop
    _17pc = _17pc + 7;

    // 	if val[increment] >= 0 then
    DeRef(_8367);
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _increment);
    Ref(_8367);
    if (binary_op_a(LESS, _8367, 0))
        goto L4;

    // 	if val[initial] > val[limit] then
    DeRef(_8367);
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_8367);
    DeRef(_8390);
    _2 = (int)SEQ_PTR(_17val);
    _8390 = (int)*(((s1_ptr)_2)->base + _limit);
    Ref(_8390);
    if (binary_op_a(LESSEQ, _8367, _8390))
        goto L5;

    // 	    pc = jump -- quit immediately, 0 iterations
    _17pc = _jump;
L6:
    goto L5;
L4:

    // 	if val[initial] < val[limit] then
    DeRef(_8390);
    _2 = (int)SEQ_PTR(_17val);
    _8390 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_8390);
    DeRef(_8367);
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _limit);
    Ref(_8367);
    if (binary_op_a(GREATEREQ, _8390, _8367))
        goto L7;

    // 	    pc = jump -- quit immediately, 0 iterations
    _17pc = _jump;
L7:
L5:

    // 	val[loopvar] = val[initial] -- initialize loop var
    DeRef(_8367);
    _2 = (int)SEQ_PTR(_17val);
    _8367 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_8367);
    Ref(_8367);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _8367;
    DeRef(_1);

    // end procedure
    DeRef(_8367);
    DeRef(_8390);
    return 0;
    ;
}


int _17opENDFOR_GENERAL()
{
    int _loopvar;
    int _increment = 0;
    int _limit = 0;
    int _next = 0;
    int _8396 = 0;
    int _0, _1, _2;
    

    // 	limit = val[Code[pc+2]]
    _8396 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _8396 = (int)*(((s1_ptr)_2)->base + _8396);
    Ref(_8396);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8396))
        _limit = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8396)->dbl));
    else
        _limit = (int)*(((s1_ptr)_2)->base + _8396);
    Ref(_limit);

    // 	increment = val[Code[pc+4]]
    DeRef(_8396);
    _8396 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _8396 = (int)*(((s1_ptr)_2)->base + _8396);
    Ref(_8396);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8396))
        _increment = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8396)->dbl));
    else
        _increment = (int)*(((s1_ptr)_2)->base + _8396);
    Ref(_increment);

    // 	loopvar = Code[pc+3]
    DeRef(_8396);
    _8396 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _loopvar = (int)*(((s1_ptr)_2)->base + _8396);
    if (!IS_ATOM_INT(_loopvar))
        _loopvar = (long)DBL_PTR(_loopvar)->dbl;

    // 	next = val[loopvar] + increment
    _2 = (int)SEQ_PTR(_17val);
    _8396 = (int)*(((s1_ptr)_2)->base + _loopvar);
    Ref(_8396);
    if (IS_ATOM_INT(_8396) && IS_ATOM_INT(_increment)) {
        _next = _8396 + _increment;
        if ((long)((unsigned long)_next + (unsigned long)HIGH_BITS) >= 0) 
            _next = NewDouble((double)_next);
    }
    else {
        _next = binary_op(PLUS, _8396, _increment);
    }

    // 	if increment >= 0 then
    if (binary_op_a(LESS, _increment, 0))
        goto L1;

    // 	if next > limit then
    if (binary_op_a(LESSEQ, _next, _limit))
        goto L2;

    // 	    pc += 5 -- exit loop
    _17pc = _17pc + 5;
    goto L3;
L2:

    // 	    val[loopvar] = next
    Ref(_next);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _next;
    DeRef(_1);

    // 	    pc = Code[pc+1] -- loop again
    DeRef(_8396);
    _8396 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8396);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L4:
    goto L3;
L1:

    // 	if next < limit then
    if (binary_op_a(GREATEREQ, _next, _limit))
        goto L5;

    // 	    pc += 5 -- exit loop
    _17pc = _17pc + 5;
    goto L6;
L5:

    // 	    val[loopvar] = next
    Ref(_next);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _next;
    DeRef(_1);

    // 	    pc = Code[pc+1] -- loop again
    DeRef(_8396);
    _8396 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8396);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L6:
L3:

    // end procedure
    DeRef(_increment);
    DeRef(_limit);
    DeRef(_next);
    DeRef(_8396);
    return 0;
    ;
}


int _17opENDFOR_INT_UP1()
{
    int _loopvar;
    int _limit = 0;
    int _next = 0;
    int _8415 = 0;
    int _0, _1, _2;
    

    // 	limit = val[Code[pc+2]]
    _8415 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _8415 = (int)*(((s1_ptr)_2)->base + _8415);
    Ref(_8415);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_8415))
        _limit = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8415)->dbl));
    else
        _limit = (int)*(((s1_ptr)_2)->base + _8415);
    Ref(_limit);

    // 	loopvar = Code[pc+3]
    DeRef(_8415);
    _8415 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _loopvar = (int)*(((s1_ptr)_2)->base + _8415);
    if (!IS_ATOM_INT(_loopvar))
        _loopvar = (long)DBL_PTR(_loopvar)->dbl;

    // 	next = val[loopvar] + 1
    _2 = (int)SEQ_PTR(_17val);
    _8415 = (int)*(((s1_ptr)_2)->base + _loopvar);
    Ref(_8415);
    if (IS_ATOM_INT(_8415)) {
        _next = _8415 + 1;
        if (_next > MAXINT)
            _next = NewDouble((double)_next);
    }
    else
        _next = binary_op(PLUS, 1, _8415);

    // 	if next > limit then
    if (binary_op_a(LESSEQ, _next, _limit))
        goto L1;

    // 	pc += 5 -- exit loop
    _17pc = _17pc + 5;
    goto L2;
L1:

    // 	val[loopvar] = next
    Ref(_next);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _next;
    DeRef(_1);

    // 	pc = Code[pc+1] -- loop again
    DeRef(_8415);
    _8415 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17pc = (int)*(((s1_ptr)_2)->base + _8415);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L2:

    // end procedure
    DeRef(_limit);
    DeRef(_next);
    DeRef(_8415);
    return 0;
    ;
}


int _17RTLookup(int _name, int _file, int _proc, int _stlen)
{
    int _s;
    int _global_found;
    int _colon;
    int _stop;
    int _p;
    int _ns;
    int _ns_file;
    int _8429 = 0;
    int _8542 = 0;
    int _8439 = 0;
    int _8426 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file)) {
        _1 = (long)(DBL_PTR(_file)->dbl);
        DeRefDS(_file);
        _file = _1;
    }
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }
    if (!IS_ATOM_INT(_stlen)) {
        _1 = (long)(DBL_PTR(_stlen)->dbl);
        DeRefDS(_stlen);
        _stlen = _1;
    }

    // 	if proc = 0 then
    if (_proc != 0)
        goto L1;

    // 	return 0
    DeRefDS(_name);
    return 0;
L1:

    // 	if proc = TopLevelSub or proc = eval_sym then 	
    DeRef(_8426);
    _8426 = (_proc == _7TopLevelSub);
    if (_8426 != 0) {
        goto L2;
    }
    DeRef(_8429);
    _8429 = (_proc == _7eval_sym);
L3:
    if (_8429 == 0)
        goto L4;
L2:

    // 		stop = 0
    _stop = 0;
    goto L5;
L4:

    // 		stop = SymTab[proc][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _proc);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _stop = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_stop))
        _stop = (long)DBL_PTR(_stop)->dbl;
L5:

    // 	colon = find(':', name)
    _colon = find(58, _name);

    // 	if colon then
    if (_colon == 0)
        goto L6;

    // 	p = colon-1
    _p = _colon - 1;

    // 	while p >= 1 and (name[p] = ' ' or name[p] = '\t') do
L7:
    DeRef(_8429);
    _8429 = (_p >= 1);
    if (_8429 == 0) {
        goto L8;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_name);
    _8426 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_8426);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_8426 == 32);
    }
    else {
        _8426 = binary_op(EQUALS, _8426, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8426)) {
        if (_8426 != 0) {
            DeRef(_8426);
            _8426 = 1;
            goto L9;
        }
    }
    else {
        if (DBL_PTR(_8426)->dbl != 0.0) {
            DeRef(_8426);
            _8426 = 1;
            goto L9;
        }
    }
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_name);
    _8439 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_8439);
    _0 = _8439;
    if (IS_ATOM_INT(_8439)) {
        _8439 = (_8439 == 9);
    }
    else {
        _8439 = binary_op(EQUALS, _8439, 9);
    }
    DeRef(_0);
    DeRef(_8426);
    if (IS_ATOM_INT(_8439))
        _8426 = (_8439 != 0);
    else
        _8426 = DBL_PTR(_8439)->dbl != 0.0;
L9:
LA:
    if (_8426 == 0)
        goto L8;

    // 	    p -= 1
    _p = _p - 1;

    // 	end while
    goto L7;
L8:

    // 	name = name[1..p] 
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, 1, _p);

    // 	ns = 1
    _ns = 1;

    // 	while ns <= length(name) and (name[ns] = ' ' or name[ns] = '\t') do
LB:
    DeRef(_8439);
    _8439 = SEQ_PTR(_name)->length;
    _8439 = (_ns <= _8439);
    if (_8439 == 0) {
        goto LC;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_name);
    _8426 = (int)*(((s1_ptr)_2)->base + _ns);
    Ref(_8426);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_8426 == 32);
    }
    else {
        _8426 = binary_op(EQUALS, _8426, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8426)) {
        if (_8426 != 0) {
            DeRef(_8426);
            _8426 = 1;
            goto LD;
        }
    }
    else {
        if (DBL_PTR(_8426)->dbl != 0.0) {
            DeRef(_8426);
            _8426 = 1;
            goto LD;
        }
    }
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_name);
    _8429 = (int)*(((s1_ptr)_2)->base + _ns);
    Ref(_8429);
    _0 = _8429;
    if (IS_ATOM_INT(_8429)) {
        _8429 = (_8429 == 9);
    }
    else {
        _8429 = binary_op(EQUALS, _8429, 9);
    }
    DeRef(_0);
    DeRef(_8426);
    if (IS_ATOM_INT(_8429))
        _8426 = (_8429 != 0);
    else
        _8426 = DBL_PTR(_8429)->dbl != 0.0;
LD:
LE:
    if (_8426 == 0)
        goto LC;

    // 	    ns += 1
    _ns = _ns + 1;

    // 	end while
    goto LB;
LC:

    // 	if ns > length(name) then
    DeRef(_8429);
    _8429 = SEQ_PTR(_name)->length;
    if (_ns <= _8429)
        goto LF;

    // 	    return 0
    DeRefDS(_name);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return 0;
LF:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop and length( SymTab[s] ) >= S_NEXT do
L10:
    DeRef(_8429);
    _8429 = (_s != _stop);
    if (_8429 == 0) {
        goto L11;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _8426 = SEQ_PTR(_8426)->length;
    DeRef(_0);
    _8426 = (_8426 >= 2);
L12:
    if (_8426 == 0)
        goto L11;

    // 	    if file = SymTab[s][S_FILE_NO] and 
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _2 = (int)SEQ_PTR(_8426);
    _8426 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8426);
    DeRef(_0);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_file == _8426);
    }
    else {
        _8426 = binary_op(EQUALS, _file, _8426);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8426)) {
        if (_8426 == 0) {
            DeRef(_8426);
            _8426 = 0;
            goto L13;
        }
    }
    else {
        if (DBL_PTR(_8426)->dbl == 0.0) {
            DeRef(_8426);
            _8426 = 0;
            goto L13;
        }
    }
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _0 = _8429;
    _2 = (int)SEQ_PTR(_8429);
    _8429 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_8429);
    DeRef(_0);
    _0 = _8429;
    if (IS_ATOM_INT(_8429)) {
        _8429 = (_8429 == 523);
    }
    else {
        _8429 = binary_op(EQUALS, _8429, 523);
    }
    DeRef(_0);
    DeRef(_8426);
    if (IS_ATOM_INT(_8429))
        _8426 = (_8429 != 0);
    else
        _8426 = DBL_PTR(_8429)->dbl != 0.0;
L13:
    if (_8426 == 0) {
        goto L14;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _2 = (int)SEQ_PTR(_8426);
    _8426 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8426);
    DeRef(_0);
    _0 = _8426;
    if (_ns == _8426)
        _8426 = 1;
    else if (IS_ATOM_INT(_ns) && IS_ATOM_INT(_8426))
        _8426 = 0;
    else
        _8426 = (compare(_ns, _8426) == 0);
    DeRef(_0);
L15:
    if (_8426 == 0)
        goto L14;

    // 		exit
    goto L11;
L14:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_8426);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while
    goto L10;
L11:

    // 	if s = 0 then
    if (_s != 0)
        goto L16;

    // 	    return 0
    DeRefDS(_name);
    DeRef(_8429);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return 0;
L16:

    // 	ns_file = SymTab[s][S_OBJ]
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_8426);
    _ns_file = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_ns_file))
        _ns_file = (long)DBL_PTR(_ns_file)->dbl;

    // 	name = name[colon+1..$]
    DeRef(_8426);
    _8426 = _colon + 1;
    DeRef(_8429);
    _8429 = SEQ_PTR(_name)->length;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, _8426, _8429);

    // 	while length(name) and (name[1] = ' ' or name[1] = '\t') do
L17:
    DeRef(_8429);
    _8429 = SEQ_PTR(_name)->length;
    if (_8429 == 0) {
        goto L18;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_name);
    _8426 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8426);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_8426 == 32);
    }
    else {
        _8426 = binary_op(EQUALS, _8426, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8426)) {
        if (_8426 != 0) {
            DeRef(_8426);
            _8426 = 1;
            goto L19;
        }
    }
    else {
        if (DBL_PTR(_8426)->dbl != 0.0) {
            DeRef(_8426);
            _8426 = 1;
            goto L19;
        }
    }
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_name);
    _8439 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8439);
    _0 = _8439;
    if (IS_ATOM_INT(_8439)) {
        _8439 = (_8439 == 9);
    }
    else {
        _8439 = binary_op(EQUALS, _8439, 9);
    }
    DeRef(_0);
    DeRef(_8426);
    if (IS_ATOM_INT(_8439))
        _8426 = (_8439 != 0);
    else
        _8426 = DBL_PTR(_8439)->dbl != 0.0;
L19:
L1A:
    if (_8426 == 0)
        goto L18;

    // 	    name = name[2..$]
    DeRef(_8439);
    _8439 = SEQ_PTR(_name)->length;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, 2, _8439);

    // 	end while
    goto L17;
L18:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8439 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8439);
    _2 = (int)SEQ_PTR(_8439);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop do
L1B:
    if (_s == _stop)
        goto L1C;

    // 	    if SymTab[s][S_FILE_NO] = ns_file and 
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8439 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8439);
    _0 = _8439;
    _2 = (int)SEQ_PTR(_8439);
    _8439 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8439);
    DeRef(_0);
    _0 = _8439;
    if (IS_ATOM_INT(_8439)) {
        _8439 = (_8439 == _ns_file);
    }
    else {
        _8439 = binary_op(EQUALS, _8439, _ns_file);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8439)) {
        if (_8439 == 0) {
            DeRef(_8439);
            _8439 = 0;
            goto L1D;
        }
    }
    else {
        if (DBL_PTR(_8439)->dbl == 0.0) {
            DeRef(_8439);
            _8439 = 0;
            goto L1D;
        }
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _2 = (int)SEQ_PTR(_8426);
    _8426 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8426);
    DeRef(_0);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_8426 == 6);
    }
    else {
        _8426 = binary_op(EQUALS, _8426, 6);
    }
    DeRef(_0);
    DeRef(_8439);
    if (IS_ATOM_INT(_8426))
        _8439 = (_8426 != 0);
    else
        _8439 = DBL_PTR(_8426)->dbl != 0.0;
L1D:
    if (_8439 == 0) {
        goto L1E;
    }
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8439 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8439);
    _0 = _8439;
    _2 = (int)SEQ_PTR(_8439);
    _8439 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8439);
    DeRef(_0);
    _0 = _8439;
    if (_name == _8439)
        _8439 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8439))
        _8439 = 0;
    else
        _8439 = (compare(_name, _8439) == 0);
    DeRef(_0);
L1F:
    if (_8439 == 0)
        goto L1E;

    // 		return s
    DeRefDS(_name);
    DeRef(_8429);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return _s;
L1E:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8439 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8439);
    _2 = (int)SEQ_PTR(_8439);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while
    goto L1B;
L1C:

    // 	return 0
    DeRefDS(_name);
    DeRef(_8429);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return 0;
    goto L20;
L6:

    // 	if proc != TopLevelSub then  
    if (_proc == _7TopLevelSub)
        goto L21;

    // 	    s = SymTab[proc][S_NEXT]
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8439 = (int)*(((s1_ptr)_2)->base + _proc);
    Ref(_8439);
    _2 = (int)SEQ_PTR(_8439);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	    while s and (SymTab[s][S_SCOPE] = SC_PRIVATE or 
L22:
    if (_s == 0) {
        goto L23;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _2 = (int)SEQ_PTR(_8426);
    _8426 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8426);
    DeRef(_0);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_8426 == 3);
    }
    else {
        _8426 = binary_op(EQUALS, _8426, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8426)) {
        if (_8426 != 0) {
            DeRef(_8426);
            _8426 = 1;
            goto L24;
        }
    }
    else {
        if (DBL_PTR(_8426)->dbl != 0.0) {
            DeRef(_8426);
            _8426 = 1;
            goto L24;
        }
    }
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _0 = _8429;
    _2 = (int)SEQ_PTR(_8429);
    _8429 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8429);
    DeRef(_0);
    _0 = _8429;
    if (IS_ATOM_INT(_8429)) {
        _8429 = (_8429 == 2);
    }
    else {
        _8429 = binary_op(EQUALS, _8429, 2);
    }
    DeRef(_0);
    DeRef(_8426);
    if (IS_ATOM_INT(_8429))
        _8426 = (_8429 != 0);
    else
        _8426 = DBL_PTR(_8429)->dbl != 0.0;
L24:
L25:
    if (_8426 == 0)
        goto L23;

    // 		if equal(name, SymTab[s][S_NAME]) then
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _0 = _8429;
    _2 = (int)SEQ_PTR(_8429);
    _8429 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8429);
    DeRef(_0);
    _0 = _8429;
    if (_name == _8429)
        _8429 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8429))
        _8429 = 0;
    else
        _8429 = (compare(_name, _8429) == 0);
    DeRef(_0);
    if (_8429 == 0)
        goto L26;

    // 		    return s           
    DeRefDS(_name);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return _s;
L26:

    // 		s = SymTab[s][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	    end while
    goto L22;
L23:
L21:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop and length(SymTab[s]) >= S_NEXT do
L27:
    DeRef(_8429);
    _8429 = (_s != _stop);
    if (_8429 == 0) {
        goto L28;
    }
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _8426 = SEQ_PTR(_8426)->length;
    DeRef(_0);
    _8426 = (_8426 >= 2);
L29:
    if (_8426 == 0)
        goto L28;

    // 	    if SymTab[s][S_FILE_NO] = file and 
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8426 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8426);
    _0 = _8426;
    _2 = (int)SEQ_PTR(_8426);
    _8426 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8426);
    DeRef(_0);
    _0 = _8426;
    if (IS_ATOM_INT(_8426)) {
        _8426 = (_8426 == _file);
    }
    else {
        _8426 = binary_op(EQUALS, _8426, _file);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8426)) {
        if (_8426 == 0) {
            DeRef(_8426);
            _8426 = 0;
            goto L2A;
        }
    }
    else {
        if (DBL_PTR(_8426)->dbl == 0.0) {
            DeRef(_8426);
            _8426 = 0;
            goto L2A;
        }
    }
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _0 = _8429;
    _2 = (int)SEQ_PTR(_8429);
    _8429 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8429);
    DeRef(_0);
    _0 = _8429;
    if (IS_ATOM_INT(_8429)) {
        _8429 = (_8429 == 5);
    }
    else {
        _8429 = binary_op(EQUALS, _8429, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8429)) {
        if (_8429 != 0) {
            DeRef(_8429);
            _8429 = 1;
            goto L2B;
        }
    }
    else {
        if (DBL_PTR(_8429)->dbl != 0.0) {
            DeRef(_8429);
            _8429 = 1;
            goto L2B;
        }
    }
    DeRef(_8439);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8439 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8439);
    _0 = _8439;
    _2 = (int)SEQ_PTR(_8439);
    _8439 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8439);
    DeRef(_0);
    _0 = _8439;
    if (IS_ATOM_INT(_8439)) {
        _8439 = (_8439 == 6);
    }
    else {
        _8439 = binary_op(EQUALS, _8439, 6);
    }
    DeRef(_0);
    DeRef(_8429);
    if (IS_ATOM_INT(_8439))
        _8429 = (_8439 != 0);
    else
        _8429 = DBL_PTR(_8439)->dbl != 0.0;
L2B:
    if (_8429 != 0) {
        DeRef(_8439);
        _8439 = 1;
        goto L2C;
    }
    DeRef(_8429);
    _8429 = (_proc == _7TopLevelSub);
    if (_8429 == 0) {
        _8429 = 0;
        goto L2D;
    }
    DeRef(_8542);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8542 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8542);
    _0 = _8542;
    _2 = (int)SEQ_PTR(_8542);
    _8542 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8542);
    DeRef(_0);
    _0 = _8542;
    if (IS_ATOM_INT(_8542)) {
        _8542 = (_8542 == 4);
    }
    else {
        _8542 = binary_op(EQUALS, _8542, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8542))
        _8429 = (_8542 != 0);
    else
        _8429 = DBL_PTR(_8542)->dbl != 0.0;
L2D:
    DeRef(_8439);
    _8439 = (_8429 != 0);
L2C:
    DeRef(_8426);
    _8426 = (_8439 != 0);
L2A:
    if (_8426 == 0) {
        goto L2E;
    }
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _0 = _8429;
    _2 = (int)SEQ_PTR(_8429);
    _8429 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8429);
    DeRef(_0);
    _0 = _8429;
    if (_name == _8429)
        _8429 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8429))
        _8429 = 0;
    else
        _8429 = (compare(_name, _8429) == 0);
    DeRef(_0);
L2F:
    if (_8429 == 0)
        goto L2E;

    // 			return s
    DeRefDS(_name);
    DeRef(_8429);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return _s;
L2E:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while 
    goto L27;
L28:

    // 	global_found = FALSE
    _global_found = 0;

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop and length(SymTab[s]) >= S_NEXT do
L30:
    DeRef(_8429);
    _8429 = (_s != _stop);
    if (_8429 == 0) {
        goto L31;
    }
    DeRef(_8542);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8542 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8542);
    _0 = _8542;
    _8542 = SEQ_PTR(_8542)->length;
    DeRef(_0);
    _8542 = (_8542 >= 2);
L32:
    if (_8542 == 0)
        goto L31;

    // 	    if SymTab[s][S_SCOPE] = SC_GLOBAL and 
    DeRef(_8542);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8542 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8542);
    _0 = _8542;
    _2 = (int)SEQ_PTR(_8542);
    _8542 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8542);
    DeRef(_0);
    _0 = _8542;
    if (IS_ATOM_INT(_8542)) {
        _8542 = (_8542 == 6);
    }
    else {
        _8542 = binary_op(EQUALS, _8542, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8542)) {
        if (_8542 == 0) {
            goto L33;
        }
    }
    else {
        if (DBL_PTR(_8542)->dbl == 0.0) {
            goto L33;
        }
    }
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _0 = _8429;
    _2 = (int)SEQ_PTR(_8429);
    _8429 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8429);
    DeRef(_0);
    _0 = _8429;
    if (_name == _8429)
        _8429 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8429))
        _8429 = 0;
    else
        _8429 = (compare(_name, _8429) == 0);
    DeRef(_0);
L34:
    if (_8429 == 0)
        goto L33;

    // 		if not global_found then
    if (_global_found != 0)
        goto L35;

    // 		    global_found = s
    _global_found = _s;
    goto L36;
L35:

    // 		    return 0 -- 2nd global with same name
    DeRefDS(_name);
    DeRef(_8429);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return 0;
L36:
L33:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8429);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8429 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8429);
    _2 = (int)SEQ_PTR(_8429);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while 
    goto L30;
L31:

    // 	return global_found
    DeRefDS(_name);
    DeRef(_8429);
    DeRef(_8542);
    DeRef(_8439);
    DeRef(_8426);
    return _global_found;
L20:
    ;
}


int _17RTLookupVar(int _name, int _file, int _proc, int _stlen)
{
    int _s;
    int _global_found;
    int _colon;
    int _stop;
    int _p;
    int _ns;
    int _ns_file;
    int _8573 = 0;
    int _8683 = 0;
    int _8576 = 0;
    int _8568 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file)) {
        _1 = (long)(DBL_PTR(_file)->dbl);
        DeRefDS(_file);
        _file = _1;
    }
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }
    if (!IS_ATOM_INT(_stlen)) {
        _1 = (long)(DBL_PTR(_stlen)->dbl);
        DeRefDS(_stlen);
        _stlen = _1;
    }

    // 	if proc = 0 then
    if (_proc != 0)
        goto L1;

    // 	return 0
    DeRefDS(_name);
    return 0;
L1:

    // 	stop = 0
    _stop = 0;

    // 	colon = find(':', name)
    _colon = find(58, _name);

    // 	if colon then
    if (_colon == 0)
        goto L2;

    // 	p = colon-1
    _p = _colon - 1;

    // 	while p >= 1 and (name[p] = ' ' or name[p] = '\t') do
L3:
    DeRef(_8568);
    _8568 = (_p >= 1);
    if (_8568 == 0) {
        goto L4;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_name);
    _8573 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_8573);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == 32);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 != 0) {
            DeRef(_8573);
            _8573 = 1;
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl != 0.0) {
            DeRef(_8573);
            _8573 = 1;
            goto L5;
        }
    }
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_name);
    _8576 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_8576);
    _0 = _8576;
    if (IS_ATOM_INT(_8576)) {
        _8576 = (_8576 == 9);
    }
    else {
        _8576 = binary_op(EQUALS, _8576, 9);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8576))
        _8573 = (_8576 != 0);
    else
        _8573 = DBL_PTR(_8576)->dbl != 0.0;
L5:
L6:
    if (_8573 == 0)
        goto L4;

    // 	    p -= 1
    _p = _p - 1;

    // 	end while
    goto L3;
L4:

    // 	name = name[1..p] 
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, 1, _p);

    // 	ns = 1
    _ns = 1;

    // 	while ns <= length(name) and (name[ns] = ' ' or name[ns] = '\t') do
L7:
    DeRef(_8576);
    _8576 = SEQ_PTR(_name)->length;
    _8576 = (_ns <= _8576);
    if (_8576 == 0) {
        goto L8;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_name);
    _8573 = (int)*(((s1_ptr)_2)->base + _ns);
    Ref(_8573);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == 32);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 != 0) {
            DeRef(_8573);
            _8573 = 1;
            goto L9;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl != 0.0) {
            DeRef(_8573);
            _8573 = 1;
            goto L9;
        }
    }
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_name);
    _8568 = (int)*(((s1_ptr)_2)->base + _ns);
    Ref(_8568);
    _0 = _8568;
    if (IS_ATOM_INT(_8568)) {
        _8568 = (_8568 == 9);
    }
    else {
        _8568 = binary_op(EQUALS, _8568, 9);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8568))
        _8573 = (_8568 != 0);
    else
        _8573 = DBL_PTR(_8568)->dbl != 0.0;
L9:
LA:
    if (_8573 == 0)
        goto L8;

    // 	    ns += 1
    _ns = _ns + 1;

    // 	end while
    goto L7;
L8:

    // 	if ns > length(name) then
    DeRef(_8568);
    _8568 = SEQ_PTR(_name)->length;
    if (_ns <= _8568)
        goto LB;

    // 	    return 0
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    return 0;
LB:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8568);
    _2 = (int)SEQ_PTR(_8568);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop and length( SymTab[s] ) >= S_NEXT do
LC:
    DeRef(_8568);
    _8568 = (_s != 0);
    if (_8568 == 0) {
        goto LD;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _8573 = SEQ_PTR(_8573)->length;
    DeRef(_0);
    _8573 = (_8573 >= 2);
LE:
    if (_8573 == 0)
        goto LD;

    // 	    if file = SymTab[s][S_FILE_NO] and 
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_file == _8573);
    }
    else {
        _8573 = binary_op(EQUALS, _file, _8573);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 == 0) {
            DeRef(_8573);
            _8573 = 0;
            goto LF;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl == 0.0) {
            DeRef(_8573);
            _8573 = 0;
            goto LF;
        }
    }
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8568);
    _0 = _8568;
    _2 = (int)SEQ_PTR(_8568);
    _8568 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_8568);
    DeRef(_0);
    _0 = _8568;
    if (IS_ATOM_INT(_8568)) {
        _8568 = (_8568 == 523);
    }
    else {
        _8568 = binary_op(EQUALS, _8568, 523);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8568))
        _8573 = (_8568 != 0);
    else
        _8573 = DBL_PTR(_8568)->dbl != 0.0;
LF:
    if (_8573 == 0) {
        goto L10;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (_ns == _8573)
        _8573 = 1;
    else if (IS_ATOM_INT(_ns) && IS_ATOM_INT(_8573))
        _8573 = 0;
    else
        _8573 = (compare(_ns, _8573) == 0);
    DeRef(_0);
L11:
    if (_8573 == 0)
        goto L10;

    // 		exit
    goto LD;
L10:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _2 = (int)SEQ_PTR(_8573);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while
    goto LC;
LD:

    // 	if s = 0 then
    if (_s != 0)
        goto L12;

    // 	    return 0
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    DeRef(_8568);
    return 0;
L12:

    // 	ns_file = SymTab[s][S_OBJ]
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _2 = (int)SEQ_PTR(_8573);
    _ns_file = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_ns_file))
        _ns_file = (long)DBL_PTR(_ns_file)->dbl;

    // 	name = name[colon+1..$]
    DeRef(_8573);
    _8573 = _colon + 1;
    DeRef(_8568);
    _8568 = SEQ_PTR(_name)->length;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, _8573, _8568);

    // 	while length(name) and (name[1] = ' ' or name[1] = '\t') do
L13:
    DeRef(_8568);
    _8568 = SEQ_PTR(_name)->length;
    if (_8568 == 0) {
        goto L14;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_name);
    _8573 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8573);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == 32);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 != 0) {
            DeRef(_8573);
            _8573 = 1;
            goto L15;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl != 0.0) {
            DeRef(_8573);
            _8573 = 1;
            goto L15;
        }
    }
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_name);
    _8576 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8576);
    _0 = _8576;
    if (IS_ATOM_INT(_8576)) {
        _8576 = (_8576 == 9);
    }
    else {
        _8576 = binary_op(EQUALS, _8576, 9);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8576))
        _8573 = (_8576 != 0);
    else
        _8573 = DBL_PTR(_8576)->dbl != 0.0;
L15:
L16:
    if (_8573 == 0)
        goto L14;

    // 	    name = name[2..$]
    DeRef(_8576);
    _8576 = SEQ_PTR(_name)->length;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, 2, _8576);

    // 	end while
    goto L13;
L14:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8576 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8576);
    _2 = (int)SEQ_PTR(_8576);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop do
L17:
    if (_s == 0)
        goto L18;

    // 	    if SymTab[s][S_FILE_NO] = ns_file and 
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8576 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8576);
    _0 = _8576;
    _2 = (int)SEQ_PTR(_8576);
    _8576 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8576);
    DeRef(_0);
    _0 = _8576;
    if (IS_ATOM_INT(_8576)) {
        _8576 = (_8576 == _ns_file);
    }
    else {
        _8576 = binary_op(EQUALS, _8576, _ns_file);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8576)) {
        if (_8576 == 0) {
            DeRef(_8576);
            _8576 = 0;
            goto L19;
        }
    }
    else {
        if (DBL_PTR(_8576)->dbl == 0.0) {
            DeRef(_8576);
            _8576 = 0;
            goto L19;
        }
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == 6);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, 6);
    }
    DeRef(_0);
    DeRef(_8576);
    if (IS_ATOM_INT(_8573))
        _8576 = (_8573 != 0);
    else
        _8576 = DBL_PTR(_8573)->dbl != 0.0;
L19:
    if (_8576 == 0) {
        goto L1A;
    }
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8576 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8576);
    _0 = _8576;
    _2 = (int)SEQ_PTR(_8576);
    _8576 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8576);
    DeRef(_0);
    _0 = _8576;
    if (_name == _8576)
        _8576 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8576))
        _8576 = 0;
    else
        _8576 = (compare(_name, _8576) == 0);
    DeRef(_0);
L1B:
    if (_8576 == 0)
        goto L1A;

    // 		return s
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    DeRef(_8568);
    return _s;
L1A:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8576 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8576);
    _2 = (int)SEQ_PTR(_8576);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while
    goto L17;
L18:

    // 	return 0
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    DeRef(_8568);
    return 0;
    goto L1C;
L2:

    // 	if proc != TopLevelSub then  
    if (_proc == _7TopLevelSub)
        goto L1D;

    // 	    s = SymTab[proc][S_NEXT]
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8576 = (int)*(((s1_ptr)_2)->base + _proc);
    Ref(_8576);
    _2 = (int)SEQ_PTR(_8576);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	    while s and (SymTab[s][S_SCOPE] = SC_PRIVATE or 
L1E:
    if (_s == 0) {
        goto L1F;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == 3);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 != 0) {
            DeRef(_8573);
            _8573 = 1;
            goto L20;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl != 0.0) {
            DeRef(_8573);
            _8573 = 1;
            goto L20;
        }
    }
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8568);
    _0 = _8568;
    _2 = (int)SEQ_PTR(_8568);
    _8568 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8568);
    DeRef(_0);
    _0 = _8568;
    if (IS_ATOM_INT(_8568)) {
        _8568 = (_8568 == 2);
    }
    else {
        _8568 = binary_op(EQUALS, _8568, 2);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8568))
        _8573 = (_8568 != 0);
    else
        _8573 = DBL_PTR(_8568)->dbl != 0.0;
L20:
L21:
    if (_8573 == 0)
        goto L1F;

    // 		if equal(name, SymTab[s][S_NAME]) then
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8568);
    _0 = _8568;
    _2 = (int)SEQ_PTR(_8568);
    _8568 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8568);
    DeRef(_0);
    _0 = _8568;
    if (_name == _8568)
        _8568 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8568))
        _8568 = 0;
    else
        _8568 = (compare(_name, _8568) == 0);
    DeRef(_0);
    if (_8568 == 0)
        goto L22;

    // 		    return s           
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    return _s;
L22:

    // 		s = SymTab[s][S_NEXT]
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8568);
    _2 = (int)SEQ_PTR(_8568);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	    end while
    goto L1E;
L1F:
L1D:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8568);
    _2 = (int)SEQ_PTR(_8568);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop and length(SymTab[s]) >= S_NEXT do
L23:
    DeRef(_8568);
    _8568 = (_s != 0);
    if (_8568 == 0) {
        goto L24;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _8573 = SEQ_PTR(_8573)->length;
    DeRef(_0);
    _8573 = (_8573 >= 2);
L25:
    if (_8573 == 0)
        goto L24;

    // 	    if (SymTab[s][S_FILE_NO] = file or SymTab[s][S_FILE_NO] = eval_file) and 
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == _file);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, _file);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 != 0) {
            DeRef(_8573);
            _8573 = 1;
            goto L26;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl != 0.0) {
            DeRef(_8573);
            _8573 = 1;
            goto L26;
        }
    }
    DeRef(_8568);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8568 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8568);
    _0 = _8568;
    _2 = (int)SEQ_PTR(_8568);
    _8568 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_8568);
    DeRef(_0);
    _0 = _8568;
    if (IS_ATOM_INT(_8568)) {
        _8568 = (_8568 == _7eval_file);
    }
    else {
        _8568 = binary_op(EQUALS, _8568, _7eval_file);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8568))
        _8573 = (_8568 != 0);
    else
        _8573 = DBL_PTR(_8568)->dbl != 0.0;
L26:
    if (_8573 == 0) {
        DeRef(_8568);
        _8568 = 0;
        goto L27;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (IS_ATOM_INT(_8573)) {
        _8573 = (_8573 == 5);
    }
    else {
        _8573 = binary_op(EQUALS, _8573, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8573)) {
        if (_8573 != 0) {
            DeRef(_8573);
            _8573 = 1;
            goto L28;
        }
    }
    else {
        if (DBL_PTR(_8573)->dbl != 0.0) {
            DeRef(_8573);
            _8573 = 1;
            goto L28;
        }
    }
    DeRef(_8576);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8576 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8576);
    _0 = _8576;
    _2 = (int)SEQ_PTR(_8576);
    _8576 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8576);
    DeRef(_0);
    _0 = _8576;
    if (IS_ATOM_INT(_8576)) {
        _8576 = (_8576 == 6);
    }
    else {
        _8576 = binary_op(EQUALS, _8576, 6);
    }
    DeRef(_0);
    DeRef(_8573);
    if (IS_ATOM_INT(_8576))
        _8573 = (_8576 != 0);
    else
        _8573 = DBL_PTR(_8576)->dbl != 0.0;
L28:
    if (_8573 != 0) {
        DeRef(_8576);
        _8576 = 1;
        goto L29;
    }
    DeRef(_8573);
    _8573 = (_proc == _7TopLevelSub);
    if (_8573 == 0) {
        _8573 = 0;
        goto L2A;
    }
    DeRef(_8683);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8683 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8683);
    _0 = _8683;
    _2 = (int)SEQ_PTR(_8683);
    _8683 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8683);
    DeRef(_0);
    _0 = _8683;
    if (IS_ATOM_INT(_8683)) {
        _8683 = (_8683 == 4);
    }
    else {
        _8683 = binary_op(EQUALS, _8683, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8683))
        _8573 = (_8683 != 0);
    else
        _8573 = DBL_PTR(_8683)->dbl != 0.0;
L2A:
    DeRef(_8576);
    _8576 = (_8573 != 0);
L29:
    DeRef(_8568);
    _8568 = (_8576 != 0);
L27:
    if (_8568 == 0) {
        goto L2B;
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (_name == _8573)
        _8573 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8573))
        _8573 = 0;
    else
        _8573 = (compare(_name, _8573) == 0);
    DeRef(_0);
L2C:
    if (_8573 == 0)
        goto L2B;

    // 			return s
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    DeRef(_8568);
    return _s;
L2B:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _2 = (int)SEQ_PTR(_8573);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while 
    goto L23;
L24:

    // 	global_found = FALSE
    _global_found = 0;

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_8573);
    _2 = (int)SEQ_PTR(_8573);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != stop and length(SymTab[s]) >= S_NEXT do
L2D:
    DeRef(_8573);
    _8573 = (_s != 0);
    if (_8573 == 0) {
        goto L2E;
    }
    DeRef(_8683);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8683 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8683);
    _0 = _8683;
    _8683 = SEQ_PTR(_8683)->length;
    DeRef(_0);
    _8683 = (_8683 >= 2);
L2F:
    if (_8683 == 0)
        goto L2E;

    // 	    if SymTab[s][S_SCOPE] = SC_GLOBAL and 
    DeRef(_8683);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8683 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8683);
    _0 = _8683;
    _2 = (int)SEQ_PTR(_8683);
    _8683 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8683);
    DeRef(_0);
    _0 = _8683;
    if (IS_ATOM_INT(_8683)) {
        _8683 = (_8683 == 6);
    }
    else {
        _8683 = binary_op(EQUALS, _8683, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8683)) {
        if (_8683 == 0) {
            goto L30;
        }
    }
    else {
        if (DBL_PTR(_8683)->dbl == 0.0) {
            goto L30;
        }
    }
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _0 = _8573;
    _2 = (int)SEQ_PTR(_8573);
    _8573 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8573);
    DeRef(_0);
    _0 = _8573;
    if (_name == _8573)
        _8573 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_8573))
        _8573 = 0;
    else
        _8573 = (compare(_name, _8573) == 0);
    DeRef(_0);
L31:
    if (_8573 == 0)
        goto L30;

    // 		if not global_found then
    if (_global_found != 0)
        goto L32;

    // 		    global_found = s
    _global_found = _s;
    goto L33;
L32:

    // 		    return 0 -- 2nd global with same name
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    DeRef(_8568);
    return 0;
L33:
L30:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_8573);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8573 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_8573);
    _2 = (int)SEQ_PTR(_8573);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while 
    goto L2D;
L2E:

    // 	return global_found
    DeRefDS(_name);
    DeRef(_8573);
    DeRef(_8683);
    DeRef(_8576);
    DeRef(_8568);
    return _global_found;
L1C:
    ;
}


int _17opCALL_PROC()
{
    int _cf;
    int _top;
    int _n;
    int _arg;
    int _sub;
    int _by_ref = 0;
    int _arg_ref = 0;
    int _8718 = 0;
    int _8717 = 0;
    int _8709 = 0;
    int _0, _1, _2, _3;
    

    // 	cf = Code[pc] = CALL_FUNC
    _2 = (int)SEQ_PTR(_7Code);
    _8709 = (int)*(((s1_ptr)_2)->base + _17pc);
    Ref(_8709);
    if (IS_ATOM_INT(_8709)) {
        _cf = (_8709 == 139);
    }
    else {
        _cf = binary_op(EQUALS, _8709, 139);
    }
    if (!IS_ATOM_INT(_cf)) {
        _1 = (long)(DBL_PTR(_cf)->dbl);
        DeRefDS(_cf);
        _cf = _1;
    }

    // 	top = length(call_stack)
    _top = SEQ_PTR(_17call_stack)->length;

    // 	a = Code[pc+1]	-- routine id
    DeRef(_8709);
    _8709 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _8709);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	if val[a] < 0 or val[a] >= length(e_routine) then
    _2 = (int)SEQ_PTR(_17val);
    _8709 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8709);
    _0 = _8709;
    if (IS_ATOM_INT(_8709)) {
        _8709 = (_8709 < 0);
    }
    else {
        _8709 = binary_op(LESS, _8709, 0);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8709)) {
        if (_8709 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8709)->dbl != 0.0) {
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_17val);
    _8717 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8717);
    _8718 = SEQ_PTR(_17e_routine)->length;
    if (IS_ATOM_INT(_8717)) {
        _8718 = (_8717 >= _8718);
    }
    else {
        _8718 = binary_op(GREATEREQ, _8717, _8718);
    }
L2:
    if (_8718 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8718) && DBL_PTR(_8718)->dbl == 0.0)
            goto L3;
    }
L1:

    // 		RTFatal("invalid routine id")
    RefDS(_8720);
    _17RTFatal(_8720);

    // 		return
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRef(_8718);
    DeRef(_8717);
    DeRef(_8709);
    return 0;
L3:

    // 	sub = e_routine[val[a]+1]
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_17val);
    _8718 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_8718);
    _0 = _8718;
    if (IS_ATOM_INT(_8718)) {
        _8718 = _8718 + 1;
    }
    else
        _8718 = binary_op(PLUS, 1, _8718);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17e_routine);
    if (!IS_ATOM_INT(_8718))
        _sub = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8718)->dbl));
    else
        _sub = (int)*(((s1_ptr)_2)->base + _8718);

    // 	b = Code[pc+2]	-- argument list
    DeRef(_8718);
    _8718 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _8718);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	if cf then
    if (_cf == 0)
        goto L4;

    // 		if SymTab[sub][S_TOKEN] = r:PROC then
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    _0 = _8718;
    _2 = (int)SEQ_PTR(_8718);
    _8718 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_8718);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _8718, 27))
        goto L5;

    // 		    RTFatal(sprintf("%s() does not return a value", SymTab[sub][S_NAME]))
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    _0 = _8718;
    _2 = (int)SEQ_PTR(_8718);
    _8718 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8718);
    DeRef(_0);
    _0 = _8718;
    _8718 = EPrintf(-9999999, _8729, _8718);
    DeRef(_0);
    RefDS(_8718);
    _17RTFatal(_8718);

    // 		    return
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRefDSi(_8718);
    DeRef(_8717);
    DeRef(_8709);
    return 0;
L6:
    goto L5;
L4:

    // 		if SymTab[sub][S_TOKEN] != r:PROC then
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    _0 = _8718;
    _2 = (int)SEQ_PTR(_8718);
    _8718 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_8718);
    DeRef(_0);
    if (binary_op_a(EQUALS, _8718, 27))
        goto L7;

    // 		    RTFatal(sprintf("the value returned by %s() must be assigned or used",
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    _0 = _8718;
    _2 = (int)SEQ_PTR(_8718);
    _8718 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8718);
    DeRef(_0);
    _0 = _8718;
    _8718 = EPrintf(-9999999, _8736, _8718);
    DeRef(_0);
    RefDS(_8718);
    _17RTFatal(_8718);

    // 			return
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRefDSi(_8718);
    DeRef(_8717);
    DeRef(_8709);
    return 0;
L7:
L5:

    // 	if atom(val[b]) then
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_17val);
    _8718 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8718);
    _0 = _8718;
    _8718 = IS_ATOM(_8718);
    DeRef(_0);
    if (_8718 == 0)
        goto L8;

    // 		RTFatal("argument list must be a sequence")
    RefDS(_8742);
    _17RTFatal(_8742);

    // 		return
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRef(_8717);
    DeRef(_8709);
    return 0;
L8:

    // 	if SymTab[sub][S_NUM_ARGS] != length(val[b]) then
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    _0 = _8718;
    _2 = (int)SEQ_PTR(_8718);
    _8718 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_8718);
    DeRef(_0);
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_17val);
    _8717 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8717);
    _0 = _8717;
    _8717 = SEQ_PTR(_8717)->length;
    DeRef(_0);
    if (binary_op_a(EQUALS, _8718, _8717))
        goto L9;

    // 		RTFatal(sprintf("call to %s() via routine-id should pass %d arguments, not %d",
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8717);
    _0 = _8717;
    _2 = (int)SEQ_PTR(_8717);
    _8717 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_8717);
    DeRef(_0);
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    _0 = _8718;
    _2 = (int)SEQ_PTR(_8718);
    _8718 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_8718);
    DeRef(_0);
    DeRef(_8709);
    _2 = (int)SEQ_PTR(_17val);
    _8709 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_8709);
    _0 = _8709;
    _8709 = SEQ_PTR(_8709)->length;
    DeRef(_0);
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_8717);
    *((int *)(_2+4)) = _8717;
    Ref(_8718);
    *((int *)(_2+8)) = _8718;
    *((int *)(_2+12)) = _8709;
    _8709 = MAKE_SEQ(_1);
    _0 = _8709;
    _8709 = EPrintf(-9999999, _8748, _8709);
    DeRefDS(_0);
    RefDS(_8709);
    _17RTFatal(_8709);

    // 		 return
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRefDSi(_8709);
    DeRef(_8718);
    DeRef(_8717);
    return 0;
L9:

    // 	by_ref = {}
    RefDS(_39);
    DeRef(_by_ref);
    _by_ref = _39;

    // 	n = SymTab[sub][S_NUM_ARGS]
    DeRef(_8709);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8709 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8709);
    _2 = (int)SEQ_PTR(_8709);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 	arg = SymTab[sub][S_NEXT]
    DeRef(_8709);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8709 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8709);
    _2 = (int)SEQ_PTR(_8709);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	SymTab[sub][S_ACTIVE] += 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRef(_8717);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _8717 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_8717);
    _0 = _8717;
    if (IS_ATOM_INT(_8717)) {
        _8717 = _8717 + 1;
        if (_8717 > MAXINT)
            _8717 = NewDouble((double)_8717);
    }
    else
        _8717 = binary_op(PLUS, 1, _8717);
    DeRef(_0);
    Ref(_8717);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _8717;
    DeRef(_1);

    // 	if SymTab[sub][S_ACTIVE] > 1 then
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8717);
    _0 = _8717;
    _2 = (int)SEQ_PTR(_8717);
    _8717 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_8717);
    DeRef(_0);
    if (binary_op_a(LESSEQ, _8717, 1))
        goto LA;

    // 		for i = 1 to n do
    DeRef(_8717);
    _8717 = _n;
    { int _i;
        _i = 1;
LB:
        if (_i > _8717)
            goto LC;

        // 		    call_stack = append(call_stack, val[arg])
        DeRef(_8718);
        _2 = (int)SEQ_PTR(_17val);
        _8718 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_8718);
        Ref(_8718);
        Append(&_17call_stack, _17call_stack, _8718);

        // 		    val[arg] = val[b][i]
        DeRef(_8718);
        _2 = (int)SEQ_PTR(_17val);
        _8718 = (int)*(((s1_ptr)_2)->base + _17b);
        Ref(_8718);
        _0 = _8718;
        _2 = (int)SEQ_PTR(_8718);
        _8718 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8718);
        DeRef(_0);
        Ref(_8718);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _8718;
        DeRef(_1);

        // 		    arg = SymTab[arg][S_NEXT]
        DeRef(_8718);
        _2 = (int)SEQ_PTR(_7SymTab);
        _8718 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_8718);
        _2 = (int)SEQ_PTR(_8718);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 		end for
        _i = _i + 1;
        goto LB;
LC:
        ;
    }

    // 		while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
LD:
    DeRef(_8718);
    _8718 = (_arg != 0);
    if (_8718 == 0) {
        goto LE;
    }
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_8717);
    _0 = _8717;
    _2 = (int)SEQ_PTR(_8717);
    _8717 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8717);
    DeRef(_0);
    _0 = _8717;
    if (IS_ATOM_INT(_8717)) {
        _8717 = (_8717 <= 3);
    }
    else {
        _8717 = binary_op(LESSEQ, _8717, 3);
    }
    DeRef(_0);
LF:
    if (_8717 <= 0) {
        if (_8717 == 0) {
            goto LE;
        }
        else {
            if (!IS_ATOM_INT(_8717) && DBL_PTR(_8717)->dbl == 0.0)
                goto LE;
        }
    }

    // 		    call_stack = append(call_stack, val[arg])
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_17val);
    _8717 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_8717);
    Ref(_8717);
    Append(&_17call_stack, _17call_stack, _8717);

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
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_8717);
    _2 = (int)SEQ_PTR(_8717);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto LD;
LE:

    // 		arg = SymTab[sub][S_TEMPS]
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8717);
    _2 = (int)SEQ_PTR(_8717);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		while arg != 0 do
L10:
    if (_arg == 0)
        goto L11;

    // 		    call_stack = append(call_stack, val[arg])
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_17val);
    _8717 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_8717);
    Ref(_8717);
    Append(&_17call_stack, _17call_stack, _8717);

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
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_8717);
    _2 = (int)SEQ_PTR(_8717);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto L10;
L11:

    // 		call_stack = append( call_stack, SymTab[sub][S_GOTO][G_DEFAULT] )
    DeRef(_8717);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8717 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8717);
    _0 = _8717;
    _2 = (int)SEQ_PTR(_8717);
    _8717 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_8717);
    DeRef(_0);
    _0 = _8717;
    _2 = (int)SEQ_PTR(_8717);
    _8717 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_8717);
    DeRef(_0);
    Ref(_8717);
    Append(&_17call_stack, _17call_stack, _8717);
    goto L12;
LA:

    // 		for i = 1 to n do
    DeRef(_8717);
    _8717 = _n;
    { int _i;
        _i = 1;
L13:
        if (_i > _8717)
            goto L14;

        // 		    val[arg] = val[b][i]
        DeRef(_8718);
        _2 = (int)SEQ_PTR(_17val);
        _8718 = (int)*(((s1_ptr)_2)->base + _17b);
        Ref(_8718);
        _0 = _8718;
        _2 = (int)SEQ_PTR(_8718);
        _8718 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8718);
        DeRef(_0);
        Ref(_8718);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _8718;
        DeRef(_1);

        // 		    arg = SymTab[arg][S_NEXT]
        DeRef(_8718);
        _2 = (int)SEQ_PTR(_7SymTab);
        _8718 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_8718);
        _2 = (int)SEQ_PTR(_8718);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 		end for
        _i = _i + 1;
        goto L13;
L14:
        ;
    }
L12:

    // 	call_stack = append( call_stack, by_ref )
    RefDS(_by_ref);
    Append(&_17call_stack, _17call_stack, _by_ref);

    // 	call_stack = append(call_stack, top)	
    Append(&_17call_stack, _17call_stack, _top);

    // 	pc += 3 + cf
    DeRef(_8718);
    _8718 = 3 + _cf;
    if ((long)((unsigned long)_8718 + (unsigned long)HIGH_BITS) >= 0) 
        _8718 = NewDouble((double)_8718);
    if (IS_ATOM_INT(_8718)) {
        _17pc = _17pc + _8718;
    }
    else {
        _17pc = NewDouble((double)_17pc + DBL_PTR(_8718)->dbl);
    }
    if (!IS_ATOM_INT(_17pc)) {
        _1 = (long)(DBL_PTR(_17pc)->dbl);
        DeRefDS(_17pc);
        _17pc = _1;
    }

    // 	call_stack = append(call_stack, pc) 
    Append(&_17call_stack, _17call_stack, _17pc);

    // 	call_stack = append(call_stack, sub)
    Append(&_17call_stack, _17call_stack, _sub);

    // 	Code = SymTab[sub][S_CODE]
    DeRef(_8718);
    _2 = (int)SEQ_PTR(_7SymTab);
    _8718 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_8718);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_8718);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	pc = 1
    _17pc = 1;

    // end procedure
    DeRefDS(_by_ref);
    DeRef(_arg_ref);
    DeRef(_8718);
    DeRef(_8717);
    DeRef(_8709);
    return 0;
    ;
}


