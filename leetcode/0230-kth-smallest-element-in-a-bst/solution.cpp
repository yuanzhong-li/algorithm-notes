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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }

private:
    int k;
    int ans;

    // BST 中序 = 从小到大；走到第 k 个就是答案
    void dfs(TreeNode* node) {
        if (node == nullptr || k == 0) return;
        dfs(node->left);
        if (--k == 0) {
            ans = node->val;
            return;
        }
        dfs(node->right);
    }
};
