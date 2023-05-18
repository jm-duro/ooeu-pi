// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _5string(int _s)
{
    int _x = 0;
    int _354;
    int _353;
    int _0, _1, _2;
    

    //    for i = 1 to length(s) do
    _353 = SEQ_PTR(_s)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _353)
            goto L2;

        //       x = s[i]
        DeRef(_x);
        _2 = (int)SEQ_PTR(_s);
        _x = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_x);

        //       if integer(x) then
        if (IS_ATOM_INT(_x))
            _354 = 1;
        else if (IS_ATOM_DBL(_x))
            _354 = IS_ATOM_INT(DoubleToInt(_x));
        else
            _354 = 0;
        if (_354 == 0)
            goto L3;

        // 	 if x < ' ' then
        if (binary_op_a(GREATEREQ, _x, 32))
            goto L4;

        // 	    if not find(x, "\t\n\r") then
        _354 = find(_x, _70);
        if (_354 != 0)
            goto L5;

        // 	       return 0
        DeRefDS(_s);
        DeRef(_x);
        return 0;
L6:
        goto L5;
L4:

        // 	 elsif x > 255 then
        if (binary_op_a(LESSEQ, _x, 255))
            goto L5;

        // 	    return 0
        DeRefDS(_s);
        DeRef(_x);
        return 0;
L7:
L8:
        goto L5;
L3:

        // 	 return 0
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


int _5PrintEuString(int _s)
{
    int _c;
    int _f;
    int _367 = 0;
    int _366;
    int _0, _1, _2;
    

    //    puts(fn, '"')
    EPuts(_5fn, 34);

    //    for i = 1 to length(s) do
    _366 = SEQ_PTR(_s)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _366)
            goto L2;

        //       c = s[i]
        _2 = (int)SEQ_PTR(_s);
        _c = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_c))
            _c = (long)DBL_PTR(_c)->dbl;

        //       f = find(c, ESCAPED_CHARS)
        _f = find(_c, _5ESCAPED_CHARS);

        //       if f then
        if (_f == 0)
            goto L3;

        // 	 puts(fn, ESCAPE_STRING[f])
        DeRef(_367);
        _2 = (int)SEQ_PTR(_5ESCAPE_STRING);
        _367 = (int)*(((s1_ptr)_2)->base + _f);
        RefDS(_367);
        EPuts(_5fn, _367);
        goto L4;
L3:

        // 	 puts(fn, c)
        EPuts(_5fn, _c);
L4:

        //    end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //    puts(fn, '"')
    EPuts(_5fn, 34);

    // end procedure
    DeRefDS(_s);
    DeRef(_367);
    return 0;
    ;
}


int _5Print(int _s)
{
    int _len;
    int _x = 0;
    int _370 = 0;
    int _372;
    int _0, _1, _2;
    

    //    len = length(s)
    _len = SEQ_PTR(_s)->length;

    //    if len and string(s) then
    if (_len == 0) {
        goto L1;
    }
    RefDS(_s);
    _372 = _5string(_s);
L2:
    if (_372 == 0)
        goto L1;

    //       PrintEuString(s)
    RefDS(_s);
    _5PrintEuString(_s);
    goto L3;
L1:

    //       puts(fn, '{')
    EPuts(_5fn, 123);

    //       for i = 1 to len do
    _372 = _len;
    { int _i;
        _i = 1;
L4:
        if (_i > _372)
            goto L5;

        // 	 x = s[i]
        DeRef(_x);
        _2 = (int)SEQ_PTR(_s);
        _x = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_x);

        // 	 if atom(x) then
        DeRef(_370);
        _370 = IS_ATOM(_x);
        if (_370 == 0)
            goto L6;

        // 	    print(fn, x)
        StdPrint(_5fn, _x, 0);
        goto L7;
L6:

        // 	    Print(x)
        Ref(_x);
        DeRef(_370);
        _370 = _x;
        Ref(_370);
        _5Print(_370);
L7:

        // 	 if i < len then
        if (_i >= _len)
            goto L8;

        // 	    puts(fn, ',')
        EPuts(_5fn, 44);
L8:

        //       end for
        _i = _i + 1;
        goto L4;
L5:
        ;
    }

    //       puts(fn, '}')
    EPuts(_5fn, 125);
L3:

    // end procedure
    DeRefDS(_s);
    DeRef(_x);
    DeRef(_370);
    return 0;
    ;
}


int _5print(int _file, int _x)
{
    int _378;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file)) {
        _1 = (long)(DBL_PTR(_file)->dbl);
        DeRefDS(_file);
        _file = _1;
    }

    //    if atom(x) then
    _378 = IS_ATOM(_x);
    if (_378 == 0)
        goto L1;

    //       printf(file, "%g", x)
    EPrintf(_file, _379, _x);
    goto L2;
L1:

    //       fn = file
    _5fn = _file;

    //       Print(x)
    Ref(_x);
    _5Print(_x);
L2:

    // end procedure
    DeRef(_x);
    return 0;
    ;
}


