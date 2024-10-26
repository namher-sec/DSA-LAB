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
    Node* current = head; 
    while (current != nullptr && current->get_data() != value) {
        current = current->get_next(); 
    }

   
    if (current != nullptr) {
        
        if (current->get_prev() != nullptr) {
            current->get_prev()->set_next(current->get_next());
        } else {
            head = current->get_next(); 
        }

        
        if (current->get_next() != nullptr) {
            current->get_next()->set_prev(current->get_prev());
        } else {
            p_last = current->get_prev(); 
        }

        delete current; // Free memory
    }
}

void List::insert_after(int prevValue, int nextValue) {
    Node* current = head; 
    while (current != nullptr && current->get_data() != prevValue) {
        current = current->get_next(); 
    }

   
    if (current != nullptr) {
        Node* newNode = new Node; 
        newNode->set_data(nextValue);
        newNode->set_next(current->get_next()); 
        newNode->set_prev(current); 

       
        if (current->get_next() != nullptr) {
            current->get_next()->set_prev(newNode);
        } else {
            p_last = newNode; 
        }

        current->set_next(newNode); 
    }
}
void List::delete_begin() {
    if (head == nullptr) {
        std::cout << "List is empty, cannot delete from the beginning." << '\n';
        return;
    }

    Node* temp = head; 

    if (head == p_last) { 
        head = nullptr;
        p_first = nullptr;
        p_last = nullptr;
    } else {
        head = head->get_next(); 
        head->set_prev(nullptr); 
    }

    delete temp; 
    std::cout << "Deleted node from the beginning." << '\n';
}

void List::delete_end() {
    if (head == nullptr) { 
        std::cout << "List is empty, cannot delete from the end." << '\n';
        return;
    }

    Node* temp = p_last; 

    if (head == p_last) { 
        head = nullptr;
        p_first = nullptr;
        p_last = nullptr;
    } else {
        p_last = p_last->get_prev(); 
        p_last->set_next(nullptr); 
    }

    delete temp; 
    std::cout << "Deleted node from the end." << '\n';
}

void List::reverse() {
    Node* current = head; 
    Node* temp = nullptr; 

    
    while (current != nullptr) {
        temp = current->get_prev(); 
        current->set_prev(current->get_next()); 
        current->set_next(temp); 
        current = current->get_prev(); 
    }

    
    if (temp != nullptr) {
        head = temp->get_prev(); 
    }
    
    
    p_first = head; 
    p_last = temp; 
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
    std::cout << '\n'; 
}



