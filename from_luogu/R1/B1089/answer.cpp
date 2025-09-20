#include<iostream>
#include<vector>
using namespace std;
int main(){
    int now_money=0,given_money=300,save_money=0,budget,bad_month=0;
    bool flag=false;
    for(int i=1;i<=12;i++){
        cin>>budget;
        if(!flag){
            now_money+=given_money-budget;
            if(now_money<0){
            bad_month=-i;
            flag=true;
            }
            int temp=now_money/100;
            now_money-=temp*100;
            save_money+=temp*100;
        }
    }
    if(flag) cout<<bad_month<<endl;
    else{
        int final_money=now_money+save_money*1.2;
        cout<<final_money<<endl;
    }
    return 0;
}