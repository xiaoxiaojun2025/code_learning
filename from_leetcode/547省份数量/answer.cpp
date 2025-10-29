class Solution {
    #define MAXSIZE 210
private:
    struct UFS {
        int elem[MAXSIZE];
        UFS(){
            for (int i = 0; i < MAXSIZE; i += 1) {
                elem[i] = -1;
            }
        }
    };
    struct Stack {
        int elem[MAXSIZE];
        int top;
        Stack(): top(-1) {}
    };
    int findRoot(UFS* &ufs, Stack* &stack, int a) {
        while (ufs->elem[a] >= 0) {
            stack->elem[++(stack->top)] = a;
            a = ufs->elem[a];
        }
        while (stack->top != -1) {
            ufs->elem[stack->elem[(stack->top)--]] = a;
        }
        return a;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = n;
        UFS* ufs = new UFS();
        Stack* stack = new Stack();
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (i == j || !isConnected[i][j]) continue;
                int i1 = findRoot(ufs, stack, i), j1 = findRoot(ufs, stack, j);
                if (i1 == j1) continue;
                if (ufs->elem[i1] < ufs->elem[j1]) {
                    ufs->elem[i1] += ufs->elem[j1];
                    ufs->elem[j1] = i1;
                } 
                else {
                    ufs->elem[j1] += ufs->elem[i1];
                    ufs->elem[i1] = j1;
                }
                res -= 1;
            }
        }
        delete ufs;
        delete stack;
        return res;
    }
};