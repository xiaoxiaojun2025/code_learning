#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
int downNumber(int n){
    return floor(sqrt(n));
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &v1:v) cin>>v1;
    sort(v.begin(),v.end(),greater<int>());
    ll sum=0;
    for(int i=0;i<n;i++){
        int temp=i;
        while(temp--){
            if(v[i]==1) break; 
            v[i]=downNumber(v[i]);
        }
    }
    for(auto i:v){
        sum+=i;
    }
    cout<<sum<<endl;
    return 0;

}