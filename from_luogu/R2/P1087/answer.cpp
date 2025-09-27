#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct tree{
    char data;
    tree*lchild,*rchild;
    tree(char x):data(x),lchild(nullptr),rchild(nullptr){}
};
struct head{
    tree*next;
};
head*h=new head{nullptr};

char whatStr(string s){
    for(size_t i=1;i<s.size();i++){
        if(s[i]!=s[0]) return 'F'; 
    }
    if(s[0]=='1') return 'I';
    else return 'B';
}
void createFBItree(string s,tree *&t){
    if(s.empty()) return ;
    t=new tree(whatStr(s));
    string s1=s.substr(0,s.size()/2),s2=s.substr(s.size()/2,s.size()/2);
    createFBItree(s1,t->lchild);
    createFBItree(s2,t->rchild);
}
void postOrder(tree *T){
    if(T==nullptr) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout<<T->data;
}
int main(){
    int N;
    string s;
    cin>>N>>s;
    createFBItree(s,h->next);
    postOrder(h->next);
    return 0;
}