// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16MethodFunc(int _tok)
{
    int _scope;
    int _opcode;
    int _class;
    int _e;
    int _real_instance;
    int _tok1;
    int _member;
    int _tok2;
    int _last_member;
    int _len_member_stack;
    int _first_member;
    int _ppoff;
    int _orig_member_stack;
    int _s;
    int _sym;
    int _csym;
    int _pdec = 0;
    int _first_arg = 0;
    int _member_subs = 0;
    int _pargs = 0;
    int _pop = 0;
    int _save_factors;
    int _save_lhs_subs_level;
    int _5761 = 0;
    int _5815 = 0;
    int _5837 = 0;
    int _5774 = 0;
    int _0, _1, _2, _3;
    

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 		cache_line()
    _16cache_line();
L1:

    // 	parse_method_stack &= 1
    Append(&_7parse_method_stack, _7parse_method_stack, 1);

    // 	if tok[T_ID] = DOT_NOTATION then
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_tok);
    _5761 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5761);
    if (binary_op_a(NOTEQ, _5761, 423))
        goto L2;

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);
L2:

    // 	last_member = 0
    _last_member = 0;

    // 	len_member_stack = length(member_stack)
    _len_member_stack = SEQ_PTR(_7member_stack)->length;

    // 	orig_member_stack = len_member_stack
    _orig_member_stack = _len_member_stack;

    // 	tok1 = length(line_tokens) - 2
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7line_tokens)->length;
    _tok1 = _5761 - 2;

    // 	member = is_member( tok )
    RefDS(_tok);
    _member = _11is_member(_tok);

    // 	if member then
    if (_member == 0)
        goto L3;

    // 		tok[T_SYM] = member_table[MEMBER_SYM][member]
    _2 = (int)SEQ_PTR(_7member_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + _member);
    Ref(_5761);
    DeRef1(_0);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5761;
    DeRef(_1);

    // 		member_stack &= member
    Append(&_7member_stack, _7member_stack, _member);

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 		while find(tok[T_ID], {DOT_NOTATION, LEFT_SQUARE}) do
L4:
    DeRef(_5761);
    _2 = (int)SEQ_PTR(_tok);
    _5761 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5761);
    DeRef(_5774);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 423;
    ((int *)_2)[2] = -28;
    _5774 = MAKE_SEQ(_1);
    _0 = _5774;
    _5774 = find(_5761, _5774);
    DeRefDSi(_0);
    if (_5774 == 0)
        goto L5;

    // 			if tok[T_ID] = DOT_NOTATION then
    _2 = (int)SEQ_PTR(_tok);
    _5774 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5774);
    if (binary_op_a(NOTEQ, _5774, 423))
        goto L6;

    // 				while tok[T_ID] = DOT_NOTATION do
L7:
    DeRef(_5774);
    _2 = (int)SEQ_PTR(_tok);
    _5774 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5774);
    if (binary_op_a(NOTEQ, _5774, 423))
        goto L4;

    // 					tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 					last_member = member
    _last_member = _member;

    // 					member = is_member( tok )
    RefDS(_tok);
    _member = _11is_member(_tok);

    // 					member_stack &= member
    Append(&_7member_stack, _7member_stack, _member);

    // 					if member then
    if (_member == 0)
        goto L4;

    // 						tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 						if member_is_sequenceof( member ) then
    _0 = _5774;
    _5774 = _11member_is_sequenceof(_member);
    DeRef(_0);
    if (_5774 == 0)
        goto L7;

    // 							if tok[T_ID] = LEFT_SQUARE then
    _2 = (int)SEQ_PTR(_tok);
    _5774 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5774);
    if (binary_op_a(NOTEQ, _5774, -28))
        goto L7;

    // 								tok = MethodSlice( tok )
    RefDS(_tok);
    _0 = _tok;
    _tok = _16MethodSlice(_tok);
    DeRefDS(_0);
L8:
L9:
    goto L7;
LA:

    // 						exit
    goto L4;
LB:

    // 				end while
    goto L7;
LC:
    goto L4;
L6:

    // 				tok = MethodSlice( tok )
    RefDS(_tok);
    _0 = _tok;
    _tok = _16MethodSlice(_tok);
    DeRefDS(_0);
LD:

    // 		end while
    goto L4;
L5:

    // 		if member_stack[$] then
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    if (_5774 == 0) {
        goto LE;
    }
    else {
        if (!IS_ATOM_INT(_5774) && DBL_PTR(_5774)->dbl == 0.0)
            goto LE;
    }

    // 		    sym = current_instance[$]
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _sym = (int)*(((s1_ptr)_2)->base + _5774);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 		    first_member = length(member_stack)
    _first_member = SEQ_PTR(_7member_stack)->length;

    // 		    while first_member and member_stack[first_member] do
LF:
    if (_first_member == 0) {
        goto L10;
    }
    DeRef(_5761);
    _2 = (int)SEQ_PTR(_7member_stack);
    _5761 = (int)*(((s1_ptr)_2)->base + _first_member);
    Ref(_5761);
L11:
    if (_5761 <= 0) {
        if (_5761 == 0) {
            goto L10;
        }
        else {
            if (!IS_ATOM_INT(_5761) && DBL_PTR(_5761)->dbl == 0.0)
                goto L10;
        }
    }

    // 		    	first_member -= 1
    _first_member = _first_member - 1;

    // 		    end while
    goto LF;
L10:

    // 		    first_member += ( member_stack[first_member] = 0 )
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7member_stack);
    _5761 = (int)*(((s1_ptr)_2)->base + _first_member);
    Ref(_5761);
    _0 = _5761;
    if (IS_ATOM_INT(_5761)) {
        _5761 = (_5761 == 0);
    }
    else {
        _5761 = binary_op(EQUALS, _5761, 0);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_5761)) {
        _first_member = _first_member + _5761;
    }
    else {
        _first_member = binary_op(PLUS, _first_member, _5761);
    }
    if (!IS_ATOM_INT(_first_member)) {
        _1 = (long)(DBL_PTR(_first_member)->dbl);
        DeRefDS(_first_member);
        _first_member = _1;
    }

    // 		    if not find( sym, class_table[CLASS_SYM] ) then
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5761);
    _0 = _5761;
    _5761 = find(_sym, _5761);
    DeRef1(_0);
    if (_5761 != 0)
        goto L12;

    // 				if not is_sequenceof( current_instance[$] ) then
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    Ref(_5761);
    _0 = _5761;
    _5761 = _11is_sequenceof(_5761);
    DeRef1(_0);
    if (IS_ATOM_INT(_5761)) {
        if (_5761 != 0)
            goto L13;
    }
    else {
        if (DBL_PTR(_5761)->dbl != 0.0)
            goto L13;
    }

    // 					emit_opnd( current_instance[$] )
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    Ref(_5761);
    _15emit_opnd(_5761);
L13:

    // 				for m = first_member to length(member_stack) do
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = _first_member;
L14:
        if (_m > _5761)
            goto L15;

        // 				    if lhs_subs_level >= 0 then
        if (_16lhs_subs_level < 0)
            goto L16;

        // 						lhs_subs_level += 1
        _16lhs_subs_level = _16lhs_subs_level + 1;
L16:

        // 				    if member_stack[m] > 0 then
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5774 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5774);
        if (binary_op_a(LESSEQ, _5774, 0))
            goto L17;

        // 				    	emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_table);
        _5774 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_5774);
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        _2 = (int)SEQ_PTR(_5774);
        if (!IS_ATOM_INT(_5815))
            _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
        else
            _5815 = (int)*(((s1_ptr)_2)->base + _5815);
        Ref(_5815);
        DeRef(_0);
        Ref(_5815);
        _15emit_opnd(_5815);

        // 				    	emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L18;
L17:

        // 				    elsif integer( member_stack[m] ) then
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        if (IS_ATOM_INT(_5815))
            _5815 = 1;
        else if (IS_ATOM_DBL(_5815))
            _5815 = IS_ATOM_INT(DoubleToInt(_5815));
        else
            _5815 = 0;
        DeRef(_0);
        if (_5815 == 0)
            goto L19;

        // 				    	emit_opnd( - member_stack[m] )				
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        if (IS_ATOM_INT(_5815)) {
            if (_5815 == 0xC0000000)
                _5815 = (int)NewDouble((double)-0xC0000000);
            else
                _5815 = - _5815;
        }
        else {
            _5815 = unary_op(UMINUS, _5815);
        }
        DeRef(_0);
        Ref(_5815);
        _15emit_opnd(_5815);

        // 						emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L18;
L19:

        // 				    	emit_op( DOLLAR )
        _15emit_op(-22);

        // 				    	emit_op( RHS_SUBS )
        _15emit_op(25);
L18:

        // 				end for
        _m = _m + 1;
        goto L14;
L15:
        ;
    }

    // 		    	if preprocess then
    if (_7preprocess == 0)
        goto L1A;

    // 		    		if line_tokens[tok1][T_ID] = RIGHT_SQUARE then
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5815 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5815);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _5815, -29))
        goto L1B;

    // 		    			pdec = ""
    RefDS(_39);
    DeRef1(_pdec);
    _pdec = _39;
    goto L1C;
L1B:

    // 		    			pdec = SymTab[current_instance[$]][S_NAME]
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5815))
        _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    DeRef1(_0);
    DeRef1(_pdec);
    _2 = (int)SEQ_PTR(_5815);
    _pdec = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_pdec);
L1C:

    // 		    		tok2 = tok1
    _tok2 = _tok1;

    // 		    		for m = first_member to length(member_stack) do
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = _first_member;
L1D:
        if (_m > _5815)
            goto L1E;

        // 		    			if member_stack[m] > 0 then
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5774 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5774);
        if (binary_op_a(LESSEQ, _5774, 0))
            goto L1F;

        // 			    			class = member_table[MEMBER_CLASS][member_stack[m]]
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_table);
        _5774 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5774);
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5761 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5761);
        _2 = (int)SEQ_PTR(_5774);
        if (!IS_ATOM_INT(_5761))
            _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
        else
            _class = (int)*(((s1_ptr)_2)->base + _5761);
        if (!IS_ATOM_INT(_class))
            _class = (long)DBL_PTR(_class)->dbl;

        // 			    			pdec &= sprintf( "[%s_MEMBER_%s]", 
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7class_table);
        _5761 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_5761);
        _0 = _5761;
        _2 = (int)SEQ_PTR(_5761);
        _5761 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_5761);
        DeRefDS(_0);
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_table);
        _5774 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5774);
        DeRef(_5837);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5837 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5837);
        _0 = _5837;
        _2 = (int)SEQ_PTR(_5774);
        if (!IS_ATOM_INT(_5837))
            _5837 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5837)->dbl));
        else
            _5837 = (int)*(((s1_ptr)_2)->base + _5837);
        Ref(_5837);
        DeRef(_0);
        _0 = _5837;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _5761;
        Ref(_5761);
        ((int *)_2)[2] = _5837;
        Ref(_5837);
        _5837 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _5837;
        _5837 = EPrintf(-9999999, _4281, _5837);
        DeRefDS(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5837);

        // 			    			tok2 += 2
        _tok2 = _tok2 + 2;
        goto L20;
L1F:

        // 			    			pdec &= sprintf("[%s]", {token_text( tok2 + 2 )})
        DeRef(_5837);
        _5837 = _tok2 + 2;
        if ((long)((unsigned long)_5837 + (unsigned long)HIGH_BITS) >= 0) 
            _5837 = NewDouble((double)_5837);
        Ref(_5837);
        _0 = _5837;
        _5837 = _16token_text(_5837);
        DeRef(_0);
        _0 = _5837;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_5837);
        *((int *)(_2+4)) = _5837;
        _5837 = MAKE_SEQ(_1);
        DeRefDS(_0);
        _0 = _5837;
        _5837 = EPrintf(-9999999, _5843, _5837);
        DeRefDS(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5837);

        // 			    			tok2 += 3
        _tok2 = _tok2 + 3;
L20:

        // 		    		end for
        _m = _m + 1;
        goto L1D;
L1E:
        ;
    }

    // 		    		if line_tokens[tok1][T_ID] = RIGHT_SQUARE then
    DeRef1(_5837);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5837 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5837);
    _0 = _5837;
    _2 = (int)SEQ_PTR(_5837);
    _5837 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5837);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _5837, -29))
        goto L21;

    // 		    			tok1 += 1
    _tok1 = _tok1 + 1;
L21:

    // 		    		replace_tokens( tok1, tok2, pdec )
    RefDS(_pdec);
    _16replace_tokens(_tok1, _tok2, _pdec);
L1A:

    // 		    	putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		    	if tok[T_ID] = LEFT_SQUARE and member_is_sequenceof( member_stack[$] ) then
    DeRef1(_5837);
    _2 = (int)SEQ_PTR(_tok);
    _5837 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5837);
    _0 = _5837;
    if (IS_ATOM_INT(_5837)) {
        _5837 = (_5837 == -28);
    }
    else {
        _5837 = binary_op(EQUALS, _5837, -28);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_5837)) {
        if (_5837 == 0) {
            goto L22;
        }
    }
    else {
        if (DBL_PTR(_5837)->dbl == 0.0) {
            goto L22;
        }
    }
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    Ref(_5774);
    _0 = _5774;
    _5774 = _11member_is_sequenceof(_5774);
    DeRef1(_0);
L23:
    if (_5774 == 0)
        goto L22;

    // 		    		Factor()
    _16Factor();
    goto L24;
L22:

    // 		    		if member_stack[$] > 0 then
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    if (binary_op_a(LESSEQ, _5774, 0))
        goto L25;

    // 		    			term_stack[$][T_SYM] = member_table[MEMBER_VARTYPE][member_stack[$]]
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_5774 + ((s1_ptr)_2)->base);
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7member_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5761);
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5761);
    if (!IS_ATOM_INT(_5815))
        _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    DeRef1(_0);
    Ref(_5815);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5815;
    DeRef(_1);
    goto L26;
L25:

    // 		    		elsif integer( member_stack[$] ) then
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _0 = _5815;
    if (IS_ATOM_INT(_5815))
        _5815 = 1;
    else if (IS_ATOM_DBL(_5815))
        _5815 = IS_ATOM_INT(DoubleToInt(_5815));
    else
        _5815 = 0;
    DeRef1(_0);
    if (_5815 == 0)
        goto L27;

    // 		    			class = member_table[MEMBER_VARTYPE][member_stack[$-1]]
    _2 = (int)SEQ_PTR(_7member_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5815);
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7member_stack)->length;
    _5761 = _5761 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5815);
    if (!IS_ATOM_INT(_5761))
        _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
    else
        _class = (int)*(((s1_ptr)_2)->base + _5761);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 		    			class = class_table[CLASS_SEQUENCEOF][find( class, class_table[CLASS_SYM] )]
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 7);
    RefDS(_5761);
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5815);
    _0 = _5815;
    _5815 = find(_class, _5815);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_5761);
    _class = (int)*(((s1_ptr)_2)->base + _5815);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 		    			term_stack[$][T_SYM] = class_table[CLASS_SYM][class]
    _5815 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_5815 + ((s1_ptr)_2)->base);
    DeRef1(_5837);
    _2 = (int)SEQ_PTR(_7class_table);
    _5837 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5837);
    _0 = _5837;
    _2 = (int)SEQ_PTR(_5837);
    _5837 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5837);
    DeRef1(_0);
    Ref(_5837);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5837;
    DeRef(_1);
    goto L26;
L27:

    // 		    			if integer( member_stack[$-1] ) then
    DeRef1(_5837);
    _5837 = SEQ_PTR(_7member_stack)->length;
    _5837 = _5837 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5837 = (int)*(((s1_ptr)_2)->base + _5837);
    Ref(_5837);
    _0 = _5837;
    if (IS_ATOM_INT(_5837))
        _5837 = 1;
    else if (IS_ATOM_DBL(_5837))
        _5837 = IS_ATOM_INT(DoubleToInt(_5837));
    else
        _5837 = 0;
    DeRef1(_0);
    if (_5837 == 0)
        goto L28;

    // 		    			if member_stack[$-1] > 0 then
    _5837 = SEQ_PTR(_7member_stack)->length;
    _5837 = _5837 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5837 = (int)*(((s1_ptr)_2)->base + _5837);
    Ref(_5837);
    if (binary_op_a(LESSEQ, _5837, 0))
        goto L29;

    // 		    				term_stack[$][T_SYM] = member_table[MEMBER_VARTYPE][member_stack[$-1]]
    DeRef1(_5837);
    _5837 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_5837 + ((s1_ptr)_2)->base);
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7member_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5815);
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    _5774 = _5774 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    _0 = _5774;
    _2 = (int)SEQ_PTR(_5815);
    if (!IS_ATOM_INT(_5774))
        _5774 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5774)->dbl));
    else
        _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    DeRef1(_0);
    Ref(_5774);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5774;
    DeRef(_1);
    goto L2A;
L29:

    // 			    			class = member_table[MEMBER_VARTYPE][member_stack[$-2]]
    DeRef1(_5774);
    _2 = (int)SEQ_PTR(_7member_table);
    _5774 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5774);
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _5815 = _5815 - 2;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _2 = (int)SEQ_PTR(_5774);
    if (!IS_ATOM_INT(_5815))
        _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _class = (int)*(((s1_ptr)_2)->base + _5815);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 			    			class = class_table[CLASS_SEQUENCEOF][find( class, class_table[CLASS_SYM] )]
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 7);
    RefDS(_5815);
    DeRef1(_5774);
    _2 = (int)SEQ_PTR(_7class_table);
    _5774 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5774);
    _0 = _5774;
    _5774 = find(_class, _5774);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_5815);
    _class = (int)*(((s1_ptr)_2)->base + _5774);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 			    			term_stack[$][T_SYM] = class_table[CLASS_SYM][class]		    				
    _5774 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_5774 + ((s1_ptr)_2)->base);
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5761);
    DeRef1(_0);
    Ref(_5761);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _5761;
    DeRef(_1);
L2A:
L28:
L26:
L24:

    // 		    	member_stack = member_stack[1..len_member_stack]
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _len_member_stack);

    // 		    	parse_method_stack = parse_method_stack[1..$-1]
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7parse_method_stack)->length;
    _5761 = _5761 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _5761);

    // 		    	if preprocess then
    if (_7preprocess == 0)
        goto L2B;

    // 		    		release_line()
    _16release_line();
L2B:

    // 				return
    DeRef1(_tok);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef1(_member_subs);
    DeRef1(_pargs);
    DeRef1(_pop);
    DeRef(_5761);
    DeRef(_5815);
    DeRef(_5837);
    DeRef(_5774);
    return 0;
    goto L2C;
L12:

    // 				emit_opnd( member_table[MEMBER_SYM][member_stack[$]] )
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7member_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_5761);
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5761);
    if (!IS_ATOM_INT(_5815))
        _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    DeRef1(_0);
    Ref(_5815);
    _15emit_opnd(_5815);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L2D;

    // 					class = member_table[MEMBER_CLASS][member_stack[$]]
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7member_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5815);
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5815);
    if (!IS_ATOM_INT(_5761))
        _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
    else
        _class = (int)*(((s1_ptr)_2)->base + _5761);
    if (!IS_ATOM_INT(_class))
        _class = (long)DBL_PTR(_class)->dbl;

    // 					pdec = sprintf( "%s_MEMBER_%s", 
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5761);
    DeRef1(_0);
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7member_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5815);
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    _0 = _5774;
    _2 = (int)SEQ_PTR(_5815);
    if (!IS_ATOM_INT(_5774))
        _5774 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5774)->dbl));
    else
        _5774 = (int)*(((s1_ptr)_2)->base + _5774);
    Ref(_5774);
    DeRef1(_0);
    _0 = _5774;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _5761;
    Ref(_5761);
    ((int *)_2)[2] = _5774;
    Ref(_5774);
    _5774 = MAKE_SEQ(_1);
    DeRef1(_0);
    DeRef1(_pdec);
    _pdec = EPrintf(-9999999, _5929, _5774);

    // 					tok2 = tok1 + (length(member_stack)-orig_member_stack) * 2
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    _5774 = _5774 - _orig_member_stack;
    _5774 = _5774 + _5774;
    if ((long)((unsigned long)_5774 + (unsigned long)HIGH_BITS) >= 0) 
        _5774 = NewDouble((double)_5774);
    if (IS_ATOM_INT(_5774)) {
        _tok2 = _tok1 + _5774;
    }
    else {
        _tok2 = NewDouble((double)_tok1 + DBL_PTR(_5774)->dbl);
    }
    if (!IS_ATOM_INT(_tok2)) {
        _1 = (long)(DBL_PTR(_tok2)->dbl);
        DeRefDS(_tok2);
        _tok2 = _1;
    }

    // 					if tok2 = tok1 then
    if (_tok2 != _tok1)
        goto L2E;

    // 						tok2 += 2
    _tok2 = _tok2 + 2;
L2E:

    // 					replace_tokens( tok1, tok2, pdec )
    RefDS(_pdec);
    _16replace_tokens(_tok1, _tok2, _pdec);

    // 					release_line()
    _16release_line();
L2D:

    // 				member_stack = member_stack[1..len_member_stack]
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _len_member_stack);

    // 				putback( tok )
    RefDS(_tok);
    _16putback(_tok);

    // 				parse_method_stack = parse_method_stack[1..$-1]
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7parse_method_stack)->length;
    _5774 = _5774 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _5774);

    // 				return
    DeRef1(_tok);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef1(_member_subs);
    DeRef1(_pargs);
    DeRef1(_pop);
    DeRef(_5761);
    DeRef(_5815);
    DeRef(_5837);
    return 0;
L2C:
LE:
L3:

    // 	term_stack[$][T_SYM] = object_type
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_5774 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11object_type;
    DeRef(_1);

    //     method_stack &= {tok}
    _0 = _5815;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _5815 = MAKE_SEQ(_1);
    DeRef1(_0);
    Concat((object_ptr)&_7method_stack, _7method_stack, (s1_ptr)_5815);

    //     method_args &= { {} }
    _0 = _5815;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_39);
    *((int *)(_2+4)) = _39;
    _5815 = MAKE_SEQ(_1);
    DeRef1(_0);
    Concat((object_ptr)&_7method_args, _7method_args, (s1_ptr)_5815);

    //     method_name = append( method_name,  SymTab[tok[T_SYM]][S_NAME] )
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_tok);
    _5815 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5815))
        _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    DeRef1(_0);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5815);
    DeRef1(_0);
    Ref(_5815);
    Append(&_7method_name, _7method_name, _5815);

    //     SymTab[tok[T_SYM]][S_USAGE] = or_bits( U_READ, U_WRITTEN )
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_tok);
    _5815 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5815);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5815))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _3 = (int)(_5815 + ((s1_ptr)_2)->base);
    DeRef1(_5761);
    _5761 = (1 | 2);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _5761;
    DeRef(_1);

    //     current_method += 1
    _7current_method = _7current_method + 1;

    //     parse_method_stack[$] = 1
    _5761 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _2 = (int)(((s1_ptr)_2)->base + _5761);
    *(int *)_2 = 1;

    //     tok_match(LEFT_ROUND)
    _16tok_match(-26);

    //     s = tok[T_SYM] 
    _2 = (int)SEQ_PTR(_tok);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	member_subs = {}
    RefDS(_39);
    DeRef1(_member_subs);
    _member_subs = _39;

    //     if last_member then
    if (_last_member == 0)
        goto L2F;

    //     	if is_sequenceof( current_instance[$] ) then
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    Ref(_5761);
    _0 = _5761;
    _5761 = _11is_sequenceof(_5761);
    DeRef1(_0);
    if (_5761 == 0) {
        goto L30;
    }
    else {
        if (!IS_ATOM_INT(_5761) && DBL_PTR(_5761)->dbl == 0.0)
            goto L30;
    }

    //     		emit_opnd( current_sequence[$] )
    DeRef1(_5761);
    _5761 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    Ref(_5761);
    _15emit_opnd(_5761);
    goto L31;
L30:

    //     		emit_opnd( current_instance[$] )
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    Ref(_5761);
    _15emit_opnd(_5761);
L31:

    //     	for m = 2 to length(member_stack)-1 do
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7member_stack)->length;
    _5761 = _5761 - 1;
    { int _m;
        _m = 2;
L32:
        if (_m > _5761)
            goto L33;

        // 		    if lhs_subs_level >= 0 then
        if (_16lhs_subs_level < 0)
            goto L34;

        // 				lhs_subs_level += 1
        _16lhs_subs_level = _16lhs_subs_level + 1;
L34:

        // 		    if member_stack[m] > 0 then
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5774 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5774);
        if (binary_op_a(LESSEQ, _5774, 0))
            goto L35;

        // 		    	emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_table);
        _5774 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_5774);
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        _2 = (int)SEQ_PTR(_5774);
        if (!IS_ATOM_INT(_5815))
            _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
        else
            _5815 = (int)*(((s1_ptr)_2)->base + _5815);
        Ref(_5815);
        DeRef(_0);
        Ref(_5815);
        _15emit_opnd(_5815);

        // 		    	emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L36;
L35:

        // 		    elsif integer( member_stack[m] ) then
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        if (IS_ATOM_INT(_5815))
            _5815 = 1;
        else if (IS_ATOM_DBL(_5815))
            _5815 = IS_ATOM_INT(DoubleToInt(_5815));
        else
            _5815 = 0;
        DeRef(_0);
        if (_5815 == 0)
            goto L37;

        // 				if member_stack[m] < 0 then
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        if (binary_op_a(GREATEREQ, _5815, 0))
            goto L36;

        // 			    	emit_opnd( -member_stack[m] )
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        if (IS_ATOM_INT(_5815)) {
            if (_5815 == 0xC0000000)
                _5815 = (int)NewDouble((double)-0xC0000000);
            else
                _5815 = - _5815;
        }
        else {
            _5815 = unary_op(UMINUS, _5815);
        }
        DeRef(_0);
        Ref(_5815);
        _15emit_opnd(_5815);

        // 			    	emit_op( RHS_SUBS )
        _15emit_op(25);
L38:
        goto L36;
L37:

        // 		    	emit_op( DOLLAR )
        _15emit_op(-22);

        // 		    	emit_op( RHS_SUBS )
        _15emit_op(25);
L36:

        //     	end for
        _m = _m + 1;
        goto L32;
L33:
        ;
    }

    //     	real_instance = length(member_stack) + 2
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _real_instance = _5815 + 2;

    // 		member_subs = member_stack[2..$-1]
    _5815 = SEQ_PTR(_7member_stack)->length;
    _5815 = _5815 - 1;
    rhs_slice_target = (object_ptr)&_member_subs;
    RHS_Slice((s1_ptr)_7member_stack, 2, _5815);
    goto L39;
L2F:

    //     elsif member_stack[$] then
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    if (_5815 == 0) {
        goto L3A;
    }
    else {
        if (!IS_ATOM_INT(_5815) && DBL_PTR(_5815)->dbl == 0.0)
            goto L3A;
    }

    //     	if is_sequenceof( current_instance[$] ) then
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    Ref(_5815);
    _0 = _5815;
    _5815 = _11is_sequenceof(_5815);
    DeRef1(_0);
    if (_5815 == 0) {
        goto L3B;
    }
    else {
        if (!IS_ATOM_INT(_5815) && DBL_PTR(_5815)->dbl == 0.0)
            goto L3B;
    }

    //     		emit_opnd( current_sequence[$] )
    DeRef1(_5815);
    _5815 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    Ref(_5815);
    _15emit_opnd(_5815);
    goto L3C;
L3B:

    //     		emit_opnd( current_instance[$] )
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    Ref(_5815);
    _15emit_opnd(_5815);
L3C:

    //     	for m = 2 to length(member_stack) do
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L3D:
        if (_m > _5815)
            goto L3E;

        //     		if m > 2 then
        if (_m <= 2)
            goto L3F;

        //     			emit_opnd( current_sequence[$] )
        DeRef(_5774);
        _5774 = SEQ_PTR(_15current_sequence)->length;
        _2 = (int)SEQ_PTR(_15current_sequence);
        _5774 = (int)*(((s1_ptr)_2)->base + _5774);
        Ref(_5774);
        Ref(_5774);
        _15emit_opnd(_5774);
L3F:

        //     		if member_stack[m] > 0 then
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5774 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5774);
        if (binary_op_a(LESSEQ, _5774, 0))
            goto L40;

        //     			emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
        DeRef(_5774);
        _2 = (int)SEQ_PTR(_7member_table);
        _5774 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_5774);
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5761 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5761);
        _0 = _5761;
        _2 = (int)SEQ_PTR(_5774);
        if (!IS_ATOM_INT(_5761))
            _5761 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
        else
            _5761 = (int)*(((s1_ptr)_2)->base + _5761);
        Ref(_5761);
        DeRef(_0);
        Ref(_5761);
        _15emit_opnd(_5761);

        //     			emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L41;
L40:

        //     		elsif integer( member_stack[m] ) then
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5761 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5761);
        _0 = _5761;
        if (IS_ATOM_INT(_5761))
            _5761 = 1;
        else if (IS_ATOM_DBL(_5761))
            _5761 = IS_ATOM_INT(DoubleToInt(_5761));
        else
            _5761 = 0;
        DeRef(_0);
        if (_5761 == 0)
            goto L42;

        //     			emit_opnd( - member_stack[m] )
        _2 = (int)SEQ_PTR(_7member_stack);
        _5761 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5761);
        _0 = _5761;
        if (IS_ATOM_INT(_5761)) {
            if (_5761 == 0xC0000000)
                _5761 = (int)NewDouble((double)-0xC0000000);
            else
                _5761 = - _5761;
        }
        else {
            _5761 = unary_op(UMINUS, _5761);
        }
        DeRef(_0);
        Ref(_5761);
        _15emit_opnd(_5761);

        //     			emit_op( RHS_SUBS )
        _15emit_op(25);
        goto L41;
L42:

        //     			emit_op( DOLLAR )
        _15emit_op(-22);

        //     			emit_op( RHS_SUBS )
        _15emit_op(25);
L41:

        //     	end for
        _m = _m + 1;
        goto L3D;
L3E:
        ;
    }

    //     	sym = current_sequence[$]
    DeRef1(_5761);
    _5761 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _sym = (int)*(((s1_ptr)_2)->base + _5761);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     	current_sequence = current_sequence[1..$-1]
    _5761 = SEQ_PTR(_15current_sequence)->length;
    _5761 = _5761 - 1;
    rhs_slice_target = (object_ptr)&_15current_sequence;
    RHS_Slice((s1_ptr)_15current_sequence, 1, _5761);

    //     	real_instance = 3
    _real_instance = 3;

    //     	if preprocess then
    if (_7preprocess == 0)
        goto L39;

    //     		first_arg = SymTab[current_instance[$]][S_NAME]
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5761))
        _5761 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
    else
        _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    DeRef1(_0);
    DeRef1(_first_arg);
    _2 = (int)SEQ_PTR(_5761);
    _first_arg = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_first_arg);

    //     		class = find( SymTab[current_instance[$]][S_VTYPE], class_table[CLASS_SYM] )
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5761))
        _5761 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
    else
        _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    DeRef1(_0);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_5761);
    DeRef1(_0);
    DeRef1(_5774);
    _2 = (int)SEQ_PTR(_7class_table);
    _5774 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5774);
    _class = find(_5761, _5774);

    //    			for m = 2 to length(member_stack) do
    DeRef1(_5774);
    _5774 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L43:
        if (_m > _5774)
            goto L44;

        //    				first_arg &= sprintf("[%s_MEMBER_%s]", 
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7class_table);
        _5761 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_5761);
        _0 = _5761;
        _2 = (int)SEQ_PTR(_5761);
        _5761 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_5761);
        DeRefDS(_0);
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_table);
        _5815 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5815);
        DeRef(_5837);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5837 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5837);
        _0 = _5837;
        _2 = (int)SEQ_PTR(_5815);
        if (!IS_ATOM_INT(_5837))
            _5837 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5837)->dbl));
        else
            _5837 = (int)*(((s1_ptr)_2)->base + _5837);
        Ref(_5837);
        DeRef(_0);
        _0 = _5837;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _5761;
        Ref(_5761);
        ((int *)_2)[2] = _5837;
        Ref(_5837);
        _5837 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _5837;
        _5837 = EPrintf(-9999999, _4281, _5837);
        DeRefDS(_0);
        Concat((object_ptr)&_first_arg, _first_arg, (s1_ptr)_5837);

        //    				class = find( member_table[MEMBER_VARTYPE][member_stack[m]], class_table[CLASS_SYM] )
        DeRefDSi(_5837);
        _2 = (int)SEQ_PTR(_7member_table);
        _5837 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5837);
        DeRef(_5815);
        _2 = (int)SEQ_PTR(_7member_stack);
        _5815 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_5815);
        _0 = _5815;
        _2 = (int)SEQ_PTR(_5837);
        if (!IS_ATOM_INT(_5815))
            _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
        else
            _5815 = (int)*(((s1_ptr)_2)->base + _5815);
        Ref(_5815);
        DeRef(_0);
        DeRef(_5837);
        _2 = (int)SEQ_PTR(_7class_table);
        _5837 = (int)*(((s1_ptr)_2)->base + 6);
        RefDS(_5837);
        _class = find(_5815, _5837);

        //    				real_instance += 2
        _real_instance = _real_instance + 2;

        //    				tok1 -= 2
        _tok1 = _tok1 - 2;

        //    			end for
        _m = _m + 1;
        goto L43;
L44:
        ;
    }
L45:
    goto L39;
L3A:

    // 	    sym = current_instance[$]
    DeRef1(_5837);
    _5837 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _sym = (int)*(((s1_ptr)_2)->base + _5837);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	    if sym and not find( sym, class_table[CLASS_SYM] ) then
    if (_sym == 0) {
        goto L46;
    }
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5815);
    _0 = _5815;
    _5815 = find(_sym, _5815);
    DeRef1(_0);
    _5815 = (_5815 == 0);
L47:
    if (_5815 == 0)
        goto L46;

    // 	    	if preprocess then
    if (_7preprocess == 0)
        goto L48;

    // 	    		first_arg = SymTab[sym][S_NAME]
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5815 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5815);
    DeRef1(_first_arg);
    _2 = (int)SEQ_PTR(_5815);
    _first_arg = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_first_arg);
L48:

    // 	   		SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_5761);
    DeRef1(_0);
    _0 = _5761;
    if (IS_ATOM_INT(_5761)) {
        _5761 = (_5761 | 1);
    }
    else {
        _5761 = binary_op(OR_BITS, _5761, 1);
    }
    DeRef1(_0);
    Ref(_5761);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _5761;
    DeRef(_1);

    // 			InitCheck(sym, TRUE)
    _16InitCheck(_sym, 1);

    // 	    	if is_sequenceof( sym ) then
    _0 = _5761;
    _5761 = _11is_sequenceof(_sym);
    DeRef1(_0);
    if (_5761 == 0) {
        goto L49;
    }
    else {
        if (!IS_ATOM_INT(_5761) && DBL_PTR(_5761)->dbl == 0.0)
            goto L49;
    }

    // 	    		emit_opnd( current_sequence[$] )
    DeRef1(_5761);
    _5761 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    Ref(_5761);
    _15emit_opnd(_5761);
    goto L4A;
L49:

    // 	    		emit_opnd( sym )
    _15emit_opnd(_sym);
L4A:

    // 			real_instance = 3
    _real_instance = 3;
    goto L4B;
L46:

    // 			real_instance = 0
    _real_instance = 0;
L4B:
L39:

    //     len_member_stack = length(member_stack)
    _len_member_stack = SEQ_PTR(_7member_stack)->length;

    //     member_stack &= 0
    Append(&_7member_stack, _7member_stack, 0);

    //     ParseMethodArgs(tok)
    RefDS(_tok);
    _16ParseMethodArgs(_tok);

    //     member_stack = member_stack[1..len_member_stack]
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _len_member_stack);

    //     if last_member then
    if (_last_member == 0)
        goto L4C;

    // 		csym = member_table[MEMBER_VARTYPE][last_member]
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7member_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5761);
    _csym = (int)*(((s1_ptr)_2)->base + _last_member);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 		class = find( csym, class_table[CLASS_SYM] )
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5761);
    _class = find(_csym, _5761);

    // 		if not class then
    if (_class != 0)
        goto L4D;

    // 			CompileErr( sprintf("member '%s' does not have methods",{method_table[METHOD_NAME][last_member]}))
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7method_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + _last_member);
    Ref(_5761);
    DeRef1(_0);
    _0 = _5761;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_5761);
    *((int *)(_2+4)) = _5761;
    _5761 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _5761;
    _5761 = EPrintf(-9999999, _6070, _5761);
    DeRef1(_0);
    RefDS(_5761);
    _9CompileErr(_5761);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L4E;

    // 				release_line()
    _16release_line();
L4E:

    // 			return 
    DeRef1(_tok);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef1(_member_subs);
    DeRef1(_pargs);
    DeRef1(_pop);
    DeRef(_5761);
    DeRef(_5815);
    DeRef(_5837);
    DeRef(_5774);
    return 0;
L4F:
    goto L4D;
L4C:

    //     elsif find( sym, class_table[CLASS_SYM] ) then
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5761);
    _0 = _5761;
    _5761 = find(_sym, _5761);
    DeRef1(_0);
    if (_5761 == 0)
        goto L50;

    //     	if not length(method_args[$]) then
    _5761 = SEQ_PTR(_7method_args)->length;
    _2 = (int)SEQ_PTR(_7method_args);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _0 = _5761;
    _5761 = SEQ_PTR(_5761)->length;
    DeRef1(_0);
    if (_5761 != 0)
        goto L51;

    //     		CompileErr( "method function requires a 'this' parameter" )
    RefDS(_6081);
    _9CompileErr(_6081);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L52;

    // 				release_line()
    _16release_line();
L52:

    //     		return
    DeRef1(_tok);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef1(_member_subs);
    DeRef1(_pargs);
    DeRef1(_pop);
    DeRef(_5761);
    DeRef(_5815);
    DeRef(_5837);
    DeRef(_5774);
    return 0;
L51:

    // 		if compare( SymTab[sym][S_NAME], SymTab[s][S_NAME] ) then
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5761);
    DeRef1(_0);
    DeRef1(_5837);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5837 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5837);
    _0 = _5837;
    _2 = (int)SEQ_PTR(_5837);
    _5837 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5837);
    DeRef1(_0);
    _0 = _5837;
    if (IS_ATOM_INT(_5761) && IS_ATOM_INT(_5837))
        _5837 = (_5761 < _5837) ? -1 : (_5761 > _5837);
    else
        _5837 = compare(_5761, _5837);
    DeRef1(_0);
    if (_5837 == 0)
        goto L53;

    // 	    	method_args[$] = method_args[$][2..$]			
    _5837 = SEQ_PTR(_7method_args)->length;
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7method_args)->length;
    _2 = (int)SEQ_PTR(_7method_args);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    DeRef1(_5815);
    _5815 = SEQ_PTR(_5761)->length;
    rhs_slice_target = (object_ptr)&_5815;
    RHS_Slice((s1_ptr)_5761, 2, _5815);
    RefDS(_5815);
    _2 = (int)SEQ_PTR(_7method_args);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_args = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _5837);
    _1 = *(int *)_2;
    *(int *)_2 = _5815;
    DeRef(_1);
L53:

    //     	class = find( sym, class_table[CLASS_SYM] )
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5815);
    _class = find(_sym, _5815);
    goto L4D;
L50:

    // 	    class = 0
    _class = 0;

    // 	    if num_zeroes( current_instance ) < num_zeroes( member_stack ) then
    RefDS(_7current_instance);
    _0 = _5815;
    _5815 = _16num_zeroes(_7current_instance);
    DeRef1(_0);
    RefDS(_7member_stack);
    _0 = _5761;
    _5761 = _16num_zeroes(_7member_stack);
    DeRef1(_0);
    if (_5815 >= _5761)
        goto L54;

    // 	    	if member_stack[$] = 0 and member_stack[$-1] != 0 then
    _5761 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _0 = _5761;
    if (IS_ATOM_INT(_5761)) {
        _5761 = (_5761 == 0);
    }
    else {
        _5761 = binary_op(EQUALS, _5761, 0);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_5761)) {
        if (_5761 == 0) {
            goto L55;
        }
    }
    else {
        if (DBL_PTR(_5761)->dbl == 0.0) {
            goto L55;
        }
    }
    _5815 = SEQ_PTR(_7member_stack)->length;
    _5815 = _5815 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _0 = _5815;
    if (IS_ATOM_INT(_5815)) {
        _5815 = (_5815 != 0);
    }
    else {
        _5815 = binary_op(NOTEQ, _5815, 0);
    }
    DeRef1(_0);
L56:
    if (_5815 == 0) {
        goto L55;
    }
    else {
        if (!IS_ATOM_INT(_5815) && DBL_PTR(_5815)->dbl == 0.0)
            goto L55;
    }

    // 	    		csym = SymTab[current_instance[$]][S_VTYPE]
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5815))
        _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_5815);
    _csym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 	    		class = find( csym, class_table[CLASS_SYM] )
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5815);
    _class = find(_csym, _5815);

    // 	    		csym = member_stack[$-1]
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7member_stack)->length;
    _5815 = _5815 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _csym = (int)*(((s1_ptr)_2)->base + _5815);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 	    		csym = member_table[MEMBER_SYM][csym]
    _2 = (int)SEQ_PTR(_7member_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_5815);
    _2 = (int)SEQ_PTR(_5815);
    _csym = (int)*(((s1_ptr)_2)->base + _csym);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 	    		csym = SymTab[csym][S_VTYPE]
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5815 = (int)*(((s1_ptr)_2)->base + _csym);
    Ref(_5815);
    _2 = (int)SEQ_PTR(_5815);
    _csym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 	    		class = find( csym, class_table[CLASS_SYM] )
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5815);
    _class = find(_csym, _5815);

    // 				if class then
    if (_class == 0)
        goto L57;

    // 		    		if class_table[CLASS_NAME][class][1] = '_' then
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5815);
    DeRef1(_0);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5815);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _5815, 95))
        goto L58;

    // 		    			class = sequence_of_class( class )
    _class = _11sequence_of_class(_class);
L58:

    // 		    		if compare( class_table[CLASS_NAME][class], SymTab[s][S_NAME] ) then
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + _class);
    Ref(_5815);
    DeRef1(_0);
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5761);
    DeRef1(_0);
    _0 = _5761;
    if (IS_ATOM_INT(_5815) && IS_ATOM_INT(_5761))
        _5761 = (_5815 < _5761) ? -1 : (_5815 > _5761);
    else
        _5761 = compare(_5815, _5761);
    DeRef1(_0);
    if (_5761 == 0)
        goto L59;

    // 		    			class = 0
    _class = 0;
    goto L5A;
L59:

    // 		    			pop = {Pop(), Pop()}
    _0 = _5761;
    _5761 = _15Pop();
    DeRef1(_0);
    _0 = _5815;
    _5815 = _15Pop();
    DeRef1(_0);
    DeRef1(_pop);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _5761;
    ((int *)_2)[2] = _5815;
    _pop = MAKE_SEQ(_1);

    // 		    			Push( pop[1] )
    _2 = (int)SEQ_PTR(_pop);
    _5815 = (int)*(((s1_ptr)_2)->base + 1);
    _15Push(_5815);
L5A:
L57:
L55:
L54:

    // 	    if not class then
    if (_class != 0)
        goto L5B;

    // 	    	if not real_instance then
    if (_real_instance != 0)
        goto L5C;

    // 		    	csym = tok[T_SYM]  
    _2 = (int)SEQ_PTR(_tok);
    _csym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;

    // 			    if current_instance[$] then
    DeRef1(_5815);
    _5815 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    if (_5815 == 0) {
        goto L5D;
    }
    else {
        if (!IS_ATOM_INT(_5815) && DBL_PTR(_5815)->dbl == 0.0)
            goto L5D;
    }

    // 			    	if find( csym, class_table[CLASS_SYM] ) then -- length(member_stack) > 1 and member_stack[$-1] then
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7class_table);
    _5815 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5815);
    _0 = _5815;
    _5815 = find(_csym, _5815);
    DeRef1(_0);
    if (_5815 == 0)
        goto L5E;

    // 						cg_stack[$-1] = Pop()
    _5815 = SEQ_PTR(_15cg_stack)->length;
    _5815 = _5815 - 1;
    _0 = _5761;
    _5761 = _15Pop();
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_15cg_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _15cg_stack = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _5815);
    _1 = *(int *)_2;
    *(int *)_2 = _5761;
    DeRef(_1);
    goto L5D;
L5E:

    // 		    			csym = SymTab[current_instance[$]][S_VTYPE]	
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5761))
        _5761 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5761)->dbl));
    else
        _5761 = (int)*(((s1_ptr)_2)->base + _5761);
    Ref(_5761);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_5761);
    _csym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;
L5F:
L60:
    goto L5D;
L5C:

    // 				csym = SymTab[sym][S_VTYPE]
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5761);
    _csym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_csym))
        _csym = (long)DBL_PTR(_csym)->dbl;
L5D:

    // 			class = find( csym, class_table[CLASS_SYM] )
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7class_table);
    _5761 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_5761);
    _class = find(_csym, _5761);
L5B:
L4D:

    //     s = PolyMorph( class )
    _s = _16PolyMorph(_class);
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     if preprocess then
    if (_7preprocess == 0)
        goto L61;

    //     	pdec = pp_decorate( SymTab[s][S_NAME]) & "( "
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5761);
    DeRef1(_0);
    Ref(_5761);
    _0 = _5761;
    _5761 = _16pp_decorate(_5761);
    DeRef1(_0);
    Concat((object_ptr)&_pdec, _5761, (s1_ptr)_5336);

    //     	if real_instance then
    if (_real_instance == 0)
        goto L62;

    // 			if line_tokens[tok1][T_ID] = RIGHT_SQUARE then
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5761 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5761);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _5761, -29))
        goto L63;

    // 				tok2 = tok1 - read_backwards( tok1 )
    _0 = _5761;
    _5761 = _16read_backwards(_tok1);
    DeRef1(_0);
    if (IS_ATOM_INT(_5761)) {
        _tok2 = _tok1 - _5761;
    }
    else {
        _tok2 = NewDouble((double)_tok1 - DBL_PTR(_5761)->dbl);
    }
    if (!IS_ATOM_INT(_tok2)) {
        _1 = (long)(DBL_PTR(_tok2)->dbl);
        DeRefDS(_tok2);
        _tok2 = _1;
    }

    // 				tok1 -= tok2
    _tok1 = _tok1 - _tok2;

    // 				ppoff = tok2
    _ppoff = _tok2;

    // 	    		for i = 0 to tok2 do
    DeRef1(_5761);
    _5761 = _tok2;
    { int _i;
        _i = 0;
L64:
        if (_i > _5761)
            goto L65;

        // 	    			pdec &= token_text( i + tok1 )
        DeRef(_5815);
        _5815 = _i + _tok1;
        if ((long)((unsigned long)_5815 + (unsigned long)HIGH_BITS) >= 0) 
            _5815 = NewDouble((double)_5815);
        Ref(_5815);
        _0 = _5815;
        _5815 = _16token_text(_5815);
        DeRef(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5815);

        // 	    		end for	
        _i = _i + 1;
        goto L64;
L65:
        ;
    }
    goto L66;
L63:

    // 	    		tok2 = 0
    _tok2 = 0;

    // 	    		ppoff = 0
    _ppoff = 0;

    // 	    		if line_tokens[tok1][T_SYM] then
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5815 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5815);
    DeRef1(_0);
    if (_5815 == 0) {
        goto L67;
    }
    else {
        if (!IS_ATOM_INT(_5815) && DBL_PTR(_5815)->dbl == 0.0)
            goto L67;
    }

    // 	    			pdec &= SymTab[line_tokens[tok1][T_SYM]][S_NAME]
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7line_tokens);
    _5815 = (int)*(((s1_ptr)_2)->base + _tok1);
    RefDS(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_5815);
    DeRef1(_0);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_5815))
        _5815 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5815)->dbl));
    else
        _5815 = (int)*(((s1_ptr)_2)->base + _5815);
    Ref(_5815);
    DeRef1(_0);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5815);
    DeRef1(_0);
    if (IS_SEQUENCE(_pdec) && IS_ATOM(_5815)) {
        Ref(_5815);
        Append(&_pdec, _pdec, _5815);
    }
    else if (IS_ATOM(_pdec) && IS_SEQUENCE(_5815)) {
    }
    else {
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5815);
    }
    goto L68;
L67:

    // 	    			tok1 += 1
    _tok1 = _tok1 + 1;

    // 	    			real_instance = 1
    _real_instance = 1;
L68:
L66:

    //     		for i = 1 to length(member_subs) do
    DeRef1(_5815);
    _5815 = SEQ_PTR(_member_subs)->length;
    { int _i;
        _i = 1;
L69:
        if (_i > _5815)
            goto L6A;

        //     			member = member_subs[i]
        _2 = (int)SEQ_PTR(_member_subs);
        _member = (int)*(((s1_ptr)_2)->base + _i);
        if (!IS_ATOM_INT(_member))
            _member = (long)DBL_PTR(_member)->dbl;

        //     			if member > 0 then
        if (_member <= 0)
            goto L6B;

        // 	    			class = member_table[MEMBER_CLASS][member]
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7member_table);
        _5761 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5761);
        _2 = (int)SEQ_PTR(_5761);
        _class = (int)*(((s1_ptr)_2)->base + _member);
        if (!IS_ATOM_INT(_class))
            _class = (long)DBL_PTR(_class)->dbl;

        // 	    			pdec &= sprintf("[%s_MEMBER_%s]", 
        DeRef(_5761);
        _2 = (int)SEQ_PTR(_7class_table);
        _5761 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_5761);
        _0 = _5761;
        _2 = (int)SEQ_PTR(_5761);
        _5761 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_5761);
        DeRefDS(_0);
        DeRef(_5837);
        _2 = (int)SEQ_PTR(_7member_table);
        _5837 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5837);
        _0 = _5837;
        _2 = (int)SEQ_PTR(_5837);
        _5837 = (int)*(((s1_ptr)_2)->base + _member);
        Ref(_5837);
        DeRef(_0);
        _0 = _5837;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _5761;
        Ref(_5761);
        ((int *)_2)[2] = _5837;
        Ref(_5837);
        _5837 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _5837;
        _5837 = EPrintf(-9999999, _4281, _5837);
        DeRefDS(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5837);

        // 	    			ppoff += 2
        _ppoff = _ppoff + 2;
        goto L6C;
L6B:

        // 	    			ppoff += 2
        _ppoff = _ppoff + 2;

        // 	    			pdec &= sprintf("[%s]",{token_text(tok1+ppoff)})
        DeRef(_5837);
        _5837 = _tok1 + _ppoff;
        if ((long)((unsigned long)_5837 + (unsigned long)HIGH_BITS) >= 0) 
            _5837 = NewDouble((double)_5837);
        Ref(_5837);
        _0 = _5837;
        _5837 = _16token_text(_5837);
        DeRef(_0);
        _0 = _5837;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_5837);
        *((int *)(_2+4)) = _5837;
        _5837 = MAKE_SEQ(_1);
        DeRefDS(_0);
        _0 = _5837;
        _5837 = EPrintf(-9999999, _5843, _5837);
        DeRefDS(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5837);

        // 	    			ppoff += 1
        _ppoff = _ppoff + 1;
L6C:

        //     		end for
        _i = _i + 1;
        goto L69;
L6A:
        ;
    }

    //     		if SymTab[s][S_NUM_ARGS] > 1 then
    DeRef1(_5837);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5837 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5837);
    _0 = _5837;
    _2 = (int)SEQ_PTR(_5837);
    _5837 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_5837);
    DeRef1(_0);
    if (binary_op_a(LESSEQ, _5837, 1))
        goto L6D;

    //     			pdec &= ", "
    Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_5341);
L6E:
    goto L6D;
L62:

    //     		tok2 = 0
    _tok2 = 0;

    //     		real_instance = 3
    _real_instance = 3;

    //     		if not current_instance[$] then
    DeRef1(_5837);
    _5837 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _5837 = (int)*(((s1_ptr)_2)->base + _5837);
    Ref(_5837);
    if (IS_ATOM_INT(_5837)) {
        if (_5837 != 0)
            goto L6F;
    }
    else {
        if (DBL_PTR(_5837)->dbl != 0.0)
            goto L6F;
    }

    //     			tok1 += 1
    _tok1 = _tok1 + 1;

    //     			real_instance -= 2
    _real_instance = 1;
L6F:
L6D:

    // 		replace_tokens( tok1, tok1 + real_instance + tok2 + 2 * (tok2 > 0 )*0, pdec )
    DeRef1(_5837);
    _5837 = _tok1 + _real_instance;
    if ((long)((unsigned long)_5837 + (unsigned long)HIGH_BITS) >= 0) 
        _5837 = NewDouble((double)_5837);
    _0 = _5837;
    if (IS_ATOM_INT(_5837)) {
        _5837 = _5837 + _tok2;
        if ((long)((unsigned long)_5837 + (unsigned long)HIGH_BITS) >= 0) 
            _5837 = NewDouble((double)_5837);
    }
    else {
        _5837 = NewDouble(DBL_PTR(_5837)->dbl + (double)_tok2);
    }
    DeRef1(_0);
    DeRef1(_5761);
    _5761 = (_tok2 > 0);
    _5761 = _5761 + _5761;
    _5761 = 0;
    if (IS_ATOM_INT(_5837)) {
        _5761 = _5837 + 0;
        if ((long)((unsigned long)_5761 + (unsigned long)HIGH_BITS) >= 0) 
            _5761 = NewDouble((double)_5761);
    }
    else {
        _5761 = NewDouble(DBL_PTR(_5837)->dbl + (double)0);
    }
    Ref(_5761);
    RefDS(_pdec);
    _16replace_tokens(_tok1, _5761, _pdec);

    //     	release_line()
    _16release_line();
L61:

    //     add_ref( {r:FUNC, s} )
    DeRef1(_5761);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 501;
    ((int *)_2)[2] = _s;
    _5761 = MAKE_SEQ(_1);
    RefDS(_5761);
    _11add_ref(_5761);

    //     method_name = method_name[1..$-1]
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7method_name)->length;
    _5761 = _5761 - 1;
    rhs_slice_target = (object_ptr)&_7method_name;
    RHS_Slice((s1_ptr)_7method_name, 1, _5761);

    // 	e = SymTab[s][S_EFFECT]
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5761);
    _e = (int)*(((s1_ptr)_2)->base + 21);
    if (!IS_ATOM_INT(_e))
        _e = (long)DBL_PTR(_e)->dbl;

    // 	if e then
    if (_e == 0)
        goto L70;

    // 	    if e = E_ALL_EFFECT or s > left_sym then
    DeRef1(_5761);
    _5761 = (_e == 1073741823);
    if (_5761 != 0) {
        goto L71;
    }
    DeRef1(_5837);
    _5837 = (_s > _16left_sym);
L72:
    if (_5837 == 0)
        goto L73;
L71:

    // 		side_effect_calls = or_bits(side_effect_calls, e)
    _16side_effect_calls = (_16side_effect_calls | _e);
L73:

    // 	    SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT], e)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5815 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_5815);
    _0 = _5815;
    _2 = (int)SEQ_PTR(_5815);
    _5815 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_5815);
    DeRef1(_0);
    _0 = _5815;
    if (IS_ATOM_INT(_5815)) {
        _5815 = (_5815 | _e);
    }
    else {
        _5815 = binary_op(OR_BITS, _5815, _e);
    }
    DeRef1(_0);
    Ref(_5815);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _5815;
    DeRef(_1);

    // 	    if short_circuit > 0 and short_circuit_B then -- and
    DeRef1(_5815);
    _5815 = (_16short_circuit > 0);
    if (_5815 == 0) {
        goto L74;
    }
L75:
    if (_16short_circuit_B == 0)
        goto L74;

    // 		Warning(sprintf(
    DeRef1(_5815);
    _2 = (int)SEQ_PTR(_7file_name);
    _5815 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_5815);
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5761);
    _0 = _5761;
    _2 = (int)SEQ_PTR(_5761);
    _5761 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5761);
    DeRef1(_0);
    _0 = _5761;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_5815);
    *((int *)(_2+4)) = _5815;
    *((int *)(_2+8)) = _7line_number;
    Ref(_5761);
    *((int *)(_2+12)) = _5761;
    _5761 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _5761;
    _5761 = EPrintf(-9999999, _3990, _5761);
    DeRef1(_0);
    RefDS(_5761);
    _9Warning(_5761);
L74:
L70:

    // 	scope = SymTab[s][S_SCOPE]
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5761);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    // 	opcode = SymTab[s][S_OPCODE]
    DeRef1(_5761);
    _2 = (int)SEQ_PTR(_7SymTab);
    _5761 = (int)*(((s1_ptr)_2)->base + _s);
    Ref(_5761);
    _2 = (int)SEQ_PTR(_5761);
    _opcode = (int)*(((s1_ptr)_2)->base + 19);
    if (!IS_ATOM_INT(_opcode))
        _opcode = (long)DBL_PTR(_opcode)->dbl;

    // 	if scope = SC_PREDEF then
    if (_scope != 7)
        goto L76;

    // 	    emit_op(opcode)
    _15emit_op(_opcode);
    goto L77;
L76:

    // 	    op_info1 = s
    _15op_info1 = _s;

    // 	    emit_op(r:PROC)
    _15emit_op(27);

    // 	    if not TRANSLATE then 

    // 		if OpTrace then
    if (_7OpTrace == 0)
        goto L78;

    // 		    emit_op(UPDATE_GLOBALS)
    _15emit_op(89);
L78:
L79:
L77:

    //     method_args = method_args[1..$-1]
    DeRef1(_5761);
    _5761 = SEQ_PTR(_7method_args)->length;
    _5761 = _5761 - 1;
    rhs_slice_target = (object_ptr)&_7method_args;
    RHS_Slice((s1_ptr)_7method_args, 1, _5761);

    //     method_stack = method_stack[1..$-1]
    _5761 = SEQ_PTR(_7method_stack)->length;
    _5761 = _5761 - 1;
    rhs_slice_target = (object_ptr)&_7method_stack;
    RHS_Slice((s1_ptr)_7method_stack, 1, _5761);

    //     member_stack = member_stack[1..orig_member_stack]
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _orig_member_stack);

    //     current_method -= 1
    _7current_method = _7current_method - 1;

    //     parse_method_stack = parse_method_stack[1..$-1]
    _5761 = SEQ_PTR(_7parse_method_stack)->length;
    _5761 = _5761 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _5761);

    // end procedure
    DeRef1(_tok);
    DeRef1(_pdec);
    DeRef1(_first_arg);
    DeRef1(_member_subs);
    DeRef1(_pargs);
    DeRef1(_pop);
    DeRef(_5815);
    DeRef(_5837);
    DeRef(_5774);
    return 0;
    ;
}


