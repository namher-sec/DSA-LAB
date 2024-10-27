#include <iostream>
#include "Stack.h"

int main() {
    Stack stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    std::cout << "Top element is: " << stack1.peek() << std::endl;

    std::cout << "Popped element: " << stack1.pop() << std::endl;
    std::cout << "Top element after pop: " << stack1.peek() << std::endl;

    std::cout << "All elements in Stack: ";
    stack1.display();

    while (!stack1.is_empty()) {
        std::cout << "Popped element: " << stack1.pop() << std::endl;
    }

    stack1.pop(); // This will indicate underflow

    stack1.push(50);
    stack1.push(60);
    stack1.push(70);

    stack1.display();

    return 0;
}
