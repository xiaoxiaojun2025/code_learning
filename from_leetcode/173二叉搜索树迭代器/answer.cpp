/**
 * Definition for a binary tree node->
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    #define MAXSIZE 50
private:
    struct Stack{
        TreeNode* elem[MAXSIZE];
        int top;
        Stack() : top(-1) {}
    };
    Stack* stack;
    TreeNode* curr;
public:
    BSTIterator(TreeNode* root) {
        stack = new Stack();
        TreeNode* p = root;
        while (p != nullptr) {
            stack->elem[++(stack->top)] = p;
            p = p->left;
        }
        curr = new TreeNode(-10000, nullptr, nullptr);
    }
    
    int next() {
        if (curr->right != nullptr) {
            curr = curr->right;
            while (curr->left != nullptr) {
                stack->elem[++(stack->top)] = curr;
                curr = curr->left;
            }
        }
        else {
            curr = stack->elem[(stack->top)--];
        }
        return curr->val;
    }
    
    bool hasNext() {
        return curr->right != nullptr || stack->top != -1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */