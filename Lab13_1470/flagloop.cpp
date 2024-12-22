// Example of a flag-controlled loop
// This program adds the values read from the keyboard and accumulates them in another variable
// until an event occurs, a negative number is read, and a flag is set to false.
//
// Flag-controlled loops can be used in place of a sentinel-controlled loops.
// The difference is that flag-controlled loops do not require priming read

#include <iostream>
using namespace std;

// This functions pauses the execution of the program
void pause()
{
	cout << "Press Enter to continue ...";
	cin.sync();
	cin.ignore();
	cin.get();
}

// This function clears the screen
void clear_screen()
{
	cout << "\033[0;0H\033[2J";	// clears the screen
}

int main()
{
	int value;						// value read from keyboard
	int total;						// accumulator
	bool flag;						// flag used to control the loop

	total = 0;						// initialize the accumulator

	flag = true;					// set the flag to true
// The number of loops that the program will take is unknown.
	while(flag)						// values from the keyboard will be read in as long
	{								// as the flag remains with value true
		cout << "Please enter a number: ";
		cin >> value;				// read the input value
		if (value < 0)				// test for the special event.If it occurs,
		{
			cout << "\nThere are no more values to be read from the keyboard\n" << endl;
			 pause();
			clear_screen();
			flag = false;			// set the flag to false so the loop is exited
		}
		else						// otherwise do what corresponds
		{
			cout << "The value read is " << value << endl;
			total = total + value;
		}
	}
	cout << endl << "The addition of the values read in is " << total << endl << endl;

	return 0;
}
