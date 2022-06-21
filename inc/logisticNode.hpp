#include <string>
#include <vector>

#ifndef LOGISTICNODE_HPP
#define LOGISTICNODE_HPP

using namespace std;

class Node {

    public:
    
    string name;
    vector< pair< string, int > > connections;

    Node();
    Node( string _name, vector< pair< string, int > > _connections);
};

#endif