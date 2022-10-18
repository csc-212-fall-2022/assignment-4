namespace assignment4 {
struct TreeNode {
  int key;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;

  TreeNode(int k) { 
    key = k;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
};
} // namespace assignment4
