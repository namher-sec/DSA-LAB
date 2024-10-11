#include <iostream>
#include"Node.h"
#include"List.h"

using namespace std;

int main()
{
    List li;
    li.Insert_Begin(1, "Zia");
    li.Insert_End(2, "Abdullah");
    li.Insert_After(1, "Ahmed", 3, "Hammad");
    li.Insert_Begin(4, "Umar");
    li.Insert_End(5, "Sami");
    li.Display();
    li.Delete(2, "Sami");
    std::cout << "List after deletion." << std::endl;
    li.Display();

    int ask_ID;
    std::cout << std::endl << "Enter ID: ";
    std::cin >> ask_ID;
    li.search_by_id(ask_ID);

}
