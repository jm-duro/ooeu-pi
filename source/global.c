// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _7boolean(int _x)
{
    int _424;
    int _423;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     return x = TRUE or x = FALSE
    _423 = (_x == 1);
    _424 = (_x == 0);
    _424 = (_423 != 0 || _424 != 0);
    return _424;
    ;
}


int _7symtab_entry(int _x)
{
    int _465;
    int _463;
    int _0, _1, _2;
    

    //     return length(x) = SIZEOF_ROUTINE_ENTRY or 
    _463 = SEQ_PTR(_x)->length;
    _463 = (_463 == 25);
    _465 = SEQ_PTR(_x)->length;
    _465 = (_465 == 14);
    _465 = (_463 != 0 || _465 != 0);
    DeRefDS(_x);
    return _465;
    ;
}


int _7symtab_index(int _x)
{
    int _468 = 0;
    int _471 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     if x = 0 then
    if (_x != 0)
        goto L1;

    // 	return TRUE -- NULL value
    return 1;
L1:

    //     if x < 0 or x > length(SymTab) then
    DeRef(_468);
    _468 = (_x < 0);
    if (_468 != 0) {
        goto L2;
    }
    DeRef(_471);
    _471 = SEQ_PTR(_7SymTab)->length;
    _471 = (_x > _471);
L3:
    if (_471 == 0)
        goto L4;
L2:

    // 	return FALSE
    DeRef(_468);
    DeRef(_471);
    return 0;
L4:

    //     return find(length(SymTab[x]), {SIZEOF_VAR_ENTRY, SIZEOF_ROUTINE_ENTRY,
    DeRef(_471);
    _2 = (int)SEQ_PTR(_7SymTab);
    _471 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_471);
    _0 = _471;
    _471 = SEQ_PTR(_471)->length;
    DeRef(_0);
    _0 = _468;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 14;
    *((int *)(_2+8)) = 25;
    *((int *)(_2+12)) = 5;
    _468 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _468;
    _468 = find(_471, _468);
    DeRefDSi(_0);
    return _468;
    ;
}


int _7temp_index(int _x)
{
    int _478;
    int _477;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     return x >= 0 and x <= length(SymTab)
    _477 = (_x >= 0);
    _478 = SEQ_PTR(_7SymTab)->length;
    _478 = (_x <= _478);
    _478 = (_477 != 0 && _478 != 0);
    return _478;
    ;
}


int _7token(int _t)
{
    int _481 = 0;
    int _483 = 0;
    int _0, _1, _2;
    

    //     return length(t) = 2 and integer(t[T_ID]) and symtab_index(t[T_SYM])
    _481 = SEQ_PTR(_t)->length;
    _481 = (_481 == 2);
    _2 = (int)SEQ_PTR(_t);
    _483 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_483);
    _0 = _483;
    if (IS_ATOM_INT(_483))
        _483 = 1;
    else if (IS_ATOM_DBL(_483))
        _483 = IS_ATOM_INT(DoubleToInt(_483));
    else
        _483 = 0;
    DeRef(_0);
    _483 = (_481 != 0 && _483 != 0);
    _2 = (int)SEQ_PTR(_t);
    _481 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_481);
    Ref(_481);
    _0 = _481;
    _481 = _7symtab_index(_481);
    DeRef(_0);
    _481 = (_483 != 0 && _481 != 0);
    DeRefDS(_t);
    return _481;
    ;
}


int _7file(int _f)
{
    int _491;
    int _489;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_f)) {
        _1 = (long)(DBL_PTR(_f)->dbl);
        DeRefDS(_f);
        _f = _1;
    }

    //     return f >= -1 and f < 100 -- rough limit
    _489 = (_f >= -1);
    _491 = (_f < 100);
    _491 = (_489 != 0 && _491 != 0);
    return _491;
    ;
}


