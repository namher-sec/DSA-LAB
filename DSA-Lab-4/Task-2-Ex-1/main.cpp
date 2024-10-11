#include <iostream>
#include "List.h"

int main() {
    List li;
    li.insert_begin(6);
    li.insert_begin(10);
    li.insert_end(7);
    li.insert_after(6, 9);
    li.insert_after(9, 11);
    li.delete_Node(6);
    li.traverse();

    return 0;
}
