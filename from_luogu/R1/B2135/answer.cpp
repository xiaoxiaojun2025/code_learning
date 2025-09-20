#include<iostream>
#include<string>
using namespace std;
void replaceWord(string &line,string substitute,string alternative){
    int i=0;  
    while(1){
        int pos= line.find(substitute,i)==string::npos ? -1:line.find(substitute,i);
        if(pos==-1) break;
        line.replace(pos,substitute.size(),alternative);
        i=pos;
      }
}
int main(){
    string line,substitute,alternative;
    getline(cin,line);
    cin>>substitute>>alternative;
    replaceWord(line,substitute,alternative);
    cout<<line<<endl;
}