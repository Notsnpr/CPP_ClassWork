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

#include <cstdlib>
#include <ctime>
using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Function prototypes
int randNumGen(int lowRange, int highRange);
string fortuneTellerA(int randomNumber);
string fortuneTellerB(int randomNumber);

int main() {
    int randomNumber;
    int lowRange = 0;
    int highRange = 4;

    // Seed the random number generator
    srand(static_cast<int>(time(NULL)));

    // Prompt the user to enter a question
    cout << "Ask a question: ";
    string question;
    getline(cin, question);

    // Generate random number
    randomNumber = randNumGen(lowRange, highRange);

    // Part A solution
    cout <<endl<< "Part A solution" << endl;
    cout <<endl<< "Answer: " << fortuneTellerA(randomNumber) << endl;

    // Part B solution
    cout <<endl<< "Part B solution" << endl;
    cout <<endl<< "Answer: " << fortuneTellerB(randomNumber) << endl;




	// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;

	test(randomNumber >= 0 && randomNumber <= 4);			// Incorrect random number (out of range)

	test(fortuneTellerA(0) == "Yes");						// Incorrect answer
	test(fortuneTellerA(1) == "Maybe");						// Incorrect answer
	test(fortuneTellerA(2) == "No");						// Incorrect answer
	test(fortuneTellerA(3) == "Ask again later");			// Incorrect answer
	test(fortuneTellerA(4) == "I don't know");				// Incorrect answer
	test(fortuneTellerA(14) == "I don't know");				// Incorrect answer

	test(fortuneTellerB(0) == "Yes");						// Incorrect answer
	test(fortuneTellerB(1) == "Maybe");						// Incorrect answer
	test(fortuneTellerB(2) == "No");						// Incorrect answer
	test(fortuneTellerB(3) == "Ask again later");			// Incorrect answer
	test(fortuneTellerB(4) == "I don't know");				// Incorrect answer
	test(fortuneTellerB(14) == "I don't know");				// Incorrect answer

	return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using expression 2) on my handout

// Function definition for randNumGen
int randNumGen(int lowRange, int highRange) {
    return (rand() % (highRange - lowRange + 1)) + lowRange;
}

// Thisfunction uses multi - branch if - else statements to determine the answer to be 
// returned based on the number received.
// It receives the random number(whole number) and returns the corresponding answer
// based on the table shown on my handout
//
// Important: in this solution make your function directly return the answer in each
// branch of the multi - branch if - else statements.

// Function definition for fortuneTellerA
string fortuneTellerA(int randomNumber) {
    if (randomNumber == 0) {
        return "Yes";
    } else if (randomNumber == 1) {
        return "Maybe";
    } else if (randomNumber == 2) {
        return "No";
    } else if (randomNumber == 3) {
        return "Ask again later";
    } else {
        return "I don't know";
    }
}

// This function uses switch statements to determine the answer to be 
// returned based on the number received.
// It receives the random number(whole number) and returns the corresponding answer
// based on the table shown on my handout
//
// Important: in this solution declare a local variable that holds text and assign
// the corresponding answer in each case of the switch statement. Upon exiting the
// switch return the value in the local variable.
// Function definition for fortuneTellerB
string fortuneTellerB(int randomNumber) {
    string answer;
    switch (randomNumber) {
        case 0:
            answer = "Yes";
            break;
        case 1:
            answer = "Maybe";
            break;
        case 2:
            answer = "No";
            break;
        case 3:
            answer = "Ask again later";
            break;
        default:
            answer = "I don't know";
            break;
    }
    return answer;
}
