#include<iostream>
#include<cctype>
using namespace std;

class Stack{
public:
    int top;
    int*arr;
    int n;

    Stack(int n):n(n){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack is overflow!"<<endl;
            return;
        }
        arr[++top]=x;
    }
    int pop(){
        if(top==-1){
            cout<<"Stack is underflow!"<<endl;
            return 0;
        }
        return arr[top--];
    }
    int peek(){
          if(top==-1){
            cout<<"Stack is underflow!"<<endl;
            return 0;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }

    
      ~Stack() {
        delete[] arr;
    }
};

int evaluateresult(const string& eq){
    Stack S(eq.length());
    for(int i=0;i<eq.length();i++){
        if(isdigit(eq[i])){
            S.push(eq[i]-'0');
        }
        else{
            int val2=S.pop();
            int val1=S.pop();
            int result;
            switch (eq[i])
            {
            case '+':
                result=val1+val2;
                break;
            case '-':
                result=val1-val2;
                break;
            case '*':
                result=val1*val2;
                break;
            case '/':
                if(val2==0){
                    cout<<"error"<<endl;
                    return 0;
                }
                result=val1/val2;
                break;
            
            default:
                cout<<"Invalid"<<endl;
                return 0;
            }
            S.push(result);
        }
    }
    return S.peek();
}

int main(){
    string postfix="23*54*+9-";
    int res=evaluateresult(postfix);
    cout<<"Final result : "<<res<<endl;
    return 0;

}
