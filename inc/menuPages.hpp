#ifndef MENUPAGES_HPP
#define MENUPAGES_HPP

#include <unordered_map>
#include "logisticNode.hpp"

void clearscr();
void intro(unordered_map<string, Node> &network);
void currentNetwork(unordered_map<string, Node> &network);

#endif