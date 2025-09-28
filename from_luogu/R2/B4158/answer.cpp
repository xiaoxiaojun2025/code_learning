#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int t,n;
string in;
vector<int> v;
bool found;
bool isPrime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
bool isStrPrime(vector<int> v,string s,int &a){
    int ans=0;
    for(size_t i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a=s[i]-'0'+a*10;
        else a=a*10+v[ans++];
    }
    return isPrime(a);
}
void dfs(int now){
    if(found) return;
    if(now>n){
        int a=0;
        if(isStrPrime(v,in,a)){
            cout<<a<<endl;
            found=true;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        v.push_back(i);
        dfs(now+1);
        v.pop_back();
    }

}
int main(){
    cin>>t;
    while(t--){
        cin>>in;
        n=0,found=false;
        v.clear();
        for(size_t i=0;i<in.size();i++){
            if(in[i]=='*') n++;
        }
        dfs(1);
        if(!found) cout<<-1<<endl;

    }
    return 0;
}