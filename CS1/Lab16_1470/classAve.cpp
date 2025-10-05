/////////////////////////////////////////////////////////////////////
// 
// Christine Reilly
// October 5, 2011
//
// Given a data file of student grades with each line formatted as:
//     Name Exam1 Exam2 Exam3
// Where Exam1, Exam2, and Exam3 are the exam grades for the given
// student. This program calculates the average grade for each
// student, then uses those average grades to calculate the final
// class average. The results are written to an output file.
//
// This program demonstrates the following skills:
// - Nested loops
// - File I/O and output formatting
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream> // for file i/o
#include<string> // so we can use the string data type
#include<iomanip> // for the output manipulators

using namespace std;

int main()
{
	ifstream inFile; // input file
	ofstream outFile; // output file
	int grade; // Grade read from file
	string name; // Student's name (read from file)
	int sumStudent; // Sum of a student's exam grades
	double studentAve; // Student's average exam grade
	double sumClass; // Sum of the class grades. 
					 // A double because studentAve is double
	int countStudents; // Number of students in the class
	double classAve; // Average final class grade
	int i; // a counter for the for loop

	// Print a message telling the user the program is running
	cout << "Running the classAve program." << endl;
	cout << "Output is saved to aveGrades.txt file" << endl;

	// Open the input file
	inFile.open("grades.txt");

	// Check for failure opening the input file
	if ( !inFile )
	{
		cout << "Error opening input file" << endl;
		return -1; // exit the program indicating an error
	}

	// Open the output file
	outFile.open("aveGrades.txt");

	// Check for failure opening the output file
	if ( !outFile )
	{
		cout << "Error opening output file" << endl;
		return -1; // exit the program indicating an error
	}

	// Initialize the sum of class grades to zero
	sumClass = 0;

	// Initialize the student count to zero
	countStudents = 0;

	// Loop through each line of the file
	while( !inFile.eof() )
	{
		// Before reading each line of the file, initialize the
		// sum of the student's grades to zero. We want to start
		// with a sum of zero for each student.
		sumStudent = 0;

		// Read the first item in the line, the student's name
		inFile >> name;

		// Loop through the grades. We use a for loop because we 
		// know ahead of time that each student has three grades.
		for ( i = 0; i < 3; i++ )
		{
			// Get the grade
			inFile >> grade;

			// Add the grade to the sum
			sumStudent += grade;
		}

		// After reading all the grades for a single student,
		// calculate that student's average grade
		studentAve = sumStudent / 3.0; // Watch out for integer division!

		// Add the student's average to the class sum and increment the
		// number of students counter
		sumClass += studentAve;
		countStudents++;

		// Print the student's name and average to the output file
		// Use output formatting to print in a tabular format
		// Print exactly two decimal places
		outFile << setw(10) << name;
		outFile << fixed << setprecision(2);
		outFile << setw(7) << studentAve << endl;

		// That is all we have to do for each student in the file.

	} // End of the while loop for reading the file

	// Now we calculate the average for the whole class and print
	// the result to the file
	classAve = sumClass / countStudents;

	outFile << "Class Average = " << classAve << endl;


	// Close the files
	inFile.close();
	outFile.close();

	system("pause");

	return 0;
}