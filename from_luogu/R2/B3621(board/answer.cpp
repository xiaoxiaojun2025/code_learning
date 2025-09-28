#include<iostream>
#include<vector>
using namespace std;
int n,k;
vector<int> a;
void dfs(int x){
    if(x>n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=k;i++){
        a.push_back(i);
        dfs(x+1);
        a.pop_back();
    }
}
int main(){
    cin>>n>>k;
    dfs(1);
    return 0;
}