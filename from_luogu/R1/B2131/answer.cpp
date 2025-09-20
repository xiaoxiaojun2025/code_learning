#include<iostream>
#include<string>
using namespace std;
class patient{
    public:
        string name;
        float temperature;
        int isCough;
    public:
        bool isSick();
};
bool patient::isSick(){
    if(temperature>=37.5&&isCough==1){
        cout<<name<<endl;
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n,count=0;
    cin>>n;
    for(int i=0;i<n;i++){
        patient a;
        cin>>a.name>>a.temperature>>a.isCough;
        if(a.isSick()) count++;
    }
    cout<<count<<endl;
    return 0;
}


