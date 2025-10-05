#include <iostream> // Used for cin and cout
#include <string>

using namespace std;

int main() 
{   
  int a = 67; //assigns a int to a value
  int* b = &a; //assigns a pointer the address of a int
  cout << a << endl; //67
  cout << &a << endl; //0x7fffdbeac584
  cout << b << endl; //0x7fffdbeac584
  cout << &b << endl; //0x7fffdbeac578
  cout << *b << endl; //67
  cout << *&a << endl; //67
  cout << *&b << endl; //0x7fffdbeac584
  //cout << &*a << endl; // This is wrong because 'a' is an integer, not a pointer 
  //The dereference operator (*) cannot be applied to an integer.
  cout << &*b << endl; //0x7fffdbeac584
  *b = 36; 
  cout << a << endl; //36
  cout << &a << endl; //0x7fffdbeac584
  cout << b << endl; //0x7fffdbeac584
  cout << &b << endl; //0x7fffdbeac578
  cout << *b << endl; //36
  cout << *&a << endl; //36
  cout << *&b << endl; //0x7fffdbeac584
// cout << &*a << endl; // This is wrong because 'a' is an integer, not a pointer 
//The dereference operator (*) cannot be applied to an integer.
  cout << &*b << endl; //0x7fffdbeac584
} 