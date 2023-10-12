# Documentation Requirements

Owner: John Akujobi
Type: Structure
Created time: September 23, 2023 11:16 AM
Status: Not started

```cpp
Program Documentation Requirements 
Ken Gamradt 
Electrical Engineering and Computer Science 
South Dakota State University 
```

## Main Files (main.cpp)

```cpp
// Driver/main Files (.cpp) 
/******************************************************************** 
*** NAME : JOHN AKUJOBI    *** 
*** CLASS : CSC 300 - DATA STRUCTURES*** 
*** ASSIGNMENT : ######## *** 
*** DUE DATE : ####                                       *** 
*** INSTRUCTOR : GAMRADT *** 
*********************************************************************
*** DESCRIPTION : <detailed english description of the current assignment> *** 
********************************************************************/ 
// preprocessor directives 
// global declarations and definitions – constants, data types, functions 
// main function definition 
/******************************************************************** 
*** FUNCTION <name of function> *** 
********************************************************************* 
*** DESCRIPTION : <detailed english description of the function> *** 
*** INPUT ARGS : <list of all input argument names> *** 
*** OUTPUT ARGS : <list of all output argument names> *** 
*** IN/OUT ARGS : <list of all input/output argument names> *** 
*** RETURN : <return type and return value name> *** 
********************************************************************/ 
ReturnType functionName( <argument declarations> ) 
{ 
// etc… 
} 

//Notes: 
//• readable, self-describing identifier names are required. 
//• a separate function description block is required for each function definition other than main. 
```

## Header Files

```cpp
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
```

## Implementation Files

```cpp
//Implementation Files (.cpp) 
/******************************************************************** 
*** NAME : JOHN AKUJOBI    *** 
*** CLASS : CSC 300 - DATA STRUCTURES*** 
*** ASSIGNMENT :                               *** 
*** DUE DATE : ####                                       *** 
*** INSTRUCTOR : GAMRADT *** 
********************************************************************* 
*** DESCRIPTION : <detailed english description of the abstract data type> *** 
*** <including supporting operations> *** 
********************************************************************/ 

#include “myadt.h” // matching header file 
// other preprocessor directives 
/******************************************************************** 
*** FUNCTION <name of function> *** 
********************************************************************* 
*** DESCRIPTION : <detailed english description of the function> *** 
*** INPUT ARGS : <list of all input argument names> *** 
*** OUTPUT ARGS : <list of all output argument names> *** 
*** IN/OUT ARGS : <list of all input/output argument names> *** 
*** RETURN : <return type and return value name> *** 
********************************************************************/ 
ReturnType MyClass::functionName( <argument declarations> ) 
{ 
// etc… 
} 
//Note: 
//• a separate function description block is required for each function definition.
```
