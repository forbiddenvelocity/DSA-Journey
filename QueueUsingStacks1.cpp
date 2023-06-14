#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
struct Queue{
    stack<int> s1, s2;

    void enQueue(int x){     //O(n)
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue(){           //O(1)
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            exit(0);
        }
        int val = s1.top();
        s1.pop();
        return val;
    }

    int peek(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            exit(0);
        }
        return s1.top();
    }

};



int main(){
    
    Queue q;
    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(15);

    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;




    return 0;
}