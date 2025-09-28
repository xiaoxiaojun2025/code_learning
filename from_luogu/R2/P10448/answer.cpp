#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
int n,m,pp=0;
vector<int> a(15);
void dfs(int x,int sid){
    if(x>m){
        for(int i=1;i<=m;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=sid;i<=n;i++){
        a[++pp]=i;
        dfs(x+1,i+1);
        pp--;
    }
}
int main(){
    cin>>n>>m;
    dfs(1,1);
    return 0;

}