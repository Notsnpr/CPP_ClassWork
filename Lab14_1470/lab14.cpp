/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/24/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Program Description: Enter here your description of what the program does
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void eof_controlled_loop();
void pause();
void clear_screen();

int main() {
    // Call the EOF controlled loop
    eof_controlled_loop();
    return 0;
}

// Function definition for eof_controlled_loop
// This function uses an EOF-controlled loop to search for a user-provided word in a dictionary file
void eof_controlled_loop() {
    // Declare variable to hold the word entered by the user
    string word;
    // Prompt the user to enter a word to search for
    cout << "Enter a word to search for in the dictionary: ";
    cin >> word;

    // Open the dictionary file
    ifstream dictionary("dictionary.txt");
    // Check if the file was opened successfully
    if (!dictionary) {
        cout << "Error: Could not open the dictionary file." << endl;
        return;
    }

    // Declare variable to hold the word read from the file
    string fileWord;
    bool found = false;
    int lineNumber = 0;

    // Use an EOF-controlled while loop to search for the word
    while (dictionary >> fileWord) {
        lineNumber++;
        // If the word matches the user-provided word
        if (fileWord == word) {
            // Set found to true and break out of the loop
            found = true;
            break;
        }
    }

    // Close the dictionary file
    dictionary.close();

    // If the word was found, display a success message with the line number
    if (found) {
        cout << "The word " << word << " was found in the dictionary on line " << lineNumber << "." << endl;
    } else {
        // Otherwise, display a failure message
        cout << "The word " << word << " was not found in the dictionary." << endl;
    }
}