#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../inc/logisticNode.hpp"
#include "../inc/menuPages.hpp"
#include "../inc/fileStream.hpp"
#include <unordered_map>

using namespace std;

int main() {
    const string dataFilePath = "../data/nodesData.dat";
    unordered_map<string, Node> network;
                                                    // initiation of the data file
    setFilePath(dataFilePath);
    
    readHashmap(network);

    intro(network);

    return 0;
}