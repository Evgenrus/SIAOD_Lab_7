//
// Created by EVGEN on 25.04.2021.
//

#include <sstream>
#include "Graph.h"

namespace SIAOD {
    Graph::Graph(unsigned int size, list<int> *data) : m_size(size) {
        m_data = new list<int>[size];
        if(data != nullptr)
            std::copy(data, data + size, m_data);
    }

    Graph::Graph(Graph &A) : m_size(A.m_size) {
        m_data = new list<int>[m_size];
        for(int i = 0; i < m_size; i++)
            m_data[i] = A.m_data[i];
    }

    Graph::~Graph() {
        delete[] m_data;
    }

    Graph &Graph::readFile(string fileName) {
        ifstream file(fileName);
        string temp;
        int dot;

        if(!file.is_open())
            throw "Couldn't open file";
        file >> m_size;

        for(int i = 0; i < m_size; i++) {
            getline(file, temp);
            istringstream iss(temp);
            while(!iss.eof()) {
                iss >> dot;
                m_data[i].push_back(dot);
                cout << dot << " pushed on list " << i << endl;
            }
        }
    }

    stack<int> &Graph::eilerCycle() {
        stack<int> cycle1;
        stack<int> cycle2;
        int current = 0;
        cycle1.push(m_data[0].front());

        while(!cycle1.empty()) {
            current = cycle1.top();
            if(!m_data[current].empty()) {
                int temp = m_data[current].front();
                cycle1.push(temp);

                this->removeFromList(current, temp);
                this->removeFromList(temp, current);
            } else {
                current = cycle1.top();
                cycle1.pop();
                cycle2.push(current);
            }
        }

        return cycle2;
    }

    void Graph::removeFromList(int k, int find) {
        it = m_data[k].begin();
        while(*it != find || it != m_data[k].end()) {
            it++;
        }
        if(*it == find)
            m_data[k].erase(it);
    }

}

