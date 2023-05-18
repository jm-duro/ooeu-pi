// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _11HidePrivates(int _sub, int _hide)
{
    int _sym;
    int _s2;
    int _hashval;
    int _1414 = 0;
    int _1411 = 0;
    int _1431 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_sub)) {
        _1 = (long)(DBL_PTR(_sub)->dbl);
        DeRefDS(_sub);
        _sub = _1;
    }
    if (!IS_ATOM_INT(_hide)) {
        _1 = (long)(DBL_PTR(_hide)->dbl);
        DeRefDS(_hide);
        _hide = _1;
    }

    // 	sym = SymTab[sub][S_NEXT]
    _2 = (int)SEQ_PTR(_7SymTab);
    _1411 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_1411);
    _2 = (int)SEQ_PTR(_1411);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	while sym and find(SymTab[sym][S_SCOPE], { SC_PRIVATE, SC_LOOP_VAR}) do
L1:
    if (_sym == 0) {
        goto L2;
    }
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1414 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1414);
    _0 = _1414;
    _2 = (int)SEQ_PTR(_1414);
    _1414 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1414);
    DeRef(_0);
    _0 = _1414;
    _1414 = find(_1414, _1416);
    DeRef(_0);
L3:
    if (_1414 == 0)
        goto L2;

    // 		hashval = SymTab[sym][S_HASHVAL]
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1414 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1414);
    _2 = (int)SEQ_PTR(_1414);
    _hashval = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_hashval))
        _hashval = (long)DBL_PTR(_hashval)->dbl;

    // 		if hide then
    if (_hide == 0)
        goto L4;

    // 			s2 = buckets[hashval]
    _2 = (int)SEQ_PTR(_11buckets);
    _s2 = (int)*(((s1_ptr)_2)->base + _hashval);
    if (!IS_ATOM_INT(_s2))
        _s2 = (long)DBL_PTR(_s2)->dbl;

    // 			if s2 = sym then
    if (_s2 != _sym)
        goto L5;

    // 				buckets[hashval] = SymTab[sym][S_SAMEHASH]
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1414 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1414);
    _0 = _1414;
    _2 = (int)SEQ_PTR(_1414);
    _1414 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1414);
    DeRef(_0);
    Ref(_1414);
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _hashval);
    _1 = *(int *)_2;
    *(int *)_2 = _1414;
    DeRef(_1);
    goto L6;
L5:

    // 				while SymTab[s2][S_SAMEHASH] do
L7:
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1414 = (int)*(((s1_ptr)_2)->base + _s2);
    Ref(_1414);
    _0 = _1414;
    _2 = (int)SEQ_PTR(_1414);
    _1414 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1414);
    DeRef(_0);
    if (_1414 <= 0) {
        if (_1414 == 0) {
            goto L6;
        }
        else {
            if (!IS_ATOM_INT(_1414) && DBL_PTR(_1414)->dbl == 0.0)
                goto L6;
        }
    }

    // 					if SymTab[s2][S_SAMEHASH] = sym then
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1414 = (int)*(((s1_ptr)_2)->base + _s2);
    Ref(_1414);
    _0 = _1414;
    _2 = (int)SEQ_PTR(_1414);
    _1414 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1414);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1414, _sym))
        goto L8;

    // 						SymTab[s2][S_SAMEHASH] = SymTab[sym][S_SAMEHASH]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s2 + ((s1_ptr)_2)->base);
    DeRef(_1431);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1431 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1431);
    _0 = _1431;
    _2 = (int)SEQ_PTR(_1431);
    _1431 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1431);
    DeRef(_0);
    Ref(_1431);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _1431;
    DeRef(_1);

    // 						exit
    goto L6;
L8:

    // 					s2 = SymTab[s2][S_SAMEHASH]
    DeRef(_1431);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1431 = (int)*(((s1_ptr)_2)->base + _s2);
    Ref(_1431);
    _2 = (int)SEQ_PTR(_1431);
    _s2 = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_s2))
        _s2 = (long)DBL_PTR(_s2)->dbl;

    // 				end while
    goto L7;
L9:
LA:
    goto L6;
L4:

    // 			SymTab[sym][S_SAMEHASH] = buckets[hashval]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_11buckets);
    _1414 = (int)*(((s1_ptr)_2)->base + _hashval);
    Ref(_1414);
    Ref(_1414);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _1414;
    DeRef(_1);

    // 			buckets[hashval] = sym
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _hashval);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);
L6:

    // 		sym = SymTab[sym][S_NEXT]
    DeRef(_1414);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1414 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1414);
    _2 = (int)SEQ_PTR(_1414);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	end while
    goto L1;
L2:

    // end procedure
    DeRef(_1414);
    DeRef(_1411);
    DeRef(_1431);
    return 0;
    ;
}


int _11HideLocals()
{
    int _s;
    int _1444 = 0;
    int _1440 = 0;
    int _0, _1, _2;
    

    //     s = file_start_sym
    _s = _7file_start_sym;

    //     while s do 
L1:
    if (_s == 0)
        goto L2;

    // 	if SymTab[s][S_SCOPE] = SC_LOCAL and 
    DeRef(_1440);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1440 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1440);
    _0 = _1440;
    _2 = (int)SEQ_PTR(_1440);
    _1440 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1440);
    DeRef(_0);
    _0 = _1440;
    if (IS_ATOM_INT(_1440)) {
        _1440 = (_1440 == 5);
    }
    else {
        _1440 = binary_op(EQUALS, _1440, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1440)) {
        if (_1440 == 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_1440)->dbl == 0.0) {
            goto L3;
        }
    }
    DeRef(_1444);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1444 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1444);
    _0 = _1444;
    _2 = (int)SEQ_PTR(_1444);
    _1444 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1444);
    DeRef(_0);
    _0 = _1444;
    if (IS_ATOM_INT(_1444)) {
        _1444 = (_1444 == _7current_file_no);
    }
    else {
        _1444 = binary_op(EQUALS, _1444, _7current_file_no);
    }
    DeRef(_0);
L4:
    if (_1444 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_1444) && DBL_PTR(_1444)->dbl == 0.0)
            goto L3;
    }

    // 	    Hide(s)
    _11Hide(_s);

    // 	    if SymTab[s][S_TOKEN] = VARIABLE then
    DeRef(_1444);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1444 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1444);
    _0 = _1444;
    _2 = (int)SEQ_PTR(_1444);
    _1444 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_1444);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1444, -100))
        goto L5;

    // 		LintCheck(s)
    _11LintCheck(_s);
L5:
L3:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_1444);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1444 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1444);
    _2 = (int)SEQ_PTR(_1444);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    // end procedure
    DeRef(_1444);
    DeRef(_1440);
    return 0;
    ;
}


int _11ExitScope()
{
    int _s;
    int _1452 = 0;
    int _1455 = 0;
    int _0, _1, _2;
    

    //     s = SymTab[CurrentSub][S_NEXT]
    _2 = (int)SEQ_PTR(_7SymTab);
    _1452 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_1452);
    _2 = (int)SEQ_PTR(_1452);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s and SymTab[s][S_SCOPE] = SC_PRIVATE do
L1:
    if (_s == 0) {
        goto L2;
    }
    DeRef(_1455);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1455 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1455);
    _0 = _1455;
    _2 = (int)SEQ_PTR(_1455);
    _1455 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1455);
    DeRef(_0);
    _0 = _1455;
    if (IS_ATOM_INT(_1455)) {
        _1455 = (_1455 == 3);
    }
    else {
        _1455 = binary_op(EQUALS, _1455, 3);
    }
    DeRef(_0);
L3:
    if (_1455 <= 0) {
        if (_1455 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_1455) && DBL_PTR(_1455)->dbl == 0.0)
                goto L2;
        }
    }

    // 		Hide(s) 
    _11Hide(_s);

    // 		LintCheck(s)
    _11LintCheck(_s);

    // 		s = SymTab[s][S_NEXT]
    DeRef(_1455);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1455 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_1455);
    _2 = (int)SEQ_PTR(_1455);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    //     for i = 1 to length(hide_member[$]) do
    DeRef(_1455);
    _1455 = SEQ_PTR(_7hide_member)->length;
    _2 = (int)SEQ_PTR(_7hide_member);
    _1455 = (int)*(((s1_ptr)_2)->base + _1455);
    Ref(_1455);
    _0 = _1455;
    _1455 = SEQ_PTR(_1455)->length;
    DeRef(_0);
    { int _i;
        _i = 1;
L4:
        if (_i > _1455)
            goto L5;

        //     	Hide( hide_member[$][i] )
        DeRef(_1452);
        _1452 = SEQ_PTR(_7hide_member)->length;
        _2 = (int)SEQ_PTR(_7hide_member);
        _1452 = (int)*(((s1_ptr)_2)->base + _1452);
        Ref(_1452);
        _0 = _1452;
        _2 = (int)SEQ_PTR(_1452);
        _1452 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1452);
        DeRef(_0);
        Ref(_1452);
        _11Hide(_1452);

        //     end for
        _i = _i + 1;
        goto L4;
L5:
        ;
    }

    //     hide_member = hide_member[1..$-1]
    DeRef(_1452);
    _1452 = SEQ_PTR(_7hide_member)->length;
    _1452 = _1452 - 1;
    rhs_slice_target = (object_ptr)&_7hide_member;
    RHS_Slice((s1_ptr)_7hide_member, 1, _1452);

    // end procedure
    DeRef(_1455);
    return 0;
    ;
}


int _11new_class(int _sym)
{
    int _class_ix;
    int _parent;
    int _mx;
    int _vtype;
    int _entry = 0;
    int _1469 = 0;
    int _1475 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	for i = 1 to CLASS_ENTRY do
    { int _i;
        _i = 1;
L1:
        if (_i > 7)
            goto L2;

        // 		class_table[i] = append( class_table[i], {} )
        DeRef(_1469);
        _2 = (int)SEQ_PTR(_7class_table);
        _1469 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_1469);
        RefDS(_39);
        Append(&_1469, _1469, _39);
        RefDS(_1469);
        _2 = (int)SEQ_PTR(_7class_table);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _1469;
        DeRefDS(_1);

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	class_ix = length(class_table[1])
    DeRef(_1469);
    _2 = (int)SEQ_PTR(_7class_table);
    _1469 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1469);
    _class_ix = SEQ_PTR(_1469)->length;

    // 	class_table[CLASS_NAME][class_ix] = SymTab[sym][S_NAME]
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(1 + ((s1_ptr)_2)->base);
    DeRef(_1475);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1475 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1475);
    _0 = _1475;
    _2 = (int)SEQ_PTR(_1475);
    _1475 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1475);
    DeRef(_0);
    Ref(_1475);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _class_ix);
    _1 = *(int *)_2;
    *(int *)_2 = _1475;
    DeRef(_1);

    // 	vtype = SymTab[sym][S_VTYPE]
    DeRef(_1475);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1475 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1475);
    _2 = (int)SEQ_PTR(_1475);
    _vtype = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_vtype))
        _vtype = (long)DBL_PTR(_vtype)->dbl;

    // 	class_table[CLASS_VARTYPE][class_ix] = vtype
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(5 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _class_ix);
    _1 = *(int *)_2;
    *(int *)_2 = _vtype;
    DeRef(_1);

    // 	class_table[CLASS_PARENT][class_ix] = find( vtype, class_table[CLASS_SYM] )
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(4 + ((s1_ptr)_2)->base);
    DeRefDS(_1469);
    _2 = (int)SEQ_PTR(_7class_table);
    _1469 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1469);
    _0 = _1469;
    _1469 = find(_vtype, _1469);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _class_ix);
    _1 = *(int *)_2;
    *(int *)_2 = _1469;
    DeRef(_1);

    // 	if find( vtype, class_table[CLASS_SYM] ) then
    _2 = (int)SEQ_PTR(_7class_table);
    _1469 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1469);
    _0 = _1469;
    _1469 = find(_vtype, _1469);
    DeRefDS(_0);
    if (_1469 == 0)
        goto L3;

    // 		if vtype = class_ix then
    if (_vtype != _class_ix)
        goto L4;

    // 			CompileErr("a class must be of a distinct type")
    RefDS(_1488);
    _9CompileErr(_1488);

    // 			return 0
    DeRef(_entry);
    DeRef(_1475);
    return 0;
L4:

    // 		add_ref( {CLASS, vtype})
    DeRef(_1469);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 421;
    ((int *)_2)[2] = _vtype;
    _1469 = MAKE_SEQ(_1);
    RefDS(_1469);
    _11add_ref(_1469);

    // 		parent = class_table[CLASS_PARENT][class_ix]
    DeRefDSi(_1469);
    _2 = (int)SEQ_PTR(_7class_table);
    _1469 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_1469);
    _2 = (int)SEQ_PTR(_1469);
    _parent = (int)*(((s1_ptr)_2)->base + _class_ix);
    if (!IS_ATOM_INT(_parent))
        _parent = (long)DBL_PTR(_parent)->dbl;

    // 		for i = 1 to length(member_table[1]) do
    DeRefDS(_1469);
    _2 = (int)SEQ_PTR(_7member_table);
    _1469 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1469);
    _0 = _1469;
    _1469 = SEQ_PTR(_1469)->length;
    DeRef(_0);
    { int _i;
        _i = 1;
L5:
        if (_i > _1469)
            goto L6;

        // 		end for
        _i = _i + 1;
        goto L5;
L6:
        ;
    }
L3:

    // 	class_table[CLASS_SYM][class_ix] = sym
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(6 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _class_ix);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);

    // 	class_table[CLASS_SEQUENCEOF][class_ix] = 0
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(7 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _class_ix);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	return class_ix
    DeRef(_entry);
    DeRef(_1469);
    DeRef(_1475);
    return _class_ix;
    ;
}


int _11is_sequenceof(int _sym)
{
    int _class;
    int _type_sym;
    int _1498 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	if not sym then
    if (_sym != 0)
        goto L1;

    // 		return 0
    return 0;
L1:

    // 	type_sym = SymTab[sym][S_VTYPE]
    DeRef(_1498);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1498 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1498);
    _2 = (int)SEQ_PTR(_1498);
    _type_sym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;

    // 	class = find( type_sym, class_table[CLASS_SYM] )
    DeRef(_1498);
    _2 = (int)SEQ_PTR(_7class_table);
    _1498 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1498);
    _class = find(_type_sym, _1498);

    // 	if not class then
    if (_class != 0)
        goto L2;

    // 		return 0
    DeRefDS(_1498);
    return 0;
L2:

    // 	return class_table[CLASS_NAME][class][1] = '_'
    DeRef(_1498);
    _2 = (int)SEQ_PTR(_7class_table);
    _1498 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1498);
    _0 = _1498;
    _2 = (int)SEQ_PTR(_1498);
    _1498 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_1498);
    DeRefDS(_0);
    _0 = _1498;
    _2 = (int)SEQ_PTR(_1498);
    _1498 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1498);
    DeRef(_0);
    _0 = _1498;
    if (IS_ATOM_INT(_1498)) {
        _1498 = (_1498 == 95);
    }
    else {
        _1498 = binary_op(EQUALS, _1498, 95);
    }
    DeRef(_0);
    return _1498;
    ;
}


int _11member_stack_is_sequenceof()
{
    int _ms;
    int _class;
    int _1508 = 0;
    int _1510 = 0;
    int _0, _1, _2;
    

    // 	ms = length(member_stack)
    _ms = SEQ_PTR(_7member_stack)->length;

    // 	while ms and member_stack[ms] < 0 do
L1:
    if (_ms == 0) {
        goto L2;
    }
    DeRef(_1510);
    _2 = (int)SEQ_PTR(_7member_stack);
    _1510 = (int)*(((s1_ptr)_2)->base + _ms);
    Ref(_1510);
    _0 = _1510;
    if (IS_ATOM_INT(_1510)) {
        _1510 = (_1510 < 0);
    }
    else {
        _1510 = binary_op(LESS, _1510, 0);
    }
    DeRef(_0);
L3:
    if (_1510 <= 0) {
        if (_1510 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_1510) && DBL_PTR(_1510)->dbl == 0.0)
                goto L2;
        }
    }

    // 		ms -= 1
    _ms = _ms - 1;

    // 	end while
    goto L1;
L2:

    // 	if ms = 0  or member_stack[ms] = 0 then
    DeRef(_1510);
    _1510 = (_ms == 0);
    if (_1510 != 0) {
        goto L4;
    }
    DeRef(_1508);
    _2 = (int)SEQ_PTR(_7member_stack);
    _1508 = (int)*(((s1_ptr)_2)->base + _ms);
    Ref(_1508);
    _0 = _1508;
    if (IS_ATOM_INT(_1508)) {
        _1508 = (_1508 == 0);
    }
    else {
        _1508 = binary_op(EQUALS, _1508, 0);
    }
    DeRef(_0);
L5:
    if (_1508 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_1508) && DBL_PTR(_1508)->dbl == 0.0)
            goto L6;
    }
L4:

    // 		return 0
    DeRef(_1508);
    DeRef(_1510);
    return 0;
L6:

    // 	ms = member_table[MEMBER_SYM][member_stack[ms]]
    DeRef(_1508);
    _2 = (int)SEQ_PTR(_7member_table);
    _1508 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_1508);
    DeRef(_1510);
    _2 = (int)SEQ_PTR(_7member_stack);
    _1510 = (int)*(((s1_ptr)_2)->base + _ms);
    Ref(_1510);
    _2 = (int)SEQ_PTR(_1508);
    if (!IS_ATOM_INT(_1510))
        _ms = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1510)->dbl));
    else
        _ms = (int)*(((s1_ptr)_2)->base + _1510);
    if (!IS_ATOM_INT(_ms))
        _ms = (long)DBL_PTR(_ms)->dbl;

    // 	class = find( SymTab[ms][S_VTYPE], class_table[CLASS_SYM] )
    DeRef(_1510);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1510 = (int)*(((s1_ptr)_2)->base + _ms);
    Ref(_1510);
    _0 = _1510;
    _2 = (int)SEQ_PTR(_1510);
    _1510 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_1510);
    DeRef(_0);
    DeRef(_1508);
    _2 = (int)SEQ_PTR(_7class_table);
    _1508 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1508);
    _class = find(_1510, _1508);

    // 	if not class then
    if (_class != 0)
        goto L7;

    // 		return 0
    DeRefDS(_1508);
    DeRef(_1510);
    return 0;
L7:

    // 	return class_table[CLASS_NAME][class][1] = '_'
    DeRef(_1508);
    _2 = (int)SEQ_PTR(_7class_table);
    _1508 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1508);
    _0 = _1508;
    _2 = (int)SEQ_PTR(_1508);
    _1508 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_1508);
    DeRefDS(_0);
    _0 = _1508;
    _2 = (int)SEQ_PTR(_1508);
    _1508 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1508);
    DeRef(_0);
    _0 = _1508;
    if (IS_ATOM_INT(_1508)) {
        _1508 = (_1508 == 95);
    }
    else {
        _1508 = binary_op(EQUALS, _1508, 95);
    }
    DeRef(_0);
    DeRef(_1510);
    return _1508;
    ;
}


int _11member_is_sequenceof(int _member)
{
    int _class;
    int _1529 = 0;
    int _1532 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_member)) {
        _1 = (long)(DBL_PTR(_member)->dbl);
        DeRefDS(_member);
        _member = _1;
    }

    // 	if member <= 0 then
    if (_member > 0)
        goto L1;

    // 		return 0
    return 0;
L1:

    // 	class = find(member_table[MEMBER_VARTYPE][member], class_table[CLASS_SYM] )
    DeRef(_1529);
    _2 = (int)SEQ_PTR(_7member_table);
    _1529 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1529);
    _0 = _1529;
    _2 = (int)SEQ_PTR(_1529);
    _1529 = (int)*(((s1_ptr)_2)->base + _member);
    Ref(_1529);
    DeRef(_0);
    DeRef(_1532);
    _2 = (int)SEQ_PTR(_7class_table);
    _1532 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1532);
    _class = find(_1529, _1532);

    // 	if class and class_table[CLASS_NAME][class][1] = '_' then
    if (_class == 0) {
        goto L2;
    }
    DeRef(_1529);
    _2 = (int)SEQ_PTR(_7class_table);
    _1529 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1529);
    _0 = _1529;
    _2 = (int)SEQ_PTR(_1529);
    _1529 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_1529);
    DeRefDS(_0);
    _0 = _1529;
    _2 = (int)SEQ_PTR(_1529);
    _1529 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1529);
    DeRef(_0);
    _0 = _1529;
    if (IS_ATOM_INT(_1529)) {
        _1529 = (_1529 == 95);
    }
    else {
        _1529 = binary_op(EQUALS, _1529, 95);
    }
    DeRef(_0);
L3:
    if (_1529 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_1529) && DBL_PTR(_1529)->dbl == 0.0)
            goto L2;
    }

    // 		return 1
    DeRef(_1529);
    DeRef(_1532);
    return 1;
L2:

    // 	return 0
    DeRef(_1529);
    DeRef(_1532);
    return 0;
    ;
}


int _11sequence_of_class(int _class)
{
    int _soc;
    int _1539 = 0;
    int _1550 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_class)) {
        _1 = (long)(DBL_PTR(_class)->dbl);
        DeRefDS(_class);
        _class = _1;
    }

    // 	if not class then
    if (_class != 0)
        goto L1;

    // 		return 0
    return 0;
L1:

    // 	soc = class_table[CLASS_SEQUENCEOF][class]
    DeRef(_1539);
    _2 = (int)SEQ_PTR(_7class_table);
    _1539 = (int)*(((s1_ptr)_2)->base + 7);
    RefDS(_1539);
    _2 = (int)SEQ_PTR(_1539);
    _soc = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_soc))
        _soc = (long)DBL_PTR(_soc)->dbl;

    // 	if not soc then
    if (_soc != 0)
        goto L2;

    // 		SymTab = append( SymTab, SymTab[class_table[CLASS_SYM][class]] )
    DeRefDS(_1539);
    _2 = (int)SEQ_PTR(_7class_table);
    _1539 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1539);
    _0 = _1539;
    _2 = (int)SEQ_PTR(_1539);
    _1539 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_1539);
    DeRefDS(_0);
    _0 = _1539;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_1539))
        _1539 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1539)->dbl));
    else
        _1539 = (int)*(((s1_ptr)_2)->base + _1539);
    Ref(_1539);
    DeRef(_0);
    Ref(_1539);
    Append(&_7SymTab, _7SymTab, _1539);

    // 		SymTab[$][S_NAME] = prepend( SymTab[$][S_NAME], '_' )
    DeRef(_1539);
    _1539 = SEQ_PTR(_7SymTab)->length;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_1539 + ((s1_ptr)_2)->base);
    DeRef(_1550);
    _1550 = SEQ_PTR(_7SymTab)->length;
    _2 = (int)SEQ_PTR(_7SymTab);
    _1550 = (int)*(((s1_ptr)_2)->base + _1550);
    Ref(_1550);
    _0 = _1550;
    _2 = (int)SEQ_PTR(_1550);
    _1550 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1550);
    DeRef(_0);
    Prepend(&_1550, _1550, 95);
    RefDS(_1550);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _1550;
    DeRef(_1);

    // 	    if last_sym then
    if (_11last_sym == 0)
        goto L3;

    // 			SymTab[last_sym][S_NEXT] = length(SymTab)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_11last_sym + ((s1_ptr)_2)->base);
    _1539 = SEQ_PTR(_7SymTab)->length;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1539;
    DeRef(_1);
L3:

    // 	    last_sym = length(SymTab)
    _11last_sym = SEQ_PTR(_7SymTab)->length;

    // 	    soc = new_class( last_sym )
    _soc = _11new_class(_11last_sym);

    // 	    class_table[CLASS_SEQUENCEOF][class] = soc
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(7 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _class);
    _1 = *(int *)_2;
    *(int *)_2 = _soc;
    DeRef(_1);

    // 	    class_table[CLASS_SEQUENCEOF][soc] = class
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(7 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _soc);
    _1 = *(int *)_2;
    *(int *)_2 = _class;
    DeRef(_1);
L2:

    // 	return soc
    DeRef(_1539);
    DeRef(_1550);
    return _soc;
    ;
}


int _11sym_to_class(int _sym)
{
    int _1563 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	return find( sym, class_table[CLASS_SYM] )
    _2 = (int)SEQ_PTR(_7class_table);
    _1563 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1563);
    _0 = _1563;
    _1563 = find(_sym, _1563);
    DeRefDS(_0);
    return _1563;
    ;
}


int _11var_class(int _sym)
{
    int _1570 = 0;
    int _1565 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	if length(SymTab[sym]) < S_VTYPE then
    _2 = (int)SEQ_PTR(_7SymTab);
    _1565 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1565);
    _0 = _1565;
    _1565 = SEQ_PTR(_1565)->length;
    DeRef(_0);
    if (_1565 >= 14)
        goto L1;

    // 		return 0
    return 0;
L1:

    // 	return find( SymTab[sym][S_VTYPE], class_table[CLASS_SYM] )
    DeRef(_1565);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1565 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1565);
    _0 = _1565;
    _2 = (int)SEQ_PTR(_1565);
    _1565 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_1565);
    DeRef(_0);
    DeRef(_1570);
    _2 = (int)SEQ_PTR(_7class_table);
    _1570 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1570);
    _0 = _1570;
    _1570 = find(_1565, _1570);
    DeRefDS(_0);
    DeRef(_1565);
    return _1570;
    ;
}


int _11add_method(int _sym)
{
    int _method;
    int _ix;
    int _decorated = 0;
    int _alist = 0;
    int _1572 = 0;
    int _1586 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	for i = 1 to METHOD_ENTRY do
    { int _i;
        _i = 1;
L1:
        if (_i > 4)
            goto L2;

        // 		method_table[i] = append( method_table[i], {} )
        DeRef(_1572);
        _2 = (int)SEQ_PTR(_7method_table);
        _1572 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_1572);
        RefDS(_39);
        Append(&_1572, _1572, _39);
        RefDS(_1572);
        _2 = (int)SEQ_PTR(_7method_table);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _1572;
        DeRefDS(_1);

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	decorated = SymTab[sym][S_NAME]
    DeRef(_1572);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1572 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1572);
    DeRef(_decorated);
    _2 = (int)SEQ_PTR(_1572);
    _decorated = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_decorated);

    // 	method = length(method_table[1])
    DeRef(_1572);
    _2 = (int)SEQ_PTR(_7method_table);
    _1572 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1572);
    _method = SEQ_PTR(_1572)->length;

    // 	method_table[METHOD_NAME][method] = decorated
    _2 = (int)SEQ_PTR(_7method_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_table = MAKE_SEQ(_2);
    }
    _3 = (int)(1 + ((s1_ptr)_2)->base);
    RefDS(_decorated);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _method);
    _1 = *(int *)_2;
    *(int *)_2 = _decorated;
    DeRef(_1);

    // 	method_table[METHOD_CLASS][method] = current_class
    _2 = (int)SEQ_PTR(_7method_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_table = MAKE_SEQ(_2);
    }
    _3 = (int)(4 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _method);
    _1 = *(int *)_2;
    *(int *)_2 = _7current_class;
    DeRef(_1);

    // 	method_table[METHOD_SYM][method] = sym
    _2 = (int)SEQ_PTR(_7method_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_table = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _method);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);

    // 	class_table[CLASS_METHOD][current_class] &= method
    _2 = (int)SEQ_PTR(_7class_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7class_table = MAKE_SEQ(_2);
    }
    _3 = (int)(2 + ((s1_ptr)_2)->base);
    DeRef(_1586);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1586 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_1586);
    if (IS_SEQUENCE(_1586) && IS_ATOM(_method)) {
        Append(&_1586, _1586, _method);
    }
    else if (IS_ATOM(_1586) && IS_SEQUENCE(_method)) {
    }
    else {
        Concat((object_ptr)&_1586, _1586, (s1_ptr)_method);
    }
    RefDS(_1586);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _7current_class);
    _1 = *(int *)_2;
    *(int *)_2 = _1586;
    DeRef(_1);

    // 	ix = find( '@', decorated )
    _ix = find(64, _decorated);

    // 	if compare( decorated[1..ix-1], class_table[CLASS_NAME][current_class]) then
    DeRefDS(_1586);
    _1586 = _ix - 1;
    rhs_slice_target = (object_ptr)&_1586;
    RHS_Slice((s1_ptr)_decorated, 1, _1586);
    DeRefDS(_1572);
    _2 = (int)SEQ_PTR(_7class_table);
    _1572 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1572);
    _0 = _1572;
    _2 = (int)SEQ_PTR(_1572);
    _1572 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_1572);
    DeRefDS(_0);
    _0 = _1572;
    if (IS_ATOM_INT(_1586) && IS_ATOM_INT(_1572))
        _1572 = (_1586 < _1572) ? -1 : (_1586 > _1572);
    else
        _1572 = compare(_1586, _1572);
    DeRef(_0);
    if (_1572 == 0)
        goto L3;

    // 		decorated = decorated[ix+1..$]
    _1572 = _ix + 1;
    DeRefDS(_1586);
    _1586 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, _1572, _1586);

    // 		ix = find( '@', decorated )
    _ix = find(64, _decorated);

    // 		decorated = decorated[ix+1..$]
    _1586 = _ix + 1;
    _1572 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, _1586, _1572);
    goto L4;
L3:

    // 		decorated = decorated[ix+1..$]
    DeRef(_1572);
    _1572 = _ix + 1;
    DeRef(_1586);
    _1586 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, _1572, _1586);
L4:

    // 	alist = {}
    RefDS(_39);
    DeRef(_alist);
    _alist = _39;

    // 	while length( decorated ) do
L5:
    DeRef(_1586);
    _1586 = SEQ_PTR(_decorated)->length;
    if (_1586 == 0)
        goto L6;

    // 		if decorated[1] = '@' then
    _2 = (int)SEQ_PTR(_decorated);
    _1586 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1586);
    if (binary_op_a(NOTEQ, _1586, 64))
        goto L7;

    // 			decorated = decorated[2..$]
    DeRef(_1586);
    _1586 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, 2, _1586);

    // 			ix = find( '@', decorated )
    _ix = find(64, _decorated);

    // 			alist = append( alist, '@' & decorated[1..ix] )
    rhs_slice_target = (object_ptr)&_1586;
    RHS_Slice((s1_ptr)_decorated, 1, _ix);
    Prepend(&_1586, _1586, 64);
    RefDS(_1586);
    Append(&_alist, _alist, _1586);

    // 			decorated = decorated[ix+1..$]
    DeRefDS(_1586);
    _1586 = _ix + 1;
    DeRef(_1572);
    _1572 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, _1586, _1572);
    goto L5;
L7:

    // 		elsif decorated[1] = '!' then
    DeRef(_1572);
    _2 = (int)SEQ_PTR(_decorated);
    _1572 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1572);
    if (binary_op_a(NOTEQ, _1572, 33))
        goto L8;

    // 			decorated = decorated[2..$]
    DeRef(_1572);
    _1572 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, 2, _1572);

    // 			ix = find( '!', decorated )
    _ix = find(33, _decorated);

    // 			alist = append( alist, '!' & decorated[1..ix] )
    rhs_slice_target = (object_ptr)&_1572;
    RHS_Slice((s1_ptr)_decorated, 1, _ix);
    Prepend(&_1572, _1572, 33);
    RefDS(_1572);
    Append(&_alist, _alist, _1572);

    // 			decorated = decorated[ix+1..$]			
    DeRefDS(_1572);
    _1572 = _ix + 1;
    DeRef(_1586);
    _1586 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, _1572, _1586);
    goto L5;
L8:

    // 			alist = append( alist, {decorated[1]})
    DeRef(_1586);
    _2 = (int)SEQ_PTR(_decorated);
    _1586 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1586);
    _0 = _1586;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_1586);
    *((int *)(_2+4)) = _1586;
    _1586 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_1586);
    Append(&_alist, _alist, _1586);

    // 			decorated = decorated[2..$]
    DeRefDS(_1586);
    _1586 = SEQ_PTR(_decorated)->length;
    rhs_slice_target = (object_ptr)&_decorated;
    RHS_Slice((s1_ptr)_decorated, 2, _1586);
L9:

    // 	end while
    goto L5;
L6:

    // 	method_table[METHOD_ARGLIST][method] = alist
    _2 = (int)SEQ_PTR(_7method_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_table = MAKE_SEQ(_2);
    }
    _3 = (int)(2 + ((s1_ptr)_2)->base);
    RefDS(_alist);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _method);
    _1 = *(int *)_2;
    *(int *)_2 = _alist;
    DeRef(_1);

    // end procedure
    DeRef(_decorated);
    DeRefDS(_alist);
    DeRef(_1572);
    DeRef(_1586);
    return 0;
    ;
}


int _11member_count(int _class)
{
    int _count;
    int _classes = 0;
    int _1640 = 0;
    int _1634 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_class)) {
        _1 = (long)(DBL_PTR(_class)->dbl);
        DeRefDS(_class);
        _class = _1;
    }

    // 	if class = 0 then
    if (_class != 0)
        goto L1;

    // 		return 0
    return 0;
L1:

    // 	count = member_count( class_table[CLASS_PARENT][class] )
    DeRef(_1634);
    _2 = (int)SEQ_PTR(_7class_table);
    _1634 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_1634);
    _0 = _1634;
    _2 = (int)SEQ_PTR(_1634);
    _1634 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_1634);
    DeRefDS(_0);
    Ref(_1634);
    _count = _11member_count(_1634);

    // 	classes = member_table[MEMBER_CLASS]
    DeRef(_classes);
    _2 = (int)SEQ_PTR(_7member_table);
    _classes = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_classes);

    // 	for i = 1 to length(classes) do
    DeRef(_1634);
    _1634 = SEQ_PTR(_classes)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _1634)
            goto L3;

        // 		if classes[i] = class then
        DeRef(_1640);
        _2 = (int)SEQ_PTR(_classes);
        _1640 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1640);
        if (binary_op_a(NOTEQ, _1640, _class))
            goto L4;

        // 			count += 1
        _count = _count + 1;
L4:

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	return count
    DeRef(_classes);
    DeRef(_1640);
    DeRef(_1634);
    return _count;
    ;
}


int _11add_member(int _sym)
{
    int _class;
    int _mx;
    int _1650 = 0;
    int _1643 = 0;
    int _1644 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	class = current_class
    _class = _7current_class;

    // 	for i = 1 to MEMBER_ENTRY do
    { int _i;
        _i = 1;
L1:
        if (_i > 5)
            goto L2;

        // 		member_table[i] &= {{}}
        _0 = _1643;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_39);
        *((int *)(_2+4)) = _39;
        _1643 = MAKE_SEQ(_1);
        DeRef(_0);
        DeRef(_1644);
        _2 = (int)SEQ_PTR(_7member_table);
        _1644 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1644);
        if (IS_SEQUENCE(_1644) && IS_ATOM(_1643)) {
        }
        else if (IS_ATOM(_1644) && IS_SEQUENCE(_1643)) {
            Ref(_1644);
            Prepend(&_1644, _1643, _1644);
        }
        else {
            Concat((object_ptr)&_1644, _1644, (s1_ptr)_1643);
        }
        RefDS(_1644);
        _2 = (int)SEQ_PTR(_7member_table);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _1644;
        DeRef(_1);

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	mx = length(member_table[1])
    DeRef(_1644);
    _2 = (int)SEQ_PTR(_7member_table);
    _1644 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1644);
    _mx = SEQ_PTR(_1644)->length;

    // 	member_table[MEMBER_NAME][mx] = SymTab[sym][S_NAME]
    _2 = (int)SEQ_PTR(_7member_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7member_table = MAKE_SEQ(_2);
    }
    _3 = (int)(1 + ((s1_ptr)_2)->base);
    DeRef(_1650);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1650 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1650);
    _0 = _1650;
    _2 = (int)SEQ_PTR(_1650);
    _1650 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1650);
    DeRef(_0);
    Ref(_1650);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _mx);
    _1 = *(int *)_2;
    *(int *)_2 = _1650;
    DeRef(_1);

    // 	member_table[MEMBER_CLASS][mx] = class
    _2 = (int)SEQ_PTR(_7member_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7member_table = MAKE_SEQ(_2);
    }
    _3 = (int)(2 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _mx);
    _1 = *(int *)_2;
    *(int *)_2 = _class;
    DeRef(_1);

    // 	member_table[MEMBER_VARTYPE][mx] = SymTab[sym][S_VTYPE]
    _2 = (int)SEQ_PTR(_7member_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7member_table = MAKE_SEQ(_2);
    }
    _3 = (int)(3 + ((s1_ptr)_2)->base);
    DeRef(_1644);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1644 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1644);
    _0 = _1644;
    _2 = (int)SEQ_PTR(_1644);
    _1644 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_1644);
    DeRef(_0);
    Ref(_1644);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _mx);
    _1 = *(int *)_2;
    *(int *)_2 = _1644;
    DeRef(_1);

    // 	SymTab[sym][S_OBJ] = member_count( class )
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _0 = _1643;
    _1643 = _11member_count(_class);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _1643;
    DeRef(_1);

    // 	SymTab[sym][S_SCOPE] = SC_GLOBAL
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
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 6;
    DeRef(_1);

    // 	SymTab[sym][S_MODE] = M_CONSTANT
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
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	member_table[MEMBER_SYM][mx] = sym
    _2 = (int)SEQ_PTR(_7member_table);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7member_table = MAKE_SEQ(_2);
    }
    _3 = (int)(5 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _mx);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);

    // 	return mx
    DeRef(_1650);
    DeRef(_1644);
    return _mx;
    ;
}


int _11is_member(int _tok)
{
    int _sym;
    int _classtype;
    int _class;
    int _ix;
    int _name = 0;
    int _members = 0;
    int _1672 = 0;
    int _1667 = 0;
    int _0, _1, _2, _3;
    

    // 	sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	class = 0
    _class = 0;

    // 	if member_stack[$] > 0 then
    _1667 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _1667 = (int)*(((s1_ptr)_2)->base + _1667);
    Ref(_1667);
    if (binary_op_a(LESSEQ, _1667, 0))
        goto L1;

    // 		classtype = member_table[MEMBER_VARTYPE][member_stack[$]]
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7member_table);
    _1667 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1667);
    _1672 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    _2 = (int)SEQ_PTR(_1667);
    if (!IS_ATOM_INT(_1672))
        _classtype = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1672)->dbl));
    else
        _classtype = (int)*(((s1_ptr)_2)->base + _1672);
    if (!IS_ATOM_INT(_classtype))
        _classtype = (long)DBL_PTR(_classtype)->dbl;

    // 		class = find( classtype, class_table[CLASS_SYM] )
    DeRef(_1672);
    _2 = (int)SEQ_PTR(_7class_table);
    _1672 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1672);
    _class = find(_classtype, _1672);
    goto L2;
L1:

    // 	elsif member_stack[$] < 0 then
    DeRef(_1672);
    _1672 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    if (binary_op_a(GREATEREQ, _1672, 0))
        goto L3;

    // 		ix = length(member_stack)
    _ix = SEQ_PTR(_7member_stack)->length;

    // 		while ix and member_stack[ix] < 0 do
L4:
    if (_ix == 0) {
        goto L5;
    }
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7member_stack);
    _1667 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_1667);
    _0 = _1667;
    if (IS_ATOM_INT(_1667)) {
        _1667 = (_1667 < 0);
    }
    else {
        _1667 = binary_op(LESS, _1667, 0);
    }
    DeRef(_0);
L6:
    if (_1667 <= 0) {
        if (_1667 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_1667) && DBL_PTR(_1667)->dbl == 0.0)
                goto L5;
        }
    }

    // 			ix -= 1
    _ix = _ix - 1;

    // 		end while
    goto L4;
L5:

    // 		if not ix then
    if (_ix != 0)
        goto L7;

    // 			return 0
    DeRefDS(_tok);
    DeRef(_name);
    DeRef(_members);
    DeRef(_1672);
    DeRef(_1667);
    return 0;
L7:

    // 		if member_stack[ix] then
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7member_stack);
    _1667 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_1667);
    if (_1667 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_1667) && DBL_PTR(_1667)->dbl == 0.0)
            goto L8;
    }

    // 			classtype = member_table[MEMBER_VARTYPE][member_stack[ix]]
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7member_table);
    _1667 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1667);
    DeRef(_1672);
    _2 = (int)SEQ_PTR(_7member_stack);
    _1672 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_1672);
    _2 = (int)SEQ_PTR(_1667);
    if (!IS_ATOM_INT(_1672))
        _classtype = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1672)->dbl));
    else
        _classtype = (int)*(((s1_ptr)_2)->base + _1672);
    if (!IS_ATOM_INT(_classtype))
        _classtype = (long)DBL_PTR(_classtype)->dbl;
    goto L9;
L8:

    // 			if length( SymTab[current_instance[$]] ) = 5 then
    DeRef(_1672);
    _1672 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    _0 = _1672;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_1672))
        _1672 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1672)->dbl));
    else
        _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    DeRef(_0);
    _0 = _1672;
    _1672 = SEQ_PTR(_1672)->length;
    DeRef(_0);
    if (_1672 != 5)
        goto LA;
    goto LB;
LA:

    // 				classtype = SymTab[current_instance[$]][S_VTYPE]
    DeRef(_1672);
    _1672 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    _0 = _1672;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_1672))
        _1672 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1672)->dbl));
    else
        _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_1672);
    _classtype = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_classtype))
        _classtype = (long)DBL_PTR(_classtype)->dbl;
LB:
L9:

    // 		class = find( classtype, class_table[CLASS_SYM] )
    DeRef(_1672);
    _2 = (int)SEQ_PTR(_7class_table);
    _1672 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1672);
    _class = find(_classtype, _1672);
    goto L2;
L3:

    // 	elsif current_instance[$] then
    DeRef(_1672);
    _1672 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    if (_1672 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_1672) && DBL_PTR(_1672)->dbl == 0.0)
            goto LC;
    }

    // 		class = find( current_instance[$], class_table[CLASS_SYM] )
    DeRef(_1672);
    _1672 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _1672 = (int)*(((s1_ptr)_2)->base + _1672);
    Ref(_1672);
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7class_table);
    _1667 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1667);
    _class = find(_1672, _1667);

    // 		if not class then
    if (_class != 0)
        goto LD;

    // 			classtype = SymTab[current_instance[$]][S_VTYPE]
    DeRefDS(_1667);
    _1667 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _1667 = (int)*(((s1_ptr)_2)->base + _1667);
    Ref(_1667);
    _0 = _1667;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_1667))
        _1667 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1667)->dbl));
    else
        _1667 = (int)*(((s1_ptr)_2)->base + _1667);
    Ref(_1667);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_1667);
    _classtype = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_classtype))
        _classtype = (long)DBL_PTR(_classtype)->dbl;

    // 			class = find( classtype, class_table[CLASS_SYM] )
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7class_table);
    _1667 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_1667);
    _class = find(_classtype, _1667);
LD:
LC:
L2:

    // 	while class do
LE:
    if (_class == 0)
        goto LF;

    // 		if class_table[CLASS_NAME][class][1] = '_' then
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7class_table);
    _1667 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_1667);
    _0 = _1667;
    _2 = (int)SEQ_PTR(_1667);
    _1667 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_1667);
    DeRefDS(_0);
    _0 = _1667;
    _2 = (int)SEQ_PTR(_1667);
    _1667 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1667);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _1667, 95))
        goto L10;

    // 			class = class_table[CLASS_SEQUENCEOF][class]
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7class_table);
    _1667 = (int)*(((s1_ptr)_2)->base + 7);
    RefDS(_1667);
    _2 = (int)SEQ_PTR(_1667);
    _class = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;
L10:

    // 		members = member_table[MEMBER_CLASS]
    DeRef(_members);
    _2 = (int)SEQ_PTR(_7member_table);
    _members = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_members);

    // 		name = SymTab[sym][S_NAME]
    DeRef(_1667);
    _2 = (int)SEQ_PTR(_7SymTab);
    _1667 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_1667);
    DeRef(_name);
    _2 = (int)SEQ_PTR(_1667);
    _name = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_name);

    // 		for i = 1 to length(members) do
    DeRef(_1667);
    _1667 = SEQ_PTR(_members)->length;
    { int _i;
        _i = 1;
L11:
        if (_i > _1667)
            goto L12;

        // 			if members[i]  = class then
        DeRef(_1672);
        _2 = (int)SEQ_PTR(_members);
        _1672 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1672);
        if (binary_op_a(NOTEQ, _1672, _class))
            goto L13;

        // 				if equal( name, member_table[MEMBER_NAME][i] ) then
        DeRef(_1672);
        _2 = (int)SEQ_PTR(_7member_table);
        _1672 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_1672);
        _0 = _1672;
        _2 = (int)SEQ_PTR(_1672);
        _1672 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1672);
        DeRef(_0);
        _0 = _1672;
        if (_name == _1672)
            _1672 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_1672))
            _1672 = 0;
        else
            _1672 = (compare(_name, _1672) == 0);
        DeRef(_0);
        if (_1672 == 0)
            goto L14;

        // 					add_ref( {0, member_table[MEMBER_SYM][i]} )
        _2 = (int)SEQ_PTR(_7member_table);
        _1672 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_1672);
        _0 = _1672;
        _2 = (int)SEQ_PTR(_1672);
        _1672 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1672);
        DeRef(_0);
        _0 = _1672;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = 0;
        ((int *)_2)[2] = _1672;
        Ref(_1672);
        _1672 = MAKE_SEQ(_1);
        DeRef(_0);
        RefDS(_1672);
        _11add_ref(_1672);

        // 					SymTab[member_table[MEMBER_SYM][i]][S_USAGE] = U_READ
        DeRefDS(_1672);
        _2 = (int)SEQ_PTR(_7member_table);
        _1672 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_1672);
        _0 = _1672;
        _2 = (int)SEQ_PTR(_1672);
        _1672 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1672);
        DeRef(_0);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_1672))
            _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_1672)->dbl));
        else
            _3 = (int)(_1672 + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 5);
        _1 = *(int *)_2;
        *(int *)_2 = 1;
        DeRef(_1);

        // 					SymTab[sym][S_USAGE] = U_WRITTEN
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
        _2 = (int)(((s1_ptr)_2)->base + 5);
        _1 = *(int *)_2;
        *(int *)_2 = 2;
        DeRef(_1);

        // 					return i
        DeRefDS(_tok);
        DeRefDS(_name);
        DeRefDS(_members);
        DeRef(_1672);
        DeRef(_1667);
        return _i;
L14:
L13:

        // 		end for		
        _i = _i + 1;
        goto L11;
L12:
        ;
    }

    // 		class = class_table[CLASS_PARENT][class]
    DeRef(_1672);
    _2 = (int)SEQ_PTR(_7class_table);
    _1672 = (int)*(((s1_ptr)_2)->base + 4);
    RefDS(_1672);
    _2 = (int)SEQ_PTR(_1672);
    _class = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 	end while
    goto LE;
LF:

    // 	return 0
    DeRefDS(_tok);
    DeRef(_name);
    DeRef(_members);
    DeRef(_1672);
    DeRef(_1667);
    return 0;
    ;
}


