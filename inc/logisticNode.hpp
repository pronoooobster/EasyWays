#include <string>
#include <vector>

#ifndef LOGISTICNODE_HPP
#define LOGISTICNODE_HPP

using namespace std;

class Node {

    public:
    
    vector< pair< string, int > > connections;

    Node();
    Node(vector< pair< string, int > > _connections);
};

#endif