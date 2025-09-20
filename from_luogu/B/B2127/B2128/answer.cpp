#include<iostream>
using namespace std;
int find_num(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        bool flag=true;
        for(int j=2;j<i;j++){
            if(i%j==0){
                flag=false;
                break;
            } 
        }
        if(flag) count++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<find_num(n)<<endl;
}