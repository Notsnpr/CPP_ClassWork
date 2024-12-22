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

// Enter here the libraries and anything else you need for the program to be compiled
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void flag_controlled_loop();
void counterNflag_controlled_loop();
void sentinel_controlled_loop();
int randNumGen(int low, int high);
void pause();
void clear_screen();

int main() {
    // Call the functions
    // Call the flag controlled loop
    flag_controlled_loop();
    // Pause the execution of the program
    pause();
    // Clear the screen
    clear_screen();

    // Call the counter controlled loop
    counterNflag_controlled_loop();
    // Pause the execution of the program
    pause();
    // Clear the screen
    clear_screen();

    // Call the sentinel controlled loop
    sentinel_controlled_loop();
    // Pause the execution of the program
    pause();

    return 0;
}

// This function uses a couple of flag-controlled loop to ensure the answer to a question is
// entered correctly. It keeps asking the question as long as the answer is not correct.
// Next, it uses another flag-controlled loop to ensure a number is entered at the keyboard.
// It keeps asking for a number as long as the value entered is invalid (not a number).


// Function definition for flag_controlled_loop
// This function uses flag-controlled loops to ensure the user enters correct information in two separate situations
void flag_controlled_loop() {
    // Declare variable to hold boolean value indicating valid input
    bool validInput = false;
    // Declare variable to hold the user's answer
    char answer;

    // Ask the user if they like ice cream
    while (!validInput) {
        cout << "Do you like ice cream? (y/n): ";
        cin >> answer;
        // Check if the input is valid ('y' or 'n')
        if (answer == 'y' || answer == 'n') {
            validInput = true;
        } else {
            // Display error message for invalid input
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }

    // Reset validInput for next input validation
    validInput = false;
    // Declare variable to hold the user's age
    int age;

    // Ask the user to enter their age
    while (!validInput) {
        cout << "Enter your age: ";
        cin >> age;
        // Check if the input stream is in a fail state (invalid input)
        if (!cin) {
            // Clear the error state and ignore invalid input
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        } else {
            validInput = true;
        }
    }
}


// This function uses a mix of counter-controlled and flag-controlled loops to implement a guessing game.
// It generates a random number (1..100) and gives the user five chances to guess it. The user receives
// feedback from the program regarding whether the guessed number is too high or too low, if it is
// incorrect. If the guess is correct, they get a message indicating they win.
// The loop is exited when the user guesses correctly or when they have gone over the five attempts.


// Function definition for counterNflag_controlled_loop
// This function uses a mix of counter-controlled and flag-controlled loops to implement a guessing game
void counterNflag_controlled_loop() {
    // Declare variable to hold a random (whole) number
    int randomNumber;
    // Declare variable to hold the (whole) number guessed by the user
    int guess;
    // Declare variable that holds boolean values and initialize it to false
    bool guessedCorrectly = false;
    // Declare variable to hold the (whole) number used to keep track of the number of guesses made by the user and initialize it to zero
    int attempts = 0;

    // Seed the random generator
    srand(static_cast<int>(time(NULL)));
    // Call function randNumGen to generate a random number between 1 and 100 and assign the value to the variable
    randomNumber = randNumGen(1, 100);

    // Note: Implement a WHILE-LOOP that gives the user five chances to guess the number generated above.
    // While the guess is not correct and the user has not used their five chances
    while (!guessedCorrectly && attempts < 5) {
        // Prompt the user to "guess the number the computer randomly picked between 1 - 100: "
        cout << "Guess the number (1-100): ";
        // Get the number from the user and save it in the corresponding variable
        cin >> guess;

        // Update quantity of guesses
        attempts++;

        // If the guess is smaller than the number
        if (guess < randomNumber) {
            // Display "sorry, your guess is too low"
            cout << "Too low. Try again." << endl;
        }
        // Otherwise, if the guess is bigger than the number
        else if (guess > randomNumber) {
            // Display "sorry, your guess is too high"
            cout << "Too high. Try again." << endl;
        }
        // Otherwise
        else {
            // Display "you guessed right, you win!"
            cout << "You guessed it!" << endl;
            // Set correct to true to stop the loop
            guessedCorrectly = true;
        }
    }

    // End of the loop for the guessing game
    // If the guess is not correct
    if (!guessedCorrectly) {
        // Display "Sorry, you lost. The number is: ", number
        cout << "Sorry, you've used all 5 attempts. The number was: " << randomNumber << endl;
    }
}


// This function uses a sentinel-controlled loop to get whole numbers greater than or equal to zero in
// order to calculate their average. It keeps asking for a grade until the user enters a negative value
// Then, it calculates and displays the average.

// Function definition for sentinel_controlled_loop
// This function uses a sentinel-controlled loop to calculate the average of non-negative grades entered by the user
void sentinel_controlled_loop() {
    // Declare variable to hold the grade entered by the user
    int grade;
    // Declare variable to hold the sum of grades entered
    int sum = 0;
    // Declare variable to hold the count of grades entered
    int count = 0;

    // Ask the user to input grades until a negative value is entered
    cout << "Enter grades (enter a negative value to finish): " << endl;
    while (true) {
        // Get the grade from the user
        cin >> grade;
        // If the grade is negative, exit the loop
        if (grade < 0) {
            break;
        }
        // Add the grade to the sum
        sum += grade;
        // Increment the count of grades entered
        count++;
    }

    // If at least one grade was entered, calculate and display the average
    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "The average grade is: " << average << endl;
    } else {
        // Otherwise, display that no grades were entered
        cout << "No grades were entered." << endl;
    }
}

// This function generates a random number within a specified range.
// It receives two whole numbers : the first one is the upper boundary and
// the second one is the lower boundary used to generate the random number.
// Returns the random number generated using the expression:
//             rand() % (upper - lower + 1)) + lower

// Function definition for randNumGen
// This function generates a random number between the given low and high values
int randNumGen(int low, int high) {
    return (rand() % (high - low + 1)) + low;
}

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