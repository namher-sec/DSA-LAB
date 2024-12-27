#include "Node.h"
#include "BST.h"
#include "BST.cpp"
#include <iostream>

using namespace std;

int main() {

	BST bst;
	bst.insert(bst.root, 60);
	bst.insert(bst.root, 50);
	bst.insert(bst.root, 55);
	bst.insert(bst.root, 40);
	bst.insert(bst.root, 25);
	bst.insert(bst.root, 30);
	

	bst.in_orderTraverse(bst.root);

	return 0;
}
