#include "MinHeapify.hpp"
#include <algorithm>
#include <stdexcept>

namespace assignment4 {

int Left(int idx) { return (idx << 1) + 1; }

int Right(int idx) { return (idx << 1) + 2; }

// Given a vector representing a binary tree and an index `idx`
// such that the trees rooted at Left(idx) and Right(idx) are min-heaps,
// transform the tree rooted at idx to be a min-heap
std::vector<int> MinHeapify(std::vector<int> vec, int idx) {
  throw std::runtime_error("Not implemented!");
}

bool IsMinHeap(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    int left = Left(i);
    int right = Right(i);
    if (left < vec.size() && vec.at(left) < vec.at(i)) {
      return false;
    }
    if (right < vec.size() && vec.at(right) < vec.at(i)) {
      return false;
    }
  }
  return true;
}

} // namespace assignment4
