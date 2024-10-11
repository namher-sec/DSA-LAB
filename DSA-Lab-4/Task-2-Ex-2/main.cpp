#include <iostream>
#include "List.h"

int main() {
    List cl;
    cl.insert_begin(5);
    cl.insert_end(10);
    cl.insert_end(15);
    cl.insert_at(2, 7);
    cl.traverse();

    cl.deleteNode(2); // Deletes 7
    cl.traverse();

    cl.delete_begin(); // Deletes 5
    cl.traverse();

    cl.delete_end(); // Deletes 15
    cl.traverse();

    return 0;
}
