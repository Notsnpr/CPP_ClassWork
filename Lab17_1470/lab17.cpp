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

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int sumList(const int list[], int size);
int indexOfMax(const int list[], int size);
// This function gets the results from the file and returns them in the corresponding
void getElectionData(ifstream & iFile, string candidates[], int ballots[], int & count);
void printResults(const string candidates[], const int ballots[], int count, int totalBallots);
const int NUM_CANDIDATES = 10; // The maximum number of candidates

int main()
{
	ifstream inFile;
	string names[NUM_CANDIDATES];	// The names of the candidates
	int votes[NUM_CANDIDATES];		// The number of votes received by each candidate
	int totalVotes;					// The total number of votes received by all candidates
	int max;						// number of candidates processed

	inFile.open("votingresults.txt");
	if (!inFile)
	{
		cout << "File not found!" << endl << endl;
		return 1;
	}
	
    ///////////////////////////////
    // Start your code here


    // Get the candidates' names and number of votes each received
    // Assume the user enters valid input (just call the getElectionData() function)
	getElectionData(inFile, names, votes, max);
	

    // Calculate the total number of votes received by all candidates
    // (call the sumList() function)
	totalVotes=sumList(votes, max);
	

    // Print each candidate's name, the number of votes she received,
    // and the percent of votes the candidate received
	// (just call the printResults() function)
	printResults(names, votes, max, totalVotes);
	
    // End of your code in the main function
    // Don't forget to complete the functions below
    ///////////////////////////////

    return 0;
}

//************************  Function definitions  *************************


//
// Returns the sum of the numbers in the given array

int sumList(const int list[], int size)
{
	// WRITE THE BODY OF THIS FUNCTION
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += list[i];
	}
	return sum;
}

// Returns the INDEX of the largest value in the given array.
// IMPORTANT: it does not return the largest value, but the INDEX of the element where it is)

int indexOfMax(const int list[], int size)
{
	// WRITE THE BODY OF THIS FUNCTION
	int max = list[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
			index = i;
		}
	}
	return index;
}

// Gets the names of the candidates and the votes they got from the file and returns
// them in the corresponding arrays. It also returns the number of rows in the file that
// were processed Makes sure it never goes over the array capacity when loading the data
// in the arrays

void getElectionData(ifstream & iFile, string candidates[], int ballots[], int & count)
{
	// WRITE THE BODY OF THIS FUNCTION
	count = 0;
	while (iFile >> candidates[count] >> ballots[count])
	{
		count++;
	}
}

// Receives the candidates names and the quantity of votes they got, the number of elements
// in the arrays to be processed, and the total number of votes so they can be displayed as
// shown in the file with the problem statement
// Must call the indexOfMax function() to find the array index of the candidate with the
// largest number of votes

void printResults(const string candidates[], const int ballots[], int count, int totalBallots)
{
	// WRITE THE BODY OF THIS FUNCTION
	cout << setw(15)<< "Candidate" << setw(15) << "Num Votes" << setw(15) << "% of Votes" << endl;
	for (int i = 0; i < count; i++)
	{
		cout <<setw(15)<< candidates[i] << setw(15) << ballots[i] << setw(15) << fixed << setprecision(2) << (static_cast<double>(ballots[i]) / totalBallots) * 100 << endl;
	}
	cout << "The winner is: " << candidates[indexOfMax(ballots, count)]<< endl;

}