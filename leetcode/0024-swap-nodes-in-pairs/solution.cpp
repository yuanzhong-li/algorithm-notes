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
    ListNode* swapPairs(ListNode* head) {
        // dummy 接在真头前面，方便统一处理「第一对」的交换
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // 每次交换 prev 后面的两个节点：a 和 b
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* a = prev->next;       // 第一节点
            ListNode* b = prev->next->next; // 第二节点

            // 交换：prev → b → a → (原来 b 后面)
            prev->next = b;
            a->next = b->next;
            b->next = a;

            // 下一对：prev 移到 a（交换后这一对的末尾）
            prev = a;
        }
        return dummy.next;
    }
};
