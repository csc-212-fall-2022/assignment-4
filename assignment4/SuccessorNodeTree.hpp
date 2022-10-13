#include "SuccessorNode.hpp"

namespace assignment4 {
class SuccessorNodeTree {
private:
  SuccessorNode *root;

  SuccessorNode *TreeMaximum(SuccessorNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    SuccessorNode *curr = node;
    while (curr->right != nullptr) {
      curr = curr->right;
    }
    return curr;
  }

public:
  SuccessorNodeTree() { root = nullptr; }
  SuccessorNodeTree(SuccessorNode *r) { root = r; }
  ~SuccessorNodeTree();

  SuccessorNode *Search(int);

  void Insert(int);

  void Delete(int);

  bool IsBinarySearchTree();

  SuccessorNode *Parent(SuccessorNode *);
};

} // namespace assignment4