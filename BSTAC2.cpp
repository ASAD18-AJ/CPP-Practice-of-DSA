#include<iostream>
#include<vector>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildBSTfromSorted(int arr[], int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end -st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromSorted(arr, st, mid - 1);
    curr->right = buildBSTfromSorted(arr, mid + 1, end);

    return curr;
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


//BST to Balanced BST
//1. Convert BST to sorted array
//2. Build BST from sorted array
Node* BSTfromSortedVec(vector<int> &arr, int st, int end) {
    if(st > end) {
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = BSTfromSortedVec(arr, st, mid - 1);
    curr->right = BSTfromSortedVec(arr, mid + 1,end);

    return curr;
}

void getInorder(Node* root, vector<int> &arr) {
    if(root == NULL) {
        return;
    }

    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);
}

Node* balanceBST(Node* root) {
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTfromSortedVec(nodes, 0, nodes.size()-1);
}


//merge 2 bst
Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;
    while(i < nodes1.size() && j < nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }

    while(i < nodes1.size()) {
        merged.push_back(nodes1[i++]);
    }

    while(j < nodes2.size()) {
        merged.push_back(nodes2[j++]);
    }

    return BSTfromSortedVec(merged, 0, merged.size()-1);
}

int main() {
    // int arr[] = {3, 4, 5, 6, 7, 8, 9};

    // Node* root = buildBSTfromSorted(arr, 0, 6);
    // preorder(root);
    // cout << endl;

    //BST to Balanced BST
    // Node* root = new Node(6);
    // root->left = new Node(5);
    // root->left->left = new Node(4);
    // root->left->left->left = new Node(3);

    // root->right = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->right = new Node(9);

    // root = balanceBST(root);
    // preorder(root);
    // cout << endl;

    //merge 2 bst
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBSTs(root1, root2);
    preorder(root);
    cout << endl;
    return 0;
}