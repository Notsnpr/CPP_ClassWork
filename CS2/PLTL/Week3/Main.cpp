#include <iostream> // Used for cin and cout
#include "Burrito.h"


using namespace std; // making life easier so taht we do not need to use std::cin , std::cout, etc.



int main()
{


	Burrito b1("Asada", false);
	cout << "your result is "<< b1.price() << ". It should be 5" << endl;

	b1.add_cheese();
	cout << "your result is " << b1.price() << ". It should be 6" << endl;

	b1.change_meat("Nada");
	cout << "your result is " << b1.price() << ". It should be 3" << endl;

	Burrito b2; // Special syntax for constructor with no parameters
	cout << "your result is " << b2.price() << ". It should be 2" << endl;

	b2.add_cheese();
	cout << "your result is " << b2.price() << ". It should be 3" << endl;

	b2.change_meat("AlPastor");
	cout << "your result is " << b2.price() << ". It should be 5" << endl;

	b2.change_meat("Asada");
	cout << "your result is " << b2.price() << ". It should be 6" << endl;

	b2.remove_cheese();
	cout << "your result is " << b2.price() << ". It should be 5" << endl;


}