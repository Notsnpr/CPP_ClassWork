/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 09/06/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Program Name: Length converter
// Program Description: Converts a length expressed in feet to yards
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cmath>
#include<typeinfo>   // operator typeid
// Include here all the other libraries that required for the program to compile
using namespace std;
// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
	//abort();
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

//Please enter a length expressed in feet: 9.2
//Hi
//9.2 feet are equal to 3.06667 yards
//Testing your solution

int main()
{
// Declare variables called len_feet and len_yards that hold double precision real numbers.
double len_feet, len_yards;

// Prompt the user to enter the length in feet.
cout << "Please enter a length expressed in feet: ";
// Get the length from the keyboard and store it in the corresponding variable.
cin >> len_feet;
// Calculate the length in yards using the formula exactly as provided above and assign the result to the corresponding variable.
len_yards = (1.0/3.0)*len_feet;
// Display on the screen the following message:
// "Hi"
cout << "Hi"<< endl;
//
// len_feet, " feet are equal to ", len_yards, " yards
cout <<len_feet<<" feet are equal to "<<len_yards<< " yards";




// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(len_feet) == typeid(double));				// Incorrect data type used for len_feet
	test(typeid(len_yards) == typeid(double));				// Incorrect data type used for len_yards
	test(fabs(len_yards-len_feet/3)<.000000000000001);		// Incorrect expression used to calculate the length in yards

	return 0;
}