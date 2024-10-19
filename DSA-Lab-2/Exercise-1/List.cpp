#include "List.h"
#include "Node.h"

List::List(){
    head = NULL;
}

bool List::is_list_empty(){
    return head == NULL;
}

void List::insert_begin(int num){

    Node* temp = new Node;
    temp->set_data(num);
    temp->set_next(head);
    head = temp;
}


void List::insert_end(int value){
    Node* temp = new Node;
    temp->set_data(value);

    if(head == NULL){
        head = temp;
    }
    else{
        Node* p = head;

        while(p->get_next() != NULL){
            p = p->get_next();
        }
        p->set_next(temp);
    }
}

void List::insert_after(int prev_val, int new_val){
    Node* temp = new Node;
    temp->set_data(new_val);

    if(head == NULL){
        head->set_next(temp);
        return;
    }
    Node* current = head;
    while(current->get_next() != NULL){
        if(current->get_data() == prev_val){
            temp->set_next(current->get_next());
            current->set_next(temp);
            return;
        }
        current = current->get_next();
    }
}


void List::delete_node(int val){
    if(head == NULL){
        std::cout << " List is empty!! ";
    }

    Node* p = head;
    Node* q = NULL;

    if(p->get_data() == val){
        head = p->get_next();
        delete p;
        return;
    }

    while(p != NULL && p->get_data() != val){
        q = p;
        p = p->get_next();
    }

    if(p == NULL){
        std::cout << "Element Not in List!!" << '\n';
        return;
    }

    if(p->get_next() == NULL){
        q->set_next(NULL);
    }
    else{
        q->set_next(p->get_next());
    }

    delete p;
}


void List::display(){
    Node* p = head;  

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










