#include <stdio.h>  
#include <stdlib.h>   
#include<map>
using namespace std;
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );
#include<map>
using namespace std; 
void multiplication( NODE *head1, NODE *head2 , NODE *head3 ){
    map<int,int> mymap;
    NODE*p=head1->next,*q=head2->next;
    while(p){
        while(q){
            int a_exp=p->exp+q->exp;
            int a_coef=p->coef*q->coef;
            if(mymap.find(a_exp)==mymap.end()&&a_coef) mymap[a_exp]=a_coef;
            else{
                mymap[a_exp]+=a_coef;
            }
            q=q->next;
        }
        p=p->next;
        q=head2->next;
    }
    NODE*tail=head3;
    for(auto i=mymap.begin();i!=mymap.end();i++){
        if(!i->second) continue;
        NODE*m=(NODE*)malloc(sizeof(NODE));
        m->coef=i->second;
        m->exp=i->first;
        m->next=NULL;
        tail->next=m;
        tail=m;
    }
    if(head3->next==NULL){
        NODE*l=(NODE*)malloc(sizeof(NODE));
        l->coef=0;
        l->exp=0;
        l->next=NULL;
        head3->next=l;
    }
}
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}