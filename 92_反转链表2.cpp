/**
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL || m == n) {
            return head;
        }
        ListNode *llh = new ListNode(0);
        ListNode *llh1 = new ListNode(0);
        llh1->next = head;
        //llh->next = head;
        ListNode *ll = llh1;
        int x = n - m;
        while (--m) {
            ll = ll->next;
        }
        //cout<<ll->val<<endl;
        ListNode *le = ll->next;
        //ListNode *ll1 = ll;
        
        //cout<<x<<endl;
        while (x--) {
            le = le->next;
        }
        //cout<<le->val;
        llh->next = ((le->next != NULL) ? le->next : NULL);
        ListNode *tmp = ll->next;
        ll->next = le;
        ll = tmp;
        while (ll != le) {
            tmp = ll;
            ll = ll->next;
            tmp->next = llh->next;
            llh->next = tmp;
        }
        le->next = llh->next;
        return llh1->next;
    }
};