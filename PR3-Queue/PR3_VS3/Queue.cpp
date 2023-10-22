/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment 3 - Queue                           *** 
*** DUE DATE : 10-18-23                                         *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/

/* Description:
The program is an implementation of a Queue data structure in C++. It is written to match the expectations of the instructor after seeing the results of the last program assignment.
- It includes a default constructor, copy constructor, destructor, enqueue, dequeue, view, isEmpty, and isFull functions. 
- The Queue is implemented using a dynamic array and circular indexing.
- The copy constructor uses a temporary queue to copy elements from the original queue to the new queue. 
- The view function prints the elements of the queue from head to tail. 
- The isEmpty and isFull functions check if the queue is empty or full, respectively.
*/

#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

//!Default Constructor (default size is 3)
/*********************************************************************
*** FUNCTION Queue (Default Constructor) ***
*********************************************************************
*** DESCRIPTION : Class constructor to create a queue with default or given capacity ***
*** INPUT ARGS : int size - queue capacity ***
*** RETURN : None ***
*********************************************************************/
// Queue::Queue(int size) : QUEUE_SIZE(size), head(0), tail(0) {
//     queueArray = new Element[QUEUE_SIZE]; // Allocate dynamic array
// }
Queue::Queue(int size) : QUEUE_SIZE(size), head(-1), tail(-1) {
    queueArray = new (nothrow) Element[QUEUE_SIZE];  // Dynamic memory allocation with new (nothrow)
    if (!queueArray) {
        cerr << "Memory allocation failed." << endl;
        exit(1);
    }
}

// Queue::Queue(int size) : QUEUE_SIZE(size), head(0), tail(0) {
//     queueArray = new (nothrow) Element[QUEUE_SIZE];  // Dynamic memory allocation with new (nothrow)
//     if (!queueArray) {
//         cerr << "Memory allocation failed." << endl;
//         exit(1);
//     }
// }



//!Copy Constructor
/*********************************************************************
*** FUNCTION Queue (Copy Constructor) ***
*********************************************************************
*** DESCRIPTION : Class copy constructor to create a new queue as a copy of an existing queue ***
*** INPUT ARGS : Queue &other - The queue to be copied ***
*** RETURN : None ***
*********************************************************************/
// Version 1 - Working well
// Queue::Queue( Queue & other) : QUEUE_SIZE (other.QUEUE_SIZE) { //gotten from last assignment
//     queueArray = new Element[QUEUE_SIZE]; // Allocate dynamic array
//     // Copy elements from the other queue
//     for (int i = 0; i < QUEUE_SIZE; ++i) {
//         queueArray[i] = other.queueArray[i];
//     }
// }

// Version 2, working well
// Queue::Queue(Queue &other) : QUEUE_SIZE(other.QUEUE_SIZE), head(other.head), tail(other.tail) {
//     queueArray = new Element[QUEUE_SIZE];
//     // Copy elements
//     for (short i = head; i != tail; i = (i + 1) % QUEUE_SIZE) {
//         enqueue(other.queueArray[i]);
//     }
// }

////Version 4 - Working now
//Copy constructor - Made sure this followed the instructors pseudocode in the Queue lecture slides
// Copy constructor

// Queue::Queue(Queue& other) : QUEUE_SIZE(other.QUEUE_SIZE), head(0), tail(0) {
//     queueArray = new Element[QUEUE_SIZE];
//     Queue tempQueue(QUEUE_SIZE); // Temporary Queue

//     // Copy elements from the original queue to the temporary queue
//     for (short i = other.head; i != other.tail; i = (i + 1) % other.QUEUE_SIZE) {
//         Element QueueElement = other.queueArray[i];
//         tempQueue.enqueue(QueueElement); // Temporary Queue
//     }

//     // Copy elements back to the new queue
//     for (short i = tempQueue.head; i != tempQueue.tail; i = (i + 1) % tempQueue.QUEUE_SIZE) {
//         Element QueueElement = tempQueue.queueArray[i];
//         enqueue(QueueElement); // New Queue
//     }
// }

Queue::Queue(Queue& other) : QUEUE_SIZE(other.QUEUE_SIZE), head(-1), tail(-1) {
    queueArray = new Element[QUEUE_SIZE];
    Queue tempQueue(QUEUE_SIZE); // Temporary Queue

    // Copy elements from the original queue to the temporary queue
    for (short i = other.head; i != other.tail; i = (i + 1) % other.QUEUE_SIZE) {
        Element QueueElement = other.queueArray[i];
        tempQueue.enqueue(QueueElement); // Temporary Queue
    }

    // Copy elements back to the new queue
    for (short i = tempQueue.head; i != tempQueue.tail; i = (i + 1) % tempQueue.QUEUE_SIZE) {
        Element QueueElement = tempQueue.queueArray[i];
        enqueue(QueueElement); // New Queue
    }
}


//!Destructor
/*********************************************************************
*** FUNCTION ~Queue (Destructor) ***
*********************************************************************
*** DESCRIPTION : Class destructor to deallocate dynamic array and clean up resources ***
*** INPUT ARGS : None ***
*** RETURN : None ***
*********************************************************************/
Queue::~Queue() {
    //pop off all the items in the queue
    Element temp;
    while (!isEmpty()) {
        dequeue(temp);
    }
    delete[] queueArray;   // Deallocate the dynamic array
    queueArray = nullptr; // Avoid the dangling pointer
}

//! Enqueue
/*********************************************************************
*** FUNCTION enqueue ***
*********************************************************************
*** DESCRIPTION : Adds an element to the tail of the queue ***
*** INPUT ARGS : const Element item - The item to be added ***
*** RETURN : None ***
*********************************************************************/
void Queue::enqueue (const Element item){
    if (!isFull()){ //checking if the queue is full, will go ahead if not full
        tail = (tail + 1) % QUEUE_SIZE; // Update tail index
        queueArray[tail] = item;
    }
    else{
        cout << "Queue is full!"<< endl;
    }
}

//! Dequeue
/*********************************************************************
*** FUNCTION dequeue ***
*********************************************************************
*** DESCRIPTION : Removes an element from the head of the queue and returns it ***
*** INPUT ARGS : Element &stuff - The item to be removed ***
*** RETURN : None ***
*********************************************************************/
void Queue::dequeue(Element &element) {
    if (!isEmpty()) { //checking if the queue is empty, will go ahead if not empty
        head = (head + 1) % QUEUE_SIZE;
        element = queueArray[head];
    } else {
        cout << "Queue is empty!";  // Removed std::
    }
}

//! View
/*********************************************************************
*** FUNCTION view ***
*********************************************************************
*** DESCRIPTION : Displays the elements of the queue from head to tail ***
*** INPUT ARGS : None ***
*** RETURN : None ***
*********************************************************************/
// Version 1 - Working well but may not be what the instructor liked
// void Queue::view() {
//     cout << "HEAD -> "; //print HEAD in front like the assignment project shows
//     while (head != tail) {
//         cout << queueArray[head] << " -> ";
//         head = (head + 1) % QUEUE_SIZE;
//     }
//     for (int i = head; i != tail; i = (i + 1) % QUEUE_SIZE) {
//         cout << queueArray[i] << " -> "; 
//     }
//     cout << "TAIL\n"; //print TAIL behind also like the assignment project shows
// }

void Queue::view() {
    Queue tempQueue(QUEUE_SIZE); // Temporary Queue
    cout << "HEAD -> ";
    while (!isEmpty()) {
        Element QueueElement;
        dequeue(QueueElement); // Viewed Queue
        cout << QueueElement << " -> ";
        tempQueue.enqueue(QueueElement); // Temporary Queue
    }
    while (!tempQueue.isEmpty()) {
        Element QueueElement;
        tempQueue.dequeue(QueueElement); // Temporary Queue
        enqueue(QueueElement); // Viewed Queue
    }
    cout << "TAIL" << endl;
}


//! isEmpty
/*********************************************************************
*** FUNCTION isEmpty ***
*********************************************************************
*** DESCRIPTION : Checks if the queue is empty ***
*** INPUT ARGS : None ***
*** RETURN : bool - True if empty, false otherwise ***
*********************************************************************/
bool Queue::isEmpty() const {
    return head == tail;    // If head and tail are equal, the queue is empty
    //return head == -1 && tail == -1; // If head and tail are -1, the queue is empty
}

//! isFull
/*********************************************************************
*** FUNCTION isFull ***
*********************************************************************
*** DESCRIPTION : Checks if the queue is full ***
*** INPUT ARGS : None ***
*** RETURN : bool - True if full, false otherwise ***
*********************************************************************/
bool Queue::isFull() const {
    return (tail + 1) % QUEUE_SIZE == head; //Found this from stack overflow
}