#ifndef HOMEWORK1_INSERTIONSORT_H
#define HOMEWORK1_INSERTIONSORT_H

// Insertion Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void InsertionSort(std::vector<int>* numbers);

//declaration variable
extern int countNumComparesInsert;
extern int countNumMemAccessInsert;

#endif //HOMEWORK1_INSERTIONSORT_H
