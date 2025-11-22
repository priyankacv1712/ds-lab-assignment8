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
