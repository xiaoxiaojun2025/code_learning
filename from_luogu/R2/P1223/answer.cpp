#include<iostream>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;
struct compare{
    bool operator()(const vector<int>&a,const vector<int>&b)const{
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
};
int main(){
    int n;
    cin>>n;
    set<vector<int>,compare> myset;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        myset.insert({x,i});
    }
    double average=0;
    long long sum=0;
    for(auto it=myset.begin();it!=myset.end();it++){
        cout<<(*it)[1]<<" ";
        average+=sum;
        sum+=(*it)[0];
    }
    cout<<endl;
    average/=n;
    cout<<fixed<<setprecision(2)<<average<<endl;
    return 0;
}