//!------------------------------------------
#ifndef _STACK_H
#define _STACK_H
#include <string>
#include <iostream>
using namespace std;

typedef string Element;

/********************************************************************
*** CLASS Stack                                                                         ***
*** DESCRIPTION : This class implements a stack data structure using a dynamic array.   ***
                It provides stack operations such as:                                   ***
                - push: add an element to the top of the stack                          ***
                - pop: remove the top element from the stack                            ***
                - peek: return the top element from the stack                           ***
                - empty: return true if the stack is empty                              ***
                - full: return true if the stack is full                                ***
                - size: return the number of elements in the stack                      ***
                - view: print the stack contents, size and capacity                     ***
                - copy constructor: create a copy of the stack                          ***
                - destructor: deallocate the stack and removes all elements             ***
*******************************************************************************************/
class Stack {
public:
    Stack(int capacity = 2);   // default constructor with initial capacity as parameter

    Stack(const Stack& other);    // copy constructor

    ~Stack();   // destructor
    
    void push(const Element& element);   // add an element as a string to the stack

    Element pop(); // remove the top element from the stack

    Element peek() const; // return the top element from the stack

    bool empty() const; // return true if the stack is empty

    bool full() const; // return true if the stack is full

    int size() const; // return the number of elements in the stack

    void view() const; // print the stack

    Stack copy() const; // return a copy of the stack

    //void destroy(); // deallocate the stack and removes all elements

    void printStack() const;
    

private:
    int STACK_SIZE;
    //I tried using a constant for this,
    //but it interfered with the resize function
    //which uses the STACK_SIZE to resize the array
    
    Element* stackArray;         // Pointer to dynamic array

    int top;  // Index of top element

    void initialize();  // initialize the stack to empty

    void resize();  // Resize the stack array when it's full

    int stackSize; // keep track of the number of elements in the stack
};

#endif // STACK_H 
