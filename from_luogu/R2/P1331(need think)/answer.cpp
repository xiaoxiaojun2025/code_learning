#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,m,ans=0;
vector<vector<char>> v;
vector<vector<bool>> used;
vector<int> x{1,0,0,-1};
vector<int> y{0,1,-1,0};

void dfs(int i,int j){
    for(int k=0;k<4;k++){
        int ai=i+x[k],aj=j+y[k];
        if(ai<=0||ai>n||aj<=0||aj>m||used[ai][aj]||v[ai][aj]=='.') continue;
        used[ai][aj]=true;
        dfs(ai,aj);
    }
}
bool isBadDot(int i,int j){
    if(v[i][j]=='#') return false;
    if(i+1<=n&&j+1<=m&&i>0&&j>0){
        if(v[i][j+1]=='#'&&v[i+1][j]=='#'&&v[i+1][j+1]=='#') return true; 
    }
    if(i+1<=n&&j<=m&&i>0&&j-1>0){
        if(v[i][j-1]=='#'&&v[i+1][j]=='#'&&v[i+1][j+1]=='#') return true; 
    }
    if(i<=n&&j<=m&&i-1>0&&j-1>0){
        if(v[i][j-1]=='#'&&v[i-1][j-1]=='#'&&v[i-1][j]=='#') return true; 
    }
    if(i<=n&&j+1<=m&&i-1>0&&j>0){
        if(v[i-1][j]=='#'&&v[i-1][j+1]=='#'&&v[i][j+1]=='#') return true; 
    }
    return false;
}
int main(){
    cin>>n>>m;
    v.assign(n+1,vector<char>(m+1,'.'));
    used.assign(n+1,vector<bool>(m+1,false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>v[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(isBadDot(i,j)){
                cout<<"Bad placement."<<endl;
                return 0;
            }
            if(used[i][j]) continue;
            if(v[i][j]=='#'){
                used[i][j]=true;
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<"There are "<<ans<<" ships."<<endl;
    return 0;
}
