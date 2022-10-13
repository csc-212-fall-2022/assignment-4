cmake_minimum_required(VERSION 3.14)

project("Assignment 4")

set(CMAKE_CXX_STANDARD 17)

# Setting -ggdb3 gets line numbers in Valgrind output
# -Og is the recommended level of optimization from the GCC docs for "the standard edit-compile-debug" cycle
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -Og")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake) # make sure we know where to find the doctest header

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/assignment1)
find_package(Doctest REQUIRED)

include(cmake/ClangFormat.cmake)

set(CMAKE_MEMORYCHECK_COMMAND valgrind)

# Use include(CTest) rather than enable_testing() to get Valgrind working
include(CTest)

find_program(CLANG_TIDY_EXE NAME clang-tidy REQUIRED)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*,bugprone-*")


add_library(SuccessorTree assignment4/SuccessorNode.hpp assignment4/SuccessorNodeTree.hpp assignment4/SuccessorNodeTree.cpp)

add_library(SortingTree assignment4/TreeNode.hpp assignment4/BinarySearchTree.hpp assignment4/BinarySearchTree.cpp)

add_executable(SortingTreeTest assignment4/BinarySearchTree.test.cpp)
target_link_libraries(SortingTreeTest Doctest SortingTree)

add_test(SortingTreeTest SortingTreeTest)

add_executable(SuccessorTreeTest assignment4/SuccessorNodeTree.test.cpp)
target_link_libraries(SuccessorTreeTest Doctest SuccessorTree)

add_test(SuccessorTreeTest SuccessorTreeTest)

add_executable(HeapTest assignment4/MinHeapify.hpp assignment4/MinHeapify.cpp assignment4/MinHeapify.test.cpp)
target_link_libraries(HeapTest Doctest)
add_test(HeapTest HeapTest)