
//!________________________________________________
// Driver/main Files (.cpp) 
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment #2 - Stack Testing                  *** 
*** DUE DATE : 10-06-23                                         *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/

//Description: This program tests the Queue class.
/*
Test Cases Included:
Default Constructor and Enqueue:
	Creates a queue using the default constructor and enqueues some elements.
Parameterized Constructor:
	Creates a queue using a parameterized constructor with a user-specified size.
Copy Constructor:
	Creates a copy of an existing queue.
Dequeue:
	Dequeues an element and shows the dequeued element.
Destructor:
	Tests the destructor by creating a queue in a local scope
*/

#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Test Case 1: Default Constructor and Enqueue\n";
    Queue defaultQueue;
    defaultQueue.enqueue(5);	// Enqueue elements that were shown in the assignment document
    defaultQueue.enqueue(-3);
    defaultQueue.view();
    cout << "------------------------------------\n";

    cout << "Test Case 2: Parameterized Constructor\n";
    Queue paramQueue(5);
    paramQueue.enqueue(10);	// Enqueue some elements
    paramQueue.enqueue(20);
    paramQueue.view();
    cout << "------------------------------------\n";

    cout << "Test Case 3: Copy Constructor\n";
    Queue copyQueue = defaultQueue;
    copyQueue.view();
    cout << "------------------------------------\n";

    cout << "Test Case 4: Dequeue\n";
    Element dequeuedElem;
    defaultQueue.dequeue(dequeuedElem);
    cout << "Dequeued Element: " << dequeuedElem << endl;
    defaultQueue.view();
    cout << "------------------------------------\n";

    cout << "Test Case 5: Destructor\n";
    {
        Queue destructorQueue;
        destructorQueue.enqueue(100);
        destructorQueue.enqueue(200);
    }
    cout << "Destructor ran successfully.\n";
    cout << "------------------------------------\n";

    return 0;
}