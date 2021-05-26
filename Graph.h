//
// Created by EVGEN on 25.04.2021.
//

#ifndef LAB7_GRAPH_H
#define LAB7_GRAPH_H

#include "iostream"
#include "list"
#include "fstream"
#include "string"
#include "stack"

using namespace std;

namespace SIAOD {

    struct ostTree {
        int origin;
        int dest;
        int range;

        bool operator <(const ostTree &b) const {
            return this->range < b.range;
        }
    };

    struct Node {
        int node;
        int range = 1;
    };

    class Graph {
    private:
        list<Node> *m_data;
        unsigned  m_size;
        list<int> marked;
    public:
        explicit Graph(unsigned size = 0, list<Node> *data = nullptr);

        Graph(const Graph &A);

        ~Graph();

        Graph & readFile(const string& fileName);

        stack<int> eilerCycle();

        Graph Kruskal();

        void removeFromList(int k, int find);

        void show();

    private:
        list<ostTree> sort();

        static bool treeCmp(ostTree a, ostTree b);

        bool isMarked(int ref);
    };
}


#endif //LAB7_GRAPH_H
