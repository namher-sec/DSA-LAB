#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List {
public:
    List();
    bool is_list_empty();
    void insert(int); // Change from multiple insert functions to a single insert function
    void delete_node(int);
    void display();

private:
    Node* head;
};

#endif // LIST_H
