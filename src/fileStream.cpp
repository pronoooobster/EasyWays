#include "../inc/fileStream.hpp"
#include "../inc/logisticNode.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
                                                                // functions for data read / write
                                                                // into files

void dataFileInit(fstream &dataFile, string filename) {
    dataFile.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    if(!dataFile) {
        dataFile.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
    }
}

void dataFileClose(fstream &dataFile) {
    dataFile.close();
}

void writeHashmap(fstream &dataFile, string filename, unordered_map<string, Node> &hashmap) {
    unordered_map<string, Node> :: iterator it = hashmap.begin();
    dataFile.close();
    dataFile.open(filename, std::fstream::out | std::fstream::in | std::fstream::trunc);

    while(it != hashmap.end()) {
        dataFile << it -> first << "\n";

        for(int i = 0; i < (it -> second).connections.size(); ++i) {
            dataFile << (it -> second).connections[i].first << " ";
            dataFile << (it -> second).connections[i].second << "\n";
        }

        dataFile << "#\n";
        it++;
    }
}

void readHashmap(fstream &dataFile, unordered_map<string, Node> &hashmap) {
                                                // move cursor to the begining
    dataFile.clear();
    dataFile.seekg(0, dataFile.beg);

    hashmap.clear();
    string name, elementFirst = "#";
    int elementSecond;

    while(true) {
        dataFile >> name;
        
        if(dataFile.eof()) break;
        
        hashmap[name] = Node();
        while(true) {
            dataFile >> elementFirst;
            if(elementFirst == "#") break;
            dataFile >> elementSecond;
            hashmap[name].connections.push_back({elementFirst, elementSecond});
        }
    }
}