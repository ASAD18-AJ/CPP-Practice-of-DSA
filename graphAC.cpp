#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *l;

public: 
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
}