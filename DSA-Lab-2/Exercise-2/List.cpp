#include "Node.h"
#include "List.h"

List::List()
{
    head = NULL;
}
void List::Insert_Begin(int id, std::string n)
{
    Node* temp = new Node;
    temp->set_ID(id);
    temp->set_name(n);
    temp->set_next(NULL);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->set_next(head);
        head = temp;
    }
}
void List::Insert_End(int id, std::string n)
{
    Node* temp = new Node;
    temp->set_ID(id);
    temp->set_name(n);
    temp->set_next(NULL);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* p = head;
        while (p->get_next() != NULL)
        {
            p = p->get_next();
        }
        p->set_next(temp);
    }
}

void List::Insert_After(int OldID, std::string OldN, int NewID, std::string NewN)
{
    Node* temp = new Node;
    temp->set_ID(NewID);
    temp->set_name(NewN);
    temp->set_next(NULL);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* current = head;
        while (current->get_next() != NULL)
        {
            if (current->get_ID() == OldID && current->get_name() == OldN)
            {
                temp->set_next(current->get_next());
                current->set_next(temp);
                return;
            }
            current = current->get_next();
        }
    }
}

void List::Delete(int id, std::string n)
{
    if (head == NULL)
    {
        std::cout << "List is empty!" << std::endl;
    }
    Node* p = head;
    Node* q = NULL;
    if (p->get_ID() == id && p->get_name() == n)
    {
        head = p->get_next();
        delete p;
        return;
    }
    while (p != NULL && p->get_ID() != id && p->get_name() != n)
    {
        q = p;
        p = p->get_next();
    }
    if (p == NULL)
    {
        std::cout << "Element not found!";
        return;
    }
    if (p->get_next() == NULL)
    {
        q->get_next() == NULL;
    }
    else
    {
        q->set_next(p->get_next());
    }
    delete p;
}

void List::Display()
{
    Node* p = head;
    p = head;
    if (head == NULL)
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    std::cout << "List is: " << std::endl;
    while (p != NULL)
    {
        std::cout << p->get_ID() << " " << p->get_name() << std::endl;
        p = p->get_next();
    }
}

void List::search_by_id(int id) {
    Node* p = head;
    if (p->get_ID() == id){
        head = p->get_next();
        std::cout << p->get_ID() << " " << p->get_name() << std::endl;
    }
}
