#ifndef HOMEWORK1_QUICKSORT_H
#define HOMEWORK1_QUICKSORT_H

// Quicksort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void QuickSort(std::vector<int>* numbers);
void QuickSortRecurse(std::vector<int>* numbers, int i, int k);
int Partition(std::vector<int>* numbers, int i, int k);

extern int countNumComparesQuickSort;
extern int countNumMemAccessQuickSort;

#endif //HOMEWORK1_QUICKSORT_H
