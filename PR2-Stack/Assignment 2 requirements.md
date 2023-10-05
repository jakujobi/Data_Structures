# CSc 300 Assignment 2 - Stack ADT

## Overview

The goal of this assignment is to create a user-defined abstract data type (ADT) called `Stack` in C++.

The `Stack` ADT should be implemented as a dynamically allocated array using pointers. It should store elements of type `string`.

The public interface (exported components) of the `Stack` consists of:

* Default constructor
* Parameterized constructor
* Copy constructor
* Destructor
* `push()` - add element to top
  * checks if the stack if full by using full()
  * if it is full, it sends the user a warning message
* `pop()` - remove element from top
  * checks if the stack is empty using empty()
  * if it is empty, send a warning message to the user
* `peek()` - access top element
  * make sure this does not modify the stack
* `view()` - display stack contents
* `copy()` - builds a separate duplicate copy of the existing stack
* `destroy()` - removes all elements from the stack
* `empty()` - checks if the stock is empty
* `full()` checks if the stock is full
* `view()` from top to bottom used for testing and debugging purpose

The private components (storage) consists of:

* `STACK_SIZE` - initial capacity
* `stackArray` - pointer to dynamic array
* `top` - index of top element
* `initialize ` - initializes a stack to empty

## Implementation Details

* Use separate `.h` and `.cpp` files for interface and implementation.
* Document public methods in `.h`, private details in `.cpp`.
* Initialize rather than assign where possible.
* Reuse `push()` and `pop()` in other methods like copy constructor.
* Output stack contents from top to bottom.
* Guard header file with include guards.

## Submission

* Use folder `Lastname2`
* Include `Stack.h`, `Stack.cpp`, `main.cpp`, `Makefile`
* Submit to GitHub and share repo link
* Email with subject line format

## Constructor Implementation

* The default constructor should initialize a stack with capacity 2.
* The parameterized constructor should take a size parameter and initialize a stack of that capacity.
* These can be merged into one constructor with a default capacity value of 2 if no size is specified.

## Copy Constructor

* The copy constructor should create a deep copy of the stack by dynamically allocating a new array.
* It should copy over the elements by pushing them onto the new stack, reusing the `push()` method.

## Destructor

* The destructor should free the dynamically allocated memory.
* It can reuse the `pop()` method to remove all elements before deleting the array.

## Stack Operations

* `push()` takes an element as a parameter and inserts it at the top. It should resize the array if needed.
* `pop()` removes and returns the top element. It should shrink the array if needed.
* `peek()` returns the top element without modification using `pop()` and `push()`.
* `view()` prints the stack contents top to bottom using `pop()` and `push()` to leave the stack unchanged.

## Documentation

* The `.h` file documents the public interface only. No implementation details.
* The `.cpp` file provides implementation details through comments.
