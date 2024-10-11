#include "Node.h"

Node::Node() {
    data = 0;
    next = nullptr;
}

void Node::set_data(int num) {
    data = num;
}

int Node::get_data() const {
    return data;
}

void Node::set_next(Node* temp) {
    next = temp;
}

Node* Node::get_next() const {
    return next;
}
