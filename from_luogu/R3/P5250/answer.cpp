#include<iostream>
#include<set>
#include<algorithm>

using namespace std;
int main(){
    int m;
    cin>>m;
    set<int> myset;
    while(m--){
        int op,length;
        cin>>op>>length;
        if(op==1){
            if(myset.find(length)==myset.end()) myset.insert(length);
            else cout<<"Already Exist"<<endl;
        }
        else{
            if(myset.size()==0){
                cout<<"Empty"<<endl;
                continue;
            }
            if(myset.find(length)!=myset.end()){
                myset.erase(length);
                cout<<length<<endl;
            }
            else{
                auto left=myset.begin(),right=prev(myset.end());
                if(length<*left){
                    myset.erase(*left);
                    cout<<*left<<endl;
                    continue;
                }
                else if(length>*right){
                    myset.erase(*right);
                    cout<<*right<<endl;
                    continue;
                }
                while(*left<length){
                    left++;
                }
                right=left;
                left--;
                int out=(length-*left)<=(*right-length)?*left:*right;
                myset.erase(out);
                cout<<out<<endl;
            }
        }
    }
    return 0;
}