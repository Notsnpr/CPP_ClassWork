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
//	Gives Change in coins
/////////////////////////////////////////////////////////////////////


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

// Insert here the prototypes of the functions

void coinChanger(int cents, int &c25, int &c10, int &c05, int &c01, int &coinCount);

void printChange(int cents, int c25, int c10, int c05, int c01, int coinCount);



int main() {
    int amount, count25, count10, count5, count1, count;

    // Prompt user for input
    cout << "Enter amount in cents to be returned as change: ";
    cin >> amount;

    // Call coinChanger function to calculate the number of coins
    coinChanger(amount, count25, count10, count5, count1, count);

    // Call printChange function to print the result
    printChange(amount, count25, count10, count5, count1, count);
	
						// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	//test(typeid(cents) == typeid(1));					// Incorrect data type used for cents
	test(typeid(count25) == typeid(1));						// Incorrect data type used for count25
	test(typeid(count10) == typeid(1));						// Incorrect data type used for count10
	test(typeid(count5) == typeid(1));						// Incorrect data type used for count5
	test(typeid(count1) == typeid(1));						// Incorrect data type used for count1
	test(typeid(amount) == typeid(1));						// Incorrect data type used for amount
	test(typeid(count) == typeid(1));						// Incorrect data type used for count
	coinChanger(71, count25, count10, count5, count1, count);
	test(count25 == 2 );										// Incorrect quantity of quarters
	test(count10 == 2);										// Incorrect quantity of dimes
	test(count5 == 0);										// Incorrect quantity of nickels
	test(count1 == 1);										// Incorrect quantity of pennies
	coinChanger(69, count25, count10, count5, count1, count);
	test(count25 == 2);										// Incorrect quantity of quarters
	test(count10 == 1);										// Incorrect quantity of dimes
	test(count5 == 1);										// Incorrect quantity of nickels
	test(count1 == 4);										// Incorrect quantity of pennies
	coinChanger(14, count25, count10, count5, count1, count);
	test(count25 == 0);										// Incorrect quantity of quarters
	test(count10 == 1);										// Incorrect quantity of dimes
	test(count5 == 0);										// Incorrect quantity of nickels
	test(count1 == 4);										// Incorrect quantity of pennies

	return 0;
}

//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// Calculate the quantity of each type of coin and the total number of coins that are needed to provide a given change
// and return all these values along with the total number of coins that are needed for the change

// Function to calculate the quantity of each type of coin
void coinChanger(int cents, int &c25, int &c10, int &c05, int &c01, int &coinCount) {
    // Calculate quarters
    c25 = cents / 25;
    cents = cents % 25;
    
    // Calculate dimes
    c10 = cents / 10;
    cents = cents % 10;
    
    // Calculate nickels
    c05 = cents / 5;
    cents = cents % 5;
    
    // Calculate pennies
    c01 = cents;
    
    // Total coin count
    coinCount = c25 + c10 + c05 + c01;
}

// Function to print the change details
void printChange(int cents, int c25, int c10, int c05, int c01, int coinCount) {
    cout << "You need to use " << coinCount << " coins for a change of " << cents << " cents:" << endl;
    cout << c25 << " Quarters" << endl;
    cout << c10 << " Dimes" << endl;
    cout << c05 << " Nickels" << endl;
    cout << c01 << " Pennies" << endl;
}



// Print the amount of cents, the quantity of each type of coin and the total number of coins 
// according to the format specifies on my handout
