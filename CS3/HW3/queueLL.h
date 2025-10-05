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

    node* head;
    node* tail;
    std::size_t n;

public:
    queueLL(): head(nullptr), tail(nullptr), n(0) {}

    ~queueLL() {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        n = 0;
    }

    bool empty() const { return head == nullptr; }
    std::size_t size() const { return n; }

    void enqueue(const T& x) {
        node* newNode = new node(x);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++n;
    }

    T dequeue() {
        if (empty()) throw std::runtime_error("Queue is empty");
        node* temp = head;
        T ret = temp->data;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        --n;
        return ret;
    }

    // Remove every other element starting with the second.
    // After decimate, elements at original indices 0,2,4,... remain.
    void decimate() {
        if (!head) return;
        node* cur = head;
        while (cur && cur->next) {
            node* victim = cur->next;
            cur->next = victim->next;
            if (victim == tail) tail = cur;
            delete victim;
            --n;
            cur = cur->next; // advance to next survivor
        }
    }
};