// #include "Stack.h"
// #include <iostream>
// using namespace std;

// // Constructor (default size is 2)
// Stack::Stack(int capacity) {
//     initialize();
//     if (capacity > 0) {
//         stackArray = new std::string[capacity];
//     }
// }

// // Copy constructor
// Stack::Stack(const Stack& other) {
//     initialize();
//     stackArray = new std::string[other.STACK_SIZE];
//     top = other.top;
//     for (int i = 0; i <= top; ++i) {
//         stackArray[i] = other.stackArray[i];
//     }
// }

// // Destructor
// Stack::~Stack() {
//     delete[] stackArray;
// }

// // Initialize stack to empty
// void Stack::initialize() {
//     stackArray = nullptr;
//     top = -1;
// }

// // Add element to top
// void Stack::push(const std::string& element) {
//     if (full()) {
//         std::cout << "Warning: Stack is full. Cannot push element." << std::endl;
//         return;
//     }
//     stackArray[++top] = element;
// }

// // Remove element from top
// void Stack::pop() {
//     if (empty()) {
//         std::cout << "Warning: Stack is empty. Cannot pop element." << std::endl;
//         return;
//     }
//     --top;
// }

// // Access top element
// std::string Stack::peek() const {
//     if (empty()) {
//         std::cout << "Warning: Stack is empty. Cannot peek." << std::endl;
//         return "";
//     }
//     return stackArray[top];
// }

// // Display stack contents
// void Stack::view() const {
//     for (int i = top; i >= 0; --i) {
//         std::cout << stackArray[i] << std::endl;
//     }
// }

// // Build a separate duplicate copy of the existing stack
// Stack Stack::copy() const {
//     Stack copiedStack(STACK_SIZE);
//     for (int i = top; i >= 0; --i) {
//         copiedStack.push(stackArray[i]);
//     }
//     return copiedStack;
// }

// // Remove all elements from the stack
// void Stack::destroy() {
//     while (!empty()) {
//         pop();
//     }
// }

// // Checks if the stack is empty
// bool Stack::empty() const {
//     return top == -1;
// }

// // Checks if the stack is full
// bool Stack::full() const {
//     return top == STACK_SIZE - 1;
// }



//!________________________________________________________________________
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor (default size is 2)
Stack::Stack(int capacity) : STACK_SIZE(capacity) {
    initialize();
    if (capacity > 0) {
        stackArray = new Element[STACK_SIZE];
    }
}

// Copy constructor
Stack::Stack(const Stack& other) : STACK_SIZE(other.STACK_SIZE) {
    initialize();
    stackArray = new Element[other.STACK_SIZE];
    top = other.top;
    for (int i = 0; i <= top; ++i) {
        stackArray[i] = other.stackArray[i];
    }
}

// Destructor
Stack::~Stack() {
    delete[] stackArray;
}

// Initialize stack to empty
void Stack::initialize() {
    stackArray = nullptr;
    top = -1;
}

// Add element to top
// Push element onto the stack
void Stack::push(const Element& element) {
    if (top == STACK_SIZE - 1) {
        resize();
    }
    stackArray[++top] = element;
    // if (full()) {
    //     std::cout << "Warning: Stack is full. Cannot push element." << std::endl;
    //     return;
}

// Remove element from top
Element Stack::pop() {
    // if (empty()) {
    //     std::cout << "Warning: Stack is empty. Cannot pop element." << std::endl;
    //     return;
    // }
    // --top;
    if (empty()) {
        throw std::runtime_error("Stack is empty. Cannot pop.");
    }
    return stackArray[top--];
}

// Access top element
Element Stack::peek() const {
    // if (empty()) {
    //     std::cout << "Warning: Stack is empty. Cannot peek." << std::endl;
    //     return "";
    // }
        if (empty()) {
        throw std::runtime_error("Stack is empty. Cannot peek.");
    }
    return stackArray[top];
}

// Display stack contents
void Stack::view() const {
    // for (int i = top; i >= 0; --i) {
    //     std::cout << stackArray[i] << std::endl;
    // }
    if (empty()) {
        cout << "TOP -> BOTTOM // Output for an empty Stack instance" << endl;
    } else {
        cout << "TOP -> ";
        for (int i = top; i >= 0; --i) {
            cout << stackArray[i];
            if (i > 0) {
                cout << " -> ";
            } else {
                cout << " -> BOTTOM // Output for a populated Stack instance" << endl;
            }
        }
    }
}

// Resize the stack array when it's full
void Stack::resize() {
    int newCapacity = STACK_SIZE * 2; // Double the capacity
    Element* newStack = new Element[newCapacity];
    
    for (int i = 0; i <= top; ++i) {
        newStack[i] = stackArray[i];
    }

    delete[] stackArray; // Deallocate the old array
    stackArray = newStack;
    STACK_SIZE = newCapacity;
}

// Build a separate duplicate copy of the existing stack
Stack Stack::copy() const {
    Stack copiedStack(STACK_SIZE);
    for (int i = top; i >= 0; --i) {
        copiedStack.push(stackArray[i]);
    }
    return copiedStack;
}

// Remove all elements from the stack
void Stack::destroy() {
    while (!empty()) {
        pop();
    }
}

// Checks if the stack is empty
bool Stack::empty() const {
    return top == -1;
}

// Checks if the stack is full
bool Stack::full() const {
    return top == STACK_SIZE - 1;
}