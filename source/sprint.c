// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _6string(int _s)
{
    int _x = 0;
    int _381;
    int _380;
    int _0, _1, _2;
    

    //    for i = 1 to length(s) do
    _380 = SEQ_PTR(_s)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _380)
            goto L2;

        //       x = s[i]
        DeRef(_x);
        _2 = (int)SEQ_PTR(_s);
        _x = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_x);

        //       if integer(x) then
        if (IS_ATOM_INT(_x))
            _381 = 1;
        else if (IS_ATOM_DBL(_x))
            _381 = IS_ATOM_INT(DoubleToInt(_x));
        else
            _381 = 0;
        if (_381 == 0)
            goto L3;

        //      if x < ' ' then
        if (binary_op_a(GREATEREQ, _x, 32))
            goto L4;

        //         if not find(x, "\t\n\r") then
        _381 = find(_x, _70);
        if (_381 != 0)
            goto L5;

        //            return 0
        DeRefDS(_s);
        DeRef(_x);
        return 0;
L6:
        goto L5;
L4:

        //      elsif x > 255 then
        if (binary_op_a(LESSEQ, _x, 255))
            goto L5;

        //         return 0
        DeRefDS(_s);
        DeRef(_x);
        return 0;
L7:
L8:
        goto L5;
L3:

        //      return 0
        DeRefDS(_s);
        DeRef(_x);
        return 0;
L5:

        //    end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //    return 1
    DeRefDS(_s);
    DeRef(_x);
    return 1;
    ;
}


int _6SprintEuString(int _s)
{
    int _c;
    int _f;
    int _390 = 0;
    int _388;
    int _0, _1, _2;
    

    //    result &= '"'
    Append(&_6result, _6result, 34);

    //    for i = 1 to length(s) do
    _388 = SEQ_PTR(_s)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _388)
            goto L2;

        //       c = s[i]
        _2 = (int)SEQ_PTR(_s);
        _c = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_c))
            _c = (long)DBL_PTR(_c)->dbl;

        //       f = find(c, ESCAPED_CHARS)
        _f = find(_c, _6ESCAPED_CHARS);

        //       if f then
        if (_f == 0)
            goto L3;

        //      result &= ESCAPE_STRING[f]
        DeRef(_390);
        _2 = (int)SEQ_PTR(_6ESCAPE_STRING);
        _390 = (int)*(((s1_ptr)_2)->base + _f);
        RefDS(_390);
        Concat((object_ptr)&_6result, _6result, (s1_ptr)_390);
        goto L4;
L3:

        //      result &= c
        Append(&_6result, _6result, _c);
L4:

        //    end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //    result &= '"'
    Append(&_6result, _6result, 34);

    // end procedure
    DeRefDS(_s);
    DeRef(_390);
    return 0;
    ;
}


int _6Sprint(int _s)
{
    int _len;
    int _x = 0;
    int _396 = 0;
    int _398;
    int _0, _1, _2;
    

    //    len = length(s)
    _len = SEQ_PTR(_s)->length;

    //    if len and string(s) then
    if (_len == 0) {
        goto L1;
    }
    RefDS(_s);
    _398 = _6string(_s);
L2:
    if (_398 == 0)
        goto L1;

    //       SprintEuString(s)
    RefDS(_s);
    _6SprintEuString(_s);
    goto L3;
L1:

    //       result &= '{'
    Append(&_6result, _6result, 123);

    //       for i = 1 to len do
    _398 = _len;
    { int _i;
        _i = 1;
L4:
        if (_i > _398)
            goto L5;

        //      x = s[i]
        DeRef(_x);
        _2 = (int)SEQ_PTR(_s);
        _x = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_x);

        //      if atom(x) then
        DeRef(_396);
        _396 = IS_ATOM(_x);
        if (_396 == 0)
            goto L6;

        //         result &= sprint(x)
        Ref(_x);
        _396 = _2sprint(_x);
        Concat((object_ptr)&_6result, _6result, (s1_ptr)_396);
        goto L7;
L6:

        //         Sprint(x)
        Ref(_x);
        DeRef(_396);
        _396 = _x;
        Ref(_396);
        _6Sprint(_396);
L7:

        //      if i < len then
        if (_i >= _len)
            goto L8;

        //         result &= ','
        Append(&_6result, _6result, 44);
L8:

        //       end for
        _i = _i + 1;
        goto L4;
L5:
        ;
    }

    //       result &= '}'
    Append(&_6result, _6result, 125);
L3:

    // end procedure
    DeRefDS(_s);
    DeRef(_x);
    DeRef(_396);
    return 0;
    ;
}


int _6pretty_sprint(int _x)
{
    int _409 = 0;
    int _0, _1, _2;
    

    //    result = ""
    RefDS(_39);
    DeRef(_6result);
    _6result = _39;

    //    if atom(x) then
    _409 = IS_ATOM(_x);
    if (_409 == 0)
        goto L1;

    //       return sprint(x)
    Ref(_x);
    _409 = _2sprint(_x);
    DeRef(_x);
    return _409;
    goto L2;
L1:

    //       if length(x) then
    DeRef(_409);
    _409 = SEQ_PTR(_x)->length;
    if (_409 == 0)
        goto L3;

    //           Sprint(x)
    Ref(_x);
    _6Sprint(_x);

    //           if result[1] = '"' then
    _2 = (int)SEQ_PTR(_6result);
    _409 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_409);
    if (binary_op_a(NOTEQ, _409, 34))
        goto L4;

    //               result = result[2..length(result)-1]
    DeRef(_409);
    _409 = SEQ_PTR(_6result)->length;
    _409 = _409 - 1;
    rhs_slice_target = (object_ptr)&_6result;
    RHS_Slice((s1_ptr)_6result, 2, _409);
L4:
L3:

    //       return result
    RefDS(_6result);
    DeRef(_x);
    DeRef(_409);
    return _6result;
L2:
    ;
}


int _6pretty_source(int _x)
{
    int _417 = 0;
    int _0, _1, _2;
    

    //    result = ""
    RefDS(_39);
    DeRef(_6result);
    _6result = _39;

    //    if atom(x) then
    _417 = IS_ATOM(_x);
    if (_417 == 0)
        goto L1;

    //       return sprint(x)
    Ref(_x);
    _417 = _2sprint(_x);
    DeRef(_x);
    return _417;
    goto L2;
L1:

    // 		if length(x) then
    DeRef(_417);
    _417 = SEQ_PTR(_x)->length;
    if (_417 == 0)
        goto L3;

    //         	Sprint(x)
    Ref(_x);
    _6Sprint(_x);
    goto L4;
L3:

    // 	  		result = "{}"
    RefDS(_420);
    DeRef(_6result);
    _6result = _420;
L4:

    //       return result
    RefDS(_6result);
    DeRef(_x);
    DeRef(_417);
    return _6result;
L2:
    ;
}


