#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ----------------------- Question 1 -------------------------------- //
//Given a sorted array of n comparable items A, and a search value key, 
//return the position (array index) of key in A if it is present,
//or -1 if it is not present. If key is present in A, 
//your algorithm must run in order O(log k) time,
//where k is the location of key in A. Otherwise, if key is not present, 
//your algorithm must run in O(log n) time. 

//lets use binary search as a helper method

int binarySearch(vector<double> &A, double key, int start, int end) {
    while (start <= end) {
        int mid = (start+end)/2; //find mid
        if (key == A[mid]) return mid; //if the mid point IS key

        if (key < A[mid]) end = mid-1; // cut out the right half of vector 
        if (key > A[mid]) start = mid+1; // cut out the left half of the vector
    }
    return -1; //the number was never found
}

// 0(log k)?

int fastFind(vector<double> &A, double key) {
    if (A.empty()) return -1; //if the list is empty the item is not found

    //check the first element
    if (A[0] == key) return 0; //the first item IS the key

    //now that we have eliminated the two best cases
    //we need to search for the key by exponetially increasing the bound until we find key
    int numItems = A.size();
    int bound = 1;

    while (bound < numItems && A[bound] < key) {
        bound *= 2; //increase bound (by doubling) to expand search range
    }

    // now we can incorporate binary search in the range we found
    int start = bound/2;
    int end = min(bound, numItems-1);

    return binarySearch(A, key, start, end);
}

// -------------------------------- Question 2 --------------------------------- //
//Given a sorted array of n comparable items A, create a binary search tree from 
// the items in A which has height h <= log2 n. 
// Your algorithm must create the tree in O(n) time.

 // Step 1. let me make a node class 
    class node1 {
        public: 
            double data;
            node1* left;
            node1* right;
            //constructor for node
            node1(double val) : data(val), left(nullptr), right(nullptr){}
    };
// I want to use recursive
node1* buildTree(vector<double> &A, int start, int end) {
      // if list is empty (base case)
    if (start > end) return nullptr;

    //start with middle
    int mid = (start+end)/2;
    node1* root = new node1(A[mid]); //making the root = mid (values less than root go left, and greater go right)

    //now we can use recursion
    root->left = buildTree(A, start, mid-1);  //left side (we get rid of anything after middle)
    root->right = buildTree(A, mid+1, end); // right side (We get rid of anything before middle)

    return root;// returns the pointer to the root node of tree.
}

//im going to include ths helper function to test
void printInOrder(node1* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// -------------------------------- Question 3 --------------------------------- //
// Traversing the tree level by level: For the following question, assume binary trees consist of nodes from the
//following class:
class node2 {
    public:
    int data;
    node2 * left;
    node2 * right;

    node2(int val) : data(val), left(nullptr), right(nullptr){}
};
//Write a method ‘void levelOrderTraversal(node * r)’ which prints the items of a binary tree rooted at node r in a
// “level order”. That is, the first item printed is the value contained in the root node r, the next items printed are the
// children of the root, the next items printed are the grandchildren of the root, etc. Your algorithm must run in O(n)
// time. Hint: You may use the STL queue in your solution
void levelOrderTraversal(node2* r) {
    if (r == nullptr) return; //the list is empty (base)

    queue<node2*> q;
    q.push(r);

    while(!q.empty()) {
        node2* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left != nullptr) q.push(current->left);
        if(current->right != nullptr) q.push(current->right);
    }

}


int main()
{
    vector<double> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    cout << "Question 1 tests: " << endl;
    cout << fastFind(arr, 1) << endl;   // 0
    cout << fastFind(arr, 9) << endl;   // 4
    cout << fastFind(arr, 17) << endl;  // 8
    cout << fastFind(arr, 6) << endl;   // -1
    cout << "-------------------" << endl;

    vector<double> A = {1, 2, 3, 4, 5, 6, 7};
    cout << "Question 2 tests" << endl;
    node1* root = buildTree(A, 0, A.size() - 1);
    cout << "Inorder traversal of tree: ";
    printInOrder(root); // should print 1 2 3 4 5 6 7
    cout << endl;
    cout << "------------------" << endl;

    cout << "Question 3 tests" << endl;
    node2* r = new node2(1);
    r->left = new node2(2);
    r->right = new node2(3);
    r->left->left = new node2(4);
    r->left->right = new node2(5);
    r->right->left = new node2(6);
    r->right->right = new node2(7);

    cout << "Level order traversal: ";
    levelOrderTraversal(r);  // should print: 1 2 3 4 5 6 7
    cout << endl;
    cout << "------------------" << endl;



    return 0;
}