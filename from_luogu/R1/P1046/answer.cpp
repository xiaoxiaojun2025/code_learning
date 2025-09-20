#include<iostream>
#include<vector>
using namespace std;

int main(){
    int count=0,myheight;
    vector<int> apple_height(10);
    for(int i=0;i<10;i++){
        cin>>apple_height.at(i);
    }
    cin>>myheight;
    for(auto apple:apple_height){
        if(myheight+30>=apple) count++;
    }
    cout<<count<<endl;
}