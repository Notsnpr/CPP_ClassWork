#include<iostream>
#include <typeinfo>   // operator typeid

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

int main()
{
	// This statement declares and initializes an int variable called age
	// Variable age is used to hold the age of the person and it is initialized to 22 
	//Change this age to 19 to check if your expression is correct
	int age = 22;  
	
	// This is the variable that will hold the lowest dateable
	// age given the age of the person (specified above)
	int dateable; 

	// This is the dateable equation. it assigns the result to
	// the variable "dateable" of type int.
	// Use parenthesis to make the equation more readable
	dateable = 7 + age / 2;

	//tells the user the result of the dateable equation.
	cout << "Your minimum dateable age is: " << dateable << endl;

// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(dateable) == typeid(int));		// Incorrect data type used for dateable
	test(typeid(age) == typeid(int));		    // Incorrect data type used for age
	if (age == 19)
        test(dateable == 16);		            // Incorrect expression used to calculate dateable

	return 0;
}

