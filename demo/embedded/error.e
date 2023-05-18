-- Euphoria 2.5
-- Compile-time Error Handling

include machine.e

-- 22 + the final "too many" warning
constant MAX_WARNINGS = 23
global constant STDIN = 0, STDERR = 2

integer Errors 
Errors = 0   -- number of errors detected during compile 

global integer TempErrFile
global sequence TempErrName
global object ThisLine        -- current line of source (or -1)
global integer bp             -- input line index of next character 

sequence warning_list
warning_list = {}

global procedure screen_output(integer f, sequence msg)
-- output messages to the screen or a file    
    puts(f, msg)
end procedure

global procedure Warning(sequence msg)
-- add a warning message to the list
    sequence p
--?1/0   
    if OpWarning and length(warning_list) < MAX_WARNINGS then
	if length(warning_list) = MAX_WARNINGS-1 then
	    p = "Too many warnings - no more will be issued"
	else 
	    p = sprintf("Warning: %s\n", {msg})
	    if find(p, warning_list) then
		return -- duplicate
	    end if
	end if
	warning_list = append(warning_list, p)          
    end if
end procedure

global function ShowWarnings(integer errfile)
-- print the warnings to the screen (or ex.err)
    for i = 1 to length(warning_list) do
	if errfile = 0 then
	    screen_output(STDERR, warning_list[i])
	else
	    puts(errfile, warning_list[i])
	end if
    end for
    return length(warning_list)
end function

global procedure Cleanup(integer status)
-- clean things up before quitting
    integer w

    w = ShowWarnings(0) 
    
    if not TRANSLATE and 
       (BIND or EWINDOWS or ELINUX) and 
       (w or Errors) then
	if getc(0) then -- prompt
	end if
    end if
    
    -- begin mwl
	if debugger > 0 then
		c_proc( cleanup_cb, {})
		debugger = 0
	end if
	
	-- Uncomment the following to get eu.ex tracebacks for where an error 
	-- ocurred.  This is useful for development and debugging eu.ex:
--	if status = -1 then
--		? 1/0
--	end if
	-- end mwl
	
    abort(status)
end procedure

global procedure OpenErrFile()
-- open the error diagnostics file - normally "ex.err"
    TempErrFile = open(TempErrName, "w")
    if TempErrFile = -1 then
	if length(TempErrName) > 0 then
	    screen_output(STDERR, "Can't create error message file: ")
	    screen_output(STDERR, TempErrName)
	    screen_output(STDERR, "\n")
	end if
	abort(1) --Cleanup(1)
    end if
end procedure

procedure ShowErr(integer f)
-- Show place where syntax error occurred  
    if length(file_name) = 0 then
	return
    end if
    if ThisLine[1] = END_OF_FILE then
	screen_output(f, "<end-of-file>\n")
    else
	screen_output(f, ThisLine)
    end if
    
    for i = 1 to bp-2 do
	if ThisLine[i] = '\t' then
	    screen_output(f, "\t")
	else
	    screen_output(f, " ")
	end if
    end for
    screen_output(f, "^\n\n") 
end procedure

global procedure CompileErr(sequence msg)
-- Handle fatal compilation errors 
    sequence errmsg
    -- begin mwl
	
    if find(1, eval_stack) and not length(eval_error[$]) then
		if ThisLine[1] = END_OF_FILE then
			errmsg = msg -- "<end-of-file>\n"
		else
			errmsg = msg & "\n" & ThisLine[1..bp-1] & "\n" 
			for i = 1 to bp - 2 do
				if ThisLine[i] = '\t' then
					errmsg &= '\t'
				else
					errmsg &= 32
				end if
			end for
			errmsg &=  "^\n"
		end if
    	
    	eval_error[$] = errmsg
    	geval_error = errmsg
    	call_proc(forward_putback,{{END_OF_FILE,0}})
    	return
    elsif length(eval_error[$]) then
    	call_proc(forward_putback,{{END_OF_FILE,0}})
    	return
    end if
    -- end mwl
    
    Errors += 1
    if length(file_name) then
	errmsg = sprintf("%.99s:%d\n%s\n", {file_name[current_file_no], 
		     line_number, msg})
    else
	errmsg = msg
    end if
	-- try to open err file *before* displaying diagnostics on screen
    OpenErrFile() -- exits if error filename is ""
    screen_output(STDERR, errmsg)
    ShowErr(STDERR)
    
    puts(TempErrFile, errmsg) 
    
    ShowErr(TempErrFile) 
    
    if ShowWarnings(TempErrFile) then
    end if
    
    puts(TempErrFile, "\n")
    
    close(TempErrFile)
--? 1/0
    Cleanup(-1)

end procedure

procedure not_supported_compile(sequence feature)
-- report feature not supported
    CompileErr(sprintf("%s is not supported in Euphoria for %s", 
		       {feature, version_name}))
end procedure

global procedure InternalErr(sequence msg)
-- Handles internal compile-time errors
-- see RTInternal() for run-time internal errors
    if TRANSLATE then
	screen_output(STDERR, sprintf("Internal Error: %s\n", {msg}))
    else
	screen_output(STDERR, sprintf("\nInternal Error at %s:%d - %s\n", 
	   {file_name[current_file_no], line_number, msg}))
    end if
    screen_output(STDERR, "\nPress Enter\n")
    if getc(0) then
    end if
    ? 1/0
    abort(1)
end procedure
