#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int evaluatePostfix(string exp){
    stack<int> st;

    for(int i=0; i<exp.size(); i++){
        if(isdigit(exp[i])){
            st.push(exp[i]-'0');
        }
        else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch(exp[i]){
            case '+':
                st.push(val1+val2);
                break;
            case '-':
                st.push(val2-val1);
                break;
            case '*':
                st.push(val1*val2);
                break;
            case '/':
                st.push(val2/val1);
                break;
            }
        }
    }
    return st.top();
}

int main(){
    
    string exp;
    cout<<"Enter a postfix expression: "<<endl;
    cin>>exp;

    cout<<"Postfix evaluation is: "<<endl;
    cout<<evaluatePostfix(exp);




    return 0;
}