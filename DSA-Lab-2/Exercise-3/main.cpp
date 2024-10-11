#include <iostream>
#include"Node.h"
#include"List.h"

using namespace std;

int main()
{
    List li;
    li.Insert_Begin(15);
    li.Insert_End(45);
    li.Insert_After(15, 20);
    li.Insert_After(20, 22);
    li.Insert_End(27);
    li.Insert_End(13);
    li.Insert_End(3);
    li.Insert_After(27, 30);
    li.Display();
    li.Largest_Node();
    li.Total_Nodes();
    li.Nodes_At_Even_Positions();
    cout << "After splitting nodes, ";
    li.Split_Nodes();
    li.Display();

}
