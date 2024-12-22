//////////////////////////////////////////////////////////////////////
//
// Use looping to read a file until end of file is reached.
//
// Find the average of the numbers in the file.
//
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n; // The number read from the file
	int num = 0; // The number of numbers in the file. MUST initialize to 0!
	int sum = 0; // The sum of numbers in the file. MUST initilaize to 0!
	double avg; // The average of the numbers in the file
	ifstream inFile; // The input file


	// Open the input file
	inFile.open("numbers.txt");

	// If there was an error opening the input file (for example, file was not found), exit the program
	if (!inFile) 
	{
		cout << "Couldn't open input file" << endl;

		// When you return in the middle of a program, the program execution
		// stops at the point of the return statement. By convention,
		// returning the value 1 indicates that an error occurred. 
		return 1;
	}

	// Loop through the input file until end of file is reached
	// When the end of file is reached, the ifstream eof function returns
	// true. Otherwise this function returns false.
	// Gather the data needed to find the average of all numbers in 
	// the input file
	inFile >> n;
	while (inFile) 
	{
		sum += n;
		num++;
		inFile >> n;
	}

	// Find the average of all numbers in the input file
	if (num == 0)		// avoid division by zero
		avg = 0;
	else
		avg = static_cast<double> (sum) / static_cast<double> (num);

	// Print the average
	cout << "The average is: " << avg << endl;
	// close the file
	inFile.close();
	return 0;
}