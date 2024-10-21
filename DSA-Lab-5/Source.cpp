#include <iostream>
#include "List.h"
#include "Node.h"

int main() {

	List doubly_list1;
	doubly_list1.emptyList();
	doubly_list1.insert_begin(15);
	doubly_list1.insert_end(29);
	//doubly_list1.insert_after(29, 34);
	//doubly_list1.deleteNode(29);
	doubly_list1.traverse();


	return 0;
}