#include <iostream>
#include <fstream>
#include <conio.h>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include "../inc/menuPages.hpp"
#include "../inc/logisticNode.hpp"
#include "../inc/fileStream.hpp"

using namespace std;

void clearscr();
void intro(unordered_map<string, Node> &network);

                                    // calculating a route between two nodes
                                    // using Dijkstra's algorithm
void calculateRoute(unordered_map<string, Node> &network) {
    clearscr();
    readHashmap(network);
    unordered_map<string, Node> :: iterator it;

    string fromNode, toNode;
                                    // reading the data from the user
    cout << "\t Caclucate an optimal route between nodes\n";
    cout << "\n\tEnter the start node of the route: ";
    cin >> fromNode;
    cout << "\n\tEnter the end node of the route: ";
    cin >> toNode;

                                    // check if the start and the end nodes are in the network
    if(network.find(fromNode) == network.end()) {
        cout << "\n\t" << fromNode << " is not in the nodes list!\n" << "\tPress 1 to return to the home menu \n";
        cin >> fromNode;
        intro(network);
    }

    if(network.find(toNode) == network.end()) {
        cout << "\n\t" << toNode << " is not in the nodes list!\n" << "\tPress 1 to return to the home menu \n";
        cin >> toNode;
        intro(network);
    }

                                    // Dijkstra's algorithm
    const int INF = 0x3f3f3f3f;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> vert;
    
    unordered_map<string, pair<string, int>> prev;

    unordered_map<string, int> dist;
    for(it = network.begin(); it != network.end(); it++) {
        dist[it -> first] = INF;
    }
    
    dist[fromNode] = 0;
    vert.push({0, fromNode});

    while(!vert.empty()) {
        string curr = vert.top().second;
        vert.pop();

        vector<pair<string, int>> connections = network[curr].connections;
        for(int i = 0; i < connections.size(); ++i) {
            string adj = connections[i].first;
            int weight = connections[i].second;

            if(dist[adj] > (dist[curr] + weight)) {
                dist[adj] = dist[curr] + weight;
                vert.push({(dist[curr] + weight), adj});
                prev[adj] = {curr, (weight)};
            }
        }
    }

                                    // output of the result
    clearscr();

    if(prev.find(toNode) == prev.end()) {
        cout << "\n\tIt is impossible to get from " << fromNode << " to " << toNode << "\n\n";
        cout << "\tPress 1 to return to the home menu \n";
        cin >> fromNode;
        intro(network);
    }
    
    vector<pair<string, int>> result;
    string curr = toNode;
    result.push_back({toNode, -1});
    while(true) {
        if(curr == fromNode) break;

        result.push_back(prev[curr]);
        curr = prev[curr].first;
    }

    cout << "\n\tThe shortest route from " << fromNode << " to " << toNode << " is:\n\n";
    cout << "\t ";
    for(int i = result.size() - 1; i > 0; --i) {
        cout << result[i].first << " - " << result[i].second << " - ";
    }
    cout << result[0].first << "\n\n";
    cout << "\tAnd takes " << dist[toNode] << " minutes\n\n";

    cout << "\tPress 1 to return to the home menu \n";
    cin >> fromNode;
    intro(network);
}

                                    // transportation node adding menu
void addNode(unordered_map<string, Node> &network) {
    clearscr();
    readHashmap(network);

    string nodeName, inputStr;
    int inputInt, numberOfConns;

    cout << "\t Add a node to the network\n\n";
    cout << "\tNode name: ";
    cin >> nodeName;

    network[nodeName] = Node();
    
    cout << "\n\tEnter node connections (end with q as a Direction)\n";
    while(true) {
        cout << "\tDirection: ";
        cin >> inputStr;

        if(inputStr == "q" || inputStr == "Q") break;

        cout << "\tLength (minutes): ";
        cin >> inputInt;

        network[nodeName].connections.push_back({inputStr, inputInt});
    }

    writeHashmap(network);
    intro(network);
}

                                    // transportation node remove menu
void removeNode(unordered_map<string, Node> &network) {
    string ans = "";
    unordered_map<string, Node> :: iterator it = network.begin();
    readHashmap(network);

    clearscr();
    cout << "\t Nodes in the network:\n";

    while(it != network.end()) {
        cout << "\t\t" << it -> first << "\n";
        it++;
    }

    while(true) {
        cout << "\tEnter the name of the node to delete (or 1 to return to the home menu): ";
        cin >> ans;
        
        if(ans == "1") {
            break;
        }

        if(network.find(ans) == network.end()) {
            cout << "\n\t" << ans << " is not in the nodes list!\n";
        } else {
            network.erase(network.find(ans));
            writeHashmap(network);
            cout << "\n\t" << ans << " is removed from the list! \n\tEnter 1 to return to the home menu\n";
            cin >> ans;
            break;
        }
    }
    intro(network);
}

                                    // current logistics network page
void currentNetwork(unordered_map<string, Node> &network) {
    clearscr();

    int ans = 0;
    unordered_map<string, Node> :: iterator it = network.begin();
    readHashmap(network);

    cout << "\t Current logistics network:\n";
    
    while(it != network.end()) {
        cout << "\tName: " << it -> first << "\n";
        cout << "\t\tConnections:\n";
        for(int i = 0; i < (it -> second).connections.size(); ++i) {
            cout << "\t\tDirection: " << (it -> second).connections[i].first << "; Length (minutes): "<< (it -> second).connections[i].second << ";\n";
        }
        it++;
    }
    cout << "\n\t1. To the home menu\n";
    cin >> ans;

    intro(network);
}

                                    // intro menu page
void intro(unordered_map<string, Node> &network) {
    int ans = 0;

    clearscr();
    cout << "\t Easy Ways logictics app\n";
    cout << "\t made by Andrew D.\n\n";
    cout << "\t 1. Current logistics network\n";
    cout << "\t 2. Add a transportation node\n";
    cout << "\t 3. Remove a transportation node\n";
    cout << "\t 4. Caclucate an optimal route between nodes\n\n";
    cout << "\t Choose a number and press Enter\n";
    cin >> ans;
    switch (ans)
    {
    case 1:
        currentNetwork(network);
        break;
    
    case 2:
        addNode(network);
        break;

    case 3:
        removeNode(network);
        break;

    case 4: 
        calculateRoute(network);
        break;
    
    default:
        intro(network);
        break;
    }
}

void clearscr() {
    cout << "\x1B[2J\x1B[H";
}