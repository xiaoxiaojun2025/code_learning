#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void getPreOrder(string s1,string s2){
    if(s2.empty()) return ;
    char c=s2[s2.size()-1];
    cout<<c;
    auto i=s1.find(c);
    string left_in=s1.substr(0,i),left_post=s2.substr(0,i);
    string right_in=s1.substr(i+1,s1.size()-i-1),right_post=s2.substr(i,s2.size()-i-1);
    getPreOrder(left_in,left_post);
    getPreOrder(right_in,right_post);
}
int main(){
    string inOrder,postOrder;
    cin>>inOrder>>postOrder;
    getPreOrder(inOrder,postOrder);
    return 0;
}