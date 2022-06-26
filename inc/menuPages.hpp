#ifndef MENUPAGES_HPP
#define MENUPAGES_HPP

#include <unordered_map>
#include <fstream>
#include "logisticNode.hpp"

void clearscr();
void intro(unordered_map<string, Node> &network);
void currentNetwork(unordered_map<string, Node> &network);
void removeNode(unordered_map<string, Node> &network);
void addNode(unordered_map<string, Node> &network);

#endif