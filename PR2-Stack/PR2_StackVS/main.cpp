//!________________________________________________
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    // Create a stack
    Stack stack;

    // Push some elements onto the stack
    stack.push("Element 1");
    stack.printStack(); // Print the stack after pushing 1 element

    stack.push("Element 2");
    stack.printStack(); // Print the stack after pushing 2 elements

    stack.push("Element 3");
    stack.printStack(); // Print the stack after pushing 3 elements

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Pop an element
    Element popped = stack.pop();
    cout << "Popped element: " << popped << endl;

    // Display the modified stack
    cout << "\nModified stack contents:" << endl;
    stack.printStack();

    cout << endl;
    stack.printStack(); // Print the stack

    cout << endl;
    cout << "\nDestroy the stack" << endl;

    stack.destroy(); // Destroy the stack

    cout << "\nCheck if the Stack is empty or not: " << endl;
    // Check if the stack is empty after destruction
    if (stack.empty()) {
        cout << "Stack is empty after destruction." << endl;
    } else {
        cout << "Stack is not empty after destruction." << endl;
    }

    return 0;
}