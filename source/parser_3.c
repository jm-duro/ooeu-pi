// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16SubProg(int _prog_type, int _is_global)
{
    int _h;
    int _pt;
    int _is_constructor;
    int _cached;
    int _p;
    int _type_sym;
    int _sym;
    int _tok = 0;
    int _prog_name = 0;
    int _decorated = 0;
    int _pdec = 0;
    int _by_ref = 0;
    int _class;
    int _seq_of_class;
    int _ix;
    int _tok1;
    int _tok2;
    int _is_ref;
    int _5413 = 0;
    int _5117 = 0;
    int _5125 = 0;
    int _5176 = 0;
    int _0, _1, _2, _3;
    

    // 	hide_member = append( hide_member, {} )
    RefDS(_39);
    Append(&_7hide_member, _7hide_member, _39);

    // 	by_ref = {}
    RefDS(_39);
    _by_ref = _39;

    //     goto_back_patch = append( goto_back_patch, {} )
    RefDS(_39);
    Append(&_7goto_back_patch, _7goto_back_patch, _39);

    // 	LeaveTopLevel()
    _16LeaveTopLevel();

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 		cache_line()
    _16cache_line();
L1:

    // 	if current_class then
    if (_7current_class == 0)
        goto L2;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 		if tok[T_ID] = MULTIPLY then
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    if (binary_op_a(NOTEQ, _5117, 13))
        goto L3;

    // 			by_ref &= 0
    Append(&_by_ref, _by_ref, 0);
    goto L4;
L3:

    // 			putback( tok )
    RefDS(_tok);
    _16putback(_tok);
L4:
L2:

    //     prog_name = next_token()
    _0 = _prog_name;
    _prog_name = _16next_token();
    DeRef1(_0);

    //     if not find(prog_name[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC}) then
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_prog_name);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    _0 = _5125;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    _5125 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _5125;
    _5125 = find(_5117, _5125);
    DeRef1(_0);
    if (_5125 != 0)
        goto L5;

    // 		CompileErr("a name is expected here")
    RefDS(_4798);
    _9CompileErr(_4798);

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L6;

    // 			release_line()
    _16release_line();
L6:

    // 		return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L5:

    //     p = prog_name[T_SYM] 
    _2 = (int)SEQ_PTR(_prog_name);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	is_constructor = 0
    _is_constructor = 0;

    // 	if current_class then
    if (_7current_class == 0)
        goto L7;

    // 		if find( prog_type, {CLASS, TYPE}) then
    DeRef1(_5125);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 421;
    ((int *)_2)[2] = 504;
    _5125 = MAKE_SEQ(_1);
    _0 = _5125;
    _5125 = find(_prog_type, _5125);
    DeRef1(_0);
    if (_5125 == 0)
        goto L8;

    // 			CompileErr( "cannot declare a class or a type from within a class" )
    RefDS(_5131);
    _9CompileErr(_5131);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L9;

    // 				release_line()
    _16release_line();
L9:

    // 			return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L8:

    // 		decorated = SymTab[p][S_NAME]
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    DeRef1(_decorated);
    _2 = (int)SEQ_PTR(_5125);
    _decorated = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_decorated);

    // 		if length(SymTab[p]) = SIZEOF_ROUTINE_ENTRY then
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    _0 = _5125;
    _5125 = SEQ_PTR(_5125)->length;
    DeRef1(_0);
    if (_5125 != 25)
        goto LA;

    // 			tok = keyfind( decorated & 127, -1 )
    Append(&_5125, _decorated, 127);
    RefDS(_5125);
    _0 = _tok;
    _tok = _11keyfind(_5125, -1);
    DeRef1(_0);

    // 			p = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;
LA:

    // 		if compare( decorated, class_table[CLASS_NAME][current_class] ) then
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7class_table);
    _5125 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_5125);
    DeRef1(_0);
    _0 = _5125;
    if (IS_ATOM_INT(_decorated) && IS_ATOM_INT(_5125))
        _5125 = (_decorated < _5125) ? -1 : (_decorated > _5125);
    else
        _5125 = compare(_decorated, _5125);
    DeRef1(_0);
    if (_5125 == 0)
        goto LB;

    // 			decorated &= '@' & class_table[CLASS_NAME][current_class] & '@'
    _2 = (int)SEQ_PTR(_7class_table);
    _5125 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_5125);
    DeRef1(_0);
    {
        int concat_list[3];

        concat_list[0] = 64;
        concat_list[1] = _5125;
        concat_list[2] = 64;
        Concat_N((object_ptr)&_5125, concat_list, 3);
    }
    Concat((object_ptr)&_decorated, _decorated, (s1_ptr)_5125);
    goto LC;
LB:

    // 			if prog_type = PROCEDURE then
    if (_prog_type != 405)
        goto LD;

    // 				CompileErr( "a constructor must be a function" )
    RefDS(_5148);
    _9CompileErr(_5148);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto LE;

    // 					release_line()
    _16release_line();
LE:

    // 				return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
LD:

    // 			is_constructor = 1
    _is_constructor = 1;

    // 			decorated &= '@'
    Append(&_decorated, _decorated, 64);
LF:
    goto LC;
L7:

    // 		DefinedYet(p)
    _11DefinedYet(_p);
LC:

    //     if prog_type = PROCEDURE then
    if (_prog_type != 405)
        goto L10;

    // 		pt = r:PROC
    _pt = 27;
    goto L11;
L10:

    //     elsif prog_type = FUNCTION then
    if (_prog_type != 406)
        goto L12;

    // 		pt = r:FUNC
    _pt = 501;
    goto L11;
L12:

    // 		pt = TYPE
    _pt = 504;
L11:

    //     if find(SymTab[p][S_SCOPE], {SC_PREDEF, SC_GLOBAL}) then
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5125);
    DeRef1(_0);
    _0 = _5125;
    _5125 = find(_5125, _5154);
    DeRef1(_0);
    if (_5125 == 0)
        goto L13;

    // 		if SymTab[p][S_SCOPE] = SC_PREDEF then  -- only warn about overriding predefined
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5125);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _5125, 7))
        goto L14;

    // 		    Warning(sprintf("built-in routine %s() redefined", 
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5125);
    DeRef1(_0);
    _0 = _5125;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_5125);
    *((int *)(_2+4)) = _5125;
    _5125 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _5125;
    _5125 = EPrintf(-9999999, _5159, _5125);
    DeRef1(_0);
    RefDS(_5125);
    _9Warning(_5125);
L14:

    // 		h = SymTab[p][S_HASHVAL]
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    _2 = (int)SEQ_PTR(_5125);
    _h = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 		sym = buckets[h]
    _2 = (int)SEQ_PTR(_11buckets);
    _sym = (int)*(((s1_ptr)_2)->base + _h);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 		p = NewEntry(SymTab[p][S_NAME], 0, 0, pt, h, sym, 0) 
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5125);
    DeRef1(_0);
    Ref(_5125);
    _p = _11NewEntry(_5125, 0, 0, _pt, _h, _sym, 0);

    // 		buckets[h] = p
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _h);
    _1 = *(int *)_2;
    *(int *)_2 = _p;
    DeRef(_1);
L13:

    //     CurrentSub = p
    _7CurrentSub = _p;

    //     temps_allocated = 0
    _11temps_allocated = 0;

    //     if is_global then
    if (_is_global == 0)
        goto L15;

    // 		SymTab[p][S_SCOPE] = SC_GLOBAL
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 6;
    DeRef(_1);
    goto L16;
L15:

    // 	elsif current_class and pt != CLASS then
    if (_7current_class == 0) {
        goto L17;
    }
    DeRef1(_5125);
    _5125 = (_pt != 421);
L18:
    if (_5125 == 0)
        goto L17;

    // 		SymTab[p][S_SCOPE] = SymTab[class_table[CLASS_SYM][current_class]][S_SCOPE]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_7class_table);
    _5176 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5176);
    _0 = _5176;
    _2 = (int)SEQ_PTR(_5176);
    _5176 = (int)*(((s1_ptr)_2)->base + _7current_class);
    Ref(_5176);
    DeRef1(_0);
    _0 = _5176;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5176))
        _5176 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5176)->dbl));
    else
        _5176 = (int)*(((s1_ptr)_2)->base + _5176);
    Ref(_5176);
    DeRef1(_0);
    _0 = _5176;
    _2 = (int)SEQ_PTR(_5176);
    _5176 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5176);
    DeRef1(_0);
    Ref(_5176);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _5176;
    DeRef(_1);
    goto L16;
L17:

    // 		SymTab[p][S_SCOPE] = SC_LOCAL
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);
L16:

    //     SymTab[p][S_TOKEN] = pt
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _pt;
    DeRef(_1);

    //     if length(SymTab[p]) < SIZEOF_ROUTINE_ENTRY then
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5176 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5176);
    _0 = _5176;
    _5176 = SEQ_PTR(_5176)->length;
    DeRef1(_0);
    if (_5176 >= 25)
        goto L19;

    // 		SymTab[p] = SymTab[p] & repeat(0, SIZEOF_ROUTINE_ENTRY - 
    _2 = (int)SEQ_PTR(_7SymTab);
    _5176 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5176);
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5117 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5117);
    _0 = _5117;
    _5117 = SEQ_PTR(_5117)->length;
    DeRef1(_0);
    _5117 = 25 - _5117;
    _5117 = Repeat(0, _5117);
    if (IS_SEQUENCE(_5176) && IS_ATOM(_5117)) {
    }
    else if (IS_ATOM(_5176) && IS_SEQUENCE(_5117)) {
        Ref(_5176);
        Prepend(&_5117, _5117, _5176);
    }
    else {
        Concat((object_ptr)&_5117, _5176, (s1_ptr)_5117);
    }
    RefDS(_5117);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _p);
    _1 = *(int *)_2;
    *(int *)_2 = _5117;
    DeRef(_1);
L19:

    //     SymTab[p][S_CODE] = 0
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_LINETAB] = 0
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_EFFECT] = E_PURE
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_REFLIST] = {}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
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

    //     SymTab[p][S_FIRSTLINE] = gline_number
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 17);
    _1 = *(int *)_2;
    *(int *)_2 = _7gline_number;
    DeRef(_1);

    //     SymTab[p][S_TEMPS] = 0
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_BYREF] = {}
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 25);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     StartSourceLine(FALSE)  
    _15StartSourceLine(0);

    //     tok_match(LEFT_ROUND)
    _16tok_match(-26);

    //     param_num = 0
    _16param_num = 0;

    //     if current_class and prog_type != CLASS and not is_constructor then
    if (_7current_class == 0) {
        DeRef1(_5176);
        _5176 = 0;
        goto L1A;
    }
    DeRef1(_5117);
    _5117 = (_prog_type != 421);
    _5176 = (_5117 != 0);
L1A:
    if (_5176 == 0) {
        goto L1B;
    }
    DeRef1(_5176);
    _5176 = (_is_constructor == 0);
L1C:
    if (_5176 == 0)
        goto L1B;

    //     	type_sym = class_table[CLASS_SYM][current_class]
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_7class_table);
    _5176 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5176);
    _2 = (int)SEQ_PTR(_5176);
    _type_sym = (int)*(((s1_ptr)_2)->base + _7current_class);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;

    // 		tok = keyfind( "this", -1 )
    RefDS(_5213);
    _0 = _tok;
    _tok = _11keyfind(_5213, -1);
    DeRef1(_0);

    // 		sym = SetPrivateScope( tok[T_SYM], type_sym, param_num )
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5176);
    Ref(_5176);
    _sym = _16SetPrivateScope(_5176, _type_sym, _16param_num);
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 		SymTab[sym][S_USAGE] = U_WRITTEN
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

    // 		if length( by_ref ) then
    DeRef1(_5117);
    _5117 = SEQ_PTR(_by_ref)->length;
    if (_5117 == 0)
        goto L1D;

    // 			by_ref[1] = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5117);
    Ref(_5117);
    _2 = (int)SEQ_PTR(_by_ref);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _by_ref = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _5117;
    DeRef(_1);
L1D:

    // 		param_num += 1
    _16param_num = _16param_num + 1;
L1B:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    //     while tok[T_ID] != RIGHT_ROUND do
L1E:
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    if (binary_op_a(EQUALS, _5117, -27))
        goto L1F;

    // 		if tok[T_ID] != TYPE and tok[T_ID] != QUALIFIED_TYPE then
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    _0 = _5117;
    if (IS_ATOM_INT(_5117)) {
        _5117 = (_5117 != 504);
    }
    else {
        _5117 = binary_op(NOTEQ, _5117, 504);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5117)) {
        if (_5117 == 0) {
            goto L20;
        }
    }
    else {
        if (DBL_PTR(_5117)->dbl == 0.0) {
            goto L20;
        }
    }
    DeRef(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5176);
    _0 = _5176;
    if (IS_ATOM_INT(_5176)) {
        _5176 = (_5176 != 526);
    }
    else {
        _5176 = binary_op(NOTEQ, _5176, 526);
    }
    DeRef(_0);
L21:
    if (_5176 == 0) {
        goto L20;
    }
    else {
        if (!IS_ATOM_INT(_5176) && DBL_PTR(_5176)->dbl == 0.0)
            goto L20;
    }

    // 		    if tok[T_ID] = VARIABLE or tok[T_ID] = QUALIFIED_VARIABLE then
    DeRef(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5176);
    _0 = _5176;
    if (IS_ATOM_INT(_5176)) {
        _5176 = (_5176 == -100);
    }
    else {
        _5176 = binary_op(EQUALS, _5176, -100);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5176)) {
        if (_5176 != 0) {
            goto L22;
        }
    }
    else {
        if (DBL_PTR(_5176)->dbl != 0.0) {
            goto L22;
        }
    }
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    _0 = _5117;
    if (IS_ATOM_INT(_5117)) {
        _5117 = (_5117 == 515);
    }
    else {
        _5117 = binary_op(EQUALS, _5117, 515);
    }
    DeRef(_0);
L23:
    if (_5117 == 0) {
        goto L24;
    }
    else {
        if (!IS_ATOM_INT(_5117) && DBL_PTR(_5117)->dbl == 0.0)
            goto L24;
    }
L22:

    // 				if UndefinedVar(tok[T_SYM]) then
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5117);
    Ref(_5117);
    _0 = _5117;
    _5117 = _16UndefinedVar(_5117);
    DeRef(_0);
    if (_5117 == 0)
        goto L25;

    // 					return
    DeRefDS(_tok);
    DeRef(_prog_name);
    DeRef(_decorated);
    DeRef(_pdec);
    DeRef(_by_ref);
    DeRef(_5413);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L25:
L24:

    // 		    CompileErr("a type is expected here")            
    RefDS(_5237);
    _9CompileErr(_5237);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L26;

    // 				release_line()
    _16release_line();
L26:

    // 		    return
    DeRef(_tok);
    DeRef(_prog_name);
    DeRef(_decorated);
    DeRef(_pdec);
    DeRef(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L20:

    // 		type_sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _type_sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 		is_ref = 0
    _is_ref = 0;

    // 		if tok[T_ID] = MULTIPLY then
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    if (binary_op_a(NOTEQ, _5117, 13))
        goto L27;

    // 			is_ref = 1
    _is_ref = 1;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);
L27:

    // 		if type_sym = sequence_type and tok[T_ID] = OF then
    DeRef(_5117);
    _5117 = (_type_sym == _11sequence_type);
    if (_5117 == 0) {
        goto L28;
    }
    DeRef(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5176);
    _0 = _5176;
    if (IS_ATOM_INT(_5176)) {
        _5176 = (_5176 == 424);
    }
    else {
        _5176 = binary_op(EQUALS, _5176, 424);
    }
    DeRef(_0);
L29:
    if (_5176 == 0) {
        goto L28;
    }
    else {
        if (!IS_ATOM_INT(_5176) && DBL_PTR(_5176)->dbl == 0.0)
            goto L28;
    }

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 			class = find( tok[T_SYM], class_table[CLASS_SYM] )
    DeRef(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5176);
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_7class_table);
    _5117 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5117);
    _class = find(_5176, _5117);

    // 			if not class then
    if (_class != 0)
        goto L2A;

    // 				CompileErr("expected a class name")
    RefDS(_5252);
    _9CompileErr(_5252);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L2B;

    // 					release_line()
    _16release_line();
L2B:

    // 				return
    DeRef(_tok);
    DeRef(_prog_name);
    DeRef(_decorated);
    DeRef(_pdec);
    DeRef(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L2A:

    // 			class = sequence_of_class( class )
    _class = _11sequence_of_class(_class);

    // 			type_sym = class_table[CLASS_SYM][class]
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_7class_table);
    _5117 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5117);
    _2 = (int)SEQ_PTR(_5117);
    _type_sym = (int)*(((s1_ptr)_2)->base + _class);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 			if tok[T_ID] = MULTIPLY then
    DeRefDS(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    if (binary_op_a(NOTEQ, _5117, 13))
        goto L2C;

    // 				is_ref = 1
    _is_ref = 1;

    // 				tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);
L2D:
    goto L2C;
L28:

    // 		elsif not find(tok[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC, NAMESPACE}) then
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    _0 = _5176;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    *((int *)(_2+20)) = 523;
    _5176 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _5176;
    _5176 = find(_5117, _5176);
    DeRefDSi(_0);
    if (_5176 != 0)
        goto L2E;

    // 		    CompileErr("a parameter name is expected here")
    RefDS(_5264);
    _9CompileErr(_5264);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L2F;

    // 				release_line()
    _16release_line();
L2F:

    // 		    return
    DeRef(_tok);
    DeRef(_prog_name);
    DeRef(_decorated);
    DeRef(_pdec);
    DeRef(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L2E:
L2C:

    // 		sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
    DeRef(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5176);
    Ref(_5176);
    _sym = _16SetPrivateScope(_5176, _type_sym, _16param_num);
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 		SymTab[sym][S_USAGE] = U_WRITTEN 
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

    // 		if prog_type = CLASS then
    if (_prog_type != 421)
        goto L30;

    // 			SymTab[p][S_VTYPE] = type_sym
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_sym;
    DeRef(_1);

    // 			SymTab[sym][S_NAME] &= " dummy variable for euclass declaration"
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    DeRef(_5125);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _5125 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5125);
    if (IS_SEQUENCE(_5125) && IS_ATOM(_5274)) {
    }
    else if (IS_ATOM(_5125) && IS_SEQUENCE(_5274)) {
        Ref(_5125);
        Prepend(&_5125, _5274, _5125);
    }
    else {
        Concat((object_ptr)&_5125, _5125, (s1_ptr)_5274);
    }
    RefDS(_5125);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _5125;
    DeRef(_1);
L30:

    // 		if is_ref then
    if (_is_ref == 0)
        goto L31;

    // 			by_ref &= sym
    Append(&_by_ref, _by_ref, _sym);
L31:

    // 		param_num += 1
    _16param_num = _16param_num + 1;

    // 		if current_class then
    if (_7current_class == 0)
        goto L32;

    // 			if type_sym = atom_type then
    if (_type_sym != _11atom_type)
        goto L33;

    // 				decorated &= 'a'
    Append(&_decorated, _decorated, 97);
    goto L34;
L33:

    // 			elsif type_sym = integer_type then
    if (_type_sym != _11integer_type)
        goto L35;

    // 				decorated &= 'i'
    Append(&_decorated, _decorated, 105);
    goto L34;
L35:

    // 			elsif type_sym = sequence_type then
    if (_type_sym != _11sequence_type)
        goto L36;

    // 				decorated &= 's'
    Append(&_decorated, _decorated, 115);
    goto L34;
L36:

    // 			elsif type_sym = object_type then
    if (_type_sym != _11object_type)
        goto L37;

    // 				decorated &= 'o'
    Append(&_decorated, _decorated, 111);
    goto L34;
L37:

    // 			elsif find( type_sym, class_table[CLASS_SYM]) then
    DeRef(_5125);
    _2 = (int)SEQ_PTR(_7class_table);
    _5125 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5125);
    _0 = _5125;
    _5125 = find(_type_sym, _5125);
    DeRefDS(_0);
    if (_5125 == 0)
        goto L38;

    // 				decorated &= '@' & SymTab[SymTab[sym][S_VTYPE]][S_NAME] & '@'
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_5125);
    DeRef(_0);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5125))
        _5125 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5125)->dbl));
    else
        _5125 = (int)*(((s1_ptr)_2)->base + _5125);
    Ref(_5125);
    DeRef(_0);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5125);
    DeRef(_0);
    {
        int concat_list[3];

        concat_list[0] = 64;
        concat_list[1] = _5125;
        concat_list[2] = 64;
        Concat_N((object_ptr)&_5125, concat_list, 3);
    }
    Concat((object_ptr)&_decorated, _decorated, (s1_ptr)_5125);
    goto L34;
L38:

    // 				decorated &= '!' & SymTab[SymTab[sym][S_VTYPE]][S_NAME] & '!'
    DeRef(_5125);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5125 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5125);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_5125);
    DeRef(_0);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5125))
        _5125 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5125)->dbl));
    else
        _5125 = (int)*(((s1_ptr)_2)->base + _5125);
    Ref(_5125);
    DeRef(_0);
    _0 = _5125;
    _2 = (int)SEQ_PTR(_5125);
    _5125 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5125);
    DeRef(_0);
    {
        int concat_list[3];

        concat_list[0] = 33;
        concat_list[1] = _5125;
        concat_list[2] = 33;
        Concat_N((object_ptr)&_5125, concat_list, 3);
    }
    Concat((object_ptr)&_decorated, _decorated, (s1_ptr)_5125);
L34:
L32:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] = COMMA then
    DeRef(_5125);
    _2 = (int)SEQ_PTR(_tok);
    _5125 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5125);
    if (binary_op_a(NOTEQ, _5125, -30))
        goto L39;

    // 		    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 		    if tok[T_ID] = RIGHT_ROUND then
    DeRef(_5125);
    _2 = (int)SEQ_PTR(_tok);
    _5125 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5125);
    if (binary_op_a(NOTEQ, _5125, -27))
        goto L1E;

    // 				CompileErr("expected to see a parameter declaration, not ')'")
    RefDS(_5307);
    _9CompileErr(_5307);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L3A;

    // 					release_line()
    _16release_line();
L3A:

    // 				return
    DeRef(_tok);
    DeRef(_prog_name);
    DeRef(_decorated);
    DeRef(_pdec);
    DeRef(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L3B:
    goto L1E;
L39:

    // 		elsif tok[T_ID] != RIGHT_ROUND then
    DeRef(_5125);
    _2 = (int)SEQ_PTR(_tok);
    _5125 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5125);
    if (binary_op_a(EQUALS, _5125, -27))
        goto L1E;

    // 		    CompileErr("badly-formed list of parameters - expected ',' or ')'")
    RefDS(_5310);
    _9CompileErr(_5310);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L3C;

    // 					release_line()
    _16release_line();
L3C:

    // 		    return
    DeRef(_tok);
    DeRef(_prog_name);
    DeRef(_decorated);
    DeRef(_pdec);
    DeRef(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L3D:
L3E:

    //     end while
    goto L1E;
L1F:

    // 	SymTab[p][S_BYREF] = by_ref
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_by_ref);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 25);
    _1 = *(int *)_2;
    *(int *)_2 = _by_ref;
    DeRef(_1);

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L3F;

    // 		if length(by_ref) then
    DeRef1(_5117);
    _5117 = SEQ_PTR(_by_ref)->length;
    if (_5117 == 0)
        goto L40;

    // 			CompileErr("cannot use pass by reference when proprocessing")
    RefDS(_5314);
    _9CompileErr(_5314);
L40:

    // 	if current_class then
    if (_7current_class == 0)
        goto L41;

    // 		ix = 1
    _ix = 1;

    // 		for t = length(line_tokens) to 1 by -1 do
    DeRef1(_5117);
    _5117 = SEQ_PTR(_7line_tokens)->length;
    { int _t;
        _t = _5117;
L42:
        if (_t < 1)
            goto L43;

        // 			if equal( line_tokens[t], {0,0} ) then
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5117 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_5117);
        DeRef(_5125);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = 0;
        ((int *)_2)[2] = 0;
        _5125 = MAKE_SEQ(_1);
        _0 = _5125;
        if (_5117 == _5125)
            _5125 = 1;
        else if (IS_ATOM_INT(_5117) && IS_ATOM_INT(_5125))
            _5125 = 0;
        else
            _5125 = (compare(_5117, _5125) == 0);
        DeRefDSi(_0);
        if (_5125 == 0)
            goto L44;

        // 				ix = t + 1
        _ix = _t + 1;

        // 				exit
        goto L43;
L44:

        // 		end for
        _t = _t + -1;
        goto L42;
L43:
        ;
    }

    // 		for t = ix to length( line_tokens ) do
    DeRef1(_5125);
    _5125 = SEQ_PTR(_7line_tokens)->length;
    { int _t;
        _t = _ix;
L45:
        if (_t > _5125)
            goto L46;

        // 			if find( line_tokens[t][1], {PROCEDURE, FUNCTION})  then
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5117 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_5117);
        _0 = _5117;
        _2 = (int)SEQ_PTR(_5117);
        _5117 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5117);
        DeRefDS(_0);
        DeRef(_5176);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = 405;
        ((int *)_2)[2] = 406;
        _5176 = MAKE_SEQ(_1);
        _0 = _5176;
        _5176 = find(_5117, _5176);
        DeRefDSi(_0);
        if (_5176 == 0)
            goto L47;

        // 				if not is_global and SymTab[p][S_SCOPE] = SC_GLOBAL then
        _5176 = (_is_global == 0);
        if (_5176 == 0) {
            goto L48;
        }
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7SymTab);
        _5117 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_5117);
        _0 = _5117;
        _2 = (int)SEQ_PTR(_5117);
        _5117 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_5117);
        DeRef(_0);
        _0 = _5117;
        if (IS_ATOM_INT(_5117)) {
            _5117 = (_5117 == 6);
        }
        else {
            _5117 = binary_op(EQUALS, _5117, 6);
        }
        DeRef(_0);
L49:
        if (_5117 == 0) {
            goto L48;
        }
        else {
            if (!IS_ATOM_INT(_5117) && DBL_PTR(_5117)->dbl == 0.0)
                goto L48;
        }

        // 					if line_tokens[t][1] = PROCEDURE then
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5117 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_5117);
        _0 = _5117;
        _2 = (int)SEQ_PTR(_5117);
        _5117 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5117);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _5117, 405))
            goto L4A;

        // 						replace_tokens( t, t, "global procedure")
        RefDS(_5333);
        _16replace_tokens(_t, _t, _5333);
        goto L4B;
L4A:

        // 						replace_tokens( t, t, "global function")
        RefDS(_5334);
        _16replace_tokens(_t, _t, _5334);
L4B:
L48:

        // 				pdec = pp_decorate( decorated )
        RefDS(_decorated);
        _0 = _pdec;
        _pdec = _16pp_decorate(_decorated);
        DeRef(_0);

        // 				if is_constructor then
        if (_is_constructor == 0)
            goto L4C;

        // 					pdec &= "( "
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5336);
        goto L4D;
L4C:

        // 					pdec &= "( object this"
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5338);

        // 					if param_num > 1 then
        if (_16param_num <= 1)
            goto L4E;

        // 						pdec &= ", "
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5341);
        goto L4F;
L4E:

        // 						pdec &= 32
        Append(&_pdec, _pdec, 32);
L4F:
L4D:

        // 				full_line()
        _16full_line();

        // 				replace_tokens( t + 1, t + 2, pdec )
        DeRef(_5117);
        _5117 = _t + 1;
        DeRef(_5176);
        _5176 = _t + 2;
        RefDS(_pdec);
        _16replace_tokens(_5117, _5176, _pdec);
        goto L50;
L47:

        // 			elsif line_tokens[t][T_ID] = TYPE and line_tokens[t-1][T_ID] != FUNCTION then
        DeRef(_5176);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5176 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_5176);
        _0 = _5176;
        _2 = (int)SEQ_PTR(_5176);
        _5176 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5176);
        DeRefDS(_0);
        _0 = _5176;
        if (IS_ATOM_INT(_5176)) {
            _5176 = (_5176 == 504);
        }
        else {
            _5176 = binary_op(EQUALS, _5176, 504);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5176)) {
            if (_5176 == 0) {
                goto L51;
            }
        }
        else {
            if (DBL_PTR(_5176)->dbl == 0.0) {
                goto L51;
            }
        }
        DeRef(_5117);
        _5117 = _t - 1;
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5117 = (int)*(((s1_ptr)_2)->base + _5117);
        RefDS(_5117);
        _0 = _5117;
        _2 = (int)SEQ_PTR(_5117);
        _5117 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5117);
        DeRefDS(_0);
        _0 = _5117;
        if (IS_ATOM_INT(_5117)) {
            _5117 = (_5117 != 406);
        }
        else {
            _5117 = binary_op(NOTEQ, _5117, 406);
        }
        DeRef(_0);
L52:
        if (_5117 == 0) {
            goto L51;
        }
        else {
            if (!IS_ATOM_INT(_5117) && DBL_PTR(_5117)->dbl == 0.0)
                goto L51;
        }

        // 				class = find( line_tokens[t][T_SYM], class_table[CLASS_SYM])
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5117 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_5117);
        _0 = _5117;
        _2 = (int)SEQ_PTR(_5117);
        _5117 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5117);
        DeRefDS(_0);
        DeRef(_5176);
        _2 = (int)SEQ_PTR(_7class_table);
        _5176 = (int)*(((s1_ptr)_2)->base + 6);
        RefDS(_5176);
        _class = find(_5117, _5176);

        // 				if class then
        if (_class == 0)
            goto L53;

        // 					full_line()
        _16full_line();

        // 					if line_tokens[t-1][T_ID] != OF then
        DeRefDS(_5176);
        _5176 = _t - 1;
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5176 = (int)*(((s1_ptr)_2)->base + _5176);
        RefDS(_5176);
        _0 = _5176;
        _2 = (int)SEQ_PTR(_5176);
        _5176 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5176);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _5176, 424))
            goto L54;

        // 						replace_tokens( t, t, SymTab[real_type(line_tokens[t][2])][S_NAME] )
        DeRef(_5176);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5176 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_5176);
        _0 = _5176;
        _2 = (int)SEQ_PTR(_5176);
        _5176 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5176);
        DeRefDS(_0);
        Ref(_5176);
        _0 = _5176;
        _5176 = _16real_type(_5176);
        DeRef(_0);
        _2 = (int)SEQ_PTR(_7SymTab);
        _5176 = (int)*(((s1_ptr)_2)->base + _5176);
        Ref(_5176);
        _0 = _5176;
        _2 = (int)SEQ_PTR(_5176);
        _5176 = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_5176);
        DeRef(_0);
        Ref(_5176);
        _16replace_tokens(_t, _t, _5176);
        goto L55;
L54:

        // 						replace_tokens( t-2, t, "sequence" )
        DeRef(_5176);
        _5176 = _t - 2;
        RefDS(_850);
        _16replace_tokens(_5176, _t, _850);
L55:
L53:
L51:
L50:

        // 		end for
        _t = _t + 1;
        goto L45;
L46:
        ;
    }
L41:
L3F:

    //     SymTab[p][S_NUM_ARGS] = param_num
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 20);
    _1 = *(int *)_2;
    *(int *)_2 = _16param_num;
    DeRef(_1);

    //     if TRANSLATE then

    //     if SymTab[p][S_TOKEN] = TYPE and param_num != 1 then
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5117 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5117);
    _0 = _5117;
    _2 = (int)SEQ_PTR(_5117);
    _5117 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_5117);
    DeRef1(_0);
    _0 = _5117;
    if (IS_ATOM_INT(_5117)) {
        _5117 = (_5117 == 504);
    }
    else {
        _5117 = binary_op(EQUALS, _5117, 504);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_5117)) {
        if (_5117 == 0) {
            goto L56;
        }
    }
    else {
        if (DBL_PTR(_5117)->dbl == 0.0) {
            goto L56;
        }
    }
    DeRef1(_5176);
    _5176 = (_16param_num != 1);
L57:
    if (_5176 == 0)
        goto L56;

    // 		CompileErr("types and classes must have exactly one parameter")
    RefDS(_5377);
    _9CompileErr(_5377);

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L58;

    // 			release_line()
    _16release_line();
L58:

    // 		return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
    goto L59;
L56:

    // 	elsif prog_type = CLASS then
    if (_prog_type != 421)
        goto L5A;

    // 		current_class = new_class( p )
    _0 = _11new_class(_p);
    _7current_class = _0;

    // 		seq_of_class = sequence_of_class( current_class )
    _seq_of_class = _11sequence_of_class(_7current_class);

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L5B;

    // 			for class_token = 1 to length(line_tokens) do
    DeRef1(_5176);
    _5176 = SEQ_PTR(_7line_tokens)->length;
    { int _class_token;
        _class_token = 1;
L5C:
        if (_class_token > _5176)
            goto L5D;

        // 				if line_tokens[class_token][T_ID] = CLASS then
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _5117 = (int)*(((s1_ptr)_2)->base + _class_token);
        RefDS(_5117);
        _0 = _5117;
        _2 = (int)SEQ_PTR(_5117);
        _5117 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5117);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _5117, 421))
            goto L5E;

        // 					if is_global then
        if (_is_global == 0)
            goto L5F;

        // 						pdec = "-- global euclass"
        RefDS(_5385);
        DeRef(_pdec);
        _pdec = _5385;
        goto L60;
L5F:

        // 						pdec = "-- euclass"
        RefDS(_5386);
        DeRef(_pdec);
        _pdec = _5386;
L60:

        // 					replace_tokens( class_token - is_global, class_token, pdec)
        DeRef(_5117);
        _5117 = _class_token - _is_global;
        RefDS(_pdec);
        _16replace_tokens(_5117, _class_token, _pdec);
L5E:

        // 			end for
        _class_token = _class_token + 1;
        goto L5C;
L5D:
        ;
    }
L5B:
L5A:
L59:

    // 	if pt = r:FUNC then
    if (_pt != 501)
        goto L61;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 		if tok[T_ID] = COLON then
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    if (binary_op_a(NOTEQ, _5117, -23))
        goto L62;

    // 			tok1 = length(line_tokens)
    _tok1 = SEQ_PTR(_7line_tokens)->length;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 			tok2 = tok1 + 1
    _tok2 = _tok1 + 1;

    // 			if not find( tok[T_ID], { TYPE, QUALIFIED_TYPE, CLASS }) then
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    _0 = _5176;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 504;
    *((int *)(_2+8)) = 526;
    *((int *)(_2+12)) = 421;
    _5176 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _5176;
    _5176 = find(_5117, _5176);
    DeRef1(_0);
    if (_5176 != 0)
        goto L63;

    // 				CompileErr( "expected a type or a class" )
    RefDS(_5399);
    _9CompileErr(_5399);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L64;

    // 					release_line()
    _16release_line();
L64:

    // 				return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L63:

    // 			if tok[T_SYM] = sequence_type then
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5176);
    if (binary_op_a(NOTEQ, _5176, _11sequence_type))
        goto L65;

    // 				tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 				if tok[T_ID] = OF then
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5176);
    if (binary_op_a(NOTEQ, _5176, 424))
        goto L66;

    // 					tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 					if not sym_to_class( tok[T_SYM] ) then
    DeRef1(_5176);
    _2 = (int)SEQ_PTR(_tok);
    _5176 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5176);
    Ref(_5176);
    _0 = _5176;
    _5176 = _11sym_to_class(_5176);
    DeRef1(_0);
    if (_5176 != 0)
        goto L67;

    // 						CompileErr( "expected a class" )
    RefDS(_5409);
    _9CompileErr(_5409);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L68;

    // 					release_line()
    _16release_line();
L68:

    // 						return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L67:

    // 					SymTab[p][S_OBJ] = class_table[CLASS_SYM][sequence_of_class( sym_to_class( tok[T_SYM]) )]
    DeRef(_5117);
    _5117 = _7SymTab;
    Ref(_5117);
    _2 = (int)SEQ_PTR(_5117);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _5117 = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef1(_5125);
    _2 = (int)SEQ_PTR(_7class_table);
    _5125 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5125);
    DeRef1(_5413);
    _2 = (int)SEQ_PTR(_tok);
    _5413 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5413);
    Ref(_5413);
    _0 = _5413;
    _5413 = _11sym_to_class(_5413);
    DeRef1(_0);
    _5413 = _11sequence_of_class(_5413);
    _2 = (int)SEQ_PTR(_5125);
    _5413 = (int)*(((s1_ptr)_2)->base + _5413);
    Ref(_5413);
    Ref(_5413);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _5413;
    DeRef(_1);
    RefDS(_5117);
    DeRef1(_7SymTab);
    _7SymTab = _5117;

    // 					tok2 += 2
    _tok2 = _tok2 + 2;
    goto L69;
L66:

    // 					putback( tok )
    RefDS(_tok);
    _16putback(_tok);

    // 					SymTab[p][S_OBJ] = sequence_type
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _11sequence_type;
    DeRef(_1);
L6A:
    goto L69;
L65:

    // 				SymTab[p][S_OBJ] = tok[T_SYM]
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5117);
    Ref(_5117);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _5117;
    DeRef(_1);
L69:

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L6B;

    // 				replace_tokens( tok1, tok2, "" )
    RefDS(_39);
    _16replace_tokens(_tok1, _tok2, _39);
L6C:
    goto L6B;
L62:

    // 			putback( tok )
    RefDS(_tok);
    _16putback(_tok);
L6B:
L61:

    //     if preprocess then
    if (_7preprocess == 0)
        goto L6D;

    //     	release_line()
    _16release_line();
L6D:

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    //     while tok[T_ID] = TYPE or tok[T_ID] = QUALIFIED_TYPE do
L6E:
    DeRef(_5117);
    _2 = (int)SEQ_PTR(_tok);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5117);
    _0 = _5117;
    if (IS_ATOM_INT(_5117)) {
        _5117 = (_5117 == 504);
    }
    else {
        _5117 = binary_op(EQUALS, _5117, 504);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5117)) {
        if (_5117 != 0) {
            goto L6F;
        }
    }
    else {
        if (DBL_PTR(_5117)->dbl != 0.0) {
            goto L6F;
        }
    }
    DeRef(_5413);
    _2 = (int)SEQ_PTR(_tok);
    _5413 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5413);
    _0 = _5413;
    if (IS_ATOM_INT(_5413)) {
        _5413 = (_5413 == 526);
    }
    else {
        _5413 = binary_op(EQUALS, _5413, 526);
    }
    DeRef(_0);
L70:
    if (_5413 <= 0) {
        if (_5413 == 0) {
            goto L71;
        }
        else {
            if (!IS_ATOM_INT(_5413) && DBL_PTR(_5413)->dbl == 0.0)
                goto L71;
        }
    }
L6F:

    // 		if prog_type = CLASS then
    if (_prog_type != 421)
        goto L72;

    // 			Member_declaration( tok[T_SYM] )
    DeRef(_5413);
    _2 = (int)SEQ_PTR(_tok);
    _5413 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5413);
    Ref(_5413);
    _16Member_declaration(_5413);
    goto L73;
L72:

    // 			Private_declaration(tok[T_SYM])
    DeRef(_5413);
    _2 = (int)SEQ_PTR(_tok);
    _5413 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5413);
    Ref(_5413);
    _16Private_declaration(_5413);
L73:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     end while
    goto L6E;
L71:

    // 	if prog_type != CLASS then
    if (_prog_type == 421)
        goto L74;

    // 	    sym = SymTab[p][S_NEXT]
    DeRef1(_5413);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5413 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5413);
    _2 = (int)SEQ_PTR(_5413);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	    for i = 1 to SymTab[p][S_NUM_ARGS] do
    DeRef1(_5413);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5413 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5413);
    _0 = _5413;
    _2 = (int)SEQ_PTR(_5413);
    _5413 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_5413);
    DeRef1(_0);
    { int _i;
        _i = 1;
L75:
        if (binary_op_a(GREATER, _i, _5413))
            goto L76;

        // 			TypeCheck(sym)
        _16TypeCheck(_sym);

        // 			sym = SymTab[sym][S_NEXT]
        DeRef(_5117);
        _2 = (int)SEQ_PTR(_7SymTab);
        _5117 = (int)*(((s1_ptr)_2)->base + _sym);
        Ref(_5117);
        _2 = (int)SEQ_PTR(_5117);
        _sym = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sym))
            _sym = (long)DBL_PTR(_sym)->dbl;

        // 	    end for	
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef1(_0);
        goto L75;
L76:
        ;
        DeRef1(_i);
    }

    // 	    if not TRANSLATE then

    // 		if OpTrace then
    if (_7OpTrace == 0)
        goto L77;

    // 		    emit_op(ERASE_PRIVATE_NAMES)
    _15emit_op(88);

    // 		    emit_addr(p)
    _15emit_addr(_p);

    // 		    sym = SymTab[p][S_NEXT]
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5117 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5117);
    _2 = (int)SEQ_PTR(_5117);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 		    for i = 1 to SymTab[p][S_NUM_ARGS] do
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5117 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_5117);
    _0 = _5117;
    _2 = (int)SEQ_PTR(_5117);
    _5117 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_5117);
    DeRef1(_0);
    { int _i;
        _i = 1;
L78:
        if (binary_op_a(GREATER, _i, _5117))
            goto L79;

        // 			emit_op(DISPLAY_VAR)
        _15emit_op(87);

        // 			emit_addr(sym)
        _15emit_addr(_sym);

        // 			sym = SymTab[sym][S_NEXT]
        DeRef(_5413);
        _2 = (int)SEQ_PTR(_7SymTab);
        _5413 = (int)*(((s1_ptr)_2)->base + _sym);
        Ref(_5413);
        _2 = (int)SEQ_PTR(_5413);
        _sym = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sym))
            _sym = (long)DBL_PTR(_sym)->dbl;

        // 		    end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef1(_0);
        goto L78;
L79:
        ;
        DeRef1(_i);
    }

    // 		    emit_op(UPDATE_GLOBALS)
    _15emit_op(89);
L77:
L7A:

    // 	    putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 	    FuncReturn = FALSE
    _16FuncReturn = 0;

    // 	    if current_class then
    if (_7current_class == 0)
        goto L7B;

    // 	    	SymTab[p][S_NAME] = decorated
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_decorated);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _decorated;
    DeRef(_1);

    // 			if find( decorated, method_table[METHOD_NAME] ) then
    DeRef1(_5117);
    _2 = (int)SEQ_PTR(_7method_table);
    _5117 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5117);
    _0 = _5117;
    _5117 = find(_decorated, _5117);
    DeRef1(_0);
    if (_5117 == 0)
        goto L7C;

    // 				CompileErr( sprintf("method '%s' already defined", {decorated}) )
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_decorated);
    *((int *)(_2+4)) = _decorated;
    _5117 = MAKE_SEQ(_1);
    _0 = _5117;
    _5117 = EPrintf(-9999999, _5451, _5117);
    DeRef1(_0);
    RefDS(_5117);
    _9CompileErr(_5117);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L7D;

    // 					release_line()
    _16release_line();
L7D:

    // 				return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L7C:

    // 	    	add_method( p )
    _11add_method(_p);
L7B:

    // 	    Statement_list()
    _16Statement_list();

    // 	    if prog_type != CLASS then
    if (_prog_type == 421)
        goto L7E;

    // 	    	tok_match(END)
    _16tok_match(402);
    goto L7F;
L7E:

    // 	    	putback(tok)
    RefDS(_tok);
    _16putback(_tok);
L7F:

    // 	    ExitScope()
    _11ExitScope();

    // 	    tok_match(prog_type)
    _16tok_match(_prog_type);

    // 	    if prog_type != PROCEDURE and prog_type != CLASS then
    DeRef1(_5117);
    _5117 = (_prog_type != 405);
    if (_5117 == 0) {
        goto L80;
    }
    DeRef1(_5413);
    _5413 = (_prog_type != 421);
L81:
    if (_5413 == 0)
        goto L80;

    // 			if not FuncReturn then
    if (_16FuncReturn != 0)
        goto L82;

    // 			    if prog_type = FUNCTION then
    if (_prog_type != 406)
        goto L83;

    // 					CompileErr("no value returned from function")
    RefDS(_5460);
    _9CompileErr(_5460);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L84;

    // 					release_line()
    _16release_line();
L84:

    // 					return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
    goto L85;
L83:

    // 					CompileErr("type must return true / false value")
    RefDS(_5461);
    _9CompileErr(_5461);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L86;

    // 					release_line()
    _16release_line();
L86:

    // 					return
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
L85:
L82:

    // 			emit_op(BADRETURNF) -- function/type shouldn't reach here 
    _15emit_op(43);
    goto L87;
L80:

    // 			StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 			if not TRANSLATE then

    // 			    if OpTrace then
    if (_7OpTrace == 0)
        goto L88;

    // 					emit_op(ERASE_PRIVATE_NAMES)
    _15emit_op(88);

    // 					emit_addr(p)
    _15emit_addr(_p);
L88:
L89:

    // 			emit_op(RETURNP)
    _15emit_op(29);

    // 			if TRANSLATE then
L87:

    // 	    if temps_allocated + param_num > max_stack_per_call then 
    DeRef1(_5413);
    _5413 = _11temps_allocated + _16param_num;
    if ((long)((unsigned long)_5413 + (unsigned long)HIGH_BITS) >= 0) 
        _5413 = NewDouble((double)_5413);
    if (binary_op_a(LESSEQ, _5413, _16max_stack_per_call))
        goto L8A;

    // 			max_stack_per_call = temps_allocated + param_num
    _16max_stack_per_call = _11temps_allocated + _16param_num;
L8B:
    goto L8A;
L74:

    // 		putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		ExitScope()
    _11ExitScope();

    // 		EnterTopLevel()
    _16EnterTopLevel();
L8A:

    //     if current_class then
    if (_7current_class == 0)
        goto L8C;

    // 	    if prog_type != CLASS then
    if (_prog_type == 421)
        goto L8D;

    // 		    StraightenBranches()
    _16StraightenBranches();

    // 		    EnterTopLevel()
    _16EnterTopLevel();
L8E:
    goto L8D;
L8C:

    // 		PatchGotos()
    _16PatchGotos();

    // 	    StraightenBranches()
    _16StraightenBranches();

    // 	    EnterTopLevel()
    _16EnterTopLevel();
L8D:

    // end procedure
    DeRef1(_tok);
    DeRef1(_prog_name);
    DeRef1(_decorated);
    DeRef1(_pdec);
    DeRef1(_by_ref);
    DeRef(_5413);
    DeRef(_5117);
    DeRef(_5125);
    DeRef(_5176);
    return 0;
    ;
}


int _16InitGlobals()
{
    int _0, _1, _2;
    

    //     ResetTP()
    _12ResetTP();

    //     OpTypeCheck = TRUE
    _7OpTypeCheck = 1;

    //     OpWarning = TRUE
    _7OpWarning = 1;

    //     OpStrictGoto = FALSE
    _7OpStrictGoto = 0;

    // end procedure
    return 0;
    ;
}


int _16not_supported_compile(int _feature)
{
    int _5467 = 0;
    int _0, _1, _2;
    

    //     CompileErr(sprintf("%s is not supported in Euphoria for %s", 
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _feature;
    RefDS(_feature);
    ((int *)_2)[2] = _7version_name;
    RefDS(_7version_name);
    _5467 = MAKE_SEQ(_1);
    _0 = _5467;
    _5467 = EPrintf(-9999999, _783, _5467);
    DeRefDS(_0);
    RefDS(_5467);
    _9CompileErr(_5467);

    // end procedure
    DeRefDSi(_feature);
    DeRefDSi(_5467);
    return 0;
    ;
}


int _16SetWith(int _on_off)
{
    int _option = 0;
    int _tok = 0;
    int _5470 = 0;
    int _5476;
    int _0, _1, _2;
    

    //     option = StringToken()
    _option = _12StringToken();

    //     if equal(option, "type_check") then
    if (_option == _5471)
        _5470 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_5471))
        _5470 = 0;
    else
        _5470 = (compare(_option, _5471) == 0);
    if (_5470 == 0)
        goto L1;

    // 	OpTypeCheck = on_off
    _7OpTypeCheck = _on_off;
    goto L2;
L1:

    //     elsif equal(option, "profile") then
    DeRef(_5470);
    if (_option == _964)
        _5470 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_964))
        _5470 = 0;
    else
        _5470 = (compare(_option, _964) == 0);
    if (_5470 == 0)
        goto L3;

    // 	if not TRANSLATE and not BIND then
    _5470 = (0 == 0);
    if (_5470 == 0) {
        goto L2;
    }
    _5476 = (0 == 0);
L4:
    if (_5476 == 0)
        goto L2;

    // 	    OpProfileStatement = on_off
    _7OpProfileStatement = _on_off;

    // 	    if OpProfileStatement then
    if (_7OpProfileStatement == 0)
        goto L2;

    // 		if AnyTimeProfile then
    if (_12AnyTimeProfile == 0)
        goto L5;

    // 		    Warning(mix_msg)
    RefDS(_16mix_msg);
    _9Warning(_16mix_msg);

    // 		    OpProfileStatement = FALSE
    _7OpProfileStatement = 0;
    goto L2;
L5:

    // 		    AnyStatementProfile = TRUE
    _12AnyStatementProfile = 1;
L6:
L7:
L8:
    goto L2;
L3:

    //     elsif equal(option, "profile_time") then
    if (_option == _5477)
        _5476 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_5477))
        _5476 = 0;
    else
        _5476 = (compare(_option, _5477) == 0);
    if (_5476 == 0)
        goto L9;

    // 	if not TRANSLATE and not BIND then
    _5476 = (0 == 0);
    if (_5476 == 0) {
        goto L2;
    }
    DeRef(_5470);
    _5470 = (0 == 0);
LA:
    if (_5470 == 0)
        goto L2;

    // 	    if not EDOS then
    if (_7EDOS != 0)
        goto LB;

    // 		if on_off then
    if (_on_off == 0)
        goto LC;

    // 		    not_supported_compile("profile_time")
    RefDS(_5477);
    _16not_supported_compile(_5477);
LC:
LB:

    // 	    OpProfileTime = on_off
    _7OpProfileTime = _on_off;

    // 	    if OpProfileTime then
    if (_7OpProfileTime == 0)
        goto L2;

    // 		if AnyStatementProfile then
    if (_12AnyStatementProfile == 0)
        goto LD;

    // 		    Warning(mix_msg)
    RefDS(_16mix_msg);
    _9Warning(_16mix_msg);

    // 		    OpProfileTime = FALSE
    _7OpProfileTime = 0;
LD:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] = ATOM then
    DeRef(_5470);
    _2 = (int)SEQ_PTR(_tok);
    _5470 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5470);
    if (binary_op_a(NOTEQ, _5470, 502))
        goto LE;

    // 		    if integer(SymTab[tok[T_SYM]][S_OBJ]) then
    DeRef(_5470);
    _2 = (int)SEQ_PTR(_tok);
    _5470 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5470);
    _0 = _5470;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5470))
        _5470 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5470)->dbl));
    else
        _5470 = (int)*(((s1_ptr)_2)->base + _5470);
    Ref(_5470);
    DeRef(_0);
    _0 = _5470;
    _2 = (int)SEQ_PTR(_5470);
    _5470 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5470);
    DeRef(_0);
    _0 = _5470;
    if (IS_ATOM_INT(_5470))
        _5470 = 1;
    else if (IS_ATOM_DBL(_5470))
        _5470 = IS_ATOM_INT(DoubleToInt(_5470));
    else
        _5470 = 0;
    DeRef(_0);
    if (_5470 == 0)
        goto LF;

    // 			sample_size = SymTab[tok[T_SYM]][S_OBJ]
    _2 = (int)SEQ_PTR(_tok);
    _5470 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5470);
    _0 = _5470;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5470))
        _5470 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5470)->dbl));
    else
        _5470 = (int)*(((s1_ptr)_2)->base + _5470);
    Ref(_5470);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_5470);
    _16sample_size = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_16sample_size))
        _16sample_size = (long)DBL_PTR(_16sample_size)->dbl;
    goto L10;
LF:

    // 			sample_size = -1
    _16sample_size = -1;
L10:

    // 		    if sample_size < 1 and OpProfileTime then
    DeRef(_5470);
    _5470 = (_16sample_size < 1);
    if (_5470 == 0) {
        goto L11;
    }
L12:
    if (_7OpProfileTime == 0)
        goto L11;

    // 			CompileErr("sample size must be a positive integer")
    RefDS(_5495);
    _9CompileErr(_5495);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L13;

    // 					release_line()
    _16release_line();
L13:

    // 			return
    DeRefi(_option);
    DeRef(_tok);
    DeRef(_5470);
    return 0;
L14:
    goto L11;
LE:

    // 		    putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		    sample_size = DEFAULT_SAMPLE_SIZE
    _16sample_size = 25000;
L11:

    // 		if OpProfileTime then
    if (_7OpProfileTime == 0)
        goto L2;

    // 		    if EDOS then
    if (_7EDOS == 0)
        goto L2;

    // 			AnyTimeProfile = TRUE
    _12AnyTimeProfile = 1;
L15:
L16:
L17:
L18:
    goto L2;
L9:

    //     elsif equal(option, "trace") then
    DeRef(_5470);
    if (_option == _894)
        _5470 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_894))
        _5470 = 0;
    else
        _5470 = (compare(_option, _894) == 0);
    if (_5470 == 0)
        goto L19;

    // 	if not BIND 

    // 	    OpTrace = on_off
    _7OpTrace = _on_off;
L1A:
    goto L2;
L19:

    //     elsif equal(option, "warning") then
    DeRef(_5470);
    if (_option == _5498)
        _5470 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_5498))
        _5470 = 0;
    else
        _5470 = (compare(_option, _5498) == 0);
    if (_5470 == 0)
        goto L1B;

    // 	OpWarning = on_off
    _7OpWarning = _on_off;
    goto L2;
L1B:

    //     elsif equal(option, "strict_goto") then
    DeRef(_5470);
    if (_option == _5500)
        _5470 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_5500))
        _5470 = 0;
    else
        _5470 = (compare(_option, _5500) == 0);
    if (_5470 == 0)
        goto L1C;

    //     	OpStrictGoto = on_off
    _7OpStrictGoto = _on_off;
    goto L2;
L1C:

    //     elsif on_off and option[1] >= '0' and option[1] <= '9' then
    if (_on_off == 0) {
        DeRef(_5470);
        _5470 = 0;
        goto L1D;
    }
    _2 = (int)SEQ_PTR(_option);
    _5476 = (int)*(((s1_ptr)_2)->base + 1);
    _5476 = (_5476 >= 48);
    _5470 = (_5476 != 0);
L1D:
    if (_5470 == 0) {
        goto L1E;
    }
    DeRef(_5470);
    _2 = (int)SEQ_PTR(_option);
    _5470 = (int)*(((s1_ptr)_2)->base + 1);
    _5470 = (_5470 <= 57);
L1F:
    if (_5470 == 0)
        goto L1E;
    goto L2;
L1E:

    // 	CompileErr("unknown with/without option")
    RefDS(_5508);
    _9CompileErr(_5508);

    // 	return
    DeRefi(_option);
    DeRef(_tok);
    DeRef(_5470);
    return 0;
L2:

    // end procedure
    DeRefi(_option);
    DeRef(_tok);
    DeRef(_5470);
    return 0;
    ;
}


