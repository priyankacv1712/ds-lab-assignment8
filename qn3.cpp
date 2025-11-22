#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertBST(Node* root, int x) {
    if(root==NULL) {
        root = new Node;
        root->data = x;
        root->left = root->right = NULL;
    } else if(x < root->data) root->left = insertBST(root->left,x);
    else if(x > root->data) root->right = insertBST(root->right,x);
    return root;
}

Node* minNode(Node* root) {
    while(root->left) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key) {
    if(root==NULL) return root;
    if(key < root->data) root->left = deleteBST(root->left,key);
    else if(key > root->data) root->right = deleteBST(root->right,key);
    else {
        if(root->left==NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right==NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* t = minNode(root->right);
        root->data = t->data;
        root->right = deleteBST(root->right,t->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if(root==NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l>r?l:r);
}

int minDepth(Node* root) {
    if(root==NULL) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(l==0 || r==0) return 1 + l + r;
    return 1 + (l<r?l:r);
}

int main() {
    Node* root = NULL;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = deleteBST(root, 30);
    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;
}
