#include <iostream>
using namespace std;
bool isPrimeNumber(int n){
  for(int i=2;i<n;i++){
    if(n%i==0) return false;
  }
  return true;
}
int main()
{
  int count=0,i=2;
  while(count<2025){
    if(isPrimeNumber(i)) count++;
    i++;
  }
  cout<<i-1<<endl;
  // 请在此输入您的代码
  return 0;
}