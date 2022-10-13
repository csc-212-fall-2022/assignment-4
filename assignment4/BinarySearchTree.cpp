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
  if (node == nullptr) {
    std::vector<int> empty;
    return empty;
  }
  std::vector<int> left = InOrderHelper(node->left);
  std::vector<int> right = InOrderHelper(node->right);
  left.push_back(node->key);
  left.insert(left.end(), right.begin(), right.end());
  return left;
}

std::vector<int> BinarySearchTree::InOrder() { return InOrderHelper(root); }

std::vector<int> SortWithTree(std::vector<int> vec) {
  BinarySearchTree tree = BinarySearchTree();
  for (int i = 0; i < vec.size(); i++) {
    tree.Insert(vec.at(i));
  }
  return tree.InOrder();
}
} // namespace assignment4