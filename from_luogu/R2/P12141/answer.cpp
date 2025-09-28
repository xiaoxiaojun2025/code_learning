#include<iostream>
#include<string>
using namespace std;
int m;
void findAnswer(int l,int c){
    string v{'1'};
    for(int i=1;i<l;i++){
        string temp=v;
        for(size_t j=0;j<temp.size();j++){
            if(temp[j]=='0') temp[j]='1';
            else temp[j]='0';
        }
        v+=temp;
    }
    if(v[c-1]=='1') cout<<"RED"<<endl;
    else cout<<"BLACK"<<endl;
    return ;
}
int main(){
    cin>>m;
    while(m--){
        int l,c;
        cin>>l>>c;
        findAnswer(l,c);
    }
}