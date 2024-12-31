#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode() : data(0), left(nullptr), right(nullptr) {}
    TNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TNode* root;

    BST() : root(nullptr) {}

    // Insert a node with the given value
    void insert(TNode* node, int val) {
        if (node == nullptr) {
            node = new TNode(val);
            if (root == nullptr) {
                root = node;
            }
            return;
        }

        if (val < node->data) {
            if (node->left == nullptr) {
                node->left = new TNode(val);
            } else {
                insert(node->left, val);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TNode(val);
            } else {
                insert(node->right, val);
            }
        }
    }

    // Search for a node with a given value
    bool search(TNode* node, int val) {
        if (node == nullptr) {
            return false;
        }

        if (val == node->data) {
            return true;
        } else if (val < node->data) {
            return search(node->left, val);
        } else {
            return search(node->right, val);
        }
    }

    // Find the maximum value in the BST
    TNode* findMax(TNode* node) {
        while (node != nullptr && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Find the parent of a given node
    TNode* getParent(TNode* node, int val) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return nullptr;
        }

        if ((node->left != nullptr && node->left->data == val) ||
            (node->right != nullptr && node->right->data == val)) {
            return node;
            } else if (val < node->data) {
                return getParent(node->left, val);
            } else {
                return getParent(node->right, val);
            }
    }
};

// Function 1: Print the path from root to the given node
bool printPath(TNode* node, int val) {
    if (node == nullptr) {
        return false;
    }

    // If the node data matches, print the node and return true
    if (node->data == val) {
        cout << node->data << " ";
        return true;
    }

    // Try to find the value in the left or right subtree
    if (printPath(node->left, val) || printPath(node->right, val)) {
        cout << node->data << " ";
        return true;
    }

    return false;
}

// Function 2: Find the maximum value in the BST
int findMaxValue(TNode* node) {
    TNode* maxNode = node;
    while (maxNode != nullptr && maxNode->right != nullptr) {
        maxNode = maxNode->right;
    }
    return maxNode ? maxNode->data : -1;  // Return -1 if tree is empty
}

// Function 3: Find the sibling of a given node value
int findSibling(TNode* root, int val) {
    TNode* parent = root;
    TNode* node = nullptr;

    while (parent != nullptr) {
        if ((parent->left != nullptr && parent->left->data == val) ||
            (parent->right != nullptr && parent->right->data == val)) {
            node = parent->left->data == val ? parent->right : parent->left;
        break;
            }

            if (val < parent->data) {
                parent = parent->left;
            } else {
                parent = parent->right;
            }
    }

    return node ? node->data : -1;  // Return -1 if no sibling exists
}

int main() {
    BST tree;
    tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    // 1. Print the path from root to a given node (e.g., 40)
    cout << "Path to node 40: ";
    if (!printPath(tree.root, 40)) {
        cout << "Node not found!";
    }
    cout << endl;

    // 2. Find the maximum value in the BST
    int maxValue = findMaxValue(tree.root);
    cout << "Maximum value in BST: " << maxValue << endl;

    // 3. Find the sibling of a given node (e.g., 40)
    int sibling = findSibling(tree.root, 40);
    if (sibling != -1) {
        cout << "Sibling of node 40: " << sibling << endl;
    } else {
        cout << "No sibling found for node 40" << endl;
    }

    return 0;
}
