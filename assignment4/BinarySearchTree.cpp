#include "BinarySearchTree.hpp"
#include <stdexcept>
#include <vector>

namespace assignment4 {
void BinarySearchTree::Insert(int n) {
  TreeNode *parent = nullptr;
  TreeNode *curr = root;
  while (curr != nullptr) {
    parent = curr;
    if (n < curr->key) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
  TreeNode *node = new TreeNode(n);
  if (parent == nullptr) {
    root = node;
  } else {
    node->parent = parent;
    if (n < parent->key) {
      parent->left = node;
    } else {
      parent->right = node;
    }
  }
}

std::vector<int> InOrderHelper(TreeNode *node) {
  // hint: to concatenate two vectors v1 and v2:
  //  v1.insert(v1.end(), v2.begin(), v2.end())
  throw std::runtime_error("Implement me!");
}

std::vector<int> BinarySearchTree::InOrder() { return InOrderHelper(root); }

std::vector<int> SortWithTree(std::vector<int> vec) {
  throw std::runtime_error("Implement me!");
}
} // namespace assignment4