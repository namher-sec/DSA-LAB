#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TNode {
public:
    char data;
    TNode* left;
    TNode* right;

    TNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
public:
    // Function to construct the expression tree
    TNode* constructTree(const string& postfix) {
        stack<TNode*> s;

        for (char ch : postfix) {
            if (isOperand(ch)) {
                // Create a new node for the operand and push it onto the stack
                TNode* node = new TNode(ch);
                s.push(node);
            } else {
                // Create a new node for the operator
                TNode* node = new TNode(ch);

                // Pop two nodes from the stack and attach them as children
                node->right = s.top(); s.pop();
                node->left = s.top(); s.pop();

                // Push the new node back onto the stack
                s.push(node);
            }
        }

        // The remaining node in the stack is the root of the expression tree
        return s.top();
    }

    // Post-order traversal of the tree
    void postorder(TNode* node) {
        if (node == nullptr) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data;
    }

private:
    // Helper function to check if a character is an operand
    bool isOperand(char ch) {
        return isalnum(ch);
    }
};

int main() {
    string postfix = "ab+ef*g*-";

    ExpressionTree tree;
    TNode* root = tree.constructTree(postfix);

    cout << "Post-order traversal of the expression tree: ";
    tree.postorder(root);
    cout << endl;

    return 0;
}
