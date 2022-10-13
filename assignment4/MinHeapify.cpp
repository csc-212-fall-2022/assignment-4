#include "MinHeapify.hpp"
#include <stdexcept>

namespace assignment4 {

int Left(int idx) { return (idx << 1) - 1; }

int Right(int idx) { return (idx << 1); }

std::vector<int> MinHeapify(std::vector<int> vec, int idx) {
  throw std::runtime_error("Implement me!");
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