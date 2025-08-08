#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int toSize;
    int currSize;
    Node** table;

    int HashFunction(string key) {
        int idx = 0;

        for(int i=0;i<key.size();i++) {
            idx = idx + (key[i]*key[i])%totSize;
        }
        return idx;
    }

    void rehash() {
        Node* oldTable = table;
        int oldSize = toSize;

        totSize = 2*totSize;
        table = new Node*[totSize];
        for(int i=0;i<totSize;i++) {
            table[i] = NULL;
        }

        for(int i=0;i<oldSize;i++) {
            Node* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size) {
        toSize = size;
        currize = 0;

        table = new Node*[totSize];
        for(int i=0;i<totSize;i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, val) {
        int idx = HashFunction(key);

        Node* newNode = new Node(key, val);
        Node* head = table[idx];

        newNode->next = head;
        head = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda > 1) {
            rehash();
        }
    }
    
    void remove(string key) {

    }

    int search(string key) {

    }
}