#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        auto up=grid.begin()+x,down=grid.begin()+x+k-1;
        while(up<down){
            vector<int> temp(k);
            copy((*up).begin()+y,(*up).begin()+y+k,temp.begin());
            copy((*down).begin()+y,(*down).begin()+y+k,(*up).begin()+y);
            copy(temp.begin(),temp.end(),(*down).begin()+y);
            up++;
            down--;
        }
        return grid;    
    }
};

