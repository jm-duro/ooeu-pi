-- Euphoria 2.5
-- Front End - main routine 

include file.e
include get.e
include pathopen.e

function ProcessOptions()
-- record command line options, return source file number
    integer src_file
    boolean dot_found
    sequence src_name, raw_name
    -- begin mwl
    if Argc >= 3 then
	if equal( Argv[3], "-s" ) then
		-- not executing, just outputing it to an 'oe' file
		execute = 0
		Argv = Argv[1..2] & Argv[4..$]
		Argc -= 1
	elsif equal( Argv[3], "-b" ) then
		-- not executing, but binding to the executable
		execute = 0
		bind = 1
		Argv = Argv[1..2] & Argv[4..$]
		Argc -= 1
	elsif equal( Argv[3], "-p" ) then
		-- preprocess and ouput RDS compatible code
		execute = 0
		preprocess = 1
		Argv = Argv[1..2] & Argv[4..$]
		Argc -= 1
		
	elsif equal( Argv[3], "-c" ) then
		-- precompile
		execute = 0
		delete_symbols = 0
		Argv = Argv[1..2] & Argv[4..$]
		Argc -= 1	
		full_debug = 1	
	end if
	
	if not execute then
	if equal( Argv[3], "-full_debug" ) then
		full_debug = 1
		Argv = Argv[1..2] & Argv[4..$]
		Argc -= 1
	end if
	else
		full_debug = 1
	end if
    end if
    
    -- check for precompiled files...
    while Argc > 3 and equal( Argv[3], "-i" ) do
    	precompiled = append( precompiled, Argv[4] )
    	Argv = Argv[1..2] & Argv[5..$]
    	Argc -= 2
    end while
    -- end mwl
    
    if Argc >= 3 then
		src_name = Argv[3]
    else 
		screen_output(STDERR, sprintf("Object Oriented Euphoria v%d.%d.%d\n", OOEU_VERSION ) )
		if INTERPRET and not BIND then
		    screen_output(STDERR, "Based on Euphoria Interpreter " & 
					  INTERPRETER_VERSION & " ")
		end if

		if ELINUX then
		    if EBSD then
			screen_output(STDERR, "for FreeBSD.\n")
		    else
			screen_output(STDERR, "for Linux.\n")
		    end if
		else
		    if (BIND and w32) or EWINDOWS then
			screen_output(STDERR, "for 32-bit Windows.\n")
		    else
			screen_output(STDERR, "for 32-bit DOS.\n")
		    end if
		end if


	     screen_output(STDERR, 
		 "Source code provided by Rapid Deployment Software \n")
	     screen_output(STDERR, 
		 "http://www.RapidEuphoria.com \n")
	     screen_output(STDERR, 
		 "Rapid Deployment Software is not responsible for any damage. \n")
	     
	     screen_output(STDERR,
		"Modified by Matt Lewis \n")
	
		    screen_output(STDERR, "\nfile name to execute? ")
		src_name = gets(STDIN)
	
		screen_output(STDERR, "\n")
    
	-- remove leading blanks
	while length(src_name) and find(src_name[1], " \t\n") do
	    src_name = src_name[2..$]
	end while
	
	if length(src_name) = 0 then
	    Cleanup(1)
	end if
	
	-- remove trailing blanks
	while length(src_name) and find(src_name[$], " \t\n") do
	    src_name = src_name[1..$-1]
	end while
	
	-- add src_name as 2nd arg for command_line()
	Argc = 2
	Argv = {Argv[1], src_name}
	-- .ex or .exw might be added to src_name below
    end if
    
    -- check src_name for '.' */
    dot_found = FALSE
    for p = 1 to length(src_name) do
	if src_name[p] = '.' then
	   dot_found = TRUE
	elsif find(src_name[p], SLASH_CHARS) then
	   dot_found = FALSE
	end if
    end for 
    
    raw_name = src_name
    
    if not dot_found then
	-- no dot found */
	if ELINUX then
	    src_name &= ".exu"
	else
	    if (BIND and w32) or EWINDOWS then
		src_name &= ".exw"
	    else
		src_name &= ".ex"
	    end if
	end if
    end if

    file_name = append(file_name, src_name)
    src_file = e_path_open(src_name, "r")

    if ELINUX then
	if src_file = -1 then
	    -- do this especially so #! will work on Linux without .exu extension 
	    src_file = open(raw_name, "r")      
	    if src_file != -1 then
		src_name = raw_name
	    end if
	end if
    end if  
	-- begin mwl
	source_name = src_name
	-- end mwl
    return src_file
end function

function full_path(sequence filename)
-- return the full path for a file
    integer p
    p = length(filename)
    while p >= 1 do
	if find(filename[p], SLASH_CHARS) then
	    return filename[1..p]
	end if
	p -= 1
    end while
    -- begin mwl
    -- make the main_path ablsolute:
	return current_dir() & SLASH
    -- return '.' & SLASH  
	-- end mwl

end function

procedure deref( symtab_index sym )
	sequence refs
	symtab_index ref
	if length(SymTab[sym]) < S_REFLIST or atom( SymTab[sym][S_REFLIST] ) then
		return
	end if
	refs = SymTab[sym][S_REFLIST]
	for i = 1 to length(refs) do
		ref = refs[i]
		if length(SymTab[ref]) >= S_NREFS then
			SymTab[ref][S_NREFS] += 1
			deref( ref )
		end if
		
	end for
end procedure

sequence deleted
integer oe_deleted

procedure patch_next( symtab_index sym )

	if length( SymTab[sym] ) < S_NEXT then
		return
	end if

	for s = TopLevelSub to length(SymTab) do
		if length(SymTab[s]) >= S_NEXT and SymTab[s][S_NEXT] = sym then
			SymTab[s][S_NEXT] = SymTab[sym][S_NEXT]
			exit
		end if
	end for

end procedure

procedure record_deleted( symtab_index sym )
	if length(SymTab[sym]) < S_NAME or sym < TopLevelSub then
		return
	end if

	printf( oe_deleted, "%s: %s\n", {file_name[SymTab[sym][S_FILE_NO]], SymTab[sym][S_NAME]})

end procedure

procedure delete_refs( symtab_index sym )
	sequence refs
	symtab_index ref
	if length(SymTab[sym]) = 1 then
		return
	elsif atom(SymTab[sym][S_REFLIST]) then
		if not eval_used or
		(not file_eval[SymTab[sym][S_FILE_NO]] or SymTab[sym][S_SCOPE] = SC_GLOBAL) then
			record_deleted( sym )
			patch_next( sym )
			SymTab[sym] = {0}
		end if
		return
	end if
	refs = SymTab[sym][S_REFLIST]
	for i = 1 to length(refs) do
		ref = refs[i]
		if length(SymTab[ref]) >= S_NREFS then
			if not SymTab[ref][S_NREFS] then
				if length(SymTab[ref]) = SIZEOF_ROUTINE_ENTRY then
--					if not find( '@', SymTab[ref][S_NAME]) then
						delete_refs( ref )
--					end if
					
				else
					if not eval_used and SymTab[ref][S_NREFS] = 0 then
					if not file_eval[SymTab[ref][S_FILE_NO]] or SymTab[ref][S_SCOPE] = SC_GLOBAL then
						if SymTab[ref][S_MODE] = M_CONSTANT then
							deleted[1] += 1
						else
							deleted[3] += 1
						end if
						record_deleted( ref )
						patch_next( ref )
						SymTab[ref] = {0}
					end if					
					end if

				end if
			end if

		end if          
	end for
	

end procedure

procedure delete_unused()
	integer ix, len
	
	if not delete_symbols then
		return
	end if
	oe_deleted = open( "oe_deleted.txt", "w" )
	
	ix = 1
	deleted = repeat( 0, 3 )
	-- delete unused symbols:
	SymTab[TopLevelSub][S_NREFS] = 1
	deref( TopLevelSub )
	for i = TopLevelSub + 2 to length(SymTab) do
		len = length(SymTab[i])
		if len > 1 then
			if (SymTab[i][S_USAGE] = U_UNUSED) or
			(len > SIZEOF_TEMP_ENTRY and SymTab[i][S_NREFS] = 0 ) then
				if SymTab[i][S_MODE] = M_CONSTANT then --and not find( '@', SymTab[i][S_NAME] ) then
					deleted[1] += 1
					record_deleted( i )
					patch_next( i )
					SymTab[i] = {0}						


				elsif length(SymTab[i]) = SIZEOF_ROUTINE_ENTRY and not SymTab[i][S_NREFS]
				then --and not find( '@', SymTab[i][S_NAME]) then
					-- delete privates
					if not eval_used or 
					(not file_eval[SymTab[i][S_FILE_NO]] or SymTab[i][S_SCOPE] = SC_GLOBAL) then
						delete_refs( i )
						record_deleted( i )
						patch_next( i )
	
						SymTab[i] = {0}
						deleted[2] += 1
					end if
				end if
				
			end if                  
		end if
	end for
	
	printf(2, "Deleted %d constants, %d routines and %d variables\n", deleted )
end procedure

procedure make_bound()
	integer exe, bound, byte, location, ix, ok
	sequence exe_name, bound_name
	delete_unused()
	exe_name = Argv[1]

	exe = open( exe_name, "rb" )
	if exe = -1 then
		-- try looking in the euphoria/bin directory:
		for j = length(exe_name) to 1 by -1 do
			if exe_name[j] = SLASH then
				exe_name = exe_name[j..$]
				exit
			end if
		end for
		exe_name = eudir & SLASH & "bin/" & exe_name
		exe = open( exe_name, "rb" )
		if exe = -1 then
			-- couldn't get the executable with which to bind...
			printf(2, "Error opening %s while attempting to bind...\n", {exe_name})
			if wait_key() then end if
			abort(-1)                       
		end if
	end if
	
	bound_name = reverse( source_name )
	
	-- remove extension
	ix = find('.', bound_name)
	if ix then
		bound_name = bound_name[ix+1..$]
	end if
	bound_name = reverse( bound_name )
	
	if EWINDOWS or EDOS then
		bound_name &= ".exe"
	end if
	
	bound = open( bound_name, "wb" )
	byte = getc( exe )
	while byte != -1 do
		puts( bound, byte )
		byte = getc( exe )
	end while
	close( exe )
	ok = seek( bound, -1 )
	location = where( bound )
	puts( bound, compress_symtab( SymTab[TopLevelSub..$] ) )
	puts( bound, int_to_bytes( location ) )
	puts( bound, "oe bound executable" )
	close( bound )
	if platform() = LINUX then
		system( "chmod 775 " & bound_name, 0 )
	end if
end procedure

-- begin mwl
procedure save_parsed_code()
	integer fn
	sequence name
	delete_unused()
	name = source_name
	for i = length(source_name) to 1 by -1 do
		if name[i] = '.' then
			name = source_name[1..i-1]
			exit
		end if
	end for
	name &= ".oe"
	fn = open( name, "wb" )
	write_symtab( fn, SymTab[TopLevelSub..$] )
	close( fn )
	
	-- a little debugging output:
--      fn = open( source_name & ".sym", "w" )
--      for i = TopLevelSub to length(SymTab) do
--              print(fn, i & SymTab[i] ) puts(fn, "\n")
--      end for
--      close(fn)
end procedure

procedure load_parsed_code()
	integer fn, hashval
    sequence kname, table
	fn = open( source_name, "rb" )
	
	SymTab = SymTab[1..$-2]
	table = read_symtab( fn )
	Code = table[1][S_CODE]
	SymTab &= table

	close( fn )
    
    
    for k = 1 to length(SymTab) do 
	if length(SymTab[k]) >= S_NAME then
		
			kname = SymTab[k][S_NAME]
	
		    if equal(kname, "object") then
				object_type = k
		    elsif equal(kname, "atom") then
				atom_type = k
		    elsif equal(kname, "integer") then
				integer_type = k
		    elsif equal(kname, "sequence") then
				sequence_type = k
		    end if
		    
		    if use_eval or length(precompiled) and length(kname) then
			    hashval = hashfn( kname )
			    SymTab[k][S_HASHVAL] = hashval
			    if buckets[hashval] and buckets[hashval] != k then
			    	SymTab[k][S_SAMEHASH] = buckets[hashval]
			    end if
			    buckets[hashval] = k		    	
		    end if
		end if
    end for

end procedure
-- end mwl

procedure load_bound_code( integer fn )
    sequence kname, table
    integer hashval

	SymTab = SymTab[1..$-2]
	table = read_symtab( fn )

	Code = table[1][S_CODE]
	SymTab &= table

	close( fn )

    for k = 1 to length(SymTab) do 
	if length(SymTab[k]) >= S_NAME then
		
			kname = SymTab[k][S_NAME]
		    if equal(kname, "object") then
				object_type = k
		    elsif equal(kname, "atom") then
				atom_type = k
		    elsif equal(kname, "integer") then
				integer_type = k
		    elsif equal(kname, "sequence") then
				sequence_type = k
		    end if
		    if use_eval then
			    hashval = hashfn( kname )
			    SymTab[k][S_HASHVAL] = hashval
			    if buckets[hashval] and buckets[hashval] != k then
			    	SymTab[k][S_SAMEHASH] = buckets[hashval]
			    end if
			    buckets[hashval] = k		    	
		    end if
		end if
    end for

end procedure

-- begin mwl
global procedure post_process( )
	-- preprocessing the program, so write out the 
	-- files that were processed
	integer pfile
	sequence fname
	system( "mkdir preprocess", 0)  
	puts(2, "Ouputting preprocessed files.\n")
	for file = 1 to length(processed_files) do
		fname = file_name[processed_files[file]]
		if find( SLASH, fname ) then
			for j = length(fname) to 1 by -1 do
				if fname[j] = SLASH then
					fname = fname[j+1..$]
					exit
				end if
			end for
		end if
		printf(2, "preprocess%s%s\n", { SLASH, fname})
		pfile = open( sprintf("preprocess%s%s", { SLASH, fname }), "w" )
		if atom(slist[$]) then
			slist = s_expand( slist )
		end if
		for l = 1 to length( slist ) do
			if slist[l][LOCAL_FILE_NO] = processed_files[file] then
				if atom(slist[l][SRC]) then
					slist[l][SRC] = fetch_line(slist[l][SRC])
				end if
				puts( pfile, slist[l][SRC] & '\n' )
			end if
		end for
		close( pfile )
	end for

end procedure
POST_PROCESS_RID = routine_id("post_process")

procedure set_eudir()
    eudir = getenv("EUDIR")
    if atom(eudir) then
	if ELINUX then
	    -- should check search PATH for euphoria/bin ?
	    eudir = getenv("HOME")
	    if atom(eudir) then
		eudir = "euphoria"  
	    else 
		eudir = eudir & "/euphoria"
	    end if
	else
	    eudir = "\\EUPHORIA"
	end if
    end if
end procedure
-- end mwl

procedure main()
-- Main routine 
    integer argc
    sequence argv
    
    -- begin mwl
    integer exe, location, ok, pfile
    sequence fname
    -- end mwl

    -- we have our own, possibly different, idea of argc and argv
    argv = command_line()

    if BIND then
		argv = extract_options(argv)
    end if

    argc = length(argv)  

    Argv = argv
    Argc = argc
    
	set_eudir()
    TempErrName = "ex.err"           

    if TRANSLATE then
	InitBackEnd()  -- for translator
    end if
    
    -- begin mwl
    -- check to see if bound
    exe = open( Argv[1], "rb" )
    if exe > -1 then
		ok = seek( exe, -1 )
		location = where( exe )
		ok = seek( exe, location - 19 )
		if equal( get_bytes( exe, 19 ), "oe bound executable" ) then
			bound = 1
			source_name = Argv[1]
			ok = seek( exe, location - 23 )
			location = getc( exe ) + getc( exe ) * #100 
				+ getc( exe ) * #10000 + getc( exe ) * #1000000
	
			ok = seek( exe, location )
			InitGlobals()
			InitSymTab()
			InitEmit()
			InitParser()
			InitLex()
			main_path = full_path(Argv[1])
			load_bound_code( exe )
			no_source = 1
			InitBackEnd()
			BackEnd( 0 )
		else
			close( exe )
		end if
	
    end if
    -- end mwl
    if not bound then
	
	    src_file = ProcessOptions()
	
	    if src_file = -1 then
		-- too early for normal error processing
		screen_output(STDERR, sprintf("Can't open %s\n", {file_name[1]}))
		if BIND or EWINDOWS or ELINUX then
		    screen_output(STDERR, "\nPress Enter\n")
		    if getc(0) then
		    end if
		end if
		Cleanup(1)
	    end if
	
	    main_path = full_path(file_name[1])  
		-- begin mwl
		
	    InitGlobals()
	    InitSymTab()

		precompiled = append( precompiled, source_name )
	    for i = 1 to length(precompiled)-1 do
	    	source_name = precompiled[i]
	    	load_parsed_code()
	    end for
	    source_name = precompiled[$]
	    if length(precompiled) > 1 then
	    	file_name = append( file_name, source_name )
	    end if
	    


	    current_file_no = length(file_name)
		if match( ".oe", lower(source_name) ) = (length(source_name) - 2) then
			InitEmit()
			InitParser()
			InitLex()
			read_line()
			-- running already parsed code
			load_parsed_code()
			no_source = 1


		else
			if bind then
				puts(2, "Binding source files\n")
			elsif preprocess then
				puts(2, "Preprocessing source files\n")
			elsif not execute then
				puts(2, "Shrouding source files\n")

			end if
		-- end mwl      
		    InitEmit()
		    InitParser()
		    InitLex()
		    read_line()
		    parser()
		end if
		
	    -- we've parsed successfully
	    -- now run the appropriate back-end 
	    if TRANSLATE then
			BackEnd(0) -- translate IL to C
	    
	    elsif INTERPRET then
			if execute then

				InitBackEnd()
				-- begin mwl


				BackEnd(0) -- execute IL using Euphoria-coded back-end                  
			elsif bind then
			
				make_bound()
				
			elsif preprocess then
				-- preprocessing the program, so write out the 
				-- files that were processed
				post_process( )

			else
				save_parsed_code()
			end if
	    end if
	end if
    Cleanup(0) -- does warnings

end procedure

if EMBEDDED then
	InitGlobals()
	InitSymTab()
	InitEmit()
	InitParser()
	InitLex()
	InitBackEnd()
	src_file = -1
	source_name = "embedded"
	main_path = full_path( "" )
	set_eudir()
else
	main()
end if

