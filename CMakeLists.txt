cmake_minimum_required(VERSION 3.8)
project(Homework1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES mergesort.cpp mergesort.h quicksort.cpp quicksort.h insertionsort.cpp insertionsort.h sortedverification.cxx consistentresultverification.cxx timealgorithms.cxx)
add_executable(Homework1 ${SOURCE_FILES})