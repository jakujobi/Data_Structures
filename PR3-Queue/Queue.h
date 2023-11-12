/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment 3 - Queue                           *** 
*** DUE DATE : 10-18-23                                         *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/

/* Description:
This code is for a Queue class with several member functions,
including enqueue, dequeue, and view, which are used to add elements to the queue, remove elements from the queue, and view the contents of the queue, respectively.
It was written by Ken Gamradt in the Assignment 3 project document
*/

#ifndef _QUEUE_H // Guard
#define _QUEUE_H

typedef int Element;
typedef Element * ElementPtr;

class Queue {
    public:     // exportable
        // General description of each of the ADT operations/functions – exportable operations only
        explicit Queue(int size = 3);        // replace … with required arguments
        Queue( Queue & );       // reuse enqueue & dequeue
        ~Queue();      // reuse dequeue
        void enqueue( const Element );
        void dequeue( Element & );
        void view(); // reuse enqueue & dequeue
        
    private: // non-exportable
        // No private member documentation – implementation details are hidden/abstracted away
        const short QUEUE_SIZE; // requires initialization
        ElementPtr queueArray;
        short head, tail;
        bool isEmpty() const;
        bool isFull() const;
};
#endif // Guard