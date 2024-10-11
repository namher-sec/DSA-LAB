#include "ListOperations.h"

List concatenate_lists(const List& list1, const List& list2) {
    List result;

    Node* current = list1.head;
    while (current != nullptr) {
        result.insert_end(current->get_data());
        current = current->get_next();
    }

    current = list2.head;
    while (current != nullptr) {
        result.insert_end(current->get_data());
        current = current->get_next();
    }

    return result;
}

List intersection(const List& list1, const List& list2) {
    List result;

    Node* current1 = list1.head;
    while (current1 != nullptr) {
        Node* current2 = list2.head;
        while (current2 != nullptr) {
            if (current1->get_data() == current2->get_data()) {
                result.insert_end(current1->get_data());
                break; // Move to the next element in list1
            }
            current2 = current2->get_next();
        }
        current1 = current1->get_next();
    }

    return result;
}

int compare_strings(const List& list1, const List& list2) {
    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->get_data() < current2->get_data()) {
            return -1; // list1 is lexicographically less
        } else if (current1->get_data() > current2->get_data()) {
            return 1; // list1 is lexicographically greater
        }
        current1 = current1->get_next();
        current2 = current2->get_next();
    }

    if (current1 == nullptr && current2 != nullptr) {
        return -1; // list1 is a prefix of list2
    } else if (current1 != nullptr && current2 == nullptr) {
        return 1; // list2 is a prefix of list1
    }

    return 0; // both lists are the same
}
