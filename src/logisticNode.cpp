#include "../inc/logisticNode.hpp"

using namespace std;
                                // default Node constructor
Node::Node() {
    name = "";
    connections = {};
}
                                // Node constructor with name and connections set
Node::Node( string _name, vector< pair< string, int > > _connections) {
    name = _name;
    connections = _connections;
}

