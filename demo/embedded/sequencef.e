include machine.e
include global.e 
integer current_db
function get1()
-- read 1-byte value at current position in database file
    return getc(current_db)
end function

atom mem0, mem1, mem2, mem3
mem0 = allocate(4)
mem1 = mem0 + 1
mem2 = mem0 + 2
mem3 = mem0 + 3

function get4()
-- read 4-byte value at current position in database file
    poke(mem0, getc(current_db))
    poke(mem1, getc(current_db))
    poke(mem2, getc(current_db))
    poke(mem3, getc(current_db))
    return peek4u(mem0)
end function

function get_string()
-- read a 0-terminated string at current position in database file
    sequence s
    integer c
    
    s = ""
    while TRUE do
	c = getc(current_db)
	if c = -1 then
--	    fatal("string is missing 0 terminator")
		puts(2, "string is missing 0 terminator")
		abort(0)
	elsif c = 0 then
	    exit
	end if
	s &= c
    end while
    return s
end function

-- Compressed format of Euphoria objects on disk
--
-- First byte:
--          0..248    -- immediate small integer, -9 to 239
		      -- since small negative integers -9..-1 might be common
constant I2B = 249,   -- 2-byte signed integer follows
	 I3B = 250,   -- 3-byte signed integer follows
	 I4B = 251,   -- 4-byte signed integer follows
	 F4B = 252,   -- 4-byte f.p. number follows
	 F8B = 253,   -- 8-byte f.p. number follows
	 S1B = 254,   -- sequence, 1-byte length follows, then elements
	 S4B = 255    -- sequence, 4-byte length follows, then elements

constant MIN1B = -9,
	 MAX1B = 239,
	 MIN2B = -power(2, 15),
	 MAX2B =  power(2, 15)-1,
	 MIN3B = -power(2, 23),
	 MAX3B =  power(2, 23)-1,
	 MIN4B = -power(2, 31)

function decompress(integer c)
-- read a compressed Euphoria object from disk
-- if c is set, then c is not <= 248    
    sequence s
    integer len
    
    if c = 0 then
		c = getc(current_db)
		if c < I2B then
		    return c + MIN1B
		end if
    end if
    
    if c = I2B then
	return getc(current_db) + 
	       #100 * getc(current_db) +
	       MIN2B
    
    elsif c = I3B then
	return getc(current_db) + 
	       #100 * getc(current_db) + 
	       #10000 * getc(current_db) +
	       MIN3B
    
    elsif c = I4B then
	return get4() + MIN4B
    
    elsif c = F4B then
	return float32_to_atom({getc(current_db), getc(current_db), 
				getc(current_db), getc(current_db)})
    elsif c = F8B then
	return float64_to_atom({getc(current_db), getc(current_db),
				getc(current_db), getc(current_db),
				getc(current_db), getc(current_db),
				getc(current_db), getc(current_db)})
    else
	-- sequence
	if c = S1B then
	    len = getc(current_db)
	else
	    len = get4()
	end if
	s = repeat(0, len)
	for i = 1 to len do
	    -- in-line small integer for greater speed on strings
	    c = getc(current_db)
	    if c < I2B then
		s[i] = c + MIN1B
	    else
		s[i] = decompress(c)
	    end if
	end for
	return s
    end if
end function

global function compress(object x)
-- return the compressed representation of a Euphoria object 
-- as a sequence of bytes
    sequence x4, s
    
    if integer(x) then
	if x >= MIN1B and x <= MAX1B then
	    return {x - MIN1B}
	    
	elsif x >= MIN2B and x <= MAX2B then
	    x -= MIN2B
	    return {I2B, and_bits(x, #FF), floor(x / #100)}
	    
	elsif x >= MIN3B and x <= MAX3B then
	    x -= MIN3B
	    return {I3B, and_bits(x, #FF), and_bits(floor(x / #100), #FF), floor(x / #10000)}
	    
	else
	    return I4B & int_to_bytes(x-MIN4B)    
	    
	end if
    
    elsif atom(x) then
	-- floating point
	x4 = atom_to_float32(x)
	if x = float32_to_atom(x4) then
	    -- can represent as 4-byte float
	    return F4B & x4
	else
	    return F8B & atom_to_float64(x)
	end if

    else
	-- sequence
	if length(x) <= 255 then
	    s = {S1B, length(x)}
	else
	    s = S4B & int_to_bytes(length(x))
	end if  
	for i = 1 to length(x) do
	    s &= compress(x[i])
	end for
	return s
    end if
end function

global function read_symtab( integer fn )
	sequence symtab, sym, line_change, magic
	integer entries, old_file, line
	object len
	current_db = fn
	if compare( getc(fn)&getc(fn)&getc(fn)&getc(fn), MAGIC_NUMBER ) then
		puts(2, "Invalid oe file\n\nPress Enter...\n" )
		while getc(0) != '\n' do
			
		end while
		abort(1)
	end if 
	if getc(fn) != SHROUD_VERSION then
		puts(2, "Incompatible shroud version\n\nPress Enter...\n" )
		while getc(0) != '\n' do
			
		end while
		abort(1)	
	end if 
	full_debug = getc( fn )
	use_eval = getc( fn )
	entries = decompress( 0 )
	symtab = repeat( {0}, entries )
	for s = 1 to entries do
		len = getc( fn )
		if len then
			sym = repeat( 0, len )

			if len = 5 then
				sym[S_OBJ] = decompress( 0 )
			elsif getc( fn ) then
				sym[S_OBJ] = decompress( 0 )
			end if
			
			sym[S_NEXT] = decompress( 0 )
			sym[S_MODE] = getc( fn )
			sym[S_SCOPE] = getc( fn )
			if len > S_USAGE then
				sym[S_FILE_NO] = getc( fn )
				if use_eval or full_debug or len > S_VTYPE then
					sym[S_NAME] = decompress( 0 )
				else
					sym[S_NAME] = ""
				end if
				
				sym[S_TOKEN] = decompress( 0 )
--				if use_eval then
					sym[S_VTYPE] = decompress( 0 )
--				end if
				
				if len > S_VTYPE then
					sym[S_CODE] = decompress( 0 )
					sym[S_LINETAB] = decompress( 0 )
					sym[S_FIRSTLINE] = decompress( 0 )
					sym[S_TEMPS] = decompress( 0 )
					sym[S_NUM_ARGS] = getc( fn )
					sym[S_GOTO] = decompress( 0 )
					sym[S_BYREF] = decompress( 0 )
				end if
			end if
			symtab[s] = sym
		end if
	end for
	file_name = decompress( 0 )

	slist = repeat( {0,0,0,0}, decompress(0))
	if full_debug then
		for i = 1 to length(slist) do
			slist[i][1] = decompress(0)
			slist[i][2] = decompress(0)
			slist[i][3] = decompress(0)
		end for
	else
		line = 1
		for until = 1 to decompress(0) do
			line_change = decompress(0)
			old_file = line_change[1]
			for s = line to line_change[2] do
				slist[s][LINE] = s
				slist[s][LOCAL_FILE_NO] = old_file
			end for
			line = line_change[2] + 1
		end for
	end if
	return symtab	
end function

function s_expand(sequence slist)
-- expand slist to full size if required
    sequence new_slist
    
    new_slist = {}
    
    for i = 1 to length(slist) do
	if sequence(slist[i]) then
	    new_slist = append(new_slist, slist[i])
	else
	    for j = 1 to slist[i] do
		slist[i-1][LINE] += 1
		new_slist = append(new_slist, slist[i-1]) 
	    end for
	end if
    end for
    return new_slist
end function

global procedure write_symtab( integer fn, sequence symtab )
	sequence sym, line_change
	integer len, old_file
	
	if atom(slist[$]) then
		slist = s_expand( slist )
	end if
	puts( fn, MAGIC_NUMBER )
	puts( fn, SHROUD_VERSION )
	puts( fn, full_debug )
	use_eval = find( 1, file_eval ) != 0 
	puts( fn, use_eval )
	
	puts( fn, compress( length(symtab) ) )
	for s = 1 to length(symtab) do
		sym = symtab[s]
		len = length(sym)
		if len = 1 then
			puts( fn, 0 )
		else
			puts( fn, length(sym) )
			if len = 5 then
				puts( fn, compress( sym[S_OBJ] ))
			elsif compare(sym[S_OBJ], NOVALUE) then
				puts( fn, 1 & compress( sym[S_OBJ] ))
			else
				puts( fn, 0 )
			end if
			
			puts( fn, compress( sym[S_NEXT] ))
			puts( fn, sym[S_MODE..S_SCOPE] )
			if len > S_USAGE then
				puts( fn, sym[S_FILE_NO] )
				if use_eval or full_debug or len > S_VTYPE then
					puts( fn, compress( sym[S_NAME] ))
				end if
				
				puts( fn, compress( sym[S_TOKEN] ))
				
--				if use_eval or full_debug then
					puts( fn, compress( sym[S_VTYPE] ))
--				end if
				
				if len > S_VTYPE then
					puts( fn, compress( sym[S_CODE] ) )
					puts( fn, compress( sym[S_LINETAB] ) )
					puts( fn, compress( sym[S_FIRSTLINE] ) )
					puts( fn, compress( sym[S_TEMPS] ) )
					puts( fn, sym[S_NUM_ARGS] )
					puts( fn, compress(sym[S_GOTO]) )
					puts( fn, compress(sym[S_BYREF]) )
				end if
			end if
		end if
	end for
	
	puts(fn, compress( file_name ) )
	if atom(slist[$]) then
		slist = s_expand( slist )
		slist = slist[1..$-1]
	end if	
	puts(fn, compress( length( slist ) ))
	if full_debug then
		for i = 1 to length(slist) do
			if atom( slist[i][SRC] ) then
				slist[i][SRC] = fetch_line( slist[i][SRC] )
			end if
			puts( fn, compress( slist[i][SRC]) )
			puts( fn, compress( slist[i][2]) )
			puts( fn, compress( slist[i][3]) )
		end for
	else
		line_change = {}
		old_file = slist[1][LOCAL_FILE_NO]
		len = 1
		for i = 1 to length(slist) do
			if old_file != slist[i][LOCAL_FILE_NO] then
				
				line_change &= compress( old_file & i )
				len += 1
				old_file = slist[i][LOCAL_FILE_NO]
			end if
		end for
		line_change &= compress( old_file & length(slist))
		puts( fn, compress( len ))
		puts( fn,  line_change	)
	end if
	
end procedure

global function compress_symtab( sequence symtab )
--	puts( fn, compress( symtab ) )
	sequence sym, st, line_change
	integer len, old_file
	object void
	use_eval = find( 1, file_eval ) != 0 
	st = MAGIC_NUMBER & SHROUD_VERSION & full_debug & use_eval
	st &= compress( length(symtab) )
	for s = 1 to length(symtab) do
		sym = symtab[s]
		len = length(sym)
		if len = 1 then
			st &= 0
		else
			st &= length(sym)
			if len = 5 then
				st &= compress( sym[S_OBJ] )
			elsif sym[S_OBJ] != NOVALUE then
				st &= 1 & compress( sym[S_OBJ] )
			else
				st &= 0
			end if
			st &= compress( sym[S_NEXT] )
			st &= sym[S_MODE..S_SCOPE] 
			if len > S_USAGE then
				st &= sym[S_FILE_NO] 
				if full_debug or use_eval or len > S_VTYPE then
					st &= compress( sym[S_NAME] )
				end if
				
				st &= compress( sym[S_TOKEN] )
--				if use_eval then
					st &= compress( sym[S_VTYPE] )
--				end if
				
				if len > S_VTYPE then
					st &= compress( sym[S_CODE] ) 
					st &= compress( sym[S_LINETAB] ) 
					st &= compress( sym[S_FIRSTLINE] )
					st &= compress( sym[S_TEMPS] )
					st &= sym[S_NUM_ARGS] 
					st &= compress( sym[S_GOTO] )
					st &= compress( sym[S_BYREF] )
				end if
			end if
		end if
	end for
	st &= compress( file_name )
	if atom(slist[$]) then
		slist = s_expand( slist )
		slist = slist[1..$-1]
	end if
	st &= compress( length(slist) )
	if full_debug then
		for i = 1 to length(slist) do
			st &= compress( slist[i][1] )
			st &= compress( slist[i][2] )
			st &= compress( slist[i][3] )
		end for		
	else
		line_change = {}
		old_file = slist[1][LOCAL_FILE_NO]
		len = 1
		if atom(slist[$]) then
			slist = s_expand( slist )
			slist = slist[1..$-1]
		end if
		for i = 1 to length(slist) do
		void = slist[i]
			if old_file != slist[i][LOCAL_FILE_NO] then
				old_file = slist[i][LOCAL_FILE_NO]
				line_change &= compress( old_file & i )
				len += 1
			end if
		end for
		line_change &= compress( old_file & length(slist))
		st &= compress( len )
		st &= line_change
	end if

	return st
end function
