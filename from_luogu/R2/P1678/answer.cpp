#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> sch(m),stu(n);
    for(auto &i:sch) cin>>i;
    for(auto &i:stu) cin>>i;
    long long sum=0;
    sort(sch.begin(),sch.end());
    sort(stu.begin(),stu.end());
    for(int i=0;i<n;i++){
        if(stu[i]>sch[m-1]){
            sum+=stu[i]-sch[m-1];
            continue;
        }
        if(stu[i]<sch[0]){
            sum+=sch[0]-stu[i];
            continue;
        }
        auto bigger=lower_bound(sch.begin(),sch.end(),stu[i]);
        auto smaller=prev(bigger);
        sum+=min(stu[i]-*smaller,*bigger-stu[i]);
    }
    cout<<sum<<endl;
    return 0;

}