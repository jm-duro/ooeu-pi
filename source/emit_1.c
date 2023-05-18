// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _15emit_assign_op(int _op)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }

    //     if op = PLUS_EQUALS then
    if (_op != 518)
        goto L1;

    // 	emit_op(PLUS)
    _15emit_op(11);
    goto L2;
L1:

    //     elsif op = MINUS_EQUALS then
    if (_op != 519)
        goto L3;

    // 	emit_op(MINUS)
    _15emit_op(10);
    goto L2;
L3:

    //     elsif op = MULTIPLY_EQUALS then 
    if (_op != 520)
        goto L4;

    // 	emit_op(MULTIPLY)
    _15emit_op(13);
    goto L2;
L4:

    //     elsif op = DIVIDE_EQUALS then 
    if (_op != 521)
        goto L5;

    // 	emit_op(DIVIDE)
    _15emit_op(14);
    goto L2;
L5:

    //     elsif op = CONCAT_EQUALS then
    if (_op != 522)
        goto L6;

    // 	emit_op(CONCAT)
    _15emit_op(15);
L6:
L2:

    // end procedure
    return 0;
    ;
}


int _15StartSourceLine(int _sl)
{
    int _line_span;
    int _3384;
    int _3367;
    int _3371 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sl)) {
        _1 = (long)(DBL_PTR(_sl)->dbl);
        DeRefDS(_sl);
        _sl = _1;
    }

    //     if gline_number = LastLineNumber then
    if (_7gline_number != _12LastLineNumber)
        goto L1;

    // 	if length(LineTable) then
    _3367 = SEQ_PTR(_7LineTable)->length;
    if (_3367 == 0)
        goto L2;

    // 	if sl = TRUE and not match( {STARTLINE, gline_number}, Code ) then
    _3367 = (_sl == 1);
    if (_3367 == 0) {
        goto L3;
    }
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 58;
    ((int *)_2)[2] = _7gline_number;
    _3371 = MAKE_SEQ(_1);
    _0 = _3371;
    _3371 = e_match(_3371, _7Code);
    DeRefDSi(_0);
    _3371 = (_3371 == 0);
L4:
    if (_3371 == 0)
        goto L3;

    // 		emit_op( STARTLINE )
    _15emit_op(58);

    // 		emit_addr( gline_number )
    _15emit_addr(_7gline_number);
L3:

    // 	    return -- ignore duplicates 
    DeRef(_3371);
    return 0;
    goto L5;
L2:

    // 	    sl = FALSE -- top-level new statement to execute on same line
    _sl = 0;
L5:
L1:

    //     LastLineNumber = gline_number
    _12LastLineNumber = _7gline_number;

    //     line_span = gline_number - SymTab[CurrentSub][S_FIRSTLINE]
    DeRef(_3371);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3371 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_3371);
    _0 = _3371;
    _2 = (int)SEQ_PTR(_3371);
    _3371 = (int)*(((s1_ptr)_2)->base + 17);
    Ref(_3371);
    DeRef(_0);
    if (IS_ATOM_INT(_3371)) {
        _line_span = _7gline_number - _3371;
    }
    else {
        _line_span = binary_op(MINUS, _7gline_number, _3371);
    }
    if (!IS_ATOM_INT(_line_span)) {
        _1 = (long)(DBL_PTR(_line_span)->dbl);
        DeRefDS(_line_span);
        _line_span = _1;
    }

    //     while length(LineTable) < line_span do
L6:
    DeRef(_3371);
    _3371 = SEQ_PTR(_7LineTable)->length;
    if (_3371 >= _line_span)
        goto L7;

    // 	LineTable = append(LineTable, -1) -- filler
    Append(&_7LineTable, _7LineTable, -1);

    //     end while
    goto L6;
L7:

    //     LineTable = append(LineTable, length(Code))
    DeRef(_3371);
    _3371 = SEQ_PTR(_7Code)->length;
    Append(&_7LineTable, _7LineTable, _3371);

    //     if sl and (TRANSLATE or (OpTrace or OpProfileStatement)) then
    if (_sl == 0) {
        goto L8;
    }
    if (0 != 0) {
        _3367 = 1;
        goto L9;
    }
    if (_7OpTrace != 0) {
        _3384 = 1;
        goto LA;
    }
    _3384 = (_7OpProfileStatement != 0);
LA:
    _3367 = (_3384 != 0);
L9:
LB:
    if (_3367 == 0)
        goto L8;

    // 	emit_op(STARTLINE)
    _15emit_op(58);

    // 	emit_addr(gline_number)
    _15emit_addr(_7gline_number);
L8:

    // end procedure
    DeRef(_3371);
    return 0;
    ;
}


