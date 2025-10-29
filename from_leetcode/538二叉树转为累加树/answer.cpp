/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    #define MAXSIZE 50
private:
    struct Stack{
        TreeNode* elem[MAXSIZE];
        int top;
        Stack(): top(-1) {}
    };
public:
    TreeNode* convertBST(TreeNode* root) {
        Stack* stack = new Stack();
        TreeNode* p = root;
        if (p == nullptr) return nullptr;
        while (p->right != nullptr) {
            stack->elem[++(stack->top)] = p;
            p = p->right;
        }
        while (stack->top != -1 || p->left != nullptr) {
            int temp = p->val;
            if (p != nullptr && p->left != nullptr) {
                p = p->left;
                while (p != nullptr) {
                    stack->elem[++(stack->top)] = p;
                    p = p->right;
                }
            }
            p = stack->elem[(stack->top)--];
            p->val += temp;
        }
        delete stack;
        return root;
    }
};