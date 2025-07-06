#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

// template<class T>
// class Stack {
//     vector<T> vec;
// public: 
//     void push(int val) {
//         vec.push_back(val);
//     }

//     void pop() {
//         if(isEmpty()){
//             cout << "Stack is empty. \n";
//             return;
//         } 
//         vec.pop_back();
//     }

//     int top() {
//         if(isEmpty()) {
//             cout << "Stack is empty. \n";
//             return -1; // or throw an exception
//         }
//         int lastIdx = vec.size() - 1;
//         return vec[lastIdx];
//     }

//     bool isEmpty() {
//         return vec.size()==0;
//     }
// };

//create stack using linked list
//template<class T>
// class Stack {
//     list<T> ll;

// public: 
//     void push(T val) {
//         ll.push_back(val);
//     }

//     void pop() {
//         ll.pop_front();
//     }

//     T top() {
//         return ll.front();
//     }

//     bool isEmpty() {
//         return ll.size() == 0;
//     }
// };

template<class T>
class Node { 
public:
    T data;
    Node* next; 
    Node(T val) {
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack {
    Node<T>* head;
public: 
    Stack() {
        head = NULL;
    }
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop() {
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top() {
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};



int main() {
    Stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    //STL stack
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}