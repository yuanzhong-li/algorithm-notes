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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 虚拟头：方便删除真正的头节点（例如只剩一个节点）
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // fast 先走 n+1 步，这样 slow 最终停在「待删节点」的前一个
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // 一起走到 fast 为 null，此时 slow->next 就是倒数第 n 个
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 删掉 slow->next
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;  // LeetCode 可不写；本地习惯可释放

        return dummy.next;
    }
};
