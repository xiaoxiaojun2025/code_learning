#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack <char> st;
void getPostOrder(string s1,string s2){
    if(s1.empty()) return ;
    st.push(s2[0]);
    int i=s1.find(s2[0]);
    string left_pre=s2.substr(1,i),right_pre=s2.substr(i+1,s1.size()-i-1);
    string left_in=s1.substr(0,i),right_in=s1.substr(i+1,s2.size()-i-1);
    getPostOrder(right_in,right_pre);
    getPostOrder(left_in,left_pre);
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    getPostOrder(s1,s2);
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}