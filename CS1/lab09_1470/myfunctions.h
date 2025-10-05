/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/2/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
/////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>	
#include <cmath>
#include <iomanip>
#include <string>
//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// round_off(): Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off(double x, int n){
	return round(x*pow(10,n))/pow(10,n);
}

// getData(): Gets two lengths from the keyboard and returns them to the caller
double getData( double & x, double & y){
    cout<<"Please enter two lengths: ";
    cin >> x >>y;
    return (x,y);
}

// printData(): Receives the output file, base of the rectangle, height of the rectangle, area of the rectangle,
void printData(ofstream &file, double base_rec, double height_rec, double a_rec, double ra, double rb, double ae){
    file << fixed << setprecision(2);
    file << "The area of the rectangle with base " << base_rec << " and height " << height_rec << " is " << a_rec << endl;
    file << "The area of the ellipse with radius " << ra << " and radius " << rb << " is " << ae << endl;
}

// radius a of the ellipse, radius b of the ellipse, and area of the ellipse and prints the output to the file



// area_rectangle(): Calculates the area of the rectangle and returns it rounded to 1 decimal digit to the caller
double area_rectangle(double b, double h){
    double area = b * h;
    return round_off(area, 1);
}

// area_ellipse(): Calculates the area of the area_ellipse and returns it rounded to 1 decimal digit to the caller

double area_ellipse(double ra, double rb){
    double area = PI * ra * rb;
    return round_off(area, 1);
}

