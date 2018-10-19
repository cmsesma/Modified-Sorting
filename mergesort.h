#ifndef HOMEWORK1_MERGESORT_H
#define HOMEWORK1_MERGESORT_H

// Merge Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>

void MergeSort(std::vector<int>* numbers);
void MergeSortRecurse(std::vector<int>* numbers, int i, int k);
void Merge(std::vector<int>* numbers, int i, int j, int k);

extern int countNumComparesMerge;
extern int countNumMemAccessMerge;

#endif //HOMEWORK1_MERGESORT_H
