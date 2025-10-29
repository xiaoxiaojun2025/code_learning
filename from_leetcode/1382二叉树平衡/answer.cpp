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
private:
    void inOrder(TreeNode* root,vector<int> &v) {
        if (root == nullptr) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    TreeNode* buildTree(vector<int> &v, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* lh = buildTree(v, start, mid - 1);
        TreeNode* rh = buildTree(v, mid + 1, end);
        return new TreeNode(v[mid], lh, rh);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v ;
        inOrder(root, v);
        return buildTree(v, 0, v.size() - 1);
    }
};