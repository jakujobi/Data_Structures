//!_______________________________________________________________
//Graph.cpp
/********************************************************************
*** NAME : Your Name ***
*** CLASS : CSc 300 ***
*** ASSIGNMENT : 5 ***
*** DUE DATE : 11-29-23 ***
*** INSTRUCTOR : GAMRADT ***
*********************************************************************
*** DESCRIPTION : This implementation file defines the functions for the
*** Graph ADT. It includes methods for graph creation, Dijkstra's algorithm,
*** and other utility functions necessary for managing a graph represented
*** as an adjacency matrix.
********************************************************************/

#include "Graph.h" // Include the Graph header file
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>

using namespace std;

/********************************************************************
*** FUNCTION Graph ***
*********************************************************************
*** DESCRIPTION : Constructs a Graph object by reading data from a file and initializing the graph. ***
*** INPUT ARGS : const string fileName - The name of the file containing graph data ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
Graph::Graph(const string fileName = "data.dat") {
    setGraph(fileName);
}

/********************************************************************
*** FUNCTION ~Graph ***
*********************************************************************
*** DESCRIPTION : Destroys the Graph object and deallocates any dynamic memory. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
Graph::~Graph() {
    // Implementation will go here
}

/********************************************************************
*** FUNCTION dijkstra ***
*********************************************************************
*** DESCRIPTION : Performs Dijkstra's algorithm on the graph to find the shortest path. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Graph::dijkstra(unsigned short startingVertex) {
    // Adjust for 0-based indexing
    startingVertex--;

    // Initialize all distances as infinite and visited array as false
    for (unsigned short i = 0; i < nodeCount; ++i) {
        distance[i] = USHRT_MAX;
        visited[i] = false;
    }

    // Distance of the source vertex from itself is always 0
    distance[startingVertex] = 0;

    for (unsigned short count = 0; count < nodeCount - 1; ++count) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        unsigned short minDistance = USHRT_MAX, u = 0;

        for (unsigned short v = 0; v < nodeCount; ++v) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                u = v;
            }
        }

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update distance value of the adjacent vertices of the picked vertex
        for (unsigned short v = 0; v < nodeCount; ++v) {
            // Update distance[v] only if it's not in visited, there is an edge from u to v,
            // and total weight of path from startingVertex to v through u is smaller than current value of distance[v]
            if (!visited[v] && cost[u][v] != USHRT_MAX && distance[u] + cost[u][v] < distance[v]) {
                distance[v] = distance[u] + cost[u][v];
            }
        }
    }
}


//! Private member functions_____________________________________________________________________________________________________________
//!______________________________________________________________________________________________________________________________________

/********************************************************************
*** FUNCTION setGraph ***
*********************************************************************
*** DESCRIPTION : Initializes the graph using the data contained within the graph file. ***
*** INPUT ARGS : const string fileName - The name of the file containing graph data ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Graph::setGraph(const string& fileName) {
    // ifstream file(fileName);
    
    // if (!file) {
    //     cerr << "Error opening file: " << fileName << endl;
    //     return;
    // }

    // // Read the number of nodes
    // file >> nodeCount;
    // if (nodeCount > GRAPH_LIMIT) {
    //     cerr << "Node count exceeds graph limit." << endl;
    //     return;
    // }

    // // Initialize the cost matrix with USHRT_MAX
    // for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
    //     for (unsigned short j = 0; j < GRAPH_LIMIT; ++j) {
    //         cost[i][j] = USHRT_MAX;
    //     }
    // }

    // // Read the adjacency matrix from the file
    // unsigned short tempCost;
    // for (unsigned short i = 0; i < nodeCount; ++i) {
    //     for (unsigned short j = 0; j < nodeCount; ++j) {
    //         file >> tempCost;
    //         cost[i][j] = (tempCost == 0 && i != j) ? USHRT_MAX : tempCost;
    //     }
    // }

    // file.close();

    ifstream file(fileName);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Error: Unable to open file '" << fileName << "'." << endl;
        throw runtime_error("File open error");
    }

    // Read the number of nodes and validate
    unsigned short nodes;
    file >> nodes;
    if (file.fail()) {
        cerr << "Error: Invalid format for the number of nodes." << endl;
        throw runtime_error("File format error");
    }
    if (nodes > GRAPH_LIMIT) {
        cerr << "Error: Node count exceeds the graph limit." << endl;
        throw runtime_error("Node count exceeds limit");
    }

    // Initialize adjacency matrix
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        for (unsigned short j = 0; j < GRAPH_LIMIT; ++j) {
            cost[i][j] = USHRT_MAX;
        }
    }

    // Read adjacency matrix values
    for (unsigned short i = 0; i < nodes; ++i) {
        for (unsigned short j = 0; j < nodes; ++j) {
            unsigned int weight;
            if (!(file >> weight)) {
                cerr << "Error: Invalid weight value in the graph." << endl;
                throw runtime_error("Invalid weight value");
            }
            cost[i][j] = (weight == 0 && i != j) ? USHRT_MAX : static_cast<unsigned short>(weight);
        }
    }

    file.close();
}


/********************************************************************
*** FUNCTION setVisited ***
*********************************************************************
*** DESCRIPTION : Initializes the set of nodes to all unvisited. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Graph::setVisited() {
    // Implementation will go here
}

/********************************************************************
*** FUNCTION setStart ***
*********************************************************************
*** DESCRIPTION : Prompts the user for the starting node and validates it. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : unsigned short - The validated starting node. ***
********************************************************************/
unsigned short Graph::setStart() const {
    // Implementation will go here
}

/********************************************************************
*** FUNCTION view ***
*********************************************************************
*** DESCRIPTION : Displays the contents of the distance array. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Graph::view() const {
    // Implementation will go here
}

/********************************************************************
*** FUNCTION restart ***
*********************************************************************
*** DESCRIPTION : Prompts the user to see if they wish to run Dijkstra's algorithm again using the same graph. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : bool - True if the user wishes to run the algorithm again, false otherwise. ***
********************************************************************/
bool Graph::restart() const {
    // Implementation will go here
}

// Add other non-exportable functions as needed
