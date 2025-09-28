#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
string a;
void dfs(int x){
    if(x>n){
        cout<<a<<endl;
        return;
    }
    for(int i=0;i<=1;i++){
        if(!i) a+='N';
        else a+='Y';
        dfs(x+1);
        a.pop_back();
    }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}