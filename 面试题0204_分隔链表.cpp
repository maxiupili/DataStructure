/**
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

示例:

输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8

题目意思同86题相同
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *lf = new ListNode(0);
        ListNode *llf = lf;
        //分左右两部分
        ListNode *lr = new ListNode(0);
        ListNode *llr = lr;
        
        while (head != NULL) {
            if (head->val < x) {
                llf->next = head;
                llf = llf->next;
            } else {
                llr-> next = head;
                llr = llr->next;
            }
            head = head->next;
        }
        llr->next = NULL;
        if (lr->next != NULL) {
            llf->next = lr->next;
        }
        
        return lf->next;
    }
};