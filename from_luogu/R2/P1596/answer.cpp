#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,m,ans=0,si,sj;
vector<string> v;
vector<vector<bool>>used;
vector<int> x{-1,-1,-1,0,0,1,1,1};
vector<int> y{-1,0,1,-1,1,-1,0,1};
void dfs(){
    for(int k=0;k<8;k++){
        if(si+x[k]<0||si+x[k]>=n||sj+y[k]<0||sj+y[k]>=m) continue;
        if(v[si+x[k]][sj+y[k]]=='W'&&used[si+x[k]][sj+y[k]]==false){
            si+=x[k],sj+=y[k];
            used[si][sj]=true;
            dfs();
            si-=x[k],sj-=y[k];
        }
    }
}
int main(){
    cin>>n>>m;
    used.assign(n,vector<bool>(m,false));
    v.assign(n,"");
    for(auto &i:v) cin>>i;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(used[i][j]) continue;
            if(v[i][j]=='W'){
                used[i][j]=true;
                si=i,sj=j;
                dfs();
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}