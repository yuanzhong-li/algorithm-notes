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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

private:
    // 判断两棵树是否互为镜像
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;   // 都空，对称
        if (a == nullptr || b == nullptr) return false;  // 一个空一个不空
        if (a->val != b->val) return false;               // 值不同
        // 镜像：a 的左对 b 的右，a 的右对 b 的左
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
};
