-- libeu.e
-- This file allows ooeu to be embedded into applications as a compiled dll or so.
-- It is used exactly as eu.e would be used from the application's point of view.

include dll.e
include misc.e

atom libeu, xcleanup_debugger, xclear_env, xdo_eval, xembed_routine, xget_eval_err,
	xillegal_builtin, xnew_env, xswitch_env, xget_current_env, xget_the_object,
	xset_the_object, xdebugger


global procedure cleanup_debugger()
	if peek4s( xdebugger ) > 0 then
		c_proc( xcleanup_debugger, {} )
	end if
end procedure

global procedure clear_env()
	c_proc( xclear_env, {} )
end procedure

global function do_eval( sequence script )
	return c_func( xdo_eval, {script} )
end function

global function embed_routine( sequence name, integer rid, sequence params, integer is_func ) 
	return c_func( xembed_routine, {name, -rid, params, is_func } )
end function

global function get_eval_err()
	return c_func( xget_eval_err, {} )
end function

global procedure illegal_builtin( sequence builtin )
	c_proc( xillegal_builtin, {builtin} )
end procedure

global function new_env()
	return c_func( xnew_env, {} )
end function

global procedure switch_env( integer env )
	c_proc( xswitch_env, {env} )
end procedure

function embedded_call_back( integer rid, integer is_func )
	sequence params
	params = c_func( xget_the_object, {} )
	if is_func then
		c_proc( xset_the_object, { call_func( rid, params ) } )
	else
		call_proc( rid, params )
	end if
	return 0
end function

global function get_current_env()
	return c_func( xget_current_env, {} )
end function

function import( sequence name, sequence args, object ret )
	if platform() = LINUX then
		name = "_1" & name
	end if
	if sequence(ret) then
		return define_c_proc( libeu, name, args )
	else
		return define_c_func( libeu, name, args, ret )
	end if
end function

procedure init()
	if platform() = WIN32 then
		libeu = open_dll( "libooeu.dll" )
	else
		libeu = open_dll( "libooeu.so" )
	end if
	
	xcleanup_debugger = import( "cleanup_debugger", {}, {} )
	xclear_env = import( "clear_env", {}, {} )
	xdo_eval = import( "do_eval", { E_SEQUENCE }, E_INTEGER )
	xembed_routine = import( "embed_routine", { E_SEQUENCE, E_INTEGER, E_SEQUENCE, E_INTEGER }, E_INTEGER )
	
	xillegal_builtin = import( "illegal_builtin", {E_SEQUENCE}, {} )
	xnew_env = import( "new_env", {}, E_INTEGER )
	xswitch_env = import( "switch_env", {E_INTEGER}, {} )
	xget_current_env = import( "get_current_env", {}, E_INTEGER )
	xget_the_object = import( "get_the_object", {}, E_OBJECT )
	xset_the_object = import( "set_the_object", {E_OBJECT}, {})
	c_proc( import( "set_embedded_call_back", {E_INTEGER}, {} ), { call_back( routine_id("embedded_call_back") ) } )
	xdebugger = define_c_var( libeu, "_6debugger" )	
	if platform() = WIN32 then
		xget_eval_err = import( "get_eval_err", {}, E_SEQUENCE )
	else
		-- This is acutally in execute.e:
		xget_eval_err = import( "6get_eval_err", {}, E_SEQUENCE )
	end if
	
end procedure
init()
