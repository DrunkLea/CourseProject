//
// Nan Chen & Shuyao Li
// 915218152 & 915277384

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
using namespace std;

int main(int argc, char** argv) {
	ifstream file;
	file.open(argv[1]);
	nlohmann::json jsonInput, jsonOutput;
	if (file.is_open()) {
		file >> jsonInput;
	}
	jsonOutput["metadata"] = jsonInput["metadata"];
	jsonOutput["metadata"]["file"] = argv[1];

	int totalCount = 0;
	int i = 0;
	for (auto itr = jsonInput.begin(); (itr != jsonInput.end()) && (i < jsonInput["metadata"]["numSamples"]); ++itr,++i) {
		cout << "sample group: " << i << "\n";


		int j = 0;
		int end = jsonInput["metadata"]["arraySize"];
		bool inver = 0;
		for (auto arrayItr = jsonInput[itr.key()].begin(); (arrayItr != jsonInput[itr.key()].end())&&(j < end-1);++arrayItr,++j) {
			cout << "j=" << j << " pairs: " << *arrayItr << " " << *(arrayItr+1) << "\n";
			if (*arrayItr > *(arrayItr+1)){
				inver = 1;
 				jsonOutput[itr.key()]["ConsecutiveInversions"][to_string(j)] = {*arrayItr, *(arrayItr+1)};
			}
		}
		if (inver){
			totalCount ++;
			jsonOutput[itr.key()]["sample"] = jsonInput[itr.key()];
		}
	}

	jsonOutput["metadata"]["samplesWithInversions"] = totalCount;
	cout << jsonOutput.dump(2) << "\n";
	file.close();
}
