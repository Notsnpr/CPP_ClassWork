#include <iostream>
#include <string>
#include "AVLTree.h"
using namespace std;

int main()
{
	binarySearchTree T;

	T.insert(115);
	T.insert(255);
	T.insert(24);
	T.insert(12);
	T.insert(362);
	T.insert(62);
	T.insert(100);
	T.insert(2);
	T.insert(10);
	T.insert(92);
	T.insert(360);

	//print out items in tree
	T.display();
	cout << "Num items: " << T.numItems() << endl;


	return 0;
}