#include <iostream>
using namespace std;

// Global constant variable to specify the array dimensions
const int BOARD_SIZE = 4;

// Function prototypes
void createBoard(int board[][BOARD_SIZE], int startNum);
void printBoard1(const int board[][BOARD_SIZE]);
void printBoard2(const int board[][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int startNum;

    cout << "Enter the starting number for the checkerboard: ";
    cin >> startNum;

    // Create the checkerboard
    createBoard(board, startNum);

    // Print the checkerboard as is (Figure 1)
    printBoard1(board);

    // Print the checkerboard in reverse order (Figure 2)
    printBoard2(board);

    return 0;
}

// Function to create the checkerboard
void createBoard(int board[][BOARD_SIZE], int startNum) {
    int currentNum = startNum;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = currentNum;
                currentNum++;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

// Function to print the checkerboard as is (Figure 1)
void printBoard1(const int board[][BOARD_SIZE]) {
    cout << "Checkerboard (Figure 1):\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print the checkerboard in reverse order (Figure 2)
void printBoard2(const int board[][BOARD_SIZE]) {
    cout << "Checkerboard in reverse order (Figure 2):\n";
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        for (int j = BOARD_SIZE - 1; j >= 0; j--) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
