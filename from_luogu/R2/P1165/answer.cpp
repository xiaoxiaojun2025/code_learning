#include<iostream>
#include<stack>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<1) return 0;
    stack<int> st;
    set<int> myset;
    while(n--){
        int op;
        cin>>op;
        switch(op){
            case 0:{
                int x;
                cin>>x;
                st.push(x);
                myset.insert(x);
                break;
            }
            case 1:{
                if(!st.empty()){
                    myset.erase(st.top());
                    st.pop();
                }
                break;
            }
            case 2:{
                if(st.empty()){
                    cout<<0<<endl;
                    break;
                }
                cout<<*prev(myset.end())<<endl;
                break;
            }
            default:break;
        }
    }
    return 0;
}