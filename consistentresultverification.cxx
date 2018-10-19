#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"

int main(int argc, char** argv) {

  std::ifstream file1;
  file1.open(argv[1]);
  nlohmann::json jsonObject1;
  if (file1.is_open()) {
    file1 >> jsonObject1;
  }

  std::ifstream file2;
  file2.open(argv[2]);
  nlohmann::json jsonObject2;
  if (file2.is_open()) {
    file2 >> jsonObject2;
  }

  int arraySize1 = jsonObject1["metadata"]["arraySize"];
  int numSamples1 = jsonObject1["metadata"]["numSamples"];
  int arraySize2 = jsonObject2["metadata"]["arraySize"];
  int numSamples2 = jsonObject2["metadata"]["numSamples"];

  std::vector<int> val;

  nlohmann::json resultObject;
  int i = 1;
  int numTotalConflicting = 0;
  int numSamplesWithConflictingResults = 0;
  for (auto itr1 = jsonObject1.begin(), itr2 = jsonObject2.begin(); itr1 != jsonObject1.end() && itr2 != jsonObject2.end(); ++itr1, ++itr2) { //goes thru all jsonObject1 keys
      for (auto arrayItr1 = itr1.value().begin(), arrayItr2 = itr2.value().begin(); arrayItr1 != itr1.value().end() && arrayItr2 != itr2.value().end(); ++arrayItr1, ++arrayItr2) { //goes thru all values in key

          if (*arrayItr1 != *arrayItr2 && itr1.key() != "metadata" && itr2.key() != "metadata"){ //if they don't match up
            numTotalConflicting++;


            val.push_back(*arrayItr1);
            val.push_back(*arrayItr2);

            resultObject[itr1.key()]["Mismatches"][std::to_string(i)] = val;

            i++;
            val.pop_back();
            val.pop_back();

            resultObject[itr1.key()][argv[1]] = itr1.value();
            resultObject[itr1.key()][argv[2]] = itr2.value();
          } else { //if they match up

          }



    }
    if (numTotalConflicting != 0){ //counts how many samples in total have conflicting results
      numSamplesWithConflictingResults++;
      numTotalConflicting = 0;
    } else {
      numTotalConflicting = 0;
    }
  }



  resultObject["metadata"]["File1"]["arraySize"] = arraySize1;
  resultObject["metadata"]["File1"]["name"] = argv[1];

  resultObject["metadata"]["File1"]["numSamples"] = numSamples1;

  resultObject["metadata"]["File2"]["arraySize"] = arraySize2;
  resultObject["metadata"]["File2"]["name"] = argv[2];

  resultObject["metadata"]["File2"]["numSamples"] = numSamples2;

  resultObject["metadata"]["samplesWithConflictingResults"] = numSamplesWithConflictingResults;


  std::cout << resultObject.dump(2) << "\n";

  return 0;

} //end of main
