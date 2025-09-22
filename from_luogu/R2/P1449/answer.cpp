#include<iostream>
#include<string>
#include<stack>
using namespace std;
enum Assemble{
    NUM,DOT,END,
    ADD,SUB,MUL,DIV,
    ERROR
};
Assemble read(char c){
    switch(c){
        case '+':return ADD;
        case '-':return SUB;
        case '*':return MUL;
        case '/':return DIV;
        case '.':return DOT;
        case '@':return END;
        default:
            if(c>='0'&&c<='9') return NUM;
            return ERROR;

    }
}
int calculatePostExpression(string s){
    stack <int> st;
    int num1=0,num2=0;
    for(auto i=s.begin();i!=s.end();i++){
        switch(read(*i)){
            case ADD:
                num2=st.top();
                st.pop();
                num1=st.top();
                st.pop();
                st.push(num1+num2);
                break;
            case SUB:
                num2=st.top();
                st.pop();
                num1=st.top();
                st.pop();
                st.push(num1-num2);
                break;
            case MUL:
                num2=st.top();
                st.pop();
                num1=st.top();
                st.pop();
                st.push(num1*num2);
                break;
            case DIV:
                num2=st.top();
                st.pop();
                num1=st.top();
                st.pop();
                st.push(num1/num2);
                break;
            case DOT:continue;
            case END:return st.top();
            case NUM:{
                int temp=0;
                while(read(*i)!=DOT){
                    temp=temp*10+((*i)-'0');
                    i++;
                }
                i--;
                st.push(temp);
                break;
            }
            default:return INT32_MAX;
        }
    }
}
int main(){
    string s;
    getline(cin,s);
    cout<<calculatePostExpression(s)<<endl;
    return 0;
}
