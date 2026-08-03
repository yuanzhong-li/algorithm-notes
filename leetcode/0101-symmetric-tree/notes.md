# 101. 对称二叉树（Symmetric Tree）

- 难度：简单
- 标签：树、深度优先搜索、广度优先搜索、二叉树
- 链接：https://leetcode.cn/problems/symmetric-tree/

## 题目

给定二叉树根节点 `root`，检查它是否轴对称（自己的镜像）。

## 例子

```text
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

输入：`[1,2,2,3,4,4,3]` → `true`

若右边是 `2,null,3` 这种不对称结构 → `false`。

## 思路（判断两棵子树是否镜像）

整棵树对称 ⇔ 根的**左子树**和**右子树**互为镜像。

两棵树 `a`、`b` 互为镜像的条件：

1. 都为空 → 是  
2. 恰有一个空 → 否  
3. `a->val != b->val` → 否  
4. 否则还要：  
   - `a` 的左 和 `b` 的右 互为镜像  
   - `a` 的右 和 `b` 的左 互为镜像  

注意是「左对右、右对左」，不是左对左。

### 和翻转二叉树的关系

226 翻转：把左右孩子换过来。  
101 对称：检查「左边长什么样」是否等于「右边翻转后的样子」。

### 走一遍例子

根 1 的左右都是 2，值相同；  
再比：左 2 的左 3 对右 2 的右 3，左 2 的右 4 对右 2 的左 4……都对上 → `true`。

## 代码

```cpp
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}
```

## 复杂度

- 时间：O(n)
- 空间：O(h)，递归栈

## 感想 / 踩坑

- 关键是交叉比较：`left` 对 `right`，不是同侧比
- 空节点情况要先处理好，再比值
- 也可用队列做层序，每次取两个节点按镜像顺序入队
