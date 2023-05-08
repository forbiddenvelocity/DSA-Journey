#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int key;
    Node* right;
    Node* left;
};

Node* createNode(int key){
    Node* newNode = new Node;
    newNode -> key = key;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key){
    if(root == NULL){
        return createNode(key);
    }
    if(key < root->key){
        root->left = insertNode(root->left, key);
    }
    else if(key > root->key){
        root->right = insertNode(root->right, key);
    }
    return root;
}

int findMin(Node* root){
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
    }
    while(root->left != NULL){
        root = root -> left;
    }
    return root->key;
}

int findMax(Node* root){
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
    }
    while(root->right!=NULL){
        root = root -> right;
    }
    return root->key;
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->key == key){
        return true;
    }
    else if(key < root->key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){

    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout<<"Minimum element: "<<findMin(root)<<endl;
    cout<<"Maximum element: "<<findMax(root)<<endl;

    int key = 60;
    cout<<key<<" "<<(search(root, key) ? "found" : "not found")<<endl;

    key = 10;
    cout<<key<<" "<<(search(root, key) ? "found" : "not found")<<endl;

    return 0;
}