// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _4allocate(int _n)
{
    int _304 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_n)) {
        _1 = (long)(DBL_PTR(_n)->dbl);
        DeRefDS(_n);
        _n = _1;
    }

    //     return machine_func(M_ALLOC, n)
    _304 = machine(16, _n);
    return _304;
    ;
}


int _4free(int _a)
{
    int _0, _1, _2;
    

    //     machine_proc(M_FREE, a)
    machine(17, _a);

    // end procedure
    DeRef(_a);
    return 0;
    ;
}


int _4allocate_low(int _n)
{
    int _305;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_n)) {
        _1 = (long)(DBL_PTR(_n)->dbl);
        DeRefDS(_n);
        _n = _1;
    }

    //     return machine_func(M_ALLOC_LOW, n)
    _305 = machine(32, _n);
    return _305;
    ;
}


int _4free_low(int _a)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_a)) {
        _1 = (long)(DBL_PTR(_a)->dbl);
        DeRefDS(_a);
        _a = _1;
    }

    //     machine_proc(M_FREE_LOW, a)
    machine(33, _a);

    // end procedure
    return 0;
    ;
}


int _4dos_interrupt(int _int_num, int _input_regs)
{
    int _306 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_int_num)) {
        _1 = (long)(DBL_PTR(_int_num)->dbl);
        DeRefDS(_int_num);
        _int_num = _1;
    }

    //     return machine_func(M_INTERRUPT, {int_num, input_regs})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _int_num;
    ((int *)_2)[2] = _input_regs;
    RefDS(_input_regs);
    _306 = MAKE_SEQ(_1);
    _0 = _306;
    _306 = machine(34, _306);
    DeRefDS(_0);
    DeRefDS(_input_regs);
    return _306;
    ;
}


int _4int_to_bytes(int _x)
{
    int _a;
    int _b;
    int _c;
    int _d;
    int _309 = 0;
    int _0, _1, _2;
    

    //     a = remainder(x, #100)
    if (IS_ATOM_INT(_x)) {
        _a = (_x % 256);
    }
    else {
        temp_d.dbl = (double)256;
        _a = Dremainder(DBL_PTR(_x), &temp_d);
    }
    if (!IS_ATOM_INT(_a)) {
        _1 = (long)(DBL_PTR(_a)->dbl);
        DeRefDS(_a);
        _a = _1;
    }

    //     x = floor(x / #100)
    _0 = _x;
    if (IS_ATOM_INT(_x)) {
        if (256 > 0 && _x >= 0) {
            _x = _x / 256;
        }
        else {
            temp_dbl = floor((double)_x / (double)256);
            if (_x != MININT)
                _x = (long)temp_dbl;
            else
                _x = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _x, 256);
        _x = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);

    //     b = remainder(x, #100)
    if (IS_ATOM_INT(_x)) {
        _b = (_x % 256);
    }
    else {
        temp_d.dbl = (double)256;
        _b = Dremainder(DBL_PTR(_x), &temp_d);
    }
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    //     x = floor(x / #100)
    _0 = _x;
    if (IS_ATOM_INT(_x)) {
        if (256 > 0 && _x >= 0) {
            _x = _x / 256;
        }
        else {
            temp_dbl = floor((double)_x / (double)256);
            if (_x != MININT)
                _x = (long)temp_dbl;
            else
                _x = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _x, 256);
        _x = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);

    //     c = remainder(x, #100)
    if (IS_ATOM_INT(_x)) {
        _c = (_x % 256);
    }
    else {
        temp_d.dbl = (double)256;
        _c = Dremainder(DBL_PTR(_x), &temp_d);
    }
    if (!IS_ATOM_INT(_c)) {
        _1 = (long)(DBL_PTR(_c)->dbl);
        DeRefDS(_c);
        _c = _1;
    }

    //     x = floor(x / #100)
    _0 = _x;
    if (IS_ATOM_INT(_x)) {
        if (256 > 0 && _x >= 0) {
            _x = _x / 256;
        }
        else {
            temp_dbl = floor((double)_x / (double)256);
            if (_x != MININT)
                _x = (long)temp_dbl;
            else
                _x = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _x, 256);
        _x = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);

    //     d = remainder(x, #100)
    if (IS_ATOM_INT(_x)) {
        _d = (_x % 256);
    }
    else {
        temp_d.dbl = (double)256;
        _d = Dremainder(DBL_PTR(_x), &temp_d);
    }
    if (!IS_ATOM_INT(_d)) {
        _1 = (long)(DBL_PTR(_d)->dbl);
        DeRefDS(_d);
        _d = _1;
    }

    //     return {a,b,c,d}
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _a;
    *((int *)(_2+8)) = _b;
    *((int *)(_2+12)) = _c;
    *((int *)(_2+16)) = _d;
    _309 = MAKE_SEQ(_1);
    DeRef(_x);
    return _309;
    ;
}


int _4bytes_to_int(int _s)
{
    int _318 = 0;
    int _0, _1, _2;
    

    //     if length(s) = 4 then
    _318 = SEQ_PTR(_s)->length;
    if (_318 != 4)
        goto L1;

    // 	poke(mem, s)
    if (IS_ATOM_INT(_4mem))
        poke_addr = (unsigned char *)_4mem;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_4mem)->dbl);
    _1 = (int)SEQ_PTR(_s);
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
    goto L2;
L1:

    // 	poke(mem, s[1..4]) -- avoid breaking old code
    rhs_slice_target = (object_ptr)&_318;
    RHS_Slice((s1_ptr)_s, 1, 4);
    if (IS_ATOM_INT(_4mem))
        poke_addr = (unsigned char *)_4mem;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_4mem)->dbl);
    _1 = (int)SEQ_PTR(_318);
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
L2:

    //     return peek4u(mem)
    DeRef(_318);
    if (IS_ATOM_INT(_4mem)) {
        _318 = *(unsigned long *)_4mem;
        if ((unsigned)_318 > (unsigned)MAXINT)
            _318 = NewDouble((double)(unsigned long)_318);
    }
    else {
        _318 = *(unsigned long *)(unsigned long)(DBL_PTR(_4mem)->dbl);
        if ((unsigned)_318 > (unsigned)MAXINT)
            _318 = NewDouble((double)(unsigned long)_318);
    }
    DeRefDS(_s);
    return _318;
    ;
}


int _4int_to_bits(int _x, int _nbits)
{
    int _bits = 0;
    int _mask;
    int _326 = 0;
    int _322 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_nbits)) {
        _1 = (long)(DBL_PTR(_nbits)->dbl);
        DeRefDS(_nbits);
        _nbits = _1;
    }

    //     bits = repeat(0, nbits)
    _bits = Repeat(0, _nbits);

    //     if integer(x) and nbits < 30 then
    if (IS_ATOM_INT(_x))
        _322 = 1;
    else if (IS_ATOM_DBL(_x))
        _322 = IS_ATOM_INT(DoubleToInt(_x));
    else
        _322 = 0;
    if (_322 == 0) {
        goto L1;
    }
    _326 = (_nbits < 30);
L2:
    if (_326 == 0)
        goto L1;

    // 	mask = 1
    _mask = 1;

    // 	for i = 1 to nbits do
    DeRef(_326);
    _326 = _nbits;
    { int _i;
        _i = 1;
L3:
        if (_i > _326)
            goto L4;

        // 	    bits[i] = and_bits(x, mask) and 1
        DeRef(_322);
        if (IS_ATOM_INT(_x)) {
            _322 = (_x & _mask);
        }
        else {
            temp_d.dbl = (double)_mask;
            _322 = Dand_bits(DBL_PTR(_x), &temp_d);
        }
        _0 = _322;
        if (IS_ATOM_INT(_322)) {
            _322 = (_322 != 0 && 1 != 0);
        }
        else {
            temp_d.dbl = (double)1;
            _322 = Dand(DBL_PTR(_322), &temp_d);
        }
        DeRef(_0);
        _2 = (int)SEQ_PTR(_bits);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _bits = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _322;
        DeRef(_1);

        // 	    mask *= 2
        _mask = _mask + _mask;

        // 	end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }
    goto L5;
L1:

    // 	if x < 0 then
    if (binary_op_a(GREATEREQ, _x, 0))
        goto L6;

    // 	    x += power(2, nbits) -- for 2's complement bit pattern
    DeRef(_322);
    _322 = power(2, _nbits);
    _0 = _x;
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_322)) {
        _x = _x + _322;
        if ((long)((unsigned long)_x + (unsigned long)HIGH_BITS) >= 0) 
            _x = NewDouble((double)_x);
    }
    else {
        if (IS_ATOM_INT(_x)) {
            _x = NewDouble((double)_x + DBL_PTR(_322)->dbl);
        }
        else {
            if (IS_ATOM_INT(_322)) {
                _x = NewDouble(DBL_PTR(_x)->dbl + (double)_322);
            }
            else
                _x = NewDouble(DBL_PTR(_x)->dbl + DBL_PTR(_322)->dbl);
        }
    }
    DeRef(_0);
L6:

    // 	for i = 1 to nbits do
    DeRef(_322);
    _322 = _nbits;
    { int _i;
        _i = 1;
L7:
        if (_i > _322)
            goto L8;

        // 	    bits[i] = remainder(x, 2) 
        DeRef(_326);
        if (IS_ATOM_INT(_x)) {
            _326 = (_x % 2);
        }
        else {
            temp_d.dbl = (double)2;
            _326 = Dremainder(DBL_PTR(_x), &temp_d);
        }
        Ref(_326);
        _2 = (int)SEQ_PTR(_bits);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _bits = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _326;
        DeRef(_1);

        // 	    x = floor(x / 2)
        _0 = _x;
        if (IS_ATOM_INT(_x)) {
            _x = _x >> 1;
        }
        else {
            _1 = binary_op(DIVIDE, _x, 2);
            _x = unary_op(FLOOR, _1);
            DeRef(_1);
        }
        DeRef(_0);

        // 	end for
        _i = _i + 1;
        goto L7;
L8:
        ;
    }
L5:

    //     return bits
    DeRef(_x);
    DeRef(_326);
    DeRef(_322);
    return _bits;
    ;
}


int _4bits_to_int(int _bits)
{
    int _value = 0;
    int _p = 0;
    int _338 = 0;
    int _337;
    int _0, _1, _2;
    

    //     value = 0
    _value = 0;

    //     p = 1
    _p = 1;

    //     for i = 1 to length(bits) do
    _337 = SEQ_PTR(_bits)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _337)
            goto L2;

        // 	if bits[i] then
        DeRef(_338);
        _2 = (int)SEQ_PTR(_bits);
        _338 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_338);
        if (_338 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_338) && DBL_PTR(_338)->dbl == 0.0)
                goto L3;
        }

        // 	    value += p
        _0 = _value;
        if (IS_ATOM_INT(_value) && IS_ATOM_INT(_p)) {
            _value = _value + _p;
            if ((long)((unsigned long)_value + (unsigned long)HIGH_BITS) >= 0) 
                _value = NewDouble((double)_value);
        }
        else {
            if (IS_ATOM_INT(_value)) {
                _value = NewDouble((double)_value + DBL_PTR(_p)->dbl);
            }
            else {
                if (IS_ATOM_INT(_p)) {
                    _value = NewDouble(DBL_PTR(_value)->dbl + (double)_p);
                }
                else
                    _value = NewDouble(DBL_PTR(_value)->dbl + DBL_PTR(_p)->dbl);
            }
        }
        DeRef(_0);
L3:

        // 	p += p
        _0 = _p;
        if (IS_ATOM_INT(_p) && IS_ATOM_INT(_p)) {
            _p = _p + _p;
            if ((long)((unsigned long)_p + (unsigned long)HIGH_BITS) >= 0) 
                _p = NewDouble((double)_p);
        }
        else {
            if (IS_ATOM_INT(_p)) {
                _p = NewDouble((double)_p + DBL_PTR(_p)->dbl);
            }
            else {
                if (IS_ATOM_INT(_p)) {
                    _p = NewDouble(DBL_PTR(_p)->dbl + (double)_p);
                }
                else
                    _p = NewDouble(DBL_PTR(_p)->dbl + DBL_PTR(_p)->dbl);
            }
        }
        DeRef(_0);

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return value
    DeRefDS(_bits);
    DeRef(_p);
    DeRef(_338);
    return _value;
    ;
}


int _4set_rand(int _seed)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_seed)) {
        _1 = (long)(DBL_PTR(_seed)->dbl);
        DeRefDS(_seed);
        _seed = _1;
    }

    //     machine_proc(M_SET_RAND, seed)
    machine(35, _seed);

    // end procedure
    return 0;
    ;
}


int _4use_vesa(int _code)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_code)) {
        _1 = (long)(DBL_PTR(_code)->dbl);
        DeRefDS(_code);
        _code = _1;
    }

    //     machine_proc(M_USE_VESA, code)
    machine(36, _code);

    // end procedure
    return 0;
    ;
}


int _4crash_message(int _msg)
{
    int _0, _1, _2;
    

    //     machine_proc(M_CRASH_MESSAGE, msg)
    machine(37, _msg);

    // end procedure
    DeRefDS(_msg);
    return 0;
    ;
}


int _4crash_file(int _file_path)
{
    int _0, _1, _2;
    

    //     machine_proc(M_CRASH_FILE, file_path)
    machine(57, _file_path);

    // end procedure
    DeRefDS(_file_path);
    return 0;
    ;
}


int _4crash_routine(int _proc)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }

    //     machine_proc(M_CRASH_ROUTINE, proc)
    machine(66, _proc);

    // end procedure
    return 0;
    ;
}


int _4tick_rate(int _rate)
{
    int _0, _1, _2;
    

    //     machine_proc(M_TICK_RATE, rate)
    machine(38, _rate);

    // end procedure
    DeRef(_rate);
    return 0;
    ;
}


int _4get_vector(int _int_num)
{
    int _341 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_int_num)) {
        _1 = (long)(DBL_PTR(_int_num)->dbl);
        DeRefDS(_int_num);
        _int_num = _1;
    }

    //     return machine_func(M_GET_VECTOR, int_num)
    _341 = machine(39, _int_num);
    return _341;
    ;
}


int _4set_vector(int _int_num, int _a)
{
    int _342 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_int_num)) {
        _1 = (long)(DBL_PTR(_int_num)->dbl);
        DeRefDS(_int_num);
        _int_num = _1;
    }

    //     machine_proc(M_SET_VECTOR, {int_num, a})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _int_num;
    ((int *)_2)[2] = _a;
    RefDS(_a);
    _342 = MAKE_SEQ(_1);
    machine(40, _342);

    // end procedure
    DeRefDS(_a);
    DeRefDS(_342);
    return 0;
    ;
}


int _4lock_memory(int _a, int _n)
{
    int _343 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_n)) {
        _1 = (long)(DBL_PTR(_n)->dbl);
        DeRefDS(_n);
        _n = _1;
    }

    //     machine_proc(M_LOCK_MEMORY, {a, n})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _a;
    Ref(_a);
    ((int *)_2)[2] = _n;
    _343 = MAKE_SEQ(_1);
    machine(41, _343);

    // end procedure
    DeRef(_a);
    DeRefDS(_343);
    return 0;
    ;
}


int _4atom_to_float64(int _a)
{
    int _344 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_A_TO_F64, a)
    _344 = machine(46, _a);
    DeRef(_a);
    return _344;
    ;
}


int _4atom_to_float32(int _a)
{
    int _345 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_A_TO_F32, a)
    _345 = machine(48, _a);
    DeRef(_a);
    return _345;
    ;
}


int _4float64_to_atom(int _ieee64)
{
    int _346 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_F64_TO_A, ieee64)
    _346 = machine(47, _ieee64);
    DeRefDS(_ieee64);
    return _346;
    ;
}


int _4float32_to_atom(int _ieee32)
{
    int _347 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_F32_TO_A, ieee32)
    _347 = machine(49, _ieee32);
    DeRefDS(_ieee32);
    return _347;
    ;
}


int _4allocate_string(int _s)
{
    int _mem = 0;
    int _348 = 0;
    int _0, _1, _2;
    

    //     mem = machine_func(M_ALLOC, length(s) + 1) -- Thanks to Igor
    _348 = SEQ_PTR(_s)->length;
    _348 = _348 + 1;
    _mem = machine(16, _348);

    //     if mem then
    if (_mem == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_mem) && DBL_PTR(_mem)->dbl == 0.0)
            goto L1;
    }

    // 	poke(mem, s)
    if (IS_ATOM_INT(_mem))
        poke_addr = (unsigned char *)_mem;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_mem)->dbl);
    _1 = (int)SEQ_PTR(_s);
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

    // 	poke(mem+length(s), 0)  -- Thanks to Aku
    _348 = SEQ_PTR(_s)->length;
    if (IS_ATOM_INT(_mem)) {
        _348 = _mem + _348;
        if ((long)((unsigned long)_348 + (unsigned long)HIGH_BITS) >= 0) 
            _348 = NewDouble((double)_348);
    }
    else {
        _348 = NewDouble(DBL_PTR(_mem)->dbl + (double)_348);
    }
    if (IS_ATOM_INT(_348))
        poke_addr = (unsigned char *)_348;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_348)->dbl);
    *poke_addr = (unsigned char)0;
L1:

    //     return mem
    DeRefDS(_s);
    DeRef(_348);
    return _mem;
    ;
}


int _4register_block(int _block_addr, int _block_len)
{
    int _0, _1, _2;
    

    // end procedure
    DeRef(_block_addr);
    DeRef(_block_len);
    return 0;
    ;
}


int _4unregister_block(int _block_addr)
{
    int _0, _1, _2;
    

    // end procedure
    DeRef(_block_addr);
    return 0;
    ;
}


int _4check_all_blocks()
{
    int _0, _1, _2;
    

    // end procedure
    return 0;
    ;
}


