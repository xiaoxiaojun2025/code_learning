//最经典的DFS
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool canGo(pair<int,int> p2,vector<vector<int>> v,int n,int m){
    if(p2.first<1||p2.first>n||p2.second<1||p2.second>m||v[p2.first][p2.second]==1) return false;
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    stack<pair<int,int>> st;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[i][j];
        }
    }
    int i=1,j=1;
    while(i!=n||j!=m){
        if(!v[i][j]) st.push({i,j});
        if(canGo({i+1,j},v,n,m)){
            v[i][j]=1;
            i++;
            continue;
        }
        if(canGo({i,j+1},v,n,m)){
            v[i][j]=1;

            j++;
            continue;
        }
        if(canGo({i-1,j},v,n,m)){
            v[i][j]=1;

            i--;
            
            continue;
        }
        if(canGo({i,j-1},v,n,m)){
            v[i][j]=1;

            j--;
            continue;
        }
        v[i][j]=1;
        st.pop();
        if(!st.empty()){
            i=st.top().first;
            j=st.top().second;
        }
        else break;
    }
    if(i==n&&j==m){
        st.push({n,m});
        stack<pair<int,int>> out;
        while(!st.empty()){
            out.push(st.top());
            st.pop();
        }
        while(!out.empty()){
            cout<<"<"<<out.top().first<<","<<out.top().second<<"> ";
            out.pop();
        }
        cout<<endl;
    }
    else cout<<"There is no solution!"<<endl;
    return 0;
}