// Euphoria To C version 3.1.1
#include "/home/pi/Téléchargements/euphoria/include/euphoria.h"
#include "main-.h"

main0()
{
    int _877 = 0;
    int _879 = 0;
    int _881 = 0;
    int _883 = 0;
    int _885 = 0;
    int _887 = 0;
    int _889 = 0;
    int _891 = 0;
    int _893 = 0;
    int _895 = 0;
    int _897 = 0;
    int _899 = 0;
    int _901 = 0;
    int _903 = 0;
    int _905 = 0;
    int _907 = 0;
    int _909 = 0;
    int _911 = 0;
    int _913 = 0;
    int _915 = 0;
    int _917 = 0;
    int _919 = 0;
    int _921 = 0;
    int _923 = 0;
    int _925 = 0;
    int _927 = 0;
    int _929 = 0;
    int _931 = 0;
    int _933 = 0;
    int _935 = 0;
    int _937 = 0;
    int _939 = 0;
    int _941 = 0;
    int _943 = 0;
    int _945 = 0;
    int _947 = 0;
    int _949 = 0;
    int _951 = 0;
    int _953 = 0;
    int _955 = 0;
    int _957 = 0;
    int _959 = 0;
    int _961 = 0;
    int _963 = 0;
    int _965 = 0;
    int _967 = 0;
    int _969 = 0;
    int _971 = 0;
    int _973 = 0;
    int _975 = 0;
    int _977 = 0;
    int _979 = 0;
    int _981 = 0;
    int _983 = 0;
    int _985 = 0;
    int _987 = 0;
    int _989 = 0;
    int _991 = 0;
    int _993 = 0;
    int _995 = 0;
    int _997 = 0;
    int _999 = 0;
    int _1001 = 0;
    int _1003 = 0;
    int _875 = 0;
    int _873 = 0;
    int _871 = 0;
    int _869 = 0;
    int _867 = 0;
    int _865 = 0;
    int _863 = 0;
    int _861 = 0;
    int _859 = 0;
    int _857 = 0;
    int _855 = 0;
    int _853 = 0;
    int _851 = 0;
    int _849 = 0;
    int _847 = 0;
    int _845 = 0;
    int _843 = 0;
    int _841 = 0;
    int _839 = 0;
    int _837 = 0;
    int _835 = 0;
    int _833 = 0;
    int _831 = 0;
    int _829 = 0;
    int _827 = 0;
    int _825 = 0;
    int _823 = 0;
    int _821 = 0;
    int _819 = 0;
    int _817 = 0;
    int _815 = 0;
    int _813 = 0;
    int _811 = 0;
    int _809 = 0;
    int _807 = 0;
    int _805 = 0;
    int _803 = 0;
    int _801 = 0;
    int _799 = 0;
    int _152 = 0;
    int _0, _1, _2, _3;
    
    

    // keylist = append(keylist, {"_toplevel_", SC_PREDEF, r:PROC, 0, 0, E_ALL_EFFECT})
    _1 = NewS1(6);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_1005);
    *((int *)(_2+4)) = _1005;
    *((int *)(_2+8)) = 7;
    *((int *)(_2+12)) = 27;
    *((int *)(_2+16)) = 0;
    *((int *)(_2+20)) = 0;
    *((int *)(_2+24)) = 1073741823;
    _1003 = MAKE_SEQ(_1);
    RefDS(_1003);
    Append(&_10keylist, _10keylist, _1003);

    // keylist = append(keylist, {"_eval_", SC_PREDEF, r:PROC, 0, 0, E_ALL_EFFECT})
    _0 = _1003;
    _1 = NewS1(6);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_1008);
    *((int *)(_2+4)) = _1008;
    *((int *)(_2+8)) = 7;
    *((int *)(_2+12)) = 27;
    *((int *)(_2+16)) = 0;
    *((int *)(_2+20)) = 0;
    *((int *)(_2+24)) = 1073741823;
    _1003 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_1003);
    Append(&_10keylist, _10keylist, _1003);

    // buckets = repeat(0, NBUCKETS)
    DeRef1(_11buckets);
    _11buckets = Repeat(0, 2003);

    // e_routine = {}
    RefDS(_39);
    DeRef1(_11e_routine);
    _11e_routine = _39;

    // literal_init = 0
    _11literal_init = 0;

    // lastintval = {}
    RefDS(_39);
    DeRef1(_11lastintval);
    _11lastintval = _39;

    // lastintsym = {}
    RefDS(_39);
    DeRef1(_11lastintsym);
    _11lastintsym = _39;

    // last_sym = 0
    _11last_sym = 0;
    _11BLANK_ENTRY = Repeat(0, 5);
    DeRef1(_1003);
    _1003 = (0 != 0 || 0 != 0);
    if (_1003 <= INT15 && _1003 >= -INT15)
        _1003 = 500 * _1003;
    else
        _1003 = NewDouble(500 * (double)_1003);
    if (IS_ATOM_INT(_1003)) {
        _11SEARCH_LIMIT = 20 + _1003;
        if ((long)((unsigned long)_11SEARCH_LIMIT + (unsigned long)HIGH_BITS) >= 0) 
            _11SEARCH_LIMIT = NewDouble((double)_11SEARCH_LIMIT);
    }
    else {
        _11SEARCH_LIMIT = NewDouble((double)20 + DBL_PTR(_1003)->dbl);
    }

    // temps_allocated = 0
    _11temps_allocated = 0;

    // start_include = FALSE
    _12start_include = 0;

    // LastLineNumber = -1     
    _12LastLineNumber = -1;

    // shebang = 0
    DeRef1(_12shebang);
    _12shebang = 0;

    // all_source = {}
    RefDS(_39);
    DeRef1(_12all_source);
    _12all_source = _39;

    // current_source_next = SOURCE_CHUNK -- forces the first allocation
    _12current_source_next = 10000;

    // if platform() = LINUX then

    //     SLASH='/'
    _13SLASH = 47;
    goto LB;
LC:

    //     SLASH='\\'
    _13SLASH = 92;
LB:

    // my_dir = DEFAULT  -- it's better not to use routine_id() here,
    _13my_dir = -2;

    // trace_called = FALSE
    _15trace_called = 0;

    // last_routine_id = 0
    _15last_routine_id = 0;

    // max_params = 0
    _15max_params = 0;

    // last_max_params = 0
    _15last_max_params = 0;

    // previous_op = -1  
    _15previous_op = -1;

    // current_sequence = {}
    RefDS(_39);
    DeRef1(_15current_sequence);
    _15current_sequence = _39;

    // lhs_ptr = FALSE
    _15lhs_ptr = 0;

    // assignable = FALSE         
    _15assignable = 0;
    DeRef1(_1003);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 8;
    ((int *)_2)[2] = _2604;
    RefDS(_2604);
    _1003 = MAKE_SEQ(_1);
    DeRef1(_1001);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _2606;
    RefDS(_2606);
    _1001 = MAKE_SEQ(_1);
    DeRef1(_999);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = _2608;
    RefDS(_2608);
    _999 = MAKE_SEQ(_1);
    DeRef1(_997);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 404;
    ((int *)_2)[2] = _2610;
    RefDS(_2610);
    _997 = MAKE_SEQ(_1);
    DeRef1(_995);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -23;
    ((int *)_2)[2] = _2612;
    RefDS(_2612);
    _995 = MAKE_SEQ(_1);
    DeRef1(_993);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -30;
    ((int *)_2)[2] = _2614;
    RefDS(_2614);
    _993 = MAKE_SEQ(_1);
    DeRef1(_991);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 15;
    ((int *)_2)[2] = _2616;
    RefDS(_2616);
    _991 = MAKE_SEQ(_1);
    DeRef1(_989);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 416;
    ((int *)_2)[2] = _2618;
    RefDS(_2618);
    _989 = MAKE_SEQ(_1);
    DeRef1(_987);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 14;
    ((int *)_2)[2] = _2620;
    RefDS(_2620);
    _987 = MAKE_SEQ(_1);
    DeRef1(_985);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 410;
    ((int *)_2)[2] = _2622;
    RefDS(_2622);
    _985 = MAKE_SEQ(_1);
    DeRef1(_983);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 23;
    ((int *)_2)[2] = _2624;
    RefDS(_2624);
    _983 = MAKE_SEQ(_1);
    DeRef1(_981);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 413;
    ((int *)_2)[2] = _2626;
    RefDS(_2626);
    _981 = MAKE_SEQ(_1);
    DeRef1(_979);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 402;
    ((int *)_2)[2] = _2628;
    RefDS(_2628);
    _979 = MAKE_SEQ(_1);
    DeRef1(_977);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -21;
    ((int *)_2)[2] = _2630;
    RefDS(_2630);
    _977 = MAKE_SEQ(_1);
    DeRef1(_975);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 155;
    ((int *)_2)[2] = _2632;
    RefDS(_2632);
    _975 = MAKE_SEQ(_1);
    DeRef1(_973);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 61;
    ((int *)_2)[2] = _2634;
    RefDS(_2634);
    _973 = MAKE_SEQ(_1);
    DeRef1(_971);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 21;
    ((int *)_2)[2] = _2636;
    RefDS(_2636);
    _971 = MAKE_SEQ(_1);
    DeRef1(_969);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 501;
    ((int *)_2)[2] = _2638;
    RefDS(_2638);
    _969 = MAKE_SEQ(_1);
    DeRef1(_967);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 406;
    ((int *)_2)[2] = _2640;
    RefDS(_2640);
    _967 = MAKE_SEQ(_1);
    DeRef1(_965);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 411;
    ((int *)_2)[2] = _2642;
    RefDS(_2642);
    _965 = MAKE_SEQ(_1);
    DeRef1(_963);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 6;
    ((int *)_2)[2] = _2644;
    RefDS(_2644);
    _963 = MAKE_SEQ(_1);
    DeRef1(_961);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 2;
    ((int *)_2)[2] = _2646;
    RefDS(_2646);
    _961 = MAKE_SEQ(_1);
    DeRef1(_959);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 20;
    ((int *)_2)[2] = _2648;
    RefDS(_2648);
    _959 = MAKE_SEQ(_1);
    DeRef1(_957);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -20;
    ((int *)_2)[2] = _2650;
    RefDS(_2650);
    _957 = MAKE_SEQ(_1);
    DeRef1(_955);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 417;
    ((int *)_2)[2] = _2652;
    RefDS(_2652);
    _955 = MAKE_SEQ(_1);
    DeRef1(_953);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -24;
    ((int *)_2)[2] = _2654;
    RefDS(_2654);
    _953 = MAKE_SEQ(_1);
    DeRef1(_951);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -26;
    ((int *)_2)[2] = _2656;
    RefDS(_2656);
    _951 = MAKE_SEQ(_1);
    DeRef1(_949);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -28;
    ((int *)_2)[2] = _2658;
    RefDS(_2658);
    _949 = MAKE_SEQ(_1);
    DeRef1(_947);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _2660;
    RefDS(_2660);
    _947 = MAKE_SEQ(_1);
    DeRef1(_945);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 5;
    ((int *)_2)[2] = _2662;
    RefDS(_2662);
    _945 = MAKE_SEQ(_1);
    DeRef1(_943);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 10;
    ((int *)_2)[2] = _2664;
    RefDS(_2664);
    _943 = MAKE_SEQ(_1);
    DeRef1(_941);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 13;
    ((int *)_2)[2] = _2666;
    RefDS(_2666);
    _941 = MAKE_SEQ(_1);
    DeRef1(_939);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 523;
    ((int *)_2)[2] = _2668;
    RefDS(_2668);
    _939 = MAKE_SEQ(_1);
    DeRef1(_937);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -6;
    ((int *)_2)[2] = _2670;
    RefDS(_2670);
    _937 = MAKE_SEQ(_1);
    DeRef1(_935);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 7;
    ((int *)_2)[2] = _2672;
    RefDS(_2672);
    _935 = MAKE_SEQ(_1);
    DeRef1(_933);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 4;
    ((int *)_2)[2] = _2674;
    RefDS(_2674);
    _933 = MAKE_SEQ(_1);
    DeRef1(_931);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 9;
    ((int *)_2)[2] = _2676;
    RefDS(_2676);
    _931 = MAKE_SEQ(_1);
    DeRef1(_929);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 11;
    ((int *)_2)[2] = _2678;
    RefDS(_2678);
    _929 = MAKE_SEQ(_1);
    DeRef1(_927);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 27;
    ((int *)_2)[2] = _2680;
    RefDS(_2680);
    _927 = MAKE_SEQ(_1);
    DeRef1(_925);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 405;
    ((int *)_2)[2] = _2682;
    RefDS(_2682);
    _925 = MAKE_SEQ(_1);
    DeRef1(_923);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 515;
    ((int *)_2)[2] = _2684;
    RefDS(_2684);
    _923 = MAKE_SEQ(_1);
    DeRef1(_921);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 524;
    ((int *)_2)[2] = _2638;
    RefDS(_2638);
    _921 = MAKE_SEQ(_1);
    DeRef1(_919);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 525;
    ((int *)_2)[2] = _2680;
    RefDS(_2680);
    _919 = MAKE_SEQ(_1);
    DeRef1(_917);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 526;
    ((int *)_2)[2] = _2688;
    RefDS(_2688);
    _917 = MAKE_SEQ(_1);
    DeRef1(_915);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -25;
    ((int *)_2)[2] = _2690;
    RefDS(_2690);
    _915 = MAKE_SEQ(_1);
    DeRef1(_913);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -27;
    ((int *)_2)[2] = _2692;
    RefDS(_2692);
    _913 = MAKE_SEQ(_1);
    DeRef1(_911);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -29;
    ((int *)_2)[2] = _2694;
    RefDS(_2694);
    _911 = MAKE_SEQ(_1);
    DeRef1(_909);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 412;
    ((int *)_2)[2] = _2696;
    RefDS(_2696);
    _909 = MAKE_SEQ(_1);
    DeRef1(_907);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 516;
    ((int *)_2)[2] = _2698;
    RefDS(_2698);
    _907 = MAKE_SEQ(_1);
    DeRef1(_905);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 503;
    ((int *)_2)[2] = _2700;
    RefDS(_2700);
    _905 = MAKE_SEQ(_1);
    DeRef1(_903);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 403;
    ((int *)_2)[2] = _2702;
    RefDS(_2702);
    _903 = MAKE_SEQ(_1);
    DeRef1(_901);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 409;
    ((int *)_2)[2] = _2704;
    RefDS(_2704);
    _901 = MAKE_SEQ(_1);
    DeRef1(_899);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 504;
    ((int *)_2)[2] = _2688;
    RefDS(_2688);
    _899 = MAKE_SEQ(_1);
    DeRef1(_897);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 415;
    ((int *)_2)[2] = _2707;
    RefDS(_2707);
    _897 = MAKE_SEQ(_1);
    DeRef1(_895);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -100;
    ((int *)_2)[2] = _2684;
    RefDS(_2684);
    _895 = MAKE_SEQ(_1);
    DeRef1(_893);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 419;
    ((int *)_2)[2] = _2710;
    RefDS(_2710);
    _893 = MAKE_SEQ(_1);
    DeRef1(_891);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 420;
    ((int *)_2)[2] = _2712;
    RefDS(_2712);
    _891 = MAKE_SEQ(_1);
    DeRef1(_889);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 47;
    ((int *)_2)[2] = _2714;
    RefDS(_2714);
    _889 = MAKE_SEQ(_1);
    DeRef1(_887);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 63;
    ((int *)_2)[2] = _2716;
    RefDS(_2716);
    _887 = MAKE_SEQ(_1);
    DeRef1(_885);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 421;
    ((int *)_2)[2] = _2718;
    RefDS(_2718);
    _885 = MAKE_SEQ(_1);
    DeRef1(_883);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 423;
    ((int *)_2)[2] = _2720;
    RefDS(_2720);
    _883 = MAKE_SEQ(_1);
    DeRef1(_881);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 424;
    ((int *)_2)[2] = _2722;
    RefDS(_2722);
    _881 = MAKE_SEQ(_1);
    DeRef1(_879);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 175;
    ((int *)_2)[2] = _990;
    RefDS(_990);
    _879 = MAKE_SEQ(_1);
    DeRef1(_877);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 176;
    ((int *)_2)[2] = _990;
    RefDS(_990);
    _877 = MAKE_SEQ(_1);
    _1 = NewS1(64);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_1003);
    *((int *)(_2+4)) = _1003;
    RefDS(_1001);
    *((int *)(_2+8)) = _1001;
    RefDS(_999);
    *((int *)(_2+12)) = _999;
    RefDS(_997);
    *((int *)(_2+16)) = _997;
    RefDS(_995);
    *((int *)(_2+20)) = _995;
    RefDS(_993);
    *((int *)(_2+24)) = _993;
    RefDS(_991);
    *((int *)(_2+28)) = _991;
    RefDS(_989);
    *((int *)(_2+32)) = _989;
    RefDS(_987);
    *((int *)(_2+36)) = _987;
    RefDS(_985);
    *((int *)(_2+40)) = _985;
    RefDS(_983);
    *((int *)(_2+44)) = _983;
    RefDS(_981);
    *((int *)(_2+48)) = _981;
    RefDS(_979);
    *((int *)(_2+52)) = _979;
    RefDS(_977);
    *((int *)(_2+56)) = _977;
    RefDS(_975);
    *((int *)(_2+60)) = _975;
    RefDS(_973);
    *((int *)(_2+64)) = _973;
    RefDS(_971);
    *((int *)(_2+68)) = _971;
    RefDS(_969);
    *((int *)(_2+72)) = _969;
    RefDS(_967);
    *((int *)(_2+76)) = _967;
    RefDS(_965);
    *((int *)(_2+80)) = _965;
    RefDS(_963);
    *((int *)(_2+84)) = _963;
    RefDS(_961);
    *((int *)(_2+88)) = _961;
    RefDS(_959);
    *((int *)(_2+92)) = _959;
    RefDS(_957);
    *((int *)(_2+96)) = _957;
    RefDS(_955);
    *((int *)(_2+100)) = _955;
    RefDS(_953);
    *((int *)(_2+104)) = _953;
    RefDS(_951);
    *((int *)(_2+108)) = _951;
    RefDS(_949);
    *((int *)(_2+112)) = _949;
    RefDS(_947);
    *((int *)(_2+116)) = _947;
    RefDS(_945);
    *((int *)(_2+120)) = _945;
    RefDS(_943);
    *((int *)(_2+124)) = _943;
    RefDS(_941);
    *((int *)(_2+128)) = _941;
    RefDS(_939);
    *((int *)(_2+132)) = _939;
    RefDS(_937);
    *((int *)(_2+136)) = _937;
    RefDS(_935);
    *((int *)(_2+140)) = _935;
    RefDS(_933);
    *((int *)(_2+144)) = _933;
    RefDS(_931);
    *((int *)(_2+148)) = _931;
    RefDS(_929);
    *((int *)(_2+152)) = _929;
    RefDS(_927);
    *((int *)(_2+156)) = _927;
    RefDS(_925);
    *((int *)(_2+160)) = _925;
    RefDS(_923);
    *((int *)(_2+164)) = _923;
    RefDS(_921);
    *((int *)(_2+168)) = _921;
    RefDS(_919);
    *((int *)(_2+172)) = _919;
    RefDS(_917);
    *((int *)(_2+176)) = _917;
    RefDS(_915);
    *((int *)(_2+180)) = _915;
    RefDS(_913);
    *((int *)(_2+184)) = _913;
    RefDS(_911);
    *((int *)(_2+188)) = _911;
    RefDS(_909);
    *((int *)(_2+192)) = _909;
    RefDS(_907);
    *((int *)(_2+196)) = _907;
    RefDS(_905);
    *((int *)(_2+200)) = _905;
    RefDS(_903);
    *((int *)(_2+204)) = _903;
    RefDS(_901);
    *((int *)(_2+208)) = _901;
    RefDS(_899);
    *((int *)(_2+212)) = _899;
    RefDS(_897);
    *((int *)(_2+216)) = _897;
    RefDS(_895);
    *((int *)(_2+220)) = _895;
    RefDS(_893);
    *((int *)(_2+224)) = _893;
    RefDS(_891);
    *((int *)(_2+228)) = _891;
    RefDS(_889);
    *((int *)(_2+232)) = _889;
    RefDS(_887);
    *((int *)(_2+236)) = _887;
    RefDS(_885);
    *((int *)(_2+240)) = _885;
    RefDS(_883);
    *((int *)(_2+244)) = _883;
    RefDS(_881);
    *((int *)(_2+248)) = _881;
    RefDS(_879);
    *((int *)(_2+252)) = _879;
    RefDS(_877);
    *((int *)(_2+256)) = _877;
    _15token_name = MAKE_SEQ(_1);

    // op_result = repeat(T_UNKNOWN, MAX_OPCODE)
    DeRef1(_15op_result);
    _15op_result = Repeat(5, 182);

    // op_result[RIGHT_BRACE_N] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 31);
    *(int *)_2 = 3;

    // op_result[RIGHT_BRACE_2] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 85);
    *(int *)_2 = 3;

    // op_result[REPEAT] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 32);
    *(int *)_2 = 3;

    // op_result[APPEND] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 35);
    *(int *)_2 = 3;

    // op_result[RHS_SLICE] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 46);
    *(int *)_2 = 3;

    // op_result[CONCAT] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 15);
    *(int *)_2 = 3;

    // op_result[CONCAT_N] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 159);
    *(int *)_2 = 3;

    // op_result[PREPEND] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 57);
    *(int *)_2 = 3;

    // op_result[COMMAND_LINE] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 100);
    *(int *)_2 = 3;

    // op_result[SPRINTF] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 53);
    *(int *)_2 = 3;

    // op_result[ROUTINE_ID] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 136);
    *(int *)_2 = 1;

    // op_result[GETC] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 33);
    *(int *)_2 = 1;

    // op_result[OPEN] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 37);
    *(int *)_2 = 1;

    // op_result[LENGTH] = T_INTEGER   -- assume less than a billion
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 42);
    *(int *)_2 = 1;

    // op_result[PLENGTH] = T_INTEGER  -- ""
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 162);
    *(int *)_2 = 1;

    // op_result[IS_AN_OBJECT] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 40);
    *(int *)_2 = 1;

    // op_result[IS_AN_ATOM] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 67);
    *(int *)_2 = 1;

    // op_result[IS_A_SEQUENCE] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 68);
    *(int *)_2 = 1;

    // op_result[COMPARE] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 76);
    *(int *)_2 = 1;

    // op_result[EQUAL] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 155);
    *(int *)_2 = 1;

    // op_result[FIND] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 77);
    *(int *)_2 = 1;

    // op_result[MATCH]  = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 78);
    *(int *)_2 = 1;

    // op_result[GET_KEY] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 79);
    *(int *)_2 = 1;

    // op_result[IS_AN_INTEGER] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 94);
    *(int *)_2 = 1;

    // op_result[ASSIGN_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 113);
    *(int *)_2 = 1;

    // op_result[RHS_SUBS_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 114);
    *(int *)_2 = 1;

    // op_result[PLUS_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 115);
    *(int *)_2 = 1;

    // op_result[MINUS_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 116);
    *(int *)_2 = 1;

    // op_result[PLUS1_I] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 117);
    *(int *)_2 = 1;

    // op_result[SYSTEM_EXEC] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 156);
    *(int *)_2 = 1;

    // op_result[TIME] = T_ATOM
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 70);
    *(int *)_2 = 4;

    // op_result[EVAL] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 169);
    *(int *)_2 = 1;

    // op_result[EVAL_ERROR] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 170);
    *(int *)_2 = 3;

    // op_result[VAR_ID] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 171);
    *(int *)_2 = 1;

    // op_result[DUMP_VARS] = T_SEQUENCE
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 174);
    *(int *)_2 = 3;

    // op_result[FIND_FROM] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 181);
    *(int *)_2 = 1;

    // op_result[MATCH_FROM] = T_INTEGER
    _2 = (int)SEQ_PTR(_15op_result);
    _2 = (int)(((s1_ptr)_2)->base + 182);
    *(int *)_2 = 1;

    // sample_size = 0
    _16sample_size = 0;

    // max_stack_per_call = 1
    _16max_stack_per_call = 1;

    // branch_list = {}
    RefDS(_39);
    DeRef1(_16branch_list);
    _16branch_list = _39;

    // short_circuit = 0
    _16short_circuit = 0;

    // short_circuit_B = FALSE   -- circuit expression? given short_circuit is TRUE.
    _16short_circuit_B = 0;

    // side_effect_calls = 0     -- on local/global variables
    _16side_effect_calls = 0;

    // factors = 0
    _16factors = 0;

    // lhs_subs_level = -1
    _16lhs_subs_level = -1;

    // left_sym = 0
    _16left_sym = 0;

    // forward_putback = routine_id("putback")
    _7forward_putback = CRoutineId(188, 16, _3513);

    // replacing_full_line = 0
    _16replacing_full_line = 0;

    // forward_expr = routine_id("Expr")
    _16forward_expr = CRoutineId(212, 16, _4174);

    // forward_Statement_list = routine_id("Statement_list")
    _16forward_Statement_list = CRoutineId(230, 16, _5040);

    // mix_msg = "can't mix profile and profile_time"
    RefDS(_5469);
    DeRef1(_16mix_msg);
    _16mix_msg = _5469;

    // forward_method_func = routine_id("MethodFunc")
    _7forward_method_func = CRoutineId(246, 16, _6249);

    // forward_method = routine_id("Method")
    _7forward_method = CRoutineId(247, 16, _6462);
    _1 = NewS1(182);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_6595);
    *((int *)(_2+4)) = _6595;
    RefDS(_6596);
    *((int *)(_2+8)) = _6596;
    RefDS(_6597);
    *((int *)(_2+12)) = _6597;
    RefDS(_6598);
    *((int *)(_2+16)) = _6598;
    RefDS(_6599);
    *((int *)(_2+20)) = _6599;
    RefDS(_6600);
    *((int *)(_2+24)) = _6600;
    RefDS(_6601);
    *((int *)(_2+28)) = _6601;
    RefDS(_6602);
    *((int *)(_2+32)) = _6602;
    RefDS(_6603);
    *((int *)(_2+36)) = _6603;
    RefDS(_6604);
    *((int *)(_2+40)) = _6604;
    RefDS(_6605);
    *((int *)(_2+44)) = _6605;
    RefDS(_6606);
    *((int *)(_2+48)) = _6606;
    RefDS(_6607);
    *((int *)(_2+52)) = _6607;
    RefDS(_6608);
    *((int *)(_2+56)) = _6608;
    RefDS(_6609);
    *((int *)(_2+60)) = _6609;
    RefDS(_6610);
    *((int *)(_2+64)) = _6610;
    RefDS(_6611);
    *((int *)(_2+68)) = _6611;
    RefDS(_6612);
    *((int *)(_2+72)) = _6612;
    RefDS(_6613);
    *((int *)(_2+76)) = _6613;
    RefDS(_6614);
    *((int *)(_2+80)) = _6614;
    RefDS(_6615);
    *((int *)(_2+84)) = _6615;
    RefDS(_6616);
    *((int *)(_2+88)) = _6616;
    RefDS(_6617);
    *((int *)(_2+92)) = _6617;
    RefDS(_6618);
    *((int *)(_2+96)) = _6618;
    RefDS(_6619);
    *((int *)(_2+100)) = _6619;
    RefDS(_6620);
    *((int *)(_2+104)) = _6620;
    RefDS(_6621);
    *((int *)(_2+108)) = _6621;
    RefDS(_6622);
    *((int *)(_2+112)) = _6622;
    RefDS(_6623);
    *((int *)(_2+116)) = _6623;
    RefDS(_6624);
    *((int *)(_2+120)) = _6624;
    RefDS(_6625);
    *((int *)(_2+124)) = _6625;
    RefDS(_6626);
    *((int *)(_2+128)) = _6626;
    RefDS(_6627);
    *((int *)(_2+132)) = _6627;
    RefDS(_6628);
    *((int *)(_2+136)) = _6628;
    RefDS(_6629);
    *((int *)(_2+140)) = _6629;
    RefDS(_6630);
    *((int *)(_2+144)) = _6630;
    RefDS(_6631);
    *((int *)(_2+148)) = _6631;
    RefDS(_6632);
    *((int *)(_2+152)) = _6632;
    RefDS(_6633);
    *((int *)(_2+156)) = _6633;
    RefDS(_6634);
    *((int *)(_2+160)) = _6634;
    RefDS(_6635);
    *((int *)(_2+164)) = _6635;
    RefDS(_6636);
    *((int *)(_2+168)) = _6636;
    RefDS(_6637);
    *((int *)(_2+172)) = _6637;
    RefDS(_6638);
    *((int *)(_2+176)) = _6638;
    RefDS(_6639);
    *((int *)(_2+180)) = _6639;
    RefDS(_6640);
    *((int *)(_2+184)) = _6640;
    RefDS(_6641);
    *((int *)(_2+188)) = _6641;
    RefDS(_6642);
    *((int *)(_2+192)) = _6642;
    RefDS(_6643);
    *((int *)(_2+196)) = _6643;
    RefDS(_6644);
    *((int *)(_2+200)) = _6644;
    RefDS(_6645);
    *((int *)(_2+204)) = _6645;
    RefDS(_6646);
    *((int *)(_2+208)) = _6646;
    RefDS(_6647);
    *((int *)(_2+212)) = _6647;
    RefDS(_6648);
    *((int *)(_2+216)) = _6648;
    RefDS(_6649);
    *((int *)(_2+220)) = _6649;
    RefDS(_6650);
    *((int *)(_2+224)) = _6650;
    RefDS(_6651);
    *((int *)(_2+228)) = _6651;
    RefDS(_6652);
    *((int *)(_2+232)) = _6652;
    RefDS(_6653);
    *((int *)(_2+236)) = _6653;
    RefDS(_6654);
    *((int *)(_2+240)) = _6654;
    RefDS(_6655);
    *((int *)(_2+244)) = _6655;
    RefDS(_6656);
    *((int *)(_2+248)) = _6656;
    RefDS(_6657);
    *((int *)(_2+252)) = _6657;
    RefDS(_6658);
    *((int *)(_2+256)) = _6658;
    RefDS(_6659);
    *((int *)(_2+260)) = _6659;
    RefDS(_6660);
    *((int *)(_2+264)) = _6660;
    RefDS(_6661);
    *((int *)(_2+268)) = _6661;
    RefDS(_6662);
    *((int *)(_2+272)) = _6662;
    RefDS(_6663);
    *((int *)(_2+276)) = _6663;
    RefDS(_6664);
    *((int *)(_2+280)) = _6664;
    RefDS(_6665);
    *((int *)(_2+284)) = _6665;
    RefDS(_6666);
    *((int *)(_2+288)) = _6666;
    RefDS(_6667);
    *((int *)(_2+292)) = _6667;
    RefDS(_6668);
    *((int *)(_2+296)) = _6668;
    RefDS(_6669);
    *((int *)(_2+300)) = _6669;
    RefDS(_6670);
    *((int *)(_2+304)) = _6670;
    RefDS(_6671);
    *((int *)(_2+308)) = _6671;
    RefDS(_6672);
    *((int *)(_2+312)) = _6672;
    RefDS(_6673);
    *((int *)(_2+316)) = _6673;
    RefDS(_6674);
    *((int *)(_2+320)) = _6674;
    RefDS(_6675);
    *((int *)(_2+324)) = _6675;
    RefDS(_6676);
    *((int *)(_2+328)) = _6676;
    RefDS(_6677);
    *((int *)(_2+332)) = _6677;
    RefDS(_6678);
    *((int *)(_2+336)) = _6678;
    RefDS(_6679);
    *((int *)(_2+340)) = _6679;
    RefDS(_6680);
    *((int *)(_2+344)) = _6680;
    RefDS(_6681);
    *((int *)(_2+348)) = _6681;
    RefDS(_6682);
    *((int *)(_2+352)) = _6682;
    RefDS(_6683);
    *((int *)(_2+356)) = _6683;
    RefDS(_6684);
    *((int *)(_2+360)) = _6684;
    RefDS(_6685);
    *((int *)(_2+364)) = _6685;
    RefDS(_6686);
    *((int *)(_2+368)) = _6686;
    RefDS(_6687);
    *((int *)(_2+372)) = _6687;
    RefDS(_6688);
    *((int *)(_2+376)) = _6688;
    RefDS(_6689);
    *((int *)(_2+380)) = _6689;
    RefDS(_6690);
    *((int *)(_2+384)) = _6690;
    RefDS(_6691);
    *((int *)(_2+388)) = _6691;
    RefDS(_6692);
    *((int *)(_2+392)) = _6692;
    RefDS(_6693);
    *((int *)(_2+396)) = _6693;
    RefDS(_6694);
    *((int *)(_2+400)) = _6694;
    RefDS(_6695);
    *((int *)(_2+404)) = _6695;
    RefDS(_6696);
    *((int *)(_2+408)) = _6696;
    RefDS(_6697);
    *((int *)(_2+412)) = _6697;
    RefDS(_6698);
    *((int *)(_2+416)) = _6698;
    RefDS(_6699);
    *((int *)(_2+420)) = _6699;
    RefDS(_6700);
    *((int *)(_2+424)) = _6700;
    RefDS(_6701);
    *((int *)(_2+428)) = _6701;
    RefDS(_6702);
    *((int *)(_2+432)) = _6702;
    RefDS(_6703);
    *((int *)(_2+436)) = _6703;
    RefDS(_6704);
    *((int *)(_2+440)) = _6704;
    RefDS(_6705);
    *((int *)(_2+444)) = _6705;
    RefDS(_6706);
    *((int *)(_2+448)) = _6706;
    RefDS(_6707);
    *((int *)(_2+452)) = _6707;
    RefDS(_6708);
    *((int *)(_2+456)) = _6708;
    RefDS(_6709);
    *((int *)(_2+460)) = _6709;
    RefDS(_6710);
    *((int *)(_2+464)) = _6710;
    RefDS(_6711);
    *((int *)(_2+468)) = _6711;
    RefDS(_6712);
    *((int *)(_2+472)) = _6712;
    RefDS(_6713);
    *((int *)(_2+476)) = _6713;
    RefDS(_6714);
    *((int *)(_2+480)) = _6714;
    RefDS(_6715);
    *((int *)(_2+484)) = _6715;
    RefDS(_6716);
    *((int *)(_2+488)) = _6716;
    RefDS(_6717);
    *((int *)(_2+492)) = _6717;
    RefDS(_6718);
    *((int *)(_2+496)) = _6718;
    RefDS(_6719);
    *((int *)(_2+500)) = _6719;
    RefDS(_6720);
    *((int *)(_2+504)) = _6720;
    RefDS(_6721);
    *((int *)(_2+508)) = _6721;
    RefDS(_6722);
    *((int *)(_2+512)) = _6722;
    RefDS(_6723);
    *((int *)(_2+516)) = _6723;
    RefDS(_6724);
    *((int *)(_2+520)) = _6724;
    RefDS(_6725);
    *((int *)(_2+524)) = _6725;
    RefDS(_6726);
    *((int *)(_2+528)) = _6726;
    RefDS(_6727);
    *((int *)(_2+532)) = _6727;
    RefDS(_6728);
    *((int *)(_2+536)) = _6728;
    RefDS(_6729);
    *((int *)(_2+540)) = _6729;
    RefDS(_6730);
    *((int *)(_2+544)) = _6730;
    RefDS(_6731);
    *((int *)(_2+548)) = _6731;
    RefDS(_6732);
    *((int *)(_2+552)) = _6732;
    RefDS(_6733);
    *((int *)(_2+556)) = _6733;
    RefDS(_6734);
    *((int *)(_2+560)) = _6734;
    RefDS(_6735);
    *((int *)(_2+564)) = _6735;
    RefDS(_6736);
    *((int *)(_2+568)) = _6736;
    RefDS(_6737);
    *((int *)(_2+572)) = _6737;
    RefDS(_6738);
    *((int *)(_2+576)) = _6738;
    RefDS(_6739);
    *((int *)(_2+580)) = _6739;
    RefDS(_6740);
    *((int *)(_2+584)) = _6740;
    RefDS(_6741);
    *((int *)(_2+588)) = _6741;
    RefDS(_6742);
    *((int *)(_2+592)) = _6742;
    RefDS(_6743);
    *((int *)(_2+596)) = _6743;
    RefDS(_6744);
    *((int *)(_2+600)) = _6744;
    RefDS(_6745);
    *((int *)(_2+604)) = _6745;
    RefDS(_6746);
    *((int *)(_2+608)) = _6746;
    RefDS(_6747);
    *((int *)(_2+612)) = _6747;
    RefDS(_6748);
    *((int *)(_2+616)) = _6748;
    RefDS(_6749);
    *((int *)(_2+620)) = _6749;
    RefDS(_6750);
    *((int *)(_2+624)) = _6750;
    RefDS(_6751);
    *((int *)(_2+628)) = _6751;
    RefDS(_6752);
    *((int *)(_2+632)) = _6752;
    RefDS(_6753);
    *((int *)(_2+636)) = _6753;
    RefDS(_6754);
    *((int *)(_2+640)) = _6754;
    RefDS(_6755);
    *((int *)(_2+644)) = _6755;
    RefDS(_6756);
    *((int *)(_2+648)) = _6756;
    RefDS(_6757);
    *((int *)(_2+652)) = _6757;
    RefDS(_6758);
    *((int *)(_2+656)) = _6758;
    RefDS(_6759);
    *((int *)(_2+660)) = _6759;
    RefDS(_6760);
    *((int *)(_2+664)) = _6760;
    RefDS(_6761);
    *((int *)(_2+668)) = _6761;
    RefDS(_6762);
    *((int *)(_2+672)) = _6762;
    RefDS(_6763);
    *((int *)(_2+676)) = _6763;
    RefDS(_6764);
    *((int *)(_2+680)) = _6764;
    RefDS(_6765);
    *((int *)(_2+684)) = _6765;
    RefDS(_6766);
    *((int *)(_2+688)) = _6766;
    RefDS(_6767);
    *((int *)(_2+692)) = _6767;
    RefDS(_6768);
    *((int *)(_2+696)) = _6768;
    RefDS(_6769);
    *((int *)(_2+700)) = _6769;
    RefDS(_6770);
    *((int *)(_2+704)) = _6770;
    RefDS(_6771);
    *((int *)(_2+708)) = _6771;
    RefDS(_6772);
    *((int *)(_2+712)) = _6772;
    RefDS(_6773);
    *((int *)(_2+716)) = _6773;
    RefDS(_6774);
    *((int *)(_2+720)) = _6774;
    RefDS(_6775);
    *((int *)(_2+724)) = _6775;
    RefDS(_6776);
    *((int *)(_2+728)) = _6776;
    _19opnames = MAKE_SEQ(_1);

    // crash_msg = 0
    DeRef1(_17crash_msg);
    _17crash_msg = 0;

    // in_trace = 0
    _17in_trace = 0;

    // crash_list = {}
    RefDS(_39);
    DeRef1(_17crash_list);
    _17crash_list = _39;

    // crash_count = 0
    _17crash_count = 0;

    // t_id = tmp_alloc()
    _0 = _11tmp_alloc();
    _17t_id = _0;

    // t_arglist = tmp_alloc()
    _0 = _11tmp_alloc();
    _17t_arglist = _0;

    // t_return_val = tmp_alloc()
    _0 = _11tmp_alloc();
    _17t_return_val = _0;

    // call_back_routine = NewEntry("_call_back_", 0, 0, r:PROC, 0, 0, 0)
    RefDS(_6781);
    _0 = _11NewEntry(_6781, 0, 0, 27, 0, 0, 0);
    _17call_back_routine = _0;

    // SymTab[call_back_routine] = SymTab[call_back_routine] & 
    DeRef1(_877);
    _2 = (int)SEQ_PTR(_7SymTab);
    _877 = (int)*(((s1_ptr)_2)->base + _17call_back_routine);
    Ref(_877);
    DeRef1(_879);
    _2 = (int)SEQ_PTR(_7SymTab);
    _879 = (int)*(((s1_ptr)_2)->base + _17call_back_routine);
    Ref(_879);
    _0 = _879;
    _879 = SEQ_PTR(_879)->length;
    DeRef1(_0);
    _879 = 25 - _879;
    _879 = Repeat(0, _879);
    if (IS_SEQUENCE(_877) && IS_ATOM(_879)) {
    }
    else if (IS_ATOM(_877) && IS_SEQUENCE(_879)) {
        Ref(_877);
        Prepend(&_879, _879, _877);
    }
    else {
        Concat((object_ptr)&_879, _877, (s1_ptr)_879);
    }
    RefDS(_879);
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _17call_back_routine);
    _1 = *(int *)_2;
    *(int *)_2 = _879;
    DeRef(_1);

    // call_back_code = {CALL_FUNC,
    _0 = _17call_back_code;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 139;
    *((int *)(_2+8)) = _17t_id;
    *((int *)(_2+12)) = _17t_arglist;
    *((int *)(_2+16)) = _17t_return_val;
    *((int *)(_2+20)) = 137;
    _17call_back_code = MAKE_SEQ(_1);
    DeRef1(_0);

    // SymTab[call_back_routine][S_CODE] = call_back_code
    _2 = (int)SEQ_PTR(_7SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _7SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_17call_back_routine + ((s1_ptr)_2)->base);
    RefDS(_17call_back_code);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _17call_back_code;
    DeRef(_1);

    // TraceOn = FALSE
    _17TraceOn = 0;

    // err_file_name = "ex.err" 
    RefDS(_6792);
    DeRef1(_17err_file_name);
    _17err_file_name = _6792;

    // err_file = -1
    _17err_file = -1;
    RefDS(_2307);
    _20DIGITS = _2307;
    Concat((object_ptr)&_20HEX_DIGITS, _20DIGITS, (s1_ptr)_7019);
    Concat((object_ptr)&_20START_NUMERIC, _20DIGITS, (s1_ptr)_7021);
    RefDS(_7036);
    _20ESCAPE_CHARS = _7036;
    RefDS(_7037);
    _20ESCAPED_CHARS = _7037;

    // trace_file = -1
    _17trace_file = -1;

    // trace_line = 0
    _17trace_line = 0;

    // result = 0
    _17result = 0;

    // e_routine = {}
    RefDS(_39);
    DeRef1(_17e_routine);
    _17e_routine = _39;

    // illegal_eval = {}
    RefDS(_39);
    DeRef1(_17illegal_eval);
    _17illegal_eval = _39;

    // set_debug_io_cb = call_back( routine_id("set_debug_io") )
    DeRef1(_877);
    _877 = CRoutineId(430, 17, _9202);
    _0 = _18call_back(_877);
    DeRef1(_7set_debug_io_cb);
    _7set_debug_io_cb = _0;

    // get_files_cb = call_back( routine_id("get_files") )
    _877 = CRoutineId(442, 17, _9295);
    _0 = _18call_back(_877);
    DeRef1(_7get_files_cb);
    _7get_files_cb = _0;

    // get_value_cb = call_back( routine_id("get_value") )
    _877 = CRoutineId(443, 17, _9298);
    _0 = _18call_back(_877);
    DeRef1(_7get_value_cb);
    _7get_value_cb = _0;

    // get_symbols_cb = call_back( routine_id("get_symbols"))
    _877 = CRoutineId(444, 17, _9302);
    _0 = _18call_back(_877);
    DeRef1(_7get_symbols_cb);
    _7get_symbols_cb = _0;

    // set_values_cb = call_back( routine_id("set_values") )
    _877 = CRoutineId(445, 17, _9306);
    _0 = _18call_back(_877);
    DeRef1(_7set_values_cb);
    _7set_values_cb = _0;

    // get_line_cb = call_back( routine_id("get_line"))
    _877 = CRoutineId(446, 17, _9323);
    _0 = _18call_back(_877);
    DeRef1(_7get_line_cb);
    _7get_line_cb = _0;

    // get_lines_cb = call_back( routine_id("get_lines"))
    _877 = CRoutineId(447, 17, _9345);
    _0 = _18call_back(_877);
    DeRef1(_7get_lines_cb);
    _7get_lines_cb = _0;

    // get_pc_cb = call_back(routine_id("get_pc"))
    _877 = CRoutineId(448, 17, _9348);
    _0 = _18call_back(_877);
    DeRef1(_7get_pc_cb);
    _7get_pc_cb = _0;

    // set_break_cb = call_back( routine_id("set_break"))
    _877 = CRoutineId(449, 17, _9360);
    _0 = _18call_back(_877);
    DeRef1(_7set_break_cb);
    _7set_break_cb = _0;

    // set_trace_cb = call_back( routine_id("set_trace"))
    _877 = CRoutineId(450, 17, _9366);
    _0 = _18call_back(_877);
    DeRef1(_7set_trace_cb);
    _7set_trace_cb = _0;

    // current_sub_cb = call_back( routine_id("current_sub") )
    _877 = CRoutineId(451, 17, _9371);
    _0 = _18call_back(_877);
    DeRef1(_7current_sub_cb);
    _7current_sub_cb = _0;

    // forward_eval_exec = routine_id("eval_exec")
    _7forward_eval_exec = CRoutineId(457, 17, _9487);
    RefDS(_9769);
    _17PARAM_ABBREV = _9769;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_9770);
    *((int *)(_2+4)) = _9770;
    RefDS(_9771);
    *((int *)(_2+8)) = _9771;
    RefDS(_850);
    *((int *)(_2+12)) = _850;
    _17PARAM_NAME = MAKE_SEQ(_1);
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_9795);
    *((int *)(_2+4)) = _9795;
    RefDS(_9796);
    *((int *)(_2+8)) = _9796;
    RefDS(_39);
    *((int *)(_2+12)) = _39;
    RefDS(_9797);
    *((int *)(_2+16)) = _9797;
    _17PROC_OR_FUNC = MAKE_SEQ(_1);

    // e_variable = {}
    RefDS(_39);
    DeRef1(_17e_variable);
    _17e_variable = _39;
    _1 = NewS1(10);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_39);
    *((int *)(_2+4)) = _39;
    RefDS(_9866);
    *((int *)(_2+8)) = _9866;
    RefDS(_9867);
    *((int *)(_2+12)) = _9867;
    RefDS(_9868);
    *((int *)(_2+16)) = _9868;
    RefDS(_9869);
    *((int *)(_2+20)) = _9869;
    RefDS(_9870);
    *((int *)(_2+24)) = _9870;
    RefDS(_9871);
    *((int *)(_2+28)) = _9871;
    RefDS(_9872);
    *((int *)(_2+32)) = _9872;
    RefDS(_9873);
    *((int *)(_2+36)) = _9873;
    RefDS(_9874);
    *((int *)(_2+40)) = _9874;
    _17VAR_SCOPE = MAKE_SEQ(_1);

    // forward_do_exec = routine_id("do_exec")
    _7forward_do_exec = CRoutineId(471, 17, _9900);

    // forward_general_callback = routine_id("general_callback")
    _17forward_general_callback = CRoutineId(472, 17, _9924);

    // call_backs = {}
    RefDS(_39);
    DeRef1(_17call_backs);
    _17call_backs = _39;
    _1 = NewS1(24);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 137;
    *((int *)(_2+8)) = 224;
    *((int *)(_2+12)) = 131;
    *((int *)(_2+16)) = 192;
    *((int *)(_2+20)) = 4;
    *((int *)(_2+24)) = 80;
    *((int *)(_2+28)) = 104;
    *((int *)(_2+32)) = 0;
    *((int *)(_2+36)) = 0;
    *((int *)(_2+40)) = 0;
    *((int *)(_2+44)) = 0;
    *((int *)(_2+48)) = 255;
    *((int *)(_2+52)) = 21;
    *((int *)(_2+56)) = 0;
    *((int *)(_2+60)) = 0;
    *((int *)(_2+64)) = 0;
    *((int *)(_2+68)) = 0;
    *((int *)(_2+72)) = 194;
    *((int *)(_2+76)) = 0;
    *((int *)(_2+80)) = 0;
    *((int *)(_2+84)) = 0;
    *((int *)(_2+88)) = 0;
    *((int *)(_2+92)) = 0;
    *((int *)(_2+96)) = 0;
    _17cb_std = MAKE_SEQ(_1);
    _1 = NewS1(27);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 137;
    *((int *)(_2+8)) = 224;
    *((int *)(_2+12)) = 131;
    *((int *)(_2+16)) = 192;
    *((int *)(_2+20)) = 4;
    *((int *)(_2+24)) = 80;
    *((int *)(_2+28)) = 104;
    *((int *)(_2+32)) = 0;
    *((int *)(_2+36)) = 0;
    *((int *)(_2+40)) = 0;
    *((int *)(_2+44)) = 0;
    *((int *)(_2+48)) = 255;
    *((int *)(_2+52)) = 21;
    *((int *)(_2+56)) = 0;
    *((int *)(_2+60)) = 0;
    *((int *)(_2+64)) = 0;
    *((int *)(_2+68)) = 0;
    *((int *)(_2+72)) = 131;
    *((int *)(_2+76)) = 196;
    *((int *)(_2+80)) = 8;
    *((int *)(_2+84)) = 195;
    *((int *)(_2+88)) = 0;
    *((int *)(_2+92)) = 0;
    *((int *)(_2+96)) = 0;
    *((int *)(_2+100)) = 0;
    *((int *)(_2+104)) = 0;
    *((int *)(_2+108)) = 0;
    _17cb_cdecl = MAKE_SEQ(_1);

    // call_stack = {}
    RefDS(_39);
    DeRef1(_17call_stack);
    _17call_stack = _39;

    // Execute_id = routine_id("Execute")
    _7Execute_id = CRoutineId(480, 17, _10070);

    // crash_file("ooeu.err")
    RefDS(_10111);
    _4crash_file(_10111);

    // crash_routine(routine_id("crash"))
    _877 = CRoutineId(481, 17, _10112);
    _4crash_routine(_877);

    // mem0 = allocate(4)
    _0 = _4allocate(4);
    DeRef1(_21mem0);
    _21mem0 = _0;

    // mem1 = mem0 + 1
    DeRef1(_21mem1);
    if (IS_ATOM_INT(_21mem0)) {
        _21mem1 = _21mem0 + 1;
        if (_21mem1 > MAXINT)
            _21mem1 = NewDouble((double)_21mem1);
    }
    else
        _21mem1 = binary_op(PLUS, 1, _21mem0);

    // mem2 = mem0 + 2
    DeRef1(_21mem2);
    if (IS_ATOM_INT(_21mem0)) {
        _21mem2 = _21mem0 + 2;
        if ((long)((unsigned long)_21mem2 + (unsigned long)HIGH_BITS) >= 0) 
            _21mem2 = NewDouble((double)_21mem2);
    }
    else {
        _21mem2 = NewDouble(DBL_PTR(_21mem0)->dbl + (double)2);
    }

    // mem3 = mem0 + 3
    DeRef1(_21mem3);
    if (IS_ATOM_INT(_21mem0)) {
        _21mem3 = _21mem0 + 3;
        if ((long)((unsigned long)_21mem3 + (unsigned long)HIGH_BITS) >= 0) 
            _21mem3 = NewDouble((double)_21mem3);
    }
    else {
        _21mem3 = NewDouble(DBL_PTR(_21mem0)->dbl + (double)3);
    }
    _877 = 32768;
    _21MIN2B = - 32768;
    _877 = 32768;
    _21MAX2B = 32767;
    _877 = 8388608;
    _21MIN3B = - 8388608;
    _877 = 8388608;
    _21MAX3B = 8388607;
    _877 = power(2, 31);
    if (IS_ATOM_INT(_877)) {
        if (_877 == 0xC0000000)
            _21MIN4B = (int)NewDouble((double)-0xC0000000);
        else
            _21MIN4B = - _877;
    }
    else {
        _21MIN4B = unary_op(UMINUS, _877);
    }

    // POST_PROCESS_RID = routine_id("post_process")
    _7POST_PROCESS_RID = CRoutineId(506, 22, _10984);

    // if EMBEDDED then

    // 	main()
    _22main();
LD:

    // if debugger > 0 then
    if (binary_op_a(LESSEQ, _7debugger, 0))
        goto LE;

    // 	c_proc( cleanup_cb, {} )
    call_c(0, _7cleanup_cb, _39);
LE:
    Cleanup(0);
}
