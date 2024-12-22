/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/24/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Program Description: This program reads information about movies from a
// file named movies.txt, stores the data into an array of Movie structs, sorts
// the movies by title, and allows the user to search for movie information by
// title. The program makes use of sorting and searching algorithms.
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>

using namespace std;

const int MOVIES_SIZE = 20;

// Declare a struct named Movie with 3 members for:
// title, year released, and revenue
struct Movie
{
    string title;
    int yearReleased;
    double revenue;
};

// Function prototypes
void storeMoviesArray(ifstream &inFile, Movie topMovies[], const int SIZE);
void sortMoviesTitle(Movie topMovies[], const int SIZE);
void printMoviesArray(const Movie topMovies[], const int SIZE);
int findMovieTitle(const Movie topMovies[], const int SIZE, string title);

// main() starts here
int main()
{
    // Declare file variable
    ifstream inFile;
    // Open file Movies.txt
    inFile.open("Movies.txt");
    // Check if file was opened
    if (!inFile)
    {
        cout << "File not found!" << endl << endl;
        return 1;
    }
    // Declare array of movies
    Movie topMovies[MOVIES_SIZE];
    // Declare auxiliary variables
    string title;
    int index;
    char answer;

    // Read the information from the movies file and store it in the array
    storeMoviesArray(inFile, topMovies, MOVIES_SIZE);
    // Sort the array by the movie title so the binary search can be used 
    sortMoviesTitle(topMovies, MOVIES_SIZE);
    // Start the loop
    do {
		cout << "\033[0;0H\033[2J";	// clears the screen
        // Print the movies array
        printMoviesArray(topMovies, MOVIES_SIZE);
        
        // Ask the user to input a title
        cout << "Enter the title of the movie you want to search for: ";
        getline(cin, title);  // No need for cin.ignore() here in each iteration
        
        // If the movie was not found
        if ((index = findMovieTitle(topMovies, MOVIES_SIZE, title)) == -1)
        {
            cout << "The movie was not found." << endl;
        }
        // Otherwise, print the information about the chosen movie
        else
        {
            cout << "Title: " << left << setw(30) << topMovies[index].title<<endl;
            cout << "Year: " << topMovies[index].yearReleased << "  "<<endl;
            cout << "Revenue: $" << right << setw(10) << fixed << setprecision(2) << topMovies[index].revenue << endl;
        }

        // Ask the user "Do you want to continue? (y/n): "
        cout << "Do you want to continue? (y/n): ";
        cin >> answer;
        answer = tolower(answer);
        cin.ignore();  // Clear any leftover newline character after reading 'answer'

    } while (answer == 'y');
    // Close the file
    inFile.close();

    return 0;
}

// Function definitions start here
void storeMoviesArray(ifstream &inFile, Movie topMovies[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        string line;
        getline(inFile, line);

        // Use a stringstream to split the line into title, year, and revenue
        stringstream ss(line);
        string yearStr, revenueStr;

        getline(ss, topMovies[i].title, ' ');  // Extract title until first space
        ss >> yearStr >> revenueStr;  // Extract year and revenue as strings

        // Remove any remaining extra spaces from title
        topMovies[i].title.erase(remove_if(topMovies[i].title.begin(), topMovies[i].title.end(), ::isspace), topMovies[i].title.end());

        // Convert year and revenue to integers/doubles
        topMovies[i].yearReleased = stoi(yearStr);
        topMovies[i].revenue = stod(revenueStr);
    }
}

// This function receives the input file, the movies array, and the size of the 
// array. It reads from the file the movie data and stores it in the array.
// Once all the data has been read in, it returns the array with the information 
// of the movies.

void sortMoviesTitle(Movie topMovies[], const int SIZE)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (topMovies[i].title > topMovies[j].title)
            {
                Movie temp = topMovies[i];
                topMovies[i] = topMovies[j];
                topMovies[j] = temp;
            }
        }
    }
}
// This function receives the movies array and the size of the array and sorts
// the array by title. It returns the sorted array.

void printMoviesArray(const Movie topMovies[], const int SIZE)
{
    cout << right << setw(36) << "Movie title" << setw(10) << "Year" << setw(15) << "Revenue" << endl;
    cout << string(61, '-') << endl; // Separator line for better readability
    for (int i = 0; i < SIZE; i++) // Loop from i = 0 to include all movies
    {
        cout << right << setw(36) << topMovies[i].title;
        cout << setw(10) << topMovies[i].yearReleased;
        cout << right << setw(5) << "$" <<  setw(10) << fixed << setprecision(0) << topMovies[i].revenue << endl;
    }
}
// This function receives the movies array and the size of the array and prints
// the list of movies.

int findMovieTitle(const Movie topMovies[], const int SIZE, string title)
{
    int low = 0;
    int high = SIZE - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (topMovies[mid].title == title)
            return mid;
        else if (topMovies[mid].title < title)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// This function receives the movies array, the size of the array, and the title
// of the movie to be searched for. It returns the index of the array where the title was found. If the title was 
// not found, it returns -1. It must use BINARY SEARCH to find the movie.
