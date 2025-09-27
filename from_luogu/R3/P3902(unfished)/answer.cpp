#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> data(n);
    for(auto &i:data) cin>>i;
    vector<int> max_up(n,1);
    int max=0;
    for(int m=0;m<n;m++){
        auto i=data.begin()+m;
    while(i!=data.end()){
        auto j=upper_bound(i+1,data.end(),*i);
        if(j!=data.end()){
            max_up[m]++;
            i=j;
        }
        else break;
    }
    if(max_up[m]>max) max=max_up[m];
}
    cout<<n-max<<endl;
    return 0;
    
}