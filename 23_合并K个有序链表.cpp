/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        ListNode *llh = new ListNode(0);
        llh->next = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            llh->next = mergeTwoLists(llh->next, lists[i]);
        }
        return llh->next;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *llh = new ListNode(0);
        ListNode *ll = llh;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ll->next = l1;
                ll = ll->next;
                l1 = l1->next;
            } else {
                ll->next = l2;
                ll = ll->next;
                l2 = l2->next;
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