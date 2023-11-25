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
#include <climits>  // For USHRT_MAX. Learned about this from Jack

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
    // Initial setup: Initialize arrays
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        distance[i] = USHRT_MAX;   // Initialize all distances as infinite or the maximum value of unsigned short
        visited[i] = false;
        for (unsigned short j = 0; j < GRAPH_LIMIT; ++j) {
            cost[i][j] = USHRT_MAX;
        }
    }

    // Call setGraph to start the graph with data from the file
    try {
        setGraph(fileName);
    } catch (const std::runtime_error& e) {
        // Handle any errors encountered in setGraph, like prof Gramradt mentioned
        cerr << "Error in initializing the graph: " << e.what() << endl;
        // Set the state of the object to indicate unsuccessful initialization
    }   //Learned about this from stackoverflow
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
    // Ummm, does nothing
    // Thats what Dr Gamradt wrote in the project document
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
    //Lets make sure that the starting vertex is valid. Like, its not greater than the number of nodes in the graph
    //Coz if it isn't, its gonna throw an exception
    if (startingVertex >= nodeCount) {
        cerr << "Invalid starting vertex" << endl;
        throw invalid_argument("Invalid starting vertex");
    }


    // Initialize distance and visited arrays
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        distance[i] = USHRT_MAX;
        visited[i] = false;
    }
    distance[startingVertex] = 0;   // Distance of the source vertex from itself is always 0

    // Perform Dijkstra's algorithm and update the distance array
    for (unsigned short i = 0; i < nodeCount - 1; ++i) {
        // Find the vertex with the minimum distance
        unsigned short minDistance = USHRT_MAX, u = 0;
        for (unsigned short v = 0; v < nodeCount; ++v) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update the distance of adjacent vertices of the chosen vertex
        for (unsigned short v = 0; v < nodeCount; ++v) {
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
    // Iterate through each node in the graph
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        visited[i] = false; // Set the visited state of each node to false
    }
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
    unsigned short startNode;
    while (true) {
        cout << "Enter the starting node (0 to " << nodeCount - 1 << "): ";
        cin >> startNode;

        if (cin.fail() || startNode >= nodeCount) {
            cerr << "Invalid input. Please enter a node number between 0 and "
                << nodeCount - 1 << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;   //learned from one of my cs250 code
        }

        break;
    }

    return startNode; // Return the validated starting node
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
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        cout << "Distance[" << i << "] = ";
        if (i == startingNode) {
            cout << "0"; // Distance to the start node itself is always 0
        } else {
            cout << ((distance[i] == USHRT_MAX) ? "65535" : to_string(distance[i]));
            // Display 65535 for unreachable nodes, otherwise display the distance
        }
        cout << endl; // Each distance on a separate line for clarity
    }
}

/********************************************************************
*** FUNCTION restart ***
*********************************************************************
*** DESCRIPTION : Prompts the user to see if they wish to run Dijkstra's algorithm again using the same graph. ***
***               It can only accept 'Y' or 'N' as input. ***
***               It will recursively call itself if the user enters an invalid input.
***               It can't change any members of the class because it is a const function.
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : bool - True if the user wishes to run the algorithm again, false otherwise. ***
********************************************************************/
bool Graph::restart() const {
    char choice;
    cout << "Do you want to run Dijkstra's algorithm again? (Y/N): ";
    cin >> choice;

    // Validate user input
    if (tolower(choice) == 'y') {
        return true; // User wants to run the algorithm again
    } else if (tolower(choice) == 'n') {
        return false; // User does not want to run the algorithm again
    } else {
        cerr << "Invalid input. Please enter 'Y' for yes or 'N' for no." << endl;
        return restart(); // Recursively call restart to handle invalid inputs
    }
}