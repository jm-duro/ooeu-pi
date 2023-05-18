
without warning
include misc.e

with trace

euclass EPoint( sequence p )
	-- other classes will use this
	atom X, Y
	function Create( atom x, atom y )
		return {x, y}
	end function
	
	function Dot( EPoint p )
		EPoint v
		
		v = this * p
		return v.X + v.Y
	end function
	
	function VectorLength()
		return sqrt( this.Dot( this ) )
	end function
end euclass

euclass EShape( sequence s )
	-- This class doesn't do much.
	sequence Name
	
end euclass


euclass ECircle( EShape c )
	-- This is a shape defined by its center and a radius.
	-- Note that the Center is an EPoint.
	EPoint Center
	atom Radius
	
	-- The Create() function isn't very interesting, but it
	-- does initialize the sequence.
	function Create( EPoint center, atom radius )
		this = repeat( 0, ECircle.Radius )
		this.Name = "Circle"
		this.Center = center
		this.Radius = radius
		return this
	end function
	
	-- This is an alternate form of creation, in case you'd rather
	-- supply two atoms rather than a sequence.
	function Create( atom x, atom y, atom radius )
		return this.Create( {x,y}, radius )
	end function
	
	-- Returns the Area of the circle
	function Area()
		return PI * this.Radius * this.Radius
	end function
	
	-- Gives the Circumference of the circle.
	function Circumference()
		return PI * 2 * this.Radius
	end function
	
	procedure Describe()
		printf( 1, "Shape: %s\n", {this.Name})
		printf(1, "  Center: (%g,%g)\n",	this.Center )
		printf(1, "  Radius: %g\n", this.Radius )
	end procedure
end euclass

euclass EPolygon( EShape p )
	-- This class is to be used as a base class for specific types
	-- of Polygons.
	
	integer Sides
	sequence of EPoint Points
	
	-- The perimeter of a polygon is always the sum of the length of the sides,
	-- no matter how many sides, or how the sides are arranged.  This will be
	-- used like a virtual function.
	function Perimeter()
		atom per, x, y
		sequence blah
		EPoint p1, p2
		per = 0.0
		p1 = this.Points[$]
		
		for i = 0 + 1 to this.Sides do
			p2 = this.Points[i]
			
			x = p2.X - p1.X
			y = p2.Y - p1.Y

			per += sqrt( x*x + y*y )
			p1 = p2
		end for
		return per
	end function
	
	procedure Describe()
		EPoint p1, p2
		printf(1, "Shape: %s has %d sides:\n", {this.Name, this.Sides})
		p1 = this.Points[$]
		for i = 1 to this.Sides do
			p2 = this.Points[i]
			printf( 1, "  (%g,%g) -> (%g,%g)\n", p1 & p2 )
			p1 = p2
		end for
	end procedure
end euclass

-- This class uses the EPolygon as its base class, so we don't 
-- need to define Perimeter() for it.
euclass ETriangle( EPolygon t )
	function Create( sequence points )
		this = repeat( "", EPolygon.Points )
		this.Name = "Triangle"
		this.Sides = 3
		this.Points = points
		return this
	end function
	
	
	function Area()
		EPoint p1, p2, p3
		atom u, v, angle
		p1 = this.Points[1]
		p2 = this.Points[2]
		p3 = this.Points[3]
		
		p2 -= p1
		p3 -= p1
		u = p2.VectorLength()
		v = p3.VectorLength()
		angle = arccos( p2.Dot( p3 ) / ( u * v ) )
		v *= sin( angle )
		return 0.5 * u * v
	end function
end euclass

-- This class uses the EPolygon as its base class, so we don't 
-- need to define Perimeter() for it.
euclass ESquare( EPolygon s )
	function Create( sequence points )
		this = repeat( "", EPolygon.Points )
		this.Name = "Square"
		this.Sides = 4
		this.Points = points
		return this
	end function
	
	function Area( )
		atom len
		EPoint p1, p2
		p1 = this.Points[1]
		p2 = this.Points[2]
		len = EPoint.VectorLength( p2 - p1 )
		-- This casts a temporary result into an EPoint, and calls the 
		-- VectorLength() method on it.

		len = EPoint.VectorLength( this.Points[2]-this.Points[1] )
		return len * len
	end function
end euclass



ECircle circle
puts( 1, "shape.ex\n\n" )
with trace
trace(1)
circle = ECircle.Create( "", 1, 2, 5 )
trace(0)
circle.Describe()
printf( 1, "Area of %s ( radius = %g ) = %g\n\n", 
	{ circle.Name, circle.Radius, circle.Area() })

ESquare square
square = ESquare.Create( "", { {0,0}, {10, 0}, {10,10}, {0,10} })
square.Describe()
printf( 1, "Area of %s = %g\nPerimeter of %s = %g\n\n", 
	{ square.Name, square.Area(), square.Name, square.Perimeter() })


ETriangle triangle
triangle = ETriangle.Create( "", { {0,0}, {1,1}, {0.5,2} })
triangle.Describe()
printf( 1, "Perimiter of %s = %g\nArea of %s = %g\n\n",
	{ triangle.Name, triangle.Perimeter(), triangle.Name, triangle.Area()})

sequence of ECircle circles
circles = repeat( circle, 3 )

circle.Radius = 2
circles[2].Radius = 5
circles[3].Center *= 3

for i = 1 to length(circles) do
	printf(1, "circles[%d]:\n", i )
	circles[i].Describe()
	puts(1, "\n")
end for

include get.e

puts( 1, "Press any key to quit\n" )
if wait_key() then
	
end if
