#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n,ans=0;
bool destroyed;
vector<vector<char>>v;
vector<int>x{1,0,-1,0},y{0,1,0,-1};
vector<vector<bool>>used;
void bfs(int i,int j){
    int count=0;
    for(int k=0;k<4;k++){
        int ai=i+x[k],aj=j+y[k];
        if(v[ai][aj]=='#') count++;
        if(v[ai][aj]=='.'||used[ai][aj]) continue;
        used[ai][aj]=true;
        bfs(ai,aj);
    }
    if(count==4) destroyed=false;
}
int main(){
    cin>>n;
    v.assign(n+1,vector<char>(n+1,'.'));
    used.assign(n+1,vector<bool>(n+1,false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>v[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]=='.'||used[i][j]) continue;
            if(v[i][j]=='#'){
                destroyed=true;
                bfs(i,j);
                if(destroyed) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}