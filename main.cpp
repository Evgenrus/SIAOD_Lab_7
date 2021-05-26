#include <iostream>
#include "Graph.h"

using namespace std;
using namespace SIAOD;

int main() {
    Graph A(7);
    A.readFile("test.txt");

    //stack<int> c;
    A.show();
    cout << endl << endl;
    //c = A.eilerCycle();
    Graph c = A.Kruskal();

    c.show();

    return 0;
}
