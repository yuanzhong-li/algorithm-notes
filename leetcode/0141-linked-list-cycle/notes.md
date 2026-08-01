# 141. 环形链表（Linked List Cycle）

- 难度：简单
- 标签：哈希表、链表、双指针
- 链接：https://leetcode.cn/problems/linked-list-cycle/

## 题目

给定链表头节点 `head`，判断链表中是否有环。

有环：某个节点可通过不断沿 `next` 再次到达。  
`pos` 表示尾部连回的节点下标（题解函数里拿不到 `pos`，只是图示用）。

## 例子

输入：`head = [3,2,0,-4]`，`pos = 1`  
`3 -> 2 -> 0 -> -4` 又指回 `2` → 有环，返回 `true`。

## 思路（快慢指针 / Floyd）

想象两个人在跑道上：

- `slow` 一次走 1 步  
- `fast` 一次走 2 步  

**有环**：快的人迟早会从后面追上慢的人 → `slow == fast`  
**无环**：快的人会走到 `nullptr`（链尾）

这就是 Floyd 判圈算法。

### 走一遍（有环）

```text
3 → 2 → 0 → -4
    ↑_________|
```

两人从 head 出发，每轮各走；若干步后会在环上某点相遇。

### 另一种：哈希表

```cpp
unordered_set<ListNode*> seen;
while (head) {
    if (seen.count(head)) return true;
    seen.insert(head);
    head = head->next;
}
return false;
```

见过的节点再出现 → 有环。好懂，但额外空间 O(n)。

| 做法 | 时间 | 空间 |
|------|------|------|
| **快慢指针** | O(n) | O(1) |
| 哈希表 | O(n) | O(n) |

## 代码对应

```cpp
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
}
```

- 先判断 `fast` 和 `fast->next`，防止空指针  
- 比的是**节点指针是否相同**，不是 `val`

## 复杂度（快慢指针）

- 时间：O(n)
- 空间：O(1)

## 感想 / 踩坑

- 和 234 回文链表一样用到快慢指针，但用途不同：那边找中点，这边判环
- 空链表、单节点无环
- `fast` 要一次走两步，循环条件必须保证 `fast->next` 存在
