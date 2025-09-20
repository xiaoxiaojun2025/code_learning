
//函数递归求解，时间复杂度高
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
struct Position{
    int x,y;
};
ll waysOfQuestion(Position destination,vector<Position> horses){
    if(destination.x<0||destination.y<0) return 0;
    if(destination.x==0&&destination.y==0) return 1;
    for(auto horse:horses){
        if(destination.x==horse.x&&destination.y==horse.y){
            return 0;
        }
    }
    return waysOfQuestion({destination.x-1,destination.y},horses)+waysOfQuestion({destination.x,destination.y-1},horses);
}
int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1<1||y1<1||x1>20||y1>20||x2<0||y2<0||x2>20||y2>20){
        cout<<"Input error"<<endl;
        return 1;
    }
    Position destination,horse;
    destination.x=x1;
    destination.y=y1;
    horse.x=x2;
    horse.y=y2;
    vector<Position> horses;
    horses.push_back({horse.x,horse.y});
    horses.push_back({horse.x-2,horse.y-1});
    horses.push_back({horse.x-1,horse.y-2});
    horses.push_back({horse.x+1,horse.y-2});
    horses.push_back({horse.x+2,horse.y-1});
    horses.push_back({horse.x-2,horse.y+1});
    horses.push_back({horse.x-1,horse.y+2});
    horses.push_back({horse.x+1,horse.y+2});
    horses.push_back({horse.x+2,horse.y+1});
    cout<<waysOfQuestion(destination,horses)<<endl;
    return 0;
}
