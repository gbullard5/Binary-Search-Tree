#include <iostream>
#include "BST.h"

using namespace std;

NodeInterface * BST::getRootNode() const
{
	return this->root;
}

bool BST::add(int data)
{
	return add(data, this->root);
}

bool BST::add(int data, Node *&node)
{
	if(node == NULL)
	{
		node = new Node(data);
		return true;
	}
	else if(node->getData() == data)
	{
		return false;
	}
	else if(data < node->getData())
	{
		return add(data, node->getLeft());
	}
	else
	{
		return add(data, node->getRight());
	}
}


bool BST::remove(int data)
{
	return remove(this->root, data);
}

bool BST::remove(Node*& local_root, int data)
{
	if(local_root == NULL)
	{
		return false;
	}
	else
	{
		if(data < local_root->data)
		{
			return remove(local_root->left, data);
		}
		else if(data > local_root->data)
		{
			return remove(local_root->right, data);
		}
		else 
		{
			Node* old_root = local_root;
			if(local_root->right == NULL)
			{
				local_root = local_root->left;
				delete old_root;
			
			}
			else if(local_root->left == NULL)
			{
				local_root = local_root->right;
				delete old_root;
		
			}
			else 
			{
				replace(old_root, local_root->left);
				
			}
			return true;
			
		}
	}
}

void BST::replace(Node*& old_root, Node*& local_root)
{
	if(local_root->right != NULL)
	{
		replace(old_root, local_root->right);
	}
	else
	{
		old_root->data = local_root->data;
		remove(old_root->left, local_root->data);
	}
}

void BST::clear()
{
	recursiveClear(this->root);
	this->root = NULL;
}

void BST::recursiveClear(Node *node)
{
	if(node != NULL)
	{
		recursiveClear(node->getLeft());
		recursiveClear(node->getRight());
		delete node;
	}
}