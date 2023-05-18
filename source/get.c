// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _20wait_key()
{
    int _7027;
    int _0, _1, _2;
    

    //     return machine_func(M_WAIT_KEY, 0)
    _7027 = machine(26, 0);
    return _7027;
    ;
}


int _20get_ch()
{
    int _7028;
    int _0, _1, _2;
    

    //     if sequence(input_string) then
    _7028 = IS_SEQUENCE(_20input_string);
    if (_7028 == 0)
        goto L1;

    // 	if string_next <= length(input_string) then
    _7028 = SEQ_PTR(_20input_string)->length;
    if (_20string_next > _7028)
        goto L2;

    // 	    ch = input_string[string_next]
    _2 = (int)SEQ_PTR(_20input_string);
    _20ch = (int)*(((s1_ptr)_2)->base + _20string_next);
    if (!IS_ATOM_INT(_20ch))
        _20ch = (long)DBL_PTR(_20ch)->dbl;

    // 	    string_next += 1
    _20string_next = _20string_next + 1;
    goto L3;
L2:

    // 	    ch = GET_EOF
    _20ch = -1;
L4:
    goto L3;
L1:

    // 	ch = getc(input_file)
    if (_20input_file != last_r_file_no) {
        last_r_file_ptr = which_file(_20input_file, EF_READ);
        last_r_file_no = _20input_file;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _20ch = getc(xstdin);
        }
        else
            _20ch = getc(last_r_file_ptr);
    }
    else
        _20ch = getc(last_r_file_ptr);
L3:

    // end procedure
    return 0;
    ;
}


int _20skip_blanks()
{
    int _7035;
    int _0, _1, _2;
    

    //     while find(ch, " \t\n\r") do
L1:
    _7035 = find(_20ch, _7034);
    if (_7035 == 0)
        goto L2;

    // 	get_ch()
    _20get_ch();

    //     end while
    goto L1;
L2:

    // end procedure
    return 0;
    ;
}


int _20escape_char(int _c)
{
    int _i;
    int _7038;
    int _0, _1, _2;
    

    //     i = find(c, ESCAPE_CHARS)
    _i = find(_c, _20ESCAPE_CHARS);

    //     if i = 0 then
    if (_i != 0)
        goto L1;

    // 	return GET_FAIL
    return 1;
    goto L2;
L1:

    // 	return ESCAPED_CHARS[i]
    _2 = (int)SEQ_PTR(_20ESCAPED_CHARS);
    _7038 = (int)*(((s1_ptr)_2)->base + _i);
    return _7038;
L2:
    ;
}


int _20get_qchar()
{
    int _c;
    int _7041 = 0;
    int _0, _1, _2;
    

    //     get_ch()
    _20get_ch();

    //     c = ch
    _c = _20ch;

    //     if ch = '\\' then
    if (_20ch != 92)
        goto L1;

    // 	get_ch()
    _20get_ch();

    // 	c = escape_char(ch)
    _c = _20escape_char(_20ch);

    // 	if c = GET_FAIL then
    if (_c != 1)
        goto L2;

    // 	    return {GET_FAIL, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7041 = MAKE_SEQ(_1);
    return _7041;
L3:
    goto L2;
L1:

    //     elsif ch = '\'' then
    if (_20ch != 39)
        goto L4;

    // 	return {GET_FAIL, 0}
    DeRef(_7041);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7041 = MAKE_SEQ(_1);
    return _7041;
L4:
L2:

    //     get_ch()
    _20get_ch();

    //     if ch != '\'' then
    if (_20ch == 39)
        goto L5;

    // 	return {GET_FAIL, 0}
    DeRef(_7041);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7041 = MAKE_SEQ(_1);
    return _7041;
    goto L6;
L5:

    // 	get_ch()
    _20get_ch();

    // 	return {GET_SUCCESS, c}
    DeRef(_7041);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _c;
    _7041 = MAKE_SEQ(_1);
    return _7041;
L6:
    ;
}


int _20get_string()
{
    int _text = 0;
    int _7052 = 0;
    int _7050;
    int _0, _1, _2;
    

    //     text = ""
    RefDS(_39);
    _text = _39;

    //     while TRUE do
L1:

    // 	get_ch()
    _20get_ch();

    // 	if ch = GET_EOF or ch = '\n' then
    _7050 = (_20ch == -1);
    if (_7050 != 0) {
        goto L2;
    }
    DeRef(_7052);
    _7052 = (_20ch == 10);
L3:
    if (_7052 == 0)
        goto L4;
L2:

    // 	    return {GET_FAIL, 0}
    DeRef(_7052);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7052 = MAKE_SEQ(_1);
    DeRefi(_text);
    return _7052;
    goto L5;
L4:

    // 	elsif ch = '"' then
    if (_20ch != 34)
        goto L6;

    // 	    get_ch()
    _20get_ch();

    // 	    return {GET_SUCCESS, text}
    DeRef(_7052);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _text;
    RefDS(_text);
    _7052 = MAKE_SEQ(_1);
    DeRefDSi(_text);
    return _7052;
    goto L5;
L6:

    // 	elsif ch = '\\' then
    if (_20ch != 92)
        goto L7;

    // 	    get_ch()
    _20get_ch();

    // 	    ch = escape_char(ch)
    _0 = _20escape_char(_20ch);
    _20ch = _0;

    // 	    if ch = GET_FAIL then
    if (_20ch != 1)
        goto L8;

    // 		return {GET_FAIL, 0}
    DeRef(_7052);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7052 = MAKE_SEQ(_1);
    DeRefi(_text);
    return _7052;
L8:
L7:
L5:

    // 	text = text & ch
    Append(&_text, _text, _20ch);

    //     end while
    goto L1;
L9:
    ;
}


int _20get_number()
{
    int _sign;
    int _e_sign;
    int _ndigits;
    int _hex_digit;
    int _mantissa = 0;
    int _dec = 0;
    int _e_mag = 0;
    int _7079 = 0;
    int _7064 = 0;
    int _0, _1, _2;
    

    //     sign = +1
    _sign = 1;

    //     mantissa = 0
    _mantissa = 0;

    //     ndigits = 0
    _ndigits = 0;

    //     if ch = '-' then
    if (_20ch != 45)
        goto L1;

    // 	sign = -1
    _sign = -1;

    // 	get_ch()
    _20get_ch();
    goto L2;
L1:

    //     elsif ch = '+' then
    if (_20ch != 43)
        goto L3;

    // 	get_ch()
    _20get_ch();
L3:
L2:

    //     if ch = '#' then
    if (_20ch != 35)
        goto L4;

    // 	get_ch()
    _20get_ch();

    // 	while TRUE do
L5:

    // 	    hex_digit = find(ch, HEX_DIGITS)-1
    DeRef(_7064);
    _7064 = find(_20ch, _20HEX_DIGITS);
    _hex_digit = _7064 - 1;

    // 	    if hex_digit >= 0 then
    if (_hex_digit < 0)
        goto L6;

    // 		ndigits += 1
    _ndigits = _ndigits + 1;

    // 		mantissa = mantissa * 16 + hex_digit
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa == (short)_mantissa)
            _7064 = _mantissa * 16;
        else
            _7064 = NewDouble(_mantissa * (double)16);
    }
    else {
        _7064 = NewDouble(DBL_PTR(_mantissa)->dbl * (double)16);
    }
    DeRef(_mantissa);
    if (IS_ATOM_INT(_7064)) {
        _mantissa = _7064 + _hex_digit;
        if ((long)((unsigned long)_mantissa + (unsigned long)HIGH_BITS) >= 0) 
            _mantissa = NewDouble((double)_mantissa);
    }
    else {
        _mantissa = NewDouble(DBL_PTR(_7064)->dbl + (double)_hex_digit);
    }

    // 		get_ch()
    _20get_ch();
    goto L5;
L6:

    // 		if ndigits > 0 then
    if (_ndigits <= 0)
        goto L7;

    // 		    return {GET_SUCCESS, sign * mantissa}
    DeRef(_7064);
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa <= INT15 && _mantissa >= -INT15)
            _7064 = _sign * _mantissa;
        else
            _7064 = NewDouble(_sign * (double)_mantissa);
    }
    else {
        _7064 = NewDouble((double)_sign * DBL_PTR(_mantissa)->dbl);
    }
    _0 = _7064;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _7064;
    Ref(_7064);
    _7064 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_7079);
    return _7064;
    goto L5;
L7:

    // 		    return {GET_FAIL, 0}
    DeRef(_7064);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7064 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_7079);
    return _7064;
L8:
L9:

    // 	end while       
    goto L5;
LA:
L4:

    //     while ch >= '0' and ch <= '9' do
LB:
    DeRef(_7064);
    _7064 = (_20ch >= 48);
    if (_7064 == 0) {
        goto LC;
    }
    DeRef(_7079);
    _7079 = (_20ch <= 57);
LD:
    if (_7079 == 0)
        goto LC;

    // 	ndigits += 1
    _ndigits = _ndigits + 1;

    // 	mantissa = mantissa * 10 + (ch - '0')
    DeRef(_7079);
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa == (short)_mantissa)
            _7079 = _mantissa * 10;
        else
            _7079 = NewDouble(_mantissa * (double)10);
    }
    else {
        _7079 = NewDouble(DBL_PTR(_mantissa)->dbl * (double)10);
    }
    DeRef(_7064);
    _7064 = _20ch - 48;
    if ((long)((unsigned long)_7064 +(unsigned long) HIGH_BITS) >= 0)
        _7064 = NewDouble((double)_7064);
    DeRef(_mantissa);
    if (IS_ATOM_INT(_7079) && IS_ATOM_INT(_7064)) {
        _mantissa = _7079 + _7064;
        if ((long)((unsigned long)_mantissa + (unsigned long)HIGH_BITS) >= 0) 
            _mantissa = NewDouble((double)_mantissa);
    }
    else {
        if (IS_ATOM_INT(_7079)) {
            _mantissa = NewDouble((double)_7079 + DBL_PTR(_7064)->dbl);
        }
        else {
            if (IS_ATOM_INT(_7064)) {
                _mantissa = NewDouble(DBL_PTR(_7079)->dbl + (double)_7064);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_7079)->dbl + DBL_PTR(_7064)->dbl);
        }
    }

    // 	get_ch()
    _20get_ch();

    //     end while
    goto LB;
LC:

    //     if ch = '.' then
    if (_20ch != 46)
        goto LE;

    // 	get_ch()
    _20get_ch();

    // 	dec = 10
    DeRef(_dec);
    _dec = 10;

    // 	while ch >= '0' and ch <= '9' do
LF:
    DeRef(_7064);
    _7064 = (_20ch >= 48);
    if (_7064 == 0) {
        goto L10;
    }
    DeRef(_7079);
    _7079 = (_20ch <= 57);
L11:
    if (_7079 == 0)
        goto L10;

    // 	    ndigits += 1
    _ndigits = _ndigits + 1;

    // 	    mantissa += (ch - '0') / dec
    DeRef(_7079);
    _7079 = _20ch - 48;
    if ((long)((unsigned long)_7079 +(unsigned long) HIGH_BITS) >= 0)
        _7079 = NewDouble((double)_7079);
    _0 = _7079;
    if (IS_ATOM_INT(_7079) && IS_ATOM_INT(_dec)) {
        _7079 = (_7079 % _dec) ? NewDouble((double)_7079 / _dec) : (_7079 / _dec);
    }
    else {
        if (IS_ATOM_INT(_7079)) {
            _7079 = NewDouble((double)_7079 / DBL_PTR(_dec)->dbl);
        }
        else {
            if (IS_ATOM_INT(_dec)) {
                _7079 = NewDouble(DBL_PTR(_7079)->dbl / (double)_dec);
            }
            else
                _7079 = NewDouble(DBL_PTR(_7079)->dbl / DBL_PTR(_dec)->dbl);
        }
    }
    DeRef(_0);
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa) && IS_ATOM_INT(_7079)) {
        _mantissa = _mantissa + _7079;
        if ((long)((unsigned long)_mantissa + (unsigned long)HIGH_BITS) >= 0) 
            _mantissa = NewDouble((double)_mantissa);
    }
    else {
        if (IS_ATOM_INT(_mantissa)) {
            _mantissa = NewDouble((double)_mantissa + DBL_PTR(_7079)->dbl);
        }
        else {
            if (IS_ATOM_INT(_7079)) {
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl + (double)_7079);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl + DBL_PTR(_7079)->dbl);
        }
    }
    DeRef(_0);

    // 	    dec *= 10
    _0 = _dec;
    if (IS_ATOM_INT(_dec)) {
        if (_dec == (short)_dec)
            _dec = _dec * 10;
        else
            _dec = NewDouble(_dec * (double)10);
    }
    else {
        _dec = NewDouble(DBL_PTR(_dec)->dbl * (double)10);
    }
    DeRef(_0);

    // 	    get_ch()
    _20get_ch();

    // 	end while
    goto LF;
L10:
LE:

    //     if ndigits = 0 then
    if (_ndigits != 0)
        goto L12;

    // 	return {GET_FAIL, 0}
    DeRef(_7079);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7079 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_7064);
    return _7079;
L12:

    //     mantissa = sign * mantissa
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa <= INT15 && _mantissa >= -INT15)
            _mantissa = _sign * _mantissa;
        else
            _mantissa = NewDouble(_sign * (double)_mantissa);
    }
    else {
        _mantissa = NewDouble((double)_sign * DBL_PTR(_mantissa)->dbl);
    }
    DeRef(_0);

    //     if ch = 'e' or ch = 'E' then
    DeRef(_7079);
    _7079 = (_20ch == 101);
    if (_7079 != 0) {
        goto L13;
    }
    DeRef(_7064);
    _7064 = (_20ch == 69);
L14:
    if (_7064 == 0)
        goto L15;
L13:

    // 	e_sign = +1
    _e_sign = 1;

    // 	e_mag = 0
    DeRef(_e_mag);
    _e_mag = 0;

    // 	get_ch()
    _20get_ch();

    // 	if ch = '-' then
    if (_20ch != 45)
        goto L16;

    // 	    e_sign = -1
    _e_sign = -1;

    // 	    get_ch()
    _20get_ch();
    goto L17;
L16:

    // 	elsif ch = '+' then
    if (_20ch != 43)
        goto L18;

    // 	    get_ch()
    _20get_ch();
L18:
L17:

    // 	if ch >= '0' and ch <= '9' then
    DeRef(_7064);
    _7064 = (_20ch >= 48);
    if (_7064 == 0) {
        goto L19;
    }
    DeRef(_7079);
    _7079 = (_20ch <= 57);
L1A:
    if (_7079 == 0)
        goto L19;

    // 	    e_mag = ch - '0'
    DeRef(_e_mag);
    _e_mag = _20ch - 48;
    if ((long)((unsigned long)_e_mag +(unsigned long) HIGH_BITS) >= 0)
        _e_mag = NewDouble((double)_e_mag);

    // 	    get_ch()
    _20get_ch();

    // 	    while ch >= '0' and ch <= '9' do
L1B:
    DeRef(_7079);
    _7079 = (_20ch >= 48);
    if (_7079 == 0) {
        goto L1C;
    }
    DeRef(_7064);
    _7064 = (_20ch <= 57);
L1D:
    if (_7064 == 0)
        goto L1C;

    // 		e_mag = e_mag * 10 + ch - '0'
    DeRef(_7064);
    if (IS_ATOM_INT(_e_mag)) {
        if (_e_mag == (short)_e_mag)
            _7064 = _e_mag * 10;
        else
            _7064 = NewDouble(_e_mag * (double)10);
    }
    else {
        _7064 = NewDouble(DBL_PTR(_e_mag)->dbl * (double)10);
    }
    _0 = _7064;
    if (IS_ATOM_INT(_7064)) {
        _7064 = _7064 + _20ch;
        if ((long)((unsigned long)_7064 + (unsigned long)HIGH_BITS) >= 0) 
            _7064 = NewDouble((double)_7064);
    }
    else {
        _7064 = NewDouble(DBL_PTR(_7064)->dbl + (double)_20ch);
    }
    DeRef(_0);
    DeRef(_e_mag);
    if (IS_ATOM_INT(_7064)) {
        _e_mag = _7064 - 48;
        if ((long)((unsigned long)_e_mag +(unsigned long) HIGH_BITS) >= 0)
            _e_mag = NewDouble((double)_e_mag);
    }
    else {
        _e_mag = NewDouble(DBL_PTR(_7064)->dbl - (double)48);
    }

    // 		get_ch()                          
    _20get_ch();

    // 	    end while
    goto L1B;
L1E:
    goto L1C;
L19:

    // 	    return {GET_FAIL, 0} -- no exponent
    DeRef(_7064);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7064 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_7079);
    return _7064;
L1C:

    // 	e_mag *= e_sign 
    _0 = _e_mag;
    if (IS_ATOM_INT(_e_mag)) {
        if (_e_mag == (short)_e_mag)
            _e_mag = _e_mag * _e_sign;
        else
            _e_mag = NewDouble(_e_mag * (double)_e_sign);
    }
    else {
        _e_mag = NewDouble(DBL_PTR(_e_mag)->dbl * (double)_e_sign);
    }
    DeRef(_0);

    // 	if e_mag > 308 then
    if (binary_op_a(LESSEQ, _e_mag, 308))
        goto L1F;

    // 	    mantissa *= power(10, 308)
    DeRef(_7064);
    _7064 = power(10, 308);
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa) && IS_ATOM_INT(_7064)) {
        if (_mantissa == (short)_mantissa && _7064 <= INT15 && _7064 >= -INT15)
            _mantissa = _mantissa * _7064;
        else
            _mantissa = NewDouble(_mantissa * (double)_7064);
    }
    else {
        if (IS_ATOM_INT(_mantissa)) {
            _mantissa = NewDouble((double)_mantissa * DBL_PTR(_7064)->dbl);
        }
        else {
            if (IS_ATOM_INT(_7064)) {
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * (double)_7064);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_7064)->dbl);
        }
    }
    DeRef(_0);

    // 	    if e_mag > 1000 then
    if (binary_op_a(LESSEQ, _e_mag, 1000))
        goto L20;

    // 		e_mag = 1000 
    DeRef(_e_mag);
    _e_mag = 1000;
L20:

    // 	    for i = 1 to e_mag - 308 do
    DeRef(_7064);
    if (IS_ATOM_INT(_e_mag)) {
        _7064 = _e_mag - 308;
        if ((long)((unsigned long)_7064 +(unsigned long) HIGH_BITS) >= 0)
            _7064 = NewDouble((double)_7064);
    }
    else {
        _7064 = NewDouble(DBL_PTR(_e_mag)->dbl - (double)308);
    }
    { int _i;
        _i = 1;
L21:
        if (binary_op_a(GREATER, _i, _7064))
            goto L22;

        // 		mantissa *= 10
        _0 = _mantissa;
        if (IS_ATOM_INT(_mantissa)) {
            if (_mantissa == (short)_mantissa)
                _mantissa = _mantissa * 10;
            else
                _mantissa = NewDouble(_mantissa * (double)10);
        }
        else {
            _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * (double)10);
        }
        DeRef(_0);

        // 	    end for
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
        goto L21;
L22:
        ;
        DeRef(_i);
    }
    goto L23;
L1F:

    // 	    mantissa *= power(10, e_mag)
    DeRef(_7079);
    if (IS_ATOM_INT(_e_mag)) {
        _7079 = power(10, _e_mag);
    }
    else {
        temp_d.dbl = (double)10;
        _7079 = Dpower(&temp_d, DBL_PTR(_e_mag));
    }
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa) && IS_ATOM_INT(_7079)) {
        if (_mantissa == (short)_mantissa && _7079 <= INT15 && _7079 >= -INT15)
            _mantissa = _mantissa * _7079;
        else
            _mantissa = NewDouble(_mantissa * (double)_7079);
    }
    else {
        if (IS_ATOM_INT(_mantissa)) {
            _mantissa = NewDouble((double)_mantissa * DBL_PTR(_7079)->dbl);
        }
        else {
            if (IS_ATOM_INT(_7079)) {
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * (double)_7079);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_7079)->dbl);
        }
    }
    DeRef(_0);
L23:
L15:

    //     return {GET_SUCCESS, mantissa}
    DeRef(_7079);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _mantissa;
    Ref(_mantissa);
    _7079 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_7064);
    return _7079;
    ;
}


int _20Get()
{
    int _s = 0;
    int _e = 0;
    int _7122 = 0;
    int _0, _1, _2;
    

    //     skip_blanks()
    _20skip_blanks();

    //     if find(ch, START_NUMERIC) then
    _7122 = find(_20ch, _20START_NUMERIC);
    if (_7122 == 0)
        goto L1;

    // 	return get_number()
    _7122 = _20get_number();
    return _7122;
    goto L2;
L1:

    //     elsif ch = '{' then
    if (_20ch != 123)
        goto L3;

    // 	s = {}
    RefDS(_39);
    DeRef(_s);
    _s = _39;

    // 	get_ch()
    _20get_ch();

    // 	skip_blanks()
    _20skip_blanks();

    // 	if ch = '}' then
    if (_20ch != 125)
        goto L4;

    // 	    get_ch()
    _20get_ch();

    // 	    return {GET_SUCCESS, s} -- empty sequence
    DeRef(_7122);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _s;
    RefDS(_s);
    _7122 = MAKE_SEQ(_1);
    DeRefDS(_s);
    DeRef(_e);
    return _7122;
L4:

    // 	while TRUE do
L5:

    // 	    e = Get() -- read next element
    _0 = _e;
    _e = _20Get();
    DeRef(_0);

    // 	    if e[1] != GET_SUCCESS then
    DeRef(_7122);
    _2 = (int)SEQ_PTR(_e);
    _7122 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7122);
    if (binary_op_a(EQUALS, _7122, 0))
        goto L6;

    // 		return e
    DeRef(_s);
    DeRef(_7122);
    return _e;
L6:

    // 	    s = append(s, e[2])
    DeRef(_7122);
    _2 = (int)SEQ_PTR(_e);
    _7122 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7122);
    Ref(_7122);
    Append(&_s, _s, _7122);

    // 	    skip_blanks()
    _20skip_blanks();

    // 	    if ch = '}' then
    if (_20ch != 125)
        goto L7;

    // 		get_ch()
    _20get_ch();

    // 		return {GET_SUCCESS, s}
    DeRef(_7122);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _s;
    RefDS(_s);
    _7122 = MAKE_SEQ(_1);
    DeRefDS(_s);
    DeRefDS(_e);
    return _7122;
    goto L8;
L7:

    // 	    elsif ch != ',' then
    if (_20ch == 44)
        goto L9;

    // 		return {GET_FAIL, 0}
    DeRef(_7122);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7122 = MAKE_SEQ(_1);
    DeRef(_s);
    DeRef(_e);
    return _7122;
L9:
L8:

    // 	    get_ch() -- skip comma
    _20get_ch();

    // 	end while
    goto L5;
LA:
    goto L2;
L3:

    //     elsif ch = '\"' then
    if (_20ch != 34)
        goto LB;

    // 	return get_string()
    _0 = _7122;
    _7122 = _20get_string();
    DeRef(_0);
    DeRef(_s);
    DeRef(_e);
    return _7122;
    goto L2;
LB:

    //     elsif ch = '\'' then
    if (_20ch != 39)
        goto LC;

    // 	return get_qchar()
    _0 = _7122;
    _7122 = _20get_qchar();
    DeRef(_0);
    DeRef(_s);
    DeRef(_e);
    return _7122;
    goto L2;
LC:

    //     elsif ch = -1 then
    if (_20ch != -1)
        goto LD;

    // 	return {GET_EOF, 0}
    DeRef(_7122);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 0;
    _7122 = MAKE_SEQ(_1);
    DeRef(_s);
    DeRef(_e);
    return _7122;
    goto L2;
LD:

    // 	return {GET_FAIL, 0}
    DeRef(_7122);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _7122 = MAKE_SEQ(_1);
    DeRef(_s);
    DeRef(_e);
    return _7122;
L2:
    ;
}


int _20get(int _file)
{
    int _7143 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file)) {
        _1 = (long)(DBL_PTR(_file)->dbl);
        DeRefDS(_file);
        _file = _1;
    }

    //     input_file = file
    _20input_file = _file;

    //     input_string = 0
    DeRef(_20input_string);
    _20input_string = 0;

    //     get_ch()
    _20get_ch();

    //     return Get()
    _7143 = _20Get();
    return _7143;
    ;
}


int _20value(int _string)
{
    int _7144 = 0;
    int _0, _1, _2;
    

    //     input_string = string
    RefDS(_string);
    DeRef(_20input_string);
    _20input_string = _string;

    //     string_next = 1
    _20string_next = 1;

    //     get_ch()
    _20get_ch();

    //     return Get()
    _7144 = _20Get();
    DeRefDS(_string);
    return _7144;
    ;
}


int _20prompt_number(int _prompt, int _range)
{
    int _answer = 0;
    int _7160 = 0;
    int _7150 = 0;
    int _7145 = 0;
    int _0, _1, _2;
    

    //     while 1 do
L1:

    // 	 puts(1, prompt)
    EPuts(1, _prompt);

    // 	 answer = gets(0) -- make sure whole line is read
    DeRef(_answer);
    _answer = EGets(0);

    // 	 puts(1, '\n')
    EPuts(1, 10);

    // 	 answer = value(answer)
    Ref(_answer);
    _0 = _answer;
    _answer = _20value(_answer);
    DeRefi(_0);

    // 	 if answer[1] != GET_SUCCESS or sequence(answer[2]) then
    DeRef(_7145);
    _2 = (int)SEQ_PTR(_answer);
    _7145 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7145);
    _0 = _7145;
    if (IS_ATOM_INT(_7145)) {
        _7145 = (_7145 != 0);
    }
    else {
        _7145 = binary_op(NOTEQ, _7145, 0);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7145)) {
        if (_7145 != 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_7145)->dbl != 0.0) {
            goto L2;
        }
    }
    DeRef(_7150);
    _2 = (int)SEQ_PTR(_answer);
    _7150 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7150);
    _0 = _7150;
    _7150 = IS_SEQUENCE(_7150);
    DeRef(_0);
L3:
    if (_7150 == 0)
        goto L4;
L2:

    // 	      puts(1, "A number is expected - try again\n")
    EPuts(1, _7152);
    goto L1;
L4:

    // 	     if length(range) = 2 then
    DeRef(_7150);
    _7150 = SEQ_PTR(_range)->length;
    if (_7150 != 2)
        goto L5;

    // 		  if range[1] <= answer[2] and answer[2] <= range[2] then
    _2 = (int)SEQ_PTR(_range);
    _7150 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7150);
    DeRef(_7145);
    _2 = (int)SEQ_PTR(_answer);
    _7145 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7145);
    _0 = _7145;
    if (IS_ATOM_INT(_7150) && IS_ATOM_INT(_7145)) {
        _7145 = (_7150 <= _7145);
    }
    else {
        _7145 = binary_op(LESSEQ, _7150, _7145);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7145)) {
        if (_7145 == 0) {
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_7145)->dbl == 0.0) {
            goto L6;
        }
    }
    DeRef(_7150);
    _2 = (int)SEQ_PTR(_answer);
    _7150 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7150);
    DeRef(_7160);
    _2 = (int)SEQ_PTR(_range);
    _7160 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7160);
    _0 = _7160;
    if (IS_ATOM_INT(_7150) && IS_ATOM_INT(_7160)) {
        _7160 = (_7150 <= _7160);
    }
    else {
        _7160 = binary_op(LESSEQ, _7150, _7160);
    }
    DeRef(_0);
L7:
    if (_7160 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_7160) && DBL_PTR(_7160)->dbl == 0.0)
            goto L6;
    }

    // 		      return answer[2]
    DeRef(_7160);
    _2 = (int)SEQ_PTR(_answer);
    _7160 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7160);
    DeRefDS(_prompt);
    DeRefDS(_range);
    DeRef(_answer);
    DeRef(_7150);
    DeRef(_7145);
    return _7160;
    goto L1;
L6:

    // 		      printf(1,
    EPrintf(1, _7163, _range);
L8:
    goto L1;
L5:

    // 		  return answer[2]
    DeRef(_7160);
    _2 = (int)SEQ_PTR(_answer);
    _7160 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7160);
    DeRefDS(_prompt);
    DeRefDS(_range);
    DeRef(_answer);
    DeRef(_7150);
    DeRef(_7145);
    return _7160;
L9:
LA:

    //     end while
    goto L1;
LB:
    ;
}


int _20prompt_string(int _prompt)
{
    int _answer = 0;
    int _7168 = 0;
    int _7165;
    int _0, _1, _2;
    

    //     puts(1, prompt)
    EPuts(1, _prompt);

    //     answer = gets(0)
    _answer = EGets(0);

    //     puts(1, '\n')
    EPuts(1, 10);

    //     if sequence(answer) and length(answer) > 0 then
    _7165 = IS_SEQUENCE(_answer);
    if (_7165 == 0) {
        goto L1;
    }
    _7168 = SEQ_PTR(_answer)->length;
    _7168 = (_7168 > 0);
L2:
    if (_7168 == 0)
        goto L1;

    // 	return answer[1..$-1] -- trim the \n
    DeRef(_7168);
    _7168 = SEQ_PTR(_answer)->length;
    _7168 = _7168 - 1;
    rhs_slice_target = (object_ptr)&_7168;
    RHS_Slice((s1_ptr)_answer, 1, _7168);
    DeRefDS(_prompt);
    DeRefi(_answer);
    return _7168;
    goto L3;
L1:

    // 	return ""
    RefDS(_39);
    DeRefDS(_prompt);
    DeRefi(_answer);
    DeRef(_7168);
    return _39;
L3:
    ;
}


int _20get_bytes(int _fn, int _n)
{
    int _s = 0;
    int _c;
    int _first;
    int _last;
    int _7182 = 0;
    int _7173;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }
    if (!IS_ATOM_INT(_n)) {
        _1 = (long)(DBL_PTR(_n)->dbl);
        DeRefDS(_n);
        _n = _1;
    }

    //     if n = 0 then
    if (_n != 0)
        goto L1;

    // 	return {}
    RefDS(_39);
    return _39;
L1:

    //     c = getc(fn)
    if (_fn != last_r_file_no) {
        last_r_file_ptr = which_file(_fn, EF_READ);
        last_r_file_no = _fn;
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

    //     if c = GET_EOF then
    if (_c != -1)
        goto L2;

    // 	return {}
    RefDS(_39);
    DeRefi(_s);
    DeRef(_7182);
    return _39;
L2:

    //     s = repeat(c, n)
    DeRefi(_s);
    _s = Repeat(_c, _n);

    //     last = 1
    _last = 1;

    //     while last < n do
L3:
    if (_last >= _n)
        goto L4;

    // 	first = last+1
    _first = _last + 1;

    // 	last  = last+CHUNK
    _last = _last + 100;

    // 	if last > n then
    if (_last <= _n)
        goto L5;

    // 	    last = n
    _last = _n;
L5:

    // 	for i = first to last do
    _7173 = _last;
    { int _i;
        _i = _first;
L6:
        if (_i > _7173)
            goto L7;

        // 	    s[i] = getc(fn)
        DeRef(_7182);
        if (_fn != last_r_file_no) {
            last_r_file_ptr = which_file(_fn, EF_READ);
            last_r_file_no = _fn;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _7182 = getc(xstdin);
            }
            else
                _7182 = getc(last_r_file_ptr);
        }
        else
            _7182 = getc(last_r_file_ptr);
        _2 = (int)SEQ_PTR(_s);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _s = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = _7182;

        // 	end for
        _i = _i + 1;
        goto L6;
L7:
        ;
    }

    // 	if s[last] = GET_EOF then  
    DeRef(_7182);
    _2 = (int)SEQ_PTR(_s);
    _7182 = (int)*(((s1_ptr)_2)->base + _last);
    if (_7182 != -1)
        goto L3;

    // 	    while s[last] = GET_EOF do
L8:
    DeRef(_7182);
    _2 = (int)SEQ_PTR(_s);
    _7182 = (int)*(((s1_ptr)_2)->base + _last);
    if (_7182 != -1)
        goto L9;

    // 		last -= 1
    _last = _last - 1;

    // 	    end while 
    goto L8;
L9:

    // 	    return s[1..last]
    rhs_slice_target = (object_ptr)&_7182;
    RHS_Slice((s1_ptr)_s, 1, _last);
    DeRefDSi(_s);
    return _7182;
LA:

    //     end while   
    goto L3;
L4:

    //     return s
    DeRef(_7182);
    return _s;
    ;
}


