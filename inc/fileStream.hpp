#ifndef FILESTREAM_HPP
#define FILESTREAM_HPP

#include <unordered_map>
#include <fstream>
#include <string>
#include "logisticNode.hpp"
                                                            // functions for data read / write
                                                            // into files
void dataFileInit(fstream &dataFile, string filename);

void dataFileClose(fstream &dataFile);

void writeHashmap(fstream &dataFile, string filename, unordered_map<string, Node> &hashmap);

void readHashmap(fstream &dataFile, unordered_map<string, Node> &hashmap);

#endif