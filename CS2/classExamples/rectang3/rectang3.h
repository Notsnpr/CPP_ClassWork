
#ifndef RECTANGLE_H		// if RECTANGLE_H has not being defined before
#define RECTANGLE_H		// define RECTANGLE_H
						// This avoids redefinitions of class rectangle
#include <iostream>
using namespace std;
// Rectangle class declaration.
class rectangle
{
	public:
		void setData(float, float);			// assigns values to private data
		void calcArea();					// calculates area and stores result in member area
		float getWidth() const;				// returns value of width
		float getLength() const;			// returns value of length
		float getArea() const;				// returns value of area
		float getPerimeter() const;			// calculates the perimeter and returns its value
		rectangle addAreas(rectangle);		// adds the areas of two rectangles
		rectangle(float w = 0, float l = 0, float a = 0);		// paramenterized constructor with default parameters
		rectangle(const rectangle & par);						// copy constructor
		~rectangle();											// destructor

	private:
		float width;						// width of the rectangle
		float length;						// length of the rectangle
		float area;							// area of the rectangle
		static int counter;					// static data member to be shared by objects of the same type
};

#endif

// For more information about static keyword access http://www.studytonight.com/cpp/static-keyword.php
//For more information about copy constructor in C++ access https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
