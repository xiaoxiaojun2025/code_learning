class Solution {
    #define MAXSIZE 1010
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
    void connectRoot(UFS*& ufs, int a, int b) {
        int a1 = ufs->elem[a], b1 = ufs->elem[b];
        if (a1 >= 0 || b1 >= 0) {return;}
        if (a1 < b1) {
            ufs->elem[a] += ufs->elem[b];
            ufs->elem[b] = a; 
        }
        else {
            ufs->elem[b] += ufs->elem[a];
            ufs->elem[a] = b;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UFS* ufs = new UFS();
        Stack* stack = new Stack();
        int n = edges.size();
        for (int i = 0; i < n; i += 1) {
            int a = edges[i][0], b = edges[i][1];
            int a1 = findRoot(ufs, stack, a), b1 = findRoot(ufs, stack, b);
            if (a1 == b1) {return vector<int> {a, b};}
            connectRoot(ufs, a1, b1);
        }
        return {};
    }
};