#include <iostream>
#include "Stack.h"

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Top element after pop: " << stack.peek() << std::endl;

    while (!stack.is_empty()) {
        std::cout << "Popped element: " << stack.pop() << std::endl;
    }

    stack.pop(); // This will indicate underflow

    return 0;
}
