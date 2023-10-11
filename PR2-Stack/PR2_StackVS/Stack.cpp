/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment #2 - Stack                          *** 
*** DUE DATE : 10-06-23                                         *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
/********************************************************************* 
*** DESCRIPTION : This class implements a stack data structure using a dynamic array.   ***
    It provides stack operations such as:                            ***
        - push: add an element to the top of the stack              ***
        - pop: remove the top element from the stack                ***
        - peek: return the top element from the stack               ***
        - empty: return true if the stack is empty                  ***
        - full: return true if the stack is full                    ***
        - size: return the number of elements in the stack          ***
        - view: print the stack contents, size and capacity         ***
        - copy constructor: create a copy of the stack              ***
        - destructor: deallocate the stack and removes all elements ***
*********************************************************************/
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
    while (!empty()) {
        pop();
    }
    
    delete[] stackArray;
    stackArray = nullptr;
}


//! Initialize stack to empty
/******************************************************************** 
*** FUNCTION Stack::initialize *** 
********************************************************************* 
*** DESCRIPTION : Initializes the stack by setting the stackArray to nullptr and top to -1. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : void *** 
********************************************************************/
void Stack::initialize() {
    stackArray = nullptr;
    top = -1;
}


//! Push element onto the top of the stack
/******************************************************************** 
*** FUNCTION push *** 
********************************************************************* 
*** DESCRIPTION : Adds an element to the top of the stack. If the stack is full, it resizes the stack before adding the element. *** 
*** INPUT ARGS : element (const Element&) - The element to be added to the stack. *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : void *** 
********************************************************************/
void Stack::push(const Element& element) {
    // if (top == STACK_SIZE - 1) {
    //     resize();
    // }
    

    if (full())
    {
        cout << "Warning: Stack is full. Cannot push element." << endl;
        cout << "Would you like to resize the stack?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            resize();
        }
    return;
    }

    stackArray[++top] = element;
}


//! Remove element from top
/******************************************************************** 
*** FUNCTION Stack::pop *** 
********************************************************************* 
*** DESCRIPTION : Removes and returns the top element of the stack. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : Element - The top element of the stack. *** 
********************************************************************/
Element Stack::pop(){
    if (empty()) {
        //cout << "Warning: Stack is empty. Cannot pop." << endl;
        throw runtime_error("Stack is empty. Cannot pop.");
        //return stackArray[top];
        //return 0;
    }
    else {
        return stackArray[top--];
    }
}


//! Access top element
/******************************************************************** 
*** FUNCTION peek *** 
********************************************************************* 
*** DESCRIPTION : Returns the top element of the stack without removing it. If the stack is empty, throws a runtime error. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : Element - The top element of the stack *** 
********************************************************************/
Element Stack::peek() const {
    // if (empty()) {
    //     cout << "Warning: Stack is empty. Cannot peek." << endl;
    //     return "";
    // }
    if (empty()) {
        throw runtime_error ("//OOP! The stack is empty. Cannot peek.");
    }
    return stackArray[top];
}


//! Display stack contents
/******************************************************************** 
*** FUNCTION view *** 
********************************************************************* 
*** DESCRIPTION : Displays the contents of the stack from top to bottom. If the stack is empty, it displays a message indicating that the stack is empty. *** 
*** INPUT ARGS : None   *** 
*** OUTPUT ARGS : None  *** 
*** IN/OUT ARGS : None  *** 
*** RETURN : void       *** 
********************************************************************/
void Stack::view() const {
    // for (int i = top; i >= 0; --i) {
    //     std::cout << stackArray[i] << std::endl;
    // }
    if (empty()) {
        cout << "TOP -> BOTTOM \nThe stack is empty\nThere has to be an element in the stack before it can do the pop operation" << endl;
    } else {
        cout << "TOP -> ";
        for (int i = top; i >= 0; --i) {
            cout << stackArray[i];
            if (i > 0) {
                cout << " -> ";
            } else {
                cout << " -> BOTTOM" << endl;
            }
        }
    }

     // Get the size of the stack
    cout << "Stack size: " << size() << endl;
    cout << "Stack capacity: " << STACK_SIZE << endl;
    cout << endl;
}


//! Resize the stack array when it's full
/********************************************************************
*** FUNCTION resize ***
*** DESCRIPTION : Doubles the capacity of the stack by creating a new array with twice the size of the current array,
        copying the elements from the old array to the new array, deallocating the old array, and updating the stack size. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : void *** ********************************************************************/
void Stack::resize() {
    int newCapacity = STACK_SIZE * 2; // Double the capacity
    Element* newStack = new Element[newCapacity];
    
    for (int i = 0; i <= top; ++i) {
        newStack[i] = stackArray[i];
    }

    delete[] stackArray; // Deallocate the old array
    stackArray = newStack;
    STACK_SIZE = newCapacity;
    cout << "Stack resized to " << STACK_SIZE << endl;
}


//! Build a separate duplicate copy of the existing stack
/******************************************************************** 
*** FUNCTION Stack::copy() *** 
********************************************************************* 
*** DESCRIPTION : This function creates a copy of the current stack object. It creates a new stack object, 
                  copies all the elements of the current stack object to the new stack object, and returns 
                  the new stack object. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : Stack - A new stack object that is a copy of the current stack object. *** 
********************************************************************/
Stack Stack::copy() const {
    Stack copiedStack(STACK_SIZE);
    for (int i = top; i >= 0; --i) {
        copiedStack.push(stackArray[i]);
    }
    return copiedStack;
}

//! Remove all elements from the stack
/******************************************************************** 
*** FUNCTION Stack::destroy *** 
********************************************************************* 
*** DESCRIPTION : This function destroys the stack by popping all elements from the stack and deleting the stack array. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : void *** 
// ********************************************************************/
// void Stack::destroy() { 
//     while (!empty()) {
//         pop();
//     }
//     delete[] stackArray;
//     stackArray = nullptr; // to avoid a dangling pointer
    
// }


//! Checks if the stack is empty
/******************************************************************** 
*** FUNCTION Stack::empty() *** 
********************************************************************* 
*** DESCRIPTION : This function checks if the stack is empty or not. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : bool - Returns true if the stack is empty, false otherwise. *** 
********************************************************************/
bool Stack::empty() const {
    return top == -1;
}


//! Checks if the stack is full
/******************************************************************** 
*** FUNCTION Stack::full() *** 
********************************************************************* 
*** DESCRIPTION : Checks if the stack is full. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : bool - true if the stack is full, false otherwise. *** 
********************************************************************/
bool Stack::full() const {
    return top == STACK_SIZE - 1;
}


//! Returns the number of elements in the stack
/******************************************************************** 
*** FUNCTION Stack::size() *** 
********************************************************************* 
*** DESCRIPTION : Returns the number of elements in the stack *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : int - Number of elements in the stack *** 
********************************************************************/
int Stack::size() const {
    return top + 1; // Number of elements in the stack
}


//Learned that i did not need this function, so i moved its code to the view function
// //! Print the stack
// /******************************************************************** 
// *** FUNCTION Stack::printStack *** 
// ********************************************************************* 
// *** DESCRIPTION : Displays the contents of the stack, its size, and capacity. *** 
// *** INPUT ARGS : None *** 
// *** OUTPUT ARGS : None *** 
// *** IN/OUT ARGS : None *** 
// *** RETURN : void *** 
// ********************************************************************/
// void Stack::printStack() const {
//     // Display the stack contents
//     cout << "Stack contents:" << endl;
//     view();

//      // Get the size of the stack
//     cout << "Stack size: " << size() << endl;
//     cout << "Stack capacity: " << STACK_SIZE << endl;
//     cout << endl;
// }