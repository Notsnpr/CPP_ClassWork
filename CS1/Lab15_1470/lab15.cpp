/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/24/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// 
// 
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

// Function prototypes
void pause();
void clear_screen();
int randNumGen(int upper, int lower);
int getSeed();
void guessNumber();
void pigRoll();

using namespace std;

int main()
{
	guessNumber();
	// Pause the execution of the program
	cout << "Press Enter to continue ...";
	cin.sync();
	cin.ignore();
	cin.get();
	// Clear the screen
	// system("clear");
	pigRoll();
	return 0;
}

//************************  Function definitions  *************************
// This functions pauses the execution of the program
void pause()
{
	cout << "Press Enter to continue ...";
	cin.sync();
	cin.ignore();
	cin.get();
}

// This function clears the screen
void clear_screen()
{
	cout << "\033[0;0H\033[2J";	// clears the screen
}


// Read the handout carefully for detailed description of the functions that you have to implement

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using expression 2) on my handout

int randNumGen(int upper, int lower)	// function heading
{										// function body
	return (rand() % (upper - lower + 1)) + lower;
}

// This function prompts the user to enter a seed (a whole number) equal to zero (0) or 
// within the range 1000..4000. If the user enters a valid value the function returns 
// the value. Otherwise it keeps asking for the seed.
// Use a DO-WHILE-LOOP to implement this function

int getSeed()
{
	int seed;
    do {
        cout << "Enter a seed equal to 0 or within the range 1000-4000:  ";
        cin >> seed;
        if (seed == 0 || (seed >= 1000 && seed <= 4000)) {
            break;
        } else {
            cout << "Sorry, but your seed is invalid. Please try again." << endl;
        }
    } while (true);
    return seed;
}

// This function generates a random number and gives the user five chances to guess it.
// As the user provides a guess the program indicates whether the guess was correct
// or if it was too low or too high to help her/him.
// If the user runs out of guesses it shows her/him the number
// MUST use a FOR-LOOP to implement this function

void guessNumber()
{
	// Get the seed value from the user
    int seed = getSeed();
    // Seed the random number generator
    if (seed == 0) {
        srand(static_cast<int>(time(NULL)));
    } else {
        srand(seed);
    }

    // Generate a random number between 1 and 100
    int randomNumber = randNumGen(1, 100);
    int guess;

    // Allow the user up to 5 guesses using a for loop
    for (int i = 1; i <= 5; ++i) {
        cout << "Guess the number the computer randomly picked between 1 - 100:  ";
        cin >> guess;

        if (guess == randomNumber) {
            cout << "You guessed right, you win!" << endl;
            break;
        } else if (guess < randomNumber) {
            cout << "Sorry, your guess is too low" << endl;
        } else {
            cout << "Sorry, your guess is too high" << endl;
        }

        if (i == 5) {
            cout << "Sorry, you lost. The number is: " << randomNumber << endl;
        }
    }

}

// This function simulates the pig dice game.Version 1.2
// It simulates a computer controlled player by rolling a die
// numbered 1 through 6 until the total_turn number is greater
// than 20 or until it rolls a 1. Once the computer finishes its
// turn, the function terminates.

void pigRoll()
{
	int turnTotal = 0;
    int roll;

    cout << "Computer is taking its turn in the Pig game..." << endl;

    // Roll until the turn total is 20 or greater, or a 1 is rolled
    while (turnTotal < 20) {
        roll = randNumGen(1, 6);
        cout << "Computer rolled: " << roll << endl;

        if (roll == 1) {
            cout << "Computer rolled a 1. Turn ends with no points." << endl;
            turnTotal = 0;
            break;
        } else {
            turnTotal += roll;
            cout << "Turn total: " << turnTotal << endl;
        }
    }

    if (turnTotal >= 20) {
        cout << "Computer ends its turn with " << turnTotal << " points." << endl;
    }
}