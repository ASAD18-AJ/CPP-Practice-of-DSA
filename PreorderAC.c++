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

static int idx = -1;

Node* buildTree(vector<int> &nodes) {// time complexity- O(n) 
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void preorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    
    if(root == NULL) {
        return;
    }

    //left
    inorder(root->left);


    //root
    cout << root->data << " ";

    //right
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//height of the tree
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currHt = max(leftHeight, rightHeight) + 1;
    return currHt;
}

//count of nodes in the tree

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(nodes);

    // cout << "root = "<< root->data << endl;

    // preorder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // postorder(root);
    // cout << endl;

    cout << "Height : " << height(root) << endl;

    return 0;

}
