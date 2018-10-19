#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "mergesort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include <ctime>
#include <vector>

int main(int argc, char** argv) {

  std::ifstream file;
  file.open(argv[1]);
  //file.open("/Users/chelsysesma/CLionProjects/Homework1/SampleExample.json");
  nlohmann::json jsonObject;
  if (file.is_open()) {
    file >> jsonObject;
  }

  //std::cout << jsonObject.dump(2) << "\n";


  //std::ofstream outputFile;
  //outputFile.open("TimeOutExample.csv");

  std::cout << "Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess";
  std::cout << std::endl;

  int i = 0; //keeps track of sample #
  std::vector<int> numbers;
  std::vector<int> numbers1;
  std::vector<int> numbers2;
  //std::vector<int> output;
  for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) { //goes thru all keys
    for (auto arrayItr = itr.value().begin(); arrayItr != itr.value().end(); ++arrayItr) { //goes thru all values in key
      //std::cout << *arrayItr << std::endl;
      if (itr.key() != "metadata"){
        numbers.push_back(*arrayItr);
        numbers1.push_back(*arrayItr);
        numbers2.push_back(*arrayItr);
      }
    }
    //std::cout << "HERE" << std::endl;

    if (itr.key() != "metadata") {
      //call sorting
      clock_t start1;
      start1 = clock();
      InsertionSort(&numbers);
      double duration1 = (clock() - start1) / (double) CLOCKS_PER_SEC;

      //output.push_back(countNumComparesInsert);
      //output.push_back(countNumMemAccessInsert);

      clock_t start2;
      start2 = clock();
      MergeSort(&numbers1);
      double duration2 = (clock() - start2) / (double) CLOCKS_PER_SEC;

      //output.push_back(countNumComparesMerge);
      //output.push_back(countNumMemAccessMerge);

      clock_t start3;
      start3 = clock();
      QuickSort(&numbers2);
      double duration3 = (clock() - start3) / (double) CLOCKS_PER_SEC;

      //output.push_back(countNumComparesQuickSort);
      //output.push_back(countNumMemAccessQuickSort);


      std::cout << itr.key() << ",";
      std::cout << duration1 << ",";
      std::cout << countNumComparesInsert << ",";
      std::cout << countNumMemAccessInsert << ",";

      std::cout << duration2 << ",";
      std::cout << countNumComparesMerge << ",";
      std::cout << countNumMemAccessMerge << ",";

      std::cout << duration3 << ",";
      std::cout << countNumComparesQuickSort << ",";
      std::cout << countNumMemAccessQuickSort;

      // countNumComparesQuickSort = 0;
      // countNumMemAccessQuickSort = 0;
      std::cout << std::endl;

    }

    countNumComparesInsert = 0;
    countNumMemAccessInsert = 0;
    countNumComparesMerge = 0;
    countNumMemAccessMerge = 0;
    countNumComparesQuickSort = 0;
    countNumMemAccessQuickSort = 0;
    numbers.clear(); //clears vector to be filled with next sample
    numbers1.clear();
    numbers2.clear();
    i++;
  };



  return 0;
}
