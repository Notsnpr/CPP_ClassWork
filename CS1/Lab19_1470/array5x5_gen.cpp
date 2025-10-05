// Example of a program that uses nested for-loops to fill and print a two-dimensional array

#include <iostream>		// required to use cout, cin, and endl
#include <iomanip>

using namespace std;	// required to use the items defined in the above libraries 
const int  DIM = 5;

void print(const int table[][DIM], int maxrow, int maxcol);

int main()									// required main function
{
	int grid [DIM][DIM];					// declare a two-dimensional array
	int col;								// inner loop control variable
	int row;								// outer loop control variable
	int maxr, maxc;
	char ans;

	for (row = 0; row < DIM; ++row )		// will loop DIM times
	{
		for (col = 0; col < DIM; ++col )	// will loop DIM times
		{
			grid[row][col] = ((row + 1) * 10) + (col +1);	// fill the array with the generated values
		}
	}
	do
	{
		cout << "\033[0;0H\033[2J";
		cout << "Enter number of rows and columns you want to display [" << DIM << ',' << DIM << "]: ";
		cin >> maxr >> maxc;
		cout << endl;
		print(grid, maxr, maxc);
		cout << "Do you want to continue[y/n]?:";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	return 0;
}


void print(const int table[][DIM], int maxrow, int maxcol)
{
	int row, col;
	for (row = 0; row < maxrow; ++row )		// will loop maxrow times
	{
		cout << "Row " << row << ": ";
		for (col = 0; col < maxcol; ++col ) // will loop maxcol times
		{
			cout << setw(4) << table[row][col];
		}
		cout << endl;
	}
	cout << endl;
}