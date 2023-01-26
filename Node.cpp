#include <iostream>
#include "Node.h"

int Node::getData() const
{
	return this->data;
}

NodeInterface * Node::getLeftChild() const
{
	return left;
}

NodeInterface * Node::getRightChild() const
{
	return right;
}


Node *& Node::getRight()
{
	return right;
}
Node *& Node::getLeft()
{
	return left;
}