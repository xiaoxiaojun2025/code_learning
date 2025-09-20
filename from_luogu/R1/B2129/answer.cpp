#include<iostream>
#include<iomanip>
using namespace std;
int maxOfThree(int a,int b,int c){
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    return max;
}
double calculate_m(int a,int b,int c){
    return (double)maxOfThree(a,b,c)/(maxOfThree(a+b,b,c)*maxOfThree(a,b,b+c));
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<fixed<<setprecision(3)<<calculate_m(a,b,c)<<endl;
    return 0;
}