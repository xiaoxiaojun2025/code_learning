#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace  std;

int n,m;
vector<vector<char>>v;
vector<int> x{1,0,-1,0};
vector<int> y{0,1,0,-1};
deque<pair<int,int>>d;
bool found=false;
void bfs(int i,int j){
    if(found==true) return;
    if(i==n&&j==m){
        found=true;
        return;
    }
    for(int k=0;k<4;k++){
        int ai=i+x[k],aj=j+y[k];
        if(ai<=0||ai>n||aj<=0||aj>m||v[ai][aj]=='#') continue;
        d.push_back({ai,aj});
        v[ai][aj]='#';
        bfs(ai,aj);
        if(found==true) return;
        d.pop_back();
    }
}
int main(){
    cin>>n>>m;
    v.assign(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[i][j];
        }
    }
    d.push_back({1,1});
    v[1][1]='#';
    bfs(1,1);
    if(found) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
