// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _22ProcessOptions()
{
    int _src_file;
    int _dot_found;
    int _src_name = 0;
    int _raw_name = 0;
    int _10575 = 0;
    int _10570 = 0;
    int _0, _1, _2;
    

    //     if Argc >= 3 then
    if (_7Argc < 3)
        goto L1;

    // 	if equal( Argv[3], "-s" ) then
    _2 = (int)SEQ_PTR(_7Argv);
    _10570 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_10570);
    _0 = _10570;
    if (_10570 == _10572)
        _10570 = 1;
    else if (IS_ATOM_INT(_10570) && IS_ATOM_INT(_10572))
        _10570 = 0;
    else
        _10570 = (compare(_10570, _10572) == 0);
    DeRef(_0);
    if (_10570 == 0)
        goto L2;

    // 		execute = 0
    _7execute = 0;

    // 		Argv = Argv[1..2] & Argv[4..$]
    rhs_slice_target = (object_ptr)&_10570;
    RHS_Slice((s1_ptr)_7Argv, 1, 2);
    _10575 = SEQ_PTR(_7Argv)->length;
    rhs_slice_target = (object_ptr)&_10575;
    RHS_Slice((s1_ptr)_7Argv, 4, _10575);
    Concat((object_ptr)&_7Argv, _10570, (s1_ptr)_10575);

    // 		Argc -= 1
    _7Argc = _7Argc - 1;
    goto L3;
L2:

    // 	elsif equal( Argv[3], "-b" ) then
    DeRef(_10575);
    _2 = (int)SEQ_PTR(_7Argv);
    _10575 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_10575);
    _0 = _10575;
    if (_10575 == _10580)
        _10575 = 1;
    else if (IS_ATOM_INT(_10575) && IS_ATOM_INT(_10580))
        _10575 = 0;
    else
        _10575 = (compare(_10575, _10580) == 0);
    DeRef(_0);
    if (_10575 == 0)
        goto L4;

    // 		execute = 0
    _7execute = 0;

    // 		bind = 1
    _7bind = 1;

    // 		Argv = Argv[1..2] & Argv[4..$]
    rhs_slice_target = (object_ptr)&_10575;
    RHS_Slice((s1_ptr)_7Argv, 1, 2);
    DeRef(_10570);
    _10570 = SEQ_PTR(_7Argv)->length;
    rhs_slice_target = (object_ptr)&_10570;
    RHS_Slice((s1_ptr)_7Argv, 4, _10570);
    Concat((object_ptr)&_7Argv, _10575, (s1_ptr)_10570);

    // 		Argc -= 1
    _7Argc = _7Argc - 1;
    goto L3;
L4:

    // 	elsif equal( Argv[3], "-p" ) then
    DeRef(_10570);
    _2 = (int)SEQ_PTR(_7Argv);
    _10570 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_10570);
    _0 = _10570;
    if (_10570 == _10588)
        _10570 = 1;
    else if (IS_ATOM_INT(_10570) && IS_ATOM_INT(_10588))
        _10570 = 0;
    else
        _10570 = (compare(_10570, _10588) == 0);
    DeRef(_0);
    if (_10570 == 0)
        goto L5;

    // 		execute = 0
    _7execute = 0;

    // 		preprocess = 1
    _7preprocess = 1;

    // 		Argv = Argv[1..2] & Argv[4..$]
    rhs_slice_target = (object_ptr)&_10570;
    RHS_Slice((s1_ptr)_7Argv, 1, 2);
    DeRef(_10575);
    _10575 = SEQ_PTR(_7Argv)->length;
    rhs_slice_target = (object_ptr)&_10575;
    RHS_Slice((s1_ptr)_7Argv, 4, _10575);
    Concat((object_ptr)&_7Argv, _10570, (s1_ptr)_10575);

    // 		Argc -= 1
    _7Argc = _7Argc - 1;
    goto L3;
L5:

    // 	elsif equal( Argv[3], "-c" ) then
    DeRef(_10575);
    _2 = (int)SEQ_PTR(_7Argv);
    _10575 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_10575);
    _0 = _10575;
    if (_10575 == _10596)
        _10575 = 1;
    else if (IS_ATOM_INT(_10575) && IS_ATOM_INT(_10596))
        _10575 = 0;
    else
        _10575 = (compare(_10575, _10596) == 0);
    DeRef(_0);
    if (_10575 == 0)
        goto L6;

    // 		execute = 0
    _7execute = 0;

    // 		delete_symbols = 0
    _7delete_symbols = 0;

    // 		Argv = Argv[1..2] & Argv[4..$]
    rhs_slice_target = (object_ptr)&_10575;
    RHS_Slice((s1_ptr)_7Argv, 1, 2);
    DeRef(_10570);
    _10570 = SEQ_PTR(_7Argv)->length;
    rhs_slice_target = (object_ptr)&_10570;
    RHS_Slice((s1_ptr)_7Argv, 4, _10570);
    Concat((object_ptr)&_7Argv, _10575, (s1_ptr)_10570);

    // 		Argc -= 1	
    _7Argc = _7Argc - 1;

    // 		full_debug = 1	
    _7full_debug = 1;
L6:
L3:

    // 	if not execute then
    if (_7execute != 0)
        goto L7;

    // 	if equal( Argv[3], "-full_debug" ) then
    DeRef(_10570);
    _2 = (int)SEQ_PTR(_7Argv);
    _10570 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_10570);
    _0 = _10570;
    if (_10570 == _10605)
        _10570 = 1;
    else if (IS_ATOM_INT(_10570) && IS_ATOM_INT(_10605))
        _10570 = 0;
    else
        _10570 = (compare(_10570, _10605) == 0);
    DeRef(_0);
    if (_10570 == 0)
        goto L8;

    // 		full_debug = 1
    _7full_debug = 1;

    // 		Argv = Argv[1..2] & Argv[4..$]
    rhs_slice_target = (object_ptr)&_10570;
    RHS_Slice((s1_ptr)_7Argv, 1, 2);
    DeRef(_10575);
    _10575 = SEQ_PTR(_7Argv)->length;
    rhs_slice_target = (object_ptr)&_10575;
    RHS_Slice((s1_ptr)_7Argv, 4, _10575);
    Concat((object_ptr)&_7Argv, _10570, (s1_ptr)_10575);

    // 		Argc -= 1
    _7Argc = _7Argc - 1;
L9:
    goto L8;
L7:

    // 		full_debug = 1
    _7full_debug = 1;
L8:
L1:

    //     while Argc > 3 and equal( Argv[3], "-i" ) do
LA:
    DeRef(_10575);
    _10575 = (_7Argc > 3);
    if (_10575 == 0) {
        goto LB;
    }
    DeRef(_10570);
    _2 = (int)SEQ_PTR(_7Argv);
    _10570 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_10570);
    _0 = _10570;
    if (_10570 == _10615)
        _10570 = 1;
    else if (IS_ATOM_INT(_10570) && IS_ATOM_INT(_10615))
        _10570 = 0;
    else
        _10570 = (compare(_10570, _10615) == 0);
    DeRef(_0);
LC:
    if (_10570 == 0)
        goto LB;

    //     	precompiled = append( precompiled, Argv[4] )
    DeRef(_10570);
    _2 = (int)SEQ_PTR(_7Argv);
    _10570 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_10570);
    Ref(_10570);
    Append(&_7precompiled, _7precompiled, _10570);

    //     	Argv = Argv[1..2] & Argv[5..$]
    rhs_slice_target = (object_ptr)&_10570;
    RHS_Slice((s1_ptr)_7Argv, 1, 2);
    DeRef(_10575);
    _10575 = SEQ_PTR(_7Argv)->length;
    rhs_slice_target = (object_ptr)&_10575;
    RHS_Slice((s1_ptr)_7Argv, 5, _10575);
    Concat((object_ptr)&_7Argv, _10570, (s1_ptr)_10575);

    //     	Argc -= 2
    _7Argc = _7Argc - 2;

    //     end while
    goto LA;
LB:

    //     if Argc >= 3 then
    if (_7Argc < 3)
        goto LD;

    // 		src_name = Argv[3]
    DeRef(_src_name);
    _2 = (int)SEQ_PTR(_7Argv);
    _src_name = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_src_name);
    goto LE;
LD:

    // 		screen_output(STDERR, sprintf("Object Oriented Euphoria v%d.%d.%d\n", OOEU_VERSION ) )
    DeRef(_10575);
    _10575 = EPrintf(-9999999, _10626, _7OOEU_VERSION);
    RefDS(_10575);
    _9screen_output(2, _10575);

    // 		if INTERPRET and not BIND then
    if (1 == 0) {
        goto LF;
    }
    DeRef(_10570);
    _10570 = (0 == 0);
L10:
    if (_10570 == 0)
        goto LF;

    // 		    screen_output(STDERR, "Based on Euphoria Interpreter " & 
    {
        int concat_list[3];

        concat_list[0] = _10631;
        concat_list[1] = _7INTERPRETER_VERSION;
        concat_list[2] = _10630;
        Concat_N((object_ptr)&_10570, concat_list, 3);
    }
    RefDS(_10570);
    _9screen_output(2, _10570);
LF:

    // 		if ELINUX then
    if (_7ELINUX == 0)
        goto L11;

    // 		    if EBSD then

    // 			screen_output(STDERR, "for Linux.\n")
    RefDS(_10634);
    _9screen_output(2, _10634);
L12:
    goto L13;
L11:

    // 		    if (BIND and w32) or EWINDOWS then
    if (0 == 0) {
        DeRef(_10570);
        _10570 = 0;
        goto L14;
    }
    _10570 = (_7w32 != 0);
L14:
    if (_10570 != 0) {
        goto L15;
    }
L16:
    if (_7EWINDOWS == 0)
        goto L17;
L15:

    // 			screen_output(STDERR, "for 32-bit Windows.\n")
    RefDS(_10637);
    _9screen_output(2, _10637);
    goto L18;
L17:

    // 			screen_output(STDERR, "for 32-bit DOS.\n")
    RefDS(_10638);
    _9screen_output(2, _10638);
L18:
L13:

    // 	     screen_output(STDERR, 
    RefDS(_10639);
    _9screen_output(2, _10639);

    // 	     screen_output(STDERR, 
    RefDS(_10640);
    _9screen_output(2, _10640);

    // 	     screen_output(STDERR, 
    RefDS(_10641);
    _9screen_output(2, _10641);

    // 	     screen_output(STDERR,
    RefDS(_10642);
    _9screen_output(2, _10642);

    // 		    screen_output(STDERR, "\nfile name to execute? ")
    RefDS(_10643);
    _9screen_output(2, _10643);

    // 		src_name = gets(STDIN)
    DeRef(_src_name);
    _src_name = EGets(0);

    // 		screen_output(STDERR, "\n")
    RefDS(_738);
    _9screen_output(2, _738);

    // 	while length(src_name) and find(src_name[1], " \t\n") do
L19:
    DeRef(_10570);
    _10570 = SEQ_PTR(_src_name)->length;
    if (_10570 == 0) {
        goto L1A;
    }
    DeRef(_10575);
    _2 = (int)SEQ_PTR(_src_name);
    _10575 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10575);
    _0 = _10575;
    _10575 = find(_10575, _10648);
    DeRef(_0);
L1B:
    if (_10575 == 0)
        goto L1A;

    // 	    src_name = src_name[2..$]
    DeRef(_10575);
    _10575 = SEQ_PTR(_src_name)->length;
    rhs_slice_target = (object_ptr)&_src_name;
    RHS_Slice((s1_ptr)_src_name, 2, _10575);

    // 	end while
    goto L19;
L1A:

    // 	if length(src_name) = 0 then
    DeRef(_10575);
    _10575 = SEQ_PTR(_src_name)->length;
    if (_10575 != 0)
        goto L1C;

    // 	    Cleanup(1)
    _9Cleanup(1);
L1C:

    // 	while length(src_name) and find(src_name[$], " \t\n") do
L1D:
    DeRef(_10575);
    _10575 = SEQ_PTR(_src_name)->length;
    if (_10575 == 0) {
        goto L1E;
    }
    DeRef(_10570);
    _10570 = SEQ_PTR(_src_name)->length;
    _2 = (int)SEQ_PTR(_src_name);
    _10570 = (int)*(((s1_ptr)_2)->base + _10570);
    Ref(_10570);
    _0 = _10570;
    _10570 = find(_10570, _10648);
    DeRef(_0);
L1F:
    if (_10570 == 0)
        goto L1E;

    // 	    src_name = src_name[1..$-1]
    DeRef(_10570);
    _10570 = SEQ_PTR(_src_name)->length;
    _10570 = _10570 - 1;
    rhs_slice_target = (object_ptr)&_src_name;
    RHS_Slice((s1_ptr)_src_name, 1, _10570);

    // 	end while
    goto L1D;
L1E:

    // 	Argc = 2
    _7Argc = 2;

    // 	Argv = {Argv[1], src_name}
    DeRef(_10570);
    _2 = (int)SEQ_PTR(_7Argv);
    _10570 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10570);
    DeRefDS(_7Argv);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10570;
    Ref(_10570);
    ((int *)_2)[2] = _src_name;
    RefDS(_src_name);
    _7Argv = MAKE_SEQ(_1);
LE:

    //     dot_found = FALSE
    _dot_found = 0;

    //     for p = 1 to length(src_name) do
    DeRef(_10570);
    _10570 = SEQ_PTR(_src_name)->length;
    { int _p;
        _p = 1;
L20:
        if (_p > _10570)
            goto L21;

        // 	if src_name[p] = '.' then
        DeRef(_10575);
        _2 = (int)SEQ_PTR(_src_name);
        _10575 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_10575);
        if (binary_op_a(NOTEQ, _10575, 46))
            goto L22;

        // 	   dot_found = TRUE
        _dot_found = 1;
        goto L23;
L22:

        // 	elsif find(src_name[p], SLASH_CHARS) then
        DeRef(_10575);
        _2 = (int)SEQ_PTR(_src_name);
        _10575 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_10575);
        _0 = _10575;
        _10575 = find(_10575, _7SLASH_CHARS);
        DeRef(_0);
        if (_10575 == 0)
            goto L24;

        // 	   dot_found = FALSE
        _dot_found = 0;
L24:
L23:

        //     end for 
        _p = _p + 1;
        goto L20;
L21:
        ;
    }

    //     raw_name = src_name
    RefDS(_src_name);
    DeRef(_raw_name);
    _raw_name = _src_name;

    //     if not dot_found then
    if (_dot_found != 0)
        goto L25;

    // 	if ELINUX then
    if (_7ELINUX == 0)
        goto L26;

    // 	    src_name &= ".exu"
    Concat((object_ptr)&_src_name, _src_name, (s1_ptr)_10670);
    goto L27;
L26:

    // 	    if (BIND and w32) or EWINDOWS then
    if (0 == 0) {
        DeRef(_10575);
        _10575 = 0;
        goto L28;
    }
    _10575 = (_7w32 != 0);
L28:
    if (_10575 != 0) {
        goto L29;
    }
L2A:
    if (_7EWINDOWS == 0)
        goto L2B;
L29:

    // 		src_name &= ".exw"
    Concat((object_ptr)&_src_name, _src_name, (s1_ptr)_10674);
    goto L2C;
L2B:

    // 		src_name &= ".ex"
    Concat((object_ptr)&_src_name, _src_name, (s1_ptr)_10676);
L2C:
L27:
L25:

    //     file_name = append(file_name, src_name)
    RefDS(_src_name);
    Append(&_7file_name, _7file_name, _src_name);

    //     src_file = e_path_open(src_name, "r")
    RefDS(_src_name);
    RefDS(_10679);
    _src_file = _23e_path_open(_src_name, _10679);

    //     if ELINUX then
    if (_7ELINUX == 0)
        goto L2D;

    // 	if src_file = -1 then
    if (_src_file != -1)
        goto L2E;

    // 	    src_file = open(raw_name, "r")      
    _src_file = EOpen(_raw_name, _10679);

    // 	    if src_file != -1 then
    if (_src_file == -1)
        goto L2F;

    // 		src_name = raw_name
    RefDS(_raw_name);
    DeRefDS(_src_name);
    _src_name = _raw_name;
L2F:
L2E:
L2D:

    // 	source_name = src_name
    RefDS(_src_name);
    DeRef(_7source_name);
    _7source_name = _src_name;

    //     return src_file
    DeRefDS(_src_name);
    DeRef(_raw_name);
    DeRef(_10575);
    DeRef(_10570);
    return _src_file;
    ;
}


int _22full_path(int _filename)
{
    int _p;
    int _10684 = 0;
    int _0, _1, _2;
    

    //     p = length(filename)
    _p = SEQ_PTR(_filename)->length;

    //     while p >= 1 do
L1:
    if (_p < 1)
        goto L2;

    // 	if find(filename[p], SLASH_CHARS) then
    DeRef(_10684);
    _2 = (int)SEQ_PTR(_filename);
    _10684 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_10684);
    _0 = _10684;
    _10684 = find(_10684, _7SLASH_CHARS);
    DeRef(_0);
    if (_10684 == 0)
        goto L3;

    // 	    return filename[1..p]
    rhs_slice_target = (object_ptr)&_10684;
    RHS_Slice((s1_ptr)_filename, 1, _p);
    DeRefDS(_filename);
    return _10684;
L3:

    // 	p -= 1
    _p = _p - 1;

    //     end while
    goto L1;
L2:

    // 	return current_dir() & SLASH
    _0 = _10684;
    _10684 = _13current_dir();
    DeRef(_0);
    Append(&_10684, _10684, _7SLASH);
    DeRefDS(_filename);
    return _10684;
    ;
}


int _22deref(int _sym)
{
    int _refs = 0;
    int _ref;
    int _10708 = 0;
    int _10692 = 0;
    int _10696 = 0;
    int _0, _1, _2, _3;
    

    // 	if length(SymTab[sym]) < S_REFLIST or atom( SymTab[sym][S_REFLIST] ) then
    _2 = (int)SEQ_PTR(_7SymTab);
    _10692 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10692);
    _0 = _10692;
    _10692 = SEQ_PTR(_10692)->length;
    DeRef(_0);
    _10692 = (_10692 < 22);
    if (_10692 != 0) {
        goto L1;
    }
    _2 = (int)SEQ_PTR(_7SymTab);
    _10696 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10696);
    _0 = _10696;
    _2 = (int)SEQ_PTR(_10696);
    _10696 = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_10696);
    DeRef(_0);
    _0 = _10696;
    _10696 = IS_ATOM(_10696);
    DeRef(_0);
L2:
    if (_10696 == 0)
        goto L3;
L1:

    // 		return
    DeRef(_refs);
    DeRef(_10708);
    DeRef(_10692);
    DeRef(_10696);
    return 0;
L3:

    // 	refs = SymTab[sym][S_REFLIST]
    DeRef(_10696);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10696 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10696);
    DeRef(_refs);
    _2 = (int)SEQ_PTR(_10696);
    _refs = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_refs);

    // 	for i = 1 to length(refs) do
    DeRef(_10696);
    _10696 = SEQ_PTR(_refs)->length;
    { int _i;
        _i = 1;
L4:
        if (_i > _10696)
            goto L5;

        // 		ref = refs[i]
        _2 = (int)SEQ_PTR(_refs);
        _ref = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_ref))
            _ref = (long)DBL_PTR(_ref)->dbl;

        // 		if length(SymTab[ref]) >= S_NREFS then
        DeRef(_10692);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10692 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10692);
        _0 = _10692;
        _10692 = SEQ_PTR(_10692)->length;
        DeRef(_0);
        if (_10692 < 11)
            goto L6;

        // 			SymTab[ref][S_NREFS] += 1
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_ref + ((s1_ptr)_2)->base);
        DeRef(_10708);
        _2 = (int)SEQ_PTR(*(int *)_3);
        _10708 = (int)*(((s1_ptr)_2)->base + 11);
        Ref(_10708);
        _0 = _10708;
        if (IS_ATOM_INT(_10708)) {
            _10708 = _10708 + 1;
            if (_10708 > MAXINT)
                _10708 = NewDouble((double)_10708);
        }
        else
            _10708 = binary_op(PLUS, 1, _10708);
        DeRef(_0);
        Ref(_10708);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 11);
        _1 = *(int *)_2;
        *(int *)_2 = _10708;
        DeRef(_1);

        // 			deref( ref )
        DeRef(_10708);
        _10708 = _ref;
        _22deref(_10708);
L6:

        // 	end for
        _i = _i + 1;
        goto L4;
L5:
        ;
    }

    // end procedure
    DeRef(_refs);
    DeRef(_10708);
    DeRef(_10692);
    DeRef(_10696);
    return 0;
    ;
}


int _22patch_next(int _sym)
{
    int _10724 = 0;
    int _10715 = 0;
    int _10719 = 0;
    int _10711 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	if length( SymTab[sym] ) < S_NEXT then
    _2 = (int)SEQ_PTR(_7SymTab);
    _10711 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10711);
    _0 = _10711;
    _10711 = SEQ_PTR(_10711)->length;
    DeRef(_0);
    if (_10711 >= 2)
        goto L1;

    // 		return
    return 0;
L1:

    // 	for s = TopLevelSub to length(SymTab) do
    DeRef(_10711);
    _10711 = SEQ_PTR(_7SymTab)->length;
    { int _s;
        _s = _7TopLevelSub;
L2:
        if (_s > _10711)
            goto L3;

        // 		if length(SymTab[s]) >= S_NEXT and SymTab[s][S_NEXT] = sym then
        DeRef(_10715);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10715 = (int)*(((s1_ptr)_2)->base + _s);
        Ref(_10715);
        _0 = _10715;
        _10715 = SEQ_PTR(_10715)->length;
        DeRef(_0);
        _10715 = (_10715 >= 2);
        if (_10715 == 0) {
            goto L4;
        }
        DeRef(_10719);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10719 = (int)*(((s1_ptr)_2)->base + _s);
        Ref(_10719);
        _0 = _10719;
        _2 = (int)SEQ_PTR(_10719);
        _10719 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10719);
        DeRef(_0);
        _0 = _10719;
        if (IS_ATOM_INT(_10719)) {
            _10719 = (_10719 == _sym);
        }
        else {
            _10719 = binary_op(EQUALS, _10719, _sym);
        }
        DeRef(_0);
L5:
        if (_10719 == 0) {
            goto L4;
        }
        else {
            if (!IS_ATOM_INT(_10719) && DBL_PTR(_10719)->dbl == 0.0)
                goto L4;
        }

        // 			SymTab[s][S_NEXT] = SymTab[sym][S_NEXT]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_s + ((s1_ptr)_2)->base);
        DeRef(_10724);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10724 = (int)*(((s1_ptr)_2)->base + _sym);
        Ref(_10724);
        _0 = _10724;
        _2 = (int)SEQ_PTR(_10724);
        _10724 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10724);
        DeRef(_0);
        Ref(_10724);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 2);
        _1 = *(int *)_2;
        *(int *)_2 = _10724;
        DeRef(_1);

        // 			exit
        goto L3;
L4:

        // 	end for
        _s = _s + 1;
        goto L2;
L3:
        ;
    }

    // end procedure
    DeRef(_10724);
    DeRef(_10715);
    DeRef(_10719);
    DeRef(_10711);
    return 0;
    ;
}


int _22record_deleted(int _sym)
{
    int _10726 = 0;
    int _10730 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	if length(SymTab[sym]) < S_NAME or sym < TopLevelSub then
    _2 = (int)SEQ_PTR(_7SymTab);
    _10726 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10726);
    _0 = _10726;
    _10726 = SEQ_PTR(_10726)->length;
    DeRef(_0);
    _10726 = (_10726 < 7);
    if (_10726 != 0) {
        goto L1;
    }
    _10730 = (_sym < _7TopLevelSub);
L2:
    if (_10730 == 0)
        goto L3;
L1:

    // 		return
    DeRef(_10726);
    DeRef(_10730);
    return 0;
L3:

    // 	printf( oe_deleted, "%s: %s\n", {file_name[SymTab[sym][S_FILE_NO]], SymTab[sym][S_NAME]})
    DeRef(_10730);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10730 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10730);
    _0 = _10730;
    _2 = (int)SEQ_PTR(_10730);
    _10730 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_10730);
    DeRef(_0);
    _0 = _10730;
    _2 = (int)SEQ_PTR(_7file_name);
    if (!IS_ATOM_INT(_10730))
        _10730 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_10730)->dbl));
    else
        _10730 = (int)*(((s1_ptr)_2)->base + _10730);
    Ref(_10730);
    DeRef(_0);
    DeRef(_10726);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10726 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10726);
    _0 = _10726;
    _2 = (int)SEQ_PTR(_10726);
    _10726 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_10726);
    DeRef(_0);
    _0 = _10726;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10730;
    Ref(_10730);
    ((int *)_2)[2] = _10726;
    Ref(_10726);
    _10726 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_22oe_deleted, _10731, _10726);

    // end procedure
    DeRefDS(_10726);
    DeRef(_10730);
    return 0;
    ;
}


int _22delete_refs(int _sym)
{
    int _refs = 0;
    int _ref;
    int _10746 = 0;
    int _10738 = 0;
    int _10751 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	if length(SymTab[sym]) = 1 then
    _2 = (int)SEQ_PTR(_7SymTab);
    _10738 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10738);
    _0 = _10738;
    _10738 = SEQ_PTR(_10738)->length;
    DeRef(_0);
    if (_10738 != 1)
        goto L1;

    // 		return
    return 0;
    goto L2;
L1:

    // 	elsif atom(SymTab[sym][S_REFLIST]) then
    DeRef(_10738);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10738 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10738);
    _0 = _10738;
    _2 = (int)SEQ_PTR(_10738);
    _10738 = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_10738);
    DeRef(_0);
    _0 = _10738;
    _10738 = IS_ATOM(_10738);
    DeRef(_0);
    if (_10738 == 0)
        goto L3;

    // 		if not eval_used or
    _10738 = (_7eval_used == 0);
    if (_10738 != 0) {
        goto L4;
    }
    DeRef(_10746);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10746 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10746);
    _0 = _10746;
    _2 = (int)SEQ_PTR(_10746);
    _10746 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_10746);
    DeRef(_0);
    _0 = _10746;
    _2 = (int)SEQ_PTR(_7file_eval);
    if (!IS_ATOM_INT(_10746))
        _10746 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_10746)->dbl));
    else
        _10746 = (int)*(((s1_ptr)_2)->base + _10746);
    DeRef(_0);
    _10746 = (_10746 == 0);
    if (_10746 != 0) {
        _10746 = 1;
        goto L5;
    }
    DeRef(_10751);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10751 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10751);
    _0 = _10751;
    _2 = (int)SEQ_PTR(_10751);
    _10751 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_10751);
    DeRef(_0);
    _0 = _10751;
    if (IS_ATOM_INT(_10751)) {
        _10751 = (_10751 == 6);
    }
    else {
        _10751 = binary_op(EQUALS, _10751, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_10751))
        _10746 = (_10751 != 0);
    else
        _10746 = DBL_PTR(_10751)->dbl != 0.0;
L5:
L6:
    if (_10746 == 0)
        goto L7;
L4:

    // 			record_deleted( sym )
    _22record_deleted(_sym);

    // 			patch_next( sym )
    _22patch_next(_sym);

    // 			SymTab[sym] = {0}
    _0 = _10751;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _10751 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_10751);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _sym);
    _1 = *(int *)_2;
    *(int *)_2 = _10751;
    DeRef(_1);
L7:

    // 		return
    DeRef(_refs);
    DeRef(_10746);
    DeRef(_10738);
    DeRef(_10751);
    return 0;
L3:
L2:

    // 	refs = SymTab[sym][S_REFLIST]
    DeRef(_10751);
    _2 = (int)SEQ_PTR(_7SymTab);
    _10751 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_10751);
    DeRef(_refs);
    _2 = (int)SEQ_PTR(_10751);
    _refs = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_refs);

    // 	for i = 1 to length(refs) do
    DeRef(_10751);
    _10751 = SEQ_PTR(_refs)->length;
    { int _i;
        _i = 1;
L8:
        if (_i > _10751)
            goto L9;

        // 		ref = refs[i]
        _2 = (int)SEQ_PTR(_refs);
        _ref = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_ref))
            _ref = (long)DBL_PTR(_ref)->dbl;

        // 		if length(SymTab[ref]) >= S_NREFS then
        DeRef(_10746);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10746 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10746);
        _0 = _10746;
        _10746 = SEQ_PTR(_10746)->length;
        DeRef(_0);
        if (_10746 < 11)
            goto LA;

        // 			if not SymTab[ref][S_NREFS] then
        _2 = (int)SEQ_PTR(_7SymTab);
        _10746 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10746);
        _0 = _10746;
        _2 = (int)SEQ_PTR(_10746);
        _10746 = (int)*(((s1_ptr)_2)->base + 11);
        Ref(_10746);
        DeRef(_0);
        if (IS_ATOM_INT(_10746)) {
            if (_10746 != 0)
                goto LB;
        }
        else {
            if (DBL_PTR(_10746)->dbl != 0.0)
                goto LB;
        }

        // 				if length(SymTab[ref]) = SIZEOF_ROUTINE_ENTRY then
        DeRef(_10746);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10746 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10746);
        _0 = _10746;
        _10746 = SEQ_PTR(_10746)->length;
        DeRef(_0);
        if (_10746 != 25)
            goto LC;

        // 						delete_refs( ref )
        _10746 = _ref;
        _22delete_refs(_10746);
        goto LD;
LC:

        // 					if not eval_used and SymTab[ref][S_NREFS] = 0 then
        DeRef(_10746);
        _10746 = (_7eval_used == 0);
        if (_10746 == 0) {
            goto LE;
        }
        DeRef(_10738);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10738 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10738);
        _0 = _10738;
        _2 = (int)SEQ_PTR(_10738);
        _10738 = (int)*(((s1_ptr)_2)->base + 11);
        Ref(_10738);
        DeRef(_0);
        _0 = _10738;
        if (IS_ATOM_INT(_10738)) {
            _10738 = (_10738 == 0);
        }
        else {
            _10738 = binary_op(EQUALS, _10738, 0);
        }
        DeRef(_0);
LF:
        if (_10738 == 0) {
            goto LE;
        }
        else {
            if (!IS_ATOM_INT(_10738) && DBL_PTR(_10738)->dbl == 0.0)
                goto LE;
        }

        // 					if not file_eval[SymTab[ref][S_FILE_NO]] or SymTab[ref][S_SCOPE] = SC_GLOBAL then
        DeRef(_10738);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10738 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10738);
        _0 = _10738;
        _2 = (int)SEQ_PTR(_10738);
        _10738 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_10738);
        DeRef(_0);
        _0 = _10738;
        _2 = (int)SEQ_PTR(_7file_eval);
        if (!IS_ATOM_INT(_10738))
            _10738 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_10738)->dbl));
        else
            _10738 = (int)*(((s1_ptr)_2)->base + _10738);
        DeRef(_0);
        _10738 = (_10738 == 0);
        if (_10738 != 0) {
            goto L10;
        }
        DeRef(_10746);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10746 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10746);
        _0 = _10746;
        _2 = (int)SEQ_PTR(_10746);
        _10746 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_10746);
        DeRef(_0);
        _0 = _10746;
        if (IS_ATOM_INT(_10746)) {
            _10746 = (_10746 == 6);
        }
        else {
            _10746 = binary_op(EQUALS, _10746, 6);
        }
        DeRef(_0);
L11:
        if (_10746 == 0) {
            goto L12;
        }
        else {
            if (!IS_ATOM_INT(_10746) && DBL_PTR(_10746)->dbl == 0.0)
                goto L12;
        }
L10:

        // 						if SymTab[ref][S_MODE] = M_CONSTANT then
        DeRef(_10746);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10746 = (int)*(((s1_ptr)_2)->base + _ref);
        Ref(_10746);
        _0 = _10746;
        _2 = (int)SEQ_PTR(_10746);
        _10746 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10746);
        DeRef(_0);
        if (binary_op_a(NOTEQ, _10746, 2))
            goto L13;

        // 							deleted[1] += 1
        DeRef(_10746);
        _2 = (int)SEQ_PTR(_22deleted);
        _10746 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10746);
        _0 = _10746;
        if (IS_ATOM_INT(_10746)) {
            _10746 = _10746 + 1;
            if (_10746 > MAXINT)
                _10746 = NewDouble((double)_10746);
        }
        else
            _10746 = binary_op(PLUS, 1, _10746);
        DeRef(_0);
        Ref(_10746);
        _2 = (int)SEQ_PTR(_22deleted);
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _10746;
        DeRef(_1);
        goto L14;
L13:

        // 							deleted[3] += 1
        DeRef(_10746);
        _2 = (int)SEQ_PTR(_22deleted);
        _10746 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10746);
        _0 = _10746;
        if (IS_ATOM_INT(_10746)) {
            _10746 = _10746 + 1;
            if (_10746 > MAXINT)
                _10746 = NewDouble((double)_10746);
        }
        else
            _10746 = binary_op(PLUS, 1, _10746);
        DeRef(_0);
        Ref(_10746);
        _2 = (int)SEQ_PTR(_22deleted);
        _2 = (int)(((s1_ptr)_2)->base + 3);
        _1 = *(int *)_2;
        *(int *)_2 = _10746;
        DeRef(_1);
L14:

        // 						record_deleted( ref )
        _22record_deleted(_ref);

        // 						patch_next( ref )
        _22patch_next(_ref);

        // 						SymTab[ref] = {0}
        _0 = _10746;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        _10746 = MAKE_SEQ(_1);
        DeRef(_0);
        RefDS(_10746);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _ref);
        _1 = *(int *)_2;
        *(int *)_2 = _10746;
        DeRef(_1);
L12:
LE:
LD:
LB:
LA:

        // 	end for
        _i = _i + 1;
        goto L8;
L9:
        ;
    }

    // end procedure
    DeRef(_refs);
    DeRef(_10746);
    DeRef(_10738);
    DeRef(_10751);
    return 0;
    ;
}


int _22delete_unused()
{
    int _ix;
    int _len;
    int _10795 = 0;
    int _10807 = 0;
    int _10805 = 0;
    int _10790;
    int _0, _1, _2, _3;
    

    // 	if not delete_symbols then
    if (_7delete_symbols != 0)
        goto L1;

    // 		return
    return 0;
L1:

    // 	oe_deleted = open( "oe_deleted.txt", "w" )
    _22oe_deleted = EOpen(_10791, _6794);

    // 	ix = 1
    _ix = 1;

    // 	deleted = repeat( 0, 3 )
    DeRef(_22deleted);
    _22deleted = Repeat(0, 3);

    // 	SymTab[TopLevelSub][S_NREFS] = 1
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

    // 	deref( TopLevelSub )
    _22deref(_7TopLevelSub);

    // 	for i = TopLevelSub + 2 to length(SymTab) do
    DeRef(_10795);
    _10795 = _7TopLevelSub + 2;
    if ((long)((unsigned long)_10795 + (unsigned long)HIGH_BITS) >= 0) 
        _10795 = NewDouble((double)_10795);
    _10790 = SEQ_PTR(_7SymTab)->length;
    { int _i;
        Ref(_10795);
        _i = _10795;
L2:
        if (binary_op_a(GREATER, _i, _10790))
            goto L3;

        // 		len = length(SymTab[i])
        DeRef(_10795);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10795 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10795 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10795);
        _len = SEQ_PTR(_10795)->length;

        // 		if len > 1 then
        if (_len <= 1)
            goto L4;

        // 			if (SymTab[i][S_USAGE] = U_UNUSED) or
        DeRef(_10795);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10795 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10795 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10795);
        _0 = _10795;
        _2 = (int)SEQ_PTR(_10795);
        _10795 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_10795);
        DeRef(_0);
        _0 = _10795;
        if (IS_ATOM_INT(_10795)) {
            _10795 = (_10795 == 0);
        }
        else {
            _10795 = binary_op(EQUALS, _10795, 0);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_10795)) {
            if (_10795 != 0) {
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_10795)->dbl != 0.0) {
                goto L5;
            }
        }
        DeRef(_10805);
        _10805 = (_len > 5);
        if (_10805 == 0) {
            _10805 = 0;
            goto L6;
        }
        DeRef(_10807);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10807 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10807 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10807);
        _0 = _10807;
        _2 = (int)SEQ_PTR(_10807);
        _10807 = (int)*(((s1_ptr)_2)->base + 11);
        Ref(_10807);
        DeRef(_0);
        _0 = _10807;
        if (IS_ATOM_INT(_10807)) {
            _10807 = (_10807 == 0);
        }
        else {
            _10807 = binary_op(EQUALS, _10807, 0);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_10807))
            _10805 = (_10807 != 0);
        else
            _10805 = DBL_PTR(_10807)->dbl != 0.0;
L6:
L7:
        if (_10805 == 0)
            goto L8;
L5:

        // 				if SymTab[i][S_MODE] = M_CONSTANT then --and not find( '@', SymTab[i][S_NAME] ) then
        DeRef(_10807);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10807 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10807 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10807);
        _0 = _10807;
        _2 = (int)SEQ_PTR(_10807);
        _10807 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_10807);
        DeRef(_0);
        if (binary_op_a(NOTEQ, _10807, 2))
            goto L9;

        // 					deleted[1] += 1
        DeRef(_10807);
        _2 = (int)SEQ_PTR(_22deleted);
        _10807 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10807);
        _0 = _10807;
        if (IS_ATOM_INT(_10807)) {
            _10807 = _10807 + 1;
            if (_10807 > MAXINT)
                _10807 = NewDouble((double)_10807);
        }
        else
            _10807 = binary_op(PLUS, 1, _10807);
        DeRef(_0);
        Ref(_10807);
        _2 = (int)SEQ_PTR(_22deleted);
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _10807;
        DeRef(_1);

        // 					record_deleted( i )
        Ref(_i);
        _22record_deleted(_i);

        // 					patch_next( i )
        Ref(_i);
        _22patch_next(_i);

        // 					SymTab[i] = {0}						
        _0 = _10807;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        _10807 = MAKE_SEQ(_1);
        DeRef(_0);
        RefDS(_10807);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_i))
            _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _10807;
        DeRef(_1);
        goto LA;
L9:

        // 				elsif length(SymTab[i]) = SIZEOF_ROUTINE_ENTRY and not SymTab[i][S_NREFS]
        DeRef(_10807);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10807 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10807 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10807);
        _0 = _10807;
        _10807 = SEQ_PTR(_10807)->length;
        DeRef(_0);
        _10807 = (_10807 == 25);
        if (_10807 == 0) {
            goto LB;
        }
        DeRef(_10805);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10805 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10805 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10805);
        _0 = _10805;
        _2 = (int)SEQ_PTR(_10805);
        _10805 = (int)*(((s1_ptr)_2)->base + 11);
        Ref(_10805);
        DeRef(_0);
        _0 = _10805;
        if (IS_ATOM_INT(_10805)) {
            _10805 = (_10805 == 0);
        }
        else {
            _10805 = unary_op(NOT, _10805);
        }
        DeRef(_0);
LC:
        if (_10805 == 0) {
            goto LB;
        }
        else {
            if (!IS_ATOM_INT(_10805) && DBL_PTR(_10805)->dbl == 0.0)
                goto LB;
        }

        // 					if not eval_used or 
        DeRef(_10805);
        _10805 = (_7eval_used == 0);
        if (_10805 != 0) {
            goto LD;
        }
        DeRef(_10807);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10807 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10807 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10807);
        _0 = _10807;
        _2 = (int)SEQ_PTR(_10807);
        _10807 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_10807);
        DeRef(_0);
        _0 = _10807;
        _2 = (int)SEQ_PTR(_7file_eval);
        if (!IS_ATOM_INT(_10807))
            _10807 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_10807)->dbl));
        else
            _10807 = (int)*(((s1_ptr)_2)->base + _10807);
        DeRef(_0);
        _10807 = (_10807 == 0);
        if (_10807 != 0) {
            _10807 = 1;
            goto LE;
        }
        DeRef(_10795);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_i))
            _10795 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _10795 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10795);
        _0 = _10795;
        _2 = (int)SEQ_PTR(_10795);
        _10795 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_10795);
        DeRef(_0);
        _0 = _10795;
        if (IS_ATOM_INT(_10795)) {
            _10795 = (_10795 == 6);
        }
        else {
            _10795 = binary_op(EQUALS, _10795, 6);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_10795))
            _10807 = (_10795 != 0);
        else
            _10807 = DBL_PTR(_10795)->dbl != 0.0;
LE:
LF:
        if (_10807 == 0)
            goto L10;
LD:

        // 						delete_refs( i )
        Ref(_i);
        _22delete_refs(_i);

        // 						record_deleted( i )
        Ref(_i);
        _22record_deleted(_i);

        // 						patch_next( i )
        Ref(_i);
        _22patch_next(_i);

        // 						SymTab[i] = {0}
        _0 = _10795;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        _10795 = MAKE_SEQ(_1);
        DeRef(_0);
        RefDS(_10795);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_i))
            _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _10795;
        DeRef(_1);

        // 						deleted[2] += 1
        DeRefDSi(_10795);
        _2 = (int)SEQ_PTR(_22deleted);
        _10795 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_10795);
        _0 = _10795;
        if (IS_ATOM_INT(_10795)) {
            _10795 = _10795 + 1;
            if (_10795 > MAXINT)
                _10795 = NewDouble((double)_10795);
        }
        else
            _10795 = binary_op(PLUS, 1, _10795);
        DeRef(_0);
        Ref(_10795);
        _2 = (int)SEQ_PTR(_22deleted);
        _2 = (int)(((s1_ptr)_2)->base + 2);
        _1 = *(int *)_2;
        *(int *)_2 = _10795;
        DeRef(_1);
L10:
LB:
LA:
L8:
L4:

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
        goto L2;
L3:
        ;
        DeRef(_i);
    }

    // 	printf(2, "Deleted %d constants, %d routines and %d variables\n", deleted )
    EPrintf(2, _10836, _22deleted);

    // end procedure
    DeRef(_10795);
    DeRef(_10807);
    DeRef(_10805);
    return 0;
    ;
}


int _22make_bound()
{
    int _exe;
    int _bound;
    int _byte;
    int _location;
    int _ix;
    int _ok;
    int _exe_name = 0;
    int _bound_name = 0;
    int _10856 = 0;
    int _10837 = 0;
    int _0, _1, _2;
    

    // 	delete_unused()
    _22delete_unused();

    // 	exe_name = Argv[1]
    _2 = (int)SEQ_PTR(_7Argv);
    _exe_name = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_exe_name);

    // 	exe = open( exe_name, "rb" )
    _exe = EOpen(_exe_name, _10838);

    // 	if exe = -1 then
    if (_exe != -1)
        goto L1;

    // 		for j = length(exe_name) to 1 by -1 do
    _10837 = SEQ_PTR(_exe_name)->length;
    { int _j;
        _j = _10837;
L2:
        if (_j < 1)
            goto L3;

        // 			if exe_name[j] = SLASH then
        DeRef(_10837);
        _2 = (int)SEQ_PTR(_exe_name);
        _10837 = (int)*(((s1_ptr)_2)->base + _j);
        Ref(_10837);
        if (binary_op_a(NOTEQ, _10837, _7SLASH))
            goto L4;

        // 				exe_name = exe_name[j..$]
        DeRef(_10837);
        _10837 = SEQ_PTR(_exe_name)->length;
        rhs_slice_target = (object_ptr)&_exe_name;
        RHS_Slice((s1_ptr)_exe_name, _j, _10837);

        // 				exit
        goto L3;
L4:

        // 		end for
        _j = _j + -1;
        goto L2;
L3:
        ;
    }

    // 		exe_name = eudir & SLASH & "bin/" & exe_name
    {
        int concat_list[4];

        concat_list[0] = _exe_name;
        concat_list[1] = _10846;
        concat_list[2] = _7SLASH;
        concat_list[3] = _7eudir;
        Concat_N((object_ptr)&_exe_name, concat_list, 4);
    }

    // 		exe = open( exe_name, "rb" )
    _exe = EOpen(_exe_name, _10838);

    // 		if exe = -1 then
    if (_exe != -1)
        goto L5;

    // 			printf(2, "Error opening %s while attempting to bind...\n", {exe_name})
    _0 = _10837;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_exe_name);
    *((int *)(_2+4)) = _exe_name;
    _10837 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(2, _10850, _10837);

    // 			if wait_key() then end if
    _0 = _10837;
    _10837 = _20wait_key();
    DeRefDS(_0);
    if (_10837 == 0)
        goto L6;
L6:

    // 			abort(-1)                       
    UserCleanup(-1);
L5:
L1:

    // 	bound_name = reverse( source_name )
    RefDS(_7source_name);
    _0 = _bound_name;
    _bound_name = _2reverse(_7source_name);
    DeRef(_0);

    // 	ix = find('.', bound_name)
    _ix = find(46, _bound_name);

    // 	if ix then
    if (_ix == 0)
        goto L7;

    // 		bound_name = bound_name[ix+1..$]
    DeRef(_10837);
    _10837 = _ix + 1;
    DeRef(_10856);
    _10856 = SEQ_PTR(_bound_name)->length;
    rhs_slice_target = (object_ptr)&_bound_name;
    RHS_Slice((s1_ptr)_bound_name, _10837, _10856);
L7:

    // 	bound_name = reverse( bound_name )
    RefDS(_bound_name);
    _0 = _bound_name;
    _bound_name = _2reverse(_bound_name);
    DeRefDS(_0);

    // 	if EWINDOWS or EDOS then
    if (_7EWINDOWS != 0) {
        goto L8;
    }
L9:
    if (_7EDOS == 0)
        goto LA;
L8:

    // 		bound_name &= ".exe"
    Concat((object_ptr)&_bound_name, _bound_name, (s1_ptr)_10860);
LA:

    // 	bound = open( bound_name, "wb" )
    _bound = EOpen(_bound_name, _7309);

    // 	byte = getc( exe )
    if (_exe != last_r_file_no) {
        last_r_file_ptr = which_file(_exe, EF_READ);
        last_r_file_no = _exe;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _byte = getc(xstdin);
        }
        else
            _byte = getc(last_r_file_ptr);
    }
    else
        _byte = getc(last_r_file_ptr);

    // 	while byte != -1 do
LB:
    if (_byte == -1)
        goto LC;

    // 		puts( bound, byte )
    EPuts(_bound, _byte);

    // 		byte = getc( exe )
    if (_exe != last_r_file_no) {
        last_r_file_ptr = which_file(_exe, EF_READ);
        last_r_file_no = _exe;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _byte = getc(xstdin);
        }
        else
            _byte = getc(last_r_file_ptr);
    }
    else
        _byte = getc(last_r_file_ptr);

    // 	end while
    goto LB;
LC:

    // 	close( exe )
    EClose(_exe);

    // 	ok = seek( bound, -1 )
    _ok = _13seek(_bound, -1);

    // 	location = where( bound )
    _location = _13where(_bound);
    if (!IS_ATOM_INT(_location)) {
        _1 = (long)(DBL_PTR(_location)->dbl);
        DeRefDS(_location);
        _location = _1;
    }

    // 	puts( bound, compress_symtab( SymTab[TopLevelSub..$] ) )
    DeRef(_10856);
    _10856 = SEQ_PTR(_7SymTab)->length;
    rhs_slice_target = (object_ptr)&_10856;
    RHS_Slice((s1_ptr)_7SymTab, _7TopLevelSub, _10856);
    RefDS(_10856);
    _0 = _10856;
    _10856 = _21compress_symtab(_10856);
    DeRefDS(_0);
    EPuts(_bound, _10856);

    // 	puts( bound, int_to_bytes( location ) )
    _0 = _10856;
    _10856 = _4int_to_bytes(_location);
    DeRefDS(_0);
    EPuts(_bound, _10856);

    // 	puts( bound, "oe bound executable" )
    EPuts(_bound, _10872);

    // 	close( bound )
    EClose(_bound);

    // 	if platform() = LINUX then

    // 		system( "chmod 775 " & bound_name, 0 )
    Concat((object_ptr)&_10856, _10874, (s1_ptr)_bound_name);
    system_call(_10856, 0);
LD:

    // end procedure
    DeRef(_exe_name);
    DeRef(_bound_name);
    DeRef(_10856);
    DeRef(_10837);
    return 0;
    ;
}


int _22save_parsed_code()
{
    int _fn;
    int _name = 0;
    int _10876 = 0;
    int _0, _1, _2;
    

    // 	delete_unused()
    _22delete_unused();

    // 	name = source_name
    RefDS(_7source_name);
    _name = _7source_name;

    // 	for i = length(source_name) to 1 by -1 do
    _10876 = SEQ_PTR(_7source_name)->length;
    { int _i;
        _i = _10876;
L1:
        if (_i < 1)
            goto L2;

        // 		if name[i] = '.' then
        DeRef(_10876);
        _2 = (int)SEQ_PTR(_name);
        _10876 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10876);
        if (binary_op_a(NOTEQ, _10876, 46))
            goto L3;

        // 			name = source_name[1..i-1]
        DeRef(_10876);
        _10876 = _i - 1;
        rhs_slice_target = (object_ptr)&_name;
        RHS_Slice((s1_ptr)_7source_name, 1, _10876);

        // 			exit
        goto L2;
L3:

        // 	end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    // 	name &= ".oe"
    Concat((object_ptr)&_name, _name, (s1_ptr)_10881);

    // 	fn = open( name, "wb" )
    _fn = EOpen(_name, _7309);

    // 	write_symtab( fn, SymTab[TopLevelSub..$] )
    DeRef(_10876);
    _10876 = SEQ_PTR(_7SymTab)->length;
    rhs_slice_target = (object_ptr)&_10876;
    RHS_Slice((s1_ptr)_7SymTab, _7TopLevelSub, _10876);
    RefDS(_10876);
    _21write_symtab(_fn, _10876);

    // 	close( fn )
    EClose(_fn);

    // end procedure
    DeRefDS(_name);
    DeRefDS(_10876);
    return 0;
    ;
}


int _22load_parsed_code()
{
    int _fn;
    int _hashval;
    int _kname = 0;
    int _table = 0;
    int _10918 = 0;
    int _10906 = 0;
    int _10895 = 0;
    int _10886 = 0;
    int _0, _1, _2, _3;
    

    // 	fn = open( source_name, "rb" )
    _fn = EOpen(_7source_name, _10838);

    // 	SymTab = SymTab[1..$-2]
    _10886 = SEQ_PTR(_7SymTab)->length;
    _10886 = _10886 - 2;
    rhs_slice_target = (object_ptr)&_7SymTab;
    RHS_Slice((s1_ptr)_7SymTab, 1, _10886);

    // 	table = read_symtab( fn )
    _table = _21read_symtab(_fn);

    // 	Code = table[1][S_CODE]
    _2 = (int)SEQ_PTR(_table);
    _10886 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_10886);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_10886);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	SymTab &= table
    Concat((object_ptr)&_7SymTab, _7SymTab, (s1_ptr)_table);

    // 	close( fn )
    EClose(_fn);

    //     for k = 1 to length(SymTab) do 
    DeRefDS(_10886);
    _10886 = SEQ_PTR(_7SymTab)->length;
    { int _k;
        _k = 1;
L1:
        if (_k > _10886)
            goto L2;

        // 	if length(SymTab[k]) >= S_NAME then
        DeRef(_10895);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10895 = (int)*(((s1_ptr)_2)->base + _k);
        Ref(_10895);
        _0 = _10895;
        _10895 = SEQ_PTR(_10895)->length;
        DeRef(_0);
        if (_10895 < 7)
            goto L3;

        // 			kname = SymTab[k][S_NAME]
        _2 = (int)SEQ_PTR(_7SymTab);
        _10895 = (int)*(((s1_ptr)_2)->base + _k);
        Ref(_10895);
        DeRef(_kname);
        _2 = (int)SEQ_PTR(_10895);
        _kname = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_kname);

        // 		    if equal(kname, "object") then
        DeRef(_10895);
        if (_kname == _10900)
            _10895 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_10900))
            _10895 = 0;
        else
            _10895 = (compare(_kname, _10900) == 0);
        if (_10895 == 0)
            goto L4;

        // 				object_type = k
        _11object_type = _k;
        goto L5;
L4:

        // 		    elsif equal(kname, "atom") then
        DeRef(_10895);
        if (_kname == _9770)
            _10895 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_9770))
            _10895 = 0;
        else
            _10895 = (compare(_kname, _9770) == 0);
        if (_10895 == 0)
            goto L6;

        // 				atom_type = k
        _11atom_type = _k;
        goto L5;
L6:

        // 		    elsif equal(kname, "integer") then
        DeRef(_10895);
        if (_kname == _9771)
            _10895 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_9771))
            _10895 = 0;
        else
            _10895 = (compare(_kname, _9771) == 0);
        if (_10895 == 0)
            goto L7;

        // 				integer_type = k
        _11integer_type = _k;
        goto L5;
L7:

        // 		    elsif equal(kname, "sequence") then
        DeRef(_10895);
        if (_kname == _850)
            _10895 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_850))
            _10895 = 0;
        else
            _10895 = (compare(_kname, _850) == 0);
        if (_10895 == 0)
            goto L8;

        // 				sequence_type = k
        _11sequence_type = _k;
L8:
L5:

        // 		    if use_eval or length(precompiled) and length(kname) then
        if (_7use_eval != 0) {
            DeRef(_10895);
            _10895 = 1;
            goto L9;
        }
        DeRef(_10906);
        _10906 = SEQ_PTR(_7precompiled)->length;
        _10895 = (_10906 != 0);
L9:
        if (_10895 == 0) {
            goto LA;
        }
        DeRef(_10895);
        _10895 = SEQ_PTR(_kname)->length;
LB:
        if (_10895 == 0)
            goto LA;

        // 			    hashval = hashfn( kname )
        RefDS(_kname);
        _hashval = _11hashfn(_kname);

        // 			    SymTab[k][S_HASHVAL] = hashval
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_k + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 10);
        _1 = *(int *)_2;
        *(int *)_2 = _hashval;
        DeRef(_1);

        // 			    if buckets[hashval] and buckets[hashval] != k then
        DeRef(_10906);
        _2 = (int)SEQ_PTR(_11buckets);
        _10906 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_10906);
        if (IS_ATOM_INT(_10906)) {
            if (_10906 == 0) {
                goto LC;
            }
        }
        else {
            if (DBL_PTR(_10906)->dbl == 0.0) {
                goto LC;
            }
        }
        DeRef(_10895);
        _2 = (int)SEQ_PTR(_11buckets);
        _10895 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_10895);
        _0 = _10895;
        if (IS_ATOM_INT(_10895)) {
            _10895 = (_10895 != _k);
        }
        else {
            _10895 = binary_op(NOTEQ, _10895, _k);
        }
        DeRef(_0);
LD:
        if (_10895 == 0) {
            goto LC;
        }
        else {
            if (!IS_ATOM_INT(_10895) && DBL_PTR(_10895)->dbl == 0.0)
                goto LC;
        }

        // 			    	SymTab[k][S_SAMEHASH] = buckets[hashval]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_k + ((s1_ptr)_2)->base);
        DeRef(_10918);
        _2 = (int)SEQ_PTR(_11buckets);
        _10918 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_10918);
        Ref(_10918);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 8);
        _1 = *(int *)_2;
        *(int *)_2 = _10918;
        DeRef(_1);
LC:

        // 			    buckets[hashval] = k		    	
        _2 = (int)SEQ_PTR(_11buckets);
        _2 = (int)(((s1_ptr)_2)->base + _hashval);
        _1 = *(int *)_2;
        *(int *)_2 = _k;
        DeRef(_1);
LA:
L3:

        //     end for
        _k = _k + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef(_kname);
    DeRef(_table);
    DeRef(_10918);
    DeRef(_10906);
    DeRef(_10895);
    DeRef(_10886);
    return 0;
    ;
}


int _22load_bound_code(int _fn)
{
    int _kname = 0;
    int _table = 0;
    int _hashval;
    int _10945 = 0;
    int _10938 = 0;
    int _10927 = 0;
    int _10919 = 0;
    int _0, _1, _2, _3;
    

    // 	SymTab = SymTab[1..$-2]
    _10919 = SEQ_PTR(_7SymTab)->length;
    _10919 = _10919 - 2;
    rhs_slice_target = (object_ptr)&_7SymTab;
    RHS_Slice((s1_ptr)_7SymTab, 1, _10919);

    // 	table = read_symtab( fn )
    _table = _21read_symtab(_fn);

    // 	Code = table[1][S_CODE]
    _2 = (int)SEQ_PTR(_table);
    _10919 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_10919);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_10919);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    // 	SymTab &= table
    Concat((object_ptr)&_7SymTab, _7SymTab, (s1_ptr)_table);

    // 	close( fn )
    EClose(_fn);

    //     for k = 1 to length(SymTab) do 
    DeRefDS(_10919);
    _10919 = SEQ_PTR(_7SymTab)->length;
    { int _k;
        _k = 1;
L1:
        if (_k > _10919)
            goto L2;

        // 	if length(SymTab[k]) >= S_NAME then
        DeRef(_10927);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10927 = (int)*(((s1_ptr)_2)->base + _k);
        Ref(_10927);
        _0 = _10927;
        _10927 = SEQ_PTR(_10927)->length;
        DeRef(_0);
        if (_10927 < 7)
            goto L3;

        // 			kname = SymTab[k][S_NAME]
        _2 = (int)SEQ_PTR(_7SymTab);
        _10927 = (int)*(((s1_ptr)_2)->base + _k);
        Ref(_10927);
        DeRef(_kname);
        _2 = (int)SEQ_PTR(_10927);
        _kname = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_kname);

        // 		    if equal(kname, "object") then
        DeRef(_10927);
        if (_kname == _10900)
            _10927 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_10900))
            _10927 = 0;
        else
            _10927 = (compare(_kname, _10900) == 0);
        if (_10927 == 0)
            goto L4;

        // 				object_type = k
        _11object_type = _k;
        goto L5;
L4:

        // 		    elsif equal(kname, "atom") then
        DeRef(_10927);
        if (_kname == _9770)
            _10927 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_9770))
            _10927 = 0;
        else
            _10927 = (compare(_kname, _9770) == 0);
        if (_10927 == 0)
            goto L6;

        // 				atom_type = k
        _11atom_type = _k;
        goto L5;
L6:

        // 		    elsif equal(kname, "integer") then
        DeRef(_10927);
        if (_kname == _9771)
            _10927 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_9771))
            _10927 = 0;
        else
            _10927 = (compare(_kname, _9771) == 0);
        if (_10927 == 0)
            goto L7;

        // 				integer_type = k
        _11integer_type = _k;
        goto L5;
L7:

        // 		    elsif equal(kname, "sequence") then
        DeRef(_10927);
        if (_kname == _850)
            _10927 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_850))
            _10927 = 0;
        else
            _10927 = (compare(_kname, _850) == 0);
        if (_10927 == 0)
            goto L8;

        // 				sequence_type = k
        _11sequence_type = _k;
L8:
L5:

        // 		    if use_eval then
        if (_7use_eval == 0)
            goto L9;

        // 			    hashval = hashfn( kname )
        RefDS(_kname);
        _hashval = _11hashfn(_kname);

        // 			    SymTab[k][S_HASHVAL] = hashval
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_k + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 10);
        _1 = *(int *)_2;
        *(int *)_2 = _hashval;
        DeRef(_1);

        // 			    if buckets[hashval] and buckets[hashval] != k then
        DeRef(_10938);
        _2 = (int)SEQ_PTR(_11buckets);
        _10938 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_10938);
        if (IS_ATOM_INT(_10938)) {
            if (_10938 == 0) {
                goto LA;
            }
        }
        else {
            if (DBL_PTR(_10938)->dbl == 0.0) {
                goto LA;
            }
        }
        DeRef(_10927);
        _2 = (int)SEQ_PTR(_11buckets);
        _10927 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_10927);
        _0 = _10927;
        if (IS_ATOM_INT(_10927)) {
            _10927 = (_10927 != _k);
        }
        else {
            _10927 = binary_op(NOTEQ, _10927, _k);
        }
        DeRef(_0);
LB:
        if (_10927 == 0) {
            goto LA;
        }
        else {
            if (!IS_ATOM_INT(_10927) && DBL_PTR(_10927)->dbl == 0.0)
                goto LA;
        }

        // 			    	SymTab[k][S_SAMEHASH] = buckets[hashval]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_k + ((s1_ptr)_2)->base);
        DeRef(_10945);
        _2 = (int)SEQ_PTR(_11buckets);
        _10945 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_10945);
        Ref(_10945);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 8);
        _1 = *(int *)_2;
        *(int *)_2 = _10945;
        DeRef(_1);
LA:

        // 			    buckets[hashval] = k		    	
        _2 = (int)SEQ_PTR(_11buckets);
        _2 = (int)(((s1_ptr)_2)->base + _hashval);
        _1 = *(int *)_2;
        *(int *)_2 = _k;
        DeRef(_1);
L9:
L3:

        //     end for
        _k = _k + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef(_kname);
    DeRef(_table);
    DeRef(_10945);
    DeRef(_10938);
    DeRef(_10927);
    DeRef(_10919);
    return 0;
    ;
}


int _22post_process()
{
    int _pfile;
    int _fname = 0;
    int _10978 = 0;
    int _10949 = 0;
    int _10971 = 0;
    int _10956 = 0;
    int _10948;
    int _0, _1, _2, _3;
    

    // 	system( "mkdir preprocess", 0)  
    system_call(_10946, 0);

    // 	puts(2, "Ouputting preprocessed files.\n")
    EPuts(2, _10947);

    // 	for file = 1 to length(processed_files) do
    _10948 = SEQ_PTR(_7processed_files)->length;
    { int _file;
        _file = 1;
L1:
        if (_file > _10948)
            goto L2;

        // 		fname = file_name[processed_files[file]]
        DeRef(_10949);
        _2 = (int)SEQ_PTR(_7processed_files);
        _10949 = (int)*(((s1_ptr)_2)->base + _file);
        DeRef(_fname);
        _2 = (int)SEQ_PTR(_7file_name);
        _fname = (int)*(((s1_ptr)_2)->base + _10949);
        Ref(_fname);

        // 		if find( SLASH, fname ) then
        _10949 = find(_7SLASH, _fname);
        if (_10949 == 0)
            goto L3;

        // 			for j = length(fname) to 1 by -1 do
        _10949 = SEQ_PTR(_fname)->length;
        { int _j;
            _j = _10949;
L4:
            if (_j < 1)
                goto L5;

            // 				if fname[j] = SLASH then
            DeRef(_10949);
            _2 = (int)SEQ_PTR(_fname);
            _10949 = (int)*(((s1_ptr)_2)->base + _j);
            Ref(_10949);
            if (binary_op_a(NOTEQ, _10949, _7SLASH))
                goto L6;

            // 					fname = fname[j+1..$]
            DeRef(_10949);
            _10949 = _j + 1;
            DeRef(_10956);
            _10956 = SEQ_PTR(_fname)->length;
            rhs_slice_target = (object_ptr)&_fname;
            RHS_Slice((s1_ptr)_fname, _10949, _10956);

            // 					exit
            goto L5;
L6:

            // 			end for
            _j = _j + -1;
            goto L4;
L5:
            ;
        }
L3:

        // 		printf(2, "preprocess%s%s\n", { SLASH, fname})
        DeRef(_10956);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _7SLASH;
        ((int *)_2)[2] = _fname;
        RefDS(_fname);
        _10956 = MAKE_SEQ(_1);
        EPrintf(2, _10958, _10956);

        // 		pfile = open( sprintf("preprocess%s%s", { SLASH, fname }), "w" )
        DeRefDS(_10956);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _7SLASH;
        ((int *)_2)[2] = _fname;
        RefDS(_fname);
        _10956 = MAKE_SEQ(_1);
        _0 = _10956;
        _10956 = EPrintf(-9999999, _10960, _10956);
        DeRefDS(_0);
        _pfile = EOpen(_10956, _6794);

        // 		if atom(slist[$]) then
        DeRefDSi(_10956);
        _10956 = SEQ_PTR(_7slist)->length;
        _2 = (int)SEQ_PTR(_7slist);
        _10956 = (int)*(((s1_ptr)_2)->base + _10956);
        Ref(_10956);
        _0 = _10956;
        _10956 = IS_ATOM(_10956);
        DeRef(_0);
        if (_10956 == 0)
            goto L7;

        // 			slist = s_expand( slist )
        RefDS(_7slist);
        _0 = _12s_expand(_7slist);
        DeRefDS(_7slist);
        _7slist = _0;
L7:

        // 		for l = 1 to length( slist ) do
        DeRef(_10956);
        _10956 = SEQ_PTR(_7slist)->length;
        { int _l;
            _l = 1;
L8:
            if (_l > _10956)
                goto L9;

            // 			if slist[l][LOCAL_FILE_NO] = processed_files[file] then
            DeRef(_10949);
            _2 = (int)SEQ_PTR(_7slist);
            _10949 = (int)*(((s1_ptr)_2)->base + _l);
            Ref(_10949);
            _0 = _10949;
            _2 = (int)SEQ_PTR(_10949);
            _10949 = (int)*(((s1_ptr)_2)->base + 3);
            Ref(_10949);
            DeRef(_0);
            DeRef(_10971);
            _2 = (int)SEQ_PTR(_7processed_files);
            _10971 = (int)*(((s1_ptr)_2)->base + _file);
            if (binary_op_a(NOTEQ, _10949, _10971))
                goto LA;

            // 				if atom(slist[l][SRC]) then
            _2 = (int)SEQ_PTR(_7slist);
            _10971 = (int)*(((s1_ptr)_2)->base + _l);
            Ref(_10971);
            _0 = _10971;
            _2 = (int)SEQ_PTR(_10971);
            _10971 = (int)*(((s1_ptr)_2)->base + 1);
            Ref(_10971);
            DeRef(_0);
            _0 = _10971;
            _10971 = IS_ATOM(_10971);
            DeRef(_0);
            if (_10971 == 0)
                goto LB;

            // 					slist[l][SRC] = fetch_line(slist[l][SRC])
            _2 = (int)SEQ_PTR(_7slist);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _7slist = MAKE_SEQ(_2);
            }
            _3 = (int)(_l + ((s1_ptr)_2)->base);
            DeRef(_10978);
            _2 = (int)SEQ_PTR(_7slist);
            _10978 = (int)*(((s1_ptr)_2)->base + _l);
            Ref(_10978);
            _0 = _10978;
            _2 = (int)SEQ_PTR(_10978);
            _10978 = (int)*(((s1_ptr)_2)->base + 1);
            Ref(_10978);
            DeRef(_0);
            Ref(_10978);
            _0 = _10978;
            _10978 = _12fetch_line(_10978);
            DeRef(_0);
            RefDS(_10978);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 1);
            _1 = *(int *)_2;
            *(int *)_2 = _10978;
            DeRef(_1);
LB:

            // 				puts( pfile, slist[l][SRC] & '\n' )
            DeRef(_10978);
            _2 = (int)SEQ_PTR(_7slist);
            _10978 = (int)*(((s1_ptr)_2)->base + _l);
            Ref(_10978);
            _0 = _10978;
            _2 = (int)SEQ_PTR(_10978);
            _10978 = (int)*(((s1_ptr)_2)->base + 1);
            Ref(_10978);
            DeRef(_0);
            if (IS_SEQUENCE(_10978) && IS_ATOM(10)) {
                Append(&_10978, _10978, 10);
            }
            else if (IS_ATOM(_10978) && IS_SEQUENCE(10)) {
            }
            else {
                Concat((object_ptr)&_10978, _10978, (s1_ptr)10);
            }
            EPuts(_pfile, _10978);
LA:

            // 		end for
            _l = _l + 1;
            goto L8;
L9:
            ;
        }

        // 		close( pfile )
        EClose(_pfile);

        // 	end for
        _file = _file + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef(_fname);
    DeRef(_10978);
    DeRef(_10949);
    DeRef(_10971);
    DeRef(_10956);
    return 0;
    ;
}


int _22set_eudir()
{
    int _10987;
    int _0, _1, _2;
    

    //     eudir = getenv("EUDIR")
    DeRefi(_7eudir);
    _7eudir = EGetEnv(_10986);

    //     if atom(eudir) then
    _10987 = IS_ATOM(_7eudir);
    if (_10987 == 0)
        goto L1;

    // 	if ELINUX then
    if (_7ELINUX == 0)
        goto L2;

    // 	    eudir = getenv("HOME")
    DeRefi(_7eudir);
    _7eudir = EGetEnv(_10989);

    // 	    if atom(eudir) then
    _10987 = IS_ATOM(_7eudir);
    if (_10987 == 0)
        goto L3;

    // 		eudir = "euphoria"  
    RefDS(_10992);
    DeRefi(_7eudir);
    _7eudir = _10992;
    goto L4;
L3:

    // 		eudir = eudir & "/euphoria"
    if (IS_SEQUENCE(_7eudir) && IS_ATOM(_10993)) {
    }
    else if (IS_ATOM(_7eudir) && IS_SEQUENCE(_10993)) {
        Ref(_7eudir);
        Prepend(&_7eudir, _10993, _7eudir);
    }
    else {
        Concat((object_ptr)&_7eudir, _7eudir, (s1_ptr)_10993);
    }
L5:
    goto L4;
L2:

    // 	    eudir = "\\EUPHORIA"
    RefDS(_10995);
    DeRefi(_7eudir);
    _7eudir = _10995;
L4:
L1:

    // end procedure
    return 0;
    ;
}


int _22main()
{
    int _argc;
    int _argv = 0;
    int _exe;
    int _location;
    int _ok;
    int _pfile;
    int _fname = 0;
    int _11012 = 0;
    int _10996 = 0;
    int _0, _1, _2;
    

    //     argv = command_line()
    _argv = Command_Line();

    //     if BIND then

    //     argc = length(argv)  
    _argc = SEQ_PTR(_argv)->length;

    //     Argv = argv
    RefDS(_argv);
    DeRef(_7Argv);
    _7Argv = _argv;

    //     Argc = argc
    _7Argc = _argc;

    // 	set_eudir()
    _22set_eudir();

    //     TempErrName = "ex.err"           
    RefDS(_6792);
    DeRefi(_9TempErrName);
    _9TempErrName = _6792;

    //     if TRANSLATE then

    //     exe = open( Argv[1], "rb" )
    _2 = (int)SEQ_PTR(_7Argv);
    _10996 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_10996);
    _exe = EOpen(_10996, _10838);

    //     if exe > -1 then
    if (_exe <= -1)
        goto L1;

    // 		ok = seek( exe, -1 )
    _ok = _13seek(_exe, -1);

    // 		location = where( exe )
    _location = _13where(_exe);
    if (!IS_ATOM_INT(_location)) {
        _1 = (long)(DBL_PTR(_location)->dbl);
        DeRefDS(_location);
        _location = _1;
    }

    // 		ok = seek( exe, location - 19 )
    DeRefDS(_10996);
    _10996 = _location - 19;
    if ((long)((unsigned long)_10996 +(unsigned long) HIGH_BITS) >= 0)
        _10996 = NewDouble((double)_10996);
    Ref(_10996);
    _ok = _13seek(_exe, _10996);

    // 		if equal( get_bytes( exe, 19 ), "oe bound executable" ) then
    _0 = _10996;
    _10996 = _20get_bytes(_exe, 19);
    DeRef(_0);
    _0 = _10996;
    if (_10996 == _10872)
        _10996 = 1;
    else if (IS_ATOM_INT(_10996) && IS_ATOM_INT(_10872))
        _10996 = 0;
    else
        _10996 = (compare(_10996, _10872) == 0);
    DeRefDSi(_0);
    if (_10996 == 0)
        goto L2;

    // 			bound = 1
    _7bound = 1;

    // 			source_name = Argv[1]
    DeRef(_7source_name);
    _2 = (int)SEQ_PTR(_7Argv);
    _7source_name = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_7source_name);

    // 			ok = seek( exe, location - 23 )
    _10996 = _location - 23;
    if ((long)((unsigned long)_10996 +(unsigned long) HIGH_BITS) >= 0)
        _10996 = NewDouble((double)_10996);
    Ref(_10996);
    _ok = _13seek(_exe, _10996);

    // 			location = getc( exe ) + getc( exe ) * #100 
    DeRef(_10996);
    if (_exe != last_r_file_no) {
        last_r_file_ptr = which_file(_exe, EF_READ);
        last_r_file_no = _exe;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10996 = getc(xstdin);
        }
        else
            _10996 = getc(last_r_file_ptr);
    }
    else
        _10996 = getc(last_r_file_ptr);
    if (_exe != last_r_file_no) {
        last_r_file_ptr = which_file(_exe, EF_READ);
        last_r_file_no = _exe;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _11012 = getc(xstdin);
        }
        else
            _11012 = getc(last_r_file_ptr);
    }
    else
        _11012 = getc(last_r_file_ptr);
    _11012 = _11012 * 256;
    _11012 = _10996 + _11012;
    if (_exe != last_r_file_no) {
        last_r_file_ptr = which_file(_exe, EF_READ);
        last_r_file_no = _exe;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _10996 = getc(xstdin);
        }
        else
            _10996 = getc(last_r_file_ptr);
    }
    else
        _10996 = getc(last_r_file_ptr);
    _10996 = _10996 * 65536;
    _10996 = _11012 + _10996;
    if (_exe != last_r_file_no) {
        last_r_file_ptr = which_file(_exe, EF_READ);
        last_r_file_no = _exe;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _11012 = getc(xstdin);
        }
        else
            _11012 = getc(last_r_file_ptr);
    }
    else
        _11012 = getc(last_r_file_ptr);
    _11012 = NewDouble(_11012 * (double)16777216);
    if (IS_ATOM_INT(_11012)) {
        _location = _10996 + _11012;
    }
    else {
        _location = NewDouble((double)_10996 + DBL_PTR(_11012)->dbl);
    }
    if (!IS_ATOM_INT(_location)) {
        _1 = (long)(DBL_PTR(_location)->dbl);
        DeRefDS(_location);
        _location = _1;
    }

    // 			ok = seek( exe, location )
    _ok = _13seek(_exe, _location);

    // 			InitGlobals()
    _16InitGlobals();

    // 			InitSymTab()
    _11InitSymTab();

    // 			InitEmit()
    _15InitEmit();

    // 			InitParser()
    _16InitParser();

    // 			InitLex()
    _12InitLex();

    // 			main_path = full_path(Argv[1])
    DeRef(_11012);
    _2 = (int)SEQ_PTR(_7Argv);
    _11012 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_11012);
    Ref(_11012);
    _0 = _22full_path(_11012);
    DeRef(_12main_path);
    _12main_path = _0;

    // 			load_bound_code( exe )
    _22load_bound_code(_exe);

    // 			no_source = 1
    _7no_source = 1;

    // 			InitBackEnd()
    _17InitBackEnd();

    // 			BackEnd( 0 )
    _17BackEnd(0);
    goto L3;
L2:

    // 			close( exe )
    EClose(_exe);
L3:
L1:

    //     if not bound then
    if (_7bound != 0)
        goto L4;

    // 	    src_file = ProcessOptions()
    _0 = _22ProcessOptions();
    _12src_file = _0;

    // 	    if src_file = -1 then
    if (_12src_file != -1)
        goto L5;

    // 		screen_output(STDERR, sprintf("Can't open %s\n", {file_name[1]}))
    DeRef(_11012);
    _2 = (int)SEQ_PTR(_7file_name);
    _11012 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_11012);
    _0 = _11012;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_11012);
    *((int *)(_2+4)) = _11012;
    _11012 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _11012;
    _11012 = EPrintf(-9999999, _11028, _11012);
    DeRefDS(_0);
    RefDS(_11012);
    _9screen_output(2, _11012);

    // 		if BIND or EWINDOWS or ELINUX then
    if (0 != 0) {
        DeRefDS(_11012);
        _11012 = 1;
        goto L6;
    }
    _11012 = (_7EWINDOWS != 0);
L6:
    if (_11012 != 0) {
        goto L7;
    }
L8:
    if (_7ELINUX == 0)
        goto L9;
L7:

    // 		    screen_output(STDERR, "\nPress Enter\n")
    RefDS(_11034);
    _9screen_output(2, _11034);

    // 		    if getc(0) then
    DeRef(_11012);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _11012 = getc(xstdin);
        }
        else
            _11012 = getc(last_r_file_ptr);
    }
    else
        _11012 = getc(last_r_file_ptr);
    if (_11012 == 0)
        goto LA;
LA:
L9:

    // 		Cleanup(1)
    _9Cleanup(1);
L5:

    // 	    main_path = full_path(file_name[1])  
    DeRef(_11012);
    _2 = (int)SEQ_PTR(_7file_name);
    _11012 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_11012);
    Ref(_11012);
    _0 = _22full_path(_11012);
    DeRef(_12main_path);
    _12main_path = _0;

    // 	    InitGlobals()
    _16InitGlobals();

    // 	    InitSymTab()
    _11InitSymTab();

    // 		precompiled = append( precompiled, source_name )
    RefDS(_7source_name);
    Append(&_7precompiled, _7precompiled, _7source_name);

    // 	    for i = 1 to length(precompiled)-1 do
    DeRef(_11012);
    _11012 = SEQ_PTR(_7precompiled)->length;
    _11012 = _11012 - 1;
    { int _i;
        _i = 1;
LB:
        if (_i > _11012)
            goto LC;

        // 	    	source_name = precompiled[i]
        DeRef(_7source_name);
        _2 = (int)SEQ_PTR(_7precompiled);
        _7source_name = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_7source_name);

        // 	    	load_parsed_code()
        _22load_parsed_code();

        // 	    end for
        _i = _i + 1;
        goto LB;
LC:
        ;
    }

    // 	    source_name = precompiled[$]
    DeRef(_10996);
    _10996 = SEQ_PTR(_7precompiled)->length;
    DeRef(_7source_name);
    _2 = (int)SEQ_PTR(_7precompiled);
    _7source_name = (int)*(((s1_ptr)_2)->base + _10996);
    Ref(_7source_name);

    // 	    if length(precompiled) > 1 then
    _10996 = SEQ_PTR(_7precompiled)->length;
    if (_10996 <= 1)
        goto LD;

    // 	    	file_name = append( file_name, source_name )
    RefDS(_7source_name);
    Append(&_7file_name, _7file_name, _7source_name);
LD:

    // 	    current_file_no = length(file_name)
    _7current_file_no = SEQ_PTR(_7file_name)->length;

    // 		if match( ".oe", lower(source_name) ) = (length(source_name) - 2) then
    RefDS(_7source_name);
    _0 = _10996;
    _10996 = _3lower(_7source_name);
    DeRef(_0);
    _0 = _10996;
    _10996 = e_match(_10881, _10996);
    DeRef(_0);
    DeRef(_11012);
    _11012 = SEQ_PTR(_7source_name)->length;
    _11012 = _11012 - 2;
    if (_10996 != _11012)
        goto LE;

    // 			InitEmit()
    _15InitEmit();

    // 			InitParser()
    _16InitParser();

    // 			InitLex()
    _12InitLex();

    // 			read_line()
    _12read_line();

    // 			load_parsed_code()
    _22load_parsed_code();

    // 			no_source = 1
    _7no_source = 1;
    goto LF;
LE:

    // 			if bind then
    if (_7bind == 0)
        goto L10;

    // 				puts(2, "Binding source files\n")
    EPuts(2, _11053);
    goto L11;
L10:

    // 			elsif preprocess then
    if (_7preprocess == 0)
        goto L12;

    // 				puts(2, "Preprocessing source files\n")
    EPuts(2, _11054);
    goto L11;
L12:

    // 			elsif not execute then
    if (_7execute != 0)
        goto L13;

    // 				puts(2, "Shrouding source files\n")
    EPuts(2, _11056);
L13:
L11:

    // 		    InitEmit()
    _15InitEmit();

    // 		    InitParser()
    _16InitParser();

    // 		    InitLex()
    _12InitLex();

    // 		    read_line()
    _12read_line();

    // 		    parser()
    _16parser();
LF:

    // 	    if TRANSLATE then

    // 	    elsif INTERPRET then

    // 			if execute then
    if (_7execute == 0)
        goto L14;

    // 				InitBackEnd()
    _17InitBackEnd();

    // 				BackEnd(0) -- execute IL using Euphoria-coded back-end                  
    _17BackEnd(0);
    goto L15;
L14:

    // 			elsif bind then
    if (_7bind == 0)
        goto L16;

    // 				make_bound()
    _22make_bound();
    goto L15;
L16:

    // 			elsif preprocess then
    if (_7preprocess == 0)
        goto L17;

    // 				post_process( )
    _22post_process();
    goto L15;
L17:

    // 				save_parsed_code()
    _22save_parsed_code();
L15:
L18:
L19:
L4:

    //     Cleanup(0) -- does warnings
    _9Cleanup(0);

    // end procedure
    DeRef(_argv);
    DeRef(_fname);
    DeRef(_11012);
    DeRef(_10996);
    return 0;
    ;
}


