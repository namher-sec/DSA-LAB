#include "Node.h"

Node::Node() {
    data = '\0';
    next = nullptr;
}

void Node::set_data(char num) {
    data = num;
}

char Node::get_data() const {
    return data;
}

void Node::set_next(Node* temp) {
    next = temp;
}

Node* Node::get_next() const {
    return next;
}
