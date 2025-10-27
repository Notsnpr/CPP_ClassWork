#include <iostream>
#include <vector>
using namespace std;
class minHeap {
    // class definition goes here
    private:
        vector<double> heap;
        //returns parents location
        int parent(int i){
            return (i-1)/2;
        }
        //bubble up till no more voilations
        void bubbleUp(int index){
            int i = index;
            while(heap[i]<heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }
    public:
        minHeap(){

        };

        void insert(double x){
            heap.push_back(x);
            bubbleUp(heap.size()-1);
        };

        void testDisplay(){
            for(int i =0; i<heap.size();i++){
                cout<< heap[i]<<endl;
            }
        };

};