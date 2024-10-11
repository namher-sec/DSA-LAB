#include <iostream>
#include "Node.h"
#include "List.h"

int main() {
    List list1;
    list1.insert(5);
    list1.insert(2);
    list1.insert(7);
    list1.insert(3);
    list1.display(); // Should display: 2 3 5 7

    return 0;
}
