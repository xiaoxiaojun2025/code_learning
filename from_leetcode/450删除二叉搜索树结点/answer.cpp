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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) return nullptr;
            else if (root->left == nullptr) {
                return root->right;
            }
            else if (root->right == nullptr) {
                return root->left;
            }
            else {
                TreeNode* p = root->right;
                while (p->left != nullptr) {
                    p = p->left;
                }
                root->val = p->val;
                root->right = deleteNode(root->right, p->val);
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};