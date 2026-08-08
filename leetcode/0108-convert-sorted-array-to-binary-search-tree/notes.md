# 108. 将有序数组转换为二叉搜索树（Convert Sorted Array to Binary Search Tree）

- 难度：简单
- 标签：树、二叉搜索树、数组、分治、二叉树
- 链接：https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/

## 题目

给定升序整数数组 `nums`，将其转换为一棵**高度平衡**的二叉搜索树（BST）。

高度平衡：每个节点的左右子树高度差绝对值不超过 1。

## 例子

输入：`nums = [-10,-3,0,5,9]`  
一种输出：`[0,-3,9,-10,null,5]`（答案不唯一）

```text
      0
     / \
   -3   9
   /   /
-10   5
```

## 思路（取中点作根）

有序数组的中序遍历就是它自己。要建 BST 且平衡：

1. 选区间中点 `mid` 当根（左右元素个数尽量接近 → 平衡）
2. 左半段 `[left, mid-1]` 递归建左子树  
3. 右半段 `[mid+1, right]` 递归建右子树  

因为数组已排序：左边都更小、右边都更大，自然满足 BST。

### 走一遍例子

`[-10,-3,0,5,9]`，下标 `0..4`，`mid=2` → 根 `0`

- 左：`[-10,-3]` → mid 取 `-3`，左孩子 `-10`  
- 右：`[5,9]` → mid 取 `5`，右孩子 `9`（或 mid 取 `9`，得到另一种合法答案）

### 和前面题的关系

| 题 | 关系 |
|----|------|
| 94 中序遍历 | BST 中序是有序序列；这题是「有序序列 → BST」的逆过程 |
| 108 | 用分治：中点作根，保证平衡 |

## 代码

```cpp
TreeNode* build(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
}
```

## 复杂度

- 时间：O(n)，每个元素建一次节点
- 空间：O(log n)，递归栈（平衡树高度）

## 感想 / 踩坑

- 答案不唯一：中点取左中位或右中位都可以
- `mid = left + (right-left)/2` 防止溢出
- 空区间 `left > right` 返回 `nullptr`
