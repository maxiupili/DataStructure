/**
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

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
		// 超出内存限制
        // vector<int> ll, rr;
        // int count = 0;
        // while (head != NULL) {
        //     if (head->val < x) {
        //         ll.push_back(head->val);
        //     } else if (head->val == x) {
        //         ++count;
        //     } else {
        //         rr.push_back(head->val);
        //     }
        // }
        // ListNode *llh = new ListNode(0);
        // ListNode *tmp = llh;
        // for (int i : ll) {
        //     tmp->next = new ListNode(i);
        //     tmp = tmp->next;
        // }
        // while (count--) {
        //     tmp->next = new ListNode(x);
        //     tmp = tmp->next;
        // }
        // for (int i : rr) {
        //     tmp->next = new ListNode(i);
        //     tmp = tmp->next;
        // }
        // return llh->next;
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