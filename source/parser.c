// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16EndLineTable()
{
    int _0, _1, _2;
    

    //     LineTable = append(LineTable, -2)
    Append(&_7LineTable, _7LineTable, -2);

    // end procedure
    return 0;
    ;
}


int _16CreateTopLevel()
{
    int _0, _1, _2, _3;
    

    //     SymTab[TopLevelSub][S_NUM_ARGS] = 0
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 20);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_TEMPS] = 0
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_CODE] = {}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_LINETAB] = {}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_FIRSTLINE] = 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 17);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_REFLIST] = {}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
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

    //     SymTab[TopLevelSub][S_NREFS] = 1
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // end procedure
    return 0;
    ;
}


int _16EnterTopLevel()
{
    int _3403 = 0;
    int _0, _1, _2, _3;
    

    //     if CurrentSub then
    if (_7CurrentSub == 0)
        goto L1;

    // 	EndLineTable()
    _16EndLineTable();

    // 	SymTab[CurrentSub][S_LINETAB] = LineTable
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    RefDS(_7LineTable);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _7LineTable;
    DeRef(_1);

    // 	SymTab[CurrentSub][S_CODE] = Code
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
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
L1:

    //     LineTable = SymTab[TopLevelSub][S_LINETAB]
    DeRef(_3403);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3403 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_3403);
    DeRef(_7LineTable);
    _2 = (int)SEQ_PTR(_3403);
    _7LineTable = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_7LineTable);

    //     Code = SymTab[TopLevelSub][S_CODE]
    DeRef(_3403);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3403 = (int)*(((s1_ptr)_2)->base + _7TopLevelSub);
    Ref(_3403);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_3403);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    //     previous_op = -1
    _15previous_op = -1;

    //     CurrentSub = TopLevelSub
    _7CurrentSub = _7TopLevelSub;

    // end procedure
    DeRef(_3403);
    return 0;
    ;
}


int _16LeaveTopLevel()
{
    int _0, _1, _2, _3;
    

    //     LastLineNumber = -1
    _12LastLineNumber = -1;

    //     SymTab[TopLevelSub][S_LINETAB] = LineTable
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_7LineTable);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _7LineTable;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_CODE] = Code
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7TopLevelSub + ((s1_ptr)_2)->base);
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

    //     LineTable = {}
    RefDS(_39);
    DeRefDS(_7LineTable);
    _7LineTable = _39;

    //     Code = {}
    RefDS(_39);
    DeRefDS(_7Code);
    _7Code = _39;

    //     previous_op = -1
    _15previous_op = -1;

    // end procedure
    return 0;
    ;
}


int _16InitParser()
{
    int _0, _1, _2;
    

    //     elist = {}
    RefDS(_39);
    DeRefi(_16elist);
    _16elist = _39;

    //     exit_list = {}
    RefDS(_39);
    DeRefi(_16exit_list);
    _16exit_list = _39;

    //     init_stack = {}
    RefDS(_39);
    DeRefi(_16init_stack);
    _16init_stack = _39;

    //     CurrentSub = 0
    _7CurrentSub = 0;

    //     CreateTopLevel()
    _16CreateTopLevel();

    //     EnterTopLevel()
    _16EnterTopLevel();

    //     backed_up_tok = UNDEFINED
    DeRef(_16backed_up_tok);
    _16backed_up_tok = -999;

    //     loop_nest = 0
    _16loop_nest = 0;

    //     stmt_nest = 0
    _16stmt_nest = 0;

    // end procedure
    return 0;
    ;
}


int _16NotReached(int _tok, int _keyword)
{
    int _3415 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_tok)) {
        _1 = (long)(DBL_PTR(_tok)->dbl);
        DeRefDS(_tok);
        _tok = _1;
    }

    //     if not find(tok, {END, ELSE, ELSIF, END_OF_FILE}) then
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 402;
    *((int *)(_2+8)) = 23;
    *((int *)(_2+12)) = 413;
    *((int *)(_2+16)) = -21;
    _3415 = MAKE_SEQ(_1);
    _0 = _3415;
    _3415 = find(_tok, _3415);
    DeRefDSi(_0);
    if (_3415 != 0)
        goto L1;

    // 	Warning(sprintf("%s:%d - statement after %s will never be executed", 
    _2 = (int)SEQ_PTR(_7file_name);
    _3415 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_3415);
    Ref(_3415);
    _0 = _3415;
    _3415 = _11name_ext(_3415);
    DeRef(_0);
    _0 = _3415;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_3415);
    *((int *)(_2+4)) = _3415;
    *((int *)(_2+8)) = _7line_number;
    RefDS(_keyword);
    *((int *)(_2+12)) = _keyword;
    _3415 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _3415;
    _3415 = EPrintf(-9999999, _3418, _3415);
    DeRefDS(_0);
    RefDS(_3415);
    _9Warning(_3415);
L1:

    // end procedure
    DeRefDSi(_keyword);
    DeRef(_3415);
    return 0;
    ;
}


int _16InitCheck(int _sym, int _ref)
{
    int _3446 = 0;
    int _3448 = 0;
    int _3423 = 0;
    int _3427 = 0;
    int _0, _1, _2, _3;
    

    //     if SymTab[sym][S_MODE] = M_NORMAL and 
    _2 = (int)SEQ_PTR(_7SymTab);
    _3423 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3423);
    _0 = _3423;
    _2 = (int)SEQ_PTR(_3423);
    _3423 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3423);
    DeRef(_0);
    _0 = _3423;
    if (IS_ATOM_INT(_3423)) {
        _3423 = (_3423 == 1);
    }
    else {
        _3423 = binary_op(EQUALS, _3423, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3423)) {
        if (_3423 == 0) {
            DeRef(_3423);
            _3423 = 0;
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_3423)->dbl == 0.0) {
            DeRef(_3423);
            _3423 = 0;
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_7SymTab);
    _3427 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3427);
    _0 = _3427;
    _2 = (int)SEQ_PTR(_3427);
    _3427 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3427);
    DeRef(_0);
    _0 = _3427;
    if (IS_ATOM_INT(_3427)) {
        _3427 = (_3427 != 2);
    }
    else {
        _3427 = binary_op(NOTEQ, _3427, 2);
    }
    DeRef(_0);
    DeRef(_3423);
    if (IS_ATOM_INT(_3427))
        _3423 = (_3427 != 0);
    else
        _3423 = DBL_PTR(_3427)->dbl != 0.0;
L1:
    if (_3423 == 0) {
        goto L2;
    }
    DeRef(_3423);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3423 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3423);
    _0 = _3423;
    _2 = (int)SEQ_PTR(_3423);
    _3423 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3423);
    DeRef(_0);
    _0 = _3423;
    if (IS_ATOM_INT(_3423)) {
        _3423 = (_3423 != 4);
    }
    else {
        _3423 = binary_op(NOTEQ, _3423, 4);
    }
    DeRef(_0);
L3:
    if (_3423 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_3423) && DBL_PTR(_3423)->dbl == 0.0)
            goto L2;
    }

    // 	if (SymTab[sym][S_SCOPE] != SC_PRIVATE and 
    DeRef(_3423);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3423 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3423);
    _0 = _3423;
    _2 = (int)SEQ_PTR(_3423);
    _3423 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3423);
    DeRef(_0);
    _0 = _3423;
    if (IS_ATOM_INT(_3423)) {
        _3423 = (_3423 != 3);
    }
    else {
        _3423 = binary_op(NOTEQ, _3423, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3423)) {
        if (_3423 == 0) {
            DeRef(_3423);
            _3423 = 0;
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_3423)->dbl == 0.0) {
            DeRef(_3423);
            _3423 = 0;
            goto L4;
        }
    }
    DeRef(_3427);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3427 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3427);
    _0 = _3427;
    _2 = (int)SEQ_PTR(_3427);
    _3427 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3427);
    DeRef(_0);
    _0 = _3427;
    if (_3427 == _7NOVALUE)
        _3427 = 1;
    else if (IS_ATOM_INT(_3427) && IS_ATOM_INT(_7NOVALUE))
        _3427 = 0;
    else
        _3427 = (compare(_3427, _7NOVALUE) == 0);
    DeRef(_0);
    DeRef(_3423);
    _3423 = (_3427 != 0);
L4:
    if (_3423 != 0) {
        goto L5;
    }
    DeRef(_3423);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3423 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3423);
    _0 = _3423;
    _2 = (int)SEQ_PTR(_3423);
    _3423 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3423);
    DeRef(_0);
    _0 = _3423;
    if (IS_ATOM_INT(_3423)) {
        _3423 = (_3423 == 3);
    }
    else {
        _3423 = binary_op(EQUALS, _3423, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3423)) {
        if (_3423 == 0) {
            DeRef(_3423);
            _3423 = 0;
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_3423)->dbl == 0.0) {
            DeRef(_3423);
            _3423 = 0;
            goto L6;
        }
    }
    DeRef(_3446);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3446 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3446);
    _0 = _3446;
    _2 = (int)SEQ_PTR(_3446);
    _3446 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_3446);
    DeRef(_0);
    DeRef(_3448);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3448 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_3448);
    _0 = _3448;
    _2 = (int)SEQ_PTR(_3448);
    _3448 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3448);
    DeRef(_0);
    _0 = _3448;
    if (IS_ATOM_INT(_3446) && IS_ATOM_INT(_3448)) {
        _3448 = (_3446 >= _3448);
    }
    else {
        _3448 = binary_op(GREATEREQ, _3446, _3448);
    }
    DeRef(_0);
    DeRef(_3423);
    if (IS_ATOM_INT(_3448))
        _3423 = (_3448 != 0);
    else
        _3423 = DBL_PTR(_3448)->dbl != 0.0;
L6:
L7:
    if (_3423 == 0)
        goto L8;
L5:

    // 	    if SymTab[sym][S_INITLEVEL] = -1 then
    DeRef(_3448);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3448 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3448);
    _0 = _3448;
    _2 = (int)SEQ_PTR(_3448);
    _3448 = (int)*(((s1_ptr)_2)->base + 13);
    Ref(_3448);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _3448, -1))
        goto L9;

    // 		if ref then
    if (_ref == 0)
        goto LA;

    // 		    if SymTab[sym][S_SCOPE] = SC_GLOBAL or 
    DeRef(_3448);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3448 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3448);
    _0 = _3448;
    _2 = (int)SEQ_PTR(_3448);
    _3448 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3448);
    DeRef(_0);
    _0 = _3448;
    if (IS_ATOM_INT(_3448)) {
        _3448 = (_3448 == 6);
    }
    else {
        _3448 = binary_op(EQUALS, _3448, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3448)) {
        if (_3448 != 0) {
            goto LB;
        }
    }
    else {
        if (DBL_PTR(_3448)->dbl != 0.0) {
            goto LB;
        }
    }
    DeRef(_3446);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3446 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3446);
    _0 = _3446;
    _2 = (int)SEQ_PTR(_3446);
    _3446 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3446);
    DeRef(_0);
    _0 = _3446;
    if (IS_ATOM_INT(_3446)) {
        _3446 = (_3446 == 5);
    }
    else {
        _3446 = binary_op(EQUALS, _3446, 5);
    }
    DeRef(_0);
LC:
    if (_3446 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_3446) && DBL_PTR(_3446)->dbl == 0.0)
            goto LD;
    }
LB:

    // 			emit_op(GLOBAL_INIT_CHECK) -- will become NOP2
    _15emit_op(109);
    goto LE;
LD:

    // 			emit_op(PRIVATE_INIT_CHECK)
    _15emit_op(30);
LE:

    // 		    emit_addr(sym)
    _15emit_addr(_sym);
LA:

    // 		if short_circuit <= 0 or short_circuit_B = FALSE then
    DeRef(_3446);
    _3446 = (_16short_circuit <= 0);
    if (_3446 != 0) {
        goto LF;
    }
    DeRef(_3448);
    _3448 = (_16short_circuit_B == 0);
L10:
    if (_3448 == 0)
        goto L11;
LF:

    // 		    init_stack = append(init_stack, sym)
    Append(&_16init_stack, _16init_stack, _sym);

    // 		    SymTab[sym][S_INITLEVEL] = stmt_nest
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 13);
    _1 = *(int *)_2;
    *(int *)_2 = _16stmt_nest;
    DeRef(_1);
L11:
L9:
L8:
L2:

    // end procedure
    DeRef(_3446);
    DeRef(_3448);
    DeRef(_3423);
    DeRef(_3427);
    return 0;
    ;
}


int _16InitDelete()
{
    int _3467;
    int _3469 = 0;
    int _0, _1, _2, _3;
    

    //     while length(init_stack) and 
L1:
    _3467 = SEQ_PTR(_16init_stack)->length;
    if (_3467 == 0) {
        goto L2;
    }
    DeRef(_3469);
    _3469 = SEQ_PTR(_16init_stack)->length;
    _2 = (int)SEQ_PTR(_16init_stack);
    _3469 = (int)*(((s1_ptr)_2)->base + _3469);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3469 = (int)*(((s1_ptr)_2)->base + _3469);
    Ref(_3469);
    _0 = _3469;
    _2 = (int)SEQ_PTR(_3469);
    _3469 = (int)*(((s1_ptr)_2)->base + 13);
    Ref(_3469);
    DeRef(_0);
    _0 = _3469;
    if (IS_ATOM_INT(_3469)) {
        _3469 = (_3469 > _16stmt_nest);
    }
    else {
        _3469 = binary_op(GREATER, _3469, _16stmt_nest);
    }
    DeRef(_0);
L3:
    if (_3469 <= 0) {
        if (_3469 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_3469) && DBL_PTR(_3469)->dbl == 0.0)
                goto L2;
        }
    }

    // 	SymTab[init_stack[$]][S_INITLEVEL] = -1
    DeRef(_3469);
    _3469 = SEQ_PTR(_16init_stack)->length;
    _2 = (int)SEQ_PTR(_16init_stack);
    _3469 = (int)*(((s1_ptr)_2)->base + _3469);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_3469 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 13);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	init_stack = init_stack[1..$-1]
    _3467 = SEQ_PTR(_16init_stack)->length;
    _3467 = _3467 - 1;
    rhs_slice_target = (object_ptr)&_16init_stack;
    RHS_Slice((s1_ptr)_16init_stack, 1, _3467);

    //     end while
    goto L1;
L2:

    // end procedure
    DeRef(_3469);
    return 0;
    ;
}


int _16emit_forward_addr()
{
    int _3481;
    int _0, _1, _2;
    

    //     emit_addr(0)
    _15emit_addr(0);

    //     branch_list = append(branch_list, length(Code))
    _3481 = SEQ_PTR(_7Code)->length;
    Append(&_16branch_list, _16branch_list, _3481);

    // end procedure
    return 0;
    ;
}


int _16StraightenBranches()
{
    int _br;
    int _target;
    int _3491 = 0;
    int _3483;
    int _0, _1, _2;
    

    //     if TRANSLATE then

    //     for i = length(branch_list) to 1 by -1 do
    _3483 = SEQ_PTR(_16branch_list)->length;
    { int _i;
        _i = _3483;
L1:
        if (_i < 1)
            goto L2;

        // 	target = Code[branch_list[i]]
        _2 = (int)SEQ_PTR(_16branch_list);
        _3483 = (int)*(((s1_ptr)_2)->base + _i);
        _2 = (int)SEQ_PTR(_7Code);
        _target = (int)*(((s1_ptr)_2)->base + _3483);
        if (!IS_ATOM_INT(_target))
            _target = (long)DBL_PTR(_target)->dbl;

        // 	if target <= length(Code) then
        _3483 = SEQ_PTR(_7Code)->length;
        if (_target > _3483)
            goto L3;

        // 	    br = Code[target]
        _2 = (int)SEQ_PTR(_7Code);
        _br = (int)*(((s1_ptr)_2)->base + _target);
        if (!IS_ATOM_INT(_br))
            _br = (long)DBL_PTR(_br)->dbl;

        // 	    if br = ELSE or br = ENDWHILE or br = EXIT then
        _3483 = (_br == 23);
        if (_3483 != 0) {
            _3483 = 1;
            goto L4;
        }
        DeRef(_3491);
        _3491 = (_br == 22);
        _3483 = (_3491 != 0);
L4:
        if (_3483 != 0) {
            goto L5;
        }
        _3483 = (_br == 61);
L6:
        if (_3483 == 0)
            goto L7;
L5:

        // 		backpatch(branch_list[i], Code[target+1])
        _2 = (int)SEQ_PTR(_16branch_list);
        _3483 = (int)*(((s1_ptr)_2)->base + _i);
        DeRef(_3491);
        _3491 = _target + 1;
        _2 = (int)SEQ_PTR(_7Code);
        _3491 = (int)*(((s1_ptr)_2)->base + _3491);
        Ref(_3491);
        Ref(_3491);
        _15backpatch(_3483, _3491);
L7:
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     branch_list = {}
    RefDS(_39);
    DeRefi(_16branch_list);
    _16branch_list = _39;

    // end procedure
    DeRef(_3491);
    return 0;
    ;
}


int _16AppendEList(int _addr)
{
    int _0, _1, _2;
    

    //     elist = append(elist, addr)
    Append(&_16elist, _16elist, _addr);

    // end procedure
    return 0;
    ;
}


int _16AppendXList(int _addr)
{
    int _0, _1, _2;
    

    //     exit_list = append(exit_list, addr)
    Append(&_16exit_list, _16exit_list, _addr);

    // end procedure
    return 0;
    ;
}


int _16PatchEList(int _base)
{
    int _elist_top;
    int _3502;
    int _3499;
    int _0, _1, _2;
    

    //     elist_top = length(elist)
    _elist_top = SEQ_PTR(_16elist)->length;

    //     while elist_top > base do
L1:
    if (_elist_top <= _base)
        goto L2;

    // 	backpatch(elist[elist_top], length(Code)+1)
    _2 = (int)SEQ_PTR(_16elist);
    _3499 = (int)*(((s1_ptr)_2)->base + _elist_top);
    _3502 = SEQ_PTR(_7Code)->length;
    _3502 = _3502 + 1;
    _15backpatch(_3499, _3502);

    // 	elist_top -= 1
    _elist_top = _elist_top - 1;

    //     end while
    goto L1;
L2:

    //     elist = elist[1..base]
    rhs_slice_target = (object_ptr)&_16elist;
    RHS_Slice((s1_ptr)_16elist, 1, _base);

    // end procedure
    return 0;
    ;
}


int _16PatchXList(int _base)
{
    int _exit_top;
    int _3509;
    int _3506;
    int _0, _1, _2;
    

    //     exit_top = length(exit_list)
    _exit_top = SEQ_PTR(_16exit_list)->length;

    //     while exit_top > base do
L1:
    if (_exit_top <= _base)
        goto L2;

    // 	backpatch(exit_list[exit_top], length(Code)+1)
    _2 = (int)SEQ_PTR(_16exit_list);
    _3506 = (int)*(((s1_ptr)_2)->base + _exit_top);
    _3509 = SEQ_PTR(_7Code)->length;
    _3509 = _3509 + 1;
    _15backpatch(_3506, _3509);

    // 	exit_top -= 1
    _exit_top = _exit_top - 1;

    //     end while
    goto L1;
L2:

    //     exit_list = exit_list[1..base] 
    rhs_slice_target = (object_ptr)&_16exit_list;
    RHS_Slice((s1_ptr)_16exit_list, 1, _base);

    // end procedure
    return 0;
    ;
}


int _16putback(int _t)
{
    int _0, _1, _2;
    

    //     backed_up_tok = t
    Ref(_t);
    DeRef(_16backed_up_tok);
    _16backed_up_tok = _t;

    // end procedure
    DeRef(_t);
    return 0;
    ;
}


int _16cache_line()
{
    int _ix;
    int _jx;
    int _line;
    int _tx;
    int _3517;
    int _3515;
    int _0, _1, _2;
    

    // 	if start_line[$] != length(slist) - 1 then
    _3515 = SEQ_PTR(_7start_line)->length;
    _2 = (int)SEQ_PTR(_7start_line);
    _3515 = (int)*(((s1_ptr)_2)->base + _3515);
    _3517 = SEQ_PTR(_7slist)->length;
    _3517 = _3517 - 1;
    if (_3515 == _3517)
        goto L1;

    // 		start_line &= length(slist) - 1
    _3517 = SEQ_PTR(_7slist)->length;
    _3517 = _3517 - 1;
    Append(&_7start_line, _7start_line, _3517);

    // 		if length(start_line) > 2 then
    _3517 = SEQ_PTR(_7start_line)->length;
    if (_3517 <= 2)
        goto L2;

    // 			start_line_token &= length(line_tokens)
    _3517 = SEQ_PTR(_7line_tokens)->length;
    Append(&_7start_line_token, _7start_line_token, _3517);
    goto L3;
L2:

    // 			start_line_token &= 1
    Append(&_7start_line_token, _7start_line_token, 1);
L3:
L1:

    // 	remember_line &= 1	
    Append(&_7remember_line, _7remember_line, 1);

    // end procedure
    return 0;
    ;
}


int _16release_line()
{
    int _ix;
    int _tx;
    int _3529;
    int _0, _1, _2;
    

    // 	remember_line = remember_line[1..$-1]
    _3529 = SEQ_PTR(_7remember_line)->length;
    _3529 = _3529 - 1;
    rhs_slice_target = (object_ptr)&_7remember_line;
    RHS_Slice((s1_ptr)_7remember_line, 1, _3529);

    // 	if not remember_line[$] then
    _3529 = SEQ_PTR(_7remember_line)->length;
    _2 = (int)SEQ_PTR(_7remember_line);
    _3529 = (int)*(((s1_ptr)_2)->base + _3529);
    if (_3529 != 0)
        goto L1;

    // 		start_line = {0} -- start_line[1..$-1]
    _0 = _7start_line;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _7start_line = MAKE_SEQ(_1);
    DeRefi(_0);

    // 		start_line_token = {0} --start_line_token[1..$-1]
    _0 = _7start_line_token;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _7start_line_token = MAKE_SEQ(_1);
    DeRefi(_0);
L1:

    // end procedure
    return 0;
    ;
}


int _16line_num(int _tok)
{
    int _3542 = 0;
    int _3537;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_tok)) {
        _1 = (long)(DBL_PTR(_tok)->dbl);
        DeRefDS(_tok);
        _tok = _1;
    }

    // 	for i = length(start_line_token) to 2 by -1 do
    _3537 = SEQ_PTR(_7start_line_token)->length;
    { int _i;
        _i = _3537;
L1:
        if (_i < 2)
            goto L2;

        // 		if tok >= start_line_token[i] then
        _2 = (int)SEQ_PTR(_7start_line_token);
        _3537 = (int)*(((s1_ptr)_2)->base + _i);
        if (_tok < _3537)
            goto L3;

        // 			return start_line[i]
        _2 = (int)SEQ_PTR(_7start_line);
        _3537 = (int)*(((s1_ptr)_2)->base + _i);
        DeRef(_3542);
        return _3537;
L3:

        // 	end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    // 	return length(slist) - atom( slist[$] )
    _3537 = SEQ_PTR(_7slist)->length;
    DeRef(_3542);
    _3542 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _3542 = (int)*(((s1_ptr)_2)->base + _3542);
    Ref(_3542);
    _0 = _3542;
    _3542 = IS_ATOM(_3542);
    DeRef(_0);
    _3542 = _3537 - _3542;
    return _3542;
    ;
}


int _16full_line()
{
    int _0, _1, _2;
    

    // 	replacing_full_line = 1
    _16replacing_full_line = 1;

    // end procedure
    return 0;
    ;
}


int _16token_text(int _tok1)
{
    int _lx;
    int _line = 0;
    int _bounds = 0;
    int _3546 = 0;
    int _3555 = 0;
    int _3556 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_tok1)) {
        _1 = (long)(DBL_PTR(_tok1)->dbl);
        DeRefDS(_tok1);
        _tok1 = _1;
    }

    // 	lx = line_num( tok1 )
    _lx = _16line_num(_tok1);

    // 	if atom(slist[$]) then
    _3546 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _3546 = (int)*(((s1_ptr)_2)->base + _3546);
    Ref(_3546);
    _0 = _3546;
    _3546 = IS_ATOM(_3546);
    DeRef(_0);
    if (_3546 == 0)
        goto L1;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L1:

    // 	if atom(slist[lx][SRC]) then
    DeRef(_3546);
    _2 = (int)SEQ_PTR(_7slist);
    _3546 = (int)*(((s1_ptr)_2)->base + _lx);
    Ref(_3546);
    _0 = _3546;
    _2 = (int)SEQ_PTR(_3546);
    _3546 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3546);
    DeRef(_0);
    _0 = _3546;
    _3546 = IS_ATOM(_3546);
    DeRef(_0);
    if (_3546 == 0)
        goto L2;

    // 		slist[lx][SRC] = fetch_line(slist[lx][SRC])
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _3 = (int)(_lx + ((s1_ptr)_2)->base);
    DeRef(_3556);
    _2 = (int)SEQ_PTR(_7slist);
    _3556 = (int)*(((s1_ptr)_2)->base + _lx);
    Ref(_3556);
    _0 = _3556;
    _2 = (int)SEQ_PTR(_3556);
    _3556 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3556);
    DeRef(_0);
    Ref(_3556);
    _0 = _3556;
    _3556 = _12fetch_line(_3556);
    DeRef(_0);
    RefDS(_3556);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _3556;
    DeRef(_1);
L2:

    // 	line = slist[lx]
    DeRef(_line);
    _2 = (int)SEQ_PTR(_7slist);
    _line = (int)*(((s1_ptr)_2)->base + _lx);
    Ref(_line);

    // 	bounds = token_boundaries[tok1]
    DeRef(_bounds);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _bounds = (int)*(((s1_ptr)_2)->base + _tok1);
    Ref(_bounds);

    // 	return line[SRC][bounds[1]..bounds[2]-1]
    DeRef(_3556);
    _2 = (int)SEQ_PTR(_line);
    _3556 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3556);
    DeRef(_3555);
    _2 = (int)SEQ_PTR(_bounds);
    _3555 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3555);
    DeRef(_3546);
    _2 = (int)SEQ_PTR(_bounds);
    _3546 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3546);
    _0 = _3546;
    if (IS_ATOM_INT(_3546)) {
        _3546 = _3546 - 1;
    }
    else {
        _3546 = binary_op(MINUS, _3546, 1);
    }
    DeRef(_0);
    rhs_slice_target = (object_ptr)&_3546;
    RHS_Slice((s1_ptr)_3556, _3555, _3546);
    DeRefDS(_line);
    DeRefDS(_bounds);
    DeRef(_3555);
    DeRef(_3556);
    return _3546;
    ;
}


int _16eat_token()
{
    int _bounds = 0;
    int _3572 = 0;
    int _3566 = 0;
    int _0, _1, _2;
    

    // 	if not length(token_boundaries) then
    _3566 = SEQ_PTR(_7token_boundaries)->length;
    if (_3566 != 0)
        goto L1;

    // 		bp -= 1
    _9bp = _9bp - 1;

    // 		return
    return 0;
L1:

    // 	bounds = token_boundaries[$]
    DeRef(_3566);
    _3566 = SEQ_PTR(_7token_boundaries)->length;
    DeRef(_bounds);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _bounds = (int)*(((s1_ptr)_2)->base + _3566);
    Ref(_bounds);

    // 	bp -= bounds[2] - bounds[1]
    _2 = (int)SEQ_PTR(_bounds);
    _3566 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3566);
    DeRef(_3572);
    _2 = (int)SEQ_PTR(_bounds);
    _3572 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3572);
    _0 = _3572;
    if (IS_ATOM_INT(_3566) && IS_ATOM_INT(_3572)) {
        _3572 = _3566 - _3572;
        if ((long)((unsigned long)_3572 +(unsigned long) HIGH_BITS) >= 0)
            _3572 = NewDouble((double)_3572);
    }
    else {
        _3572 = binary_op(MINUS, _3566, _3572);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3572)) {
        _9bp = _9bp - _3572;
    }
    else {
        _9bp = binary_op(MINUS, _9bp, _3572);
    }
    if (!IS_ATOM_INT(_9bp)) {
        _1 = (long)(DBL_PTR(_9bp)->dbl);
        DeRefDS(_9bp);
        _9bp = _1;
    }

    // 	token_boundaries = token_boundaries[1..$-1]
    DeRef(_3572);
    _3572 = SEQ_PTR(_7token_boundaries)->length;
    _3572 = _3572 - 1;
    rhs_slice_target = (object_ptr)&_7token_boundaries;
    RHS_Slice((s1_ptr)_7token_boundaries, 1, _3572);

    // 	line_tokens = line_tokens[1..$-1]
    _3572 = SEQ_PTR(_7line_tokens)->length;
    _3572 = _3572 - 1;
    rhs_slice_target = (object_ptr)&_7line_tokens;
    RHS_Slice((s1_ptr)_7line_tokens, 1, _3572);

    // end procedure
    DeRefDS(_bounds);
    DeRef(_3566);
    return 0;
    ;
}


int _16replace_tokens(int _tok1, int _tok2, int _text)
{
    int _line = 0;
    int _bounds = 0;
    int _old_len;
    int _new_len;
    int _lx1;
    int _lx2;
    int _lx;
    int _3665 = 0;
    int _3663 = 0;
    int _3586 = 0;
    int _3581 = 0;
    int _3598 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_tok1)) {
        _1 = (long)(DBL_PTR(_tok1)->dbl);
        DeRefDS(_tok1);
        _tok1 = _1;
    }
    if (!IS_ATOM_INT(_tok2)) {
        _1 = (long)(DBL_PTR(_tok2)->dbl);
        DeRefDS(_tok2);
        _tok2 = _1;
    }

    // 	lx1 = line_num( tok1 )
    _lx1 = _16line_num(_tok1);

    // 	lx2 = line_num( tok2 )
    _lx2 = _16line_num(_tok2);

    // 	if tok1 > length(token_boundaries) or tok2 > length(token_boundaries) then
    _3581 = SEQ_PTR(_7token_boundaries)->length;
    _3581 = (_tok1 > _3581);
    if (_3581 != 0) {
        goto L1;
    }
    _3586 = SEQ_PTR(_7token_boundaries)->length;
    _3586 = (_tok2 > _3586);
L2:
    if (_3586 == 0)
        goto L3;
L1:

    // 		InternalErr( "invalid tokens in replace_tokens()" )
    RefDS(_3588);
    _9InternalErr(_3588);
L3:

    // 	if atom(slist[$]) then
    DeRef(_3586);
    _3586 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _3586 = (int)*(((s1_ptr)_2)->base + _3586);
    Ref(_3586);
    _0 = _3586;
    _3586 = IS_ATOM(_3586);
    DeRef(_0);
    if (_3586 == 0)
        goto L4;

    // 		slist = s_expand( slist )
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L4:

    // 	if atom(slist[lx1][SRC]) then
    DeRef(_3586);
    _2 = (int)SEQ_PTR(_7slist);
    _3586 = (int)*(((s1_ptr)_2)->base + _lx1);
    Ref(_3586);
    _0 = _3586;
    _2 = (int)SEQ_PTR(_3586);
    _3586 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3586);
    DeRef(_0);
    _0 = _3586;
    _3586 = IS_ATOM(_3586);
    DeRef(_0);
    if (_3586 == 0)
        goto L5;

    // 		slist[lx1][SRC] = fetch_line(slist[lx1][SRC])
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _3 = (int)(_lx1 + ((s1_ptr)_2)->base);
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7slist);
    _3598 = (int)*(((s1_ptr)_2)->base + _lx1);
    Ref(_3598);
    _0 = _3598;
    _2 = (int)SEQ_PTR(_3598);
    _3598 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3598);
    DeRef(_0);
    Ref(_3598);
    _0 = _3598;
    _3598 = _12fetch_line(_3598);
    DeRef(_0);
    RefDS(_3598);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _3598;
    DeRef(_1);
L5:

    // 	line = slist[lx1][SRC]
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7slist);
    _3598 = (int)*(((s1_ptr)_2)->base + _lx1);
    Ref(_3598);
    DeRef(_line);
    _2 = (int)SEQ_PTR(_3598);
    _line = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_line);

    // 	if lx1 = lx2 then
    if (_lx1 != _lx2)
        goto L6;

    // 		line = slist[lx1][SRC]
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7slist);
    _3598 = (int)*(((s1_ptr)_2)->base + _lx1);
    Ref(_3598);
    DeRefDS(_line);
    _2 = (int)SEQ_PTR(_3598);
    _line = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_line);

    // 		old_len = token_boundaries[tok2][2] - token_boundaries[tok1][1]
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3598 = (int)*(((s1_ptr)_2)->base + _tok2);
    Ref(_3598);
    _0 = _3598;
    _2 = (int)SEQ_PTR(_3598);
    _3598 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3598);
    DeRef(_0);
    DeRef(_3581);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3581 = (int)*(((s1_ptr)_2)->base + _tok1);
    Ref(_3581);
    _0 = _3581;
    _2 = (int)SEQ_PTR(_3581);
    _3581 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3581);
    DeRef(_0);
    if (IS_ATOM_INT(_3598) && IS_ATOM_INT(_3581)) {
        _old_len = _3598 - _3581;
    }
    else {
        _old_len = binary_op(MINUS, _3598, _3581);
    }
    if (!IS_ATOM_INT(_old_len)) {
        _1 = (long)(DBL_PTR(_old_len)->dbl);
        DeRefDS(_old_len);
        _old_len = _1;
    }

    // 		new_len = length(text)
    _new_len = SEQ_PTR(_text)->length;

    // 		bounds = token_boundaries[tok1] & token_boundaries[tok2]
    DeRef(_3581);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3581 = (int)*(((s1_ptr)_2)->base + _tok1);
    Ref(_3581);
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3598 = (int)*(((s1_ptr)_2)->base + _tok2);
    Ref(_3598);
    if (IS_SEQUENCE(_3581) && IS_ATOM(_3598)) {
        Ref(_3598);
        Append(&_bounds, _3581, _3598);
    }
    else if (IS_ATOM(_3581) && IS_SEQUENCE(_3598)) {
        Ref(_3581);
        Prepend(&_bounds, _3598, _3581);
    }
    else {
        Concat((object_ptr)&_bounds, _3581, (s1_ptr)_3598);
    }

    // 		if bounds[$] = -1 then
    DeRef(_3598);
    _3598 = SEQ_PTR(_bounds)->length;
    _2 = (int)SEQ_PTR(_bounds);
    _3598 = (int)*(((s1_ptr)_2)->base + _3598);
    Ref(_3598);
    if (binary_op_a(NOTEQ, _3598, -1))
        goto L7;

    // 			bounds[$] = bounds[$-1]
    DeRef(_3598);
    _3598 = SEQ_PTR(_bounds)->length;
    DeRef(_3581);
    _3581 = SEQ_PTR(_bounds)->length;
    _3581 = _3581 - 1;
    _2 = (int)SEQ_PTR(_bounds);
    _3581 = (int)*(((s1_ptr)_2)->base + _3581);
    Ref(_3581);
    Ref(_3581);
    _2 = (int)SEQ_PTR(_bounds);
    _2 = (int)(((s1_ptr)_2)->base + _3598);
    _1 = *(int *)_2;
    *(int *)_2 = _3581;
    DeRef(_1);
L7:

    // 		line = line[1..token_boundaries[tok1][1]-1] & text & 
    DeRef(_3581);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3581 = (int)*(((s1_ptr)_2)->base + _tok1);
    Ref(_3581);
    _0 = _3581;
    _2 = (int)SEQ_PTR(_3581);
    _3581 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3581);
    DeRef(_0);
    _0 = _3581;
    if (IS_ATOM_INT(_3581)) {
        _3581 = _3581 - 1;
    }
    else {
        _3581 = binary_op(MINUS, _3581, 1);
    }
    DeRef(_0);
    rhs_slice_target = (object_ptr)&_3581;
    RHS_Slice((s1_ptr)_line, 1, _3581);
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3598 = (int)*(((s1_ptr)_2)->base + _tok2);
    Ref(_3598);
    _0 = _3598;
    _2 = (int)SEQ_PTR(_3598);
    _3598 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3598);
    DeRef(_0);
    DeRef(_3586);
    _3586 = SEQ_PTR(_line)->length;
    rhs_slice_target = (object_ptr)&_3586;
    RHS_Slice((s1_ptr)_line, _3598, _3586);
    {
        int concat_list[3];

        concat_list[0] = _3586;
        concat_list[1] = _text;
        concat_list[2] = _3581;
        Concat_N((object_ptr)&_line, concat_list, 3);
    }

    // 		if lx2 = length(slist) then
    DeRefDS(_3586);
    _3586 = SEQ_PTR(_7slist)->length;
    if (_lx2 != _3586)
        goto L8;

    // 			if replacing_full_line = 0 then
    if (_16replacing_full_line != 0)
        goto L9;

    // 				token_boundaries[tok2..$] += new_len - old_len -- (tok2 = length(token_boundaries))
    _3586 = SEQ_PTR(_7token_boundaries)->length;
    DeRef(_3598);
    _3598 = _new_len - _old_len;
    if ((long)((unsigned long)_3598 +(unsigned long) HIGH_BITS) >= 0)
        _3598 = NewDouble((double)_3598);
    rhs_slice_target = (object_ptr)&_3581;
    assign_slice_seq = (s1_ptr *)&_7token_boundaries;
    RHS_Slice((s1_ptr)_7token_boundaries, _tok2, _3586);
    _0 = _3581;
    _3581 = binary_op(PLUS, _3581, _3598);
    DeRefDS(_0);
    AssignSlice(_tok2, _3586, _3581);
    goto LA;
L9:

    // 				token_boundaries[tok2..$] += new_len - old_len
    DeRef(_3581);
    _3581 = SEQ_PTR(_7token_boundaries)->length;
    DeRef(_3598);
    _3598 = _new_len - _old_len;
    if ((long)((unsigned long)_3598 +(unsigned long) HIGH_BITS) >= 0)
        _3598 = NewDouble((double)_3598);
    rhs_slice_target = (object_ptr)&_3586;
    assign_slice_seq = (s1_ptr *)&_7token_boundaries;
    RHS_Slice((s1_ptr)_7token_boundaries, _tok2, _3581);
    _0 = _3586;
    _3586 = binary_op(PLUS, _3586, _3598);
    DeRefDS(_0);
    AssignSlice(_tok2, _3581, _3586);
LB:
    goto LA;
L8:

    // 			lx2 = find( lx2, start_line )
    _lx2 = find(_lx2, _7start_line);

    // 			token_boundaries[tok2..start_line_token[lx2+1]-1] += new_len - old_len 
    DeRef(_3586);
    _3586 = _lx2 + 1;
    _2 = (int)SEQ_PTR(_7start_line_token);
    _3586 = (int)*(((s1_ptr)_2)->base + _3586);
    _3586 = _3586 - 1;
    if ((long)((unsigned long)_3586 +(unsigned long) HIGH_BITS) >= 0)
        _3586 = NewDouble((double)_3586);
    DeRef(_3598);
    _3598 = _new_len - _old_len;
    if ((long)((unsigned long)_3598 +(unsigned long) HIGH_BITS) >= 0)
        _3598 = NewDouble((double)_3598);
    rhs_slice_target = (object_ptr)&_3581;
    assign_slice_seq = (s1_ptr *)&_7token_boundaries;
    RHS_Slice((s1_ptr)_7token_boundaries, _tok2, _3586);
    _0 = _3581;
    _3581 = binary_op(PLUS, _3581, _3598);
    DeRefDS(_0);
    AssignSlice(_tok2, _3586, _3581);
LA:

    // 		slist[lx1][SRC] = line
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _3 = (int)(_lx1 + ((s1_ptr)_2)->base);
    RefDS(_line);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _line;
    DeRef(_1);
    goto LC;
L6:

    // 		line = line[1..token_boundaries[tok1][1]-1] & text
    DeRef(_3598);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3598 = (int)*(((s1_ptr)_2)->base + _tok1);
    Ref(_3598);
    _0 = _3598;
    _2 = (int)SEQ_PTR(_3598);
    _3598 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3598);
    DeRef(_0);
    _0 = _3598;
    if (IS_ATOM_INT(_3598)) {
        _3598 = _3598 - 1;
    }
    else {
        _3598 = binary_op(MINUS, _3598, 1);
    }
    DeRef(_0);
    rhs_slice_target = (object_ptr)&_3598;
    RHS_Slice((s1_ptr)_line, 1, _3598);
    Concat((object_ptr)&_line, _3598, (s1_ptr)_text);

    // 		slist[lx1][SRC] = line
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _3 = (int)(_lx1 + ((s1_ptr)_2)->base);
    RefDS(_line);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _line;
    DeRef(_1);

    // 		for i = tok1 + 1 to tok2 do
    DeRef(_3581);
    _3581 = _tok1 + 1;
    if (_3581 > MAXINT)
        _3581 = NewDouble((double)_3581);
    DeRefDS(_3598);
    _3598 = _tok2;
    { int _i;
        Ref(_3581);
        _i = _3581;
LD:
        if (binary_op_a(GREATER, _i, _3598))
            goto LE;

        // 			slist[line_num(i)][SRC][token_boundaries[i][1]..token_boundaries[i][2]] = ' '
        Ref(_i);
        _0 = _3581;
        _3581 = _16line_num(_i);
        DeRef(_0);
        _2 = (int)SEQ_PTR(_7slist);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7slist = MAKE_SEQ(_2);
        }
        _3 = (int)(_3581 + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(object_ptr)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(object_ptr)_3 = MAKE_SEQ(_2);
        }
        _3 = (int)(1 + ((s1_ptr)_2)->base);
        DeRef(_3663);
        _2 = (int)SEQ_PTR(_7token_boundaries);
        if (!IS_ATOM_INT(_i))
            _3663 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _3663 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_3663);
        _0 = _3663;
        _2 = (int)SEQ_PTR(_3663);
        _3663 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3663);
        DeRef(_0);
        DeRef(_3665);
        _2 = (int)SEQ_PTR(_7token_boundaries);
        if (!IS_ATOM_INT(_i))
            _3665 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _3665 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_3665);
        _0 = _3665;
        _2 = (int)SEQ_PTR(_3665);
        _3665 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_3665);
        DeRef(_0);
        assign_slice_seq = (s1_ptr *)_3;
        AssignSlice(_3663, _3665, 32);

        // 		end for
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
        goto LD;
LE:
        ;
        DeRef(_i);
    }
LC:

    // 	if not find( current_file_no, processed_files ) then
    DeRef(_3665);
    _3665 = find(_7current_file_no, _7processed_files);
    if (_3665 != 0)
        goto LF;

    // 		processed_files &= current_file_no
    Append(&_7processed_files, _7processed_files, _7current_file_no);
LF:

    // 	replacing_full_line = 0
    _16replacing_full_line = 0;

    // 	slist &= 0
    Append(&_7slist, _7slist, 0);

    // end procedure
    DeRefDS(_text);
    DeRef(_line);
    DeRef(_bounds);
    DeRef5(_3665, _3663, _3586, _3581, _3598);
    return 0;
    ;
}


int _16next_token()
{
    int _t = 0;
    int _offset;
    int _3695 = 0;
    int _3679 = 0;
    int _3671 = 0;
    int _0, _1, _2, _3;
    

    //     if length(eval_error[$]) then
    _3671 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _3671 = (int)*(((s1_ptr)_2)->base + _3671);
    RefDS(_3671);
    _0 = _3671;
    _3671 = SEQ_PTR(_3671)->length;
    DeRefDS(_0);
    if (_3671 == 0)
        goto L1;

    //     	return {END_OF_FILE, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -21;
    ((int *)_2)[2] = 0;
    _3671 = MAKE_SEQ(_1);
    return _3671;
L1:

    //     if atom(backed_up_tok) then
    DeRef(_3671);
    _3671 = IS_ATOM(_16backed_up_tok);
    if (_3671 == 0)
        goto L2;

    // 	 t = Scanner() 
    _0 = _t;
    _t = _12Scanner();
    DeRef(_0);

    // 	 if preprocess then
    if (_7preprocess == 0)
        goto L3;

    // 	 	token_boundaries[$][2] = bp 
    _3671 = SEQ_PTR(_7token_boundaries)->length;
    _2 = (int)SEQ_PTR(_7token_boundaries);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7token_boundaries = MAKE_SEQ(_2);
    }
    _3 = (int)(_3671 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _9bp;
    DeRef(_1);

    // 	 	if length(token_boundaries) > 1 then
    DeRef(_3679);
    _3679 = SEQ_PTR(_7token_boundaries)->length;
    if (_3679 <= 1)
        goto L4;

    // 	 		offset = token_boundaries[$][1] - token_boundaries[$-1][2]
    _3679 = SEQ_PTR(_7token_boundaries)->length;
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3679 = (int)*(((s1_ptr)_2)->base + _3679);
    Ref(_3679);
    _0 = _3679;
    _2 = (int)SEQ_PTR(_3679);
    _3679 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3679);
    DeRef(_0);
    _3671 = SEQ_PTR(_7token_boundaries)->length;
    _3671 = _3671 - 1;
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3671 = (int)*(((s1_ptr)_2)->base + _3671);
    Ref(_3671);
    _0 = _3671;
    _2 = (int)SEQ_PTR(_3671);
    _3671 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3671);
    DeRef(_0);
    if (IS_ATOM_INT(_3679) && IS_ATOM_INT(_3671)) {
        _offset = _3679 - _3671;
    }
    else {
        _offset = binary_op(MINUS, _3679, _3671);
    }
    if (!IS_ATOM_INT(_offset)) {
        _1 = (long)(DBL_PTR(_offset)->dbl);
        DeRefDS(_offset);
        _offset = _1;
    }

    // 	 		if offset < 0 then
    if (_offset >= 0)
        goto L5;

    // 	 			token_boundaries[$] -= (offset)- token_ws[$] --+ whitespace_count
    DeRef(_3671);
    _3671 = SEQ_PTR(_7token_boundaries)->length;
    DeRef(_3679);
    _3679 = SEQ_PTR(_7token_ws)->length;
    _2 = (int)SEQ_PTR(_7token_ws);
    _3679 = (int)*(((s1_ptr)_2)->base + _3679);
    Ref(_3679);
    _0 = _3679;
    if (IS_ATOM_INT(_3679)) {
        _3679 = _offset - _3679;
        if ((long)((unsigned long)_3679 +(unsigned long) HIGH_BITS) >= 0)
            _3679 = NewDouble((double)_3679);
    }
    else {
        _3679 = binary_op(MINUS, _offset, _3679);
    }
    DeRef(_0);
    DeRef(_3695);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _3695 = (int)*(((s1_ptr)_2)->base + _3671);
    Ref(_3695);
    _0 = _3695;
    if (IS_ATOM_INT(_3695) && IS_ATOM_INT(_3679)) {
        _3695 = _3695 - _3679;
        if ((long)((unsigned long)_3695 +(unsigned long) HIGH_BITS) >= 0)
            _3695 = NewDouble((double)_3695);
    }
    else {
        _3695 = binary_op(MINUS, _3695, _3679);
    }
    DeRef(_0);
    Ref(_3695);
    _2 = (int)SEQ_PTR(_7token_boundaries);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7token_boundaries = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _3671);
    _1 = *(int *)_2;
    *(int *)_2 = _3695;
    DeRef(_1);
L5:
L4:

    // 	 	line_tokens = append( line_tokens, t )
    RefDS(_t);
    Append(&_7line_tokens, _7line_tokens, _t);
L6:
    goto L3;
L2:

    // 	 t = backed_up_tok 
    Ref(_16backed_up_tok);
    DeRef(_t);
    _t = _16backed_up_tok;

    // 	 backed_up_tok = UNDEFINED 
    DeRef(_16backed_up_tok);
    _16backed_up_tok = -999;
L3:

    //     return t
    DeRef(_3695);
    DeRef(_3679);
    DeRef(_3671);
    return _t;
    ;
}


int _16Expr_list()
{
    int _tok = 0;
    int _n;
    int _3698 = 0;
    int _0, _1, _2;
    

    //     tok = next_token()
    _tok = _16next_token();

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    //     if tok[T_ID] = RIGHT_BRACE then
    _2 = (int)SEQ_PTR(_tok);
    _3698 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3698);
    if (binary_op_a(NOTEQ, _3698, -25))
        goto L1;

    // 	return 0
    DeRefDS(_tok);
    DeRef(_3698);
    return 0;
    goto L2;
L1:

    // 	n = 0
    _n = 0;

    // 	short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    // 	while TRUE do 
L3:

    // 	    call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 	    n += 1
    _n = _n + 1;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 	    if tok[T_ID] != COMMA then
    DeRef(_3698);
    _2 = (int)SEQ_PTR(_tok);
    _3698 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3698);
    if (binary_op_a(EQUALS, _3698, -30))
        goto L3;

    // 		exit
    goto L4;
L5:

    // 	end while  
    goto L3;
L4:

    // 	short_circuit += 1
    _16short_circuit = _16short_circuit + 1;
L2:

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    //     return n
    DeRefDS(_tok);
    DeRef(_3698);
    return _n;
    ;
}


int _16tok_match(int _tok)
{
    int _t = 0;
    int _expected = 0;
    int _actual = 0;
    int _3707 = 0;
    int _0, _1, _2;
    

    //     t = next_token()
    _t = _16next_token();

    //     if t[T_ID] != tok then
    _2 = (int)SEQ_PTR(_t);
    _3707 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3707);
    if (binary_op_a(EQUALS, _3707, _tok))
        goto L1;

    // 	expected = LexName(tok)
    _expected = _15LexName(_tok);

    // 	actual = LexName(t[T_ID])
    DeRef(_3707);
    _2 = (int)SEQ_PTR(_t);
    _3707 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3707);
    Ref(_3707);
    _actual = _15LexName(_3707);

    // 	CompileErr(sprintf(
    DeRef(_3707);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _expected;
    RefDS(_expected);
    ((int *)_2)[2] = _actual;
    RefDS(_actual);
    _3707 = MAKE_SEQ(_1);
    _0 = _3707;
    _3707 = EPrintf(-9999999, _3713, _3707);
    DeRefDS(_0);
    RefDS(_3707);
    _9CompileErr(_3707);

    // 	return
    DeRefDS(_t);
    DeRefDS(_expected);
    DeRefDS(_actual);
    DeRefDSi(_3707);
    return 0;
L1:

    // end procedure
    DeRef(_t);
    DeRef(_expected);
    DeRef(_actual);
    DeRef(_3707);
    return 0;
    ;
}


int _16UndefinedVar(int _s)
{
    int _dup;
    int _errmsg = 0;
    int _3730 = 0;
    int _3716 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     if SymTab[s][S_SCOPE] = SC_UNDEFINED then
    _2 = (int)SEQ_PTR(_7SymTab);
    _3716 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3716);
    _0 = _3716;
    _2 = (int)SEQ_PTR(_3716);
    _3716 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3716);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _3716, 9))
        goto L1;

    // 	CompileErr(sprintf("%s has not been declared", {SymTab[s][S_NAME]}))
    DeRef(_3716);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3716 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3716);
    _0 = _3716;
    _2 = (int)SEQ_PTR(_3716);
    _3716 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3716);
    DeRef(_0);
    _0 = _3716;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3716);
    *((int *)(_2+4)) = _3716;
    _3716 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3716;
    _3716 = EPrintf(-9999999, _3719, _3716);
    DeRefDS(_0);
    RefDS(_3716);
    _9CompileErr(_3716);

    //     return 1
    DeRefDSi(_3716);
    return 1;
    goto L2;
L1:

    //     elsif SymTab[s][S_SCOPE] = SC_MULTIPLY_DEFINED then
    DeRef(_3716);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3716 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3716);
    _0 = _3716;
    _2 = (int)SEQ_PTR(_3716);
    _3716 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3716);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _3716, 10))
        goto L3;

    // 	errmsg = sprintf("A namespace qualifier is needed to resolve %s.\n%s is defined as a global symbol in:\n", 
    DeRef(_3716);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3716 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3716);
    _0 = _3716;
    _2 = (int)SEQ_PTR(_3716);
    _3716 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3716);
    DeRef(_0);
    DeRef(_3730);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3730 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3730);
    _0 = _3730;
    _2 = (int)SEQ_PTR(_3730);
    _3730 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3730);
    DeRef(_0);
    _0 = _3730;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _3716;
    Ref(_3716);
    ((int *)_2)[2] = _3730;
    Ref(_3730);
    _3730 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_errmsg);
    _errmsg = EPrintf(-9999999, _3727, _3730);

    // 	for i = length(dup_globals) to 1 by -1 do
    DeRefDS(_3730);
    _3730 = SEQ_PTR(_11dup_globals)->length;
    { int _i;
        _i = _3730;
L4:
        if (_i < 1)
            goto L5;

        // 	    dup = dup_globals[i]
        _2 = (int)SEQ_PTR(_11dup_globals);
        _dup = (int)*(((s1_ptr)_2)->base + _i);

        // 	    errmsg &= "    " & file_name[SymTab[dup][S_FILE_NO]] & "\n"
        DeRef(_3730);
        _2 = (int)SEQ_PTR(_7SymTab);
        _3730 = (int)*(((s1_ptr)_2)->base + _dup);
        Ref(_3730);
        _0 = _3730;
        _2 = (int)SEQ_PTR(_3730);
        _3730 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_3730);
        DeRef(_0);
        _0 = _3730;
        _2 = (int)SEQ_PTR(_7file_name);
        if (!IS_ATOM_INT(_3730))
            _3730 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3730)->dbl));
        else
            _3730 = (int)*(((s1_ptr)_2)->base + _3730);
        Ref(_3730);
        DeRef(_0);
        {
            int concat_list[3];

            concat_list[0] = _738;
            concat_list[1] = _3730;
            concat_list[2] = _3736;
            Concat_N((object_ptr)&_3730, concat_list, 3);
        }
        Concat((object_ptr)&_errmsg, _errmsg, (s1_ptr)_3730);

        // 	end for
        _i = _i + -1;
        goto L4;
L5:
        ;
    }

    // 	CompileErr(errmsg)
    RefDS(_errmsg);
    _9CompileErr(_errmsg);

    // 	return 1
    DeRefDS(_errmsg);
    DeRef(_3730);
    DeRef(_3716);
    return 1;
L3:
L2:

    //     return 0
    DeRef(_errmsg);
    DeRef(_3730);
    DeRef(_3716);
    return 0;
    ;
}


int _16WrongNumberArgs(int _subsym, int _only)
{
    int _plural = 0;
    int _3749 = 0;
    int _3742 = 0;
    int _0, _1, _2;
    

    //     if SymTab[subsym][S_NUM_ARGS] = 1 then
    _2 = (int)SEQ_PTR(_7SymTab);
    _3742 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_3742);
    _0 = _3742;
    _2 = (int)SEQ_PTR(_3742);
    _3742 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3742);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _3742, 1))
        goto L1;

    // 	plural = ""
    RefDS(_39);
    _plural = _39;
    goto L2;
L1:

    // 	plural = "s"
    RefDS(_3745);
    DeRefi(_plural);
    _plural = _3745;
L2:

    //     CompileErr(sprintf("%s takes %s%d argument%s", 
    DeRef(_3742);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3742 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_3742);
    _0 = _3742;
    _2 = (int)SEQ_PTR(_3742);
    _3742 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3742);
    DeRef(_0);
    DeRef(_3749);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3749 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_3749);
    _0 = _3749;
    _2 = (int)SEQ_PTR(_3749);
    _3749 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3749);
    DeRef(_0);
    _0 = _3749;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3742);
    *((int *)(_2+4)) = _3742;
    RefDS(_only);
    *((int *)(_2+8)) = _only;
    Ref(_3749);
    *((int *)(_2+12)) = _3749;
    RefDS(_plural);
    *((int *)(_2+16)) = _plural;
    _3749 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3749;
    _3749 = EPrintf(-9999999, _3746, _3749);
    DeRefDS(_0);
    RefDS(_3749);
    _9CompileErr(_3749);

    // end procedure
    DeRefDSi(_only);
    DeRefDSi(_plural);
    DeRefDSi(_3749);
    DeRef(_3742);
    return 0;
    ;
}


int _16ParseArgs(int _subsym)
{
    int _n;
    int _tok = 0;
    int _3757 = 0;
    int _3753 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_subsym)) {
        _1 = (long)(DBL_PTR(_subsym)->dbl);
        DeRefDS(_subsym);
        _subsym = _1;
    }

    //     n = SymTab[subsym][S_NUM_ARGS]
    _2 = (int)SEQ_PTR(_7SymTab);
    _3753 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_3753);
    _2 = (int)SEQ_PTR(_3753);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    //     for i = 1 to n do
    DeRef(_3753);
    _3753 = _n;
    { int _i;
        _i = 1;
L1:
        if (_i > _3753)
            goto L2;

        // 	call_proc(forward_expr, {})
        _0 = (int)_00[_16forward_expr].addr;
        (*(int (*)())_0)(
                             );

        // 	if i != n then 
        if (_i == _n)
            goto L3;

        // 	    tok = next_token()
        _0 = _tok;
        _tok = _16next_token();
        DeRef(_0);

        // 	    if tok[T_ID] != COMMA then
        DeRef(_3757);
        _2 = (int)SEQ_PTR(_tok);
        _3757 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3757);
        if (binary_op_a(EQUALS, _3757, -30))
            goto L4;

        // 		if tok[T_ID] = RIGHT_ROUND then
        DeRef(_3757);
        _2 = (int)SEQ_PTR(_tok);
        _3757 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3757);
        if (binary_op_a(NOTEQ, _3757, -27))
            goto L5;

        // 		    WrongNumberArgs(subsym, "")
        RefDS(_39);
        _16WrongNumberArgs(_subsym, _39);
        goto L6;
L5:

        // 		    putback(tok)
        RefDS(_tok);
        _16putback(_tok);

        // 		    tok_match(COMMA)
        _16tok_match(-30);
L6:
L4:
L3:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     short_circuit += 1
    _16short_circuit = _16short_circuit + 1;

    //     if tok[T_ID] != RIGHT_ROUND then
    DeRef(_3757);
    _2 = (int)SEQ_PTR(_tok);
    _3757 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3757);
    if (binary_op_a(EQUALS, _3757, -27))
        goto L7;

    // 	if tok[T_ID] = COMMA then
    DeRef(_3757);
    _2 = (int)SEQ_PTR(_tok);
    _3757 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3757);
    if (binary_op_a(NOTEQ, _3757, -30))
        goto L8;

    // 	    WrongNumberArgs(subsym, "only ")
    RefDS(_3769);
    _16WrongNumberArgs(_subsym, _3769);
    goto L9;
L8:

    // 	    putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 	    tok_match(RIGHT_ROUND)
    _16tok_match(-27);
L9:
L7:

    // end procedure
    DeRef(_tok);
    DeRef(_3757);
    DeRef(_3753);
    return 0;
    ;
}


int _16TypeLCD(int _t1, int _t2)
{
    int _s;
    int _3770 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_t1)) {
        _1 = (long)(DBL_PTR(_t1)->dbl);
        DeRefDS(_t1);
        _t1 = _1;
    }

    // 	if t1 = t2 then
    if (_t1 != _t2)
        goto L1;

    // 		return t1
    return _t1;
L1:

    // 	s = t2
    _s = _t2;

    // 	while s != t1 do
L2:
    if (_s == _t1)
        goto L3;

    // 		if find( s, {integer_type, atom_type, sequence_type, object_type}) then
    _0 = _3770;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _11integer_type;
    *((int *)(_2+8)) = _11atom_type;
    *((int *)(_2+12)) = _11sequence_type;
    *((int *)(_2+16)) = _11object_type;
    _3770 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3770;
    _3770 = find(_s, _3770);
    DeRefDSi(_0);
    if (_3770 == 0)
        goto L4;

    // 			exit
    goto L3;
    goto L2;
L4:

    // 		elsif length( SymTab[s] ) > S_VTYPE then
    DeRef(_3770);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3770 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3770);
    _0 = _3770;
    _3770 = SEQ_PTR(_3770)->length;
    DeRef(_0);
    if (_3770 <= 14)
        goto L5;

    // 			exit
    goto L3;
    goto L2;
L5:

    // 			s = SymTab[s][S_VTYPE]
    DeRef(_3770);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3770 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3770);
    _2 = (int)SEQ_PTR(_3770);
    _s = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;
L6:

    // 	end while
    goto L2;
L3:

    // 	if s = t1 then
    if (_s != _t1)
        goto L7;

    // 		return s
    DeRef(_3770);
    return _s;
L7:

    // 	s = t1
    _s = _t1;

    // 	while s != t2 do
L8:
    if (_s == _t2)
        goto L9;

    // 		if find( s, {integer_type, atom_type, sequence_type, object_type}) then
    _0 = _3770;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _11integer_type;
    *((int *)(_2+8)) = _11atom_type;
    *((int *)(_2+12)) = _11sequence_type;
    *((int *)(_2+16)) = _11object_type;
    _3770 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3770;
    _3770 = find(_s, _3770);
    DeRefDSi(_0);
    if (_3770 == 0)
        goto LA;

    // 			exit
    goto L9;
    goto L8;
LA:

    // 		elsif length( SymTab[s] ) > S_VTYPE then
    DeRef(_3770);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3770 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3770);
    _0 = _3770;
    _3770 = SEQ_PTR(_3770)->length;
    DeRef(_0);
    if (_3770 <= 14)
        goto LB;

    // 			exit
    goto L9;
    goto L8;
LB:

    // 			s = SymTab[s][S_VTYPE]
    DeRef(_3770);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3770 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_3770);
    _2 = (int)SEQ_PTR(_3770);
    _s = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;
LC:

    // 	end while
    goto L8;
L9:

    // 	if s = t2 then
    if (_s != _t2)
        goto LD;

    // 		return s
    DeRef(_3770);
    return _s;
LD:

    // 	return object_type
    DeRef(_3770);
    return _11object_type;
    ;
}


int _16token_type(int _tok)
{
    int _the_type;
    int _obj = 0;
    int _3790 = 0;
    int _3789 = 0;
    int _0, _1, _2;
    

    // 	if find( tok[T_ID], {TYPE, QUALIFIED_TYPE})  then
    _2 = (int)SEQ_PTR(_tok);
    _3789 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3789);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 504;
    ((int *)_2)[2] = 526;
    _3790 = MAKE_SEQ(_1);
    _0 = _3790;
    _3790 = find(_3789, _3790);
    DeRefDSi(_0);
    if (_3790 == 0)
        goto L1;

    // 		the_type = object_type
    _the_type = _11object_type;
    goto L2;
L1:

    // 	elsif find( tok[T_ID], {r:FUNC, QUALIFIED_FUNC}) then
    DeRef(_3790);
    _2 = (int)SEQ_PTR(_tok);
    _3790 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3790);
    DeRef(_3789);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 501;
    ((int *)_2)[2] = 524;
    _3789 = MAKE_SEQ(_1);
    _0 = _3789;
    _3789 = find(_3790, _3789);
    DeRefDSi(_0);
    if (_3789 == 0)
        goto L3;

    // 		if SymTab[tok[T_SYM]][S_OBJ] = NOVALUE then
    _2 = (int)SEQ_PTR(_tok);
    _3789 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3789);
    _0 = _3789;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3789))
        _3789 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3789)->dbl));
    else
        _3789 = (int)*(((s1_ptr)_2)->base + _3789);
    Ref(_3789);
    DeRef(_0);
    _0 = _3789;
    _2 = (int)SEQ_PTR(_3789);
    _3789 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3789);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _3789, _7NOVALUE))
        goto L4;

    // 			the_type = object_type
    _the_type = _11object_type;
    goto L2;
L4:

    // 			the_type = SymTab[tok[T_SYM]][S_OBJ]
    DeRef(_3789);
    _2 = (int)SEQ_PTR(_tok);
    _3789 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3789);
    _0 = _3789;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3789))
        _3789 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3789)->dbl));
    else
        _3789 = (int)*(((s1_ptr)_2)->base + _3789);
    Ref(_3789);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_3789);
    _the_type = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_the_type))
        _the_type = (long)DBL_PTR(_the_type)->dbl;
L5:
    goto L2;
L3:

    // 	elsif tok[T_ID] = ATOM then
    DeRef(_3789);
    _2 = (int)SEQ_PTR(_tok);
    _3789 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3789);
    if (binary_op_a(NOTEQ, _3789, 502))
        goto L6;

    // 		the_type = atom_type
    _the_type = _11atom_type;
    goto L2;
L6:

    // 	elsif find(tok[T_ID], {STRING, LEFT_BRACE}) then
    DeRef(_3789);
    _2 = (int)SEQ_PTR(_tok);
    _3789 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3789);
    DeRef(_3790);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 503;
    ((int *)_2)[2] = -24;
    _3790 = MAKE_SEQ(_1);
    _0 = _3790;
    _3790 = find(_3789, _3790);
    DeRefDSi(_0);
    if (_3790 == 0)
        goto L7;

    // 		the_type = sequence_type
    _the_type = _11sequence_type;
    goto L2;
L7:

    // 		the_type = SymTab[tok[T_SYM]][S_VTYPE]
    DeRef(_3790);
    _2 = (int)SEQ_PTR(_tok);
    _3790 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3790);
    _0 = _3790;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3790))
        _3790 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3790)->dbl));
    else
        _3790 = (int)*(((s1_ptr)_2)->base + _3790);
    Ref(_3790);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_3790);
    _the_type = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_the_type))
        _the_type = (long)DBL_PTR(_the_type)->dbl;

    // 		if not the_type then
    if (_the_type != 0)
        goto L8;

    // 			obj = SymTab[tok[T_SYM]][S_OBJ]
    DeRef(_3790);
    _2 = (int)SEQ_PTR(_tok);
    _3790 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3790);
    _0 = _3790;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3790))
        _3790 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3790)->dbl));
    else
        _3790 = (int)*(((s1_ptr)_2)->base + _3790);
    Ref(_3790);
    DeRef(_0);
    DeRef(_obj);
    _2 = (int)SEQ_PTR(_3790);
    _obj = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_obj);

    // 			if sequence( obj ) then
    DeRef(_3790);
    _3790 = IS_SEQUENCE(_obj);
    if (_3790 == 0)
        goto L9;

    // 				return sequence_type
    DeRefDS(_tok);
    DeRef(_obj);
    DeRef(_3789);
    return _11sequence_type;
    goto LA;
L9:

    // 			elsif integer( obj ) then
    DeRef(_3790);
    if (IS_ATOM_INT(_obj))
        _3790 = 1;
    else if (IS_ATOM_DBL(_obj))
        _3790 = IS_ATOM_INT(DoubleToInt(_obj));
    else
        _3790 = 0;
    if (_3790 == 0)
        goto LB;

    // 				return integer_type
    DeRefDS(_tok);
    DeRef(_obj);
    DeRef(_3789);
    return _11integer_type;
    goto LA;
LB:
    DeRefDS(_tok);
    DeRef(_obj);
    DeRef(_3790);
    DeRef(_3789);
    return _11atom_type;
LA:
L8:
L2:

    // 	return the_type
    DeRefDS(_tok);
    DeRef(_obj);
    DeRef(_3790);
    DeRef(_3789);
    return _the_type;
    ;
}


