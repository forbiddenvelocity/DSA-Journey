#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node {
    int key;
    Node* right;
    Node* left;
};

Node* createTree(int key){
    Node* newNode = new Node;
    newNode -> key = key;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

Node* insert(Node* root, int key){
    if(root == NULL){
        return createTree(key);
    }

    if(key < root->key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }

    return root;
}

int findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root->key;
}

int findMax(Node* root){
    while(root->right != NULL){
        root = root-> right;
    }
    return root->key;
}

int search(Node* root, int key){
    if(root->key == key || root == NULL){
        cout<<"Key has been found";
    }
    if(key < root->key){
        search(root->left, key);
    }
    else if(key > root->key){
        search(root -> right, key);
    }
}

int main(){
    
    return 0;
}