
#include <string>
#include <iostream>

#include <stack>

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
	//abort();
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main() 
{
	unsigned int max;
	stack<string> s, sc1, sc2;		// BOTTOM[}TOP
	test(s.size() == 0);

	s.push("hello");				// ["hello"}
	test(s.top() == "hello");
	test(s.size() == 1);

	s.push("dog");					// ["hello", "dog"}
	test(s.size() == 2);
	test(s.top() == "dog");

	s.push("phone");				// ["hello", "dog", "phone"}
	test(s.size() == 3);
	test(s.top() == "phone");

	sc2 = s;						// copy s to sc2

	cout << "Content of stack s" << endl << endl;
	max = s.size();
	for (unsigned int x = 0; x < max; ++x)			// pass the content of s to sc1
	{
		cout << x <<':' << s.top() << endl;			// display what is at the top of the stack
		sc1.push(s.top());							// pass the item at the top of s to sc1
		s.pop();									// remove the item at the top of s
	}
	cout << endl << "Content of stack sc1" << endl << endl;

	max = sc1.size();
	for (unsigned int x = 0; x < max; ++x)			// display the content of sc1
	{
		cout << x << ':' << sc1.top() << endl;		// display what is at the top of the stack sc1
		sc1.pop();									// remove the item at the top of sc1
	}
	cout << endl;

	s = sc2;										// copy sc2 to s
	s.pop();										// ["hello", "dog"}
	test(s.size() == 2);
	test(s.top() == "dog");
	
	s.push("cat");									// ["hello", "dog", "cat"}
	test(s.size() == 3);
	test(s.top() == "cat");

	s.pop();										// ["hello", "dog"}
	test(s.size() == 2);
	test(s.top() == "dog");

	s.pop();										// ["hello"}
	test(s.size() == 1);
	test(s.top() == "hello");

	s.pop();										// [}
	test(s.size() == 0);

	
	cout << endl << "Tests passed." << endl << endl;

}
