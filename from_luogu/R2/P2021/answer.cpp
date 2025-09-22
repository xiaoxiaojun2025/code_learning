#include<iostream>
#include<deque>
using namespace std;
void getList(int n,deque<int> &qu){
    if(n<=0) return;
    qu.push_front(n);
    int temp=qu.back();
    qu.pop_back();
    qu.push_front(temp);
    getList(n-1,qu);
}
int main(){
    int n;
    cin>>n;
    deque<int> qu;
    getList(n,qu);
    for(auto i:qu){
        cout<<i<< " ";
    }
    cout<<endl;
    return 0;
}