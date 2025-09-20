#include<iostream>
using namespace std;
int sum(int i){
    int s=0;
    for(int j=1;j<=i;j++){
        s+=j;
    }
    return s;
}
void calculate(int n){
    if(n==1){
        cout<<3<<" "<<4<<endl;
        return;
    }
    for(int y=1;y<=2*n;y++){
        if((sum(y)-n)%3==0&&(sum(y)-n)/3>0){
            int x=(sum(y)-n)/3;
            cout<<x<<" "<<y<<endl;
            break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    if(n<1) return 0;
    calculate(n);
    return 0;
}