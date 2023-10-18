
//!________________________________________________
// Driver/main Files (.cpp) 
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment 3 - Queue                           *** 
*** DUE DATE : 10-18-23                                         *** 
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
    //it should show 5, -3

    // // Test Case 4: Test Enqueue on Full Queue
    // cout << "Test Case 4: Test Enqueue on Full Queue\n";
    // defaultQueue.enqueue("6"); // it has a size of 3
    // defaultQueue.enqueue("9"); // It should fail
    // cout << "---------------------------\n";

    cout << "Test Case 5: Dequeue\n";
    Element dequeuedElem;
    defaultQueue.dequeue(dequeuedElem);
    cout << "Dequeued Element: " << dequeuedElem << endl;
    defaultQueue.view();
    cout << "------------------------------------\n";

    cout << "Test Case 6: Destructor\n";
    {
        Queue destructorQueue;
        destructorQueue.enqueue(100);
        destructorQueue.enqueue(200);
    }
    cout << "Destructor ran successfully.\n";
    cout << "------------------------------------\n";

    // cout << "Test Case 7: Test Dequeue on Empty Queue\n";
    // Queue emptyQueue(3);
    // emptyQueue.dequeue(dequeuedElement);
    // cout << "---------------------------\n";

    return 0;
}