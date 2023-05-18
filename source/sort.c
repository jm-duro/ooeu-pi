// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _14sort(int _x)
{
    int _gap;
    int _j;
    int _first;
    int _last;
    int _tempi = 0;
    int _tempj = 0;
    int _1905 = 0;
    int _1900;
    int _0, _1, _2;
    

    //     last = length(x)
    _last = SEQ_PTR(_x)->length;

    //     gap = floor(last / 10) + 1
    if (10 > 0 && _last >= 0) {
        _1900 = _last / 10;
    }
    else {
        temp_dbl = floor((double)_last / (double)10);
        _1900 = (long)temp_dbl;
    }
    _gap = _1900 + 1;

    //     while 1 do
L1:

    // 	first = gap + 1
    _first = _gap + 1;

    // 	for i = first to last do
    _1900 = _last;
    { int _i;
        _i = _first;
L2:
        if (_i > _1900)
            goto L3;

        // 	    tempi = x[i]
        DeRef(_tempi);
        _2 = (int)SEQ_PTR(_x);
        _tempi = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_tempi);

        // 	    j = i - gap
        _j = _i - _gap;

        // 	    while 1 do
L4:

        // 		tempj = x[j]
        DeRef(_tempj);
        _2 = (int)SEQ_PTR(_x);
        _tempj = (int)*(((s1_ptr)_2)->base + _j);
        Ref(_tempj);

        // 		if compare(tempi, tempj) >= 0 then
        DeRef(_1905);
        if (IS_ATOM_INT(_tempi) && IS_ATOM_INT(_tempj))
            _1905 = (_tempi < _tempj) ? -1 : (_tempi > _tempj);
        else
            _1905 = compare(_tempi, _tempj);
        if (_1905 < 0)
            goto L5;

        // 		    j += gap
        _j = _j + _gap;

        // 		    exit
        goto L6;
L5:

        // 		x[j+gap] = tempj
        DeRef(_1905);
        _1905 = _j + _gap;
        Ref(_tempj);
        _2 = (int)SEQ_PTR(_x);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _x = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _1905);
        _1 = *(int *)_2;
        *(int *)_2 = _tempj;
        DeRef(_1);

        // 		if j <= gap then
        if (_j > _gap)
            goto L7;

        // 		    exit
        goto L6;
L7:

        // 		j -= gap
        _j = _j - _gap;

        // 	    end while
        goto L4;
L6:

        // 	    x[j] = tempi
        Ref(_tempi);
        _2 = (int)SEQ_PTR(_x);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _x = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _j);
        _1 = *(int *)_2;
        *(int *)_2 = _tempi;
        DeRef(_1);

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	if gap = 1 then
    if (_gap != 1)
        goto L8;

    // 	    return x
    DeRef(_tempi);
    DeRef(_tempj);
    DeRef(_1905);
    return _x;
    goto L1;
L8:

    // 	    gap = floor(gap / 3.5) + 1
    DeRef(_1905);
    _2 = binary_op(DIVIDE, _gap, _1915);
    _1905 = unary_op(FLOOR, _2);
    DeRef(_2);
    if (IS_ATOM_INT(_1905)) {
        _gap = _1905 + 1;
    }
    else
        _gap = 1+(long)(DBL_PTR(_1905)->dbl);
L9:

    //     end while
    goto L1;
LA:
    ;
}


int _14custom_sort(int _custom_compare, int _x)
{
    int _gap;
    int _j;
    int _first;
    int _last;
    int _tempi = 0;
    int _tempj = 0;
    int _1923 = 0;
    int _1918;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_custom_compare)) {
        _1 = (long)(DBL_PTR(_custom_compare)->dbl);
        DeRefDS(_custom_compare);
        _custom_compare = _1;
    }

    //     last = length(x)
    _last = SEQ_PTR(_x)->length;

    //     gap = floor(last / 10) + 1
    if (10 > 0 && _last >= 0) {
        _1918 = _last / 10;
    }
    else {
        temp_dbl = floor((double)_last / (double)10);
        _1918 = (long)temp_dbl;
    }
    _gap = _1918 + 1;

    //     while 1 do
L1:

    // 	first = gap + 1
    _first = _gap + 1;

    // 	for i = first to last do
    _1918 = _last;
    { int _i;
        _i = _first;
L2:
        if (_i > _1918)
            goto L3;

        // 	    tempi = x[i]
        DeRef(_tempi);
        _2 = (int)SEQ_PTR(_x);
        _tempi = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_tempi);

        // 	    j = i - gap
        _j = _i - _gap;

        // 	    while 1 do
L4:

        // 		tempj = x[j]
        DeRef(_tempj);
        _2 = (int)SEQ_PTR(_x);
        _tempj = (int)*(((s1_ptr)_2)->base + _j);
        Ref(_tempj);

        // 		if call_func(custom_compare, {tempi, tempj}) >= 0 then
        DeRef(_1923);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _tempi;
        Ref(_tempi);
        ((int *)_2)[2] = _tempj;
        Ref(_tempj);
        _1923 = MAKE_SEQ(_1);
        _1 = (int)SEQ_PTR(_1923);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_custom_compare].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRefDS(_1923);
        _1923 = _1;
        if (binary_op_a(LESS, _1923, 0))
            goto L5;

        // 		    j += gap
        _j = _j + _gap;

        // 		    exit
        goto L6;
L5:

        // 		x[j+gap] = tempj
        DeRef(_1923);
        _1923 = _j + _gap;
        Ref(_tempj);
        _2 = (int)SEQ_PTR(_x);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _x = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _1923);
        _1 = *(int *)_2;
        *(int *)_2 = _tempj;
        DeRef(_1);

        // 		if j <= gap then
        if (_j > _gap)
            goto L7;

        // 		    exit
        goto L6;
L7:

        // 		j -= gap
        _j = _j - _gap;

        // 	    end while
        goto L4;
L6:

        // 	    x[j] = tempi
        Ref(_tempi);
        _2 = (int)SEQ_PTR(_x);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _x = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _j);
        _1 = *(int *)_2;
        *(int *)_2 = _tempi;
        DeRef(_1);

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	if gap = 1 then
    if (_gap != 1)
        goto L8;

    // 	    return x
    DeRef(_tempi);
    DeRef(_tempj);
    DeRef(_1923);
    return _x;
    goto L1;
L8:

    // 	    gap = floor(gap / 3.5) + 1
    DeRef(_1923);
    _2 = binary_op(DIVIDE, _gap, _1915);
    _1923 = unary_op(FLOOR, _2);
    DeRef(_2);
    if (IS_ATOM_INT(_1923)) {
        _gap = _1923 + 1;
    }
    else
        _gap = 1+(long)(DBL_PTR(_1923)->dbl);
L9:

    //     end while
    goto L1;
LA:
    ;
}


