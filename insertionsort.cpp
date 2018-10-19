// Insertion Sort
//
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"

int countNumComparesInsert = 0;
int countNumMemAccessInsert = 0;

void InsertionSort(std::vector<int>* numbers) {
  int i = 0;
  int j = 0;


  int temp = 0;  // Temporary variable for swap

  for (i = 1; i < numbers->size(); ++i) {
    j = i;


    // Insert numbers[i] into sorted part
    // stopping once numbers[i] in correct position

    while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]){
      countNumComparesInsert++;
      countNumMemAccessInsert++;
      countNumMemAccessInsert++;

      // Swap numbers[j] and numbers[j - 1]
      temp = (*numbers)[j];
      countNumMemAccessInsert++;
      (*numbers)[j] = (*numbers)[j - 1];
      countNumMemAccessInsert++;
      countNumMemAccessInsert++;
      (*numbers)[j - 1] = temp;
      countNumMemAccessInsert++;
      --j;
    }

    if( (j) > 0 ){
      countNumComparesInsert++;
      countNumMemAccessInsert++;
      countNumMemAccessInsert++;
    }

  }


  return;
}
