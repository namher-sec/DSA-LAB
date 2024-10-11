#include "List.h"
#include "Node.h"

List::List() {
    head = nullptr;
}

bool List::is_list_empty() {
    return head == nullptr;
}

void List::insert_begin(char num) {
    Node* temp = new Node;
    temp->set_data(num);
    temp->set_next(head);
    head = temp;
}

void List::insert_end(char value) {
    Node* temp = new Node;
    temp->set_data(value);
    temp->set_next(nullptr);

    if (head == nullptr) {
        head = temp;
    } else {
        Node* p = head;
        while (p->get_next() != nullptr) {
            p = p->get_next();
        }
        p->set_next(temp);
    }
}

void List::display() {
    if (head == nullptr) {
        std::cout << "List is Empty!! " << '\n';
        return;
    }
    Node* p = head;
    std::cout << "List elements: ";
    while (p != nullptr) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    }
    std::cout << '\n';
}
