[answer.cpp]:answer.cpp
[answer1.cpp]:answer1.cpp
[answer2.cpp]:answer2.cpp
一开始采用递归[answer.cpp]，时间复杂度过大$O(2^{n+m})$  
之后采用动态规划数组递推方式[answer1.cpp]，时间复杂度约为$O(n\times m\times k)$,本题$k=9$不是很大，若k过大answer1.cpp效率较低，因而可以优化改为先标记封锁点而不是在循环时遍历判断是不是封锁点，时间复杂度可以优化为$O(n\times m)$[answer2.cpp]