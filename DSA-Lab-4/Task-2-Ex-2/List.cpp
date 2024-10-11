#include <iostream>
#include "List.h"
#include "Node.h"

List::List() {
    head = nullptr;
}

bool List::emptyList() {
    return head == nullptr;
}

void List::insert_begin(int value) {
    Node* newNode = new Node();
    newNode->set_data(value);

    if (emptyList()) {
        head = newNode;
        newNode->set_next(head);
    } else {
        Node* temp = head;
        while (temp->get_next() != head) {
            temp = temp->get_next();
        }
        newNode->set_next(head);
        temp->set_next(newNode);
        head = newNode;
    }
}

void List::insert_end(int value) {
    Node* newNode = new Node();
    newNode->set_data(value);

    if (emptyList()) {
        head = newNode;
        newNode->set_next(head);
    } else {
        Node* temp = head;
        while (temp->get_next() != head) {
            temp = temp->get_next();
        }
        temp->set_next(newNode);
        newNode->set_next(head);
    }
}

void List::insert_at(int pos, int value) {
    if (pos == 1) {
        std::cout << "Position 1 is not allowed." << std::endl;
        return;
    }

    if (emptyList() && pos > 1) {
        std::cout << "List is empty. Cannot insert at position " << pos << "." << std::endl;
        return;
    }

    Node* newNode = new Node();
    newNode->set_data(value);

    Node* temp = head;
    int currentPos = 1;

    while (currentPos < pos - 1 && temp->get_next() != head) {
        temp = temp->get_next();
        currentPos++;
    }

    if (currentPos < pos - 1) {
        std::cout << "Position out of bounds." << std::endl;
        delete newNode;
        return;
    }

    newNode->set_next(temp->get_next());
    temp->set_next(newNode);
}

void List::deleteNode(int pos) {
    if (pos == 1) {
        std::cout << "Cannot delete the first node." << std::endl;
        return;
    }

    if (emptyList()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int currentPos = 1;

    while (currentPos < pos && temp->get_next() != head) {
        prev = temp;
        temp = temp->get_next();
        currentPos++;
    }

    if (currentPos < pos) {
        std::cout << "Position out of bounds." << std::endl;
        return;
    }

    if (temp == head) {
        std::cout << "Cannot delete the first node." << std::endl;
        return;
    }

    prev->set_next(temp->get_next());
    delete temp;
}

void List::delete_begin() {
    if (emptyList()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (head->get_next() == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->get_next() != head) {
            temp = temp->get_next();
        }
        Node* toDelete = head;
        head = head->get_next();
        temp->set_next(head);
        delete toDelete;
    }
}

void List::delete_end() {
    if (emptyList()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (head->get_next() == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp->get_next() != head) {
        prev = temp;
        temp = temp->get_next();
    }

    prev->set_next(head);
    delete temp;
}

void List::traverse() {
    if (emptyList()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();
    } while (temp != head);
    std::cout << std::endl;
}
