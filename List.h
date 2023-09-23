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
#ifndef _MYADT_H // myadt.h 
#define _MYADT_H 
// other preprocessor directives 
// exportable declarations and definitions – constants, data types 
class MyClass 
{ 
 public: // exportable
/******************************************************************** 
*** FUNCTION <name of function> *** 
********************************************************************* 
*** DESCRIPTION : <general english description of the function> *** 
*** INPUT ARGS : <list of all input arguments> *** 
*** OUTPUT ARGS : <list of all output arguments> *** 
*** IN/OUT ARGS : <list of all input/output arguments> *** 
*** RETURN : <return type and return value> *** 
********************************************************************/ 
ReturnType exportableFunction( <argument declarations> ); 
 private: // non-exportable
// No Documentation 
 ReturnType nonExportableFunction( <argument declarations> ); 
 // all other non-exportable members – constants, types, data 
}; 
#endif 
//Note: 
//• a separate function description block is required for each exportable function declaration. 

#ifndef _LIST_H // Guard – start
#define _LIST_H

typedef float Element; // typedef <existing type> <new type>
// basic form of generic programming

class List {
public: // exportable
  // General description of each of the ADT operations/methods/functions – exportable operations only
    List();
    List( const List & ); // reuse add
    ~List();
    void add(const Element );
    void remove(const Element );
    void view() const;

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