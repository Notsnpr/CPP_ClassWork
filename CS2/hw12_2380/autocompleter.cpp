//***********************************************************************
// Team #13                            CSCI 2380                          Spring 2025                      Homework # 12
// Victor Munoz
// Luis Elizondo
// Angel Morales
//  
//*********************************************************************** 

#include "autocompleter.h"


Autocompleter::Autocompleter() {
    root = nullptr;
}

// Helper method for size()
int Autocompleter::size_recurse(Node* root){
    if(root==nullptr){
        return 0;
    }
    return 1+ (size_recurse(root->left))+(size_recurse(root->right));
}
int Autocompleter::completion_count_recurse(string x, Node* root){
    if(root==nullptr){
        return 0;
    }
    if(root->s.rfind(x,0)==0){//starts with val
        return 1 + completion_count_recurse(x,root->left)+completion_count_recurse(x,root->right);
    }else{// doesnt start with val
        return 0 + completion_count_recurse(x,root->left)+completion_count_recurse(x,root->right);
    }
}
void Autocompleter::completions_recurse(string x, string* suggestions, Node* root){
    if (root == nullptr) {
        return;
    }
    // If suggestions array is already filled, stop recursion
    if (suggestions[4] != "") {
        return;
    }
    // Traverse left subtree
    completions_recurse(x, suggestions, root->left);
    // Check current node; if starts with x, add to first empty slot
    if (root->s.rfind(x, 0) == 0) {
        for (int i = 0; i < 5; ++i) {
            if (suggestions[i] == "") {
                suggestions[i] = root->s;
                break;
            }
        }
    }
    // Traverse right subtree
    completions_recurse(x, suggestions, root->right);
}
void Autocompleter::insert(string x){ // a.k.a. add()
    if (root == nullptr) {
        root = new Node(x);
        return;
    }
    Node* cur = root;
    while (true) {
        if (x == cur->s) {
            return; // Duplicate found, do not insert again.
        } else if (x < cur->s) {
            if (cur->left == nullptr) {
                cur->left = new Node(x);
                return;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == nullptr) {
                cur->right = new Node(x);
                return;
            } else {
                cur = cur->right;
            }
        }
    }
} 
int Autocompleter::size(){
    // we use post order to get the size
    return size_recurse(root);
}
int Autocompleter::completion_count(string x){
    if (x == "") {
        return size();
    }
    return completion_count_recurse(x, root);
}
void Autocompleter::completions(string x, string* suggestions){
    // Initialize all suggestions as empty strings
    for (int i = 0; i < 5; ++i) {
        suggestions[i] = "";
    }
    completions_recurse(x, suggestions, root);
}