#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void changeBase(int n,int base,char* result,int *count){
    if(base<2){
        printf("Input error.\n");
        return;
    }
    if(n==0) return;
        changeBase(n/base,base,result,count);
        char c;
        if(n%base>9) c='A'+n%base-10;
        else c='0'+n%base;
        result[(*count)++]=c;
}
int main(){
    int n,base;
    scanf("%d%d",&n,&base);
    if(n==0){
        printf("0\n");
        return 0;
    }
    int count=0;
    char*result=(char*)malloc(70*sizeof(char));
    changeBase(n,base,result,&count);
    result[count]='\0';
    puts(result);
    free(result);
    return 0;

}