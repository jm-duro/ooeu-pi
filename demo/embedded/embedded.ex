include get.e
include eu.e

procedure print_help()
	puts(1,"\n")
	puts(1,"Embedded ooeu demo      by Matt Lewis\n")
	puts(1,"Type in lines of valid Euphoria code.  Press enter on a\n")
	puts(1,"blank line and the script will be run.  You can define\n")
	puts(1,"routines to be called later.  Type 'help' to see this\n")
	puts(1,"help again, or 'quit' to end your session. \n" )
	puts(1,"You cannot use 'print'.  You may access the variables \n")
	puts(1,"x (atom) and s (sequence) using get_var(\"x/s\") or\n")
	puts(1,"set_var( \"x/s\", <val> )\n\n" )
end procedure


sequence script, line
integer ok

sequence s
atom x
s = ""
x = 0
ok = do_eval( "with trace\nif 1=1 then end if\nwithout trace" )
procedure set_var( sequence var, object val )
	if equal(var,"s") then
		s = val
	elsif equal(var,"x") then
		x = val
	end if
end procedure
ok = embed_routine( "set_var", routine_id("set_var"), "so", 0 )


function get_var( sequence var )
	if equal( var, "s" ) then
		return s
	elsif equal( var, "x" ) then
		return x
	end if
	return 0
end function
ok = embed_routine( "get_var", routine_id("get_var"), "s", 1 )

illegal_builtin( "print" )
script = {}

print_help()

while 1 do
	line = prompt_string("> ")
	if equal(line,"quit") then
		exit
	elsif equal(line,"help") then
		print_help()
	elsif not length(line) then
		if length(script) then
			puts(1, "\n" )
			ok = do_eval( script )
			if not ok then
				printf(1,"\nError: \'%s\'\n", {get_eval_err()})
			end if
			puts(1, "\n")
	
			script = {}			
		end if

	else
		script &= line & '\n'
	end if
end while

cleanup_debugger()
