#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
bool isCircleNumber(string s){
    auto left=s.begin(),right=s.end()-1;
    while(left<right){
        if(*left!=*right) return false;
        left++;
        right--;
    }
    return true;
}
string bigAdd(string s1,string s2,int N){
    if(s1==s2) return "0";
    string res;
    int len=max(s1.size(),s2.size());
    vector<int> v1(len),v2(len),v3(len+1);
    for(size_t i=0;i<s1.size();i++){
        char c=s1[s1.size()-i-1];
        if(c>='A'&&c<='F'){
            v1[i]=10+c-'A';
        }
        else v1[i]=c-'0';
    }
    for(size_t i=0;i<s2.size();i++){
        char c=s2[s2.size()-i-1];
        if(c>='A'&&c<='F'){
            v2[i]=10+c-'A';
        }
        else v2[i]=c-'0';
    }
    for(int i=0;i<len;i++){
        v3[i]+=v1[i]+v2[i];
        if(v3[i]>=N){
            v3[i]-=N;
            v3[i+1]+=1;
        }
    }
    int highest=len;
    while(highest>0&&!v3[highest]){
        highest--;
    }
    for(int i=highest;i>=0;i--){
        if(v3[i]>=10){
            res.push_back('A'+v3[i]-10);
        }
        else res.append(to_string(v3[i]));
    }
    return res;
}
string getReverse(string s){
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    int N;
    string M;
    cin>>N>>M;
    int step=0;
    while(step!=30&&!isCircleNumber(M)){
        M=bigAdd(M,getReverse(M),N);
        step++;
    }
    if(step==30) cout<<"Impossible!"<<endl;
    else cout<<"STEP="<<step<<endl;
    return 0;
}