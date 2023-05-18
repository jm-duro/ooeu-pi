// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

int _12NameSpace_declaration(int _sym)
{
    int _h;
    int _2506 = 0;
    int _2514 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    //     DefinedYet(sym)
    _11DefinedYet(_sym);

    //     if find(SymTab[sym][S_SCOPE], {SC_GLOBAL, SC_PREDEF}) then
    _2 = (int)SEQ_PTR(_7SymTab);
    _2506 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2506);
    _0 = _2506;
    _2 = (int)SEQ_PTR(_2506);
    _2506 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2506);
    DeRef(_0);
    _0 = _2506;
    _2506 = find(_2506, _2508);
    DeRef(_0);
    if (_2506 == 0)
        goto L1;

    // 	h = SymTab[sym][S_HASHVAL]
    _2 = (int)SEQ_PTR(_7SymTab);
    _2506 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2506);
    _2 = (int)SEQ_PTR(_2506);
    _h = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	sym = NewEntry(SymTab[sym][S_NAME], 0, 0, VARIABLE, h, buckets[h], 0) 
    DeRef(_2506);
    _2 = (int)SEQ_PTR(_7SymTab);
    _2506 = (int)*(((s1_ptr)_2)->base + _sym);
    Ref(_2506);
    _0 = _2506;
    _2 = (int)SEQ_PTR(_2506);
    _2506 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_2506);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_11buckets);
    _2514 = (int)*(((s1_ptr)_2)->base + _h);
    Ref(_2514);
    Ref(_2506);
    Ref(_2514);
    _sym = _11NewEntry(_2506, 0, 0, -100, _h, _2514, 0);

    // 	buckets[h] = sym
    _2 = (int)SEQ_PTR(_11buckets);
    _2 = (int)(((s1_ptr)_2)->base + _h);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);
L1:

    //     SymTab[sym][S_SCOPE] = SC_LOCAL
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
    *(int *)_2 = 5;
    DeRef(_1);

    //     SymTab[sym][S_MODE] = M_CONSTANT
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

    //     SymTab[sym][S_TOKEN] = NAMESPACE -- [obj] will get the file number referred-to
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
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = 523;
    DeRef(_1);

    //     if TRANSLATE then

    //     return sym
    DeRef(_2506);
    DeRef(_2514);
    return _sym;
    ;
}


int _12StringToken()
{
    int _ch;
    int _m;
    int _gtext = 0;
    int _2523;
    int _2526;
    int _0, _1, _2;
    

    //     ch = getch()
    _ch = _12getch();

    //     while ch = ' ' or ch = '\t' do
L1:
    _2523 = (_ch == 32);
    if (_2523 != 0) {
        goto L2;
    }
    _2526 = (_ch == 9);
L3:
    if (_2526 == 0)
        goto L4;
L2:

    // 	ch = getch()
    _ch = _12getch();

    //     end while
    goto L1;
L4:

    //     gtext = ""
    RefDS(_39);
    DeRefi(_gtext);
    _gtext = _39;

    //     while not find(ch,  {' ', '\t', '\n', '\r', END_OF_FILE_CHAR}) do 
L5:
    _2526 = find(_ch, _2528);
    if (_2526 != 0)
        goto L6;

    // 	gtext &= ch
    Append(&_gtext, _gtext, _ch);

    // 	ch = getch()
    _ch = _12getch();

    //     end while
    goto L5;
L6:

    //     ungetch()
    _12ungetch();

    //     m = match("--", gtext)
    _m = e_match(_2533, _gtext);

    //     if m then
    if (_m == 0)
        goto L7;

    // 	gtext = gtext[1..m-1]
    _2526 = _m - 1;
    rhs_slice_target = (object_ptr)&_gtext;
    RHS_Slice((s1_ptr)_gtext, 1, _2526);

    // 	if ch = ' ' or ch = '\t' then
    _2526 = (_ch == 32);
    if (_2526 != 0) {
        goto L8;
    }
    _2523 = (_ch == 9);
L9:
    if (_2523 == 0)
        goto LA;
L8:

    // 	    read_line()
    _12read_line();
LA:
L7:

    //     return gtext
    return _gtext;
    ;
}


int _12IncludeScan()
{
    int _ch;
    int _gtext = 0;
    int _s = 0;
    int _2543 = 0;
    int _2540 = 0;
    int _0, _1, _2;
    

    //     ch = getch()
    _ch = _12getch();

    //     while ch = ' ' or ch = '\t' do
L1:
    DeRef(_2540);
    _2540 = (_ch == 32);
    if (_2540 != 0) {
        goto L2;
    }
    DeRef(_2543);
    _2543 = (_ch == 9);
L3:
    if (_2543 == 0)
        goto L4;
L2:

    // 	ch = getch()
    _ch = _12getch();

    //     end while
    goto L1;
L4:

    //     gtext = ""
    RefDS(_39);
    DeRefi(_gtext);
    _gtext = _39;

    //     if ch = '"' then
    if (_ch != 34)
        goto L5;

    // 	ch = getch()
    _ch = _12getch();

    // 	while not find(ch, {'\n', '\r', '"', END_OF_FILE_CHAR}) do         
L6:
    DeRef(_2543);
    _2543 = find(_ch, _2547);
    if (_2543 != 0)
        goto L7;

    // 	    if ch = '\\' then
    if (_ch != 92)
        goto L8;

    // 		ch = EscapeChar(getch())
    _2543 = _12getch();
    _ch = _12EscapeChar(_2543);
L8:

    // 	    gtext &= ch
    Append(&_gtext, _gtext, _ch);

    // 	    ch = getch()
    _ch = _12getch();

    // 	end while
    goto L6;
L7:

    // 	if ch != '"' then
    if (_ch == 34)
        goto L9;

    // 	    CompileErr("missing closing quote on file name")
    RefDS(_2556);
    _9CompileErr(_2556);
LA:
    goto L9;
L5:

    // 	while not find(ch, {' ', '\t', '\n', '\r', END_OF_FILE_CHAR}) do  
LB:
    DeRef(_2543);
    _2543 = find(_ch, _2528);
    if (_2543 != 0)
        goto LC;

    // 	    gtext &= ch
    Append(&_gtext, _gtext, _ch);

    // 	    ch = getch()
    _ch = _12getch();

    // 	end while
    goto LB;
LC:

    // 	ungetch()
    _12ungetch();
L9:

    //     if length(gtext) = 0 then
    DeRef(_2543);
    _2543 = SEQ_PTR(_gtext)->length;
    if (_2543 != 0)
        goto LD;

    // 	CompileErr("file name is missing")
    RefDS(_2563);
    _9CompileErr(_2563);
LD:

    //     new_include_name = gtext  
    RefDS(_gtext);
    DeRef(_12new_include_name);
    _12new_include_name = _gtext;

    //     ch = getch()
    _ch = _12getch();

    //     while ch = ' ' or ch = '\t' do
LE:
    DeRef(_2543);
    _2543 = (_ch == 32);
    if (_2543 != 0) {
        goto LF;
    }
    DeRef(_2540);
    _2540 = (_ch == 9);
L10:
    if (_2540 == 0)
        goto L11;
LF:

    // 	ch = getch()
    _ch = _12getch();

    //     end while   
    goto LE;
L11:

    //     new_include_space = 0
    _12new_include_space = 0;

    //     if ch = 'a' then
    if (_ch != 97)
        goto L12;

    // 	ch = getch()
    _ch = _12getch();

    // 	if ch = 's' then
    if (_ch != 115)
        goto L13;

    // 	    ch = getch()
    _ch = _12getch();

    // 	    if ch = ' ' or ch = '\t' then
    DeRef(_2540);
    _2540 = (_ch == 32);
    if (_2540 != 0) {
        goto L14;
    }
    DeRef(_2543);
    _2543 = (_ch == 9);
L15:
    if (_2543 == 0)
        goto L16;
L14:

    // 		ch = getch()
    _ch = _12getch();

    // 		while ch = ' ' or ch = '\t' do
L17:
    DeRef(_2543);
    _2543 = (_ch == 32);
    if (_2543 != 0) {
        goto L18;
    }
    DeRef(_2540);
    _2540 = (_ch == 9);
L19:
    if (_2540 == 0)
        goto L1A;
L18:

    // 		    ch = getch()
    _ch = _12getch();

    // 		end while
    goto L17;
L1A:

    // 		if char_class[ch] = LETTER then
    DeRef(_2540);
    _2 = (int)SEQ_PTR(_12char_class);
    _2540 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_2540 != -2)
        goto L1B;

    // 		    gtext = {ch}
    _0 = _gtext;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _ch;
    _gtext = MAKE_SEQ(_1);
    DeRefi(_0);

    // 		    ch = getch()
    _ch = _12getch();

    // 		    while char_class[ch] = LETTER or
L1C:
    DeRef(_2540);
    _2 = (int)SEQ_PTR(_12char_class);
    _2540 = (int)*(((s1_ptr)_2)->base + _ch);
    _2540 = (_2540 == -2);
    if (_2540 != 0) {
        _2540 = 1;
        goto L1D;
    }
    DeRef(_2543);
    _2 = (int)SEQ_PTR(_12char_class);
    _2543 = (int)*(((s1_ptr)_2)->base + _ch);
    _2543 = (_2543 == -7);
    _2540 = (_2543 != 0);
L1D:
    if (_2540 != 0) {
        goto L1E;
    }
    DeRef(_2540);
    _2540 = (_ch == 95);
L1F:
    if (_2540 == 0)
        goto L20;
L1E:

    // 			gtext &= ch
    Append(&_gtext, _gtext, _ch);

    // 			ch = getch()
    _ch = _12getch();

    // 		    end while
    goto L1C;
L20:

    // 		    ungetch()
    _12ungetch();

    // 		    s = keyfind(gtext, -1)
    RefDS(_gtext);
    _0 = _s;
    _s = _11keyfind(_gtext, -1);
    DeRef(_0);

    // 		    if not find(s[T_ID], {VARIABLE, r:FUNC, TYPE, r:PROC}) then
    DeRef(_2540);
    _2 = (int)SEQ_PTR(_s);
    _2540 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2540);
    _0 = _2543;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    _2543 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _2543;
    _2543 = find(_2540, _2543);
    DeRefDSi(_0);
    if (_2543 != 0)
        goto L21;

    // 			CompileErr("a new namespace identifier is expected here")
    RefDS(_2599);
    _9CompileErr(_2599);
L21:

    // 		    new_include_space = NameSpace_declaration(s[T_SYM])
    DeRef(_2543);
    _2 = (int)SEQ_PTR(_s);
    _2543 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2543);
    Ref(_2543);
    _0 = _12NameSpace_declaration(_2543);
    _12new_include_space = _0;
    goto L22;
L1B:

    // 		    CompileErr("missing namespace qualifier")
    RefDS(_2602);
    _9CompileErr(_2602);
L23:
    goto L22;
L16:

    // 		CompileErr("improper syntax for include-as")
    RefDS(_2603);
    _9CompileErr(_2603);
L24:
    goto L22;
L13:

    // 	    CompileErr("improper syntax for include-as")
    RefDS(_2603);
    _9CompileErr(_2603);
L25:
    goto L22;
L12:

    // 	ungetch()
    _12ungetch();
L22:

    //     start_include = TRUE -- let scanner know
    _12start_include = 1;

    // end procedure
    DeRefi(_gtext);
    DeRef(_s);
    DeRef(_2543);
    DeRef(_2540);
    return 0;
    ;
}


