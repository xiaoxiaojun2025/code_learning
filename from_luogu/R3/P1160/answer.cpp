#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    if(N<0) return 1;
    vector<int> left(N+2,-1),right(N+2,-1);
    left[1]=0;
    right[0]=1;
    left[N+1]=1;
    right[1]=N+1;
    for(int i=2;i<=N;i++){
        int k,p;
        cin>>k>>p;
        if(k<1) continue;
        if(p){
            left[right[k]]=i;
            right[i]=right[k];
            right[k]=i;
            left[i]=k;
        }
        else{
            right[left[k]]=i;
            left[i]=left[k];
            right[i]=k;
            left[k]=i;
        }
    }
    int M;
    cin>>M;
    if(M<0) return 1;
    while(M--){
        int x;
        cin>>x;
        if(left[x]==-1&&right[x]==-1) continue;
        right[left[x]]=right[x];
        left[right[x]]=left[x];
        left[x]=right[x]=-1;
    }
    int cur=right[0];
    while(cur!=N+1){
        cout<<cur<<" ";
        cur=right[cur];
    }
}