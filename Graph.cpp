//
// Created by EVGEN on 25.04.2021.
//

#include <sstream>
#include <algorithm>
#include "Graph.h"

namespace SIAOD {

    Graph::Graph(unsigned int size, list<Node> *data) : m_size(size) {
        m_data = new list<Node>[size];
        if(data != nullptr)
            std::copy(data, data + size, m_data);
    }

    Graph::Graph(const Graph &A) : m_size(A.m_size) {
        m_data = new list<Node>[m_size];
        for(int i = 0; i < m_size; i++)
            m_data[i] = A.m_data[i];
    }

    Graph::~Graph() {
        delete[] m_data;
    }

    Graph &Graph::readFile(const string& fileName) {
        ifstream file(fileName);
        string temp;
        int dot;

        if(!file.is_open())
            throw "Couldn't open file";
        getline(file, temp);
        stringstream iss(temp);
        iss >> m_size;

        for(int i = 0; i < m_size; i++) {
            getline(file, temp);
            stringstream iss(temp);
            while(!iss.eof()) {
                iss >> dot;
                //iss >> rang;
                Node tem = {dot, i + dot};
                m_data[i].push_back(tem);
                cout << dot << " pushed on list " << i << endl;
            }
        }
        return *this;
    }

    stack<int> Graph::eilerCycle() {
        stack<int> cycle1;
        stack<int> cycle2;
        int current;
        cycle1.push(m_data[0].front().node);

        while(!cycle1.empty()) {
            current = cycle1.top();
            if(!m_data[current].empty()) {
                int temp = m_data[current].front().node;
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

    Graph Graph::Kruskal(){
        Graph T(7);
        auto LE = sort();

        int origin = LE.front().origin;
        int dest = LE.front().dest;
        int range = LE.front().range;
        Node temp {dest, range};
        T.m_data[origin].push_back(temp);
        cout << "pushed " << origin << " - " << dest << endl;
        T.marked.push_back(origin);
        //T.marked.push_back(dest);
        LE.pop_front();

        while(!LE.empty()) {
            ostTree temper = LE.front();
            LE.pop_front();
            if(T.isMarked(temper.dest) == T.isMarked(temper.origin)) {
                T.m_data[temper.origin].push_back(Node {temper.dest, temp.range});
                T.marked.push_back(temper.origin);
                cout << "pushed " << temper.origin << " - " << temper.dest << endl;
            }
        }

        return T;
    }

    void Graph::removeFromList(int k, int find) {
        for(auto iter = m_data[k].begin(); iter != m_data[k].end(); iter++){
            if(iter->node == find && iter != m_data[k].end()) {
                iter = m_data[k].erase(iter);
                break;
            }
        }
    }

    bool Graph::treeCmp(ostTree a, ostTree b) {
        return a.range < b.range;
    }

    list<ostTree> Graph::sort() {
        list<ostTree> LE;
        for(int i = 0; i < m_size; i++) {
            auto iter = m_data[i].begin();
            while(iter != m_data[i].end()) {
                ostTree temp = ostTree {i, iter->node, iter->range};
                LE.push_back(temp);
                iter++;
            }
        }

        LE.sort();

        return LE;
    }

    bool Graph::isMarked(int ref) {
        bool res = false;
        if(!marked.empty()) {
            auto temp = std::find(marked.begin(), marked.end(), ref);
            if(temp != marked.end())
                res = true;
            cout << ref << " == " << *temp << endl;
        }
        return res;
    }

    void Graph::show() {
        for(int i = 0; i < m_size; i++) {
            auto iter = m_data[i].begin();
            cout << i << " : ";
            while(iter != m_data[i].end()) {
                cout << iter->node << "; ";
                iter++;
            }
            cout << endl;
        }
    }

}

