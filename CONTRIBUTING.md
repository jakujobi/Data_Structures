# Contributing to Data Structures

Thank you for your interest in contributing to this educational Data Structures repository! While this is primarily an academic portfolio project, contributions are welcome for improvements, bug fixes, and additional educational content.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
- [Development Setup](#development-setup)
- [Coding Standards](#coding-standards)
- [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)
- [Documentation Standards](#documentation-standards)

## Code of Conduct

This project follows standard open-source etiquette:

- **Be respectful** and constructive in all interactions
- **Focus on learning** - this is an educational project
- **Assume good intentions** from all contributors
- **Help others** learn from your expertise

## How Can I Contribute?

### Reporting Bugs

Before creating a bug report:
1. **Check existing issues** to avoid duplicates
2. **Verify the bug** with the latest code
3. **Determine which project** (PR1-PR6) is affected

When creating a bug report, include:
- **Clear title** describing the issue
- **Steps to reproduce** the problem
- **Expected behavior** vs. actual behavior
- **System information** (OS, compiler version)
- **Code snippet** or error message

**Example:**
```markdown
**Title:** Stack overflow in PR2 when pushing after clear

**Description:**
When clearing a stack and then pushing elements, the program crashes.

**Steps to Reproduce:**
1. Create a stack and push 5 elements
2. Call clear()
3. Push a new element
4. Program crashes

**Expected:** New element should be pushed successfully
**Actual:** Segmentation fault

**Environment:**
- OS: Ubuntu 22.04
- Compiler: g++ 11.3.0
- Project: PR2-Stack
```

### Suggesting Enhancements

Enhancement suggestions are welcome for:
- **Additional data structures** (Heap, Hash Table, Red-Black Tree, etc.)
- **Improved test coverage**
- **Performance optimizations**
- **Better documentation**
- **Additional examples**

Please open an issue with:
- **Clear description** of the enhancement
- **Rationale** - why it would be valuable
- **Proposed implementation** approach (if you have one)
- **Examples** or references

### Adding New Data Structures

To add a new data structure:

1. **Create a new issue** first to discuss the addition
2. **Follow the existing pattern:**
   - Create `PRX-StructureName/` directory
   - Implement `StructureName.h` with documented interface
   - Implement `StructureName.cpp` with all methods
   - Create `main.cpp` with comprehensive tests
   - Add `Makefile` for building
3. **Follow documentation standards** (see below)
4. **Include test cases** demonstrating all operations
5. **Update README.md** with the new structure

### Improving Existing Code

Contributions that improve existing implementations:
- **Bug fixes** for incorrect behavior
- **Memory leak fixes**
- **Performance improvements** (with benchmarks)
- **Better error handling**
- **Enhanced documentation**

**Note:** Maintain backward compatibility when possible.

## Development Setup

See [docs/DEVELOPMENT.md](docs/DEVELOPMENT.md) for detailed setup instructions.

**Quick start:**
```bash
# Clone the repository
git clone https://github.com/jakujobi/Data_Structures.git
cd Data_Structures

# Build a project to verify setup
cd PR1-Abstract-Data-Type
make
./output
```

## Coding Standards

All contributions must follow the existing code style and documentation standards.

### Documentation Standards

This repository follows strict documentation requirements specified in [Documentation Requirements.md](Documentation%20Requirements.md).

**All files must have header comments:**
```cpp
/******************************************************************** 
*** NAME : [Your Name]                                          *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : [Assignment Number or "Community Contribution"]*** 
*** DUE DATE : [Date or "N/A"]                                  *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
```

**All public functions must be documented:**
```cpp
/********************************************************************
*** FUNCTION functionName                                        ***
*********************************************************************
*** DESCRIPTION : [What the function does]                      ***
*** INPUT ARGS : [List of input parameters]                     ***
*** OUTPUT ARGS : [List of output parameters]                   ***
*** IN/OUT ARGS : [List of input/output parameters]             ***
*** RETURN : [Return type and description]                      ***
********************************************************************/
```

### C++ Style Guidelines

1. **Naming:**
   - Classes: `PascalCase` (e.g., `BinaryTree`, `Stack`)
   - Functions/Methods: `camelCase` (e.g., `insertNode`, `isEmpty`)
   - Constants: `UPPER_SNAKE_CASE` (e.g., `MAX_SIZE`, `DEFAULT_CAPACITY`)
   - Private members: No prefix required

2. **Formatting:**
   - Indentation: 4 spaces (no tabs)
   - Line length: 80-100 characters preferred
   - Braces: Opening brace on same line (K&R style) or next line (Allman) - be consistent

3. **Code Organization:**
   - Header guards in all `.h` files
   - Public members before private
   - Include only necessary headers
   - Use `const` where appropriate

4. **Memory Management:**
   - Always pair `new` with `delete`
   - Implement copy constructors for deep copies
   - Implement destructors for cleanup
   - No memory leaks (verify with Valgrind)

5. **Error Handling:**
   - Check for null pointers
   - Validate array bounds
   - Handle edge cases (empty structures, full structures)

### Example Code

```cpp
// Good ✓
class Stack {
public:
    Stack(int capacity = 2);
    ~Stack();
    void push(const Element& element);
    Element pop();
    
private:
    Element* stackArray;
    int top;
    int capacity;
    
    void resize();
    bool isEmpty() const;
    bool isFull() const;
};

// Avoid ✗
class stack {  // Wrong: lowercase class name
    public:
    void PUSH(Element e);  // Wrong: uppercase function, non-const ref
    Element* stackarray;   // Wrong: public data member
};
```

## Commit Guidelines

### Commit Message Format

```
<type>: <short summary>

<optional detailed description>

<optional footer>
```

**Types:**
- `feat`: New feature or data structure
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code formatting (no logic change)
- `refactor`: Code restructuring (no behavior change)
- `test`: Adding or updating tests
- `perf`: Performance improvement
- `build`: Build system changes

**Examples:**

```
feat: Add AVL tree implementation (PR7)

- Implement self-balancing AVL tree
- Include rotation operations
- Add comprehensive test cases

Closes #15
```

```
fix: Resolve memory leak in BST destructor

The destructor was not properly deallocating all nodes
in the right subtree. Fixed by correcting the traversal logic.

Fixes #23
```

```
docs: Update README with installation instructions

Added platform-specific setup for Windows, macOS, and Linux.
```

### Commit Best Practices

- **Keep commits focused** - one logical change per commit
- **Commit often** - small, incremental commits
- **Write clear messages** - explain what and why, not how
- **Test before committing** - ensure code compiles and runs
- **Don't commit build artifacts** (`.o`, `output`, etc.)

## Pull Request Process

### Before Submitting

1. **Create a feature branch:**
   ```bash
   git checkout -b feature/your-feature-name
   ```

2. **Make your changes** following coding standards

3. **Test thoroughly:**
   ```bash
   make clean
   make
   ./output
   ```

4. **Check for memory leaks** (Linux):
   ```bash
   valgrind --leak-check=full ./output
   ```

5. **Update documentation** if needed:
   - README.md (if adding new features)
   - ARCHITECTURE.md (if changing structure)
   - Code comments

6. **Commit your changes** with clear messages

### Submitting the Pull Request

1. **Push your branch:**
   ```bash
   git push origin feature/your-feature-name
   ```

2. **Create PR on GitHub** with:
   - **Clear title** describing the change
   - **Description** explaining what and why
   - **Link to related issues** (if any)
   - **Test results** (what you tested)

3. **PR Template:**
   ```markdown
   ## Description
   Brief description of changes
   
   ## Type of Change
   - [ ] Bug fix
   - [ ] New feature
   - [ ] Documentation update
   - [ ] Performance improvement
   
   ## Testing
   - [ ] Code compiles without errors
   - [ ] All tests pass
   - [ ] No memory leaks (verified with Valgrind)
   - [ ] Tested on: [OS and compiler version]
   
   ## Checklist
   - [ ] Code follows project style guidelines
   - [ ] Documentation is updated
   - [ ] Commit messages are clear
   
   ## Related Issues
   Closes #[issue number]
   ```

### Review Process

- The maintainer will review your PR
- Address any feedback or requested changes
- Once approved, your PR will be merged
- Celebrate your contribution! 🎉

## Documentation Standards

### Code Documentation

All exported functions, classes, and public methods must have documentation blocks (see [Coding Standards](#coding-standards)).

### Markdown Documentation

When updating `.md` files:

1. **Use clear headings** - hierarchical structure
2. **Include code examples** - with proper syntax highlighting
3. **Keep it concise** - respect the reader's time
4. **Use proper formatting:**
   - Lists for multiple items
   - Code blocks for commands
   - Tables for structured data
   - Links to related sections

### Example Documentation

```markdown
## Function Name

**Description:** Brief description of what it does

**Parameters:**
- `param1` (type): Description
- `param2` (type): Description

**Returns:** Description of return value

**Example:**
```cpp
Stack myStack(10);
myStack.push("example");
string item = myStack.pop();
```

**Time Complexity:** O(1)
**Space Complexity:** O(1)
```

## Testing Guidelines

### Test Requirements

All new features must include tests:

1. **Normal cases** - typical usage
2. **Edge cases** - empty, full, single element
3. **Error cases** - invalid input, boundary conditions

### Writing Tests

Add test cases to `main.cpp`:

```cpp
int main() {
    cout << "Test 1: Normal operation\n";
    // Test code
    
    cout << "\nTest 2: Edge case - empty structure\n";
    // Edge case test
    
    cout << "\nTest 3: Error handling\n";
    // Error case test
    
    return 0;
}
```

## Questions?

- **Open an issue** for questions about contributing
- **Check existing documentation** in `docs/` directory
- **Review existing code** for examples

## License

By contributing, you agree that your contributions will be licensed under the GNU General Public License v3.0 (GPL-3.0), the same license as this project.

---

**Thank you for contributing to this educational resource! Your efforts help others learn data structures and C++ programming.**
