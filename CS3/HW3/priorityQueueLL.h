#pragma once
#include <stdexcept>

template <class T>
class priorityQueueLL
{
private:
	class node {
	public:
		T data;
		node* next;
		node(const T& d, node* n = nullptr) : data(d), next(n) {}
	};

	node* head;

public:

	priorityQueueLL()
		: head(nullptr)
	{}

	~priorityQueueLL()
	{
		while (head != nullptr) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	//return true if empty, false if not
	bool empty()
	{
		return head == nullptr;
	}

	//add item
	void insert(T x)
	{
		node* newNode = new node(x);
		if (head == nullptr || x <= head->data) {
			newNode->next = head;
			head = newNode;
			return;
		}
		node* current = head;
		while (current->next != nullptr && current->next->data < x) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	//remove and return smallest item
	T extractMin()
	{
		if (head == nullptr) {
			throw std::runtime_error("PriorityQueue is empty");
		}
		T ret = head->data;
		node* temp = head;
		head = head->next;
		delete temp;
		return ret;
	}

};