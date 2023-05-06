#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int data;
    Node* right = NULL;
    Node* left = NULL;
};

Node* createTree(int key){
    Node* newNode = new Node;
    newNode -> data = key;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

Node* insert(Node* root, int key){
    if(root == NULL){
        return createTree(key);
    }
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root -> right = insert(root->right, key);
    }
}

Node* findMin(Node* node){
    Node* temp = node;
    while(temp->left!=NULL){
        temp = temp -> left;
    }
    return temp;
}

Node* findMax(Node* node){
    Node* temp = node;
    while(temp->right!=NULL){
        temp = temp -> right;
    }
    return temp;
}

Node* sucessor(Node* root, Node* node){
    if(node->right!=NULL){
        return findMin(node->right);
    }
    Node* successor = NULL;
    while(root!=NULL){
        if(node->data < root->data){
            successor = root;
            root = root->left;
        }
        else if(node->data > root->data){
            root = root->right;
        }
        else{
            break;
        }
    }
    return successor;
}

Node* predecessor(Node* root, Node* node){
    if(node->left!=NULL){
        return findMax(node->left);
    }
    Node* predecessor = NULL;
    while(root != NULL){
        if(node->data > root->data){
            predecessor = root;
            root = root->right;
        }
        else if(node->data < root->data){
            root = root->left;
        }
        else{
            break;
        }
    }
    return predecessor;
}

Node* postorder(Node* p, int indent = 0)
{
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
}

Node* inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){
    
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    Node* node = root->left->right;

    postorder(root, 0);

    cout<<endl;

    Node* suc = sucessor(root, node);
    Node* pre = predecessor(root, node);

    if (suc != NULL) {
        cout << "The successor of " << node->data << " is " << suc->data << endl;
    }
    else {
        cout << "There is no successor for " << node->data << endl;
    }
    if (pre != NULL) {
        cout << "The predecessor of " << node->data<< " is " <<pre -> data << endl;
    }

    return 0;
}