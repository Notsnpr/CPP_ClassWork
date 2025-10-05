#include <cassert>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int fastFind(vector<double>&, double);

int main() {
    vector<double> data = {1.0, 2.5, 3.3, 4.8, 5.5, 6.7, 7.9};
    double targets[] = {1.0, 2.5, 3.3, 4.8, 5.5, 6.7, 7.9, 0.5, 8.0, 4.0, 6.7, 2.4};
    for (double t : targets) {
        int result = fastFind(data, t);
        if (result != -1)
            cout << "Found " << t << " at index " << result << endl;
        else
            cout << t << " not found" << endl;
    }
    return 0;
}


int fastFind(vector<double> &A, double key){
    if((A.empty()) || (A.size()==1 && A[0]!=key)){ // This is the base case assuming that there exists no such value in a 1 value list
        return -1;
    };
    int midd= A.size()/2;
    if(A[midd]==key){
        return midd; //this means that we found the value in binary search
    }else if(A[midd]<key){// this means that the value is somewhere to the right
        vector<double> right(A.begin()+midd+1,A.end());
        int res =fastFind(right,key);
        if(res!=-1){
            res +=midd+1;
        };
        return res;
    }else if(A[midd]>key){ // this means that the value is somewhere to the left
        vector<double> left(A.begin(),A.begin()+midd);
        int res =fastFind(left,key);   
        return res;
    }
    return -1;
}
