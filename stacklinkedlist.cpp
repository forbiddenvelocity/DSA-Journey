#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
    Node* top;
    public:
        Stack() : top{nullptr} {};

        void push(int d){
            Node* newNode = new Node{d, nullptr};
            newNode -> next = top;
            top = newNode;
        }

        bool isEmpty(){
            return top == nullptr;
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return -1;
            }

            int value = top->data;

            Node* poppedtop = top;
            top = top -> next;
            delete top;

            return value;
        }
};


int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Pop the values off the stack and print them
    cout << stack.pop() <<endl;  // Output: 3
    cout << stack.pop() <<endl;  // Output: 2
    cout << stack.pop() <<endl;  // Output: 1

    // Try to pop from an empty stack (should print an error message)
    cout << stack.pop() <<endl; 
    return 0;
}