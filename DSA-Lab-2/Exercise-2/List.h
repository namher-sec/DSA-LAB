#ifndef LIST_H
#define LIST_H

#include"Node.h"
#include<iostream>

class List
{
public:
    List();
    void Insert_Begin(int, std::string);
    void Insert_End(int, std::string);
    void Insert_After(int, std::string, int, std::string);
    void Delete(int, std::string);
    void Display();
    void search_by_id(int);

private:
    Node* head;

};
#endif // LIST_H
