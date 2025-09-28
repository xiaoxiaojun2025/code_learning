#include<iostream>
#include<vector>
using namespace std;
int n,k;
vector<int> a;
vector<bool> used;
void dfs(int x){
    if(x>k){
        for(auto i:a) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        a.push_back(i);
        used[i]=true;
        dfs(x+1);
        a.pop_back();
        used[i]=false;
    }
}
int main(){
    cin>>n>>k;
    used.assign(n+1,false);
    dfs(1);
    return 0;
}