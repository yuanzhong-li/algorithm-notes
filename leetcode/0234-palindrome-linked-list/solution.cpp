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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // 1. 快慢指针找中点（slow 停在前半段末尾）
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 反转后半段
        ListNode* second = reverseList(slow->next);

        // 3. 前半段和后半段逐个比较
        ListNode* p1 = head;
        ListNode* p2 = second;
        bool ok = true;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                ok = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 可选：恢复链表（题目不要求，写上更稳妥）
        slow->next = reverseList(second);
        return ok;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
