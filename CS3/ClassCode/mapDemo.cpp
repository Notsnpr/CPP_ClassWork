#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    //needs key val pair
    // key type must be hashable
    //value type can be anything
    unordered_map<string,double> M;

    //inset an item into the hash table M
    pair<string, double> joe;
    joe.first = "Joe";
    joe.second = 1.3;
    pair<string,double> carlos;
    carlos.first ="Carlos";
    carlos.second = 3.7;
    M.insert(joe);
    M.insert(carlos);

    // Can also use bracket to insert
    M["Gabriel"]=3.9;
    //lets search for an item
    cout<< M["Carlos"]<<endl;
    cout<< M["Joe"]<<endl;
    cout<< M["Gabriel"]<<endl;
    return 0;
}