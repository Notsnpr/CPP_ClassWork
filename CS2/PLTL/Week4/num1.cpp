#include <iostream> // Used for cin and cout
#include <string>

using namespace std;

int main(){
    string word = "Bleargh";  
    string *wp;

    wp= &word;
    *wp="AckAckAck";

    cout <<*wp;

}