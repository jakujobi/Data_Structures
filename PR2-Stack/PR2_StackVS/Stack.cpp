//!________________________________________________________________________
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

//! Constructor (default size is 2)
/*********************************************************************
*** FUNCTION Stack ***
*********************************************************************
*** DESCRIPTION : Class constructor to create a stack with default or given capacity ***
*** INPUT ARGS : int capacity - stack capacity ***
*** RETURN : None ***
*********************************************************************/
Stack::Stack(int capacity) : STACK_SIZE(capacity) {
    initialize();
    if (capacity > 0) {
        stackArray = new Element[STACK_SIZE];
    }
}

//! Copy constructor
/******************************************************************** 
*** FUNCTION Stack::Stack(const Stack& other) *** 
********************************************************************* 
*** DESCRIPTION : Copy constructor for the Stack class. Initializes a new Stack object with the same size as the input Stack object, and copies over all elements from the input Stack object to the new Stack object. *** 
*** INPUT ARGS : other (const Stack&) - The Stack object to be copied. *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : None *** 
********************************************************************/
Stack::Stack(const Stack& other) : STACK_SIZE(other.STACK_SIZE) {
    initialize();
    stackArray = new Element[other.STACK_SIZE];
    top = other.top;
    for (int i = 0; i <= top; ++i) {
        stackArray[i] = other.stackArray[i];
    }
}


//! Destructor
/******************************************************************** 
*** FUNCTION Stack::~Stack() *** 
********************************************************************* 
*** DESCRIPTION : Destructor for the Stack class. Deletes the stackArray and sets it to nullptr. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : None *** 
********************************************************************/
Stack::~Stack() {
    delete[] stackArray;
    stackArray = nullptr;
}


//! Initialize stack to empty
void Stack::initialize() {
    stackArray = nullptr;
    top = -1;
}

//! Push element onto the top of the stack
void Stack::push(const Element& element) {
    if (top == STACK_SIZE - 1) {
        resize();
    }
    stackArray[++top] = element;
    // if (full()) {
    //     std::cout << "Warning: Stack is full. Cannot push element." << std::endl;
    //     return;
}

//! Remove element from top
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

//! Access top element
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

//! Display stack contents
/******************************************************************** 
*** FUNCTION view *** 
********************************************************************* 
*** DESCRIPTION : Displays the contents of the stack from top to bottom. If the stack is empty, it displays a message indicating that the stack is empty. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : void *** 
********************************************************************/
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

//! Resize the stack array when it's full
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

//! Build a separate duplicate copy of the existing stack
Stack Stack::copy() const {
    Stack copiedStack(STACK_SIZE);
    for (int i = top; i >= 0; --i) {
        copiedStack.push(stackArray[i]);
    }
    return copiedStack;
}

//! Remove all elements from the stack
void Stack::destroy() { 
    while (!empty()) {
        pop();
    }
    delete[] stackArray;
    stackArray = nullptr; // to avoid a dangling pointer
    
}

//! Checks if the stack is empty
bool Stack::empty() const {
    return top == -1;
}

//! Checks if the stack is full
bool Stack::full() const {
    return top == STACK_SIZE - 1;
}

//! Returns the number of elements in the stack
int Stack::size() const {
    return top + 1; // Number of elements in the stack
}


//! Print the stack
void Stack::printStack() const {
    // Display the stack contents
    cout << "Stack contents:" << endl;
    view();

     // Get the size of the stack
    cout << "Stack size: " << size() << endl;
    cout << "Stack capacity: " << STACK_SIZE << endl;
    cout << endl;
}