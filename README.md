# Assignment 4

## Part 1: 12.3-3

Implement the function `SortWithTree` in `assignment4/BinarySearchTree.cpp`. This function should
sort a vector by inserting it into a binary search tree and then performing an in-order traversal
of that tree.

You'll need to implement the `InOrderHelper` function to finish off the implementation of the `InOrder` function.

##  Part 2: 12.3-5

When we discussed Binary Search Trees in class, we implemented them using nodes that held a pointer to their parent.
Instead, you'll implement the `SuccessorNodeTree` class that uses nodes that hold a reference to their _successor_:
```c++
struct SuccessorNode {
  int key;
  SuccessorNode *left;
  SuccessorNode *right;
  SuccessorNode *successor;

  SuccessorNode(int n) { key = n; }
};
```
To help, start by implementing the `Parent` function. There is a `TreeMaximum` method already implemented. Your `Search`, `Insert` and `Delete` functions should
be O(h) where h is the height of the tree.


## Part 3: 6.2-2

Implement the function `MinHeapify` in `assignment4/MinHeapify.cpp`.