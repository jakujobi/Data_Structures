// Driver/main Files (.cpp) 
/********************************************************************
*** NAME : JOHN AKUJOBI                                           ***
*** CLASS : CSC 300 - DATA STRUCTURES                             ***
*** ASSIGNMENT : 1                                                ***
*** DUE DATE : 09-25-23                                           ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This program implements a List ADT in C++ using a linked list structure. The List supports core operations like add, remove, and traverse with proper encapsulation and abstraction. ***
********************************************************************/


// global declarations and definitions � constants, data types, functions 
// main function definition 

// Implementation Files (.cpp)
#include "List.h"
//#include "List.cpp"

// preprocessor directives 
#include <iostream>

using namespace std;

int main() {
    List myList;    // create a list object

    // print the list
    cout << "List contents: "; 
    myList.view();
    cout << endl;

    myList.add(5);  // add some elements to the list
    // print the list
    cout << "List contents after adding 5: ";
    myList.view();
    cout << "List size: " << myList.size() << endl;
    cout << endl;


    myList.add(10); // add 10 elements to the list
    // print the list
    cout << "List contents after adding 10: ";
    myList.view();
    cout << "List size: " << myList.size() << endl;
    cout << endl;



    myList.add(15);
    // print the list
    cout << "List contents after adding 15: ";
    myList.view();
    cout << "List size: " << myList.size() << endl; // check the size of the list
    cout << endl;

    // remove an element from the list
    myList.remove(10);
    // print the list again
    cout << "List contents after removing 10: ";
    myList.view();

    // get the size of the list
    cout << "List size: " << myList.size() << endl;
    // I added this to easily check the size of the list and to confirm that the remove function works
    cout << endl;

    // clear the list
    myList.clear();
    // I added this to easily reset the list and clear it up for the next test

    // print the list again
    cout << "List contents after clearing: ";
    myList.view();

    // get the size of the list again
    cout << "List size after clearing: " << myList.size() << endl;
    cout << endl;

    return 0;
}


