# CSc 300: Assignment #3

**Instructor**: Gamradt
**Due Date**: 10-18-23
**Late Submission**: 10-25-23

## Objective

Create a user-defined Abstract Data Type (ADT) named `Queue`.

### Specifications

- Use an appropriate set of C++ header/implementation files as discussed in class.
- Queue is implemented as a dynamically allocated Array.
  - Implemented as a circular queue.
  - Refer to C++ Pointers under D2L Lecture Notes.
- Queue consists of 0 or more `Element` values.
  - `Element` is an exportable standard library `int` data type.

#### Exportable Operations (Declared in `.h` file and defined in `.cpp` file)

- **Queue default constructor**: Creates an initialized empty queue with size 3.
- **Queue parameterized constructor**: Creates an initialized empty queue with user-specified size.
- **Queue copy constructor**: Creates a duplicate copy of an existing queue.
- **Destructor (`~Queue`)**: Removes all elements from the queue.
- **enqueue**: Inserts a new element to the tail of the queue.
- **dequeue**: Removes an existing element from the head of the queue.
- **view**: Displays the contents of the queue from the head to the tail.
  - Uses a non-destructive implementation.

#### Additional Exportable Operations

- **isEmpty**: Returns `true` if the current queue instance is empty, `false` otherwise.
- **isFull**: Returns `true` if the current queue instance is full, `false` otherwise.

### User-Defined Data Types

- `Element`
- `ElementPtr`

### Queue Required Output Format (view)

- **Empty Queue**: `HEAD -> TAIL`
- **Populated Queue**: `HEAD -> 5 -> -3 -> TAIL`

---

## Implementation Details

### Required Header File (.h)

```cpp
#ifndef _QUEUE_H
#define _QUEUE_H
typedef int Element;
typedef Element * ElementPtr;
class Queue {
public:
  explicit Queue( ... ); // replace ... with required arguments
  Queue( Queue & );
  ~Queue();
  void enqueue( const Element );
  void dequeue( Element & );
  void view();
private:
  const short QUEUE_SIZE;
  ElementPtr queueArray;
  short head, tail;
  bool isEmpty() const;
  bool isFull() const;
};
#endif
```

### Include Sequence

- `main.cpp`
- `Queue.h`
- `Queue.cpp`

### Building Sequence (Using `make`)

1. Place all files in the project folder.
2. Run `make` to process Makefile.
3. Run `./output` to execute the project.

---

## Documentation

- The header file should contain general descriptions only.
- The implementation file should contain detailed descriptions.

## Submission

- Push your assignment solution to your GitHub account.
- Send a shared link to the assignment repository.

**Note**: A 20% reduction is applied for not using GitHub.

### Email Subject

`SUBJECT: csc300 – Lastname – a3`

---

I hope this Markdown-formatted document helps you understand your assignment better! If you have any questions, feel free to ask.
