#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List {
public:
    List();
    bool is_list_empty();
    void insert_begin(char);
    void insert_end(char);
    void display();

    // For internal use in other functions
    Node* head;

private:
    void insert_after(char, char);
};

#endif // LIST_H
