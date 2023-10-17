#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

//!Default Constructor (default size is 3)
Queue::Queue(int size) : QUEUE_SIZE(size), head(0), tail(0) {
    queueArray = new Element[QUEUE_SIZE]; // Allocate dynamic array
}

Queue::Queue( Queue & other) : QUEUE_SIZE (other.QUEUE_SIZE) { //gotten from last assignment
    queueArray = new Element[QUEUE_SIZE]; // Allocate dynamic array
    
    // Copy elements from the other queue
    for (int i = 0; i < QUEUE_SIZE; ++i) {
        queueArray[i] = other.queueArray[i];
    }
}

//!Destructor
Queue::~Queue() {
    delete[] queueArray;    // Deallocate the dynamic array
    queueArray = nullptr; // Avoid the dangling pointer
}

void Queue::enqueue (const Element item){
    if (!isFull()){ //cheching if the queue is full, will go ahead if not full
        queueArray[tail] = item;
        tail = (tail + 1) % QUEUE_SIZE; // Update tail index
    }
    else{
        cout << "Umm...the queue is full!/nWe can't put " << item << " in there."<< endl;
    }
}

void Queue::dequeue(Element &stuff) {
    if (!isEmpty()) { //checking if the queue is empty, will go ahead if not empty
        stuff = queueArray[head];
        head = (head + 1) % QUEUE_SIZE;
    } else {
        cout << "Yikes...The Queue is empty.\nSo, there's nothing to dequeue";  // Removed std::
    }
}

void Queue::view() {
    cout << "HEAD -> "; //print HEAD in front like the assignment project shows
    for (int i = head; i != tail; i = (i + 1) % QUEUE_SIZE) {
        cout << queueArray[i] << " -> "; 
    }
    cout << "TAIL\n"; //print TAIL behind also like the assignment project shows
}

bool Queue::isEmpty() const {
    return head == tail;    // If head and tail are equal, the queue is empty
}

bool Queue::isFull() const {
    return (tail + 1) % QUEUE_SIZE == head; //Found this from stack overflow
}