// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _17embed_params_to_string(int _params)
{
    int _string = 0;
    int _ix;
    int _9774 = 0;
    int _9773;
    int _0, _1, _2;
    

    // 	string = ""
    RefDS(_39);
    _string = _39;

    // 	for i = 1 to length(params) do
    _9773 = SEQ_PTR(_params)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _9773)
            goto L2;

        // 		ix = find( params[i], PARAM_ABBREV )
        DeRef(_9774);
        _2 = (int)SEQ_PTR(_params);
        _9774 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_9774);
        _ix = find(_9774, _17PARAM_ABBREV);

        // 		if ix then
        if (_ix == 0)
            goto L3;

        // 			string &= sprintf( "%s p%d", {PARAM_NAME[ix], i})
        DeRef(_9774);
        _2 = (int)SEQ_PTR(_17PARAM_NAME);
        _9774 = (int)*(((s1_ptr)_2)->base + _ix);
        RefDS(_9774);
        _0 = _9774;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _9774;
        RefDS(_9774);
        ((int *)_2)[2] = _i;
        _9774 = MAKE_SEQ(_1);
        DeRefDS(_0);
        _0 = _9774;
        _9774 = EPrintf(-9999999, _9776, _9774);
        DeRefDS(_0);
        Concat((object_ptr)&_string, _string, (s1_ptr)_9774);
        goto L4;
L3:

        // 			string &= sprintf( "object p%d", i )
        DeRef(_9774);
        _9774 = EPrintf(-9999999, _9781, _i);
        Concat((object_ptr)&_string, _string, (s1_ptr)_9774);
L4:

        // 		if i != length(params) then
        DeRef(_9774);
        _9774 = SEQ_PTR(_params)->length;
        if (_i == _9774)
            goto L5;

        // 			string &= ','
        Append(&_string, _string, 44);
L5:

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	return string
    DeRefDS(_params);
    DeRef(_9774);
    return _string;
    ;
}


int _17embed_params_to_call_params(int _params)
{
    int _string = 0;
    int _9789 = 0;
    int _9787;
    int _0, _1, _2;
    

    // 	string = ""
    RefDS(_39);
    _string = _39;

    // 	for i = 1 to length(params) do
    _9787 = SEQ_PTR(_params)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _9787)
            goto L2;

        // 		string &= sprintf( "p%d", {i})
        _0 = _9789;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = _i;
        _9789 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _9789;
        _9789 = EPrintf(-9999999, _9788, _9789);
        DeRefDSi(_0);
        Concat((object_ptr)&_string, _string, (s1_ptr)_9789);

        // 		if i != length(params) then
        DeRefDSi(_9789);
        _9789 = SEQ_PTR(_params)->length;
        if (_i == _9789)
            goto L3;

        // 			string &= ','
        Append(&_string, _string, 44);
L3:

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	return string
    DeRefDS(_params);
    DeRef(_9789);
    return _string;
    ;
}


int _17embed_routine_exec(int _name, int _rid, int _params, int _is_func)
{
    int _9808 = 0;
    int _9807 = 0;
    int _9805 = 0;
    int _9803 = 0;
    int _9802 = 0;
    int _9800 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_rid)) {
        _1 = (long)(DBL_PTR(_rid)->dbl);
        DeRefDS(_rid);
        _rid = _1;
    }
    if (!IS_ATOM_INT(_is_func)) {
        _1 = (long)(DBL_PTR(_is_func)->dbl);
        DeRefDS(_is_func);
        _is_func = _1;
    }

    // 	return do_eval_exec( sprintf("global %s %s(%s)\n\t%sembedded_%s_call(%d,{%s})\nend %s\n",
    _9800 = _is_func + 1;
    _2 = (int)SEQ_PTR(_17PROC_OR_FUNC);
    _9800 = (int)*(((s1_ptr)_2)->base + _9800);
    RefDS(_9800);
    RefDS(_params);
    _9802 = _17embed_params_to_string(_params);
    _9803 = _is_func + 3;
    _2 = (int)SEQ_PTR(_17PROC_OR_FUNC);
    _9803 = (int)*(((s1_ptr)_2)->base + _9803);
    RefDS(_9803);
    _9805 = _is_func + 1;
    _2 = (int)SEQ_PTR(_17PROC_OR_FUNC);
    _9805 = (int)*(((s1_ptr)_2)->base + _9805);
    RefDS(_9805);
    RefDS(_params);
    _9807 = _17embed_params_to_call_params(_params);
    _9808 = _is_func + 1;
    _2 = (int)SEQ_PTR(_17PROC_OR_FUNC);
    _9808 = (int)*(((s1_ptr)_2)->base + _9808);
    RefDS(_9808);
    _0 = _9808;
    _1 = NewS1(8);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_9800);
    *((int *)(_2+4)) = _9800;
    RefDS(_name);
    *((int *)(_2+8)) = _name;
    RefDS(_9802);
    *((int *)(_2+12)) = _9802;
    RefDS(_9803);
    *((int *)(_2+16)) = _9803;
    RefDS(_9805);
    *((int *)(_2+20)) = _9805;
    *((int *)(_2+24)) = _rid;
    RefDS(_9807);
    *((int *)(_2+28)) = _9807;
    RefDS(_9808);
    *((int *)(_2+32)) = _9808;
    _9808 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _9808;
    _9808 = EPrintf(-9999999, _9799, _9808);
    DeRefDS(_0);
    RefDS(_9808);
    _0 = _9808;
    _9808 = _17do_eval_exec(_9808);
    DeRefDSi(_0);
    DeRefDS(_name);
    DeRefDS(_params);
    DeRefDSi(_9807);
    DeRefDS(_9805);
    DeRefDS(_9803);
    DeRefDSi(_9802);
    DeRefDS(_9800);
    return _9808;
    ;
}


int _17opEVAL_ERROR()
{
    int _9813 = 0;
    int _0, _1, _2;
    

    // 	val[Code[pc+1]] = geval_error
    _9813 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9813 = (int)*(((s1_ptr)_2)->base + _9813);
    Ref(_9813);
    RefDS(_7geval_error);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_9813))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_9813)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _9813);
    _1 = *(int *)_2;
    *(int *)_2 = _7geval_error;
    DeRef(_1);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRef(_9813);
    return 0;
    ;
}


int _17opVAR_ID()
{
    int _sub;
    int _fn;
    int _p;
    int _stlen;
    int _name = 0;
    int _9832 = 0;
    int _9834 = 0;
    int _9816 = 0;
    int _0, _1, _2;
    

    // 	sub = Code[pc+1]   -- CurrentSub
    _9816 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _sub = (int)*(((s1_ptr)_2)->base + _9816);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	stlen = Code[pc+2]	-- s.t. length
    _9816 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _stlen = (int)*(((s1_ptr)_2)->base + _9816);
    if (!IS_ATOM_INT(_stlen))
        _stlen = (long)DBL_PTR(_stlen)->dbl;

    // 	name = val[Code[pc+3]]	-- routine name sequence
    _9816 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _9816 = (int)*(((s1_ptr)_2)->base + _9816);
    Ref(_9816);
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9816))
        _name = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9816)->dbl));
    else
        _name = (int)*(((s1_ptr)_2)->base + _9816);
    Ref(_name);

    // 	fn = Code[pc+4]    -- file number
    DeRef(_9816);
    _9816 = _17pc + 4;
    _2 = (int)SEQ_PTR(_7Code);
    _fn = (int)*(((s1_ptr)_2)->base + _9816);
    if (!IS_ATOM_INT(_fn))
        _fn = (long)DBL_PTR(_fn)->dbl;

    // 	target = Code[pc+5]
    _9816 = _17pc + 5;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9816);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	pc += 6
    _17pc = _17pc + 6;

    // 	if atom(name) then
    _9816 = IS_ATOM(_name);
    if (_9816 == 0)
        goto L1;

    // 		val[target] = -1
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 		return
    DeRef(_name);
    return 0;
L1:

    // 	p = RTLookupVar(name, fn, sub, stlen)
    Ref(_name);
    _p = _17RTLookupVar(_name, _fn, _sub, _stlen);

    // 	if p = 0 or find(SymTab[p][S_TOKEN], {r:PROC, r:FUNC, TYPE}) then
    DeRef(_9816);
    _9816 = (_p == 0);
    if (_9816 != 0) {
        goto L2;
    }
    DeRef(_9832);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9832 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_9832);
    _0 = _9832;
    _2 = (int)SEQ_PTR(_9832);
    _9832 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_9832);
    DeRef(_0);
    _0 = _9834;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _9834 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _9834;
    _9834 = find(_9832, _9834);
    DeRefDSi(_0);
L3:
    if (_9834 == 0)
        goto L4;
L2:

    // 		val[target] = -1  -- name is not a variable
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 		return
    DeRef(_name);
    DeRef(_9832);
    DeRef(_9834);
    DeRef(_9816);
    return 0;
L4:

    // 	for i = 1 to length(e_variable) do
    DeRef(_9834);
    _9834 = SEQ_PTR(_17e_variable)->length;
    { int _i;
        _i = 1;
L5:
        if (_i > _9834)
            goto L6;

        // 		if e_variable[i] = p then
        DeRef(_9832);
        _2 = (int)SEQ_PTR(_17e_variable);
        _9832 = (int)*(((s1_ptr)_2)->base + _i);
        if (_9832 != _p)
            goto L7;

        // 		    val[target] = i - 1 -- routine was already assigned an id
        _9832 = _i - 1;
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _17target);
        _1 = *(int *)_2;
        *(int *)_2 = _9832;
        DeRef(_1);

        // 		    return
        DeRef(_name);
        DeRef(_9834);
        DeRef(_9816);
        return 0;
L7:

        // 	end for 
        _i = _i + 1;
        goto L5;
L6:
        ;
    }

    // 	e_variable = append(e_variable, p)
    Append(&_17e_variable, _17e_variable, _p);

    // 	val[target] = length(e_variable) - 1	
    DeRef(_9832);
    _9832 = SEQ_PTR(_17e_variable)->length;
    _9832 = _9832 - 1;
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9832;
    DeRef(_1);

    // end procedure
    DeRef(_name);
    DeRef(_9834);
    DeRef(_9816);
    return 0;
    ;
}


int _17opREAD_VAR()
{
    int _9849 = 0;
    int _9843 = 0;
    int _0, _1, _2;
    

    // 	a = val[Code[pc+1]] + 1
    _9843 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _9843 = (int)*(((s1_ptr)_2)->base + _9843);
    Ref(_9843);
    _0 = _9843;
    _2 = (int)SEQ_PTR(_17val);
    if (!IS_ATOM_INT(_9843))
        _9843 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9843)->dbl));
    else
        _9843 = (int)*(((s1_ptr)_2)->base + _9843);
    Ref(_9843);
    DeRef(_0);
    if (IS_ATOM_INT(_9843)) {
        _17a = _9843 + 1;
    }
    else
        _17a = 1+(long)(DBL_PTR(_9843)->dbl);

    // 	if a < 1 or a > length(e_variable) then
    DeRef(_9843);
    _9843 = (_17a < 1);
    if (_9843 != 0) {
        goto L1;
    }
    _9849 = SEQ_PTR(_17e_variable)->length;
    _9849 = (_17a > _9849);
L2:
    if (_9849 == 0)
        goto L3;
L1:

    // 		RTFatal( "Invalid variable_id" )
    RefDS(_9851);
    _17RTFatal(_9851);

    // 		return
    DeRef(_9849);
    DeRef(_9843);
    return 0;
L3:

    // 	a = e_variable[a]
    _2 = (int)SEQ_PTR(_17e_variable);
    _17a = (int)*(((s1_ptr)_2)->base + _17a);

    // 	target = Code[pc+2]
    DeRef(_9849);
    _9849 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9849);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	val[target] = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _9849 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9849);
    Ref(_9849);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9849;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9849);
    DeRef(_9843);
    return 0;
    ;
}


int _17opWRITE_VAR()
{
    int _9857 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9857 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9857);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	target = e_variable[val[a]+1]
    _2 = (int)SEQ_PTR(_17val);
    _9857 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9857);
    _0 = _9857;
    if (IS_ATOM_INT(_9857)) {
        _9857 = _9857 + 1;
    }
    else
        _9857 = binary_op(PLUS, 1, _9857);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_17e_variable);
    if (!IS_ATOM_INT(_9857))
        _17target = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9857)->dbl));
    else
        _17target = (int)*(((s1_ptr)_2)->base + _9857);

    // 	b = Code[pc+2]
    DeRef(_9857);
    _9857 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9857);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	val[target] = val[b]
    _2 = (int)SEQ_PTR(_17val);
    _9857 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_9857);
    Ref(_9857);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _9857;
    DeRef(_1);

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_9857);
    return 0;
    ;
}


int _17opDUMP_VARS()
{
    int _vars = 0;
    int _entry = 0;
    int _9893 = 0;
    int _9890 = 0;
    int _9889 = 0;
    int _9876 = 0;
    int _9884 = 0;
    int _9879;
    int _0, _1, _2;
    

    // 	target = Code[pc+1]
    _9876 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9876);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	vars = {}
    RefDS(_39);
    _vars = _39;

    // 	for sym = TopLevelSub + 2 to length(SymTab) do
    _9876 = _7TopLevelSub + 2;
    if ((long)((unsigned long)_9876 + (unsigned long)HIGH_BITS) >= 0) 
        _9876 = NewDouble((double)_9876);
    _9879 = SEQ_PTR(_7SymTab)->length;
    { int _sym;
        Ref(_9876);
        _sym = _9876;
L1:
        if (binary_op_a(GREATER, _sym, _9879))
            goto L2;

        // 		entry = SymTab[sym]
        DeRef(_entry);
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_sym))
            _entry = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_sym)->dbl));
        else
            _entry = (int)*(((s1_ptr)_2)->base + _sym);
        Ref(_entry);

        // 		if length(entry) = SIZEOF_VAR_ENTRY and entry[S_VTYPE] then
        DeRef(_9876);
        _9876 = SEQ_PTR(_entry)->length;
        _9876 = (_9876 == 14);
        if (_9876 == 0) {
            goto L3;
        }
        DeRef(_9884);
        _2 = (int)SEQ_PTR(_entry);
        _9884 = (int)*(((s1_ptr)_2)->base + 14);
        Ref(_9884);
L4:
        if (_9884 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_9884) && DBL_PTR(_9884)->dbl == 0.0)
                goto L3;
        }

        // 			vars = append( vars, { file_name[entry[S_FILE_NO]], VAR_SCOPE[entry[S_SCOPE]],
        DeRef(_9884);
        _2 = (int)SEQ_PTR(_entry);
        _9884 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_9884);
        _0 = _9884;
        _2 = (int)SEQ_PTR(_7file_name);
        if (!IS_ATOM_INT(_9884))
            _9884 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9884)->dbl));
        else
            _9884 = (int)*(((s1_ptr)_2)->base + _9884);
        Ref(_9884);
        DeRef(_0);
        DeRef(_9876);
        _2 = (int)SEQ_PTR(_entry);
        _9876 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_9876);
        _0 = _9876;
        _2 = (int)SEQ_PTR(_17VAR_SCOPE);
        if (!IS_ATOM_INT(_9876))
            _9876 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9876)->dbl));
        else
            _9876 = (int)*(((s1_ptr)_2)->base + _9876);
        RefDS(_9876);
        DeRef(_0);
        DeRef(_9889);
        _2 = (int)SEQ_PTR(_entry);
        _9889 = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_9889);
        DeRef(_9890);
        _2 = (int)SEQ_PTR(_entry);
        _9890 = (int)*(((s1_ptr)_2)->base + 14);
        Ref(_9890);
        _0 = _9890;
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!IS_ATOM_INT(_9890))
            _9890 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9890)->dbl));
        else
            _9890 = (int)*(((s1_ptr)_2)->base + _9890);
        Ref(_9890);
        DeRef(_0);
        _0 = _9890;
        _2 = (int)SEQ_PTR(_9890);
        _9890 = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_9890);
        DeRef(_0);
        DeRef(_9893);
        _9893 = find(_sym, _17e_variable);
        _9893 = _9893 - 1;
        _1 = NewS1(5);
        _2 = (int)((s1_ptr)_1)->base;
        Ref(_9884);
        *((int *)(_2+4)) = _9884;
        RefDS(_9876);
        *((int *)(_2+8)) = _9876;
        Ref(_9889);
        *((int *)(_2+12)) = _9889;
        Ref(_9890);
        *((int *)(_2+16)) = _9890;
        *((int *)(_2+20)) = _9893;
        _9893 = MAKE_SEQ(_1);
        RefDS(_9893);
        Append(&_vars, _vars, _9893);
L3:

        // 	end for
        _0 = _sym;
        if (IS_ATOM_INT(_sym)) {
            _sym = _sym + 1;
            if ((long)((unsigned long)_sym +(unsigned long) HIGH_BITS) >= 0) 
                _sym = NewDouble((double)_sym);
        }
        else {
            _sym = binary_op_a(PLUS, _sym, 1);
        }
        DeRef(_0);
        goto L1;
L2:
        ;
        DeRef(_sym);
    }

    // 	val[target] = vars
    RefDS(_vars);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _vars;
    DeRef(_1);

    // 	pc += 2
    _17pc = _17pc + 2;

    // end procedure
    DeRefDS(_vars);
    DeRef(_entry);
    DeRef5(_9893, _9890, _9889, _9876, _9884);
    return 0;
    ;
}


int _17do_exec()
{
    int _op;
    int _9898;
    int _0, _1, _2;
    

    // 	keep_running = TRUE
    _17keep_running = 1;

    // 	while keep_running do 
L1:
    if (_17keep_running == 0)
        goto L2;

    // 	op = Code[pc]
    _2 = (int)SEQ_PTR(_7Code);
    _op = (int)*(((s1_ptr)_2)->base + _17pc);
    if (!IS_ATOM_INT(_op))
        _op = (long)DBL_PTR(_op)->dbl;

    // 	call_proc(operation[op], {}) -- opcodes start at 1
    _2 = (int)SEQ_PTR(_17operation);
    _9898 = (int)*(((s1_ptr)_2)->base + _op);
    _0 = (int)_00[_9898].addr;
    (*(int (*)())_0)(
                         );

    // 	end while
    goto L1;
L2:

    // 	keep_running = TRUE -- so higher-level do_exec() will keep running
    _17keep_running = 1;

    // end procedure
    return 0;
    ;
}


int _17general_callback(int _cbx, int _ptr)
{
    int _args = 0;
    int _routine = 0;
    int _9902 = 0;
    int _0, _1, _2;
    

    // 	if in_trace then
    if (_17in_trace == 0)
        goto L1;

    // 		in_trace += 1
    _17in_trace = _17in_trace + 1;
L1:

    // 	routine = call_backs[cbx]
    DeRef(_routine);
    _2 = (int)SEQ_PTR(_17call_backs);
    if (!IS_ATOM_INT(_cbx))
        _routine = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_cbx)->dbl));
    else
        _routine = (int)*(((s1_ptr)_2)->base + _cbx);
    RefDS(_routine);

    // 	args = peek4u( ptr & call_backs[cbx][C_NUM_ARGS] )
    DeRef(_9902);
    _2 = (int)SEQ_PTR(_17call_backs);
    if (!IS_ATOM_INT(_cbx))
        _9902 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_cbx)->dbl));
    else
        _9902 = (int)*(((s1_ptr)_2)->base + _cbx);
    RefDS(_9902);
    _0 = _9902;
    _2 = (int)SEQ_PTR(_9902);
    _9902 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9902);
    DeRefDS(_0);
    if (IS_SEQUENCE(_ptr) && IS_ATOM(_9902)) {
    }
    else if (IS_ATOM(_ptr) && IS_SEQUENCE(_9902)) {
        Ref(_ptr);
        Prepend(&_9902, _9902, _ptr);
    }
    else {
        Concat((object_ptr)&_9902, _ptr, (s1_ptr)_9902);
    }
    DeRef(_args);
    _1 = (int)SEQ_PTR(_9902);
    peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
    _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
    poke4_addr = (unsigned long *)NewS1(_2);
    _args = MAKE_SEQ(poke4_addr);
    poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
    while (--_2 >= 0) {
        poke4_addr++;
        _1 = (int)*peek4_addr++;
        if ((unsigned)_1 > (unsigned)MAXINT)
            _1 = NewDouble((double)(unsigned long)_1);
        *(int *)poke4_addr = _1;
    }

    // 	val[t_id] = routine[C_USER_ROUTINE]
    DeRefDS(_9902);
    _2 = (int)SEQ_PTR(_routine);
    _9902 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_9902);
    Ref(_9902);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17t_id);
    _1 = *(int *)_2;
    *(int *)_2 = _9902;
    DeRef(_1);

    // 	val[t_arglist] = args
    RefDS(_args);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17t_arglist);
    _1 = *(int *)_2;
    *(int *)_2 = _args;
    DeRef(_1);

    // 	call_stack = call_stack & {length(call_stack), pc, call_back_routine} 
    DeRef(_9902);
    _9902 = SEQ_PTR(_17call_stack)->length;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _9902;
    *((int *)(_2+8)) = _17pc;
    *((int *)(_2+12)) = _17call_back_routine;
    _9902 = MAKE_SEQ(_1);
    Concat((object_ptr)&_17call_stack, _17call_stack, (s1_ptr)_9902);

    // 	Code = call_back_code 
    RefDS(_17call_back_code);
    DeRef(_7Code);
    _7Code = _17call_back_code;

    // 	pc = 1 
    _17pc = 1;

    // 	if EMBEDDED then

    // 		do_exec()
    _17do_exec();
L2:

    // 	pc = call_stack[$-1]
    DeRef(_9902);
    _9902 = SEQ_PTR(_17call_stack)->length;
    _9902 = _9902 - 1;
    _2 = (int)SEQ_PTR(_17call_stack);
    _17pc = (int)*(((s1_ptr)_2)->base + _9902);
    if (!IS_ATOM_INT(_17pc))
        _17pc = (long)DBL_PTR(_17pc)->dbl;

    // 	call_stack = call_stack[1..$-3]
    _9902 = SEQ_PTR(_17call_stack)->length;
    _9902 = _9902 - 3;
    rhs_slice_target = (object_ptr)&_17call_stack;
    RHS_Slice((s1_ptr)_17call_stack, 1, _9902);

    // 	Code = SymTab[call_stack[$]][S_CODE]
    _9902 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _9902 = (int)*(((s1_ptr)_2)->base + _9902);
    Ref(_9902);
    _0 = _9902;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_9902))
        _9902 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9902)->dbl));
    else
        _9902 = (int)*(((s1_ptr)_2)->base + _9902);
    Ref(_9902);
    DeRef(_0);
    DeRef(_7Code);
    _2 = (int)SEQ_PTR(_9902);
    _7Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_7Code);

    //  	if in_trace then
    if (_17in_trace == 0)
        goto L3;

    //  		in_trace -= 1
    _17in_trace = _17in_trace - 1;
L3:

    // 	return val[t_return_val]
    DeRef(_9902);
    _2 = (int)SEQ_PTR(_17val);
    _9902 = (int)*(((s1_ptr)_2)->base + _17t_return_val);
    Ref(_9902);
    DeRef(_cbx);
    DeRef(_ptr);
    DeRef(_args);
    DeRef(_routine);
    return _9902;
    ;
}


int _17machine_callback(int _cbx, int _ptr)
{
    int _rtn_def = 0;
    int _args = 0;
    int _9926 = 0;
    int _0, _1, _2;
    

    // 	rtn_def = call_backs[cbx]
    _2 = (int)SEQ_PTR(_17call_backs);
    if (!IS_ATOM_INT(_cbx))
        _rtn_def = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_cbx)->dbl));
    else
        _rtn_def = (int)*(((s1_ptr)_2)->base + _cbx);
    RefDS(_rtn_def);

    // 	args = peek4u(ptr & call_backs[cbx][C_NUM_ARGS])
    _2 = (int)SEQ_PTR(_17call_backs);
    if (!IS_ATOM_INT(_cbx))
        _9926 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_cbx)->dbl));
    else
        _9926 = (int)*(((s1_ptr)_2)->base + _cbx);
    RefDS(_9926);
    _0 = _9926;
    _2 = (int)SEQ_PTR(_9926);
    _9926 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9926);
    DeRefDS(_0);
    if (IS_SEQUENCE(_ptr) && IS_ATOM(_9926)) {
    }
    else if (IS_ATOM(_ptr) && IS_SEQUENCE(_9926)) {
        Ref(_ptr);
        Prepend(&_9926, _9926, _ptr);
    }
    else {
        Concat((object_ptr)&_9926, _ptr, (s1_ptr)_9926);
    }
    _1 = (int)SEQ_PTR(_9926);
    peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
    _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
    poke4_addr = (unsigned long *)NewS1(_2);
    _args = MAKE_SEQ(poke4_addr);
    poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
    while (--_2 >= 0) {
        poke4_addr++;
        _1 = (int)*peek4_addr++;
        if ((unsigned)_1 > (unsigned)MAXINT)
            _1 = NewDouble((double)(unsigned long)_1);
        *(int *)poke4_addr = _1;
    }

    // 	return general_callback(rtn_def, args)
    RefDS(_rtn_def);
    RefDS(_args);
    _0 = _9926;
    _9926 = _17general_callback(_rtn_def, _args);
    DeRefDS(_0);
    DeRef(_cbx);
    DeRef(_ptr);
    DeRefDS(_rtn_def);
    DeRefDS(_args);
    return _9926;
    ;
}


int _17do_callback(int _b)
{
    int _r;
    int _id;
    int _convention;
    int _asm97531 = 0;
    int _x = 0;
    int _9945 = 0;
    int _9939 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    // 	x = val[b]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_x);

    // 	if atom(x) then
    _9939 = IS_ATOM(_x);
    if (_9939 == 0)
        goto L1;

    // 		id = x
    Ref(_x);
    _id = _x;
    if (!IS_ATOM_INT(_id)) {
        _1 = (long)(DBL_PTR(_id)->dbl);
        DeRefDS(_id);
        _id = _1;
    }

    // 		convention = 0
    _convention = 0;
    goto L2;
L1:

    // 		convention = x[1]
    _2 = (int)SEQ_PTR(_x);
    _convention = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_convention))
        _convention = (long)DBL_PTR(_convention)->dbl;

    // 		id = x[2]
    _2 = (int)SEQ_PTR(_x);
    _id = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;
L2:

    // 	if id < 0 or id >= length(e_routine) then
    DeRef(_9939);
    _9939 = (_id < 0);
    if (_9939 != 0) {
        goto L3;
    }
    DeRef(_9945);
    _9945 = SEQ_PTR(_17e_routine)->length;
    _9945 = (_id >= _9945);
L4:
    if (_9945 == 0)
        goto L5;
L3:

    // 		RTFatal("Invalid routine id")
    RefDS(_9947);
    _17RTFatal(_9947);

    // 		return
    DeRef(_asm97531);
    DeRef(_x);
    DeRef(_9945);
    DeRef(_9939);
    return 0;
L5:

    // 	r = e_routine[id+1]
    DeRef(_9945);
    _9945 = _id + 1;
    _2 = (int)SEQ_PTR(_17e_routine);
    _r = (int)*(((s1_ptr)_2)->base + _9945);

    // 	if platform() = WIN32 and not convention then
    _9945 = (3 == 2);
    if (_9945 == 0) {
        goto L6;
    }
    DeRef(_9939);
    _9939 = (_convention == 0);
L7:
    if (_9939 == 0)
        goto L6;

    // 	    asm = allocate( length(cb_std) )
    DeRef(_9939);
    _9939 = 24;
    _0 = _asm97531;
    _asm97531 = _4allocate(24);
    DeRef(_0);

    // 	    poke( asm, cb_std ) 
    if (IS_ATOM_INT(_asm97531))
        poke_addr = (unsigned char *)_asm97531;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_asm97531)->dbl);
    _1 = (int)SEQ_PTR(_17cb_std);
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

    // 	    poke4( asm + 7, length(call_backs) + 1 )
    if (IS_ATOM_INT(_asm97531)) {
        _9939 = _asm97531 + 7;
        if ((long)((unsigned long)_9939 + (unsigned long)HIGH_BITS) >= 0) 
            _9939 = NewDouble((double)_9939);
    }
    else {
        _9939 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)7);
    }
    DeRef(_9945);
    _9945 = SEQ_PTR(_17call_backs)->length;
    _9945 = _9945 + 1;
    if (IS_ATOM_INT(_9939))
        poke4_addr = (unsigned long *)_9939;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9939)->dbl);
    *poke4_addr = (unsigned long)_9945;

    // 	    poke4( asm + 13, asm + 20 )
    if (IS_ATOM_INT(_asm97531)) {
        _9945 = _asm97531 + 13;
        if ((long)((unsigned long)_9945 + (unsigned long)HIGH_BITS) >= 0) 
            _9945 = NewDouble((double)_9945);
    }
    else {
        _9945 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)13);
    }
    DeRef(_9939);
    if (IS_ATOM_INT(_asm97531)) {
        _9939 = _asm97531 + 20;
        if ((long)((unsigned long)_9939 + (unsigned long)HIGH_BITS) >= 0) 
            _9939 = NewDouble((double)_9939);
    }
    else {
        _9939 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)20);
    }
    if (IS_ATOM_INT(_9945))
        poke4_addr = (unsigned long *)_9945;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9945)->dbl);
    if (IS_ATOM_INT(_9939)) {
        *poke4_addr = (unsigned long)_9939;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_9939)->dbl;
    }

    // 	    poke( asm + 18, SymTab[r][S_NUM_ARGS] * 4 )
    DeRef(_9939);
    if (IS_ATOM_INT(_asm97531)) {
        _9939 = _asm97531 + 18;
        if ((long)((unsigned long)_9939 + (unsigned long)HIGH_BITS) >= 0) 
            _9939 = NewDouble((double)_9939);
    }
    else {
        _9939 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)18);
    }
    DeRef(_9945);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9945 = (int)*(((s1_ptr)_2)->base + _r);
    Ref(_9945);
    _0 = _9945;
    _2 = (int)SEQ_PTR(_9945);
    _9945 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_9945);
    DeRef(_0);
    _0 = _9945;
    if (IS_ATOM_INT(_9945)) {
        if (_9945 == (short)_9945)
            _9945 = _9945 * 4;
        else
            _9945 = NewDouble(_9945 * (double)4);
    }
    else {
        _9945 = binary_op(MULTIPLY, _9945, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_9939))
        poke_addr = (unsigned char *)_9939;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_9939)->dbl);
    if (IS_ATOM_INT(_9945)) {
        *poke_addr = (unsigned char)_9945;
    }
    else if (IS_ATOM(_9945)) {
        *poke_addr = (signed char)DBL_PTR(_9945)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_9945);
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

    // 		poke4( asm + 20, call_back( routine_id("machine_callback") ) )
    DeRef(_9945);
    if (IS_ATOM_INT(_asm97531)) {
        _9945 = _asm97531 + 20;
        if ((long)((unsigned long)_9945 + (unsigned long)HIGH_BITS) >= 0) 
            _9945 = NewDouble((double)_9945);
    }
    else {
        _9945 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)20);
    }
    DeRef(_9939);
    _9939 = CRoutineId(474, 17, _9965);
    _9939 = _18call_back(_9939);
    if (IS_ATOM_INT(_9945))
        poke4_addr = (unsigned long *)_9945;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9945)->dbl);
    if (IS_ATOM_INT(_9939)) {
        *poke4_addr = (unsigned long)_9939;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_9939)->dbl;
    }
    goto L8;
L6:

    // 	    asm = allocate( length(cb_cdecl) )  
    DeRef(_9939);
    _9939 = 27;
    _0 = _asm97531;
    _asm97531 = _4allocate(27);
    DeRef(_0);

    // 	    poke( asm, cb_cdecl )
    if (IS_ATOM_INT(_asm97531))
        poke_addr = (unsigned char *)_asm97531;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_asm97531)->dbl);
    _1 = (int)SEQ_PTR(_17cb_cdecl);
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

    // 	    poke4( asm + 7, length(call_backs) + 1 )
    if (IS_ATOM_INT(_asm97531)) {
        _9939 = _asm97531 + 7;
        if ((long)((unsigned long)_9939 + (unsigned long)HIGH_BITS) >= 0) 
            _9939 = NewDouble((double)_9939);
    }
    else {
        _9939 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)7);
    }
    DeRef(_9945);
    _9945 = SEQ_PTR(_17call_backs)->length;
    _9945 = _9945 + 1;
    if (IS_ATOM_INT(_9939))
        poke4_addr = (unsigned long *)_9939;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9939)->dbl);
    *poke4_addr = (unsigned long)_9945;

    // 	    poke4( asm + 13, asm + 23 )
    if (IS_ATOM_INT(_asm97531)) {
        _9945 = _asm97531 + 13;
        if ((long)((unsigned long)_9945 + (unsigned long)HIGH_BITS) >= 0) 
            _9945 = NewDouble((double)_9945);
    }
    else {
        _9945 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)13);
    }
    DeRef(_9939);
    if (IS_ATOM_INT(_asm97531)) {
        _9939 = _asm97531 + 23;
        if ((long)((unsigned long)_9939 + (unsigned long)HIGH_BITS) >= 0) 
            _9939 = NewDouble((double)_9939);
    }
    else {
        _9939 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)23);
    }
    if (IS_ATOM_INT(_9945))
        poke4_addr = (unsigned long *)_9945;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9945)->dbl);
    if (IS_ATOM_INT(_9939)) {
        *poke4_addr = (unsigned long)_9939;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_9939)->dbl;
    }

    // 		poke4( asm + 23, call_back( '+' & routine_id("machine_callback") ) )
    DeRef(_9939);
    if (IS_ATOM_INT(_asm97531)) {
        _9939 = _asm97531 + 23;
        if ((long)((unsigned long)_9939 + (unsigned long)HIGH_BITS) >= 0) 
            _9939 = NewDouble((double)_9939);
    }
    else {
        _9939 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)23);
    }
    DeRef(_9945);
    _9945 = CRoutineId(474, 17, _9965);
    Concat((object_ptr)&_9945, 43, (s1_ptr)_9945);
    RefDS(_9945);
    _0 = _9945;
    _9945 = _18call_back(_9945);
    DeRefDSi(_0);
    if (IS_ATOM_INT(_9939))
        poke4_addr = (unsigned long *)_9939;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_9939)->dbl);
    if (IS_ATOM_INT(_9945)) {
        *poke4_addr = (unsigned long)_9945;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_9945)->dbl;
    }
L8:

    // 	val[target] = asm
    Ref(_asm97531);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _asm97531;
    DeRef(_1);

    // 	call_backs = append( call_backs, { r, id, SymTab[r][S_NUM_ARGS] })
    DeRef(_9945);
    _2 = (int)SEQ_PTR(_7SymTab);
    _9945 = (int)*(((s1_ptr)_2)->base + _r);
    Ref(_9945);
    _0 = _9945;
    _2 = (int)SEQ_PTR(_9945);
    _9945 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_9945);
    DeRef(_0);
    _0 = _9945;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _r;
    *((int *)(_2+8)) = _id;
    Ref(_9945);
    *((int *)(_2+12)) = _9945;
    _9945 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9945);
    Append(&_17call_backs, _17call_backs, _9945);

    // end procedure	 
    DeRef(_asm97531);
    DeRef(_x);
    DeRefDS(_9945);
    DeRef(_9939);
    return 0;
    ;
}


int _17do_crash_routine(int _b)
{
    int _x = 0;
    int _9983 = 0;
    int _9986 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    // 	x = val[b]
    _2 = (int)SEQ_PTR(_17val);
    _x = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_x);

    // 	if atom(x) and x >= 0 and x < length(e_routine) then
    _9983 = IS_ATOM(_x);
    if (_9983 == 0) {
        _9983 = 0;
        goto L1;
    }
    if (IS_ATOM_INT(_x)) {
        _9986 = (_x >= 0);
    }
    else {
        _9986 = binary_op(GREATEREQ, _x, 0);
    }
    if (IS_ATOM_INT(_9986))
        _9983 = (_9986 != 0);
    else
        _9983 = DBL_PTR(_9986)->dbl != 0.0;
L1:
    if (_9983 == 0) {
        goto L2;
    }
    DeRef(_9983);
    _9983 = SEQ_PTR(_17e_routine)->length;
    if (IS_ATOM_INT(_x)) {
        _9983 = (_x < _9983);
    }
    else {
        _9983 = binary_op(LESS, _x, _9983);
    }
L3:
    if (_9983 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9983) && DBL_PTR(_9983)->dbl == 0.0)
            goto L2;
    }

    // 		crash_list &= x 
    if (IS_SEQUENCE(_17crash_list) && IS_ATOM(_x)) {
        Ref(_x);
        Append(&_17crash_list, _17crash_list, _x);
    }
    else if (IS_ATOM(_17crash_list) && IS_SEQUENCE(_x)) {
    }
    else {
        Concat((object_ptr)&_17crash_list, _17crash_list, (s1_ptr)_x);
    }
    goto L4;
L2:

    // 		RTFatal("crash routine requires a valid routine id")
    RefDS(_9991);
    _17RTFatal(_9991);

    // 		return
    DeRef(_x);
    DeRef(_9983);
    DeRef(_9986);
    return 0;
L4:

    // end procedure
    DeRef(_x);
    DeRef(_9983);
    DeRef(_9986);
    return 0;
    ;
}


int _17opMACHINE_FUNC()
{
    int _10002 = 0;
    int _9992 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _9992 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _9992);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2] 
    _9992 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _9992);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	target = Code[pc+3]
    _9992 = _17pc + 3;
    _2 = (int)SEQ_PTR(_7Code);
    _17target = (int)*(((s1_ptr)_2)->base + _9992);
    if (!IS_ATOM_INT(_17target))
        _17target = (long)DBL_PTR(_17target)->dbl;

    // 	pc += 4
    _17pc = _17pc + 4;

    // 	if val[a] = M_CALL_BACK then
    _2 = (int)SEQ_PTR(_17val);
    _9992 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9992);
    if (binary_op_a(NOTEQ, _9992, 52))
        goto L1;

    // 	do_callback(b)  
    _17do_callback(_17b);
    goto L2;
L1:

    // 	val[target] = machine_func(val[a], val[b])
    DeRef(_9992);
    _2 = (int)SEQ_PTR(_17val);
    _9992 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_9992);
    DeRef(_10002);
    _2 = (int)SEQ_PTR(_17val);
    _10002 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_10002);
    _0 = _10002;
    _10002 = machine(_9992, _10002);
    DeRef(_0);
    Ref(_10002);
    _2 = (int)SEQ_PTR(_17val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _17val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17target);
    _1 = *(int *)_2;
    *(int *)_2 = _10002;
    DeRef(_1);
L2:

    // end procedure
    DeRef(_10002);
    DeRef(_9992);
    return 0;
    ;
}


int _17opMACHINE_PROC()
{
    int _v = 0;
    int _10004 = 0;
    int _10014 = 0;
    int _0, _1, _2;
    

    // 	a = Code[pc+1]
    _10004 = _17pc + 1;
    _2 = (int)SEQ_PTR(_7Code);
    _17a = (int)*(((s1_ptr)_2)->base + _10004);
    if (!IS_ATOM_INT(_17a))
        _17a = (long)DBL_PTR(_17a)->dbl;

    // 	b = Code[pc+2]
    _10004 = _17pc + 2;
    _2 = (int)SEQ_PTR(_7Code);
    _17b = (int)*(((s1_ptr)_2)->base + _10004);
    if (!IS_ATOM_INT(_17b))
        _17b = (long)DBL_PTR(_17b)->dbl;

    // 	v = val[a]
    _2 = (int)SEQ_PTR(_17val);
    _v = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_v);

    // 	if v = M_CRASH_ROUTINE then
    if (binary_op_a(NOTEQ, _v, 66))
        goto L1;

    // 	do_crash_routine(b) 
    _17do_crash_routine(_17b);
    goto L2;
L1:

    // 	elsif v = M_CRASH_MESSAGE then
    if (binary_op_a(NOTEQ, _v, 37))
        goto L3;

    // 	crash_msg = val[b]
    DeRef(_17crash_msg);
    _2 = (int)SEQ_PTR(_17val);
    _17crash_msg = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_17crash_msg);
    goto L2;
L3:

    // 	elsif v = M_CRASH_FILE and sequence(val[b]) then
    DeRef(_10004);
    if (IS_ATOM_INT(_v)) {
        _10004 = (_v == 57);
    }
    else {
        _10004 = binary_op(EQUALS, _v, 57);
    }
    if (IS_ATOM_INT(_10004)) {
        if (_10004 == 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_10004)->dbl == 0.0) {
            goto L4;
        }
    }
    DeRef(_10014);
    _2 = (int)SEQ_PTR(_17val);
    _10014 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_10014);
    _0 = _10014;
    _10014 = IS_SEQUENCE(_10014);
    DeRef(_0);
L5:
    if (_10014 == 0)
        goto L4;

    // 	err_file_name = val[b]  
    DeRef(_17err_file_name);
    _2 = (int)SEQ_PTR(_17val);
    _17err_file_name = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_17err_file_name);
    goto L2;
L4:

    // 	machine_proc(val[a], val[b]) 
    DeRef(_10014);
    _2 = (int)SEQ_PTR(_17val);
    _10014 = (int)*(((s1_ptr)_2)->base + _17a);
    Ref(_10014);
    DeRef(_10004);
    _2 = (int)SEQ_PTR(_17val);
    _10004 = (int)*(((s1_ptr)_2)->base + _17b);
    Ref(_10004);
    machine(_10014, _10004);
L2:

    // 	pc += 3
    _17pc = _17pc + 3;

    // end procedure
    DeRef(_v);
    DeRef(_10004);
    DeRef(_10014);
    return 0;
    ;
}


int _17save_il()
{
    int _st;
    int _10027 = 0;
    int _10022 = 0;
    int _0, _1, _2;
    

    // 	puts(2,"save il\n")
    EPuts(2, _10020);

    // 	printf(2,"%s.sym", {source_name})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7source_name);
    *((int *)(_2+4)) = _7source_name;
    _10022 = MAKE_SEQ(_1);
    EPrintf(2, _10021, _10022);

    // 	st = open( sprintf("%s.sym", {source_name}), "w" )
    _0 = _10022;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7source_name);
    *((int *)(_2+4)) = _7source_name;
    _10022 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _10022;
    _10022 = EPrintf(-9999999, _10021, _10022);
    DeRefDS(_0);
    _st = EOpen(_10022, _6794);

    // 	for j = 1 to length( SymTab ) do
    DeRefDSi(_10022);
    _10022 = SEQ_PTR(_7SymTab)->length;
    { int _j;
        _j = 1;
L1:
        if (_j > _10022)
            goto L2;

        // 		print( st, j & SymTab[j] ) puts( st, "\n" )
        DeRef(_10027);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10027 = (int)*(((s1_ptr)_2)->base + _j);
        Ref(_10027);
        if (IS_SEQUENCE(_j) && IS_ATOM(_10027)) {
        }
        else if (IS_ATOM(_j) && IS_SEQUENCE(_10027)) {
            Prepend(&_10027, _10027, _j);
        }
        else {
            Concat((object_ptr)&_10027, _j, (s1_ptr)_10027);
        }
        RefDS(_10027);
        _5print(_st, _10027);
        EPuts(_st, _738);

        // 	end for
        _j = _j + 1;
        goto L1;
L2:
        ;
    }

    // 	close( st )
    EClose(_st);

    // end procedure
    DeRef(_10027);
    DeRef(_10022);
    return 0;
    ;
}


int _17InitBackEnd()
{
    int _name = 0;
    int _10029 = 0;
    int _10032 = 0;
    int _0, _1, _2;
    

    // 	val = repeat(0, length(SymTab))
    _10029 = SEQ_PTR(_7SymTab)->length;
    DeRef(_17val);
    _17val = Repeat(0, _10029);

    // 	for i = 1 to length(SymTab) do
    _10029 = SEQ_PTR(_7SymTab)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _10029)
            goto L2;

        // 	val[i] = SymTab[i][S_OBJ] -- might be NOVALUE
        DeRef(_10032);
        _2 = (int)SEQ_PTR(_7SymTab);
        _10032 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10032);
        _0 = _10032;
        _2 = (int)SEQ_PTR(_10032);
        _10032 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_10032);
        DeRef(_0);
        Ref(_10032);
        _2 = (int)SEQ_PTR(_17val);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _17val = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _10032;
        DeRef(_1);

        // 	end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // 	operation = repeat(-1, length(opnames))
    DeRef(_10032);
    _10032 = 182;
    DeRefi(_17operation);
    _17operation = Repeat(-1, 182);

    // 	for i = 1 to length(opnames) do
    _10032 = 182;
    { int _i;
        _i = 1;
L3:
        if (_i > 182)
            goto L4;

        // 	name = opnames[i]
        DeRef(_name);
        _2 = (int)SEQ_PTR(_19opnames);
        _name = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_name);

        // 	if find(name, {"RHS_SUBS_CHECK", "RHS_SUBS_I"}) then
        DeRef(_10029);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _6686;
        RefDS(_6686);
        ((int *)_2)[2] = _6708;
        RefDS(_6708);
        _10029 = MAKE_SEQ(_1);
        _0 = _10029;
        _10029 = find(_name, _10029);
        DeRefDS(_0);
        if (_10029 == 0)
            goto L5;

        // 	    name = "RHS_SUBS"
        RefDS(_6619);
        DeRefDS(_name);
        _name = _6619;
        goto L6;
L5:

        // 	elsif find(name, {"ASSIGN_SUBS_CHECK", "ASSIGN_SUBS_I"}) then
        DeRef(_10029);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _6678;
        RefDS(_6678);
        ((int *)_2)[2] = _6712;
        RefDS(_6712);
        _10029 = MAKE_SEQ(_1);
        _0 = _10029;
        _10029 = find(_name, _10029);
        DeRefDS(_0);
        if (_10029 == 0)
            goto L7;

        // 	    name = "ASSIGN_SUBS"
        RefDS(_6610);
        DeRefDS(_name);
        _name = _6610;
        goto L6;
L7:

        // 	elsif equal(name, "ASSIGN_I") then
        DeRef(_10029);
        if (_name == _6707)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6707))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6707) == 0);
        if (_10029 == 0)
            goto L8;

        // 	    name = "ASSIGN"
        RefDS(_6612);
        DeRefDS(_name);
        _name = _6612;
        goto L6;
L8:

        // 	elsif find(name, {"EXIT", "ENDWHILE", "GOTO_STATIC"}) then
        _0 = _10029;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_6655);
        *((int *)(_2+4)) = _6655;
        RefDS(_6616);
        *((int *)(_2+8)) = _6616;
        RefDS(_6770);
        *((int *)(_2+12)) = _6770;
        _10029 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10029;
        _10029 = find(_name, _10029);
        DeRefDS(_0);
        if (_10029 == 0)
            goto L9;

        // 	    name = "ELSE"
        RefDS(_6617);
        DeRefDS(_name);
        _name = _6617;
        goto L6;
L9:

        // 	elsif equal(name, "PLUS1_I") then
        DeRef(_10029);
        if (_name == _6711)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6711))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6711) == 0);
        if (_10029 == 0)
            goto LA;

        // 	    name = "PLUS1"      
        RefDS(_6687);
        DeRefDS(_name);
        _name = _6687;
        goto L6;
LA:

        // 	elsif equal(name, "PRIVATE_INIT_CHECK") then
        DeRef(_10029);
        if (_name == _6624)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6624))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6624) == 0);
        if (_10029 == 0)
            goto LB;

        // 	    name = "GLOBAL_INIT_CHECK"
        RefDS(_6703);
        DeRefDS(_name);
        _name = _6703;
        goto L6;
LB:

        // 	elsif equal(name, "PLUS_I") then
        DeRef(_10029);
        if (_name == _6709)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6709))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6709) == 0);
        if (_10029 == 0)
            goto LC;

        // 	    name = "PLUS"
        RefDS(_6605);
        DeRefDS(_name);
        _name = _6605;
        goto L6;
LC:

        // 	elsif equal(name, "MINUS_I") then
        DeRef(_10029);
        if (_name == _6710)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6710))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6710) == 0);
        if (_10029 == 0)
            goto LD;

        // 	    name = "MINUS"
        RefDS(_6604);
        DeRefDS(_name);
        _name = _6604;
        goto L6;
LD:

        // 	elsif equal(name, "FOR_I") then
        DeRef(_10029);
        if (_name == _6719)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6719))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6719) == 0);
        if (_10029 == 0)
            goto LE;

        // 	    name = "FOR"
        RefDS(_6615);
        DeRefDS(_name);
        _name = _6615;
        goto L6;
LE:

        // 	elsif find(name, {"ENDFOR_UP", "ENDFOR_DOWN", 
        _0 = _10029;
        _1 = NewS1(5);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_6643);
        *((int *)(_2+4)) = _6643;
        RefDS(_6644);
        *((int *)(_2+8)) = _6644;
        RefDS(_6642);
        *((int *)(_2+12)) = _6642;
        RefDS(_6646);
        *((int *)(_2+16)) = _6646;
        RefDS(_6649);
        *((int *)(_2+20)) = _6649;
        _10029 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10029;
        _10029 = find(_name, _10029);
        DeRefDS(_0);
        if (_10029 == 0)
            goto LF;

        // 	    name = "ENDFOR_GENERAL"
        RefDS(_6633);
        DeRefDS(_name);
        _name = _6633;
        goto L6;
LF:

        // 	elsif equal(name, "CALL_FUNC") then
        DeRef(_10029);
        if (_name == _6733)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6733))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6733) == 0);
        if (_10029 == 0)
            goto L10;

        // 	    name = "CALL_PROC"
        RefDS(_6732);
        DeRefDS(_name);
        _name = _6732;
        goto L6;
L10:

        // 	elsif equal(name, "SC2_AND") then
        DeRef(_10029);
        if (_name == _6738)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6738))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6738) == 0);
        if (_10029 == 0)
            goto L11;

        // 	    name = "SC2_OR"
        RefDS(_6740);
        DeRefDS(_name);
        _name = _6740;
        goto L6;
L11:

        // 	elsif find(name, {"SC2_NULL", "ASSIGN_SUBS2", "PLATFORM",
        _0 = _10029;
        _1 = NewS1(6);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_6741);
        *((int *)(_2+4)) = _6741;
        RefDS(_6744);
        *((int *)(_2+8)) = _6744;
        RefDS(_6751);
        *((int *)(_2+12)) = _6751;
        RefDS(_6752);
        *((int *)(_2+16)) = _6752;
        RefDS(_6754);
        *((int *)(_2+20)) = _6754;
        RefDS(_6755);
        *((int *)(_2+24)) = _6755;
        _10029 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _10029;
        _10029 = find(_name, _10029);
        DeRefDS(_0);
        if (_10029 == 0)
            goto L12;

        // 	    name = "NOP2" 
        RefDS(_6704);
        DeRefDS(_name);
        _name = _6704;
        goto L6;
L12:

        // 	elsif equal(name, "GREATER_IFW_I") then
        DeRef(_10029);
        if (_name == _6718)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6718))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6718) == 0);
        if (_10029 == 0)
            goto L13;

        // 	    name = "GREATER_IFW"
        RefDS(_6701);
        DeRefDS(_name);
        _name = _6701;
        goto L6;
L13:

        // 	elsif equal(name, "LESS_IFW_I") then
        DeRef(_10029);
        if (_name == _6713)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6713))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6713) == 0);
        if (_10029 == 0)
            goto L14;

        // 	    name = "LESS_IFW"
        RefDS(_6696);
        DeRefDS(_name);
        _name = _6696;
        goto L6;
L14:

        // 	elsif equal(name, "EQUALS_IFW_I") then
        DeRef(_10029);
        if (_name == _6715)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6715))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6715) == 0);
        if (_10029 == 0)
            goto L15;

        // 	    name = "EQUALS_IFW"
        RefDS(_6698);
        DeRefDS(_name);
        _name = _6698;
        goto L6;
L15:

        // 	elsif equal(name, "NOTEQ_IFW_I") then
        DeRef(_10029);
        if (_name == _6716)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6716))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6716) == 0);
        if (_10029 == 0)
            goto L16;

        // 	    name = "NOTEQ_IFW"
        RefDS(_6699);
        DeRefDS(_name);
        _name = _6699;
        goto L6;
L16:

        // 	elsif equal(name, "GREATEREQ_IFW_I") then
        DeRef(_10029);
        if (_name == _6714)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6714))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6714) == 0);
        if (_10029 == 0)
            goto L17;

        // 	    name = "GREATEREQ_IFW"
        RefDS(_6697);
        DeRefDS(_name);
        _name = _6697;
        goto L6;
L17:

        // 	elsif equal(name, "LESSEQ_IFW_I") then
        DeRef(_10029);
        if (_name == _6717)
            _10029 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_6717))
            _10029 = 0;
        else
            _10029 = (compare(_name, _6717) == 0);
        if (_10029 == 0)
            goto L18;

        // 	    name = "LESSEQ_IFW"
        RefDS(_6700);
        DeRefDS(_name);
        _name = _6700;
L18:
L6:

        // 	operation[i] = routine_id("op" & name)
        Concat((object_ptr)&_10029, _10062, (s1_ptr)_name);
        _0 = _10029;
        _10029 = CRoutineId(479, 17, _10029);
        DeRefDS(_0);
        _2 = (int)SEQ_PTR(_17operation);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = _10029;

        // 	if operation[i] = -1 then
        _2 = (int)SEQ_PTR(_17operation);
        _10029 = (int)*(((s1_ptr)_2)->base + _i);
        if (_10029 != -1)
            goto L19;

        // 	    RTInternal("no routine id for op" & name)
        Concat((object_ptr)&_10029, _10067, (s1_ptr)_name);
        RefDS(_10029);
        _17RTInternal(_10029);
L19:

        // 	end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    // end procedure
    DeRef(_name);
    DeRef(_10029);
    DeRef(_10032);
    return 0;
    ;
}


int _17Execute(int _proc, int _start_index)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }
    if (!IS_ATOM_INT(_start_index)) {
        _1 = (long)(DBL_PTR(_start_index)->dbl);
        DeRefDS(_start_index);
        _start_index = _1;
    }

    // 	CurrentSub = proc
    _7CurrentSub = _proc;

    // 	call_stack = {CurrentSub}
    _0 = _17call_stack;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _7CurrentSub;
    _17call_stack = MAKE_SEQ(_1);
    DeRef(_0);

    // 	pc = start_index
    _17pc = _start_index;

    // 	do_exec()
    _17do_exec();

    // end procedure
    return 0;
    ;
}


int _17crash(int _c)
{
    int _entry = 0;
    int _10072 = 0;
    int _10078 = 0;
    int _0, _1, _2;
    

    // 	if length(file_name) then
    _10072 = SEQ_PTR(_7file_name)->length;
    if (_10072 == 0)
        goto L1;

    // 		puts(2, "OOEU has crashed...\n")
    EPuts(2, _10073);

    // 		if not bound then
    if (_7bound != 0)
        goto L2;

    // 			puts( 2, "Dumping symbol table...\n" )
    EPuts(2, _10075);

    // 			save_il()
    _17save_il();
L2:

    // 		if length(slist) and atom(slist[$]) then
    DeRef(_10072);
    _10072 = SEQ_PTR(_7slist)->length;
    if (_10072 == 0) {
        goto L3;
    }
    DeRef(_10078);
    _10078 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _10078 = (int)*(((s1_ptr)_2)->base + _10078);
    Ref(_10078);
    _0 = _10078;
    _10078 = IS_ATOM(_10078);
    DeRef(_0);
L4:
    if (_10078 == 0)
        goto L3;

    // 			slist = s_expand(slist)
    RefDS(_7slist);
    _0 = _12s_expand(_7slist);
    DeRefDS(_7slist);
    _7slist = _0;
L3:

    // 		if length(call_stack) and call_stack[$] and length(SymTab[call_stack[$]]) = SIZEOF_ROUTINE_ENTRY and
    DeRef(_10078);
    _10078 = SEQ_PTR(_17call_stack)->length;
    if (_10078 == 0) {
        _10078 = 0;
        goto L5;
    }
    DeRef(_10072);
    _10072 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    if (IS_ATOM_INT(_10072))
        _10078 = (_10072 != 0);
    else
        _10078 = DBL_PTR(_10072)->dbl != 0.0;
L5:
    if (_10078 == 0) {
        DeRef(_10072);
        _10072 = 0;
        goto L6;
    }
    DeRef(_10078);
    _10078 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _10078 = (int)*(((s1_ptr)_2)->base + _10078);
    Ref(_10078);
    _0 = _10078;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_10078))
        _10078 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_10078)->dbl));
    else
        _10078 = (int)*(((s1_ptr)_2)->base + _10078);
    Ref(_10078);
    DeRef(_0);
    _0 = _10078;
    _10078 = SEQ_PTR(_10078)->length;
    DeRef(_0);
    _10078 = (_10078 == 25);
    _10072 = (_10078 != 0);
L6:
    if (_10072 == 0) {
        goto L7;
    }
    DeRef(_10072);
    _10072 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    _0 = _10072;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_10072))
        _10072 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_10072)->dbl));
    else
        _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    DeRef(_0);
    _0 = _10072;
    _2 = (int)SEQ_PTR(_10072);
    _10072 = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_10072);
    DeRef(_0);
    _0 = _10072;
    _10072 = IS_SEQUENCE(_10072);
    DeRef(_0);
L8:
    if (_10072 == 0)
        goto L7;

    // 			printf(2, "\n%s: %d\nLine:\n%s\n", find_line( call_stack[$], pc ) & {ThisLine})	
    DeRef(_10072);
    _10072 = SEQ_PTR(_17call_stack)->length;
    _2 = (int)SEQ_PTR(_17call_stack);
    _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    Ref(_10072);
    _0 = _10072;
    _10072 = _17find_line(_10072, _17pc);
    DeRef(_0);
    _0 = _10078;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9ThisLine);
    *((int *)(_2+4)) = _9ThisLine;
    _10078 = MAKE_SEQ(_1);
    DeRef(_0);
    Concat((object_ptr)&_10078, _10072, (s1_ptr)_10078);
    EPrintf(2, _10098, _10078);
    goto L9;
L7:

    // 			printf(2, "\n%s: %d\nLine:\n%s\n", {file_name[current_file_no], slist[$][2],ThisLine})	
    DeRef(_10078);
    _2 = (int)SEQ_PTR(_7file_name);
    _10078 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_10078);
    DeRef(_10072);
    _10072 = SEQ_PTR(_7slist)->length;
    _2 = (int)SEQ_PTR(_7slist);
    _10072 = (int)*(((s1_ptr)_2)->base + _10072);
    Ref(_10072);
    _0 = _10072;
    _2 = (int)SEQ_PTR(_10072);
    _10072 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_10072);
    DeRef(_0);
    _0 = _10072;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_10078);
    *((int *)(_2+4)) = _10078;
    Ref(_10072);
    *((int *)(_2+8)) = _10072;
    Ref(_9ThisLine);
    *((int *)(_2+12)) = _9ThisLine;
    _10072 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(2, _10098, _10072);
L9:

    // 		if execute then
    if (_7execute == 0)
        goto LA;

    // 			open_err_file()
    _17open_err_file();

    // 			if length(call_stack) then
    DeRef(_10072);
    _10072 = SEQ_PTR(_17call_stack)->length;
    if (_10072 == 0)
        goto LB;

    // 				trace_back("")
    RefDS(_39);
    _17trace_back(_39);
LB:

    // 			call_crash_routines()
    _17call_crash_routines();
    goto LC;
LA:

    // 		elsif preprocess then
    if (_7preprocess == 0)
        goto LD;

    // 			call_proc( POST_PROCESS_RID, {})
    _0 = (int)_00[_7POST_PROCESS_RID].addr;
    (*(int (*)())_0)(
                         );
LD:
LC:
L1:

    // 	if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto LE;

    // 		c_proc( cleanup_cb, {})
    call_c(0, _7cleanup_cb, _39);
LE:

    // 	return 0
    DeRef(_c);
    DeRef(_entry);
    DeRef(_10072);
    DeRef(_10078);
    return 0;
    ;
}


int _17BackEnd(int _ignore)
{
    int _0, _1, _2;
    

    // 	Execute(TopLevelSub, 1)
    _17Execute(_7TopLevelSub, 1);

    // end procedure
    return 0;
    ;
}


