#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor 
    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
    //destructor
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<< temp -> data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    
    return len;
}

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    temp -> prev = tail;
    tail -> next = temp;
    tail = temp;
}

void insertAtanypos(Node* &tail, Node* &head, int position, int d){
    //inserting at start
    if(position==1){
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    //inserting at last position 
    if(temp->next==NULL){
        insertAtTail(tail, d);
        return;
    }
    //creating a node for d
    Node* nodetoInsert = new Node(d);
    nodetoInsert -> next = temp -> next;
    temp -> next = nodetoInsert;
}

void deleteNode(int position, Node* &head){
    //delete first or starting node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count<position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL;
        prev -> next = curr->next;
        curr -> next = NULL;

        delete curr;
    }
}

int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    

    insertAtHead(head, 17);

    insertAtHead(head, 13);
   
    insertAtHead(head, 21);

    insertAtHead(head, 11);
    print(head);

    cout<<"DL after insertion at tail: "<<endl;
    insertAtTail(tail, 29);
    insertAtTail(tail, 55);
    insertAtTail(tail, 98);
    print(head);
    cout<<"DL after insertion at a given index: "<<endl;
    insertAtanypos(tail, head, 2, 9);
    print(head);

    cout<<"Length of the doubly linked list = "<<getLength(head)<<endl;

    deleteNode(3, head);
    deleteNode(6, head);
    cout<<"DL after deletion of nodes at given index: "<<endl;
    print(head);

    return 0;
}