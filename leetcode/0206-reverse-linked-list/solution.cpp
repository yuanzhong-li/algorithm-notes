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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;  // 先记住下一个，否则断链后找不到
            curr->next = prev;            // 反转指针：指向前一个
            prev = curr;                  // prev、curr 都前进一步
            curr = next;
        }
        // prev 停在原链表最后一个节点，即新的头
        return prev;
    }
};
