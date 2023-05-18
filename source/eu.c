// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _1Print(int _fn, int _o)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    // 	print( fn, o )
    StdPrint(_fn, _o, 0);

    // end procedure
    DeRef(_o);
    return 0;
    ;
}


