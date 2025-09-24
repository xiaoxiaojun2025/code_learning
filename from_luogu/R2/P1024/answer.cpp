#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int calculate(vector<double> v,double x){
    double res= x*x*x*v[0]+x*x*v[1]+x*v[2]+v[3];
    if(res==0) return 0;
    else if(res>0) return 1;
    else return -1;
}
void getAnswer(double left,double right,vector<double> &res){
    
}
int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<double> res;
    double left=-101,right=101,mid=0;
    getAnswer(left,right,res);
}