#include "Node.h"

Node::Node()
{
    data = 0;
    next = NULL;
}
void Node::Set_Data(int Value)
{
    data = Value;
}
int Node::Get_Data() const
{
    return data;
}
void Node::Set_Next(Node* temp)
{
    next = temp;
}
Node* Node::Get_Next() const
{
    return next;
}
