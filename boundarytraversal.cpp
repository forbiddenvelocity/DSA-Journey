#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int data;
    Node* right;
    Node* left;
};

Node* newNode(int d){
    Node* temp = new Node;
    temp -> data = d;
    temp -> right = temp -> left = NULL;
    return temp;
}

void leftBoundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    if(root -> left){
        cout<<root->data<<" ";
        leftBoundaryTraversal(root->left);
    }
    else if(root->right){
        cout<<root->right<<" ";
        leftBoundaryTraversal(root->right);
    }
}


void rightBoundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    if(root->right){
        rightBoundaryTraversal(root->right);
        cout<<root->data;
    }
    else if(root->left){
        rightBoundaryTraversal(root->left);
        cout<<root->data;
    }
}

void printLeaves(Node* root){
    if(root == NULL){
        return;
    }
    
    printLeaves(root->left);

    if(root->left != NULL && root->right!=NULL){
        cout<<root->data;
    }

    printLeaves(root->right);
}

void printBoundary(Node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    leftBoundaryTraversal(root);
    rightBoundaryTraversal(root);
    printLeaves(root);
}

int main(){
    
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}