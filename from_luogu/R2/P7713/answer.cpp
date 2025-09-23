#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll sum=0,res=0;
    for(int i=1;i<n-1;i++){
        sum+=v[i];
    }
    if(sum+m<=(n-2)*v[n-1]) res=sum+m;
    else{
        ll remain=m-((n-2)*v[n-1]-sum);
        if(remain%(n-1)==0) res=sum+m-remain/(n-1);
        else res=sum+m-remain/(n-1)-1;
    }
    cout<<res<<endl;
    return 0;
}