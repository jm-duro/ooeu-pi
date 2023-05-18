// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17opERASE_PRIVATE_NAMES()
{
    int _9272 = 0;
    int _9270;
    int _0, _1, _2;
    

    // 	if TraceOn = 0 or TraceOn > 2 or not debugger or in_trace > 1 then
    _9270 = (_17TraceOn == 0);
    if (_9270 != 0) {
        _9270 = 1;
        goto L1;
    }
    _9272 = (_17TraceOn > 2);
    _9270 = (_9272 != 0);
L1:
    if (_9270 != 0) {
        DeRef(_9272);
        _9272 = 1;
        goto L2;
    }
    if (IS_ATOM_INT(_7debugger)) {
        _9270 = (_7debugger == 0);
    }
    else {
        _9270 = unary_op(NOT, _7debugger);
    }
    _9272 = (_9270 != 0);
L2:
    if (_9272 != 0) {
        goto L3;
    }
    DeRef(_9272);
    _9272 = (_17in_trace > 1);
L4:
    if (_9272 == 0)
        goto L5;
L3:

    // 		pc += 2
    _17pc = _17pc + 2;

    // 		return
    DeRef(_9272);
    return 0;
L5:

    // 	c_proc( erase_privates_cb, {Code[pc+1]})
    DeRef(_9272);
    _9272 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9272 = (int)*(((s1_ptr)_2)->base + _9272);
    Ref(_9272);
    _0 = _9272;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9272);
    *((int *)(_2+4)) = _9272;
    _9272 = MAKE_SEQ(_1);
    DeRef(_0);
    call_c(0, _7erase_privates_cb, _9272);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDS(_9272);
    return 0;
    ;
}


int _17opERASE_SYMBOL()
{
    int _9284 = 0;
    int _9282;
    int _0, _1, _2;
    

    // 	if TraceOn = 0 or TraceOn > 2 or not debugger or in_trace > 1 then
    _9282 = (_17TraceOn == 0);
    if (_9282 != 0) {
        _9282 = 1;
        goto L1;
    }
    _9284 = (_17TraceOn > 2);
    _9282 = (_9284 != 0);
L1:
    if (_9282 != 0) {
        DeRef(_9284);
        _9284 = 1;
        goto L2;
    }
    if (IS_ATOM_INT(_7debugger)) {
        _9282 = (_7debugger == 0);
    }
    else {
        _9282 = unary_op(NOT, _7debugger);
    }
    _9284 = (_9282 != 0);
L2:
    if (_9284 != 0) {
        goto L3;
    }
    DeRef(_9284);
    _9284 = (_17in_trace > 1);
L4:
    if (_9284 == 0)
        goto L5;
L3:

    // 		pc += 2
    _17pc = _17pc + 2;

    // 		return
    DeRef(_9284);
    return 0;
L5:

    // 	c_proc( erase_symbol_cb, {Code[pc+1]})
    DeRef(_9284);
    _9284 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9284 = (int)*(((s1_ptr)_2)->base + _9284);
    Ref(_9284);
    _0 = _9284;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9284);
    *((int *)(_2+4)) = _9284;
    _9284 = MAKE_SEQ(_1);
    DeRef(_0);
    call_c(0, _7erase_symbol_cb, _9284);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDS(_9284);
    return 0;
    ;
}


int _17set_object(int _obj)
{
    int _9294 = 0;
    int _0, _1, _2;
    

    // 	c_proc( set_object_cb, {obj})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_obj);
    *((int *)(_2+4)) = _obj;
    _9294 = MAKE_SEQ(_1);
    call_c(0, _7set_object_cb, _9294);

    // end procedure
    DeRef(_obj);
    DeRefDS(_9294);
    return 0;
    ;
}


int _17get_files()
{
    int _0, _1, _2;
    

    // 	set_object(file_name)
    RefDS(_7file_name);
    _17set_object(_7file_name);

    // 	return 0
    return 0;
    ;
}


int _17get_value(int _var)
{
    int _v;
    int _0, _1, _2;
    

    // 	v = 0
    _v = 0;

    // 	return v
    DeRefDS(_var);
    return 0;
    ;
}


int _17get_symbols()
{
    int _9301 = 0;
    int _0, _1, _2;
    

    // 	set_object( {SymTab, val} )
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7SymTab;
    RefDS(_7SymTab);
    ((int *)_2)[2] = _17val;
    RefDS(_17val);
    _9301 = MAKE_SEQ(_1);
    RefDS(_9301);
    _17set_object(_9301);

    // 	return 0
    DeRefDS(_9301);
    return 0;
    ;
}


int _17set_values(int _sym)
{
    int _9305 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	val[sym] = c_func( get_object_cb, {}) 
    _9305 = call_c(1, _7get_object_cb, _39);
    Ref(_9305);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _sym);
    _1 = *(int *)_2;
    *(int *)_2 = _9305;
    DeRef(_1);

    // 	return 0
    DeRef(_9305);
    return 0;
    ;
}


int _17get_line(int _line)
{
    int _9318 = 0;
    int _9309;
    int _9311 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_line)) {
        _1 = (long)(DBL_PTR(_line)->dbl);
        DeRefDS(_line);
        _line = _1;
    }

    // 	if line > 0 and line <= length( slist ) then
    _9309 = (_line > 0);
    if (_9309 == 0) {
        goto L1;
    }
    _9311 = SEQ_PTR(_7slist)->length;
    _9311 = (_line <= _9311);
L2:
    if (_9311 == 0)
        goto L1;

    // 		if atom(slist[line][SRC]) then
    DeRef(_9311);
    _2 = (int)SEQ_PTR(_7slist);
    _9311 = (int)*(((s1_ptr)_2)->base + _line);
    Ref(_9311);
    _0 = _9311;
    _2 = (int)SEQ_PTR(_9311);
    _9311 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9311);
    DeRef(_0);
    _0 = _9311;
    _9311 = IS_ATOM(_9311);
    DeRef(_0);
    if (_9311 == 0)
        goto L3;

    // 			slist[line][SRC] = fetch_line( slist[line][SRC] )
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _3 = (int)(_line + ((s1_ptr)_2)->base);
    DeRef(_9318);
    _2 = (int)SEQ_PTR(_7slist);
    _9318 = (int)*(((s1_ptr)_2)->base + _line);
    Ref(_9318);
    _0 = _9318;
    _2 = (int)SEQ_PTR(_9318);
    _9318 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9318);
    DeRef(_0);
    Ref(_9318);
    _0 = _9318;
    _9318 = _12fetch_line(_9318);
    DeRef(_0);
    RefDS(_9318);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9318;
    DeRef(_1);
L3:

    // 		set_object( slist[line] )
    DeRef(_9318);
    _2 = (int)SEQ_PTR(_7slist);
    _9318 = (int)*(((s1_ptr)_2)->base + _line);
    Ref(_9318);
    Ref(_9318);
    _17set_object(_9318);

    // 		return 0
    DeRef(_9318);
    DeRef(_9311);
    return 0;
L1:

    // 	set_object( {0,0,0,0} )
    _0 = _9318;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    *((int *)(_2+8)) = 0;
    *((int *)(_2+12)) = 0;
    *((int *)(_2+16)) = 0;
    _9318 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9318);
    _17set_object(_9318);
    ;
}


int _17get_lines(int _line1, int _line2)
{
    int _9341 = 0;
    int _9336 = 0;
    int _9326 = 0;
    int _0, _1, _2, _3;
    

    // 	if atom(slist[$]) then
    _9326 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _9326 = (int)*(((s1_ptr)_2)->base + _9326);
    Ref(_9326);
    _0 = _9326;
    _9326 = IS_ATOM(_9326);
    DeRef(_0);
    if (_9326 == 0)
        goto L1;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L1:

    // 	if line1 < 1 then
    if (binary_op_a(GREATEREQ, _line1, 1))
        goto L2;

    // 		set_object( {} )
    RefDS(_39);
    _17set_object(_39);

    // 		return 0
    DeRef(_line1);
    DeRef(_line2);
    DeRef(_9341);
    DeRef(_9336);
    DeRef(_9326);
    return 0;
L2:

    // 	if line2 = #FFFFFFFF then
    if (binary_op_a(NOTEQ, _line2, _9331))
        goto L3;

    // 		line2 = length(slist)
    DeRef(_line2);
    _line2 = SEQ_PTR(_7slist)->length;
L3:

    // 	if line1 > line2 then
    if (binary_op_a(LESSEQ, _line1, _line2))
        goto L4;

    // 		set_object({})
    RefDS(_39);
    _17set_object(_39);

    // 		return 0
    DeRef(_line1);
    DeRef(_line2);
    DeRef(_9341);
    DeRef(_9336);
    DeRef(_9326);
    return 0;
L4:

    // 	for i = line1 to line2 do
    Ref(_line2);
    DeRef(_9326);
    _9326 = _line2;
    { int _i;
        Ref(_line1);
        _i = _line1;
L5:
        if (binary_op_a(GREATER, _i, _9326))
            goto L6;

        // 		if atom(slist[i][SRC]) then
        DeRef(_9336);
        _2 = (int)SEQ_PTR(_7slist);
        if (!IS_ATOM_INT(_i))
            _9336 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _9336 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9336);
        _0 = _9336;
        _2 = (int)SEQ_PTR(_9336);
        _9336 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9336);
        DeRef(_0);
        _0 = _9336;
        _9336 = IS_ATOM(_9336);
        DeRef(_0);
        if (_9336 == 0)
            goto L7;

        // 			slist[i][SRC] = fetch_line(slist[i][SRC])
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_i))
            _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_9341);
        _2 = (int)SEQ_PTR(_7slist);
        if (!IS_ATOM_INT(_i))
            _9341 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _9341 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9341);
        _0 = _9341;
        _2 = (int)SEQ_PTR(_9341);
        _9341 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9341);
        DeRef(_0);
        Ref(_9341);
        _0 = _9341;
        _9341 = _12fetch_line(_9341);
        DeRef(_0);
        RefDS(_9341);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _9341;
        DeRef(_1);
L7:

        // 	end for
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

    // 	set_object( slist[line1..line2] )
    rhs_slice_target = (object_ptr)&_9341;
    RHS_Slice((s1_ptr)_7slist, _line1, _line2);
    RefDS(_9341);
    _17set_object(_9341);

    // 	return 0
    DeRef(_line1);
    DeRef(_line2);
    DeRefDS(_9341);
    DeRef(_9336);
    DeRef(_9326);
    return 0;
    ;
}


int _17get_pc()
{
    int _0, _1, _2;
    

    // 	return pc
    return _17pc;
    ;
}


int _17set_break(int _line, int _break)
{
    int _ix;
    int _9357 = 0;
    int _9356;
    int _9351 = 0;
    int _0, _1, _2;
    

    // 	ix = find( line, break_points )
    _ix = find(_line, _7break_points);

    // 	if break then
    if (_break == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_break) && DBL_PTR(_break)->dbl == 0.0)
            goto L1;
    }

    // 		if not ix then
    if (_ix != 0)
        goto L2;

    // 			break_points &= line
    Ref(_line);
    Append(&_7break_points, _7break_points, _line);
L3:
    goto L2;
L1:

    // 	elsif ix then
    if (_ix == 0)
        goto L4;

    // 		break_points = break_points[1..ix-1] & break_points[ix+1..$]
    DeRef(_9351);
    _9351 = _ix - 1;
    rhs_slice_target = (object_ptr)&_9351;
    RHS_Slice((s1_ptr)_7break_points, 1, _9351);
    _9356 = _ix + 1;
    DeRef(_9357);
    _9357 = SEQ_PTR(_7break_points)->length;
    rhs_slice_target = (object_ptr)&_9357;
    RHS_Slice((s1_ptr)_7break_points, _9356, _9357);
    Concat((object_ptr)&_7break_points, _9351, (s1_ptr)_9357);
L4:
L2:

    // 	return 0
    DeRef(_line);
    DeRef(_break);
    DeRef(_9357);
    DeRef(_9351);
    return 0;
    ;
}


int _17set_trace(int _on)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_on)) {
        _1 = (long)(DBL_PTR(_on)->dbl);
        DeRefDS(_on);
        _on = _1;
    }

    // 	if on = 4 then
    if (_on != 4)
        goto L1;

    // 		TraceOn = 0
    _17TraceOn = 0;

    // 		debugger = 0
    DeRef(_7debugger);
    _7debugger = 0;

    // 		c_proc( cleanup_cb, {})
    call_c(0, _7cleanup_cb, _39);
    goto L2;
L1:

    // 	elsif on = 5 then
    if (_on != 5)
        goto L3;

    // 		RTFatal( "program aborted" )
    RefDS(_9365);
    _17RTFatal(_9365);

    // 		return 5
    return 5;
    goto L2;
L3:

    // 		TraceOn = on
    _17TraceOn = _on;
L2:

    // 	return on
    return _on;
    ;
}


int _17current_sub()
{
    int _9369 = 0;
    int _0, _1, _2;
    

    // 	return call_stack[$]
    _9369 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9369 = (int)*(((s1_ptr)_2)->base + _9369);
    Ref(_9369);
    return _9369;
    ;
}


int _17opUPDATE_GLOBALS()
{
    int _9377;
    int _9374;
    int _0, _1, _2;
    

    // 	pc += 1
    _17pc = _17pc + 1;

    // 	if TraceOn > 0 and TraceOn < 3 and debugger then
    _9374 = (_17TraceOn > 0);
    if (_9374 == 0) {
        _9374 = 0;
        goto L1;
    }
    _9377 = (_17TraceOn < 3);
    _9374 = (_9377 != 0);
L1:
    if (_9374 == 0) {
        goto L2;
    }
L3:
    if (_7debugger == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_7debugger) && DBL_PTR(_7debugger)->dbl == 0.0)
            goto L2;
    }

    // 	c_proc( update_vars, {})
    call_c(0, _7update_vars, _39);
L2:

    // end procedure
    return 0;
    ;
}


int _17find_label(int _gotos, int _label)
{
    int _ix;
    int _9388 = 0;
    int _9383 = 0;
    int _9389 = 0;
    int _9379 = 0;
    int _0, _1, _2, _3;
    

    // 	ix = find( label, gotos[G_LABEL] )
    _2 = (int)SEQ_PTR(_gotos);
    _9379 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9379);
    _ix = find(_label, _9379);

    // 	if ix then
    if (_ix == 0)
        goto L1;

    // 		return ix
    DeRefDS(_gotos);
    DeRefDS(_label);
    DeRef(_9379);
    return _ix;
L1:

    // 	for i = 1 to length(gotos[G_LABEL]) do
    DeRef(_9379);
    _2 = (int)SEQ_PTR(_gotos);
    _9379 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9379);
    _0 = _9379;
    _9379 = SEQ_PTR(_9379)->length;
    DeRef(_0);
    { int _i;
        _i = 1;
L2:
        if (_i > _9379)
            goto L3;

        // 		if length(gotos[G_LABEL][i]) = 3 and label[1] = gotos[G_LABEL][i][1] 
        DeRef(_9383);
        _2 = (int)SEQ_PTR(_gotos);
        _9383 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9383);
        _0 = _9383;
        _2 = (int)SEQ_PTR(_9383);
        _9383 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9383);
        DeRef(_0);
        _0 = _9383;
        _9383 = SEQ_PTR(_9383)->length;
        DeRef(_0);
        _9383 = (_9383 == 3);
        if (_9383 == 0) {
            _9383 = 0;
            goto L4;
        }
        DeRef(_9388);
        _2 = (int)SEQ_PTR(_label);
        _9388 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9388);
        DeRef(_9389);
        _2 = (int)SEQ_PTR(_gotos);
        _9389 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9389);
        _0 = _9389;
        _2 = (int)SEQ_PTR(_9389);
        _9389 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9389);
        DeRef(_0);
        _0 = _9389;
        _2 = (int)SEQ_PTR(_9389);
        _9389 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9389);
        DeRef(_0);
        _0 = _9389;
        if (IS_ATOM_INT(_9388) && IS_ATOM_INT(_9389)) {
            _9389 = (_9388 == _9389);
        }
        else {
            _9389 = binary_op(EQUALS, _9388, _9389);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_9389))
            _9383 = (_9389 != 0);
        else
            _9383 = DBL_PTR(_9389)->dbl != 0.0;
L4:
        if (_9383 == 0) {
            goto L5;
        }
        DeRef(_9388);
        _2 = (int)SEQ_PTR(_gotos);
        _9388 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9388);
        _0 = _9388;
        _2 = (int)SEQ_PTR(_9388);
        _9388 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9388);
        DeRef(_0);
        _0 = _9388;
        _2 = (int)SEQ_PTR(_9388);
        _9388 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_9388);
        DeRef(_0);
        _0 = _9388;
        _2 = (int)SEQ_PTR(_17val);
        if (!IS_ATOM_INT(_9388))
            _9388 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9388)->dbl));
        else
            _9388 = (int)*(((s1_ptr)_2)->base + _9388);
        Ref(_9388);
        DeRef(_0);
        DeRef(_9383);
        _2 = (int)SEQ_PTR(_label);
        _9383 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_9383);
        _0 = _9383;
        if (_9388 == _9383)
            _9383 = 1;
        else if (IS_ATOM_INT(_9388) && IS_ATOM_INT(_9383))
            _9383 = 0;
        else
            _9383 = (compare(_9388, _9383) == 0);
        DeRef(_0);
L6:
        if (_9383 == 0)
            goto L5;

        // 			return i
        DeRefDS(_gotos);
        DeRefDS(_label);
        DeRef(_9388);
        DeRef(_9383);
        DeRef(_9389);
        DeRef(_9379);
        return _i;
L5:

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	ix = find( label[1], gotos[G_DEFAULT][1] )
    DeRef(_9383);
    _2 = (int)SEQ_PTR(_label);
    _9383 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9383);
    DeRef(_9388);
    _2 = (int)SEQ_PTR(_gotos);
    _9388 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9388);
    _0 = _9388;
    _2 = (int)SEQ_PTR(_9388);
    _9388 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9388);
    DeRef(_0);
    _ix = find(_9383, _9388);

    // 	if ix then
    if (_ix == 0)
        goto L7;

    // 		label[2] = gotos[G_DEFAULT][2][ix]
    DeRef(_9388);
    _2 = (int)SEQ_PTR(_gotos);
    _9388 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9388);
    _0 = _9388;
    _2 = (int)SEQ_PTR(_9388);
    _9388 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_9388);
    DeRef(_0);
    _0 = _9388;
    _2 = (int)SEQ_PTR(_9388);
    _9388 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_9388);
    DeRef(_0);
    Ref(_9388);
    _2 = (int)SEQ_PTR(_label);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _label = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _9388;
    DeRef(_1);

    // 		gotos[G_DEFAULT][1] = {}
    _2 = (int)SEQ_PTR(_gotos);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _gotos = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    // 		return find_label( gotos, label )
    RefDS(_gotos);
    DeRef(_9383);
    _9383 = _gotos;
    RefDS(_label);
    DeRef(_9388);
    _9388 = _label;
    RefDS(_9383);
    RefDS(_9388);
    _0 = _9388;
    _9388 = _17find_label(_9383, _9388);
    DeRefDS(_0);
    DeRefDS(_gotos);
    DeRefDS(_label);
    DeRefDS(_9383);
    DeRef(_9389);
    DeRef(_9379);
    return _9388;
L7:

    // 	return 0
    DeRefDS(_gotos);
    DeRefDS(_label);
    DeRef(_9388);
    DeRef(_9383);
    DeRef(_9389);
    DeRef(_9379);
    return 0;
    ;
}


int _17opDEFAULT_GOTO()
{
    int _file;
    int _ix;
    int _sub;
    int _fx;
    int _label = 0;
    int _gotos = 0;
    int _9412 = 0;
    int _9427 = 0;
    int _0, _1, _2, _3;
    

    // 	file = Code[pc+1]
    _9412 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _file = (int)*(((s1_ptr)_2)->base + _9412);
    if (!IS_ATOM_INT(_file))
        _file = (long)DBL_PTR(_file)->dbl;

    // 	label = val[Code[pc+2]]
    _9412 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _9412 = (int)*(((s1_ptr)_2)->base + _9412);
    Ref(_9412);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9412))
        _label = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9412)->dbl));
    else
        _label = (int)*(((s1_ptr)_2)->base + _9412);
    Ref(_label);

    // 	sub = call_stack[$]
    DeRef(_9412);
    _9412 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _sub = (int)*(((s1_ptr)_2)->base + _9412);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	gotos = SymTab[sub][S_GOTO]
    _2 = (int)SEQ_PTR(_7SymTab);
    _9412 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_9412);
    _2 = (int)SEQ_PTR(_9412);
    _gotos = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_gotos);

    // 	fx = find( file, gotos[G_DEFAULT][1] )
    DeRef(_9412);
    _2 = (int)SEQ_PTR(_gotos);
    _9412 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9412);
    _0 = _9412;
    _2 = (int)SEQ_PTR(_9412);
    _9412 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9412);
    DeRef(_0);
    _fx = find(_file, _9412);

    // 	if not fx then
    if (_fx != 0)
        goto L1;

    // 		gotos[G_DEFAULT][1] &= file
    _2 = (int)SEQ_PTR(_gotos);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _gotos = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _9427 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9427);
    if (IS_SEQUENCE(_9427) && IS_ATOM(_file)) {
        Append(&_9427, _9427, _file);
    }
    else if (IS_ATOM(_9427) && IS_SEQUENCE(_file)) {
    }
    else {
        Concat((object_ptr)&_9427, _9427, (s1_ptr)_file);
    }
    RefDS(_9427);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9427;
    DeRef(_1);

    // 		gotos[G_DEFAULT][2] = append( gotos[G_DEFAULT][2], label )
    _2 = (int)SEQ_PTR(_gotos);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _gotos = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    DeRef(_9412);
    _2 = (int)SEQ_PTR(_gotos);
    _9412 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9412);
    _0 = _9412;
    _2 = (int)SEQ_PTR(_9412);
    _9412 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_9412);
    DeRef(_0);
    Ref(_label);
    Append(&_9412, _9412, _label);
    RefDS(_9412);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _9412;
    DeRef(_1);
    goto L2;
L1:

    // 		gotos[G_DEFAULT][2][fx] = label
    _2 = (int)SEQ_PTR(_gotos);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _gotos = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(object_ptr)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(object_ptr)_3 = MAKE_SEQ(_2);
    }
    _3 = (int)(2 + ((s1_ptr)_2)->base);
    Ref(_label);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _fx);
    _1 = *(int *)_2;
    *(int *)_2 = _label;
    DeRef(_1);
L2:

    // 	SymTab[sub][S_GOTO] = gotos
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    RefDS(_gotos);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _gotos;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_label);
    DeRefDS(_gotos);
    DeRef(_9412);
    DeRef(_9427);
    return 0;
    ;
}


int _17opIS_GOTO()
{
    int _file;
    int _ix;
    int _sub;
    int _label = 0;
    int _gotos = 0;
    int _9450 = 0;
    int _9439 = 0;
    int _0, _1, _2, _3;
    

    // 	file = Code[pc+1]
    _9439 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _file = (int)*(((s1_ptr)_2)->base + _9439);
    if (!IS_ATOM_INT(_file))
        _file = (long)DBL_PTR(_file)->dbl;

    // 	label = {file, val[Code[pc+2]]}
    _9439 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _9439 = (int)*(((s1_ptr)_2)->base + _9439);
    Ref(_9439);
    _0 = _9439;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9439))
        _9439 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9439)->dbl));
    else
        _9439 = (int)*(((s1_ptr)_2)->base + _9439);
    Ref(_9439);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _file;
    ((int *)_2)[2] = _9439;
    Ref(_9439);
    _label = MAKE_SEQ(_1);

    // 	sub = call_stack[$]
    DeRef(_9439);
    _9439 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _sub = (int)*(((s1_ptr)_2)->base + _9439);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	gotos = SymTab[sub][S_GOTO]
    _2 = (int)SEQ_PTR(_7SymTab);
    _9439 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_9439);
    _2 = (int)SEQ_PTR(_9439);
    _gotos = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_gotos);

    // 	gotos[G_DEFAULT][1] = {}
    _2 = (int)SEQ_PTR(_gotos);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _gotos = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    // 	ix = find_label( gotos, label )
    RefDS(_gotos);
    RefDS(_label);
    _ix = _17find_label(_gotos, _label);
    if (!IS_ATOM_INT(_ix)) {
        _1 = (long)(DBL_PTR(_ix)->dbl);
        DeRefDS(_ix);
        _ix = _1;
    }

    // 	if ix then
    if (_ix == 0)
        goto L1;

    // 		val[Code[pc+3]] = 1
    _9450 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _9450 = (int)*(((s1_ptr)_2)->base + _9450);
    Ref(_9450);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_9450))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_9450)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _9450);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
    goto L2;
L1:

    // 		val[Code[pc+3]] = 0
    DeRef(_9450);
    _9450 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _9450 = (int)*(((s1_ptr)_2)->base + _9450);
    Ref(_9450);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_9450))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_9450)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _9450);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L2:

    // 	pc += 4
    _17pc = _17pc + 4;

    // end procedure
    DeRef(_label);
    DeRef(_gotos);
    DeRef(_9450);
    DeRef(_9439);
    return 0;
    ;
}


int _17opGOTO()
{
    int _label = 0;
    int _gotos = 0;
    int _gx;
    int _sub;
    int _ix;
    int _fx;
    int _9457 = 0;
    int _0, _1, _2;
    

    // 	ix = Code[pc+1]
    _9457 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _ix = (int)*(((s1_ptr)_2)->base + _9457);
    if (!IS_ATOM_INT(_ix))
        _ix = (long)DBL_PTR(_ix)->dbl;

    // 	sub = call_stack[$]
    _9457 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _sub = (int)*(((s1_ptr)_2)->base + _9457);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	fx = Code[pc+2]
    _9457 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _fx = (int)*(((s1_ptr)_2)->base + _9457);
    if (!IS_ATOM_INT(_fx))
        _fx = (long)DBL_PTR(_fx)->dbl;

    // 	gotos = SymTab[sub][S_GOTO]
    _2 = (int)SEQ_PTR(_7SymTab);
    _9457 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_9457);
    _2 = (int)SEQ_PTR(_9457);
    _gotos = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_gotos);

    // 	if atom(gotos) then
    DeRef(_9457);
    _9457 = IS_ATOM(_gotos);
    if (_9457 == 0)
        goto L1;

    // 		RTFatal("invalid goto target")
    RefDS(_9466);
    _17RTFatal(_9466);

    // 		return
    DeRef(_gotos);
    return 0;
L1:

    // 	label = {fx, val[ix] }
    DeRef(_9457);
    _2 = (int)SEQ_PTR(_17val);
    _9457 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_9457);
    DeRef(_label);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _fx;
    ((int *)_2)[2] = _9457;
    Ref(_9457);
    _label = MAKE_SEQ(_1);

    // 	gx = find_label( gotos, label )
    Ref(_gotos);
    RefDS(_label);
    _gx = _17find_label(_gotos, _label);
    if (!IS_ATOM_INT(_gx)) {
        _1 = (long)(DBL_PTR(_gx)->dbl);
        DeRefDS(_gx);
        _gx = _1;
    }

    // 	if not gx then
    if (_gx != 0)
        goto L2;

    // 		if Code[pc+3] then
    DeRef(_9457);
    _9457 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _9457 = (int)*(((s1_ptr)_2)->base + _9457);
    Ref(_9457);
    if (_9457 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_9457) && DBL_PTR(_9457)->dbl == 0.0)
            goto L3;
    }

    // 			RTFatal("invalid goto target: " & pretty_source(label[2]) )
    DeRef(_9457);
    _2 = (int)SEQ_PTR(_label);
    _9457 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_9457);
    Ref(_9457);
    _0 = _9457;
    _9457 = _6pretty_source(_9457);
    DeRef(_0);
    Concat((object_ptr)&_9457, _9473, (s1_ptr)_9457);
    RefDS(_9457);
    _17RTFatal(_9457);

    // 			return
    DeRefDS(_label);
    DeRef(_gotos);
    DeRefDS(_9457);
    return 0;
    goto L4;
L3:

    // 			pc += 4
    _17pc = _17pc + 4;
L5:
    goto L4;
L2:

    // 		pc = gotos[2][gx]
    DeRef(_9457);
    _2 = (int)SEQ_PTR(_gotos);
    _9457 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_9457);
    _2 = (int)SEQ_PTR(_9457);
    _17pc = (int)*(((s1_ptr)_2)->base + _gx);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;
L4:

    // end procedure
    DeRef(_label);
    DeRef(_gotos);
    DeRef(_9457);
    return 0;
    ;
}


int _17eval_exec()
{
    int _op;
    int _9481 = 0;
    int _9480;
    int _0, _1, _2;
    

    // 	keep_running = TRUE
    _17keep_running = 1;

    // 	while keep_running and length(eval_error[$]) = 0 do 
L1:
    if (_17keep_running == 0) {
        goto L2;
    }
    DeRef(_9481);
    _9481 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _9481 = (int)*(((s1_ptr)_2)->base + _9481);
    RefDS(_9481);
    _0 = _9481;
    _9481 = SEQ_PTR(_9481)->length;
    DeRefDS(_0);
    _9481 = (_9481 == 0);
L3:
    if (_9481 == 0)
        goto L2;

    // 		op = Code[pc]
    _2 = (int)SEQ_PTR(_7Code);
    _op = (int)*(((s1_ptr)_2)->base + _17pc);
    if (!IS_ATOM_INT(_op))
        _op = (long)DBL_PTR(_op)->dbl;

    // 		call_proc(operation[op], {}) -- opcodes start at 1
    DeRef(_9481);
    _2 = (int)SEQ_PTR(_17operation);
    _9481 = (int)*(((s1_ptr)_2)->base + _op);
    _0 = (int)_00[_9481].addr;
    (*(int (*)())_0)(
                         );

    // 	end while
    goto L1;
L2:

    // 	keep_running = TRUE -- so higher-level do_exec() will keep running
    _17keep_running = 1;

    // end procedure
    DeRef(_9481);
    return 0;
    ;
}


int _17opEVAL()
{
    int _eval_code = 0;
    int _ix;
    int _new_syms;
    int _pc_start;
    int _top;
    int _temp_top;
    int _gline;
    int _eval_target;
    int _with_trace;
    int _start_line;
    int _9528 = 0;
    int _9558 = 0;
    int _9489 = 0;
    int _9527 = 0;
    int _0, _1, _2, _3;
    

    // 	a = Code[pc+1]
    _9489 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9489);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	top = length(call_stack)
    _top = SEQ_PTR(_17call_stack)->length;

    // 	if atom(val[a]) then
    _2 = (int)SEQ_PTR(_17val);
    _9489 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9489);
    _0 = _9489;
    _9489 = IS_ATOM(_9489);
    DeRef(_0);
    if (_9489 == 0)
        goto L1;

    // 		RTFatal("parameter to eval must be a sequence")
    RefDS(_9494);
    _17RTFatal(_9494);

    // 		return
    return 0;
L1:

    // 	top = length(call_stack)
    _top = SEQ_PTR(_17call_stack)->length;

    // 	if call_stack[$] != TopLevelSub then
    DeRef(_9489);
    _9489 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9489 = (int)*(((s1_ptr)_2)->base + _9489);
    Ref(_9489);
    if (binary_op_a(EQUALS, _9489, _7TopLevelSub))
        goto L2;

    // 		HidePrivates( call_stack[$], 0 )
    DeRef(_9489);
    _9489 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9489 = (int)*(((s1_ptr)_2)->base + _9489);
    Ref(_9489);
    Ref(_9489);
    _11HidePrivates(_9489, 0);
L2:

    // 	eval_code = val[a]
    DeRef(_eval_code);
    _2 = (int)SEQ_PTR(_17val);
    _eval_code = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_eval_code);

    // 	target = Code[pc+2]
    DeRef(_9489);
    _9489 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9489);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	eval_target = target
    _eval_target = _17target;

    // 	eval_stack &= 1
    Append(&_7eval_stack, _7eval_stack, 1);

    // 	eval_error = append( eval_error, "" )
    RefDS(_39);
    Append(&_7eval_error, _7eval_error, _39);

    // 	gline = find_gline( call_stack[$], pc )
    _9489 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9489 = (int)*(((s1_ptr)_2)->base + _9489);
    Ref(_9489);
    Ref(_9489);
    _gline = _17find_gline(_9489, _17pc);
    if (!IS_ATOM_INT(_gline)) {
        _1 = (long)(DBL_PTR(_gline)->dbl);
        DeRefDS(_gline);
        _gline = _1;
    }

    // 	if atom(slist[$]) then
    DeRef(_9489);
    _9489 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _9489 = (int)*(((s1_ptr)_2)->base + _9489);
    Ref(_9489);
    _0 = _9489;
    _9489 = IS_ATOM(_9489);
    DeRef(_0);
    if (_9489 == 0)
        goto L3;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L3:

    // 	start_line = length(slist)
    _start_line = SEQ_PTR(_7slist)->length;

    // 	eval_file_no &= slist[gline][LOCAL_FILE_NO]
    DeRef(_9489);
    _2 = (int)SEQ_PTR(_7slist);
    _9489 = (int)*(((s1_ptr)_2)->base + _gline);
    Ref(_9489);
    _0 = _9489;
    _2 = (int)SEQ_PTR(_9489);
    _9489 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9489);
    DeRef(_0);
    if (IS_SEQUENCE(_7eval_file_no) && IS_ATOM(_9489)) {
        Ref(_9489);
        Append(&_7eval_file_no, _7eval_file_no, _9489);
    }
    else if (IS_ATOM(_7eval_file_no) && IS_SEQUENCE(_9489)) {
    }
    else {
        Concat((object_ptr)&_7eval_file_no, _7eval_file_no, (s1_ptr)_9489);
    }

    // 	with_trace = and_bits( slist[gline][OPTIONS], SOP_TRACE )
    DeRef(_9489);
    _2 = (int)SEQ_PTR(_7slist);
    _9489 = (int)*(((s1_ptr)_2)->base + _gline);
    Ref(_9489);
    _0 = _9489;
    _2 = (int)SEQ_PTR(_9489);
    _9489 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_9489);
    DeRef(_0);
    if (IS_ATOM_INT(_9489)) {
        _with_trace = (_9489 & 1);
    }
    else {
        _with_trace = binary_op(AND_BITS, _9489, 1);
    }
    if (!IS_ATOM_INT(_with_trace)) {
        _1 = (long)(DBL_PTR(_with_trace)->dbl);
        DeRefDS(_with_trace);
        _with_trace = _1;
    }

    // 	slist &= 0
    Append(&_7slist, _7slist, 0);

    // 	ix = find( "_eval_", file_name )
    _ix = find(_9521, _7file_name);

    // 	if not ix then --equal( file_name[$], "_eval_") then
    if (_ix != 0)
        goto L4;

    // 		file_name = append(file_name, "_eval_")
    RefDS(_9521);
    Append(&_7file_name, _7file_name, _9521);

    // 		current_file_no = length(file_name)
    _7current_file_no = SEQ_PTR(_7file_name)->length;

    // 		eval_file = current_file_no
    _7eval_file = _7current_file_no;

    // 		line_number = 0
    _7line_number = 0;

    // 		SymTab[eval_sym][S_FIRSTLINE] = length(slist)+1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9528);
    _9528 = SEQ_PTR(_7slist)->length;
    _9528 = _9528 + 1;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 17);
    _1 = *(int *)_2;
    *(int *)_2 = _9528;
    DeRef(_1);
L4:

    // 	ix = find( '\n', eval_code )
    _ix = find(10, _eval_code);

    // 	eval_buffer = {}
    RefDS(_39);
    DeRef(_7eval_buffer);
    _7eval_buffer = _39;

    // 	while ix do
L5:
    if (_ix == 0)
        goto L6;

    // 		eval_buffer = append( eval_buffer, eval_code[1..ix-1] )
    DeRef(_9528);
    _9528 = _ix - 1;
    rhs_slice_target = (object_ptr)&_9528;
    RHS_Slice((s1_ptr)_eval_code, 1, _9528);
    RefDS(_9528);
    Append(&_7eval_buffer, _7eval_buffer, _9528);

    // 		eval_code = eval_code[ix+1..$]
    DeRefDS(_9528);
    _9528 = _ix + 1;
    DeRef(_9527);
    _9527 = SEQ_PTR(_eval_code)->length;
    rhs_slice_target = (object_ptr)&_eval_code;
    RHS_Slice((s1_ptr)_eval_code, _9528, _9527);

    // 		ix = find( '\n', eval_code )
    _ix = find(10, _eval_code);

    // 	end while
    goto L5;
L6:

    // 	if length(eval_code) then
    DeRef(_9527);
    _9527 = SEQ_PTR(_eval_code)->length;
    if (_9527 == 0)
        goto L7;

    // 		eval_buffer = append( eval_buffer, eval_code )
    RefDS(_eval_code);
    Append(&_7eval_buffer, _7eval_buffer, _eval_code);
L7:

    // 	read_line()
    _12read_line();

    // 	CurrentSub = eval_sym
    _7CurrentSub = _7eval_sym;

    // 	new_syms = length( SymTab )
    _new_syms = SEQ_PTR(_7SymTab)->length;

    // 	if sequence(SymTab[eval_sym][S_CODE]) then
    DeRef(_9527);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9527 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9527);
    _0 = _9527;
    _2 = (int)SEQ_PTR(_9527);
    _9527 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_9527);
    DeRef(_0);
    _0 = _9527;
    _9527 = IS_SEQUENCE(_9527);
    DeRef(_0);
    if (_9527 == 0)
        goto L8;

    // 		pc_start = length( SymTab[eval_sym][S_CODE] ) + 1
    _2 = (int)SEQ_PTR(_7SymTab);
    _9527 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9527);
    _0 = _9527;
    _2 = (int)SEQ_PTR(_9527);
    _9527 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_9527);
    DeRef(_0);
    _0 = _9527;
    _9527 = SEQ_PTR(_9527)->length;
    DeRef(_0);
    _pc_start = _9527 + 1;
    goto L9;
L8:

    // 		pc_start = 1
    _pc_start = 1;
L9:

    // 	temp_top = TopLevelSub
    _temp_top = _7TopLevelSub;

    // 	TopLevelSub = eval_sym
    _7TopLevelSub = _7eval_sym;

    // 	if atom(SymTab[eval_sym][S_CODE]) then
    DeRef(_9527);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9527 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9527);
    _0 = _9527;
    _2 = (int)SEQ_PTR(_9527);
    _9527 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_9527);
    DeRef(_0);
    _0 = _9527;
    _9527 = IS_ATOM(_9527);
    DeRef(_0);
    if (_9527 == 0)
        goto LA;

    // 		Code = {}
    RefDS(_39);
    DeRef(_7Code);
    _7Code = _39;

    // 		LineTable = {}
    RefDS(_39);
    DeRef(_7LineTable);
    _7LineTable = _39;
    goto LB;
LA:

    // 		Code = SymTab[eval_sym][S_CODE]
    DeRef(_9527);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9527 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9527);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_9527);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 		if length(Code) then
    DeRef(_9527);
    _9527 = SEQ_PTR(_7Code)->length;
    if (_9527 == 0)
        goto LC;

    // 			SymTab[eval_sym][S_LINETAB] = SymTab[eval_sym][S_LINETAB][1..$-1]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9489);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9489 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9489);
    _0 = _9489;
    _2 = (int)SEQ_PTR(_9489);
    _9489 = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_9489);
    DeRef(_0);
    DeRef(_9558);
    _9558 = SEQ_PTR(_9489)->length;
    _9558 = _9558 - 1;
    rhs_slice_target = (object_ptr)&_9558;
    RHS_Slice((s1_ptr)_9489, 1, _9558);
    RefDS(_9558);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _9558;
    DeRef(_1);

    // 			LineTable = SymTab[eval_sym][S_LINETAB]			
    DeRefDS(_9558);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9558 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9558);
    DeRef(_7LineTable);
    _2 = (int)SEQ_PTR(_9558);
    _7LineTable = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_7LineTable);
    goto LD;
LC:

    // 			LineTable = {}
    RefDS(_39);
    DeRef(_7LineTable);
    _7LineTable = _39;
LD:
LB:

    // 	call_proc( forward_putback,{0})
    _0 = _9558;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _9558 = MAKE_SEQ(_1);
    DeRef(_0);
    _1 = (int)SEQ_PTR(_9558);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_putback].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 	parser()
    _16parser();

    // 	SymTab[eval_sym][S_CODE] = Code
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    RefDS(_7Code);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _7Code;
    DeRef(_1);

    // 	if atom(SymTab[eval_sym][S_LINETAB]) then
    DeRef(_9489);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9489 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9489);
    _0 = _9489;
    _2 = (int)SEQ_PTR(_9489);
    _9489 = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_9489);
    DeRef(_0);
    _0 = _9489;
    _9489 = IS_ATOM(_9489);
    DeRef(_0);
    if (_9489 == 0)
        goto LE;

    // 		SymTab[eval_sym][S_LINETAB] = repeat( -1, length(Code))
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9528);
    _9528 = SEQ_PTR(_7Code)->length;
    _9528 = Repeat(-1, _9528);
    RefDS(_9528);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _9528;
    DeRef(_1);
LE:

    // 	TopLevelSub = temp_top
    _7TopLevelSub = _temp_top;

    // 	val &= repeat( 0, length(SymTab) - new_syms )
    DeRef(_9528);
    _9528 = SEQ_PTR(_7SymTab)->length;
    _9528 = _9528 - _new_syms;
    _9528 = Repeat(0, _9528);
    Concat((object_ptr)&_17val, _17val, (s1_ptr)_9528);

    // 	for i = new_syms + 1 to length(SymTab) do
    DeRefDSi(_9528);
    _9528 = _new_syms + 1;
    DeRef(_9558);
    _9558 = SEQ_PTR(_7SymTab)->length;
    { int _i;
        _i = _9528;
LF:
        if (_i > _9558)
            goto L10;

        // 		val[i] = SymTab[i][S_OBJ]
        DeRef(_9528);
        _2 = (int)SEQ_PTR(_7SymTab);
        _9528 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9528);
        _0 = _9528;
        _2 = (int)SEQ_PTR(_9528);
        _9528 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9528);
        DeRef(_0);
        Ref(_9528);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _9528;
        DeRef(_1);

        // 	end for
        _i = _i + 1;
        goto LF;
L10:
        ;
    }

    // 	call_stack = append(call_stack, top)
    Append(&_17call_stack, _17call_stack, _top);

    // 	call_stack = append(call_stack, pc) 
    Append(&_17call_stack, _17call_stack, _17pc);

    // 	call_stack = append(call_stack, eval_sym )
    Append(&_17call_stack, _17call_stack, _7eval_sym);

    // 	Code = SymTab[eval_sym][S_CODE]
    DeRef(_9528);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9528 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9528);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_9528);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	pc = pc_start
    _17pc = _pc_start;

    // 	if not length(eval_error[$]) then
    DeRef(_9528);
    _9528 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    RefDS(_9528);
    _0 = _9528;
    _9528 = SEQ_PTR(_9528)->length;
    DeRefDS(_0);
    if (_9528 != 0)
        goto L11;

    // 		eval_exec()
    _17eval_exec();
    goto L12;
L11:

    // 		eval_stack[$] = 0
    DeRef(_9528);
    _9528 = SEQ_PTR(_7eval_stack)->length;
    _2 = (int)SEQ_PTR(_7eval_stack);
    _2 = (int)(((s1_ptr)_2)->base + _9528);
    *(int *)_2 = 0;
L12:

    // 	if not with_trace then
    if (_with_trace != 0)
        goto L13;

    // 		SymTab[eval_sym][S_CODE] = Code[1..pc_start - 1]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9489);
    _9489 = _pc_start - 1;
    rhs_slice_target = (object_ptr)&_9489;
    RHS_Slice((s1_ptr)_7Code, 1, _9489);
    RefDS(_9489);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _9489;
    DeRef(_1);

    // 		SymTab[eval_sym][S_LINETAB] = LineTable[1..pc_start-1]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9528);
    _9528 = _pc_start - 1;
    rhs_slice_target = (object_ptr)&_9528;
    RHS_Slice((s1_ptr)_7LineTable, 1, _9528);
    RefDS(_9528);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _9528;
    DeRef(_1);

    // 		rollback_source( start_line )
    _12rollback_source(_start_line);
L13:

    // 	target = eval_target
    _17target = _eval_target;

    // 	pc = call_stack[$-1] + 3
    DeRef(_9528);
    _9528 = SEQ_PTR(_17call_stack)->length;
    _9528 = _9528 - 1;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    if (IS_ATOM_INT(_9528)) {
        _17pc = _9528 + 3;
    }
    else {
        _17pc = binary_op(PLUS, _9528, 3);
    }
    if (!IS_ATOM_INT(_17pc)) {
        _1 = (long)(DBL_PTR(_17pc)->dbl);
        DeRefDS(_17pc);
        _17pc = _1;
    }

    // 	call_stack = call_stack[1..$-3]
    DeRef(_9528);
    _9528 = SEQ_PTR(_17call_stack)->length;
    _9528 = _9528 - 3;
    rhs_slice_target = (object_ptr)&_17call_stack;
    RHS_Slice((s1_ptr)_17call_stack, 1, _9528);

    // 	if call_stack[$] != TopLevelSub then
    _9528 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    if (binary_op_a(EQUALS, _9528, _7TopLevelSub))
        goto L14;

    // 		HidePrivates( call_stack[$], 1 )
    DeRef(_9528);
    _9528 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    Ref(_9528);
    _11HidePrivates(_9528, 1);
L14:

    // 	Code = SymTab[call_stack[top]][S_CODE]		
    DeRef(_9528);
    _2 = (int)SEQ_PTR(_17call_stack);
    _9528 = (int)*(((s1_ptr)_2)->base + _top);
    Ref(_9528);
    _0 = _9528;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_9528))
        _9528 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9528)->dbl));
    else
        _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    DeRef(_0);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_9528);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	LineTable = SymTab[call_stack[top]][S_LINETAB]
    DeRef(_9528);
    _2 = (int)SEQ_PTR(_17call_stack);
    _9528 = (int)*(((s1_ptr)_2)->base + _top);
    Ref(_9528);
    _0 = _9528;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_9528))
        _9528 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9528)->dbl));
    else
        _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    DeRef(_0);
    DeRef(_7LineTable);
    _2 = (int)SEQ_PTR(_9528);
    _7LineTable = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_7LineTable);

    // 	val[target] = eval_stack[$]
    DeRef(_9528);
    _9528 = SEQ_PTR(_7eval_stack)->length;
    _2 = (int)SEQ_PTR(_7eval_stack);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9528;
    DeRef(_1);

    // 	eval_stack = eval_stack[1..$-1]
    _9528 = SEQ_PTR(_7eval_stack)->length;
    _9528 = _9528 - 1;
    rhs_slice_target = (object_ptr)&_7eval_stack;
    RHS_Slice((s1_ptr)_7eval_stack, 1, _9528);

    // 	eval_error = eval_error[1..$-1]
    _9528 = SEQ_PTR(_7eval_error)->length;
    _9528 = _9528 - 1;
    rhs_slice_target = (object_ptr)&_7eval_error;
    RHS_Slice((s1_ptr)_7eval_error, 1, _9528);

    // 	eval_file_no = eval_file_no[1..$-1]
    _9528 = SEQ_PTR(_7eval_file_no)->length;
    _9528 = _9528 - 1;
    rhs_slice_target = (object_ptr)&_7eval_file_no;
    RHS_Slice((s1_ptr)_7eval_file_no, 1, _9528);

    // end procedure
    DeRef(_eval_code);
    DeRef(_9558);
    DeRef(_9489);
    DeRef(_9527);
    return 0;
    ;
}


int _17opEMBEDDED_PROCEDURE_CALL()
{
    int _rid;
    int _params = 0;
    int _void = 0;
    int _mycode = 0;
    int _mypc;
    int _9629 = 0;
    int _0, _1, _2;
    

    // 	rid = val[Code[pc+1]]
    _9629 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9629 = (int)*(((s1_ptr)_2)->base + _9629);
    Ref(_9629);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9629))
        _rid = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9629)->dbl));
    else
        _rid = (int)*(((s1_ptr)_2)->base + _9629);
    if (!IS_ATOM_INT(_rid))
        _rid = (long)DBL_PTR(_rid)->dbl;

    // 	params = val[Code[pc+2]]
    DeRef(_9629);
    _9629 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _9629 = (int)*(((s1_ptr)_2)->base + _9629);
    Ref(_9629);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9629))
        _params = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9629)->dbl));
    else
        _params = (int)*(((s1_ptr)_2)->base + _9629);
    Ref(_params);

    // 	mycode = Code
    RefDS(_7Code);
    _mycode = _7Code;

    // 	mypc = pc
    _mypc = _17pc;

    // 	if rid > 0 then
    if (_rid <= 0)
        goto L1;

    // 		call_proc( rid, params )
    _1 = (int)SEQ_PTR(_params);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_rid].addr;
    switch(((s1_ptr)_1)->length) {
        case 0:
            (*(int (*)())_0)(
                                 );
            break;
        case 1:
            Ref(*(int *)(_2+4));
            (*(int (*)())_0)(
                                *(int *)(_2+4)
                                 );
            break;
        case 2:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8)
                                 );
            break;
        case 3:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12)
                                 );
            break;
        case 4:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16)
                                 );
            break;
        case 5:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            Ref(*(int *)(_2+20));
            (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16), 
                                *(int *)(_2+20)
                                 );
            break;
        case 6:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            Ref(*(int *)(_2+20));
            Ref(*(int *)(_2+24));
            (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16), 
                                *(int *)(_2+20), 
                                *(int *)(_2+24)
                                 );
            break;
        case 7:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            Ref(*(int *)(_2+20));
            Ref(*(int *)(_2+24));
            Ref(*(int *)(_2+28));
            (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16), 
                                *(int *)(_2+20), 
                                *(int *)(_2+24), 
                                *(int *)(_2+28)
                                 );
            break;
    }
    goto L2;
L1:

    // 		the_object = params
    RefDS(_params);
    DeRef(_1the_object);
    _1the_object = _params;

    // 		c_proc( embedded_call_back, {-rid, 0})
    DeRef(_9629);
    if (_rid == 0xC0000000)
        _9629 = (int)NewDouble((double)-0xC0000000);
    else
        _9629 = - _rid;
    _0 = _9629;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9629;
    Ref(_9629);
    ((int *)_2)[2] = 0;
    _9629 = MAKE_SEQ(_1);
    DeRef(_0);
    call_c(0, 0, _9629);
L2:

    // 	Code = mycode
    RefDS(_mycode);
    DeRef(_7Code);
    _7Code = _mycode;

    // 	pc = mypc + 3
    _17pc = _mypc + 3;

    // end procedure
    DeRef(_params);
    DeRef(_void);
    DeRefDS(_mycode);
    DeRef(_9629);
    return 0;
    ;
}


int _17opEMBEDDED_FUNCTION_CALL()
{
    int _rid;
    int _target;
    int _mypc;
    int _params = 0;
    int _mycode = 0;
    int _9639 = 0;
    int _0, _1, _2;
    

    // 	rid = val[Code[pc+1]]
    _9639 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9639 = (int)*(((s1_ptr)_2)->base + _9639);
    Ref(_9639);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9639))
        _rid = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9639)->dbl));
    else
        _rid = (int)*(((s1_ptr)_2)->base + _9639);
    if (!IS_ATOM_INT(_rid))
        _rid = (long)DBL_PTR(_rid)->dbl;

    // 	params = val[Code[pc+2]]
    DeRef(_9639);
    _9639 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _9639 = (int)*(((s1_ptr)_2)->base + _9639);
    Ref(_9639);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9639))
        _params = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9639)->dbl));
    else
        _params = (int)*(((s1_ptr)_2)->base + _9639);
    Ref(_params);

    // 	target = Code[pc + 3]
    DeRef(_9639);
    _9639 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _target = (int)*(((s1_ptr)_2)->base + _9639);
    if (!IS_ATOM_INT(_target))
        _target = (long)DBL_PTR(_target)->dbl;

    // 	mycode = Code
    RefDS(_7Code);
    _mycode = _7Code;

    // 	mypc = pc
    _mypc = _17pc;

    // 	if rid > 0 then
    if (_rid <= 0)
        goto L1;

    // 		val[target] = call_func( rid, params )
    _1 = (int)SEQ_PTR(_params);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_rid].addr;
    switch(((s1_ptr)_1)->length) {
        case 0:
            _1 = (*(int (*)())_0)(
                                 );
            break;
        case 1:
            Ref(*(int *)(_2+4));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4)
                                 );
            break;
        case 2:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8)
                                 );
            break;
        case 3:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12)
                                 );
            break;
        case 4:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16)
                                 );
            break;
        case 5:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            Ref(*(int *)(_2+20));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16), 
                                *(int *)(_2+20)
                                 );
            break;
        case 6:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            Ref(*(int *)(_2+20));
            Ref(*(int *)(_2+24));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16), 
                                *(int *)(_2+20), 
                                *(int *)(_2+24)
                                 );
            break;
        case 7:
            Ref(*(int *)(_2+4));
            Ref(*(int *)(_2+8));
            Ref(*(int *)(_2+12));
            Ref(*(int *)(_2+16));
            Ref(*(int *)(_2+20));
            Ref(*(int *)(_2+24));
            Ref(*(int *)(_2+28));
            _1 = (*(int (*)())_0)(
                                *(int *)(_2+4), 
                                *(int *)(_2+8), 
                                *(int *)(_2+12), 
                                *(int *)(_2+16), 
                                *(int *)(_2+20), 
                                *(int *)(_2+24), 
                                *(int *)(_2+28)
                                 );
            break;
    }
    _9639 = _1;
    Ref(_9639);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _target);
    _1 = *(int *)_2;
    *(int *)_2 = _9639;
    DeRef(_1);
    goto L2;
L1:

    // 		the_object = params
    RefDS(_params);
    DeRef(_1the_object);
    _1the_object = _params;

    // 		c_proc( embedded_call_back, { -rid, 1 })
    DeRef(_9639);
    if (_rid == 0xC0000000)
        _9639 = (int)NewDouble((double)-0xC0000000);
    else
        _9639 = - _rid;
    _0 = _9639;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9639;
    Ref(_9639);
    ((int *)_2)[2] = 1;
    _9639 = MAKE_SEQ(_1);
    DeRef(_0);
    call_c(0, 0, _9639);

    // 		val[target] = the_object
    RefDS(_1the_object);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _target);
    _1 = *(int *)_2;
    *(int *)_2 = _1the_object;
    DeRef(_1);
L2:

    // 	Code = mycode
    RefDS(_mycode);
    DeRef(_7Code);
    _7Code = _mycode;

    // 	pc = mypc + 4
    _17pc = _mypc + 4;

    // end procedure
    DeRef(_params);
    DeRefDS(_mycode);
    DeRef(_9639);
    return 0;
    ;
}


int _17get_eval_err()
{
    int _0, _1, _2;
    

    // 	return last_eval_error
    RefDS(_17last_eval_error);
    return _17last_eval_error;
    ;
}


int _17do_eval_exec(int _eval_code)
{
    int _ix;
    int _new_syms;
    int _pc_start;
    int _top;
    int _temp_top;
    int _gline;
    int _eval_target;
    int _with_trace;
    int _start_line;
    int _9711 = 0;
    int _9671 = 0;
    int _9652 = 0;
    int _9670 = 0;
    int _0, _1, _2, _3;
    

    // 	eval_stack &= 1
    Append(&_7eval_stack, _7eval_stack, 1);

    // 	eval_error = append( eval_error, "" )
    RefDS(_39);
    Append(&_7eval_error, _7eval_error, _39);

    // 	if length(slist) then
    _9652 = SEQ_PTR(_7slist)->length;
    if (_9652 == 0)
        goto L1;

    // 		if atom(slist[$]) then
    _9652 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _9652 = (int)*(((s1_ptr)_2)->base + _9652);
    Ref(_9652);
    _0 = _9652;
    _9652 = IS_ATOM(_9652);
    DeRef(_0);
    if (_9652 == 0)
        goto L2;

    // 			slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L2:

    // 		start_line = length(slist)
    _start_line = SEQ_PTR(_7slist)->length;

    // 		with_trace = and_bits( slist[start_line-1][OPTIONS], SOP_TRACE )
    DeRef(_9652);
    _9652 = _start_line - 1;
    _2 = (int)SEQ_PTR(_7slist);
    _9652 = (int)*(((s1_ptr)_2)->base + _9652);
    Ref(_9652);
    _0 = _9652;
    _2 = (int)SEQ_PTR(_9652);
    _9652 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_9652);
    DeRef(_0);
    if (IS_ATOM_INT(_9652)) {
        _with_trace = (_9652 & 1);
    }
    else {
        _with_trace = binary_op(AND_BITS, _9652, 1);
    }
    if (!IS_ATOM_INT(_with_trace)) {
        _1 = (long)(DBL_PTR(_with_trace)->dbl);
        DeRefDS(_with_trace);
        _with_trace = _1;
    }

    // 		slist &= 0
    Append(&_7slist, _7slist, 0);
    goto L3;
L1:

    // 		start_line = 0
    _start_line = 0;

    // 		with_trace = 1
    _with_trace = 1;
L3:

    // 	ix = find( "_eval_", file_name )
    _ix = find(_9521, _7file_name);

    // 	if not ix then --equal( file_name[$], "_eval_") then
    if (_ix != 0)
        goto L4;

    // 		file_name = append(file_name, "_eval_")
    RefDS(_9521);
    Append(&_7file_name, _7file_name, _9521);

    // 		current_file_no = length(file_name)
    _7current_file_no = SEQ_PTR(_7file_name)->length;

    // 		eval_file = current_file_no
    _7eval_file = _7current_file_no;

    // 		line_number = 0
    _7line_number = 0;

    // 		SymTab[eval_sym][S_FIRSTLINE] = length(slist)+1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9671);
    _9671 = SEQ_PTR(_7slist)->length;
    _9671 = _9671 + 1;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 17);
    _1 = *(int *)_2;
    *(int *)_2 = _9671;
    DeRef(_1);
L4:

    // 	ix = find( '\n', eval_code )
    _ix = find(10, _eval_code);

    // 	eval_buffer = {}
    RefDS(_39);
    DeRef(_7eval_buffer);
    _7eval_buffer = _39;

    // 	while ix do
L5:
    if (_ix == 0)
        goto L6;

    // 		eval_buffer = append( eval_buffer, eval_code[1..ix-1] )
    DeRef(_9671);
    _9671 = _ix - 1;
    rhs_slice_target = (object_ptr)&_9671;
    RHS_Slice((s1_ptr)_eval_code, 1, _9671);
    RefDS(_9671);
    Append(&_7eval_buffer, _7eval_buffer, _9671);

    // 		eval_code = eval_code[ix+1..$]
    DeRefDS(_9671);
    _9671 = _ix + 1;
    DeRef(_9670);
    _9670 = SEQ_PTR(_eval_code)->length;
    rhs_slice_target = (object_ptr)&_eval_code;
    RHS_Slice((s1_ptr)_eval_code, _9671, _9670);

    // 		ix = find( '\n', eval_code )
    _ix = find(10, _eval_code);

    // 	end while
    goto L5;
L6:

    // 	if length(eval_code) then
    DeRef(_9670);
    _9670 = SEQ_PTR(_eval_code)->length;
    if (_9670 == 0)
        goto L7;

    // 		eval_buffer = append( eval_buffer, eval_code )
    RefDS(_eval_code);
    Append(&_7eval_buffer, _7eval_buffer, _eval_code);
L7:

    // 	if not length( eval_buffer ) then
    DeRef(_9670);
    _9670 = SEQ_PTR(_7eval_buffer)->length;
    if (_9670 != 0)
        goto L8;

    // 		eval_target = eval_stack[$]
    _9670 = SEQ_PTR(_7eval_stack)->length;
    _2 = (int)SEQ_PTR(_7eval_stack);
    _eval_target = (int)*(((s1_ptr)_2)->base + _9670);

    // 		eval_stack = eval_stack[1..$-1]
    _9670 = SEQ_PTR(_7eval_stack)->length;
    _9670 = _9670 - 1;
    rhs_slice_target = (object_ptr)&_7eval_stack;
    RHS_Slice((s1_ptr)_7eval_stack, 1, _9670);

    // 		eval_error = eval_error[1..$-1]
    _9670 = SEQ_PTR(_7eval_error)->length;
    _9670 = _9670 - 1;
    rhs_slice_target = (object_ptr)&_7eval_error;
    RHS_Slice((s1_ptr)_7eval_error, 1, _9670);

    // 		return 1
    DeRefDS(_eval_code);
    DeRef(_9711);
    DeRef(_9671);
    DeRef(_9652);
    return 1;
L8:

    // 	read_line()
    _12read_line();

    // 	CurrentSub = eval_sym
    _7CurrentSub = _7eval_sym;

    // 	new_syms = length( SymTab )
    _new_syms = SEQ_PTR(_7SymTab)->length;

    // 	if sequence(SymTab[eval_sym][S_CODE]) then
    DeRef(_9670);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9670 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9670);
    _0 = _9670;
    _2 = (int)SEQ_PTR(_9670);
    _9670 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_9670);
    DeRef(_0);
    _0 = _9670;
    _9670 = IS_SEQUENCE(_9670);
    DeRef(_0);
    if (_9670 == 0)
        goto L9;

    // 		pc_start = length( SymTab[eval_sym][S_CODE] ) + 1
    _2 = (int)SEQ_PTR(_7SymTab);
    _9670 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9670);
    _0 = _9670;
    _2 = (int)SEQ_PTR(_9670);
    _9670 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_9670);
    DeRef(_0);
    _0 = _9670;
    _9670 = SEQ_PTR(_9670)->length;
    DeRef(_0);
    _pc_start = _9670 + 1;
    goto LA;
L9:

    // 		pc_start = 1
    _pc_start = 1;
LA:

    // 	temp_top = TopLevelSub
    _temp_top = _7TopLevelSub;

    // 	TopLevelSub = eval_sym
    _7TopLevelSub = _7eval_sym;

    // 	if atom(SymTab[eval_sym][S_CODE]) then
    DeRef(_9670);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9670 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9670);
    _0 = _9670;
    _2 = (int)SEQ_PTR(_9670);
    _9670 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_9670);
    DeRef(_0);
    _0 = _9670;
    _9670 = IS_ATOM(_9670);
    DeRef(_0);
    if (_9670 == 0)
        goto LB;

    // 		Code = {}
    RefDS(_39);
    DeRef(_7Code);
    _7Code = _39;

    // 		LineTable = {}
    RefDS(_39);
    DeRef(_7LineTable);
    _7LineTable = _39;
    goto LC;
LB:

    // 		Code = SymTab[eval_sym][S_CODE]
    DeRef(_9670);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9670 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9670);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_9670);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 		if length(Code) then
    DeRef(_9670);
    _9670 = SEQ_PTR(_7Code)->length;
    if (_9670 == 0)
        goto LD;

    // 			SymTab[eval_sym][S_LINETAB] = SymTab[eval_sym][S_LINETAB][1..$-1]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9652);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9652 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9652);
    _0 = _9652;
    _2 = (int)SEQ_PTR(_9652);
    _9652 = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_9652);
    DeRef(_0);
    DeRef(_9711);
    _9711 = SEQ_PTR(_9652)->length;
    _9711 = _9711 - 1;
    rhs_slice_target = (object_ptr)&_9711;
    RHS_Slice((s1_ptr)_9652, 1, _9711);
    RefDS(_9711);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _9711;
    DeRef(_1);

    // 			LineTable = SymTab[eval_sym][S_LINETAB]			
    DeRefDS(_9711);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9711 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9711);
    DeRef(_7LineTable);
    _2 = (int)SEQ_PTR(_9711);
    _7LineTable = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_7LineTable);
    goto LE;
LD:

    // 			LineTable = {}
    RefDS(_39);
    DeRef(_7LineTable);
    _7LineTable = _39;
LE:
LC:

    // 	call_proc( forward_putback,{0})
    _0 = _9711;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _9711 = MAKE_SEQ(_1);
    DeRef(_0);
    _1 = (int)SEQ_PTR(_9711);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_putback].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 	parser()
    _16parser();

    // 	if not length(eval_error[$]) then	
    DeRefDSi(_9711);
    _9711 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _9711 = (int)*(((s1_ptr)_2)->base + _9711);
    RefDS(_9711);
    _0 = _9711;
    _9711 = SEQ_PTR(_9711)->length;
    DeRefDS(_0);
    if (_9711 != 0)
        goto LF;

    // 		SymTab[eval_sym][S_CODE] = Code
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    RefDS(_7Code);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _7Code;
    DeRef(_1);

    // 		if atom(SymTab[eval_sym][S_LINETAB]) then
    DeRef(_9652);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9652 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9652);
    _0 = _9652;
    _2 = (int)SEQ_PTR(_9652);
    _9652 = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_9652);
    DeRef(_0);
    _0 = _9652;
    _9652 = IS_ATOM(_9652);
    DeRef(_0);
    if (_9652 == 0)
        goto L10;

    // 			SymTab[eval_sym][S_LINETAB] = repeat( -1, length(Code))
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9671);
    _9671 = SEQ_PTR(_7Code)->length;
    _9671 = Repeat(-1, _9671);
    RefDS(_9671);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _9671;
    DeRef(_1);
L10:

    // 		TopLevelSub = temp_top
    _7TopLevelSub = _temp_top;

    // 		val &= repeat( 0, length(SymTab) - new_syms )
    DeRef(_9671);
    _9671 = SEQ_PTR(_7SymTab)->length;
    _9671 = _9671 - _new_syms;
    _9671 = Repeat(0, _9671);
    Concat((object_ptr)&_17val, _17val, (s1_ptr)_9671);

    // 		for i = new_syms + 1 to length(SymTab) do
    DeRefDSi(_9671);
    _9671 = _new_syms + 1;
    DeRef(_9711);
    _9711 = SEQ_PTR(_7SymTab)->length;
    { int _i;
        _i = _9671;
L11:
        if (_i > _9711)
            goto L12;

        // 			val[i] = SymTab[i][S_OBJ]
        DeRef(_9671);
        _2 = (int)SEQ_PTR(_7SymTab);
        _9671 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9671);
        _0 = _9671;
        _2 = (int)SEQ_PTR(_9671);
        _9671 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_9671);
        DeRef(_0);
        Ref(_9671);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _9671;
        DeRef(_1);

        // 		end for
        _i = _i + 1;
        goto L11;
L12:
        ;
    }

    // 		call_stack = append(call_stack, 0)
    Append(&_17call_stack, _17call_stack, 0);

    // 		call_stack = append(call_stack, 0) 
    Append(&_17call_stack, _17call_stack, 0);

    // 		call_stack = append(call_stack, eval_sym )
    Append(&_17call_stack, _17call_stack, _7eval_sym);

    // 		Code = SymTab[eval_sym][S_CODE]
    DeRef(_9671);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9671 = (int)*(((s1_ptr)_2)->base + _7eval_sym);
    Ref(_9671);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_9671);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 		pc = pc_start
    _17pc = _pc_start;

    // 		eval_exec()
    _17eval_exec();

    // 		if not with_trace then
    if (_with_trace != 0)
        goto L13;

    // 			SymTab[eval_sym][S_CODE] = Code[1..pc_start - 1]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9652);
    _9652 = _pc_start - 1;
    rhs_slice_target = (object_ptr)&_9652;
    RHS_Slice((s1_ptr)_7Code, 1, _9652);
    RefDS(_9652);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _9652;
    DeRef(_1);

    // 			SymTab[eval_sym][S_LINETAB] = LineTable[1..pc_start-1]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7eval_sym + ((s1_ptr)_2)->base);
    DeRef(_9671);
    _9671 = _pc_start - 1;
    rhs_slice_target = (object_ptr)&_9671;
    RHS_Slice((s1_ptr)_7LineTable, 1, _9671);
    RefDS(_9671);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _9671;
    DeRef(_1);

    // 			if start_line then
    if (_start_line == 0)
        goto L14;

    // 				rollback_source( start_line )
    _12rollback_source(_start_line);
L14:
L13:

    // 		call_stack = call_stack[1..$-3]
    DeRef(_9671);
    _9671 = SEQ_PTR(_17call_stack)->length;
    _9671 = _9671 - 3;
    rhs_slice_target = (object_ptr)&_17call_stack;
    RHS_Slice((s1_ptr)_17call_stack, 1, _9671);
LF:

    // 	eval_target = eval_stack[$]
    DeRef(_9671);
    _9671 = SEQ_PTR(_7eval_stack)->length;
    _2 = (int)SEQ_PTR(_7eval_stack);
    _eval_target = (int)*(((s1_ptr)_2)->base + _9671);

    // 	eval_stack = eval_stack[1..$-1]
    _9671 = SEQ_PTR(_7eval_stack)->length;
    _9671 = _9671 - 1;
    rhs_slice_target = (object_ptr)&_7eval_stack;
    RHS_Slice((s1_ptr)_7eval_stack, 1, _9671);

    // 	last_eval_error = eval_error[$]
    _9671 = SEQ_PTR(_7eval_error)->length;
    DeRef(_17last_eval_error);
    _2 = (int)SEQ_PTR(_7eval_error);
    _17last_eval_error = (int)*(((s1_ptr)_2)->base + _9671);
    RefDS(_17last_eval_error);

    // 	eval_error = eval_error[1..$-1]
    _9671 = SEQ_PTR(_7eval_error)->length;
    _9671 = _9671 - 1;
    rhs_slice_target = (object_ptr)&_7eval_error;
    RHS_Slice((s1_ptr)_7eval_error, 1, _9671);

    // 	if TraceOn and debugger > 0 then
    if (_17TraceOn == 0) {
        goto L15;
    }
    DeRef(_9711);
    if (IS_ATOM_INT(_7debugger)) {
        _9711 = (_7debugger > 0);
    }
    else {
        _9711 = (DBL_PTR(_7debugger)->dbl > (double)0);
    }
L16:
    if (_9711 == 0)
        goto L15;

    // 		c_proc( hide_debugger, {} )
    call_c(0, _7hide_debugger, _39);
L15:

    // 	return length(last_eval_error) = 0
    DeRef(_9711);
    _9711 = SEQ_PTR(_17last_eval_error)->length;
    _9711 = (_9711 == 0);
    DeRefDS(_eval_code);
    DeRef(_9671);
    DeRef(_9652);
    DeRef(_9670);
    return _9711;
    ;
}


