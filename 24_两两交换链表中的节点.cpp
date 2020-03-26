/**
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *llh = new ListNode(0);
        llh->next = head;
        ListNode *lh = llh;
        ListNode *lhn = lh->next;
        while (lh != NULL && lhn != NULL && lhn->next != NULL) {
            lh->next = lhn->next;
            lhn->next = lh->next->next;
            lh->next->next = lhn;
            lh = lhn;
            lhn = lhn->next;
        }
        return llh->next;
    }
};