// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _21get4()
{
    int _10119 = 0;
    int _0, _1, _2;
    

    //     poke(mem0, getc(current_db))
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10119 = getc(xstdin);
        }
        else
            _10119 = getc(last_r_file_ptr);
    }
    else
        _10119 = getc(last_r_file_ptr);
    if (IS_ATOM_INT(_21mem0))
        poke_addr = (unsigned char *)_21mem0;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_21mem0)->dbl);
    *poke_addr = (unsigned char)_10119;

    //     poke(mem1, getc(current_db))
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10119 = getc(xstdin);
        }
        else
            _10119 = getc(last_r_file_ptr);
    }
    else
        _10119 = getc(last_r_file_ptr);
    if (IS_ATOM_INT(_21mem1))
        poke_addr = (unsigned char *)_21mem1;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_21mem1)->dbl);
    *poke_addr = (unsigned char)_10119;

    //     poke(mem2, getc(current_db))
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10119 = getc(xstdin);
        }
        else
            _10119 = getc(last_r_file_ptr);
    }
    else
        _10119 = getc(last_r_file_ptr);
    if (IS_ATOM_INT(_21mem2))
        poke_addr = (unsigned char *)_21mem2;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_21mem2)->dbl);
    *poke_addr = (unsigned char)_10119;

    //     poke(mem3, getc(current_db))
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10119 = getc(xstdin);
        }
        else
            _10119 = getc(last_r_file_ptr);
    }
    else
        _10119 = getc(last_r_file_ptr);
    if (IS_ATOM_INT(_21mem3))
        poke_addr = (unsigned char *)_21mem3;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_21mem3)->dbl);
    *poke_addr = (unsigned char)_10119;

    //     return peek4u(mem0)
    if (IS_ATOM_INT(_21mem0)) {
        _10119 = *(unsigned long *)_21mem0;
        if ((unsigned)_10119 > (unsigned)MAXINT)
            _10119 = NewDouble((double)(unsigned long)_10119);
    }
    else {
        _10119 = *(unsigned long *)(unsigned long)(DBL_PTR(_21mem0)->dbl);
        if ((unsigned)_10119 > (unsigned)MAXINT)
            _10119 = NewDouble((double)(unsigned long)_10119);
    }
    return _10119;
    ;
}


int _21decompress(int _c)
{
    int _s = 0;
    int _len;
    int _10182 = 0;
    int _10183 = 0;
    int _10181;
    int _10180;
    int _10151 = 0;
    int _10145;
    int _10171;
    int _10172 = 0;
    int _0, _1, _2;
    

    //     if c = 0 then
    if (_c != 0)
        goto L1;

    // 		c = getc(current_db)
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _c = getc(xstdin);
        }
        else
            _c = getc(last_r_file_ptr);
    }
    else
        _c = getc(last_r_file_ptr);

    // 		if c < I2B then
    if (_c >= 249)
        goto L2;

    // 		    return c + MIN1B
    _10145 = _c + -9;
    return _10145;
L2:
L1:

    //     if c = I2B then
    if (_c != 249)
        goto L3;

    // 	return getc(current_db) + 
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10145 = getc(xstdin);
        }
        else
            _10145 = getc(last_r_file_ptr);
    }
    else
        _10145 = getc(last_r_file_ptr);
    DeRef(_10151);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10151 = getc(xstdin);
        }
        else
            _10151 = getc(last_r_file_ptr);
    }
    else
        _10151 = getc(last_r_file_ptr);
    _10151 = 256 * _10151;
    _10151 = _10145 + _10151;
    _10151 = _10151 + _21MIN2B;
    if ((long)((unsigned long)_10151 + (unsigned long)HIGH_BITS) >= 0) 
        _10151 = NewDouble((double)_10151);
    DeRef(_s);
    DeRef(_10182);
    DeRef(_10183);
    DeRef(_10172);
    return _10151;
    goto L4;
L3:

    //     elsif c = I3B then
    if (_c != 250)
        goto L5;

    // 	return getc(current_db) + 
    DeRef(_10151);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10151 = getc(xstdin);
        }
        else
            _10151 = getc(last_r_file_ptr);
    }
    else
        _10151 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10145 = getc(xstdin);
        }
        else
            _10145 = getc(last_r_file_ptr);
    }
    else
        _10145 = getc(last_r_file_ptr);
    _10145 = 256 * _10145;
    _10145 = _10151 + _10145;
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10151 = getc(xstdin);
        }
        else
            _10151 = getc(last_r_file_ptr);
    }
    else
        _10151 = getc(last_r_file_ptr);
    _10151 = 65536 * _10151;
    _10151 = _10145 + _10151;
    _10151 = _10151 + _21MIN3B;
    if ((long)((unsigned long)_10151 + (unsigned long)HIGH_BITS) >= 0) 
        _10151 = NewDouble((double)_10151);
    DeRef(_s);
    DeRef(_10182);
    DeRef(_10183);
    DeRef(_10172);
    return _10151;
    goto L4;
L5:

    //     elsif c = I4B then
    if (_c != 251)
        goto L6;

    // 	return get4() + MIN4B
    _0 = _10151;
    _10151 = _21get4();
    DeRef(_0);
    _0 = _10151;
    if (IS_ATOM_INT(_10151) && IS_ATOM_INT(_21MIN4B)) {
        _10151 = _10151 + _21MIN4B;
        if ((long)((unsigned long)_10151 + (unsigned long)HIGH_BITS) >= 0) 
            _10151 = NewDouble((double)_10151);
    }
    else {
        if (IS_ATOM_INT(_10151)) {
            _10151 = NewDouble((double)_10151 + DBL_PTR(_21MIN4B)->dbl);
        }
        else {
            if (IS_ATOM_INT(_21MIN4B)) {
                _10151 = NewDouble(DBL_PTR(_10151)->dbl + (double)_21MIN4B);
            }
            else
                _10151 = NewDouble(DBL_PTR(_10151)->dbl + DBL_PTR(_21MIN4B)->dbl);
        }
    }
    DeRef(_0);
    DeRef(_s);
    DeRef(_10182);
    DeRef(_10183);
    DeRef(_10172);
    return _10151;
    goto L4;
L6:

    //     elsif c = F4B then
    if (_c != 252)
        goto L7;

    // 	return float32_to_atom({getc(current_db), getc(current_db), 
    DeRef(_10151);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10151 = getc(xstdin);
        }
        else
            _10151 = getc(last_r_file_ptr);
    }
    else
        _10151 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10145 = getc(xstdin);
        }
        else
            _10145 = getc(last_r_file_ptr);
    }
    else
        _10145 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10171 = getc(xstdin);
        }
        else
            _10171 = getc(last_r_file_ptr);
    }
    else
        _10171 = getc(last_r_file_ptr);
    DeRef(_10172);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10172 = getc(xstdin);
        }
        else
            _10172 = getc(last_r_file_ptr);
    }
    else
        _10172 = getc(last_r_file_ptr);
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _10151;
    *((int *)(_2+8)) = _10145;
    *((int *)(_2+12)) = _10171;
    *((int *)(_2+16)) = _10172;
    _10172 = MAKE_SEQ(_1);
    RefDS(_10172);
    _0 = _10172;
    _10172 = _4float32_to_atom(_10172);
    DeRefDSi(_0);
    DeRef(_s);
    DeRef(_10182);
    DeRef(_10183);
    return _10172;
    goto L4;
L7:

    //     elsif c = F8B then
    if (_c != 253)
        goto L8;

    // 	return float64_to_atom({getc(current_db), getc(current_db),
    DeRef(_10172);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10172 = getc(xstdin);
        }
        else
            _10172 = getc(last_r_file_ptr);
    }
    else
        _10172 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10171 = getc(xstdin);
        }
        else
            _10171 = getc(last_r_file_ptr);
    }
    else
        _10171 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10145 = getc(xstdin);
        }
        else
            _10145 = getc(last_r_file_ptr);
    }
    else
        _10145 = getc(last_r_file_ptr);
    DeRef(_10151);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10151 = getc(xstdin);
        }
        else
            _10151 = getc(last_r_file_ptr);
    }
    else
        _10151 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10180 = getc(xstdin);
        }
        else
            _10180 = getc(last_r_file_ptr);
    }
    else
        _10180 = getc(last_r_file_ptr);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10181 = getc(xstdin);
        }
        else
            _10181 = getc(last_r_file_ptr);
    }
    else
        _10181 = getc(last_r_file_ptr);
    DeRef(_10182);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10182 = getc(xstdin);
        }
        else
            _10182 = getc(last_r_file_ptr);
    }
    else
        _10182 = getc(last_r_file_ptr);
    DeRef(_10183);
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10183 = getc(xstdin);
        }
        else
            _10183 = getc(last_r_file_ptr);
    }
    else
        _10183 = getc(last_r_file_ptr);
    _1 = NewS1(8);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _10172;
    *((int *)(_2+8)) = _10171;
    *((int *)(_2+12)) = _10145;
    *((int *)(_2+16)) = _10151;
    *((int *)(_2+20)) = _10180;
    *((int *)(_2+24)) = _10181;
    *((int *)(_2+28)) = _10182;
    *((int *)(_2+32)) = _10183;
    _10183 = MAKE_SEQ(_1);
    RefDS(_10183);
    _0 = _10183;
    _10183 = _4float64_to_atom(_10183);
    DeRefDSi(_0);
    DeRef(_s);
    return _10183;
    goto L4;
L8:

    // 	if c = S1B then
    if (_c != 254)
        goto L9;

    // 	    len = getc(current_db)
    if (_21current_db != last_r_file_no) {
        last_r_file_ptr = which_file(_21current_db, EF_READ);
        last_r_file_no = _21current_db;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _len = getc(xstdin);
        }
        else
            _len = getc(last_r_file_ptr);
    }
    else
        _len = getc(last_r_file_ptr);
    goto LA;
L9:

    // 	    len = get4()
    _len = _21get4();
    if (!IS_ATOM_INT(_len)) {
        _1 = (long)(DBL_PTR(_len)->dbl);
        DeRefDS(_len);
        _len = _1;
    }
LA:

    // 	s = repeat(0, len)
    DeRef(_s);
    _s = Repeat(0, _len);

    // 	for i = 1 to len do
    DeRef(_10183);
    _10183 = _len;
    { int _i;
        _i = 1;
LB:
        if (_i > _10183)
            goto LC;

        // 	    c = getc(current_db)
        if (_21current_db != last_r_file_no) {
            last_r_file_ptr = which_file(_21current_db, EF_READ);
            last_r_file_no = _21current_db;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _c = getc(xstdin);
            }
            else
                _c = getc(last_r_file_ptr);
        }
        else
            _c = getc(last_r_file_ptr);

        // 	    if c < I2B then
        if (_c >= 249)
            goto LD;

        // 		s[i] = c + MIN1B
        DeRef(_10182);
        _10182 = _c + -9;
        _2 = (int)SEQ_PTR(_s);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _s = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _10182;
        DeRef(_1);
        goto LE;
LD:

        // 		s[i] = decompress(c)
        DeRef(_10182);
        _10182 = _c;
        _10182 = _21decompress(_10182);
        Ref(_10182);
        _2 = (int)SEQ_PTR(_s);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _s = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _10182;
        DeRef(_1);
LE:

        // 	end for
        _i = _i + 1;
        goto LB;
LC:
        ;
    }

    // 	return s
    DeRef(_10182);
    DeRef(_10183);
    DeRef(_10151);
    DeRef(_10172);
    return _s;
L4:
    ;
}


int _21compress(int _x)
{
    int _x4 = 0;
    int _s = 0;
    int _10199 = 0;
    int _10216 = 0;
    int _10196 = 0;
    int _0, _1, _2;
    

    //     if integer(x) then
    if (IS_ATOM_INT(_x))
        _10196 = 1;
    else if (IS_ATOM_DBL(_x))
        _10196 = IS_ATOM_INT(DoubleToInt(_x));
    else
        _10196 = 0;
    if (_10196 == 0)
        goto L1;

    // 	if x >= MIN1B and x <= MAX1B then
    if (IS_ATOM_INT(_x)) {
        _10196 = (_x >= -9);
    }
    else {
        _10196 = binary_op(GREATEREQ, _x, -9);
    }
    if (IS_ATOM_INT(_10196)) {
        if (_10196 == 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_10196)->dbl == 0.0) {
            goto L2;
        }
    }
    if (IS_ATOM_INT(_x)) {
        _10199 = (_x <= 239);
    }
    else {
        _10199 = binary_op(LESSEQ, _x, 239);
    }
L3:
    if (_10199 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_10199) && DBL_PTR(_10199)->dbl == 0.0)
            goto L2;
    }

    // 	    return {x - MIN1B}
    DeRef(_10199);
    if (IS_ATOM_INT(_x)) {
        _10199 = _x - -9;
        if ((long)((unsigned long)_10199 +(unsigned long) HIGH_BITS) >= 0)
            _10199 = NewDouble((double)_10199);
    }
    else {
        _10199 = binary_op(MINUS, _x, -9);
    }
    _0 = _10199;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10199);
    *((int *)(_2+4)) = _10199;
    _10199 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_x);
    DeRefi(_x4);
    DeRef(_s);
    DeRef(_10216);
    DeRef(_10196);
    return _10199;
    goto L4;
L2:

    // 	elsif x >= MIN2B and x <= MAX2B then
    DeRef(_10199);
    if (IS_ATOM_INT(_x)) {
        _10199 = (_x >= _21MIN2B);
    }
    else {
        _10199 = binary_op(GREATEREQ, _x, _21MIN2B);
    }
    if (IS_ATOM_INT(_10199)) {
        if (_10199 == 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_10199)->dbl == 0.0) {
            goto L5;
        }
    }
    DeRef(_10196);
    if (IS_ATOM_INT(_x)) {
        _10196 = (_x <= 32767);
    }
    else {
        _10196 = binary_op(LESSEQ, _x, 32767);
    }
L6:
    if (_10196 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_10196) && DBL_PTR(_10196)->dbl == 0.0)
            goto L5;
    }

    // 	    x -= MIN2B
    _0 = _x;
    if (IS_ATOM_INT(_x)) {
        _x = _x - _21MIN2B;
        if ((long)((unsigned long)_x +(unsigned long) HIGH_BITS) >= 0)
            _x = NewDouble((double)_x);
    }
    else {
        _x = binary_op(MINUS, _x, _21MIN2B);
    }
    DeRef(_0);

    // 	    return {I2B, and_bits(x, #FF), floor(x / #100)}
    DeRef(_10196);
    if (IS_ATOM_INT(_x)) {
        _10196 = (_x & 255);
    }
    else {
        _10196 = binary_op(AND_BITS, _x, 255);
    }
    DeRef(_10199);
    if (IS_ATOM_INT(_x)) {
        if (256 > 0 && _x >= 0) {
            _10199 = _x / 256;
        }
        else {
            temp_dbl = floor((double)_x / (double)256);
            if (_x != MININT)
                _10199 = (long)temp_dbl;
            else
                _10199 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _x, 256);
        _10199 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    _0 = _10199;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 249;
    Ref(_10196);
    *((int *)(_2+8)) = _10196;
    Ref(_10199);
    *((int *)(_2+12)) = _10199;
    _10199 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_x);
    DeRefi(_x4);
    DeRef(_s);
    DeRef(_10216);
    DeRef(_10196);
    return _10199;
    goto L4;
L5:

    // 	elsif x >= MIN3B and x <= MAX3B then
    DeRef(_10199);
    if (IS_ATOM_INT(_x)) {
        _10199 = (_x >= _21MIN3B);
    }
    else {
        _10199 = binary_op(GREATEREQ, _x, _21MIN3B);
    }
    if (IS_ATOM_INT(_10199)) {
        if (_10199 == 0) {
            goto L7;
        }
    }
    else {
        if (DBL_PTR(_10199)->dbl == 0.0) {
            goto L7;
        }
    }
    DeRef(_10196);
    if (IS_ATOM_INT(_x)) {
        _10196 = (_x <= 8388607);
    }
    else {
        _10196 = binary_op(LESSEQ, _x, 8388607);
    }
L8:
    if (_10196 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_10196) && DBL_PTR(_10196)->dbl == 0.0)
            goto L7;
    }

    // 	    x -= MIN3B
    _0 = _x;
    if (IS_ATOM_INT(_x)) {
        _x = _x - _21MIN3B;
        if ((long)((unsigned long)_x +(unsigned long) HIGH_BITS) >= 0)
            _x = NewDouble((double)_x);
    }
    else {
        _x = binary_op(MINUS, _x, _21MIN3B);
    }
    DeRef(_0);

    // 	    return {I3B, and_bits(x, #FF), and_bits(floor(x / #100), #FF), floor(x / #10000)}
    DeRef(_10196);
    if (IS_ATOM_INT(_x)) {
        _10196 = (_x & 255);
    }
    else {
        _10196 = binary_op(AND_BITS, _x, 255);
    }
    DeRef(_10199);
    if (IS_ATOM_INT(_x)) {
        if (256 > 0 && _x >= 0) {
            _10199 = _x / 256;
        }
        else {
            temp_dbl = floor((double)_x / (double)256);
            if (_x != MININT)
                _10199 = (long)temp_dbl;
            else
                _10199 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _x, 256);
        _10199 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    _0 = _10199;
    if (IS_ATOM_INT(_10199)) {
        _10199 = (_10199 & 255);
    }
    else {
        _10199 = binary_op(AND_BITS, _10199, 255);
    }
    DeRef(_0);
    DeRef(_10216);
    if (IS_ATOM_INT(_x)) {
        if (65536 > 0 && _x >= 0) {
            _10216 = _x / 65536;
        }
        else {
            temp_dbl = floor((double)_x / (double)65536);
            if (_x != MININT)
                _10216 = (long)temp_dbl;
            else
                _10216 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _x, 65536);
        _10216 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    _0 = _10216;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 250;
    Ref(_10196);
    *((int *)(_2+8)) = _10196;
    Ref(_10199);
    *((int *)(_2+12)) = _10199;
    Ref(_10216);
    *((int *)(_2+16)) = _10216;
    _10216 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_x);
    DeRefi(_x4);
    DeRef(_s);
    DeRef(_10199);
    DeRef(_10196);
    return _10216;
    goto L4;
L7:

    // 	    return I4B & int_to_bytes(x-MIN4B)    
    DeRef(_10216);
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_21MIN4B)) {
        _10216 = _x - _21MIN4B;
        if ((long)((unsigned long)_10216 +(unsigned long) HIGH_BITS) >= 0)
            _10216 = NewDouble((double)_10216);
    }
    else {
        _10216 = binary_op(MINUS, _x, _21MIN4B);
    }
    Ref(_10216);
    _0 = _10216;
    _10216 = _4int_to_bytes(_10216);
    DeRef(_0);
    Prepend(&_10216, _10216, 251);
    DeRef(_x);
    DeRefi(_x4);
    DeRef(_s);
    DeRef(_10199);
    DeRef(_10196);
    return _10216;
L9:
    goto L4;
L1:

    //     elsif atom(x) then
    DeRef(_10216);
    _10216 = IS_ATOM(_x);
    if (_10216 == 0)
        goto LA;

    // 	x4 = atom_to_float32(x)
    Ref(_x);
    _0 = _x4;
    _x4 = _4atom_to_float32(_x);
    DeRefi(_0);

    // 	if x = float32_to_atom(x4) then
    RefDS(_x4);
    _10216 = _4float32_to_atom(_x4);
    if (binary_op_a(NOTEQ, _x, _10216))
        goto LB;

    // 	    return F4B & x4
    Prepend(&_10216, _x4, 252);
    DeRef(_x);
    DeRefDSi(_x4);
    DeRef(_s);
    DeRef(_10199);
    DeRef(_10196);
    return _10216;
    goto L4;
LB:

    // 	    return F8B & atom_to_float64(x)
    Ref(_x);
    _0 = _10216;
    _10216 = _4atom_to_float64(_x);
    DeRef(_0);
    Prepend(&_10216, _10216, 253);
    DeRef(_x);
    DeRefi(_x4);
    DeRef(_s);
    DeRef(_10199);
    DeRef(_10196);
    return _10216;
LC:
    goto L4;
LA:

    // 	if length(x) <= 255 then
    DeRef(_10216);
    _10216 = SEQ_PTR(_x)->length;
    if (_10216 > 255)
        goto LD;

    // 	    s = {S1B, length(x)}
    _10216 = SEQ_PTR(_x)->length;
    DeRef(_s);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 254;
    ((int *)_2)[2] = _10216;
    _s = MAKE_SEQ(_1);
    goto LE;
LD:

    // 	    s = S4B & int_to_bytes(length(x))
    DeRef(_10216);
    _10216 = SEQ_PTR(_x)->length;
    _10216 = _4int_to_bytes(_10216);
    Prepend(&_s, _10216, 255);
LE:

    // 	for i = 1 to length(x) do
    DeRef(_10216);
    _10216 = SEQ_PTR(_x)->length;
    { int _i;
        _i = 1;
LF:
        if (_i > _10216)
            goto L10;

        // 	    s &= compress(x[i])
        DeRef(_10199);
        _2 = (int)SEQ_PTR(_x);
        _10199 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10199);
        Ref(_10199);
        _0 = _10199;
        _10199 = _21compress(_10199);
        DeRef(_0);
        Concat((object_ptr)&_s, _s, (s1_ptr)_10199);

        // 	end for
        _i = _i + 1;
        goto LF;
L10:
        ;
    }

    // 	return s
    DeRef(_x);
    DeRefi(_x4);
    DeRef(_10199);
    DeRef(_10216);
    DeRef(_10196);
    return _s;
L4:
    ;
}


int _21read_symtab(int _fn)
{
    int _symtab = 0;
    int _sym = 0;
    int _line_change = 0;
    int _magic = 0;
    int _entries;
    int _old_file;
    int _line;
    int _len;
    int _10240 = 0;
    int _10241 = 0;
    int _10242 = 0;
    int _10239 = 0;
    int _0, _1, _2, _3;
    

    // 	current_db = fn
    _21current_db = _fn;

    // 	if compare( getc(fn)&getc(fn)&getc(fn)&getc(fn), MAGIC_NUMBER ) then
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10239 = getc(xstdin);
        }
        else
            _10239 = getc(last_r_file_ptr);
    }
    else
        _10239 = getc(last_r_file_ptr);
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10240 = getc(xstdin);
        }
        else
            _10240 = getc(last_r_file_ptr);
    }
    else
        _10240 = getc(last_r_file_ptr);
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10241 = getc(xstdin);
        }
        else
            _10241 = getc(last_r_file_ptr);
    }
    else
        _10241 = getc(last_r_file_ptr);
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10242 = getc(xstdin);
        }
        else
            _10242 = getc(last_r_file_ptr);
    }
    else
        _10242 = getc(last_r_file_ptr);
    {
        int concat_list[4];

        concat_list[0] = _10242;
        concat_list[1] = _10241;
        concat_list[2] = _10240;
        concat_list[3] = _10239;
        Concat_N((object_ptr)&_10242, concat_list, 4);
    }
    _0 = _10242;
    if (IS_ATOM_INT(_10242) && IS_ATOM_INT(_7MAGIC_NUMBER))
        _10242 = (_10242 < _7MAGIC_NUMBER) ? -1 : (_10242 > _7MAGIC_NUMBER);
    else
        _10242 = compare(_10242, _7MAGIC_NUMBER);
    DeRefDSi(_0);
    if (_10242 == 0)
        goto L1;

    // 		puts(2, "Invalid oe file\n\nPress Enter...\n" )
    EPuts(2, _10245);

    // 		while getc(0) != '\n' do
L2:
    DeRef(_10242);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10242 = getc(xstdin);
        }
        else
            _10242 = getc(last_r_file_ptr);
    }
    else
        _10242 = getc(last_r_file_ptr);
    if (_10242 == 10)
        goto L3;

    // 		end while
    goto L2;
L3:

    // 		abort(1)
    UserCleanup(1);
L1:

    // 	if getc(fn) != SHROUD_VERSION then
    DeRef(_10242);
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10242 = getc(xstdin);
        }
        else
            _10242 = getc(last_r_file_ptr);
    }
    else
        _10242 = getc(last_r_file_ptr);
    if (_10242 == 3)
        goto L4;

    // 		puts(2, "Incompatible shroud version\n\nPress Enter...\n" )
    EPuts(2, _10250);

    // 		while getc(0) != '\n' do
L5:
    DeRef(_10242);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10242 = getc(xstdin);
        }
        else
            _10242 = getc(last_r_file_ptr);
    }
    else
        _10242 = getc(last_r_file_ptr);
    if (_10242 == 10)
        goto L6;

    // 		end while
    goto L5;
L6:

    // 		abort(1)	
    UserCleanup(1);
L4:

    // 	full_debug = getc( fn )
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _7full_debug = getc(xstdin);
        }
        else
            _7full_debug = getc(last_r_file_ptr);
    }
    else
        _7full_debug = getc(last_r_file_ptr);

    // 	use_eval = getc( fn )
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _7use_eval = getc(xstdin);
        }
        else
            _7use_eval = getc(last_r_file_ptr);
    }
    else
        _7use_eval = getc(last_r_file_ptr);

    // 	entries = decompress( 0 )
    _entries = _21decompress(0);
    if (!IS_ATOM_INT(_entries)) {
        _1 = (long)(DBL_PTR(_entries)->dbl);
        DeRefDS(_entries);
        _entries = _1;
    }

    // 	symtab = repeat( {0}, entries )
    _0 = _10242;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _10242 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_symtab);
    _symtab = Repeat(_10242, _entries);

    // 	for s = 1 to entries do
    DeRefDS(_10242);
    _10242 = _entries;
    { int _s;
        _s = 1;
L7:
        if (_s > _10242)
            goto L8;

        // 		len = getc( fn )
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _len = getc(xstdin);
            }
            else
                _len = getc(last_r_file_ptr);
        }
        else
            _len = getc(last_r_file_ptr);

        // 		if len then
        if (_len == 0)
            goto L9;

        // 			sym = repeat( 0, len )
        DeRef(_sym);
        _sym = Repeat(0, _len);

        // 			if len = 5 then
        if (_len != 5)
            goto LA;

        // 				sym[S_OBJ] = decompress( 0 )
        _0 = _10241;
        _10241 = _21decompress(0);
        DeRef(_0);
        Ref(_10241);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        *(int *)_2 = _10241;
        goto LB;
LA:

        // 			elsif getc( fn ) then
        DeRef(_10241);
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _10241 = getc(xstdin);
            }
            else
                _10241 = getc(last_r_file_ptr);
        }
        else
            _10241 = getc(last_r_file_ptr);
        if (_10241 == 0)
            goto LC;

        // 				sym[S_OBJ] = decompress( 0 )
        _10241 = _21decompress(0);
        Ref(_10241);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _10241;
        DeRef(_1);
LC:
LB:

        // 			sym[S_NEXT] = decompress( 0 )
        _0 = _10241;
        _10241 = _21decompress(0);
        DeRef(_0);
        Ref(_10241);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 2);
        _1 = *(int *)_2;
        *(int *)_2 = _10241;
        DeRef(_1);

        // 			sym[S_MODE] = getc( fn )
        DeRef(_10241);
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _10241 = getc(xstdin);
            }
            else
                _10241 = getc(last_r_file_ptr);
        }
        else
            _10241 = getc(last_r_file_ptr);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 3);
        _1 = *(int *)_2;
        *(int *)_2 = _10241;
        DeRef(_1);

        // 			sym[S_SCOPE] = getc( fn )
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _10241 = getc(xstdin);
            }
            else
                _10241 = getc(last_r_file_ptr);
        }
        else
            _10241 = getc(last_r_file_ptr);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 4);
        _1 = *(int *)_2;
        *(int *)_2 = _10241;
        DeRef(_1);

        // 			if len > S_USAGE then
        if (_len <= 5)
            goto LD;

        // 				sym[S_FILE_NO] = getc( fn )
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _10241 = getc(xstdin);
            }
            else
                _10241 = getc(last_r_file_ptr);
        }
        else
            _10241 = getc(last_r_file_ptr);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 6);
        _1 = *(int *)_2;
        *(int *)_2 = _10241;
        DeRef(_1);

        // 				if use_eval or full_debug or len > S_VTYPE then
        if (_7use_eval != 0) {
            _10241 = 1;
            goto LE;
        }
        _10241 = (_7full_debug != 0);
LE:
        if (_10241 != 0) {
            goto LF;
        }
        DeRef(_10240);
        _10240 = (_len > 14);
L10:
        if (_10240 == 0)
            goto L11;
LF:

        // 					sym[S_NAME] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 7);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);
        goto L12;
L11:

        // 					sym[S_NAME] = ""
        RefDS(_39);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 7);
        _1 = *(int *)_2;
        *(int *)_2 = _39;
        DeRef(_1);
L12:

        // 				sym[S_TOKEN] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 9);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_VTYPE] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 14);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 				if len > S_VTYPE then
        if (_len <= 14)
            goto L13;

        // 					sym[S_CODE] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 15);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_LINETAB] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 16);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_FIRSTLINE] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 17);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_TEMPS] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 18);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_NUM_ARGS] = getc( fn )
        DeRef(_10240);
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _10240 = getc(xstdin);
            }
            else
                _10240 = getc(last_r_file_ptr);
        }
        else
            _10240 = getc(last_r_file_ptr);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 20);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_GOTO] = decompress( 0 )
        _10240 = _21decompress(0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 24);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 					sym[S_BYREF] = decompress( 0 )
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(_sym);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _sym = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 25);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);
L13:
LD:

        // 			symtab[s] = sym
        RefDS(_sym);
        _2 = (int)SEQ_PTR(_symtab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _symtab = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _s);
        _1 = *(int *)_2;
        *(int *)_2 = _sym;
        DeRefDS(_1);
L9:

        // 	end for
        _s = _s + 1;
        goto L7;
L8:
        ;
    }

    // 	file_name = decompress( 0 )
    _0 = _21decompress(0);
    DeRef(_7file_name);
    _7file_name = _0;

    // 	slist = repeat( {0,0,0,0}, decompress(0))
    _0 = _10240;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    *((int *)(_2+8)) = 0;
    *((int *)(_2+12)) = 0;
    *((int *)(_2+16)) = 0;
    _10240 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _10241;
    _10241 = _21decompress(0);
    DeRef(_0);
    DeRef(_7slist);
    _7slist = Repeat(_10240, _10241);

    // 	if full_debug then
    if (_7full_debug == 0)
        goto L14;

    // 		for i = 1 to length(slist) do
    DeRef(_10241);
    _10241 = SEQ_PTR(_7slist)->length;
    { int _i;
        _i = 1;
L15:
        if (_i > _10241)
            goto L16;

        // 			slist[i][1] = decompress(0)
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        _0 = _10239;
        _10239 = _21decompress(0);
        DeRef(_0);
        Ref(_10239);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _10239;
        DeRef(_1);

        // 			slist[i][2] = decompress(0)
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        _0 = _10240;
        _10240 = _21decompress(0);
        DeRef(_0);
        Ref(_10240);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 2);
        _1 = *(int *)_2;
        *(int *)_2 = _10240;
        DeRef(_1);

        // 			slist[i][3] = decompress(0)
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        _0 = _10239;
        _10239 = _21decompress(0);
        DeRef(_0);
        Ref(_10239);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 3);
        _1 = *(int *)_2;
        *(int *)_2 = _10239;
        DeRef(_1);

        // 		end for
        _i = _i + 1;
        goto L15;
L16:
        ;
    }
    goto L17;
L14:

    // 		line = 1
    _line = 1;

    // 		for until = 1 to decompress(0) do
    _0 = _10239;
    _10239 = _21decompress(0);
    DeRef(_0);
    { int _until;
        _until = 1;
L18:
        if (binary_op_a(GREATER, _until, _10239))
            goto L19;

        // 			line_change = decompress(0)
        _0 = _line_change;
        _line_change = _21decompress(0);
        DeRef(_0);

        // 			old_file = line_change[1]
        _2 = (int)SEQ_PTR(_line_change);
        _old_file = (int)*(((s1_ptr)_2)->base + 1);
        if (!IS_ATOM_INT(_old_file))
            _old_file = (long)DBL_PTR(_old_file)->dbl;

        // 			for s = line to line_change[2] do
        DeRef(_10242);
        _2 = (int)SEQ_PTR(_line_change);
        _10242 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10242);
        { int _s;
            _s = _line;
L1A:
            if (binary_op_a(GREATER, _s, _10242))
                goto L1B;

            // 				slist[s][LINE] = s
            _2 = (int)SEQ_PTR(_7slist);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _7slist = MAKE_SEQ(_2);
            }
            if (!IS_ATOM_INT(_s))
                _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_s)->dbl));
            else
                _3 = (int)(_s + ((s1_ptr)_2)->base);
            Ref(_s);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 2);
            _1 = *(int *)_2;
            *(int *)_2 = _s;
            DeRef(_1);

            // 				slist[s][LOCAL_FILE_NO] = old_file
            _2 = (int)SEQ_PTR(_7slist);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _7slist = MAKE_SEQ(_2);
            }
            if (!IS_ATOM_INT(_s))
                _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_s)->dbl));
            else
                _3 = (int)(_s + ((s1_ptr)_2)->base);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 3);
            _1 = *(int *)_2;
            *(int *)_2 = _old_file;
            DeRef(_1);

            // 			end for
            _0 = _s;
            if (IS_ATOM_INT(_s)) {
                _s = _s + 1;
                if ((long)((unsigned long)_s +(unsigned long) HIGH_BITS) >= 0) 
                    _s = NewDouble((double)_s);
            }
            else {
                _s = binary_op_a(PLUS, _s, 1);
            }
            DeRef(_0);
            goto L1A;
L1B:
            ;
            DeRef(_s);
        }

        // 			line = line_change[2] + 1
        DeRef(_10240);
        _2 = (int)SEQ_PTR(_line_change);
        _10240 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10240);
        if (IS_ATOM_INT(_10240)) {
            _line = _10240 + 1;
        }
        else
            _line = 1+(long)(DBL_PTR(_10240)->dbl);

        // 		end for
        _0 = _until;
        if (IS_ATOM_INT(_until)) {
            _until = _until + 1;
            if ((long)((unsigned long)_until +(unsigned long) HIGH_BITS) >= 0) 
                _until = NewDouble((double)_until);
        }
        else {
            _until = binary_op_a(PLUS, _until, 1);
        }
        DeRef(_0);
        goto L18;
L19:
        ;
        DeRef(_until);
    }
L17:

    // 	return symtab	
    DeRef(_sym);
    DeRef(_line_change);
    DeRef(_magic);
    DeRef(_10240);
    DeRef(_10241);
    DeRef(_10242);
    DeRef(_10239);
    return _symtab;
    ;
}


int _21s_expand(int _slist)
{
    int _new_slist = 0;
    int _10317 = 0;
    int _10314;
    int _10309 = 0;
    int _10308;
    int _0, _1, _2, _3;
    

    //     new_slist = {}
    RefDS(_39);
    _new_slist = _39;

    //     for i = 1 to length(slist) do
    _10308 = SEQ_PTR(_slist)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _10308)
            goto L2;

        // 	if sequence(slist[i]) then
        DeRef(_10309);
        _2 = (int)SEQ_PTR(_slist);
        _10309 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10309);
        _0 = _10309;
        _10309 = IS_SEQUENCE(_10309);
        DeRef(_0);
        if (_10309 == 0)
            goto L3;

        // 	    new_slist = append(new_slist, slist[i])
        _2 = (int)SEQ_PTR(_slist);
        _10309 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10309);
        Ref(_10309);
        Append(&_new_slist, _new_slist, _10309);
        goto L4;
L3:

        // 	    for j = 1 to slist[i] do
        DeRef(_10309);
        _2 = (int)SEQ_PTR(_slist);
        _10309 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10309);
        { int _j;
            _j = 1;
L5:
            if (binary_op_a(GREATER, _j, _10309))
                goto L6;

            // 		slist[i-1][LINE] += 1
            _10314 = _i - 1;
            _2 = (int)SEQ_PTR(_slist);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _slist = MAKE_SEQ(_2);
            }
            _3 = (int)(_10314 + ((s1_ptr)_2)->base);
            DeRef(_10317);
            _2 = (int)SEQ_PTR(*(int *)_3);
            _10317 = (int)*(((s1_ptr)_2)->base + 2);
            Ref(_10317);
            _0 = _10317;
            if (IS_ATOM_INT(_10317)) {
                _10317 = _10317 + 1;
                if (_10317 > MAXINT)
                    _10317 = NewDouble((double)_10317);
            }
            else
                _10317 = binary_op(PLUS, 1, _10317);
            DeRef(_0);
            Ref(_10317);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 2);
            _1 = *(int *)_2;
            *(int *)_2 = _10317;
            DeRef(_1);

            // 		new_slist = append(new_slist, slist[i-1]) 
            DeRef(_10317);
            _10317 = _i - 1;
            _2 = (int)SEQ_PTR(_slist);
            _10317 = (int)*(((s1_ptr)_2)->base + _10317);
            Ref(_10317);
            Ref(_10317);
            Append(&_new_slist, _new_slist, _10317);

            // 	    end for
            _0 = _j;
            if (IS_ATOM_INT(_j)) {
                _j = _j + 1;
                if ((long)((unsigned long)_j +(unsigned long) HIGH_BITS) >= 0) 
                    _j = NewDouble((double)_j);
            }
            else {
                _j = binary_op_a(PLUS, _j, 1);
            }
            DeRef(_0);
            goto L5;
L6:
            ;
            DeRef(_j);
        }
L4:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return new_slist
    DeRefDS(_slist);
    DeRef(_10317);
    DeRef(_10309);
    return _new_slist;
    ;
}


int _21write_symtab(int _fn, int _symtab)
{
    int _sym = 0;
    int _line_change = 0;
    int _len;
    int _old_file;
    int _10322 = 0;
    int _10387 = 0;
    int _10331 = 0;
    int _10350 = 0;
    int _0, _1, _2, _3;
    

    // 	if atom(slist[$]) then
    _10322 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _10322 = (int)*(((s1_ptr)_2)->base + _10322);
    Ref(_10322);
    _0 = _10322;
    _10322 = IS_ATOM(_10322);
    DeRef(_0);
    if (_10322 == 0)
        goto L1;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _21s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L1:

    // 	puts( fn, MAGIC_NUMBER )
    EPuts(_fn, _7MAGIC_NUMBER);

    // 	puts( fn, SHROUD_VERSION )
    EPuts(_fn, 3);

    // 	puts( fn, full_debug )
    EPuts(_fn, _7full_debug);

    // 	use_eval = find( 1, file_eval ) != 0 
    DeRef(_10322);
    _10322 = find(1, _7file_eval);
    _7use_eval = (_10322 != 0);

    // 	puts( fn, use_eval )
    EPuts(_fn, _7use_eval);

    // 	puts( fn, compress( length(symtab) ) )
    _10322 = SEQ_PTR(_symtab)->length;
    _10322 = _21compress(_10322);
    EPuts(_fn, _10322);

    // 	for s = 1 to length(symtab) do
    DeRefDS(_10322);
    _10322 = SEQ_PTR(_symtab)->length;
    { int _s;
        _s = 1;
L2:
        if (_s > _10322)
            goto L3;

        // 		sym = symtab[s]
        DeRef(_sym);
        _2 = (int)SEQ_PTR(_symtab);
        _sym = (int)*(((s1_ptr)_2)->base + _s);
        Ref(_sym);

        // 		len = length(sym)
        _len = SEQ_PTR(_sym)->length;

        // 		if len = 1 then
        if (_len != 1)
            goto L4;

        // 			puts( fn, 0 )
        EPuts(_fn, 0);
        goto L5;
L4:

        // 			puts( fn, length(sym) )
        DeRef(_10331);
        _10331 = SEQ_PTR(_sym)->length;
        EPuts(_fn, _10331);

        // 			if len = 5 then
        if (_len != 5)
            goto L6;

        // 				puts( fn, compress( sym[S_OBJ] ))
        _2 = (int)SEQ_PTR(_sym);
        _10331 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10331);
        Ref(_10331);
        _0 = _10331;
        _10331 = _21compress(_10331);
        DeRef(_0);
        EPuts(_fn, _10331);
        goto L7;
L6:

        // 			elsif compare(sym[S_OBJ], NOVALUE) then
        DeRef(_10331);
        _2 = (int)SEQ_PTR(_sym);
        _10331 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10331);
        _0 = _10331;
        if (IS_ATOM_INT(_10331) && IS_ATOM_INT(_7NOVALUE))
            _10331 = (_10331 < _7NOVALUE) ? -1 : (_10331 > _7NOVALUE);
        else
            _10331 = compare(_10331, _7NOVALUE);
        DeRef(_0);
        if (_10331 == 0)
            goto L8;

        // 				puts( fn, 1 & compress( sym[S_OBJ] ))
        _2 = (int)SEQ_PTR(_sym);
        _10331 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10331);
        Ref(_10331);
        _0 = _10331;
        _10331 = _21compress(_10331);
        DeRef(_0);
        Prepend(&_10331, _10331, 1);
        EPuts(_fn, _10331);
        goto L7;
L8:

        // 				puts( fn, 0 )
        EPuts(_fn, 0);
L7:

        // 			puts( fn, compress( sym[S_NEXT] ))
        DeRef(_10331);
        _2 = (int)SEQ_PTR(_sym);
        _10331 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10331);
        Ref(_10331);
        _0 = _10331;
        _10331 = _21compress(_10331);
        DeRef(_0);
        EPuts(_fn, _10331);

        // 			puts( fn, sym[S_MODE..S_SCOPE] )
        rhs_slice_target = (object_ptr)&_10331;
        RHS_Slice((s1_ptr)_sym, 3, 4);
        EPuts(_fn, _10331);

        // 			if len > S_USAGE then
        if (_len <= 5)
            goto L9;

        // 				puts( fn, sym[S_FILE_NO] )
        DeRefDS(_10331);
        _2 = (int)SEQ_PTR(_sym);
        _10331 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_10331);
        EPuts(_fn, _10331);

        // 				if use_eval or full_debug or len > S_VTYPE then
        if (_7use_eval != 0) {
            DeRef(_10331);
            _10331 = 1;
            goto LA;
        }
        _10331 = (_7full_debug != 0);
LA:
        if (_10331 != 0) {
            goto LB;
        }
        DeRef(_10350);
        _10350 = (_len > 14);
LC:
        if (_10350 == 0)
            goto LD;
LB:

        // 					puts( fn, compress( sym[S_NAME] ))
        DeRef(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);
LD:

        // 				puts( fn, compress( sym[S_TOKEN] ))
        DeRef(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 9);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 					puts( fn, compress( sym[S_VTYPE] ))
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 14);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 				if len > S_VTYPE then
        if (_len <= 14)
            goto LE;

        // 					puts( fn, compress( sym[S_CODE] ) )
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 15);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 					puts( fn, compress( sym[S_LINETAB] ) )
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 16);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 					puts( fn, compress( sym[S_FIRSTLINE] ) )
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 17);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 					puts( fn, compress( sym[S_TEMPS] ) )
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 18);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 					puts( fn, sym[S_NUM_ARGS] )
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 20);
        Ref(_10350);
        EPuts(_fn, _10350);

        // 					puts( fn, compress(sym[S_GOTO]) )
        DeRef(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 24);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);

        // 					puts( fn, compress(sym[S_BYREF]) )
        DeRefDS(_10350);
        _2 = (int)SEQ_PTR(_sym);
        _10350 = (int)*(((s1_ptr)_2)->base + 25);
        Ref(_10350);
        Ref(_10350);
        _0 = _10350;
        _10350 = _21compress(_10350);
        DeRef(_0);
        EPuts(_fn, _10350);
LE:
L9:
L5:

        // 	end for
        _s = _s + 1;
        goto L2;
L3:
        ;
    }

    // 	puts(fn, compress( file_name ) )
    RefDS(_7file_name);
    _0 = _10350;
    _10350 = _21compress(_7file_name);
    DeRef(_0);
    EPuts(_fn, _10350);

    // 	if atom(slist[$]) then
    DeRefDS(_10350);
    _10350 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _10350 = (int)*(((s1_ptr)_2)->base + _10350);
    Ref(_10350);
    _0 = _10350;
    _10350 = IS_ATOM(_10350);
    DeRef(_0);
    if (_10350 == 0)
        goto LF;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _21s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;

    // 		slist = slist[1..$-1]
    _10350 = SEQ_PTR(_7slist)->length;
    _10350 = _10350 - 1;
    rhs_slice_target = (object_ptr)&_7slist;
    RHS_Slice((s1_ptr)_7slist, 1, _10350);
LF:

    // 	puts(fn, compress( length( slist ) ))
    DeRef(_10350);
    _10350 = SEQ_PTR(_7slist)->length;
    _10350 = _21compress(_10350);
    EPuts(_fn, _10350);

    // 	if full_debug then
    if (_7full_debug == 0)
        goto L10;

    // 		for i = 1 to length(slist) do
    DeRefDS(_10350);
    _10350 = SEQ_PTR(_7slist)->length;
    { int _i;
        _i = 1;
L11:
        if (_i > _10350)
            goto L12;

        // 			if atom( slist[i][SRC] ) then
        DeRef(_10331);
        _2 = (int)SEQ_PTR(_7slist);
        _10331 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10331);
        _0 = _10331;
        _2 = (int)SEQ_PTR(_10331);
        _10331 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10331);
        DeRef(_0);
        _0 = _10331;
        _10331 = IS_ATOM(_10331);
        DeRef(_0);
        if (_10331 == 0)
            goto L13;

        // 				slist[i][SRC] = fetch_line( slist[i][SRC] )
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_10387);
        _2 = (int)SEQ_PTR(_7slist);
        _10387 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10387);
        _0 = _10387;
        _2 = (int)SEQ_PTR(_10387);
        _10387 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10387);
        DeRef(_0);
        Ref(_10387);
        _0 = _10387;
        _10387 = _12fetch_line(_10387);
        DeRef(_0);
        RefDS(_10387);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _10387;
        DeRef(_1);
L13:

        // 			puts( fn, compress( slist[i][SRC]) )
        DeRef(_10387);
        _2 = (int)SEQ_PTR(_7slist);
        _10387 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10387);
        _0 = _10387;
        _2 = (int)SEQ_PTR(_10387);
        _10387 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10387);
        DeRef(_0);
        Ref(_10387);
        _0 = _10387;
        _10387 = _21compress(_10387);
        DeRef(_0);
        EPuts(_fn, _10387);

        // 			puts( fn, compress( slist[i][2]) )
        DeRefDS(_10387);
        _2 = (int)SEQ_PTR(_7slist);
        _10387 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10387);
        _0 = _10387;
        _2 = (int)SEQ_PTR(_10387);
        _10387 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10387);
        DeRef(_0);
        Ref(_10387);
        _0 = _10387;
        _10387 = _21compress(_10387);
        DeRef(_0);
        EPuts(_fn, _10387);

        // 			puts( fn, compress( slist[i][3]) )
        DeRefDS(_10387);
        _2 = (int)SEQ_PTR(_7slist);
        _10387 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10387);
        _0 = _10387;
        _2 = (int)SEQ_PTR(_10387);
        _10387 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10387);
        DeRef(_0);
        Ref(_10387);
        _0 = _10387;
        _10387 = _21compress(_10387);
        DeRef(_0);
        EPuts(_fn, _10387);

        // 		end for
        _i = _i + 1;
        goto L11;
L12:
        ;
    }
    goto L14;
L10:

    // 		line_change = {}
    RefDS(_39);
    DeRef(_line_change);
    _line_change = _39;

    // 		old_file = slist[1][LOCAL_FILE_NO]
    DeRef(_10387);
    _2 = (int)SEQ_PTR(_7slist);
    _10387 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10387);
    _2 = (int)SEQ_PTR(_10387);
    _old_file = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_old_file))
        _old_file = (long)DBL_PTR(_old_file)->dbl;

    // 		len = 1
    _len = 1;

    // 		for i = 1 to length(slist) do
    DeRef(_10387);
    _10387 = SEQ_PTR(_7slist)->length;
    { int _i;
        _i = 1;
L15:
        if (_i > _10387)
            goto L16;

        // 			if old_file != slist[i][LOCAL_FILE_NO] then
        DeRef(_10322);
        _2 = (int)SEQ_PTR(_7slist);
        _10322 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10322);
        _0 = _10322;
        _2 = (int)SEQ_PTR(_10322);
        _10322 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10322);
        DeRef(_0);
        if (binary_op_a(EQUALS, _old_file, _10322))
            goto L17;

        // 				line_change &= compress( old_file & i )
        Concat((object_ptr)&_10322, _old_file, (s1_ptr)_i);
        RefDS(_10322);
        _0 = _10322;
        _10322 = _21compress(_10322);
        DeRefDSi(_0);
        Concat((object_ptr)&_line_change, _line_change, (s1_ptr)_10322);

        // 				len += 1
        _len = _len + 1;

        // 				old_file = slist[i][LOCAL_FILE_NO]
        DeRefDS(_10322);
        _2 = (int)SEQ_PTR(_7slist);
        _10322 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10322);
        _2 = (int)SEQ_PTR(_10322);
        _old_file = (int)*(((s1_ptr)_2)->base + 3);
        if (!IS_ATOM_INT(_old_file))
            _old_file = (long)DBL_PTR(_old_file)->dbl;
L17:

        // 		end for
        _i = _i + 1;
        goto L15;
L16:
        ;
    }

    // 		line_change &= compress( old_file & length(slist))
    DeRef(_10322);
    _10322 = SEQ_PTR(_7slist)->length;
    Concat((object_ptr)&_10322, _old_file, (s1_ptr)_10322);
    RefDS(_10322);
    _0 = _10322;
    _10322 = _21compress(_10322);
    DeRefDSi(_0);
    Concat((object_ptr)&_line_change, _line_change, (s1_ptr)_10322);

    // 		puts( fn, compress( len ))
    _0 = _10322;
    _10322 = _21compress(_len);
    DeRefDS(_0);
    EPuts(_fn, _10322);

    // 		puts( fn,  line_change	)
    EPuts(_fn, _line_change);
L14:

    // end procedure
    DeRefDS(_symtab);
    DeRef(_sym);
    DeRef(_line_change);
    DeRef(_10322);
    DeRef(_10387);
    DeRef(_10331);
    DeRef(_10350);
    return 0;
    ;
}


int _21compress_symtab(int _symtab)
{
    int _sym = 0;
    int _st = 0;
    int _line_change = 0;
    int _len;
    int _old_file;
    int _void = 0;
    int _10450 = 0;
    int _10423 = 0;
    int _10416 = 0;
    int _0, _1, _2;
    

    // 	use_eval = find( 1, file_eval ) != 0 
    _10416 = find(1, _7file_eval);
    _7use_eval = (_10416 != 0);

    // 	st = MAGIC_NUMBER & SHROUD_VERSION & full_debug & use_eval
    {
        int concat_list[4];

        concat_list[0] = _7use_eval;
        concat_list[1] = _7full_debug;
        concat_list[2] = 3;
        concat_list[3] = _7MAGIC_NUMBER;
        Concat_N((object_ptr)&_st, concat_list, 4);
    }

    // 	st &= compress( length(symtab) )
    _10416 = SEQ_PTR(_symtab)->length;
    _10416 = _21compress(_10416);
    Concat((object_ptr)&_st, _st, (s1_ptr)_10416);

    // 	for s = 1 to length(symtab) do
    DeRefDS(_10416);
    _10416 = SEQ_PTR(_symtab)->length;
    { int _s;
        _s = 1;
L1:
        if (_s > _10416)
            goto L2;

        // 		sym = symtab[s]
        DeRef(_sym);
        _2 = (int)SEQ_PTR(_symtab);
        _sym = (int)*(((s1_ptr)_2)->base + _s);
        Ref(_sym);

        // 		len = length(sym)
        _len = SEQ_PTR(_sym)->length;

        // 		if len = 1 then
        if (_len != 1)
            goto L3;

        // 			st &= 0
        Append(&_st, _st, 0);
        goto L4;
L3:

        // 			st &= length(sym)
        DeRef(_10423);
        _10423 = SEQ_PTR(_sym)->length;
        Append(&_st, _st, _10423);

        // 			if len = 5 then
        if (_len != 5)
            goto L5;

        // 				st &= compress( sym[S_OBJ] )
        _2 = (int)SEQ_PTR(_sym);
        _10423 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10423);
        Ref(_10423);
        _0 = _10423;
        _10423 = _21compress(_10423);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);
        goto L6;
L5:

        // 			elsif sym[S_OBJ] != NOVALUE then
        DeRef(_10423);
        _2 = (int)SEQ_PTR(_sym);
        _10423 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10423);
        if (binary_op_a(EQUALS, _10423, _7NOVALUE))
            goto L7;

        // 				st &= 1 & compress( sym[S_OBJ] )
        DeRef(_10423);
        _2 = (int)SEQ_PTR(_sym);
        _10423 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10423);
        Ref(_10423);
        _0 = _10423;
        _10423 = _21compress(_10423);
        DeRef(_0);
        Prepend(&_10423, _10423, 1);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);
        goto L6;
L7:

        // 				st &= 0
        Append(&_st, _st, 0);
L6:

        // 			st &= compress( sym[S_NEXT] )
        DeRef(_10423);
        _2 = (int)SEQ_PTR(_sym);
        _10423 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10423);
        Ref(_10423);
        _0 = _10423;
        _10423 = _21compress(_10423);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);

        // 			st &= sym[S_MODE..S_SCOPE] 
        rhs_slice_target = (object_ptr)&_10423;
        RHS_Slice((s1_ptr)_sym, 3, 4);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);

        // 			if len > S_USAGE then
        if (_len <= 5)
            goto L8;

        // 				st &= sym[S_FILE_NO] 
        DeRefDS(_10423);
        _2 = (int)SEQ_PTR(_sym);
        _10423 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_10423);
        if (IS_SEQUENCE(_st) && IS_ATOM(_10423)) {
            Ref(_10423);
            Append(&_st, _st, _10423);
        }
        else if (IS_ATOM(_st) && IS_SEQUENCE(_10423)) {
        }
        else {
            Concat((object_ptr)&_st, _st, (s1_ptr)_10423);
        }

        // 				if full_debug or use_eval or len > S_VTYPE then
        if (_7full_debug != 0) {
            DeRef(_10423);
            _10423 = 1;
            goto L9;
        }
        _10423 = (_7use_eval != 0);
L9:
        if (_10423 != 0) {
            goto LA;
        }
        DeRef(_10450);
        _10450 = (_len > 14);
LB:
        if (_10450 == 0)
            goto LC;
LA:

        // 					st &= compress( sym[S_NAME] )
        DeRef(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);
LC:

        // 				st &= compress( sym[S_TOKEN] )
        DeRef(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 9);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 					st &= compress( sym[S_VTYPE] )
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 14);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 				if len > S_VTYPE then
        if (_len <= 14)
            goto LD;

        // 					st &= compress( sym[S_CODE] ) 
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 15);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 					st &= compress( sym[S_LINETAB] ) 
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 16);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 					st &= compress( sym[S_FIRSTLINE] )
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 17);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 					st &= compress( sym[S_TEMPS] )
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 18);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 					st &= sym[S_NUM_ARGS] 
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 20);
        Ref(_10450);
        if (IS_SEQUENCE(_st) && IS_ATOM(_10450)) {
            Ref(_10450);
            Append(&_st, _st, _10450);
        }
        else if (IS_ATOM(_st) && IS_SEQUENCE(_10450)) {
        }
        else {
            Concat((object_ptr)&_st, _st, (s1_ptr)_10450);
        }

        // 					st &= compress( sym[S_GOTO] )
        DeRef(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 24);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

        // 					st &= compress( sym[S_BYREF] )
        DeRefDS(_10450);
        _2 = (int)SEQ_PTR(_sym);
        _10450 = (int)*(((s1_ptr)_2)->base + 25);
        Ref(_10450);
        Ref(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10450);
LD:
L8:
L4:

        // 	end for
        _s = _s + 1;
        goto L1;
L2:
        ;
    }

    // 	st &= compress( file_name )
    RefDS(_7file_name);
    _0 = _10450;
    _10450 = _21compress(_7file_name);
    DeRef(_0);
    Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

    // 	if atom(slist[$]) then
    DeRefDS(_10450);
    _10450 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _10450 = (int)*(((s1_ptr)_2)->base + _10450);
    Ref(_10450);
    _0 = _10450;
    _10450 = IS_ATOM(_10450);
    DeRef(_0);
    if (_10450 == 0)
        goto LE;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _21s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;

    // 		slist = slist[1..$-1]
    _10450 = SEQ_PTR(_7slist)->length;
    _10450 = _10450 - 1;
    rhs_slice_target = (object_ptr)&_7slist;
    RHS_Slice((s1_ptr)_7slist, 1, _10450);
LE:

    // 	st &= compress( length(slist) )
    DeRef(_10450);
    _10450 = SEQ_PTR(_7slist)->length;
    _10450 = _21compress(_10450);
    Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

    // 	if full_debug then
    if (_7full_debug == 0)
        goto LF;

    // 		for i = 1 to length(slist) do
    DeRefDS(_10450);
    _10450 = SEQ_PTR(_7slist)->length;
    { int _i;
        _i = 1;
L10:
        if (_i > _10450)
            goto L11;

        // 			st &= compress( slist[i][1] )
        DeRef(_10423);
        _2 = (int)SEQ_PTR(_7slist);
        _10423 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10423);
        _0 = _10423;
        _2 = (int)SEQ_PTR(_10423);
        _10423 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10423);
        DeRef(_0);
        Ref(_10423);
        _0 = _10423;
        _10423 = _21compress(_10423);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);

        // 			st &= compress( slist[i][2] )
        DeRefDS(_10423);
        _2 = (int)SEQ_PTR(_7slist);
        _10423 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10423);
        _0 = _10423;
        _2 = (int)SEQ_PTR(_10423);
        _10423 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10423);
        DeRef(_0);
        Ref(_10423);
        _0 = _10423;
        _10423 = _21compress(_10423);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);

        // 			st &= compress( slist[i][3] )
        DeRefDS(_10423);
        _2 = (int)SEQ_PTR(_7slist);
        _10423 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10423);
        _0 = _10423;
        _2 = (int)SEQ_PTR(_10423);
        _10423 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10423);
        DeRef(_0);
        Ref(_10423);
        _0 = _10423;
        _10423 = _21compress(_10423);
        DeRef(_0);
        Concat((object_ptr)&_st, _st, (s1_ptr)_10423);

        // 		end for		
        _i = _i + 1;
        goto L10;
L11:
        ;
    }
    goto L12;
LF:

    // 		line_change = {}
    RefDS(_39);
    DeRef(_line_change);
    _line_change = _39;

    // 		old_file = slist[1][LOCAL_FILE_NO]
    DeRef(_10423);
    _2 = (int)SEQ_PTR(_7slist);
    _10423 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10423);
    _2 = (int)SEQ_PTR(_10423);
    _old_file = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_old_file))
        _old_file = (long)DBL_PTR(_old_file)->dbl;

    // 		len = 1
    _len = 1;

    // 		if atom(slist[$]) then
    DeRef(_10423);
    _10423 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _10423 = (int)*(((s1_ptr)_2)->base + _10423);
    Ref(_10423);
    _0 = _10423;
    _10423 = IS_ATOM(_10423);
    DeRef(_0);
    if (_10423 == 0)
        goto L13;

    // 			slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _21s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;

    // 			slist = slist[1..$-1]
    _10423 = SEQ_PTR(_7slist)->length;
    _10423 = _10423 - 1;
    rhs_slice_target = (object_ptr)&_7slist;
    RHS_Slice((s1_ptr)_7slist, 1, _10423);
L13:

    // 		for i = 1 to length(slist) do
    DeRef(_10423);
    _10423 = SEQ_PTR(_7slist)->length;
    { int _i;
        _i = 1;
L14:
        if (_i > _10423)
            goto L15;

        // 		void = slist[i]
        DeRef(_void);
        _2 = (int)SEQ_PTR(_7slist);
        _void = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_void);

        // 			if old_file != slist[i][LOCAL_FILE_NO] then
        DeRef(_10450);
        _2 = (int)SEQ_PTR(_7slist);
        _10450 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10450);
        _0 = _10450;
        _2 = (int)SEQ_PTR(_10450);
        _10450 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10450);
        DeRef(_0);
        if (binary_op_a(EQUALS, _old_file, _10450))
            goto L16;

        // 				old_file = slist[i][LOCAL_FILE_NO]
        DeRef(_10450);
        _2 = (int)SEQ_PTR(_7slist);
        _10450 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10450);
        _2 = (int)SEQ_PTR(_10450);
        _old_file = (int)*(((s1_ptr)_2)->base + 3);
        if (!IS_ATOM_INT(_old_file))
            _old_file = (long)DBL_PTR(_old_file)->dbl;

        // 				line_change &= compress( old_file & i )
        Concat((object_ptr)&_10450, _old_file, (s1_ptr)_i);
        RefDS(_10450);
        _0 = _10450;
        _10450 = _21compress(_10450);
        DeRefDSi(_0);
        Concat((object_ptr)&_line_change, _line_change, (s1_ptr)_10450);

        // 				len += 1
        _len = _len + 1;
L16:

        // 		end for
        _i = _i + 1;
        goto L14;
L15:
        ;
    }

    // 		line_change &= compress( old_file & length(slist))
    DeRef(_10450);
    _10450 = SEQ_PTR(_7slist)->length;
    Concat((object_ptr)&_10450, _old_file, (s1_ptr)_10450);
    RefDS(_10450);
    _0 = _10450;
    _10450 = _21compress(_10450);
    DeRefDSi(_0);
    Concat((object_ptr)&_line_change, _line_change, (s1_ptr)_10450);

    // 		st &= compress( len )
    _0 = _10450;
    _10450 = _21compress(_len);
    DeRefDS(_0);
    Concat((object_ptr)&_st, _st, (s1_ptr)_10450);

    // 		st &= line_change
    Concat((object_ptr)&_st, _st, (s1_ptr)_line_change);
L12:

    // 	return st
    DeRefDS(_symtab);
    DeRef(_sym);
    DeRef(_line_change);
    DeRef(_void);
    DeRef(_10450);
    DeRef(_10423);
    DeRef(_10416);
    return _st;
    ;
}


