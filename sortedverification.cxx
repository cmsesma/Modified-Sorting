// Created by Chelsy Sesma on 4/15/18.
//
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"

int main(int argc, char** argv) {

  std::ifstream file;
  file.open(argv[1]);
  nlohmann::json jsonObject;
  if (file.is_open()) {
    file >> jsonObject;
  }

  int arraySize = jsonObject["metadata"]["arraySize"];
  int numSamples = jsonObject["metadata"]["numSamples"];
  std::vector<int> val;


  nlohmann::json resultObject;

  int location = 0;
  int i = 1;
  int numConsecInversion = 0;
  int numSamplesWithInversion = 0;
  int prevNum;
  for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) { //goes thru all keys
    int count = 0;
    location = 0;
    for (auto arrayItr = itr.value().begin(); arrayItr != itr.value().end(); ++arrayItr){ //goes thru all values in key
      location++;
      if (count != 0){ //if its not the first value in the list
        if (prevNum >= *arrayItr && itr.key() != "metadata"){
          numConsecInversion++;


          val.push_back(prevNum);
          val.push_back(*arrayItr);


          resultObject[itr.key()]["ConsecutiveInversions"][std::to_string(location-2)] = val;

          i++;
          val.pop_back();
          val.pop_back();
          prevNum = *arrayItr;
        } else {
          prevNum = *arrayItr;
        }
        count++;

      } else { //if it is first value go to next value
        prevNum = *arrayItr;
        count++;
      }
    }
    if (numConsecInversion != 0 && itr.key() != "metadata"){ //if sample DOES have a consec inversion
      numSamplesWithInversion++;

      resultObject[itr.key()]["sample"] = itr.value();

      numConsecInversion = 0;

    } else { //if sample does NOT have consec inversion
      numConsecInversion = 0;
    }
  }


  resultObject["metadata"]["arraySize"] = arraySize;
  resultObject["metadata"]["file"] = argv[1];


  resultObject["metadata"]["numSamples"] = numSamples;
  resultObject["metadata"]["samplesWithInversions"] = numSamplesWithInversion;


  std::cout << resultObject.dump(2) << "\n";


  return 0;
}