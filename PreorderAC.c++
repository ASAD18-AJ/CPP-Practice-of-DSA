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
int count(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

//sum of all nodes in the tree
int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    int currSum = leftSum + rightSum + root->data;
    cout << "sum = " << currSum << endl;

    return currSum;
}

int diam1(Node* root) { //Time complexity - O(n^2)
    if(root == NULL) {
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}



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

    // cout << "Height : " << height(root) << endl;
    // cout << "Count : " << count(root) << endl;

    // cout << "sum of nodes : " << sum(root) << endl;

    cout << "diameter of tree : " << diam1(root) << endl;

    return 0;

}
