#include <iostream>
#include <fstream>
#include <conio.h>
#include <unordered_map>
#include <string>
#include <vector>
#include "../inc/menuPages.hpp"
#include "../inc/logisticNode.hpp"
#include "../inc/fileStream.hpp"

using namespace std;

void clearscr();
void intro(unordered_map<string, Node> &network);

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
        break;
    
    default:
        intro(network);
        break;
    }
}

void clearscr() {
    cout << "\x1B[2J\x1B[H";
}