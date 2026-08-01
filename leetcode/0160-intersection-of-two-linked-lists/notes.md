# 160. 相交链表（Intersection of Two Linked Lists）

- 难度：简单
- 标签：哈希表、链表、双指针
- 链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/

## 题目

给定两个单链表的头节点 `headA`、`headB`，找出并返回两链表相交的起始节点。  
不相交则返回 `null`。

注意：

- 链表无环
- 函数返回后，链表须保持原结构（不能真的改链）
- 相交指的是**节点地址相同**（同一段后缀），不是节点值相同

## 例子

```text
A:      a1 → a2
               ↘
                c1 → c2 → c3
               ↗
B: b1 → b2 → b3
```

相交起始节点是 `c1`。

## 思路（双指针：互相接对方的链表）

若直接比长度再对齐，也可以，但要先量长度。

更巧妙的写法：

- 指针 `pA` 从 A 头走到尾，然后接到 B 头继续走  
- 指针 `pB` 从 B 头走到尾，然后接到 A 头继续走  

设 A 独有部分长度 `a`，B 独有部分长度 `b`，公共部分长度 `c`：

```text
pA 总路程：a + c + b
pB 总路程：b + c + a
```

一样长，所以会同时走到交点 `c1`。  
若不相交，两人都会走到 `null`，同时相等，返回 `null`。

### 为什么换到对方链表时写 `pA == nullptr` 才跳？

走到最后一个节点时 `pA` 还不是 null，要再 `pA = pA->next` 变成 null，下一轮才接到 `headB`。  
这样「走到 null」也算一步，两不相交时两边都能在 null 相遇。

### 和哈希表做法对比

| 做法 | 思路 | 空间 |
|------|------|------|
| 哈希表 | 先把 A 所有节点放进 set，再扫 B | O(n) |
| **双指针** | 互相走对方链表，对齐路程 | O(1) |

## 代码

```cpp
ListNode* pA = headA, *pB = headB;
while (pA != pB) {
    pA = (pA == nullptr) ? headB : pA->next;
    pB = (pB == nullptr) ? headA : pB->next;
}
return pA;
```

## 复杂度

- 时间：O(m + n)
- 空间：O(1)

## 感想 / 踩坑

- 比的是指针是否相同（`pA == pB`），不是 `val` 是否相同
- 不能破坏原链表结构
- 不相交时靠两边都走到 `null` 退出，别漏了 null 的情况
