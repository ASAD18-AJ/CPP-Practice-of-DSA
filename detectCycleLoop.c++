#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class List {
public: 
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        
        if(tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop_front() {
    if(head == NULL) {
        return;
    }

    Node* temp = head;
    head = head->next;

    temp->next = NULL;
    delete temp;
}
};

bool isCycle(Node* head) {
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout << "Cycle exists\n";
            return true;
        }
    }

    cout << "No cycle exists\n";
    return false;
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void removeCycle(Node* head) {
    Node* fast = head;
    Node* slow = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout << "Cycle exists\n";
            isCycle = true;
            break;
        }
    }

    if(!isCycle) {
        cout << "Cycle doesn't exist\n";
        return;
    }

    slow = head;
    if(slow == fast) {   //special case : tail -> head
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    } else {
        Node* prev = fast;
        while(slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL & fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }
    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans;
}

void mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, rightHead);
}


int main() {
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head;

    // isCycle(ll.head);
    removeCycle(ll.head);
    printList(ll.head);
}