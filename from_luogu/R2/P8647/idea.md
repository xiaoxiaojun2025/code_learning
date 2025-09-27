经典二分，设置l=1,r=100001, 循环$while(l<=r) mid=(l+r)/2$  

check函数为$if(sum((v[i].first/mid)\times(v[i].second/mid))>=K)$  
  
  满足则在右区间继续找，否则输出mid