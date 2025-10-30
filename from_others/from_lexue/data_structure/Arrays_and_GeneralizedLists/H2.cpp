/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  
  
typedef enum { ATOM, LIST } ListTag;  
  
typedef struct node {  
    ListTag  tag;  
    union {  
        char  data;  
        struct node *hp;  
    } ptr;  
    struct node *tp;  
} GLNode;  
  
GLNode * reverse( GLNode * );  
  
int count;  
  
void Substring( char *sub, char *s, int pos, int len )  
{  
    s = s + pos;  
    while ( len > 0 )  
    {   *sub = *s;  
        sub++;  
        s++;  
        len--;  
    }  
    *sub = '\0';  
}  
  
void sever( char *str, char *hstr )  
{   int n, i, k;  
    char ch[50];  
    n = strlen(str);  
    i = k = 0;  
    do  
    {   Substring( ch, str, i++, 1 );  
        if ( *ch=='(' )  
            k ++;  
        else if ( *ch==')' )  
            k --;  
    } while ( i<n && ( *ch!=',' || k!=0 ) );  
  
    if ( i<n )  
    {   Substring( hstr, str, 0, i-1 );  
        Substring( str, str, i, n-i );  
    }  
    else  
    {   strcpy( hstr, str );  
        str[0] = '\0';  
    }  
}  /* sever */  
  
int PrintGList( GLNode * T )  
{  
    GLNode *p=T, *q;  
  
    if ( p==NULL )  
        printf( ")" );  
    else  
    {   if ( p->tag==ATOM )  
        {   if ( count > 0 )  
                printf( "," );  
            printf( "%c", p->ptr.data );  
            count ++;  
        }  
        else  
        {   q = p->ptr.hp;  
            if ( q == NULL )  
            {   if ( count > 0 )  
                    printf(",");  
                printf("(");  
            }  
            else if ( q->tag == LIST )  
            {   if ( count > 0 )  
                    printf( "," );  
                printf( "(" );  
                count = 0;  
            }  
            PrintGList( q );  
            PrintGList( p->tp );  
        }  
    }  
    return 1;  
}  
  
void print( GLNode * L )  
{  
    if ( L == NULL )  
        printf( "()" );  
    else  
    {  
        if ( L->tag == LIST )  
            printf( "(" );  
        if ( L->ptr.hp != NULL )  
            PrintGList( L );  
        else  
        {  
            printf( "()" );  
            if ( L->tp == NULL )  
                printf( ")" );  
        }  
    }  
    printf( "\n" );  
}  
  
int CreateGList( GLNode **L,  char *s )  
{  
    GLNode *p, *q;  
    char sub[100],  hsub[100];  
  
    p = *L;  
    if ( strcmp(s, "()" )==0 )  
        *L = NULL;    /* 创建空表 */  
    else  
    {  
        *L = ( GLNode * ) malloc( sizeof( GLNode ) );  
        if ( strlen(s)==1 )  
        {   (*L)->tag = ATOM;  
            (*L)->ptr.data = s[0];  
        }  
        else  
        {   (*L)->tag = LIST;  
            p = *L;  
            Substring( sub, s, 1, strlen(s)-2 );  
            do  
            {   sever( sub, hsub );  
                CreateGList( &p->ptr.hp, hsub );  
                q = p;  
                if ( strlen(sub) > 0 )  
                {   p = (GLNode *) malloc( sizeof(GLNode) );  
                    p->tag = LIST;  
                    q->tp = p;  
                }  
            } while ( strlen(sub)>0 );  
            q->tp = NULL;  
        }   /* else */  
    }  /* else */  
    return 1;  
}  
  
/********** 
这是你要实现的函数。 
***********/  
GLNode * reverse( GLNode *p ) {
    if (p == NULL) return NULL;  // F(LS) = null 若 LS 为空
    
    if (p->tag == ATOM && p->tp == NULL) {
        // F(LS) = LS 若 LS 为原子，且 tail(LS) 为空
        GLNode *node = (GLNode *)malloc(sizeof(GLNode));
        node->tag = ATOM;
        node->ptr.data = p->ptr.data;
        node->tp = NULL;
        return node;
    }
    else if (p->tag == ATOM && p->tp != NULL) {
        // F(LS) = append( F(tail(LS)), head(LS) ) 若 LS->tag=0 ，且 LS->tp!=null
        GLNode *reversed_tail = reverse(p->tp);  // F(tail(LS))
        
        // 创建新节点来保存当前原子
        GLNode *current_atom = (GLNode *)malloc(sizeof(GLNode));
        current_atom->tag = ATOM;
        current_atom->ptr.data = p->ptr.data;
        current_atom->tp = NULL;
        
        // 将当前原子连接到反转后的表尾的末尾
        if (reversed_tail == NULL) {
            // 如果反转后的表尾为空，直接返回当前原子
            GLNode *new_list = (GLNode *)malloc(sizeof(GLNode));
            new_list->tag = LIST;
            new_list->ptr.hp = current_atom;
            new_list->tp = NULL;
            return new_list;
        }
        else {
            // 找到反转后表尾的最后一个节点
            GLNode *last = reversed_tail;
            while (last->tp != NULL) {
                last = last->tp;
            }
            // 将当前原子添加到末尾
            last->tp = (GLNode *)malloc(sizeof(GLNode));
            last->tp->tag = LIST;
            last->tp->ptr.hp = current_atom;
            last->tp->tp = NULL;
            return reversed_tail;
        }
    }
    else {
        // F(LS) = append( F(tail(LS), F(head(LS)) ) 若 LS->tag=1
        GLNode *reversed_tail = reverse(p->tp);      // F(tail(LS))
        GLNode *reversed_head = NULL;
        if (p->ptr.hp != NULL) {
            reversed_head = reverse(p->ptr.hp);  // F(head(LS))
        }
        
        // 将反转后的表头连接到反转后的表尾的末尾
        if (reversed_tail == NULL) {
            if (reversed_head == NULL) {
                return NULL;
            }
            // 如果只有表头，直接返回
            GLNode *new_list = (GLNode *)malloc(sizeof(GLNode));
            new_list->tag = LIST;
            new_list->ptr.hp = reversed_head;
            new_list->tp = NULL;
            return new_list;
        }
        else {
            // 找到反转后表尾的最后一个节点
            GLNode *last = reversed_tail;
            while (last->tp != NULL) {
                last = last->tp;
            }
            // 将反转后的表头添加到末尾
            last->tp = (GLNode *)malloc(sizeof(GLNode));
            last->tp->tag = LIST;
            last->tp->ptr.hp = reversed_head;
            last->tp->tp = NULL;
            return reversed_tail;
        }
    }
}
/*******************/  
  
int main( )  
{  
    char list[100];  
    GLNode *L, *G;  
    int d;  
  
    count = 0;  
    scanf("%s", list);  
    CreateGList( &L, list );  
  
/*  print( L );   */  
    G = reverse( L );  
    count = 0;  
    print( G );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  