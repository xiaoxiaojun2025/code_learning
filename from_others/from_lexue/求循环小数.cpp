 
#include <stdio.h>  
#include <stdlib.h>  
#include<unordered_map>
#include<vector>
using namespace std;
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  
void change( int, int, NODE * );  
#include<unordered_map>
#include<vector>
using namespace std;
void change(int n,int m,NODE*h){
    unordered_map <long long ,int> mymap;
    vector<int>v;
    size_t first=0;
    while(n){
        if(mymap.find(n)!=mymap.end()){
            first=mymap[n];
            break;
        }
        mymap[n]=(int)v.size();
        n*=10;
        int temp=n/m;
        v.push_back(temp);
        n%=m;
    }
        NODE*tail=h;
    if(!n){
        for(size_t i=0;i<v.size();i++){
            NODE*p=(NODE*)malloc(sizeof(NODE));
            p->data=v[i];
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
    }
    else{
        for(size_t i=0;i<first;i++){
            NODE*p=(NODE*)malloc(sizeof(NODE));
            p->data=v[i];
            p->next=NULL;
            tail->next=p;
            tail=p;  
        }
        NODE*t1=tail;
        for(size_t i=first;i<v.size();i++){
            NODE*p=(NODE*)malloc(sizeof(NODE));
            p->data=v[i];
            p->next=NULL;
            t1->next=p;
            t1=p;           
        }
        t1->next=tail->next;
    }


} 
void output( NODE * head, int kk )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  