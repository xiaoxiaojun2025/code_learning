#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string res,temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(i) {
        auto pos=res.find(temp[0]);
        string temp1;
        if(temp[1]!='*') temp1+=temp[1]; 
        if(temp[2]!='*') temp1+=temp[2]; 

        res.insert(pos+1,temp1);
        }
        else{
            string temp1;
            temp1+=temp[0];
            if(temp[1]!='*') temp1+=temp[1]; 
            if(temp[2]!='*') temp1+=temp[2]; 
            res+=temp1;           
        }
    }
    cout<<res<<endl;
}