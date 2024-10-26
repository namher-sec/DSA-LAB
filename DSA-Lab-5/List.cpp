#include "List.h"

List::List() : head(nullptr), p_first(nullptr), p_last(nullptr) {}

List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->get_next();
        delete current; // Free the current node
        current = next;
    }
}

bool List::emptyList() const {
    return head == nullptr;
}

void List::insert_begin(int value)
{
	Node* temp = new Node;
	temp->set_data(value);
	temp->set_prev(NULL);

	if (head == NULL) {
		temp->set_next(NULL);
		p_first = temp;
		p_last = temp;
		head = temp;
	}
	else {
		temp->set_next(head); 
		head->set_prev(temp);  
		head = temp;
	}

}

void List::insert_end(int value)
{
	Node* temp = new Node;
	temp->set_data(value);
	temp->set_next(NULL); 

	if (head == NULL) { 
		temp->set_prev(NULL);
		p_first = temp;
		p_last = temp;
		head = temp; 
	}
	else {
		p_last->set_next(temp); 
		temp->set_prev(p_last); 
		p_last = temp;
	}
}

void List::deleteNode(int value) {
    Node* current = head; // Start from the head of the list
    // Search for the node with the value
    while (current != nullptr && current->get_data() != value) {
        current = current->get_next(); // Move to the next node
    }

    // If we found the node to delete
    if (current != nullptr) {
        // If there's a previous node, link it to the next node
        if (current->get_prev() != nullptr) {
            current->get_prev()->set_next(current->get_next());
        } else {
            head = current->get_next(); // Update head if needed
        }

        // If there's a next node, link it back to the previous node
        if (current->get_next() != nullptr) {
            current->get_next()->set_prev(current->get_prev());
        } else {
            p_last = current->get_prev(); // Update p_last if needed
        }

        delete current; // Free memory
    }
}

void List::insert_after(int prevValue, int nextValue) {
    Node* current = head; // Start from the head of the list
    // Search for the node with the value prevValue
    while (current != nullptr && current->get_data() != prevValue) {
        current = current->get_next(); // Move to the next node
    }

    // If we found the node with prevValue
    if (current != nullptr) {
        Node* newNode = new Node; // Create the new node
        newNode->set_data(nextValue);
        newNode->set_next(current->get_next()); // Set newNode's next to current's next
        newNode->set_prev(current); // Set newNode's previous to current

        // Adjust the next node's previous pointer if it exists
        if (current->get_next() != nullptr) {
            current->get_next()->set_prev(newNode);
        } else {
            p_last = newNode; // Update p_last if current was the last node
        }

        current->set_next(newNode); // Link current's next to the new node
    }
}
void List::traverse()
{
	Node* p = p_first;

	if (p == NULL) {
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


