/////////////////////////////////////////////////////////////////////
// 
// Christine Reilly
// February 10, 2011
//
// Given x, y, calculate x to the power of y
/////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main()
{
    int x, y; // x to the power of y
    int i; // loop counter
    int pow = 1; // result

    // Ask the user to enter x and y
    cout << "Find the value of x to the power of y" << endl;
    cout << "Enter the integer value for x: ";
    cin >> x;
    cout << "Enter the integer value for y: ";
    cin >> y;

    // Calculate x to the power of y using a for loop
    // Initialize i to 0;
    // We want to multiply x by itself y times, so loop y times;
    // Increment i by 1 at the end of each iteration
    // Remember that x^0 = 1 and x^1 = x
    for (i = 0 ; i < y ; i++) 
    {
        // Each time through the loop multiply pow by x
        pow *= x;
    }

    // Print the result
    cout << x << " to the power of " << y << " = " << pow << endl;

    return 0;
}

/*
Sample output:

Find the value of x to the power of y
Enter the integer value for x: 2
Enter the integer value for y: 8
2 to the power of 8 = 256
Press any key to continue . . .

*/
