// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _18open_dll(int _file_name)
{
    int _6587 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_OPEN_DLL, file_name)
    _6587 = machine(50, _file_name);
    DeRefDS(_file_name);
    return _6587;
    ;
}


int _18define_c_var(int _lib, int _variable_name)
{
    int _6588 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DEFINE_VAR, {lib, variable_name})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _lib;
    Ref(_lib);
    ((int *)_2)[2] = _variable_name;
    RefDS(_variable_name);
    _6588 = MAKE_SEQ(_1);
    _0 = _6588;
    _6588 = machine(56, _6588);
    DeRefDS(_0);
    DeRef(_lib);
    DeRefDS(_variable_name);
    return _6588;
    ;
}


int _18define_c_proc(int _lib, int _routine_name, int _arg_types)
{
    int _6590 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DEFINE_C, {lib, routine_name, arg_types, 0})
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_lib);
    *((int *)(_2+4)) = _lib;
    Ref(_routine_name);
    *((int *)(_2+8)) = _routine_name;
    RefDS(_arg_types);
    *((int *)(_2+12)) = _arg_types;
    *((int *)(_2+16)) = 0;
    _6590 = MAKE_SEQ(_1);
    _0 = _6590;
    _6590 = machine(51, _6590);
    DeRefDS(_0);
    DeRef(_lib);
    DeRef(_routine_name);
    DeRefDS(_arg_types);
    return _6590;
    ;
}


int _18define_c_func(int _lib, int _routine_name, int _arg_types, int _return_type)
{
    int _6592 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DEFINE_C, {lib, routine_name, arg_types, return_type})
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_lib);
    *((int *)(_2+4)) = _lib;
    Ref(_routine_name);
    *((int *)(_2+8)) = _routine_name;
    RefDS(_arg_types);
    *((int *)(_2+12)) = _arg_types;
    Ref(_return_type);
    *((int *)(_2+16)) = _return_type;
    _6592 = MAKE_SEQ(_1);
    _0 = _6592;
    _6592 = machine(51, _6592);
    DeRefDS(_0);
    DeRef(_lib);
    DeRef(_routine_name);
    DeRefDS(_arg_types);
    DeRef(_return_type);
    return _6592;
    ;
}


int _18call_back(int _id)
{
    int _6594 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_CALL_BACK, id)
    _6594 = machine(52, _id);
    DeRef(_id);
    return _6594;
    ;
}


int _18free_console()
{
    int _0, _1, _2;
    

    //     machine_proc(M_FREE_CONSOLE, 0)
    machine(54, 0);

    // end procedure
    return 0;
    ;
}


