#include<iostream>
using namespace std;

class Stack{
public:
    int top;
    char arr[10];

    Stack(){
        top=-1;
    }
    void push(char x){
        if(top==9){
            cout<<"Stack is overflow!"<<endl;
            return;
        }
        arr[++top]=x;
    }
    char pop(){
        if(top==-1){
           return '\0';
        }
        return arr[top--];
    }
    char peek(){
          if(top==-1){
            return '\0';
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}


string infixtopostfix(string expression){
    Stack S;
    string postfix="";
    for(int i=0;i<expression.length();i++){
        if((expression[i]>='A' && expression[i]<='Z') ||
           (expression[i]>='a' && expression[i]<='z') ||
           (expression[i]>='0' && expression[i]<='9')){
            postfix=postfix+expression[i];
           }
        else if(expression[i]=='('){
            S.push(expression[i]);
        }
        else if(expression[i]==')'){
            while (!S.empty() && S.peek()!='('){
                postfix=postfix+S.pop();
            }
            S.pop();
        }
         else {
            while (!S.empty() && precedence(S.peek()) >= precedence(expression[i])) {
                postfix += S.pop();
            }
            S.push(expression[i]);
        }
    }
      while (!S.empty()) {
        postfix += S.pop();
    }
    return postfix;
}

int main(){
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    string postfix=infixtopostfix(infix);
    cout<<postfix;

}
