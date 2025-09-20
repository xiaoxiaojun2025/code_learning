#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> data(n);
    set<int> sub;
    for(int i=0;i<n;i++){
        cin>>data.at(i);
    }
    for(auto i=data.begin();i!=data.end()-1;i++){
        sub.insert(abs(*i-*(i+1)));
    }
    if((int)sub.size()==n-1) cout<<"Jolly"<<endl;
    else cout<<"Not jolly"<<endl;
    return 0;
}
