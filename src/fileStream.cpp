#include "../inc/fileStream.hpp"
#include "../inc/logisticNode.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
                                                                // functions for data read / write
                                                                // into files
string filePath = "";
ifstream inputFile;
ofstream outputFile;

void setFilePath(string _filePath) {
    filePath = _filePath;
}

void writeHashmap(unordered_map<string, Node> &hashmap) {
    unordered_map<string, Node> :: iterator it = hashmap.begin();

    outputFile.open(filePath, std::fstream::out | std::fstream::trunc);

    while(it != hashmap.end()) {
        outputFile << it -> first << "\n";

        for(int i = 0; i < (it -> second).connections.size(); ++i) {
            outputFile << (it -> second).connections[i].first << " ";
            outputFile << (it -> second).connections[i].second << "\n";
        }

        outputFile << "#\n";
        it++;
    }

    outputFile.clear();
    outputFile.close();
}

void readHashmap(unordered_map<string, Node> &hashmap) {
    inputFile.open(filePath);
    string name, elementFirst = "#";
    int elementSecond;

    while(true) {
        inputFile >> name;
        if(inputFile.eof()) break;
        
        hashmap[name] = Node();
        while(true) {
            inputFile >> elementFirst;
            if(elementFirst == "#") break;
            inputFile >> elementSecond;
            hashmap[name].connections.push_back({elementFirst, elementSecond});
        }
    }

    inputFile.clear();
    inputFile.close();
}