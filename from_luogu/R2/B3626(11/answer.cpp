#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int n;
struct pos{
    int x;
    int cost;
    pos(int ax,int acost):x(ax),cost(acost){}
};
deque<pos> d;
vector<bool>used;
int main(){
    cin>>n;
    if(n<=1){
        cout<<1<<endl;
        return 0;
    }
    used.assign(2*n+2,false);
    d.push_back(pos(1,0));
    used[1]=true;
    used[0]=true;
    for(int i=n+1;i<=2*n+2;i++){
        used[i]=true;
    }
    while(d.front().x!=n){
        auto i=d.front().x,j=d.front().cost;
        if(!used[i*2]) {d.push_back(pos(i*2,j+1));used[i*2]=true;}
        if(!used[i+1]) {d.push_back(pos(i+1,j+1));used[i+1]=true;}
        if(!used[i-1]) {d.push_back(pos(i-1,j+1));used[i-1]=true;}
        d.pop_front();
    }
    cout<<d.front().cost<<endl;
    return 0;


}