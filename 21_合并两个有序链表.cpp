/**
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *llh = new ListNode(0);
        ListNode *ll = llh;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ll->next = l1;
                ll = ll->next;
                //while (l1->val < l2->val) {
                    l1 = l1->next;
                    //ll = ll->next;
                //}
            } else {
                ll->next = l2;
                ll = ll->next;
                //while (l2->val <= l1->val) {
                    l2 = l2->next;
                    //ll = ll->next;
                //}
            }
        }
        if (l1 != NULL) {
            ll->next = l1;
        }
        if (l2 != NULL) {
            ll->next = l2;
        }
        return llh->next;
    }
};