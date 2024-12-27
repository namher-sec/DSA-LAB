#include "BST.h"
#include <iostream>
using namespace std;

BST::BST()
{
	root = nullptr;
}

void BST::insert(Node* current, int value)
{
	// If the tree is empty, the root node is nullptr
	if (current == nullptr) {
		current = new Node();  // Create a new node
		current->data = value; // Assign the data value to the new node
		current->left = nullptr;
		current->right = nullptr;

		if (root == nullptr) {  // If the tree is empty, this new node becomes the root
			root = current;
		}
		return;
	}

	// Otherwise, insert into the left or right subtree recursively
	if (value < current->data) {
		// Value is smaller, go left
		if (current->left == nullptr) {
			current->left = new Node();  // Create new node as left child
			current->left->data = value;
			current->left->left = nullptr;
			current->left->right = nullptr;
		}
		else {
			insert(current->left, value);  // Recur on the left subtree
		}
	}
	else if (value > current->data) {
		// Value is greater, go right
		if (current->right == nullptr) {
			current->right = new Node();  // Create new node as right child
			current->right->data = value;
			current->right->left = nullptr;
			current->right->right = nullptr;
		}
		else {
			insert(current->right, value);  // Recur on the right subtree
		}
	}
}

bool BST::search(Node* current, int value)
{
	if (current == nullptr) {
		return false; // Node not found
	}
	if (current->data == value) {
		return true; // Node found
	}
	if (value < current->data) {
		return search(current->left, value); // Recur on the left subtree
	}
	else {
		return search(current->right, value); // Recur on the right subtree
	}
}

void BST::delete_node(Node* &current, int value)
{
	if (current == nullptr) {
		return; // Node not found
	}
	if (value < current->data) {
		delete_node(current->left, value); // Recur on the left subtree
	}
	else if (value > current->data) {
		delete_node(current->right, value); // Recur on the right subtree
	}
	else {
		// Node found
		if (current->left == nullptr && current->right == nullptr) {
			// Case 1: No children
			delete current;
			current = nullptr;
		}
		else if (current->left == nullptr) {
			// Case 2: One child (right)
			Node* temp = current;
			current = current->right;
			delete temp;
		}
		else if (current->right == nullptr) {
			// Case 2: One child (left)
			Node* temp = current;
			current = current->left;
			delete temp;
		}
		else {
			// Case 3: Two children
			Node* minNode = findmin(current->right);
			current->data = minNode->data;
			delete_node(current->right, minNode->data);
		}
	}
}

bool BST::isEmpty()
{
	return root == nullptr;
}

void BST::in_orderTraverse(Node* current)
{
	if (current != nullptr) {
		in_orderTraverse(current->left);   // Traverse left subtree
		cout << current->data << " "; // Print current node's data
		in_orderTraverse(current->right);  // Traverse right subtree
	}
}

Node* BST::findmin(Node* current)
{
	while (current && current->left != nullptr) {
		current = current->left;
	}
	return current;
}

Node* BST::getParent(Node* current, int value)
{
	if (current == nullptr || current->data == value) {
		return nullptr; // Root node or tree is empty
	}

	if ((current->left && current->left->data == value) || (current->right && current->right->data == value)) {
		return current; // Parent node found
	}

	if (value < current->data) {
		return getParent(current->left, value); // Recur on the left subtree
	}
	else {
		return getParent(current->right, value); // Recur on the right subtree
	}
}

void BST::insert(int value)
{
	insert(root, value);
}

bool BST::search(int value)
{
	return search(root, value);
}

void BST::delete_node(int value)
{
	delete_node(root, value);
}

void BST::in_orderTraverse()
{
	in_orderTraverse(root);
	cout << endl;
}
