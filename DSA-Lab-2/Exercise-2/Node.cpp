#include "Node.h"

Node::Node(){
    ID = 0;
    name = " ";
    next = NULL;
}

void Node::set_ID(int id){
    ID = id;
}

int Node::get_ID() const{
    return ID;
}

void Node::set_name(std::string n){
    name = n;
}

std::string Node::get_name() const{
    return name;
}

void Node::set_next(Node* temp){
    next = temp;
}

Node* Node::get_next() const{
    return next;
}
