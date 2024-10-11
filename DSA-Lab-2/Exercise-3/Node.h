#ifndef NODE_H
#define NODE_H
#include<iostream>

class Node
{
public:
    Node();
    void Set_Data(int);
    int Get_Data() const;
    void Set_Next(Node*);
    Node* Get_Next() const;

private:
    int data;
    Node* next;
};

#endif // NODE_H
