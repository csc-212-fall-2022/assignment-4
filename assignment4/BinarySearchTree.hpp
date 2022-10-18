#include "TreeNode.hpp"
#include <vector>

namespace assignment4 {
class BinarySearchTree {
private:
  TreeNode *root = nullptr;

public:
  void Insert(int);

  std::vector<int> InOrder();
};

std::vector<int> SortWithTree(std::vector<int>);
} // namespace assignment4
