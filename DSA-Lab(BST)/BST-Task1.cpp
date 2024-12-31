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

    // Find the minimum node in the given subtree
    TNode* findmin(TNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Delete a node with a given value
    void delete_node(TNode* node, int val) {
        if (node == nullptr) return;

        if (val < node->data) {
            delete_node(node->left, val);
        } else if (val > node->data) {
            delete_node(node->right, val);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                TNode* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                TNode* temp = node;
                node = node->left;
                delete temp;
            } else {
                TNode* temp = findmin(node->right);
                node->data = temp->data;
                delete_node(node->right, temp->data);
            }
        }
    }

    // Check if the tree is empty
    bool isEmpty() {
        return root == nullptr;
    }

    // In-order traversal to print the values in ascending order
    void in_orderTraverse(TNode* node) {
        if (node == nullptr) return;
        in_orderTraverse(node->left);
        cout << node->data << " ";
        in_orderTraverse(node->right);
    }

    // Find the parent of a node with the given value
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

int main() {
    BST tree;
    tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order traversal: ";
    tree.in_orderTraverse(tree.root);
    cout << endl;

    cout << "Search for 40: " << (tree.search(tree.root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search for 100: " << (tree.search(tree.root, 100) ? "Found" : "Not Found") << endl;

    cout << "Parent of 40: " << (tree.getParent(tree.root, 40) ? to_string(tree.getParent(tree.root, 40)->data) : "No parent") << endl;

    tree.delete_node(tree.root, 20);
    cout << "In-order traversal after deleting 20: ";
    tree.in_orderTraverse(tree.root);
    cout << endl;

    return 0;
}
