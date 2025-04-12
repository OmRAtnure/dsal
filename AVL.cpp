#include<iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* rightRotate(struct Node *y){
    Node *x = y->left;
    Node *T2 = x->right;
    x->right=y;
    y->left = T2;
    
    y->height = max(getHeight(y->right),getHeight(y->left))+1;
    x->height = max(getHeight(x->right),getHeight(x->left))+1;
    return x;
}

struct Node* leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    x->right=y;
    y->left = T2;
    
    y->height = max(getHeight(y->right),getHeight(y->left))+1;
    x->height = max(getHeight(x->right),getHeight(x->left))+1;
    return x;
}

struct Node* insert(struct Node* node, int key){
    if(node==NULL){
        return createNode(key);
    }
    if(key<node->key){
        node->left = insert(node->left, key);
    }
    else if(key>node->key){
        node->right = insert(node->right, key);
    }
    return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalanceFactor(node);

    if(bf>1 && key<node->left->key){
        return rightRotate(node);
    }

    if(bf< -1 && key>node->right->key){
        return leftRotate(node);
    }

    if(bf< -1 && key<node->right->key){
        node->right = rightRotate(node->right);
        leftRotate(node);
    }

    if(bf>1 && key>node->left->key){
        node->left = leftRotate(node->left);
        rightRotate(node);
    }
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main(){
    Node* root= NULL;
    root = insert (root, 55);
    root = insert (root, 20);
    root = insert (root, 22);
    root = insert (root, 42);
    root = insert (root, 77);
    root = insert (root, 27);
    root = insert (root, 45);
    root = insert (root, 30);
    root = insert (root, 29);
    root = insert (root, 72);

    cout<<"Inorder of AVL tree is : ";
    inorder(root);
    return 0;
}