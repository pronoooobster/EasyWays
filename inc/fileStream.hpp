#ifndef FILESTREAM_HPP
#define FILESTREAM_HPP

#include <unordered_map>
#include <fstream>
#include <string>
#include "logisticNode.hpp"
                                                            // functions for data read / write
                                                            // into files

void setFilePath(string _filePath);

void writeHashmap(unordered_map<string, Node> &hashmap);

void readHashmap(unordered_map<string, Node> &hashmap);

#endif