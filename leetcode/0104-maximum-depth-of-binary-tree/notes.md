# 104. 二叉树的最大深度（Maximum Depth of Binary Tree）

- 难度：简单
- 标签：树、深度优先搜索、广度优先搜索、二叉树
- 链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree/

## 题目

给定二叉树根节点 `root`，返回其最大深度。

最大深度：从根节点到最远叶子节点的最长路径上的**节点数**。

## 例子

```text
      3
     / \
    9  20
      /  \
     15   7
```

输入：`root = [3,9,20,null,null,15,7]`  
输出：`3`（最长路径如 `3→20→15` 或 `3→20→7`，共 3 个节点）

## 思路（递归）

一棵树的最大深度：

```text
maxDepth(root) = 0                          （root 为空）
maxDepth(root) = 1 + max(左子树深度, 右子树深度)  （否则）
```

人话：站在当前节点，看左、右两边谁更深，再算上自己这一层。

### 走一遍例子

```text
maxDepth(3) = 1 + max(maxDepth(9), maxDepth(20))
maxDepth(9) = 1 + max(0, 0) = 1
maxDepth(20) = 1 + max(maxDepth(15), maxDepth(7)) = 1 + max(1, 1) = 2
⇒ maxDepth(3) = 1 + max(1, 2) = 3
```

### 和中序遍历的关系

94 中序是「按左-根-右访问每个节点」；  
这题也是递归进左右子树，但关心的是**深度数值**，不是访问顺序。

也可用层序遍历（BFS）：一层层数，层数就是深度。

## 代码

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

## 复杂度

- 时间：O(n)，每个节点访问一次
- 空间：O(h)，递归栈深度为树高

## 感想 / 踩坑

- 深度按「节点个数」算，不是边的条数（根到叶子有 2 条边时深度是 3）
- 空树返回 0，单节点返回 1
- 这是二叉树递归的经典模板题
