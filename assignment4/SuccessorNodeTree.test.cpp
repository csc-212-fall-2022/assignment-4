#include <iostream>
#include <string>
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "SuccessorNodeTree.hpp"
#include "doctest/doctest.h"

using namespace assignment4;

TEST_CASE("Test parents") {
  // manually construct a tree
  SuccessorNode *node12 = new SuccessorNode(12);
  SuccessorNode *node2 = new SuccessorNode(2);
  SuccessorNode *node1 = new SuccessorNode(1);
  SuccessorNode *node3 = new SuccessorNode(3);
  SuccessorNode *node4 = new SuccessorNode(4);
  SuccessorNode *node5 = new SuccessorNode(5);
  SuccessorNode *node7 = new SuccessorNode(7);
  node12->left = node2;
  node2->left = node1;
  node2->right = node4;
  node2->successor = node3;
  node1->successor = node2;
  node3->successor = node4;
  node4->left = node3;
  node4->right = node5;
  node4->successor = node5;
  node5->right = node7;
  node5->successor = node7;
  node7->successor = node12;

  SuccessorNodeTree tree = SuccessorNodeTree(node12);

  CHECK_EQ(tree.Parent(node1), node2);
  CHECK_EQ(tree.Parent(node2), node12);
  CHECK_EQ(tree.Parent(node12), nullptr);
  CHECK_EQ(tree.Parent(node3), node4);
}

TEST_CASE("Test insertion") {
  SuccessorNodeTree tree = SuccessorNodeTree();

  std::vector<int> insertionOrder = {12, 2, 1, 4, 3, 5, 7};
  std::vector<int> successors = {-1, 3, 2, 5, 4, 7, 12};

  for (int idx = 0; idx < insertionOrder.size(); idx++) {
    int i = insertionOrder.at(idx);
    CAPTURE(i);
    tree.Insert(i);
    CHECK(tree.IsBinarySearchTree());

  }
  
  // now check the successors once everything has been inserted
  for (int idx = 0; idx < insertionOrder.size(); idx++) {
    int i = insertionOrder.at(idx);
    CAPTURE(i);
    SuccessorNode *node = tree.Search(i);
    int successor = successors.at(idx);
    if (successor > 0) {
      CHECK_EQ(node->successor->key, successors.at(idx));
    } else {
      // should have the nullptr
      CHECK_EQ(node->successor, nullptr);
    }
  }
}
