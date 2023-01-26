#include <iostream>
#include "BSTInterface.h"
#include "Node.h"



class BST {
public:

	BST() 
	{
		root = NULL;
	}
	
	BST(int data)
	{
		root = new Node(data);
	}

	~BST() 
	{
		clear();
	}

	NodeInterface * getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();

	bool remove(Node*& local_root, int data);
	
	void replace(Node*& old_root, Node*& local_root);

	private:
		bool add(int data, Node *&node);
		void recursiveClear(Node *node);
		Node * root;
	
};