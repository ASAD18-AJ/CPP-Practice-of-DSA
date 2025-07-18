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

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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
    return ans.head;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node* zigZagLL(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    //alternate merging
    Node* right = rightHeadRev;
    Node* left = head;
    Node* tail = right;

    while(left != NULL && right != NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {
        tail->next = right;
    }

    return head;
}


int main() {
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    printList(ll.head);

    // ll.tail->next = ll.head;

    // isCycle(ll.head);
    // removeCycle(ll.head);
    // ll.head = mergeSort(ll.head);

    ll.head = zigZagLL(ll.head);
    printList(ll.head);
}