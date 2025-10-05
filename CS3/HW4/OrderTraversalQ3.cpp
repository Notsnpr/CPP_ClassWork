
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

void levelOrderTraversal(node * r)
{
    if (r == NULL) return;

    queue<node*> q;
    q.push(r);

    while (!q.empty())
    {
        node * current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    // Create a sample binary tree
    node* root = new node{1, nullptr, nullptr};
    root->left = new node{2, nullptr, nullptr};
    root->right = new node{3, nullptr, nullptr};
    root->left->left = new node{4, nullptr, nullptr};
    root->left->right = new node{5, nullptr, nullptr};
    root->right->left = new node{6, nullptr, nullptr};
    root->right->right = new node{7, nullptr, nullptr};

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}