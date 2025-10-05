#include <iostream> // Used for cin and cout
#include <string>

using namespace std;

void swap(int &a, int &b);

int main(){
    int x,y;
    x=7;
    y=15;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    return 0;
}

void swap(int &a, int &b){
    int *iptr1, *iptr2;
    iptr1 =&a;
    iptr2 =&b;
    int temp = *iptr1;
    *iptr1 = *iptr2;
    *iptr2 = temp;
    

}