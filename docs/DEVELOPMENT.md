# Development Guide

This guide provides detailed instructions for setting up a development environment, building, testing, and contributing to the Data Structures repository.

## Table of Contents

- [Development Environment Setup](#development-environment-setup)
- [Building the Projects](#building-the-projects)
- [Running Tests](#running-tests)
- [Project Structure](#project-structure)
- [Coding Standards](#coding-standards)
- [Troubleshooting](#troubleshooting)

## Development Environment Setup

### Prerequisites

#### For C++ Development

**Required:**
- GCC/G++ compiler (version 4.8.1 or later for C++11 support)
- GNU Make (optional but recommended)

**Optional:**
- GDB debugger
- Valgrind (for memory leak detection on Linux)
- Code editor (VS Code, Vim, Emacs, etc.)

#### For Python Development

**Required:**
- Python 3.x (any version)

### Platform-Specific Setup

#### Linux (Ubuntu/Debian)

```bash
# Install build tools
sudo apt-get update
sudo apt-get install build-essential

# Verify installation
g++ --version
make --version
```

#### macOS

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or install via Homebrew
brew install gcc make

# Verify installation
g++ --version
make --version
```

#### Windows

**Option 1: MinGW**
1. Download MinGW from [mingw-w64.org](https://www.mingw-w64.org/)
2. Install and add to PATH
3. Verify: `g++ --version`

**Option 2: WSL (Recommended)**
1. Install WSL2
2. Install Ubuntu from Microsoft Store
3. Follow Linux instructions above

**Option 3: Visual Studio**
- The repository includes Visual Studio project files (`.vcxproj`) in some directories
- Open with Visual Studio 2019 or later

### Clone the Repository

```bash
git clone https://github.com/jakujobi/Data_Structures.git
cd Data_Structures
```

## Building the Projects

### Using Make (Recommended)

Each C++ project has a Makefile for automated building:

```bash
# Navigate to a project directory
cd PR1-Abstract-Data-Type

# Build the project
make

# Run the executable
./output

# Clean build artifacts
make clean
```

### Manual Compilation

If Make is not available, compile manually:

```bash
# Compile each source file to object file
g++ -std=c++11 -c main.cpp
g++ -std=c++11 -c List.cpp

# Link object files to create executable
g++ -std=c++11 -o output main.o List.o

# Run
./output
```

### Build All Projects

To build all C++ projects at once:

```bash
# From repository root
for dir in PR1-Abstract-Data-Type PR2-Stack PR3-Queue; do
    echo "Building $dir..."
    (cd "$dir" && make clean && make)
done

# Build PR4 (different structure)
(cd PR4-BST/PR4_BST && \
 g++ -std=c++11 -c main.cpp && \
 g++ -std=c++11 -c BST.cpp && \
 g++ -std=c++11 -o output main.o BST.o)

# Build PR5 (different structure)
(cd PR5-Graph/PR5_Graph && \
 g++ -std=c++11 -c main.cpp && \
 g++ -std=c++11 -c Graph.cpp && \
 g++ -std=c++11 -o output main.o Graph.o)
```

### Python Projects

```bash
cd PR6-Sorting\ Numbers
python3 "Merge sort V2 Verbose.py"
```

## Running Tests

Each project's `main.cpp` serves as a test driver with built-in test cases.

### PR1: Linked List

```bash
cd PR1-Abstract-Data-Type
make && ./output
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
...
```

### PR2: Stack

```bash
cd PR2-Stack
make && ./output
```

Tests cover:
- Push operation
- Pop operation
- Peek operation
- Automatic resizing
- Copy constructor
- Edge cases (empty stack, full stack)

### PR3: Queue

```bash
cd PR3-Queue
make && ./output
```

Tests cover:
- Enqueue operation
- Dequeue operation
- Circular array behavior
- Copy constructor
- Full/empty queue conditions

### PR4: Binary Search Tree

```bash
cd PR4-BST/PR4_BST
make clean
g++ -std=c++11 -c main.cpp
g++ -std=c++11 -c BST.cpp
g++ -std=c++11 -o output main.o BST.o
./output
```

Tests cover:
- Insertion (with duplicates)
- Deletion (leaf, one child, two children)
- Search operation
- All three traversal orders

### PR5: Graph

```bash
cd PR5-Graph/PR5_Graph
# Requires data.dat file
./output
```

**Note:** PR5 requires a `data.dat` file with graph data. The program will prompt for input.

### PR6: Sorting

```bash
cd PR6-Sorting\ Numbers
python3 "Merge sort V2 Verbose.py"
```

## Project Structure

### Directory Layout

```
Data_Structures/
├── .gitignore                      # Ignored files (build artifacts, etc.)
├── README.md                       # Main documentation
├── LICENSE                         # GPL-3.0 license
├── Makefile                        # Root makefile (template)
├── Documentation Requirements.md   # Code documentation standards
│
├── docs/                           # Additional documentation
│   ├── ARCHITECTURE.md             # System architecture
│   └── DEVELOPMENT.md              # This file
│
├── PR1-Abstract-Data-Type/         # Assignment 1: Linked List
│   ├── List.h                      # Public interface
│   ├── List.cpp                    # Implementation
│   ├── main.cpp                    # Test driver
│   ├── Makefile                    # Build script
│   └── Assignment 1.pdf            # Requirements
│
├── PR2-Stack/                      # Assignment 2: Stack
│   ├── Stack.h
│   ├── Stack.cpp
│   ├── main.cpp
│   ├── Makefile
│   └── PR2_StackVS/                # Visual Studio project
│
├── PR3-Queue/                      # Assignment 3: Queue
│   ├── Queue.h
│   ├── Queue.cpp
│   ├── main.cpp
│   ├── Makefile
│   └── PR3_VS3/                    # Visual Studio project
│
├── PR4-BST/                        # Assignment 4: Binary Search Tree
│   └── PR4_BST/
│       ├── BST.h
│       ├── BST.cpp
│       ├── main.cpp
│       └── *.vcxproj               # Visual Studio files
│
├── PR5-Graph/                      # Assignment 5: Graph + Dijkstra
│   └── PR5_Graph/
│       ├── Graph.h
│       ├── Graph.cpp
│       ├── main.cpp
│       └── *.vcxproj
│
└── PR6-Sorting Numbers/            # Assignment 6: Sorting
    ├── Merge sort V2 Verbose.py
    ├── Merge sort verbose.py
    └── *.md                        # Algorithm documentation
```

### File Naming Conventions

- **Header files:** `ClassName.h`
- **Implementation files:** `ClassName.cpp`
- **Test drivers:** `main.cpp`
- **Build scripts:** `Makefile`
- **Documentation:** `*.md`, `*.pdf`

## Coding Standards

All code in this repository follows the documentation standards specified in [Documentation Requirements.md](../Documentation%20Requirements.md).

### File Header Format

```cpp
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : [Assignment Number]                            *** 
*** DUE DATE : [MM-DD-YY]                                       *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
```

### Function Documentation Format

```cpp
/********************************************************************
*** FUNCTION functionName                                        ***
*********************************************************************
*** DESCRIPTION : [Detailed description of what function does]  ***
*** INPUT ARGS : [List input parameters]                        ***
*** OUTPUT ARGS : [List output parameters]                      ***
*** IN/OUT ARGS : [List input/output parameters]                ***
*** RETURN : [Return type and description]                      ***
********************************************************************/
ReturnType functionName(parameters) {
    // Implementation
}
```

### Code Style Guidelines

1. **Naming Conventions:**
   - Classes: PascalCase (`Stack`, `List`, `BST`)
   - Functions: camelCase (`enqueue`, `isEmpty`)
   - Constants: UPPER_SNAKE_CASE (`STACK_SIZE`, `QUEUE_SIZE`)

2. **Indentation:** 4 spaces (or tab width 4)

3. **Braces:** K&R style or Allman style (be consistent within a file)

4. **Comments:**
   - Header blocks for all files and public functions
   - Inline comments for complex logic
   - No redundant comments

5. **Include Guards:**
   ```cpp
   #ifndef _CLASSNAME_H
   #define _CLASSNAME_H
   // ... content ...
   #endif
   ```

## Debugging

### Using GDB (Linux/macOS)

```bash
# Compile with debug symbols
g++ -std=c++11 -g -c main.cpp
g++ -std=c++11 -g -c List.cpp
g++ -std=c++11 -g -o output main.o List.o

# Run with GDB
gdb ./output

# GDB commands:
# (gdb) break main          # Set breakpoint
# (gdb) run                 # Start program
# (gdb) next                # Step over
# (gdb) step                # Step into
# (gdb) print variable      # Print variable value
# (gdb) quit                # Exit GDB
```

### Memory Leak Detection (Linux)

```bash
# Install valgrind
sudo apt-get install valgrind

# Build with debug symbols
make clean
g++ -std=c++11 -g -c main.cpp
g++ -std=c++11 -g -c List.cpp
g++ -std=c++11 -g -o output main.o List.o

# Run valgrind
valgrind --leak-check=full ./output
```

## Common Build Issues

### Issue: "make: command not found"

**Solution:** Install GNU Make or use manual compilation.

```bash
# Ubuntu/Debian
sudo apt-get install make

# macOS
xcode-select --install
```

### Issue: "g++: command not found"

**Solution:** Install GCC/G++.

```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install
```

### Issue: C++11 features not recognized

**Solution:** Ensure `-std=c++11` flag is used.

```bash
g++ -std=c++11 -c main.cpp
```

### Issue: Undefined reference errors during linking

**Solution:** Link all necessary object files.

```bash
# Correct
g++ -std=c++11 -o output main.o List.o

# Incorrect (missing List.o)
g++ -std=c++11 -o output main.o
```

### Issue: "No rule to make target" in PR4/PR5

**Solution:** Use manual compilation for PR4/PR5 as Makefiles may be in different locations.

```bash
cd PR4-BST/PR4_BST
g++ -std=c++11 -c main.cpp
g++ -std=c++11 -c BST.cpp
g++ -std=c++11 -o output main.o BST.o
```

## Modifying the Code

### Adding a New Data Structure

1. **Create a new directory:**
   ```bash
   mkdir PR7-NewStructure
   cd PR7-NewStructure
   ```

2. **Create header file (`NewStructure.h`):**
   - Follow the documentation standard
   - Define public interface
   - Declare private members

3. **Create implementation file (`NewStructure.cpp`):**
   - Implement all methods
   - Add documentation blocks

4. **Create test driver (`main.cpp`):**
   - Write comprehensive test cases

5. **Create Makefile:**
   - Copy from existing project
   - Update file names

### Changing Element Type

Edit the typedef in the header file:

```cpp
// In List.h, line 23
typedef float Element;

// Change to:
typedef int Element;  // or any other type
```

Then rebuild:

```bash
make clean
make
```

## Performance Profiling

### Using gprof (Linux)

```bash
# Compile with profiling
g++ -std=c++11 -pg -c main.cpp
g++ -std=c++11 -pg -c List.cpp
g++ -std=c++11 -pg -o output main.o List.o

# Run program (generates gmon.out)
./output

# View profile
gprof output gmon.out
```

## Continuous Integration

**Note:** This repository does not currently have CI/CD configured. To add:

1. Create `.github/workflows/build.yml`
2. Define build and test steps for each project
3. Configure matrix builds for multiple compilers/platforms

Example workflow (TODO):
```yaml
name: Build and Test
on: [push, pull_request]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Build PR1
        run: cd PR1-Abstract-Data-Type && make
```

## Editor Configuration

### VS Code

Create `.vscode/settings.json`:

```json
{
    "files.associations": {
        "*.h": "cpp",
        "*.cpp": "cpp"
    },
    "C_Cpp.default.cppStandard": "c++11",
    "C_Cpp.default.compilerPath": "/usr/bin/g++"
}
```

### Vim

Add to `.vimrc`:

```vim
set tabstop=4
set shiftwidth=4
set expandtab
syntax on
```

## Additional Resources

- [C++ Reference](https://en.cppreference.com/)
- [Data Structures Visualizations](https://www.cs.usfca.edu/~galles/visualization/)
- [GDB Tutorial](https://www.cs.cmu.edu/~gilpin/tutorial/)
- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)

---

*For architecture details, see [ARCHITECTURE.md](ARCHITECTURE.md).  
For contribution guidelines, see [CONTRIBUTING.md](../CONTRIBUTING.md).*
