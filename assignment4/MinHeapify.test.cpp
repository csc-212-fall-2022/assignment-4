#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "MinHeapify.hpp"
#include "doctest/doctest.h"

TEST_CASE("Min-Heapify(vec, 0) results in a min-heap") {
  // NOTE: Min-heapify assumes that Left(i) and Right(i) are themselves
  // min-heaps
  SUBCASE("{20, 10, 50, 4}") {
    std::vector<int> vec = {20, 4, 50, 10};
    std::vector<int> expected = {4, 10, 50, 20};

    std::vector<int> result = assignment4::MinHeapify(vec, 0);

    CHECK_EQ(expected, result);
    CHECK(assignment4::IsMinHeap(result));
  }

  SUBCASE("{6, 4, 1, 6, 12, 2, 4}") {
    std::vector<int> vec = {6, 4, 1, 6, 12, 2, 4};
    std::vector<int> expected = {1, 4, 2, 6, 12, 6, 4};

    std::vector<int> result = assignment4::MinHeapify(vec, 0);

    CHECK_EQ(expected, result);
    CHECK(assignment4::IsMinHeap(result));
  }
}