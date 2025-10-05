/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/24/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
//
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries and anything else that your program needs to compile


using namespace std;
// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Function prototype for Part A
char letter2digitA(char letter);

// Function prototype for Part B
char letter2digitB(char letter);

int main() {
    char letter;
    char digit;

    // Display the title
    cout << "Converts a capital letter to a digit on the telephone" << endl;

    // Prompt the user to enter a single capital letter
    cout << "Enter a single capital letter: ";
    cin >> letter;

    // Solution A
    cout <<endl<< "Solution A" << endl;
    digit = letter2digitA(letter);
    if (digit != '?') {
        cout <<endl<< "letter " << letter << " corresponds to digit " << digit << " on the telephone" << endl;
    } else {
        cout <<endl<< "there is no matching digit for the letter " << letter << " entered" << endl;
    }

    // Solution B
    cout <<endl<< "Solution B" << endl;
    digit = letter2digitB(letter);
    if (digit != '?') {
        cout <<endl<< "letter " << letter << " corresponds to digit " << digit << " on the telephone" << endl;
    } else {
        cout <<endl<< "there is no matching digit for the letter " << letter << " entered" << endl;
    }


	cout << endl << "Testing your solution" << endl << endl;

	test(letter2digitA('A') == '2');				// Incorrect letter to digit correlation
	test(letter2digitA('B') == '2');				// Incorrect letter to digit correlation
	test(letter2digitA('C') == '2');				// Incorrect letter to digit correlation
	test(letter2digitA('D') == '3');				// Incorrect letter to digit correlation
	test(letter2digitA('E') == '3');				// Incorrect letter to digit correlation
	test(letter2digitA('F') == '3');				// Incorrect letter to digit correlation
	test(letter2digitA('G') == '4');				// Incorrect letter to digit correlation
	test(letter2digitA('H') == '4');				// Incorrect letter to digit correlation
	test(letter2digitA('I') == '4');				// Incorrect letter to digit correlation
	test(letter2digitA('J') == '5');				// Incorrect letter to digit correlation
	test(letter2digitA('K') == '5');				// Incorrect letter to digit correlation
	test(letter2digitA('L') == '5');				// Incorrect letter to digit correlation
	test(letter2digitA('M') == '6');				// Incorrect letter to digit correlation
	test(letter2digitA('N') == '6');				// Incorrect letter to digit correlation
	test(letter2digitA('O') == '6');				// Incorrect letter to digit correlation
	test(letter2digitA('P') == '7');				// Incorrect letter to digit correlation
	test(letter2digitA('Q') == '7');				// Incorrect letter to digit correlation
	test(letter2digitA('R') == '7');				// Incorrect letter to digit correlation
	test(letter2digitA('S') == '7');				// Incorrect letter to digit correlation
	test(letter2digitA('T') == '8');				// Incorrect letter to digit correlation
	test(letter2digitA('U') == '8');				// Incorrect letter to digit correlation
	test(letter2digitA('V') == '8');				// Incorrect letter to digit correlation
	test(letter2digitA('W') == '9');				// Incorrect letter to digit correlation
	test(letter2digitA('X') == '9');				// Incorrect letter to digit correlation
	test(letter2digitA('Y') == '9');				// Incorrect letter to digit correlation
	test(letter2digitA('Z') == '9');				// Incorrect letter to digit correlation
	test(letter2digitA('a') == '?');				// Incorrect letter to digit correlation
	test(letter2digitA('#') == '?');				// Incorrect letter to digit correlation
	test(letter2digitA('1') == '?');				// Incorrect letter to digit correlation

	test(letter2digitB('A') == '2');				// Incorrect letter to digit correlation
	test(letter2digitB('B') == '2');				// Incorrect letter to digit correlation
	test(letter2digitB('C') == '2');				// Incorrect letter to digit correlation
	test(letter2digitB('D') == '3');				// Incorrect letter to digit correlation
	test(letter2digitB('E') == '3');				// Incorrect letter to digit correlation
	test(letter2digitB('F') == '3');				// Incorrect letter to digit correlation
	test(letter2digitB('G') == '4');				// Incorrect letter to digit correlation
	test(letter2digitB('H') == '4');				// Incorrect letter to digit correlation
	test(letter2digitB('I') == '4');				// Incorrect letter to digit correlation
	test(letter2digitB('J') == '5');				// Incorrect letter to digit correlation
	test(letter2digitB('K') == '5');				// Incorrect letter to digit correlation
	test(letter2digitB('L') == '5');				// Incorrect letter to digit correlation
	test(letter2digitB('M') == '6');				// Incorrect letter to digit correlation
	test(letter2digitB('N') == '6');				// Incorrect letter to digit correlation
	test(letter2digitB('O') == '6');				// Incorrect letter to digit correlation
	test(letter2digitB('P') == '7');				// Incorrect letter to digit correlation
	test(letter2digitB('Q') == '7');				// Incorrect letter to digit correlation
	test(letter2digitB('R') == '7');				// Incorrect letter to digit correlation
	test(letter2digitB('S') == '7');				// Incorrect letter to digit correlation
	test(letter2digitB('T') == '8');				// Incorrect letter to digit correlation
	test(letter2digitB('U') == '8');				// Incorrect letter to digit correlation
	test(letter2digitB('V') == '8');				// Incorrect letter to digit correlation
	test(letter2digitB('W') == '9');				// Incorrect letter to digit correlation
	test(letter2digitB('X') == '9');				// Incorrect letter to digit correlation
	test(letter2digitB('Y') == '9');				// Incorrect letter to digit correlation
	test(letter2digitB('Z') == '9');				// Incorrect letter to digit correlation
	test(letter2digitB('a') == '?');				// Incorrect letter to digit correlation
	test(letter2digitB('#') == '?');				// Incorrect letter to digit correlation
	test(letter2digitB('1') == '?');				// Incorrect letter to digit correlation

	return 0;                               // Indicate successful
}                                           //   completion


//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// This function receives a character. If the character corresponds to any capital letter of the English
// alphabet it returns the corresponding telephone digit as a character; otherwise, it returns character
// '?' to indicate that an invalid character has been entered.
// 
// This function uses COMPLEX CONDITIONAL EXPRESSIONS to determine the matching digit for the letter entered
// Works with RANGE of letters to determine the digit

// Function definition for Part A
char letter2digitA(char letter) {
    if ((letter >= 'A' && letter <= 'C')) {
        return '2';
    } else if ((letter >= 'D' && letter <= 'F')) {
        return '3';
    } else if ((letter >= 'G' && letter <= 'I')) {
        return '4';
    } else if ((letter >= 'J' && letter <= 'L')) {
        return '5';
    } else if ((letter >= 'M' && letter <= 'O')) {
        return '6';
    } else if ((letter >= 'P' && letter <= 'S')) {
        return '7';
    } else if ((letter >= 'T' && letter <= 'V')) {
        return '8';
    } else if ((letter >= 'W' && letter <= 'Z')) {
        return '9';
    } else {
        return '?';
    }
}

// Function definition for Part B
char letter2digitB(char letter) {
    if (letter >= 'A' && letter <= 'C') {
        return '2';
    } else if (letter >= 'D' && letter <= 'F') {
        return '3';
    } else if (letter >= 'G' && letter <= 'I') {
        return '4';
    } else if (letter >= 'J' && letter <= 'L') {
        return '5';
    } else if (letter >= 'M' && letter <= 'O') {
        return '6';
    } else if (letter >= 'P' && letter <= 'S') {
        return '7';
    } else if (letter >= 'T' && letter <= 'V') {
        return '8';
    } else if (letter >= 'W' && letter <= 'Z') {
        return '9';
    } else {
        return '?';
    }
}

// This function receives a character. If the character corresponds to any capital letter of the English
// alphabet it returns the corresponding telephone digit as a character; otherwise, it returns character
// '?' to indicate that an invalid character has been entered.
//
// This function uses MULTI-BRANCH IF-ELSE STATEMENTS to determine the matching digit for the letter entered
// Works with RANGE of letters to determine the digit
