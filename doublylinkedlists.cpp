#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class doublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        doublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insertAtHead(int d){
            Node* newNode = new Node;
            newNode -> data = d;
            newNode -> prev = NULL;
            newNode -> next = head;
            if(head != NULL){
                head->prev = newNode;
            } else {
                tail = newNode;
            }
            head = newNode;
        }

        void insertAtTail(int d){
            Node* newNode = new Node;
            newNode -> data = d;
            newNode -> prev = tail;
            newNode -> next = NULL;
            if(tail != NULL){
                tail -> next = newNode;
            } else {
                head = newNode;
            }
            tail = newNode;
        }

        void insertAtRandom(int d, int pos){
            Node* newNode = new Node;
            Node* temp = head;
            for(int i=0; i<pos - 1 && temp!=NULL; i++){
                temp = temp -> next;
            }
            if(temp!=NULL){
                newNode -> prev = temp;
                newNode -> next = temp -> next;
                if(temp->next != NULL){
                    temp -> next -> prev = newNode;
                }
                else{
                    tail = newNode;
                }
                temp -> next = newNode;
            } else{
                cout<<"Invalid position"<<endl;
            }
        }

        void printList() {
            Node* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << "\n";
        }

        bool search(int value) {
            Node* current = head;
            while (current != NULL) {
                if (current->data == value) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
};

int main(){
    doublyLinkedList dll;

    dll.insertAtHead(2);
    dll.insertAtHead(1);
    dll.insertAtTail(3);
    dll.insertAtRandom(4, 3);

    dll.printList();

    if (dll.search(3)) {
        cout << "3 found in the list\n";
    } else {
        cout << "3 not found in the list\n";
    }
    return 0;
}