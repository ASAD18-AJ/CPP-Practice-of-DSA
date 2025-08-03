#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;


class Heap {
    vector<int> vec;
public:
    void push(int val) {
        vec.push_back(val);

        int x = vec.size() - 1;
        int parI = (x-1)/2;

        while(parI > 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void pop() {

    }

    int top() {

    }
}

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);

    while(!pq.empty()) {
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}