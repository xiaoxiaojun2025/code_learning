#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<ll> sum(n-k);
    for(auto &i:v) cin>>i;
    for(int i=0;i<=k;i++){
        sum[0]+=v[i];
    }
    for(int i=1;i<n-k;i++){
        sum[i]=sum[i-1]-v[i-1]+v[i+k];
    }
    sort(sum.begin(),sum.end(),greater<int>());
    cout<<sum[0]<<endl;
    return 0;
}