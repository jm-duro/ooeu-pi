
without type_check
without warning
global constant TRUE = 1, FALSE = 0

global constant EMBEDDED = TRUE

global constant INTERPRET = TRUE,
		TRANSLATE = FALSE,
		BIND = FALSE
		
global constant EXTRA_CHECK = FALSE 

-- standard Euphoria includes
include misc.e
include wildcard.e

include machine.e


global procedure Print( integer fn, object o )
	print( fn, o )
end procedure

-- a nice pretty print file
include print.e
include sprint.e

-- INTERPRETER front-end
include global.e
include reswords.e as r
include error.e
include keylist.e
include symtab.e
include scanner.e
include emit.e
include parser.e

global object the_object
global function get_the_object()
	return the_object
end function

global procedure set_the_object( object o )
	the_object = o
end procedure

-- INTERPRETER back-end, written in Euphoria
include execute.e   

include sequencef.e

-- main program:
include main.e


-- begin mwl
-- handy stuff for embedded purposes:
global sequence symtab_table, slist_table, routine_table, variable_table, 
	crash_table, buckets_table, val_table, classes_table, members_table,
	methods_table, lastintval_table, lastintsym_table, init_stack_table,
	file_name_table, literal_table
integer current_env
symtab_table = {0}
slist_table = {0}
routine_table = {0}
variable_table = {0}
crash_table = {0}
buckets_table = {0}
val_table = {0}
classes_table = {0}
members_table = {0}
methods_table = {0}
lastintval_table = {0}
lastintsym_table = {0}
init_stack_table = {0}
file_name_table = {0}
literal_table = {0}
current_env = 1

procedure save_current_env()
	symtab_table    [current_env] = SymTab
	slist_table     [current_env] = slist
	routine_table   [current_env] = e_routine
	variable_table  [current_env] = e_variable
	crash_table     [current_env] = crash_table
	buckets_table   [current_env] = buckets
	val_table       [current_env] = val
	classes_table   [current_env] = class_table
	members_table   [current_env] = member_table
	methods_table   [current_env] = method_table
	lastintval_table[current_env] = lastintval
	lastintsym_table[current_env] = lastintsym
	init_stack_table[current_env] = init_stack
	file_name_table [current_env] = file_name
	literal_table   [current_env] = literal_init
end procedure


global procedure clear_env()
	integer call_back_routine
	sequence call_back_code
	class_table = repeat( {}, CLASS_ENTRY )
	method_table = repeat( {}, METHOD_ENTRY )
	member_table = repeat( {}, MEMBER_ENTRY )	
	SymTab = {}
	slist = {}
	e_routine = {}
	e_variable = {}
	crash_list = {}
	val = {}
	lastintval = {}
	lastintsym = {}
	buckets = repeat( 0, NBUCKETS )
	last_sym = 0
	init_stack = {}
	file_name = {}
	literal_init = 0
	
	-- only need one set of temps for call-backs
	t_id = tmp_alloc()
	t_arglist = tmp_alloc()
	t_return_val = tmp_alloc()
	call_back_code = {CALL_FUNC,
			  t_id,
			  t_arglist,
			  t_return_val,
			  CALL_BACK_RETURN
			 }
	-- dummy call-back routine
	call_back_routine = NewEntry("_call_back_", 0, 0, r:PROC, 0, 0, 0)
	SymTab[call_back_routine] = SymTab[call_back_routine] & 
				    repeat(0, SIZEOF_ROUTINE_ENTRY - 
				    length(SymTab[call_back_routine]))
	SymTab[call_back_routine][S_CODE] = call_back_code	
	InitSymTab()
	InitBackEnd()
	
end procedure


global function new_env()
	integer env, call_back_routine
	
	env = find( -1, symtab_table )
	if env = 0 then
		symtab_table &= 0
		slist_table &= 0
		routine_table &= 0
		variable_table &= 0
		crash_table &= 0
		buckets_table &= 0
		val_table &= 0
		classes_table &= 0
		members_table &= 0
		methods_table &= 0
		lastintval_table &= 0
		lastintsym_table &= 0
		init_stack_table &= 0
		file_name_table &= 0
		literal_table &= 0
		env = length( symtab_table )
	end if
	save_current_env()
	clear_env()
	current_env = env
	return env
end function


global procedure switch_env( integer env )
	if env < 1 or env > length(symtab_table) or env = current_env then
		return
	end if
	
	save_current_env()
	
	SymTab = symtab_table[env]

	last_sym = length(SymTab)
	slist  = slist_table [env]
	e_routine = routine_table[env]
	e_variable = variable_table[env]
	crash_list = crash_table[env]
	buckets = buckets_table[env]
	val = val_table[env]
	class_table = classes_table[env]
	member_table = members_table[env]
	method_table = methods_table[env]
	init_stack = init_stack_table[env]
	file_name = file_name_table[env]
	literal_init = literal_table[env]
	current_env = env
end procedure


global function get_current_env()
	return current_env
end function

global procedure cleanup_debugger()
	if debugger > 0 then
		c_proc( cleanup_cb, {})
	end if
end procedure

global procedure set_embedded_call_back( atom cb )
	embedded_call_back = define_c_proc( "", cb, { C_INT, C_INT } )
end procedure

global procedure illegal_builtin( sequence builtin )
	integer illegal
	
	if not length(builtin) then
		return
	end if
	if atom( builtin[1] ) then
		builtin = {builtin}
	end if
	
	illegal = routine_id("opILLEGAL")
	for i = 1 to length( keylist ) do
		if find( keylist[i][1], builtin ) then
			operation[keylist[i][4]] = illegal
			return
		end if
	end for
	if find ( "?", builtin ) then
		operation[QPRINT] = illegal
	end if
end procedure

global function do_eval( sequence code )
	return do_eval_exec( code )
end function

global function embed_routine( sequence name, integer rid, sequence params, integer is_func )
	return embed_routine_exec( name, rid, params, is_func )
end function
