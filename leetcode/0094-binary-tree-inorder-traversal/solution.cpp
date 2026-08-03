#include <vector>
#include <stack>
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
    // 递归写法（最直观）
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;
        dfs(node->left, ans);      // 左
        ans.push_back(node->val);  // 根
        dfs(node->right, ans);     // 右
    }
};

/*
// 迭代写法（用栈模拟递归）
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {   // 一路向左走到底
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();            // 访问「最左」节点
            st.pop();
            ans.push_back(cur->val);
            cur = cur->right;          // 转向右子树
        }
        return ans;
    }
};
*/
