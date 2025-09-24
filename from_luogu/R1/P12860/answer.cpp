#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(3);
    int min=1000000,min_size=0;
    for(int m=1;m<=n;m++){
        int p;
        string s;
        cin>>p>>s;
        for(auto i:s){
            int temp=i-'0';
            if(temp==1||temp==0||temp==2) v[temp]++;
        }
        if(v[2]>=2&&v[0]>=1&&v[1]>=1){
            if(p<min){
                min=p;
                min_size=m;
            }
        }
        v[0]=v[1]=v[2]=0;
    }
    cout<<min_size<<endl;
    return 0;
}