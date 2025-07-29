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

//diameter of the tree
int diam1(Node* root) { //Time complexity - O(n^2)
    if(root == NULL) {
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}


//subtree check

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}


bool isSubtree(Node* root, Node* subRoot) {
    if(root == NULL && subRoot == NULL) {
        return true;
    } else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot -> data) {

    }

    int isLeftSubtree = isSubtree(root->left, subRoot->left);

    if(!isLeftSubtree) {
        return isSubtree(root->right, subRoot->right);
    }
    return true;
}

//Kth level of the tree
void KthHelper(Node* root, int k, int currLevel) {
    if(root == NULL) {
        return ;
    }
    if(currLevel == k) {
        cout << root->data << " ";
        return;
    }
    KthHelper(root->left, k, currLevel + 1);//left
    KthHelper(root->right, k, currLevel + 1);//right
}
void KthLevel(Node* root, int k) {
    KthHelper(root, k, 0);
    cout << endl;
}

//lowest common ancestor TC-O(n)
bool rootToNodePath(Node* root, int n, vector<int> &path) {
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight) {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }
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

    // cout << "diameter of tree : " << diam1(root) << endl;


    // Node* subRoot = new Node(2);
    // subRoot->left = new Node(4);
    // subRoot->right = new Node(5);

    // cout << isSubtree(root, subRoot)<<endl;

    // Kth level of the tree
    // KthLevel(root, 2);

    // lowest common ancestor
    int n1 = 4, n2 = 5;
    cout<< "LCA of " << n1 << " and " << n2 << " is: " << LCA(root, n1, n2) << endl;

    return 0;

}
