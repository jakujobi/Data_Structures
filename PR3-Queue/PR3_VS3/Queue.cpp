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