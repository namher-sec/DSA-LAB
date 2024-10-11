#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List {
public:
    List();
    bool emptyList();
    void insert_at(int pos, int value);
    void insert_begin(int value);
    void insert_end(int value);
    void deleteNode(int pos);
    void delete_begin();
    void delete_end();
    void traverse();

private:
    Node* head;
};

#endif // LIST_H
