# Data Structures - Educational C++ Implementations

A comprehensive collection of classic data structure implementations in C++ and Python, created as coursework for CSC 300 - Data Structures at South Dakota State University. This repository demonstrates foundational computer science concepts through well-documented, working implementations.

## Overview

This repository contains six programming assignments (PR1-PR6), each implementing a fundamental data structure or algorithm with complete documentation, test cases, and working examples. All C++ code follows strict documentation standards and is verified to compile and run successfully.

## Key Features

- **Linked List ADT** ([PR1-Abstract-Data-Type/](PR1-Abstract-Data-Type/)) - Generic linked list with add, remove, view, and clear operations
- **Stack (Dynamic Array)** ([PR2-Stack/](PR2-Stack/)) - Dynamic array-based stack with automatic resizing
- **Queue (Circular Array)** ([PR3-Queue/](PR3-Queue/)) - Circular array-based queue implementation
- **Binary Search Tree** ([PR4-BST/PR4_BST/](PR4-BST/PR4_BST/)) - BST with insert, remove, search, and three traversal methods (preorder, inorder, postorder)
- **Graph with Dijkstra's Algorithm** ([PR5-Graph/PR5_Graph/](PR5-Graph/PR5_Graph/)) - Graph ADT implementing Dijkstra's shortest path algorithm
- **Sorting Algorithms** ([PR6-Sorting Numbers/](PR6-Sorting%20Numbers/)) - Merge sort implementation in Python with verbose output

## Architecture Overview

The repository follows a consistent structure across all projects:

```
Data_Structures/
├── PR1-Abstract-Data-Type/     # Linked List implementation
│   ├── List.h                  # Header with ADT interface
│   ├── List.cpp                # Implementation
│   ├── main.cpp                # Test driver
│   └── Makefile                # Build configuration
├── PR2-Stack/                  # Stack implementation
├── PR3-Queue/                  # Queue implementation
├── PR4-BST/                    # Binary Search Tree
├── PR5-Graph/                  # Graph with Dijkstra's
└── PR6-Sorting Numbers/        # Sorting algorithms (Python)
```

Each C++ project follows a three-file architecture:

1. **Header file (.h)** - Public interface and documentation
2. **Implementation file (.cpp)** - Function implementations
3. **Main driver (main.cpp)** - Test cases and usage examples

For detailed architecture information, see [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md).

## Quickstart

### Prerequisites

**For C++ projects:**

- GCC/G++ compiler with C++11 support
- GNU Make (optional but recommended)
- Linux, macOS, or Windows with MinGW/WSL

**For Python projects:**

- Python 3.x

### Build and Run

**C++ Projects (PR1-PR5):**

```bash
# Navigate to any C++ project directory
cd PR1-Abstract-Data-Type

# Build using Make
make

# Run the compiled program
./output

# Clean build artifacts
make clean
```

**Python Projects (PR6):**

```bash
cd PR6-Sorting\ Numbers
python3 "Merge sort V2 Verbose.py"
```

### Example: Building and Running the Linked List

```bash
cd PR1-Abstract-Data-Type
make
./output
```

**Expected output:**

```
List contents: 

Addition Successful
List contents after adding 5: 5 
List size: 1

Addition Successful
List contents after adding 10: 10 5 
List size: 2

Addition Successful
List contents after adding 15: 15 10 5 
List size: 3

List contents after removing 10: 15 5 
List size: 2

List contents after clearing: 
List size after clearing: 0
```

## Usage

### Linked List (PR1)

```cpp
#include "List.h"

List myList;
myList.add(5);      // Add element
myList.add(10);
myList.view();      // Display: 10 5
myList.remove(5);   // Remove element
int count = myList.size();  // Get size
myList.clear();     // Clear all elements
```

### Stack (PR2)

```cpp
#include "Stack.h"

Stack myStack(2);           // Initial capacity of 2
myStack.push("first");      // Auto-resizes when full
myStack.push("second");
string top = myStack.peek(); // View top without removing
string item = myStack.pop();// Remove and return top
myStack.view();             // Display stack contents
```

### Queue (PR3)

```cpp
#include "Queue.h"

Queue q(5);          // Queue with capacity 5
int value;
q.enqueue(10);       // Add to rear
q.enqueue(20);
q.dequeue(value);    // Remove from front (value = 10)
q.view();            // Display queue
```

### Binary Search Tree (PR4)

```cpp
#include "BST.h"

BST tree;
tree.insert(5);
tree.insert(3);
tree.insert(7);

tree.search(5);          // Returns NodePtr if found, NULL otherwise
tree.inorderView();      // Displays: 3 5 7 (sorted)
tree.preorderView();     // Top-down traversal
tree.postorderView();    // Bottom-up traversal
tree.remove(3);          // Remove node
```

### Graph with Dijkstra's (PR5)

```cpp
#include "Graph.h"

Graph g("data.dat");  // Load graph from file
g.dijkstra();         // Run Dijkstra's shortest path algorithm
```

**Note:** Requires a `data.dat` file with graph adjacency matrix data.

### Merge Sort (PR6)

```python
from merge_sort import merge_sort

my_list = [43, 12, 32, 20, 14, 39, 21, 28, 48]
sorted_list = merge_sort(my_list)
print(sorted_list)  # [12, 14, 20, 21, 28, 32, 39, 43, 48]
```

## Configuration

### Build Settings

All C++ projects use the following compilation flags:

- **Standard:** `-std=c++11`
- **Compiler:** `g++`

Modify the `Makefile` in each project directory to change build settings.

### Element Types

Each data structure uses a typedef for flexibility:

| Project     | Element Type       | Location                                    |
| ----------- | ------------------ | ------------------------------------------- |
| List (PR1)  | `float`          | [List.h:23](PR1-Abstract-Data-Type/List.h#L23) |
| Stack (PR2) | `string`         | [Stack.h:29](PR2-Stack/Stack.h#L29)            |
| Queue (PR3) | `int`            | [Queue.h:18](PR3-Queue/Queue.h#L18)            |
| BST (PR4)   | `int`            | [BST.h:21](PR4-BST/PR4_BST/BST.h#L21)          |
| Graph (PR5) | `unsigned short` | [Graph.h:64](PR5-Graph/PR5_Graph/Graph.h#L64)  |

To change the data type, modify the `typedef` declaration in the respective header file.

## Testing and Quality

### Running Tests

Each project includes a `main.cpp` driver program with test cases:

```bash
# Build and run tests for any project
cd PR1-Abstract-Data-Type
make
./output
```

### Test Coverage

- **PR1 (List):** Tests add, remove, view, size, clear operations
- **PR2 (Stack):** Tests push, pop, peek, resize, copy constructor
- **PR3 (Queue):** Tests enqueue, dequeue, circular behavior, copy constructor
- **PR4 (BST):** Tests insert, remove, search, all three traversal orders
- **PR5 (Graph):** Tests Dijkstra's algorithm with sample graph data
- **PR6 (Sorting):** Demonstrates merge sort with verbose step-by-step output

### Code Standards

All code follows the documentation requirements specified in [Documentation Requirements.md](Documentation%20Requirements.md):

- Comprehensive header comments on all files
- Function-level documentation blocks
- Clear variable naming
- Proper encapsulation (public/private)

This is an academic portfolio project. Future enhancements could include:

- Additional data structures (Red-Black Tree, Heap, Hash Table)
- Unit testing framework integration (Google Test)
- Performance benchmarking suite
- Generic template implementations for all structures

## What This Project Demonstrates

This repository showcases foundational computer science and software engineering skills:

### Data Structures Knowledge

- **Abstract Data Types (ADTs)** - Proper encapsulation and interface design ([All .h files](./))
- **Memory Management** - Manual memory allocation/deallocation in linked structures ([List.cpp](PR1-Abstract-Data-Type/List.cpp), [BST.cpp](PR4-BST/PR4_BST/BST.cpp))
- **Dynamic Arrays** - Automatic resizing and capacity management ([Stack.cpp](PR2-Stack/Stack.cpp))
- **Tree Algorithms** - Recursive tree traversal and manipulation ([BST.cpp](PR4-BST/PR4_BST/BST.cpp))
- **Graph Algorithms** - Dijkstra's shortest path implementation ([Graph.cpp](PR5-Graph/PR5_Graph/Graph.cpp))

### C++ Proficiency

- **OOP Principles** - Classes, constructors, destructors, copy constructors
- **Resource Management** - Proper cleanup in destructors, copy operations
- **Header/Implementation Separation** - Professional code organization
- **Const Correctness** - Appropriate use of `const` methods and parameters

### Software Engineering Practices

- **Documentation Standards** - Extensive inline documentation following academic standards ([Documentation Requirements.md](Documentation%20Requirements.md))
- **Build Automation** - Makefile-based build system ([Example Makefile](PR1-Abstract-Data-Type/Makefile))
- **Code Organization** - Modular design with clear separation of concerns
- **Testing** - Comprehensive test drivers for each implementation

### Algorithm Implementation

- **Sorting Algorithms** - Merge sort with divide-and-conquer approach ([Merge sort V2 Verbose.py](PR6-Sorting%20Numbers/Merge%20sort%20V2%20Verbose.py))
- **Search Algorithms** - Binary search tree operations
- **Graph Algorithms** - Dijkstra's shortest path

## Contributing

This is an academic portfolio project. While it's not actively seeking contributions, you're welcome to:

- Fork the repository for educational purposes
- Use as reference for learning data structures
- Report issues or suggest improvements via GitHub Issues

For contribution guidelines, see [CONTRIBUTING.md](CONTRIBUTING.md).

## Development Setup

For detailed development environment setup, testing procedures, and project structure information, see [docs/DEVELOPMENT.md](docs/DEVELOPMENT.md).

## License

This project is licensed under the **GNU General Public License v3.0** - see the [LICENSE](LICENSE) file for details.

### Summary of GPL-3.0:

- ✅ Commercial use allowed
- ✅ Modification allowed
- ✅ Distribution allowed
- ✅ Private use allowed
- ⚠️ Derivative works must also be GPL-3.0
- ⚠️ Must disclose source code
- ⚠️ Must include license and copyright notice

## Credits and Acknowledgements

**Author:** John Akujobi
**Course:** CSC 300 - Data Structures
**Institution:** South Dakota State University
**Instructor:** Ken Gamradt
**Academic Year:** Fall 2023

### Assignment Completion Timeline:

- PR1 (List ADT): Due 09-25-23
- PR2 (Stack): Due 10-06-23
- PR3 (Queue): Due 10-18-23
- PR4 (BST): Due 11-08-23
- PR5 (Graph): Due 11-29-23
- PR6 (Sorting): Completed Assignment 6

---

**Note:** This is an educational project. All implementations are for learning purposes and may not be optimized for production use.
