# 19. 删除链表的倒数第 N 个结点（Remove Nth Node From End of List）

- 难度：中等
- 标签：链表、双指针
- 链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

## 题目

给定链表，删除倒数第 `n` 个节点，返回链表的头节点。

## 例子

输入：`head = [1,2,3,4,5]`，`n = 2`  
删除倒数第 2 个（节点 4）→ `[1,2,3,5]`

输入：`head = [1]`，`n = 1` → `[]`

## 思路（快慢指针 + 虚拟头）

要删「倒数第 n 个」，其实要找到它的**前一个节点**，改 `prev->next`。

用两个指针拉开距离：

1. `fast` 先从虚拟头走 `n + 1` 步  
2. 然后 `fast`、`slow` 一起走，直到 `fast` 走到 `null`  
3. 此时 `slow->next` 正好是倒数第 n 个节点  
4. `slow->next = slow->next->next` 删掉它

### 为什么是先走 n+1 步？

因为我们要让 `slow` 停在「待删节点的前一个」，中间隔着待删节点，所以 `fast` 比 `slow` 多出 `n+1` 个节点的距离（含从 dummy 起算）。

```text
dummy → 1 → 2 → 3 → 4 → 5 → null
         ↑               ↑
       slow            倒数第2个(4)
fast 先拉开后，两人同步走，fast 到 null 时 slow 在 3
```

### 为什么要用虚拟头？`dummy` 是什么？

`dummy` 不是语言关键字，是链表题常用技巧：**自己新建的假头节点**（哨兵），放在真链表前面：

```text
dummy → 1 → 2 → 3 → 4 → 5
```

- 本身一般不表示答案数据  
- 最后返回 `dummy.next` 才是真正的头  

作用：让「删头 / 删中间」用同一套改 `next` 的逻辑，不用特判头节点。  
若删的是头（`n` 等于链表长度），`slow` 停在 `dummy` 上，`dummy.next` 直接跳过原头即可。

你在 21 合并链表、2 两数相加里其实也用过同样套路。

### 走一遍例子

`1→2→3→4→5`，`n=2`

1. `fast` 从 dummy 先走 3 步，到节点 `3`  
2. 一起走：最终 `fast=null`，`slow` 在 `3`  
3. 删掉 `slow->next`（节点 4）→ `1→2→3→5`

## 代码对应

```cpp
ListNode dummy(0, head);
ListNode* fast = &dummy;
ListNode* slow = &dummy;
for (int i = 0; i <= n; ++i) fast = fast->next;
while (fast) {
    fast = fast->next;
    slow = slow->next;
}
slow->next = slow->next->next;
return dummy.next;
```

## 复杂度

- 时间：O(L)，L 为链表长度，只扫一遍
- 空间：O(1)

## 感想 / 踩坑

- 先走 `n+1` 不是 `n`，为了停在待删节点的前驱
- 删除头节点靠 dummy，别忘了返回 `dummy.next`
- 也可以先量长度再删第 `L-n+1` 个，但要两遍扫描
