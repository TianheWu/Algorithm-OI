#include <bits/stdc++.h>
using namespace std;

int n;
char root_char, root_left, root_right;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val('0'), left(NULL), right(NULL) {}
    TreeNode(char c) : val(c), left(NULL), right(NULL) {}
};

TreeNode* find_node(TreeNode* root, char c) {
    if (root->val == c)
        return root;
    TreeNode* ret_root = NULL;
    if (root->left)
        ret_root = find_node(root->left, c);
    if (ret_root)
        return ret_root;
    if (root->right)
        ret_root = find_node(root->right, c);
    return ret_root;
}

TreeNode* build(char c) {
    if (c == '*')
        return NULL;
    TreeNode* ret_root = new TreeNode(c);
    return ret_root;
}

void pre_order(TreeNode* root) {
    if (!root)
        return;
    cout << root->val;
    pre_order(root->left);
    pre_order(root->right);
}

int main() {
    cin >> n;
    cin >> root_char >> root_left >> root_right;
    TreeNode* root = new TreeNode(root_char);
    root->left = build(root_left);
    root->right = build(root_right);
    for (int i = 1; i < n; i++) {
        cin >> root_char >> root_left >> root_right;
        TreeNode* cur_node = find_node(root, root_char);
        cur_node->left = build(root_left);
        cur_node->right = build(root_right);
    }
    pre_order(root);
    return 0;
}