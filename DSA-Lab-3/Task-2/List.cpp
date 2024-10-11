#include "List.h"
#include "Node.h"

List::List() {
    head = NULL;
}

bool List::is_list_empty() {
    return head == NULL;
}

void List::insert(int value) {
    Node* newNode = new Node();
    newNode->set_data(value);
    newNode->set_next(NULL);

    if (head == NULL || head->get_data() >= value) {
        // Insert at the beginning
        newNode->set_next(head);
        head = newNode;
    } else {
        // Find the appropriate position
        Node* current = head;
        while (current->get_next() != NULL && current->get_next()->get_data() < value) {
            current = current->get_next();
        }
        newNode->set_next(current->get_next());
        current->set_next(newNode);
    }
}

void List::delete_node(int val) {
    if (head == NULL) {
        std::cout << "List is empty!! ";
        return;
    }

    Node* p = head;
    Node* q = NULL;

    if (p->get_data() == val) {
        head = p->get_next();
        delete p;
        return;
    }

    while (p != NULL && p->get_data() != val) {
        q = p;
        p = p->get_next();
    }

    if (p == NULL) {
        std::cout << "Element Not in List!!" << '\n';
        return;
    }

    q->set_next(p->get_next());
    delete p;
}

void List::display() {
    Node* p = head;

    if (head == NULL) {
        std::cout << "List is Empty!! " << '\n';
        return;
    }
    std::cout << "List elements: " << '\n';
    while (p != NULL) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << '\n';
}
