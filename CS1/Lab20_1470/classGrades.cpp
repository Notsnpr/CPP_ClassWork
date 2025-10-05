/////////////////////////////////////////////////////////////////////
//
// Christine Reilly
// November 16, 2011
//
// A program that works with an array of Grade structs
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

const int CLASS_SIZE = 100;

//
// Stores a student's grades
//
struct Grades
{
	string name;
	int id;
	int test1;
	int test2;
	int test3;
};

void storeGradesArray(Grades classGrades[], const int size, ifstream& inFile);
void sortGradesId(Grades classGrades[], int size);
int findStudentId(const Grades classGrades[], int size, int target);
void printClassGrades(const Grades classGrades[], int size, int target);


int main()
{
	//char fileName[30]; // Name of the input file
	Grades myClass[CLASS_SIZE]; // Array of Grades structs
	int id; // Student id to search for
	int pos; // Position of searched for student

	ifstream inFile;
	inFile.open("classGrades.txt");

	if (!inFile)
	{
		cout << "Error opening input file" << endl;
		return 1;
	}

	// Read the file
	storeGradesArray(myClass, CLASS_SIZE, inFile);
	// Sort the list of grades by student id
	sortGradesId(myClass, CLASS_SIZE);


	// Search for the student id provided by the user
	cout << endl << endl << "Enter a studentId: ";
	cin >> id;

	pos = findStudentId(myClass, CLASS_SIZE, id);

	// Print the information about the chosen student
	// If the student was not found, print a message
	cout << endl << endl;

	if (pos == -1)
	{
		cout << "Id: " << id << " not found" << endl << endl;
	}
	else
	{
		cout << "Name: " << myClass[pos].name << ',';
		cout << " ID: " << myClass[pos].id << ',';
		cout << " Test 1: " << myClass[pos].test1 << ','
			<< " Test 2: " << myClass[pos].test2 << ','
			<< " Test 3: " << myClass[pos].test3 << endl << endl;
	}

	printClassGrades(myClass, CLASS_SIZE, pos);
	inFile.close();

	return 0;
}


//
// Reads student data from a file and stores it in an array of Grades structs
//
void storeGradesArray(Grades classGrades[], int size, ifstream& inFile)
{
	int i; // Counter

	// Read from the file into the array
	for (i = 0; i < size; ++i)
	{
		inFile >> classGrades[i].name >> classGrades[i].id;
		inFile >> classGrades[i].test1 >> classGrades[i].test2 >> classGrades[i].test3;
	}
} // end of reading file

//} // end storeGradesArray function


  //
  // Uses bubble sort to sort a list of Grades structs by the student id
  //
void sortGradesId(Grades classGrades[], int size)
{
	Grades temp;
	int i, j;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - i - 1; ++j)
		{
			if (classGrades[j].id > classGrades[j + 1].id)
			{
				temp = classGrades[j];
				classGrades[j] = classGrades[j + 1];
				classGrades[j + 1] = temp;
			}
		}
	}
} // end sortGradesId function


  //
  // Uses binary search to search an array of Grades structs for the given id.
  //
int findStudentId(const Grades classGrades[], int size, int target)
{
	int first = 0; // Beginning of the search range
	int last = size - 1; // End of the search range
	int middle; // Middle of the search range
	int pos = -1; // Position of the target, or -1 if not found
	bool found = false; // True if the target has been found

	// Use binary search to find the given title
	while (!found && first <= last)
	{
		// Calculate the middle position
		// Note that integer division gives the desired result in this case
		middle = (first + last) / 2;

		// If the middle element is the target, we are done
		if (classGrades[middle].id == target)
		{
			pos = middle;
			found = true;
		}

		// If the middle value is greater than the target value,
		// search the lower half of the search space
		else if (classGrades[middle].id > target)
		{
			last = middle - 1;
		}

		// Otherwise, search the upper half of the search space
		else
		{
			first = middle + 1;
		}
	}

	return pos;

} // end findStudentId function

void printClassGrades(const Grades classGrades[], int size, int target)
{
	cout << "     Name         ID    Test 1  Test 2  Test 3" << endl;
	cout << "--------------  ------  ------  ------  ------" << endl;
	int i;

	// Display the student id and test grades for the entire class. Mark with an arrow the target
	for (i = 0; i < size; ++i)
	{
		if (i == target)
			cout << "--> ";
		else
			cout << "    ";
		cout << setw(10) << classGrades[i].name << setw(7) << classGrades[i].id << "  " << setw(6) << classGrades[i].test1 << "  " << setw(6) << classGrades[i].test2 << "  " << setw(6) << classGrades[i].test3 << endl;
	}
}