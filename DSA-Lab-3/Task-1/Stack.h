#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {
public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    int peek() const;
    bool is_empty() const;

private:
    Node* top;
};

#endif // STACK_H
