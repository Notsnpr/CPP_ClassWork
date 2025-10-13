#pragma once
#include <iostream>
using namespace std;

class binarySearchTree
{
private:
	class node
	{
	public:
		double data;
		node* left;
		node* right;
        int height;

		node(double x)
		{
			data = x;
			left = nullptr;
			right = nullptr;
			height=0;
		}
	};

	node* root;

	void leftRotation(node*&p){
		node* A=p;
		node* B= p->right;
		node* bl = B->left;
		p=B;
		A->right=bl;
		B->left=A;
		updateHeight(A);
		updateHeight(B);

	}
	void rightRotation(node*&p){
		node* A=p;
		node* B= p->left;
		node* br = B->right;
		p=B;
		A->left=br;
		B->right=A;
		updateHeight(A);
		updateHeight(B);
		
	}
	void leftRightRotation(node*& p){
		leftRotation(p->left);
		rightRotation(p);
	}
	void rightLeftRotation(node*& p){
		rightRotation(p->right);
		leftRotation(p);
	}

	void fixBalance(node* &p){
		if (height(p->left)>height(p->right)+1){
			if(height(p->left->left)>height(p->left->right)+1){
				rightRotation(p);
			}else{
				leftRightRotation(p);
			}
		}else if (height(p->right)>height(p->left)+1){
			if(height(p->right->right)>height(p->right->left)+1){
				leftRotation(p);
			}else{
				rightLeftRotation(p);
			}
		}
	}

	//insert x into tree rooted at node p.
	void recInsert(double x, node* &p)
	{
		if (p==nullptr) //base case
		{
			p = new node(x);
		}
		else //big problem, use recursion
		{
			if (x < p->data)
			{
				recInsert(x, p->left);
                fixheight(p);
			}
			else
			{
				recInsert(x, p->right);
                fixheight(p);
			}
			//The Heigth of p might be out of date
			updateHeight(p);
		}
	}

	//print all items in tree rooted at node p
	void inOrder(node* p)
	{
		if(p==nullptr) //base case
		{ 
			//don't do anything!  no items to print!
			//saving tons of coding time because we don't
			//do anything in this case!!!!!
		}
		else //recursive case
		{
			inOrder(p->left);
			cout << p->data << endl;
			inOrder(p->right);
		}
	}

	void updateHeight(node* p){
		int lheight = height(p->left);
		int rheight = height(p->right);
		p->height= 1+ max(lheight,rheight);
	}

	int height(node*p){
		if (p==nullptr) return -1;
		return p->height;
	}
	//return number of items/nodes in tree rooted at p.
	int numItems(node* p)
	{
		if (p==nullptr) //base case
		{
			return 0;
		}
		else //recursive
		{
			int numLeft = numItems(p->left);
			int numRight = numItems(p->right);
			return 1 + numLeft + numRight;
		}
	}

	//return number of leaves in the tree rooted at p
	int numLeaves(node* p)
	{
		if (p == nullptr) //base case
			return 0;
		else //recursive case
		{
			if (p->left == nullptr && p->right == nullptr)
				return 1;
			else
			{
				int numLeft = numLeaves(p->left);
				int numRight = numLeaves(p->right);
				return numLeft + numRight;
			}
		}
	}

	//return height of tree rooted at node p.
	int height(node* p)
	{
        if(p==nullptr){
            return -1;
        }else{
            return p->height;
        }
	}
    void fixheight(node *p){
        p->height=max(height(p->left),height(p->right))+1;
    }

public:
	binarySearchTree()
	{
		root = nullptr;
	}

	void insert(double x)
	{
		recInsert(x, root);
	}

	void display()
	{
		inOrder(root);
	}

	int numItems()
	{
		return numItems(root);
	}

	int numLeaves()
	{
		return numLeaves(root);
	}

	int height()
	{
		return height(root);
	}
};