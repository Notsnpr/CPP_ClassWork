#pragma once
#include <stdexcept>
#include <cstddef>

// Singly-linked stack of ints.
// push: O(1), pop: O(1), top: O(1)
class stackLL {
private:
    struct node {
        int data;
        node* next;
        node(int d, node* n=nullptr): data(d), next(n) {}
    };
    node* top_;
    std::size_t n_;

public:
    stackLL() : top_(nullptr), n_(0) {}
    ~stackLL() {
        while (top_) { node* t = top_; top_ = top_->next; delete t; }
    }

    bool empty() const { return top_ == nullptr; }
    std::size_t size() const { return n_; }

    void push(int x) {
        top_ = new node(x, top_);
        ++n_;
    }

    int pop() {
        if (empty()) throw std::runtime_error("Stack is empty");
        int v = top_->data;
        node* t = top_;
        top_ = top_->next;
        delete t;
        --n_;
        return v;
    }

    // insert x after the i-th item from the top (0-based). If i<=0, push at top.
    void insertAt(int x, int i) {
        if (i <= 0 || empty()) { push(x); return; }
        node* cur = top_;
        for (int k = 1; k < i && cur->next; ++k) cur = cur->next;
        cur->next = new node(x, cur->next);
        ++n_;
    }

    // Access to top value
    int& top() {
        if (empty()) throw std::runtime_error("Stack is empty");
        return top_->data;
    }
    const int& top() const {
        if (empty()) throw std::runtime_error("Stack is empty");
        return top_->data;
    }
};
#pragma once
#include <stdexcept>
#include <cstddef>

// Templated singly-linked queue with decimate().
// enqueue: O(1), dequeue: O(1), decimate: O(n)
template <typename T>
class queueLL {
private:
    struct node {
        T data;
        node* next;
        node(const T& d, node* n=nullptr): data(d), next(n) {}
    };
    node* head_;
    node* tail_;
    std::size_t n_;

public:
    queueLL() : head_(nullptr), tail_(nullptr), n_(0) {}
    ~queueLL() {
        while (head_) { node* t = head_; head_ = head_->next; delete t; }
        tail_ = nullptr; n_ = 0;
    }

    bool empty() const { return head_ == nullptr; }
    std::size_t size() const { return n_; }

    void enqueue(const T& x) {
        node* nd = new node(x);
        if (!tail_) head_ = tail_ = nd;
        else { tail_->next = nd; tail_ = nd; }
        ++n_;
    }

    T dequeue() {
        if (empty()) throw std::runtime_error("Queue is empty");
        node* t = head_;
        T v = t->data;
        head_ = head_->next;
        if (!head_) tail_ = nullptr;
        delete t;
        --n_;
        return v;
    }

    // Remove every other element starting with the second.
    void decimate() {
        if (!head_) return;
        node* cur = head_;
        while (cur && cur->next) {
            node* victim = cur->next;
            cur->next = victim->next;
            if (victim == tail_) tail_ = cur;
            delete victim;
            --n_;
            cur = cur->next;
        }
    }
};
// Standard library includes replacing <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <chrono>
#include <utility>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(const string& s): data(s), next(nullptr) {}
};

static vector<string> readWordsFromFile(const string& path) {
    ifstream in(path);
    vector<string> out;
    if (!in) { cerr << "Cannot open " << path << "\n"; return out; }
    char c;
    while (in.get(c)) {
        if (isalnum(static_cast<unsigned char>(c))) {
            string w(1, static_cast<char>(tolower(c)));
            while (in.get(c) && isalnum(static_cast<unsigned char>(c))) {
                w.push_back(static_cast<char>(tolower(c)));
            }
            out.push_back(move(w));
            if (in) in.unget();
        }
    }
    return out;
}

static Node* buildList(const vector<string>& v) {
    Node* head = nullptr; Node* tail = nullptr;
    for (const auto& s : v) {
        Node* nd = new Node(s);
        if (!head) head = tail = nd;
        else { tail->next = nd; tail = nd; }
    }
    return head;
}

static void freeList(Node*& h) {
    while (h) { Node* t = h; h = h->next; delete t; }
}

static void split(Node* source, Node*& front, Node*& back) {
    if (!source || !source->next) { front = source; back = nullptr; return; }
    Node* slow = source; Node* fast = source->next;
    while (fast) {
        fast = fast->next;
        if (fast) { slow = slow->next; fast = fast->next; }
    }
    front = source;
    back = slow->next;
    slow->next = nullptr;
}

static Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

static void mergeSort(Node*& head) {
    if (!head || !head->next) return;
    Node* a; Node* b;
    split(head, a, b);
    mergeSort(a);
    mergeSort(b);
    head = merge(a, b);
}

static void slowSort(Node*& head) {
    for (Node* i = head; i; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j; j = j->next)
            if (j->data < minNode->data) minNode = j;
        if (minNode != i) swap(minNode->data, i->data);
    }
}

static void writeList(Node* h, const string& path) {
    ofstream out(path);
    for (; h; h = h->next) out << h->data << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string inPath = "whale.txt";
    vector<string> items = readWordsFromFile(inPath);

    Node* A = buildList(items);
    Node* B = buildList(items);

    auto t1 = chrono::high_resolution_clock::now();
    slowSort(A);
    auto t2 = chrono::high_resolution_clock::now();
    auto slow_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    writeList(A, "slowSortedWhale.txt");

    auto t3 = chrono::high_resolution_clock::now();
    mergeSort(B);
    auto t4 = chrono::high_resolution_clock::now();
    auto merge_ms = chrono::duration_cast<chrono::milliseconds>(t4 - t3).count();
    writeList(B, "mergeSortedWhale.txt");

    cout << "Items sorted: " << items.size() << "\n";
    cout << "slowSort (selection) time: " << slow_ms  << " ms\n";
    cout << "mergeSort time:           " << merge_ms << " ms\n";

    freeList(A); freeList(B);
    return 0;
}