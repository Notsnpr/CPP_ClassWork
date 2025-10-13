#include "autocompleter.h"
#include <algorithm> // for max()

Autocompleter::Autocompleter() {
    root = nullptr;
}

void Autocompleter::insert(string s, int freq) {
    Entry e;
    e.s = s;
    e.freq = freq;
    insert_recurse(e, root);
}
int Autocompleter::size() {
    return size_recurse(root);
}
void Autocompleter::completions(string x, vector<string>& C) {
    C.clear();
    vector<Entry> entries;
    completions_recurse(x, root, entries);

    // Sort by frequency descending
    sort(entries.begin(), entries.end(),
         [](const Entry& a, const Entry& b) { return a.freq > b.freq; });

    // Only top 3
    for (int i = 0; i < (int)entries.size() && i < 3; ++i)
        C.push_back(entries[i].s);
}

// Returns the size of the binary tree rooted at p
int Autocompleter::size_recurse(Node* p)
{
    if (p == nullptr)
        return 0;
    return 1 + size_recurse(p->left) + size_recurse(p->right);
}

// Fills C with all completions of x in the BST rooted at p
void Autocompleter::completions_recurse(string x, Node* p, vector<Entry>& C)
{
    if (p == nullptr)
        return;

    // If p->e.s starts with x, add it
    if (p->e.s.compare(0, x.size(), x) == 0)
        C.push_back(p->e);

    // Search left subtree if possible
    if (x < p->e.s)
        completions_recurse(x, p->left, C);

    // Search right subtree if possible
    if (x >= p->e.s.substr(0, x.size()) || p->e.s < x)
        completions_recurse(x, p->right, C);
}

// Insert a new entry into the AVL tree rooted at p
void Autocompleter::insert_recurse(Entry e, Node*& p)
{
    if (p == nullptr) {
        p = new Node(e);
        return;
    }

    if (e.s < p->e.s)
        insert_recurse(e, p->left);
    else if (e.s > p->e.s)
        insert_recurse(e, p->right);
    else
        return; // duplicate, do nothing

    update_height(p);
    rebalance(p);
}

// Rotations
void Autocompleter::right_rotate(Node*& p)
{
    Node* L = p->left;
    p->left = L->right;
    L->right = p;
    update_height(p);
    update_height(L);
    p = L;
}

void Autocompleter::left_rotate(Node*& p)
{
    Node* R = p->right;
    p->right = R->left;
    R->left = p;
    update_height(p);
    update_height(R);
    p = R;
}

// Rebalances the AVL tree rooted at p
void Autocompleter::rebalance(Node*& p)
{
    if (!p) return;

    int balance = height(p->left) - height(p->right);

    // Left heavy
    if (balance > 1) {
        if (height(p->left->left) < height(p->left->right))
            left_rotate(p->left);
        right_rotate(p);
    }
    // Right heavy
    else if (balance < -1) {
        if (height(p->right->right) < height(p->right->left))
            right_rotate(p->right);
        left_rotate(p);
    }
}



