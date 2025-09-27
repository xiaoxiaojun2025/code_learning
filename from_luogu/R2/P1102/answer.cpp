#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int N,C;
    cin>>N>>C;
    vector<int> v(N);
    for(auto &i:v) cin>>i;
    sort(v.begin(),v.end());
    long long count=0;
    for(int i=0;i<N;i++){
        int target=v[i]+C;
        int left=lower_bound(v.begin(),v.end(),target)-v.begin();
        int right=upper_bound(v.begin(),v.end(),target)-v.begin();
        count+=right-left;
    }
    cout<<count<<endl;
    return 0;
}