#include "SuccessorNodeTree.hpp"
#include <stdexcept>
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

void PostOrderCleanup(SuccessorNode *node) {
  if (node != nullptr) {
    PostOrderCleanup(node->left);
    PostOrderCleanup(node->right);
    delete node;
  }
}

SuccessorNodeTree::~SuccessorNodeTree() { PostOrderCleanup(root); }

SuccessorNode *SuccessorNodeTree::Search(int n) {
  throw std::runtime_error("Implement me!");
}

void SuccessorNodeTree::Insert(int n) {
  throw std::runtime_error("Implement me!");
}

void SuccessorNodeTree::Delete(int n) {
  throw std::runtime_error("Implement me!");
}

bool SuccessorNodeTree::IsBinarySearchTree() { return IsBSTHelper(root); }

SuccessorNode *SuccessorNodeTree::Parent(SuccessorNode *node) {
  throw std::runtime_error("Implement me!");
}

}; // namespace assignment4