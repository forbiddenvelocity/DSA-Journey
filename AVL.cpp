#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SPACE 10;

struct Node{
    int data;
    Node* right;
    Node* left;
    int height;
};

int height(Node* root){
    if(root==NULL){
        return -1;
    }
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight > rheight){
            return(lheight+1);
        }
        else return (rheight+1);
    }
}

int getBalance(Node* root){
    if(root==NULL){
        return -1;
    }
    else{
        return(height(root->left)-height(root->right));
    }
}

Node* createNode(int data){
    Node* newNode = new Node;
    newNode-> data = data;
    newNode->right=NULL;
    newNode->left=NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y; 
}

Node* insertNode(Node* root, Node* new_node){
    if(root==NULL){
        root = new_node;
        cout<<"Value inserted succesfully"<<endl;
    }

    if(new_node -> data < root->data){
        root->left = insertNode(root, root->left);
    }
    else if(new_node -> data > root->data){
        root->right = insertNode(root, root->right);
    }

    int bf = getBalance(root);
    //LL
    if(bf>1 && new_node->data < root->left->data){
        return rightRotate(root);
    }
    //RR
    if(bf<-1 && new_node->data > root->right->data){
        return leftRotate(root);
    }
    //LR
    if(bf>1 && new_node->data > root->left->data){
        root->left = leftRotate(root);
        return rightRotate(root);
    }
    //RL
    if(bf<-1 && new_node->data < root->right->data){
        root->right = rightRotate(root);
        return leftRotate(root);
    }

    return root;
}

void print2D(Node* root, int space) {
    if (root == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(root -> right, space); // Process right child first 3 
    cout << endl;
    for(int i=10; i<space; i++){ // 5 
      cout << " "; // 5.1
    }
    cout << root -> data << "\n"; // 6
    print2D(root -> left, space); // Process left child  7
}



int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        Node* new_node = createNode(arr[i]);
        root = insertNode(root, new_node);
    }

    print2D(root, 5);

    return 0;
}