#include<iostream>
#include<vector>
using namespace std;
int main(){
    int worst_day=0,max=-1;
    vector<vector<int>> learning_hours(7,vector<int>(2));
    for(int i=0;i<7;i++){
        int temp=0;
        for(int j=0;j<2;j++){
            cin>>learning_hours[i][j];
            temp+=learning_hours[i][j];
        }
        if(temp>8&&temp>max){
            worst_day=i+1;
            max=temp;
        }
    }
    cout<<worst_day<<endl;
}