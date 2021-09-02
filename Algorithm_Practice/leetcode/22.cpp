/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast_pointer = head;
        ListNode* slow_pointer = head;
        for (int i = 0; i < k; i++) fast_pointer = fast_pointer->next;
        while (fast_pointer) {
            fast_pointer = fast_pointer->next;
            slow_pointer = slow_pointer->next;
        }
        return slow_pointer;
    }
};