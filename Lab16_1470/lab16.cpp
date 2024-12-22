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
using namespace std;

// Function prototype
void printHotelOccupancy(ifstream &inputFile);

int main() {
    ifstream inputFile("occupants.txt");
    
    // Ensure the file opened successfully
    if (!inputFile) {
        cout << "Error: Could not open the occupants file." << endl;
        return 1;
    }

    // Call the function to print hotel occupancy details
    printHotelOccupancy(inputFile);

    // Close the file
    inputFile.close();
    
    return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement


// This function receives an input file with data about rooms in a hotel.
// Each row of the file represents a floor in the hotel. You do not know ahead of time how many floors there are in the hotel.
// Each room is represented by a single digit: 1 (the room is occupied) or 0 (the room is not occupied).
// Because each floor can have a different number of rooms, the value -1 is used to indicate that the end of data for that floor has been reached.
// The function must print the header of the table followed by the floor number, the number of rooms occupied in that floor, and the occupancy
// rate (percentage of rooms occupied) for that floor. Below this information it must display the 
// overall occupancy rate (total number of occupied rooms/total number of rooms) for the whole hotel.
// The rates must be displayed real numbers with a single decimal digit.


// Function definition for printHotelOccupancy
// This function reads the occupancy data from the input file and prints the occupancy table
void printHotelOccupancy(ifstream &inputFile) {
    int floorNumber = 1;
    int totalRooms = 0;
    int totalOccupied = 0;
    
    cout << fixed << setprecision(1);
    cout << "Floor | Occupants  | Rate (%)" << endl;
    cout << "------------------------------" << endl;
    
    // Read through each floor in the file
    while (!inputFile.eof()) {
        int room;
        int roomsOnFloor = 0;
        int occupiedRoomsOnFloor = 0;

        // Read each room's occupancy status until -1 is found
        while (inputFile >> room && room != -1) {
            roomsOnFloor++;
            if (room == 1) {
                occupiedRoomsOnFloor++;
            }
        }

        // Calculate and display the occupancy rate for the current floor
        if (roomsOnFloor > 0) {
            double occupancyRate = (static_cast<double>(occupiedRoomsOnFloor) / roomsOnFloor) * 100;
            cout << setw(2) << floorNumber << "   | " << setw(9) << occupiedRoomsOnFloor << " | " << setw(8) << occupancyRate << "%" << endl;
        }

        // Update totals
        totalRooms += roomsOnFloor;
        totalOccupied += occupiedRoomsOnFloor;
        floorNumber++;
    }

    // Calculate and display the overall occupancy rate
    if (totalRooms > 0) {
        double overallOccupancyRate = (static_cast<double>(totalOccupied) / totalRooms) * 100;
        cout << "\nThe overall occupancy rate is: " << overallOccupancyRate << "%" << endl;
    } else {
        cout << "\nNo data available." << endl;
    }
}




