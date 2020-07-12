//
// Nan Chen & Shuyao Li
// 915218152 & 915277384

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
#include "priorityqueue.h"
using namespace std;

int main(int argc, char** argv) {
  ifstream file;
	file.open(argv[1]);
	nlohmann::json jsonObj;
	if (file.is_open()) {
		file >> jsonObj;
	}

  size_t s = jsonObj["metadata"]["maxHeapSize"];
  PriorityQueue queueObj(s);
  for (auto itr = jsonObj.begin(); itr != jsonObj.end(); ++itr) {
    if(itr.key() == "metadata")
      break;

    string str = jsonObj[itr.key()]["operation"];
    if (str.compare("insert") == 0){
      Key k=jsonObj[itr.key()]["key"];
      queueObj.insert(k);
    }else if (str.compare("removeMin") == 0) {
      queueObj.removeMin();
    }
  }

  nlohmann::json jsonOut = queueObj.JSON();
  jsonOut["metadata"]["numOperations"] = jsonObj["metadata"]["numOperations"];
  cout << jsonOut.dump(2);
}
