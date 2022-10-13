
namespace assignment4 {
struct SuccessorNode {
  int key;
  SuccessorNode *left;
  SuccessorNode *right;
  SuccessorNode *successor;

  SuccessorNode(int n) {
    key = n;
    left = nullptr;
    right = nullptr;
    successor = nullptr;
  }
};
} // namespace assignment4