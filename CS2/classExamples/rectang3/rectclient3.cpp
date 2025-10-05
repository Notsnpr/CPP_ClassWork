// This program demonstrates a simple class

#include <iostream>
#include <iomanip>

#include "rectang3.h"  // contains Rectangle class declaration

using namespace std;

int main()
{
	rectangle box1,box2(box1),box3(6,6,6);
	float shrtsd, longsd;

	cout << fixed << showpoint << setprecision(2);	// format the output

	cout << "This part of the program will calculate the area and the perimeter of a rectangle\n";
	cout << "What is the width? ";							// get width
	cin >> shrtsd;
	cout << "What is the length? ";							// get length
	cin >> longsd;
	box1.setData(shrtsd, longsd);								// assingn values to private data
	box1.calcArea();											// calculate area 
	cout << "Here is the rectangle's data:\n";
	cout << "Width: " << box1.getWidth() << endl;			// show width
	cout << "Length: " << box1.getLength() << endl;			// show length
	cout << "Area: " << box1.getArea() << endl;				// show area
	cout << "Perimeter: " << box1.getPerimeter() << endl;	// show perimeter

	cout << endl << "This part of the program will calculate the area and the perimeter of another rectangle\n";
	cout << "What is the width? ";							// get width
	cin >> shrtsd;
	cout << "What is the length? ";							// get length
	cin >> longsd;
	box2.setData(shrtsd, longsd);								// assingn values to private data
	box2.calcArea();											// calculate area 
	cout << "Here is the rectangle's data:\n";
	cout << "Width: " << box2.getWidth() << endl;			// show width
	cout << "Length: " << box2.getLength() << endl;			// show length
	cout << "Area: " << box2.getArea() << endl;				// show area
	cout << "Perimeter: " << box2.getPerimeter() << endl;	// show perimeter

	cout << endl << "This part of the program will calculate the data of a rectangle\n";
	cout << "whose area is the result of adding the areas of both rectangles\n";
	box3 = box1.addAreas(box2);								// calculate area 
	cout << "Here is the rectangle's data:\n";
	cout << "Width: " << box3.getWidth() << endl;			// show width
	cout << "Length: " << box3.getLength() << endl;			// show length
	cout << "Area: " << box3.getArea() << endl;				// show area
	cout << "Perimeter: " << box3.getPerimeter() << endl;	// show perimeter

	return 0;
}

