#include <iostream>
#include "NodeInterface.h"

using namespace std;

class Node : public NodeInterface
 {

public:
	friend class BST;
	int data;
	Node* left;
	Node* right;

	
	Node()
	{
		left = NULL;
		right = NULL;
	}
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~Node() 
	{
		
	}

	int getData() const;

	NodeInterface * getLeftChild() const;

	NodeInterface * getRightChild() const;

	Node *&getRight();
	Node *&getLeft();

};