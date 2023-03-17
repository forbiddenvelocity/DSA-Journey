#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in left "<<data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter data for inserting in right "<<data<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp -> data <<" ";
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inorder(Node* root){
    //base case
    if(root==NULL){
        return ;
    }
    inorder(root -> left);   //L
    cout<<root -> data <<" ";  //N
    inorder(root -> right);   //R
}

void preorder(Node* root){
    //base case
    if(root == NULL){
        return ;
    }
    cout<<root -> data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    //base case
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    //creating a tree
    root = buildTree(root);
    cout<<"The output after level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"The inorder traversal is: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"The preorder traversal is: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"The post order traversal is: "<<endl;
    postorder(root);

    return 0;
}