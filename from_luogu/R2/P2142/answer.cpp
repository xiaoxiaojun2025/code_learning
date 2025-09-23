#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isBigger(string s1,string s2){
    if(s1.size()>s2.size()) return true;
    else if(s1.size()<s2.size()) return false;
    else{
        for(int i=0;i<(int)s1.size();i++){
            if(s1[i]!=s2[i]) return s1[i]>s2[i];
        }
        return true;
    }
}
string bigSub(string s1,string s2){
    string res;
    if(!isBigger(s1,s2)){
        string temp(s1);
        s1=s2;
        s2=temp;
        res.append("-");
    }
    vector<int> v1(s1.size()),v2(s1.size()),v3(s1.size());
    for(size_t i=0;i<s1.size();i++){
        v1[i]=s1[s1.size()-i-1]-'0';
    }
    for(size_t i=0;i<s2.size();i++){
        v2[i]=s2[s2.size()-i-1]-'0';
    }
    for(size_t i=0;i<s1.size();i++){
        int temp=v1[i]-v2[i];
        if(temp>=0) v3[i]=temp;
        else{
            v1[i+1]--;
            v3[i]=temp+10;
        }
    }
    int highest=s1.size()-1;
    while(!v3[highest]&&highest>0){
        highest--;
    }
    for(int i=highest;i>=0;i--){
        res.append(to_string(v3[i]));
    }
    return res;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string s3=bigSub(s1,s2);
    cout<<bigSub(s1,s2)<<endl;
}
