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
    class Graph {
    private:
        list<int> *m_data;
        unsigned  m_size;
        list<int> :: iterator it;
    public:
        Graph(unsigned size = 0, list<int> *data = nullptr);

        Graph(Graph &A);

        ~Graph();

        Graph& readFile(string fileName);

        stack<int>& eilerCycle();

        void removeFromList(int k, int find);
    };
}


#endif //LAB7_GRAPH_H
