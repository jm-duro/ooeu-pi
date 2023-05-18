puts(1, "gl.e\n")
euclass Local( integer l )
	global procedure LocalMethod()
		puts(1, "Local\n")
		? 1/0
	end procedure
end euclass

global type t1( object o )
	return 1
end type

global type t2( object o )
	return 1
end type

global euclass Global( Local g )
	procedure GlobalMethod()
		puts(1, "Global\n" )
	end procedure
	
	procedure test( t1 t )
		puts(1, "test( t1 t )\n")
	end procedure

	procedure test( t2 t )
		puts(1, "test( t2 t )\n")
	end procedure

end euclass

Global.GlobalMethod(0)
--? 1/0

