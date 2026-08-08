#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }

private:
    // 当前子树所有节点必须落在 (low, high) 开区间内
    bool check(TreeNode* node, long long low, long long high) {
        if (node == nullptr) return true;
        if (node->val <= low || node->val >= high) return false;
        // 左子树：都要比当前小；右子树：都要比当前大
        return check(node->left, low, node->val)
            && check(node->right, node->val, high);
    }
};
