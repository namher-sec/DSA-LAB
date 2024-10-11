#include <iostream>
#include "Node.h"
#include "List.h"



int main()
{
    List list1;
    list1.insert_begin(25);
    list1.insert_end(35);
    list1.insert_after(25, 29);
    list1.insert_after(29, 33);
    list1.insert_after(33, 39);
    list1.delete_node(33);
    list1.display();

    return 0;
}
