#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node {
    int value;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack (){
            top = nullptr;
        }

    void push(int val){
        Node* newNode = new Node;
        newNode -> value = val;
        newNode -> next = top;
        top = newNode;
    }

    int pop(){
        if(top == nullptr){
            cout<<"Stack is empty"<<endl;
        }
        Node* temp = top;
        top = top -> next;
        delete temp;
    }

    int peek(){
        if(top == nullptr){
            cout<<"stack is empty";
            return -1;
        }
        return top -> value;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    int print(){
        cout<<"The stack is :"<<endl;
        Node* temp = top;
        while(temp!=NULL){
            cout<<temp->value;
            cout<<endl;
            temp = temp -> next;
        }
        cout<<endl;
    }
};

int main(){

    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout<<s.peek()<<endl;
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}