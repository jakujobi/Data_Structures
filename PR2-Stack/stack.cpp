#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    Stack();    // default constructor
    
    Stack(int capacity);   // constructor with initial capacity

    Stack(const Stack& other);    // copy constructor

    ~Stack();   // destructor
    
    void push(const string& element);   // add an element as a string to the stack