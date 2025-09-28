#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int n,pp=0;
vector<bool> used(15,false);
vector<int>a(15);
void dfs(int x){
    if(x>n){
        for(int j=1;j<=n;j++){
            cout<<setw(5)<<a[j];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            a[++pp]=i;
            used[i]=true;
            dfs(x+1);
            pp--;
            used[i]=false;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
}