// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _16validate_current_term(int _tok)
{
    int _tok_type;
    int _3826 = 0;
    int _3816 = 0;
    int _0, _1, _2, _3;
    

    // 	tok[T_SYM] = token_type( tok )
    RefDS(_tok);
    _3816 = _16token_type(_tok);
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _3816;
    DeRef(_1);

    // 	if not term_stack[$][T_ID] then
    _3816 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    _3816 = (int)*(((s1_ptr)_2)->base + _3816);
    RefDS(_3816);
    _0 = _3816;
    _2 = (int)SEQ_PTR(_3816);
    _3816 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3816);
    DeRefDS(_0);
    if (IS_ATOM_INT(_3816)) {
        if (_3816 != 0)
            goto L1;
    }
    else {
        if (DBL_PTR(_3816)->dbl != 0.0)
            goto L1;
    }

    // 		term_stack[$] = tok
    DeRef(_3816);
    _3816 = SEQ_PTR(_7term_stack)->length;
    RefDS(_tok);
    _2 = (int)SEQ_PTR(_7term_stack);
    _2 = (int)(((s1_ptr)_2)->base + _3816);
    _1 = *(int *)_2;
    *(int *)_2 = _tok;
    DeRefDS(_1);
    goto L2;
L1:

    // 		tok_type = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _tok_type = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_tok_type))
        _tok_type = (long)DBL_PTR(_tok_type)->dbl;

    // 		term_stack[$][T_SYM] = TypeLCD( term_stack[$][T_SYM], tok_type )
    DeRef(_3816);
    _3816 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_3816 + ((s1_ptr)_2)->base);
    DeRef(_3826);
    _3826 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    _3826 = (int)*(((s1_ptr)_2)->base + _3826);
    RefDS(_3826);
    _0 = _3826;
    _2 = (int)SEQ_PTR(_3826);
    _3826 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3826);
    DeRefDS(_0);
    Ref(_3826);
    _0 = _3826;
    _3826 = _16TypeLCD(_3826, _tok_type);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _3826;
    DeRef(_1);
L2:

    // end procedure
    DeRefDS(_tok);
    DeRef(_3826);
    DeRef(_3816);
    return 0;
    ;
}


int _16Factor()
{
    int _tok = 0;
    int _id;
    int _n;
    int _scope;
    int _opcode;
    int _e;
    int _save_factors;
    int _save_lhs_subs_level;
    int _minus_term;
    int _sym;
    int _rid;
    int _arg;
    int _seq_of;
    int _routine = 0;
    int _3830 = 0;
    int _3835 = 0;
    int _3842 = 0;
    int _0, _1, _2, _3;
    

    //     factors += 1
    _16factors = _16factors + 1;

    //     tok = next_token()
    _tok = _16next_token();

    //     id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	minus_term = 0
    _minus_term = 0;

    // 	seq_of = 0
    _seq_of = 0;

    //     if id = VARIABLE or id = QUALIFIED_VARIABLE then
    _3830 = (_id == -100);
    if (_3830 != 0) {
        goto L1;
    }
    _3835 = (_id == 515);
L2:
    if (_3835 == 0)
        goto L3;
L1:

    // 		sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 		if UndefinedVar(sym) then
    _0 = _3835;
    _3835 = _16UndefinedVar(_sym);
    DeRef1(_0);
    if (_3835 == 0)
        goto L4;

    // 			return
    DeRef1(_tok);
    DeRef1(_routine);
    DeRef(_3830);
    DeRef(_3842);
    return 0;
L4:

    // 	    if parse_method_stack[$] then
    DeRef1(_3835);
    _3835 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3835 = (int)*(((s1_ptr)_2)->base + _3835);
    if (_3835 == 0)
        goto L5;

    // 			validate_current_term( tok )
    RefDS(_tok);
    _16validate_current_term(_tok);
L5:

    // 		SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3842 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_3842);
    _0 = _3842;
    _2 = (int)SEQ_PTR(_3842);
    _3842 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_3842);
    DeRef1(_0);
    _0 = _3842;
    if (IS_ATOM_INT(_3842)) {
        _3842 = (_3842 | 1);
    }
    else {
        _3842 = binary_op(OR_BITS, _3842, 1);
    }
    DeRef1(_0);
    Ref(_3842);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _3842;
    DeRef(_1);

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 		if tok[T_ID] = DOT_NOTATION then
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3842);
    if (binary_op_a(NOTEQ, _3842, 423))
        goto L6;

    // 			current_instance &= sym
    Append(&_7current_instance, _7current_instance, _sym);

    // 			InitCheck(sym, TRUE)
    _16InitCheck(_sym, 1);

    // 			call_proc( forward_method_func, {tok})
    _0 = _3842;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _3842 = MAKE_SEQ(_1);
    DeRef1(_0);
    _1 = (int)SEQ_PTR(_3842);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method_func].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 			if tok[T_ID] != LEFT_SQUARE then
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3842);
    if (binary_op_a(EQUALS, _3842, -28))
        goto L7;

    // 				putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 				current_instance = current_instance[1..$-1]
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3842);

    // 				return
    DeRef1(_tok);
    DeRef1(_routine);
    DeRef(_3830);
    DeRef(_3835);
    return 0;
L7:

    // 			if parse_method_stack[$] then
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3842 = (int)*(((s1_ptr)_2)->base + _3842);
    if (_3842 == 0)
        goto L8;

    // 				term_stack[$-1][T_SYM] = object_type
    _3842 = SEQ_PTR(_7term_stack)->length;
    _3842 = _3842 - 1;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_3842 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11object_type;
    DeRef(_1);

    // 				parse_method_stack &= 0
    Append(&_7parse_method_stack, _7parse_method_stack, 0);

    // 				minus_term = 1
    _minus_term = 1;

    // 				current_instance = current_instance[1..$-1]
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7current_instance)->length;
    _3830 = _3830 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3830);
L9:
    goto L8;
L6:

    // 			current_sequence = append(current_sequence, sym)
    Append(&_15current_sequence, _15current_sequence, _sym);

    // 			InitCheck(sym, TRUE)
    _16InitCheck(_sym, 1);

    // 			emit_opnd(sym)
    _15emit_opnd(_sym);
L8:

    // 		if sym = left_sym then
    if (_sym != _16left_sym)
        goto LA;

    // 		    lhs_subs_level = 0 -- start counting subscripts
    _16lhs_subs_level = 0;
LA:

    // 		short_circuit -= 1
    _16short_circuit = _16short_circuit - 1;

    // 		if tok[T_ID] = LEFT_SQUARE then
    DeRef1(_3830);
    _2 = (int)SEQ_PTR(_tok);
    _3830 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3830);
    if (binary_op_a(NOTEQ, _3830, -28))
        goto LB;

    // 		if parse_method_stack[$] then
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    if (_3830 == 0)
        goto LC;

    // 			term_stack[$][2] = object_type
    _3830 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_3830 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11object_type;
    DeRef(_1);
LC:

    // 		if is_sequenceof( left_sym ) then
    _0 = _3842;
    _3842 = _11is_sequenceof(_16left_sym);
    DeRef1(_0);
    if (_3842 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_3842) && DBL_PTR(_3842)->dbl == 0.0)
            goto LD;
    }

    // 			current_instance &= left_sym
    Append(&_7current_instance, _7current_instance, _16left_sym);

    // 			seq_of = 1
    _seq_of = 1;
    goto LE;
LD:

    // 		elsif is_sequenceof( sym ) then
    _0 = _3842;
    _3842 = _11is_sequenceof(_sym);
    DeRef1(_0);
    if (_3842 == 0) {
        goto LF;
    }
    else {
        if (!IS_ATOM_INT(_3842) && DBL_PTR(_3842)->dbl == 0.0)
            goto LF;
    }

    // 			current_instance &= sym
    Append(&_7current_instance, _7current_instance, _sym);

    // 			seq_of = 1
    _seq_of = 1;
    goto LE;
LF:
LE:
LB:

    // 		while tok[T_ID] = LEFT_SQUARE do
L10:
    DeRef(_3842);
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3842);
    if (binary_op_a(NOTEQ, _3842, -28))
        goto L11;

    // 		    if lhs_subs_level >= 0 then
    if (_16lhs_subs_level < 0)
        goto L12;

    // 				lhs_subs_level += 1
    _16lhs_subs_level = _16lhs_subs_level + 1;
L12:

    // 		    save_factors = factors
    _save_factors = _16factors;

    // 		    save_lhs_subs_level = lhs_subs_level
    _save_lhs_subs_level = _16lhs_subs_level;

    // 		    parse_method_stack &= 0
    Append(&_7parse_method_stack, _7parse_method_stack, 0);

    // 		    current_instance &= 0
    Append(&_7current_instance, _7current_instance, 0);

    // 		    call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 		    current_instance = current_instance[1..$-1]
    DeRef(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3842);

    // 		    parse_method_stack = parse_method_stack[1..$-1]
    _3842 = SEQ_PTR(_7parse_method_stack)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _3842);

    // 		    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		    if tok[T_ID] = SLICE then
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3842);
    if (binary_op_a(NOTEQ, _3842, 516))
        goto L13;

    // 				call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 				emit_op(RHS_SLICE)
    _15emit_op(46);

    // 				tok_match(RIGHT_SQUARE)
    _16tok_match(-29);

    // 				tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 				exit
    goto L11;
    goto L14;
L13:

    // 				putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 				tok_match(RIGHT_SQUARE)
    _16tok_match(-29);

    // 				current_sequence = current_sequence[1..$-1]
    DeRef(_3842);
    _3842 = SEQ_PTR(_15current_sequence)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_15current_sequence;
    RHS_Slice((s1_ptr)_15current_sequence, 1, _3842);

    // 				emit_op(RHS_SUBS) -- current_sequence will be updated
    _15emit_op(25);
L14:

    // 		    factors = save_factors
    _16factors = _save_factors;

    // 		    lhs_subs_level = save_lhs_subs_level
    _16lhs_subs_level = _save_lhs_subs_level;

    // 		    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		end while
    goto L10;
L11:

    // 		if is_sequenceof( current_instance[$] ) then
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _3842 = (int)*(((s1_ptr)_2)->base + _3842);
    Ref(_3842);
    Ref(_3842);
    _0 = _3842;
    _3842 = _11is_sequenceof(_3842);
    DeRef1(_0);
    if (_3842 == 0) {
        goto L15;
    }
    else {
        if (!IS_ATOM_INT(_3842) && DBL_PTR(_3842)->dbl == 0.0)
            goto L15;
    }

    // 			if tok[T_ID] = DOT_NOTATION then
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3842);
    if (binary_op_a(NOTEQ, _3842, 423))
        goto L16;

    // 				putback({VARIABLE, current_instance[$]})
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _3842 = (int)*(((s1_ptr)_2)->base + _3842);
    Ref(_3842);
    _0 = _3842;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -100;
    ((int *)_2)[2] = _3842;
    Ref(_3842);
    _3842 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_3842);
    _16putback(_3842);

    // 				current_instance = current_instance[1..$-1]
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3842);

    // 				eat_token()
    _16eat_token();

    // 				Factor()
    _16Factor();
    goto L17;
L16:

    // 				putback(tok)
    RefDS(_tok);
    _16putback(_tok);
L18:
    goto L17;
L15:

    // 			putback(tok)
    RefDS(_tok);
    _16putback(_tok);
L17:

    // 		current_sequence = current_sequence[1..$-1]
    DeRef1(_3842);
    _3842 = SEQ_PTR(_15current_sequence)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_15current_sequence;
    RHS_Slice((s1_ptr)_15current_sequence, 1, _3842);

    // 		short_circuit += 1
    _16short_circuit = _16short_circuit + 1;

    // 		if minus_term then
    if (_minus_term == 0)
        goto L19;

    // 			parse_method_stack = parse_method_stack[1..$-1]
    _3842 = SEQ_PTR(_7parse_method_stack)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _3842);
L1A:
    goto L19;
L3:

    //     elsif id = DOLLAR then
    if (_id != -22)
        goto L1B;

    // 		if length(current_sequence) then
    DeRef1(_3842);
    _3842 = SEQ_PTR(_15current_sequence)->length;
    if (_3842 == 0)
        goto L1C;

    // 			if member_stack[$] or current_instance[$] then
    _3842 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _3842 = (int)*(((s1_ptr)_2)->base + _3842);
    Ref(_3842);
    if (IS_ATOM_INT(_3842)) {
        if (_3842 != 0) {
            goto L1D;
        }
    }
    else {
        if (DBL_PTR(_3842)->dbl != 0.0) {
            goto L1D;
        }
    }
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    Ref(_3830);
L1E:
    if (_3830 == 0) {
        goto L1F;
    }
    else {
        if (!IS_ATOM_INT(_3830) && DBL_PTR(_3830)->dbl == 0.0)
            goto L1F;
    }
L1D:

    // 				member_stack &= -0.5
    RefDS(_3926);
    Append(&_7member_stack, _7member_stack, _3926);
    goto L19;
L1F:

    // 				emit_op(DOLLAR)
    _15emit_op(-22);
L20:
    goto L19;
L1C:

    // 		    CompileErr("'$' must only appear between '[' and ']'")
    RefDS(_3928);
    _9CompileErr(_3928);

    // 		    return
    DeRef1(_tok);
    DeRef1(_routine);
    DeRef(_3830);
    DeRef(_3835);
    DeRef(_3842);
    return 0;
L21:
    goto L19;
L1B:

    //     elsif id = ATOM then
    if (_id != 502)
        goto L22;

    // 		emit_opnd(tok[T_SYM])
    DeRef1(_3830);
    _2 = (int)SEQ_PTR(_tok);
    _3830 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3830);
    Ref(_3830);
    _15emit_opnd(_3830);

    // 		if parse_method_stack[$] then
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    if (_3830 == 0)
        goto L19;

    // 			validate_current_term( tok )
    RefDS(_tok);
    _16validate_current_term(_tok);
L23:
    goto L19;
L22:

    //     elsif id = LEFT_BRACE then
    if (_id != -24)
        goto L24;

    // 		if parse_method_stack[$] then
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    if (_3830 == 0)
        goto L25;

    // 			validate_current_term( tok )
    RefDS(_tok);
    _16validate_current_term(_tok);
L25:

    // 		parse_method_stack &= 0
    Append(&_7parse_method_stack, _7parse_method_stack, 0);

    // 		n = Expr_list()
    _n = _16Expr_list();

    // 		tok_match(RIGHT_BRACE)
    _16tok_match(-25);

    // 		op_info1 = n
    _15op_info1 = _n;

    // 		emit_op(RIGHT_BRACE_N)
    _15emit_op(31);

    // 		parse_method_stack = parse_method_stack[1..$-1]
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _3830 = _3830 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _3830);
    goto L19;
L24:

    //     elsif id = STRING then
    if (_id != 503)
        goto L26;

    // 		emit_opnd(tok[T_SYM])
    DeRef1(_3830);
    _2 = (int)SEQ_PTR(_tok);
    _3830 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3830);
    Ref(_3830);
    _15emit_opnd(_3830);

    // 		if parse_method_stack[$] then
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    if (_3830 == 0)
        goto L19;

    // 			validate_current_term( tok )
    RefDS(_tok);
    _16validate_current_term(_tok);
L27:
    goto L19;
L26:

    //     elsif id = LEFT_ROUND then
    if (_id != -26)
        goto L28;

    // 		call_proc(forward_expr, {})
    _0 = (int)_00[_16forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 		tok_match(RIGHT_ROUND)
    _16tok_match(-27);
    goto L19;
L28:

    //     elsif find(id, {r:FUNC, QUALIFIED_FUNC, TYPE, QUALIFIED_TYPE}) then
    _0 = _3830;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 501;
    *((int *)(_2+8)) = 524;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 526;
    _3830 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _3830;
    _3830 = find(_id, _3830);
    DeRef1(_0);
    if (_3830 == 0)
        goto L29;

    // 		add_ref( tok )
    RefDS(_tok);
    _11add_ref(_tok);

    // 		if parse_method_stack[$] then
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    if (_3830 == 0)
        goto L2A;

    // 			validate_current_term( tok )
    RefDS(_tok);
    _16validate_current_term(_tok);
L2A:

    // 		if find( tok[T_SYM], class_table[CLASS_SYM]) then
    DeRef1(_3830);
    _2 = (int)SEQ_PTR(_tok);
    _3830 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3830);
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_7class_table);
    _3842 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_3842);
    _0 = _3842;
    _3842 = find(_3830, _3842);
    DeRef1(_0);
    if (_3842 == 0)
        goto L2B;

    // 			sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    // 			if tok[T_ID] = DOT_NOTATION then
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3842);
    if (binary_op_a(NOTEQ, _3842, 423))
        goto L2C;

    // 				current_instance &= sym
    Append(&_7current_instance, _7current_instance, _sym);

    // 				call_proc( forward_method_func, {tok})
    _0 = _3842;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _3842 = MAKE_SEQ(_1);
    DeRef1(_0);
    _1 = (int)SEQ_PTR(_3842);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method_func].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 				if seq_of then
    if (_seq_of == 0)
        goto L2D;

    // 					seq_of = 0
    _seq_of = 0;

    // 					current_instance = current_instance[1..$-2]
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _3842 = _3842 - 2;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3842);
    goto L2E;
L2D:

    // 					current_instance = current_instance[1..$-1]
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7current_instance)->length;
    _3842 = _3842 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3842);
L2E:

    // 				return
    DeRef1(_tok);
    DeRef1(_routine);
    DeRef(_3830);
    DeRef(_3835);
    DeRef(_3842);
    return 0;
    goto L19;
L2C:

    // 				putback( tok )
    RefDS(_tok);
    _16putback(_tok);

    // 				call_proc( forward_method_func, {{id, sym}})
    DeRef1(_3842);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _id;
    ((int *)_2)[2] = _sym;
    _3842 = MAKE_SEQ(_1);
    _0 = _3842;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_3842);
    *((int *)(_2+4)) = _3842;
    _3842 = MAKE_SEQ(_1);
    DeRef1(_0);
    _1 = (int)SEQ_PTR(_3842);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method_func].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 				return
    DeRef1(_tok);
    DeRef1(_routine);
    DeRefDS(_3842);
    DeRef(_3830);
    DeRef(_3835);
    return 0;
L2F:
    goto L19;
L2B:

    // 			parse_method_stack &= 0
    Append(&_7parse_method_stack, _7parse_method_stack, 0);

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L30;

    // 				if SymTab[tok[T_SYM]][S_OPCODE] = ROUTINE_ID then
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3842);
    _0 = _3842;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3842))
        _3842 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3842)->dbl));
    else
        _3842 = (int)*(((s1_ptr)_2)->base + _3842);
    Ref(_3842);
    DeRef1(_0);
    _0 = _3842;
    _2 = (int)SEQ_PTR(_3842);
    _3842 = (int)*(((s1_ptr)_2)->base + 19);
    Ref(_3842);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _3842, 136))
        goto L31;

    // 					cache_line()
    _16cache_line();

    // 					rid = 1
    _rid = 1;
    goto L32;
L31:

    // 					rid = 0
    _rid = 0;
L33:
    goto L32;
L30:

    // 				rid = 0
    _rid = 0;
L32:

    // 			e = SymTab[tok[T_SYM]][S_EFFECT]
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_tok);
    _3842 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3842);
    _0 = _3842;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3842))
        _3842 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3842)->dbl));
    else
        _3842 = (int)*(((s1_ptr)_2)->base + _3842);
    Ref(_3842);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_3842);
    _e = (int)*(((s1_ptr)_2)->base + 21);
    if (!IS_ATOM_INT(_e))
        _e = (long)DBL_PTR(_e)->dbl;

    // 			if e then
    if (_e == 0)
        goto L34;

    // 			    if e = E_ALL_EFFECT or tok[T_SYM] > left_sym then
    DeRef1(_3842);
    _3842 = (_e == 1073741823);
    if (_3842 != 0) {
        goto L35;
    }
    DeRef1(_3830);
    _2 = (int)SEQ_PTR(_tok);
    _3830 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3830);
    _0 = _3830;
    if (IS_ATOM_INT(_3830)) {
        _3830 = (_3830 > _16left_sym);
    }
    else {
        _3830 = binary_op(GREATER, _3830, _16left_sym);
    }
    DeRef1(_0);
L36:
    if (_3830 == 0) {
        goto L37;
    }
    else {
        if (!IS_ATOM_INT(_3830) && DBL_PTR(_3830)->dbl == 0.0)
            goto L37;
    }
L35:

    // 				side_effect_calls = or_bits(side_effect_calls, e)
    _16side_effect_calls = (_16side_effect_calls | _e);
L37:

    // 			    SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    DeRef1(_3835);
    _2 = (int)SEQ_PTR(_7SymTab);
    _3835 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_3835);
    _0 = _3835;
    _2 = (int)SEQ_PTR(_3835);
    _3835 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3835);
    DeRef1(_0);
    _0 = _3835;
    if (IS_ATOM_INT(_3835)) {
        _3835 = (_3835 | _e);
    }
    else {
        _3835 = binary_op(OR_BITS, _3835, _e);
    }
    DeRef1(_0);
    Ref(_3835);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _3835;
    DeRef(_1);

    // 			    if short_circuit > 0 and short_circuit_B and
    DeRef1(_3835);
    _3835 = (_16short_circuit > 0);
    if (_3835 == 0) {
        _3835 = 0;
        goto L38;
    }
    _3835 = (_16short_circuit_B != 0);
L38:
    if (_3835 == 0) {
        goto L39;
    }
    DeRef1(_3842);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 501;
    ((int *)_2)[2] = 524;
    _3842 = MAKE_SEQ(_1);
    _0 = _3842;
    _3842 = find(_id, _3842);
    DeRef1(_0);
L3A:
    if (_3842 == 0)
        goto L39;

    // 				Warning(sprintf(
    DeRef1(_3842);
    _2 = (int)SEQ_PTR(_7file_name);
    _3842 = (int)*(((s1_ptr)_2)->base + _7current_file_no);
    Ref(_3842);
    DeRef1(_3835);
    _2 = (int)SEQ_PTR(_tok);
    _3835 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3835);
    _0 = _3835;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3835))
        _3835 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3835)->dbl));
    else
        _3835 = (int)*(((s1_ptr)_2)->base + _3835);
    Ref(_3835);
    DeRef1(_0);
    _0 = _3835;
    _2 = (int)SEQ_PTR(_3835);
    _3835 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3835);
    DeRef1(_0);
    _0 = _3835;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3842);
    *((int *)(_2+4)) = _3842;
    *((int *)(_2+8)) = _7line_number;
    Ref(_3835);
    *((int *)(_2+12)) = _3835;
    _3835 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _3835;
    _3835 = EPrintf(-9999999, _3990, _3835);
    DeRef1(_0);
    RefDS(_3835);
    _9Warning(_3835);
L39:
L34:

    // 			tok_match(LEFT_ROUND)
    _16tok_match(-26);

    // 			scope = SymTab[tok[T_SYM]][S_SCOPE]
    DeRef1(_3835);
    _2 = (int)SEQ_PTR(_tok);
    _3835 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3835);
    _0 = _3835;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3835))
        _3835 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3835)->dbl));
    else
        _3835 = (int)*(((s1_ptr)_2)->base + _3835);
    Ref(_3835);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_3835);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    // 			opcode = SymTab[tok[T_SYM]][S_OPCODE]
    DeRef1(_3835);
    _2 = (int)SEQ_PTR(_tok);
    _3835 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3835);
    _0 = _3835;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_3835))
        _3835 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3835)->dbl));
    else
        _3835 = (int)*(((s1_ptr)_2)->base + _3835);
    Ref(_3835);
    DeRef1(_0);
    _2 = (int)SEQ_PTR(_3835);
    _opcode = (int)*(((s1_ptr)_2)->base + 19);
    if (!IS_ATOM_INT(_opcode))
        _opcode = (long)DBL_PTR(_opcode)->dbl;

    // 			ParseArgs(tok[T_SYM])
    DeRef1(_3835);
    _2 = (int)SEQ_PTR(_tok);
    _3835 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3835);
    Ref(_3835);
    _16ParseArgs(_3835);

    // 			parse_method_stack = parse_method_stack[1..$-1]
    DeRef1(_3835);
    _3835 = SEQ_PTR(_7parse_method_stack)->length;
    _3835 = _3835 - 1;
    rhs_slice_target = (object_ptr)&_7parse_method_stack;
    RHS_Slice((s1_ptr)_7parse_method_stack, 1, _3835);

    // 		    if rid then
    if (_rid == 0)
        goto L3B;

    // 		    	arg = Pop()
    _arg = _15Pop();

    // 		    	Push( arg )
    _15Push(_arg);

    // 		    	routine = SymTab[arg][S_OBJ]
    _2 = (int)SEQ_PTR(_7SymTab);
    _3835 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_3835);
    DeRef1(_routine);
    _2 = (int)SEQ_PTR(_3835);
    _routine = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_routine);

    // 		    	if sequence( routine ) then
    DeRef1(_3835);
    _3835 = IS_SEQUENCE(_routine);
    if (_3835 == 0)
        goto L3C;

    // 		    		for i = 1 to length(routine) do
    _3835 = SEQ_PTR(_routine)->length;
    { int _i;
        _i = 1;
L3D:
        if (_i > _3835)
            goto L3E;

        // 		    			if find(routine[i], "@!") then
        DeRef(_3842);
        _2 = (int)SEQ_PTR(_routine);
        _3842 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_3842);
        _0 = _3842;
        _3842 = find(_3842, _4013);
        DeRef(_0);
        if (_3842 == 0)
            goto L3F;

        // 		    				routine[i] = '_'
        _2 = (int)SEQ_PTR(_routine);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _routine = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = 95;
        DeRef(_1);
L3F:

        // 		    		end for
        _i = _i + 1;
        goto L3D;
L3E:
        ;
    }

    // 		    		replace_tokens( length(line_tokens) - 1, length(line_tokens) - 1, '"' & routine & '"' )
    DeRef1(_3842);
    _3842 = SEQ_PTR(_7line_tokens)->length;
    _3842 = _3842 - 1;
    DeRef1(_3835);
    _3835 = SEQ_PTR(_7line_tokens)->length;
    _3835 = _3835 - 1;
    {
        int concat_list[3];

        concat_list[0] = 34;
        concat_list[1] = _routine;
        concat_list[2] = 34;
        Concat_N((object_ptr)&_3830, concat_list, 3);
    }
    RefDS(_3830);
    _16replace_tokens(_3842, _3835, _3830);
L3C:

    // 		    	release_line()
    _16release_line();
L3B:

    // 			if scope = SC_PREDEF then
    if (_scope != 7)
        goto L40;

    // 			    emit_op(opcode)
    _15emit_op(_opcode);
    goto L19;
L40:

    // 			    op_info1 = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _15op_info1 = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_15op_info1))
        _15op_info1 = (long)DBL_PTR(_15op_info1)->dbl;

    // 			    emit_op(r:PROC)
    _15emit_op(27);

    // 			    if not TRANSLATE then 

    // 				if OpTrace then
    if (_7OpTrace == 0)
        goto L19;

    // 				    emit_op(UPDATE_GLOBALS)
    _15emit_op(89);
L41:
L42:
L43:
L44:
    goto L19;
L29:

    // 	elsif id = CLASS then
    if (_id != 421)
        goto L45;

    // 		if parse_method_stack[$] then
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _3830 = (int)*(((s1_ptr)_2)->base + _3830);
    if (_3830 == 0)
        goto L46;

    // 			validate_current_term( tok )
    RefDS(_tok);
    _16validate_current_term(_tok);
    goto L19;
L46:

    // 			CompileErr(sprintf(
    _0 = _3830;
    _3830 = _15LexName(_id);
    DeRef1(_0);
    _0 = _3830;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3830);
    *((int *)(_2+4)) = _3830;
    _3830 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _3830;
    _3830 = EPrintf(-9999999, _4026, _3830);
    DeRef1(_0);
    RefDS(_3830);
    _9CompileErr(_3830);
L47:
    goto L19;
L45:

    // 		CompileErr(sprintf(
    _0 = _3830;
    _3830 = _15LexName(_id);
    DeRef1(_0);
    _0 = _3830;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3830);
    *((int *)(_2+4)) = _3830;
    _3830 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _3830;
    _3830 = EPrintf(-9999999, _4026, _3830);
    DeRef1(_0);
    RefDS(_3830);
    _9CompileErr(_3830);

    // 		return
    DeRef1(_tok);
    DeRef1(_routine);
    DeRefDSi(_3830);
    DeRef(_3835);
    DeRef(_3842);
    return 0;
L19:

    //     if seq_of then
    if (_seq_of == 0)
        goto L48;

    //     	current_instance = current_instance[1..$-1]
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7current_instance)->length;
    _3830 = _3830 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _3830);
L48:

    //     if minus_term = 1 then
    if (_minus_term != 1)
        goto L49;

    // 		if length(term_stack) > 1 then
    DeRef1(_3830);
    _3830 = SEQ_PTR(_7term_stack)->length;
    if (_3830 <= 1)
        goto L4A;
L4A:
L49:

    // end procedure
    DeRef1(_tok);
    DeRef1(_routine);
    DeRef(_3830);
    DeRef(_3835);
    DeRef(_3842);
    return 0;
    ;
}


int _16UFactor()
{
    int _tok = 0;
    int _4039 = 0;
    int _0, _1, _2;
    

    //     tok = next_token()
    _tok = _16next_token();

    //     if tok[T_ID] = MINUS then
    _2 = (int)SEQ_PTR(_tok);
    _4039 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4039);
    if (binary_op_a(NOTEQ, _4039, 10))
        goto L1;

    // 	Factor()
    _16Factor();

    // 	emit_op(UMINUS)
    _15emit_op(12);
    goto L2;
L1:

    //     elsif tok[T_ID] = NOT then
    DeRef(_4039);
    _2 = (int)SEQ_PTR(_tok);
    _4039 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4039);
    if (binary_op_a(NOTEQ, _4039, 7))
        goto L3;

    // 	Factor()
    _16Factor();

    // 	emit_op(NOT)
    _15emit_op(7);
    goto L2;
L3:

    //     elsif tok[T_ID] = PLUS then
    DeRef(_4039);
    _2 = (int)SEQ_PTR(_tok);
    _4039 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4039);
    if (binary_op_a(NOTEQ, _4039, 11))
        goto L4;

    // 	Factor()
    _16Factor();
    goto L2;
L4:

    // 	putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 	Factor()
    _16Factor();
L2:

    // end procedure
    DeRef(_tok);
    DeRef(_4039);
    return 0;
    ;
}


int _16term()
{
    int _tok = 0;
    int _4050 = 0;
    int _4046 = 0;
    int _0, _1, _2;
    

    //     UFactor()   
    _16UFactor();

    //     tok = next_token() 
    _tok = _16next_token();

    //     while tok[T_ID] = MULTIPLY or tok[T_ID] = DIVIDE do
L1:
    DeRef(_4046);
    _2 = (int)SEQ_PTR(_tok);
    _4046 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4046);
    _0 = _4046;
    if (IS_ATOM_INT(_4046)) {
        _4046 = (_4046 == 13);
    }
    else {
        _4046 = binary_op(EQUALS, _4046, 13);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4046)) {
        if (_4046 != 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_4046)->dbl != 0.0) {
            goto L2;
        }
    }
    DeRef(_4050);
    _2 = (int)SEQ_PTR(_tok);
    _4050 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4050);
    _0 = _4050;
    if (IS_ATOM_INT(_4050)) {
        _4050 = (_4050 == 14);
    }
    else {
        _4050 = binary_op(EQUALS, _4050, 14);
    }
    DeRef(_0);
L3:
    if (_4050 <= 0) {
        if (_4050 == 0) {
            goto L4;
        }
        else {
            if (!IS_ATOM_INT(_4050) && DBL_PTR(_4050)->dbl == 0.0)
                goto L4;
        }
    }
L2:

    // 	UFactor() 
    _16UFactor();

    // 	emit_op(tok[T_ID]) 
    DeRef(_4050);
    _2 = (int)SEQ_PTR(_tok);
    _4050 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4050);
    Ref(_4050);
    _15emit_op(_4050);

    // 	tok = next_token() 
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    //     end while
    goto L1;
L4:

    //     return tok
    DeRef(_4050);
    DeRef(_4046);
    return _tok;
    ;
}


int _16aexpr()
{
    int _tok = 0;
    int _id;
    int _4058 = 0;
    int _4054 = 0;
    int _0, _1, _2;
    

    //     tok = term()
    _tok = _16term();

    //     while tok[T_ID] = PLUS or tok[T_ID] = MINUS do
L1:
    DeRef(_4054);
    _2 = (int)SEQ_PTR(_tok);
    _4054 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4054);
    _0 = _4054;
    if (IS_ATOM_INT(_4054)) {
        _4054 = (_4054 == 11);
    }
    else {
        _4054 = binary_op(EQUALS, _4054, 11);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4054)) {
        if (_4054 != 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_4054)->dbl != 0.0) {
            goto L2;
        }
    }
    DeRef(_4058);
    _2 = (int)SEQ_PTR(_tok);
    _4058 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4058);
    _0 = _4058;
    if (IS_ATOM_INT(_4058)) {
        _4058 = (_4058 == 10);
    }
    else {
        _4058 = binary_op(EQUALS, _4058, 10);
    }
    DeRef(_0);
L3:
    if (_4058 <= 0) {
        if (_4058 == 0) {
            goto L4;
        }
        else {
            if (!IS_ATOM_INT(_4058) && DBL_PTR(_4058)->dbl == 0.0)
                goto L4;
        }
    }
L2:

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	tok = term()
    _0 = _tok;
    _tok = _16term();
    DeRefDS(_0);

    // 	emit_op(id) 
    _15emit_op(_id);

    //     end while
    goto L1;
L4:

    //     return tok
    DeRef(_4058);
    DeRef(_4054);
    return _tok;
    ;
}


int _16cexpr()
{
    int _tok = 0;
    int _concat_count;
    int _4062 = 0;
    int _0, _1, _2, _3;
    

    //     tok = aexpr()
    _tok = _16aexpr();

    //     concat_count = 0 
    _concat_count = 0;

    //     while tok[T_ID] = CONCAT do
L1:
    DeRef(_4062);
    _2 = (int)SEQ_PTR(_tok);
    _4062 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4062);
    if (binary_op_a(NOTEQ, _4062, 15))
        goto L2;

    // 	tok = aexpr()
    _0 = _tok;
    _tok = _16aexpr();
    DeRefDS(_0);

    // 	concat_count += 1 
    _concat_count = _concat_count + 1;

    //     end while
    goto L1;
L2:

    //     if concat_count = 1 then
    if (_concat_count != 1)
        goto L3;

    // 	emit_op(CONCAT)
    _15emit_op(15);
    goto L4;
L3:

    //     elsif concat_count > 1 then
    if (_concat_count <= 1)
        goto L5;

    // 	op_info1 = concat_count+1 
    _15op_info1 = _concat_count + 1;

    // 	emit_op(CONCAT_N) 
    _15emit_op(159);
L5:
L4:

    //     if parse_method_stack[$] and concat_count then
    DeRef(_4062);
    _4062 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _4062 = (int)*(((s1_ptr)_2)->base + _4062);
    if (_4062 == 0) {
        goto L6;
    }
L7:
    if (_concat_count == 0)
        goto L6;

    //     	term_stack[current_term][T_SYM] = sequence_type
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_7current_term + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11sequence_type;
    DeRef(_1);
L6:

    //     return tok
    DeRef(_4062);
    return _tok;
    ;
}


int _16rexpr()
{
    int _tok = 0;
    int _id;
    int _sym;
    int _4079 = 0;
    int _4075 = 0;
    int _0, _1, _2, _3;
    

    //     tok = cexpr()
    _tok = _16cexpr();

    //     while tok[T_ID] <= GREATER and tok[T_ID] >= LESS do
L1:
    DeRef(_4075);
    _2 = (int)SEQ_PTR(_tok);
    _4075 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4075);
    _0 = _4075;
    if (IS_ATOM_INT(_4075)) {
        _4075 = (_4075 <= 6);
    }
    else {
        _4075 = binary_op(LESSEQ, _4075, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4075)) {
        if (_4075 == 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_4075)->dbl == 0.0) {
            goto L2;
        }
    }
    DeRef(_4079);
    _2 = (int)SEQ_PTR(_tok);
    _4079 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4079);
    _0 = _4079;
    if (IS_ATOM_INT(_4079)) {
        _4079 = (_4079 >= 1);
    }
    else {
        _4079 = binary_op(GREATEREQ, _4079, 1);
    }
    DeRef(_0);
L3:
    if (_4079 <= 0) {
        if (_4079 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_4079) && DBL_PTR(_4079)->dbl == 0.0)
                goto L2;
        }
    }

    // 		id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 		tok = cexpr()
    _0 = _tok;
    _tok = _16cexpr();
    DeRefDS(_0);

    // 	    if parse_method_stack[$] then
    DeRef(_4079);
    _4079 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _4079 = (int)*(((s1_ptr)_2)->base + _4079);
    if (_4079 == 0)
        goto L4;

    // 	    	sym = term_stack[current_term][T_SYM]
    _2 = (int)SEQ_PTR(_7term_stack);
    _4079 = (int)*(((s1_ptr)_2)->base + _7current_term);
    RefDS(_4079);
    _2 = (int)SEQ_PTR(_4079);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     		while not find( sym, {integer_type, atom_type, object_type, sequence_type}) and
L5:
    _0 = _4079;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _11integer_type;
    *((int *)(_2+8)) = _11atom_type;
    *((int *)(_2+12)) = _11object_type;
    *((int *)(_2+16)) = _11sequence_type;
    _4079 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4079;
    _4079 = find(_sym, _4079);
    DeRefDSi(_0);
    _4079 = (_4079 == 0);
    if (_4079 == 0) {
        goto L6;
    }
    DeRef(_4075);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4075 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4075);
    _0 = _4075;
    _4075 = SEQ_PTR(_4075)->length;
    DeRef(_0);
    _4075 = (_4075 <= 14);
L7:
    if (_4075 == 0)
        goto L6;

    //     			sym = SymTab[sym][S_VTYPE]
    DeRef(_4075);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4075 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4075);
    _2 = (int)SEQ_PTR(_4075);
    _sym = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     		end while
    goto L5;
L6:

    // 	    	if find(sym, {integer_type, atom_type}) then
    DeRef(_4075);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _11integer_type;
    ((int *)_2)[2] = _11atom_type;
    _4075 = MAKE_SEQ(_1);
    _0 = _4075;
    _4075 = find(_sym, _4075);
    DeRefDSi(_0);
    if (_4075 == 0)
        goto L8;

    // 	    		term_stack[current_term][T_SYM] = integer_type
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_7current_term + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11integer_type;
    DeRef(_1);
    goto L9;
L8:

    // 	    	elsif sym = object_type or length(SymTab[sym]) > S_VTYPE then
    DeRef(_4079);
    _4079 = (_sym == _11object_type);
    if (_4079 != 0) {
        goto LA;
    }
    DeRef(_4075);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4075 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4075);
    _0 = _4075;
    _4075 = SEQ_PTR(_4075)->length;
    DeRef(_0);
    _4075 = (_4075 > 14);
LB:
    if (_4075 == 0)
        goto LC;
LA:

    // 	    		term_stack[current_term][T_SYM] = object_type
    _2 = (int)SEQ_PTR(_7term_stack);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7term_stack = MAKE_SEQ(_2);
    }
    _3 = (int)(_7current_term + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _11object_type;
    DeRef(_1);
LC:
L9:
L4:

    // 		emit_op(id)
    _15emit_op(_id);

    //     end while
    goto L1;
L2:

    //     return tok
    DeRef(_4079);
    DeRef(_4075);
    return _tok;
    ;
}


int _16MethodArg(int _sym)
{
    int _ix;
    int _a = 0;
    int _4107 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	ix = find( sym, {integer_type, object_type, atom_type, sequence_type})
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _11integer_type;
    *((int *)(_2+8)) = _11object_type;
    *((int *)(_2+12)) = _11atom_type;
    *((int *)(_2+16)) = _11sequence_type;
    _4107 = MAKE_SEQ(_1);
    _ix = find(_sym, _4107);

    // 	if ix then
    if (_ix == 0)
        goto L1;

    // 		a = "ioas"
    RefDS(_4109);
    _a = _4109;

    // 		return {{a[ix]}}
    DeRefDSi(_4107);
    _2 = (int)SEQ_PTR(_a);
    _4107 = (int)*(((s1_ptr)_2)->base + _ix);
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _4107;
    _4107 = MAKE_SEQ(_1);
    _0 = _4107;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_4107);
    *((int *)(_2+4)) = _4107;
    _4107 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    DeRefDSi(_a);
    return _4107;
L1:

    // 	ix = find( sym, class_table[CLASS_SYM] )
    DeRef(_4107);
    _2 = (int)SEQ_PTR(_7class_table);
    _4107 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4107);
    _ix = find(_sym, _4107);

    // 	if ix then
    if (_ix == 0)
        goto L2;

    // 		return { '@' & class_table[CLASS_NAME][ix] & '@' }
    DeRefDS(_4107);
    _2 = (int)SEQ_PTR(_7class_table);
    _4107 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_4107);
    _0 = _4107;
    _2 = (int)SEQ_PTR(_4107);
    _4107 = (int)*(((s1_ptr)_2)->base + _ix);
    Ref(_4107);
    DeRefDS(_0);
    {
        int concat_list[3];

        concat_list[0] = 64;
        concat_list[1] = _4107;
        concat_list[2] = 64;
        Concat_N((object_ptr)&_4107, concat_list, 3);
    }
    _0 = _4107;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_4107);
    *((int *)(_2+4)) = _4107;
    _4107 = MAKE_SEQ(_1);
    DeRefDS(_0);
    DeRefi(_a);
    return _4107;
    goto L3;
L2:

    // 		return { '!' & SymTab[sym][S_NAME] & '!' }
    DeRef(_4107);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4107 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_4107);
    _0 = _4107;
    _2 = (int)SEQ_PTR(_4107);
    _4107 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4107);
    DeRef(_0);
    {
        int concat_list[3];

        concat_list[0] = 33;
        concat_list[1] = _4107;
        concat_list[2] = 33;
        Concat_N((object_ptr)&_4107, concat_list, 3);
    }
    _0 = _4107;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_4107);
    *((int *)(_2+4)) = _4107;
    _4107 = MAKE_SEQ(_1);
    DeRefDS(_0);
    DeRefi(_a);
    return _4107;
L3:
    ;
}


int _16Expr()
{
    int _tok = 0;
    int _id;
    int _patch;
    int _4125 = 0;
    int _4123 = 0;
    int _0, _1, _2;
    

    //     id = -1
    _id = -1;

    //     patch = 0
    _patch = 0;

    //     while TRUE do 
L1:

    // 	if id != -1 and id != XOR and short_circuit > 0 then
    DeRef(_4123);
    _4123 = (_id != -1);
    if (_4123 == 0) {
        _4123 = 0;
        goto L2;
    }
    DeRef(_4125);
    _4125 = (_id != 154);
    _4123 = (_4125 != 0);
L2:
    if (_4123 == 0) {
        goto L3;
    }
    DeRef(_4123);
    _4123 = (_16short_circuit > 0);
L4:
    if (_4123 == 0)
        goto L3;

    // 	    if id = OR then
    if (_id != 9)
        goto L5;

    // 		emit_op(SC1_OR)
    _15emit_op(145);
    goto L6;
L5:

    // 		emit_op(SC1_AND)
    _15emit_op(143);
L6:

    // 	    patch = length(Code)+1
    DeRef(_4123);
    _4123 = SEQ_PTR(_7Code)->length;
    _patch = _4123 + 1;

    // 	    emit_forward_addr()
    _16emit_forward_addr();

    // 	    short_circuit_B = TRUE
    _16short_circuit_B = 1;
L3:

    // 	if parse_method_stack[$] then
    DeRef(_4123);
    _4123 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _4123 = (int)*(((s1_ptr)_2)->base + _4123);
    if (_4123 == 0)
        goto L7;

    // 		term_stack = append( term_stack, {0,0})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 0;
    _4123 = MAKE_SEQ(_1);
    RefDS(_4123);
    Append(&_7term_stack, _7term_stack, _4123);

    // 		current_term += 1
    _7current_term = _7current_term + 1;
L7:

    // 	tok = rexpr()
    _0 = _tok;
    _tok = _16rexpr();
    DeRef(_0);

    // 	if parse_method_stack[$] = 1 then
    DeRef(_4123);
    _4123 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _4123 = (int)*(((s1_ptr)_2)->base + _4123);
    if (_4123 != 1)
        goto L8;

    // 		method_args[current_method] &= MethodArg( term_stack[$][T_SYM] )
    _4123 = SEQ_PTR(_7term_stack)->length;
    _2 = (int)SEQ_PTR(_7term_stack);
    _4123 = (int)*(((s1_ptr)_2)->base + _4123);
    RefDS(_4123);
    _0 = _4123;
    _2 = (int)SEQ_PTR(_4123);
    _4123 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4123);
    DeRefDS(_0);
    Ref(_4123);
    _0 = _4123;
    _4123 = _16MethodArg(_4123);
    DeRef(_0);
    DeRef(_4125);
    _2 = (int)SEQ_PTR(_7method_args);
    _4125 = (int)*(((s1_ptr)_2)->base + _7current_method);
    Ref(_4125);
    if (IS_SEQUENCE(_4125) && IS_ATOM(_4123)) {
    }
    else if (IS_ATOM(_4125) && IS_SEQUENCE(_4123)) {
        Ref(_4125);
        Prepend(&_4125, _4123, _4125);
    }
    else {
        Concat((object_ptr)&_4125, _4125, (s1_ptr)_4123);
    }
    RefDS(_4125);
    _2 = (int)SEQ_PTR(_7method_args);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7method_args = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _7current_method);
    _1 = *(int *)_2;
    *(int *)_2 = _4125;
    DeRef(_1);

    // 		term_stack = term_stack[1..$-1]
    DeRefDS(_4125);
    _4125 = SEQ_PTR(_7term_stack)->length;
    _4125 = _4125 - 1;
    rhs_slice_target = (object_ptr)&_7term_stack;
    RHS_Slice((s1_ptr)_7term_stack, 1, _4125);

    // 		current_term -= 1
    _7current_term = _7current_term - 1;
    goto L9;
L8:

    // 	elsif parse_method_stack[$] then
    DeRef(_4125);
    _4125 = SEQ_PTR(_7parse_method_stack)->length;
    _2 = (int)SEQ_PTR(_7parse_method_stack);
    _4125 = (int)*(((s1_ptr)_2)->base + _4125);
    if (_4125 == 0)
        goto LA;

    // 		term_stack = term_stack[1..$-1]
    _4125 = SEQ_PTR(_7term_stack)->length;
    _4125 = _4125 - 1;
    rhs_slice_target = (object_ptr)&_7term_stack;
    RHS_Slice((s1_ptr)_7term_stack, 1, _4125);

    // 		current_term -= 1
    _7current_term = _7current_term - 1;
LA:
L9:

    // 	if id != -1 then
    if (_id == -1)
        goto LB;

    // 	    if id != XOR and short_circuit > 0 then
    DeRef(_4125);
    _4125 = (_id != 154);
    if (_4125 == 0) {
        goto LC;
    }
    DeRef(_4123);
    _4123 = (_16short_circuit > 0);
LD:
    if (_4123 == 0)
        goto LC;

    // 		if tok[T_ID] != THEN and tok[T_ID] != DO then
    DeRef(_4123);
    _2 = (int)SEQ_PTR(_tok);
    _4123 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4123);
    _0 = _4123;
    if (IS_ATOM_INT(_4123)) {
        _4123 = (_4123 != 409);
    }
    else {
        _4123 = binary_op(NOTEQ, _4123, 409);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4123)) {
        if (_4123 == 0) {
            goto LE;
        }
    }
    else {
        if (DBL_PTR(_4123)->dbl == 0.0) {
            goto LE;
        }
    }
    DeRef(_4125);
    _2 = (int)SEQ_PTR(_tok);
    _4125 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4125);
    _0 = _4125;
    if (IS_ATOM_INT(_4125)) {
        _4125 = (_4125 != 410);
    }
    else {
        _4125 = binary_op(NOTEQ, _4125, 410);
    }
    DeRef(_0);
LF:
    if (_4125 == 0) {
        goto LE;
    }
    else {
        if (!IS_ATOM_INT(_4125) && DBL_PTR(_4125)->dbl == 0.0)
            goto LE;
    }

    // 		    if id = OR then
    if (_id != 9)
        goto L10;

    // 			emit_op(SC2_OR)
    _15emit_op(146);
    goto L11;
L10:

    // 			emit_op(SC2_AND)
    _15emit_op(144);
L12:
    goto L11;
LE:

    // 		    SC1_type = id -- if/while/elsif must patch
    _16SC1_type = _id;

    // 		    emit_op(SC2_NULL)
    _15emit_op(147);
L11:

    // 		if TRANSLATE then

    // 		backpatch(patch, length(Code)+1)
    DeRef(_4125);
    _4125 = SEQ_PTR(_7Code)->length;
    _4125 = _4125 + 1;
    _15backpatch(_patch, _4125);
    goto L13;
LC:

    // 		emit_op(id)
    _15emit_op(_id);
L13:
LB:

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	if id != OR and id != AND and id != XOR then
    DeRef(_4125);
    _4125 = (_id != 9);
    if (_4125 == 0) {
        _4125 = 0;
        goto L14;
    }
    DeRef(_4123);
    _4123 = (_id != 8);
    _4125 = (_4123 != 0);
L14:
    if (_4125 == 0) {
        goto L1;
    }
    DeRef(_4125);
    _4125 = (_id != 154);
L15:
    if (_4125 == 0)
        goto L1;

    // 	    exit
    goto L16;
L17:

    //     end while
    goto L1;
L16:

    //     putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    //     SC1_patch = patch -- extra line
    _16SC1_patch = _patch;

    // end procedure
    DeRefDS(_tok);
    DeRef(_4125);
    DeRef(_4123);
    return 0;
    ;
}


int _16real_type(int _var)
{
    int _ix;
    int _4176 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    // 	ix = find( var, class_table[CLASS_SYM] )
    _2 = (int)SEQ_PTR(_7class_table);
    _4176 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4176);
    _ix = find(_var, _4176);

    // 	while ix do
L1:
    if (_ix == 0)
        goto L2;

    // 		var = class_table[CLASS_VARTYPE][ix]
    DeRef(_4176);
    _2 = (int)SEQ_PTR(_7class_table);
    _4176 = (int)*(((s1_ptr)_2)->base + 5);
    RefDS(_4176);
    _2 = (int)SEQ_PTR(_4176);
    _var = (int)*(((s1_ptr)_2)->base + _ix);
    if (!IS_ATOM_INT(_var))
        _var = (long)DBL_PTR(_var)->dbl;

    // 		ix = find( var, class_table[CLASS_SYM] )
    DeRefDS(_4176);
    _2 = (int)SEQ_PTR(_7class_table);
    _4176 = (int)*(((s1_ptr)_2)->base + 6);
    RefDS(_4176);
    _ix = find(_var, _4176);

    // 	end while
    goto L1;
L2:

    // 	return var
    DeRef(_4176);
    return _var;
    ;
}


int _16TypeCheck(int _var)
{
    int _which_type;
    int _4198 = 0;
    int _4182 = 0;
    int _0, _1, _2;
    

    //     which_type = real_type( SymTab[var][S_VTYPE] )
    _2 = (int)SEQ_PTR(_7SymTab);
    _4182 = (int)*(((s1_ptr)_2)->base + _var);
    Ref(_4182);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_4182);
    _4182 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_4182);
    DeRef(_0);
    Ref(_4182);
    _which_type = _16real_type(_4182);

    //     if TRANSLATE then

    // 	if OpTypeCheck then
    if (_7OpTypeCheck == 0)
        goto L1;

    // 	    if which_type != object_type then
    if (_which_type == _11object_type)
        goto L2;

    // 		if which_type = integer_type then
    if (_which_type != _11integer_type)
        goto L3;

    // 		    op_info1 = var
    _15op_info1 = _var;

    // 		    emit_op(INTEGER_CHECK)
    _15emit_op(96);
    goto L4;
L3:

    // 		elsif which_type = sequence_type then
    if (_which_type != _11sequence_type)
        goto L5;

    // 		    op_info1 = var
    _15op_info1 = _var;

    // 		    emit_op(SEQUENCE_CHECK)
    _15emit_op(97);
    goto L4;
L5:

    // 		elsif which_type = atom_type then
    if (_which_type != _11atom_type)
        goto L6;

    // 		    op_info1 = var
    _15op_info1 = _var;

    // 		    emit_op(ATOM_CHECK)
    _15emit_op(101);
    goto L4;
L6:

    // 		    if SymTab[SymTab[which_type][S_NEXT]][S_VTYPE] = 
    DeRef(_4182);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4182 = (int)*(((s1_ptr)_2)->base + _which_type);
    Ref(_4182);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_4182);
    _4182 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4182);
    DeRef(_0);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4182))
        _4182 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4182)->dbl));
    else
        _4182 = (int)*(((s1_ptr)_2)->base + _4182);
    Ref(_4182);
    DeRef(_0);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_4182);
    _4182 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_4182);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _4182, _11integer_type))
        goto L7;

    // 			op_info1 = var
    _15op_info1 = _var;

    // 			emit_op(INTEGER_CHECK) -- need integer conversion 
    _15emit_op(96);
L7:

    // 		    emit_opnd(var)
    _15emit_opnd(_var);

    // 		    op_info1 = which_type
    _15op_info1 = _which_type;

    // 		    emit_op(r:PROC)
    _15emit_op(27);

    // 		    emit_op(TYPE_CHECK)
    _15emit_op(65);
L4:
L2:
L1:
L8:

    //     if TRANSLATE or not OpTypeCheck then
    if (0 != 0) {
        goto L9;
    }
    DeRef(_4198);
    _4198 = (_7OpTypeCheck == 0);
LA:
    if (_4198 == 0)
        goto LB;
L9:

    // 	op_info1 = var
    _15op_info1 = _var;

    // 	if which_type = sequence_type or
    DeRef(_4198);
    _4198 = (_which_type == _11sequence_type);
    if (_4198 != 0) {
        goto LC;
    }
    DeRef(_4182);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4182 = (int)*(((s1_ptr)_2)->base + _which_type);
    Ref(_4182);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_4182);
    _4182 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4182);
    DeRef(_0);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4182))
        _4182 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4182)->dbl));
    else
        _4182 = (int)*(((s1_ptr)_2)->base + _4182);
    Ref(_4182);
    DeRef(_0);
    _0 = _4182;
    _2 = (int)SEQ_PTR(_4182);
    _4182 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_4182);
    DeRef(_0);
    _0 = _4182;
    if (IS_ATOM_INT(_4182)) {
        _4182 = (_4182 == _11sequence_type);
    }
    else {
        _4182 = binary_op(EQUALS, _4182, _11sequence_type);
    }
    DeRef(_0);
LD:
    if (_4182 == 0) {
        goto LE;
    }
    else {
        if (!IS_ATOM_INT(_4182) && DBL_PTR(_4182)->dbl == 0.0)
            goto LE;
    }
LC:

    // 	    emit_op(SEQUENCE_CHECK)
    _15emit_op(97);
    goto LF;
LE:

    // 	elsif which_type = integer_type or
    DeRef(_4182);
    _4182 = (_which_type == _11integer_type);
    if (_4182 != 0) {
        goto L10;
    }
    DeRef(_4198);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4198 = (int)*(((s1_ptr)_2)->base + _which_type);
    Ref(_4198);
    _0 = _4198;
    _2 = (int)SEQ_PTR(_4198);
    _4198 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4198);
    DeRef(_0);
    _0 = _4198;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4198))
        _4198 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4198)->dbl));
    else
        _4198 = (int)*(((s1_ptr)_2)->base + _4198);
    Ref(_4198);
    DeRef(_0);
    _0 = _4198;
    _2 = (int)SEQ_PTR(_4198);
    _4198 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_4198);
    DeRef(_0);
    _0 = _4198;
    if (IS_ATOM_INT(_4198)) {
        _4198 = (_4198 == _11integer_type);
    }
    else {
        _4198 = binary_op(EQUALS, _4198, _11integer_type);
    }
    DeRef(_0);
L11:
    if (_4198 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_4198) && DBL_PTR(_4198)->dbl == 0.0)
            goto L12;
    }
L10:

    // 	    emit_op(INTEGER_CHECK)
    _15emit_op(96);
L12:
LF:
LB:

    // end procedure
    DeRef(_4198);
    DeRef(_4182);
    return 0;
    ;
}


int _16Assignment(int _left_var)
{
    int _tok = 0;
    int _subs;
    int _slice;
    int _assign_op;
    int _subs1_patch;
    int _dangerous;
    int _members = 0;
    int _pdec = 0;
    int _cg = 0;
    int _cs = 0;
    int _class;
    int _tok1;
    int _tok2;
    int _len_member_stack;
    int _tokm;
    int _tokn;
    int _mis;
    int _seq_of;
    int _4239 = 0;
    int _4237 = 0;
    int _4213 = 0;
    int _4220 = 0;
    int _0, _1, _2, _3;
    

    // 	seq_of = 0
    _seq_of = 0;

    // 	cg = cg_stack
    RefDS(_15cg_stack);
    _cg = _15cg_stack;

    // 	cs = current_sequence
    RefDS(_15current_sequence);
    _cs = _15current_sequence;

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L1;

    // 		cache_line()
    _16cache_line();
L1:

    //     left_sym = left_var[T_SYM]
    _2 = (int)SEQ_PTR(_left_var);
    _16left_sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_16left_sym))
        _16left_sym = (long)DBL_PTR(_16left_sym)->dbl;

    // 	len_member_stack = length(member_stack)
    _len_member_stack = SEQ_PTR(_7member_stack)->length;

    // 		if UndefinedVar(left_sym) then
    _0 = _4213;
    _4213 = _16UndefinedVar(_16left_sym);
    DeRef1(_0);
    if (_4213 == 0)
        goto L2;

    // 			return
    DeRef1(_left_var);
    DeRef1(_tok);
    DeRef1(_members);
    DeRef1(_pdec);
    DeRef1(_cg);
    DeRef1(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4220);
    return 0;
L2:

    //     if SymTab[left_sym][S_SCOPE] = SC_LOOP_VAR or 
    DeRef1(_4213);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4213 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4213);
    _0 = _4213;
    _2 = (int)SEQ_PTR(_4213);
    _4213 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4213);
    DeRef1(_0);
    _0 = _4213;
    if (IS_ATOM_INT(_4213)) {
        _4213 = (_4213 == 2);
    }
    else {
        _4213 = binary_op(EQUALS, _4213, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_4213)) {
        if (_4213 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4213)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef1(_4220);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4220 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4220);
    _0 = _4220;
    _2 = (int)SEQ_PTR(_4220);
    _4220 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4220);
    DeRef1(_0);
    _0 = _4220;
    if (IS_ATOM_INT(_4220)) {
        _4220 = (_4220 == 4);
    }
    else {
        _4220 = binary_op(EQUALS, _4220, 4);
    }
    DeRef1(_0);
L4:
    if (_4220 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_4220) && DBL_PTR(_4220)->dbl == 0.0)
            goto L5;
    }
L3:

    // 		CompileErr("may not assign to a for-loop variable")
    RefDS(_4223);
    _9CompileErr(_4223);

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L6;

    // 			release_line()
    _16release_line();
L6:

    // 	    return
    DeRef1(_left_var);
    DeRef1(_tok);
    DeRef1(_members);
    DeRef1(_pdec);
    DeRef1(_cg);
    DeRef1(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
    goto L7;
L5:

    //     elsif SymTab[left_sym][S_MODE] = M_CONSTANT then
    DeRef1(_4220);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4220 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4220);
    _0 = _4220;
    _2 = (int)SEQ_PTR(_4220);
    _4220 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4220);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _4220, 2))
        goto L8;

    // 		CompileErr("may not change the value of a constant")
    RefDS(_4227);
    _9CompileErr(_4227);

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L9;

    // 			release_line()
    _16release_line();
L9:

    // 	    return
    DeRef1(_left_var);
    DeRef1(_tok);
    DeRef1(_members);
    DeRef1(_pdec);
    DeRef1(_cg);
    DeRef1(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
    goto L7;
L8:

    //     elsif SymTab[left_sym][S_SCOPE] = SC_LOCAL or 
    DeRef1(_4220);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4220 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4220);
    _0 = _4220;
    _2 = (int)SEQ_PTR(_4220);
    _4220 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4220);
    DeRef1(_0);
    _0 = _4220;
    if (IS_ATOM_INT(_4220)) {
        _4220 = (_4220 == 5);
    }
    else {
        _4220 = binary_op(EQUALS, _4220, 5);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_4220)) {
        if (_4220 != 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_4220)->dbl != 0.0) {
            goto LA;
        }
    }
    DeRef1(_4213);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4213 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4213);
    _0 = _4213;
    _2 = (int)SEQ_PTR(_4213);
    _4213 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4213);
    DeRef1(_0);
    _0 = _4213;
    if (IS_ATOM_INT(_4213)) {
        _4213 = (_4213 == 6);
    }
    else {
        _4213 = binary_op(EQUALS, _4213, 6);
    }
    DeRef1(_0);
LB:
    if (_4213 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_4213) && DBL_PTR(_4213)->dbl == 0.0)
            goto LC;
    }
LA:

    // 		SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_7CurrentSub + ((s1_ptr)_2)->base);
    DeRef1(_4237);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4237 = (int)*(((s1_ptr)_2)->base + _7CurrentSub);
    Ref(_4237);
    _0 = _4237;
    _2 = (int)SEQ_PTR(_4237);
    _4237 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_4237);
    DeRef1(_0);
    DeRef1(_4239);
    _4239 = (_16left_sym % 29);
    _4239 = power(2, _4239);
    _0 = _4239;
    if (IS_ATOM_INT(_4237) && IS_ATOM_INT(_4239)) {
        _4239 = (_4237 | _4239);
    }
    else {
        _4239 = binary_op(OR_BITS, _4237, _4239);
    }
    DeRef1(_0);
    Ref(_4239);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _4239;
    DeRef(_1);
LC:
L7:

    //     SymTab[left_sym][S_USAGE] = or_bits(SymTab[left_sym][S_USAGE], U_WRITTEN)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_16left_sym + ((s1_ptr)_2)->base);
    DeRef1(_4220);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4220 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4220);
    _0 = _4220;
    _2 = (int)SEQ_PTR(_4220);
    _4220 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4220);
    DeRef1(_0);
    _0 = _4220;
    if (IS_ATOM_INT(_4220)) {
        _4220 = (_4220 | 2);
    }
    else {
        _4220 = binary_op(OR_BITS, _4220, 2);
    }
    DeRef1(_0);
    Ref(_4220);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _4220;
    DeRef(_1);

    //     tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef1(_0);

    //     if tok[T_ID] = DOT_NOTATION then
    DeRef1(_4220);
    _2 = (int)SEQ_PTR(_tok);
    _4220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4220);
    if (binary_op_a(NOTEQ, _4220, 423))
        goto LD;

    //    		current_instance &= left_sym
    Append(&_7current_instance, _7current_instance, _16left_sym);

    //     	if preprocess then
    if (_7preprocess == 0)
        goto LE;

    //     		tok1 = length(line_tokens) - 1	
    DeRef1(_4220);
    _4220 = SEQ_PTR(_7line_tokens)->length;
    _tok1 = _4220 - 1;
LE:

    // 	    while tok[T_ID] = DOT_NOTATION do
LF:
    DeRef(_4220);
    _2 = (int)SEQ_PTR(_tok);
    _4220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4220);
    if (binary_op_a(NOTEQ, _4220, 423))
        goto L10;

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 			hide_member[$] &= tok[T_SYM]
    DeRef(_4220);
    _4220 = SEQ_PTR(_7hide_member)->length;
    DeRef(_4237);
    _2 = (int)SEQ_PTR(_tok);
    _4237 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4237);
    DeRef(_4239);
    _2 = (int)SEQ_PTR(_7hide_member);
    _4239 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4239);
    if (IS_SEQUENCE(_4239) && IS_ATOM(_4237)) {
        Ref(_4237);
        Append(&_4239, _4239, _4237);
    }
    else if (IS_ATOM(_4239) && IS_SEQUENCE(_4237)) {
        Ref(_4239);
        Prepend(&_4239, _4237, _4239);
    }
    else {
        Concat((object_ptr)&_4239, _4239, (s1_ptr)_4237);
    }
    RefDS(_4239);
    _2 = (int)SEQ_PTR(_7hide_member);
    _2 = (int)(((s1_ptr)_2)->base + _4220);
    _1 = *(int *)_2;
    *(int *)_2 = _4239;
    DeRef(_1);

    // 			member_stack &= is_member( tok )
    RefDS(_tok);
    _0 = _4239;
    _4239 = _11is_member(_tok);
    DeRefDS(_0);
    Append(&_7member_stack, _7member_stack, _4239);

    // 			if member_stack[$] = 0 then
    _4239 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _4239 = (int)*(((s1_ptr)_2)->base + _4239);
    Ref(_4239);
    if (binary_op_a(NOTEQ, _4239, 0))
        goto L11;

    // 				member_stack = member_stack[1..$-1]
    DeRef(_4239);
    _4239 = SEQ_PTR(_7member_stack)->length;
    _4239 = _4239 - 1;
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _4239);

    // 				call_proc( forward_method, {tok})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _4239 = MAKE_SEQ(_1);
    _1 = (int)SEQ_PTR(_4239);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 				current_instance = current_instance[1..$-1]
    DeRefDS(_4239);
    _4239 = SEQ_PTR(_7current_instance)->length;
    _4239 = _4239 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4239);

    // 				if preprocess then
    if (_7preprocess == 0)
        goto L12;

    // 					release_line()
    _16release_line();
L12:

    // 				return
    DeRefDS(_left_var);
    DeRef(_tok);
    DeRef(_members);
    DeRef(_pdec);
    DeRef(_cg);
    DeRef(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
L11:

    // 			tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 	    end while
    goto LF;
L10:

    //     	if preprocess then
    if (_7preprocess == 0)
        goto L13;

    //     		pdec = SymTab[current_instance[$]][S_NAME]
    DeRef1(_4239);
    _4239 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4239 = (int)*(((s1_ptr)_2)->base + _4239);
    Ref(_4239);
    _0 = _4239;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4239))
        _4239 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4239)->dbl));
    else
        _4239 = (int)*(((s1_ptr)_2)->base + _4239);
    Ref(_4239);
    DeRef1(_0);
    DeRef1(_pdec);
    _2 = (int)SEQ_PTR(_4239);
    _pdec = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_pdec);

    //     		for m = 2 to length(member_stack) do
    DeRef1(_4239);
    _4239 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L14:
        if (_m > _4239)
            goto L15;

        //     			class = member_table[MEMBER_CLASS][member_stack[m]]
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_table);
        _4237 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4237);
        DeRef(_4220);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4220 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4220);
        _2 = (int)SEQ_PTR(_4237);
        if (!IS_ATOM_INT(_4220))
            _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4220)->dbl));
        else
            _class = (int)*(((s1_ptr)_2)->base + _4220);
        if (!IS_ATOM_INT(_class))
            _class = (long)DBL_PTR(_class)->dbl;

        //     			pdec &= sprintf( "[%s_MEMBER_%s]", 
        DeRef(_4220);
        _2 = (int)SEQ_PTR(_7class_table);
        _4220 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_4220);
        _0 = _4220;
        _2 = (int)SEQ_PTR(_4220);
        _4220 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_4220);
        DeRefDS(_0);
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_table);
        _4237 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_4237);
        DeRef(_4213);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4213 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4213);
        _0 = _4213;
        _2 = (int)SEQ_PTR(_4237);
        if (!IS_ATOM_INT(_4213))
            _4213 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4213)->dbl));
        else
            _4213 = (int)*(((s1_ptr)_2)->base + _4213);
        Ref(_4213);
        DeRef(_0);
        _0 = _4213;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _4220;
        Ref(_4220);
        ((int *)_2)[2] = _4213;
        Ref(_4213);
        _4213 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _4213;
        _4213 = EPrintf(-9999999, _4281, _4213);
        DeRefDS(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_4213);

        //     		end for
        _m = _m + 1;
        goto L14;
L15:
        ;
    }

    //     		tok2 = tok1 + (length(member_stack)-1) * 2
    DeRef1(_4213);
    _4213 = SEQ_PTR(_7member_stack)->length;
    _4213 = _4213 - 1;
    _4213 = _4213 + _4213;
    if ((long)((unsigned long)_4213 + (unsigned long)HIGH_BITS) >= 0) 
        _4213 = NewDouble((double)_4213);
    if (IS_ATOM_INT(_4213)) {
        _tok2 = _tok1 + _4213;
    }
    else {
        _tok2 = NewDouble((double)_tok1 + DBL_PTR(_4213)->dbl);
    }
    if (!IS_ATOM_INT(_tok2)) {
        _1 = (long)(DBL_PTR(_tok2)->dbl);
        DeRefDS(_tok2);
        _tok2 = _1;
    }

    //     		replace_tokens( tok1, tok2, pdec )
    RefDS(_pdec);
    _16replace_tokens(_tok1, _tok2, _pdec);
L16:
    goto L13;
LD:

    // 		current_instance &= 0
    Append(&_7current_instance, _7current_instance, 0);
L13:

    //     subs = 0
    _subs = 0;

    //     slice = FALSE
    _slice = 0;

    //     dangerous = FALSE
    _dangerous = 0;

    //     side_effect_calls = 0
    _16side_effect_calls = 0;

    //     if member_stack[$] then
    DeRef1(_4213);
    _4213 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _4213 = (int)*(((s1_ptr)_2)->base + _4213);
    Ref(_4213);
    if (_4213 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_4213) && DBL_PTR(_4213)->dbl == 0.0)
            goto L17;
    }

    //     	emit_opnd( current_instance[$] )
    DeRef1(_4213);
    _4213 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4213 = (int)*(((s1_ptr)_2)->base + _4213);
    Ref(_4213);
    Ref(_4213);
    _15emit_opnd(_4213);

    //     	left_sym = current_instance[$]
    DeRef1(_4213);
    _4213 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _16left_sym = (int)*(((s1_ptr)_2)->base + _4213);
    if (!IS_ATOM_INT(_16left_sym))
        _16left_sym = (long)DBL_PTR(_16left_sym)->dbl;
    goto L18;
L17:

    // 	    emit_opnd(left_sym)    
    _15emit_opnd(_16left_sym);
L18:

    //     current_sequence = append(current_sequence, left_sym)
    Append(&_15current_sequence, _15current_sequence, _16left_sym);

    //     for m = 2 to length(member_stack) do
    DeRef1(_4213);
    _4213 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L19:
        if (_m > _4213)
            goto L1A;

        // 		if lhs_ptr then
        if (_15lhs_ptr == 0)
            goto L1B;

        // 		    current_sequence = current_sequence[1..$-1]
        DeRef(_4237);
        _4237 = SEQ_PTR(_15current_sequence)->length;
        _4237 = _4237 - 1;
        rhs_slice_target = (object_ptr)&_15current_sequence;
        RHS_Slice((s1_ptr)_15current_sequence, 1, _4237);

        // 		    if subs = 1 then
        if (_subs != 1)
            goto L1C;

        // 				subs1_patch = length(Code)+1
        _4237 = SEQ_PTR(_7Code)->length;
        _subs1_patch = _4237 + 1;

        // 				emit_op(LHS_SUBS1) -- creates new current_sequence
        _15emit_op(163);
        goto L1D;
L1C:

        // 				emit_op(LHS_SUBS) -- creates new current_sequence
        _15emit_op(95);
L1D:
L1B:

        // 		subs += 1
        _subs = _subs + 1;

        // 		emit_opnd( member_table[MEMBER_SYM][member_stack[m]] )
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_table);
        _4237 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_4237);
        DeRef(_4220);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4220 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4220);
        _0 = _4220;
        _2 = (int)SEQ_PTR(_4237);
        if (!IS_ATOM_INT(_4220))
            _4220 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4220)->dbl));
        else
            _4220 = (int)*(((s1_ptr)_2)->base + _4220);
        Ref(_4220);
        DeRef(_0);
        Ref(_4220);
        _15emit_opnd(_4220);

        // 		lhs_ptr = TRUE   
        _15lhs_ptr = 1;

        //     end for
        _m = _m + 1;
        goto L19;
L1A:
        ;
    }

    //     while tok[T_ID] = LEFT_SQUARE do
L1E:
    DeRef(_4220);
    _2 = (int)SEQ_PTR(_tok);
    _4220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4220);
    if (binary_op_a(NOTEQ, _4220, -28))
        goto L1F;

    // 		if lhs_ptr then
    if (_15lhs_ptr == 0)
        goto L20;

    // 		    current_sequence = current_sequence[1..$-1]
    DeRef(_4220);
    _4220 = SEQ_PTR(_15current_sequence)->length;
    _4220 = _4220 - 1;
    rhs_slice_target = (object_ptr)&_15current_sequence;
    RHS_Slice((s1_ptr)_15current_sequence, 1, _4220);

    // 		    if subs = 1 then
    if (_subs != 1)
        goto L21;

    // 				subs1_patch = length(Code)+1
    _4220 = SEQ_PTR(_7Code)->length;
    _subs1_patch = _4220 + 1;

    // 				emit_op(LHS_SUBS1) -- creates new current_sequence
    _15emit_op(163);
    goto L22;
L21:

    // 				emit_op(LHS_SUBS) -- creates new current_sequence
    _15emit_op(95);
L22:
L20:

    // 		subs += 1
    _subs = _subs + 1;

    // 		if subs = 1 then
    if (_subs != 1)
        goto L23;

    // 		    InitCheck(left_sym, TRUE) 
    _16InitCheck(_16left_sym, 1);
L23:

    // 		Expr() 
    _16Expr();

    // 		if current_instance[$] then
    DeRef(_4220);
    _4220 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4220 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4220);
    if (_4220 == 0) {
        goto L24;
    }
    else {
        if (!IS_ATOM_INT(_4220) && DBL_PTR(_4220)->dbl == 0.0)
            goto L24;
    }

    // 			member_stack &= - Pop()
    _0 = _4220;
    _4220 = _15Pop();
    DeRef(_0);
    if (_4220 == 0xC0000000)
        _4220 = (int)NewDouble((double)-0xC0000000);
    else
        _4220 = - _4220;
    Ref(_4220);
    Append(&_7member_stack, _7member_stack, _4220);

    // 			Push( - member_stack[$] )
    DeRef(_4220);
    _4220 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _4220 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4220);
    _0 = _4220;
    if (IS_ATOM_INT(_4220)) {
        if (_4220 == 0xC0000000)
            _4220 = (int)NewDouble((double)-0xC0000000);
        else
            _4220 = - _4220;
    }
    else {
        _4220 = unary_op(UMINUS, _4220);
    }
    DeRef(_0);
    Ref(_4220);
    _15Push(_4220);
L24:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		if tok[T_ID] = SLICE then
    DeRef(_4220);
    _2 = (int)SEQ_PTR(_tok);
    _4220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4220);
    if (binary_op_a(NOTEQ, _4220, 516))
        goto L25;

    // 		    Expr()
    _16Expr();

    // 		    slice = TRUE
    _slice = 1;

    // 		    tok_match(RIGHT_SQUARE)
    _16tok_match(-29);

    // 		    tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRefDS(_0);

    // 		    exit  -- no further subs or slices allowed 
    goto L1F;
    goto L26;
L25:

    // 		    putback(tok)
    RefDS(_tok);
    _16putback(_tok);

    // 		    tok_match(RIGHT_SQUARE)
    _16tok_match(-29);
L26:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		lhs_ptr = TRUE
    _15lhs_ptr = 1;

    //     end while
    goto L1E;
L1F:

    //     if tok[T_ID] = DOT_NOTATION then
    DeRef1(_4220);
    _2 = (int)SEQ_PTR(_tok);
    _4220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4220);
    if (binary_op_a(NOTEQ, _4220, 423))
        goto L27;

    // 		if length(member_stack) > 1 then
    DeRef1(_4220);
    _4220 = SEQ_PTR(_7member_stack)->length;
    if (_4220 <= 1)
        goto L28;

    // 			mis = member_is_sequenceof( member_stack[$-1] )
    _4220 = SEQ_PTR(_7member_stack)->length;
    _4220 = _4220 - 1;
    _2 = (int)SEQ_PTR(_7member_stack);
    _4220 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4220);
    Ref(_4220);
    _mis = _11member_is_sequenceof(_4220);
    goto L29;
L28:

    // 			mis = 0		
    _mis = 0;
L29:

    //     	if is_sequenceof( left_sym ) or mis  then
    _0 = _4220;
    _4220 = _11is_sequenceof(_16left_sym);
    DeRef1(_0);
    if (IS_ATOM_INT(_4220)) {
        if (_4220 != 0) {
            goto L2A;
        }
    }
    else {
        if (DBL_PTR(_4220)->dbl != 0.0) {
            goto L2A;
        }
    }
L2B:
    if (_mis == 0)
        goto L2C;
L2A:

    //     		if subs > 1 then
    if (_subs <= 1)
        goto L2D;

    // 				if not mis then
    if (_mis != 0)
        goto L2E;

    // 					current_instance &= 0
    Append(&_7current_instance, _7current_instance, 0);
L2E:

    //     			if previous_op = DOLLAR then
    if (_15previous_op != -22)
        goto L2F;

    //     				Code = Code[1..$-3]
    DeRef1(_4220);
    _4220 = SEQ_PTR(_7Code)->length;
    _4220 = _4220 - 3;
    rhs_slice_target = (object_ptr)&_7Code;
    RHS_Slice((s1_ptr)_7Code, 1, _4220);

    //     				tok2 = Pop()
    _tok2 = _15Pop();
L2F:

    //     			for i = 2 to subs do
    DeRef1(_4220);
    _4220 = _subs;
    { int _i;
        _i = 2;
L30:
        if (_i > _4220)
            goto L31;

        //     				if not mis then
        if (_mis != 0)
            goto L32;

        //     					member_stack &= - Code[$-2]
        DeRef(_4237);
        _4237 = SEQ_PTR(_7Code)->length;
        _4237 = _4237 - 2;
        _2 = (int)SEQ_PTR(_7Code);
        _4237 = (int)*(((s1_ptr)_2)->base + _4237);
        Ref(_4237);
        _0 = _4237;
        if (IS_ATOM_INT(_4237)) {
            if (_4237 == 0xC0000000)
                _4237 = (int)NewDouble((double)-0xC0000000);
            else
                _4237 = - _4237;
        }
        else {
            _4237 = unary_op(UMINUS, _4237);
        }
        DeRef(_0);
        if (IS_SEQUENCE(_7member_stack) && IS_ATOM(_4237)) {
            Ref(_4237);
            Append(&_7member_stack, _7member_stack, _4237);
        }
        else if (IS_ATOM(_7member_stack) && IS_SEQUENCE(_4237)) {
        }
        else {
            Concat((object_ptr)&_7member_stack, _7member_stack, (s1_ptr)_4237);
        }

        //     					current_instance[$] = Code[$-3]
        DeRef(_4237);
        _4237 = SEQ_PTR(_7current_instance)->length;
        DeRef(_4213);
        _4213 = SEQ_PTR(_7Code)->length;
        _4213 = _4213 - 3;
        _2 = (int)SEQ_PTR(_7Code);
        _4213 = (int)*(((s1_ptr)_2)->base + _4213);
        Ref(_4213);
        Ref(_4213);
        _2 = (int)SEQ_PTR(_7current_instance);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _7current_instance = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _4237);
        _1 = *(int *)_2;
        *(int *)_2 = _4213;
        DeRef(_1);
L32:

        // 					Code = Code[1..$-5]    				
        DeRef(_4213);
        _4213 = SEQ_PTR(_7Code)->length;
        _4213 = _4213 - 5;
        rhs_slice_target = (object_ptr)&_7Code;
        RHS_Slice((s1_ptr)_7Code, 1, _4213);

        //     			end for
        _i = _i + 1;
        goto L30;
L31:
        ;
    }

    // 				if not mis then
    if (_mis != 0)
        goto L33;

    // 	    			if previous_op = DOLLAR then
    if (_15previous_op != -22)
        goto L34;

    // 	    				member_stack &= -0.5
    RefDS(_3926);
    Append(&_7member_stack, _7member_stack, _3926);
    goto L35;
L34:

    // 		    			member_stack &= -Pop()
    _0 = _4213;
    _4213 = _15Pop();
    DeRef1(_0);
    if (_4213 == 0xC0000000)
        _4213 = (int)NewDouble((double)-0xC0000000);
    else
        _4213 = - _4213;
    Ref(_4213);
    Append(&_7member_stack, _7member_stack, _4213);
L36:
    goto L35;
L33:

    // 	    			mis = Pop() + Pop()		
    _0 = _4213;
    _4213 = _15Pop();
    DeRef1(_0);
    _0 = _4237;
    _4237 = _15Pop();
    DeRef1(_0);
    _mis = _4213 + _4237;
L35:

    //     			tok2 = Pop()
    _tok2 = _15Pop();
    goto L37;
L2D:

    //     		elsif subs = 1 then
    if (_subs != 1)
        goto L38;

    //     			if previous_op = DOLLAR then
    if (_15previous_op != -22)
        goto L39;

    //     				member_stack &= -0.5
    RefDS(_3926);
    Append(&_7member_stack, _7member_stack, _3926);
    goto L3A;
L39:

    //     				member_stack &= -Pop()	
    _0 = _4237;
    _4237 = _15Pop();
    DeRef1(_0);
    if (_4237 == 0xC0000000)
        _4237 = (int)NewDouble((double)-0xC0000000);
    else
        _4237 = - _4237;
    Ref(_4237);
    Append(&_7member_stack, _7member_stack, _4237);
L3A:

    //     			current_instance &= Pop()
    _0 = _4237;
    _4237 = _15Pop();
    DeRef1(_0);
    Append(&_7current_instance, _7current_instance, _4237);
    goto L37;
L38:

    //     			current_instance &= left_sym	
    Append(&_7current_instance, _7current_instance, _16left_sym);
L37:

    // 	    	if preprocess then
    if (_7preprocess == 0)
        goto L3B;

    // 	    		tok1 = length(line_tokens) - 1	
    DeRef1(_4237);
    _4237 = SEQ_PTR(_7line_tokens)->length;
    _tok1 = _4237 - 1;
L3B:

    // 		    while tok[T_ID] = DOT_NOTATION do
L3C:
    DeRef(_4237);
    _2 = (int)SEQ_PTR(_tok);
    _4237 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4237);
    if (binary_op_a(NOTEQ, _4237, 423))
        goto L3D;

    // 		    	if not var_class( current_instance[$] ) then
    DeRef(_4237);
    _4237 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4237 = (int)*(((s1_ptr)_2)->base + _4237);
    Ref(_4237);
    Ref(_4237);
    _0 = _4237;
    _4237 = _11var_class(_4237);
    DeRef(_0);
    if (_4237 != 0)
        goto L3E;

    // 		    		current_instance[$] = current_sequence[$]
    _4237 = SEQ_PTR(_7current_instance)->length;
    DeRef(_4213);
    _4213 = SEQ_PTR(_15current_sequence)->length;
    _2 = (int)SEQ_PTR(_15current_sequence);
    _4213 = (int)*(((s1_ptr)_2)->base + _4213);
    Ref(_4213);
    Ref(_4213);
    _2 = (int)SEQ_PTR(_7current_instance);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7current_instance = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _4237);
    _1 = *(int *)_2;
    *(int *)_2 = _4213;
    DeRef(_1);
L3E:

    // 				tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 				hide_member[$] &= tok[T_SYM]
    DeRef(_4213);
    _4213 = SEQ_PTR(_7hide_member)->length;
    DeRef(_4237);
    _2 = (int)SEQ_PTR(_tok);
    _4237 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4237);
    DeRef(_4220);
    _2 = (int)SEQ_PTR(_7hide_member);
    _4220 = (int)*(((s1_ptr)_2)->base + _4213);
    Ref(_4220);
    if (IS_SEQUENCE(_4220) && IS_ATOM(_4237)) {
        Ref(_4237);
        Append(&_4220, _4220, _4237);
    }
    else if (IS_ATOM(_4220) && IS_SEQUENCE(_4237)) {
        Ref(_4220);
        Prepend(&_4220, _4237, _4220);
    }
    else {
        Concat((object_ptr)&_4220, _4220, (s1_ptr)_4237);
    }
    RefDS(_4220);
    _2 = (int)SEQ_PTR(_7hide_member);
    _2 = (int)(((s1_ptr)_2)->base + _4213);
    _1 = *(int *)_2;
    *(int *)_2 = _4220;
    DeRef(_1);

    // 				member_stack &= is_member( tok )
    RefDS(_tok);
    _0 = _4220;
    _4220 = _11is_member(_tok);
    DeRefDS(_0);
    Append(&_7member_stack, _7member_stack, _4220);

    // 				if member_stack[$] = 0 then
    _4220 = SEQ_PTR(_7member_stack)->length;
    _2 = (int)SEQ_PTR(_7member_stack);
    _4220 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4220);
    if (binary_op_a(NOTEQ, _4220, 0))
        goto L3F;

    // 					member_stack = member_stack[1..$-1]
    DeRef(_4220);
    _4220 = SEQ_PTR(_7member_stack)->length;
    _4220 = _4220 - 1;
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _4220);

    // 					call_proc( forward_method, {tok})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_tok);
    *((int *)(_2+4)) = _tok;
    _4220 = MAKE_SEQ(_1);
    _1 = (int)SEQ_PTR(_4220);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[_7forward_method].addr;
    Ref(*(int *)(_2+4));
    (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );

    // 					if seq_of then
    if (_seq_of == 0)
        goto L40;

    // 						current_instance = current_instance[1..$-2]
    DeRefDS(_4220);
    _4220 = SEQ_PTR(_7current_instance)->length;
    _4220 = _4220 - 2;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4220);
    goto L41;
L40:

    // 						current_instance = current_instance[1..$-1]
    DeRef(_4220);
    _4220 = SEQ_PTR(_7current_instance)->length;
    _4220 = _4220 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4220);
L41:

    // 					lhs_ptr = FALSE
    _15lhs_ptr = 0;

    // 					if preprocess then
    if (_7preprocess == 0)
        goto L42;

    // 						release_line()
    _16release_line();
L42:

    // 					return
    DeRefDS(_left_var);
    DeRef(_tok);
    DeRef(_members);
    DeRef(_pdec);
    DeRef(_cg);
    DeRef(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
L3F:

    // 				tok = next_token()
    _0 = _tok;
    _tok = _16next_token();
    DeRef(_0);

    // 		    end while
    goto L3C;
L3D:

    // 	    	if preprocess then
    if (_7preprocess == 0)
        goto L43;

    // 	    		pdec = SymTab[current_instance[$]][S_NAME]
    DeRef1(_4220);
    _4220 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4220 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4220);
    _0 = _4220;
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!IS_ATOM_INT(_4220))
        _4220 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4220)->dbl));
    else
        _4220 = (int)*(((s1_ptr)_2)->base + _4220);
    Ref(_4220);
    DeRef1(_0);
    DeRef1(_pdec);
    _2 = (int)SEQ_PTR(_4220);
    _pdec = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_pdec);

    // 	    		tokm = tok1 - 2
    _tokm = _tok1 - 2;

    // 	    		for m = 2 to length(member_stack) do
    DeRef1(_4220);
    _4220 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L44:
        if (_m > _4220)
            goto L45;

        // 	    			if member_stack[m] > 0 then
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4237 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4237);
        if (binary_op_a(LESSEQ, _4237, 0))
            goto L46;

        // 		    			class = member_table[MEMBER_CLASS][member_stack[m]]
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_table);
        _4237 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4237);
        DeRef(_4213);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4213 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4213);
        _2 = (int)SEQ_PTR(_4237);
        if (!IS_ATOM_INT(_4213))
            _class = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4213)->dbl));
        else
            _class = (int)*(((s1_ptr)_2)->base + _4213);
        if (!IS_ATOM_INT(_class))
            _class = (long)DBL_PTR(_class)->dbl;

        // 		    			pdec &= sprintf( "[%s_MEMBER_%s]", 
        DeRef(_4213);
        _2 = (int)SEQ_PTR(_7class_table);
        _4213 = (int)*(((s1_ptr)_2)->base + 1);
        RefDS(_4213);
        _0 = _4213;
        _2 = (int)SEQ_PTR(_4213);
        _4213 = (int)*(((s1_ptr)_2)->base + _class);
        Ref(_4213);
        DeRefDS(_0);
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_table);
        _4237 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_4237);
        DeRef(_4239);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4239 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4239);
        _0 = _4239;
        _2 = (int)SEQ_PTR(_4237);
        if (!IS_ATOM_INT(_4239))
            _4239 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4239)->dbl));
        else
            _4239 = (int)*(((s1_ptr)_2)->base + _4239);
        Ref(_4239);
        DeRef(_0);
        _0 = _4239;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _4213;
        Ref(_4213);
        ((int *)_2)[2] = _4239;
        Ref(_4239);
        _4239 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _4239;
        _4239 = EPrintf(-9999999, _4281, _4239);
        DeRefDS(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_4239);

        // 		    			tokn += 2
        _tokn = _tokn + 2;
        goto L47;
L46:

        // 						tokn = tokm
        _tokn = _tokm;

        // 						pdec &= token_text(tokn)
        _0 = _4239;
        _4239 = _16token_text(_tokn);
        DeRef(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_4239);

        // 						while line_tokens[tokn][T_ID] != RIGHT_SQUARE do
L48:
        DeRef(_4239);
        _2 = (int)SEQ_PTR(_7line_tokens);
        _4239 = (int)*(((s1_ptr)_2)->base + _tokn);
        RefDS(_4239);
        _0 = _4239;
        _2 = (int)SEQ_PTR(_4239);
        _4239 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_4239);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _4239, -29))
            goto L49;

        // 							tokn += 1
        _tokn = _tokn + 1;

        // 							pdec &= token_text(tokn)
        _0 = _4239;
        _4239 = _16token_text(_tokn);
        DeRef(_0);
        Concat((object_ptr)&_pdec, _pdec, (s1_ptr)_4239);

        // 						end while
        goto L48;
L49:

        // 						tokm = tokn
        _tokm = _tokn;

        // 						tok1 -= 3
        _tok1 = _tok1 - 3;
L47:

        // 	    		end for
        _m = _m + 1;
        goto L44;
L45:
        ;
    }

    // 				tok2 = tokn --tok1 + (length(member_stack)-1) * 2
    _tok2 = _tokn;

    // 				replace_tokens( tok1, tok2, pdec )
    RefDS(_pdec);
    _16replace_tokens(_tok1, _tok2, _pdec);
L43:

    // 	    	emit_opnd( current_instance[$] )
    DeRef1(_4239);
    _4239 = SEQ_PTR(_7current_instance)->length;
    _2 = (int)SEQ_PTR(_7current_instance);
    _4239 = (int)*(((s1_ptr)_2)->base + _4239);
    Ref(_4239);
    Ref(_4239);
    _15emit_opnd(_4239);

    // 	    	for m = 2 to length(member_stack) do
    DeRef1(_4239);
    _4239 = SEQ_PTR(_7member_stack)->length;
    { int _m;
        _m = 2;
L4A:
        if (_m > _4239)
            goto L4B;

        // 	    		if member_stack[m] > 0 then
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4237 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4237);
        if (binary_op_a(LESSEQ, _4237, 0))
            goto L4C;

        // 	    			emit_opnd( member_table[MEMBER_SYM][member_stack[m]])
        DeRef(_4237);
        _2 = (int)SEQ_PTR(_7member_table);
        _4237 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_4237);
        DeRef(_4213);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4213 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4213);
        _0 = _4213;
        _2 = (int)SEQ_PTR(_4237);
        if (!IS_ATOM_INT(_4213))
            _4213 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4213)->dbl));
        else
            _4213 = (int)*(((s1_ptr)_2)->base + _4213);
        Ref(_4213);
        DeRef(_0);
        Ref(_4213);
        _15emit_opnd(_4213);
        goto L4D;
L4C:

        // 	    		elsif integer( member_stack[m] ) then
        DeRef(_4213);
        _2 = (int)SEQ_PTR(_7member_stack);
        _4213 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4213);
        _0 = _4213;
        if (IS_ATOM_INT(_4213))
            _4213 = 1;
        else if (IS_ATOM_DBL(_4213))
            _4213 = IS_ATOM_INT(DoubleToInt(_4213));
        else
            _4213 = 0;
        DeRef(_0);
        if (_4213 == 0)
            goto L4E;

        // 	    			emit_opnd( -member_stack[m] )
        _2 = (int)SEQ_PTR(_7member_stack);
        _4213 = (int)*(((s1_ptr)_2)->base + _m);
        Ref(_4213);
        _0 = _4213;
        if (IS_ATOM_INT(_4213)) {
            if (_4213 == 0xC0000000)
                _4213 = (int)NewDouble((double)-0xC0000000);
            else
                _4213 = - _4213;
        }
        else {
            _4213 = unary_op(UMINUS, _4213);
        }
        DeRef(_0);
        Ref(_4213);
        _15emit_opnd(_4213);
        goto L4D;
L4E:

        // 	    			emit_op( DOLLAR )
        _15emit_op(-22);
L4D:

        // 			    if subs = 1 then
        if (_subs != 1)
            goto L4F;

        // 					subs1_patch = length(Code)+1
        DeRef(_4213);
        _4213 = SEQ_PTR(_7Code)->length;
        _subs1_patch = _4213 + 1;

        // 					emit_op(LHS_SUBS1) -- creates new current_sequence
        _15emit_op(163);
        goto L50;
L4F:

        // 			    elsif m < length(member_stack) then
        DeRef(_4213);
        _4213 = SEQ_PTR(_7member_stack)->length;
        if (_m >= _4213)
            goto L51;

        // 					emit_op(LHS_SUBS) -- creates new current_sequence
        _15emit_op(95);
L51:
L50:

        // 			    subs += 1
        _subs = _subs + 1;

        // 	    	end for
        _m = _m + 1;
        goto L4A;
L4B:
        ;
    }
    goto L52;
L2C:

    // 		    lhs_ptr = FALSE
    _15lhs_ptr = 0;

    // 			if preprocess then
    if (_7preprocess == 0)
        goto L53;

    // 				release_line()
    _16release_line();
L53:

    // 	    	return
    DeRef1(_left_var);
    DeRef1(_tok);
    DeRef1(_members);
    DeRef1(_pdec);
    DeRef1(_cg);
    DeRef1(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
L52:
L27:

    //     lhs_ptr = FALSE
    _15lhs_ptr = 0;

    //     assign_op = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _assign_op = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_assign_op))
        _assign_op = (long)DBL_PTR(_assign_op)->dbl;

    //     if not find(assign_op, {EQUALS, PLUS_EQUALS, MINUS_EQUALS, MULTIPLY_EQUALS, 
    _0 = _4213;
    _1 = NewS1(6);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 3;
    *((int *)(_2+8)) = 518;
    *((int *)(_2+12)) = 519;
    *((int *)(_2+16)) = 520;
    *((int *)(_2+20)) = 521;
    *((int *)(_2+24)) = 522;
    _4213 = MAKE_SEQ(_1);
    DeRef1(_0);
    _0 = _4213;
    _4213 = find(_assign_op, _4213);
    DeRef1(_0);
    if (_4213 != 0)
        goto L54;

    // 		CompileErr("Syntax error - expected to see =, +=, -=, *=, /= or &=")
    RefDS(_4470);
    _9CompileErr(_4470);

    // 		if preprocess then
    if (_7preprocess == 0)
        goto L55;

    // 			release_line()
    _16release_line();
L55:

    // 		return
    DeRef1(_left_var);
    DeRef1(_tok);
    DeRef1(_members);
    DeRef1(_pdec);
    DeRef1(_cg);
    DeRef1(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
L54:

    //     member_stack &= 0
    Append(&_7member_stack, _7member_stack, 0);

    //     if subs = 0 then
    if (_subs != 0)
        goto L56;

    // 	if assign_op = EQUALS then
    if (_assign_op != 3)
        goto L57;

    // 	    Expr() -- RHS expression
    _16Expr();

    // 	    InitCheck(left_sym, FALSE)
    _16InitCheck(_16left_sym, 0);
    goto L58;
L57:

    // 	    InitCheck(left_sym, TRUE)
    _16InitCheck(_16left_sym, 1);

    // 	    SymTab[left_sym][S_USAGE] = or_bits(SymTab[left_sym][S_USAGE], U_READ)
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_16left_sym + ((s1_ptr)_2)->base);
    DeRef1(_4239);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4239 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4239);
    _0 = _4239;
    _2 = (int)SEQ_PTR(_4239);
    _4239 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4239);
    DeRef1(_0);
    _0 = _4239;
    if (IS_ATOM_INT(_4239)) {
        _4239 = (_4239 | 1);
    }
    else {
        _4239 = binary_op(OR_BITS, _4239, 1);
    }
    DeRef1(_0);
    Ref(_4239);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _4239;
    DeRef(_1);

    // 	    emit_opnd(left_sym)
    _15emit_opnd(_16left_sym);

    // 	    Expr() -- RHS expression
    _16Expr();

    // 	    emit_assign_op(assign_op)
    _15emit_assign_op(_assign_op);
L58:

    // 	emit_op(ASSIGN)
    _15emit_op(18);

    // 	TypeCheck(left_sym)
    _16TypeCheck(_16left_sym);
    goto L59;
L56:

    // 	factors = 0
    _16factors = 0;

    // 	lhs_subs_level = -1
    _16lhs_subs_level = -1;

    // 	Expr() -- RHS expression
    _16Expr();

    // 	if subs > 1 then
    if (_subs <= 1)
        goto L5A;

    // 	    if SymTab[left_sym][S_SCOPE] != SC_PRIVATE and
    DeRef1(_4239);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4239 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4239);
    _0 = _4239;
    _2 = (int)SEQ_PTR(_4239);
    _4239 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4239);
    DeRef1(_0);
    _0 = _4239;
    if (IS_ATOM_INT(_4239)) {
        _4239 = (_4239 != 3);
    }
    else {
        _4239 = binary_op(NOTEQ, _4239, 3);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_4239)) {
        if (_4239 == 0) {
            goto L5B;
        }
    }
    else {
        if (DBL_PTR(_4239)->dbl == 0.0) {
            goto L5B;
        }
    }
    DeRef1(_4237);
    _4237 = (_16left_sym % 29);
    _4237 = power(2, _4237);
    _0 = _4237;
    if (IS_ATOM_INT(_4237)) {
        _4237 = (_16side_effect_calls & _4237);
    }
    else {
        temp_d.dbl = (double)_16side_effect_calls;
        _4237 = Dand_bits(&temp_d, DBL_PTR(_4237));
    }
    DeRef1(_0);
L5C:
    if (_4237 == 0) {
        goto L5B;
    }
    else {
        if (!IS_ATOM_INT(_4237) && DBL_PTR(_4237)->dbl == 0.0)
            goto L5B;
    }

    // 		dangerous = TRUE
    _dangerous = 1;
L5B:

    // 	    if factors = 1 and 
    DeRef1(_4237);
    _4237 = (_16factors == 1);
    if (_4237 == 0) {
        _4237 = 0;
        goto L5D;
    }
    DeRef1(_4239);
    _4239 = (_16lhs_subs_level >= 0);
    _4237 = (_4239 != 0);
L5D:
    if (_4237 == 0) {
        goto L5E;
    }
    DeRef1(_4237);
    _4237 = _subs + _slice;
    if ((long)((unsigned long)_4237 + (unsigned long)HIGH_BITS) >= 0) 
        _4237 = NewDouble((double)_4237);
    _0 = _4237;
    if (IS_ATOM_INT(_4237)) {
        _4237 = (_16lhs_subs_level < _4237);
    }
    else {
        _4237 = ((double)_16lhs_subs_level < DBL_PTR(_4237)->dbl);
    }
    DeRef1(_0);
L5F:
    if (_4237 == 0)
        goto L5E;

    // 		dangerous = TRUE  
    _dangerous = 1;
L5E:

    // 	    if dangerous then
    if (_dangerous == 0)
        goto L60;

    // 		backpatch(subs1_patch, LHS_SUBS1_COPY)
    _15backpatch(_subs1_patch, 168);
L60:
L5A:

    // 	if slice then 
    if (_slice == 0)
        goto L61;

    // 	    if assign_op != EQUALS then
    if (_assign_op == 3)
        goto L62;

    // 		if subs = 1 then
    if (_subs != 1)
        goto L63;

    // 		    emit_op(ASSIGN_OP_SLICE)
    _15emit_op(152);
    goto L64;
L63:

    // 		    emit_op(PASSIGN_OP_SLICE)
    _15emit_op(167);
L64:

    // 		emit_assign_op(assign_op)
    _15emit_assign_op(_assign_op);
L62:

    // 	    if subs = 1 then
    if (_subs != 1)
        goto L65;

    // 		emit_op(ASSIGN_SLICE)
    _15emit_op(45);
    goto L66;
L65:

    // 		emit_op(PASSIGN_SLICE)
    _15emit_op(165);
L67:
    goto L66;
L61:

    // 	    if assign_op = EQUALS then
    if (_assign_op != 3)
        goto L68;

    // 		if subs = 1 then
    if (_subs != 1)
        goto L69;

    // 		    emit_op(ASSIGN_SUBS)
    _15emit_op(16);
    goto L6A;
L69:

    // 		    emit_op(PASSIGN_SUBS)
    _15emit_op(164);
L6B:
    goto L6A;
L68:

    // 		if subs = 1 then
    if (_subs != 1)
        goto L6C;

    // 		    emit_op(ASSIGN_OP_SUBS)
    _15emit_op(151);
    goto L6D;
L6C:

    // 		    emit_op(PASSIGN_OP_SUBS)
    _15emit_op(166);
L6D:

    // 		emit_assign_op(assign_op)
    _15emit_assign_op(_assign_op);

    // 		if subs = 1 then
    if (_subs != 1)
        goto L6E;

    // 		    emit_op(ASSIGN_SUBS2)
    _15emit_op(150);
    goto L6F;
L6E:

    // 		    emit_op(PASSIGN_SUBS)
    _15emit_op(164);
L6F:
L6A:
L66:

    // 	if subs > 1 then
    if (_subs <= 1)
        goto L70;

    // 	    if dangerous then
    if (_dangerous == 0)
        goto L71;

    // 		emit_opnd(left_sym)
    _15emit_opnd(_16left_sym);

    // 		emit_opnd(lhs_subs1_copy_temp) -- will be freed 
    _15emit_opnd(_15lhs_subs1_copy_temp);

    // 		emit_op(ASSIGN)
    _15emit_op(18);
    goto L72;
L71:

    // 		TempFree(lhs_subs1_copy_temp)
    _15TempFree(_15lhs_subs1_copy_temp);
L72:
L70:

    // 	if OpTypeCheck and SymTab[left_sym][S_VTYPE] != sequence_type then
    if (_7OpTypeCheck == 0) {
        goto L73;
    }
    DeRef1(_4239);
    _2 = (int)SEQ_PTR(_7SymTab);
    _4239 = (int)*(((s1_ptr)_2)->base + _16left_sym);
    Ref(_4239);
    _0 = _4239;
    _2 = (int)SEQ_PTR(_4239);
    _4239 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_4239);
    DeRef1(_0);
    _0 = _4239;
    if (IS_ATOM_INT(_4239)) {
        _4239 = (_4239 != _11sequence_type);
    }
    else {
        _4239 = binary_op(NOTEQ, _4239, _11sequence_type);
    }
    DeRef1(_0);
L74:
    if (_4239 == 0) {
        goto L73;
    }
    else {
        if (!IS_ATOM_INT(_4239) && DBL_PTR(_4239)->dbl == 0.0)
            goto L73;
    }

    // 	    TypeCheck(left_sym)
    _16TypeCheck(_16left_sym);
L73:
L59:

    //     current_sequence = current_sequence[1..$-1]
    DeRef1(_4239);
    _4239 = SEQ_PTR(_15current_sequence)->length;
    _4239 = _4239 - 1;
    rhs_slice_target = (object_ptr)&_15current_sequence;
    RHS_Slice((s1_ptr)_15current_sequence, 1, _4239);

    //     current_instance = current_instance[1..$-1]
    _4239 = SEQ_PTR(_7current_instance)->length;
    _4239 = _4239 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4239);

    //     member_stack = member_stack[1..len_member_stack]
    rhs_slice_target = (object_ptr)&_7member_stack;
    RHS_Slice((s1_ptr)_7member_stack, 1, _len_member_stack);

    // 	if preprocess then
    if (_7preprocess == 0)
        goto L75;

    // 		release_line()
    _16release_line();
L75:

    //     if not TRANSLATE then

    // 	if OpTrace then 
    if (_7OpTrace == 0)
        goto L76;

    // 	    emit_op(DISPLAY_VAR)
    _15emit_op(87);

    // 	    emit_addr(left_sym)
    _15emit_addr(_16left_sym);
L76:
L77:

    //     if seq_of then
    if (_seq_of == 0)
        goto L78;

    // 	    current_instance = current_instance[1..$-1]
    DeRef1(_4239);
    _4239 = SEQ_PTR(_7current_instance)->length;
    _4239 = _4239 - 1;
    rhs_slice_target = (object_ptr)&_7current_instance;
    RHS_Slice((s1_ptr)_7current_instance, 1, _4239);

    // 	    seq_of = Pop()
    _seq_of = _15Pop();
L78:

    // 	cg_stack = cg
    RefDS(_cg);
    DeRef1(_15cg_stack);
    _15cg_stack = _cg;

    // 	current_sequence = cs
    RefDS(_cs);
    DeRef1(_15current_sequence);
    _15current_sequence = _cs;

    // end procedure
    DeRef1(_left_var);
    DeRef1(_tok);
    DeRef1(_members);
    DeRef1(_pdec);
    DeRef1(_cg);
    DeRef1(_cs);
    DeRef(_4239);
    DeRef(_4237);
    DeRef(_4213);
    DeRef(_4220);
    return 0;
    ;
}


