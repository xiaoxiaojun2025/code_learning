extern "C" int Seniorious(int);
extern "C" int Chtholly(int n,int c){
    int left=0,right=n+1,mid=0;
    while(right-left>1){
        mid=(left+right)/2;
        int temp=Seniorious(mid);
        if(temp==0) return mid;
        else if(temp==1) right=mid;
        else left=mid;
    }
    return 0;
}