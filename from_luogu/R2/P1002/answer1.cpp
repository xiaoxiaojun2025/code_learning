//递推求解，时间复杂度较低
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
struct Position{
    int x,y;
};
ll waysOfQuestion(Position destination,vector<Position> horses){
    ll dp[destination.x+1][destination.y+1];
    for(int i=0;i<=destination.x;i++){
        for(int j=0;j<=destination.y;j++){
            bool flag=true;
            for(auto horse:horses){
                if(i==horse.x&&j==horse.y){
                    dp[i][j]=0;
                    flag=false;
                    break;
                }
            }
            if(flag){
                if(i==0&&j==0) dp[i][j]=1;
                else if(i==0&&j!=0) dp[i][j]=dp[i][j-1];
                else if(j==0&&i!=0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[destination.x][destination.y];
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