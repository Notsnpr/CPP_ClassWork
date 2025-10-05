#include <cassert>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


using namespace std;

struct node {
    double value;
    node* left;
    node* right;
    node(double v) : value(v), left(nullptr), right(nullptr) {}
};

node* buildTree(vector<double>& A, int start, int end) {
    if (start > end){
        return nullptr;
    } 
    int mid = start + (end - start) / 2;
    node* root = new node(A[mid]);
    root->left  = buildTree(A, start, mid - 1);
    root->right = buildTree(A, mid + 1, end);
    return root;
}

void printInOrder(node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->value << " ";
    printInOrder(root->right);
}

int main() {
    vector<double> data1 = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> data2 = {-5.0, -3.0, -1.0, 0.0, 2.5, 4.8};
    vector<double> data3 = {10.0};

    cout << "Tree 1 (1..5): ";
    node* root1 = buildTree(data1, 0, (int)data1.size() - 1);
    printInOrder(root1);
    cout << endl;

    cout << "Tree 2 (negatives and positives): ";
    node* root2 = buildTree(data2, 0, (int)data2.size() - 1);
    printInOrder(root2);
    cout << endl;

    cout << "Tree 3 (single element): ";
    node* root3 = buildTree(data3, 0, (int)data3.size() - 1);
    printInOrder(root3);
    cout << endl;

    return 0;
}