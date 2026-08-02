# 24. 两两交换链表中的节点（Swap Nodes in Pairs）

- 难度：中等
- 标签：递归、链表
- 链接：https://leetcode.cn/problems/swap-nodes-in-pairs/

## 题目

给定链表，两两交换其中相邻的节点，返回交换后的链表头。  
**不能只改节点内部的值**，必须真正交换节点。

## 例子

输入：`1 → 2 → 3 → 4`  
输出：`2 → 1 → 4 → 3`

输入：`[]` → `[]`  
输入：`[1]` → `[1]`（只剩一个，没法成对，不动）

## 思路（虚拟头 + 每次交换一对）

把链表看成若干对：`(1,2)`、`(3,4)`……  
每一对内部交换，再接到后面。

用 `dummy` 接在头前面：

```text
dummy → 1 → 2 → 3 → 4
```

用指针 `prev` 表示「当前这一对前面的那个节点」。  
一开始 `prev = dummy`，后面的两个就是要交换的 `a`、`b`。

### 交换一对时改哪几条线？

交换前：

```text
prev → a → b → 后面
```

交换后要变成：

```text
prev → b → a → 后面
```

三步：

1. `prev->next = b`（prev 改连 b）  
2. `a->next = b->next`（a 改连原来 b 后面）  
3. `b->next = a`（b 改连 a）

然后 `prev = a`（交换后这一对的末尾是 a），继续处理下一对。

### 走一遍例子

`1→2→3→4`

**第一对：** `prev=dummy`，`a=1`，`b=2`

```text
dummy → 2 → 1 → 3 → 4
prev 移到 1
```

**第二对：** `prev=1`，`a=3`，`b=4`

```text
dummy → 2 → 1 → 4 → 3
```

返回 `dummy.next` → `2→1→4→3`。

### 为什么又用 dummy？

第一对交换后，**新的头**变成原来的第二个节点。  
有了 `dummy`，第一对和后面的对用同一套「改 prev->next」逻辑，不用单独处理头。

## 代码对应

```cpp
ListNode dummy(0, head);
ListNode* prev = &dummy;
while (prev->next && prev->next->next) {
    ListNode* a = prev->next;
    ListNode* b = prev->next->next;
    prev->next = b;
    a->next = b->next;
    b->next = a;
    prev = a;
}
return dummy.next;
```

循环条件：后面至少还有两个节点，才交换。

## 递归写法（了解）

```cpp
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* a = head;
    ListNode* b = head->next;
    a->next = swapPairs(b->next);
    b->next = a;
    return b;
}
```

先处理后面，再交换当前这对。

## 复杂度

- 时间：O(n)
- 空间：O(1)（迭代）；递归 O(n) 栈

## 感想 / 踩坑

- 题目要求交换节点，不能只 `swap(a->val, b->val)`（虽能过，但不符题意）
- 改指针顺序别乱，建议先画图再写三步
- 奇数个节点时最后单个自然留下
- 再次体会 `dummy`：统一处理「新头」和中间节点
