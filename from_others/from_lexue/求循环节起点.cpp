 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );

#include<unordered_map>
#include<vector>
using namespace std;
NODE*find(NODE*h,int *n){
    NODE*fast=h,*slow=h;
    do{
        fast=fast->next->next;
        slow=slow->next;
    }while(fast!=slow);
    *n=0;
    do{
        fast=fast->next;
        (*n)++;
    }while(fast!=slow);
    fast=h,slow=h;
    for(int i=0;i<*n;i++){
        fast=fast->next;
    }
    do{
        fast=fast->next;
        slow=slow->next;
    }while(fast!=slow);
    return fast;


}
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
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}