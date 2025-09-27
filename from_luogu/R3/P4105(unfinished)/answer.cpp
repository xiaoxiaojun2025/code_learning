#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll=long long;
ll n,sa,sb,sc,sd,a1,mod,maxn=0;
ll f(ll x){
    return x*x*x*sa+x*x*sb+x*sc+sd;
}
int main(){
    cin>>n>>sa>>sb>>sc>>sd>>a1>>mod;
    vector<ll> data(n+1);

    data[1]=a1;
    for(int i=2;i<=n;i++){
        data[i]=(f(data[i-1])+f(data[i-2]))%mod;
    }
    vector<ll> last_min(n);
    last_min[n-1]=data[n];
    for(int i=n-2;i>1;i--){
        last_min[i]=min(data[i+1],last_min[i+1]);
    }
    for(int i=1;i<n;i++){
        if(data[i]-last_min[i]>maxn&&data[i]-last_min[i]>0){
            maxn=data[i]-last_min[i];
        }
    }
    ll ans=(maxn+1)/2;
    cout<<ans<<endl;
    
}