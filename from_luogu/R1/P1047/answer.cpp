#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int l,m;
    cin>>l>>m;
    set<int>toDelete;
    vector <vector<int>> area(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>area[i][j];
        }
        for(int k=area[i][0];k<=area[i][1];k++){
            toDelete.insert(k);
        }
    }
    int count=l+1-toDelete.size();
    cout<<count<<endl;
    return 0;
}