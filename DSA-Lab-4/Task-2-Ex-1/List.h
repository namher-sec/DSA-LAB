#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List {
public:
    List();
    bool emptyList();
    void insert_after(int oldV, int newV);
    void insert_begin(int value);
    void insert_end(int value);
    void delete_Node(int val);
    void delete_begin();
    void delete_end();
    void traverse();

private:
    Node* head;
};

#endif // LIST_H
