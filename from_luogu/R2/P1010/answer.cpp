#include<iostream>
#include<vector>
#include<stack>
#include<iterator>
#include<string>
using namespace std;
vector<int> broken(int n){
    vector<int> v1;
    while(n>0){
        v1.push_back(n%2);
        n/=2;
    }
    vector<int>temp;
    for(int i=(int)v1.size()-1;i>=0;i--){
        if(v1[i]) temp.push_back(i);
    }
    return temp;
}
void getAnswer(vector<int> v,string &output){
    for(size_t i=0;i<v.size();i++){
        switch(v[i]){
            case 2:output.append("2(2)");break;
            case 0:output.append("2(0)");break;
            case 1:output.append("2");break;
            default:
                output.append("2(");
                getAnswer(broken(v[i]),output);
                output.append(")");
                break;
        }
        if(i!=v.size()-1) output.append("+");
    }
}
int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Input error"<<endl;
        return 0;
    }
    string o;
    getAnswer(broken(n),o);
    cout<<o<<endl;
    return 0;
}

