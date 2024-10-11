#include "Stack.h"
#include <iostream>

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    while (!is_empty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node();
    newNode->set_data(value);
    newNode->set_next(top);
    top = newNode;
}

int Stack::pop() {
    if (is_empty()) {
        std::cerr << "Stack underflow! Cannot pop from an empty stack." << std::endl;
        return -1; // Indicating stack is empty
    }
    Node* temp = top;
    int poppedValue = top->get_data();
    top = top->get_next();
    delete temp;
    return poppedValue;
}

int Stack::peek() const {
    if (is_empty()) {
        std::cerr << "Stack is empty! Cannot peek." << std::endl;
        return -1; // Indicating stack is empty
    }
    return top->get_data();
}

bool Stack::is_empty() const {
    return top == nullptr;
}
