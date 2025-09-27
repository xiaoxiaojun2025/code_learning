#include<iostream>
#include<vector>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll=long long;
int main(){
    IOS;
    int N,K;
    cin>>N>>K;
    vector<pair<int,int>> v(N);
    for(auto &i:v){
        cin>>i.first;
        cin>>i.second;
    }
    int left=1,right=100001,mid=0;
    int ans=0;
    while(left<=right){
        ll sum=0;
        mid=(left+right)/2;
        for(int i=0;i<N;i++){
            sum+=1LL*(v[i].first/mid)*(v[i].second/mid);
        }
        if(sum>=K){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}