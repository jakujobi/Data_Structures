
//!_______________________________________________________________
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment //!# - ###############              *** 
*** DUE DATE : //!                                               *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
/********************************************************************* 
*** DESCRIPTION : ///**
*** This ADT represents a Graph data structure, which is a collection of vertices and edges.
*** The supported operations are:
***  - Constructor: Creates a new Graph object.
***  - Destructor: Destroys the Graph object and frees up memory.
***  - Dijkstra's Algorithm: Finds the shortest path between two vertices in the Graph.
*********************************************************************/

#include <iostream>
#include <string>
#pragma once

using namespace std;
/*
General description of the ADT and supported operations – exportable operations only
*/

class Graph {
public: 
    // exportable
    
    // General description of each of the ADT operations/functions – exportable operations only
    explicit Graph(const string = "data.dat");
    ~Graph();
    void dijkstra();
    
private: 
    // non-exportable
    
    // No private member documentation – implementation details are hidden/abstracted away
    typedef unsigned short Element;
    enum {GRAPH_LIMIT = 15};
    
    Graph(const Graph &) = delete;
    void setGraph(const string); 
    void setVisited();
    unsigned short setStart() const;
    void view() const;
    bool restart() const;
    
    Element cost[GRAPH_LIMIT][GRAPH_LIMIT];
    Element distance[GRAPH_LIMIT]; 
    bool visited[GRAPH_LIMIT];
    unsigned short nodeCount;
};

#endif // _PROJECT_H //! #Change this to the right one
