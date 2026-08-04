#include <algorithm>
using namespace std;

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
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }

private:
    int ans;

    // 返回以 node 为根的子树高度（边数意义上：叶子高度为 0）
    // 顺便用「左高度 + 右高度」更新直径
    int depth(TreeNode* node) {
        if (node == nullptr) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L + R);   // 经过本节点的最长路径边数
        return max(L, R) + 1;    // 本节点高度
    }
};
