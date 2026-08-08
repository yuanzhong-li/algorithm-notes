# 98. 验证二叉搜索树（Validate Binary Search Tree）

- 难度：中等
- 标签：树、深度优先搜索、二叉搜索树、二叉树
- 链接：https://leetcode.cn/problems/validate-binary-search-tree/

## 题目

给定二叉树根节点，判断是否为有效的**二叉搜索树（BST）**。

BST 定义：

- 节点左子树的所有值都 **严格小于** 该节点  
- 节点右子树的所有值都 **严格大于** 该节点  
- 左右子树也必须是 BST  

## 例子

```text
  2
 / \
1   3
```
是 BST → `true`

```text
    5
   / \
  1   4
     / \
    3   6
```
不是：3 在 5 的右子树里，但 3 < 5 → `false`

## 思路（带上下界的递归）

### 常见错误

只检查「左孩子 < 自己 < 右孩子」不够。例如：

```text
      5
     / \
    1   6
       / \
      3   7
```

直接孩子看起来都合法，但 **3 在 5 的右子树里却比 5 小**，不是 BST。  
所以要保证整棵子树相对所有祖先都合法。

### 正确做法：每个节点带合法区间 `(low, high)`

当前节点（及其子树）必须满足：`low < val < high`。

| 位置 | 区间 |
|------|------|
| 根 | `(-∞, +∞)` |
| 往左 | 上界变成当前值 → `(low, val)` |
| 往右 | 下界变成当前值 → `(val, high)` |

根一开始用 `LLONG_MIN/MAX`（`long long`），避免节点值是 `INT_MIN/MAX` 时出问题。

### 走一遍反例

上面那棵树：到节点 3 时区间是 `(5, 6)`，要求 `5 < 3 < 6`，不成立 → `false`。

再看题面例子：

```text
    5
   / \
  1   4
     / \
    3   6
```

到节点 3：在 5 的右子树，下界应是 5；`3 < 5` → `false`。

### 另一种：中序遍历

BST 的中序是严格递增序列。中序扫一遍，看是否始终 `prev < 当前` 即可。

| 做法 | 要点 |
|------|------|
| **上下界递归** | 每个节点带合法范围 |
| 中序 | 序列必须严格递增 |

## 代码

```cpp
bool check(TreeNode* node, long long low, long long high) {
    if (!node) return true;
    if (node->val <= low || node->val >= high) return false;
    return check(node->left, low, node->val)
        && check(node->right, node->val, high);
}
```

## 复杂度

- 时间：O(n)
- 空间：O(h)

## 感想 / 踩坑

- 不能只比父子，要管整棵子树相对祖先的约束
- 是**严格**小于/大于，相等也不行
- 边界用 `long long`，别用 `INT_MIN/MAX` 当初值硬比
- 和 108「有序数组建 BST」对照：那边保证建出来合法，这边检查一棵树是否合法
