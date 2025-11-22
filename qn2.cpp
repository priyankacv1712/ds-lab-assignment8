Node* searchRec(Node* root, int key) {
    if(root==NULL || root->data==key) return root;
    if(key < root->data) return searchRec(root->left,key);
    return searchRec(root->right,key);
}

Node* searchIter(Node* root, int key) {
    while(root) {
        if(root->data == key) return root;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}


int maxBST(Node* root) {
    while(root->right) root = root->right;
    return root->data;
}


int minBST(Node* root) {
    while(root->left) root = root->left;
    return root->data;
}


Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;
    while(root) {
        if(target->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}


Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = NULL;
    while(root) {
        if(target->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}
