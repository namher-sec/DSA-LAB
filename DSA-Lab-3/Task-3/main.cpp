#include <iostream>
#include "Node.h"
#include "List.h"
#include "ListOperations.h"

int main() {
    List list1;
    list1.insert_end('h');
    list1.insert_end('e');
    list1.insert_end('l');
    list1.insert_end('l');
    list1.insert_end('o');

    List list2;
    list2.insert_end('w');
    list2.insert_end('o');
    list2.insert_end('r');
    list2.insert_end('l');
    list2.insert_end('d');

    // Concatenate lists
    List concatenated = concatenate_lists(list1, list2);
    concatenated.display();

    // Find intersection (assuming lists contain unique characters for simplicity)
    List intersected = intersection(list1, list2);
    intersected.display();

    // Compare lists
    int comparison = compare_strings(list1, list2);
    std::cout << "Comparison Result: " << comparison << std::endl;

    return 0;
}
