#include <string>
#include <vector>

#ifndef LOGISTICNODE_HPP
#define LOGISTICNODE_HPP

class Node {

    public:
    
    Node();
    Node( std::string _name, std::vector< std::pair< std::string, int > > _connections);
    std::string name;
    std::vector< std::pair< std::string, int > > connections;

};

#endif