#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    Stack();    // default constructor
    
    Stack(int capacity);   // constructor with initial capacity as parameter

    Stack(const Stack& other);    // copy constructor

    ~Stack();   // destructor
    
    void push(const string& element);   // add an element as a string to the stack

    void pop(); // remove the top element from the stack

    string peek() const; // return the top element from the stack

    bool empty() const; // return true if the stack is empty

    bool full() const; // return true if the stack is full

    int size() const; // return the number of elements in the stack

    void view() const; // print the stack

    Stack copy() const; // return a copy of the stack

    void destroy(); // deallocate the stack and removes all elements

private:
    static const int STACK_SIZE = 2;
    
    string* stackArray;         // Pointer to dynamic array

    int top;                         // Index of top element

    void initialize();  // initialize the stack to empty

    void resize();  // Resize the stack array when it's full
};

#endif // STACK_H 