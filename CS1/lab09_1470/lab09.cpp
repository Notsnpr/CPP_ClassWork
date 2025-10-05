/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/9/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
//
/////////////////////////////////////////////////////////////////////

#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries that your program needs to compile

#include <fstream>
#include <iostream>	
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Declare a global constant named PI equal to 3.141592
const double PI = 3.141592;
// Include here your header file 
#include "myfunctions.h"

int main()
{
// Declare variable named outFile to represent the output file
	ofstream outFile;
// Declare variables named base, height, radiusa, and radiusb that hold doble precision numbers
	double base, height, radiusa, radiusb;
// Declare variables named rec_area, and elli_area that hold double precision real numbers
	double rec_area, elli_area;
// Open output file "output9.txt" and relate it to outFile
	outFile.open("output9.txt");
//Print on the screen "For the rectangle"
	cout << "For the rectangle";
//Call void function getData() and receive in base and height the two lengths read from the keyboard
	getData(base, height);
//Print on the screen "For the ellipse"
	cout<<"For the ellipse";
//Call void function getData() and receive in radiusa and radiusb the two lengths read from the keyboard
	getData(radiusa, radiusb);
// Call function area_rectangle() to calculate the area of a rectangle and assign the returned value to rec_area
//Call function area_ellipse() to calculate the area of an ellipse and assign the returned value to elli_area
	rec_area = area_rectangle(base, height);
	elli_area = area_ellipse(radiusa, radiusb);
// Call function printData() to print the output to the output file
	printData(outFile, base, height, rec_area, radiusa, radiusb, elli_area);
// Close the file
	outFile.close();

	// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(PI) == typeid(1.));							// Incorrect data type used for PI
	test(PI == 3.141592);									// Incorrect value used for PI
	test(typeid(base) == typeid(1.));						// Incorrect data type used for base
	test(typeid(height) == typeid(1.));						// Incorrect data type used for height
	test(typeid(radiusa) == typeid(1.));					// Incorrect data type used for radiusa
	test(typeid(radiusb) == typeid(1.));					// Incorrect data type used for radiusb
	test(typeid(rec_area) == typeid(1.));					// Incorrect data type used for rec_area
	test(typeid(elli_area) == typeid(1.));					// Incorrect data type used for elli_area
	test(fabs(area_rectangle(2.33, 3.61) - 8.4) < 0.001);	// Incorrect rounding of area of rectangle
	test(fabs(area_rectangle(2.42, 3.7) - 9.0) < 0.001);	// Incorrect rounding of area of rectangle
	test(fabs(area_ellipse(4.55, 5.95) - 85.1) < 0.001);	// Incorrect rounding of area of ellipse
	test(fabs(area_ellipse(4.61, 6.01) - 87.0) < 0.001);	// Incorrect rounding of area of ellipse

	return 0 ;
}

