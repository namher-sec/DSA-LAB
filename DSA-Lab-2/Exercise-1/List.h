#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <Node.h>

class List
{
public:
    List();
    bool is_list_empty();
    void insert_begin(int);
    void insert_end(int);
    void insert_after(int, int);
    void delete_node(int);
    void display();

private:
    Node* head;
};

#endif // LIST_H
