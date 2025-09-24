#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<string,int> data;
    int count=0;
    while(n--){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                string name;
                int score;
                cin>>name>>score;
                if(data.find(name)==data.end()) count++;                
                data[name]=score;
                cout<<"OK"<<endl;
                break;
            }
            case 2:{
                string name;
                cin>>name;
                auto i=data.find(name);
                if(i==data.end()){
                    cout<<"Not found"<<endl;
                    break;
                }
                cout<<i->second<<endl;
                break;
            }
            case 3:{
                string name;
                cin>>name;
                auto i=data.find(name);
                if(i==data.end()){
                    cout<<"Not found"<<endl;
                    break;
                }
                data.erase(name);
                count--;
                cout<<"Deleted successfully"<<endl;  
                break;
            }
            default:{
                cout<<count<<endl;
            }
        }
    }
    return 0;
}