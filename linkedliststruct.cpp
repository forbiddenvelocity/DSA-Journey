#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    private: 
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }

        void addAtHead(int d){
            Node* newNode = new Node();
            newNode -> data = d;
            newNode -> next = head;
            head = newNode;
        }

        void addAtTail(int d){
            Node* newNode = new Node();
            newNode -> data = d;
            newNode -> next = NULL;
            if(head == NULL){
                head = newNode;
            }
            else{
                Node* temp = head;
                while(temp!=NULL){
                    temp = temp -> next;
                }
                temp -> next = newNode;
            }
        }

        void addAtAnypos(int d, int pos){
            Node* newNode = new Node;
            newNode-> data = d;
            newNode->next = NULL;

            if(pos==1){
                //addAtHead(d);
                newNode -> data = d;
                newNode -> next = head;
                newNode = head;
            }
            else{
                Node* temp = new Node;
                for(int i=0; i<pos-1 && temp!=NULL; i++){
                    temp = temp -> next;
                }
                if(temp == NULL){
                    cout<<"Invaid position"<<endl;
                } else {
                    newNode -> next = temp -> next;
                    newNode = temp;
                }
            }
        }

        void print(){
            Node* temp = new Node;
            while(temp != NULL){
                cout<<temp ->data<<" ";
                temp = temp -> next;
            }
            cout<<endl;
        }

};

int main(){
    LinkedList myList;

    myList.addAtHead(5);
    myList.addAtHead(10);
    myList.addAtTail(20);
    myList.addAtAnypos(15, 2);

    myList.print();
    return 0;
}