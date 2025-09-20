#include<iostream>
using namespace std;
void find_num(int n){
    for(int i=2;i<=n;i++){
        int sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0) sum+=j;
        }
        if(sum==i){
            cout<<i<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    find_num(n);
}