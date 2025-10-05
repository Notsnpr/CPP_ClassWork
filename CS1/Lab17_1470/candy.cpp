/////////////////////////////////////////////////////////////////////

// This program asks the user to input the name and number sold for each
// type of candy. Then it displays the average of the total sales and
// reports which candies had below average sales.
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

double average(const double list[], int size);


// Use a constant to specify the size of the arrays. This makes it easy
// to change the size of the arrays because you only need to change the
// value of the constant.
const int NUM_CANDY = 3; // The number of types of candy

int main()
{
    int i; // A counter
    double avgTotal; // Average of total sales

    // These four variables are the parallel arrays. They are all the same size
    string names[NUM_CANDY]; // Name of the candy
    double unitPrice[NUM_CANDY]; // Unit price of the candy
    int quantity[NUM_CANDY]; // Quantity sold of the candy
    double totalSales[NUM_CANDY]; // Total price of candy sold
	

    // Ask the user to enter the name, unit price, and quantity sold for each candy
    // Assume the user enters valid input
    // Calculate the amount of money for each candy's sales
    
    // Notice how I use the same index value to access the corresponding
    // components of the parallel arrays.
    for( i = 0; i < NUM_CANDY; i++ )
    {
        // get the name, price, and quantity sold from the user
        // Use getline so the user can enter a name with multiple words
        cout << "Enter the name of the candy: ";
        getline(cin, names[i]);

        cout << "What is the unit price of " << names[i] << "? ";
        cin >> unitPrice[i];

        cout << "How many " << names[i] << " were sold? ";
        cin >> quantity[i];

        // Calculate the total price of the candy that was sold
        totalSales[i] = unitPrice[i] * quantity[i];

        // Take the end line off the input stream so the getline in the next 
        // loop will work properly
        cin.ignore(5000, '\n');

        // For nice output formatting
        cout << endl;

    } // end of for loop to get user input

    // Find the average of the total sales
    avgTotal = average(totalSales, NUM_CANDY);
    cout << "The average total sales is: $";
    cout << fixed << setprecision(2) << avgTotal << endl;

    // Print the information for candies with total sales below average
    cout << endl;
    cout << "These candies have a total sales below the average:" << endl;
    cout << setw(15) << "Name";
    cout << setw(15) << "Unit Price";
    cout << setw(15) << "Quant Sold";
    cout << setw(15) << "Total Price" << endl;

    // Notice again how I use the same index to access the corresponding
    // components of the parallel arrays.
    for( i = 0; i < NUM_CANDY; i++ )
    {
        if( totalSales[i] < avgTotal )
        {
            cout << setw(15) << names[i];
            cout << setw(15) << unitPrice[i];
            cout << setw(15) << quantity[i];
            cout << setw(15) << totalSales[i];
            cout << endl;
        }
    }
	cout << endl;

    return 0;
}

//
// Calculates the average of integers in an array
//
// Notice that I use a generic name for the function. This allows us
// to easily reuse this function for another program.
//
double average(const double list[], int size)
{
    double sum = 0; // sum of numbers in the array
    double avg; // average of numbers in the array
    int i; // A counter

    for( i = 0; i < size; i++ )
    {
        sum += list[i];
    }
    avg = sum / static_cast<double>(size);
    return avg;
} // end of average function
