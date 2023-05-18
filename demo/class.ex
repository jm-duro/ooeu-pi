with trace
global euclass person( sequence p )
	sequence name

	function create( sequence name )
		return { name }
	end function

	procedure say( sequence speech )
		printf( 1, "%s: \"%s\"\n", { this.name, speech})
	end procedure
	

end euclass

global euclass coder( person c )
	sequence language
	
	procedure execute( sequence program )
		this.say( "Running " & program )
	end procedure
	
	integer Integer
	procedure debug( sequence program )
		this.say( sprintf("Dang, %s didn't work...", {program}))
		this.say( "Oh, there's the problem..." )
	end procedure
	

	
end euclass

global euclass euphoria_coder( coder e )

	function create( sequence name )
		this = person.create( this, name )
		this &= { "", 0 }
		this.language = "Euphoria"
		return this
	end function
	
	procedure test( sequence program )
		coder c
		c = this
		this.execute( program )
		this.debug( program )
		this.execute( program )
		this.say( "Excellent!")
	end procedure

end euclass

global euclass c_coder( coder c )
	sequence language
	procedure compile( sequence program )
		this.say( sprintf("Compiling %s...",{program}))
	end procedure
	
	procedure link( sequence program )
		this.say( sprintf("Linking %s...",{program}))
	end procedure
	
	
	procedure execute( sequence program )
		this.compile( program )
		this.link( program )
		coder.execute( this, program )
	end procedure
	
	procedure test( sequence program )
		integer x, y, z
		this.execute( program )
		this.debug( program )
		this.execute( program )
	end procedure

	function create( sequence name )
		this = person.create( this, name )
		this &= {"",0,""}
		this.language = "C"
		return this
	end function
end euclass

euphoria_coder me
c_coder you

procedure foo( integer x )
	? x
end procedure

me = euphoria_coder.create( "", "Matt" )

foo(3)

you = c_coder.create( "", "Fred" )
? you[coder.language]

puts(1,"\n")
me.say( sprintf( "I like to code in %s", {me.language}))
me.test( "EuApp.ex" )

puts(1, "\n")
you.say( sprintf( "I like to code in %s", {you.language}))
you.test( "CApp.c" )



include machine.e
function my_crash( object o )
	puts(1,"You crashed!\n")
	return 0
end function
? routine_id("my_crash")
crash_routine(routine_id("my_crash"))

? 1/0
