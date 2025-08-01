#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }
    if(val < root->data) { //left subtree
        root->left = insert(root->left, val);
    } else { //right subtree
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0;i<n;i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root, int key) { //O(height)
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }

    if(val < root->data) { //left subtree
        root->left = delNode(root->left, val);
    } else if(val > root->data) { //right subtree
        root->right = delNode(root->right, val);
    } else {
        //root == val
        //case1: 0 children
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //case2: 1 child
        if(root->left == NULL || root->right == NULL) {
            return root->left ? root->left : root->right;
        }

        //case3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); //case1, case2
        return root;
    }
}

void printInRange(Node* root, int start, int end) {
    if(root == NULL) {
        return;
    }

    if(start <= root->data && root->data <= end) {//case1
        cout << root->data << " ";
        printInRange(root->left, start, end);
        printInRange(root->right, start, end);
    } else if(root->data < start) { //case2
        printInRange(root->right, start, end);
    } else {//case3
        printInRange(root->left, start, end);
    }
}


int main() {
    // int arr[6] = {5,1,3,4,2,7};
    int arr2[9] = {8,5,3,1,4,6,10,11,14};

    // Node* root = new Node(arr, 6);
    // Node* root = buildBST(arr, 6);

    // inorder(root);
    // cout << endl;

    // Node* root = buildBST(arr2, 9);
    // cout << search(root, 6) << endl;

    Node* root = buildBST(arr2, 9);
    // inorder(root);
    // cout << endl;

    // delNode(root, 4);

    // inorder(root);
    // cout << endl;

    printInRange(root, 5, 12);
    cout << endl;

    return 0;
}