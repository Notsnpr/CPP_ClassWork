#pragma once
#include <stdexcept>
class stackLL
{
private:
	class node
	{
	public:
		int data;
		node* next;
		node(int d, node* n=nullptr): data(d), next(n) {}
	};

	node * top;

public:

	stackLL()
	{
		top = nullptr;
	}

	//Take care of memory leaks...
	~stackLL()
	{
		while(top != nullptr)
		{
			node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	//return true if empty, false if not
	bool empty()
	{
		return top == nullptr;
	}

	//add item to top of stack
	void push(int x)
	{
		top = new node(x, top);
	}

	//remove and return top item from stack
	int pop()
	{
		if(top == nullptr)
			throw std::runtime_error("Stack is empty");
		int val = top->data;
		node* temp = top;
		top = top->next;
		delete temp;
		return val;
	}

	//add item x to stack, but insert it
	//right after the current ith item from the top
	//(and before the i+1 item).
	void insertAt(int x, int i)
	{
		if(i <= 0 || top == nullptr)
		{
			push(x);
			return;
		}

		node* current = top;
		for(int count = 1; count < i && current->next != nullptr; ++count)
		{
			current = current->next;
		}

		current->next = new node(x, current->next);
	}

};
#pragma once
#include <stdexcept>
class stackLL
{
private:
    class node
    {
    public:
        int data;
        node* next;
        node(int d, node* n=nullptr): data(d), next(n) {}
    };

    node * top;

public:

    stackLL()
    {
        top = nullptr;
    }

    //Take care of memory leaks...
    ~stackLL()
    {
        while(top != nullptr)
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    //return true if empty, false if not
    bool empty()
    {
        return top == nullptr;
    }

    //add item to top of stack
    void push(int x)
    {
        top = new node(x, top);
    }

    //remove and return top item from stack
    int pop()
    {
        if(top == nullptr)
            throw std::runtime_error("Stack is empty");
        int val = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    //add item x to stack, but insert it
    //right after the current ith item from the top
    //(and before the i+1 item).
    void insertAt(int x, int i)
    {
        if(i <= 0 || top == nullptr)
        {
            push(x);
            return;
        }

        node* current = top;
        for(int count = 1; count < i && current->next != nullptr; ++count)
        {
            current = current->next;
        }

        current->next = new node(x, current->next);
    }

};