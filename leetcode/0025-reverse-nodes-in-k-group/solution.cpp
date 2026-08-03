/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;  // 上一组翻转后的尾，一开始是 dummy

        while (true) {
            // 1. 看从 prev 后面开始，够不够 k 个节点
            ListNode* kth = prev;
            for (int i = 0; i < k && kth != nullptr; ++i) {
                kth = kth->next;
            }
            if (kth == nullptr) break;  // 不够 k 个，剩下保持原样

            ListNode* groupNext = kth->next;  // 下一组的开头
            ListNode* groupHead = prev->next; // 当前组原来的头（翻转后会变尾）

            // 2. 翻转当前这一组：区间 [groupHead, kth]
            ListNode* p = groupHead;
            ListNode* q = groupHead->next;
            while (p != kth) {
                ListNode* next = q->next;
                q->next = p;
                p = q;
                q = next;
            }
            // 翻转后：kth 成了组头，groupHead 成了组尾

            // 3. 把这一组接到前后
            prev->next = kth;
            groupHead->next = groupNext;

            // 4. prev 移到本组尾，准备下一组
            prev = groupHead;
        }
        return dummy.next;
    }
};
