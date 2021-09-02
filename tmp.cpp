#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
    int val;
};

ListNode* reverse(ListNode* head) {
    ListNode* pre_node = nullptr;
    ListNode* cur_node = head;
    while (cur_node) {
        ListNode* tmp = cur_node->next;
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = tmp;
    }
    return pre_node;
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode* ans = reverse(head);
    for (int i = 0; i < 6; i++) {
        cout << ans->val;
        ans = ans->next;
    }
    return 0;
}