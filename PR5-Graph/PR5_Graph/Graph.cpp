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
    graphPrivateConstructor(fileName);
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
void Graph::dijkstra() {
    // Call dijkstraPrivate with the starting vertex as 0
    dijkstraPrivate();
}




//! Private member functions_____________________________________________________________________________________________________________
//!______________________________________________________________________________________________________________________________________

/********************************************************************
*** FUNCTION graphPrivateConstructor ***
*********************************************************************
*** DESCRIPTION : Initializes the Graph object. This function is ***
*** called by the Graph constructor to set up the initial state  ***
*** of the Graph object, including initializing arrays and       ***
*** loading graph data from a file.                              ***
*** INPUT ARGS : const string& fileName - The name of the file   ***
*** containing graph data.                                       ***
*** OUTPUT ARGS : None                                           ***
*** IN/OUT ARGS : None                                           ***
*** RETURN : None                                                ***
********************************************************************/
void Graph::graphPrivateConstructor(const string& fileName) {
    // Initialize member variables, such as setting all distances to USHRT_MAX
    // and all visited flags to false
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        distance[i] = USHRT_MAX;
        visited[i] = false;
        for (unsigned short j = 0; j < GRAPH_LIMIT; ++j) {
            cost[i][j] = USHRT_MAX;
        }
    }

    // Call setGraph to initialize the graph with data from the file
    setGraph(fileName);
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
void Graph::dijkstraPrivate(unsigned short startingVertex = 0) {
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

/********************************************************************
*** FUNCTION setGraph ***
*********************************************************************
*** DESCRIPTION : Initializes the graph using the data contained within the graph file. ***
*** INPUT ARGS : const string fileName - The name of the file containing graph data ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Graph::setGraph(const string fileName = "data.dat") {
    ifstream file(fileName);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Error: Unable to open file '" << fileName << "'." << endl;
        throw runtime_error("File open error");
    }

    // Read the number of nodes and validate
    file >> nodeCount;
    if (file.fail()) {
        cerr << "Error: Invalid format for the number of nodes." << endl;
        throw runtime_error("File format error");
    }
    if (nodeCount > GRAPH_LIMIT) {
        cerr << "Error: Node count exceeds the graph limit." << endl;
        throw runtime_error("Node count exceeds limit");
    }

    // Initialize adjacency matrix
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        for (unsigned short j = 0; j < GRAPH_LIMIT; ++j) {
            cost[i][j] = (i == j) ? 0 : USHRT_MAX;
        }
    }

    // Read adjacency matrix values
    for (unsigned short i = 0; i < nodeCount; ++i) {
        for (unsigned short j = 0; j < nodeCount; ++j) {
            unsigned short weight;
            if (!(file >> weight)) {
                cerr << "Error: Invalid weight value in the graph." << endl;
                throw runtime_error("Invalid weight value");
            }
            cost[i][j] = weight;
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
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore();
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
    // Ensure that the function only reads from the Graph object and doesn't modify its state

    cout << "Shortest path distances from the start node:" << endl;
    for (unsigned short i = 0; i < GRAPH_LIMIT; ++i) {
        cout << "Distance[" << i << "] = ";
        if (distance[i] == USHRT_MAX) {
            cout << "Infinity"; // No path to this node or distance is not calculated
        } else {
            cout << distance[i]; // Display the calculated shortest path distance
        }
        cout << endl;
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