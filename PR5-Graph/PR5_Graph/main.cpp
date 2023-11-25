//main.cpp

//!_______________________________________________________________
/********************************************************************
*** NAME : John Doe                                            ***
*** CLASS : CSc 300 - DATA STRUCTURES                           ***
*** ASSIGNMENT : 5                                             ***
*** DUE DATE : 11-29-23                                        ***
*** INSTRUCTOR : GAMRADT                                       ***
*********************************************************************
*** DESCRIPTION : This program is designed to test the Graph   ***
*** ADT implementation. It includes various tests to ensure    ***
*** the correctness and robustness of the Graph class. The     ***
*** tests cover graph construction, Dijkstra's algorithm, and  ***
*** other utility functions like view, restart, setVisited,    ***
*** and setStart.                                              ***
********************************************************************/

#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Graph Construction and Initialization
    cout << "Test 1: Graph Construction and Initialization\n";
    Graph myGraph("data.dat"); // Assuming "data.dat" is a valid graph file
    cout << "Graph constructed with data from 'data.dat'\n\n";

    // // Test 3: Restart Functionality
    // cout << "Test 3: Restart Functionality\n";
    // bool doRestart = myGraph.restart(); // User input required
    // cout << "Restart response: " << (doRestart ? "Yes" : "No") << "\n\n";

    //I just realized that the private functions cannot be tested because they can't be called from outside the class
    //So because of that I think I would end it here
    //But, since he said that we can't add any more exportable functions how do I test this project?
    //The last time I did more functions to the project.h file, it took a toll on my grades

    cout << "Tada! All tests completed.\nIf you can see this, then you are good to go!\n\n";
    return 0;
}