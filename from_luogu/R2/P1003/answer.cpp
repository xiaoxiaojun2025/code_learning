#include<iostream>
#include<vector>
using namespace std;
struct carpet{
    int a,b;
    int x_length,y_length;
};
struct dot{
    int a,b;
};
bool isCovered(carpet carp,dot e){
    return e.a>=carp.a&&e.a<=carp.a+carp.x_length&&e.b>=carp.b&&e.b<=carp.b+carp.y_length;
}
int main(){
    int n;
    cin>>n;
    if(n<1){
        cout<<-1<<endl;
        return 0;
    }
    vector<carpet> data(n);
    for(int i=0;i<n;i++){
        cin>>data[i].a>>data[i].b>>data[i].x_length>>data[i].y_length;
    }
    dot d;
    cin>>d.a>>d.b;
    int found=-1;
    for(int i=n-1;i>=0;i--){
        if(isCovered(data.at(i),d)){
            found=i;
            break;
        }
    }
    cout<<found<<endl;
    return 0;
}
