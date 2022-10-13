#include "SuccessorNodeTree.hpp"
#include <vector>

namespace assignment4 {
bool IsBSTHelper(SuccessorNode *node) {
  if (node == nullptr) {
    return true;
  }
  if (node->left != nullptr && node->left->key > node->key) {
    return false;
  }
  if (node->right != nullptr && node->right->key < node->key) {
    return false;
  }
  return IsBSTHelper(node->left) && IsBSTHelper(node->right);
}

void PostOrderCleanup(SuccessorNode* node) {
  if (node != nullptr) {
    PostOrderCleanup(node->left);
    PostOrderCleanup(node->right);
    delete node;
  }
}

SuccessorNodeTree::~SuccessorNodeTree() {
  PostOrderCleanup(root);
}


SuccessorNode* SuccessorNodeTree::Search(int n) {
    
}

void SuccessorNodeTree::Insert(int n) {
  // otherwise find where we insert
  SuccessorNode *pred = nullptr;
  SuccessorNode *p = nullptr;
  SuccessorNode *curr = root;
  while (curr != nullptr) {
    p = curr;
    if (n < curr->key) {
      // no need to update the predecessor
      curr = curr->left;
    } else {
      // when we step right, the predecessor becomes where we were
      pred = curr;
      curr = curr->right;
    }
  }
  if (p == nullptr) {
    root = new SuccessorNode(n);
  } else {
    if (n < p->key) {
      // insert as the left child
      p->left = new SuccessorNode(n);
      p->left->successor = p;
      if (pred != nullptr) {
        pred->successor = p->left;
      }
    } else {
      // insert as the right child
      p->right = new SuccessorNode(n);
      p->right->successor = p->successor;
      p->successor = p->right;
    }
  }
}

bool SuccessorNodeTree::IsBinarySearchTree() { return IsBSTHelper(root); }

SuccessorNode *SuccessorNodeTree::Parent(SuccessorNode *node) {
  if (node == root) {
    return nullptr;
  }
  // find the maximum element of the tree rooted at node
  // its successor has to lie above node, so start there and
  // iterate downwards
  SuccessorNode *y = TreeMaximum(node)->successor;
  if (y == nullptr) { // it has no successor so just start at the root
    // node therefore has to lie in the right subtree of the root
    y = root;
  } else {
    if (y->left == node) {
      // we happend to find the parent
      return y;
    } else {
      // we know that to go from y -> node, we must start by stepping left
      y = y->left;
    }
  }
  while (y->right != node) {
    y = y->right;
  }
  return y;
}

}; // namespace assignment4