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
#include <iomanip>
#include <string>
#include <cmath>		// to be able to use the function round()
// Include here the libraries that your program needs to compile


using namespace std;

// Insert here your function prototypes
int	getData(ifstream & iFile, string names[], int grades[]);
int	getMax(const int grades[], int count);
void printData(ofstream &outputFile, const string names[], const int grades[], int numStudents, int highestGrade);
int	curveGrade(int actualGrade, int highestGrade);

// Declare here global constant MAX
const int MAX = 40;

int main()
{
	// Declare all the variables that will be used to process the data
	ifstream inputFile;
	ofstream outputFile;
	string names[MAX];
	int grades[MAX];
	int numStudents;
	int highestGrade;
	// Open the files ensuring they are opened
	inputFile.open("input18.txt");
	// Call the functions to process the data
	numStudents = getData(inputFile, names, grades);
	highestGrade = getMax(grades, numStudents);
	// Open the output file
	outputFile.open("output18.txt");
	// Call the function to print the data
	printData(outputFile, names, grades, numStudents, highestGrade);
	// Close the files
	inputFile.close();
	outputFile.close();
	// End the program
return 0;		
}


//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// Receives the input file, the array of students� names, and the array of students� grades.
// It reads the input data from the file into the corresponding arrays and returns them along
// with the quantity of students processed to main().Although there should be no more than 40
// students, this function must ensure that if the file has more than 40 records it reads only
// the first 40 and displays a warning on the screen indicating that the maximum has been exceeded.

int	getData(ifstream & iFile, string names[], int grades[])
{
	// WRITE THE BODY OF THIS FUNCTION
	int count = 0;
	while (iFile >> names[count] >> grades[count])
	{
		count++;
		if (count == 40)
		{
			cout << "The maximum number of students has been exceeded." << endl;
			break;
		}
	}
	return count;
}

// Receives the array of students� grades and the quantity of grades to process. It determines
// and returns to main() the highest grade of the class.

int	getMax(const int grades[], int count)
{
	// WRITE THE BODY OF THIS FUNCTION
	int max = grades[0];
	for (int i = 1; i < count; i++)
	{
		if (grades[i] > max)
			max = grades[i];
	}
	return max;
}



// Receives the output file, the array of students� names, the array of students� grades, the
// quantity of students to process, and the highest grade of the class.It sends the output
// to the output file as shown in Figure 2. This function must call a function named curveGrade()
// to get the values for the curved grades(curved grade = actual grade / highest grade * 100).

void printData(ofstream &outputFile, const string names[], const int grades[], int numStudents, int highestGrade) {
    outputFile << "    Student        Actual      Curved         Graph" << endl;
    outputFile << "    Name           Grade       Grade" << endl;
    outputFile << "-----------------   --------    --------    -----------" << endl;

    for (int i = 0; i < numStudents; i++) {
        int curvedGrade = curveGrade(grades[i], highestGrade);
        int numAsterisks = (curvedGrade + 5) / 10;  // Rounding to the nearest integer

        outputFile << setw(17) << names[i]
                   << setw(12) << grades[i]
                   << setw(12) << curvedGrade << "    |";

        for (int j = 0; j < numAsterisks; j++) {
            outputFile << "*";
        }
        outputFile << endl;
    }
}


// Receives the actual grade of a student and the highest grade of the class and returns the curved grade.
// The arguments that it receives are whole numbers. The result of the division must be rounded off to
//  the nearest integer before it is returned by the function.

int	curveGrade(int actualGrade, int highestGrade)
{
	// WRITE THE BODY OF THIS FUNCTION
	return (round(static_cast<double>(actualGrade) / highestGrade * 100));
}
