// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16Method(int _tok)
{
    int _scope;
    int _opcode;
    int _class;
    int _tok1;
    int _tok2;
    int _real_instance;
    int _member;
    int _last_member;
    int _ix;
    int _temp_tok = 0;
    int _ppoff = 0;
    int _s;
    int _sym;
    int _csym;
    int _pdec = 0;
    int _first_arg = 0;
    int _6251 = 0;
    int _6325 = 0;
    int _6267 = 0;
    int _6268 = 0;
    int _0, _1, _2, _3;
    

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 		cache_line()
    _16cache_line();
L1:

    // 	member = is_member( tok )
    RefDS(_tok);
    _member = _11is_member(_tok);

    // 	if member then
    if (_member == 0)
        goto L2;

    // 		tok[T_SYM] = member_table[MEMBER_SYM][member]
    DeRef1(_6251);
    _2 = (int)SEQ_PTR(_7member_table);
    _6251 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_6251);
    _0 = _6251;
    _2 = (int)SEQ_PTR(_6251);
    _6251 = (int)*(((s1_ptr)_2)->base + _member);
    Ref(_6251);
    DeRef1(_0);
    Ref(_6251);
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _6251;
    DeRef(_1);

    // 		member_stack &= member
    Append(&_7member_stack, _7member_stack, _member);

    // 		Assignment( tok )
    RefDS(_tok);
    _16Assignment(_tok);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L3;

    // 					release_line()
    _16release_line();
L3:

    // 		return
    DeRef1(_tok);
    DeRef1(_temp_tok);
    DeRef1(_ppoff);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef(_6251);
    DeRef(_6325);
    DeRef(_6267);
    DeRef(_6268);
    return 0;
L2:

    // 	tok1 = length(line_tokens) - 2
    DeRef1(_6251);
    _6251 = SEQ_PTR(_7line_tokens)->length;
    _tok1 = _6251 - 2;

    //     method_stack &= {tok}
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _6251 = MAKE_SEQ(_1);
    Concat((object_ptr)&_7method_stack, _7method_stack, (s1_ptr)_6251);

    //     method_args &= { {} }
    _0 = _6251;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_39);
    *((int *)(_2+4)) = _39;
    _6251 = MAKE_SEQ(_1);
    DeRef1(_0);
    Concat((object_ptr)&_7method_args, _7method_args, (s1_ptr)_6251);

    //     method_name = append( method_name, SymTab[tok[T_SYM]][S_NAME] )
    DeRef1(_6251);
    _2 = (int)SEQ_PTR(_tok);
    _6251 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6251);
    _0 = _6251;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_6251))
        _6251 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6251)->dbl));
    else
        _6251 = (int)*(((s1_ptr)_2)->base + _6251);
    Ref(_6251);
    DeRef1(_0);
    _0 = _6251;
    _2 = (int)SEQ_PTR(_6251);
    _6251 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6251);
    DeRef1(_0);
    Ref(_6251);
    Append(&_7method_name, _7method_name, _6251);

    //     SymTab[tok[T_SYM]][S_USAGE] = or_bits( U_READ, U_WRITTEN )
    DeRef1(_6251);
    _2 = (int)SEQ_PTR(_tok);
    _6251 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6251);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_6251))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_6251)->dbl));
    else
        _3 = (int)(_6251 + ((s1_ptr)_2)->base);
    DeRef1(_6268);
    _6268 = (1 | 2);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _6268;
    DeRef(_1);

    //     current_method += 1
    _7current_method = _7current_method + 1;

    //     parse_method_stack &= 1
    Append(&_7parse_method_stack, _7parse_method_stack, 1);

    //     tok_match(LEFT_ROUND)
    _16tok_match(-26);

    //     s = tok[T_SYM] 
    _2 = (int)SEQ_PTR(_tok);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     if member_stack[$] then
    _6268 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _6268 = (int)*(((s1_ptr)_2)->base + _6268);
    Ref(_6268);
    if (_6268 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_6268) && DBL_PTR(_6268)->dbl == 0.0)
            goto L4;
    }

    //     	emit_opnd( current_instance[$] )
    DeRef1(_6268);
    _6268 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6268 = (int)*(((s1_ptr)_2)->base + _6268);
    Ref(_6268);
    Ref(_6268);
    _15emit_opnd(_6268);

    //     	for m = 2 to length(member_stack) do
    DeRef1(_6268);
    _6268 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L5:
        if (_m > _6268)
            goto L6;

        //     		if m > 2 then
        if (_m <= 2)
            goto L7;

        //     			emit_opnd( current_sequence[$] )
        DeRef(_6267);
        _6267 = SEQ_PTR(_15current_sequence)->length;
        _2 = (int)SEQ_PTR(_15current_sequence);
        _6267 = (int)*(((s1_ptr)_2)->base + _6267);
        Ref(_6267);
        Ref(_6267);
        _15emit_opnd(_6267);
L7:

        //     		if member_stack[m] > 0 then
        DeRef(_6267);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6267 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6267);
        if (binary_op_a(LESSEQ, _6267, 0))
            goto L8;

        //     			emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
        DeRef(_6267);
        _2 = (int)SEQ_PTR(_7member_table);
        _6267 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_6267);
        DeRef(_6251);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6251 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6251);
        _0 = _6251;
        _2 = (int)SEQ_PTR(_6267);
        if (!IS_ATOM_INT(_6251))
            _6251 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6251)->dbl));
        else
            _6251 = (int)*(((s1_ptr)_2)->base + _6251);
        Ref(_6251);
        DeRef(_0);
        Ref(_6251);
        _15emit_opnd(_6251);

        //     			emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L9;
L8:

        //     		elsif integer( member_stack[m] ) then
        DeRef(_6251);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6251 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6251);
        _0 = _6251;
        if (IS_ATOM_INT(_6251))
            _6251 = 1;
        else if (IS_ATOM_DBL(_6251))
            _6251 = IS_ATOM_INT(DoubleToInt(_6251));
        else
            _6251 = 0;
        DeRef(_0);
        if (_6251 == 0)
            goto LA;

        //     			emit_opnd( -member_stack[m] )
        _2 = (int)SEQ_PTR(_7member_stack);
        _6251 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6251);
        _0 = _6251;
        if (IS_ATOM_INT(_6251)) {
            if (_6251 == 0xC0000000)
                _6251 = (int)NewDouble((double)-0xC0000000);
            else
                _6251 = - _6251;
        }
        else {
            _6251 = unary_op(UMINUS, _6251);
        }
        DeRef(_0);
        Ref(_6251);
        _15emit_opnd(_6251);

        //     			emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L9;
LA:

        //     			emit_op( DOLLAR )
        _15emit_op(-22);

        //     			emit_op( RHS_SUBS )
        _15emit_op(25);
L9:

        //     	end for
        _m = _m + 1;
        goto L5;
L6:
        ;
    }

    //     	sym = current_sequence[$]
    DeRef1(_6251);
    _6251 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _sym = (int)*(((s1_ptr)_2)->base + _6251);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     	current_sequence = current_sequence[1..$-1]
    _6251 = SEQ_PTR(_15current_sequence)->length;
    _6251 = _6251 - 1;
    rhs_slice_target = (object_ptr)&_15current_sequence;
    RHS_Slice((s1_ptr)_15current_sequence, 1, _6251);

    //     	real_instance = 3
    _real_instance = 3;

    //     	if preprocess then
    if (_7preprocess == 0)
        goto LB;

    //     		first_arg = ""
    RefDS(_39);
    DeRef1(_first_arg);
    _first_arg = _39;

    //     		if is_sequenceof( current_instance[$] ) then
    _6251 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6251 = (int)*(((s1_ptr)_2)->base + _6251);
    Ref(_6251);
    Ref(_6251);
    _0 = _6251;
    _6251 = _11is_sequenceof(_6251);
    DeRef1(_0);
    if (_6251 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_6251) && DBL_PTR(_6251)->dbl == 0.0)
            goto LC;
    }

    //     			first_arg = sprintf("[%s]", {token_text( length(line_tokens) - (length(member_stack)-1)*2 - 2 )})
    DeRef1(_6251);
    _6251 = SEQ_PTR(_7line_tokens)->length;
    DeRef1(_6267);
    _6267 = SEQ_PTR(_7member_stack)->length;
    _6267 = _6267 - 1;
    _6267 = _6267 + _6267;
    if ((long)((unsigned long)_6267 + (unsigned long)HIGH_BITS) >= 0) 
        _6267 = NewDouble((double)_6267);
    _0 = _6267;
    if (IS_ATOM_INT(_6267)) {
        _6267 = _6251 - _6267;
        if ((long)((unsigned long)_6267 +(unsigned long) HIGH_BITS) >= 0)
            _6267 = NewDouble((double)_6267);
    }
    else {
        _6267 = NewDouble((double)_6251 - DBL_PTR(_6267)->dbl);
    }
    DeRef1(_0);
    _0 = _6267;
    if (IS_ATOM_INT(_6267)) {
        _6267 = _6267 - 2;
        if ((long)((unsigned long)_6267 +(unsigned long) HIGH_BITS) >= 0)
            _6267 = NewDouble((double)_6267);
    }
    else {
        _6267 = NewDouble(DBL_PTR(_6267)->dbl - (double)2);
    }
    DeRef1(_0);
    Ref(_6267);
    _0 = _6267;
    _6267 = _16token_text(_6267);
    DeRef1(_0);
    _0 = _6267;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_6267);
    *((int *)(_2+4)) = _6267;
    _6267 = MAKE_SEQ(_1);
    DeRef1(_0);
    DeRef1(_first_arg);
    _first_arg = EPrintf(-9999999, _5843, _6267);

    //     			tok1 -= 3
    _tok1 = _tok1 - 3;

    //     			real_instance += 3
    _real_instance = 6;

    //     			member_stack = member_stack[1..$-1]
    DeRef1(_6267);
    _6267 = SEQ_PTR(_7member_stack)->length;
    _6267 = _6267 - 1;
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _6267);
LC:

    //     		first_arg = SymTab[current_instance[$]][S_NAME] & first_arg
    DeRef1(_6267);
    _6267 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6267 = (int)*(((s1_ptr)_2)->base + _6267);
    Ref(_6267);
    _0 = _6267;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_6267))
        _6267 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6267)->dbl));
    else
        _6267 = (int)*(((s1_ptr)_2)->base + _6267);
    Ref(_6267);
    DeRef1(_0);
    _0 = _6267;
    _2 = (int)SEQ_PTR(_6267);
    _6267 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6267);
    DeRef1(_0);
    if (IS_SEQUENCE(_6267) && IS_ATOM(_first_arg)) {
    }
    else if (IS_ATOM(_6267) && IS_SEQUENCE(_first_arg)) {
        Ref(_6267);
        Prepend(&_first_arg, _first_arg, _6267);
    }
    else {
        Concat((object_ptr)&_first_arg, _6267, (s1_ptr)_first_arg);
    }

    //    			for m = 2 to length(member_stack) do
    DeRef1(_6267);
    _6267 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
LD:
        if (_m > _6267)
            goto LE;

        //    				if member_stack[m] > 0 then
        DeRef(_6251);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6251 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6251);
        if (binary_op_a(LESSEQ, _6251, 0))
            goto LF;

        // 	   				class = member_table[MEMBER_CLASS][member_stack[m]]
        DeRef(_6251);
        _2 = (int)SEQ_PTR(_7member_table);
        _6251 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_6251);
        DeRef(_6268);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6268 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6268);
        _2 = (int)SEQ_PTR(_6251);
        if (!IS_ATOM_INT(_6268))
            _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6268)->dbl));
        else
            _class = (int)*(((s1_ptr)_2)->base + _6268);
        if (!IS_ATOM_INT(_class))
            _class = (long)DBL_PTR(_class)->dbl;

        // 	   				first_arg &= sprintf("[%s_MEMBER_%s]", 
        DeRef(_6268);
        _2 = (int)SEQ_PTR(_7class_table);
        _6268 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_6268);
        _0 = _6268;
        _2 = (int)SEQ_PTR(_6268);
        _6268 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_6268);
        DeRefDS(_0);
        DeRef(_6251);
        _2 = (int)SEQ_PTR(_7member_table);
        _6251 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6251);
        DeRef(_6325);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6325 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6325);
        _0 = _6325;
        _2 = (int)SEQ_PTR(_6251);
        if (!IS_ATOM_INT(_6325))
            _6325 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6325)->dbl));
        else
            _6325 = (int)*(((s1_ptr)_2)->base + _6325);
        Ref(_6325);
        DeRef(_0);
        _0 = _6325;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _6268;
        Ref(_6268);
        ((int *)_2)[2] = _6325;
        Ref(_6325);
        _6325 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _6325;
        _6325 = EPrintf(-9999999, _4281, _6325);
        DeRefDS(_0);
        Concat((object_ptr)&_first_arg, _first_arg, (s1_ptr)_6325);
        goto L10;
LF:

        //    					first_arg &= sprintf("[%s]", {token_text( length(line_tokens) - (length(member_stack)-1)*2 - 2 )})
        DeRef(_6325);
        _6325 = SEQ_PTR(_7line_tokens)->length;
        DeRef(_6251);
        _6251 = SEQ_PTR(_7member_stack)->length;
        _6251 = _6251 - 1;
        _6251 = _6251 + _6251;
        if ((long)((unsigned long)_6251 + (unsigned long)HIGH_BITS) >= 0) 
            _6251 = NewDouble((double)_6251);
        _0 = _6251;
        if (IS_ATOM_INT(_6251)) {
            _6251 = _6325 - _6251;
            if ((long)((unsigned long)_6251 +(unsigned long) HIGH_BITS) >= 0)
                _6251 = NewDouble((double)_6251);
        }
        else {
            _6251 = NewDouble((double)_6325 - DBL_PTR(_6251)->dbl);
        }
        DeRef(_0);
        _0 = _6251;
        if (IS_ATOM_INT(_6251)) {
            _6251 = _6251 - 2;
            if ((long)((unsigned long)_6251 +(unsigned long) HIGH_BITS) >= 0)
                _6251 = NewDouble((double)_6251);
        }
        else {
            _6251 = NewDouble(DBL_PTR(_6251)->dbl - (double)2);
        }
        DeRef(_0);
        Ref(_6251);
        _0 = _6251;
        _6251 = _16token_text(_6251);
        DeRef(_0);
        _0 = _6251;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_6251);
        *((int *)(_2+4)) = _6251;
        _6251 = MAKE_SEQ(_1);
        DeRefDS(_0);
        _0 = _6251;
        _6251 = EPrintf(-9999999, _5843, _6251);
        DeRefDS(_0);
        Concat((object_ptr)&_first_arg, _first_arg, (s1_ptr)_6251);
L10:

        //    				real_instance += 2
        _real_instance = _real_instance + 2;

        //    				tok1 -= 2
        _tok1 = _tok1 - 2;

        //    			end for
        _m = _m + 1;
        goto LD;
LE:
        ;
    }
L11:
    goto LB;
L4:

    // 	    sym = current_instance[$]
    DeRef1(_6251);
    _6251 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _sym = (int)*(((s1_ptr)_2)->base + _6251);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	    if not find( sym, class_table[CLASS_SYM] ) then
    _2 = (int)SEQ_PTR(_7class_table);
    _6251 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_6251);
    _0 = _6251;
    _6251 = find(_sym, _6251);
    DeRef1(_0);
    if (_6251 != 0)
        goto L12;

    // 	    	if preprocess then
    if (_7preprocess == 0)
        goto L13;

    // 	    		real_instance = 3
    _real_instance = 3;

    // 	    		first_arg = ""
    RefDS(_39);
    DeRef1(_first_arg);
    _first_arg = _39;

    // 	    		if is_sequenceof( current_instance[$] ) then
    _6251 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6251 = (int)*(((s1_ptr)_2)->base + _6251);
    Ref(_6251);
    Ref(_6251);
    _0 = _6251;
    _6251 = _11is_sequenceof(_6251);
    DeRef1(_0);
    if (_6251 == 0) {
        goto L14;
    }
    else {
        if (!IS_ATOM_INT(_6251) && DBL_PTR(_6251)->dbl == 0.0)
            goto L14;
    }

    // 	    			first_arg = sprintf("[%s]", {token_text( tok1 - 1)})
    DeRef1(_6251);
    _6251 = _tok1 - 1;
    if ((long)((unsigned long)_6251 +(unsigned long) HIGH_BITS) >= 0)
        _6251 = NewDouble((double)_6251);
    Ref(_6251);
    _0 = _6251;
    _6251 = _16token_text(_6251);
    DeRef1(_0);
    _0 = _6251;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_6251);
    *((int *)(_2+4)) = _6251;
    _6251 = MAKE_SEQ(_1);
    DeRef1(_0);
    DeRef1(_first_arg);
    _first_arg = EPrintf(-9999999, _5843, _6251);

    // 	    			tok1 -= 3
    _tok1 = _tok1 - 3;

    // 	    			real_instance += 3
    _real_instance = 6;
L14:

    // 	    		first_arg = SymTab[current_instance[$]][S_NAME] & first_arg
    DeRef1(_6251);
    _6251 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6251 = (int)*(((s1_ptr)_2)->base + _6251);
    Ref(_6251);
    _0 = _6251;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_6251))
        _6251 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6251)->dbl));
    else
        _6251 = (int)*(((s1_ptr)_2)->base + _6251);
    Ref(_6251);
    DeRef1(_0);
    _0 = _6251;
    _2 = (int)SEQ_PTR(_6251);
    _6251 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6251);
    DeRef1(_0);
    if (IS_SEQUENCE(_6251) && IS_ATOM(_first_arg)) {
    }
    else if (IS_ATOM(_6251) && IS_SEQUENCE(_first_arg)) {
        Ref(_6251);
        Prepend(&_first_arg, _first_arg, _6251);
    }
    else {
        Concat((object_ptr)&_first_arg, _6251, (s1_ptr)_first_arg);
    }

    // 	   			for m = 2 to length(member_stack) do
    DeRef1(_6251);
    _6251 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L15:
        if (_m > _6251)
            goto L16;

        // 	   				class = member_table[MEMBER_CLASS][member_stack[m]]
        DeRef(_6325);
        _2 = (int)SEQ_PTR(_7member_table);
        _6325 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_6325);
        DeRef(_6268);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6268 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6268);
        _2 = (int)SEQ_PTR(_6325);
        if (!IS_ATOM_INT(_6268))
            _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6268)->dbl));
        else
            _class = (int)*(((s1_ptr)_2)->base + _6268);
        if (!IS_ATOM_INT(_class))
            _class = (long)DBL_PTR(_class)->dbl;

        // 	   				first_arg &= sprintf("[%s_MEMBER_%s]", 
        DeRef(_6268);
        _2 = (int)SEQ_PTR(_7class_table);
        _6268 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_6268);
        _0 = _6268;
        _2 = (int)SEQ_PTR(_6268);
        _6268 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_6268);
        DeRefDS(_0);
        DeRef(_6325);
        _2 = (int)SEQ_PTR(_7member_table);
        _6325 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6325);
        DeRef(_6267);
        _2 = (int)SEQ_PTR(_7member_stack);
        _6267 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_6267);
        _0 = _6267;
        _2 = (int)SEQ_PTR(_6325);
        if (!IS_ATOM_INT(_6267))
            _6267 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6267)->dbl));
        else
            _6267 = (int)*(((s1_ptr)_2)->base + _6267);
        Ref(_6267);
        DeRef(_0);
        _0 = _6267;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _6268;
        Ref(_6268);
        ((int *)_2)[2] = _6267;
        Ref(_6267);
        _6267 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _6267;
        _6267 = EPrintf(-9999999, _4281, _6267);
        DeRefDS(_0);
        Concat((object_ptr)&_first_arg, _first_arg, (s1_ptr)_6267);

        // 	   				real_instance += 2
        _real_instance = _real_instance + 2;

        // 	   				tok1 -= 2
        _tok1 = _tok1 - 2;

        // 	   			end for
        _m = _m + 1;
        goto L15;
L16:
        ;
    }
L13:

    // 	   		SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6268 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_6268);
    _0 = _6268;
    _2 = (int)SEQ_PTR(_6268);
    _6268 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_6268);
    DeRef1(_0);
    _0 = _6268;
    if (IS_ATOM_INT(_6268)) {
        _6268 = (_6268 | 1);
    }
    else {
        _6268 = binary_op(OR_BITS, _6268, 1);
    }
    DeRef1(_0);
    Ref(_6268);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _6268;
    DeRef(_1);

    // 			InitCheck(sym, TRUE)
    _16InitCheck(_sym, 1);

    // 			emit_opnd(sym)
    _15emit_opnd(_sym);
    goto L17;
L12:

    // 			real_instance = 0
    _real_instance = 0;
L17:
LB:

    //     ix = length( member_stack )
    _ix = SEQ_PTR(_7member_stack)->length;

    //     while ix and member_stack[ix] < 0 do
L18:
    if (_ix == 0) {
        goto L19;
    }
    DeRef(_6325);
    _2 = (int)SEQ_PTR(_7member_stack);
    _6325 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_6325);
    _0 = _6325;
    if (IS_ATOM_INT(_6325)) {
        _6325 = (_6325 < 0);
    }
    else {
        _6325 = binary_op(LESS, _6325, 0);
    }
    DeRef(_0);
L1A:
    if (_6325 <= 0) {
        if (_6325 == 0) {
            goto L19;
        }
        else {
            if (!IS_ATOM_INT(_6325) && DBL_PTR(_6325)->dbl == 0.0)
                goto L19;
        }
    }

    //     	ix -= 1
    _ix = _ix - 1;

    //     end while
    goto L18;
L19:

    //     if ix then
    if (_ix == 0)
        goto L1B;

    //     	last_member = member_stack[ix]
    _2 = (int)SEQ_PTR(_7member_stack);
    _last_member = (int)*(((s1_ptr)_2)->base + _ix);
    if (!IS_ATOM_INT(_last_member))
        _last_member = (long)DBL_PTR(_last_member)->dbl;
L1B:

    // 	member_stack = {0}
    _0 = _7member_stack;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    _7member_stack = MAKE_SEQ(_1);
    DeRef1(_0);

    //     ParseMethodArgs(tok)
    RefDS(_tok);
    _16ParseMethodArgs(_tok);

    //     if last_member then
    if (_last_member == 0)
        goto L1C;

    // 		csym = member_table[MEMBER_VARTYPE][last_member]
    DeRef1(_6325);
    _2 = (int)SEQ_PTR(_7member_table);
    _6325 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6325);
    _2 = (int)SEQ_PTR(_6325);
    _csym = (int)*(((s1_ptr)_2)->base + _last_member);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 		class = find( csym, class_table[CLASS_SYM] )
    DeRef1(_6325);
    _2 = (int)SEQ_PTR(_7class_table);
    _6325 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_6325);
    _class = find(_csym, _6325);

    // 		if not class then
    if (_class != 0)
        goto L1D;

    // 			CompileErr( sprintf("member '%s' does not have methods",{method_table[METHOD_NAME][last_member]}))
    DeRef1(_6325);
    _2 = (int)SEQ_PTR(_7method_table);
    _6325 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_6325);
    _0 = _6325;
    _2 = (int)SEQ_PTR(_6325);
    _6325 = (int)*(((s1_ptr)_2)->base + _last_member);
    Ref(_6325);
    DeRef1(_0);
    _0 = _6325;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6325);
    *((int *)(_2+4)) = _6325;
    _6325 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _6325;
    _6325 = EPrintf(-9999999, _6070, _6325);
    DeRef1(_0);
    RefDS(_6325);
    _9CompileErr(_6325);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L1E;

    // 					release_line()
    _16release_line();
L1E:

    // 			return 
    DeRef1(_tok);
    DeRef1(_temp_tok);
    DeRef1(_ppoff);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef(_6251);
    DeRef(_6325);
    DeRef(_6267);
    DeRef(_6268);
    return 0;
L1F:
    goto L1D;
L1C:

    //     elsif find( sym, class_table[CLASS_SYM] ) then
    DeRef1(_6325);
    _2 = (int)SEQ_PTR(_7class_table);
    _6325 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_6325);
    _0 = _6325;
    _6325 = find(_sym, _6325);
    DeRef1(_0);
    if (_6325 == 0)
        goto L20;

    //     	if not length(method_args[$]) then
    _6325 = SEQ_PTR(_7method_args)->length;
    _2 = (int)SEQ_PTR(_7method_args);
    _6325 = (int)*(((s1_ptr)_2)->base + _6325);
    Ref(_6325);
    _0 = _6325;
    _6325 = SEQ_PTR(_6325)->length;
    DeRef1(_0);
    if (_6325 != 0)
        goto L21;

    //     		CompileErr( "method procedure requires a 'this' parameter" )
    RefDS(_6402);
    _9CompileErr(_6402);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L22;

    // 					release_line()
    _16release_line();
L22:

    //     		return
    DeRef1(_tok);
    DeRef1(_temp_tok);
    DeRef1(_ppoff);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef(_6251);
    DeRef(_6325);
    DeRef(_6267);
    DeRef(_6268);
    return 0;
L21:

    //     	method_args[$] = method_args[$][2..$]
    DeRef1(_6325);
    _6325 = SEQ_PTR(_7method_args)->length;
    DeRef1(_6268);
    _6268 = SEQ_PTR(_7method_args)->length;
    _2 = (int)SEQ_PTR(_7method_args);
    _6268 = (int)*(((s1_ptr)_2)->base + _6268);
    Ref(_6268);
    DeRef1(_6267);
    _6267 = SEQ_PTR(_6268)->length;
    rhs_slice_target = (object_ptr)&_6267;
    RHS_Slice((s1_ptr)_6268, 2, _6267);
    RefDS(_6267);
    _2 = (int)SEQ_PTR(_7method_args);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_args = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _6325);
    _1 = *(int *)_2;
    *(int *)_2 = _6267;
    DeRef(_1);

    //     	class = find( current_instance[$], class_table[CLASS_SYM] )
    DeRef1(_6267);
    _6267 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6267 = (int)*(((s1_ptr)_2)->base + _6267);
    Ref(_6267);
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7class_table);
    _6268 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_6268);
    _class = find(_6267, _6268);
    goto L1D;
L20:

    // 	    csym = SymTab[current_instance[$]][S_VTYPE]
    DeRef1(_6268);
    _6268 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6268 = (int)*(((s1_ptr)_2)->base + _6268);
    Ref(_6268);
    _0 = _6268;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_6268))
        _6268 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6268)->dbl));
    else
        _6268 = (int)*(((s1_ptr)_2)->base + _6268);
    Ref(_6268);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_6268);
    _csym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 	    class = find( csym, class_table[CLASS_SYM] )    	    	
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7class_table);
    _6268 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_6268);
    _class = find(_csym, _6268);
L1D:

    //     s = PolyMorph( class )
    _s = _16PolyMorph(_class);
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     if preprocess then
    if (_7preprocess == 0)
        goto L23;

    //     	pdec = pp_decorate( SymTab[s][S_NAME]) & "( "
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6268 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_6268);
    _0 = _6268;
    _2 = (int)SEQ_PTR(_6268);
    _6268 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6268);
    DeRef1(_0);
    Ref(_6268);
    _0 = _6268;
    _6268 = _16pp_decorate(_6268);
    DeRef1(_0);
    Concat((object_ptr)&_pdec, _6268, (s1_ptr)_5336);

    //     	if real_instance then
    if (_real_instance == 0)
        goto L24;

    //     		pdec &= first_arg -- SymTab[line_tokens[tok1][T_SYM]][S_NAME]
    Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_first_arg);

    //     		if SymTab[s][S_NUM_ARGS] > 1 then
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6268 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_6268);
    _0 = _6268;
    _2 = (int)SEQ_PTR(_6268);
    _6268 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6268);
    DeRef1(_0);
    if (binary_op_a(LESSEQ, _6268, 1))
        goto L25;

    //     			pdec &= ", "
    Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5341);
L25:

    //     		replace_tokens( tok1, tok1 + real_instance, pdec )
    DeRef1(_6268);
    _6268 = _tok1 + _real_instance;
    if ((long)((unsigned long)_6268 + (unsigned long)HIGH_BITS) >= 0) 
        _6268 = NewDouble((double)_6268);
    Ref(_6268);
    RefDS(_pdec);
    _16replace_tokens(_tok1, _6268, _pdec);
    goto L26;
L24:

    //     		replace_tokens( tok1, tok1 + 3, pdec )
    DeRef1(_6268);
    _6268 = _tok1 + 3;
    if ((long)((unsigned long)_6268 + (unsigned long)HIGH_BITS) >= 0) 
        _6268 = NewDouble((double)_6268);
    Ref(_6268);
    RefDS(_pdec);
    _16replace_tokens(_tok1, _6268, _pdec);
L26:

    //     	release_line()
    _16release_line();
L23:

    //     add_ref( {r:PROC, s} )
    DeRef1(_6268);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 27;
    ((int *)_2)[2] = _s;
    _6268 = MAKE_SEQ(_1);
    RefDS(_6268);
    _11add_ref(_6268);

    // 	method_name = method_name[1..$-1]
    DeRef1(_6268);
    _6268 = SEQ_PTR(_7method_name)->length;
    _6268 = _6268 - 1;
    rhs_slice_target = (object_ptr)&_7method_name;
    RHS_Slice((s1_ptr)_7method_name, 1, _6268);

    //     scope = SymTab[s][S_SCOPE]
    _2 = (int)SEQ_PTR(_7SymTab);
    _6268 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_6268);
    _2 = (int)SEQ_PTR(_6268);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    //     opcode = SymTab[s][S_OPCODE]
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6268 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_6268);
    _2 = (int)SEQ_PTR(_6268);
    _opcode = (int)*(((s1_ptr)_2)->base + 19);
    if (!IS_ATOM_INT(_opcode))
        _opcode = (long)DBL_PTR(_opcode)->dbl;

    //     if SymTab[s][S_EFFECT] then
    DeRef1(_6268);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6268 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_6268);
    _0 = _6268;
    _2 = (int)SEQ_PTR(_6268);
    _6268 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_6268);
    DeRef1(_0);
    if (_6268 == 0) {
        goto L27;
    }
    else {
        if (!IS_ATOM_INT(_6268) && DBL_PTR(_6268)->dbl == 0.0)
            goto L27;
    }

    // 		SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    DeRef1(_6325);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6325 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_6325);
    _0 = _6325;
    _2 = (int)SEQ_PTR(_6325);
    _6325 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_6325);
    DeRef1(_0);
    DeRef1(_6251);
    _2 = (int)SEQ_PTR(_7SymTab);
    _6251 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_6251);
    _0 = _6251;
    _2 = (int)SEQ_PTR(_6251);
    _6251 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_6251);
    DeRef1(_0);
    _0 = _6251;
    if (IS_ATOM_INT(_6325) && IS_ATOM_INT(_6251)) {
        _6251 = (_6325 | _6251);
    }
    else {
        _6251 = binary_op(OR_BITS, _6325, _6251);
    }
    DeRef1(_0);
    Ref(_6251);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _6251;
    DeRef(_1);
L27:

    //     if scope = SC_PREDEF then
    if (_scope != 7)
        goto L28;

    // 		emit_op(opcode)
    _15emit_op(_opcode);

    // 		if opcode = ABORT then
    if (_opcode != 126)
        goto L29;

    // 		    temp_tok = next_token()
    _0 = _temp_tok;
    _temp_tok = _16next_token();
    DeRef1(_0);

    // 		    putback(temp_tok)
    RefDS(_temp_tok);
    _16putback(_temp_tok);

    // 		    NotReached(temp_tok[T_ID], "abort()")
    DeRef1(_6251);
    _2 = (int)SEQ_PTR(_temp_tok);
    _6251 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6251);
    Ref(_6251);
    RefDS(_4979);
    _16NotReached(_6251, _4979);
L2A:
    goto L29;
L28:

    // 	op_info1 = s
    _15op_info1 = _s;

    // 	emit_op(r:PROC)
    _15emit_op(27);

    // 	if not TRANSLATE then

    // 	    if OpTrace then
    if (_7OpTrace == 0)
        goto L2B;

    // 		emit_op(UPDATE_GLOBALS)
    _15emit_op(89);
L2B:
L2C:
L29:

    //     method_args = method_args[1..$-1]
    DeRef1(_6251);
    _6251 = SEQ_PTR(_7method_args)->length;
    _6251 = _6251 - 1;
    rhs_slice_target = (object_ptr)&_7method_args;
    RHS_Slice((s1_ptr)_7method_args, 1, _6251);

    //     method_stack = method_stack[1..$-1]
    _6251 = SEQ_PTR(_7method_stack)->length;
    _6251 = _6251 - 1;
    rhs_slice_target = (object_ptr)&_7method_stack;
    RHS_Slice((s1_ptr)_7method_stack, 1, _6251);

    //     current_method -= 1
    _7current_method = _7current_method - 1;

    //     parse_method_stack = parse_method_stack[1..$-1]
    _6251 = SEQ_PTR(_7parse_method_stack)->length;
    _6251 = _6251 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _6251);

    // end procedure
    DeRef1(_tok);
    DeRef1(_temp_tok);
    DeRef1(_ppoff);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef(_6325);
    DeRef(_6267);
    DeRef(_6268);
    return 0;
    ;
}


int _16parser()
{
    int _tok = 0;
    int _tok2 = 0;
    int _id;
    int _6470 = 0;
    int _6565 = 0;
    int _6561 = 0;
    int _6464 = 0;
    int _0, _1, _2, _3;
    

    //     tok = next_token()
    _tok = _16next_token();

    //     while TRUE do  -- infinite loop until scanner aborts
L1:

    // 	start_index = length(Code)+1
    DeRef(_6464);
    _6464 = SEQ_PTR(_7Code)->length;
    _16start_index = _6464 + 1;

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	if id = VARIABLE or id = QUALIFIED_VARIABLE then
    _6464 = (_id == -100);
    if (_6464 != 0) {
        goto L2;
    }
    DeRef(_6470);
    _6470 = (_id == 515);
L3:
    if (_6470 == 0)
        goto L4;
L2:

    // 		if length(current_instance) and current_instance[$] then
    DeRef(_6470);
    _6470 = SEQ_PTR(_7current_instance)->length;
    if (_6470 == 0) {
        goto L5;
    }
    DeRef(_6464);
    _6464 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6464 = (int)*(((s1_ptr)_2)->base + _6464);
    Ref(_6464);
L6:
    if (_6464 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_6464) && DBL_PTR(_6464)->dbl == 0.0)
            goto L5;
    }

    // 			StartSourceLine(FALSE)
    _15StartSourceLine(0);

    // 			Method(tok)
    RefDS(_tok);
    _16Method(_tok);

    // 			current_instance = current_instance[1..$-1]
    DeRef(_6464);
    _6464 = SEQ_PTR(_7current_instance)->length;
    _6464 = _6464 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _6464);

    // 			ExecCommand()
    _16ExecCommand();
    goto L7;
L5:

    // 		    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 		    Assignment(tok)
    RefDS(_tok);
    _16Assignment(_tok);

    // 		    ExecCommand()
    _16ExecCommand();
L8:
    goto L7;
L4:

    // 	elsif find(id, {PROCEDURE, FUNCTION, TYPE_DECL, CLASS}) then
    _0 = _6464;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 405;
    *((int *)(_2+8)) = 406;
    *((int *)(_2+12)) = 415;
    *((int *)(_2+16)) = 421;
    _6464 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _6464;
    _6464 = find(_id, _6464);
    DeRefDSi(_0);
    if (_6464 == 0)
        goto L9;

    // 		if current_instance[$] then
    _6464 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6464 = (int)*(((s1_ptr)_2)->base + _6464);
    Ref(_6464);
    if (_6464 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_6464) && DBL_PTR(_6464)->dbl == 0.0)
            goto LA;
    }

    // 			StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 			Method( tok )
    RefDS(_tok);
    _16Method(_tok);

    // 			current_instance = current_instance[1..$-1]
    DeRef(_6464);
    _6464 = SEQ_PTR(_7current_instance)->length;
    _6464 = _6464 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _6464);
    goto L7;
LA:

    // 			SubProg(id, 0)
    _16SubProg(_id, 0);
LB:
    goto L7;
L9:

    // 	elsif id = GLOBAL then
    if (_id != 411)
        goto LC;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 	    id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	    if id = TYPE then
    if (_id != 504)
        goto LD;

    // 	    	if current_class then
    if (_7current_class == 0)
        goto LE;

    // 	    		Member_declaration( tok[T_SYM] )
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_tok);
    _6464 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6464);
    Ref(_6464);
    _16Member_declaration(_6464);
    goto L7;
LE:

    // 	    		Global_declaration(tok[T_SYM], 1)
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_tok);
    _6464 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6464);
    Ref(_6464);
    _16Global_declaration(_6464, 1);
LF:
    goto L7;
LD:

    // 	    elsif id = CONSTANT then
    if (_id != 416)
        goto L10;

    // 			Global_declaration(0, 1)
    _16Global_declaration(0, 1);

    // 			ExecCommand()
    _16ExecCommand();
    goto L7;
L10:

    // 	    elsif find(id, {PROCEDURE, FUNCTION, TYPE_DECL, CLASS}) then
    _0 = _6464;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 405;
    *((int *)(_2+8)) = 406;
    *((int *)(_2+12)) = 415;
    *((int *)(_2+16)) = 421;
    _6464 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _6464;
    _6464 = find(_id, _6464);
    DeRefDSi(_0);
    if (_6464 == 0)
        goto L11;

    // 			SubProg(id, 1)
    _16SubProg(_id, 1);
    goto L7;
L11:

    // 			if id = VARIABLE or id = QUALIFIED_VARIABLE then
    DeRef(_6464);
    _6464 = (_id == -100);
    if (_6464 != 0) {
        goto L12;
    }
    DeRef(_6470);
    _6470 = (_id == 515);
L13:
    if (_6470 == 0)
        goto L14;
L12:

    // 			    if UndefinedVar(tok[T_SYM]) then
    DeRef(_6470);
    _2 = (int)SEQ_PTR(_tok);
    _6470 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6470);
    Ref(_6470);
    _0 = _6470;
    _6470 = _16UndefinedVar(_6470);
    DeRef(_0);
    if (_6470 == 0)
        goto L15;

    // 			    	return
    DeRefDS(_tok);
    DeRef(_tok2);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
L15:
L14:

    // 			CompileErr(
    RefDS(_6499);
    _9CompileErr(_6499);

    // 			return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
L16:
    goto L7;
LC:

    // 	elsif id = TYPE or id = QUALIFIED_TYPE then
    DeRef(_6470);
    _6470 = (_id == 504);
    if (_6470 != 0) {
        goto L17;
    }
    DeRef(_6464);
    _6464 = (_id == 526);
L18:
    if (_6464 == 0)
        goto L19;
L17:

    // 		tok2 = next_token()
    _0 = _tok2;
    _tok2 = _16next_token();
    DeRef(_0);

    // 		if tok2[T_ID] = DOT_NOTATION then
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_tok2);
    _6464 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6464);
    if (binary_op_a(NOTEQ, _6464, 423))
        goto L1A;

    // 			StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 			current_instance &= {tok[T_SYM]}
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_tok);
    _6464 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6464);
    _0 = _6464;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6464);
    *((int *)(_2+4)) = _6464;
    _6464 = MAKE_SEQ(_1);
    DeRef(_0);
    Concat((object_ptr)&_7current_instance, _7current_instance, (s1_ptr)_6464);
    goto L7;
L1A:

    // 			putback(tok2)
    RefDS(_tok2);
    _16putback(_tok2);

    // 			if current_class then
    if (_7current_class == 0)
        goto L1B;

    // 				Member_declaration( tok[T_SYM] )
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_tok);
    _6464 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6464);
    Ref(_6464);
    _16Member_declaration(_6464);
    goto L7;
L1B:

    // 				Global_declaration(tok[T_SYM], 0)
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_tok);
    _6464 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6464);
    Ref(_6464);
    _16Global_declaration(_6464, 0);
L1C:
L1D:
    goto L7;
L19:

    // 	elsif id = CONSTANT then
    if (_id != 416)
        goto L1E;

    // 	    Global_declaration(0, 0)
    _16Global_declaration(0, 0);

    // 	    ExecCommand()
    _16ExecCommand();
    goto L7;
L1E:

    // 	elsif id = IF then
    if (_id != 20)
        goto L1F;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    If_statement()
    _16If_statement();

    // 	    ExecCommand()
    _16ExecCommand();
    goto L7;
L1F:

    // 	elsif id = FOR then
    if (_id != 21)
        goto L20;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    For_statement()
    _16For_statement();

    // 	    ExecCommand()
    _16ExecCommand();
    goto L7;
L20:

    // 	elsif id = WHILE then
    if (_id != 47)
        goto L21;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    While_statement()
    _16While_statement();

    // 	    ExecCommand()
    _16ExecCommand();
    goto L7;
L21:

    // 	elsif id = r:PROC or id = QUALIFIED_PROC then
    DeRef(_6464);
    _6464 = (_id == 27);
    if (_6464 != 0) {
        goto L22;
    }
    DeRef(_6470);
    _6470 = (_id == 525);
L23:
    if (_6470 == 0)
        goto L24;
L22:

    // 		if length(current_instance) and current_instance[$] then
    DeRef(_6470);
    _6470 = SEQ_PTR(_7current_instance)->length;
    if (_6470 == 0) {
        goto L25;
    }
    DeRef(_6464);
    _6464 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _6464 = (int)*(((s1_ptr)_2)->base + _6464);
    Ref(_6464);
L26:
    if (_6464 == 0) {
        goto L25;
    }
    else {
        if (!IS_ATOM_INT(_6464) && DBL_PTR(_6464)->dbl == 0.0)
            goto L25;
    }

    // 			StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 			Method(tok)
    RefDS(_tok);
    _16Method(_tok);

    // 			ExecCommand()
    _16ExecCommand();

    // 			current_instance = current_instance[1..$-1]
    DeRef(_6464);
    _6464 = SEQ_PTR(_7current_instance)->length;
    _6464 = _6464 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _6464);
    goto L7;
L25:

    // 		    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 		    Procedure_call(tok)
    RefDS(_tok);
    _16Procedure_call(_tok);

    // 		    ExecCommand()
    _16ExecCommand();
L27:
    goto L7;
L24:

    // 	elsif id = r:FUNC or id = QUALIFIED_FUNC then
    DeRef(_6464);
    _6464 = (_id == 501);
    if (_6464 != 0) {
        goto L28;
    }
    DeRef(_6470);
    _6470 = (_id == 524);
L29:
    if (_6470 == 0)
        goto L2A;
L28:

    // 	    CompileErr("function result must be assigned or used")
    RefDS(_6528);
    _9CompileErr(_6528);

    // 	    return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
    goto L7;
L2A:

    // 	elsif id = RETURN then
    if (_id != 412)
        goto L2B;

    // 	    Return_statement() -- will fail - not allowed at top level
    _16Return_statement();
    goto L7;
L2B:

    // 	elsif id = EXIT then
    if (_id != 61)
        goto L2C;

    // 	    CompileErr("exit must be inside a loop")                 
    RefDS(_6531);
    _9CompileErr(_6531);

    // 	    return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
    goto L7;
L2C:

    // 	elsif id = INCLUDE then
    if (_id != 417)
        goto L2D;

    // 	    IncludeScan()
    _12IncludeScan();
    goto L7;
L2D:

    // 	elsif id = WITH then
    if (_id != 419)
        goto L2E;

    // 	    SetWith(TRUE)
    _16SetWith(1);
    goto L7;
L2E:

    // 	elsif id = WITHOUT then
    if (_id != 420)
        goto L2F;

    // 	    SetWith(FALSE)
    _16SetWith(0);
    goto L7;
L2F:

    // 	elsif id = END_OF_FILE then
    if (_id != -21)
        goto L30;

    // 	    if IncludePop() then
    _0 = _6470;
    _6470 = _12IncludePop();
    DeRef(_0);
    if (_6470 == 0)
        goto L31;

    // 		read_line()
    _12read_line();
    goto L7;
L32:

    // 		exit -- all finished
    goto L31;
L33:
    goto L7;
L30:

    // 	elsif id = QUESTION_MARK then
    if (_id != -31)
        goto L34;

    // 	    StartSourceLine(TRUE)
    _15StartSourceLine(1);

    // 	    Print_statement()
    _16Print_statement();

    // 	    ExecCommand()
    _16ExecCommand();
    goto L7;
L34:

    // 	elsif id = ILLEGAL_CHAR then
    if (_id != -20)
        goto L35;

    // 	    CompileErr("illegal character")
    RefDS(_6539);
    _9CompileErr(_6539);

    // 	    return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
    goto L7;
L35:

    // 	elsif id = END then
    if (_id != 402)
        goto L36;

    // 		if current_class then
    if (_7current_class == 0)
        goto L37;

    // 			tok_match(CLASS)
    _16tok_match(421);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L38;

    // 				cache_line()
    _16cache_line();

    // 				replace_tokens( length(line_tokens)-1, length(line_tokens)-1, "--end")
    DeRef(_6470);
    _6470 = SEQ_PTR(_7line_tokens)->length;
    _6470 = _6470 - 1;
    DeRef(_6464);
    _6464 = SEQ_PTR(_7line_tokens)->length;
    _6464 = _6464 - 1;
    RefDS(_6545);
    _16replace_tokens(_6470, _6464, _6545);

    // 				release_line()
    _16release_line();
L38:

    // 			current_class = 0
    _7current_class = 0;
    goto L7;
L37:

    // 			CompileErr("syntax error")
    RefDS(_6546);
    _9CompileErr(_6546);

    // 			return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
L39:
    goto L7;
L36:

    // 	elsif id = CONTINUE then
    if (_id != 425)
        goto L3A;

    // 		Continue_statement()
    _16Continue_statement();
    goto L7;
L3A:

    // 	elsif id = GOTO then
    if (_id != 175)
        goto L3B;

    // 		Goto_Statement()
    _16Goto_Statement();
    goto L7;
L3B:

    // 	elsif id = COLON then
    if (_id != -23)
        goto L3C;

    // 		Goto_Label()
    _16Goto_Label();
    goto L7;
L3C:

    // 	    CompileErr("unknown command")
    RefDS(_6550);
    _9CompileErr(_6550);

    // 	    return
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
L7:

    // 	if length(eval_error[$]) then
    DeRef(_6464);
    _6464 = SEQ_PTR(_7eval_error)->length;
    _2 = (int)SEQ_PTR(_7eval_error);
    _6464 = (int)*(((s1_ptr)_2)->base + _6464);
    RefDS(_6464);
    _0 = _6464;
    _6464 = SEQ_PTR(_6464)->length;
    DeRefDS(_0);
    if (_6464 == 0)
        goto L3D;

    // 		exit
    goto L31;
L3D:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    //     end while 
    goto L1;
L31:

    //     for i = 1 to length(SymTab) do
    DeRef(_6464);
    _6464 = SEQ_PTR(_7SymTab)->length;
    { int _i;
        _i = 1;
L3E:
        if (_i > _6464)
            goto L3F;

        //     	if length(SymTab[i]) >= 14 then
        DeRef(_6470);
        _2 = (int)SEQ_PTR(_7SymTab);
        _6470 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6470);
        _0 = _6470;
        _6470 = SEQ_PTR(_6470)->length;
        DeRef(_0);
        if (_6470 < 14)
            goto L40;

        // 	    	id = find( SymTab[i][S_VTYPE], class_table[CLASS_SYM])
        _2 = (int)SEQ_PTR(_7SymTab);
        _6470 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6470);
        _0 = _6470;
        _2 = (int)SEQ_PTR(_6470);
        _6470 = (int)*(((s1_ptr)_2)->base + 14);
        Ref(_6470);
        DeRef(_0);
        DeRef(_6561);
        _2 = (int)SEQ_PTR(_7class_table);
        _6561 = (int)*(((s1_ptr)_2)->base + 6);
        RefDS(_6561);
        _id = find(_6470, _6561);

        // 			while id do
L41:
        if (_id == 0)
            goto L42;

        // 				SymTab[i][S_VTYPE] = class_table[CLASS_VARTYPE][id]
        _2 = (int)SEQ_PTR(_7SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_6565);
        _2 = (int)SEQ_PTR(_7class_table);
        _6565 = (int)*(((s1_ptr)_2)->base + 5);
        RefDS(_6565);
        _0 = _6565;
        _2 = (int)SEQ_PTR(_6565);
        _6565 = (int)*(((s1_ptr)_2)->base + _id);
        Ref(_6565);
        DeRefDS(_0);
        Ref(_6565);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 14);
        _1 = *(int *)_2;
        *(int *)_2 = _6565;
        DeRef(_1);

        // 				id = find( SymTab[i][S_VTYPE], class_table[CLASS_SYM])
        DeRef(_6565);
        _2 = (int)SEQ_PTR(_7SymTab);
        _6565 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6565);
        _0 = _6565;
        _2 = (int)SEQ_PTR(_6565);
        _6565 = (int)*(((s1_ptr)_2)->base + 14);
        Ref(_6565);
        DeRef(_0);
        DeRef(_6470);
        _2 = (int)SEQ_PTR(_7class_table);
        _6470 = (int)*(((s1_ptr)_2)->base + 6);
        RefDS(_6470);
        _id = find(_6565, _6470);

        // 			end while    		
        goto L41;
L42:
L40:

        //     end for
        _i = _i + 1;
        goto L3E;
L3F:
        ;
    }

    //     PatchGotos()
    _16PatchGotos();

    //     emit_op(RETURNT)
    _15emit_op(34);

    //     StraightenBranches()
    _16StraightenBranches();

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

    //     EndLineTable()
    _16EndLineTable();

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

    // end procedure
    DeRef(_tok);
    DeRef(_tok2);
    DeRef(_6470);
    DeRef(_6565);
    DeRef(_6561);
    DeRef(_6464);
    return 0;
    ;
}


