#include <iostream>
#include "Graph.h"

using namespace std;
using namespace SIAOD;

int main() {
    Graph A(7);
    A.readFile("test.txt");

    stack<int> c;

    c = A.eilerCycle();

    while(!c.empty()) {
        cout << c.top() << "; ";
        c.pop();
    }
    return 0;
}
