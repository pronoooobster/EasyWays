#include <iostream>
#include <fstream>
#include <conio.h>
#include "../inc/menuPages.hpp"

using namespace std;

void clearscr();
                                    // intro menu page
int intro() {
    int ans = 0;

    clearscr();
    cout << "\t Easy Ways logictics app\n";
    cout << "\t made by Andrew D.\n\n";
    cout << "\t 1. Current logistics network\n";
    cout << "\t 2. Add a transportation node\n";
    cout << "\t 3. Remove a transportation node\n";
    cout << "\t 4. Caclucate an optimal route between nodes\n";
    cin >> ans;
    return ans;
}

void clearscr() {
    cout << "\x1B[2J\x1B[H";
}