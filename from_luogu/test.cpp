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
  char c='B';
  cout<<c<<endl;
  return 0;
}