#include "..\inc\logisticNode.hpp"
                                // default Node constructor
Node::Node() {
    name = "";
    connections = {};
}
                                // Node constructor with name and connections set
Node::Node(std::string _name, std::vector< std::pair< std::string, int > > _connections) {
    name = _name;
    connections = _connections;
}

