// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _11hashfn(int _name)
{
    int _len;
    int _val;
    int _1013 = 0;
    int _1016 = 0;
    int _0, _1, _2;
    

    //     len = length(name)
    _len = SEQ_PTR(_name)->length;

    //     val = name[len] * 256 + name[1]*2 + len
    _2 = (int)SEQ_PTR(_name);
    _1013 = (int)*(((s1_ptr)_2)->base + _len);
    Ref(_1013);
    _0 = _1013;
    if (IS_ATOM_INT(_1013)) {
        if (_1013 == (short)_1013)
            _1013 = _1013 * 256;
        else
            _1013 = NewDouble(_1013 * (double)256);
    }
    else {
        _1013 = binary_op(MULTIPLY, _1013, 256);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_name);
    _1016 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1016);
    _0 = _1016;
    if (IS_ATOM_INT(_1016) && IS_ATOM_INT(_1016)) {
        _1016 = _1016 + _1016;
        if ((long)((unsigned long)_1016 + (unsigned long)HIGH_BITS) >= 0) 
            _1016 = NewDouble((double)_1016);
    }
    else {
        _1016 = binary_op(PLUS, _1016, _1016);
    }
    DeRef(_0);
    _0 = _1016;
    if (IS_ATOM_INT(_1013) && IS_ATOM_INT(_1016)) {
        _1016 = _1013 + _1016;
        if ((long)((unsigned long)_1016 + (unsigned long)HIGH_BITS) >= 0) 
            _1016 = NewDouble((double)_1016);
    }
    else {
        _1016 = binary_op(PLUS, _1013, _1016);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1016)) {
        _val = _1016 + _len;
    }
    else {
        _val = binary_op(PLUS, _1016, _len);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }

    //     if len >= 4 then
    if (_len < 4)
        goto L1;

    // 	val = val * 64 + name[2]
    DeRef(_1016);
    if (_val == (short)_val)
        _1016 = _val * 64;
    else
        _1016 = NewDouble(_val * (double)64);
    DeRef(_1013);
    _2 = (int)SEQ_PTR(_name);
    _1013 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1013);
    if (IS_ATOM_INT(_1016) && IS_ATOM_INT(_1013)) {
        _val = _1016 + _1013;
    }
    else {
        _val = binary_op(PLUS, _1016, _1013);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }

    // 	val = val * 64 + name[3]
    DeRef(_1013);
    if (_val == (short)_val)
        _1013 = _val * 64;
    else
        _1013 = NewDouble(_val * (double)64);
    DeRef(_1016);
    _2 = (int)SEQ_PTR(_name);
    _1016 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1016);
    if (IS_ATOM_INT(_1013) && IS_ATOM_INT(_1016)) {
        _val = _1013 + _1016;
    }
    else {
        _val = binary_op(PLUS, _1013, _1016);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }
    goto L2;
L1:

    //     elsif len >= 3 then
    if (_len < 3)
        goto L3;

    // 	val = val * 64 + name[2]
    DeRef(_1016);
    if (_val == (short)_val)
        _1016 = _val * 64;
    else
        _1016 = NewDouble(_val * (double)64);
    DeRef(_1013);
    _2 = (int)SEQ_PTR(_name);
    _1013 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1013);
    if (IS_ATOM_INT(_1016) && IS_ATOM_INT(_1013)) {
        _val = _1016 + _1013;
    }
    else {
        _val = binary_op(PLUS, _1016, _1013);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }
L3:
L2:

    //     return remainder(val, NBUCKETS) + 1
    DeRef(_1013);
    _1013 = (_val % 2003);
    _1013 = _1013 + 1;
    DeRefDS(_name);
    DeRef(_1016);
    return _1013;
    ;
}


int _11NewEntry(int _name, int _varnum, int _scope, int _token, int _hashval, int _samehash, int _type_sym)
{
    int _new = 0;
    int _1038;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_varnum)) {
        _1 = (long)(DBL_PTR(_varnum)->dbl);
        DeRefDS(_varnum);
        _varnum = _1;
    }
    if (!IS_ATOM_INT(_scope)) {
        _1 = (long)(DBL_PTR(_scope)->dbl);
        DeRefDS(_scope);
        _scope = _1;
    }
    if (!IS_ATOM_INT(_token)) {
        _1 = (long)(DBL_PTR(_token)->dbl);
        DeRefDS(_token);
        _token = _1;
    }
    if (!IS_ATOM_INT(_hashval)) {
        _1 = (long)(DBL_PTR(_hashval)->dbl);
        DeRefDS(_hashval);
        _hashval = _1;
    }
    if (!IS_ATOM_INT(_samehash)) {
        _1 = (long)(DBL_PTR(_samehash)->dbl);
        DeRefDS(_samehash);
        _samehash = _1;
    }
    if (!IS_ATOM_INT(_type_sym)) {
        _1 = (long)(DBL_PTR(_type_sym)->dbl);
        DeRefDS(_type_sym);
        _type_sym = _1;
    }

    //     if TRANSLATE then

    // 	new = repeat(0, SIZEOF_VAR_ENTRY)
    _new = Repeat(0, 14);
L1:

    //     new[S_NEXT] = 0
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     new[S_NAME] = name
    RefDS(_name);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _name;
    DeRef(_1);

    //     new[S_SCOPE] = scope
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _scope;
    DeRef(_1);

    //     new[S_MODE] = M_NORMAL
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     new[S_USAGE] = U_UNUSED
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     new[S_FILE_NO] = current_file_no
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 6);
    _1 = *(int *)_2;
    *(int *)_2 = _7current_file_no;
    DeRef(_1);

    //     new[S_TOKEN] = token
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _token;
    DeRef(_1);

    //     new[S_VARNUM] = varnum
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 12);
    _1 = *(int *)_2;
    *(int *)_2 = _varnum;
    DeRef(_1);

    //     new[S_INITLEVEL] = -1
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 13);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    //     new[S_VTYPE] = type_sym
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_sym;
    DeRef(_1);

    //     new[S_HASHVAL] = hashval
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _hashval;
    DeRef(_1);

    //     new[S_SAMEHASH] = samehash
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _samehash;
    DeRef(_1);

    //     new[S_OBJ] = NOVALUE -- important 
    RefDS(_7NOVALUE);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7NOVALUE;
    DeRef(_1);

    //     SymTab = append(SymTab, new)
    RefDS(_new);
    Append(&_7SymTab, _7SymTab, _new);

    //     if last_sym then
    if (_11last_sym == 0)
        goto L2;

    // 		SymTab[last_sym][S_NEXT] = length(SymTab)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_11last_sym + ((s1_ptr)_2)->base);
    _1038 = SEQ_PTR(_7SymTab)->length;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1038;
    DeRef(_1);
L2:

    //     last_sym = length(SymTab)
    _11last_sym = SEQ_PTR(_7SymTab)->length;

    //     return last_sym
    DeRefDS(_name);
    DeRef(_new);
    return _11last_sym;
    ;
}


int _11tmp_alloc()
{
    int _new;
    int _0, _1, _2, _3;
    

    //     SymTab = append(SymTab, BLANK_ENTRY)
    RefDS(_11BLANK_ENTRY);
    Append(&_7SymTab, _7SymTab, _11BLANK_ENTRY);

    //     new = length(SymTab)
    _new = SEQ_PTR(_7SymTab)->length;

    //     SymTab[new][S_USAGE] = T_UNKNOWN
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);

    //     return new
    return _new;
    ;
}


int _11DefinedYet(int _sym)
{
    int _1054 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    //     if not find(SymTab[sym][S_SCOPE], 
    _2 = (int)SEQ_PTR(_7SymTab);
    _1054 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1054);
    _0 = _1054;
    _2 = (int)SEQ_PTR(_1054);
    _1054 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1054);
    DeRef(_0);
    _0 = _1054;
    _1054 = find(_1054, _1056);
    DeRef(_0);
    if (_1054 != 0)
        goto L1;

    // 	if SymTab[sym][S_FILE_NO] = current_file_no then
    _2 = (int)SEQ_PTR(_7SymTab);
    _1054 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1054);
    _0 = _1054;
    _2 = (int)SEQ_PTR(_1054);
    _1054 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1054);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1054, _7current_file_no))
        goto L2;

    // 	    CompileErr(sprintf("attempt to redefine %s", {SymTab[sym][S_NAME]}))
    DeRef(_1054);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1054 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1054);
    _0 = _1054;
    _2 = (int)SEQ_PTR(_1054);
    _1054 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1054);
    DeRef(_0);
    _0 = _1054;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_1054);
    *((int *)(_2+4)) = _1054;
    _1054 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _1054;
    _1054 = EPrintf(-9999999, _1062, _1054);
    DeRefDS(_0);
    RefDS(_1054);
    _9CompileErr(_1054);
L2:
L1:

    // end procedure
    DeRef(_1054);
    return 0;
    ;
}


int _11name_ext(int _s)
{
    int _i;
    int _1067 = 0;
    int _1070 = 0;
    int _0, _1, _2;
    

    //     i = length(s)
    _i = SEQ_PTR(_s)->length;

    //     while i >= 1 and not find(s[i], "/\\:") do  
L1:
    DeRef(_1067);
    _1067 = (_i >= 1);
    if (_1067 == 0) {
        goto L2;
    }
    DeRef(_1070);
    _2 = (int)SEQ_PTR(_s);
    _1070 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_1070);
    _0 = _1070;
    _1070 = find(_1070, _1071);
    DeRef(_0);
    _1070 = (_1070 == 0);
L3:
    if (_1070 == 0)
        goto L2;

    // 	i -= 1
    _i = _i - 1;

    //     end while
    goto L1;
L2:

    //     return s[i+1..$]
    DeRef(_1070);
    _1070 = _i + 1;
    if (_1070 > MAXINT)
        _1070 = NewDouble((double)_1070);
    DeRef(_1067);
    _1067 = SEQ_PTR(_s)->length;
    rhs_slice_target = (object_ptr)&_1067;
    RHS_Slice((s1_ptr)_s, _1070, _1067);
    DeRefDS(_s);
    DeRef(_1070);
    return _1067;
    ;
}


int _11NewStringSym(int _s)
{
    int _p;
    int _tp;
    int _prev;
    int _search_count;
    int _1091 = 0;
    int _1090 = 0;
    int _1082 = 0;
    int _0, _1, _2, _3;
    

    //     tp = literal_init
    _tp = _11literal_init;

    //     prev = 0
    _prev = 0;

    //     search_count = 0
    _search_count = 0;

    //     while tp != 0 do
L1:
    if (_tp == 0)
        goto L2;

    // 	search_count += 1
    _search_count = _search_count + 1;

    // 	if search_count > SEARCH_LIMIT then  -- avoid n-squared algorithm
    if (binary_op_a(LESSEQ, _search_count, _11SEARCH_LIMIT))
        goto L3;

    // 	    exit
    goto L2;
L3:

    // 	if equal(s, SymTab[tp][S_OBJ]) then
    DeRef(_1082);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1082 = (int)*(((s1_ptr)_2)->base + _tp);
    Ref(_1082);
    _0 = _1082;
    _2 = (int)SEQ_PTR(_1082);
    _1082 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1082);
    DeRef(_0);
    _0 = _1082;
    if (_s == _1082)
        _1082 = 1;
    else if (IS_ATOM_INT(_s) && IS_ATOM_INT(_1082))
        _1082 = 0;
    else
        _1082 = (compare(_s, _1082) == 0);
    DeRef(_0);
    if (_1082 == 0)
        goto L4;

    // 	    if tp != literal_init then
    if (_tp == _11literal_init)
        goto L5;

    // 		SymTab[prev][S_NEXT] = SymTab[tp][S_NEXT]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev + ((s1_ptr)_2)->base);
    DeRef(_1091);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1091 = (int)*(((s1_ptr)_2)->base + _tp);
    Ref(_1091);
    _0 = _1091;
    _2 = (int)SEQ_PTR(_1091);
    _1091 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1091);
    DeRef(_0);
    Ref(_1091);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1091;
    DeRef(_1);

    // 		SymTab[tp][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_tp + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11literal_init;
    DeRef(_1);

    // 		literal_init = tp
    _11literal_init = _tp;
L5:

    // 	    return tp
    DeRefDS(_s);
    DeRef(_1091);
    DeRef(_1090);
    DeRef(_1082);
    return _tp;
L4:

    // 	prev = tp
    _prev = _tp;

    // 	tp = SymTab[tp][S_NEXT]
    DeRef(_1090);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1090 = (int)*(((s1_ptr)_2)->base + _tp);
    Ref(_1090);
    _2 = (int)SEQ_PTR(_1090);
    _tp = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_tp))
        _tp = (long)DBL_PTR(_tp)->dbl;

    //     end while
    goto L1;
L2:

    //     p = tmp_alloc()
    _p = _11tmp_alloc();

    //     SymTab[p][S_OBJ] = s
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_s);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _s;
    DeRef(_1);

    //     SymTab[p][S_MODE] = M_CONSTANT
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    //     SymTab[p][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11literal_init;
    DeRef(_1);

    //     literal_init = p
    _11literal_init = _p;

    //     return p
    DeRefDS(_s);
    DeRef(_1091);
    DeRef(_1090);
    DeRef(_1082);
    return _p;
    ;
}


int _11NewIntSym(int _int_val)
{
    int _p;
    int _x;
    int _1104 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_int_val)) {
        _1 = (long)(DBL_PTR(_int_val)->dbl);
        DeRefDS(_int_val);
        _int_val = _1;
    }

    //     x = find(int_val, lastintval) 
    _x = find(_int_val, _11lastintval);

    //     if x then
    if (_x == 0)
        goto L1;

    // 	return lastintsym[x]  -- saves space, helps Translator reduce code size
    _2 = (int)SEQ_PTR(_11lastintsym);
    _1104 = (int)*(((s1_ptr)_2)->base + _x);
    return _1104;
    goto L2;
L1:

    // 	p = tmp_alloc()
    _p = _11tmp_alloc();

    // 	SymTab[p][S_MODE] = M_CONSTANT
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	SymTab[p][S_OBJ] = int_val
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _int_val;
    DeRef(_1);

    // 	lastintval = prepend(lastintval, int_val)
    Prepend(&_11lastintval, _11lastintval, _int_val);

    // 	lastintsym = prepend(lastintsym, p)
    Prepend(&_11lastintsym, _11lastintsym, _p);

    // 	if length(lastintval) > SEARCH_LIMIT then
    DeRef(_1104);
    _1104 = SEQ_PTR(_11lastintval)->length;
    if (binary_op_a(LESSEQ, _1104, _11SEARCH_LIMIT))
        goto L3;

    // 	    lastintval = lastintval[1..floor(SEARCH_LIMIT/2)]
    if (IS_ATOM_INT(_11SEARCH_LIMIT)) {
        _1104 = _11SEARCH_LIMIT >> 1;
    }
    else {
        _1 = binary_op(DIVIDE, _11SEARCH_LIMIT, 2);
        _1104 = unary_op(FLOOR, _1);
        DeRef(_1);
    }
    rhs_slice_target = (object_ptr)&_11lastintval;
    RHS_Slice((s1_ptr)_11lastintval, 1, _1104);
L3:

    // 	return p
    DeRef(_1104);
    return _p;
L2:
    ;
}


int _11NewDoubleSym(int _d)
{
    int _p;
    int _tp;
    int _prev;
    int _search_count;
    int _1126 = 0;
    int _1125 = 0;
    int _1117 = 0;
    int _0, _1, _2, _3;
    

    //     tp = literal_init
    _tp = _11literal_init;

    //     prev = 0
    _prev = 0;

    //     search_count = 0
    _search_count = 0;

    //     while tp != 0 do
L1:
    if (_tp == 0)
        goto L2;

    // 	search_count += 1
    _search_count = _search_count + 1;

    // 	if search_count > SEARCH_LIMIT then  -- avoid n-squared algorithm
    if (binary_op_a(LESSEQ, _search_count, _11SEARCH_LIMIT))
        goto L3;

    // 	    exit
    goto L2;
L3:

    // 	if equal(d, SymTab[tp][S_OBJ]) then
    DeRef(_1117);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1117 = (int)*(((s1_ptr)_2)->base + _tp);
    Ref(_1117);
    _0 = _1117;
    _2 = (int)SEQ_PTR(_1117);
    _1117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1117);
    DeRef(_0);
    _0 = _1117;
    if (_d == _1117)
        _1117 = 1;
    else if (IS_ATOM_INT(_d) && IS_ATOM_INT(_1117))
        _1117 = 0;
    else
        _1117 = (compare(_d, _1117) == 0);
    DeRef(_0);
    if (_1117 == 0)
        goto L4;

    // 	    if tp != literal_init then
    if (_tp == _11literal_init)
        goto L5;

    // 		SymTab[prev][S_NEXT] = SymTab[tp][S_NEXT]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev + ((s1_ptr)_2)->base);
    DeRef(_1126);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1126 = (int)*(((s1_ptr)_2)->base + _tp);
    Ref(_1126);
    _0 = _1126;
    _2 = (int)SEQ_PTR(_1126);
    _1126 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1126);
    DeRef(_0);
    Ref(_1126);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1126;
    DeRef(_1);

    // 		SymTab[tp][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_tp + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11literal_init;
    DeRef(_1);

    // 		literal_init = tp
    _11literal_init = _tp;
L5:

    // 	    return tp
    DeRef(_d);
    DeRef(_1126);
    DeRef(_1125);
    DeRef(_1117);
    return _tp;
L4:

    // 	prev = tp
    _prev = _tp;

    // 	tp = SymTab[tp][S_NEXT]
    DeRef(_1125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1125 = (int)*(((s1_ptr)_2)->base + _tp);
    Ref(_1125);
    _2 = (int)SEQ_PTR(_1125);
    _tp = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_tp))
        _tp = (long)DBL_PTR(_tp)->dbl;

    //     end while
    goto L1;
L2:

    //     p = tmp_alloc()
    _p = _11tmp_alloc();

    //     SymTab[p][S_MODE] = M_CONSTANT
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    //     SymTab[p][S_OBJ] = d
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    Ref(_d);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _d;
    DeRef(_1);

    //     SymTab[p][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11literal_init;
    DeRef(_1);

    //     literal_init = p
    _11literal_init = _p;

    //     return p
    DeRef(_d);
    DeRef(_1126);
    DeRef(_1125);
    DeRef(_1117);
    return _p;
    ;
}


int _11NewTempSym()
{
    int _p;
    int _1155 = 0;
    int _1143 = 0;
    int _1139 = 0;
    int _0, _1, _2, _3;
    

    //     p = SymTab[CurrentSub][S_TEMPS]
    _2 = (int)SEQ_PTR(_7SymTab);
    _1139 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_1139);
    _2 = (int)SEQ_PTR(_1139);
    _p = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     while p != 0 and SymTab[p][S_SCOPE] != FREE do
L1:
    DeRef(_1139);
    _1139 = (_p != 0);
    if (_1139 == 0) {
        goto L2;
    }
    DeRef(_1143);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1143 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_1143);
    _0 = _1143;
    _2 = (int)SEQ_PTR(_1143);
    _1143 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1143);
    DeRef(_0);
    _0 = _1143;
    if (IS_ATOM_INT(_1143)) {
        _1143 = (_1143 != 0);
    }
    else {
        _1143 = binary_op(NOTEQ, _1143, 0);
    }
    DeRef(_0);
L3:
    if (_1143 <= 0) {
        if (_1143 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_1143) && DBL_PTR(_1143)->dbl == 0.0)
                goto L2;
        }
    }

    // 	p = SymTab[p][S_NEXT]
    DeRef(_1143);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1143 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_1143);
    _2 = (int)SEQ_PTR(_1143);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     end while
    goto L1;
L2:

    //     if p = 0 then
    if (_p != 0)
        goto L4;

    // 	temps_allocated += 1
    _11temps_allocated = _11temps_allocated + 1;

    // 	p = tmp_alloc()
    _p = _11tmp_alloc();

    // 	SymTab[p][S_MODE] = M_TEMP
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[p][S_NEXT] = SymTab[CurrentSub][S_TEMPS]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_1155);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1155 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_1155);
    _0 = _1155;
    _2 = (int)SEQ_PTR(_1155);
    _1155 = (int)*(((s1_ptr)_2)->base + 18);
    Ref(_1155);
    DeRef(_0);
    Ref(_1155);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1155;
    DeRef(_1);

    // 	SymTab[CurrentSub][S_TEMPS] = p
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = _p;
    DeRef(_1);
L4:

    //     SymTab[p][S_OBJ] = NOVALUE
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_7NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7NOVALUE;
    DeRef(_1);

    //     SymTab[p][S_USAGE] = T_UNKNOWN
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);

    //     SymTab[p][S_SCOPE] = IN_USE
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     return p
    DeRef(_1155);
    DeRef(_1143);
    DeRef(_1139);
    return _p;
    ;
}


int _11InitSymTab()
{
    int _hashval;
    int _len;
    int _s;
    int _st_index;
    int _kname = 0;
    int _1187 = 0;
    int _1166 = 0;
    int _1172 = 0;
    int _1165;
    int _0, _1, _2, _3;
    

    //     for k = 1 to length(keylist) do 
    _1165 = SEQ_PTR(_10keylist)->length;
    { int _k;
        _k = 1;
L1:
        if (_k > _1165)
            goto L2;

        // 	kname = keylist[k][K_NAME]
        DeRef(_1166);
        _2 = (int)SEQ_PTR(_10keylist);
        _1166 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1166);
        DeRef(_kname);
        _2 = (int)SEQ_PTR(_1166);
        _kname = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_kname);

        // 	len = length(kname)
        _len = SEQ_PTR(_kname)->length;

        // 	hashval = hashfn(kname)
        RefDS(_kname);
        _hashval = _11hashfn(_kname);

        // 	st_index = NewEntry(kname,
        DeRefDS(_1166);
        _2 = (int)SEQ_PTR(_10keylist);
        _1166 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1166);
        _0 = _1166;
        _2 = (int)SEQ_PTR(_1166);
        _1166 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_1166);
        DeRefDS(_0);
        DeRef(_1172);
        _2 = (int)SEQ_PTR(_10keylist);
        _1172 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1172);
        _0 = _1172;
        _2 = (int)SEQ_PTR(_1172);
        _1172 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1172);
        DeRefDS(_0);
        RefDS(_kname);
        Ref(_1166);
        Ref(_1172);
        _st_index = _11NewEntry(_kname, 0, _1166, _1172, _hashval, 0, 0);

        // 	if find(keylist[k][K_TOKEN], {r:PROC, r:FUNC, TYPE}) then
        DeRef(_1172);
        _2 = (int)SEQ_PTR(_10keylist);
        _1172 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1172);
        _0 = _1172;
        _2 = (int)SEQ_PTR(_1172);
        _1172 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1172);
        DeRefDS(_0);
        _0 = _1166;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 27;
        *((int *)(_2+8)) = 501;
        *((int *)(_2+12)) = 504;
        _1166 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _1166;
        _1166 = find(_1172, _1166);
        DeRefDSi(_0);
        if (_1166 == 0)
            goto L3;

        // 	    SymTab[st_index] = SymTab[st_index] & 
        _2 = (int)SEQ_PTR(_7SymTab);
        _1166 = (int)*(((s1_ptr)_2)->base + _st_index);
        Ref(_1166);
        DeRef(_1172);
        _2 = (int)SEQ_PTR(_7SymTab);
        _1172 = (int)*(((s1_ptr)_2)->base + _st_index);
        Ref(_1172);
        _0 = _1172;
        _1172 = SEQ_PTR(_1172)->length;
        DeRef(_0);
        _1172 = 25 - _1172;
        _1172 = Repeat(0, _1172);
        if (IS_SEQUENCE(_1166) && IS_ATOM(_1172)) {
        }
        else if (IS_ATOM(_1166) && IS_SEQUENCE(_1172)) {
            Ref(_1166);
            Prepend(&_1172, _1172, _1166);
        }
        else {
            Concat((object_ptr)&_1172, _1166, (s1_ptr)_1172);
        }
        RefDS(_1172);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _st_index);
        _1 = *(int *)_2;
        *(int *)_2 = _1172;
        DeRef(_1);

        // 	    SymTab[st_index][S_NUM_ARGS] = keylist[k][K_NUM_ARGS]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        DeRef(_1187);
        _2 = (int)SEQ_PTR(_10keylist);
        _1187 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1187);
        _0 = _1187;
        _2 = (int)SEQ_PTR(_1187);
        _1187 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_1187);
        DeRefDS(_0);
        Ref(_1187);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 20);
        _1 = *(int *)_2;
        *(int *)_2 = _1187;
        DeRef(_1);

        // 	    SymTab[st_index][S_OPCODE] = keylist[k][K_OPCODE]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        DeRefDS(_1172);
        _2 = (int)SEQ_PTR(_10keylist);
        _1172 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1172);
        _0 = _1172;
        _2 = (int)SEQ_PTR(_1172);
        _1172 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_1172);
        DeRefDS(_0);
        Ref(_1172);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 19);
        _1 = *(int *)_2;
        *(int *)_2 = _1172;
        DeRef(_1);

        // 	    SymTab[st_index][S_EFFECT] = keylist[k][K_EFFECT]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        DeRef(_1187);
        _2 = (int)SEQ_PTR(_10keylist);
        _1187 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1187);
        _0 = _1187;
        _2 = (int)SEQ_PTR(_1187);
        _1187 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_1187);
        DeRefDS(_0);
        Ref(_1187);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 21);
        _1 = *(int *)_2;
        *(int *)_2 = _1187;
        DeRef(_1);

        // 	    SymTab[st_index][S_REFLIST] = {}
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        RefDS(_39);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 22);
        _1 = *(int *)_2;
        *(int *)_2 = _39;
        DeRef(_1);
L3:

        // 	if keylist[k][K_TOKEN] = r:PROC then
        DeRef(_1166);
        _2 = (int)SEQ_PTR(_10keylist);
        _1166 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1166);
        _0 = _1166;
        _2 = (int)SEQ_PTR(_1166);
        _1166 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1166);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _1166, 27))
            goto L4;

        // 	    if equal(kname, "_toplevel_") then
        DeRef(_1166);
        if (_kname == _1005)
            _1166 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_1005))
            _1166 = 0;
        else
            _1166 = (compare(_kname, _1005) == 0);
        if (_1166 == 0)
            goto L5;

        // 		TopLevelSub = st_index
        _7TopLevelSub = _st_index;
        goto L6;
L5:

        // 		elsif equal(kname, "_eval_") then
        DeRef(_1166);
        if (_kname == _1008)
            _1166 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_1008))
            _1166 = 0;
        else
            _1166 = (compare(_kname, _1008) == 0);
        if (_1166 == 0)
            goto L6;

        // 			eval_sym = st_index
        _7eval_sym = _st_index;
L7:
L8:
        goto L6;
L4:

        // 	elsif keylist[k][K_TOKEN] = TYPE then
        DeRef(_1166);
        _2 = (int)SEQ_PTR(_10keylist);
        _1166 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1166);
        _0 = _1166;
        _2 = (int)SEQ_PTR(_1166);
        _1166 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1166);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _1166, 504))
            goto L9;

        // 	    if equal(kname, "object") then
        DeRef(_1166);
        if (_kname == _854)
            _1166 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_854))
            _1166 = 0;
        else
            _1166 = (compare(_kname, _854) == 0);
        if (_1166 == 0)
            goto LA;

        // 		object_type = st_index
        _11object_type = _st_index;
        goto LB;
LA:

        // 	    elsif equal(kname, "atom") then
        DeRef(_1166);
        if (_kname == _878)
            _1166 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_878))
            _1166 = 0;
        else
            _1166 = (compare(_kname, _878) == 0);
        if (_1166 == 0)
            goto LC;

        // 		atom_type = st_index
        _11atom_type = _st_index;
        goto LB;
LC:

        // 	    elsif equal(kname, "integer") then
        DeRef(_1166);
        if (_kname == _848)
            _1166 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_848))
            _1166 = 0;
        else
            _1166 = (compare(_kname, _848) == 0);
        if (_1166 == 0)
            goto LD;

        // 		integer_type = st_index
        _11integer_type = _st_index;
        goto LB;
LD:

        // 	    elsif equal(kname, "sequence") then
        DeRef(_1166);
        if (_kname == _850)
            _1166 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_850))
            _1166 = 0;
        else
            _1166 = (compare(_kname, _850) == 0);
        if (_1166 == 0)
            goto LE;

        // 		sequence_type = st_index
        _11sequence_type = _st_index;
LE:
LB:
L9:
L6:

        // 	if buckets[hashval] = 0 then
        DeRef(_1166);
        _2 = (int)SEQ_PTR(_11buckets);
        _1166 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_1166);
        if (binary_op_a(NOTEQ, _1166, 0))
            goto LF;

        // 	    buckets[hashval] = st_index
        _2 = (int)SEQ_PTR(_11buckets);
        _2 = (int)(((s1_ptr)_2)->base + _hashval);
        _1 = *(int *)_2;
        *(int *)_2 = _st_index;
        DeRef(_1);
        goto L10;
LF:

        // 	    s = buckets[hashval]
        _2 = (int)SEQ_PTR(_11buckets);
        _s = (int)*(((s1_ptr)_2)->base + _hashval);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    while SymTab[s][S_SAMEHASH] != 0 do 
L11:
        DeRef(_1166);
        _2 = (int)SEQ_PTR(_7SymTab);
        _1166 = (int)*(((s1_ptr)_2)->base + _s);
        Ref(_1166);
        _0 = _1166;
        _2 = (int)SEQ_PTR(_1166);
        _1166 = (int)*(((s1_ptr)_2)->base + 8);
        Ref(_1166);
        DeRef(_0);
        if (binary_op_a(EQUALS, _1166, 0))
            goto L12;

        // 		s = SymTab[s][S_SAMEHASH]
        DeRef(_1166);
        _2 = (int)SEQ_PTR(_7SymTab);
        _1166 = (int)*(((s1_ptr)_2)->base + _s);
        Ref(_1166);
        _2 = (int)SEQ_PTR(_1166);
        _s = (int)*(((s1_ptr)_2)->base + 8);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    end while
        goto L11;
L12:

        // 	    SymTab[s][S_SAMEHASH] = st_index
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_s + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 8);
        _1 = *(int *)_2;
        *(int *)_2 = _st_index;
        DeRef(_1);
L10:

        //     end for
        _k = _k + 1;
        goto L1;
L2:
        ;
    }

    //     file_start_sym = length(SymTab)
    _7file_start_sym = SEQ_PTR(_7SymTab)->length;

    // end procedure
    DeRef(_kname);
    DeRef(_1187);
    DeRef(_1166);
    DeRef(_1172);
    return 0;
    ;
}


int _11add_ref(int _tok)
{
    int _s;
    int _1222 = 0;
    int _1223;
    int _1233 = 0;
    int _0, _1, _2, _3;
    

    //     if BIND or not execute then
    if (0 != 0) {
        goto L1;
    }
    _1223 = (_7execute == 0);
L2:
    if (_1223 == 0)
        goto L3;
L1:

    // 		s = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 		if s != CurrentSub and -- ignore self-ref's
    _1223 = (_s != _7CurrentSub);
    if (_1223 == 0) {
        goto L4;
    }
    DeRef(_1222);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1222 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_1222);
    _0 = _1222;
    _2 = (int)SEQ_PTR(_1222);
    _1222 = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_1222);
    DeRef(_0);
    _0 = _1222;
    _1222 = find(_s, _1222);
    DeRef(_0);
    _1222 = (_1222 == 0);
L5:
    if (_1222 == 0)
        goto L4;

    // 	SymTab[s][S_NREFS] += 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_1233);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1233 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_1233);
    _0 = _1233;
    if (IS_ATOM_INT(_1233)) {
        _1233 = _1233 + 1;
        if (_1233 > MAXINT)
            _1233 = NewDouble((double)_1233);
    }
    else
        _1233 = binary_op(PLUS, 1, _1233);
    DeRef(_0);
    Ref(_1233);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = _1233;
    DeRef(_1);

    // 		    SymTab[CurrentSub][S_REFLIST] &= s
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    DeRef(_1222);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1222 = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_1222);
    if (IS_SEQUENCE(_1222) && IS_ATOM(_s)) {
        Append(&_1222, _1222, _s);
    }
    else if (IS_ATOM(_1222) && IS_SEQUENCE(_s)) {
    }
    else {
        Concat((object_ptr)&_1222, _1222, (s1_ptr)_s);
    }
    RefDS(_1222);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 22);
    _1 = *(int *)_2;
    *(int *)_2 = _1222;
    DeRef(_1);
L4:
L3:

    // end procedure
    DeRefDS(_tok);
    DeRef(_1222);
    DeRef(_1233);
    return 0;
    ;
}


int _11MarkTargets(int _s, int _attribute)
{
    int _p;
    int _sname = 0;
    int _string = 0;
    int _colon;
    int _h;
    int _1243 = 0;
    int _1275 = 0;
    int _1239 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }
    if (!IS_ATOM_INT(_attribute)) {
        _1 = (long)(DBL_PTR(_attribute)->dbl);
        DeRefDS(_attribute);
        _attribute = _1;
    }

    //     if (SymTab[s][S_MODE] = M_TEMP or
    _2 = (int)SEQ_PTR(_7SymTab);
    _1239 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1239);
    _0 = _1239;
    _2 = (int)SEQ_PTR(_1239);
    _1239 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1239);
    DeRef(_0);
    _0 = _1239;
    if (IS_ATOM_INT(_1239)) {
        _1239 = (_1239 == 3);
    }
    else {
        _1239 = binary_op(EQUALS, _1239, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1239)) {
        if (_1239 != 0) {
            DeRef(_1239);
            _1239 = 1;
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_1239)->dbl != 0.0) {
            DeRef(_1239);
            _1239 = 1;
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_7SymTab);
    _1243 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1243);
    _0 = _1243;
    _2 = (int)SEQ_PTR(_1243);
    _1243 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1243);
    DeRef(_0);
    _0 = _1243;
    if (IS_ATOM_INT(_1243)) {
        _1243 = (_1243 == 2);
    }
    else {
        _1243 = binary_op(EQUALS, _1243, 2);
    }
    DeRef(_0);
    DeRef(_1239);
    if (IS_ATOM_INT(_1243))
        _1239 = (_1243 != 0);
    else
        _1239 = DBL_PTR(_1243)->dbl != 0.0;
L1:
    if (_1239 == 0) {
        goto L2;
    }
    DeRef(_1239);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1239 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1239);
    _0 = _1239;
    _2 = (int)SEQ_PTR(_1239);
    _1239 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1239);
    DeRef(_0);
    _0 = _1239;
    _1239 = IS_SEQUENCE(_1239);
    DeRef(_0);
L3:
    if (_1239 == 0)
        goto L2;

    // 	string = SymTab[s][S_OBJ] 
    DeRef(_1239);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1239 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1239);
    DeRef(_string);
    _2 = (int)SEQ_PTR(_1239);
    _string = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_string);

    // 	colon = find(':', string)
    _colon = find(58, _string);

    // 	if colon = 0 then
    if (_colon != 0)
        goto L4;

    // 	    sname = string
    RefDS(_string);
    DeRef(_sname);
    _sname = _string;
    goto L5;
L4:

    // 	    sname = string[colon+1..$]  -- ignore namespace part
    DeRef(_1239);
    _1239 = _colon + 1;
    DeRef(_1243);
    _1243 = SEQ_PTR(_string)->length;
    rhs_slice_target = (object_ptr)&_sname;
    RHS_Slice((s1_ptr)_string, _1239, _1243);

    // 	    while length(sname) and sname[1] = ' ' or sname[1] = '\t' do
L6:
    DeRef(_1243);
    _1243 = SEQ_PTR(_sname)->length;
    if (_1243 == 0) {
        _1243 = 0;
        goto L7;
    }
    DeRef(_1239);
    _2 = (int)SEQ_PTR(_sname);
    _1239 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1239);
    _0 = _1239;
    if (IS_ATOM_INT(_1239)) {
        _1239 = (_1239 == 32);
    }
    else {
        _1239 = binary_op(EQUALS, _1239, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1239))
        _1243 = (_1239 != 0);
    else
        _1243 = DBL_PTR(_1239)->dbl != 0.0;
L7:
    if (_1243 != 0) {
        goto L8;
    }
    DeRef(_1243);
    _2 = (int)SEQ_PTR(_sname);
    _1243 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1243);
    _0 = _1243;
    if (IS_ATOM_INT(_1243)) {
        _1243 = (_1243 == 9);
    }
    else {
        _1243 = binary_op(EQUALS, _1243, 9);
    }
    DeRef(_0);
L9:
    if (_1243 <= 0) {
        if (_1243 == 0) {
            goto LA;
        }
        else {
            if (!IS_ATOM_INT(_1243) && DBL_PTR(_1243)->dbl == 0.0)
                goto LA;
        }
    }
L8:

    // 		sname = sname[2..$]
    DeRef(_1243);
    _1243 = SEQ_PTR(_sname)->length;
    rhs_slice_target = (object_ptr)&_sname;
    RHS_Slice((s1_ptr)_sname, 2, _1243);

    // 	    end while   
    goto L6;
LA:
L5:

    // 	h = buckets[hashfn(sname)]
    RefDS(_sname);
    _0 = _1243;
    _1243 = _11hashfn(_sname);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_11buckets);
    _h = (int)*(((s1_ptr)_2)->base + _1243);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	while h do
LB:
    if (_h == 0)
        goto LC;

    // 	    if equal(sname, SymTab[h][S_NAME]) then
    DeRef(_1243);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1243 = (int)*(((s1_ptr)_2)->base + _h);
    Ref(_1243);
    _0 = _1243;
    _2 = (int)SEQ_PTR(_1243);
    _1243 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1243);
    DeRef(_0);
    _0 = _1243;
    if (_sname == _1243)
        _1243 = 1;
    else if (IS_ATOM_INT(_sname) && IS_ATOM_INT(_1243))
        _1243 = 0;
    else
        _1243 = (compare(_sname, _1243) == 0);
    DeRef(_0);
    if (_1243 == 0)
        goto LD;

    // 		if attribute = S_NREFS then
    if (_attribute != 11)
        goto LE;

    // 		    add_ref({r:PROC, h}) 
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 27;
    ((int *)_2)[2] = _h;
    _1243 = MAKE_SEQ(_1);
    RefDS(_1243);
    _11add_ref(_1243);
    goto LF;
LE:

    // 		    SymTab[h][attribute] += 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_h + ((s1_ptr)_2)->base);
    DeRef(_1275);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1275 = (int)*(((s1_ptr)_2)->base + _attribute);
    Ref(_1275);
    _0 = _1275;
    if (IS_ATOM_INT(_1275)) {
        _1275 = _1275 + 1;
        if (_1275 > MAXINT)
            _1275 = NewDouble((double)_1275);
    }
    else
        _1275 = binary_op(PLUS, 1, _1275);
    DeRef(_0);
    Ref(_1275);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _attribute);
    _1 = *(int *)_2;
    *(int *)_2 = _1275;
    DeRef(_1);
LF:
LD:

    // 	    h = SymTab[h][S_SAMEHASH]
    DeRef(_1275);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1275 = (int)*(((s1_ptr)_2)->base + _h);
    Ref(_1275);
    _2 = (int)SEQ_PTR(_1275);
    _h = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	end while           
    goto LB;
L10:
    goto LC;
L2:

    // 	p = SymTab[TopLevelSub][S_NEXT]
    DeRef(_1275);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1275 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_1275);
    _2 = (int)SEQ_PTR(_1275);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	while p != 0 do
L11:
    if (_p == 0)
        goto L12;

    // 	    if SymTab[p][S_FILE_NO] = current_file_no or
    DeRef(_1275);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1275 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_1275);
    _0 = _1275;
    _2 = (int)SEQ_PTR(_1275);
    _1275 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1275);
    DeRef(_0);
    _0 = _1275;
    if (IS_ATOM_INT(_1275)) {
        _1275 = (_1275 == _7current_file_no);
    }
    else {
        _1275 = binary_op(EQUALS, _1275, _7current_file_no);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1275)) {
        if (_1275 != 0) {
            goto L13;
        }
    }
    else {
        if (DBL_PTR(_1275)->dbl != 0.0) {
            goto L13;
        }
    }
    DeRef(_1239);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1239 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_1239);
    _0 = _1239;
    _2 = (int)SEQ_PTR(_1239);
    _1239 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1239);
    DeRef(_0);
    _0 = _1239;
    if (IS_ATOM_INT(_1239)) {
        _1239 = (_1239 == 6);
    }
    else {
        _1239 = binary_op(EQUALS, _1239, 6);
    }
    DeRef(_0);
L14:
    if (_1239 == 0) {
        goto L15;
    }
    else {
        if (!IS_ATOM_INT(_1239) && DBL_PTR(_1239)->dbl == 0.0)
            goto L15;
    }
L13:

    // 		SymTab[p][attribute] += 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_1243);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1243 = (int)*(((s1_ptr)_2)->base + _attribute);
    Ref(_1243);
    _0 = _1243;
    if (IS_ATOM_INT(_1243)) {
        _1243 = _1243 + 1;
        if (_1243 > MAXINT)
            _1243 = NewDouble((double)_1243);
    }
    else
        _1243 = binary_op(PLUS, 1, _1243);
    DeRef(_0);
    Ref(_1243);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _attribute);
    _1 = *(int *)_2;
    *(int *)_2 = _1243;
    DeRef(_1);
L15:

    // 	    p = SymTab[p][S_NEXT]
    DeRef(_1243);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1243 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_1243);
    _2 = (int)SEQ_PTR(_1243);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	end while
    goto L11;
L12:
LC:

    // end procedure
    DeRef(_sname);
    DeRef(_string);
    DeRef(_1243);
    DeRef(_1275);
    DeRef(_1239);
    return 0;
    ;
}


int _11keyfind(int _word, int _file_no)
{
    int _hashval;
    int _scope;
    int _defined;
    int _st_ptr;
    int _tok = 0;
    int _gtok = 0;
    int _1295 = 0;
    int _1317 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file_no)) {
        _1 = (long)(DBL_PTR(_file_no)->dbl);
        DeRefDS(_file_no);
        _file_no = _1;
    }

    //     dup_globals = {}
    RefDS(_39);
    DeRefi(_11dup_globals);
    _11dup_globals = _39;

    //     hashval = hashfn(word)
    RefDS(_word);
    _hashval = _11hashfn(_word);

    //     st_ptr = buckets[hashval] 
    _2 = (int)SEQ_PTR(_11buckets);
    _st_ptr = (int)*(((s1_ptr)_2)->base + _hashval);
    if (!IS_ATOM_INT(_st_ptr))
        _st_ptr = (long)DBL_PTR(_st_ptr)->dbl;

    //     while st_ptr do
L1:
    if (_st_ptr == 0)
        goto L2;

    // 		if equal(word, SymTab[st_ptr][S_NAME]) then
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_1295);
    _1295 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1295);
    DeRef(_0);
    _0 = _1295;
    if (_word == _1295)
        _1295 = 1;
    else if (IS_ATOM_INT(_word) && IS_ATOM_INT(_1295))
        _1295 = 0;
    else
        _1295 = (compare(_word, _1295) == 0);
    DeRef(_0);
    if (_1295 == 0)
        goto L3;

    // 		    tok = {SymTab[st_ptr][S_TOKEN], st_ptr}
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_1295);
    _1295 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_1295);
    DeRef(_0);
    DeRef(_tok);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _1295;
    Ref(_1295);
    ((int *)_2)[2] = _st_ptr;
    _tok = MAKE_SEQ(_1);

    // 		    if file_no = -1 then
    if (_file_no != -1)
        goto L4;

    // 				scope = SymTab[st_ptr][S_SCOPE]
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _2 = (int)SEQ_PTR(_1295);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    // 				if scope = SC_GLOBAL then
    if (_scope != 6)
        goto L5;

    // 				    if current_file_no = SymTab[st_ptr][S_FILE_NO] then
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_1295);
    _1295 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1295);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _7current_file_no, _1295))
        goto L6;

    // 						add_ref(tok)
    RefDS(_tok);
    _11add_ref(_tok);

    // 						return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1295);
    DeRef(_1317);
    return _tok;
L6:

    // 				    gtok = tok
    RefDS(_tok);
    DeRef(_gtok);
    _gtok = _tok;

    // 				    dup_globals &= st_ptr               
    Append(&_11dup_globals, _11dup_globals, _st_ptr);
    goto L7;
L5:

    // 				elsif scope = SC_LOCAL then 
    if (_scope != 5)
        goto L8;

    // 				    if current_file_no = SymTab[st_ptr][S_FILE_NO] then
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_1295);
    _1295 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1295);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _7current_file_no, _1295))
        goto L9;

    // 					add_ref(tok)
    RefDS(_tok);
    _11add_ref(_tok);

    // 					return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1295);
    DeRef(_1317);
    return _tok;
    goto L7;
L9:

    // 					elsif eval_file_no[$] = SymTab[st_ptr][S_FILE_NO] then
    DeRef(_1295);
    _1295 = SEQ_PTR(_7eval_file_no)->length;
    _2 = (int)SEQ_PTR(_7eval_file_no);
    _1295 = (int)*(((s1_ptr)_2)->base + _1295);
    Ref(_1295);
    DeRef(_1317);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1317 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1317);
    _0 = _1317;
    _2 = (int)SEQ_PTR(_1317);
    _1317 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1317);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1295, _1317))
        goto L7;

    // 					add_ref(tok)
    RefDS(_tok);
    _11add_ref(_tok);

    // 					return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1295);
    DeRef(_1317);
    return _tok;
LA:
LB:
    goto L7;
L8:

    // 				elsif scope = SC_PREDEF then
    if (_scope != 7)
        goto LC;

    // 				    if length(dup_globals) = 0 then
    DeRef(_1317);
    _1317 = SEQ_PTR(_11dup_globals)->length;
    if (_1317 != 0)
        goto L7;

    // 					add_ref(tok)
    RefDS(_tok);
    _11add_ref(_tok);

    // 					return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1295);
    return _tok;
LD:
    goto L7;
LC:

    // 				    add_ref(tok)
    RefDS(_tok);
    _11add_ref(_tok);

    // 				    return tok -- keyword, private
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1295);
    DeRef(_1317);
    return _tok;
LE:
    goto L7;
L4:

    // 				if file_no = SymTab[tok[T_SYM]][S_FILE_NO] and
    DeRef(_1317);
    _2 = (int)SEQ_PTR(_tok);
    _1317 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1317);
    _0 = _1317;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_1317))
        _1317 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1317)->dbl));
    else
        _1317 = (int)*(((s1_ptr)_2)->base + _1317);
    Ref(_1317);
    DeRef(_0);
    _0 = _1317;
    _2 = (int)SEQ_PTR(_1317);
    _1317 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1317);
    DeRef(_0);
    _0 = _1317;
    if (IS_ATOM_INT(_1317)) {
        _1317 = (_file_no == _1317);
    }
    else {
        _1317 = binary_op(EQUALS, _file_no, _1317);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1317)) {
        if (_1317 == 0) {
            goto L7;
        }
    }
    else {
        if (DBL_PTR(_1317)->dbl == 0.0) {
            goto L7;
        }
    }
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_tok);
    _1295 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1295);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_1295))
        _1295 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1295)->dbl));
    else
        _1295 = (int)*(((s1_ptr)_2)->base + _1295);
    Ref(_1295);
    DeRef(_0);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_1295);
    _1295 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1295);
    DeRef(_0);
    _0 = _1295;
    if (IS_ATOM_INT(_1295)) {
        _1295 = (_1295 == 6);
    }
    else {
        _1295 = binary_op(EQUALS, _1295, 6);
    }
    DeRef(_0);
LF:
    if (_1295 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_1295) && DBL_PTR(_1295)->dbl == 0.0)
            goto L7;
    }

    // 				    add_ref(tok)
    RefDS(_tok);
    _11add_ref(_tok);

    // 				    return tok 
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1295);
    DeRef(_1317);
    return _tok;
L10:
L11:
    goto L7;
L3:

    // if equal( word, "ECircle" ) then printf(1, "    no match: %d %s\n", {st_ptr, SymTab[st_ptr][S_NAME]} )  end if
    DeRef(_1295);
    if (_word == _1332)
        _1295 = 1;
    else if (IS_ATOM_INT(_word) && IS_ATOM_INT(_1332))
        _1295 = 0;
    else
        _1295 = (compare(_word, _1332) == 0);
    if (_1295 == 0)
        goto L12;
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _0 = _1295;
    _2 = (int)SEQ_PTR(_1295);
    _1295 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1295);
    DeRef(_0);
    _0 = _1295;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _st_ptr;
    ((int *)_2)[2] = _1295;
    Ref(_1295);
    _1295 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(1, _1334, _1295);
L12:
L7:

    // 		st_ptr = SymTab[st_ptr][S_SAMEHASH]
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1295 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    Ref(_1295);
    _2 = (int)SEQ_PTR(_1295);
    _st_ptr = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_st_ptr))
        _st_ptr = (long)DBL_PTR(_st_ptr)->dbl;

    //     end while
    goto L1;
L2:

    //     if length(dup_globals) = 1 then
    DeRef(_1295);
    _1295 = SEQ_PTR(_11dup_globals)->length;
    if (_1295 != 1)
        goto L13;

    // 		add_ref(gtok)
    RefDS(_gtok);
    _11add_ref(_gtok);

    // 		return gtok
    DeRefDS(_word);
    DeRef(_tok);
    DeRef(_1317);
    return _gtok;
L13:

    //     if length(dup_globals) = 0 then
    DeRef(_1295);
    _1295 = SEQ_PTR(_11dup_globals)->length;
    if (_1295 != 0)
        goto L14;

    // 		defined = SC_UNDEFINED
    _defined = 9;
    goto L15;
L14:

    // 		defined = SC_MULTIPLY_DEFINED
    _defined = 10;
L15:

    //     if current_instance[$] then
    DeRef(_1295);
    _1295 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _1295 = (int)*(((s1_ptr)_2)->base + _1295);
    Ref(_1295);
    if (_1295 == 0) {
        goto L16;
    }
    else {
        if (!IS_ATOM_INT(_1295) && DBL_PTR(_1295)->dbl == 0.0)
            goto L16;
    }

    //     	defined = SC_PRIVATE
    _defined = 3;
L16:

    //     tok = {VARIABLE, NewEntry(word, 0, defined, 
    DeRef(_1295);
    _2 = (int)SEQ_PTR(_11buckets);
    _1295 = (int)*(((s1_ptr)_2)->base + _hashval);
    Ref(_1295);
    RefDS(_word);
    Ref(_1295);
    _0 = _1295;
    _1295 = _11NewEntry(_word, 0, _defined, -100, _hashval, _1295, 0);
    DeRef(_0);
    DeRef(_tok);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -100;
    ((int *)_2)[2] = _1295;
    _tok = MAKE_SEQ(_1);

    //     buckets[hashval] = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _1295 = (int)*(((s1_ptr)_2)->base + 2);
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _hashval);
    _1 = *(int *)_2;
    *(int *)_2 = _1295;
    DeRef(_1);

    //     return tok  -- no ref on newly declared symbol
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1317);
    return _tok;
    ;
}


int _11Hide(int _s)
{
    int _prev;
    int _p;
    int _1366 = 0;
    int _1355 = 0;
    int _1350 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     p = buckets[SymTab[s][S_HASHVAL]]
    _2 = (int)SEQ_PTR(_7SymTab);
    _1350 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1350);
    _0 = _1350;
    _2 = (int)SEQ_PTR(_1350);
    _1350 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_1350);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_11buckets);
    if (!IS_ATOM_INT(_1350))
        _p = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1350)->dbl));
    else
        _p = (int)*(((s1_ptr)_2)->base + _1350);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     prev = 0
    _prev = 0;

    //     while p != s and p != 0 do
L1:
    DeRef(_1350);
    _1350 = (_p != _s);
    if (_1350 == 0) {
        goto L2;
    }
    DeRef(_1355);
    _1355 = (_p != 0);
L3:
    if (_1355 == 0)
        goto L2;

    // 		prev = p
    _prev = _p;

    // 		p = SymTab[p][S_SAMEHASH]
    DeRef(_1355);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1355 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_1355);
    _2 = (int)SEQ_PTR(_1355);
    _p = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     end while
    goto L1;
L2:

    //     if p = 0 then
    if (_p != 0)
        goto L4;

    // 		return -- already hidden 
    DeRef(_1366);
    DeRef(_1355);
    DeRef(_1350);
    return 0;
L4:

    //     if prev = 0 then
    if (_prev != 0)
        goto L5;

    // 		buckets[SymTab[s][S_HASHVAL]] = SymTab[s][S_SAMEHASH]
    DeRef(_1355);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1355 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1355);
    _0 = _1355;
    _2 = (int)SEQ_PTR(_1355);
    _1355 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_1355);
    DeRef(_0);
    DeRef(_1350);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1350 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1350);
    _0 = _1350;
    _2 = (int)SEQ_PTR(_1350);
    _1350 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1350);
    DeRef(_0);
    Ref(_1350);
    _2 = (int)SEQ_PTR(_11buckets);
    if (!IS_ATOM_INT(_1355))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_1355)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _1355);
    _1 = *(int *)_2;
    *(int *)_2 = _1350;
    DeRef(_1);
    goto L6;
L5:

    // 		SymTab[prev][S_SAMEHASH] = SymTab[s][S_SAMEHASH]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev + ((s1_ptr)_2)->base);
    DeRef(_1366);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1366);
    _0 = _1366;
    _2 = (int)SEQ_PTR(_1366);
    _1366 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1366);
    DeRef(_0);
    Ref(_1366);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _1366;
    DeRef(_1);
L6:

    // end procedure
    DeRef(_1366);
    DeRef(_1355);
    DeRef(_1350);
    return 0;
    ;
}


int _11LintCheck(int _s)
{
    int _u;
    int _n;
    int _vtype = 0;
    int _place = 0;
    int _problem = 0;
    int _file = 0;
    int _1395 = 0;
    int _1393;
    int _1368 = 0;
    int _0, _1, _2;
    

    //     u = SymTab[s][S_USAGE]
    _2 = (int)SEQ_PTR(_7SymTab);
    _1368 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1368);
    _2 = (int)SEQ_PTR(_1368);
    _u = (int)*(((s1_ptr)_2)->base + 5);
    if (!IS_ATOM_INT(_u))
        _u = (long)DBL_PTR(_u)->dbl;

    //     file = name_ext(file_name[current_file_no])
    DeRef(_1368);
    _2 = (int)SEQ_PTR(_7file_name);
    _1368 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_1368);
    Ref(_1368);
    _file = _11name_ext(_1368);

    //     if SymTab[s][S_SCOPE] = SC_LOCAL then
    DeRef(_1368);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1368 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1368);
    _0 = _1368;
    _2 = (int)SEQ_PTR(_1368);
    _1368 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1368);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1368, 5))
        goto L1;

    // 	if SymTab[s][S_MODE] = M_CONSTANT then
    DeRef(_1368);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1368 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1368);
    _0 = _1368;
    _2 = (int)SEQ_PTR(_1368);
    _1368 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1368);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1368, 2))
        goto L2;

    // 	    vtype = "local constant"
    RefDS(_1378);
    _vtype = _1378;
    goto L3;
L2:

    // 	    vtype = "local variable"
    RefDS(_1379);
    DeRefi(_vtype);
    _vtype = _1379;
L3:

    // 	place = ""
    RefDS(_39);
    DeRef(_place);
    _place = _39;
    goto L4;
L1:

    // 	n = SymTab[CurrentSub][S_NUM_ARGS]
    DeRef(_1368);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1368 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_1368);
    _2 = (int)SEQ_PTR(_1368);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 	if SymTab[s][S_VARNUM] < n then
    DeRef(_1368);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1368 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1368);
    _0 = _1368;
    _2 = (int)SEQ_PTR(_1368);
    _1368 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_1368);
    DeRef(_0);
    if (binary_op_a(GREATEREQ, _1368, _n))
        goto L5;

    // 	    vtype = "parameter"
    RefDS(_1385);
    DeRefi(_vtype);
    _vtype = _1385;
    goto L6;
L5:

    // 	    vtype = "private variable"
    RefDS(_1386);
    DeRefi(_vtype);
    _vtype = _1386;
L6:

    // 	place = SymTab[CurrentSub][S_NAME]
    DeRef(_1368);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1368 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_1368);
    DeRef(_place);
    _2 = (int)SEQ_PTR(_1368);
    _place = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_place);
L4:

    //     problem = ""
    RefDS(_39);
    DeRefi(_problem);
    _problem = _39;

    //     if u != or_bits(U_READ, U_WRITTEN) then
    DeRef(_1368);
    _1368 = (1 | 2);
    if (_u == _1368)
        goto L7;

    // 	if u = U_UNUSED or 
    _1368 = (_u == 0);
    if (_1368 != 0) {
        goto L8;
    }
    _1393 = (_u == 2);
    if (_1393 == 0) {
        _1393 = 0;
        goto L9;
    }
    DeRef(_1395);
    if (_vtype == _1378)
        _1395 = 1;
    else if (IS_ATOM_INT(_vtype) && IS_ATOM_INT(_1378))
        _1395 = 0;
    else
        _1395 = (compare(_vtype, _1378) == 0);
    _1393 = (_1395 != 0);
L9:
LA:
    if (_1393 == 0)
        goto LB;
L8:

    // 	    problem = "not used" 
    RefDS(_1396);
    DeRefi(_problem);
    _problem = _1396;
    goto LC;
LB:

    // 	elsif u = U_READ then
    if (_u != 1)
        goto LD;

    // 	    problem = "never assigned a value"
    RefDS(_1398);
    DeRefi(_problem);
    _problem = _1398;
LD:
LC:

    // 	if length(problem) then
    DeRef(_1395);
    _1395 = SEQ_PTR(_problem)->length;
    if (_1395 == 0)
        goto LE;

    // 	    if length(place) then
    _1395 = SEQ_PTR(_place)->length;
    if (_1395 == 0)
        goto LF;

    // 		Warning(sprintf("%s %s in %s() in %s is %s", 
    _2 = (int)SEQ_PTR(_7SymTab);
    _1395 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1395);
    _0 = _1395;
    _2 = (int)SEQ_PTR(_1395);
    _1395 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1395);
    DeRef(_0);
    _0 = _1395;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_vtype);
    *((int *)(_2+4)) = _vtype;
    Ref(_1395);
    *((int *)(_2+8)) = _1395;
    RefDS(_place);
    *((int *)(_2+12)) = _place;
    RefDS(_file);
    *((int *)(_2+16)) = _file;
    RefDS(_problem);
    *((int *)(_2+20)) = _problem;
    _1395 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _1395;
    _1395 = EPrintf(-9999999, _1401, _1395);
    DeRefDS(_0);
    RefDS(_1395);
    _9Warning(_1395);
    goto L10;
LF:

    // 		Warning(sprintf("%s %s in %s is %s", 
    DeRef(_1395);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1395 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1395);
    _0 = _1395;
    _2 = (int)SEQ_PTR(_1395);
    _1395 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1395);
    DeRef(_0);
    _0 = _1395;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_vtype);
    *((int *)(_2+4)) = _vtype;
    Ref(_1395);
    *((int *)(_2+8)) = _1395;
    RefDS(_file);
    *((int *)(_2+12)) = _file;
    RefDS(_problem);
    *((int *)(_2+16)) = _problem;
    _1395 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _1395;
    _1395 = EPrintf(-9999999, _1406, _1395);
    DeRefDS(_0);
    RefDS(_1395);
    _9Warning(_1395);
L10:
LE:
L7:

    // end procedure
    DeRefi(_vtype);
    DeRef(_place);
    DeRefi(_problem);
    DeRef(_file);
    DeRef(_1395);
    DeRef(_1368);
    return 0;
    ;
}


