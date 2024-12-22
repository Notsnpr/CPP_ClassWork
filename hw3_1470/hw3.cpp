// //******************************************************************************
// // Team:          CSCI 1470 Fall 2024 Homework # 3
// // First and Last Name
// // First and Last Name
// // Using your own words, write here a description of what the program does.
// //
// //******************************************************************************

// #include <typeinfo>				// to be able to use operator typeid

// // Include the libraries and namespace statement that your program needs to compile here



// // Include the function prototypes here. Define the functions below main()



// // // Ignore this; it's a little function used for making tests
// // inline void _test(const char* expression, const char* file, int line)
// // {
// // 	cerr << "test(" << expression << ") failed in file " << file;
// // 	cerr << ", line " << line << "." << endl << endl;
// // }
// // // This goes along with the above function...don't worry about it
// // #define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// int main()
// {
// // Start entering your code for main() here ----------------------------------------





// // Stop entering your code for main() here ----------------------------------------

// 	cout << endl;

// 	// Do NOT remove or modify the following statements
// 	cout << endl << "Testing your solution" << endl << endl;
// 	int num, den;
// 	num = 4; den = 3;
// 	reduce(num, den);
// 	test(num == 4 && den == 3);								// Incorrect reducing of the fraction
// 	num = 12; den = 3;
// 	reduce(num, den);
// 	test(num == 4 && den == 1);								// Incorrect reducing of the fraction
// 	num = 3; den = 12;
// 	reduce(num, den);
// 	test(num == 1 && den == 4);								// Incorrect reducing of the fraction
// 	num = -3; den = 12;
// 	reduce(num, den);
// 	test(num == -1 && den == 4);							// Incorrect reducing of the fraction
// 	num = -63; den = 15;
// 	reduce(num, den);
// 	test(num == -21 && den == 5);							// Incorrect reducing of the fraction
// 	num = -1024; den = 127;
// 	reduce(num, den);
// 	test(num == -1024 && den == 127);						// Incorrect reducing of the fraction

// 	AddRational(num, den, 1, 2, 2, 4);
// 	test(num == 1 && den == 1);								// Incorrect addition of the fractions
// 	AddRational(num, den, 1, 3, 3, 4);
// 	test(num == 13 && den == 12);							// Incorrect addition of the fractions
// 	AddRational(num, den, 9, 5, 2, 5);
// 	test(num == 11 && den == 5);							// Incorrect addition of the fractions
// 	AddRational(num, den, 1, 3, 3, 18);
// 	test(num == 1 && den == 2);								// Incorrect addition of the fractions
// 	AddRational(num, den, 1, 7, 3, 9);
// 	test(num == 10 && den == 21);							// Incorrect addition of the fractions
// 	AddRational(num, den, 3, 7, 6, 9);
// 	test(num == 23 && den == 21);							// Incorrect addition of the fractions

// 	SubtractRational(num, den, 1, 2, 2, 4);
// 	test(num == 0 && den == 1);								// Incorrect subtraction of the fractions
// 	SubtractRational(num, den, 1, 3, 3, 4);
// 	test(num == -5 && den == 12);							// Incorrect subtraction of the fractions
// 	SubtractRational(num, den, 9, 5, 2, 5);
// 	test(num == 7 && den == 5);								// Incorrect subtraction of the fractions
// 	SubtractRational(num, den, 1, 3, 3, 18);
// 	test(num == 1 && den == 6);								// Incorrect subtraction of the fractions
// 	SubtractRational(num, den, 1, 1, 75, 12);
// 	test(num == -21 && den == 4);							// Incorrect subtraction of the fractions
// 	SubtractRational(num, den, 6, 9, 3, 7);
// 	test(num == 5 && den == 21);							// Incorrect subtraction of the fractions

// 	cout << "Done!" << endl;
// 	return 0;
// }

// // Define your functions below this line please
// //---------------------------------------------

// void pause()	// This function pauses the execution of the program
// {
// 	cout << "Press Enter to continue ...";
// 	cin.sync();
// 	cin.ignore();
// 	cin.get();
// }

// Void clear_screen()	// This function clears the screen
// {
// 	cout << "\033[0;0H\033[2J";
// }
