// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17open_err_file()
{
    int _6793 = 0;
    int _0, _1, _2;
    

    // 	if err_file != -1 then
    if (_17err_file == -1)
        goto L1;

    // 		return
    return 0;
L1:

    // 	err_file = open(err_file_name, "w")
    _17err_file = EOpen(_17err_file_name, _6794);

    // 	if err_file = -1 then
    if (_17err_file != -1)
        goto L2;

    // 	puts(2, "Can't open " & err_file_name & '\n')
    {
        int concat_list[3];

        concat_list[0] = 10;
        concat_list[1] = _17err_file_name;
        concat_list[2] = _6797;
        Concat_N((object_ptr)&_6793, concat_list, 3);
    }
    EPuts(2, _6793);

    // 	if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto L3;

    // 		c_proc( cleanup_cb, {} )
    call_c(0, _7cleanup_cb, _39);
L3:

    // 	abort(1)
    UserCleanup(1);
L2:

    // end procedure
    DeRef(_6793);
    return 0;
    ;
}


int _17both_puts(int _s)
{
    int _6800;
    int _0, _1, _2;
    

    // 	if atom(crash_msg) then
    _6800 = IS_ATOM(_17crash_msg);
    if (_6800 == 0)
        goto L1;

    // 	puts(2, s)
    EPuts(2, _s);
L1:

    // 	puts(err_file, s)
    EPuts(_17err_file, _s);

    // end procedure
    DeRef(_s);
    return 0;
    ;
}


int _17both_printf(int _format, int _items)
{
    int _6801;
    int _0, _1, _2;
    

    // 	if atom(crash_msg) then
    _6801 = IS_ATOM(_17crash_msg);
    if (_6801 == 0)
        goto L1;

    // 	printf(2, format, items)
    EPrintf(2, _format, _items);
L1:

    // 	printf(err_file, format, items)
    EPrintf(_17err_file, _format, _items);

    // end procedure
    DeRefDS(_format);
    DeRefDS(_items);
    return 0;
    ;
}


int _17find_gline(int _sub, int _pc)
{
    int _linetab = 0;
    int _s = 0;
    int _line;
    int _6806 = 0;
    int _6809 = 0;
    int _6802 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sub)) {
        _1 = (long)(DBL_PTR(_sub)->dbl);
        DeRefDS(_sub);
        _sub = _1;
    }
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }

    // 	s = SymTab[sub]
    _2 = (int)SEQ_PTR(_7SymTab);
    _s = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_s);

    // 	linetab = SymTab[sub][S_LINETAB]
    _2 = (int)SEQ_PTR(_7SymTab);
    _6802 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6802);
    _2 = (int)SEQ_PTR(_6802);
    _linetab = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_linetab);

    // 	line = 1
    _line = 1;

    // 	for i = 1 to length(linetab) do
    DeRef(_6802);
    _6802 = SEQ_PTR(_linetab)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _6802)
            goto L2;

        // 		if linetab[i] >= pc or linetab[i] = -2 then
        DeRef(_6806);
        _2 = (int)SEQ_PTR(_linetab);
        _6806 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6806);
        _0 = _6806;
        if (IS_ATOM_INT(_6806)) {
            _6806 = (_6806 >= _pc);
        }
        else {
            _6806 = binary_op(GREATEREQ, _6806, _pc);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_6806)) {
            if (_6806 != 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_6806)->dbl != 0.0) {
                goto L3;
            }
        }
        DeRef(_6809);
        _2 = (int)SEQ_PTR(_linetab);
        _6809 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6809);
        _0 = _6809;
        if (IS_ATOM_INT(_6809)) {
            _6809 = (_6809 == -2);
        }
        else {
            _6809 = binary_op(EQUALS, _6809, -2);
        }
        DeRef(_0);
L4:
        if (_6809 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_6809) && DBL_PTR(_6809)->dbl == 0.0)
                goto L5;
        }
L3:

        // 		    line = i-1
        _line = _i - 1;

        // 		    while line > 1 and linetab[line] = -1 do
L6:
        DeRef(_6809);
        _6809 = (_line > 1);
        if (_6809 == 0) {
            goto L2;
        }
        DeRef(_6806);
        _2 = (int)SEQ_PTR(_linetab);
        _6806 = (int)*(((s1_ptr)_2)->base + _line);
        Ref(_6806);
        _0 = _6806;
        if (IS_ATOM_INT(_6806)) {
            _6806 = (_6806 == -1);
        }
        else {
            _6806 = binary_op(EQUALS, _6806, -1);
        }
        DeRef(_0);
L7:
        if (_6806 <= 0) {
            if (_6806 == 0) {
                goto L2;
            }
            else {
                if (!IS_ATOM_INT(_6806) && DBL_PTR(_6806)->dbl == 0.0)
                    goto L2;
            }
        }

        // 				line -= 1
        _line = _line - 1;

        // 		    end while
        goto L6;
L8:

        // 		    exit
        goto L2;
L5:

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	return SymTab[sub][S_FIRSTLINE] + line - 1
    DeRef(_6806);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6806 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6806);
    _0 = _6806;
    _2 = (int)SEQ_PTR(_6806);
    _6806 = (int)*(((s1_ptr)_2)->base + 17);
    Ref(_6806);
    DeRef(_0);
    _0 = _6806;
    if (IS_ATOM_INT(_6806)) {
        _6806 = _6806 + _line;
        if ((long)((unsigned long)_6806 + (unsigned long)HIGH_BITS) >= 0) 
            _6806 = NewDouble((double)_6806);
    }
    else {
        _6806 = binary_op(PLUS, _6806, _line);
    }
    DeRef(_0);
    _0 = _6806;
    if (IS_ATOM_INT(_6806)) {
        _6806 = _6806 - 1;
        if ((long)((unsigned long)_6806 +(unsigned long) HIGH_BITS) >= 0)
            _6806 = NewDouble((double)_6806);
    }
    else {
        _6806 = binary_op(MINUS, _6806, 1);
    }
    DeRef(_0);
    DeRef(_linetab);
    DeRef(_s);
    DeRef(_6809);
    DeRef(_6802);
    return _6806;
    ;
}


int _17find_line(int _sub, int _pc)
{
    int _linetab = 0;
    int _line;
    int _gline;
    int _6827 = 0;
    int _6824 = 0;
    int _6821 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sub)) {
        _1 = (long)(DBL_PTR(_sub)->dbl);
        DeRefDS(_sub);
        _sub = _1;
    }
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }

    // 	linetab = SymTab[sub][S_LINETAB]
    _2 = (int)SEQ_PTR(_7SymTab);
    _6821 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6821);
    _2 = (int)SEQ_PTR(_6821);
    _linetab = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_linetab);

    // 	line = 1
    _line = 1;

    // 	for i = 1 to length(linetab) do
    DeRef(_6821);
    _6821 = SEQ_PTR(_linetab)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _6821)
            goto L2;

        // 		if linetab[i] >= pc or linetab[i] = -2 then
        DeRef(_6824);
        _2 = (int)SEQ_PTR(_linetab);
        _6824 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6824);
        _0 = _6824;
        if (IS_ATOM_INT(_6824)) {
            _6824 = (_6824 >= _pc);
        }
        else {
            _6824 = binary_op(GREATEREQ, _6824, _pc);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_6824)) {
            if (_6824 != 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_6824)->dbl != 0.0) {
                goto L3;
            }
        }
        DeRef(_6827);
        _2 = (int)SEQ_PTR(_linetab);
        _6827 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6827);
        _0 = _6827;
        if (IS_ATOM_INT(_6827)) {
            _6827 = (_6827 == -2);
        }
        else {
            _6827 = binary_op(EQUALS, _6827, -2);
        }
        DeRef(_0);
L4:
        if (_6827 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_6827) && DBL_PTR(_6827)->dbl == 0.0)
                goto L5;
        }
L3:

        // 		    line = i-1
        _line = _i - 1;

        // 		    while line > 1 and linetab[line] = -1 do
L6:
        DeRef(_6827);
        _6827 = (_line > 1);
        if (_6827 == 0) {
            goto L2;
        }
        DeRef(_6824);
        _2 = (int)SEQ_PTR(_linetab);
        _6824 = (int)*(((s1_ptr)_2)->base + _line);
        Ref(_6824);
        _0 = _6824;
        if (IS_ATOM_INT(_6824)) {
            _6824 = (_6824 == -1);
        }
        else {
            _6824 = binary_op(EQUALS, _6824, -1);
        }
        DeRef(_0);
L7:
        if (_6824 <= 0) {
            if (_6824 == 0) {
                goto L2;
            }
            else {
                if (!IS_ATOM_INT(_6824) && DBL_PTR(_6824)->dbl == 0.0)
                    goto L2;
            }
        }

        // 				line -= 1
        _line = _line - 1;

        // 		    end while
        goto L6;
L8:

        // 		    exit
        goto L2;
L5:

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	gline = SymTab[sub][S_FIRSTLINE] + line - 1
    DeRef(_6824);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6824 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6824);
    _0 = _6824;
    _2 = (int)SEQ_PTR(_6824);
    _6824 = (int)*(((s1_ptr)_2)->base + 17);
    Ref(_6824);
    DeRef(_0);
    _0 = _6824;
    if (IS_ATOM_INT(_6824)) {
        _6824 = _6824 + _line;
        if ((long)((unsigned long)_6824 + (unsigned long)HIGH_BITS) >= 0) 
            _6824 = NewDouble((double)_6824);
    }
    else {
        _6824 = binary_op(PLUS, _6824, _line);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6824)) {
        _gline = _6824 - 1;
    }
    else {
        _gline = binary_op(MINUS, _6824, 1);
    }
    if (!IS_ATOM_INT(_gline)) {
        _1 = (long)(DBL_PTR(_gline)->dbl);
        DeRefDS(_gline);
        _gline = _1;
    }

    // 	return {file_name[slist[gline][LOCAL_FILE_NO]], slist[gline][LINE]}
    DeRef(_6824);
    _2 = (int)SEQ_PTR(_7slist);
    _6824 = (int)*(((s1_ptr)_2)->base + _gline);
    Ref(_6824);
    _0 = _6824;
    _2 = (int)SEQ_PTR(_6824);
    _6824 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6824);
    DeRef(_0);
    _0 = _6824;
    _2 = (int)SEQ_PTR(_7file_name);
    if (!IS_ATOM_INT(_6824))
        _6824 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6824)->dbl));
    else
        _6824 = (int)*(((s1_ptr)_2)->base + _6824);
    Ref(_6824);
    DeRef(_0);
    DeRef(_6827);
    _2 = (int)SEQ_PTR(_7slist);
    _6827 = (int)*(((s1_ptr)_2)->base + _gline);
    Ref(_6827);
    _0 = _6827;
    _2 = (int)SEQ_PTR(_6827);
    _6827 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6827);
    DeRef(_0);
    _0 = _6827;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6824;
    Ref(_6824);
    ((int *)_2)[2] = _6827;
    Ref(_6827);
    _6827 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_linetab);
    DeRef(_6824);
    DeRef(_6821);
    return _6827;
    ;
}


int _17show_var(int _x)
{
    int _6853 = 0;
    int _6845 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    // 	puts(err_file, "    " & SymTab[x][S_NAME] & " = ")
    _2 = (int)SEQ_PTR(_7SymTab);
    _6845 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_6845);
    _0 = _6845;
    _2 = (int)SEQ_PTR(_6845);
    _6845 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6845);
    DeRef(_0);
    {
        int concat_list[3];

        concat_list[0] = _6847;
        concat_list[1] = _6845;
        concat_list[2] = _3736;
        Concat_N((object_ptr)&_6845, concat_list, 3);
    }
    EPuts(_17err_file, _6845);

    // 	if equal(val[x], NOVALUE) then
    DeRefDS(_6845);
    _2 = (int)SEQ_PTR(_17val);
    _6845 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_6845);
    _0 = _6845;
    if (_6845 == _7NOVALUE)
        _6845 = 1;
    else if (IS_ATOM_INT(_6845) && IS_ATOM_INT(_7NOVALUE))
        _6845 = 0;
    else
        _6845 = (compare(_6845, _7NOVALUE) == 0);
    DeRef(_0);
    if (_6845 == 0)
        goto L1;

    // 	puts(err_file, "<no value>")
    EPuts(_17err_file, _6851);
    goto L2;
L1:

    // 	misc:pretty_print(err_file, val[x], 
    DeRef(_6845);
    _2 = (int)SEQ_PTR(_17val);
    _6845 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_6845);
    DeRef(_6853);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6853 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_6853);
    _0 = _6853;
    _2 = (int)SEQ_PTR(_6853);
    _6853 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6853);
    DeRef(_0);
    _0 = _6853;
    _6853 = SEQ_PTR(_6853)->length;
    DeRef(_0);
    _6853 = _6853 + 7;
    _1 = NewS1(9);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 1;
    *((int *)(_2+8)) = 2;
    *((int *)(_2+12)) = _6853;
    *((int *)(_2+16)) = 78;
    RefDS(_6857);
    *((int *)(_2+20)) = _6857;
    RefDS(_6858);
    *((int *)(_2+24)) = _6858;
    *((int *)(_2+28)) = 32;
    *((int *)(_2+32)) = 127;
    *((int *)(_2+36)) = 500;
    _6853 = MAKE_SEQ(_1);
    Ref(_6845);
    RefDS(_6853);
    _2pretty_print(_17err_file, _6845, _6853);
L2:

    // 	puts(err_file, '\n')
    EPuts(_17err_file, 10);

    // end procedure
    DeRef(_6853);
    DeRef(_6845);
    return 0;
    ;
}


int _17dump_slist()
{
    int _fn;
    int _6870 = 0;
    int _6863 = 0;
    int _6861;
    int _0, _1, _2, _3;
    

    // 	fn = open("slist.txt", "w")
    _fn = EOpen(_6860, _6794);

    // 	for i = 1 to length(slist) do
    _6861 = SEQ_PTR(_7slist)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _6861)
            goto L2;

        // 		if sequence(slist[i]) then
        DeRef(_6863);
        _2 = (int)SEQ_PTR(_7slist);
        _6863 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6863);
        _0 = _6863;
        _6863 = IS_SEQUENCE(_6863);
        DeRef(_0);
        if (_6863 == 0)
            goto L3;

        // 			if atom(slist[i][SRC]) then
        _2 = (int)SEQ_PTR(_7slist);
        _6863 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6863);
        _0 = _6863;
        _2 = (int)SEQ_PTR(_6863);
        _6863 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6863);
        DeRef(_0);
        _0 = _6863;
        _6863 = IS_ATOM(_6863);
        DeRef(_0);
        if (_6863 == 0)
            goto L4;

        // 				slist[i][SRC] = fetch_line( slist[i][SRC] )
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_6870);
        _2 = (int)SEQ_PTR(_7slist);
        _6870 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6870);
        _0 = _6870;
        _2 = (int)SEQ_PTR(_6870);
        _6870 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6870);
        DeRef(_0);
        Ref(_6870);
        _0 = _6870;
        _6870 = _12fetch_line(_6870);
        DeRef(_0);
        RefDS(_6870);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _6870;
        DeRef(_1);
L4:

        // 			print(fn, i & slist[i]) puts(fn, "\n")			
        DeRef(_6870);
        _2 = (int)SEQ_PTR(_7slist);
        _6870 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6870);
        if (IS_SEQUENCE(_i) && IS_ATOM(_6870)) {
        }
        else if (IS_ATOM(_i) && IS_SEQUENCE(_6870)) {
            Prepend(&_6870, _6870, _i);
        }
        else {
            Concat((object_ptr)&_6870, _i, (s1_ptr)_6870);
        }
        RefDS(_6870);
        _5print(_fn, _6870);
        EPuts(_fn, _738);
L3:

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	close(fn)
    EClose(_fn);

    // end procedure
    DeRef(_6870);
    DeRef(_6863);
    return 0;
    ;
}


int _17trace_back(int _msg)
{
    int _sub;
    int _v;
    int _levels;
    int _prev_file_no;
    int _sp;
    int _gline;
    int _6875 = 0;
    int _6931 = 0;
    int _6992 = 0;
    int _6927 = 0;
    int _0, _1, _2, _3;
    

    // 	levels = 1
    _levels = 1;

    // 	if atom(slist[$]) then
    _6875 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _6875 = (int)*(((s1_ptr)_2)->base + _6875);
    Ref(_6875);
    _0 = _6875;
    _6875 = IS_ATOM(_6875);
    DeRef(_0);
    if (_6875 == 0)
        goto L1;

    // 	slist = s_expand(slist)
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L1:

    // 	while length(call_stack) and TRUE do
L2:
    DeRef(_6875);
    _6875 = SEQ_PTR(_17call_stack)->length;
    if (_6875 == 0) {
        goto L3;
    }
L4:

    // 		sub = call_stack[$]
    DeRef(_6875);
    _6875 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _sub = (int)*(((s1_ptr)_2)->base + _6875);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 		if levels = 1 then
    if (_levels != 1)
        goto L5;

    // 		    puts(2, '\n')
    EPuts(2, 10);
    goto L6;
L5:

    // 		elsif sub != call_back_routine then
    if (_sub == _17call_back_routine)
        goto L7;

    // 		    both_puts("... called from ")
    RefDS(_6885);
    _17both_puts(_6885);
L7:
L6:

    // 		if sub = call_back_routine then
    if (_sub != _17call_back_routine)
        goto L8;

    // 		    if crash_count > 0 then
    if (_17crash_count <= 0)
        goto L9;

    // 				both_puts("^^^ called to handle run-time crash\n")
    RefDS(_6888);
    _17both_puts(_6888);

    // 				exit
    goto L3;
    goto LA;
L9:

    // 				both_puts("^^^ call-back from ")
    RefDS(_6889);
    _17both_puts(_6889);

    // 				if EWINDOWS then
    if (_7EWINDOWS == 0)
        goto LB;

    // 				    both_puts("Windows\n")
    RefDS(_6890);
    _17both_puts(_6890);
    goto LA;
LB:

    // 				    both_puts("external program\n")
    RefDS(_6891);
    _17both_puts(_6891);
LC:
LD:
    goto LA;
L8:

    // 		    both_printf("%s:%d ", find_line(sub, pc)) 
    _0 = _6875;
    _6875 = _17find_line(_sub, _17pc);
    DeRef(_0);
    RefDS(_6892);
    RefDS(_6875);
    _17both_printf(_6892, _6875);

    // 		    if not equal(SymTab[sub][S_NAME], "_toplevel_") then
    DeRefDS(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6875);
    DeRef(_0);
    _0 = _6875;
    if (_6875 == _1005)
        _6875 = 1;
    else if (IS_ATOM_INT(_6875) && IS_ATOM_INT(_1005))
        _6875 = 0;
    else
        _6875 = (compare(_6875, _1005) == 0);
    DeRef(_0);
    if (_6875 != 0)
        goto LE;

    // 				if SymTab[sub][S_TOKEN] = r:PROC then
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6875);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _6875, 27))
        goto LF;

    // 				    both_puts("in procedure ")
    RefDS(_6901);
    _17both_puts(_6901);
    goto L10;
LF:

    // 				elsif SymTab[sub][S_TOKEN] = r:FUNC then
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6875);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _6875, 501))
        goto L11;

    // 				    both_puts("in function ")
    RefDS(_6905);
    _17both_puts(_6905);
    goto L10;
L11:

    // 				elsif SymTab[sub][S_TOKEN] = TYPE then
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6875);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _6875, 504))
        goto L12;

    // 				    both_puts("in type ")
    RefDS(_6909);
    _17both_puts(_6909);
L12:
L10:

    // 				both_printf("%s()", {SymTab[sub][S_NAME]})
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6875);
    DeRef(_0);
    _0 = _6875;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6875);
    *((int *)(_2+4)) = _6875;
    _6875 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_6910);
    RefDS(_6875);
    _17both_printf(_6910, _6875);
LE:

    // 		    both_puts("\n")
    RefDS(_738);
    _17both_puts(_738);

    // 		    if levels = 1 then
    if (_levels != 1)
        goto L13;

    // 				if sequence(crash_msg) then
    DeRef(_6875);
    _6875 = IS_SEQUENCE(_17crash_msg);
    if (_6875 == 0)
        goto L14;

    // 				    clear_screen()
    ClearScreen();

    // 				    puts(2, crash_msg)
    EPuts(2, _17crash_msg);
L14:

    // 				both_puts(msg & '\n')
    Append(&_6875, _msg, 10);
    RefDS(_6875);
    _17both_puts(_6875);
L13:

    // 		    if length(call_stack) < 2 then
    DeRef(_6875);
    _6875 = SEQ_PTR(_17call_stack)->length;
    if (_6875 >= 2)
        goto L15;

    // 				both_puts('\n')
    _17both_puts(10);

    // 				exit
    goto L3;
L15:

    // if 0 then

    // 		    SymTab[sub][S_ACTIVE] -= 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRef(_6875);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _6875 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_6875);
    _0 = _6875;
    if (IS_ATOM_INT(_6875)) {
        _6875 = _6875 - 1;
        if ((long)((unsigned long)_6875 +(unsigned long) HIGH_BITS) >= 0)
            _6875 = NewDouble((double)_6875);
    }
    else {
        _6875 = binary_op(MINUS, _6875, 1);
    }
    DeRef(_0);
    Ref(_6875);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _6875;
    DeRef(_1);
LA:

    // 		puts(err_file, '\n')
    EPuts(_17err_file, 10);

    // 		pc = call_stack[$-1] - 1
    DeRef(_6875);
    _6875 = SEQ_PTR(_17call_stack)->length;
    _6875 = _6875 - 1;
    _2 = (int)SEQ_PTR(_17call_stack);
    _6875 = (int)*(((s1_ptr)_2)->base + _6875);
    Ref(_6875);
    if (IS_ATOM_INT(_6875)) {
        _17pc = _6875 - 1;
    }
    else {
        _17pc = binary_op(MINUS, _6875, 1);
    }
    if (!IS_ATOM_INT(_17pc)) {
        _1 = (long)(DBL_PTR(_17pc)->dbl);
        DeRefDS(_17pc);
        _17pc = _1;
    }

    // 		call_stack = call_stack[1..call_stack[$-2]]
    DeRef(_6875);
    _6875 = SEQ_PTR(_17call_stack)->length;
    _6875 = _6875 - 2;
    _2 = (int)SEQ_PTR(_17call_stack);
    _6875 = (int)*(((s1_ptr)_2)->base + _6875);
    Ref(_6875);
    rhs_slice_target = (object_ptr)&_17call_stack;
    RHS_Slice((s1_ptr)_17call_stack, 1, _6875);

    // 		levels += 1
    _levels = _levels + 1;

    // 	end while
    goto L2;
L3:

    // 	puts(2, "--> see " & err_file_name & '\n')
    {
        int concat_list[3];

        concat_list[0] = 10;
        concat_list[1] = _17err_file_name;
        concat_list[2] = _6954;
        Concat_N((object_ptr)&_6875, concat_list, 3);
    }
    EPuts(2, _6875);

    // 	puts(err_file, "\n\nGlobal & Local Variables\n")
    EPuts(_17err_file, _6956);

    // 	prev_file_no = -1
    _prev_file_no = -1;

    // 	v = SymTab[TopLevelSub][S_NEXT]
    DeRefDS(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_6875);
    _2 = (int)SEQ_PTR(_6875);
    _v = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_v))
        _v = (long)DBL_PTR(_v)->dbl;

    // 	while v do
L16:
    if (_v == 0)
        goto L17;

    // 		if SymTab[v][S_TOKEN] = VARIABLE and 
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _v);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6875);
    DeRef(_0);
    _0 = _6875;
    if (IS_ATOM_INT(_6875)) {
        _6875 = (_6875 == -100);
    }
    else {
        _6875 = binary_op(EQUALS, _6875, -100);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6875)) {
        if (_6875 == 0) {
            DeRef(_6875);
            _6875 = 0;
            goto L18;
        }
    }
    else {
        if (DBL_PTR(_6875)->dbl == 0.0) {
            DeRef(_6875);
            _6875 = 0;
            goto L18;
        }
    }
    DeRef(_6927);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6927 = (int)*(((s1_ptr)_2)->base + _v);
    Ref(_6927);
    _0 = _6927;
    _2 = (int)SEQ_PTR(_6927);
    _6927 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6927);
    DeRef(_0);
    _0 = _6927;
    if (IS_ATOM_INT(_6927)) {
        _6927 = (_6927 == 1);
    }
    else {
        _6927 = binary_op(EQUALS, _6927, 1);
    }
    DeRef(_0);
    DeRef(_6875);
    if (IS_ATOM_INT(_6927))
        _6875 = (_6927 != 0);
    else
        _6875 = DBL_PTR(_6927)->dbl != 0.0;
L18:
    if (_6875 == 0) {
        goto L19;
    }
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _v);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6875);
    DeRef(_0);
    _0 = _6875;
    _6875 = find(_6875, _6969);
    DeRef(_0);
L1A:
    if (_6875 == 0)
        goto L19;

    // 			    if SymTab[v][S_FILE_NO] != prev_file_no then
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _v);
    Ref(_6875);
    _0 = _6875;
    _2 = (int)SEQ_PTR(_6875);
    _6875 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_6875);
    DeRef(_0);
    if (binary_op_a(EQUALS, _6875, _prev_file_no))
        goto L1B;

    // 					prev_file_no = SymTab[v][S_FILE_NO]
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _v);
    Ref(_6875);
    _2 = (int)SEQ_PTR(_6875);
    _prev_file_no = (int)*(((s1_ptr)_2)->base + 6);
    if (!IS_ATOM_INT(_prev_file_no))
        _prev_file_no = (long)DBL_PTR(_prev_file_no)->dbl;

    // 					puts(err_file, "\n " & file_name[prev_file_no] & ":\n")
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7file_name);
    _6875 = (int)*(((s1_ptr)_2)->base + _prev_file_no);
    Ref(_6875);
    {
        int concat_list[3];

        concat_list[0] = _6978;
        concat_list[1] = _6875;
        concat_list[2] = _6976;
        Concat_N((object_ptr)&_6875, concat_list, 3);
    }
    EPuts(_17err_file, _6875);
L1B:

    // 			    show_var(v)
    _17show_var(_v);
L19:

    // 		v = SymTab[v][S_NEXT]
    DeRef(_6875);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6875 = (int)*(((s1_ptr)_2)->base + _v);
    Ref(_6875);
    _2 = (int)SEQ_PTR(_6875);
    _v = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_v))
        _v = (long)DBL_PTR(_v)->dbl;

    // 	end while
    goto L16;
L17:

    // 	if full_debug and length(traced_lines) then
    if (_7full_debug == 0) {
        goto L1C;
    }
    DeRef(_6927);
    _6927 = SEQ_PTR(_7traced_lines)->length;
L1D:
    if (_6927 == 0)
        goto L1C;

    // 	puts( err_file, "\n\nTraced lines leading up to the failure:\n\n" )
    EPuts(_17err_file, _6984);

    // 	for i = 1 to length(traced_lines) do
    DeRef(_6927);
    _6927 = SEQ_PTR(_7traced_lines)->length;
    { int _i;
        _i = 1;
L1E:
        if (_i > _6927)
            goto L1F;

        // 		gline = traced_lines[i]
        _2 = (int)SEQ_PTR(_7traced_lines);
        _gline = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_gline))
            _gline = (long)DBL_PTR(_gline)->dbl;

        // 		if atom(slist[gline][SRC] ) then
        DeRef(_6875);
        _2 = (int)SEQ_PTR(_7slist);
        _6875 = (int)*(((s1_ptr)_2)->base + _gline);
        Ref(_6875);
        _0 = _6875;
        _2 = (int)SEQ_PTR(_6875);
        _6875 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6875);
        DeRef(_0);
        _0 = _6875;
        _6875 = IS_ATOM(_6875);
        DeRef(_0);
        if (_6875 == 0)
            goto L20;

        // 			slist[gline][SRC] = fetch_line( slist[gline][SRC] )
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_gline + ((s1_ptr)_2)->base);
        DeRef(_6992);
        _2 = (int)SEQ_PTR(_7slist);
        _6992 = (int)*(((s1_ptr)_2)->base + _gline);
        Ref(_6992);
        _0 = _6992;
        _2 = (int)SEQ_PTR(_6992);
        _6992 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6992);
        DeRef(_0);
        Ref(_6992);
        _0 = _6992;
        _6992 = _12fetch_line(_6992);
        DeRef(_0);
        RefDS(_6992);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _6992;
        DeRef(_1);
L20:

        // 		printf( err_file, "%s:%d\t%s\n", { file_name[slist[gline][LOCAL_FILE_NO]],
        DeRef(_6992);
        _2 = (int)SEQ_PTR(_7slist);
        _6992 = (int)*(((s1_ptr)_2)->base + _gline);
        Ref(_6992);
        _0 = _6992;
        _2 = (int)SEQ_PTR(_6992);
        _6992 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_6992);
        DeRef(_0);
        _0 = _6992;
        _2 = (int)SEQ_PTR(_7file_name);
        if (!IS_ATOM_INT(_6992))
            _6992 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6992)->dbl));
        else
            _6992 = (int)*(((s1_ptr)_2)->base + _6992);
        Ref(_6992);
        DeRef(_0);
        DeRef(_6931);
        _2 = (int)SEQ_PTR(_7slist);
        _6931 = (int)*(((s1_ptr)_2)->base + _gline);
        Ref(_6931);
        _0 = _6931;
        _2 = (int)SEQ_PTR(_6931);
        _6931 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_6931);
        DeRef(_0);
        DeRef(_6875);
        _2 = (int)SEQ_PTR(_7slist);
        _6875 = (int)*(((s1_ptr)_2)->base + _gline);
        Ref(_6875);
        _0 = _6875;
        _2 = (int)SEQ_PTR(_6875);
        _6875 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6875);
        DeRef(_0);
        _0 = _6875;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        Ref(_6992);
        *((int *)(_2+4)) = _6992;
        Ref(_6931);
        *((int *)(_2+8)) = _6931;
        Ref(_6875);
        *((int *)(_2+12)) = _6875;
        _6875 = MAKE_SEQ(_1);
        DeRef(_0);
        EPrintf(_17err_file, _6995, _6875);

        // 	end for
        _i = _i + 1;
        goto L1E;
L1F:
        ;
    }
L1C:

    // 	puts(err_file, '\n')
    EPuts(_17err_file, 10);

    // 	close(err_file)
    EClose(_17err_file);

    // end procedure
    DeRefDS(_msg);
    DeRef(_6875);
    DeRef(_6931);
    DeRef(_6992);
    DeRef(_6927);
    return 0;
    ;
}


int _17call_crash_routines_for_real(int _routine, int _args)
{
    int _7004 = 0;
    int _0, _1, _2;
    

    // 	val[t_id] = routine[C_USER_ROUTINE]
    _2 = (int)SEQ_PTR(_routine);
    _7004 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7004);
    Ref(_7004);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17t_id);
    _1 = *(int *)_2;
    *(int *)_2 = _7004;
    DeRef(_1);

    // 	val[t_arglist] = args
    RefDS(_args);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17t_arglist);
    _1 = *(int *)_2;
    *(int *)_2 = _args;
    DeRef(_1);

    // 	call_stack = call_stack & {length(call_stack), pc, call_back_routine} 
    DeRef(_7004);
    _7004 = SEQ_PTR(_17call_stack)->length;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _7004;
    *((int *)(_2+8)) = _17pc;
    *((int *)(_2+12)) = _17call_back_routine;
    _7004 = MAKE_SEQ(_1);
    Concat((object_ptr)&_17call_stack, _17call_stack, (s1_ptr)_7004);

    // 	Code = call_back_code 
    RefDS(_17call_back_code);
    DeRef(_7Code);
    _7Code = _17call_back_code;

    // 	pc = 1 
    _17pc = 1;

    // 	if EMBEDDED then

    // 		call_proc( forward_do_exec, {})
    _0 = (int)_00[_7forward_do_exec].addr;
    (*(int (*)())_0)(
                         );
L1:

    // 	pc = call_stack[$-1]
    DeRef(_7004);
    _7004 = SEQ_PTR(_17call_stack)->length;
    _7004 = _7004 - 1;
    _2 = (int)SEQ_PTR(_17call_stack);
    _17pc = (int)*(((s1_ptr)_2)->base + _7004);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;

    // 	call_stack = call_stack[1..$-3]
    _7004 = SEQ_PTR(_17call_stack)->length;
    _7004 = _7004 - 3;
    rhs_slice_target = (object_ptr)&_17call_stack;
    RHS_Slice((s1_ptr)_17call_stack, 1, _7004);

    // 	Code = SymTab[call_stack[$]][S_CODE]
    _7004 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _7004 = (int)*(((s1_ptr)_2)->base + _7004);
    Ref(_7004);
    _0 = _7004;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_7004))
        _7004 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7004)->dbl));
    else
        _7004 = (int)*(((s1_ptr)_2)->base + _7004);
    Ref(_7004);
    DeRef(_0);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_7004);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	return val[t_return_val]
    DeRef(_7004);
    _2 = (int)SEQ_PTR(_17val);
    _7004 = (int)*(((s1_ptr)_2)->base + _17t_return_val);
    Ref(_7004);
    DeRefDS(_routine);
    DeRefDS(_args);
    return _7004;
    ;
}


int _17call_crash_routines()
{
    int _quit = 0;
    int _7195 = 0;
    int _7189 = 0;
    int _0, _1, _2;
    

    // 	if crash_count > 0 then
    if (_17crash_count <= 0)
        goto L1;

    // 	return
    return 0;
L1:

    // 	crash_count += 1
    _17crash_count = _17crash_count + 1;

    // 	err_file_name = "ex_crash.err"
    RefDS(_7191);
    DeRef(_17err_file_name);
    _17err_file_name = _7191;

    // 	for i = length(crash_list) to 1 by -1 do
    DeRef(_7189);
    _7189 = SEQ_PTR(_17crash_list)->length;
    { int _i;
        _i = _7189;
L2:
        if (_i < 1)
            goto L3;

        // 		quit = call_func(forward_general_callback, 
        DeRef(_7189);
        _2 = (int)SEQ_PTR(_17crash_list);
        _7189 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7189);
        _0 = _7189;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        Ref(_7189);
        *((int *)(_2+8)) = _7189;
        *((int *)(_2+12)) = 1;
        _7189 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _7195;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        _7195 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _7195;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _7189;
        RefDS(_7189);
        ((int *)_2)[2] = _7195;
        RefDS(_7195);
        _7195 = MAKE_SEQ(_1);
        DeRefDSi(_0);
        _1 = (int)SEQ_PTR(_7195);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_17forward_general_callback].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRef(_quit);
        _quit = _1;

        // 		if not equal(quit, 0) then
        DeRefDS(_7195);
        if (_quit == 0)
            _7195 = 1;
        else if (IS_ATOM_INT(_quit) && IS_ATOM_INT(0))
            _7195 = 0;
        else
            _7195 = (compare(_quit, 0) == 0);
        if (_7195 != 0)
            goto L4;

        // 		    return -- don't call the others
        DeRef(_quit);
        DeRefDS(_7189);
        return 0;
L4:

        // 	end for
        _i = _i + -1;
        goto L2;
L3:
        ;
    }

    // end procedure
    DeRef(_quit);
    DeRef(_7195);
    DeRef(_7189);
    return 0;
    ;
}


int _17quit_after_error()
{
    int _7200;
    int _0, _1, _2;
    

    // 	if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto L1;

    // 		if cleanup_cb > 0 then
    if (_7cleanup_cb <= 0)
        goto L2;

    // 			c_proc( cleanup_cb, {})
    call_c(0, _7cleanup_cb, _39);
L2:
L1:

    // 	if EWINDOWS then
    if (_7EWINDOWS == 0)
        goto L3;

    // 	puts(2, "\nPress Enter...\n")
    EPuts(2, _7202);

    // 	if getc(0) then
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _7200 = getc(xstdin);
        }
        else
            _7200 = getc(last_r_file_ptr);
    }
    else
        _7200 = getc(last_r_file_ptr);
    if (_7200 == 0)
        goto L4;
L4:
L3:

    // 	abort(1)
    UserCleanup(1);

    // end procedure
    return 0;
    ;
}


int _17RTFatalType(int _x)
{
    int _msg = 0;
    int _v = 0;
    int _vname = 0;
    int _7204 = 0;
    int _7213;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    // 	open_err_file()
    _17open_err_file();

    // 	a = Code[x]
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _x);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	vname = SymTab[a][S_NAME]
    _2 = (int)SEQ_PTR(_7SymTab);
    _7204 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7204);
    _2 = (int)SEQ_PTR(_7204);
    _vname = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_vname);

    // 	msg = sprintf("type_check error\n%s is ", {vname}) 
    _0 = _7204;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_vname);
    *((int *)(_2+4)) = _vname;
    _7204 = MAKE_SEQ(_1);
    DeRef(_0);
    _msg = EPrintf(-9999999, _7207, _7204);

    // 	v = sprint(val[a])
    DeRefDS(_7204);
    _2 = (int)SEQ_PTR(_17val);
    _7204 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7204);
    Ref(_7204);
    _v = _2sprint(_7204);

    // 	if length(v) > 70 - length(vname) then
    DeRef(_7204);
    _7204 = SEQ_PTR(_v)->length;
    _7213 = SEQ_PTR(_vname)->length;
    _7213 = 70 - _7213;
    if (_7204 <= _7213)
        goto L1;

    // 	v = v[1..70 - length(vname)]
    _7213 = SEQ_PTR(_vname)->length;
    _7213 = 70 - _7213;
    rhs_slice_target = (object_ptr)&_v;
    RHS_Slice((s1_ptr)_v, 1, _7213);

    // 	while length(v) and not find(v[$], ",}")  do
L2:
    _7213 = SEQ_PTR(_v)->length;
    if (_7213 == 0) {
        goto L3;
    }
    DeRef(_7204);
    _7204 = SEQ_PTR(_v)->length;
    _2 = (int)SEQ_PTR(_v);
    _7204 = (int)*(((s1_ptr)_2)->base + _7204);
    Ref(_7204);
    _0 = _7204;
    _7204 = find(_7204, _7223);
    DeRef(_0);
    _7204 = (_7204 == 0);
L4:
    if (_7204 == 0)
        goto L3;

    // 	    v = v[1..$-1]
    DeRef(_7204);
    _7204 = SEQ_PTR(_v)->length;
    _7204 = _7204 - 1;
    rhs_slice_target = (object_ptr)&_v;
    RHS_Slice((s1_ptr)_v, 1, _7204);

    // 	end while
    goto L2;
L3:

    // 	v = v & " ..."
    Concat((object_ptr)&_v, _v, (s1_ptr)_7229);
L1:

    // 	trace_back(msg & v)
    Concat((object_ptr)&_7204, _msg, (s1_ptr)_v);
    RefDS(_7204);
    _17trace_back(_7204);

    // 	call_crash_routines()
    _17call_crash_routines();

    // 	quit_after_error()
    _17quit_after_error();

    // end procedure
    DeRefDSi(_msg);
    DeRefDS(_v);
    DeRef(_vname);
    DeRefDS(_7204);
    return 0;
    ;
}


int _17RTFatal(int _msg)
{
    int _7232;
    int _0, _1, _2;
    

    // 	if find( 1, eval_stack ) then
    _7232 = find(1, _7eval_stack);
    if (_7232 == 0)
        goto L1;

    // 		eval_error[$] = msg
    _7232 = SEQ_PTR(_7eval_error)->length;
    RefDS(_msg);
    _2 = (int)SEQ_PTR(_7eval_error);
    _2 = (int)(((s1_ptr)_2)->base + _7232);
    _1 = *(int *)_2;
    *(int *)_2 = _msg;
    DeRefDS(_1);

    // 		return
    DeRefDS(_msg);
    return 0;
L1:

    // 	open_err_file()
    _17open_err_file();

    // 	trace_back(msg)
    RefDS(_msg);
    _17trace_back(_msg);

    // 	call_crash_routines() 
    _17call_crash_routines();

    // 	quit_after_error()
    _17quit_after_error();

    // end procedure
    DeRefDS(_msg);
    return 0;
    ;
}


int _17RTInternal(int _msg)
{
    int _7234 = 0;
    int _0, _1, _2;
    

    // 	puts(2, '\n' & msg & '\n')
    {
        int concat_list[3];

        concat_list[0] = 10;
        concat_list[1] = _msg;
        concat_list[2] = 10;
        Concat_N((object_ptr)&_7234, concat_list, 3);
    }
    EPuts(2, _7234);

    // 	? 1/0
    DeRefDS(_7234);
    RTFatal("divide by 0");
    StdPrint(1, _7234, 1);

    // end procedure
    DeRefDS(_msg);
    DeRef(_7234);
    return 0;
    ;
}


int _17one_trace_line(int _line)
{
    int _7237 = 0;
    int _0, _1, _2;
    

    // 	if ELINUX then
    if (_7ELINUX == 0)
        goto L1;

    // 	printf(trace_file, "%-78.78s\n", {line})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_line);
    *((int *)(_2+4)) = _line;
    _7237 = MAKE_SEQ(_1);
    EPrintf(_17trace_file, _7236, _7237);
    goto L2;
L1:

    // 	printf(trace_file, "%-77.77s\r\n", {line})
    _0 = _7237;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_line);
    *((int *)(_2+4)) = _line;
    _7237 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_17trace_file, _7238, _7237);
L2:

    // end procedure
    DeRefDS(_line);
    DeRef(_7237);
    return 0;
    ;
}


int _17load_debugger()
{
    int _7301 = 0;
    int _7240 = 0;
    int _0, _1, _2;
    

    // 	if platform() = DOS32 then

    // 	elsif no_source = 0 or full_debug then
    _7240 = (_7no_source == 0);
    if (_7240 != 0) {
        goto L1;
    }
L2:
    if (_7full_debug == 0)
        goto L3;
L1:

    // 		debugger = open_dll(debugger_name)
    Ref(_7debugger_name);
    _0 = _18open_dll(_7debugger_name);
    DeRef(_7debugger);
    _7debugger = _0;

    // 		if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto L4;

    // 			if platform() = LINUX  then

    // 				update_vars = define_c_proc( debugger, "_1update_vars", {})
    Ref(_7debugger);
    RefDS(_7246);
    RefDS(_39);
    _0 = _18define_c_proc(_7debugger, _7246, _39);
    _7update_vars = _0;

    // 				debug_main = define_c_func( debugger, "_1initialize", {E_SEQUENCE, E_SEQUENCE}, E_ATOM )
    DeRef(_7240);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 134217732;
    ((int *)_2)[2] = 134217732;
    _7240 = MAKE_SEQ(_1);
    Ref(_7debugger);
    RefDS(_7248);
    RefDS(_7240);
    _0 = _18define_c_func(_7debugger, _7248, _7240, 117440516);
    _7debug_main = _0;

    // 				set_object_cb = define_c_proc( debugger, "_1set_object", {E_OBJECT})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 150994948;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7251);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7251, _7240);
    _7set_object_cb = _0;

    // 				display_var_cb = define_c_proc( debugger, "_1display_var", {E_INTEGER})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7254);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7254, _7240);
    _7display_var_cb = _0;

    // 				erase_privates_cb = define_c_proc( debugger, "_1erase_privates", {E_INTEGER})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7257);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7257, _7240);
    _7erase_privates_cb = _0;

    // 				erase_symbol_cb = define_c_proc( debugger, "_1erase_symbol", {E_INTEGER})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7260);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7260, _7240);
    _7erase_symbol_cb = _0;

    // 				cleanup_cb = define_c_proc( debugger, "_1cleanup_debugger", {})
    Ref(_7debugger);
    RefDS(_7263);
    RefDS(_39);
    _0 = _18define_c_proc(_7debugger, _7263, _39);
    _7cleanup_cb = _0;

    // 				hide_debugger = define_c_proc( debugger, "_1hide_debugger", {})
    Ref(_7debugger);
    RefDS(_7265);
    RefDS(_39);
    _0 = _18define_c_proc(_7debugger, _7265, _39);
    _7hide_debugger = _0;

    // 				get_object_cb = define_c_func( debugger, "_1get_object", {}, E_OBJECT )
    Ref(_7debugger);
    RefDS(_7267);
    RefDS(_39);
    _0 = _18define_c_func(_7debugger, _7267, _39, 150994948);
    _7get_object_cb = _0;

    // 				debug_out = define_c_proc( debugger, "_1debug_out", {E_OBJECT} )
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 150994948;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7269);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7269, _7240);
    _7debug_out = _0;
    goto L5;
L6:

    // 				update_vars = define_c_proc( debugger, "update_vars", {})
    Ref(_7debugger);
    RefDS(_7272);
    RefDS(_39);
    _0 = _18define_c_proc(_7debugger, _7272, _39);
    _7update_vars = _0;

    // 				debug_main = define_c_func( debugger, "initialize", {E_SEQUENCE, E_SEQUENCE}, E_ATOM )
    DeRef(_7240);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 134217732;
    ((int *)_2)[2] = 134217732;
    _7240 = MAKE_SEQ(_1);
    Ref(_7debugger);
    RefDS(_7274);
    RefDS(_7240);
    _0 = _18define_c_func(_7debugger, _7274, _7240, 117440516);
    _7debug_main = _0;

    // 				set_object_cb = define_c_proc( debugger, "set_object", {E_OBJECT})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 150994948;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7277);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7277, _7240);
    _7set_object_cb = _0;

    // 				display_var_cb = define_c_proc( debugger, "display_var", {E_INTEGER})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7280);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7280, _7240);
    _7display_var_cb = _0;

    // 				erase_privates_cb = define_c_proc( debugger, "erase_privates", {E_INTEGER})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7283);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7283, _7240);
    _7erase_privates_cb = _0;

    // 				erase_symbol_cb = define_c_proc( debugger, "erase_symbol", {E_INTEGER})
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7286);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7286, _7240);
    _7erase_symbol_cb = _0;

    // 				cleanup_cb = define_c_proc( debugger, "cleanup_debugger", {})
    Ref(_7debugger);
    RefDS(_7289);
    RefDS(_39);
    _0 = _18define_c_proc(_7debugger, _7289, _39);
    _7cleanup_cb = _0;

    // 				hide_debugger = define_c_proc( debugger, "hide_debugger", {})
    Ref(_7debugger);
    RefDS(_7291);
    RefDS(_39);
    _0 = _18define_c_proc(_7debugger, _7291, _39);
    _7hide_debugger = _0;

    // 				get_object_cb = define_c_func( debugger, "get_object", {}, E_OBJECT )
    Ref(_7debugger);
    RefDS(_7293);
    RefDS(_39);
    _0 = _18define_c_func(_7debugger, _7293, _39, 150994948);
    _7get_object_cb = _0;

    // 				debug_out = define_c_proc( debugger, "debug_out", {E_OBJECT} )
    _0 = _7240;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 150994948;
    _7240 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    Ref(_7debugger);
    RefDS(_7295);
    RefDS(_7240);
    _0 = _18define_c_proc(_7debugger, _7295, _7240);
    _7debug_out = _0;
L5:

    // 			trace_func = define_c_proc( "", 
    _0 = _7240;
    _1 = NewS1(11);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_7get_value_cb);
    *((int *)(_2+4)) = _7get_value_cb;
    Ref(_7get_symbols_cb);
    *((int *)(_2+8)) = _7get_symbols_cb;
    Ref(_7get_line_cb);
    *((int *)(_2+12)) = _7get_line_cb;
    Ref(_7get_lines_cb);
    *((int *)(_2+16)) = _7get_lines_cb;
    Ref(_7set_break_cb);
    *((int *)(_2+20)) = _7set_break_cb;
    Ref(_7get_files_cb);
    *((int *)(_2+24)) = _7get_files_cb;
    Ref(_7set_trace_cb);
    *((int *)(_2+28)) = _7set_trace_cb;
    Ref(_7current_sub_cb);
    *((int *)(_2+32)) = _7current_sub_cb;
    Ref(_7get_pc_cb);
    *((int *)(_2+36)) = _7get_pc_cb;
    Ref(_7set_values_cb);
    *((int *)(_2+40)) = _7set_values_cb;
    Ref(_7set_debug_io_cb);
    *((int *)(_2+44)) = _7set_debug_io_cb;
    _7240 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _7240;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7240;
    RefDS(_7240);
    ((int *)_2)[2] = _7source_name;
    RefDS(_7source_name);
    _7240 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _7240;
    _7240 = call_c(1, _7debug_main, _7240);
    DeRefDS(_0);
    _0 = _7301;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 100663300;
    _7301 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_39);
    Ref(_7240);
    RefDS(_7301);
    _0 = _18define_c_proc(_39, _7240, _7301);
    _7trace_func = _0;

    // 			if trace_func = -1 then
    if (_7trace_func != -1)
        goto L7;

    // 				debugger = 0
    DeRef(_7debugger);
    _7debugger = 0;
L8:
    goto L7;
L4:

    // 			debugger = 0
    DeRef(_7debugger);
    _7debugger = 0;

    // 			printf( 1, "debugger %s failed to open\n", {debugger_name} )
    _0 = _7301;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_7debugger_name);
    *((int *)(_2+4)) = _7debugger_name;
    _7301 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(1, _7304, _7301);
L7:
L3:
L9:

    // end procedure
    DeRef(_7301);
    DeRef(_7240);
    return 0;
    ;
}


int _17opSTARTLINE()
{
    int _gline;
    int _sub;
    int _line = 0;
    int _w;
    int _7326 = 0;
    int _7324 = 0;
    int _7306 = 0;
    int _0, _1, _2;
    

    // 	if TraceOn	= 3 then
    if (_17TraceOn != 3)
        goto L1;

    // 		if trace_file = -1 then
    if (_17trace_file != -1)
        goto L2;

    // 		    trace_file = open("ctrace.out", "wb")
    _17trace_file = EOpen(_7308, _7309);

    // 		    if trace_file = -1 then
    if (_17trace_file != -1)
        goto L3;

    // 			RTFatal("Couldn't open ctrace.out")
    RefDS(_7312);
    _17RTFatal(_7312);

    // 			return
    return 0;
L3:
L2:

    // 		a = Code[pc+1]
    DeRef(_7306);
    _7306 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _7306);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 		if atom(slist[$]) then
    _7306 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _7306 = (int)*(((s1_ptr)_2)->base + _7306);
    Ref(_7306);
    _0 = _7306;
    _7306 = IS_ATOM(_7306);
    DeRef(_0);
    if (_7306 == 0)
        goto L4;

    // 			slist = s_expand(slist)
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L4:

    // 		line = sprintf("%.20s:%d\t%.80s",
    DeRef(_7306);
    _2 = (int)SEQ_PTR(_7slist);
    _7306 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7306);
    _0 = _7306;
    _2 = (int)SEQ_PTR(_7306);
    _7306 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_7306);
    DeRef(_0);
    _0 = _7306;
    _2 = (int)SEQ_PTR(_7file_name);
    if (!IS_ATOM_INT(_7306))
        _7306 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7306)->dbl));
    else
        _7306 = (int)*(((s1_ptr)_2)->base + _7306);
    Ref(_7306);
    DeRef(_0);
    Ref(_7306);
    _0 = _7306;
    _7306 = _11name_ext(_7306);
    DeRef(_0);
    DeRef(_7324);
    _2 = (int)SEQ_PTR(_7slist);
    _7324 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7324);
    _0 = _7324;
    _2 = (int)SEQ_PTR(_7324);
    _7324 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7324);
    DeRef(_0);
    DeRef(_7326);
    _2 = (int)SEQ_PTR(_7slist);
    _7326 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_7326);
    _0 = _7326;
    _2 = (int)SEQ_PTR(_7326);
    _7326 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7326);
    DeRef(_0);
    Ref(_7326);
    _0 = _7326;
    _7326 = _12fetch_line(_7326);
    DeRef(_0);
    _0 = _7326;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7306);
    *((int *)(_2+4)) = _7306;
    Ref(_7324);
    *((int *)(_2+8)) = _7324;
    RefDS(_7326);
    *((int *)(_2+12)) = _7326;
    _7326 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    DeRefi(_line);
    _line = EPrintf(-9999999, _7319, _7326);

    // 		trace_line += 1
    _17trace_line = _17trace_line + 1;

    // 		if trace_line >= 500 then
    if (_17trace_line < 500)
        goto L5;

    // 		    trace_line = 0
    _17trace_line = 0;

    // 		    one_trace_line("")
    RefDS(_39);
    _17one_trace_line(_39);

    // 		    one_trace_line("               ")
    RefDS(_7333);
    _17one_trace_line(_7333);

    // 		    flush(trace_file)
    _13flush(_17trace_file);

    // 		    if seek(trace_file, 0) then
    _0 = _7326;
    _7326 = _13seek(_17trace_file, 0);
    DeRefDS(_0);
    if (_7326 == 0)
        goto L6;
L6:
L5:

    // 		one_trace_line(line)
    RefDS(_line);
    _17one_trace_line(_line);

    // 		one_trace_line("")
    RefDS(_39);
    _17one_trace_line(_39);

    // 		one_trace_line("=== THE END ===")
    RefDS(_7335);
    _17one_trace_line(_7335);

    // 		one_trace_line("")
    RefDS(_39);
    _17one_trace_line(_39);

    // 		one_trace_line("")
    RefDS(_39);
    _17one_trace_line(_39);

    // 		one_trace_line("")
    RefDS(_39);
    _17one_trace_line(_39);

    // 		flush(trace_file)
    _13flush(_17trace_file);

    // 		w = where(trace_file)
    _w = _13where(_17trace_file);
    if (!IS_ATOM_INT(_w)) {
        _1 = (long)(DBL_PTR(_w)->dbl);
        DeRefDS(_w);
        _w = _1;
    }

    // 		if seek(trace_file, w-79*5) then -- back up 5 lines
    DeRef(_7326);
    _7326 = 395;
    _7326 = _w - 395;
    if ((long)((unsigned long)_7326 +(unsigned long) HIGH_BITS) >= 0)
        _7326 = NewDouble((double)_7326);
    Ref(_7326);
    _0 = _7326;
    _7326 = _13seek(_17trace_file, _7326);
    DeRef(_0);
    if (_7326 == 0)
        goto L7;
L7:
L1:

    // 	sub = call_stack[$]
    DeRef(_7326);
    _7326 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _sub = (int)*(((s1_ptr)_2)->base + _7326);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	gline = find_gline(sub, pc)
    _gline = _17find_gline(_sub, _17pc);
    if (!IS_ATOM_INT(_gline)) {
        _1 = (long)(DBL_PTR(_gline)->dbl);
        DeRefDS(_gline);
        _gline = _1;
    }

    // 	if length(traced_lines) = 10 then
    _7326 = SEQ_PTR(_7traced_lines)->length;
    if (_7326 != 10)
        goto L8;

    // 		traced_lines[1..9] = traced_lines[2..10]
    rhs_slice_target = (object_ptr)&_7326;
    RHS_Slice((s1_ptr)_7traced_lines, 2, 10);
    assign_slice_seq = (s1_ptr *)&_7traced_lines;
    AssignSlice(1, 9, _7326);

    // 		traced_lines[10] = gline
    _2 = (int)SEQ_PTR(_7traced_lines);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7traced_lines = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _gline;
    DeRef(_1);
    goto L9;
L8:

    // 		traced_lines &= gline
    Append(&_7traced_lines, _7traced_lines, _gline);
L9:

    // 	if TraceOn and debugger = -1 then
    if (_17TraceOn == 0) {
        goto LA;
    }
    DeRef(_7324);
    if (IS_ATOM_INT(_7debugger)) {
        _7324 = (_7debugger == -1);
    }
    else {
        _7324 = (DBL_PTR(_7debugger)->dbl == (double)-1);
    }
LB:
    if (_7324 == 0)
        goto LA;

    // 		load_debugger()
    _17load_debugger();
LA:

    // 	if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto LC;

    // 	if ((TraceOn and TraceOn < 3) or find( gline, break_points )) and in_trace < 2 then
    if (_17TraceOn == 0) {
        DeRef(_7324);
        _7324 = 0;
        goto LD;
    }
    DeRef(_7326);
    _7326 = (_17TraceOn < 3);
    _7324 = (_7326 != 0);
LD:
    if (_7324 != 0) {
        DeRef(_7326);
        _7326 = 1;
        goto LE;
    }
    DeRef(_7324);
    _7324 = find(_gline, _7break_points);
    _7326 = (_7324 != 0);
LE:
    if (_7326 == 0) {
        goto LF;
    }
    DeRef(_7326);
    _7326 = (_17in_trace < 2);
L10:
    if (_7326 == 0)
        goto LF;

    // 		if not TraceOn then
    if (_17TraceOn != 0)
        goto L11;

    // 			TraceOn = 1
    _17TraceOn = 1;
L11:

    // 		in_trace = 1
    _17in_trace = 1;

    // 		c_proc( trace_func, {gline})
    _0 = _7326;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _gline;
    _7326 = MAKE_SEQ(_1);
    DeRef(_0);
    call_c(0, _7trace_func, _7326);

    // 		in_trace = 0
    _17in_trace = 0;
LF:
LC:

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefi(_line);
    DeRef(_7326);
    DeRef(_7324);
    DeRef(_7306);
    return 0;
    ;
}


int _17pass_by_reference(int _sub)
{
    int _top;
    int _by_ref = 0;
    int _arg_ref = 0;
    int _7375 = 0;
    int _7370 = 0;
    int _7359 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sub)) {
        _1 = (long)(DBL_PTR(_sub)->dbl);
        DeRefDS(_sub);
        _sub = _1;
    }

    // 	if length(call_stack) <= 3 then
    _7359 = SEQ_PTR(_17call_stack)->length;
    if (_7359 > 3)
        goto L1;

    // 		return
    return 0;
L1:

    // 	sub = Code[pc+1]
    DeRef(_7359);
    _7359 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _sub = (int)*(((s1_ptr)_2)->base + _7359);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	arg_ref = SymTab[sub][S_BYREF]
    _2 = (int)SEQ_PTR(_7SymTab);
    _7359 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7359);
    DeRef(_arg_ref);
    _2 = (int)SEQ_PTR(_7359);
    _arg_ref = (int)*(((s1_ptr)_2)->base + 25);
    Ref(_arg_ref);

    // 	by_ref = call_stack[$-3]
    DeRef(_7359);
    _7359 = SEQ_PTR(_17call_stack)->length;
    _7359 = _7359 - 3;
    DeRef(_by_ref);
    _2 = (int)SEQ_PTR(_17call_stack);
    _by_ref = (int)*(((s1_ptr)_2)->base + _7359);
    Ref(_by_ref);

    // 	if atom(by_ref) then
    _7359 = IS_ATOM(_by_ref);
    if (_7359 == 0)
        goto L2;

    // 		return
    DeRef(_by_ref);
    DeRefDS(_arg_ref);
    DeRef(_7375);
    DeRef(_7370);
    return 0;
L2:

    // 	for i = 1 to length(by_ref) do
    DeRef(_7359);
    _7359 = SEQ_PTR(_by_ref)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _7359)
            goto L4;

        // 		if length(SymTab[by_ref[i]]) > 5 then
        DeRef(_7370);
        _2 = (int)SEQ_PTR(_by_ref);
        _7370 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7370);
        _0 = _7370;
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_7370))
            _7370 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7370)->dbl));
        else
            _7370 = (int)*(((s1_ptr)_2)->base + _7370);
        Ref(_7370);
        DeRef(_0);
        _0 = _7370;
        _7370 = SEQ_PTR(_7370)->length;
        DeRef(_0);
        if (_7370 <= 5)
            goto L5;

        // 			val[by_ref[i]] = val[arg_ref[i]]
        _2 = (int)SEQ_PTR(_by_ref);
        _7370 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7370);
        DeRef(_7375);
        _2 = (int)SEQ_PTR(_arg_ref);
        _7375 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7375);
        _0 = _7375;
        _2 = (int)SEQ_PTR(_17val);
        if (!IS_ATOM_INT(_7375))
            _7375 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7375)->dbl));
        else
            _7375 = (int)*(((s1_ptr)_2)->base + _7375);
        Ref(_7375);
        DeRef(_0);
        Ref(_7375);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_7370))
            _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7370)->dbl));
        else
            _2 = (int)(((s1_ptr)_2)->base + _7370);
        _1 = *(int *)_2;
        *(int *)_2 = _7375;
        DeRef(_1);
L5:

        // 	end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    // end procedure
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRef(_7375);
    DeRef(_7370);
    DeRef(_7359);
    return 0;
    ;
}


int _17opPROC()
{
    int _n;
    int _arg;
    int _sub;
    int _top;
    int _by_ref = 0;
    int _arg_ref = 0;
    int _7384 = 0;
    int _7385 = 0;
    int _7377 = 0;
    int _0, _1, _2, _3;
    

    // 	by_ref = {}
    RefDS(_39);
    _by_ref = _39;

    // 	sub = Code[pc+1] -- subroutine
    _7377 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _sub = (int)*(((s1_ptr)_2)->base + _7377);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	arg = SymTab[sub][S_NEXT] 
    _2 = (int)SEQ_PTR(_7SymTab);
    _7377 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7377);
    _2 = (int)SEQ_PTR(_7377);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	n = SymTab[sub][S_NUM_ARGS]
    DeRef(_7377);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7377 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7377);
    _2 = (int)SEQ_PTR(_7377);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 	SymTab[sub][S_ACTIVE] += 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _7385 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_7385);
    _0 = _7385;
    if (IS_ATOM_INT(_7385)) {
        _7385 = _7385 + 1;
        if (_7385 > MAXINT)
            _7385 = NewDouble((double)_7385);
    }
    else
        _7385 = binary_op(PLUS, 1, _7385);
    DeRef(_0);
    Ref(_7385);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _7385;
    DeRef(_1);

    // 	top = length(call_stack)
    _top = SEQ_PTR(_17call_stack)->length;

    // 	arg_ref = SymTab[sub][S_BYREF]
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7385);
    _2 = (int)SEQ_PTR(_7385);
    _arg_ref = (int)*(((s1_ptr)_2)->base + 25);
    Ref(_arg_ref);

    // 	pass_by_reference( sub )
    _17pass_by_reference(_sub);

    // 	if SymTab[sub][S_ACTIVE] > 1 then
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7385);
    _0 = _7385;
    _2 = (int)SEQ_PTR(_7385);
    _7385 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_7385);
    DeRef(_0);
    if (binary_op_a(LESSEQ, _7385, 1))
        goto L1;

    // 		for i = 1 to n do
    DeRef(_7385);
    _7385 = _n;
    { int _i;
        _i = 1;
L2:
        if (_i > _7385)
            goto L3;

        // 		    call_stack = append(call_stack, val[arg])   
        DeRef(_7384);
        _2 = (int)SEQ_PTR(_17val);
        _7384 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_7384);
        Ref(_7384);
        Append(&_17call_stack, _17call_stack, _7384);

        // 		    val[arg] = val[Code[pc+1+i]]
        DeRef(_7384);
        _7384 = _17pc + 1;
        if (_7384 > MAXINT)
            _7384 = NewDouble((double)_7384);
        _0 = _7384;
        if (IS_ATOM_INT(_7384)) {
            _7384 = _7384 + _i;
        }
        else {
            _7384 = NewDouble(DBL_PTR(_7384)->dbl + (double)_i);
        }
        DeRef(_0);
        _0 = _7384;
        _2 = (int)SEQ_PTR(_7Code);
        if (!IS_ATOM_INT(_7384))
            _7384 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7384)->dbl));
        else
            _7384 = (int)*(((s1_ptr)_2)->base + _7384);
        Ref(_7384);
        DeRef(_0);
        _0 = _7384;
        _2 = (int)SEQ_PTR(_17val);
        if (!IS_ATOM_INT(_7384))
            _7384 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7384)->dbl));
        else
            _7384 = (int)*(((s1_ptr)_2)->base + _7384);
        Ref(_7384);
        DeRef(_0);
        Ref(_7384);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _7384;
        DeRef(_1);

        // 		    if find( arg, arg_ref ) then
        DeRef(_7384);
        _7384 = find(_arg, _arg_ref);
        if (_7384 == 0)
            goto L4;

        // 		    	by_ref &= Code[pc+1+i]
        _7384 = _17pc + 1;
        if (_7384 > MAXINT)
            _7384 = NewDouble((double)_7384);
        _0 = _7384;
        if (IS_ATOM_INT(_7384)) {
            _7384 = _7384 + _i;
        }
        else {
            _7384 = NewDouble(DBL_PTR(_7384)->dbl + (double)_i);
        }
        DeRef(_0);
        _0 = _7384;
        _2 = (int)SEQ_PTR(_7Code);
        if (!IS_ATOM_INT(_7384))
            _7384 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7384)->dbl));
        else
            _7384 = (int)*(((s1_ptr)_2)->base + _7384);
        Ref(_7384);
        DeRef(_0);
        if (IS_SEQUENCE(_by_ref) && IS_ATOM(_7384)) {
            Ref(_7384);
            Append(&_by_ref, _by_ref, _7384);
        }
        else if (IS_ATOM(_by_ref) && IS_SEQUENCE(_7384)) {
        }
        else {
            Concat((object_ptr)&_by_ref, _by_ref, (s1_ptr)_7384);
        }
L4:

        // 		    arg = SymTab[arg][S_NEXT]
        DeRef(_7384);
        _2 = (int)SEQ_PTR(_7SymTab);
        _7384 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_7384);
        _2 = (int)SEQ_PTR(_7384);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 		end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 		while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L5:
    DeRef(_7384);
    _7384 = (_arg != 0);
    if (_7384 == 0) {
        goto L6;
    }
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7385);
    _0 = _7385;
    _2 = (int)SEQ_PTR(_7385);
    _7385 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_7385);
    DeRef(_0);
    _0 = _7385;
    if (IS_ATOM_INT(_7385)) {
        _7385 = (_7385 <= 3);
    }
    else {
        _7385 = binary_op(LESSEQ, _7385, 3);
    }
    DeRef(_0);
L7:
    if (_7385 <= 0) {
        if (_7385 == 0) {
            goto L6;
        }
        else {
            if (!IS_ATOM_INT(_7385) && DBL_PTR(_7385)->dbl == 0.0)
                goto L6;
        }
    }

    // 		    call_stack = append(call_stack, val[arg])   
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_17val);
    _7385 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7385);
    Ref(_7385);
    Append(&_17call_stack, _17call_stack, _7385);

    // 		    val[arg] = NOVALUE  
    RefDS(_7NOVALUE);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _7NOVALUE;
    DeRef(_1);

    // 		    arg = SymTab[arg][S_NEXT]
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7385);
    _2 = (int)SEQ_PTR(_7385);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto L5;
L6:

    // 		arg = SymTab[sub][S_TEMPS]
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7385);
    _2 = (int)SEQ_PTR(_7385);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		while arg != 0 do
L8:
    if (_arg == 0)
        goto L9;

    // 		    call_stack = append(call_stack, val[arg])   
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_17val);
    _7385 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7385);
    Ref(_7385);
    Append(&_17call_stack, _17call_stack, _7385);

    // 		    val[arg] = NOVALUE
    RefDS(_7NOVALUE);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _7NOVALUE;
    DeRef(_1);

    // 		    arg = SymTab[arg][S_NEXT]
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_7385);
    _2 = (int)SEQ_PTR(_7385);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 		end while
    goto L8;
L9:

    // 		call_stack = append( call_stack, SymTab[sub][S_GOTO][G_DEFAULT] )
    DeRef(_7385);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7385 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7385);
    _0 = _7385;
    _2 = (int)SEQ_PTR(_7385);
    _7385 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_7385);
    DeRef(_0);
    _0 = _7385;
    _2 = (int)SEQ_PTR(_7385);
    _7385 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_7385);
    DeRef(_0);
    Ref(_7385);
    Append(&_17call_stack, _17call_stack, _7385);
    goto LA;
L1:

    // 		for i = 1 to n do
    DeRef(_7385);
    _7385 = _n;
    { int _i;
        _i = 1;
LB:
        if (_i > _7385)
            goto LC;

        // 		    val[arg] = val[Code[pc+1+i]]
        DeRef(_7384);
        _7384 = _17pc + 1;
        if (_7384 > MAXINT)
            _7384 = NewDouble((double)_7384);
        _0 = _7384;
        if (IS_ATOM_INT(_7384)) {
            _7384 = _7384 + _i;
        }
        else {
            _7384 = NewDouble(DBL_PTR(_7384)->dbl + (double)_i);
        }
        DeRef(_0);
        _0 = _7384;
        _2 = (int)SEQ_PTR(_7Code);
        if (!IS_ATOM_INT(_7384))
            _7384 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7384)->dbl));
        else
            _7384 = (int)*(((s1_ptr)_2)->base + _7384);
        Ref(_7384);
        DeRef(_0);
        _0 = _7384;
        _2 = (int)SEQ_PTR(_17val);
        if (!IS_ATOM_INT(_7384))
            _7384 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7384)->dbl));
        else
            _7384 = (int)*(((s1_ptr)_2)->base + _7384);
        Ref(_7384);
        DeRef(_0);
        Ref(_7384);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _7384;
        DeRef(_1);

        // 		    if find( arg, arg_ref ) then
        DeRef(_7384);
        _7384 = find(_arg, _arg_ref);
        if (_7384 == 0)
            goto LD;

        // 		    	by_ref &= Code[pc+1+i]
        _7384 = _17pc + 1;
        if (_7384 > MAXINT)
            _7384 = NewDouble((double)_7384);
        _0 = _7384;
        if (IS_ATOM_INT(_7384)) {
            _7384 = _7384 + _i;
        }
        else {
            _7384 = NewDouble(DBL_PTR(_7384)->dbl + (double)_i);
        }
        DeRef(_0);
        _0 = _7384;
        _2 = (int)SEQ_PTR(_7Code);
        if (!IS_ATOM_INT(_7384))
            _7384 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7384)->dbl));
        else
            _7384 = (int)*(((s1_ptr)_2)->base + _7384);
        Ref(_7384);
        DeRef(_0);
        if (IS_SEQUENCE(_by_ref) && IS_ATOM(_7384)) {
            Ref(_7384);
            Append(&_by_ref, _by_ref, _7384);
        }
        else if (IS_ATOM(_by_ref) && IS_SEQUENCE(_7384)) {
        }
        else {
            Concat((object_ptr)&_by_ref, _by_ref, (s1_ptr)_7384);
        }
LD:

        // 		    arg = SymTab[arg][S_NEXT]
        DeRef(_7384);
        _2 = (int)SEQ_PTR(_7SymTab);
        _7384 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_7384);
        _2 = (int)SEQ_PTR(_7384);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 		end for
        _i = _i + 1;
        goto LB;
LC:
        ;
    }
LA:

    // 	call_stack = append( call_stack, by_ref )
    RefDS(_by_ref);
    Append(&_17call_stack, _17call_stack, _by_ref);

    // 	call_stack = append(call_stack, top)	
    Append(&_17call_stack, _17call_stack, _top);

    // 	pc = pc + 2 + n
    DeRef(_7384);
    _7384 = _17pc + 2;
    if ((long)((unsigned long)_7384 + (unsigned long)HIGH_BITS) >= 0) 
        _7384 = NewDouble((double)_7384);
    if (IS_ATOM_INT(_7384)) {
        _17pc = _7384 + _n;
    }
    else {
        _17pc = NewDouble(DBL_PTR(_7384)->dbl + (double)_n);
    }
    if (!IS_ATOM_INT(_17pc)) {
        _1 = (long)(DBL_PTR(_17pc)->dbl);
        DeRefDS(_17pc);
        _17pc = _1;
    }

    // 	if SymTab[sub][S_TOKEN] != r:PROC then
    DeRef(_7384);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7384 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7384);
    _0 = _7384;
    _2 = (int)SEQ_PTR(_7384);
    _7384 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_7384);
    DeRef(_0);
    if (binary_op_a(EQUALS, _7384, 27))
        goto LE;

    // 		pc += 1
    _17pc = _17pc + 1;
LE:

    // 	call_stack = append(call_stack, pc) 
    Append(&_17call_stack, _17call_stack, _17pc);

    // 	call_stack = append(call_stack, sub)
    Append(&_17call_stack, _17call_stack, _sub);

    // 	Code = SymTab[sub][S_CODE]
    DeRef(_7384);
    _2 = (int)SEQ_PTR(_7SymTab);
    _7384 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_7384);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_7384);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	pc = 1 
    _17pc = 1;

    // end procedure
    DeRef(_by_ref);
    DeRef(_arg_ref);
    DeRef(_7384);
    DeRef(_7385);
    DeRef(_7377);
    return 0;
    ;
}


