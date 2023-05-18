// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _3lower(int _x)
{
    int _182 = 0;
    int _180 = 0;
    int _0, _1, _2;
    

    //     return x + (x >= 'A' and x <= 'Z') * TO_LOWER
    if (IS_ATOM_INT(_x)) {
        _180 = (_x >= 65);
    }
    else {
        _180 = binary_op(GREATEREQ, _x, 65);
    }
    if (IS_ATOM_INT(_x)) {
        _182 = (_x <= 90);
    }
    else {
        _182 = binary_op(LESSEQ, _x, 90);
    }
    _0 = _182;
    if (IS_ATOM_INT(_180) && IS_ATOM_INT(_182)) {
        _182 = (_180 != 0 && _182 != 0);
    }
    else {
        _182 = binary_op(AND, _180, _182);
    }
    DeRef(_0);
    _0 = _182;
    if (IS_ATOM_INT(_182)) {
        if (_182 == (short)_182)
            _182 = _182 * 32;
        else
            _182 = NewDouble(_182 * (double)32);
    }
    else {
        _182 = binary_op(MULTIPLY, _182, 32);
    }
    DeRef(_0);
    _0 = _182;
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_182)) {
        _182 = _x + _182;
        if ((long)((unsigned long)_182 + (unsigned long)HIGH_BITS) >= 0) 
            _182 = NewDouble((double)_182);
    }
    else {
        _182 = binary_op(PLUS, _x, _182);
    }
    DeRef(_0);
    DeRef(_x);
    DeRef(_180);
    return _182;
    ;
}


int _3upper(int _x)
{
    int _188 = 0;
    int _186 = 0;
    int _0, _1, _2;
    

    //     return x - (x >= 'a' and x <= 'z') * TO_LOWER
    if (IS_ATOM_INT(_x)) {
        _186 = (_x >= 97);
    }
    else {
        _186 = binary_op(GREATEREQ, _x, 97);
    }
    if (IS_ATOM_INT(_x)) {
        _188 = (_x <= 122);
    }
    else {
        _188 = binary_op(LESSEQ, _x, 122);
    }
    _0 = _188;
    if (IS_ATOM_INT(_186) && IS_ATOM_INT(_188)) {
        _188 = (_186 != 0 && _188 != 0);
    }
    else {
        _188 = binary_op(AND, _186, _188);
    }
    DeRef(_0);
    _0 = _188;
    if (IS_ATOM_INT(_188)) {
        if (_188 == (short)_188)
            _188 = _188 * 32;
        else
            _188 = NewDouble(_188 * (double)32);
    }
    else {
        _188 = binary_op(MULTIPLY, _188, 32);
    }
    DeRef(_0);
    _0 = _188;
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_188)) {
        _188 = _x - _188;
        if ((long)((unsigned long)_188 +(unsigned long) HIGH_BITS) >= 0)
            _188 = NewDouble((double)_188);
    }
    else {
        _188 = binary_op(MINUS, _x, _188);
    }
    DeRef(_0);
    DeRef(_x);
    DeRef(_186);
    return _188;
    ;
}


int _3qmatch(int _p, int _s)
{
    int _k;
    int _201 = 0;
    int _202 = 0;
    int _193;
    int _197;
    int _0, _1, _2;
    

    //     if not find('?', p) then
    _193 = find(63, _p);
    if (_193 != 0)
        goto L1;

    // 	return match(p, s) -- fast
    _193 = e_match(_p, _s);
    DeRefDS(_p);
    DeRefDS(_s);
    return _193;
L1:

    //     for i = 1 to length(s) - length(p) + 1 do
    _193 = SEQ_PTR(_s)->length;
    _197 = SEQ_PTR(_p)->length;
    _197 = _193 - _197;
    _197 = _197 + 1;
    { int _i;
        _i = 1;
L2:
        if (_i > _197)
            goto L3;

        // 	k = i
        _k = _i;

        // 	for j = 1 to length(p) do
        _193 = SEQ_PTR(_p)->length;
        { int _j;
            _j = 1;
L4:
            if (_j > _193)
                goto L5;

            // 	    if p[j] != s[k] and p[j] != '?' then
            DeRef(_201);
            _2 = (int)SEQ_PTR(_p);
            _201 = (int)*(((s1_ptr)_2)->base + _j);
            Ref(_201);
            DeRef(_202);
            _2 = (int)SEQ_PTR(_s);
            _202 = (int)*(((s1_ptr)_2)->base + _k);
            Ref(_202);
            _0 = _202;
            if (IS_ATOM_INT(_201) && IS_ATOM_INT(_202)) {
                _202 = (_201 != _202);
            }
            else {
                _202 = binary_op(NOTEQ, _201, _202);
            }
            DeRef(_0);
            if (IS_ATOM_INT(_202)) {
                if (_202 == 0) {
                    goto L6;
                }
            }
            else {
                if (DBL_PTR(_202)->dbl == 0.0) {
                    goto L6;
                }
            }
            DeRef(_201);
            _2 = (int)SEQ_PTR(_p);
            _201 = (int)*(((s1_ptr)_2)->base + _j);
            Ref(_201);
            _0 = _201;
            if (IS_ATOM_INT(_201)) {
                _201 = (_201 != 63);
            }
            else {
                _201 = binary_op(NOTEQ, _201, 63);
            }
            DeRef(_0);
L7:
            if (_201 == 0) {
                goto L6;
            }
            else {
                if (!IS_ATOM_INT(_201) && DBL_PTR(_201)->dbl == 0.0)
                    goto L6;
            }

            // 		k = 0
            _k = 0;

            // 		exit
            goto L5;
L6:

            // 	    k += 1
            _k = _k + 1;

            // 	end for
            _j = _j + 1;
            goto L4;
L5:
            ;
        }

        // 	if k != 0 then
        if (_k == 0)
            goto L8;

        // 	    return i
        DeRefDS(_p);
        DeRefDS(_s);
        DeRef(_201);
        DeRef(_202);
        return _i;
L8:

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     return 0
    DeRefDS(_p);
    DeRefDS(_s);
    DeRef(_201);
    DeRef(_202);
    return 0;
    ;
}


int _3wildcard_match(int _pattern, int _string)
{
    int _p;
    int _f;
    int _t;
    int _match_string = 0;
    int _214 = 0;
    int _209 = 0;
    int _0, _1, _2;
    

    //     pattern = pattern & END_MARKER
    Append(&_pattern, _pattern, -1);

    //     string = string & END_MARKER
    Append(&_string, _string, -1);

    //     p = 1
    _p = 1;

    //     f = 1
    _f = 1;

    //     while f <= length(string) do
L1:
    DeRef(_209);
    _209 = SEQ_PTR(_string)->length;
    if (_f > _209)
        goto L2;

    // 	if not find(pattern[p], {string[f], '?'}) then
    _2 = (int)SEQ_PTR(_pattern);
    _209 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_209);
    DeRef(_214);
    _2 = (int)SEQ_PTR(_string);
    _214 = (int)*(((s1_ptr)_2)->base + _f);
    Ref(_214);
    _0 = _214;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _214;
    Ref(_214);
    ((int *)_2)[2] = 63;
    _214 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _214;
    _214 = find(_209, _214);
    DeRefDS(_0);
    if (_214 != 0)
        goto L3;

    // 	    if pattern[p] = '*' then
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (binary_op_a(NOTEQ, _214, 42))
        goto L4;

    // 		while pattern[p] = '*' do
L5:
    DeRef(_214);
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (binary_op_a(NOTEQ, _214, 42))
        goto L6;

    // 		    p += 1
    _p = _p + 1;

    // 		end while
    goto L5;
L6:

    // 		if pattern[p] = END_MARKER then
    DeRef(_214);
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (binary_op_a(NOTEQ, _214, -1))
        goto L7;

    // 		    return 1
    DeRefDS(_pattern);
    DeRefDS(_string);
    DeRef(_match_string);
    DeRef(_214);
    DeRef(_209);
    return 1;
L7:

    // 		match_string = ""
    RefDS(_39);
    DeRef(_match_string);
    _match_string = _39;

    // 		while pattern[p] != '*' do
L8:
    DeRef(_214);
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (binary_op_a(EQUALS, _214, 42))
        goto L9;

    // 		    match_string = match_string & pattern[p]
    DeRef(_214);
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (IS_SEQUENCE(_match_string) && IS_ATOM(_214)) {
        Ref(_214);
        Append(&_match_string, _match_string, _214);
    }
    else if (IS_ATOM(_match_string) && IS_SEQUENCE(_214)) {
    }
    else {
        Concat((object_ptr)&_match_string, _match_string, (s1_ptr)_214);
    }

    // 		    if pattern[p] = END_MARKER then
    DeRef(_214);
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (binary_op_a(NOTEQ, _214, -1))
        goto LA;

    // 			exit
    goto L9;
LA:

    // 		    p += 1
    _p = _p + 1;

    // 		end while
    goto L8;
L9:

    // 		if pattern[p] = '*' then
    DeRef(_214);
    _2 = (int)SEQ_PTR(_pattern);
    _214 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_214);
    if (binary_op_a(NOTEQ, _214, 42))
        goto LB;

    // 		    p -= 1
    _p = _p - 1;
LB:

    // 		t = qmatch(match_string, string[f..$])
    DeRef(_214);
    _214 = SEQ_PTR(_string)->length;
    rhs_slice_target = (object_ptr)&_214;
    RHS_Slice((s1_ptr)_string, _f, _214);
    RefDS(_match_string);
    RefDS(_214);
    _t = _3qmatch(_match_string, _214);

    // 		if t = 0 then
    if (_t != 0)
        goto LC;

    // 		    return 0
    DeRefDS(_pattern);
    DeRefDS(_string);
    DeRefDS(_match_string);
    DeRefDS(_214);
    DeRef(_209);
    return 0;
    goto LD;
LC:

    // 		    f += t + length(match_string) - 2
    DeRef(_214);
    _214 = SEQ_PTR(_match_string)->length;
    _214 = _t + _214;
    if ((long)((unsigned long)_214 + (unsigned long)HIGH_BITS) >= 0) 
        _214 = NewDouble((double)_214);
    _0 = _214;
    if (IS_ATOM_INT(_214)) {
        _214 = _214 - 2;
        if ((long)((unsigned long)_214 +(unsigned long) HIGH_BITS) >= 0)
            _214 = NewDouble((double)_214);
    }
    else {
        _214 = NewDouble(DBL_PTR(_214)->dbl - (double)2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_214)) {
        _f = _f + _214;
    }
    else {
        _f = NewDouble((double)_f + DBL_PTR(_214)->dbl);
    }
    if (!IS_ATOM_INT(_f)) {
        _1 = (long)(DBL_PTR(_f)->dbl);
        DeRefDS(_f);
        _f = _1;
    }
LE:
    goto LD;
L4:

    // 		return 0
    DeRefDS(_pattern);
    DeRefDS(_string);
    DeRef(_match_string);
    DeRef(_214);
    DeRef(_209);
    return 0;
LD:
L3:

    // 	p += 1
    _p = _p + 1;

    // 	f += 1
    _f = _f + 1;

    // 	if p > length(pattern) then
    DeRef(_214);
    _214 = SEQ_PTR(_pattern)->length;
    if (_p <= _214)
        goto L1;

    // 	    return f > length(string) 
    _214 = SEQ_PTR(_string)->length;
    _214 = (_f > _214);
    DeRefDS(_pattern);
    DeRefDS(_string);
    DeRef(_match_string);
    DeRef(_209);
    return _214;
LF:

    //     end while
    goto L1;
L2:

    //     return 0
    DeRefDS(_pattern);
    DeRefDS(_string);
    DeRef(_match_string);
    DeRef(_214);
    DeRef(_209);
    return 0;
    ;
}


int _3wildcard_file(int _pattern, int _filename)
{
    int _250;
    int _0, _1, _2;
    

    //     if platform() != LINUX then

    //     if not find('.', pattern) then
    _250 = find(46, _pattern);
    if (_250 != 0)
        goto L1;

    // 	pattern = pattern & '.'
    Append(&_pattern, _pattern, 46);
L1:

    //     if not find('.', filename) then
    _250 = find(46, _filename);
    if (_250 != 0)
        goto L2;

    // 	filename = filename & '.'
    Append(&_filename, _filename, 46);
L2:

    //     return wildcard_match(pattern, filename)
    RefDS(_pattern);
    RefDS(_filename);
    _250 = _3wildcard_match(_pattern, _filename);
    DeRefDS(_pattern);
    DeRefDS(_filename);
    return _250;
    ;
}


