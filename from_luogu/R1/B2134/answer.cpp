#include<iostream>
using namespace std;
bool isPrimeNumber(int i){
    if(i<2) return false;
    bool flag=true;
    for(int j=2;j<i;j++){
        if(i%j==0){
            flag=false;
            break;
        }
    }
    return flag;
}
int calculateMax(int S){
    int max=0;
    int x=S/2,y=S-x;
    while(y<S){
        if(isPrimeNumber(x)&&isPrimeNumber(y)){
            max=x*y;
            break;
        }
        x--;
        y++;
    }
    return max;
}
int main(){
    int S;
    cin>>S;
    cout<<calculateMax(S)<<endl;
}