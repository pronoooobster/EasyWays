#include "../inc/logisticNode.hpp"

using namespace std;
                                // default Node constructor
Node::Node() {
    connections = {};
}
                                // Node constructor with name and connections set
Node::Node(vector< pair< string, int > > _connections) {
    connections = _connections;
}

