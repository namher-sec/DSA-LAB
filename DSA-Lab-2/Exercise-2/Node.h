#ifndef NODE_H
#define NODE_H
#include<iostream>

class Node
{
public:
    Node();
    void set_ID(int);
    int get_ID()const;
    void set_name(std::string);
    std::string get_name()const;
    void set_next(Node*);
    Node* get_next()const;

private:
    int ID;
    std::string name;
    Node* next;
};

#endif // NODE_H
