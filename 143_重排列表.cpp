/**
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        //ListNode llh = new ListNode(0);
        //llh->next = head;
        ListNode *ll = head;
        vector<ListNode *> vc;
        while (ll != nullptr) {
            vc.push_back(ll);
            ll = ll->next;
        }
        int i, j;
        for (i = 0, j = vc.size() - 1; i < j; ++i, --j) {
            vc[i]->next = vc[j];
            vc[j]->next = vc[i + 1];
        }
        vc[i]->next = nullptr;
    }
};