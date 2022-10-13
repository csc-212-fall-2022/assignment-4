#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "BinarySearchTree.hpp"

using namespace assignment4;

TEST_CASE("Test sort") {
    std::vector<int> input = {20, 5, 1, 4, 71, 2, 9};

    std::vector<int> sorted = SortWithTree(input);

    std::vector<int> expected = {1,2,4,5,9,20,71};
    CHECK_EQ(sorted, expected);
}

TEST_CASE("The empty vector should sort") {
    std::vector<int> empty;

    std::vector<int> sorted = SortWithTree(empty);

    CHECK_EQ(empty, sorted);
}