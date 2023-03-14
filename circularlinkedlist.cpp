#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Node{
    public:
    int data;
    Node* next;

    //constructor 
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    //destrcutor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data: "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non empty list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    else{
        //non empty 
        Node* prev = tail;
        Node* curr = prev -> next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(tail==curr){
            tail = prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}


int main(){
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 12);
    print(tail);
    insertNode(tail, 12, 9);
    print(tail);
    insertNode(tail, 9, 15);
    print(tail);
    insertNode(tail, 12, 6);
    print(tail);
    deleteNode(tail, 6);
    print(tail);

    return 0;
}