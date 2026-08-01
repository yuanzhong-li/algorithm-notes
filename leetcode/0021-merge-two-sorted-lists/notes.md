# 21. 合并两个有序链表（Merge Two Sorted Lists）

- 难度：简单
- 标签：递归、链表
- 链接：https://leetcode.cn/problems/merge-two-sorted-lists/

## 题目

将两个升序链表合并为一个新的升序链表并返回。  
新链表通过拼接两个链表的节点得到（不用新建值相同的节点）。

## 例子

输入：`list1 = [1,2,4]`，`list2 = [1,3,4]`  
输出：`[1,1,2,3,4,4]`

## 思路一：迭代 + 虚拟头节点

设一个假的头节点 `dummy`，用 `tail` 指向当前结果链表末尾。

每次比较 `list1`、`list2` 当前节点：

- 谁小（或相等）就把谁接到 `tail` 后面，该指针后移  
- `tail` 也后移  

某一条走完后，把另一条剩下的直接接上。  
返回 `dummy.next`（真正的头）。

```text
dummy → 1 → 1 → 2 → 3 → 4 → 4
        ↑ 从 list1 / list2 里拼出来的
```

### 为什么要用 dummy？

如果不用虚拟头，就要单独处理「结果链表第一个节点是谁」，代码更啰嗦。  
`dummy` 让「接在后面」的逻辑从头到尾一致。

## 思路二：递归（你截图里那种）

你缺的是最后的 `else` 分支：

```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
```

含义：

- 某一条为空 → 返回另一条  
- `list1` 更小 → `list1` 当头，后面接「合并 `list1->next` 与 `list2`」的结果  
- 否则 → `list2` 当头，后面接「合并 `list1` 与 `list2->next`」的结果  

相等时走 `else`，用 `list2` 也可以（稳定与否看实现，都能过）。

## 复杂度

- 时间：O(m + n)
- 空间：迭代 O(1)；递归 O(m + n) 栈空间

## 感想 / 踩坑

- 递归别漏 `else`：`list2` 更小或相等时要把 `list2` 接进去
- 迭代记得最后把剩余链表接上
- 和数组归并排序的「合并两段有序」是同一思想
