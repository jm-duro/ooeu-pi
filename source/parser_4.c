// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16ExecCommand()
{
    int _0, _1, _2;
    

    //     if TRANSLATE then

    //     StraightenBranches()  -- straighten top-level
    _16StraightenBranches();

    // end procedure
    return 0;
    ;
}


int _16ParseMethodArgs(int _method)
{
    int _ix;
    int _current;
    int _tok = 0;
    int _decorated = 0;
    int _subsym;
    int _class;
    int _5509 = 0;
    int _5518 = 0;
    int _0, _1, _2;
    

    // 	subsym = method[T_SYM]
    _2 = (int)SEQ_PTR(_method);
    _subsym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_subsym))
        _subsym = (long)DBL_PTR(_subsym)->dbl;

    // 	current = current_instance[$]
    _5509 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _current = (int)*(((s1_ptr)_2)->base + _5509);
    if (!IS_ATOM_INT(_current))
        _current = (long)DBL_PTR(_current)->dbl;

    // 	if current then
    if (_current == 0)
        goto L1;

    // 		class = SymTab[current_instance[$]][S_VTYPE]
    _5509 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5509 = (int)*(((s1_ptr)_2)->base + _5509);
    Ref(_5509);
    _0 = _5509;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5509))
        _5509 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5509)->dbl));
    else
        _5509 = (int)*(((s1_ptr)_2)->base + _5509);
    Ref(_5509);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_5509);
    _class = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;
    goto L2;
L1:

    // 		class = find( SymTab[subsym][S_NAME], class_table[CLASS_NAME] )
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5509 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_5509);
    _0 = _5509;
    _2 = (int)SEQ_PTR(_5509);
    _5509 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5509);
    DeRef(_0);
    DeRef(_5518);
    _2 = (int)SEQ_PTR(_7class_table);
    _5518 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5518);
    _class = find(_5509, _5518);

    // 		if not class then
    if (_class != 0)
        goto L3;

    // 			CompileErr( sprintf( "%s is undefined", {SymTab[subsym][S_NAME]}))
    DeRefDS(_5518);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5518 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_5518);
    _0 = _5518;
    _2 = (int)SEQ_PTR(_5518);
    _5518 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5518);
    DeRef(_0);
    _0 = _5518;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_5518);
    *((int *)(_2+4)) = _5518;
    _5518 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _5518;
    _5518 = EPrintf(-9999999, _5521, _5518);
    DeRefDS(_0);
    RefDS(_5518);
    _9CompileErr(_5518);

    // 			return
    DeRefDS(_method);
    DeRef(_tok);
    DeRef(_decorated);
    DeRefDSi(_5518);
    DeRef(_5509);
    return 0;
L3:

    // 		class = class_table[CLASS_SYM][class]
    DeRef(_5518);
    _2 = (int)SEQ_PTR(_7class_table);
    _5518 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5518);
    _2 = (int)SEQ_PTR(_5518);
    _class = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;
L2:

    // 	ix = find( class, class_table[CLASS_SYM] )
    DeRef(_5518);
    _2 = (int)SEQ_PTR(_7class_table);
    _5518 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5518);
    _ix = find(_class, _5518);

    // 	if not ix then
    if (_ix != 0)
        goto L4;

    // 		class = current_instance[$]
    DeRefDS(_5518);
    _5518 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _class = (int)*(((s1_ptr)_2)->base + _5518);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 		ix = find( class, class_table[CLASS_SYM] )
    _2 = (int)SEQ_PTR(_7class_table);
    _5518 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5518);
    _ix = find(_class, _5518);

    // 		if not ix then
    if (_ix != 0)
        goto L5;

    // 			CompileErr( "invalid class instance" )
    RefDS(_5536);
    _9CompileErr(_5536);

    // 			return
    DeRefDS(_method);
    DeRef(_tok);
    DeRef(_decorated);
    DeRefDS(_5518);
    DeRef(_5509);
    return 0;
L5:
L4:

    // 	if current_instance[$] then
    DeRef(_5518);
    _5518 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5518 = (int)*(((s1_ptr)_2)->base + _5518);
    Ref(_5518);
    if (_5518 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_5518) && DBL_PTR(_5518)->dbl == 0.0)
            goto L6;
    }

    // 		decorated = SymTab[subsym][S_NAME] & '@' & class_table[CLASS_NAME][ix] & '@'
    DeRef(_5518);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5518 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_5518);
    _0 = _5518;
    _2 = (int)SEQ_PTR(_5518);
    _5518 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5518);
    DeRef(_0);
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_7class_table);
    _5509 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5509);
    _0 = _5509;
    _2 = (int)SEQ_PTR(_5509);
    _5509 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_5509);
    DeRefDS(_0);
    {
        int concat_list[4];

        concat_list[0] = 64;
        concat_list[1] = _5509;
        concat_list[2] = 64;
        concat_list[3] = _5518;
        Concat_N((object_ptr)&_decorated, concat_list, 4);
    }
    goto L7;
L6:

    // 		decorated = SymTab[subsym][S_NAME] & '@'
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5509 = (int)*(((s1_ptr)_2)->base + _subsym);
    Ref(_5509);
    _0 = _5509;
    _2 = (int)SEQ_PTR(_5509);
    _5509 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5509);
    DeRef(_0);
    if (IS_SEQUENCE(_5509) && IS_ATOM(64)) {
        Append(&_decorated, _5509, 64);
    }
    else if (IS_ATOM(_5509) && IS_SEQUENCE(64)) {
    }
    else {
        Concat((object_ptr)&_decorated, _5509, (s1_ptr)64);
    }
L7:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 	if tok[T_ID] != RIGHT_ROUND then
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_tok);
    _5509 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5509);
    if (binary_op_a(EQUALS, _5509, -27))
        goto L8;

    // 		putback(tok)
    RefDS(_tok);
    _16putback(_tok);
L8:

    //     short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    // 	current_instance &= 0
    Append(&_7current_instance, _7current_instance, 0);

    //     while tok[T_ID] != RIGHT_ROUND do
L9:
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_tok);
    _5509 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5509);
    if (binary_op_a(EQUALS, _5509, -27))
        goto LA;

    // 		call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 	    if tok[T_ID] != COMMA then
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_tok);
    _5509 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5509);
    if (binary_op_a(EQUALS, _5509, -30))
        goto L9;

    // 		if tok[T_ID] != RIGHT_ROUND then
    DeRef(_5509);
    _2 = (int)SEQ_PTR(_tok);
    _5509 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5509);
    if (binary_op_a(EQUALS, _5509, -27))
        goto L9;

    // 		    putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		    tok_match(COMMA)
    _16tok_match(-30);
LB:
LC:

    // 	end while
    goto L9;
LA:

    // 	current_instance = current_instance[1..$-1]
    DeRef(_5509);
    _5509 = SEQ_PTR(_7current_instance)->length;
    _5509 = _5509 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _5509);

    //     short_circuit += 1
    _16short_circuit = _16short_circuit + 1;

    // end procedure
    DeRefDS(_method);
    DeRef(_tok);
    DeRef(_decorated);
    DeRef(_5518);
    return 0;
    ;
}


int _16class_base_type(int _name)
{
    int _class;
    int _ix;
    int _types = 0;
    int _5575 = 0;
    int _5563 = 0;
    int _0, _1, _2;
    

    // 	name = name[2..$-1]  -- strip off leading and trailing '@'
    _5563 = SEQ_PTR(_name)->length;
    _5563 = _5563 - 1;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, 2, _5563);

    // 	class = find( name, class_table[CLASS_NAME] )
    _2 = (int)SEQ_PTR(_7class_table);
    _5563 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5563);
    _class = find(_name, _5563);

    // 	if not class then
    if (_class != 0)
        goto L1;

    // 		return ""
    RefDS(_39);
    DeRefDS(_name);
    DeRefDS(_5563);
    return _39;
L1:

    // 	while class_table[CLASS_PARENT][class] do
L2:
    DeRef(_5563);
    _2 = (int)SEQ_PTR(_7class_table);
    _5563 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_5563);
    _0 = _5563;
    _2 = (int)SEQ_PTR(_5563);
    _5563 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5563);
    DeRefDS(_0);
    if (_5563 <= 0) {
        if (_5563 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_5563) && DBL_PTR(_5563)->dbl == 0.0)
                goto L3;
        }
    }

    // 		class = class_table[CLASS_PARENT][class]
    DeRef(_5563);
    _2 = (int)SEQ_PTR(_7class_table);
    _5563 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_5563);
    _2 = (int)SEQ_PTR(_5563);
    _class = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 	end while
    goto L2;
L3:

    // 	ix = find( class_table[CLASS_VARTYPE][class], {atom_type, integer_type, object_type, sequence_type})
    DeRef(_5563);
    _2 = (int)SEQ_PTR(_7class_table);
    _5563 = (int)*(((s1_ptr)_2)->base + 5);
    RefDS(_5563);
    _0 = _5563;
    _2 = (int)SEQ_PTR(_5563);
    _5563 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5563);
    DeRefDS(_0);
    _0 = _5575;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _11atom_type;
    *((int *)(_2+8)) = _11integer_type;
    *((int *)(_2+12)) = _11object_type;
    *((int *)(_2+16)) = _11sequence_type;
    _5575 = MAKE_SEQ(_1);
    DeRef(_0);
    _ix = find(_5563, _5575);

    // 	if not ix then
    if (_ix != 0)
        goto L4;

    // 		ix = 3
    _ix = 3;
L4:

    // 	types = {"a","i","o","s"}
    _0 = _types;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_5578);
    *((int *)(_2+4)) = _5578;
    RefDS(_5579);
    *((int *)(_2+8)) = _5579;
    RefDS(_5580);
    *((int *)(_2+12)) = _5580;
    RefDS(_3745);
    *((int *)(_2+16)) = _3745;
    _types = MAKE_SEQ(_1);
    DeRef(_0);

    // 	return types[ix]
    DeRef(_5575);
    _2 = (int)SEQ_PTR(_types);
    _5575 = (int)*(((s1_ptr)_2)->base + _ix);
    RefDS(_5575);
    DeRefDS(_name);
    DeRefDS(_types);
    DeRef(_5563);
    return _5575;
    ;
}


int _16ArgLCD(int _a1, int _a2)
{
    int _c;
    int _d;
    int _sym;
    int _base_type = 0;
    int _5583 = 0;
    int _5592 = 0;
    int _0, _1, _2;
    

    // 	if equal( a1, a2 ) then
    if (_a1 == _a2)
        _5583 = 1;
    else if (IS_ATOM_INT(_a1) && IS_ATOM_INT(_a2))
        _5583 = 0;
    else
        _5583 = (compare(_a1, _a2) == 0);
    if (_5583 == 0)
        goto L1;

    // 		return 1
    DeRefDS(_a1);
    DeRefDS(_a2);
    return 1;
    goto L2;
L1:

    // 	elsif equal( a2, "o" ) then
    DeRef(_5583);
    if (_a2 == _5580)
        _5583 = 1;
    else if (IS_ATOM_INT(_a2) && IS_ATOM_INT(_5580))
        _5583 = 0;
    else
        _5583 = (compare(_a2, _5580) == 0);
    if (_5583 == 0)
        goto L3;

    // 		return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5592);
    return 0;
    goto L2;
L3:

    // 	elsif a2[1] = '@' then --length( a2 ) > 1 then
    DeRef(_5583);
    _2 = (int)SEQ_PTR(_a2);
    _5583 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5583);
    if (binary_op_a(NOTEQ, _5583, 64))
        goto L4;

    // 		if length(a1) = 1 then
    DeRef(_5583);
    _5583 = SEQ_PTR(_a1)->length;
    if (_5583 != 1)
        goto L5;

    // 			a2 = class_base_type( a2 )
    RefDS(_a2);
    _0 = _a2;
    _a2 = _16class_base_type(_a2);
    DeRefDS(_0);

    // 			if equal( a1, a2 ) then
    if (_a1 == _a2)
        _5583 = 1;
    else if (IS_ATOM_INT(_a1) && IS_ATOM_INT(_a2))
        _5583 = 0;
    else
        _5583 = (compare(_a1, _a2) == 0);
    if (_5583 == 0)
        goto L6;

    // 				return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5592);
    return 0;
L6:

    // 			if atom( ArgLCD(a1, a2)) then
    RefDS(_a1);
    DeRef(_5583);
    _5583 = _a1;
    RefDS(_a2);
    DeRef(_5592);
    _5592 = _a2;
    RefDS(_5583);
    RefDS(_5592);
    _0 = _5592;
    _5592 = _16ArgLCD(_5583, _5592);
    DeRefDS(_0);
    _0 = _5592;
    _5592 = IS_ATOM(_5592);
    DeRef(_0);
    if (_5592 == 0)
        goto L7;

    // 				return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRefDS(_5583);
    return 0;
L7:

    // 			return {}
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
L5:

    // 		c = find( a1[2..$-1], class_table[CLASS_NAME] )
    DeRef(_5592);
    _5592 = SEQ_PTR(_a1)->length;
    _5592 = _5592 - 1;
    rhs_slice_target = (object_ptr)&_5592;
    RHS_Slice((s1_ptr)_a1, 2, _5592);
    DeRef(_5583);
    _2 = (int)SEQ_PTR(_7class_table);
    _5583 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5583);
    _c = find(_5592, _5583);

    // 		if not c then
    if (_c != 0)
        goto L8;

    // 			CompileErr(sprintf("invalid class: '%s'",{a1}))
    _0 = _5583;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_a1);
    *((int *)(_2+4)) = _a1;
    _5583 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _5583;
    _5583 = EPrintf(-9999999, _5601, _5583);
    DeRefDS(_0);
    RefDS(_5583);
    _9CompileErr(_5583);

    // 			return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRefDSi(_5583);
    DeRefDS(_5592);
    return 0;
L8:

    // 		a2 = a2[2..$-1]
    DeRef(_5583);
    _5583 = SEQ_PTR(_a2)->length;
    _5583 = _5583 - 1;
    rhs_slice_target = (object_ptr)&_a2;
    RHS_Slice((s1_ptr)_a2, 2, _5583);

    // 		while c and compare( a2, class_table[CLASS_NAME][c] ) do
L9:
    if (_c == 0) {
        goto LA;
    }
    DeRef(_5592);
    _2 = (int)SEQ_PTR(_7class_table);
    _5592 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5592);
    _0 = _5592;
    _2 = (int)SEQ_PTR(_5592);
    _5592 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_5592);
    DeRefDS(_0);
    _0 = _5592;
    if (IS_ATOM_INT(_a2) && IS_ATOM_INT(_5592))
        _5592 = (_a2 < _5592) ? -1 : (_a2 > _5592);
    else
        _5592 = compare(_a2, _5592);
    DeRef(_0);
LB:
    if (_5592 == 0)
        goto LA;

    // 			c = class_table[CLASS_PARENT][c]
    DeRef(_5592);
    _2 = (int)SEQ_PTR(_7class_table);
    _5592 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_5592);
    _2 = (int)SEQ_PTR(_5592);
    _c = (int)*(((s1_ptr)_2)->base + _c);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 		end while
    goto L9;
LA:

    // 		if c then
    if (_c == 0)
        goto LC;

    // 			return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
LC:

    // 			return ""
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
LD:
    goto L2;
L4:

    // 	elsif a2[1] = '!' then
    DeRef(_5592);
    _2 = (int)SEQ_PTR(_a2);
    _5592 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5592);
    if (binary_op_a(NOTEQ, _5592, 33))
        goto LE;

    // 		return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
LE:

    // 	elsif a1[1] = '@' then --length( a1 ) > 1 then
    DeRef(_5592);
    _2 = (int)SEQ_PTR(_a1);
    _5592 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5592);
    if (binary_op_a(NOTEQ, _5592, 64))
        goto LF;

    // 		c = find( a1[2..$-1], class_table[CLASS_NAME] )
    DeRef(_5592);
    _5592 = SEQ_PTR(_a1)->length;
    _5592 = _5592 - 1;
    rhs_slice_target = (object_ptr)&_5592;
    RHS_Slice((s1_ptr)_a1, 2, _5592);
    DeRef(_5583);
    _2 = (int)SEQ_PTR(_7class_table);
    _5583 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5583);
    _c = find(_5592, _5583);

    // 		sym = class_table[CLASS_SYM][c]
    DeRefDS(_5583);
    _2 = (int)SEQ_PTR(_7class_table);
    _5583 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5583);
    _2 = (int)SEQ_PTR(_5583);
    _sym = (int)*(((s1_ptr)_2)->base + _c);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 		sym = real_type( sym )
    _sym = _16real_type(_sym);

    // 		if length( SymTab[sym] ) > S_VTYPE then return 0 end if
    DeRefDS(_5583);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5583 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5583);
    _0 = _5583;
    _5583 = SEQ_PTR(_5583)->length;
    DeRef(_0);
    if (_5583 <= 14)
        goto L10;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRefDS(_5592);
    return 0;
L10:

    // 		c = match( a2, "iaso" )
    _c = e_match(_a2, _5628);

    // 		if sym = integer_type then
    if (_sym != _11integer_type)
        goto L11;

    // 			if c = 1 then return 1	
    if (_c != 1)
        goto L12;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 1;
    goto L2;
L12:

    // 			elsif c = 2 then return 0
    if (_c != 2)
        goto L13;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
L13:

    // 			elsif c = 4 then return 0
    if (_c != 4)
        goto L14;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
L14:
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
L15:
    goto L2;
L11:

    // 		elsif sym = atom_type then
    if (_sym != _11atom_type)
        goto L16;

    // 			if c = 1 then return 0
    if (_c != 1)
        goto L17;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
L17:

    // 			elsif c = 2 then return 1
    if (_c != 2)
        goto L18;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 1;
    goto L2;
L18:

    // 			elsif c = 4 then return 0
    if (_c != 4)
        goto L19;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
L19:
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
L1A:
    goto L2;
L16:

    // 		elsif sym = sequence_type then
    if (_sym != _11sequence_type)
        goto L2;

    // 			if c = 3 then return 1
    if (_c != 3)
        goto L1B;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 1;
    goto L2;
L1B:

    // 			elsif c = 4 then return 0
    if (_c != 4)
        goto L1C;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
L1C:
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
L1D:
L1E:
L1F:
    goto L2;
LF:

    // 	elsif a1[1] = '!' then
    DeRef(_5583);
    _2 = (int)SEQ_PTR(_a1);
    _5583 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5583);
    if (binary_op_a(NOTEQ, _5583, 33))
        goto L20;

    // 		return 0
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2;
L20:

    // 		c = match( a1, "iaso" )
    _c = e_match(_a1, _5628);

    // 		d = match( a2, "iaso" )
    _d = e_match(_a2, _5628);

    // 		if c = d then return 1 end if
    if (_c != _d)
        goto L21;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 1;
L21:

    // 		if d = 2 then
    if (_d != 2)
        goto L22;

    // 			if c = 1 then return 1
    if (_c != 1)
        goto L23;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 1;
    goto L24;
L23:

    // 			elsif c = 4 then return 0
    if (_c != 4)
        goto L25;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L24;
L25:
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
L26:
    goto L24;
L22:

    // 		elsif d = 1 then
    if (_d != 1)
        goto L27;

    // 			if c = 4 then return 0
    if (_c != 4)
        goto L28;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L24;
L28:

    // 			elsif c = 2 then return 0
    if (_c != 2)
        goto L29;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L24;
L29:
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
L2A:
    goto L24;
L27:

    // 			if c < 3 then return {}
    if (_c >= 3)
        goto L2B;
    RefDS(_39);
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return _39;
    goto L2C;
L2B:

    // 			elsif c = 4 then return 0
    if (_c != 4)
        goto L2D;
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 0;
    goto L2C;
L2D:
    DeRefDS(_a1);
    DeRefDS(_a2);
    DeRef(_base_type);
    DeRef(_5583);
    DeRef(_5592);
    return 1;
L2C:
L24:
L2:
    ;
}


int _16PolyMorph(int _class_)
{
    int _csym;
    int _mlist = 0;
    int _real_list = 0;
    int _temp_list = 0;
    int _candidates = 0;
    int _ma_list = 0;
    int _methods = 0;
    int _name = 0;
    int _ok;
    int _parent;
    int _5694 = 0;
    int _5695 = 0;
    int _5671 = 0;
    int _5676 = 0;
    int _5683 = 0;
    int _5654 = 0;
    int _0, _1, _2, _3;
    

    // 	if class_table[CLASS_NAME][class_][1] = '_' then
    _2 = (int)SEQ_PTR(_7class_table);
    _5654 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5654);
    _0 = _5654;
    _2 = (int)SEQ_PTR(_5654);
    _5654 = (int)*(((s1_ptr)_2)->base + _class_);
    Ref(_5654);
    DeRefDS(_0);
    _0 = _5654;
    _2 = (int)SEQ_PTR(_5654);
    _5654 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5654);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _5654, 95))
        goto L1;

    // 		class_ = class_table[CLASS_SEQUENCEOF][class_]
    DeRef(_5654);
    _2 = (int)SEQ_PTR(_7class_table);
    _5654 = (int)*(((s1_ptr)_2)->base + 7);
    RefDS(_5654);
    _2 = (int)SEQ_PTR(_5654);
    _class_ = (int)*(((s1_ptr)_2)->base + _class_);
    if (!IS_ATOM_INT(_class_))
        _class_ = (long)DBL_PTR(_class_)->dbl;
L1:

    // 	csym = class_table[CLASS_SYM][class_]
    DeRef(_5654);
    _2 = (int)SEQ_PTR(_7class_table);
    _5654 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5654);
    _2 = (int)SEQ_PTR(_5654);
    _csym = (int)*(((s1_ptr)_2)->base + _class_);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    //     mlist = class_table[CLASS_METHOD][class_]
    DeRefDS(_5654);
    _2 = (int)SEQ_PTR(_7class_table);
    _5654 = (int)*(((s1_ptr)_2)->base + 2);
    RefDS(_5654);
    DeRef(_mlist);
    _2 = (int)SEQ_PTR(_5654);
    _mlist = (int)*(((s1_ptr)_2)->base + _class_);
    Ref(_mlist);

    //     real_list = method_args[$]
    DeRefDS(_5654);
    _5654 = SEQ_PTR(_7method_args)->length;
    DeRef(_real_list);
    _2 = (int)SEQ_PTR(_7method_args);
    _real_list = (int)*(((s1_ptr)_2)->base + _5654);
    Ref(_real_list);

    //     candidates = {}
    RefDS(_39);
    DeRef(_candidates);
    _candidates = _39;

    //     methods = method_table[METHOD_NAME]
    DeRef(_methods);
    _2 = (int)SEQ_PTR(_7method_table);
    _methods = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_methods);

    // 	name = method_name[$] & '@'
    _5654 = SEQ_PTR(_7method_name)->length;
    _2 = (int)SEQ_PTR(_7method_name);
    _5654 = (int)*(((s1_ptr)_2)->base + _5654);
    Ref(_5654);
    if (IS_SEQUENCE(_5654) && IS_ATOM(64)) {
        Append(&_name, _5654, 64);
    }
    else if (IS_ATOM(_5654) && IS_SEQUENCE(64)) {
    }
    else {
        Concat((object_ptr)&_name, _5654, (s1_ptr)64);
    }

    //     for m = 1 to length(mlist) do
    DeRef(_5654);
    _5654 = SEQ_PTR(_mlist)->length;
    { int _m;
        _m = 1;
L2:
        if (_m > _5654)
            goto L3;

        //     	if match( name, methods[mlist[m]]) = 1 then
        DeRef(_5671);
        _2 = (int)SEQ_PTR(_mlist);
        _5671 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5671);
        _0 = _5671;
        _2 = (int)SEQ_PTR(_methods);
        if (!IS_ATOM_INT(_5671))
            _5671 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5671)->dbl));
        else
            _5671 = (int)*(((s1_ptr)_2)->base + _5671);
        Ref(_5671);
        DeRef(_0);
        _0 = _5671;
        _5671 = e_match(_name, _5671);
        DeRef(_0);
        if (_5671 != 1)
            goto L4;

        // 	    	temp_list = real_list
        RefDS(_real_list);
        DeRef(_temp_list);
        _temp_list = _real_list;

        // 	    	ma_list = method_table[METHOD_ARGLIST][mlist[m]]
        _2 = (int)SEQ_PTR(_7method_table);
        _5671 = (int)*(((s1_ptr)_2)->base + 2);
        RefDS(_5671);
        DeRef(_5676);
        _2 = (int)SEQ_PTR(_mlist);
        _5676 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5676);
        DeRef(_ma_list);
        _2 = (int)SEQ_PTR(_5671);
        if (!IS_ATOM_INT(_5676))
            _ma_list = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5676)->dbl));
        else
            _ma_list = (int)*(((s1_ptr)_2)->base + _5676);
        Ref(_ma_list);

        // 	    	if length(temp_list) = length(ma_list) then
        DeRef(_5676);
        _5676 = SEQ_PTR(_temp_list)->length;
        DeRefDS(_5671);
        _5671 = SEQ_PTR(_ma_list)->length;
        if (_5676 != _5671)
            goto L5;

        // 		    	ok = 1
        _ok = 1;

        // 		    	for arg = 1 to length(temp_list) do
        _5671 = SEQ_PTR(_temp_list)->length;
        { int _arg;
            _arg = 1;
L6:
            if (_arg > _5671)
                goto L7;

            // 		    		temp_list[arg] = ArgLCD( temp_list[arg], ma_list[arg] )
            DeRef(_5676);
            _2 = (int)SEQ_PTR(_temp_list);
            _5676 = (int)*(((s1_ptr)_2)->base + _arg);
            Ref(_5676);
            DeRef(_5683);
            _2 = (int)SEQ_PTR(_ma_list);
            _5683 = (int)*(((s1_ptr)_2)->base + _arg);
            Ref(_5683);
            Ref(_5676);
            Ref(_5683);
            _0 = _5683;
            _5683 = _16ArgLCD(_5676, _5683);
            DeRef(_0);
            Ref(_5683);
            _2 = (int)SEQ_PTR(_temp_list);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _temp_list = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + _arg);
            _1 = *(int *)_2;
            *(int *)_2 = _5683;
            DeRef(_1);

            // 		    		if sequence( temp_list[arg] ) then
            DeRef(_5683);
            _2 = (int)SEQ_PTR(_temp_list);
            _5683 = (int)*(((s1_ptr)_2)->base + _arg);
            Ref(_5683);
            _0 = _5683;
            _5683 = IS_SEQUENCE(_5683);
            DeRef(_0);
            if (_5683 == 0)
                goto L8;

            // 		    			ok = 0
            _ok = 0;

            // 		    			exit
            goto L7;
L8:

            // 		    	end for
            _arg = _arg + 1;
            goto L6;
L7:
            ;
        }

        // 		    	if ok then
        if (_ok == 0)
            goto L9;

        // 		    		candidates = append( candidates, {0, mlist[m]})
        DeRef(_5683);
        _2 = (int)SEQ_PTR(_mlist);
        _5683 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5683);
        _0 = _5683;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = 0;
        ((int *)_2)[2] = _5683;
        Ref(_5683);
        _5683 = MAKE_SEQ(_1);
        DeRef(_0);
        RefDS(_5683);
        Append(&_candidates, _candidates, _5683);

        // 		    		for q = 1 to length(real_list) do
        DeRefDS(_5683);
        _5683 = SEQ_PTR(_real_list)->length;
        { int _q;
            _q = 1;
LA:
            if (_q > _5683)
                goto LB;

            // 		    			candidates[$][1] += temp_list[q]
            DeRef(_5676);
            _5676 = SEQ_PTR(_candidates)->length;
            _2 = (int)SEQ_PTR(_candidates);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _candidates = MAKE_SEQ(_2);
            }
            _3 = (int)(_5676 + ((s1_ptr)_2)->base);
            DeRef(_5694);
            _2 = (int)SEQ_PTR(_temp_list);
            _5694 = (int)*(((s1_ptr)_2)->base + _q);
            Ref(_5694);
            DeRef(_5695);
            _2 = (int)SEQ_PTR(*(int *)_3);
            _5695 = (int)*(((s1_ptr)_2)->base + 1);
            Ref(_5695);
            _0 = _5695;
            if (IS_ATOM_INT(_5695) && IS_ATOM_INT(_5694)) {
                _5695 = _5695 + _5694;
                if ((long)((unsigned long)_5695 + (unsigned long)HIGH_BITS) >= 0) 
                    _5695 = NewDouble((double)_5695);
            }
            else {
                _5695 = binary_op(PLUS, _5695, _5694);
            }
            DeRef(_0);
            Ref(_5695);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 1);
            _1 = *(int *)_2;
            *(int *)_2 = _5695;
            DeRef(_1);

            // 		    		end for
            _q = _q + 1;
            goto LA;
LB:
            ;
        }
L9:
L5:
L4:

        //     end for
        _m = _m + 1;
        goto L2;
L3:
        ;
    }

    //     if length( candidates ) > 1 then
    DeRef(_5695);
    _5695 = SEQ_PTR(_candidates)->length;
    if (_5695 <= 1)
        goto LC;

    //     	candidates = sort( candidates )
    RefDS(_candidates);
    _0 = _candidates;
    _candidates = _14sort(_candidates);
    DeRefDS(_0);

    //     	if not candidates[$][1] then
    _5695 = SEQ_PTR(_candidates)->length;
    _2 = (int)SEQ_PTR(_candidates);
    _5695 = (int)*(((s1_ptr)_2)->base + _5695);
    Ref(_5695);
    _0 = _5695;
    _2 = (int)SEQ_PTR(_5695);
    _5695 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5695);
    DeRef(_0);
    if (IS_ATOM_INT(_5695)) {
        if (_5695 != 0)
            goto LD;
    }
    else {
        if (DBL_PTR(_5695)->dbl != 0.0)
            goto LD;
    }

    // 			Warning(sprintf("%s:%d - ambiguous method call", 
    DeRef(_5695);
    _2 = (int)SEQ_PTR(_7file_name);
    _5695 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_5695);
    Ref(_5695);
    _0 = _5695;
    _5695 = _11name_ext(_5695);
    DeRef(_0);
    _0 = _5695;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _5695;
    RefDS(_5695);
    ((int *)_2)[2] = _7line_number;
    _5695 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _5695;
    _5695 = EPrintf(-9999999, _5704, _5695);
    DeRefDS(_0);
    RefDS(_5695);
    _9Warning(_5695);
LE:
    goto LD;
LC:

    //     elsif not length( candidates ) then
    DeRef(_5695);
    _5695 = SEQ_PTR(_candidates)->length;
    if (_5695 != 0)
        goto LF;

    //     	parent = class_table[CLASS_PARENT][class_]
    _2 = (int)SEQ_PTR(_7class_table);
    _5695 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_5695);
    _2 = (int)SEQ_PTR(_5695);
    _parent = (int)*(((s1_ptr)_2)->base + _class_);
    if (!IS_ATOM_INT(_parent))
        _parent = (long)DBL_PTR(_parent)->dbl;

    //     	if not parent then
    if (_parent != 0)
        goto L10;

    //     		CompileErr(sprintf( "method '%s' does not exist", {SymTab[method_stack[current_method][T_SYM]][S_NAME]}))
    DeRefDS(_5695);
    _2 = (int)SEQ_PTR(_7method_stack);
    _5695 = (int)*(((s1_ptr)_2)->base + _7current_method);
    RefDS(_5695);
    _0 = _5695;
    _2 = (int)SEQ_PTR(_5695);
    _5695 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5695);
    DeRefDS(_0);
    _0 = _5695;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5695))
        _5695 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5695)->dbl));
    else
        _5695 = (int)*(((s1_ptr)_2)->base + _5695);
    Ref(_5695);
    DeRef(_0);
    _0 = _5695;
    _2 = (int)SEQ_PTR(_5695);
    _5695 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5695);
    DeRef(_0);
    _0 = _5695;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_5695);
    *((int *)(_2+4)) = _5695;
    _5695 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _5695;
    _5695 = EPrintf(-9999999, _5714, _5695);
    DeRefDS(_0);
    RefDS(_5695);
    _9CompileErr(_5695);

    //     		return 0
    DeRef(_mlist);
    DeRef(_real_list);
    DeRef(_temp_list);
    DeRefDS(_candidates);
    DeRef(_ma_list);
    DeRef(_methods);
    DeRef(_name);
    DeRefDSi(_5695);
    DeRef5(_5694, _5671, _5676, _5683, _5654);
    return 0;
    goto L11;
L10:

    //     		return PolyMorph( parent )
    _0 = _5695;
    _5695 = _16PolyMorph(_parent);
    DeRef(_0);
    DeRef(_mlist);
    DeRef(_real_list);
    DeRef(_temp_list);
    DeRef(_candidates);
    DeRef(_ma_list);
    DeRef(_methods);
    DeRef(_name);
    DeRef5(_5694, _5671, _5676, _5683, _5654);
    return _5695;
L11:
LF:
LD:

    //     return method_table[METHOD_SYM][candidates[$][2]]
    DeRef(_5695);
    _2 = (int)SEQ_PTR(_7method_table);
    _5695 = (int)*(((s1_ptr)_2)->base + 3);
    RefDS(_5695);
    DeRef(_5694);
    _5694 = SEQ_PTR(_candidates)->length;
    _2 = (int)SEQ_PTR(_candidates);
    _5694 = (int)*(((s1_ptr)_2)->base + _5694);
    Ref(_5694);
    _0 = _5694;
    _2 = (int)SEQ_PTR(_5694);
    _5694 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5694);
    DeRef(_0);
    _0 = _5694;
    _2 = (int)SEQ_PTR(_5695);
    if (!IS_ATOM_INT(_5694))
        _5694 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5694)->dbl));
    else
        _5694 = (int)*(((s1_ptr)_2)->base + _5694);
    Ref(_5694);
    DeRef(_0);
    DeRef(_mlist);
    DeRef(_real_list);
    DeRef(_temp_list);
    DeRefDS(_candidates);
    DeRef(_ma_list);
    DeRef(_methods);
    DeRef(_name);
    DeRefDS(_5695);
    DeRef(_5671);
    DeRef(_5676);
    DeRef(_5683);
    DeRef(_5654);
    return _5694;
    ;
}


int _16MethodSlice(int _tok)
{
    int _save_factors;
    int _save_lhs_subs_level;
    int _5727 = 0;
    int _0, _1, _2;
    

    // 	while tok[T_ID] = LEFT_SQUARE do
L1:
    DeRef(_5727);
    _2 = (int)SEQ_PTR(_tok);
    _5727 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5727);
    if (binary_op_a(NOTEQ, _5727, -28))
        goto L2;

    // 	    if lhs_subs_level >= 0 then
    if (_16lhs_subs_level < 0)
        goto L3;

    // 			lhs_subs_level += 1
    _16lhs_subs_level = _16lhs_subs_level + 1;
L3:

    // 	    save_factors = factors
    _save_factors = _16factors;

    // 	    save_lhs_subs_level = lhs_subs_level
    _save_lhs_subs_level = _16lhs_subs_level;

    // 	    parse_method_stack &= 0
    Append(&_7parse_method_stack, _7parse_method_stack, 0);

    // 	    call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 	    parse_method_stack = parse_method_stack[1..$-1]
    DeRef(_5727);
    _5727 = SEQ_PTR(_7parse_method_stack)->length;
    _5727 = _5727 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _5727);

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 	    if tok[T_ID] = SLICE then
    _2 = (int)SEQ_PTR(_tok);
    _5727 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5727);
    if (binary_op_a(NOTEQ, _5727, 516))
        goto L4;

    // 			call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 			emit_op(RHS_SLICE)
    _15emit_op(46);

    // 			tok_match(RIGHT_SQUARE)
    _16tok_match(-29);

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 			exit
    goto L2;
    goto L5;
L4:

    // 			putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 			tok_match(RIGHT_SQUARE)
    _16tok_match(-29);

    // 			if member_stack[$] = -0.5 then
    DeRef(_5727);
    _5727 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5727 = (int)*(((s1_ptr)_2)->base + _5727);
    Ref(_5727);
    if (binary_op_a(NOTEQ, _5727, _3926))
        goto L6;
    goto L7;
L6:

    // 				PopMember()
    _15PopMember();
L7:
L5:

    // 	    factors = save_factors
    _16factors = _save_factors;

    // 	    lhs_subs_level = save_lhs_subs_level
    _16lhs_subs_level = _save_lhs_subs_level;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 	end while
    goto L1;
L2:

    // 	return tok
    DeRef(_5727);
    return _tok;
    ;
}


int _16read_backwards(int _tok1)
{
    int _brackets;
    int _5743 = 0;
    int _0, _1, _2;
    

    // 	brackets = line_tokens[tok1][T_ID] = RIGHT_SQUARE
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5743 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5743);
    _0 = _5743;
    _2 = (int)SEQ_PTR(_5743);
    _5743 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5743);
    DeRefDS(_0);
    if (IS_ATOM_INT(_5743)) {
        _brackets = (_5743 == -29);
    }
    else {
        _brackets = binary_op(EQUALS, _5743, -29);
    }
    if (!IS_ATOM_INT(_brackets)) {
        _1 = (long)(DBL_PTR(_brackets)->dbl);
        DeRefDS(_brackets);
        _brackets = _1;
    }

    // 	while tok1 and brackets do
L1:
    if (_tok1 == 0) {
        goto L2;
    }
L3:
    if (_brackets == 0)
        goto L2;

    // 		tok1 -= 1
    _tok1 = _tok1 - 1;

    // 		brackets += line_tokens[tok1][T_ID] = RIGHT_SQUARE
    DeRef(_5743);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5743 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5743);
    _0 = _5743;
    _2 = (int)SEQ_PTR(_5743);
    _5743 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5743);
    DeRefDS(_0);
    _0 = _5743;
    if (IS_ATOM_INT(_5743)) {
        _5743 = (_5743 == -29);
    }
    else {
        _5743 = binary_op(EQUALS, _5743, -29);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5743)) {
        _brackets = _brackets + _5743;
    }
    else {
        _brackets = binary_op(PLUS, _brackets, _5743);
    }
    if (!IS_ATOM_INT(_brackets)) {
        _1 = (long)(DBL_PTR(_brackets)->dbl);
        DeRefDS(_brackets);
        _brackets = _1;
    }

    // 		brackets -= line_tokens[tok1][T_ID] = LEFT_SQUARE
    DeRef(_5743);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5743 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5743);
    _0 = _5743;
    _2 = (int)SEQ_PTR(_5743);
    _5743 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5743);
    DeRefDS(_0);
    _0 = _5743;
    if (IS_ATOM_INT(_5743)) {
        _5743 = (_5743 == -28);
    }
    else {
        _5743 = binary_op(EQUALS, _5743, -28);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5743)) {
        _brackets = _brackets - _5743;
    }
    else {
        _brackets = binary_op(MINUS, _brackets, _5743);
    }
    if (!IS_ATOM_INT(_brackets)) {
        _1 = (long)(DBL_PTR(_brackets)->dbl);
        DeRefDS(_brackets);
        _brackets = _1;
    }

    // 	end while
    goto L1;
L2:

    // 	return tok1 - 1
    DeRef(_5743);
    _5743 = _tok1 - 1;
    if ((long)((unsigned long)_5743 +(unsigned long) HIGH_BITS) >= 0)
        _5743 = NewDouble((double)_5743);
    return _5743;
    ;
}


int _16num_zeroes(int _s)
{
    int _z;
    int _5758 = 0;
    int _5757;
    int _0, _1, _2;
    

    // 	z = 0
    _z = 0;

    // 	for i = 1 to length(s) do
    _5757 = SEQ_PTR(_s)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _5757)
            goto L2;

        // 		if equal( s[i], 0 ) then
        DeRef(_5758);
        _2 = (int)SEQ_PTR(_s);
        _5758 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5758);
        _0 = _5758;
        if (_5758 == 0)
            _5758 = 1;
        else if (IS_ATOM_INT(_5758) && IS_ATOM_INT(0))
            _5758 = 0;
        else
            _5758 = (compare(_5758, 0) == 0);
        DeRef(_0);
        if (_5758 == 0)
            goto L3;

        // 			z += 1
        _z = _z + 1;
L3:

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	return z
    DeRefDS(_s);
    DeRef(_5758);
    return _z;
    ;
}


