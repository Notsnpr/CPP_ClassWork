/////////////////////////////////////////////////////////////////////
//
// Given x, y, calculate x to the power of y
/////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int power(int base, int expo);		// function prototype

int main()
{
	int x, y; // x to the power of y
	int i = 0;
	int result;		// result

	// Ask the user to enter x and y
	cout << "Find the value of x to the power of y" << endl;
	cout << "Enter the integer value for x: ";
	cin >> x;
	cout << "Enter the integer value for y: ";
	cin >> y;

	result = power(x, y);	// call the function to calculate x to the power of y
	// Print the result
	cout << x << " to the power of " << y << " = " << result << endl;

	return 0;
}

// function definition
int power(int base, int expo)
{
	int pow = 1;	// resulting power
	int i;			// loop counter
	i = 0;			// initialize loop counter
	while (i < expo)	// test the counter
	{
		// Calculate base to the power of expo using a while loop
		// We want to multiply base by itself expo times, so loop expo times
		// Remember that x^0 = 1 and x^1 = x
		// Each time through the loop multiply pow by base
		pow *= base;	// this is equivalent to pow = pow * base;

		// Update the counter
		++i;			// this is equivalent to i = i + 1;
	}
	return pow;	// return the resulting power
}



/*
Sample output:

Find the value of x to the power of y
Enter the integer value for x: 2
Enter the integer value for y: 8
2 to the power of 8 = 256
Press any key to continue . . .

*/
