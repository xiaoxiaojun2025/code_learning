#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,m,ans=0,si,sj;
vector<vector<int>>v;
vector<int>x{-1,-1,-1,0,0,1,1,1,0};
vector<int>y{-1,0,1,-1,1,-1,0,1,0};
vector<vector<bool>> used;
bool isSpace(int i,int j){
    for(int k=0;k<9;k++){
        if(i+x[k]<0||i+x[k]>=n||j+y[k]<0||j+y[k]>=m) continue;
        if(v[i+x[k]][j+y[k]]==1) return false;
    }
    return true;
}
bool isNum(int i,int j){
    if(v[i][j]!=0) return false;
    bool dirt=false;
    for(int k=0;k<8;k++){
        if(i+x[k]<0||i+x[k]>=n||j+y[k]<0||j+y[k]>=m) continue;
        if(v[i+x[k]][j+y[k]]==-1) return false;
        if(v[i+x[k]][j+y[k]]==1) dirt=true;
    }
    if(!dirt) return false;
    return true;
}
void dfs(){
    for(int k=0;k<8;k++){
        if(si+x[k]<0||si+x[k]>=n||sj+y[k]<0||sj+y[k]>=m) continue;
        if(isSpace(si+x[k],sj+y[k])&&used[si+x[k]][sj+y[k]]==false){
            si+=x[k],sj+=y[k];
            used[si][sj]=true;
            v[si][sj]=-1;
            dfs();
            si-=x[k],sj-=y[k];
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        v.push_back(vector<int>(0));
        used.push_back(vector<bool>(0));
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v[i].push_back(x);
            used[i].push_back(false);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(used[i][j]) continue;
            if(isSpace(i,j)){
                v[i][j]=-1;
                used[i][j]=true;
                si=i,sj=j;
                dfs();
                ans++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isNum(i,j)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;

}