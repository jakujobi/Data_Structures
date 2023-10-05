// #include <iostream>
// #include "Stack.h"

// using namespace std;

// int main() {
//     // Create a stack with default size (2)
//     Stack stack;

//     // Push elements onto the stack
//     stack.push("Apple");
//     stack.push("Banana");
//     stack.push("Cherry");

//     // Display the stack contents
//     cout << "Stack contents:" << endl;
//     stack.view();

//     // Peek at the top element without removing it
//     cout << "Top element: " << stack.peek() << endl;

//     // Copy the stack and display the copied stack contents
//     Stack copiedStack = stack.copy();
//     cout << "Copied stack contents:" << endl;
//     copiedStack.view();

//     // Pop an element from the original stack
//     stack.pop();

//     // Display the modified stack
//     cout << "Modified stack contents:" << endl;
//     stack.view();

//     // Check if the stack is empty
//     if (stack.empty()) {
//         cout << "Stack is empty." << endl;
//     }
//     else {
//         cout << "Stack is not empty." << endl;
//     }

//     // Destroy the stack
//     stack.destroy();

//     // Check if the stack is empty after destruction
//     if (stack.empty()) {
//         cout << "Stack is empty after destruction." << endl;
//     }
//     else {
//         cout << "Stack is not empty after destruction." << endl;
//     }

//     return 0;
// }


//!________________________________________________
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    // Create a stack
    Stack stack;

    // Push some elements onto the stack
    stack.push("Element 1");
    stack.push("Element 2");
    stack.push("Element 3");

    // Display the stack contents
    cout << "Stack contents:" << endl;
    stack.view();

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Pop an element
    Element popped = stack.pop();
    cout << "Popped element: " << popped << endl;

    // Display the modified stack
    cout << "Modified stack contents:" << endl;
    stack.view();

    // Check if the stack is empty
    if (stack.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    // Get the size of the stack
    cout << "Stack size: " << stack.size() << endl;

    // Destroy the stack
    stack.destroy();

    // Check if the stack is empty after destruction
    if (stack.empty()) {
        cout << "Stack is empty after destruction." << endl;
    } else {
        cout << "Stack is not empty after destruction." << endl;
    }

    return 0;
}
