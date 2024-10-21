#pragma once
#include <iostream>

class Node
{
public:

	Node();
	void set_data(int);
	int get_data() const;
	void set_prev(Node*);
	Node* get_prev() const;
	void set_next(Node*);
	Node* get_next() const;

private:
	Node* prev;
	int data;
	Node* next;
};

