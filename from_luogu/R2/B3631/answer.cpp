
//映射与哈希表
#include<iostream>
#include<list>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(){
    int q;
    cin>>q;
    list<int> lst{1};
    unordered_map<int ,list<int>::iterator> mymap;
    mymap[1]=lst.begin();
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op<0) return 0;
        switch(op){
            case 1:{
                int x,y;
                cin>>x>>y;
                auto index=mymap[x];
                index++;
                lst.insert(index,y);
                mymap[y]=prev(index);
                break;
            }
            case 2:{
                int x;
                cin>>x;
                auto index=mymap[x];
                if(next(index)==lst.end()){
                    cout<<0<<endl;
                    break;
                }
                index++;
                cout<<*index<<endl;
                break;
            }
            case 3:{
                int x;
                cin>>x;
                auto index=mymap[x];
                if(next(index)==lst.end()) break;
                index++;
                mymap.erase(*index);
                lst.erase(index);
                break;
            }
            default:return 0;
            }
        }
        return 0;
}