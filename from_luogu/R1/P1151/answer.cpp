#include<iostream>
#include<vector>
using namespace std;
int main(){
    int K;
    cin>>K;
    if(K<=0){
        cout<<"No"<<endl;
        return 0;
    }
    bool is_empty=true;
    for(int i=10000;i<=30000;i++){
        int x1=i/10000;
        int x2=i/1000%10;
        int x3=i%1000/100;
        int x4=i%100/10;
        int x5=i%10000;
        int sub1=x1*100+x2*10+x3,sub2=x2*100+x3*10+x4,sub3=x3*100+x4*10+x5;
        if(sub1%K==0&&sub2%K==0&&sub3%K==0){
            cout<<i<<endl;
            is_empty=false;
        }
    }
    if(is_empty) cout<<"No"<<endl;
    return 0;
}