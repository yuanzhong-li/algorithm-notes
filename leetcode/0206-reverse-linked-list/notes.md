# 206. 反转链表（Reverse Linked List）

- 难度：简单
- 标签：递归、链表
- 链接：https://leetcode.cn/problems/reverse-linked-list/

## 题目

给你单链表的头节点 `head`，请反转链表，并返回反转后的链表头节点。

## 例子

输入：`1 -> 2 -> 3 -> 4 -> 5`  
输出：`5 -> 4 -> 3 -> 2 -> 1`

## 思路（迭代：三个指针）

链表反转 = 把每个节点的 `next` 指向**前一个节点**，而不是后一个。

需要三个指针：

| 指针 | 含义 |
|------|------|
| `prev` | 前一个节点（反转后，当前节点要指向它） |
| `curr` | 当前正在处理的节点 |
| `next` | 临时保存原来的下一个，防止断链后丢了后面 |

每一步：

1. `next = curr->next`（先存起来）
2. `curr->next = prev`（掉头）
3. `prev = curr`，`curr = next`（两人往右挪）

循环结束时 `curr` 为空，`prev` 就是新的头（原链表最后一个节点）。

### 走一遍例子

`1 -> 2 -> 3 -> null`

| 步骤 | prev | curr | 操作后链表关系（示意） |
|------|------|------|------------------------|
| 开始 | null | 1 | 1→2→3 |
| 1 | 1 | 2 | null←1  2→3 |
| 2 | 2 | 3 | null←1←2  3 |
| 3 | 3 | null | null←1←2←3 |

返回 `prev`（节点 3），即 `3 -> 2 -> 1`。

### 图示一步

处理节点 2 时：

```text
之前：  null ← 1     2 → 3
              prev  curr

之后：  null ← 1 ← 2     3
                   prev  curr
```

## 递归写法（了解即可）

```cpp
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

先反转后面，再把「下一个」指回自己。面试更常写迭代版。

## 复杂度

- 时间：O(n)
- 空间：O(1)（迭代）；递归是 O(n) 栈空间

## 感想 / 踩坑

- **一定要先保存 `next`**，再改 `curr->next`，否则后面的链就丢了
- 空链表 / 只有一个节点：循环不进或只走一步，直接返回即可
- 返回的是 `prev`，不是原来的 `head`
