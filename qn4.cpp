#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBSTUtil(Node* root, int minv, int maxv) {
    if(root==NULL) return true;
    if(root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left,minv,root->data) && isBSTUtil(root->right,root->data,maxv);
}

bool isBST(Node* root) {
    return isBSTUtil(root,-1000000,1000000);
}
