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

#include "List.h" // matching header file 
#include <iostream> // for cout
using namespace std;

/******************************************************************** 
*** FUNCTION List::List *** 
********************************************************************* 
*** DESCRIPTION : This is the constructor for the List class. It initializes the head pointer to NULL. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : None *** 
********************************************************************/ 
List::List() {
  front = nullptr;
}


/*******************************************************
 * *** FUNCTION List::List(const List &other) ***

*** DESCRIPTION : Constructor for the List class that creates a new List object as a copy of another List object.
                It initializes the front pointer to null and then iterates through the other List object, adding each element to the new List object. ***
*** INPUT ARGS : other (const List&) - the List object to be copied ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
******************************************************/
List::List(const List &other) {
    front = nullptr;
    NodePtr current = other.front;
    while (current != nullptr) {
        add(current->element);
        current = current->next;
    }
}

/******************************************************************** 
*** FUNCTION List::~List *** 
********************************************************************* 
*** DESCRIPTION : This is the destructor for the List class. It deallocates all the nodes in the linked list. *** 
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : None *** 
********************************************************************/ 
List::~List() {
    while (front != nullptr) {
        NodePtr temp = front;
        front = front->next;
        delete temp;
    }
}


/******************************************************************** 
*** FUNCTION List::insert *** 
********************************************************************* 
*** DESCRIPTION : This function inserts a new node with the given value at the beginning of the linked list.    *** 
*** INPUT ARGS : element (int) - the value to be inserted                                                         *** 
*** OUTPUT ARGS : None                                                                                          *** 
*** IN/OUT ARGS : None                                                                                          *** 
*** RETURN : None                                                                                               *** 
********************************************************************/ 
void List::add(const Element e) {

    int initialCount = List::size();    //check the initial size of the list

    NodePtr newNode = new Node;
    newNode->element = e;
    newNode->next = front;
    front = newNode;

    int endCount = List::size();
    
    //This is to check if the element was successfully added to the list
    //if (front->element == e) {
    //if (endCount == initialCount+1) {
    if (endCount > initialCount) { //check if the final list size is larger than the initial
        cout << "Addition Successful" << endl;
    }
    else {
        cout << "Error: Allocation addition failed" << endl;
       // deallocate the node that failed to be added
       // delete newNode;
    }
    //*/
}


/******************************************************************** 
*** FUNCTION List::remove *** 
********************************************************************* 
*** DESCRIPTION : This function removes the first node in the linked list with the given value. *** 
*** INPUT ARGS : element (int) - the value to be removed                                          *** 
*** OUTPUT ARGS : None                                                                          *** 
*** IN/OUT ARGS : None                                                                          *** 
*** RETURN : None                                                                               *** 
********************************************************************/ 
void List::remove(const Element e) {
    NodePtr current = front;
    NodePtr previous = nullptr;
    while (current != nullptr && current->element != e) {
        previous = current;
        current = current->next;
    }
    if (current != nullptr) {
        if (previous == nullptr) {
            front = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }
}

/******************************************************************** 
*** FUNCTION List::view *** 
********************************************************************* 
*** DESCRIPTION : This function prints the values of all the nodes in the linked list.  *** 
*** INPUT ARGS : None                                                                   *** 
*** OUTPUT ARGS : None                                                                  *** 
*** IN/OUT ARGS : None                                                                  *** 
*** RETURN : None                                                                       *** 
********************************************************************/ 
void List::view() const {
    NodePtr current = front;
    while (current != nullptr) {
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
}

/******************************************************************** 
*** FUNCTION List::size *** 
********************************************************************* 
*** DESCRIPTION : This function returns the number of elements in the linked list. *** 
***                I used this function to test my implementation of the List class. ***
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : int - the number of elements in the linked list *** 
********************************************************************/ 
int List::size() const {
    int count = 0;
    NodePtr current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

/******************************************************************** 
*** FUNCTION List::clear *** 
********************************************************************* 
*** DESCRIPTION : This function deallocates all the nodes in the linked list. *** 
***                I used this function to test my implementation of the List class. ***
*** INPUT ARGS : None *** 
*** OUTPUT ARGS : None *** 
*** IN/OUT ARGS : None *** 
*** RETURN : None *** 
********************************************************************/ 
void List::clear() {
    NodePtr current = front;
    while (current != nullptr) {
        NodePtr temp = current;
        current = current->next;
        delete temp;
    }
    front = nullptr;
}
