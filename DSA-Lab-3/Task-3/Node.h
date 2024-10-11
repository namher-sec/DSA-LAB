#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
public:
    Node();
    void set_data(char);
    char get_data() const;
    void set_next(Node*);
    Node* get_next() const;

private:
    char data;
    Node* next;
};

#endif // NODE_H
