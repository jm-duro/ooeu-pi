-- written by Don Phillips with some modifications for ooeu debugger
-- ported to wxEuphoria by Matt Lewis
integer kd_rid
without trace
without warning
without type_check

include wxEuphoria.e
include wxButton.e
include wxGraphics.e
include wxScrollBar.e
include wxText.e
include wxSizer.e

constant eu_keywords = {
	"if", "end", "then", "procedure", "else", "for", "return",
	"do", "elsif", "while", "type", "constant", "to", "and", "or",
	"exit", "function", "global", "by", "not", "include",
	"with", "without", "euclass"}

global constant eu_builtins = {
	"length", "puts", "integer", "sequence", "position", "object",
	"append", "prepend", "print", "printf", 
	"clear_screen", "floor", "getc", "gets", "get_key",
	"rand", "repeat", "atom", "compare", "find", "match",
	"time", "command_line", "open", "close", "trace", "getenv",
	"sqrt", "sin", "cos", "tan", "log", "system", "date", "remainder",
	"power", "machine_func", "machine_proc", "abort", "peek", "poke", 
	"call", "sprintf", "arctan", "and_bits", "or_bits", "xor_bits",
	"not_bits", "pixel", "get_pixel", "mem_copy", "mem_set",
	"c_proc", "c_func", "routine_id", "call_proc", "call_func", 
	"poke4", "peek4s", "peek4u"}


global constant eu_library = {
	"all_palette", "allocate", "allocate_low", "allocate_string",
	"allow_break", "atom_to_float32", "atom_to_float64", "bits_to_int",
	"bk_color", "bytes_to_int", "call_back", "check_break", "crash_message",
	"current_dir", "cursor", "custom_sort", "define_c_func", "define_c_proc",
	"dir", "display_image", "display_text_image", "dos_interrupt",
	"draw_line", "ellipse", "float32_to_atom", "float64_to_atom",
	"free", "free_low", "get", "get_active_page", "get_all_palette",
	"get_display_page", "get_mouse", "get_position", "get_vector",
	"graphics_mode", "int_to_bits", "int_to_bytes", "lock_memory",
	"lower", "message_box", "mouse_events", "mouse_pointer",
	"open_dll", "palette", "polygon", "read_bitmap", "save_bitmap",
	"save_image", "save_screen", "save_text_image", "scroll",
	"seek", "set_active_page", "set_display_page", "set_rand",
	"set_vector", "sort", "sound", "text_rows", "tick_rate",
	"upper", "use_vesa", "value", "video_config", "wait_key",
	"where", "wildcard_file", "wildcard_match", "wrap"}




integer slash
if platform() = LINUX then
	slash = '/'
else
	slash = '\\'
end if

constant True = 1, False = 0

-- variables for Syntax2 ----------------------------------------------------------------

-- control handles
atom
SynFrame, Syntax, SynPix, SynVScroll, SynHScroll, CursorPix, SynInput, Options, ParID,
frame_sizer, syn_sizer, horz_sizer, vert_sizer



-- state variables
global
sequence	Actual		  Actual		= {{}}
global
sequence	Printable	 Printable	  = {{}}
global
sequence	UnBuff		  UnBuff		= {}
integer 	   SynSizeX    SynSizeX    = 0
integer 	   SynSizeY    SynSizeY    = 0
integer 	   TabStop		  TabStop		 = 4
integer 	   MaxLine		  MaxLine		 = 0
integer 	   NumLinesX	NumLinesX	 = 0
integer 	   NumLinesY	NumLinesY	 = 0
integer 	   StartLine	StartLine	 = 1
integer 	   StartOff    StartOff    = 1
integer 	   scrolled    scrolled    = 1
integer 	   maxcolumn   maxcolumn   = 1
-- variables related to cursor
integer 	   CursorX1    CursorX1    = 0
integer 	   CursorX2    CursorX2    = 0
integer 	   CursorY		  CursorY		 = 1
integer 	   CursorW		  CursorW		 = 0
integer 	   CursorSt    CursorSt    = 1
integer 	   CarrotVis	CarrotVis	 = False
integer 	   BlinkTime	BlinkTime	 = 0

-- variables related to selection
integer 	   DragMouse	DragMouse	 = False
integer 	   HasSelec    HasSelec    = False
integer 	   CursorXs1	CursorXs1	 = 0
integer 	   CursorXs2	CursorXs2	 = 0
integer 	   CursorYs    CursorYs    = 1
integer 	   CursorWs    CursorWs    = 0
integer 	   CursorXo2	CursorXo2	 = 0
integer 	   CursorYo    CursorYo    = 0

-- hightlight word lists
sequence	WordName	WordName	= {}
sequence	WordList	WordList	= {}
sequence	ColorList	 ColorList	  = {}

-- character class for scanning
sequence	Variable	Variable	= repeat( 0, 255 )
			Variable['a'..'z']		  = 1
			Variable['A'..'Z']		  = 1
			Variable['0'..'9']		  = 1
			Variable['_']			 = 1
			Variable['\'']			  = 2
			Variable['"']			 = 2
			Variable['-']			 = 3
			Variable['.']			 = 4

-- character class for print filter
sequence	PFilter 	   PFilter		  = repeat( 1, 255 )
			PFilter[8]				  = 0
			PFilter[10] 			   = 0
			PFilter[127]			= 0

-- character class for non-print filter
sequence	NPFilter	NPFilter	= repeat( 0, 400 )
			NPFilter[8] 			   = 1
			NPFilter[46]			= 1
			NPFilter[33..40]		= 1
			NPFilter[112]			 = 1
NPFilter[WXK_LEFT] = 1
NPFilter[WXK_RIGHT] = 1
NPFilter[WXK_DOWN] = 1
NPFilter[WXK_UP] = 1
NPFilter[WXK_DELETE] = 1
NPFilter[WXK_HOME] = 1
NPFilter[WXK_END] = 1
NPFilter[WXK_PRIOR] = 1
NPFilter[WXK_NEXT] = 1
NPFilter[WXK_ESCAPE] = 1
NPFilter[WXK_F1] = 1
NPFilter[WXK_F2] = 1
NPFilter[WXK_F3] = 1
NPFilter[WXK_F4] = 1
NPFilter[WXK_F5] = 1
NPFilter[WXK_F12] = 1
-- variables related to the font
atom		hFont		 hFont		  = 0
sequence	FontSize

-- extra variable
object		  Void

-- variables related to the options window
atom		BckColor	BckColor	= 0
atom		TmpColor	TmpColor	= 0
atom		ModuleColor ModuleColor = 0
integer 	   NumDeflts	NumDeflts	 = 0
sequence	oWordName	 oWordName	  = {}
sequence	oWordList	 oWordList	  = {}
sequence	oColorList	  oColorList	= {}

-- variables related to open file
sequence	synFileN	synFileN	= {}
integer 	   FileOpen    FileOpen    = False
sequence	CurrPath	CurrPath	= {}
integer 	   EnableHL    EnableHL    = False
integer 	   isModified	 isModified    = False

-- variables related dialogs
integer 	   OptOpen		  OptOpen		 = False
integer 	   OpenDialog	 OpenDialog    = False

-- variables related to IDE
atom		F1CallBack				F1CallBack	  = 0
atom		HintCB					HintCB		  = 0
global
integer 	HintLocY				HintLocY	  = 0
global
atom		synSaveAsFileName_id	synSaveAsFileName_id = 0
global
atom		synOpenFileName_id		synOpenFileName_id = 0


-- convert actual line w/tabs to spaced -------------------------------------------------
function RemoveTabs( object Line )
	sequence NewLine
	integer TabPos

	NewLine = {}

	if sequence(Line) then
		TabPos = find( 9, Line )
		while TabPos do
			NewLine &= Line[1..TabPos-1]
			NewLine &= repeat( 32, TabStop-remainder(length(NewLine),TabStop) )
			Line = Line[TabPos+1..length(Line)]
			TabPos = find( 9, Line )
		end while
		NewLine &= Line
	end if
		
	return( NewLine )
end function

atom wdc, back_pen, cursor_pen
wdc = 0
cursor_pen = 0
atom back_brush
atom hdcMem, hbmMem
hdcMem=0
hbmMem=0


-- repaint the highlighter --------------------------------------------------------------

back_brush = 0 --create( wxBrush,{ create(wxColour,c2rgb(ColorList[1])),wxSOLID })
back_pen = 0 --create( wxPen, create(wxColour,c2rgb(ColorList[1]) )& {1,wxSOLID})

function make_printable( sequence text )
	integer char
	for i = 1 to length(text) do
		char = text[i]
		if char > 127 or not char then
			text[i] = 31
		end if
	end for
	return text
end function

global procedure make_visible( integer line )
	sequence size
	integer vpos
	
	if line > length(Actual) then
		CursorY = length(Actual)
	else
		CursorY = line
	end if

	size = get_client_size( Syntax )
	NumLinesY = floor( SynSizeY / FontSize[2] ) + 1
	
	vpos = get_scroll_position( SynVScroll )

	if (CursorY < vpos + 2) or (CursorY > (vpos + NumLinesY - 5)) then

		vpos = floor( CursorY - NumLinesY / 2 ) - 1
		if vpos < 0 then
			vpos = 0
		end if
		set_scroll_position( SynVScroll, vpos )
	end if
	
	refresh_window( Syntax )
end procedure

procedure onPaint_Syntax( atom this,  atom event_type, atom id, atom event )
	integer YCoord
	integer End
	sequence Sel1, Sel2
	sequence Temp, upd
	integer Loop, Loop3
	atom hDC, cpDC, oldcr, oldFont, Rect, size, buffer, mset, oDC, pen, temp_color,
		region


	hDC = create( wxPaintDC, {Syntax} )
	begin_drawing( hDC )

	YCoord	= 3
	if not back_brush then
		back_brush = create( wxBrush,{ ColorList[1],wxSOLID })
		back_pen = create( wxPen, {ColorList[1],2,wxSOLID})
		cursor_pen = create(wxPen,	{ColorList[2], 2,wxSOLID})
	end if


	if not hbmMem then

		size = get_sys_metric( wxSYS_SCREEN_X ) &
			   get_sys_metric( wxSYS_SCREEN_Y )

		hbmMem = create( wxBitmap, {BM_IN_MEMORY} & size )
		hdcMem = create( wxMemoryDC, {hbmMem})
		set_font( hdcMem, hFont )

		set_background_mode( hdcMem, wxSOLID )
	end if

	set_pen( hdcMem, back_pen )
	set_brush( hdcMem, back_brush )
	size = get_client_size( Syntax )
	upd = {}


	if length(upd) and compare(size, upd[3..4]) then
		-- this tells me that something moved in front of the window, so nothing
		-- really changed, and I can simply blit the editor over...
		--draw_bitmap( {hdcMem,hbmMem}, hDC, 0, 0, 0, 0, SynSizeX, SynSizeY, wxCOPY, 0 )
		--draw_bitmap( hDC, hbmMem, 0, 0, 0 )
		blit( hDC, 0, 0, hdcMem, 0, 0, SynSizeX, SynSizeY, wxCOPY )

	else
		draw_polygon( hdcMem, {0,0,size[1],0,size[1],size[2],0,size[2]},0,0,wxODDEVEN_RULE )

		SynSizeX = size[1]
		SynSizeY = size[2]

		FontSize = get_text_extent( Syntax, "D", hFont )
		FontSize[2] += 1
		
		-- Subtracting makes sure that we keep the cursor within the 
		-- bounds of the screen
		NumLinesX = floor( SynSizeX / FontSize[1] ) - 5
		NumLinesY = floor( SynSizeY / FontSize[2] ) + 1

		StartLine = get_scroll_position( SynVScroll )+1
		StartOff = get_scroll_position( SynHScroll )

		End = StartLine + NumLinesY - 1
		if End > length(Actual) then
			End = length( Actual )
		end if

		set_text_back_color( hdcMem, ColorList[1])


		if MaxLine != 0 then
	
			YCoord = 3
			for Iter = StartLine to End do
	
				Temp = sprintf("%6d: ", Iter ) & make_printable(Printable[Iter])
				

				if Iter = displayed_line and current_file = displayed_file then
					set_text_color( hdcMem, ColorList[5] )
					set_text_back_color( hdcMem, ColorList[4] )
					set_background_mode( hdcMem, wxSOLID )
					wx_puts( {hbmMem, 5, 3+(Iter-StartLine)*FontSize[2], hdcMem}, Temp)
					set_background_mode( hdcMem, wxTRANSPARENT )
							
				else
					set_text_color( hdcMem, ColorList[3])
					wx_puts( {hbmMem, 5-StartOff*FontSize[1], YCoord, hdcMem}, Temp )

					if syntax_coloring then

						Temp &= 32 & 32
						Loop = 1
	
						while Loop < length(Temp)-1 do
		
							if Temp[Loop]=0 then
								--not valid file type
								exit
							end if
							if Variable[Temp[Loop]] = 1 then
								for Loop2 = Loop+1 to length(Temp)-1 do
									if Variable[Temp[Loop2]] != 1 then
										Sel1 = Temp[Loop..Loop2-1]
										for list = 1 to length(WordList) do
											if find( Sel1, WordList[list] ) then
												set_text_color( hdcMem, ColorList[list] )
												wx_puts( {hbmMem, 5+(Loop-StartOff-1)*FontSize[1],
													YCoord,hdcMem},Sel1)
												exit
											end if
										end for
										Loop = Loop2 - 1
										exit
									end if
								end for
							elsif Variable[Temp[Loop]] = 3 then
								if Variable[Temp[Loop+1]] = 3 then
									set_text_color( hdcMem, ColorList[6] )
									wx_puts( {hbmMem, 5+(Loop-StartOff-1)*FontSize[1],YCoord,
										hdcMem}, Temp[Loop..length(Temp)-2])
									exit
								end if
							elsif Variable[Temp[Loop]] = 2 then
								Loop3 = Loop+1
								while Loop3 <= length(Temp) do
									if Temp[Loop3] = Temp[Loop] or
									Loop3 = length(Temp) then
										set_text_color( hdcMem, ColorList[7])
										wx_puts( {hbmMem, 5+(Loop-StartOff-1)*FontSize[1],
											YCoord, hdcMem}, Temp[Loop..Loop3])
										Loop = Loop3 + 1
										exit
									elsif Temp[Loop3] = 92 then --47 then
										Loop3 += 1
									end if
									Loop3 += 1
								end while
							end if
							Loop += 1
						end while
					end if
					

				end if
				
				if find( Iter, gbreak_lines[displayed_file] ) then
				
						set_text_color( hdcMem, ColorList[9] )
						set_text_back_color( hdcMem, ColorList[8] )
						set_background_mode( hdcMem, wxSOLID )
	
						wx_puts( {hbmMem, 5, 3+(Iter-StartLine)*FontSize[2], hdcMem}, Temp[1..7])
						set_background_mode( hdcMem, wxTRANSPARENT )
					end if
				YCoord += FontSize[2]
			end for
	
			set_background_mode( hdcMem, wxTRANSPARENT )

		end if
	
		CursorSt = 1
		blit( hDC, 0, 0, hdcMem, 0, 0, SynSizeX, SynSizeY, wxCOPY )
	end if



	set_font( hDC, wxNullFont )
	set_pen( hDC, wxNullPen )
	set_brush( hDC, wxNullBrush )

	end_drawing(hDC)
	
	delete_instance( hDC )

end procedure



-- mouse handler ------------------------------------------------------------------------
procedure onMouse_Syntax( atom this,  atom event_type, atom id, atom event )
	integer ok
	sequence hList, coords, pos
	integer line, col, x, y, ix

	coords = mouse_event_position( event )
	if event_type = wxEVT_LEFT_DOWN then

		pos = mouse_event_position( event)
		x = pos[1]

		y = pos[2]
		line = floor((y-6)/FontSize[2]) + StartLine
		if line > length(Actual) then
			line = length(Actual)
		end if
		col = floor((x-3)/FontSize[1]) + StartOff
		
		if col < 7 then
			-- set / remove breakpoint
			ix = find( line, gbreak_lines[displayed_file] )
			if ix then
				-- remove
				c_proc( set_break_cb, { local_to_global(line), 0 } )
				gbreak_lines[displayed_file] = gbreak_lines[displayed_file][1..ix-1] &
					gbreak_lines[displayed_file][ix+1..$]
			else
				-- set
				gbreak_lines[displayed_file] &= line
				c_proc( set_break_cb, { local_to_global(line), 1 } )
			end if
			refresh_window( editor )			
		end if


	end if

end procedure

-- printable key handler routine --------------------------------------------------------
procedure onKeyPress_SynInput( atom this,  atom event_type, atom id, atom event )
	sequence Temp
	integer RetPos
	sequence Rect
	integer ok, pc, line
	sequence hList, code
	integer trap40
	integer cnt
	integer skipIt
	integer checkPrior
	atom key_code, shift, control

	if CursorY > length(Actual) then
		CursorY = length(Actual)
		CursorX1 = 0
		CursorX2 = 0
	end if

	
	key_code = get_key_code( event )
	shift = key_event_shiftdown( event )
	control = key_event_controldown( event )

	if key_code = 'q' then
		call_proc( stop_forward, {quit, 0,0,0})
	elsif key_code = 'Q' then
		call_proc( stop_forward, {Quit, 0,0,0})	
	elsif key_code = WXK_RETURN then
		call_proc( continue_forward, {0,0,0,0})
	elsif key_code = '!' then
		call_proc( stop_forward, {Abort,0,0,0})
	elsif key_code = '?' then
		set_focus( var_entry )
	elsif key_code = '=' then
		call_proc( change_forward, {0, 0, 0, 0})
	elsif key_code = WXK_DOWN then
		-- down arrow, set a temporary break point...
		pc = c_func( get_pc_cb, {})
		code = SymTab[CurrentSub][S_CODE]
		line = 0
		for i = pc + 1 to length(code) do
			-- opSTART_LINE = 58
			if code[i] = 58 then
				line = code[i+1]
				exit
			end if
			
		end for
		if line then
			if not find( line, gbreak_lines ) then
				c_proc( set_break_cb, {line, 1})
				gbreak_lines &= -line
				c_proc( set_trace_cb, {0})
			end if
		end if
		if platform() = WIN32 then
			poke( m_keepGoing, 0 )
		else
			wait = 0
		end if
	elsif key_code = 3 and control then
		copy_var()
	end if
	

end procedure



-- non-printable key handler routine ----------------------------------------------------
procedure onKeyDown_SynInput( atom this, atom event_type, atom id,	atom event )
	integer ScrollOff
	integer iter
	sequence Temp
	integer ok, pc, break, line
	sequence hList, code
	atom key_code, shift, control, alt

	key_code = get_key_code( event )
	shift = key_event_shiftdown( event )
	control = key_event_controldown( event )
	alt = key_event_altdown( event )

end procedure
kd_rid = routine_id("onKeyDown_SynInput")


-- paint on scroll bar changes ----------------------------------------------------------
procedure onScroll_SynScroll( atom this, atom event_type, atom id,	atom event )
	show_window( Syntax, 1 )
	set_focus( Syntax )

	scrolled = 1
	refresh_window( Syntax )
end procedure

procedure onMouseWheel_Syntax( atom this, atom event_type, atom id, atom event )
	integer rotation

	rotation = floor( call_member_s( wxMouseEvent_GetWheelRotation, event, {}) / 40 )
	Void = get_scroll_position( SynVScroll )
	set_scroll_position( SynVScroll, Void - rotation )	
	set_focus( Syntax )
	refresh_window( Syntax )
end procedure


-- dont erase previous on repaint
-------------------------------------------------------
procedure onEvent_Syntax( atom this,  atom event_type, atom id, atom event )
	integer strLen
	sequence findWhat
	integer Found

	if event_type = wxEVT_SET_FOCUS then
		CarrotVis = True
	elsif event_type = wxEVT_ERASE_BACKGROUND then
		--returnValue( True )
		CarrotVis = True
	else
		skip(event)
	end if
end procedure

--setup environment
integer syntax_firstOpen
syntax_firstOpen=True


-- add a new wordlist to Syntax2 --------------------------------------------------------
global procedure synAddWordList( sequence Name, sequence List, atom Color )	
	WordName = append( WordName, Name )
	WordList = append( WordList, List ) --sort(List) )
	ColorList = append( ColorList, create(wxColour, Color))
end procedure

--procedure to set focus to input after using a control in parent

global procedure synSetText( sequence text )
	sequence printable
	integer len
	Actual = text
	Printable = Actual

	maxcolumn = 1

	for i = 1 to length(Printable) do
		printable = RemoveTabs(Printable[i])
		len = length(printable)
		if len > maxcolumn then
			maxcolumn = len
		end if
		Printable[i] = printable
	end for
	MaxLine = length(Actual)
	set_scrollbar( SynHScroll, 0, 1, maxcolumn - NumLinesX, floor(NumLinesX/2), 1 )
	set_scrollbar( SynVScroll, 0, 1, length(Actual), NumLinesY, 1 )
end procedure

procedure onSize_Syntax( atom this, atom event_type, atom id, atom event )
	set_scrollbar( SynHScroll, 0, 1, maxcolumn - NumLinesX, floor(NumLinesX/2), 1 )
end procedure


-- create a new Syntax2 control ---------------------------------------------------------
global function Syntax2( atom hParent, object x, object y, object cx, object cy, object styleFlags, object exFlags )
	atom hFile, id, timer
	object Data
	atom mset,icon
	atom hLogFont
	atom hChooseFont
	sequence font
	integer points, class
	EnableHL = 1

	ParID = hParent
	if platform() = WIN32 then
		hFont = create( wxFont, {10,wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,0,
			"Courier New"})
	else
		hFont = create( wxFont, {12,wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,0,
			"Courier"})
	end if

	-- Syntax2 control
	SynFrame = hParent
	if platform() = WIN32 then
		class = wxWindow
	else
		class = wxPanel
	end if
	
	Syntax		= create( class, { SynFrame, -1,-1,-1,-1,-1, wxCLIP_CHILDREN + wxSUNKEN_BORDER + wxWANTS_CHARS })
	SynPix		  = create( wxBitmap, {BM_IN_MEMORY, 1,1,-1})
	SynVScroll	  = create( wxScrollBar,{ SynFrame, -1,-1,-1,-1,-1,wxVERTICAL} )
	SynHScroll	  = create( wxScrollBar,{ SynFrame, -1,-1,-1,-1,-1,wxHORIZONTAL})
	CursorPix	 = create( wxBitmap,{BM_IN_MEMORY, 2,1,-1})

	vert_sizer = create( wxBoxSizer, {wxVERTICAL})
	horz_sizer = create( wxBoxSizer, {wxHORIZONTAL})
	
	add_window_to_sizer( vert_sizer, Syntax, 1, wxGROW, 5)
	add_window_to_sizer( vert_sizer, SynHScroll,0, wxGROW+wxBOTTOM, 0)

	add_sizer_to_sizer( horz_sizer, vert_sizer, 1, wxGROW+wxTOP, 0 )
	add_window_to_sizer( horz_sizer, SynVScroll, 0, wxGROW+wxBOTTOM, 16 )

	set_sizer( hParent, horz_sizer )


	-- set handlers
	id = get_id( hParent )
	set_event_handler( hParent, id, wxEVT_SHOW, routine_id("onOpen_MainWin"))

	id = get_id(Syntax)
	set_event_handler( Syntax, id, {wxEVT_SET_FOCUS,wxEVT_ERASE_BACKGROUND}, routine_id("onEvent_Syntax"))
	set_event_handler( Syntax, id, wxEVT_SIZE, routine_id("onSize_Syntax"))
	set_event_handler( Syntax, id, wxEVT_PAINT, routine_id("onPaint_Syntax"))
	set_event_handler( Syntax, -1, {wxEVT_LEFT_DOWN, wxEVT_RIGHT_DOWN, 
		wxEVT_LEFT_UP, wxEVT_RIGHT_UP, wxEVT_MOTION}, routine_id("onMouse_Syntax"))
	set_event_handler( Syntax, -1, wxEVT_MOUSEWHEEL, routine_id("onMouseWheel_Syntax"))
	set_event_handler( Syntax, -1, wxEVT_CHAR, routine_id("onKeyPress_SynInput"))

	id = get_id(SynVScroll)
	set_event_handler( SynVScroll, id, wxEVT_SCROLL, routine_id("onScroll_SynScroll"))
	set_event_handler( SynHScroll, get_id(SynHScroll), wxEVT_SCROLL, routine_id("onScroll_SynScroll"))

	BlinkTime = 500

	set_default_font( Syntax, hFont )
	FontSize = get_text_extent( Syntax, "D", 0 )
	FontSize[2] += 1

	set_bitmap_size( CursorPix, 2, FontSize[2] )

	-- set default vals for colors
	synAddWordList( "Background", {}, {#F8,#F8,#F8} )
	synAddWordList( "Cursor", {}, {#00,#00,#FF} )
	synAddWordList( "Default text", {}, {#00,#00,#00} )
	synAddWordList( "Selection back", {}, {#70,#90,#B0} )
	synAddWordList( "Selection text", {}, {#FF,#00FF,#00FF} )
	synAddWordList( "Comment", {}, {128,0,#00} )
	synAddWordList( "String", {}, {0,128,#00} )
	synAddWordList( "Break Back", {}, {#FF,#00,#00} ) --getSysColor(COLOR_INFOBK) )
	synAddWordList( "Break Text", {}, {#FF,#FF,#FF} )
	synAddWordList( "Hint Param", {}, {#FF,#00,#00} )
	synAddWordList( "Keywords", eu_keywords, {#0,#00,128})
	synAddWordList( "Builtins", eu_builtins, {128,#00,128})
	synAddWordList( "Library", eu_library, {  0, 128, 128 })

	NumDeflts = length( WordList )

	return( Syntax )
end function
