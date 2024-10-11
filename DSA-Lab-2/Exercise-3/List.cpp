#include "Node.h"
#include "List.h"
using namespace std;

List::List()
{
    head = NULL;
}

bool List::Is_List_Empty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void List::Insert_Begin(int Value)
{
    Node* temp = new Node;
    temp->Set_Data(Value);
    temp->Set_Next(NULL);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->Set_Next(head);
        head = temp;
    }
}

void List::Insert_End(int Value)
{
    Node* temp = new Node;
    temp->Set_Data(Value);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* p = head;
        while (p->Get_Next() != NULL)
        {
            p = p->Get_Next();
        }
        p->Set_Next(temp);
    }

}

void List::Insert_After(int OldV, int NewV)
{
    Node* temp = new Node;
    temp->Set_Data(NewV);
    if (head == NULL)
    {
        head->Set_Next(temp);
        return;
    }
    Node* current = head;
    while (current->Get_Next() != NULL)
    {
    if (current->Get_Data() == OldV)
    {
        temp->Set_Next(current->Get_Next());
        current->Set_Next(temp);
        return;
    }
    current = current->Get_Next();
}
}

void List::Delete_Node(int Value)
{
    if (head == NULL)
    {
        cout << "Empty List";
    }

    Node* p = head;
    Node* q = NULL;
    if (p->Get_Data() == Value)
    {
        head = p->Get_Next();
        delete p;
        return;
    }
    while (p != NULL && p->Get_Data() != Value)
    {
        q = p;
        p = p->Get_Next();
    }
    if (p == NULL)
    {
        cout << "Element not found!" << endl;
        return;
    }
    if (p->Get_Next() == NULL)
    {
    q->Set_Next(NULL);

    }
    else
    {
    q->Set_Next(p->Get_Next());

    }
    delete p;

}

void List::Display()
{
    Node* p = new Node;
    p = head;
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
    }
    cout << "List is: " << endl;
    while (p != NULL)
    {
        cout << p->Get_Data() << " ";
        p = p->Get_Next();
    }
    cout << endl;
}

void List::Largest_Node()
{
    Node* largest = head;
    Node* temp = head;
    while (temp != NULL)
    {
        if (largest->Get_Data() < temp->Get_Data())
        {
        largest = temp;

        }
        temp = temp->Get_Next();

    }
    cout << "The largest node is: " << largest->Get_Data() << endl;
}
void List::Total_Nodes()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
    }
    int count = 0;
    Node* p = head;
    while (p != NULL)
    {
    p = p->Get_Next();
    count++;

    }
    cout << "Total number of nodes are: " << count << endl;
}

void List::Nodes_At_Even_Positions()
{
    Node* temp = head;
    int check = 0;
    cout << "Nodes at even positions are: " << endl;
    while (temp != NULL)
    {
        if ((check % 2) == 0)
        {
            cout << temp->Get_Data() << " ";
        }
        temp = temp->Get_Next();
        check++;
    }
    cout << endl;
}


void List::Split_Nodes()
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        current = current->Get_Next();
        count++;
    }
    int Mid = count / 2;
    Node* p = head;
    for (int i = 1; i < Mid; i++)
    {
        p = p->Get_Next();
    }
    Node* q = p->Get_Next();
    p->Set_Next(NULL);
    Node* r = q;
    while (r->Get_Next() != NULL)
    {
    r = r->Get_Next();

    }
    r->Set_Next(head);
    head = q;
}

































