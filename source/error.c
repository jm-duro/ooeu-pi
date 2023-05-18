// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _9screen_output(int _f, int _msg)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_f)) {
        _1 = (long)(DBL_PTR(_f)->dbl);
        DeRefDS(_f);
        _f = _1;
    }

    //     puts(f, msg)
    EPuts(_f, _msg);

    // end procedure
    DeRefDS(_msg);
    return 0;
    ;
}


int _9Warning(int _msg)
{
    int _p = 0;
    int _706 = 0;
    int _707;
    int _0, _1, _2;
    

    //     if OpWarning and length(warning_list) < MAX_WARNINGS then
    if (_7OpWarning == 0) {
        goto L1;
    }
    _707 = SEQ_PTR(_9warning_list)->length;
    _707 = (_707 < 23);
L2:
    if (_707 == 0)
        goto L1;

    // 	if length(warning_list) = MAX_WARNINGS-1 then
    _707 = SEQ_PTR(_9warning_list)->length;
    DeRef(_706);
    _706 = 22;
    if (_707 != 22)
        goto L3;

    // 	    p = "Too many warnings - no more will be issued"
    RefDS(_712);
    DeRefi(_p);
    _p = _712;
    goto L4;
L3:

    // 	    p = sprintf("Warning: %s\n", {msg})
    _0 = _706;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_msg);
    *((int *)(_2+4)) = _msg;
    _706 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefi(_p);
    _p = EPrintf(-9999999, _713, _706);

    // 	    if find(p, warning_list) then
    DeRefDS(_706);
    _706 = find(_p, _9warning_list);
    if (_706 == 0)
        goto L5;

    // 		return -- duplicate
    DeRefDS(_msg);
    DeRefDSi(_p);
    return 0;
L5:
L4:

    // 	warning_list = append(warning_list, p)          
    RefDS(_p);
    Append(&_9warning_list, _9warning_list, _p);
L1:

    // end procedure
    DeRefDS(_msg);
    DeRefi(_p);
    DeRef(_706);
    return 0;
    ;
}


int _9ShowWarnings(int _errfile)
{
    int _719 = 0;
    int _718;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_errfile)) {
        _1 = (long)(DBL_PTR(_errfile)->dbl);
        DeRefDS(_errfile);
        _errfile = _1;
    }

    //     for i = 1 to length(warning_list) do
    _718 = SEQ_PTR(_9warning_list)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _718)
            goto L2;

        // 	if errfile = 0 then
        if (_errfile != 0)
            goto L3;

        // 	    screen_output(STDERR, warning_list[i])
        DeRef(_719);
        _2 = (int)SEQ_PTR(_9warning_list);
        _719 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_719);
        RefDS(_719);
        _9screen_output(2, _719);
        goto L4;
L3:

        // 	    puts(errfile, warning_list[i])
        DeRef(_719);
        _2 = (int)SEQ_PTR(_9warning_list);
        _719 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_719);
        EPuts(_errfile, _719);
L4:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return length(warning_list)
    DeRef(_719);
    _719 = SEQ_PTR(_9warning_list)->length;
    return _719;
    ;
}


int _9Cleanup(int _status)
{
    int _w;
    int _723;
    int _726;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_status)) {
        _1 = (long)(DBL_PTR(_status)->dbl);
        DeRefDS(_status);
        _status = _1;
    }

    //     w = ShowWarnings(0) 
    _w = _9ShowWarnings(0);

    //     if not TRANSLATE and 
    _723 = (0 == 0);
    if (_723 == 0) {
        _723 = 0;
        goto L1;
    }
    if (0 != 0) {
        _726 = 1;
        goto L2;
    }
    _726 = (_7EWINDOWS != 0);
L2:
    if (_726 != 0) {
        _726 = 1;
        goto L3;
    }
    _726 = (_7ELINUX != 0);
L3:
    _723 = (_726 != 0);
L1:
    if (_723 == 0) {
        goto L4;
    }
    if (_w != 0) {
        _723 = 1;
        goto L5;
    }
    _723 = (_9Errors != 0);
L5:
L6:
    if (_723 == 0)
        goto L4;

    // 	if getc(0) then -- prompt
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _723 = getc(xstdin);
        }
        else
            _723 = getc(last_r_file_ptr);
    }
    else
        _723 = getc(last_r_file_ptr);
    if (_723 == 0)
        goto L7;
L7:
L4:

    // 	if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto L8;

    // 		c_proc( cleanup_cb, {})
    call_c(0, _7cleanup_cb, _39);

    // 		debugger = 0
    DeRef(_7debugger);
    _7debugger = 0;
L8:

    //     abort(status)
    UserCleanup(_status);

    // end procedure
    return 0;
    ;
}


int _9OpenErrFile()
{
    int _733;
    int _0, _1, _2;
    

    //     TempErrFile = open(TempErrName, "w")
    _9TempErrFile = EOpen(_9TempErrName, _732);

    //     if TempErrFile = -1 then
    if (_9TempErrFile != -1)
        goto L1;

    // 	if length(TempErrName) > 0 then
    _733 = 6;

    // 	    screen_output(STDERR, "Can't create error message file: ")
    RefDS(_737);
    _9screen_output(2, _737);

    // 	    screen_output(STDERR, TempErrName)
    RefDS(_9TempErrName);
    _9screen_output(2, _9TempErrName);

    // 	    screen_output(STDERR, "\n")
    RefDS(_738);
    _9screen_output(2, _738);
L2:

    // 	abort(1) --Cleanup(1)
    UserCleanup(1);
L1:

    // end procedure
    return 0;
    ;
}


int _9ShowErr(int _f)
{
    int _745 = 0;
    int _739 = 0;
    int _0, _1, _2;
    

    //     if length(file_name) = 0 then
    _739 = SEQ_PTR(_7file_name)->length;
    if (_739 != 0)
        goto L1;

    // 	return
    return 0;
L1:

    //     if ThisLine[1] = END_OF_FILE then
    DeRef(_739);
    _2 = (int)SEQ_PTR(_9ThisLine);
    _739 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_739);
    if (binary_op_a(NOTEQ, _739, -21))
        goto L2;

    // 	screen_output(f, "<end-of-file>\n")
    RefDS(_743);
    _9screen_output(_f, _743);
    goto L3;
L2:

    // 	screen_output(f, ThisLine)
    Ref(_9ThisLine);
    _9screen_output(_f, _9ThisLine);
L3:

    //     for i = 1 to bp-2 do
    DeRef(_739);
    _739 = _9bp - 2;
    if ((long)((unsigned long)_739 +(unsigned long) HIGH_BITS) >= 0)
        _739 = NewDouble((double)_739);
    { int _i;
        _i = 1;
L4:
        if (binary_op_a(GREATER, _i, _739))
            goto L5;

        // 	if ThisLine[i] = '\t' then
        DeRef(_745);
        _2 = (int)SEQ_PTR(_9ThisLine);
        if (!IS_ATOM_INT(_i))
            _745 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _745 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_745);
        if (binary_op_a(NOTEQ, _745, 9))
            goto L6;

        // 	    screen_output(f, "\t")
        RefDS(_747);
        _9screen_output(_f, _747);
        goto L7;
L6:

        // 	    screen_output(f, " ")
        RefDS(_748);
        _9screen_output(_f, _748);
L7:

        //     end for
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
        goto L4;
L5:
        ;
        DeRef(_i);
    }

    //     screen_output(f, "^\n\n") 
    RefDS(_749);
    _9screen_output(_f, _749);

    // end procedure
    DeRef(_745);
    DeRef(_739);
    return 0;
    ;
}


int _9CompileErr(int _msg)
{
    int _errmsg = 0;
    int _750 = 0;
    int _752 = 0;
    int _0, _1, _2;
    

    //     if find(1, eval_stack) and not length(eval_error[$]) then
    _750 = find(1, _7eval_stack);
    if (_750 == 0) {
        goto L1;
    }
    _752 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _752 = (int)*(((s1_ptr)_2)->base + _752);
    RefDS(_752);
    _0 = _752;
    _752 = SEQ_PTR(_752)->length;
    DeRefDS(_0);
    _752 = (_752 == 0);
L2:
    if (_752 == 0)
        goto L1;

    // 		if ThisLine[1] = END_OF_FILE then
    DeRef(_752);
    _2 = (int)SEQ_PTR(_9ThisLine);
    _752 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_752);
    if (binary_op_a(NOTEQ, _752, -21))
        goto L3;

    // 			errmsg = msg -- "<end-of-file>\n"
    RefDS(_msg);
    DeRef(_errmsg);
    _errmsg = _msg;
    goto L4;
L3:

    // 			errmsg = msg & "\n" & ThisLine[1..bp-1] & "\n" 
    DeRef(_752);
    _752 = _9bp - 1;
    rhs_slice_target = (object_ptr)&_752;
    RHS_Slice((s1_ptr)_9ThisLine, 1, _752);
    {
        int concat_list[4];

        concat_list[0] = _738;
        concat_list[1] = _752;
        concat_list[2] = _738;
        concat_list[3] = _msg;
        Concat_N((object_ptr)&_errmsg, concat_list, 4);
    }

    // 			for i = 1 to bp - 2 do
    DeRefDS(_752);
    _752 = _9bp - 2;
    if ((long)((unsigned long)_752 +(unsigned long) HIGH_BITS) >= 0)
        _752 = NewDouble((double)_752);
    { int _i;
        _i = 1;
L5:
        if (binary_op_a(GREATER, _i, _752))
            goto L6;

        // 				if ThisLine[i] = '\t' then
        DeRef(_750);
        _2 = (int)SEQ_PTR(_9ThisLine);
        if (!IS_ATOM_INT(_i))
            _750 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _750 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_750);
        if (binary_op_a(NOTEQ, _750, 9))
            goto L7;

        // 					errmsg &= '\t'
        Append(&_errmsg, _errmsg, 9);
        goto L8;
L7:

        // 					errmsg &= 32
        Append(&_errmsg, _errmsg, 32);
L8:

        // 			end for
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
        goto L5;
L6:
        ;
        DeRef(_i);
    }

    // 			errmsg &=  "^\n"
    Concat((object_ptr)&_errmsg, _errmsg, (s1_ptr)_766);
L4:

    //     	eval_error[$] = errmsg
    DeRef(_750);
    _750 = SEQ_PTR(_7eval_error)->length;
    RefDS(_errmsg);
    _2 = (int)SEQ_PTR(_7eval_error);
    _2 = (int)(((s1_ptr)_2)->base + _750);
    _1 = *(int *)_2;
    *(int *)_2 = _errmsg;
    DeRefDS(_1);

    //     	geval_error = errmsg
    RefDS(_errmsg);
    DeRef(_7geval_error);
    _7geval_error = _errmsg;

    //     	call_proc(forward_putback,{{END_OF_FILE,0}})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -21;
    ((int *)_2)[2] = 0;
    _750 = MAKE_SEQ(_1);
    _0 = _750;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_750);
    *((int *)(_2+4)) = _750;
    _750 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    _1 = (int)SEQ_PTR(_750);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_putback].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    //     	return
    DeRefDS(_msg);
    DeRefDS(_errmsg);
    DeRefDS(_750);
    DeRef(_752);
    return 0;
    goto L9;
L1:

    //     elsif length(eval_error[$]) then
    DeRef(_750);
    _750 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _750 = (int)*(((s1_ptr)_2)->base + _750);
    RefDS(_750);
    _0 = _750;
    _750 = SEQ_PTR(_750)->length;
    DeRefDS(_0);
    if (_750 == 0)
        goto LA;

    //     	call_proc(forward_putback,{{END_OF_FILE,0}})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -21;
    ((int *)_2)[2] = 0;
    _750 = MAKE_SEQ(_1);
    _0 = _750;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_750);
    *((int *)(_2+4)) = _750;
    _750 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    _1 = (int)SEQ_PTR(_750);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_putback].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    //     	return
    DeRefDS(_msg);
    DeRef(_errmsg);
    DeRefDS(_750);
    DeRef(_752);
    return 0;
LA:
L9:

    //     Errors += 1
    _9Errors = _9Errors + 1;

    //     if length(file_name) then
    DeRef(_750);
    _750 = SEQ_PTR(_7file_name)->length;
    if (_750 == 0)
        goto LB;

    // 	errmsg = sprintf("%.99s:%d\n%s\n", {file_name[current_file_no], 
    _2 = (int)SEQ_PTR(_7file_name);
    _750 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_750);
    _0 = _750;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_750);
    *((int *)(_2+4)) = _750;
    *((int *)(_2+8)) = _7line_number;
    RefDS(_msg);
    *((int *)(_2+12)) = _msg;
    _750 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_errmsg);
    _errmsg = EPrintf(-9999999, _778, _750);
    goto LC;
LB:

    // 	errmsg = msg
    RefDS(_msg);
    DeRef(_errmsg);
    _errmsg = _msg;
LC:

    //     OpenErrFile() -- exits if error filename is ""
    _9OpenErrFile();

    //     screen_output(STDERR, errmsg)
    RefDS(_errmsg);
    _9screen_output(2, _errmsg);

    //     ShowErr(STDERR)
    _9ShowErr(2);

    //     puts(TempErrFile, errmsg) 
    EPuts(_9TempErrFile, _errmsg);

    //     ShowErr(TempErrFile) 
    _9ShowErr(_9TempErrFile);

    //     if ShowWarnings(TempErrFile) then
    _0 = _750;
    _750 = _9ShowWarnings(_9TempErrFile);
    DeRef(_0);
    if (_750 == 0)
        goto LD;
LD:

    //     puts(TempErrFile, "\n")
    EPuts(_9TempErrFile, _738);

    //     close(TempErrFile)
    EClose(_9TempErrFile);

    //     Cleanup(-1)
    _9Cleanup(-1);

    // end procedure
    DeRefDS(_msg);
    DeRef(_errmsg);
    DeRef(_750);
    DeRef(_752);
    return 0;
    ;
}


int _9InternalErr(int _msg)
{
    int _787 = 0;
    int _0, _1, _2;
    

    //     if TRANSLATE then

    // 	screen_output(STDERR, sprintf("\nInternal Error at %s:%d - %s\n", 
    _2 = (int)SEQ_PTR(_7file_name);
    _787 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_787);
    _0 = _787;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_787);
    *((int *)(_2+4)) = _787;
    *((int *)(_2+8)) = _7line_number;
    RefDS(_msg);
    *((int *)(_2+12)) = _msg;
    _787 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _787;
    _787 = EPrintf(-9999999, _789, _787);
    DeRefDS(_0);
    RefDS(_787);
    _9screen_output(2, _787);
L1:

    //     screen_output(STDERR, "\nPress Enter\n")
    RefDS(_793);
    _9screen_output(2, _793);

    //     if getc(0) then
    DeRef(_787);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _787 = getc(xstdin);
        }
        else
            _787 = getc(last_r_file_ptr);
    }
    else
        _787 = getc(last_r_file_ptr);
    if (_787 == 0)
        goto L2;
L2:

    //     ? 1/0
    DeRef(_787);
    RTFatal("divide by 0");
    StdPrint(1, _787, 1);

    //     abort(1)
    UserCleanup(1);

    // end procedure
    DeRefDS(_msg);
    DeRef(_787);
    return 0;
    ;
}


