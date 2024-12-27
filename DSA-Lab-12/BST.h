#pragma once
#include "Node.h"
using namespace std;

class BST
{
public:
	Node* root;
	BST();

	// Core BST functionality
	void insert(Node*, int);             // Insert using current node
	void insert(int);                    // Wrapper for insert
	bool search(Node*, int);             // Search using current node
	bool search(int);                    // Wrapper for search
	void delete_node(Node*&, int);       // Delete using current node
	void delete_node(int);               // Wrapper for delete
	bool isEmpty();                      // Check if tree is empty

	// Traversals
	void in_orderTraverse(Node*);        // In-order traversal using current node
	void in_orderTraverse();             // Wrapper for in-order traversal

	// Utility functions
	Node* findmin(Node*);                // Find the minimum node
	Node* getParent(Node*, int);         // Find the parent of a node
};
