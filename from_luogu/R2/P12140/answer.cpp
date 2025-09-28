#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,res=0;
int score(int a,int b,int c){
    if(a==b&&b==c) return 200;
    else if((a==b&&b!=c)||(a==c&&a!=b)||(b==c&&b!=a)) return 100;
    else if(c-b==1&&b-a==1) return 200;
    else{
        vector<int>v{a,b,c};
        sort(v.begin(),v.end());
        if(v[2]-v[1]==1&&v[1]-v[0]==1) return 100;
        else return 0;
    }
}
int main(){
    cin>>n;
    vector<vector<int>> data(3,vector<int>(n));
    for(auto &i:data){
        for(auto &j:i) cin>>j;
    }
    cin>>m;
    vector<int>v(3);
    for(int c=0;c<m;c++){
        for(int i=0;i<3;i++){
            int x;
            cin>>x;
            v[i]+=x;
            while(v[i]>=n) v[i]-=n;
        }
        res+=score(data[0][v[0]],data[1][v[1]],data[2][v[2]]);
    }
    cout<<res<<endl;
    return 0;

}