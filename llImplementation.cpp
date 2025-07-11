#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
    ~Node() {
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }
    ~List() {
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }

    void insert(int val, int pos) {
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {
                cout << "position is INVALID" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        Node* temp = head;

        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        temp->next = NULL;
        tail = temp;
    }

    int searchItr(int key) {
        Node* temp = head;
        int idx = 0;

        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int helper(Node* head, int key) {
        Node* temp = head;
        if(temp == NULL) {
            return -1;
        }

        if(head->data == key) {
            return 0;
        }

        int idx = helper(head->next, key);
        if(idx == -1) {
            return -1;
        }
        return idx + 1;
        
    }

    int searchRec(int key) {
        return helper(head, key);
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize() {
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n) {
        int size = getSize();
        Node* prev = head;

        for(int i=1;i<(size-n);i++) {
            prev = prev->next;
        }
        
        Node* toDel = prev->next;
        cout << "going to delete: " << toDel->data << endl;
        prev->next = prev->next->next;
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    // ll.insert(100, 2);

    // ll.pop_back();
    // ll.printList();

    ll.reverse();
    // ll.printList();

    ll.removeNth(2);
    ll.printList();

    // cout << ll.searchItr(2) << endl;
    return 0;
}