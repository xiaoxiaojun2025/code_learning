/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                TreeNode *ancestor = root;
        while (1) {
            if (ancestor->val > p->val && ancestor->val > q->val) {
                ancestor = ancestor->left;
            } else if (ancestor->val < p->val && ancestor->val < q->val) {
                ancestor = ancestor->right;
            } else {
                return ancestor;
            }
        }
    }
};