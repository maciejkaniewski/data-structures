# data-structures

data-structures is a project I realized in the fourth semester of my studies within the Design of Algorithms and Artificial Intelligence Methods course at the Wroclaw University of Technology in the field of Control Engineering and Robotics. The main goal of this task was to implement a bidirectional linked list. Then, using the created list, we had to create such structures as stack, queue and priority queue. Additionally, unit tests had to be carried out to verify the correct implementation of the previously mentioned data structures. I used the `GoogleTest` framework to conduct unit tests and `Valgrind` tool to detect memory leaks.

## Table of Contents

  - [Features](#features)
  - [Setup](#setup)
  - [Usage](#usage)
  - [Concepts I Learned](#concepts-i-learned)
  
## Features

- Bidirectional Linked List
- Stack
- Queue
- Priority Queue


## Setup
Prerequisites:
* Installed CMake *(minimum VERSION 3.0)*,

Clone repository:

    git clone https://github.com/maciejkaniewski/data-structures.git

Create `build` directory and launch `CMake`:

    cd data-structures
    mkdir build
    cd build
    cmake ..

`CMake` will also clone `GoogleTest` library to the repository. The structure of folders in the repository after running the `CMake`:

```bash
.
├── build
├── CMakeLists.txt
├── googletest 
├── inc
│   ├── list.hh
│   ├── priority_queue.hh
│   ├── queue.hh
│   └── stack.hh
├── README.md
└── src
    └── test_data_structures.cpp
```
    
Run `make` command and execute the program:

    make
    ./Test_Data_Structures

## Usage

The compiled program performs tests on the implemented data structures and displays their results:

    [==========] Running 10 tests from 4 test suites.
    [----------] Global test environment set-up.
    [----------] 7 tests from ListTest
    [ RUN      ] ListTest.pushFront
    [       OK ] ListTest.pushFront (0 ms)
    [ RUN      ] ListTest.pushBack
    [       OK ] ListTest.pushBack (0 ms)
    [ RUN      ] ListTest.insert
    [       OK ] ListTest.insert (0 ms)
    [ RUN      ] ListTest.remove
    [       OK ] ListTest.remove (0 ms)
    [ RUN      ] ListTest.removeAll
    [       OK ] ListTest.removeAll (0 ms)
    [ RUN      ] ListTest.Iterator
    [       OK ] ListTest.Iterator (0 ms)
    [ RUN      ] ListTest.ConstIterator
    [       OK ] ListTest.ConstIterator (0 ms)
    [----------] 7 tests from ListTest (0 ms total)

    [----------] 1 test from StackTest
    [ RUN      ] StackTest.pushAndPop
    [       OK ] StackTest.pushAndPop (0 ms)
    [----------] 1 test from StackTest (0 ms total)

    [----------] 1 test from QueueTest
    [ RUN      ] QueueTest.enqueueAndDequeue
    [       OK ] QueueTest.enqueueAndDequeue (0 ms)
    [----------] 1 test from QueueTest (0 ms total)

    [----------] 1 test from PriorityQueueTest
    [ RUN      ] PriorityQueueTest.enqueueAndDequeue
    [       OK ] PriorityQueueTest.enqueueAndDequeue (0 ms)
    [----------] 1 test from PriorityQueueTest (0 ms total)

    [----------] Global test environment tear-down
    [==========] 10 tests from 4 test suites ran. (0 ms total)
    [  PASSED  ] 10 tests.


### Defining your own test

Current tests can be changed, extended. You can add new test conditions. All tests are defined in the `test_data_structures.cpp` file.

### Valgrind Output

    valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./Test_Data_Structures
    ==88260== Memcheck, a memory error detector
    ==88260== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==88260== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==88260== Command: ./Test_Data_Structures
    ==88260== HEAP SUMMARY:
    ==88260==     in use at exit: 0 bytes in 0 blocks
    ==88260==   total heap usage: 395 allocs, 395 frees, 133,392 bytes allocated
    ==88260== 
    ==88260== All heap blocks were freed -- no leaks are possible
    ==88260== 
    ==88260== For lists of detected and suppressed errors, rerun with: -s
    ==88260== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


## Concepts I Learned

- Creating own data structures,
- Using `Valgrind` to detect memory leaks,
- Performing tests using the `GoogleTest` framework.