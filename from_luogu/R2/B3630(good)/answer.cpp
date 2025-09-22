#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,h;
    cin>>n;
    vector<int> data(n+1);
    for(int i=1;i<=n;i++){
        cin>>data[i];
    }
    cin>>h;
    int cur=h;
    for(int i=0;i<n;i++){
        cout<<cur<<" ";
        cur=data[cur];
    }
    cout<<endl;
    return 0;
}