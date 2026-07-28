# 49. 字母异位词分组（Group Anagrams）

- 难度：中等
- 标签：哈希表、字符串、排序
- 链接：https://leetcode.cn/problems/group-anagrams/

## 题目

给定字符串数组 `strs`，将**字母异位词**组合在一起。可以按任意顺序返回结果。

字母异位词：字母相同、顺序不同。例如 `"eat"`、`"tea"`、`"ate"`。

## 例子

输入：`["eat","tea","tan","ate","nat","bat"]`  
输出：`[["bat"],["nat","tan"],["ate","eat","tea"]]`（分组内部/分组之间顺序不限）

## 思路（unordered_map）

核心问题：怎么判断两个词是同一组？

办法：把每个词的字母**排序**，异位词会变成同一个 key。

| 原词 | 排序后（key） |
|------|---------------|
| eat  | aet           |
| tea  | aet           |
| ate  | aet           |
| tan  | ant           |
| nat  | ant           |
| bat  | abt           |

用 `unordered_map<string, vector<string>>`：

- **key**：排序后的字符串
- **value**：属于这一组的所有原词

扫一遍 `strs`，每个词算 key，丢进对应分组；最后把 map 里所有 value 收集起来即可。

## 复杂度

设有 n 个字符串，每个平均长度 k：

- 时间：O(n · k log k)（每个词排序）
- 空间：O(n · k)（存所有字符串）

## 感想 / 踩坑

- 和两数之和一样：先想清楚「用什么当 key」
- 两数之和：key = 数字；这题：key = 排序后的词
- `groups[key].push_back(s)`：如果 key 不存在，会自动建一个空 vector 再 push
- 返回顺序任意，不用特意排序结果
