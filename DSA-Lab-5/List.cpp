#include "List.h"

List::List()
{
	head = NULL;
	p_first = NULL;
	p_last = NULL;
}

bool List::emptyList()
{
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
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

void List::insert_after(int prev, int next)
{
}

void List::deleteNode(int value)
{
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


