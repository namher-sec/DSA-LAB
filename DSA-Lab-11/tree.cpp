#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    // Function to count leaf nodes
    int count_leaf(TNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        return count_leaf(root->left) + count_leaf(root->right);
    }

    // Function to count non-leaf nodes
    int count_nonleaf(TNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        return 1 + count_nonleaf(root->left) + count_nonleaf(root->right);
    }

    // Function to check if a node with a given value is a leaf
    bool isleaf(TNode* root, int value) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == value) {
            return root->left == nullptr && root->right == nullptr;
        }
        return isleaf(root->left, value) || isleaf(root->right, value);
    }
};

int main() {
    // Construct a simple binary tree for testing
    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(4);
    root->left->right = new TNode(5);

    BinaryTree tree;

    cout << "Number of leaf nodes: " << tree.count_leaf(root) << endl;
    cout << "Number of non-leaf nodes: " << tree.count_nonleaf(root) << endl;

    int query = 4;
    cout << "Is node with value " << query << " a leaf? " << (tree.isleaf(root, query) ? "Yes" : "No") << endl;

    return 0;
}
