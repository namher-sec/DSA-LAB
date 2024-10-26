#pragma once
#include "Node.h"

class List
{
public:
	List();                                        
	bool emptyList();
	void insert_begin(int value);
	void insert_end(int value);
	void insert_after(int prev, int next);
	void deleteNode(int value); 
        void delete_begin(); 
        void delete_end();
        void traverse();
        void traverse_reverse();

private:
	Node* head;
	Node* p_first;
	Node* p_last;
};

