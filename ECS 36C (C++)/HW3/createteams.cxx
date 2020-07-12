
#include "teamdata.h"
#include "priorityqueue.h"
#include "json.hpp"
#include <fstream>
#include <iosream>
using namespace std;

int main(int argc, char** argv) {

  /*TeamData td = TeamData(argv[1]);
  nlohmann::json result;
  int teams[td.getPlayers()/2][2];
  result["teams"]=//arr
  cout << result.dump(2);*/

  std::ifstream ifs(filename);
  nlohmann::json jsonObj;
  if (ifs.is_open()) {
    ifs >> jsonObj;
  }
  int size = jsonObj["metadata"]["numPlayers"];

 PriorityQueue teamStats(size);
 

}
