#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public: 
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for(int u=0; u<V; u++) {
            list<int> neighbours = l[u];
            cout<<u<< " : ";
            for(int v: neighbours) {
                cout << v << " ";
            }
            cout << endl;
        }
        
    }

    void bfs() {
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;

        while(q.size()>0) {
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            list<int> neighbours = l[u];
            for(int v: neighbours) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &vis ){
        vis[u] = true;
        cout << u << " ";

        list<int> neighbours = l[u];
        for(int v : neighbours) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(7,false);
        dfsHelper(0, vis);
        cout << endl;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    // graph.bfs();
    graph.dfs();

    return 0;
}