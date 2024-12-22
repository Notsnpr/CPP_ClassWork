/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 09/20/2024
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

// Insert the prototype of the function here
double round_off(double , double ) ;

int main()
{
// Declare variable value, valuero that hold double precision real numbers
	double value, valuero; 
// Declare variable decdig that holds whole numbers
	int decdig;
// Prompt the user to "Enter the real number: "
	cout <<"Enter the real number: ";
// Read from keyboard the value entered by the user and assign it to value
	cin >> value;
// Prompt the user to "Enter number of digits: "
	cout <<"\nEnter number of digits: ";
// Read from keyboard the value entered by the user and assign it to decdig
	cin >> decdig;
// Round the real number to the number of decimal digits specified and assign the result to valuero
	valuero = round_off(value,decdig);
// Format the output to display the numbers in fixed format with ten decimal digits
	cout << fixed;
	cout << setprecision(10);
// Display on the screen, using 23 columns, the message
//	   "The original number is ", value
	cout<< endl <<setw(23)<< "The original number is " <<value << endl;
// Format the output to display the numbers in fixed format with the number of decimal digits specified plus 2
	cout << fixed;
	cout << setprecision(decdig+2);
// Display on the screen, using 23 columns, the message
//	   "The rounded number is ", valuero
	cout<< endl << setw(23) <<"The rounded number is " << valuero;



// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(value) == typeid(1.));										// Incorrect data type used for value
	test(typeid(valuero) == typeid(1.));									// Incorrect data type used for valuero
	test(typeid(decdig) == typeid(1));										// Incorrect data type used for decdig
	
	//IMPORTANT!!!  Include these tests once the function has been implemented

	test(fabs(round_off(125.123456789,2) - 125.12 ) < 0.001);				// Incorrect rounding to two decimal digits 
	test(fabs(round_off(125.123456789,4) - 125.1235) < 0.00001);			// Incorrect rounding to four decimal digits 
	test(fabs(round_off(125.987654321,0) - 126.) < 0.001);					// Incorrect rounding to no decimal digits 
	test(fabs(round_off(125.987654321, 5) - 125.98765) < 0.000001);			// Incorrect rounding to five decimal digits 
	 
	return 0;
}



//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement
double round_off(double valuex , double n ){
	return round(valuex*pow(10,n))/pow(10,n);
}
// Rounds the value received in the first parameter to the number of digits received in the second parameter
