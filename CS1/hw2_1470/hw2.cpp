//******************************************************************************
// Team # CSCI 1470 Fall 2024 Homework # 2
// First and Last Name
// First and Last Name
// Using your own words, write here a description of what the program does.
//
//******************************************************************************

#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries that your program needs to compile




// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions



int main()
{




	
	
// Do NOT remove or modify the following statements

	cout << endl << "Testing your solution" << endl << endl;

	test(fabs(round_off(calcLength(1.0, 1.2, 6.0, 6.1), 2) - 7.00) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calcLength(6.0, 6.1, 3.2, 6.5), 2) - 2.83) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calcLength(1.0, 1.2, 3.2, 6.5), 2) - 5.74) < .001);			// Incorrect calculation of length
	test(fabs(calcArea(calcLength(1.0, 1.2, 6.0, 6.1), calcLength(6.0, 6.1, 3.2, 6.5), calcLength(1.0, 1.2, 3.2, 6.5)) - 7.86) < .001);			// Incorrect calculation of area

	test(fabs(round_off(calcLength(1.2, 1.2, 7.6, 4.3), 2) - 7.11) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calcLength(7.6, 4.3, 9.2, 3.4), 2) - 1.84) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calcLength(1.2, 1.2, 9.2, 3.4), 2) - 8.30) < .001);			// Incorrect calculation of length
	test(fabs(calcArea(calcLength(1.2, 1.2, 7.6, 4.3), calcLength(7.6, 4.3, 9.2, 3.4), calcLength(1.2, 1.2, 9.2, 3.4)) - 5.36) < .001);			// Incorrect calculation of area

	test(fabs(round_off(calcLength(5.0, 5.0, 9.0, 9.0), 2) - 5.66) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calcLength(1.0, 1.0, 5.0, 5.0), 2) - 5.66) < .001);			// Incorrect calculation of length
	test(fabs(round_off(calcLength(1.0, 1.0, 9.0, 9.0), 2) - 11.31) < .001);		// Incorrect calculation of length
	test(fabs(calcArea(calcLength(1.0, 1.0, 5.0, 5.0), calcLength(5.0, 5.0, 9.0, 9.0), calcLength(1.0, 1.0, 9.0, 9.0)) - 0.00) < .001);			// Incorrect calculation of area

	return 0;		
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

