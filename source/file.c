// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _13seek(int _fn, int _pos)
{
    int _1941 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     return machine_func(M_SEEK, {fn, pos})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _fn;
    ((int *)_2)[2] = _pos;
    Ref(_pos);
    _1941 = MAKE_SEQ(_1);
    _0 = _1941;
    _1941 = machine(19, _1941);
    DeRefDS(_0);
    DeRef(_pos);
    return _1941;
    ;
}


int _13where(int _fn)
{
    int _1943 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     return machine_func(M_WHERE, fn)
    _1943 = machine(20, _fn);
    return _1943;
    ;
}


int _13flush(int _fn)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     machine_proc(M_FLUSH, fn)
    machine(60, _fn);

    // end procedure
    return 0;
    ;
}


int _13lock_file(int _fn, int _t, int _r)
{
    int _1956 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }
    if (!IS_ATOM_INT(_t)) {
        _1 = (long)(DBL_PTR(_t)->dbl);
        DeRefDS(_t);
        _t = _1;
    }

    //     return machine_func(M_LOCK_FILE, {fn, t, r})
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _fn;
    *((int *)(_2+8)) = _t;
    RefDS(_r);
    *((int *)(_2+12)) = _r;
    _1956 = MAKE_SEQ(_1);
    _0 = _1956;
    _1956 = machine(61, _1956);
    DeRefDS(_0);
    DeRefDS(_r);
    return _1956;
    ;
}


int _13unlock_file(int _fn, int _r)
{
    int _1958 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     machine_proc(M_UNLOCK_FILE, {fn, r})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _fn;
    ((int *)_2)[2] = _r;
    RefDS(_r);
    _1958 = MAKE_SEQ(_1);
    machine(62, _1958);

    // end procedure
    DeRefDS(_r);
    DeRefDS(_1958);
    return 0;
    ;
}


int _13dir(int _name)
{
    int _1959 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DIR, name)
    _1959 = machine(22, _name);
    DeRefDS(_name);
    return _1959;
    ;
}


int _13current_dir()
{
    int _1960 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_CURRENT_DIR, 0)
    _1960 = machine(23, 0);
    return _1960;
    ;
}


int _13chdir(int _newdir)
{
    int _1961;
    int _0, _1, _2;
    

    //     return machine_func(M_CHDIR, newdir)
    _1961 = machine(63, _newdir);
    DeRefDS(_newdir);
    return _1961;
    ;
}


int _13allow_break(int _b)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    //     machine_proc(M_ALLOW_BREAK, b)
    machine(42, _b);

    // end procedure
    return 0;
    ;
}


int _13check_break()
{
    int _1962;
    int _0, _1, _2;
    

    //     return machine_func(M_CHECK_BREAK, 0)
    _1962 = machine(43, 0);
    return _1962;
    ;
}


int _13default_dir(int _path)
{
    int _d = 0;
    int _1963 = 0;
    int _0, _1, _2;
    

    //     d = dir(path)
    RefDS(_path);
    _d = _13dir(_path);

    //     if atom(d) then
    _1963 = IS_ATOM(_d);
    if (_1963 == 0)
        goto L1;

    // 	return d
    DeRefDS(_path);
    return _d;
    goto L2;
L1:

    // 	return sort(d)
    Ref(_d);
    _0 = _1963;
    _1963 = _14sort(_d);
    DeRef(_0);
    DeRefDS(_path);
    DeRef(_d);
    return _1963;
L2:
    ;
}


int _13walk_dir(int _path_name, int _your_function, int _scan_subdirs)
{
    int _d = 0;
    int _abort_now = 0;
    int _1975 = 0;
    int _2002;
    int _1967 = 0;
    int _1977 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_your_function)) {
        _1 = (long)(DBL_PTR(_your_function)->dbl);
        DeRefDS(_your_function);
        _your_function = _1;
    }
    if (!IS_ATOM_INT(_scan_subdirs)) {
        _1 = (long)(DBL_PTR(_scan_subdirs)->dbl);
        DeRefDS(_scan_subdirs);
        _scan_subdirs = _1;
    }

    //     if my_dir = DEFAULT then

    // 	d = default_dir(path_name)
    RefDS(_path_name);
    _d = _13default_dir(_path_name);
    goto L1;
L2:

    // 	d = call_func(my_dir, {path_name})
    _0 = _1967;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_path_name);
    *((int *)(_2+4)) = _path_name;
    _1967 = MAKE_SEQ(_1);
    DeRef(_0);
    _1 = (int)SEQ_PTR(_1967);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[-2].addr;
    Ref(*(int *)(_2+4));
    _1 = (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );
    DeRef(_d);
    _d = _1;
L1:

    //     if atom(d) then
    DeRef(_1967);
    _1967 = IS_ATOM(_d);
    if (_1967 == 0)
        goto L3;

    // 	return W_BAD_PATH
    DeRefDS(_path_name);
    DeRef(_d);
    DeRef(_abort_now);
    DeRef(_1975);
    DeRef(_1977);
    return -1;
L3:

    //     while length(path_name) > 0 and 
L4:
    DeRef(_1967);
    _1967 = SEQ_PTR(_path_name)->length;
    _1967 = (_1967 > 0);
    if (_1967 == 0) {
        goto L5;
    }
    DeRef(_1975);
    _1975 = SEQ_PTR(_path_name)->length;
    _2 = (int)SEQ_PTR(_path_name);
    _1975 = (int)*(((s1_ptr)_2)->base + _1975);
    Ref(_1975);
    DeRef(_1977);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 32;
    ((int *)_2)[2] = _13SLASH;
    _1977 = MAKE_SEQ(_1);
    _0 = _1977;
    _1977 = find(_1975, _1977);
    DeRefDSi(_0);
L6:
    if (_1977 == 0)
        goto L5;

    // 	path_name = path_name[1..$-1]
    DeRef(_1977);
    _1977 = SEQ_PTR(_path_name)->length;
    _1977 = _1977 - 1;
    rhs_slice_target = (object_ptr)&_path_name;
    RHS_Slice((s1_ptr)_path_name, 1, _1977);

    //     end while
    goto L4;
L5:

    //     for i = 1 to length(d) do
    DeRef(_1977);
    _1977 = SEQ_PTR(_d)->length;
    { int _i;
        _i = 1;
L7:
        if (_i > _1977)
            goto L8;

        // 	if find('d', d[i][D_ATTRIBUTES]) then
        DeRef(_1975);
        _2 = (int)SEQ_PTR(_d);
        _1975 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1975);
        _0 = _1975;
        _2 = (int)SEQ_PTR(_1975);
        _1975 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_1975);
        DeRef(_0);
        _0 = _1975;
        _1975 = find(100, _1975);
        DeRef(_0);
        if (_1975 == 0)
            goto L9;

        // 	    if not find(d[i][D_NAME], {".", ".."}) then
        _2 = (int)SEQ_PTR(_d);
        _1975 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1975);
        _0 = _1975;
        _2 = (int)SEQ_PTR(_1975);
        _1975 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_1975);
        DeRef(_0);
        DeRef(_1967);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _1988;
        RefDS(_1988);
        ((int *)_2)[2] = _1989;
        RefDS(_1989);
        _1967 = MAKE_SEQ(_1);
        _0 = _1967;
        _1967 = find(_1975, _1967);
        DeRefDS(_0);
        if (_1967 != 0)
            goto LA;

        // 		abort_now = call_func(your_function, {path_name, d[i]})
        _2 = (int)SEQ_PTR(_d);
        _1967 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1967);
        _0 = _1967;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _path_name;
        RefDS(_path_name);
        ((int *)_2)[2] = _1967;
        Ref(_1967);
        _1967 = MAKE_SEQ(_1);
        DeRef(_0);
        _1 = (int)SEQ_PTR(_1967);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_your_function].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRef(_abort_now);
        _abort_now = _1;

        // 		if not equal(abort_now, 0) then
        DeRefDS(_1967);
        if (_abort_now == 0)
            _1967 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(0))
            _1967 = 0;
        else
            _1967 = (compare(_abort_now, 0) == 0);
        if (_1967 != 0)
            goto LB;

        // 		    return abort_now
        DeRefDS(_path_name);
        DeRef(_d);
        DeRef(_1975);
        DeRef(_1977);
        return _abort_now;
LB:

        // 		if scan_subdirs then
        if (_scan_subdirs == 0)
            goto LA;

        // 		    abort_now = walk_dir(path_name & SLASH & d[i][D_NAME],
        DeRef(_1967);
        _2 = (int)SEQ_PTR(_d);
        _1967 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1967);
        _0 = _1967;
        _2 = (int)SEQ_PTR(_1967);
        _1967 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_1967);
        DeRef(_0);
        {
            int concat_list[3];

            concat_list[0] = _1967;
            concat_list[1] = _13SLASH;
            concat_list[2] = _path_name;
            Concat_N((object_ptr)&_1967, concat_list, 3);
        }
        DeRef(_1975);
        _1975 = _your_function;
        _2002 = _scan_subdirs;
        RefDS(_1967);
        _0 = _abort_now;
        _abort_now = _13walk_dir(_1967, _1975, _2002);
        DeRef(_0);

        // 		    if not equal(abort_now, 0) and 
        if (_abort_now == 0)
            _2002 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(0))
            _2002 = 0;
        else
            _2002 = (compare(_abort_now, 0) == 0);
        _2002 = (_2002 == 0);
        if (_2002 == 0) {
            goto LA;
        }
        if (_abort_now == -1)
            _1975 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(-1))
            _1975 = 0;
        else
            _1975 = (compare(_abort_now, -1) == 0);
        _1975 = (_1975 == 0);
LC:
        if (_1975 == 0)
            goto LA;

        // 			return abort_now
        DeRefDS(_path_name);
        DeRef(_d);
        DeRef(_1975);
        DeRef(_1967);
        DeRef(_1977);
        return _abort_now;
LD:
LE:
LF:
        goto LA;
L9:

        // 	    abort_now = call_func(your_function, {path_name, d[i]})
        DeRef(_1975);
        _2 = (int)SEQ_PTR(_d);
        _1975 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1975);
        _0 = _1975;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _path_name;
        RefDS(_path_name);
        ((int *)_2)[2] = _1975;
        Ref(_1975);
        _1975 = MAKE_SEQ(_1);
        DeRef(_0);
        _1 = (int)SEQ_PTR(_1975);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_your_function].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRef(_abort_now);
        _abort_now = _1;

        // 	    if not equal(abort_now, 0) then
        DeRefDS(_1975);
        if (_abort_now == 0)
            _1975 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(0))
            _1975 = 0;
        else
            _1975 = (compare(_abort_now, 0) == 0);
        if (_1975 != 0)
            goto L10;

        // 		return abort_now
        DeRefDS(_path_name);
        DeRef(_d);
        DeRef(_1967);
        DeRef(_1977);
        return _abort_now;
L10:
LA:

        //     end for
        _i = _i + 1;
        goto L7;
L8:
        ;
    }

    //     return 0
    DeRefDS(_path_name);
    DeRef(_d);
    DeRef(_abort_now);
    DeRef(_1975);
    DeRef(_1967);
    DeRef(_1977);
    return 0;
    ;
}


