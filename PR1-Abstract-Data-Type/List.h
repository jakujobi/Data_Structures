// Header Files (.h) 
/******************************************************************** 
*** NAME : JOHN AKUJOBI    *** 
*** CLASS : CSC 300 - DATA STRUCTURES*** 
*** ASSIGNMENT : #############       *** 
*** DUE DATE : ####                                       *** 
*** INSTRUCTOR : GAMRADT *** 
********************************************************************* 
*** DESCRIPTION : <general english description of the abstract data type> *** 
*** <including supporting operations> *** 
********************************************************************/ 

// other preprocessor directives 

// global declarations and definitions – constants, data types, functions
// exportable declarations and definitions – constants, data types 



// Implementation Files (.cpp)
#ifndef _LIST_H // Guard – start
#define _LIST_H

typedef float Element; // typedef <existing type> <new type>
// basic form of generic programming

class List {
  public: // exportable
    // General description of each of the ADT operations/methods/functions – exportable operations only
      List(); // constructor
      List( const List & ); // copy constructor
      ~List(); // destructor
      void add(const Element ); // add an element to the list
      void remove(const Element );  // remove an element from the list
      void view() const;  // view the list
      int size() const; // get the size of the list
      void clear();


  private: // non-exportable
    // No private member documentation – implementation details are hidden/abstracted away
    struct Node;
    typedef Node * NodePtr;

    struct Node {
        Element element;
        NodePtr next;
    };

    NodePtr front;
  };

#endif // Guard – end