/**
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *llh = new ListNode(0);
        llh->next = head;
        ListNode * ll = llh;
        int flag = 0;
        while (ll->next != NULL && ll->next->next != NULL) {
            if (ll->next->val == ll->next->next->val) {
                flag = 1;
                ll->next = ll->next->next;
            } else if (ll->next->val != ll->next->next->val) {
                if (flag == 1) {
                    ll->next = ll->next->next;
                    flag = 0;
                    cout<<flag<<endl;
                } else {
                    ll = ll->next;
                }
            }
        }
        cout<<flag<<endl;
        //cout<<ll->next->val;
        // if (ll == llh && ll->next == NULL) {
        //     return NULL;
        // }
        if (flag == 1) {
            ll->next = NULL;
        }
        //cout<<ll->next->val;
        return llh->next;
    }
};