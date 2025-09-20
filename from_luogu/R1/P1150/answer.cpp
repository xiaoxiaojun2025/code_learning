#include<iostream>
#include<vector>
using namespace std;
int countCigarette(int cig,int butt,int k){
    if(cig==0) return 0;
    butt+=cig;
    return cig+countCigarette(butt/k,butt%k,k);
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<countCigarette(n,0,k)<<endl;
    return 0;
}