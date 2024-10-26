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
void List::delete_begin() {
    if (head == nullptr) { // List is empty
        std::cout << "List is empty, cannot delete from the beginning." << '\n';
        return;
    }

    Node* temp = head; // Store the current head

    if (head == p_last) { // Only one node in the list
        head = nullptr;
        p_first = nullptr;
        p_last = nullptr;
    } else {
        head = head->get_next(); // Move head to the next node
        head->set_prev(nullptr); // Update the new head's previous pointer
    }

    delete temp; // Free memory of the old head
    std::cout << "Deleted node from the beginning." << '\n';
}

void List::delete_end() {
    if (head == nullptr) { // List is empty
        std::cout << "List is empty, cannot delete from the end." << '\n';
        return;
    }

    Node* temp = p_last; // Store the current last node

    if (head == p_last) { // Only one node in the list
        head = nullptr;
        p_first = nullptr;
        p_last = nullptr;
    } else {
        p_last = p_last->get_prev(); // Move p_last to the previous node
        p_last->set_next(nullptr); // Update the new last node's next pointer
    }

    delete temp; // Free memory of the old last node
    std::cout << "Deleted node from the end." << '\n';
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

void List::traverse_reverse() {
    Node* p = p_last; // Start from the last node

    if (p == nullptr) { // Check if the list is empty
        std::cout << "List is Empty!! " << '\n';
        return;
    }

    std::cout << "List elements in reverse: " << '\n';
    while (p != nullptr) {
        std::cout << p->get_data() << " "; // Print the data of the current node
        p = p->get_prev(); // Move to the previous node
    }
    std::cout << '\n'; // New line at the end
}



