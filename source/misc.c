// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _2instance()
{
    int _11 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_INSTANCE, 0)
    _11 = machine(55, 0);
    return _11;
    ;
}


int _2sleep(int _t)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_t)) {
        _1 = (long)(DBL_PTR(_t)->dbl);
        DeRefDS(_t);
        _t = _1;
    }

    //     if t >= 0 then
    if (_t < 0)
        goto L1;

    // 	machine_proc(M_SLEEP, t)
    machine(64, _t);
L1:

    // end procedure
    return 0;
    ;
}


int _2reverse(int _s)
{
    int _lower;
    int _n;
    int _n2;
    int _t = 0;
    int _19 = 0;
    int _13;
    int _0, _1, _2;
    

    //     n = length(s)
    _n = SEQ_PTR(_s)->length;

    //     n2 = floor(n/2)+1
    _13 = _n >> 1;
    _n2 = _13 + 1;

    //     t = repeat(0, n)
    _t = Repeat(0, _n);

    //     lower = 1
    _lower = 1;

    //     for upper = n to n2 by -1 do
    _13 = _n2;
    { int _upper;
        _upper = _n;
L1:
        if (_upper < _13)
            goto L2;

        // 	t[upper] = s[lower]
        DeRef(_19);
        _2 = (int)SEQ_PTR(_s);
        _19 = (int)*(((s1_ptr)_2)->base + _lower);
        Ref(_19);
        Ref(_19);
        _2 = (int)SEQ_PTR(_t);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _t = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _upper);
        _1 = *(int *)_2;
        *(int *)_2 = _19;
        DeRef(_1);

        // 	t[lower] = s[upper]
        DeRef(_19);
        _2 = (int)SEQ_PTR(_s);
        _19 = (int)*(((s1_ptr)_2)->base + _upper);
        Ref(_19);
        Ref(_19);
        _2 = (int)SEQ_PTR(_t);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _t = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _lower);
        _1 = *(int *)_2;
        *(int *)_2 = _19;
        DeRef(_1);

        // 	lower += 1
        _lower = _lower + 1;

        //     end for
        _upper = _upper + -1;
        goto L1;
L2:
        ;
    }

    //     return t
    DeRefDS(_s);
    DeRef(_19);
    return _t;
    ;
}


int _2sprint(int _x)
{
    int _s = 0;
    int _27 = 0;
    int _22 = 0;
    int _0, _1, _2;
    

    //     if atom(x) then
    _22 = IS_ATOM(_x);
    if (_22 == 0)
        goto L1;

    // 	return sprintf("%.10g", x)
    _22 = EPrintf(-9999999, _23, _x);
    DeRef(_x);
    return _22;
    goto L2;
L1:

    // 	s = "{"
    RefDS(_25);
    DeRef(_s);
    _s = _25;

    // 	for i = 1 to length(x) do
    DeRef(_22);
    _22 = SEQ_PTR(_x)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _22)
            goto L4;

        // 	    s &= sprint(x[i])  
        DeRef(_27);
        _2 = (int)SEQ_PTR(_x);
        _27 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_27);
        Ref(_27);
        _0 = _27;
        _27 = _2sprint(_27);
        DeRef(_0);
        Concat((object_ptr)&_s, _s, (s1_ptr)_27);

        // 	    if i < length(x) then
        DeRefDS(_27);
        _27 = SEQ_PTR(_x)->length;
        if (_i >= _27)
            goto L5;

        // 		s &= ','
        Append(&_s, _s, 44);
L5:

        // 	end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    // 	s &= "}"
    Concat((object_ptr)&_s, _s, (s1_ptr)_34);

    // 	return s
    DeRef(_x);
    DeRef(_27);
    DeRef(_22);
    return _s;
L2:
    ;
}


int _2pretty_out(int _text)
{
    int _36;
    int _0, _1, _2;
    

    //     pretty_line &= text
    if (IS_SEQUENCE(_2pretty_line) && IS_ATOM(_text)) {
        Ref(_text);
        Append(&_2pretty_line, _2pretty_line, _text);
    }
    else if (IS_ATOM(_2pretty_line) && IS_SEQUENCE(_text)) {
    }
    else {
        Concat((object_ptr)&_2pretty_line, _2pretty_line, (s1_ptr)_text);
    }

    //     if equal(text, '\n') then
    if (_text == 10)
        _36 = 1;
    else if (IS_ATOM_INT(_text) && IS_ATOM_INT(10))
        _36 = 0;
    else
        _36 = (compare(_text, 10) == 0);
    if (_36 == 0)
        goto L1;

    // 	puts(pretty_file, pretty_line)
    EPuts(_2pretty_file, _2pretty_line);

    // 	pretty_line = ""
    RefDS(_39);
    DeRefDS(_2pretty_line);
    _2pretty_line = _39;

    // 	pretty_line_count += 1
    _2pretty_line_count = _2pretty_line_count + 1;
L1:

    //     if atom(text) then
    _36 = IS_ATOM(_text);
    if (_36 == 0)
        goto L2;

    // 	pretty_chars += 1
    _2pretty_chars = _2pretty_chars + 1;
    goto L3;
L2:

    // 	pretty_chars += length(text)
    _36 = SEQ_PTR(_text)->length;
    _2pretty_chars = _2pretty_chars + _36;
L3:

    // end procedure
    DeRef(_text);
    return 0;
    ;
}


int _2cut_line(int _n)
{
    int _45 = 0;
    int _0, _1, _2;
    

    //     if pretty_chars + n > pretty_end_col then
    _45 = _2pretty_chars + _n;
    if ((long)((unsigned long)_45 + (unsigned long)HIGH_BITS) >= 0) 
        _45 = NewDouble((double)_45);
    if (binary_op_a(LESSEQ, _45, _2pretty_end_col))
        goto L1;

    // 	pretty_out('\n')
    _2pretty_out(10);

    // 	pretty_chars = 0
    _2pretty_chars = 0;
L1:

    // end procedure
    DeRef(_45);
    return 0;
    ;
}


int _2indent()
{
    int _50 = 0;
    int _47 = 0;
    int _0, _1, _2;
    

    //     if pretty_chars > 0 then
    if (_2pretty_chars <= 0)
        goto L1;

    // 	pretty_out('\n')
    _2pretty_out(10);

    // 	pretty_chars = 0
    _2pretty_chars = 0;
L1:

    //     pretty_out(repeat(' ', (pretty_start_col-1) + 
    DeRef(_47);
    _47 = _2pretty_start_col - 1;
    if ((long)((unsigned long)_47 +(unsigned long) HIGH_BITS) >= 0)
        _47 = NewDouble((double)_47);
    DeRef(_50);
    if (_2pretty_level == (short)_2pretty_level && _2pretty_indent <= INT15 && _2pretty_indent >= -INT15)
        _50 = _2pretty_level * _2pretty_indent;
    else
        _50 = NewDouble(_2pretty_level * (double)_2pretty_indent);
    _0 = _50;
    if (IS_ATOM_INT(_47) && IS_ATOM_INT(_50)) {
        _50 = _47 + _50;
    }
    else {
        if (IS_ATOM_INT(_47)) {
            _50 = NewDouble((double)_47 + DBL_PTR(_50)->dbl);
        }
        else {
            if (IS_ATOM_INT(_50)) {
                _50 = NewDouble(DBL_PTR(_47)->dbl + (double)_50);
            }
            else
                _50 = NewDouble(DBL_PTR(_47)->dbl + DBL_PTR(_50)->dbl);
        }
    }
    DeRef(_0);
    _0 = _50;
    _50 = Repeat(32, _50);
    DeRef(_0);
    RefDS(_50);
    _2pretty_out(_50);

    // end procedure
    DeRefDSi(_50);
    DeRef(_47);
    return 0;
    ;
}


int _2show(int _a)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_a)) {
        _1 = (long)(DBL_PTR(_a)->dbl);
        DeRefDS(_a);
        _a = _1;
    }

    //     if a = '\t' then
    if (_a != 9)
        goto L1;

    // 	return "\\t"
    RefDS(_55);
    return _55;
    goto L2;
L1:

    //     elsif a = '\n' then
    if (_a != 10)
        goto L3;

    // 	return "\\n"
    RefDS(_57);
    return _57;
    goto L2;
L3:

    //     elsif a = '\r' then
    if (_a != 13)
        goto L4;

    // 	return "\\r"
    RefDS(_60);
    return _60;
    goto L2;
L4:

    // 	return a
    return _a;
L2:
    ;
}


int _2rPrint(int _a)
{
    int _sbuff = 0;
    int _multi_line;
    int _all_ascii;
    int _67 = 0;
    int _97 = 0;
    int _95 = 0;
    int _85 = 0;
    int _61 = 0;
    int _0, _1, _2;
    

    //     if atom(a) then
    _61 = IS_ATOM(_a);
    if (_61 == 0)
        goto L1;

    // 	if integer(a) then
    if (IS_ATOM_INT(_a))
        _61 = 1;
    else if (IS_ATOM_DBL(_a))
        _61 = IS_ATOM_INT(DoubleToInt(_a));
    else
        _61 = 0;
    if (_61 == 0)
        goto L2;

    // 	    sbuff = sprintf(pretty_int_format, a)
    _sbuff = EPrintf(-9999999, _2pretty_int_format, _a);

    // 	    if pretty_ascii then 
    if (_2pretty_ascii == 0)
        goto L3;

    // 		if pretty_ascii >= 3 then 
    if (_2pretty_ascii < 3)
        goto L4;

    // 		    if (a >= pretty_ascii_min and a <= pretty_ascii_max) then
    if (IS_ATOM_INT(_a)) {
        _61 = (_a >= _2pretty_ascii_min);
    }
    else {
        _61 = binary_op(GREATEREQ, _a, _2pretty_ascii_min);
    }
    if (IS_ATOM_INT(_61)) {
        if (_61 == 0) {
            DeRef(_61);
            _61 = 0;
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_61)->dbl == 0.0) {
            DeRef(_61);
            _61 = 0;
            goto L5;
        }
    }
    if (IS_ATOM_INT(_a)) {
        _67 = (_a <= _2pretty_ascii_max);
    }
    else {
        _67 = binary_op(LESSEQ, _a, _2pretty_ascii_max);
    }
    DeRef(_61);
    if (IS_ATOM_INT(_67))
        _61 = (_67 != 0);
    else
        _61 = DBL_PTR(_67)->dbl != 0.0;
L5:
    if (_61 == 0)
        goto L6;

    // 			sbuff = '\'' & a & '\''  -- display char only
    {
        int concat_list[3];

        concat_list[0] = 39;
        concat_list[1] = _a;
        concat_list[2] = 39;
        Concat_N((object_ptr)&_sbuff, concat_list, 3);
    }
    goto L3;
L6:

    // 		    elsif find(a, "\t\n\r") then
    DeRef(_67);
    _67 = find(_a, _70);
    if (_67 == 0)
        goto L3;

    // 			sbuff = '\'' & show(a) & '\''  -- display char only
    Ref(_a);
    _67 = _2show(_a);
    {
        int concat_list[3];

        concat_list[0] = 39;
        concat_list[1] = _67;
        concat_list[2] = 39;
        Concat_N((object_ptr)&_sbuff, concat_list, 3);
    }
L7:
L8:
    goto L3;
L4:

    // 		    if (a >= pretty_ascii_min and a <= pretty_ascii_max) then
    DeRef(_67);
    if (IS_ATOM_INT(_a)) {
        _67 = (_a >= _2pretty_ascii_min);
    }
    else {
        _67 = binary_op(GREATEREQ, _a, _2pretty_ascii_min);
    }
    if (IS_ATOM_INT(_67)) {
        if (_67 == 0) {
            DeRef(_67);
            _67 = 0;
            goto L9;
        }
    }
    else {
        if (DBL_PTR(_67)->dbl == 0.0) {
            DeRef(_67);
            _67 = 0;
            goto L9;
        }
    }
    DeRef(_61);
    if (IS_ATOM_INT(_a)) {
        _61 = (_a <= _2pretty_ascii_max);
    }
    else {
        _61 = binary_op(LESSEQ, _a, _2pretty_ascii_max);
    }
    DeRef(_67);
    if (IS_ATOM_INT(_61))
        _67 = (_61 != 0);
    else
        _67 = DBL_PTR(_61)->dbl != 0.0;
L9:
    if (_67 == 0)
        goto L3;

    // 			sbuff &= '\'' & a & '\'' -- add to numeric display
    {
        int concat_list[3];

        concat_list[0] = 39;
        concat_list[1] = _a;
        concat_list[2] = 39;
        Concat_N((object_ptr)&_61, concat_list, 3);
    }
    Concat((object_ptr)&_sbuff, _sbuff, (s1_ptr)_61);
LA:
LB:
LC:
    goto L3;
L2:

    // 	    sbuff = sprintf(pretty_fp_format, a)
    DeRef(_sbuff);
    _sbuff = EPrintf(-9999999, _2pretty_fp_format, _a);
L3:

    // 	pretty_out(sbuff)
    RefDS(_sbuff);
    _2pretty_out(_sbuff);
    goto LD;
L1:

    // 	cut_line(1)
    _2cut_line(1);

    // 	multi_line = 0
    _multi_line = 0;

    // 	all_ascii = pretty_ascii > 1
    _all_ascii = (_2pretty_ascii > 1);

    // 	for i = 1 to length(a) do
    DeRef(_61);
    _61 = SEQ_PTR(_a)->length;
    { int _i;
        _i = 1;
LE:
        if (_i > _61)
            goto LF;

        // 	    if sequence(a[i]) and length(a[i]) > 0 then
        DeRef(_67);
        _2 = (int)SEQ_PTR(_a);
        _67 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_67);
        _0 = _67;
        _67 = IS_SEQUENCE(_67);
        DeRef(_0);
        if (_67 == 0) {
            goto L10;
        }
        DeRef(_85);
        _2 = (int)SEQ_PTR(_a);
        _85 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_85);
        _0 = _85;
        _85 = SEQ_PTR(_85)->length;
        DeRef(_0);
        _85 = (_85 > 0);
L11:
        if (_85 == 0)
            goto L10;

        // 		multi_line = 1
        _multi_line = 1;

        // 		all_ascii = 0
        _all_ascii = 0;

        // 		exit
        goto LF;
L10:

        // 	    if not integer(a[i]) or
        DeRef(_85);
        _2 = (int)SEQ_PTR(_a);
        _85 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_85);
        _0 = _85;
        if (IS_ATOM_INT(_85))
            _85 = 1;
        else if (IS_ATOM_DBL(_85))
            _85 = IS_ATOM_INT(DoubleToInt(_85));
        else
            _85 = 0;
        DeRef(_0);
        _85 = (_85 == 0);
        if (_85 != 0) {
            _85 = 1;
            goto L12;
        }
        DeRef(_67);
        _2 = (int)SEQ_PTR(_a);
        _67 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_67);
        _0 = _67;
        if (IS_ATOM_INT(_67)) {
            _67 = (_67 < _2pretty_ascii_min);
        }
        else {
            _67 = binary_op(LESS, _67, _2pretty_ascii_min);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_67)) {
            if (_67 == 0) {
                DeRef(_67);
                _67 = 0;
                goto L13;
            }
        }
        else {
            if (DBL_PTR(_67)->dbl == 0.0) {
                DeRef(_67);
                _67 = 0;
                goto L13;
            }
        }
        DeRef(_95);
        _95 = (_2pretty_ascii < 3);
        if (_95 != 0) {
            _95 = 1;
            goto L14;
        }
        DeRef(_97);
        _2 = (int)SEQ_PTR(_a);
        _97 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_97);
        _0 = _97;
        _97 = find(_97, _98);
        DeRef(_0);
        _97 = (_97 == 0);
        _95 = (_97 != 0);
L14:
        DeRef(_67);
        _67 = (_95 != 0);
L13:
        DeRef(_85);
        _85 = (_67 != 0);
L12:
        if (_85 != 0) {
            goto L15;
        }
        DeRef(_95);
        _2 = (int)SEQ_PTR(_a);
        _95 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_95);
        _0 = _95;
        if (IS_ATOM_INT(_95)) {
            _95 = (_95 > _2pretty_ascii_max);
        }
        else {
            _95 = binary_op(GREATER, _95, _2pretty_ascii_max);
        }
        DeRef(_0);
L16:
        if (_95 == 0) {
            goto L17;
        }
        else {
            if (!IS_ATOM_INT(_95) && DBL_PTR(_95)->dbl == 0.0)
                goto L17;
        }
L15:

        // 		all_ascii = 0
        _all_ascii = 0;
L17:

        // 	end for
        _i = _i + 1;
        goto LE;
LF:
        ;
    }

    // 	if all_ascii then
    if (_all_ascii == 0)
        goto L18;

    // 	    pretty_out('\"')
    _2pretty_out(34);
    goto L19;
L18:

    // 	    pretty_out('{')
    _2pretty_out(123);
L19:

    // 	pretty_level += 1
    _2pretty_level = _2pretty_level + 1;

    // 	for i = 1 to length(a) do
    DeRef(_95);
    _95 = SEQ_PTR(_a)->length;
    { int _i;
        _i = 1;
L1A:
        if (_i > _95)
            goto L1B;

        // 	    if multi_line then
        if (_multi_line == 0)
            goto L1C;

        // 		indent()
        _2indent();
L1C:

        // 	    if all_ascii then
        if (_all_ascii == 0)
            goto L1D;

        // 		pretty_out(show(a[i]))
        DeRef(_97);
        _2 = (int)SEQ_PTR(_a);
        _97 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_97);
        Ref(_97);
        _0 = _97;
        _97 = _2show(_97);
        DeRef(_0);
        Ref(_97);
        _2pretty_out(_97);
        goto L1E;
L1D:

        // 		rPrint(a[i])
        DeRef(_97);
        _2 = (int)SEQ_PTR(_a);
        _97 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_97);
        Ref(_97);
        _2rPrint(_97);
L1E:

        // 	    if pretty_line_count >= pretty_line_max then
        if (_2pretty_line_count < _2pretty_line_max)
            goto L1F;

        // 		if not pretty_dots then
        if (_2pretty_dots != 0)
            goto L20;

        // 		    pretty_out(" ...")
        RefDS(_113);
        _2pretty_out(_113);
L20:

        // 		pretty_dots = 1
        _2pretty_dots = 1;

        // 		return
        DeRef(_a);
        DeRef(_sbuff);
        DeRef5(_67, _97, _95, _85, _61);
        return 0;
L1F:

        // 	    if i != length(a) and not all_ascii then
        DeRef(_97);
        _97 = SEQ_PTR(_a)->length;
        _97 = (_i != _97);
        if (_97 == 0) {
            goto L21;
        }
        DeRef(_67);
        _67 = (_all_ascii == 0);
L22:
        if (_67 == 0)
            goto L21;

        // 		pretty_out(',')
        _2pretty_out(44);

        // 		cut_line(6)
        _2cut_line(6);
L21:

        // 	end for
        _i = _i + 1;
        goto L1A;
L1B:
        ;
    }

    // 	pretty_level -= 1
    _2pretty_level = _2pretty_level - 1;

    // 	if multi_line then
    if (_multi_line == 0)
        goto L23;

    // 	    indent()
    _2indent();
L23:

    // 	if all_ascii then
    if (_all_ascii == 0)
        goto L24;

    // 	    pretty_out('\"')
    _2pretty_out(34);
    goto L25;
L24:

    // 	    pretty_out('}')
    _2pretty_out(125);
L25:
LD:

    // end procedure
    DeRef(_a);
    DeRef(_sbuff);
    DeRef5(_67, _97, _95, _85, _61);
    return 0;
    ;
}


int _2pretty_print(int _fn, int _x, int _options)
{
    int _n;
    int _124;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     pretty_ascii = 1             --[1] 
    _2pretty_ascii = 1;

    //     pretty_indent = 2            --[2]
    _2pretty_indent = 2;

    //     pretty_start_col = 1         --[3]
    _2pretty_start_col = 1;

    //     pretty_end_col = 78          --[4]
    _2pretty_end_col = 78;

    //     pretty_int_format = "%d"     --[5]
    RefDS(_122);
    DeRef(_2pretty_int_format);
    _2pretty_int_format = _122;

    //     pretty_fp_format = "%.10g"   --[6]
    RefDS(_23);
    DeRef(_2pretty_fp_format);
    _2pretty_fp_format = _23;

    //     pretty_ascii_min = 32        --[7]
    _2pretty_ascii_min = 32;

    //     pretty_ascii_max = 127       --[8] 
    _124 = (3 == 3);
    _2pretty_ascii_max = 127 - _124;

    //     pretty_line_max = 1000000000 --[9]
    _2pretty_line_max = 1000000000;

    //     n = length(options)
    _n = SEQ_PTR(_options)->length;

    //     if n >= 1 then
    if (_n < 1)
        goto L1;

    // 	pretty_ascii = options[1] 
    _2 = (int)SEQ_PTR(_options);
    _2pretty_ascii = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_2pretty_ascii))
        _2pretty_ascii = (long)DBL_PTR(_2pretty_ascii)->dbl;

    // 	if n >= 2 then
    if (_n < 2)
        goto L2;

    // 	    pretty_indent = options[2]
    _2 = (int)SEQ_PTR(_options);
    _2pretty_indent = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_2pretty_indent))
        _2pretty_indent = (long)DBL_PTR(_2pretty_indent)->dbl;

    // 	    if n >= 3 then
    if (_n < 3)
        goto L3;

    // 		pretty_start_col = options[3]
    _2 = (int)SEQ_PTR(_options);
    _2pretty_start_col = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_2pretty_start_col))
        _2pretty_start_col = (long)DBL_PTR(_2pretty_start_col)->dbl;

    // 		if n >= 4 then
    if (_n < 4)
        goto L4;

    // 		    pretty_end_col = options[4]
    _2 = (int)SEQ_PTR(_options);
    _2pretty_end_col = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_2pretty_end_col))
        _2pretty_end_col = (long)DBL_PTR(_2pretty_end_col)->dbl;

    // 		    if n >= 5 then
    if (_n < 5)
        goto L5;

    // 			pretty_int_format = options[5]
    DeRefDSi(_2pretty_int_format);
    _2 = (int)SEQ_PTR(_options);
    _2pretty_int_format = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_2pretty_int_format);

    // 			if n >= 6 then
    if (_n < 6)
        goto L6;

    // 			    pretty_fp_format = options[6]
    DeRefDSi(_2pretty_fp_format);
    _2 = (int)SEQ_PTR(_options);
    _2pretty_fp_format = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_2pretty_fp_format);

    // 			    if n >= 7 then
    if (_n < 7)
        goto L7;

    // 				pretty_ascii_min = options[7]
    _2 = (int)SEQ_PTR(_options);
    _2pretty_ascii_min = (int)*(((s1_ptr)_2)->base + 7);
    if (!IS_ATOM_INT(_2pretty_ascii_min))
        _2pretty_ascii_min = (long)DBL_PTR(_2pretty_ascii_min)->dbl;

    // 				if n >= 8 then
    if (_n < 8)
        goto L8;

    // 				    pretty_ascii_max = options[8]
    _2 = (int)SEQ_PTR(_options);
    _2pretty_ascii_max = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_2pretty_ascii_max))
        _2pretty_ascii_max = (long)DBL_PTR(_2pretty_ascii_max)->dbl;

    // 				    if n >= 9 then
    if (_n < 9)
        goto L9;

    // 					pretty_line_max = options[9]
    _2 = (int)SEQ_PTR(_options);
    _2pretty_line_max = (int)*(((s1_ptr)_2)->base + 9);
    if (!IS_ATOM_INT(_2pretty_line_max))
        _2pretty_line_max = (long)DBL_PTR(_2pretty_line_max)->dbl;
L9:
L8:
L7:
L6:
L5:
L4:
L3:
L2:
L1:

    //     pretty_chars = pretty_start_col
    _2pretty_chars = _2pretty_start_col;

    //     pretty_file = fn
    _2pretty_file = _fn;

    //     pretty_level = 0 
    _2pretty_level = 0;

    //     pretty_line = ""
    RefDS(_39);
    DeRef(_2pretty_line);
    _2pretty_line = _39;

    //     pretty_line_count = 0
    _2pretty_line_count = 0;

    //     pretty_dots = 0
    _2pretty_dots = 0;

    //     rPrint(x)
    Ref(_x);
    _2rPrint(_x);

    //     puts(pretty_file, pretty_line)
    EPuts(_2pretty_file, _2pretty_line);

    // end procedure
    DeRef(_x);
    DeRefDS(_options);
    return 0;
    ;
}


int _2arccos(int _x)
{
    int _162 = 0;
    int _0, _1, _2;
    

    //     return PI_HALF - 2 * arctan(x / (1.0 + sqrt(1.0 - x * x)))
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_x)) {
        if (_x == (short)_x && _x <= INT15 && _x >= -INT15)
            _162 = _x * _x;
        else
            _162 = NewDouble(_x * (double)_x);
    }
    else {
        _162 = binary_op(MULTIPLY, _x, _x);
    }
    _0 = _162;
    _162 = binary_op(MINUS, _161, _162);
    DeRef(_0);
    _0 = _162;
    if (IS_ATOM_INT(_162))
        _162 = e_sqrt(_162);
    else
        _162 = unary_op(SQRT, _162);
    DeRef(_0);
    _0 = _162;
    _162 = binary_op(PLUS, _161, _162);
    DeRef(_0);
    _0 = _162;
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_162)) {
        _162 = (_x % _162) ? NewDouble((double)_x / _162) : (_x / _162);
    }
    else {
        _162 = binary_op(DIVIDE, _x, _162);
    }
    DeRef(_0);
    _0 = _162;
    if (IS_ATOM_INT(_162))
        _162 = e_arctan(_162);
    else
        _162 = unary_op(ARCTAN, _162);
    DeRef(_0);
    _0 = _162;
    if (IS_ATOM_INT(_162) && IS_ATOM_INT(_162)) {
        _162 = _162 + _162;
        if ((long)((unsigned long)_162 + (unsigned long)HIGH_BITS) >= 0) 
            _162 = NewDouble((double)_162);
    }
    else {
        _162 = binary_op(PLUS, _162, _162);
    }
    DeRef(_0);
    _0 = _162;
    _162 = binary_op(MINUS, _2PI_HALF, _162);
    DeRef(_0);
    DeRef(_x);
    return _162;
    ;
}


int _2arcsin(int _x)
{
    int _170 = 0;
    int _0, _1, _2;
    

    //     return 2 * arctan(x / (1.0 + sqrt(1.0 - x * x)))
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_x)) {
        if (_x == (short)_x && _x <= INT15 && _x >= -INT15)
            _170 = _x * _x;
        else
            _170 = NewDouble(_x * (double)_x);
    }
    else {
        _170 = binary_op(MULTIPLY, _x, _x);
    }
    _0 = _170;
    _170 = binary_op(MINUS, _161, _170);
    DeRef(_0);
    _0 = _170;
    if (IS_ATOM_INT(_170))
        _170 = e_sqrt(_170);
    else
        _170 = unary_op(SQRT, _170);
    DeRef(_0);
    _0 = _170;
    _170 = binary_op(PLUS, _161, _170);
    DeRef(_0);
    _0 = _170;
    if (IS_ATOM_INT(_x) && IS_ATOM_INT(_170)) {
        _170 = (_x % _170) ? NewDouble((double)_x / _170) : (_x / _170);
    }
    else {
        _170 = binary_op(DIVIDE, _x, _170);
    }
    DeRef(_0);
    _0 = _170;
    if (IS_ATOM_INT(_170))
        _170 = e_arctan(_170);
    else
        _170 = unary_op(ARCTAN, _170);
    DeRef(_0);
    _0 = _170;
    if (IS_ATOM_INT(_170) && IS_ATOM_INT(_170)) {
        _170 = _170 + _170;
        if ((long)((unsigned long)_170 + (unsigned long)HIGH_BITS) >= 0) 
            _170 = NewDouble((double)_170);
    }
    else {
        _170 = binary_op(PLUS, _170, _170);
    }
    DeRef(_0);
    DeRef(_x);
    return _170;
    ;
}


