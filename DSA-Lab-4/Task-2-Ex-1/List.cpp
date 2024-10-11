#include <iostream>
#include "List.h"
#include "Node.h"

// Constructor initializes the dummy head node
List::List() {
    head = new Node();
    head->set_data(0); // Dummy value
    head->set_next(nullptr);
}

// Checks if the list is empty.
bool List::emptyList() {
    return head->get_next() == nullptr;
}

void List::insert_begin(int value) {
    Node* p = new Node();
    p->set_data(value);

    // Insert at the beginning
    p->set_next(head->get_next());
    head->set_next(p);
}

void List::insert_after(int oldV, int newV) {
    if (emptyList()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* p = head->get_next();
    while (p != nullptr && p->get_data() != oldV) {
        p = p->get_next();
    }

    if (p == nullptr) {
        std::cout << "Node not found" << std::endl;
        return;
    }

    Node* t = new Node();
    t->set_data(newV);
    t->set_next(p->get_next());
    p->set_next(t);
}

void List::insert_end(int value) {
    Node* p = new Node();
    p->set_data(value);
    p->set_next(nullptr);

    if (emptyList()) {
        head->set_next(p);
    } else {
        Node* temp = head;
        while (temp->get_next() != nullptr) {
            temp = temp->get_next();
        }
        temp->set_next(p);
    }
}

void List::delete_Node(int val) {
    if (emptyList()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* p = head->get_next(), * t = head;
    while (p != nullptr && p->get_data() != val) {
        t = p;
        p = p->get_next();
    }

    if (p == nullptr) {
        std::cout << "Node not found" << std::endl;
        return;
    }

    t->set_next(p->get_next());
    delete p;
}

void List::delete_begin() {
    if (emptyList()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* temp = head->get_next();
    head->set_next(temp->get_next());
    delete temp;
}

void List::delete_end() {
    if (emptyList()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* p = head->get_next();
    Node* t = nullptr;

    // If there's only one node
    if (p->get_next() == nullptr) {
        delete_begin();
        return;
    }

    // Find the second last node
    while (p->get_next() != nullptr) {
        t = p;
        p = p->get_next();
    }

    // Delete the last node
    if (t != nullptr) {
        t->set_next(nullptr);
    }
    delete p;
}

void List::traverse() {
    Node* p = head->get_next();
    while (p != nullptr) {
        std::cout << p->get_data() << "--";
        p = p->get_next();
    }
    std::cout << "nullptr" << std::endl; // Indicate end of list
}
