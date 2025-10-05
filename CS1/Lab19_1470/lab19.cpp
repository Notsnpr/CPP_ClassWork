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
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

// Declare constant DIM = 7
const int DIM = 7;



// Inserte prototypes here
void createBoard(char board[][DIM], int size);
void printBoard1(char board[][DIM], int size);
void printBoard2(char board[][DIM], int size);

int main()
{
	// Declare a two-dimensional array (using the constant) to hold single characters
	char board[DIM][DIM];
	// Declare variable bsize to hold a whole number
	int bsize;
	// Declare variable answer to hold a character
	char answer;
	// Use a do-loop to allow the user to try again
	do{
		// Prompt the user "Please enter the size of the board [1-7]: "
		cout << "Please enter the size of the board [1-7]: ";
		// Get the size and store it in bsize
		cin >> bsize;
		// Check the input stream. If it is invalid, display error message "Invalid entry" and jump out of the loop
		if (!cin)
		{
			cout << "Invalid entry" << endl;
			break;
		}
		// Check if bsize is within the range. If it is, call the functions
		if (bsize >= 1 && bsize <= 7){
			// Call the function to create the checkerboard
			createBoard(board, bsize);
			// Call the function to print the checkerboard
			printBoard1(board, bsize);
			// Call the function to print the rotated checkerboard
			printBoard2(board, bsize);
		}
		else
		{
			cout << "Invalid size" << endl;
		}
		// Prompt the user "Do you want to try again [y-n]?: "
		cout << "Do you want to try again [y-n]?: ";
		// Get the answer and store in answer
		cin >> answer;
		// As long as the answer is 'y' (in upper or lower case), keep looping
	} while (answer == 'y' || answer == 'Y');

	
	return 0;
}
// Function definitions

// createBoard(): Receives the two-dimensional array and the size of the board (quantity of rows and columns)
void createBoard(char board[][DIM], int size)
{
	char letter = 'A';
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = letter;
                letter++;
                if (letter > 'Z') {
                    letter = 'A';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}
// printBoard1(): Receives the two-dimensional array and the size of the board (quantity of rows and columns)
// Using nested loops prints the board
void printBoard1(char board[][DIM], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
	cout<<endl;
}
// printBoard2(): Receives the two-dimensional array and the size of the board (quantity of rows and columns)
// Using nested loops prints the board rotated

void printBoard2(char board[][DIM], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
	cout<<endl;
}