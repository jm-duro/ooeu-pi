--include machine.e
without warning
global object void
sequence before, after

include misc.e

global function wxEu_Lib()
	if platform() = LINUX then
		return "wxooeu.so"
	else
		return "wxooeu.dll"
	end if
end function

include wxEuphoria.e
include wxButton.e
include wxGraphics.e
include wxSizer.e
include wxText.e
include wxList.e 
include wxData.e
include wxDialog.e
include sprint.e
include print.e



--log_message( "Object Oriented Euphoria Debugger", {})
global constant NOVALUE = -1.295837195871e307  

global integer slash
if platform() = WIN32 then
	slash = '\\'
else
	slash = '/'
end if 

-- common fields for all symbols, literal constants and temporaries 
global constant 
	 S_OBJ = 1,     -- initialized for literal constants
		      -- NOVALUE for other temps 
		      -- run time object (vars)
		      -- must be first field in C
	 S_NEXT = 2,    -- index of next temp, or next var, or 0
	 S_MODE = 3,    -- M_NORMAL, M_TEMP or M_CONSTANT 
	 S_SCOPE = 4,   -- for temps at compile time: FREE or IN_USE, 
		      -- or DELETED (Translator-only) 
	 S_USAGE = 5    -- for temps: type T_UNKNOWN or T_INTEGER 
		      -- for vars, read/written/to be deleted

-- extra fields for vars (and routines) only but not temps 
global constant 
	 S_FILE_NO = 6,   -- file number where symbol is defined
	 S_NAME = 7,      -- name string
	 S_SAMEHASH = 8,  -- index of next symbol with same hash value
	 S_TOKEN = 9,     -- token number to return to parser
	 S_HASHVAL = 10,  -- hash value 
	 S_NREFS = 11     -- number of references to this symbol 

	 -- for vars only:  
global constant 
	 S_VARNUM = 12,   -- local variable number 
	 S_INITLEVEL = 13,-- nesting level where initialized or -1 
	 S_VTYPE = 14     -- variable type or NULL 

	 -- for routines only: 
global constant 
	 S_CODE = 15,     -- IL code for proc/func/type 
	 S_LINETAB = 16,  -- Line table for traceback
	 S_FIRSTLINE = 17,-- global line number of start of routine
	 S_TEMPS = 18,    -- pointer to linked list of temps, or 0
	 S_OPCODE = 19,   -- opcode to emit (predefined subprograms)
	 S_NUM_ARGS = 20, -- number of arguments
	 S_EFFECT = 21,   -- side effects
	 S_REFLIST = 22,  -- list of referenced symbols (for BIND)
	 S_ACTIVE = 23    -- currently in use (at run-time)

-- SCOPE values: 
global constant SC_LOOP_VAR = 2, -- "private" loop vars known within a single loop 
	 SC_PRIVATE  = 3,    -- private within subprogram
	 SC_GLOOP_VAR = 4,   -- "global" loop var 
	 SC_LOCAL    = 5,    -- local to the file
	 SC_GLOBAL   = 6,    -- global across all files 
	 SC_PREDEF   = 7,    -- predefined symbol - could be overriden
	 SC_KEYWORD  = 8,    -- a keyword
	 SC_UNDEFINED = 9,   -- new undefined symbol 
	 SC_MULTIPLY_DEFINED = 10  -- global symbol defined in 2 or more other files

global constant SIZEOF_ROUTINE_ENTRY = 23,
		SIZEOF_VAR_ENTRY = 14 + 33,
		SIZEOF_TEMP_ENTRY = 5

global constant syntax_coloring = 1
global sequence break_lines, selected_lines, SymTab, val
global integer displayed_line
break_lines = {}
selected_lines = {}
displayed_line = 0


global constant 
	SRC = 1,  -- line of source code
	LINE = 2,  -- line number within file
	LOCAL_FILE_NO = 3,  -- file number
	OPTIONS = 4   -- options in effect

global integer stop_forward, continue_forward, displayed_file, CurrentSub, 
	LastSub, TopLevelSub, wait, current_file, change_forward
displayed_file = 0

-- controls:
global atom main, win, continue, quit, editor, editor_panel, main_splitter, 
	lower_pane, Quit, Abort, var_entry, show_value, var_list, remove_value,
	var_msg, file_list, m_keepGoing, clip_widget, value_button

global atom value_dialog, value_text, value_ok, value_cancel, value_label

main = 0

global sequence gbreak_lines, gselected_lines, watch_list
watch_list = {}
gbreak_lines = {}
gselected_lines = {}

-- callbacks:
global atom debugger, debug_main, get_value_cb, get_symbols_cb, get_line_cb, get_lines_cb,
	set_break_cb, get_files_cb, set_trace_cb, current_sub_cb, get_pc_cb, set_values_cb,
	set_debug_io_cb
	
global sequence appname, file_name, slist, file_text
	
global function local_to_global( integer line )
	for i = 1 to length(slist) do
		if displayed_file = slist[i][LOCAL_FILE_NO] then
		if slist[i][LINE] = line then
			return i
		end if
		end if
	end for
	return 0
end function

object the_object
global procedure set_object( object obj)
	the_object = obj
end procedure

global function get_object()

	return the_object
end function

--/topic Utilities
--/func seq_fetch( object a, sequence b )
--
-- return a[b...]
global function seq_fetch(object a, sequence b)

	for i = 1 to length(b) do
		if atom(a) or (not b[i]) or (b[i] > length(a)) then
			return {0,{}}
		end if
		a = a[b[i]]

	end for

	return {1,a}
end function

--/topic Utilities
--/func seq_store(object a, object b, object c)
--
--Store a in b at subcript c
global function seq_store(object a, object b, object c)
	integer len
	
	if atom(c) then
		c = {c}
	end if
	
	len = length(c)
	
	-- now it will insert a new element!
	if c[1] = -1 or length(b) + 1 = c[1] then
		return b & { a }
	elsif len > 1 then
		-- recursively go into the sequence
		
		b[c[1]] = seq_store(a, b[c[1]], c[2..len] )
		return b
	end if
	
	-- get the index
	c = c[1]
	
	if c then
		b[c] = a
	else
		b = a	 
	end if
	
	return b
end function

-- parse variable and subscripts
constant DIGITS = "1234567890"
function parse_subs( sequence subs )
	integer ix, jx, len, char
	sequence parsed, val
	
	ix = find( '[', subs )
	if not ix then
		-- no subscripts
		return { subs }
	end if
	
	parsed = {subs[1..ix-1]}
	len = length(subs)
	ix += 1
	jx = ix
	while jx <= len do
		char = subs[jx]
		if not find( char, DIGITS ) then
			
			if char = ']' then
				val = value( subs[ix..jx-1] )
				if val[1] != GET_SUCCESS then
					return 0
					
				elsif not val[2] then
					return 0
					
				end if
				parsed &= val[2]
				
			elsif char = '[' then
				ix = jx + 1
				
			else
				return 0
			end if
		end if
		jx += 1
	end while
	
	return parsed
end function

global procedure copy_var( )
	sequence var
	integer item
	item = get_selection( var_list )
	if item = -1 then
		return
	end if
	var = get_string_selection( var_list )
	if platform() = LINUX then
		set_text( clip_widget, var )
		copy_text( clip_widget )
	else
		set_clip_text( var )
	end if
end procedure

include trace_screen.e


procedure on_var_list_key( atom this, atom event_type, atom id, atom event )
	integer key, ctrl
	
	key = get_key_code( event )
	ctrl = key_event_controldown( event )

	if key = 3 and ctrl then

		copy_var()
	end if
end procedure

procedure on_continue( atom this, atom event_type, atom id, atom event )
	wait = 0
	poke( m_keepGoing, 0 )
end procedure
continue_forward = routine_id("on_continue")

procedure on_stop( atom this, atom event_type, atom id, atom event )

	poke( m_keepGoing, 0 )
	wait = 0
	show_window( main, 0 )

	if this = quit or this = main then
		c_proc( set_trace_cb, {0})
	elsif this = Quit then
		c_proc( set_trace_cb, {4})
	elsif this = Abort then
		c_proc( set_trace_cb, {5})
	end if
	
	wait = 0
end procedure
stop_forward = routine_id("on_stop")

global function erase_symbol( integer sym )
	integer ix
	ix = find( sym, watch_list )

	if not ix then
		return 0
	end if
	delete_item( var_list, ix  - 1)
	watch_list[ix..$-1] = watch_list[ix+1..$]
	watch_list = watch_list[1..$-1]
	return 0
end function

global function display_var( integer sym )
	if find(sym, watch_list) then
		return 0
	end if
	c_proc( get_symbols_cb, {})
	SymTab = the_object[1]
	val = the_object[2]

	watch_list &= sym
	add_item( var_list, SymTab[sym][S_NAME] & " = " & pretty_source( val[sym] ))
	void = call_member( wxApp_Yield, myApp_this, {1})

	return 0
end function

global function erase_privates( integer sub )
	-- remove out of scope privates...
	integer ix
	object sym

	c_proc( get_symbols_cb, {})
	SymTab = the_object[1]
	val = the_object[2]	
	ix = 1
	while ix <= length(watch_list) do 
		sym = watch_list[ix]
		if sequence( sym ) then
			sym = sym[1]
		end if
		if find( SymTab[sym][S_SCOPE], {SC_PRIVATE, SC_LOOP_VAR}) then
		
			delete_item( var_list, ix  - 1)
			watch_list[ix..$-1] = watch_list[ix+1..$]
			watch_list = watch_list[1..$-1]
		else
			ix += 1
		end if                  
	end while
	return 0
end function

procedure set_var_val( object sym, object the_val )
	sequence subs
	object var_val
	subs = ""

	if sequence( sym ) then
		subs = sym[2]
		sym = sym[1]
		var_val = seq_fetch( val[sym], subs )
		
		if var_val[1] then
			var_val = var_val[2]
			val[sym] = seq_store( the_val, val[sym], subs )

		else
			return
		end if
		
		
	else
		val[sym] = the_val
	end if
	
	the_object = val[sym]
	c_proc( set_values_cb, {sym})
end procedure

function get_var_val( object sym )
	sequence subs
	object var_val
	subs = ""
	if sequence( sym ) then
		subs = sym[2]
		var_val = seq_fetch( val[sym[1]], subs )
		if var_val[1] then
			var_val = var_val[2]
		else
			var_val = "<subscript out of range>"
		end if
				
	else
		var_val = val[sym]
		if var_val = NOVALUE then
			var_val = "<no value>"
		end if

	end if
	
	return var_val
end function

function get_var_name( object sym )
	sequence var_name, subs
	
	if sequence(sym) then
		var_name = SymTab[sym[1]][S_NAME]
		subs = sym[2]
		for i = 1 to length(subs) do
			var_name &= sprintf( "[%d]", subs[i] )
		end for
	else
		var_name = SymTab[sym][S_NAME]
	end if

	return var_name
end function

procedure add_watch_var( object sym )
	sequence var_name
	object var_val
	
	var_name = get_var_name( sym )
	var_val = get_var_val( sym )

	if sequence( sym ) then
		watch_list = append( watch_list, {sym[1], sym[2]})
		
	else
		watch_list &= sym
		
	end if
	
	add_item( var_list, sprintf( "%s = %s", { var_name, pretty_source( var_val ) }))
end procedure

procedure update_watch_var( integer ix )
	object sym
	sequence var_name, var_string
	
	sym = watch_list[ix]
	var_string = sprintf( "%s = %s", { get_var_name( sym ), pretty_source( get_var_val( sym ) ) } )
	if length( var_string ) > 60000 then
		var_string = var_string[1..60000] & "..."
	end if
	set_string( var_list, ix - 1, var_string )
	
end procedure

global function update_vars()
	integer ix
	object sym
	sequence subs
	c_proc( get_symbols_cb, {})
	SymTab = the_object[1]
	val = the_object[2]
	set_label(var_msg, "")

	for i = 1 to length(watch_list) do
		update_watch_var( i )
	end for

	return 0
end function



procedure on_show_value( atom this, atom event_type, atom id, atom event )
	sequence text, refs
	integer sym, ok, ix
	object subs

	set_label(var_msg, "")
	text = get_text_value( var_entry )

	if not length(text) then
		return
	end if
	
	subs = parse_subs( text )
	if atom( subs ) then
		set_label( var_msg, "improper subscript or variable name" )
		return
	end if
	
	text = subs[1]
	subs = subs[2..$]

	
	set_text( var_entry, "" )
	ok = 0
	
	-- start searching for the symbol in the privates...
	sym = SymTab[CurrentSub][S_NEXT]
	while sym and find(SymTab[sym][S_SCOPE], { SC_PRIVATE, SC_LOOP_VAR}) do
		if equal( text, SymTab[sym][S_NAME] ) then
			-- found it!
			ix = find( sym, watch_list )
			if ix and not length(subs) then
				-- already being displayed, so just update the value...
				update_watch_var( ix )

			elsif length(subs) then
				ix = find( watch_list, {sym, subs})
				if ix then
					update_watch_var( ix )
				else
					add_watch_var( {sym, subs})
				end if
				
			else
				-- it's a new variable to be displayed
				add_watch_var( sym )
				set_focus( editor )				

			end if
			return
		end if
		sym = SymTab[sym][S_NEXT]
	end while
	
	-- wasn't a private...
	for s = TopLevelSub + 1 to length(SymTab) do
		if length(SymTab[s]) > SIZEOF_TEMP_ENTRY then
		if equal( text, SymTab[s][S_NAME]) then
		if (SymTab[s][S_SCOPE] = SC_GLOBAL) or 
		(SymTab[s][S_FILE_NO] = displayed_file and SymTab[s][S_SCOPE] = SC_LOCAL) or
		(CurrentSub = TopLevelSub and SymTab[s][S_SCOPE] = SC_GLOOP_VAR) then
			-- found it!
			ix = find( s, watch_list )

			if ix and not length(subs) then
				-- it's already up there, so just have to update the entry:
				update_watch_var( ix )

			elsif length(subs) then
				ix = find( watch_list, {s, subs})
				if ix then
					update_watch_var( ix )
				else
					add_watch_var( {s, subs})
				end if
								
			else
				-- not already being displayed
				add_watch_var( s )
	
			end if


			set_focus( editor )
			return
		end if
		end if
		end if
	end for
	set_label( var_msg, sprintf("'%s' doesn't exist here", {text}))
	set_focus( editor )
end procedure

procedure on_remove_value( atom this, atom event_type, atom id, atom event )
	atom item
	set_label(var_msg, "")
	item = get_selection( var_list )
	if item = -1 then
		return
	end if
	
	delete_item( var_list, item )
	watch_list = watch_list[1..item] & watch_list[item+2..$]
	set_focus( editor )
end procedure

procedure on_change_value( atom this, atom event_type, atom id, atom event )
	integer ok, item
	object sym
	sequence var_name
	item = get_selection( var_list ) + 1
	if not item then
		return
	end if
	var_name = get_string_selection( var_list )
	sym = watch_list[item]
	
	set_label( value_label, var_name )
	set_text( value_text, pretty_source( get_var_val( sym ) ) )
	ok = show_modal( value_dialog )
end procedure
change_forward = routine_id("on_change_value")

procedure on_value_ok_cancel( atom this, atom event_type, atom id, atom event )
	integer ok, item
	object sym, var_val
	sequence var_name

	if id = wxID_CANCEL then
		end_modal( value_dialog, id )
		return
	end if

	item = get_selection( var_list ) + 1
	if not item then
		return
	end if
	
	sym = watch_list[item]	
	var_val = value( get_text_value( value_text ) )
	if var_val[1] = GET_SUCCESS then

		set_var_val( sym, var_val[2] )
	end if
	sym = update_vars()	

	end_modal( value_dialog, id )

end procedure

procedure on_select_file( atom this, atom event_type, atom id, atom event )
	-- show the correct file
	integer fn
	fn = get_selection( file_list )
	if fn = -1 then
		set_focus( editor )
		return
	end if
	
	fn += 1
	displayed_file = fn
	if atom( file_text[fn] ) then
		file_text[fn] = {}
		for i = 1 to length(slist) do
			if slist[i][LOCAL_FILE_NO] = fn  then
			if sequence( slist[i][SRC] )then
				file_text[fn] = append( file_text[fn], slist[i][SRC] )
			else
				file_text[fn] = append( file_text[fn], "" )
			end if
			end if
		end for
	end if

	synSetText( file_text[fn] )
	if fn = current_file then
		make_visible( displayed_line )
	end if
	refresh_window( editor )
	set_focus( editor )
end procedure

procedure create_debugger()
	atom hsizer, vsizer, editor_splitter, editor_parent, hFont

	if platform() = WIN32 then
		hFont = create( wxFont, {10,wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,0,
			"Courier New"})
	else
		hFont = create( wxFont, {12,wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,0,
			"Courier"})
	end if
	
	
	main = create( wxFrame, {0, -1, "Object Oriented Euphoria Debugger: " & appname, 
		-1, -1, 800, 600})

	win = create( wxPanel, main )

	continue = create( wxButton, {win, -1, "Continue"})
	quit = create( wxButton, {win, -1, "Stop Trace"})
	Quit = create( wxButton, {win, -1, "Kill Trace"})
	Abort = create( wxButton, {win, -1, "Abort"})


	-- create the editor
	main_splitter = create( wxSplitterWindow,{ win, 400, 300 })
	editor_panel = create( wxSplitterWindow, main_splitter )
	lower_pane = create( wxPanel, main_splitter )

	split_window( main_splitter, editor_panel, lower_pane, wxHORIZONTAL, 400 )
	
	-- create the value dialog
	value_dialog = create( wxDialog, {main, -1, "Change Variable Value", -1, -1, 400, 300} )
	value_text = create( wxTextCtrl, {value_dialog, -1, "", -1, -1, -1, -1, wxTE_MULTILINE})
	value_label = create( wxStaticText, {value_dialog, -1})
	value_ok = create( wxButton, {value_dialog, wxID_OK, "OK"})
	value_cancel = create( wxButton, {value_dialog, wxID_CANCEL, "Cancel"})
	
	set_default_font( value_text, hFont )
	set_default_font( value_label, hFont )
	
	vsizer = create( wxBoxSizer, wxVERTICAL )
	add_window_to_sizer( vsizer, value_label, 0, wxGROW + wxTOP + wxLEFT, 5 )
	add_window_to_sizer( vsizer, value_text, 1, wxGROW + wxTOP + wxLEFT, 5 )
	hsizer = create( wxBoxSizer, wxHORIZONTAL )
	add_window_to_sizer( hsizer, value_ok, 0, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, value_cancel, 0, wxTOP + wxLEFT, 5 )
	add_sizer_to_sizer( vsizer, hsizer, 0, 0, 0 )
	set_sizer( value_dialog, vsizer )
	
	set_min_pane_size( main_splitter, 20 )
--	set_splitter_sash_position( main_splitter, 150, 1 )


	file_list = create( wxListBox, {editor_panel, -1})
	editor_parent = create( wxPanel, editor_panel )
	editor = Syntax2( editor_parent, 0, 0,-1,-1,0,0 )
	
	split_window( editor_panel, file_list, editor_parent, wxVERTICAL, 100 )
	set_min_pane_size( editor_panel, 20 )
--	set_splitter_sash_position( editor_panel, 150, 1 )
	
	var_entry = create( wxTextCtrl, {lower_pane, -1, "", -1,-1,-1,-1,wxTE_PROCESS_ENTER})
	show_value = create( wxButton, {lower_pane, -1, "Show"})
	remove_value = create( wxButton, {lower_pane, -1, "Remove"})
	value_button = create( wxButton, {lower_pane, -1, "Change"})
	
	var_list = create( wxListBox, {lower_pane, -1,-1,-1,-1,-1,{},wxLB_HSCROLL})
	var_msg = create( wxStaticText, {lower_pane, -1})
	
	set_event_handler( continue, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_continue"))
	set_event_handler( quit, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_stop"))
	set_event_handler( Quit, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_stop"))
	set_event_handler( Abort, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_stop"))
	set_event_handler( show_value, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_show_value"))
	set_event_handler( var_entry, -1, wxEVT_COMMAND_TEXT_ENTER, routine_id("on_show_value"))
	set_event_handler( remove_value, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_remove_value"))
	set_event_handler( file_list, -1, wxEVT_COMMAND_LISTBOX_SELECTED, routine_id("on_select_file"))
	set_event_handler( main, get_id(main), wxEVT_CLOSE_WINDOW, routine_id("on_stop"))
	
	set_event_handler( value_button, -1, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_change_value"))
	set_event_handler( value_ok, wxID_OK, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_value_ok_cancel"))
	set_event_handler( value_cancel, wxID_CANCEL, wxEVT_COMMAND_BUTTON_CLICKED, routine_id("on_value_ok_cancel"))
		
	set_event_handler( var_list, -1, wxEVT_CHAR, routine_id("on_var_list_key"))
--	set_event_handler( var_list, -1, wxEVT_KEY_DOWN, routine_id("on_var_list_key"))
	
	-- The buttons at the top
	hsizer = create( wxBoxSizer, wxHORIZONTAL )
	add_window_to_sizer( hsizer, continue, 0, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, quit, 0, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, Quit, 0, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, Abort, 0, wxTOP + wxLEFT, 5 )
	
	-- buttons, plus the main splitter
	vsizer = create( wxBoxSizer, wxVERTICAL )
	add_sizer_to_sizer( vsizer, hsizer, 0, 0, 0 )
	add_window_to_sizer( vsizer, main_splitter, 1, wxGROW, 0 )
	set_sizer( win, vsizer )
	
	-- horizontal sizer for the watch box and buttons
	hsizer = create( wxBoxSizer, wxHORIZONTAL )
	add_window_to_sizer( hsizer, var_entry, 1, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, show_value, 0, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, remove_value, 0, wxTOP + wxLEFT, 5 )
	add_window_to_sizer( hsizer, value_button, 0, wxTOP + wxLEFT, 5 )
	
	-- contains the watch box and buttons plus the list that shows
	-- the vars being watched
	vsizer = create( wxBoxSizer, wxVERTICAL )
	add_sizer_to_sizer( vsizer, hsizer, 0, wxGROW + wxBOTTOM + wxRIGHT + wxLEFT, 5 )
	add_window_to_sizer( vsizer, var_msg, 0, wxGROW + wxBOTTOM, 5 )
	add_window_to_sizer( vsizer, var_list, 1, wxGROW, 0 )
	set_sizer( lower_pane, vsizer )
	
	vsizer = create( wxBoxSizer, wxVERTICAL )
	add_window_to_sizer( vsizer, win, 1, wxGROW, 0 )
	set_sizer( main, vsizer )
	
	c_proc( get_lines_cb, {1, -1})
	slist = the_object
	
	if platform() = LINUX then
		clip_widget = create( wxTextCtrl, {main, -1, "", -1, -1, -1, -1, wxTE_MULTILINE} )
		show_window( clip_widget, 0 )
	end if

end procedure

function short_name(sequence fname)
	for f = 1 to length(fname) do
		for g = length(fname[f]) to 1 by -1 do
			if fname[f][g] = slash then
				fname[f] = fname[f][g+1..$]
				exit
			end if
		end for
	end for
	return fname
end function



function do_trace( integer line )
	sequence sline, m_keepRunning
	object void
	integer fn, ix
	atom dc
	atom pending, process

	if wait then
		return 0
	end if

	if not main then
		create_debugger()
		add_item( file_list, file_name )
		m_keepGoing = myApp_this + sizeof_wxApp - 1
	end if

	c_proc( get_lines_cb, {1,-1})
	if length(the_object) > length(slist) then
		slist = the_object
	end if

	set_label(var_msg, "")
	fn = slist[line][LOCAL_FILE_NO]
	if fn > length(file_name) then
		
		c_proc( get_files_cb, {})
		the_object = short_name( the_object )
		for f = length(file_name) + 1 to length(the_object) do
		
			file_name = append(file_name, the_object[f])
			gbreak_lines &= {{}}
			gselected_lines &= {{}}
			add_item( file_list, the_object[f] )    
		end for
		file_name = the_object
		
	end if
	set_list_selection( file_list, fn-1)
	
	if atom( file_text[fn] ) or slist[line][LINE] > length(file_text[fn]) then

		file_text[fn] = {}
		for i = 1 to length(slist) do
			if slist[i][LOCAL_FILE_NO] = fn  then
			if sequence( slist[i][SRC] )then
				file_text[fn] = append( file_text[fn], slist[i][SRC] )
			else
				file_text[fn] = append( file_text[fn], "" )
			end if
			end if
		end for
		synSetText( file_text[fn] )

	end if



	c_proc( get_symbols_cb, {})
	SymTab = the_object
	CurrentSub = c_func( current_sub_cb, {})
	displayed_line = slist[line][LINE]
	
	ix = find( -line, gbreak_lines )
	if ix then
		gbreak_lines = gbreak_lines[1..ix-1] & gbreak_lines[ix+1..$]
		c_proc( set_break_cb, {line, 0})
	end if
	
	if fn != displayed_file then
		synSetText( file_text[fn] )
		set_list_selection( file_list, fn - 1 ) 
		displayed_file = fn
	end if
	
	current_file = displayed_file
	void = update_vars()
	
	make_visible( displayed_line )
	show_window( main, 1 )
	raise_window( main )
	refresh_window( editor )

	set_focus(editor)

	if platform() = WIN32 then
		void = call_member( wxApp_MainLoop, myApp_this, {})
		poke( m_keepGoing, 1 )
	else
		wait = 1
		while wait do
			void = call_member( wxApp_Yield, myApp_this, {1})
		end while
	end if
	

	-- deref it
	SymTab = ""
	LastSub = CurrentSub

	return 0
end function


global function initialize( sequence funcs, sequence file )

	get_value_cb = define_c_proc( "", funcs[1], {C_POINTER} )
	get_symbols_cb = define_c_proc( "", funcs[2], {} )
	get_line_cb = define_c_proc( "", funcs[3], {C_LONG} )
	get_lines_cb = define_c_proc( "", funcs[4], {C_LONG, C_LONG} )
	set_break_cb = define_c_proc( "", funcs[5], {C_LONG, C_LONG})
	get_files_cb = define_c_proc( "", funcs[6], {} )
	set_trace_cb = define_c_proc( "", funcs[7], {C_LONG})
	current_sub_cb = define_c_func( "", funcs[8], {}, C_LONG)
	get_pc_cb = define_c_func( "", funcs[9], {}, C_LONG)
	set_values_cb = define_c_proc( "", funcs[10], {E_INTEGER} )
	set_debug_io_cb = define_c_proc( "", funcs[11], {E_INTEGER} )
	
	appname = file
	c_proc( get_files_cb, {})
	file_name = the_object
	
	for f = 1 to length(file_name) do
		for g = length(file_name[f]) to 1 by -1 do
			if file_name[f][g] = slash then
				file_name[f] = file_name[f][g+1..$]
				exit
			end if
		end for
	end for
	file_text = repeat( 0, length(file_name) )
	gbreak_lines = repeat( {}, length(file_name))
	
	c_proc( get_symbols_cb, {})
	SymTab = the_object[1]
	
	for i = 1 to length(SymTab) do
		if length(SymTab[i]) >= S_NAME then
		if equal( SymTab[i][S_NAME], "_toplevel_" ) then
			TopLevelSub = i
			exit
		end if
		end if
	end for
	
	LastSub = TopLevelSub
	return call_back( routine_id("do_trace") )
end function



global procedure cleanup_debugger()

	if main then
		destroy(main)
	end if
	
	if platform() = WIN32 then
		cleanup()
	end if
	
end procedure


global procedure hide_debugger()
	show_window( main, 0 )
end procedure

function ooeu_trace_crash( object o )
	puts(1, "crash!\n" )
	trace(0)
	return 0
end function
crash_routine(routine_id("ooeu_trace_crash"))
