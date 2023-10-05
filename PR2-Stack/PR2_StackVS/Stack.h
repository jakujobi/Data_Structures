// #ifndef _STACK_H
// #define _STACK_H
// #include <string>
// #include <iostream>
// using namespace std;

// class Stack {
// public:
//     Stack(int capacity = 2);   // default constructor with initial capacity as parameter

//     Stack(const Stack& other);    // copy constructor

//     ~Stack();   // destructor
    
//     void push(const string& element);   // add an element as a string to the stack

//     void pop(); // remove the top element from the stack

//     string peek() const; // return the top element from the stack

//     bool empty() const; // return true if the stack is empty

//     bool full() const; // return true if the stack is full

//     int size() const; // return the number of elements in the stack

//     void view() const; // print the stack

//     Stack copy() const; // return a copy of the stack

//     void destroy(); // deallocate the stack and removes all elements

// private:
//     static const int STACK_SIZE = 2;
    
//     string* stackArray;         // Pointer to dynamic array

//     int top;  // Index of top element

//     void initialize();  // initialize the stack to empty

//     void resize();  // Resize the stack array when it's full

//     int stackSize; // keep track of the number of elements in the stack
// };

// #endif // STACK_H 


//!------------------------------------------
#ifndef _STACK_H
#define _STACK_H
#include <string>
#include <iostream>
using namespace std;

typedef string Element;

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

    void destroy(); // deallocate the stack and removes all elements

private:
    int STACK_SIZE;
    
    Element* stackArray;         // Pointer to dynamic array

    int top;  // Index of top element

    void initialize();  // initialize the stack to empty

    void resize();  // Resize the stack array when it's full

    int stackSize; // keep track of the number of elements in the stack
};

#endif // STACK_H 
