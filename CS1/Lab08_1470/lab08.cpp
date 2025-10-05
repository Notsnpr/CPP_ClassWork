/////////////////////////////////////////////////////////////////////
//
// Name: Victor Munoz
// Date: 10/2/2024
// Class: CSCi 1470.05
// Semester: Fall 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
// code that gets the volume of a cone
/////////////////////////////////////////////////////////////////////

#include <typeinfo>				// to be able to use operator typeid
// Include here the libraries that your program needs to compile
#include <iostream>	
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
double volume_cone(int , int);
double square(double);
double round_off(double, int);
void print_data(int,int,double,string);
// Declare a global constant variable called PI above main() that holds value 3.141592
const double PI=3.141592;
int main()
{
// Declare a variable named name that holds text
	string name;
// Declares variables named height and radius that hold whole numbers
	int height, radius;
// Declare a variable named volume that holds double precision real numbers
	double volume;
// Prompts the user "May I get your first name please?: "
	cout <<"May I get your first name please?: ";
// Read the value from the keyboard and stores it in name
	cin >> name;
// Prompt the user "Thanks ", name, ", now enter radius and height of the cone please: "
	cout <<"\nThanks " << name<< ", now enter radius and height of the cone please: ";
// Read the values from the keyboard and stores them in radius and height respectively
	cin >> radius >> height;
// Call function volume_cone() to calculate the volume of the cone and assign the result to volume 
	//volume = volume_cone(radius, height);
// Call function print_data() to print the values entered by the user and the volume of the cone
	print_data(radius, height, volume_cone(radius, height), name);





// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(PI) == typeid(1.));							// Incorrect data type used for PI
	test(PI == 3.141592);									// Incorrect value used for PI
	test(typeid(name) == typeid(string));					// Incorrect data type used for name
	test(typeid(height) == typeid(1));						// Incorrect data type used for height
	test(typeid(radius) == typeid(1));						// Incorrect data type used for radius
	test(typeid(volume) == typeid(1.));						// Incorrect data type used for volume
	test(fabs(volume_cone(3,5) - 47.124) < 0.0001);			// Incorrect rounding of volume
	test(fabs(volume_cone(3, 4) - 37.699) < 0.0001);		// Incorrect rounding of volume

	return 0;
}


//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement
// Calculates the square of the value received
double square(double x){
	return x*x;
}
// Calculates the volume of the cone using the formula 1 / 3 x Pi x radius^2 x height
double volume_cone(int rad, int hei){
	return round_off(((1.0/3.0)*PI*square(rad)*hei),3);
}
// Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off(double x, int n){
	return round(x*pow(10,n))/pow(10,n);
}
// Prints the volume of the cone
void print_data(int R, int H, double vol, string nan){
	cout<< "\nOk "<< nan<<endl<<
	"\nFor a radius: "<< R<<" and a height: "<< H<< " the cone's volume is "<< vol<<endl<<endl;
}