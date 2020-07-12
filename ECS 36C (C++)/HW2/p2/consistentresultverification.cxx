//
// Shuyao Li
// 915277384
// Copyright [2019] <Shuyao Li>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
using namespace std;

int main(int argc, char** argv) {
  ifstream file1,file2;
  file1.open(argv[1]);
  file2.open(argv[2]);
  nlohmann::json ex1, ex2;
  if (file1.is_open()&&file2.is_open()) {
    file1 >> ex1;
    file2 >> ex2;
  }
  ex1["metadata"]["name"] = argv[1];
  ex2["metadata"]["name"] = argv[2];
  int count = 0;
  nlohmann::json output;


  for ( auto itr = ex1.begin();(itr != ex1.end()) && (count < ex1["metadata"]["numSamples"]); ++itr) {
    string misSpNum = itr.key();

    auto arrayItr1 = ex1[itr.key()].begin();
    auto arrayItr2 = ex2[itr.key()].begin();
    int misCount = 0;
    for (;arrayItr1 != ex1[itr.key()].end();++arrayItr1, ++arrayItr2) {
      if (*arrayItr1 != *arrayItr2){
        misCount++;
        output[misSpNum]["Mismatches"][to_string(misCount)] = {*arrayItr1,*arrayItr2};
      }
    }
    if(misCount == 0)
      continue;
      
    count++;

    string tmp = ex1["metadata"]["name"];
    output[misSpNum][tmp] = ex1[misSpNum]; //put sample array under name key
    tmp = ex2["metadata"]["name"];
    output[misSpNum][tmp] = ex2[misSpNum];
  }

  output ["metadata"]["File1"] = ex1["metadata"];
  output ["metadata"]["File2"] = ex2["metadata"];
  output ["metadata"]["samplesWithConflictingResults"] = count;
  cout << output.dump(2) << "\n";

  file1.close();
  file2.close();
}
