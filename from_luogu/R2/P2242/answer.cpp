#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector <ll>v(n);
    vector <ll> sub(n-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i) sub[i-1]=v[i]-v[i-1];
    }
    sort(sub.begin(),sub.end(),greater<int>());
    ll res=v[n-1]-v[0]+m;
    for(int i=0;i<m-1;i++){
        res-=sub[i];
    }
    cout<<res<<endl;
    return 0;

}