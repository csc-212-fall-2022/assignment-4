#include "MinHeapify.hpp"
#include <algorithm>
#include <stdexcept>

namespace assignment4 {

int Left(int idx) {  
    return (idx << 1) + 1;
}

int Right(int idx) {
  return (idx << 1) + 2;
}

std::vector<int> MinHeapify(std::vector<int> vec, int idx) {
  int l = Left(idx);
  int r = Right(idx);

  if (l >= vec.size()) {
    l = idx;
  }

  if (r >= vec.size()) {
    r = idx;
  }

  int smallest = idx;
  int smallest_value = vec.at(idx);
  if (vec.at(l) < smallest_value) {
    smallest = l;
    smallest_value = vec.at(l);
  }
  if (vec.at(r) < smallest_value) {
    smallest = r;
    smallest_value = vec.at(r);
  }

  if (smallest != idx) {
    vec.at(smallest) = vec.at(idx);
    vec.at(idx) = smallest_value;
    return MinHeapify(vec, smallest);
  }
  return vec;
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