#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[100010];
int max_up=1,current_up=1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            current_up++;
            if(max_up<current_up) max_up=current_up;
        }
        else{
            current_up=1;
        }
    }
    int res=n-max_up;
    cout<<res<<endl;
    return 0;
    
}