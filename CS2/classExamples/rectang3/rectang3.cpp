#include "rectang3.h"

int	rectangle::counter = 0;		// initialize the static data member counter to zero

// setData copies the argument w to private member width and
// l to private member length.
void rectangle::setData(float w, float l)
{
	width = w;
	length = l;
}

// calcArea multiplies the private members width and length.
// The result is stored in the private member area.
void rectangle::calcArea()
{
	area = width * length;
}

// getPerimeter calculates the perimeter and returns its value
float rectangle::getPerimeter() const
{
	return 2 * (getWidth() + getLength());
}

// getWidth returns the value stored in the private member width.
float rectangle::getWidth() const
{
	return width;
}

// getLength returns the value stored in the private member length.
float rectangle::getLength() const
{
	return length;
}

// getArea returns the value stored in the private member area.
float rectangle::getArea() const
{
	return area;
}

// addAreas adds the areas of two rectangles assuming they are aligned in such a way
// that the width of the resulting is equivalent to both widths added together (like if
// they were one on top of the other). Then, it calculates the length that the resulting
// rectangle should have.
rectangle rectangle::addAreas(rectangle sec)
{
//	rectangle sec(8, 8, 64);					// declare and initialize a local object
// Change the parameter to sec2 to work with the local object
	rectangle result;
	result.area = area + sec.area;				// simply adds both areas
	result.width = width + sec.width;			// assumes the width is the addition of both widths
	result.length = result.area/result.width;	// calculates the length the resulting rectangle should have
	return result;								// returns an object of type rectangle
}

// Parameterized constructor. Assigns to the private data members the values passed through
// the parameter list by the client program.
// This function is called automatically when an object of this class is declared with a parameter list.
rectangle::rectangle(float w, float l, float a)
{
	counter++;
	width = w;
	length = l;
	area = a;
	cout << "(PC) data members in object " << counter << " w: " << width << " l: " << length << " a: " << area << " at " << &(*this) << endl;
	//system("pause");
}

// Copy constructor. Assigns the data of the object received through the parameter list to the data members of SELF
// It is used to:
//1) Initialize one object from another of the same type.
//2) Copy an object to pass it as an argument to a function.
//3) Copy an object to return it from a function.
//4) Assign an object to another object

rectangle::rectangle(const rectangle & par)						// copy constructor
{
	counter++;
	width = par.width;
	length = par.length;
	area = par.area;
	counter = par.counter;
	cout << "(CC) data members in object " << counter << " w: " << width << " l: " << length << " a: " << area << " at " << &(*this) << endl;
	//system("pause");
}

// Destructor.
// This member function is called automatically when an object of this class is destroyed.
rectangle::~rectangle()
{
	counter--;
	cout << "using destructor. Now there are only " << counter << " objects" << " at " << &(*this) << endl;
	//system("pause");
}
