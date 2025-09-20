#include<iostream>
#include<vector>
#include<set>
using namespace std;
void insert_each_bit(set<int>&a,int n){
    while(n!=0){
        int temp=n%10;
        n/=10;
        a.insert(temp);
    }
}
int main(){
    set<int> data;
    for(int i=123;i<=329;i++){
        int j=2*i,k=3*i;
        insert_each_bit(data,i);
        insert_each_bit(data,j);
        insert_each_bit(data,k);
        if(*data.begin()==1&&*data.rbegin()==9&&(int)data.size()==9) cout<<i<<" "<<j<<" "<<k<<endl;
        data.clear();
    }
    return 0;
}