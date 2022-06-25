#include <iostream>
#include <fstream>
#include <conio.h>
#include <unordered_map>
#include <string>
#include "../inc/menuPages.hpp"
#include "../inc/logisticNode.hpp"

using namespace std;

void clearscr();
void intro(unordered_map<string, Node> &network);
                                    // current logistics network page
void currentNetwork(unordered_map<string, Node> &network) {
    int ans = 0;
    unordered_map<string, Node> :: iterator it = network.begin();

    clearscr();
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
        break;

    case 3:
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