/**
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *llh = new ListNode(0);
        ListNode *ll = llh;
        ll->next =head;
        int tmp = head->val;
        head = head->next;
        ll = ll->next;
        while (head) {
            if (head->val == tmp) {
                head = head->next;
            } else {
                tmp = head->val;
                ll->next = head;
                ll = ll->next;
                head = head->next;
            }
        }
        ll->next = NULL;
        return llh->next;
    }
};