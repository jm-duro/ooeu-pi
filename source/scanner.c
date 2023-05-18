// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _12InitLex()
{
    int _1749 = 0;
    int _1742;
    int _1740;
    int _0, _1, _2;
    

    //     gline_number = 0
    _7gline_number = 0;

    //     line_number = 0
    _7line_number = 0;

    //     IncludeStk = {}
    RefDS(_39);
    DeRef(_12IncludeStk);
    _12IncludeStk = _39;

    //     char_class = repeat(ILLEGAL_CHAR, 255)  -- we screen out the 0 character
    DeRefi(_12char_class);
    _12char_class = Repeat(-20, 255);

    //     char_class['0'..'9'] = DIGIT
    assign_slice_seq = (s1_ptr *)&_12char_class;
    AssignSlice(48, 57, -7);

    //     char_class['a'..'z'] = LETTER
    assign_slice_seq = (s1_ptr *)&_12char_class;
    AssignSlice(97, 122, -2);

    //     char_class['A'..'Z'] = LETTER
    assign_slice_seq = (s1_ptr *)&_12char_class;
    AssignSlice(65, 90, -2);

    //     char_class[KEYWORD_BASE+1..KEYWORD_BASE+NUM_KEYWORDS] = KEYWORD
    _1740 = 129;
    _1742 = 152;
    assign_slice_seq = (s1_ptr *)&_12char_class;
    AssignSlice(129, 152, -10);

    //     char_class[BUILTIN_BASE+1..BUILTIN_BASE+NUM_BUILTINS] = BUILTIN
    _1742 = 171;
    _1740 = 234;
    assign_slice_seq = (s1_ptr *)&_12char_class;
    AssignSlice(171, 234, -9);

    //     char_class[' '] = BLANK
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 32);
    *(int *)_2 = -8;

    //     char_class['\t'] = BLANK
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 9);
    *(int *)_2 = -8;

    //     char_class['+'] = PLUS
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 43);
    *(int *)_2 = 11;

    //     char_class['-'] = MINUS
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 45);
    *(int *)_2 = 10;

    //     char_class['*'] = MULTIPLY
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 42);
    *(int *)_2 = 13;

    //     char_class['/'] = DIVIDE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 47);
    *(int *)_2 = 14;

    //     char_class['='] = EQUALS
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 61);
    *(int *)_2 = 3;

    //     char_class['<'] = LESS
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 60);
    *(int *)_2 = 1;

    //     char_class['>'] = GREATER
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 62);
    *(int *)_2 = 6;

    //     char_class['\''] = SINGLE_QUOTE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 39);
    *(int *)_2 = -5;

    //     char_class['"'] = DOUBLE_QUOTE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 34);
    *(int *)_2 = -4;

    //     char_class['.'] = DOT
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 46);
    *(int *)_2 = -3;

    //     char_class[':'] = COLON
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 58);
    *(int *)_2 = -23;

    //     char_class['\r'] = NEWLINE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 13);
    *(int *)_2 = -6;

    //     char_class['\n'] = NEWLINE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 10);
    *(int *)_2 = -6;

    //     char_class['!'] = BANG
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 33);
    *(int *)_2 = -1;

    //     char_class['{'] = LEFT_BRACE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 123);
    *(int *)_2 = -24;

    //     char_class['}'] = RIGHT_BRACE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 125);
    *(int *)_2 = -25;

    //     char_class['('] = LEFT_ROUND
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 40);
    *(int *)_2 = -26;

    //     char_class[')'] = RIGHT_ROUND
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 41);
    *(int *)_2 = -27;

    //     char_class['['] = LEFT_SQUARE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 91);
    *(int *)_2 = -28;

    //     char_class[']'] = RIGHT_SQUARE
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 93);
    *(int *)_2 = -29;

    //     char_class['$'] = DOLLAR
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 36);
    *(int *)_2 = -22;

    //     char_class[','] = COMMA
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 44);
    *(int *)_2 = -30;

    //     char_class['&'] = CONCAT
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 38);
    *(int *)_2 = 15;

    //     char_class['?'] = QUESTION_MARK
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 63);
    *(int *)_2 = -31;

    //     char_class['#'] = NUMBER_SIGN
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 35);
    *(int *)_2 = -11;

    //     char_class[END_OF_FILE_CHAR] = END_OF_FILE 
    _2 = (int)SEQ_PTR(_12char_class);
    _2 = (int)(((s1_ptr)_2)->base + 26);
    *(int *)_2 = -21;

    //     id_char = repeat(FALSE, 255)
    DeRefi(_12id_char);
    _12id_char = Repeat(0, 255);

    //     for i = 1 to 255 do
    { int _i;
        _i = 1;
L1:
        if (_i > 255)
            goto L2;

        // 	if i = '_' or find(char_class[i], {LETTER, DIGIT}) then
        _1740 = (_i == 95);
        if (_1740 != 0) {
            goto L3;
        }
        _2 = (int)SEQ_PTR(_12char_class);
        _1742 = (int)*(((s1_ptr)_2)->base + _i);
        DeRef(_1749);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = -2;
        ((int *)_2)[2] = -7;
        _1749 = MAKE_SEQ(_1);
        _0 = _1749;
        _1749 = find(_1742, _1749);
        DeRefDSi(_0);
L4:
        if (_1749 == 0)
            goto L5;
L3:

        // 	    id_char[i] = TRUE
        _2 = (int)SEQ_PTR(_12id_char);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = 1;
L5:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef(_1749);
    return 0;
    ;
}


int _12ResetTP()
{
    int _0, _1, _2;
    

    //     OpTrace = FALSE
    _7OpTrace = 0;

    //     OpProfileStatement = FALSE
    _7OpProfileStatement = 0;

    //     OpProfileTime = FALSE
    _7OpProfileTime = 0;

    //     AnyStatementProfile = FALSE
    _12AnyStatementProfile = 0;

    //     AnyTimeProfile = FALSE
    _12AnyTimeProfile = 0;

    // end procedure
    return 0;
    ;
}


int _12rollback_source(int _line)
{
    int _chunk;
    int _start;
    int _1759 = 0;
    int _1752 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_line)) {
        _1 = (long)(DBL_PTR(_line)->dbl);
        DeRefDS(_line);
        _line = _1;
    }

    // 	start = slist[line][LINE]
    _2 = (int)SEQ_PTR(_7slist);
    _1752 = (int)*(((s1_ptr)_2)->base + _line);
    Ref(_1752);
    _2 = (int)SEQ_PTR(_1752);
    _start = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_start))
        _start = (long)DBL_PTR(_start)->dbl;

    //     chunk = 1+floor( start / SOURCE_CHUNK)
    DeRef(_1752);
    if (10000 > 0 && _start >= 0) {
        _1752 = _start / 10000;
    }
    else {
        temp_dbl = floor((double)_start / (double)10000);
        _1752 = (long)temp_dbl;
    }
    _chunk = _1752 + 1;

    //     if length(all_source) then
    _1752 = SEQ_PTR(_12all_source)->length;
    if (_1752 == 0)
        goto L1;

    // 	    while length(all_source) and chunk > length(all_source) do
L2:
    DeRef(_1752);
    _1752 = SEQ_PTR(_12all_source)->length;
    if (_1752 == 0) {
        goto L3;
    }
    DeRef(_1759);
    _1759 = SEQ_PTR(_12all_source)->length;
    _1759 = (_chunk > _1759);
L4:
    if (_1759 == 0)
        goto L3;

    // 	    	free( all_source[$] )
    DeRef(_1759);
    _1759 = SEQ_PTR(_12all_source)->length;
    _2 = (int)SEQ_PTR(_12all_source);
    _1759 = (int)*(((s1_ptr)_2)->base + _1759);
    Ref(_1759);
    Ref(_1759);
    _4free(_1759);

    // 	    	all_source = all_source[1..$-1]
    DeRef(_1759);
    _1759 = SEQ_PTR(_12all_source)->length;
    _1759 = _1759 - 1;
    rhs_slice_target = (object_ptr)&_12all_source;
    RHS_Slice((s1_ptr)_12all_source, 1, _1759);

    // 	    end while
    goto L2;
L3:

    // 	    current_source = all_source[$]
    DeRef(_1759);
    _1759 = SEQ_PTR(_12all_source)->length;
    DeRef(_12current_source);
    _2 = (int)SEQ_PTR(_12all_source);
    _12current_source = (int)*(((s1_ptr)_2)->base + _1759);
    Ref(_12current_source);

    // 	    current_source_next = remainder(start, SOURCE_CHUNK)    	
    _12current_source_next = (_start % 10000);
L1:

    //     slist = slist[1..line] & 0
    rhs_slice_target = (object_ptr)&_1759;
    RHS_Slice((s1_ptr)_7slist, 1, _line);
    Append(&_7slist, _1759, 0);

    //     line_number = slist[$-1][LINE_NO]
    DeRefDS(_1759);
    _1759 = SEQ_PTR(_7slist)->length;
    _1759 = _1759 - 1;
    _2 = (int)SEQ_PTR(_7slist);
    _1759 = (int)*(((s1_ptr)_2)->base + _1759);
    Ref(_1759);
    _2 = (int)SEQ_PTR(_1759);
    _7line_number = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_7line_number))
        _7line_number = (long)DBL_PTR(_7line_number)->dbl;

    //     gline_number = line - 1
    _7gline_number = _line - 1;

    // end procedure
    DeRef(_1759);
    DeRef(_1752);
    return 0;
    ;
}


int _12pack_source(int _src)
{
    int _start;
    int _1776 = 0;
    int _0, _1, _2;
    

    //     if equal(src, 0) then
    if (_src == 0)
        _1776 = 1;
    else if (IS_ATOM_INT(_src) && IS_ATOM_INT(0))
        _1776 = 0;
    else
        _1776 = (compare(_src, 0) == 0);
    if (_1776 == 0)
        goto L1;

    // 	return 0
    DeRef(_src);
    return 0;
L1:

    //     if current_source_next + length(src) >= SOURCE_CHUNK then
    DeRef(_1776);
    _1776 = SEQ_PTR(_src)->length;
    _1776 = _12current_source_next + _1776;
    if ((long)((unsigned long)_1776 + (unsigned long)HIGH_BITS) >= 0) 
        _1776 = NewDouble((double)_1776);
    if (binary_op_a(LESS, _1776, 10000))
        goto L2;

    // 	current_source = allocate(SOURCE_CHUNK)
    _0 = _4allocate(10000);
    DeRef(_12current_source);
    _12current_source = _0;

    // 	all_source = append(all_source, current_source)
    Ref(_12current_source);
    Append(&_12all_source, _12all_source, _12current_source);

    // 	current_source_next = 1 
    _12current_source_next = 1;
L2:

    //     start = current_source_next 
    _start = _12current_source_next;

    //     poke(current_source+current_source_next, src)
    DeRef(_1776);
    if (IS_ATOM_INT(_12current_source)) {
        _1776 = _12current_source + _12current_source_next;
        if ((long)((unsigned long)_1776 + (unsigned long)HIGH_BITS) >= 0) 
            _1776 = NewDouble((double)_1776);
    }
    else {
        _1776 = NewDouble(DBL_PTR(_12current_source)->dbl + (double)_12current_source_next);
    }
    if (IS_ATOM_INT(_1776))
        poke_addr = (unsigned char *)_1776;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_1776)->dbl);
    if (IS_ATOM_INT(_src)) {
        *poke_addr = (unsigned char)_src;
    }
    else if (IS_ATOM(_src)) {
        *poke_addr = (signed char)DBL_PTR(_src)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_src);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *poke_addr++ = (unsigned char)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
            }
        }
    }

    //     current_source_next += length(src)-1
    DeRef(_1776);
    _1776 = SEQ_PTR(_src)->length;
    _1776 = _1776 - 1;
    _12current_source_next = _12current_source_next + _1776;

    //     poke(current_source+current_source_next, 0) -- overwrite \n
    if (IS_ATOM_INT(_12current_source)) {
        _1776 = _12current_source + _12current_source_next;
        if ((long)((unsigned long)_1776 + (unsigned long)HIGH_BITS) >= 0) 
            _1776 = NewDouble((double)_1776);
    }
    else {
        _1776 = NewDouble(DBL_PTR(_12current_source)->dbl + (double)_12current_source_next);
    }
    if (IS_ATOM_INT(_1776))
        poke_addr = (unsigned char *)_1776;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_1776)->dbl);
    *poke_addr = (unsigned char)0;

    //     current_source_next += 1
    _12current_source_next = _12current_source_next + 1;

    //     return start + SOURCE_CHUNK * (length(all_source)-1)
    DeRef(_1776);
    _1776 = SEQ_PTR(_12all_source)->length;
    _1776 = _1776 - 1;
    if (_1776 <= INT15)
        _1776 = 10000 * _1776;
    else
        _1776 = NewDouble(10000 * (double)_1776);
    _0 = _1776;
    if (IS_ATOM_INT(_1776)) {
        _1776 = _start + _1776;
        if ((long)((unsigned long)_1776 + (unsigned long)HIGH_BITS) >= 0) 
            _1776 = NewDouble((double)_1776);
    }
    else {
        _1776 = NewDouble((double)_start + DBL_PTR(_1776)->dbl);
    }
    DeRef(_0);
    DeRef(_src);
    return _1776;
    ;
}


int _12fetch_line(int _start)
{
    int _line = 0;
    int _c;
    int _chunk;
    int _p = 0;
    int _1792 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_start)) {
        _1 = (long)(DBL_PTR(_start)->dbl);
        DeRefDS(_start);
        _start = _1;
    }

    //     if start = 0 then
    if (_start != 0)
        goto L1;

    // 	return ""
    RefDS(_39);
    return _39;
L1:

    //     line = ""
    RefDS(_39);
    DeRefi(_line);
    _line = _39;

    //     chunk = 1+floor(start / SOURCE_CHUNK)
    DeRef(_1792);
    if (10000 > 0 && _start >= 0) {
        _1792 = _start / 10000;
    }
    else {
        temp_dbl = floor((double)_start / (double)10000);
        _1792 = (long)temp_dbl;
    }
    _chunk = _1792 + 1;

    //     start = remainder(start, SOURCE_CHUNK)
    _start = (_start % 10000);

    //     p = all_source[chunk] + start
    _2 = (int)SEQ_PTR(_12all_source);
    _1792 = (int)*(((s1_ptr)_2)->base + _chunk);
    Ref(_1792);
    DeRef(_p);
    if (IS_ATOM_INT(_1792)) {
        _p = _1792 + _start;
        if ((long)((unsigned long)_p + (unsigned long)HIGH_BITS) >= 0) 
            _p = NewDouble((double)_p);
    }
    else {
        _p = NewDouble(DBL_PTR(_1792)->dbl + (double)_start);
    }

    //     while TRUE do
L2:

    // 	c = peek(p)
    if (IS_ATOM_INT(_p)) {
        _c = *(unsigned char *)_p;
    }
    else {
        _c = *(unsigned char *)(unsigned long)(DBL_PTR(_p)->dbl);
    }

    // 	if c = 0 then
    if (_c != 0)
        goto L3;

    // 	    exit
    goto L4;
L3:

    // 	line &= c
    Append(&_line, _line, _c);

    // 	p += 1
    _0 = _p;
    if (IS_ATOM_INT(_p)) {
        _p = _p + 1;
        if (_p > MAXINT)
            _p = NewDouble((double)_p);
    }
    else
        _p = binary_op(PLUS, 1, _p);
    DeRef(_0);

    //     end while
    goto L2;
L4:

    //     return line
    DeRef(_p);
    DeRef(_1792);
    return _line;
    ;
}


int _12AppendSourceLine()
{
    int _new = 0;
    int _old = 0;
    int _options;
    int _src = 0;
    int _1824 = 0;
    int _1802 = 0;
    int _1819 = 0;
    int _0, _1, _2;
    

    //     src = 0
    _src = 0;

    //     options = 0
    _options = 0;

    //     if TRANSLATE or OpTrace or OpProfileStatement or OpProfileTime or preprocess then
    if (0 != 0) {
        _1802 = 1;
        goto L1;
    }
    _1802 = (_7OpTrace != 0);
L1:
    if (_1802 != 0) {
        DeRef(_1802);
        _1802 = 1;
        goto L2;
    }
    _1802 = (_7OpProfileStatement != 0);
L2:
    if (_1802 != 0) {
        DeRef(_1802);
        _1802 = 1;
        goto L3;
    }
    _1802 = (_7OpProfileTime != 0);
L3:
    if (_1802 != 0) {
        goto L4;
    }
L5:
    if (_7preprocess == 0)
        goto L6;
L4:

    // 	src = ThisLine
    Ref(_9ThisLine);
    DeRef(_src);
    _src = _9ThisLine;

    // 	if OpTrace or preprocess then
    if (_7OpTrace != 0) {
        goto L7;
    }
L8:
    if (_7preprocess == 0)
        goto L9;
L7:

    // 	    options = SOP_TRACE
    _options = 1;
L9:

    // 	if OpProfileTime then
    if (_7OpProfileTime == 0)
        goto LA;

    // 	    options = or_bits(options, SOP_PROFILE_TIME)
    _options = (_options | 2);
LA:

    // 	if OpProfileStatement then
    if (_7OpProfileStatement == 0)
        goto LB;

    // 	    options = or_bits(options, SOP_PROFILE_STATEMENT)
    _options = (_options | 4);
LB:

    // 	if OpProfileStatement or OpProfileTime then
    if (_7OpProfileStatement != 0) {
        goto LC;
    }
LD:
    if (_7OpProfileTime == 0)
        goto LE;
LC:

    // 	    src = {0,0,0,0} & src
    _0 = _1802;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    *((int *)(_2+8)) = 0;
    *((int *)(_2+12)) = 0;
    *((int *)(_2+16)) = 0;
    _1802 = MAKE_SEQ(_1);
    DeRef(_0);
    if (IS_SEQUENCE(_1802) && IS_ATOM(_src)) {
        Ref(_src);
        Append(&_src, _1802, _src);
    }
    else if (IS_ATOM(_1802) && IS_SEQUENCE(_src)) {
    }
    else {
        Concat((object_ptr)&_src, _1802, (s1_ptr)_src);
    }
LE:
L6:

    //     if length(slist) then
    DeRef(_1802);
    _1802 = SEQ_PTR(_7slist)->length;
    if (_1802 == 0)
        goto LF;

    // 	old = slist[$-1]
    _1802 = SEQ_PTR(_7slist)->length;
    _1802 = _1802 - 1;
    DeRef(_old);
    _2 = (int)SEQ_PTR(_7slist);
    _old = (int)*(((s1_ptr)_2)->base + _1802);
    Ref(_old);

    // 	if equal(src, old[SRC]) and 
    _2 = (int)SEQ_PTR(_old);
    _1802 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1802);
    _0 = _1802;
    if (_src == _1802)
        _1802 = 1;
    else if (IS_ATOM_INT(_src) && IS_ATOM_INT(_1802))
        _1802 = 0;
    else
        _1802 = (compare(_src, _1802) == 0);
    DeRef(_0);
    if (_1802 == 0) {
        _1802 = 0;
        goto L10;
    }
    DeRef(_1819);
    _2 = (int)SEQ_PTR(_old);
    _1819 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1819);
    _0 = _1819;
    if (IS_ATOM_INT(_1819)) {
        _1819 = (_7current_file_no == _1819);
    }
    else {
        _1819 = binary_op(EQUALS, _7current_file_no, _1819);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1819))
        _1802 = (_1819 != 0);
    else
        _1802 = DBL_PTR(_1819)->dbl != 0.0;
L10:
    if (_1802 == 0) {
        DeRef(_1819);
        _1819 = 0;
        goto L11;
    }
    DeRef(_1802);
    _2 = (int)SEQ_PTR(_old);
    _1802 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1802);
    _0 = _1802;
    if (IS_ATOM_INT(_1802)) {
        _1802 = _1802 + 1;
        if (_1802 > MAXINT)
            _1802 = NewDouble((double)_1802);
    }
    else
        _1802 = binary_op(PLUS, 1, _1802);
    DeRef(_0);
    DeRef(_1824);
    _1824 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _1824 = (int)*(((s1_ptr)_2)->base + _1824);
    Ref(_1824);
    _0 = _1824;
    if (IS_ATOM_INT(_1802) && IS_ATOM_INT(_1824)) {
        _1824 = _1802 + _1824;
        if ((long)((unsigned long)_1824 + (unsigned long)HIGH_BITS) >= 0) 
            _1824 = NewDouble((double)_1824);
    }
    else {
        _1824 = binary_op(PLUS, _1802, _1824);
    }
    DeRef(_0);
    _0 = _1824;
    if (IS_ATOM_INT(_1824)) {
        _1824 = (_7line_number == _1824);
    }
    else {
        _1824 = binary_op(EQUALS, _7line_number, _1824);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1824))
        _1819 = (_1824 != 0);
    else
        _1819 = DBL_PTR(_1824)->dbl != 0.0;
L11:
    if (_1819 == 0) {
        goto L12;
    }
    DeRef(_1802);
    _2 = (int)SEQ_PTR(_old);
    _1802 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1802);
    _0 = _1802;
    if (IS_ATOM_INT(_1802)) {
        _1802 = (_options == _1802);
    }
    else {
        _1802 = binary_op(EQUALS, _options, _1802);
    }
    DeRef(_0);
L13:
    if (_1802 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_1802) && DBL_PTR(_1802)->dbl == 0.0)
            goto L12;
    }

    // 	    slist[$] += 1  
    DeRef(_1802);
    _1802 = SEQ_PTR(_7slist)->length;
    DeRef(_1824);
    _2 = (int)SEQ_PTR(_7slist);
    _1824 = (int)*(((s1_ptr)_2)->base + _1802);
    Ref(_1824);
    _0 = _1824;
    if (IS_ATOM_INT(_1824)) {
        _1824 = _1824 + 1;
        if (_1824 > MAXINT)
            _1824 = NewDouble((double)_1824);
    }
    else
        _1824 = binary_op(PLUS, 1, _1824);
    DeRef(_0);
    Ref(_1824);
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _1802);
    _1 = *(int *)_2;
    *(int *)_2 = _1824;
    DeRef(_1);
    goto L14;
L12:

    // 	    src = pack_source(src)
    Ref(_src);
    _0 = _src;
    _src = _12pack_source(_src);
    DeRef(_0);

    // 	    new = {src, line_number, current_file_no, options}
    _0 = _new;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_src);
    *((int *)(_2+4)) = _src;
    *((int *)(_2+8)) = _7line_number;
    *((int *)(_2+12)) = _7current_file_no;
    *((int *)(_2+16)) = _options;
    _new = MAKE_SEQ(_1);
    DeRef(_0);

    // 		if equal( slist[$], 0 ) then
    DeRef(_1824);
    _1824 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _1824 = (int)*(((s1_ptr)_2)->base + _1824);
    Ref(_1824);
    _0 = _1824;
    if (_1824 == 0)
        _1824 = 1;
    else if (IS_ATOM_INT(_1824) && IS_ATOM_INT(0))
        _1824 = 0;
    else
        _1824 = (compare(_1824, 0) == 0);
    DeRef(_0);
    if (_1824 == 0)
        goto L15;

    // 		slist[$] = new
    _1824 = SEQ_PTR(_7slist)->length;
    RefDS(_new);
    _2 = (int)SEQ_PTR(_7slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7slist = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _1824);
    _1 = *(int *)_2;
    *(int *)_2 = _new;
    DeRef(_1);
    goto L16;
L15:

    // 		slist = append(slist, new)
    RefDS(_new);
    Append(&_7slist, _7slist, _new);
L16:

    // 	    slist = append(slist, 0)
    Append(&_7slist, _7slist, 0);
L17:
    goto L14;
LF:

    // 	src = pack_source(src)
    Ref(_src);
    _0 = _src;
    _src = _12pack_source(_src);
    DeRef(_0);

    // 	slist = {{src, line_number, current_file_no, options}, 0}
    _0 = _1824;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_src);
    *((int *)(_2+4)) = _src;
    *((int *)(_2+8)) = _7line_number;
    *((int *)(_2+12)) = _7current_file_no;
    *((int *)(_2+16)) = _options;
    _1824 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_7slist);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _1824;
    RefDS(_1824);
    ((int *)_2)[2] = 0;
    _7slist = MAKE_SEQ(_1);
L14:

    // end procedure
    DeRef(_new);
    DeRef(_old);
    DeRef(_src);
    DeRef(_1824);
    DeRef(_1802);
    DeRef(_1819);
    return 0;
    ;
}


int _12s_expand(int _slist)
{
    int _new_slist = 0;
    int _1854 = 0;
    int _1851;
    int _1846 = 0;
    int _1845;
    int _0, _1, _2, _3;
    

    //     new_slist = {}
    RefDS(_39);
    _new_slist = _39;

    //     for i = 1 to length(slist) do
    _1845 = SEQ_PTR(_slist)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _1845)
            goto L2;

        // 	if sequence(slist[i]) then
        DeRef(_1846);
        _2 = (int)SEQ_PTR(_slist);
        _1846 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1846);
        _0 = _1846;
        _1846 = IS_SEQUENCE(_1846);
        DeRef(_0);
        if (_1846 == 0)
            goto L3;

        // 	    new_slist = append(new_slist, slist[i])
        _2 = (int)SEQ_PTR(_slist);
        _1846 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1846);
        Ref(_1846);
        Append(&_new_slist, _new_slist, _1846);
        goto L4;
L3:

        // 	    for j = 1 to slist[i] do
        DeRef(_1846);
        _2 = (int)SEQ_PTR(_slist);
        _1846 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1846);
        { int _j;
            _j = 1;
L5:
            if (binary_op_a(GREATER, _j, _1846))
                goto L6;

            // 		slist[i-1][LINE] += 1
            _1851 = _i - 1;
            _2 = (int)SEQ_PTR(_slist);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _slist = MAKE_SEQ(_2);
            }
            _3 = (int)(_1851 + ((s1_ptr)_2)->base);
            DeRef(_1854);
            _2 = (int)SEQ_PTR(*(int *)_3);
            _1854 = (int)*(((s1_ptr)_2)->base + 2);
            Ref(_1854);
            _0 = _1854;
            if (IS_ATOM_INT(_1854)) {
                _1854 = _1854 + 1;
                if (_1854 > MAXINT)
                    _1854 = NewDouble((double)_1854);
            }
            else
                _1854 = binary_op(PLUS, 1, _1854);
            DeRef(_0);
            Ref(_1854);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 2);
            _1 = *(int *)_2;
            *(int *)_2 = _1854;
            DeRef(_1);

            // 		new_slist = append(new_slist, slist[i-1]) 
            DeRef(_1854);
            _1854 = _i - 1;
            _2 = (int)SEQ_PTR(_slist);
            _1854 = (int)*(((s1_ptr)_2)->base + _1854);
            Ref(_1854);
            Ref(_1854);
            Append(&_new_slist, _new_slist, _1854);

            // 	    end for
            _0 = _j;
            if (IS_ATOM_INT(_j)) {
                _j = _j + 1;
                if ((long)((unsigned long)_j +(unsigned long) HIGH_BITS) >= 0) 
                    _j = NewDouble((double)_j);
            }
            else {
                _j = binary_op_a(PLUS, _j, 1);
            }
            DeRef(_0);
            goto L5;
L6:
            ;
            DeRef(_j);
        }
L4:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return new_slist
    DeRefDS(_slist);
    DeRef(_1854);
    DeRef(_1846);
    return _new_slist;
    ;
}


int _12read_line()
{
    int _n;
    int _1859 = 0;
    int _1866 = 0;
    int _0, _1, _2;
    

    //     if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 	    if not remember_line[$] then
    _1859 = SEQ_PTR(_7remember_line)->length;
    _2 = (int)SEQ_PTR(_7remember_line);
    _1859 = (int)*(((s1_ptr)_2)->base + _1859);
    if (_1859 != 0)
        goto L2;

    // 		    line_tokens = {}
    RefDS(_39);
    DeRef(_7line_tokens);
    _7line_tokens = _39;

    // 		    token_boundaries = {}
    RefDS(_39);
    DeRef(_7token_boundaries);
    _7token_boundaries = _39;

    // 		    token_ws = {}
    RefDS(_39);
    DeRef(_7token_ws);
    _7token_ws = _39;

    // 			start_line = {0}
    _0 = _7start_line;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _7start_line = MAKE_SEQ(_1);
    DeRefi(_0);

    // 			start_line_token = {0}
    _0 = _7start_line_token;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _7start_line_token = MAKE_SEQ(_1);
    DeRefi(_0);
    goto L3;
L2:

    // 			if token_boundaries[$][$] = -1 then
    DeRef(_1859);
    _1859 = SEQ_PTR(_7token_boundaries)->length;
    _2 = (int)SEQ_PTR(_7token_boundaries);
    _1859 = (int)*(((s1_ptr)_2)->base + _1859);
    Ref(_1859);
    DeRef(_1866);
    _1866 = SEQ_PTR(_1859)->length;
    _2 = (int)SEQ_PTR(_1859);
    _1866 = (int)*(((s1_ptr)_2)->base + _1866);
    Ref(_1866);
    if (binary_op_a(NOTEQ, _1866, -1))
        goto L4;

    // 				line_tokens = append( line_tokens, {0,0})
    DeRef(_1866);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 0;
    _1866 = MAKE_SEQ(_1);
    RefDS(_1866);
    Append(&_7line_tokens, _7line_tokens, _1866);

    // 				token_ws &= 0
    Append(&_7token_ws, _7token_ws, 0);
L4:

    // 			start_line &= length(slist) + 1
    DeRef(_1866);
    _1866 = SEQ_PTR(_7slist)->length;
    _1866 = _1866 + 1;
    Append(&_7start_line, _7start_line, _1866);

    // 			start_line_token &= length(line_tokens) + 1
    _1866 = SEQ_PTR(_7line_tokens)->length;
    _1866 = _1866 + 1;
    Append(&_7start_line_token, _7start_line_token, _1866);
L3:
L1:

    //     line_number += 1
    _7line_number = _7line_number + 1;

    //     gline_number += 1
    _7gline_number = _7gline_number + 1;

    //     if eval_stack[$] then
    DeRef(_1866);
    _1866 = SEQ_PTR(_7eval_stack)->length;
    _2 = (int)SEQ_PTR(_7eval_stack);
    _1866 = (int)*(((s1_ptr)_2)->base + _1866);
    if (_1866 == 0)
        goto L5;

    //     	if length( eval_buffer ) then
    _1866 = SEQ_PTR(_7eval_buffer)->length;
    if (_1866 == 0)
        goto L6;

    //     		ThisLine = eval_buffer[1]
    DeRef(_9ThisLine);
    _2 = (int)SEQ_PTR(_7eval_buffer);
    _9ThisLine = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_9ThisLine);

    //     		eval_buffer = eval_buffer[2..$]
    _1866 = SEQ_PTR(_7eval_buffer)->length;
    rhs_slice_target = (object_ptr)&_7eval_buffer;
    RHS_Slice((s1_ptr)_7eval_buffer, 2, _1866);
    goto L7;
L6:

    //     		ThisLine = {END_OF_FILE_CHAR}
    RefDS(_1886);
    DeRef(_9ThisLine);
    _9ThisLine = _1886;
L8:
    goto L7;
L5:

    // 	    ThisLine = gets(src_file)
    DeRef(_9ThisLine);
    _9ThisLine = EGets(_12src_file);

    // 	    if atom(ThisLine) then
    DeRef(_1866);
    _1866 = IS_ATOM(_9ThisLine);
    if (_1866 == 0)
        goto L9;

    // 			ThisLine = {END_OF_FILE_CHAR}
    RefDS(_1886);
    DeRefi(_9ThisLine);
    _9ThisLine = _1886;
L9:
L7:

    //     bp = 1
    _9bp = 1;

    //     n = length(ThisLine)
    _n = SEQ_PTR(_9ThisLine)->length;

    //     if not n or ThisLine[n] != '\n' then
    DeRef(_1866);
    _1866 = (_n == 0);
    if (_1866 != 0) {
        goto LA;
    }
    DeRef(_1859);
    _2 = (int)SEQ_PTR(_9ThisLine);
    _1859 = (int)*(((s1_ptr)_2)->base + _n);
    Ref(_1859);
    _0 = _1859;
    if (IS_ATOM_INT(_1859)) {
        _1859 = (_1859 != 10);
    }
    else {
        _1859 = binary_op(NOTEQ, _1859, 10);
    }
    DeRef(_0);
LB:
    if (_1859 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_1859) && DBL_PTR(_1859)->dbl == 0.0)
            goto LC;
    }
LA:

    // 	ThisLine = append(ThisLine, '\n') -- add missing \n (might happen at end of file)
    Append(&_9ThisLine, _9ThisLine, 10);
LC:

    //     AppendSourceLine()
    _12AppendSourceLine();

    // end procedure
    DeRef(_1859);
    DeRef(_1866);
    return 0;
    ;
}


int _12bad_zero()
{
    int _0, _1, _2;
    

    //     CompileErr("illegal character (ASCII 0)")
    RefDS(_1895);
    _9CompileErr(_1895);

    // end procedure
    return 0;
    ;
}


int _12getch()
{
    int _c;
    int _0, _1, _2;
    

    //     c = ThisLine[bp]
    _2 = (int)SEQ_PTR(_9ThisLine);
    _c = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    //     if c = 0 then
    if (_c != 0)
        goto L1;

    // 	bad_zero()
    _12bad_zero();
L1:

    //     bp += 1
    _9bp = _9bp + 1;

    //     return c   
    return _c;
    ;
}


int _12ungetch()
{
    int _0, _1, _2;
    

    //     bp -= 1               
    _9bp = _9bp - 1;

    // end procedure
    return 0;
    ;
}


int _12path_open()
{
    int _absolute;
    int _try97531;
    int _full_path = 0;
    int _inc_path = 0;
    int _errbuff = 0;
    int _2017 = 0;
    int _2014 = 0;
    int _2043 = 0;
    int _2016;
    int _0, _1, _2;
    

    //     absolute = FALSE
    _absolute = 0;

    //     absolute = find(new_include_name[1], SLASH_CHARS) or
    _2 = (int)SEQ_PTR(_12new_include_name);
    _2014 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2014);
    _0 = _2014;
    _2014 = find(_2014, _7SLASH_CHARS);
    DeRef(_0);
    _2016 = (_7ELINUX == 0);
    _2017 = find(58, _12new_include_name);
    _2017 = (_2016 != 0 && _2017 != 0);
    _absolute = (_2014 != 0 || _2017 != 0);

    //     if absolute then
    if (_absolute == 0)
        goto L1;

    // 	try = open(new_include_name, "r")
    _try97531 = EOpen(_12new_include_name, _2020);

    // 	if try = -1 then
    if (_try97531 != -1)
        goto L2;

    // 	    errbuff = sprintf("can't open %s", new_include_name)
    _errbuff = EPrintf(-9999999, _2023, _12new_include_name);

    // 	    CompileErr(errbuff)
    RefDS(_errbuff);
    _9CompileErr(_errbuff);
L2:

    // 	return try
    DeRef(_full_path);
    DeRefi(_inc_path);
    DeRefi(_errbuff);
    DeRef(_2017);
    DeRef(_2014);
    DeRef(_2043);
    return _try97531;
L1:

    //     full_path = main_path & new_include_name
    Concat((object_ptr)&_full_path, _12main_path, (s1_ptr)_12new_include_name);

    //     try = open(full_path,  "r")
    _try97531 = EOpen(_full_path, _2020);

    //     if try = -1 then
    if (_try97531 != -1)
        goto L3;

    // 		inc_path = getenv("EUINC")
    DeRefi(_inc_path);
    _inc_path = EGetEnv(_2028);

    // 		if sequence(inc_path) and length(inc_path) > 0 then  
    DeRef(_2017);
    _2017 = IS_SEQUENCE(_inc_path);
    if (_2017 == 0) {
        goto L4;
    }
    _2016 = SEQ_PTR(_inc_path)->length;
    _2016 = (_2016 > 0);
L5:
    if (_2016 == 0)
        goto L4;

    // 		    inc_path = append(inc_path, PATH_SEPARATOR)
    Append(&_inc_path, _inc_path, _7PATH_SEPARATOR);

    // 		    full_path = ""
    RefDS(_39);
    DeRef(_full_path);
    _full_path = _39;

    // 		    for p = 1 to length(inc_path) do
    _2016 = SEQ_PTR(_inc_path)->length;
    { int _p;
        _p = 1;
L6:
        if (_p > _2016)
            goto L7;

        // 				if inc_path[p] = PATH_SEPARATOR then
        DeRef(_2017);
        _2 = (int)SEQ_PTR(_inc_path);
        _2017 = (int)*(((s1_ptr)_2)->base + _p);
        if (_2017 != _7PATH_SEPARATOR)
            goto L8;

        // 				    while length(full_path) and 
L9:
        DeRef(_2017);
        _2017 = SEQ_PTR(_full_path)->length;
        if (_2017 == 0) {
            goto LA;
        }
        DeRef(_2014);
        _2014 = SEQ_PTR(_full_path)->length;
        _2 = (int)SEQ_PTR(_full_path);
        _2014 = (int)*(((s1_ptr)_2)->base + _2014);
        Ref(_2014);
        Concat((object_ptr)&_2043, _2042, (s1_ptr)_7SLASH_CHARS);
        _0 = _2043;
        _2043 = find(_2014, _2043);
        DeRefDSi(_0);
LB:
        if (_2043 == 0)
            goto LA;

        // 					full_path = full_path[1..$-1]
        DeRef(_2043);
        _2043 = SEQ_PTR(_full_path)->length;
        _2043 = _2043 - 1;
        rhs_slice_target = (object_ptr)&_full_path;
        RHS_Slice((s1_ptr)_full_path, 1, _2043);

        // 				    end while
        goto L9;
LA:

        // 				    if length(full_path) then
        DeRef(_2043);
        _2043 = SEQ_PTR(_full_path)->length;
        if (_2043 == 0)
            goto LC;

        // 					full_path = full_path & SLASH & new_include_name
        {
            int concat_list[3];

            concat_list[0] = _12new_include_name;
            concat_list[1] = _7SLASH;
            concat_list[2] = _full_path;
            Concat_N((object_ptr)&_full_path, concat_list, 3);
        }

        // 					try = open(full_path, "r")
        _try97531 = EOpen(_full_path, _2020);

        // 					if try != -1 then
        if (_try97531 == -1)
            goto LD;

        // 					    exit
        goto L7;
LD:

        // 					full_path = ""
        RefDS(_39);
        DeRef(_full_path);
        _full_path = _39;
LE:
        goto LC;
L8:

        // 				    if length(full_path) or 
        DeRef(_2043);
        _2043 = SEQ_PTR(_full_path)->length;
        if (_2043 != 0) {
            goto LF;
        }
        DeRef(_2014);
        _2 = (int)SEQ_PTR(_inc_path);
        _2014 = (int)*(((s1_ptr)_2)->base + _p);
        _2014 = (_2014 != 32);
        if (_2014 == 0) {
            _2014 = 0;
            goto L10;
        }
        DeRef(_2017);
        _2 = (int)SEQ_PTR(_inc_path);
        _2017 = (int)*(((s1_ptr)_2)->base + _p);
        _2017 = (_2017 != 9);
        _2014 = (_2017 != 0);
L10:
L11:
        if (_2014 == 0)
            goto L12;
LF:

        // 					full_path &= inc_path[p]
        DeRef(_2017);
        _2 = (int)SEQ_PTR(_inc_path);
        _2017 = (int)*(((s1_ptr)_2)->base + _p);
        Append(&_full_path, _full_path, _2017);
L12:
LC:

        // 		    end for
        _p = _p + 1;
        goto L6;
L7:
        ;
    }

    // 		    inc_path = inc_path[1..$-1] 
    DeRef(_2017);
    _2017 = SEQ_PTR(_inc_path)->length;
    _2017 = _2017 - 1;
    rhs_slice_target = (object_ptr)&_inc_path;
    RHS_Slice((s1_ptr)_inc_path, 1, _2017);
L4:
L3:

    //     if try = -1 then
    if (_try97531 != -1)
        goto L13;

    // 		full_path = eudir & SLASH & "include" & SLASH & new_include_name
    {
        int concat_list[5];

        concat_list[0] = _12new_include_name;
        concat_list[1] = _7SLASH;
        concat_list[2] = _836;
        concat_list[3] = _7SLASH;
        concat_list[4] = _7eudir;
        Concat_N((object_ptr)&_full_path, concat_list, 5);
    }

    // 		try = open(full_path, "r")
    _try97531 = EOpen(_full_path, _2020);
L13:

    //     if try != -1 then
    if (_try97531 == -1)
        goto L14;

    // 		if full_path[1] = '\\' then
    DeRef(_2017);
    _2 = (int)SEQ_PTR(_full_path);
    _2017 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2017);
    if (binary_op_a(NOTEQ, _2017, 92))
        goto L15;

    // 			new_include_name = current_dir()
    _0 = _13current_dir();
    DeRef(_12new_include_name);
    _12new_include_name = _0;

    // 			full_path = new_include_name[1..2] & full_path
    rhs_slice_target = (object_ptr)&_2017;
    RHS_Slice((s1_ptr)_12new_include_name, 1, 2);
    Concat((object_ptr)&_full_path, _2017, (s1_ptr)_full_path);
L15:

    // 		new_include_name = full_path
    RefDS(_full_path);
    DeRef(_12new_include_name);
    _12new_include_name = _full_path;

    // 		return try
    DeRefDS(_full_path);
    DeRefi(_inc_path);
    DeRefi(_errbuff);
    DeRef(_2017);
    DeRef(_2014);
    DeRef(_2043);
    return _try97531;
L14:

    //     if length(main_path) = 0 then
    DeRef(_2017);
    _2017 = SEQ_PTR(_12main_path)->length;
    if (_2017 != 0)
        goto L16;

    // 		main_path = "."
    RefDS(_1988);
    DeRefDS(_12main_path);
    _12main_path = _1988;
L16:

    //     if find(main_path[$], SLASH_CHARS) then
    DeRef(_2017);
    _2017 = SEQ_PTR(_12main_path)->length;
    _2 = (int)SEQ_PTR(_12main_path);
    _2017 = (int)*(((s1_ptr)_2)->base + _2017);
    Ref(_2017);
    _0 = _2017;
    _2017 = find(_2017, _7SLASH_CHARS);
    DeRef(_0);
    if (_2017 == 0)
        goto L17;

    // 		main_path = main_path[1..$-1]  -- looks better
    _2017 = SEQ_PTR(_12main_path)->length;
    _2017 = _2017 - 1;
    rhs_slice_target = (object_ptr)&_12main_path;
    RHS_Slice((s1_ptr)_12main_path, 1, _2017);
L17:

    //     if atom(inc_path) then
    DeRef(_2017);
    _2017 = IS_ATOM(_inc_path);
    if (_2017 == 0)
        goto L18;

    // 	errbuff = sprintf("can't find %s in %s\nor in %s%sinclude", 
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_12new_include_name);
    *((int *)(_2+4)) = _12new_include_name;
    RefDS(_12main_path);
    *((int *)(_2+8)) = _12main_path;
    Ref(_7eudir);
    *((int *)(_2+12)) = _7eudir;
    *((int *)(_2+16)) = _7SLASH;
    _2017 = MAKE_SEQ(_1);
    DeRefi(_errbuff);
    _errbuff = EPrintf(-9999999, _2082, _2017);
    goto L19;
L18:

    // 	errbuff = sprintf("can't find %s in %s\nor in %s\nor in %s%sinclude", 
    _0 = _2017;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_12new_include_name);
    *((int *)(_2+4)) = _12new_include_name;
    RefDS(_12main_path);
    *((int *)(_2+8)) = _12main_path;
    Ref(_inc_path);
    *((int *)(_2+12)) = _inc_path;
    Ref(_7eudir);
    *((int *)(_2+16)) = _7eudir;
    *((int *)(_2+20)) = _7SLASH;
    _2017 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefi(_errbuff);
    _errbuff = EPrintf(-9999999, _2085, _2017);
L19:

    //     CompileErr(errbuff)
    RefDS(_errbuff);
    _9CompileErr(_errbuff);
    ;
}


int _12equal_ins(int _a, int _b)
{
    int _2094 = 0;
    int _2088 = 0;
    int _2089;
    int _0, _1, _2;
    

    //     if length(a) != length(b) then
    _2088 = SEQ_PTR(_a)->length;
    _2089 = SEQ_PTR(_b)->length;
    if (_2088 == _2089)
        goto L1;

    // 	return FALSE
    DeRefDS(_a);
    DeRefDS(_b);
    return 0;
L1:

    //     for i = 1 to length(a) do
    _2089 = SEQ_PTR(_a)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _2089)
            goto L3;

        // 	if upper(a[i]) != upper(b[i]) then
        DeRef(_2088);
        _2 = (int)SEQ_PTR(_a);
        _2088 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2088);
        Ref(_2088);
        _0 = _2088;
        _2088 = _3upper(_2088);
        DeRef(_0);
        DeRef(_2094);
        _2 = (int)SEQ_PTR(_b);
        _2094 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2094);
        Ref(_2094);
        _0 = _2094;
        _2094 = _3upper(_2094);
        DeRef(_0);
        if (binary_op_a(EQUALS, _2088, _2094))
            goto L4;

        // 	    return FALSE
        DeRefDS(_a);
        DeRefDS(_b);
        DeRef(_2094);
        DeRef(_2088);
        return 0;
L4:

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     return TRUE
    DeRefDS(_a);
    DeRefDS(_b);
    DeRef(_2094);
    DeRef(_2088);
    return 1;
    ;
}


int _12IncludePush()
{
    int _new_file;
    int _short_name = 0;
    int _2097 = 0;
    int _2104 = 0;
    int _0, _1, _2, _3;
    

    //     start_include = FALSE
    _12start_include = 0;

    //     short_name = name_ext(new_include_name)
    RefDS(_12new_include_name);
    _short_name = _11name_ext(_12new_include_name);

    //     for i = length(file_name) to 1 by -1 do
    _2097 = SEQ_PTR(_7file_name)->length;
    { int _i;
        _i = _2097;
L1:
        if (_i < 1)
            goto L2;

        // 		if equal_ins(short_name, name_ext(file_name[i])) then
        DeRef(_2097);
        _2 = (int)SEQ_PTR(_7file_name);
        _2097 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2097);
        Ref(_2097);
        _0 = _2097;
        _2097 = _11name_ext(_2097);
        DeRef(_0);
        RefDS(_short_name);
        RefDS(_2097);
        _0 = _2097;
        _2097 = _12equal_ins(_short_name, _2097);
        DeRefDS(_0);
        if (_2097 == 0)
            goto L3;

        // 		    if new_include_space != 0 then
        if (_12new_include_space == 0)
            goto L4;

        // 				SymTab[new_include_space][S_OBJ] = i
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_12new_include_space + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _i;
        DeRef(_1);
L4:

        // 		    return -- already included (or main .ex file)  
        DeRef(_short_name);
        DeRef(_2097);
        DeRef(_2104);
        return 0;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     eval_stack &= 0
    Append(&_7eval_stack, _7eval_stack, 0);

    //     new_file = path_open() 
    _new_file = _12path_open();

    //     if length(IncludeStk) >= INCLUDE_LIMIT then
    DeRef(_2104);
    _2104 = SEQ_PTR(_12IncludeStk)->length;
    if (_2104 < 30)
        goto L5;

    // 		CompileErr("includes are nested too deeply")
    RefDS(_2109);
    _9CompileErr(_2109);
L5:

    //     IncludeStk = append(IncludeStk, 
    _0 = _2104;
    _1 = NewS1(10);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _7current_file_no;
    *((int *)(_2+8)) = _7line_number;
    *((int *)(_2+12)) = _12src_file;
    *((int *)(_2+16)) = _7file_start_sym;
    *((int *)(_2+20)) = _7OpWarning;
    *((int *)(_2+24)) = _7OpTrace;
    *((int *)(_2+28)) = _7OpTypeCheck;
    *((int *)(_2+32)) = _7OpProfileTime;
    *((int *)(_2+36)) = _7OpProfileStatement;
    *((int *)(_2+40)) = _7OpStrictGoto;
    _2104 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_2104);
    Append(&_12IncludeStk, _12IncludeStk, _2104);

    //     src_file = new_file
    _12src_file = _new_file;

    //     file_start_sym = last_sym
    _7file_start_sym = _11last_sym;

    //     if current_file_no >= MAX_FILE then
    if (_7current_file_no < 256)
        goto L6;

    // 		CompileErr("program includes too many files")
    RefDS(_2113);
    _9CompileErr(_2113);
L6:

    //     file_name = append(file_name, new_include_name)
    RefDS(_12new_include_name);
    Append(&_7file_name, _7file_name, _12new_include_name);

    //     file_eval &= 0
    Append(&_7file_eval, _7file_eval, 0);

    //     current_file_no = length(file_name)
    _7current_file_no = SEQ_PTR(_7file_name)->length;

    //     if new_include_space != 0 then
    if (_12new_include_space == 0)
        goto L7;

    // 		SymTab[new_include_space][S_OBJ] = current_file_no
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_12new_include_space + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7current_file_no;
    DeRef(_1);
L7:

    //     line_number = 0
    _7line_number = 0;

    // end procedure
    DeRef(_short_name);
    DeRef(_2097);
    DeRef(_2104);
    return 0;
    ;
}


int _12IncludePop()
{
    int _top = 0;
    int _2120;
    int _0, _1, _2;
    

    // 	if not eval_stack[$] then
    _2120 = SEQ_PTR(_7eval_stack)->length;
    _2 = (int)SEQ_PTR(_7eval_stack);
    _2120 = (int)*(((s1_ptr)_2)->base + _2120);
    if (_2120 != 0)
        goto L1;

    // 		eval_stack = eval_stack[1..$-1]
    _2120 = SEQ_PTR(_7eval_stack)->length;
    _2120 = _2120 - 1;
    rhs_slice_target = (object_ptr)&_7eval_stack;
    RHS_Slice((s1_ptr)_7eval_stack, 1, _2120);
L1:

    // 	if src_file != -1 then
    if (_12src_file == -1)
        goto L2;

    // 		close(src_file)	
    EClose(_12src_file);
L2:

    //     if length(IncludeStk) = 0 then 
    _2120 = SEQ_PTR(_12IncludeStk)->length;
    if (_2120 != 0)
        goto L3;

    //     src_file = -1
    _12src_file = -1;

    // 	return FALSE  -- the end  
    DeRef(_top);
    return 0;
L3:

    //     top = IncludeStk[length(IncludeStk)]
    _2120 = SEQ_PTR(_12IncludeStk)->length;
    DeRef(_top);
    _2 = (int)SEQ_PTR(_12IncludeStk);
    _top = (int)*(((s1_ptr)_2)->base + _2120);
    RefDS(_top);

    //     current_file_no    = top[FILE_NO]
    _2 = (int)SEQ_PTR(_top);
    _7current_file_no = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_7current_file_no))
        _7current_file_no = (long)DBL_PTR(_7current_file_no)->dbl;

    //     line_number        = top[LINE_NO]
    _2 = (int)SEQ_PTR(_top);
    _7line_number = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_7line_number))
        _7line_number = (long)DBL_PTR(_7line_number)->dbl;

    //     src_file           = top[FILE_PTR]
    _2 = (int)SEQ_PTR(_top);
    _12src_file = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_12src_file))
        _12src_file = (long)DBL_PTR(_12src_file)->dbl;

    //     file_start_sym     = top[FILE_START_SYM]
    _2 = (int)SEQ_PTR(_top);
    _7file_start_sym = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_7file_start_sym))
        _7file_start_sym = (long)DBL_PTR(_7file_start_sym)->dbl;

    //     OpWarning          = top[OP_WARNING]
    _2 = (int)SEQ_PTR(_top);
    _7OpWarning = (int)*(((s1_ptr)_2)->base + 5);
    if (!IS_ATOM_INT(_7OpWarning))
        _7OpWarning = (long)DBL_PTR(_7OpWarning)->dbl;

    //     OpTrace            = top[OP_TRACE]
    _2 = (int)SEQ_PTR(_top);
    _7OpTrace = (int)*(((s1_ptr)_2)->base + 6);
    if (!IS_ATOM_INT(_7OpTrace))
        _7OpTrace = (long)DBL_PTR(_7OpTrace)->dbl;

    //     OpTypeCheck        = top[OP_TYPE_CHECK]
    _2 = (int)SEQ_PTR(_top);
    _7OpTypeCheck = (int)*(((s1_ptr)_2)->base + 7);
    if (!IS_ATOM_INT(_7OpTypeCheck))
        _7OpTypeCheck = (long)DBL_PTR(_7OpTypeCheck)->dbl;

    //     OpProfileTime      = top[OP_PROFILE_TIME]
    _2 = (int)SEQ_PTR(_top);
    _7OpProfileTime = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_7OpProfileTime))
        _7OpProfileTime = (long)DBL_PTR(_7OpProfileTime)->dbl;

    //     OpProfileStatement = top[OP_PROFILE_STATEMENT]
    _2 = (int)SEQ_PTR(_top);
    _7OpProfileStatement = (int)*(((s1_ptr)_2)->base + 9);
    if (!IS_ATOM_INT(_7OpProfileStatement))
        _7OpProfileStatement = (long)DBL_PTR(_7OpProfileStatement)->dbl;

    // 	OpStrictGoto       = top[OP_STRICT_GOTO]
    _2 = (int)SEQ_PTR(_top);
    _7OpStrictGoto = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_7OpStrictGoto))
        _7OpStrictGoto = (long)DBL_PTR(_7OpStrictGoto)->dbl;

    //     IncludeStk = IncludeStk[1..$-1]
    _2120 = SEQ_PTR(_12IncludeStk)->length;
    _2120 = _2120 - 1;
    rhs_slice_target = (object_ptr)&_12IncludeStk;
    RHS_Slice((s1_ptr)_12IncludeStk, 1, _2120);

    //     return TRUE
    DeRefDS(_top);
    return 1;
    ;
}


int _12MakeInt(int _text)
{
    int _num;
    int _2150 = 0;
    int _2149 = 0;
    int _2144 = 0;
    int _0, _1, _2;
    

    //     if length(text) > 9 then -- ensure no possibility of overflow  
    _2144 = SEQ_PTR(_text)->length;
    if (_2144 <= 9)
        goto L1;

    // 	return -1            -- use f.p. calculations  
    DeRefDS(_text);
    return -1;
L1:

    //     num = text[1] - '0'
    DeRef(_2144);
    _2 = (int)SEQ_PTR(_text);
    _2144 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2144);
    if (IS_ATOM_INT(_2144)) {
        _num = _2144 - 48;
    }
    else {
        _num = binary_op(MINUS, _2144, 48);
    }
    if (!IS_ATOM_INT(_num)) {
        _1 = (long)(DBL_PTR(_num)->dbl);
        DeRefDS(_num);
        _num = _1;
    }

    //     for i = 2 to length(text) do 
    DeRef(_2144);
    _2144 = SEQ_PTR(_text)->length;
    { int _i;
        _i = 2;
L2:
        if (_i > _2144)
            goto L3;

        // 	num = num * 10 + (text[i] - '0')
        DeRef(_2149);
        if (_num == (short)_num)
            _2149 = _num * 10;
        else
            _2149 = NewDouble(_num * (double)10);
        DeRef(_2150);
        _2 = (int)SEQ_PTR(_text);
        _2150 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_2150);
        _0 = _2150;
        if (IS_ATOM_INT(_2150)) {
            _2150 = _2150 - 48;
            if ((long)((unsigned long)_2150 +(unsigned long) HIGH_BITS) >= 0)
                _2150 = NewDouble((double)_2150);
        }
        else {
            _2150 = binary_op(MINUS, _2150, 48);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_2149) && IS_ATOM_INT(_2150)) {
            _num = _2149 + _2150;
        }
        else {
            _num = binary_op(PLUS, _2149, _2150);
        }
        if (!IS_ATOM_INT(_num)) {
            _1 = (long)(DBL_PTR(_num)->dbl);
            DeRefDS(_num);
            _num = _1;
        }

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     return num
    DeRefDS(_text);
    DeRef(_2150);
    DeRef(_2149);
    DeRef(_2144);
    return _num;
    ;
}


int _12EscapeChar(int _c)
{
    int _0, _1, _2;
    

    //     if c = 'n' then
    if (_c != 110)
        goto L1;

    // 	return '\n'
    return 10;
    goto L2;
L1:

    //     elsif c = '\\' then
    if (_c != 92)
        goto L3;

    // 	return '\\'
    return 92;
    goto L2;
L3:

    //     elsif c = 't' then
    if (_c != 116)
        goto L4;

    // 	return '\t'
    return 9;
    goto L2;
L4:

    //     elsif c = '"' then
    if (_c != 34)
        goto L5;

    // 	return '"'
    return 34;
    goto L2;
L5:

    //     elsif c = '\''then
    if (_c != 39)
        goto L6;

    // 	return '\''
    return 39;
    goto L2;
L6:

    //     elsif c = 'r' then
    if (_c != 114)
        goto L7;

    // 	return '\r'
    return 13;
    goto L2;
L7:

    // 	CompileErr("unknown escape character")
    RefDS(_2159);
    _9CompileErr(_2159);
L2:
    ;
}


int _12my_sscanf(int _yytext)
{
    int _e_sign;
    int _ndigits;
    int _e_mag;
    int _mantissa = 0;
    int _c;
    int _i;
    int _dec = 0;
    int _2160 = 0;
    int _2168 = 0;
    int _0, _1, _2;
    

    //     if length(yytext) < 2 then
    _2160 = SEQ_PTR(_yytext)->length;
    if (_2160 >= 2)
        goto L1;

    // 	CompileErr("number not formed correctly")
    RefDS(_2162);
    _9CompileErr(_2162);
L1:

    //     mantissa = 0.0
    RefDS(_2163);
    DeRef(_mantissa);
    _mantissa = _2163;

    //     ndigits = 0
    _ndigits = 0;

    //     yytext &= 0 -- end marker
    Append(&_yytext, _yytext, 0);

    //     c = yytext[1]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    //     i = 2
    _i = 2;

    //     while c >= '0' and c <= '9' do
L2:
    DeRef(_2160);
    _2160 = (_c >= 48);
    if (_2160 == 0) {
        goto L3;
    }
    DeRef(_2168);
    _2168 = (_c <= 57);
L4:
    if (_2168 == 0)
        goto L3;

    // 	ndigits += 1
    _ndigits = _ndigits + 1;

    // 	mantissa = mantissa * 10.0 + (c - '0')
    DeRef(_2168);
    _2168 = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_2170)->dbl);
    DeRef(_2160);
    _2160 = _c - 48;
    if ((long)((unsigned long)_2160 +(unsigned long) HIGH_BITS) >= 0)
        _2160 = NewDouble((double)_2160);
    DeRefDS(_mantissa);
    if (IS_ATOM_INT(_2160)) {
        _mantissa = NewDouble(DBL_PTR(_2168)->dbl + (double)_2160);
    }
    else
        _mantissa = NewDouble(DBL_PTR(_2168)->dbl + DBL_PTR(_2160)->dbl);

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	i += 1
    _i = _i + 1;

    //     end while
    goto L2;
L3:

    //     if c = '.' then
    if (_c != 46)
        goto L5;

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	i += 1
    _i = _i + 1;

    // 	dec = 10.0
    RefDS(_2170);
    DeRef(_dec);
    _dec = _2170;

    // 	while c >= '0' and c <= '9' do
L6:
    DeRef(_2160);
    _2160 = (_c >= 48);
    if (_2160 == 0) {
        goto L7;
    }
    DeRef(_2168);
    _2168 = (_c <= 57);
L8:
    if (_2168 == 0)
        goto L7;

    // 	    ndigits += 1
    _ndigits = _ndigits + 1;

    // 	    mantissa = mantissa + (c - '0') / dec
    DeRef(_2168);
    _2168 = _c - 48;
    if ((long)((unsigned long)_2168 +(unsigned long) HIGH_BITS) >= 0)
        _2168 = NewDouble((double)_2168);
    _0 = _2168;
    if (IS_ATOM_INT(_2168)) {
        _2168 = NewDouble((double)_2168 / DBL_PTR(_dec)->dbl);
    }
    else {
        _2168 = NewDouble(DBL_PTR(_2168)->dbl / DBL_PTR(_dec)->dbl);
    }
    DeRef(_0);
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl + DBL_PTR(_2168)->dbl);
    DeRef(_0);

    // 	    dec = dec * 10.0
    _0 = _dec;
    _dec = NewDouble(DBL_PTR(_dec)->dbl * DBL_PTR(_2170)->dbl);
    DeRefDS(_0);

    // 	    c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    i += 1
    _i = _i + 1;

    // 	end while
    goto L6;
L7:
L5:

    //     if ndigits = 0 then
    if (_ndigits != 0)
        goto L9;

    // 	return {}  -- no digits
    RefDS(_39);
    DeRefDS(_yytext);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_2160);
    DeRef(_2168);
    return _39;
L9:

    //     if c = 'e' or c = 'E' then
    DeRef(_2168);
    _2168 = (_c == 101);
    if (_2168 != 0) {
        goto LA;
    }
    DeRef(_2160);
    _2160 = (_c == 69);
LB:
    if (_2160 == 0)
        goto LC;
LA:

    // 	e_sign = +1
    _e_sign = 1;

    // 	e_mag = 0
    _e_mag = 0;

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	i += 1
    _i = _i + 1;

    // 	if c = '-' then
    if (_c != 45)
        goto LD;

    // 	    e_sign = -1
    _e_sign = -1;
    goto LE;
LD:

    // 	elsif c != '+' then
    if (_c == 43)
        goto LF;

    // 	    i -= 1
    _i = _i - 1;
LF:
LE:

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	i += 1
    _i = _i + 1;

    // 	if c >= '0' and c <= '9' then
    DeRef(_2160);
    _2160 = (_c >= 48);
    if (_2160 == 0) {
        goto L10;
    }
    DeRef(_2168);
    _2168 = (_c <= 57);
L11:
    if (_2168 == 0)
        goto L10;

    // 	    e_mag = c - '0'
    _e_mag = _c - 48;

    // 	    c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    i += 1
    _i = _i + 1;

    // 	    while c >= '0' and c <= '9' do
L12:
    DeRef(_2168);
    _2168 = (_c >= 48);
    if (_2168 == 0) {
        goto L13;
    }
    DeRef(_2160);
    _2160 = (_c <= 57);
L14:
    if (_2160 == 0)
        goto L13;

    // 		e_mag = e_mag * 10 + c - '0'
    DeRef(_2160);
    if (_e_mag == (short)_e_mag)
        _2160 = _e_mag * 10;
    else
        _2160 = NewDouble(_e_mag * (double)10);
    _0 = _2160;
    if (IS_ATOM_INT(_2160)) {
        _2160 = _2160 + _c;
        if ((long)((unsigned long)_2160 + (unsigned long)HIGH_BITS) >= 0) 
            _2160 = NewDouble((double)_2160);
    }
    else {
        _2160 = NewDouble(DBL_PTR(_2160)->dbl + (double)_c);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_2160)) {
        _e_mag = _2160 - 48;
    }
    else {
        _e_mag = NewDouble(DBL_PTR(_2160)->dbl - (double)48);
    }
    if (!IS_ATOM_INT(_e_mag)) {
        _1 = (long)(DBL_PTR(_e_mag)->dbl);
        DeRefDS(_e_mag);
        _e_mag = _1;
    }

    // 		c = yytext[i]                          
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 		i += 1
    _i = _i + 1;

    // 		if e_mag > 1000 then -- avoid int overflow. can only have 
    if (_e_mag <= 1000)
        goto L12;

    // 		    exit             -- 200-digit mantissa to reduce mag
    goto L13;
L15:

    // 	    end while
    goto L12;
L16:
    goto L13;
L10:

    // 	    return {} -- no exponent
    RefDS(_39);
    DeRefDS(_yytext);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_2160);
    DeRef(_2168);
    return _39;
L13:

    // 	e_mag = e_sign * e_mag
    _e_mag = _e_sign * _e_mag;

    // 	if e_mag > 308 then
    if (_e_mag <= 308)
        goto L17;

    // 	    mantissa = mantissa * power(10.0, 308.0)
    DeRef(_2160);
    _2160 = Dpower(DBL_PTR(_2170), DBL_PTR(_2219));
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_2160)->dbl);
    DeRef(_0);

    // 	    e_mag = e_mag - 308
    _e_mag = _e_mag - 308;

    // 	    while e_mag > 0 do
L18:
    if (_e_mag <= 0)
        goto L19;

    // 		mantissa = mantissa * 10.0 -- Could crash? No we'll get INF.
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_2170)->dbl);
    DeRef(_0);

    // 		e_mag -= 1
    _e_mag = _e_mag - 1;

    // 	    end while
    goto L18;
L1A:
    goto L19;
L17:

    // 	    mantissa = mantissa * power(10.0, e_mag)
    DeRef(_2160);
    temp_d.dbl = (double)_e_mag;
    _2160 = Dpower(DBL_PTR(_2170), &temp_d);
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_2160)->dbl);
    DeRef(_0);
L19:
LC:

    //     return mantissa
    DeRefDS(_yytext);
    DeRef(_dec);
    DeRef(_2160);
    DeRef(_2168);
    return _mantissa;
    ;
}


int _12Scanner()
{
    int _ch;
    int _i;
    int _sp;
    int _yytext = 0;
    int _d = 0;
    int _tok = 0;
    int _is_int;
    int _class;
    int _name = 0;
    int _2246 = 0;
    int _2248 = 0;
    int _2236;
    int _2228 = 0;
    int _0, _1, _2, _3;
    

    //     while TRUE do
L1:

    // 	ch = ThisLine[bp]  -- getch inlined (in all the "hot" spots)
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 	bp += 1
    _9bp = _9bp + 1;

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L2;

    // 		token_boundaries = append( token_boundaries, { bp-1, -1 } )
    DeRef(_2228);
    _2228 = _9bp - 1;
    if ((long)((unsigned long)_2228 +(unsigned long) HIGH_BITS) >= 0)
        _2228 = NewDouble((double)_2228);
    _0 = _2228;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _2228;
    Ref(_2228);
    ((int *)_2)[2] = -1;
    _2228 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_2228);
    Append(&_7token_boundaries, _7token_boundaries, _2228);

    // 		token_ws &= 0
    Append(&_7token_ws, _7token_ws, 0);
L2:

    // 	while ch = ' ' or ch = '\t' do
L3:
    DeRef(_2228);
    _2228 = (_ch == 32);
    if (_2228 != 0) {
        goto L4;
    }
    _2236 = (_ch == 9);
L5:
    if (_2236 == 0)
        goto L6;
L4:

    // 		if preprocess then 
    if (_7preprocess == 0)
        goto L7;

    // 			token_ws[$] += 1
    _2236 = SEQ_PTR(_7token_ws)->length;
    DeRef(_2228);
    _2 = (int)SEQ_PTR(_7token_ws);
    _2228 = (int)*(((s1_ptr)_2)->base + _2236);
    Ref(_2228);
    _0 = _2228;
    if (IS_ATOM_INT(_2228)) {
        _2228 = _2228 + 1;
        if (_2228 > MAXINT)
            _2228 = NewDouble((double)_2228);
    }
    else
        _2228 = binary_op(PLUS, 1, _2228);
    DeRef(_0);
    Ref(_2228);
    _2 = (int)SEQ_PTR(_7token_ws);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7token_ws = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _2236);
    _1 = *(int *)_2;
    *(int *)_2 = _2228;
    DeRef(_1);
L7:

    // 	    ch = ThisLine[bp]  -- getch inlined
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 	    bp += 1
    _9bp = _9bp + 1;

    // 	end while
    goto L3;
L6:

    // 	if ch = 0 then
    if (_ch != 0)
        goto L8;

    // 	    bad_zero()
    _12bad_zero();
L8:

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L9;

    // 		token_boundaries[$][1] += token_ws[$]
    DeRef(_2228);
    _2228 = SEQ_PTR(_7token_boundaries)->length;
    _2 = (int)SEQ_PTR(_7token_boundaries);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7token_boundaries = MAKE_SEQ(_2);
    }
    _3 = (int)(_2228 + ((s1_ptr)_2)->base);
    DeRef(_2246);
    _2246 = SEQ_PTR(_7token_ws)->length;
    _2 = (int)SEQ_PTR(_7token_ws);
    _2246 = (int)*(((s1_ptr)_2)->base + _2246);
    Ref(_2246);
    DeRef(_2248);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _2248 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2248);
    _0 = _2248;
    if (IS_ATOM_INT(_2248) && IS_ATOM_INT(_2246)) {
        _2248 = _2248 + _2246;
        if ((long)((unsigned long)_2248 + (unsigned long)HIGH_BITS) >= 0) 
            _2248 = NewDouble((double)_2248);
    }
    else {
        _2248 = binary_op(PLUS, _2248, _2246);
    }
    DeRef(_0);
    Ref(_2248);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _2248;
    DeRef(_1);
L9:

    // 	class = char_class[ch]
    _2 = (int)SEQ_PTR(_12char_class);
    _class = (int)*(((s1_ptr)_2)->base + _ch);

    // 	if class = LETTER then
    if (_class != -2)
        goto LA;

    // 	    sp = bp
    _sp = _9bp;

    // 	    ch = ThisLine[bp]  -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 	    bp += 1 
    _9bp = _9bp + 1;

    // 	    if ch = 0 then
    if (_ch != 0)
        goto LB;

    // 		bad_zero()
    _12bad_zero();
LB:

    // 	    while id_char[ch] do
LC:
    DeRef(_2248);
    _2 = (int)SEQ_PTR(_12id_char);
    _2248 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2248 == 0)
        goto LD;

    // 		ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 		bp += 1
    _9bp = _9bp + 1;

    // 		if ch = 0 then
    if (_ch != 0)
        goto LC;

    // 		    bad_zero()
    _12bad_zero();
LE:

    // 	    end while    
    goto LC;
LD:

    // 	    yytext = ThisLine[sp-1..bp-2]
    DeRef(_2248);
    _2248 = _sp - 1;
    if ((long)((unsigned long)_2248 +(unsigned long) HIGH_BITS) >= 0)
        _2248 = NewDouble((double)_2248);
    DeRef(_2246);
    _2246 = _9bp - 2;
    rhs_slice_target = (object_ptr)&_yytext;
    RHS_Slice((s1_ptr)_9ThisLine, _2248, _2246);

    // 	    bp -= 1  -- ungetch inlined in all the "hot" spots
    _9bp = _9bp - 1;

    // 		    tok = keyfind(yytext, -1)
    RefDS(_yytext);
    _0 = _tok;
    _tok = _11keyfind(_yytext, -1);
    DeRef(_0);

    // 		    if tok[T_ID] = NAMESPACE then
    _2 = (int)SEQ_PTR(_tok);
    _2246 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2246);
    if (binary_op_a(NOTEQ, _2246, 523))
        goto LF;

    // 				ch = getch()
    _ch = _12getch();

    // 				while ch = ' ' or ch = '\t' do
L10:
    DeRef(_2246);
    _2246 = (_ch == 32);
    if (_2246 != 0) {
        goto L11;
    }
    DeRef(_2248);
    _2248 = (_ch == 9);
L12:
    if (_2248 == 0)
        goto L13;
L11:

    // 				    ch = getch()
    _ch = _12getch();

    // 				end while
    goto L10;
L13:

    // 				if ch = ':' then
    if (_ch != 58)
        goto L14;

    // 				    ch = getch()
    _ch = _12getch();

    // 				    while ch = ' ' or ch = '\t' do
L15:
    DeRef(_2248);
    _2248 = (_ch == 32);
    if (_2248 != 0) {
        goto L16;
    }
    DeRef(_2246);
    _2246 = (_ch == 9);
L17:
    if (_2246 == 0)
        goto L18;
L16:

    // 						ch = getch()
    _ch = _12getch();

    // 				    end while
    goto L15;
L18:

    // 				    yytext = ""
    RefDS(_39);
    DeRef(_yytext);
    _yytext = _39;

    // 		    while id_char[ch] do
L19:
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_12id_char);
    _2246 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2246 == 0)
        goto L1A;

    // 						yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 						ch = getch()
    _ch = _12getch();

    // 				    end while 
    goto L19;
L1A:

    // 				    ungetch()
    _12ungetch();

    // 				    if length(yytext) = 0 then
    DeRef(_2246);
    _2246 = SEQ_PTR(_yytext)->length;
    if (_2246 != 0)
        goto L1B;

    // 						CompileErr("an identifier is expected here")
    RefDS(_2282);
    _9CompileErr(_2282);
L1B:

    // 				    tok = keyfind(yytext, SymTab[tok[T_SYM]][S_OBJ]) 
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_tok);
    _2246 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2246);
    _0 = _2246;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_2246))
        _2246 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2246)->dbl));
    else
        _2246 = (int)*(((s1_ptr)_2)->base + _2246);
    Ref(_2246);
    DeRef(_0);
    _0 = _2246;
    _2 = (int)SEQ_PTR(_2246);
    _2246 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2246);
    DeRef(_0);
    RefDS(_yytext);
    Ref(_2246);
    _0 = _tok;
    _tok = _11keyfind(_yytext, _2246);
    DeRefDS(_0);

    // 				    if tok[T_ID] = VARIABLE then
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_tok);
    _2246 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2246);
    if (binary_op_a(NOTEQ, _2246, -100))
        goto L1C;

    // 						tok[T_ID] = QUALIFIED_VARIABLE
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 515;
    DeRef(_1);
    goto L1D;
L1C:

    // 				    elsif tok[T_ID] = r:FUNC then
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_tok);
    _2246 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2246);
    if (binary_op_a(NOTEQ, _2246, 501))
        goto L1E;

    // 						tok[T_ID] = QUALIFIED_FUNC
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 524;
    DeRef(_1);
    goto L1D;
L1E:

    // 				    elsif tok[T_ID] = r:PROC then
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_tok);
    _2246 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2246);
    if (binary_op_a(NOTEQ, _2246, 27))
        goto L1F;

    // 						tok[T_ID] = QUALIFIED_PROC
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 525;
    DeRef(_1);
    goto L1D;
L1F:

    // 				    elsif tok[T_ID] = TYPE then
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_tok);
    _2246 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2246);
    if (binary_op_a(NOTEQ, _2246, 504))
        goto L1D;

    // 						tok[T_ID] = QUALIFIED_TYPE
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 526;
    DeRef(_1);
L20:
L21:
    goto L1D;
L14:

    // 				    ungetch()
    _12ungetch();
L1D:
LF:

    // 		    return tok
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_name);
    DeRef(_2246);
    DeRef(_2248);
    DeRef(_2228);
    return _tok;
    goto L1;
LA:

    // 	elsif class <= ILLEGAL_CHAR then
    if (_class > -20)
        goto L22;

    // 	    return {class, 0}  -- brackets, punctuation, eof, illegal char etc.
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _class;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L22:

    // 	elsif class = NEWLINE then
    if (_class != -6)
        goto L23;

    // 	    if start_include then
    if (_12start_include == 0)
        goto L24;

    // 			IncludePush()
    _12IncludePush();
L24:

    // 	    read_line()
    _12read_line();
    goto L1;
L23:

    // 	elsif class = EQUALS then
    if (_class != 3)
        goto L25;

    // 	    return {class, 0}  
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _class;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L25:

    // 	elsif class = DOT or class = DIGIT then
    DeRef(_2246);
    _2246 = (_class == -3);
    if (_2246 != 0) {
        goto L26;
    }
    DeRef(_2248);
    _2248 = (_class == -7);
L27:
    if (_2248 == 0)
        goto L28;
L26:

    // 	    if class = DOT then
    if (_class != -3)
        goto L29;

    // 		    ch = getch()
    _ch = _12getch();

    // 			if ch = '.' then
    if (_ch != 46)
        goto L2A;

    // 			    return {SLICE, 0}
    DeRef(_2248);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 516;
    ((int *)_2)[2] = 0;
    _2248 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2246);
    DeRef(_2228);
    return _2248;
    goto L2B;
L2A:

    // 			elsif not find(ch ,"0123456789" ) then
    DeRef(_2248);
    _2248 = find(_ch, _2307);
    if (_2248 != 0)
        goto L2C;

    // 			    ungetch()
    _12ungetch();

    // 				return {DOT_NOTATION, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 423;
    ((int *)_2)[2] = 0;
    _2248 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2246);
    DeRef(_2228);
    return _2248;
    goto L2B;
L2C:

    // 				ungetch()
    _12ungetch();

    // 				ch = '.'
    _ch = 46;
L2B:
L29:

    // 	    is_int = TRUE
    _is_int = 1;

    // 	    yytext = {ch}
    _0 = _yytext;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _ch;
    _yytext = MAKE_SEQ(_1);
    DeRef(_0);

    // 	    if ch = '.' then
    if (_ch != 46)
        goto L2D;

    // 		is_int = FALSE
    _is_int = 0;
L2D:

    // 	    ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 	    if ch = 0 then
    if (_ch != 0)
        goto L2E;

    // 		bad_zero()
    _12bad_zero();
L2E:

    // 	    bp += 1
    _9bp = _9bp + 1;

    // 	    while char_class[ch] = DIGIT do 
L2F:
    DeRef(_2248);
    _2 = (int)SEQ_PTR(_12char_class);
    _2248 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2248 != -7)
        goto L30;

    // 		yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 		ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 		if ch = 0 then
    if (_ch != 0)
        goto L31;

    // 		    bad_zero()
    _12bad_zero();
L31:

    // 		bp += 1
    _9bp = _9bp + 1;

    // 	    end while
    goto L2F;
L30:

    // 	    if ch = '.' then
    if (_ch != 46)
        goto L32;

    // 		ch = getch()
    _ch = _12getch();

    // 		if ch = '.' then
    if (_ch != 46)
        goto L33;

    // 		    ungetch()
    _12ungetch();
    goto L34;
L33:

    // 		    is_int = FALSE
    _is_int = 0;

    // 		    if yytext[1] = '.' then
    DeRef(_2248);
    _2 = (int)SEQ_PTR(_yytext);
    _2248 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2248);
    if (binary_op_a(NOTEQ, _2248, 46))
        goto L35;

    // 			CompileErr("only one decimal point allowed")
    RefDS(_2327);
    _9CompileErr(_2327);
    goto L36;
L35:

    // 			yytext &= '.'
    Append(&_yytext, _yytext, 46);
L36:

    // 		    if char_class[ch] = DIGIT then
    DeRef(_2248);
    _2 = (int)SEQ_PTR(_12char_class);
    _2248 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2248 != -7)
        goto L37;

    // 			yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 			ch = getch()
    _ch = _12getch();

    // 			while char_class[ch] = DIGIT do
L38:
    DeRef(_2248);
    _2 = (int)SEQ_PTR(_12char_class);
    _2248 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2248 != -7)
        goto L39;

    // 			    yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 			    ch = getch()
    _ch = _12getch();

    // 			end while
    goto L38;
L3A:
    goto L39;
L37:

    // 			CompileErr("fractional part of number is missing")
    RefDS(_2337);
    _9CompileErr(_2337);
L39:
L34:
L32:

    // 	    if ch = 'e' or ch = 'E' then
    DeRef(_2248);
    _2248 = (_ch == 101);
    if (_2248 != 0) {
        goto L3B;
    }
    DeRef(_2246);
    _2246 = (_ch == 69);
L3C:
    if (_2246 == 0)
        goto L3D;
L3B:

    // 		is_int = FALSE
    _is_int = 0;

    // 		yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 		ch = getch()
    _ch = _12getch();

    // 		if ch = '-' or ch = '+' or char_class[ch] = DIGIT then
    DeRef(_2246);
    _2246 = (_ch == 45);
    if (_2246 != 0) {
        _2246 = 1;
        goto L3E;
    }
    DeRef(_2248);
    _2248 = (_ch == 43);
    _2246 = (_2248 != 0);
L3E:
    if (_2246 != 0) {
        goto L3F;
    }
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_12char_class);
    _2246 = (int)*(((s1_ptr)_2)->base + _ch);
    _2246 = (_2246 == -7);
L40:
    if (_2246 == 0)
        goto L41;
L3F:

    // 		    yytext &= ch
    Append(&_yytext, _yytext, _ch);
    goto L42;
L41:

    // 		    CompileErr("exponent not formed correctly")
    RefDS(_2350);
    _9CompileErr(_2350);
L42:

    // 		ch = getch()
    _ch = _12getch();

    // 		while char_class[ch] = DIGIT do
L43:
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_12char_class);
    _2246 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2246 != -7)
        goto L44;

    // 		    yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 		    ch = getch()
    _ch = _12getch();

    // 		end while
    goto L43;
L44:
L3D:

    // 	    bp -= 1  --ungetch
    _9bp = _9bp - 1;

    // 	    i = MakeInt(yytext)
    RefDS(_yytext);
    _i = _12MakeInt(_yytext);

    // 	    if is_int and i != -1 then
    if (_is_int == 0) {
        goto L45;
    }
    DeRef(_2248);
    _2248 = (_i != -1);
L46:
    if (_2248 == 0)
        goto L45;

    // 		return {ATOM, NewIntSym(i)}
    _0 = _2248;
    _2248 = _11NewIntSym(_i);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2248;
    _2248 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2246);
    DeRef(_2228);
    return _2248;
    goto L1;
L45:

    // 		d = my_sscanf(yytext)
    RefDS(_yytext);
    _0 = _d;
    _d = _12my_sscanf(_yytext);
    DeRef(_0);

    // 		if sequence(d) then
    DeRef(_2248);
    _2248 = 0;
    if (_2248 == 0)
        goto L47;

    // 		    CompileErr("number not formed correctly")
    RefDS(_2162);
    _9CompileErr(_2162);
    goto L1;
L47:

    // 		elsif is_int and d <= MAXINT_DBL then
    if (_is_int == 0) {
        goto L48;
    }
    DeRef(_2246);
    if (IS_ATOM_INT(_d)) {
        _2246 = (_d <= 1073741823);
    }
    else {
        _2246 = (DBL_PTR(_d)->dbl <= (double)1073741823);
    }
L49:
    if (_2246 == 0)
        goto L48;

    // 		    return {ATOM, NewIntSym(d)}  -- 1 to 1.07 billion
    Ref(_d);
    _0 = _2246;
    _2246 = _11NewIntSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L48:

    // 		    return {ATOM, NewDoubleSym(d)}
    Ref(_d);
    _0 = _2246;
    _2246 = _11NewDoubleSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L4A:
L4B:
    goto L1;
L28:

    // 	elsif class = MINUS then
    if (_class != 10)
        goto L4C;

    // 	    ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 	    bp += 1
    _9bp = _9bp + 1;

    // 	    if ch = '-' then 
    if (_ch != 45)
        goto L4D;

    // 		if start_include then
    if (_12start_include == 0)
        goto L4E;

    // 		    IncludePush()
    _12IncludePush();
L4E:

    // 		read_line()
    _12read_line();
    goto L1;
L4D:

    // 	    elsif ch = '=' then
    if (_ch != 61)
        goto L4F;

    // 		return {MINUS_EQUALS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 519;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L4F:

    // 		bp -= 1
    _9bp = _9bp - 1;

    // 		return {MINUS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 10;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L50:
    goto L1;
L4C:

    // 	elsif class = DOUBLE_QUOTE then
    if (_class != -4)
        goto L51;

    // 	    ch = ThisLine[bp]  -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 	    bp += 1
    _9bp = _9bp + 1;

    // 	    yytext = ""
    RefDS(_39);
    DeRef(_yytext);
    _yytext = _39;

    // 	    while ch != '\n' and ch != '\r' do -- can't be EOF
L52:
    DeRef(_2246);
    _2246 = (_ch != 10);
    if (_2246 == 0) {
        goto L53;
    }
    DeRef(_2248);
    _2248 = (_ch != 13);
L54:
    if (_2248 == 0)
        goto L53;

    // 			if ch = '"' then 
    if (_ch != 34)
        goto L55;

    // 			    exit
    goto L53;
    goto L56;
L55:

    // 			elsif ch = '\\' then
    if (_ch != 92)
        goto L57;

    // 			    yytext &= EscapeChar(getch())
    _0 = _2248;
    _2248 = _12getch();
    DeRef(_0);
    _2248 = _12EscapeChar(_2248);
    Append(&_yytext, _yytext, _2248);
    goto L56;
L57:

    // 			elsif ch = '\t' then
    if (_ch != 9)
        goto L58;

    // 			    CompileErr("tab character found in string - use \\t instead")
    RefDS(_2390);
    _9CompileErr(_2390);
    goto L56;
L58:

    // 			elsif ch = 0 then
    if (_ch != 0)
        goto L59;

    // 			    bad_zero()
    _12bad_zero();
    goto L56;
L59:

    // 			    yytext &= ch
    Append(&_yytext, _yytext, _ch);
L56:

    // 			ch = ThisLine[bp]  -- getch
    _2 = (int)SEQ_PTR(_9ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _9bp);
    if (!IS_ATOM_INT(_ch))
        _ch = (long)DBL_PTR(_ch)->dbl;

    // 			bp += 1
    _9bp = _9bp + 1;

    // 	    end while
    goto L52;
L53:

    // 	    if ch = '\n' or ch = '\r' then
    DeRef(_2248);
    _2248 = (_ch == 10);
    if (_2248 != 0) {
        goto L5A;
    }
    DeRef(_2246);
    _2246 = (_ch == 13);
L5B:
    if (_2246 == 0)
        goto L5C;
L5A:

    // 		CompileErr("end of line reached with no closing \"")
    RefDS(_2398);
    _9CompileErr(_2398);
L5C:

    // 	    return {STRING, NewStringSym(yytext)}
    RefDS(_yytext);
    _0 = _2246;
    _2246 = _11NewStringSym(_yytext);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 503;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRefDS(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L51:

    // 	elsif class = PLUS then
    if (_class != 11)
        goto L5D;

    // 	    ch = getch()
    _ch = _12getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L5E;

    // 		return {PLUS_EQUALS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 518;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L5E:

    // 		ungetch()
    _12ungetch();

    // 		return {PLUS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 11;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L5F:
    goto L1;
L5D:

    // 	elsif class = CONCAT then
    if (_class != 15)
        goto L60;

    // 	    ch = getch()
    _ch = _12getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L61;

    // 		return {CONCAT_EQUALS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 522;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L61:

    // 		ungetch()
    _12ungetch();

    // 		return {CONCAT, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 15;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L62:
    goto L1;
L60:

    // 	elsif class = NUMBER_SIGN then
    if (_class != -11)
        goto L63;

    // 	    i = 0
    _i = 0;

    // 	    is_int = -1
    _is_int = -1;

    // 	    while i < MAXINT_VAL/32 do             
L64:
    DeRef(_2246);
    _2246 = (1073741823 % 32) ? NewDouble((double)1073741823 / 32) : (1073741823 / 32);
    if (binary_op_a(GREATEREQ, _i, _2246))
        goto L65;

    // 		ch = getch()
    _ch = _12getch();

    // 		if char_class[ch] = DIGIT then
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_12char_class);
    _2246 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2246 != -7)
        goto L66;

    // 		    i = i * 16 + ch - '0'
    if (_i == (short)_i)
        _2246 = _i * 16;
    else
        _2246 = NewDouble(_i * (double)16);
    _0 = _2246;
    if (IS_ATOM_INT(_2246)) {
        _2246 = _2246 + _ch;
        if ((long)((unsigned long)_2246 + (unsigned long)HIGH_BITS) >= 0) 
            _2246 = NewDouble((double)_2246);
    }
    else {
        _2246 = NewDouble(DBL_PTR(_2246)->dbl + (double)_ch);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_2246)) {
        _i = _2246 - 48;
    }
    else {
        _i = NewDouble(DBL_PTR(_2246)->dbl - (double)48);
    }
    if (!IS_ATOM_INT(_i)) {
        _1 = (long)(DBL_PTR(_i)->dbl);
        DeRefDS(_i);
        _i = _1;
    }

    // 		    is_int = TRUE
    _is_int = 1;
    goto L64;
L66:

    // 		elsif ch >= 'A' and ch <= 'F' then   
    DeRef(_2246);
    _2246 = (_ch >= 65);
    if (_2246 == 0) {
        goto L65;
    }
    DeRef(_2248);
    _2248 = (_ch <= 70);
L67:
    if (_2248 == 0)
        goto L65;

    // 		    i = (i * 16) + ch - ('A'-10)
    DeRef(_2248);
    if (_i == (short)_i)
        _2248 = _i * 16;
    else
        _2248 = NewDouble(_i * (double)16);
    _0 = _2248;
    if (IS_ATOM_INT(_2248)) {
        _2248 = _2248 + _ch;
        if ((long)((unsigned long)_2248 + (unsigned long)HIGH_BITS) >= 0) 
            _2248 = NewDouble((double)_2248);
    }
    else {
        _2248 = NewDouble(DBL_PTR(_2248)->dbl + (double)_ch);
    }
    DeRef(_0);
    DeRef(_2246);
    _2246 = 55;
    if (IS_ATOM_INT(_2248)) {
        _i = _2248 - 55;
    }
    else {
        _i = NewDouble(DBL_PTR(_2248)->dbl - (double)55);
    }
    if (!IS_ATOM_INT(_i)) {
        _1 = (long)(DBL_PTR(_i)->dbl);
        DeRefDS(_i);
        _i = _1;
    }

    // 		    is_int = TRUE
    _is_int = 1;
    goto L64;
L68:

    // 		    exit 
    goto L65;
L69:

    // 	    end while
    goto L64;
L65:

    // 	    if is_int = -1 then
    if (_is_int != -1)
        goto L6A;

    // 		if ch = '!' then
    if (_ch != 33)
        goto L6B;

    // 		    if line_number > 1 then
    if (_7line_number <= 1)
        goto L6C;

    // 			CompileErr(
    RefDS(_2430);
    _9CompileErr(_2430);
L6C:

    // 		    shebang = ThisLine
    Ref(_9ThisLine);
    DeRef(_12shebang);
    _12shebang = _9ThisLine;

    // 		    if start_include then
    if (_12start_include == 0)
        goto L6D;

    // 			IncludePush()
    _12IncludePush();
L6D:

    // 		    read_line()
    _12read_line();
    goto L1;
L6B:

    // 		    CompileErr("hex number not formed correctly")
    RefDS(_2431);
    _9CompileErr(_2431);
L6E:
    goto L1;
L6A:

    // 		if i >= MAXINT_VAL/32 then
    DeRef(_2246);
    _2246 = (1073741823 % 32) ? NewDouble((double)1073741823 / 32) : (1073741823 / 32);
    if (binary_op_a(LESS, _i, _2246))
        goto L6F;

    // 		    d = i
    DeRef(_d);
    _d = _i;

    // 		    is_int = FALSE
    _is_int = 0;

    // 		    while TRUE do
L70:

    // 			ch = getch()  -- eventually END_OF_FILE_CHAR or new-line 
    _ch = _12getch();

    // 			if char_class[ch] = DIGIT then
    DeRef(_2246);
    _2 = (int)SEQ_PTR(_12char_class);
    _2246 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2246 != -7)
        goto L71;

    // 			    d = (d * 16) + ch - '0'
    if (IS_ATOM_INT(_d)) {
        if (_d == (short)_d)
            _2246 = _d * 16;
        else
            _2246 = NewDouble(_d * (double)16);
    }
    else {
        _2246 = NewDouble(DBL_PTR(_d)->dbl * (double)16);
    }
    _0 = _2246;
    if (IS_ATOM_INT(_2246)) {
        _2246 = _2246 + _ch;
        if ((long)((unsigned long)_2246 + (unsigned long)HIGH_BITS) >= 0) 
            _2246 = NewDouble((double)_2246);
    }
    else {
        _2246 = NewDouble(DBL_PTR(_2246)->dbl + (double)_ch);
    }
    DeRef(_0);
    DeRef(_d);
    if (IS_ATOM_INT(_2246)) {
        _d = _2246 - 48;
        if ((long)((unsigned long)_d +(unsigned long) HIGH_BITS) >= 0)
            _d = NewDouble((double)_d);
    }
    else {
        _d = NewDouble(DBL_PTR(_2246)->dbl - (double)48);
    }
    goto L70;
L71:

    // 			elsif ch >= 'A' and ch <= 'F' then   
    DeRef(_2246);
    _2246 = (_ch >= 65);
    if (_2246 == 0) {
        goto L72;
    }
    DeRef(_2248);
    _2248 = (_ch <= 70);
L73:
    if (_2248 == 0)
        goto L72;

    // 			    d = (d * 16) + ch - ('A'- 10)
    DeRef(_2248);
    if (IS_ATOM_INT(_d)) {
        if (_d == (short)_d)
            _2248 = _d * 16;
        else
            _2248 = NewDouble(_d * (double)16);
    }
    else {
        _2248 = NewDouble(DBL_PTR(_d)->dbl * (double)16);
    }
    _0 = _2248;
    if (IS_ATOM_INT(_2248)) {
        _2248 = _2248 + _ch;
        if ((long)((unsigned long)_2248 + (unsigned long)HIGH_BITS) >= 0) 
            _2248 = NewDouble((double)_2248);
    }
    else {
        _2248 = NewDouble(DBL_PTR(_2248)->dbl + (double)_ch);
    }
    DeRef(_0);
    DeRef(_2246);
    _2246 = 55;
    DeRef(_d);
    if (IS_ATOM_INT(_2248)) {
        _d = _2248 - 55;
        if ((long)((unsigned long)_d +(unsigned long) HIGH_BITS) >= 0)
            _d = NewDouble((double)_d);
    }
    else {
        _d = NewDouble(DBL_PTR(_2248)->dbl - (double)55);
    }
    goto L70;
L74:

    // 			    exit 
    goto L72;
L75:

    // 		    end while
    goto L70;
L72:
L6F:

    // 		ungetch()
    _12ungetch();

    // 		if is_int then
    if (_is_int == 0)
        goto L76;

    // 		    return {ATOM, NewIntSym(i)}
    _0 = _2246;
    _2246 = _11NewIntSym(_i);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L76:

    // 		    if d <= MAXINT_DBL then            -- d is always >= 0
    if (binary_op_a(GREATER, _d, 1073741823))
        goto L77;

    // 			return {ATOM, NewIntSym(d)} 
    Ref(_d);
    _0 = _2246;
    _2246 = _11NewIntSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L77:

    // 			return {ATOM, NewDoubleSym(d)}
    Ref(_d);
    _0 = _2246;
    _2246 = _11NewDoubleSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L78:
L79:
L7A:
    goto L1;
L63:

    // 	elsif class = MULTIPLY then
    if (_class != 13)
        goto L7B;

    // 	    ch = getch()
    _ch = _12getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L7C;

    // 		return {MULTIPLY_EQUALS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 520;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L7C:

    // 		ungetch()
    _12ungetch();

    // 		return {MULTIPLY, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 13;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L7D:
    goto L1;
L7B:

    // 	elsif class = DIVIDE then
    if (_class != 14)
        goto L7E;

    // 	    ch = getch()
    _ch = _12getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L7F;

    // 		return {DIVIDE_EQUALS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 521;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L7F:

    // 		ungetch()
    _12ungetch();

    // 		return {DIVIDE, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 14;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L80:
    goto L1;
L7E:

    // 	elsif class = SINGLE_QUOTE then
    if (_class != -5)
        goto L81;

    // 	    ch = getch()
    _ch = _12getch();

    // 	    if ch = '\\' then 
    if (_ch != 92)
        goto L82;

    // 		ch = EscapeChar(getch())
    _0 = _2246;
    _2246 = _12getch();
    DeRef(_0);
    _ch = _12EscapeChar(_2246);
    goto L83;
L82:

    // 	    elsif ch = '\t' then
    if (_ch != 9)
        goto L84;

    // 		CompileErr("tab character found in string - use \\t instead")
    RefDS(_2390);
    _9CompileErr(_2390);
    goto L83;
L84:

    // 	    elsif ch = '\'' then
    if (_ch != 39)
        goto L85;

    // 		CompileErr("single-quote character is empty")
    RefDS(_2471);
    _9CompileErr(_2471);
L85:
L83:

    // 	    if getch() != '\'' then
    _0 = _2246;
    _2246 = _12getch();
    DeRef(_0);
    if (_2246 == 39)
        goto L86;

    // 		CompileErr("character constant is missing a closing '")
    RefDS(_2474);
    _9CompileErr(_2474);
L86:

    // 	    return {ATOM, NewIntSym(ch)}
    _0 = _2246;
    _2246 = _11NewIntSym(_ch);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2246;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L81:

    // 	elsif class = LESS then
    if (_class != 1)
        goto L87;

    // 	    if getch() = '=' then
    _0 = _2246;
    _2246 = _12getch();
    DeRef(_0);
    if (_2246 != 61)
        goto L88;

    // 		return {LESSEQ, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 5;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L88:

    // 		ungetch()
    _12ungetch();

    // 		return {LESS, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L89:
    goto L1;
L87:

    // 	elsif class = GREATER then
    if (_class != 6)
        goto L8A;

    // 	    if getch() = '=' then
    _0 = _2246;
    _2246 = _12getch();
    DeRef(_0);
    if (_2246 != 61)
        goto L8B;

    // 		return {GREATEREQ, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 2;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L8B:

    // 		ungetch()
    _12ungetch();

    // 		return {GREATER, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 6;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L8C:
    goto L1;
L8A:

    // 	elsif class = BANG then
    if (_class != -1)
        goto L8D;

    // 	    if getch() = '=' then 
    _0 = _2246;
    _2246 = _12getch();
    DeRef(_0);
    if (_2246 != 61)
        goto L8E;

    // 		return {NOTEQ, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 4;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L8E:

    // 		ungetch()
    _12ungetch();

    // 		return {BANG, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
L8F:
    goto L1;
L8D:

    // 	elsif class = KEYWORD then
    if (_class != -10)
        goto L90;

    // 	    return {keylist[ch - KEYWORD_BASE][K_TOKEN], 0}
    DeRef(_2246);
    _2246 = _ch - 128;
    _2 = (int)SEQ_PTR(_10keylist);
    _2246 = (int)*(((s1_ptr)_2)->base + _2246);
    RefDS(_2246);
    _0 = _2246;
    _2 = (int)SEQ_PTR(_2246);
    _2246 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2246);
    DeRefDS(_0);
    _0 = _2246;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _2246;
    Ref(_2246);
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L90:

    // 	elsif class = BUILTIN then
    if (_class != -9)
        goto L91;

    // 	    name = keylist[ch - BUILTIN_BASE + NUM_KEYWORDS][K_NAME]
    DeRef(_2246);
    _2246 = _ch - 170;
    if ((long)((unsigned long)_2246 +(unsigned long) HIGH_BITS) >= 0)
        _2246 = NewDouble((double)_2246);
    _0 = _2246;
    if (IS_ATOM_INT(_2246)) {
        _2246 = _2246 + 24;
    }
    else {
        _2246 = NewDouble(DBL_PTR(_2246)->dbl + (double)24);
    }
    DeRef(_0);
    _0 = _2246;
    _2 = (int)SEQ_PTR(_10keylist);
    if (!IS_ATOM_INT(_2246))
        _2246 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2246)->dbl));
    else
        _2246 = (int)*(((s1_ptr)_2)->base + _2246);
    RefDS(_2246);
    DeRef(_0);
    DeRef(_name);
    _2 = (int)SEQ_PTR(_2246);
    _name = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_name);

    // 	    return keyfind(name, -1)
    RefDS(_name);
    _0 = _2246;
    _2246 = _11keyfind(_name, -1);
    DeRefDS(_0);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRefDS(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L91:

    // 	elsif class = COLON then
    if (_class != -23)
        goto L92;

    // 		return {COLON, 0}
    DeRef(_2246);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -23;
    ((int *)_2)[2] = 0;
    _2246 = MAKE_SEQ(_1);
    DeRef(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_2248);
    DeRef(_2228);
    return _2246;
    goto L1;
L92:

    // 	    InternalErr("Scanner()")  
    RefDS(_2505);
    _9InternalErr(_2505);
L93:

    //    end while
    goto L1;
L94:
    ;
}


