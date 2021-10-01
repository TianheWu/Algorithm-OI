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
    bool ans = true;
    long long pre_val = (long long) INT_MIN - 5;
    void mid_order(TreeNode* root) {
        if (!root) return ;
        mid_order(root->left);
        if (root->val <= pre_val) {
            ans = false; return ;
        } else pre_val = root->val;
        mid_order(root->right);
    }
    bool isValidBST(TreeNode* root) {
        mid_order(root);
        return ans;
    }
};