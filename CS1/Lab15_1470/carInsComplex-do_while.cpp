//////////////////////////////////////////////////////////////////////
//
// Christine Reilly
// February 8, 2011
//
// Revised: September 7, 2011
//
// Calculate the car insurance premium based on the following rules:
// - (Gender); (Age); (Annual Premium)
// - Male; Under 21; 1500 + 200 for every ticket on record
// - Male; 21 to 29; 1200 + 100 for every ticket on record
// - Male; 30 and older; 1000 + 100 for every ticket on record
// - Female; Under 21; 1200 + 200 for every ticket on record
// - Female; 21 and older; 1000 + 100 for every ticket on record
//
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main()
{

	char gender; // The customer's gender
	int age; // The customer's age
	int numTix; // Number of tickets the customer has had
	int premium; // Customer's insurance premium

	// Use a char variable to store if the user chooses to ask another question.
	char askAgain; // If the user wants to ask another question

	do
	{
		system("cls");
		// Get information from the user
		// We will assume that the user always enters correct input

		// Get the user's gender
		cout << "Enter your gender (M/F): ";
		cin >> gender;

		// Get the user's age
		cout << "Enter your age as an integer: ";
		cin >> age;

		// Get the number of tickets
		cout << "How many tickets do you have: ";
		cin >> numTix;

		// Calculate the insurance premium
		if (gender == 'M' && age < 21)
		{
			premium = 1500 + 200 * numTix;
		}
		else if (gender == 'M' && age >= 21 && age < 30)
		{
			premium = 1200 + 100 * numTix;
		}
		else if (gender == 'M' && age >= 30)
		{
			premium = 1000 + 100 * numTix;
		}
		else if (gender == 'F' && age < 21)
		{
			premium = 1200 + 200 * numTix;
		}
		else
		{
			premium = 1000 + 100 * numTix;
		}

		// Print the result
		cout << "Your premium is $" << premium << endl << endl;

		// At some point in the while loop we must update the variable that is
		// part of the while loop's condition. If we don't update the condition
		// variable, the program will never end (it will be an infinite loop)! 
		// So we ask the user if she wants to continue and store her answer in 
		// the askAgain variable. 
		// Assume the user always enters vaild input
		cout << "Would you like to ask another question? (y/n): ";
		cin >> askAgain;
	} while (askAgain == 'y');



	return 0;
}
