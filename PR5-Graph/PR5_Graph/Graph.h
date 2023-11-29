
//!_______________________________________________________________
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment 5                                   *** 
*** DUE DATE : 11-29-23                                         *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
/********************************************************************* 
*** DESCRIPTION : ***
*** This ADT represents a Graph data structure, which is a collection of vertices and edges.
*** The supported operations are:
***  - Constructor: Creates a new Graph object.
***  - Destructor: Does nothing, but is supposed to destroy the Graph object and frees up memory.
***  - Dijkstra's Algorithm: Finds the shortest path between two vertices in the Graph.
*********************************************************************/

#include <iostream>
#include <string>
#pragma once
using namespace std;


class Graph {
public: 
        /********************************************************************
    *** FUNCTION Graph ***
    *********************************************************************
    *** DESCRIPTION : Constructs a Graph object by reading data from a file and initializing the graph. ***
    *** INPUT ARGS : const string fileName - The name of the file containing graph data ***
    *** OUTPUT ARGS : None ***
    *** IN/OUT ARGS : None ***
    *** RETURN : None ***
    ********************************************************************/
    explicit Graph(const string = "data.dat");

    /********************************************************************
    *** FUNCTION ~Graph ***
    *********************************************************************
    *** DESCRIPTION : Destroys the Graph object and deallocates any dynamic memory. ***
    *** INPUT ARGS : None ***
    *** OUTPUT ARGS : None ***
    *** IN/OUT ARGS : None ***
    *** RETURN : None ***
    ********************************************************************/
    ~Graph();

    /********************************************************************
    *** FUNCTION dijkstra ***
    *********************************************************************
    *** DESCRIPTION : Performs Dijkstra's algorithm on the graph to find the shortest path. ***
    *** INPUT ARGS : None ***
    *** OUTPUT ARGS : None ***
    *** IN/OUT ARGS : None ***
    *** RETURN : None ***
    ********************************************************************/

    void dijkstra();
    
private: 
    
    // No private member documentation – implementation details are hidden/abstracted away
    typedef unsigned short Element;
    enum {GRAPH_LIMIT = 15};
    
    void setGraph(const string); 
    void setVisited();
    unsigned short setStart() const;
    void view() const;
    bool restart() const;

    Element cost[GRAPH_LIMIT][GRAPH_LIMIT];
    Element distance[GRAPH_LIMIT]; 
    bool visited[GRAPH_LIMIT];
    unsigned short nodeCount;

    //Added private functions
    void dijkstraPrivate();    

};

//#endif // _PROJECT_H //! #Change this to the right one
