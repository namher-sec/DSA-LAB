#include "Node.h"
#include <iostream>

Node::Node()
{
	data = 0;
	prev = NULL;
	next = NULL;
}

void Node::set_data(int num)
{
	data = num;
}

int Node::get_data() const
{
	return data;
}

void Node::set_prev(Node* temp)
{
	prev = temp;
}

Node* Node::get_prev() const
{
	return prev;
}

void Node::set_next(Node* temp)
{
	next = temp;
}

Node* Node::get_next() const
{
	return next;
}

