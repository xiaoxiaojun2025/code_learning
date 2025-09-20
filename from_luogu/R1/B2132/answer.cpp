#include<iostream>
using namespace std;
bool isPrimeNumber(int i){
    if(i<=1){
        printf("Input error.\n");
        return false;
    }
    bool flag=true;
    for(int j=2;j<i;j++){
        if(i%j==0){
            flag=false;
            break;
        }
    }
    return flag;
}
void printPrimePair(int n){
    bool is_empty=true;
    for(int i=2;i<=n-2;i++){
        if(isPrimeNumber(i)&&isPrimeNumber(i+2)){
            cout<<i<<" "<<i+2<<endl;
            is_empty=false;
        }
    }
    if(is_empty) cout<<"empty"<<endl;
}
int main(){
    int n;
    cin>>n;
    printPrimePair(n);
}