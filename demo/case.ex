with strict_goto
include misc.e
constant break = "break"

-- Here's a way to implement a non-fall-through case statement
-- that uses the if/elsif's automatic flow control, but jumps 
-- right to the appropriate case:

procedure non_fall_through_if( integer case )
	printf(1, "\nNon fall through: %d\n", case)
	default_goto( "else" )
	goto "case" & sprint(case)
	if 1 then
		:"case1"
		? 1
		
	elsif 2 then
		:"case2"
		? 2
		
	elsif 3 then
		:"case3"
		? 3
		
	elsif 4 then
		:"case4"
		? 4
	
	else
		:"else"
		printf(1,"Else: %d\n", case )
	end if
end procedure

procedure non_fall_through_goto( integer case )
	printf(1, "\nAnother Non fall through: %d\n", case)

	-- Here's how to implement a non-fall-through case statement
	-- without using an if statement:
	default_goto("else")
	
	goto "nft" & sprint(case)
	:"nft1"
	? 1
	goto break
	
	:"nft2"
	? 2
	goto break
	
	:"nft3"
	? 3
	goto break
	
	:"nft4"
	? 4
	goto break
	
	:"else"
	printf(1,"Else: %d\n", case )

	:break	
end procedure

procedure fall_through( integer case )
	printf(1, "\nFall through: %d\n", case)
	default_goto( "else" )
	
	-- Here's how to implement a fall-through case statement:
	goto "ft" & sprint(case)
	:"ft1"
	? 1
	
	:"ft2"
	? 2
	
	:"ft3"
	? 3
	
	:"ft4"
	? 4
	goto break
	
	:"else"
	printf(1,"Else: %d\n", case )
	
	:break
end procedure
for case = 1 to 5 do
	non_fall_through_if( case )
	non_fall_through_goto( case )
	fall_through( case )
end for

puts(1,"\nPress any key to exit.\n")
include get.e
abort(wait_key())
