/**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        int flag = 0;
        ListNode *llh = new ListNode(0);
        //ListNode *ll = llh;
        llh->next = l1;
        //ll = ll->next;
        while (l1 && l2) {
            l1->val = l1->val + l2->val + flag;
            flag = l1->val / 10;
            l1->val = l1->val % 10;
            if (l1->next == NULL && l2->next == NULL) {
                if (flag) {
                    ListNode *last = new ListNode(1);
                    l1->next = last;
                }
                return llh->next;
            }
            if (l1->next == NULL && l2->next != NULL) {
                l1->next = l2->next;
                l1 = l1->next; 
                break;
            } 
            l1 = l1->next;
            l2 = l2->next;
            //ll = ll->next; 
        }
        // if (l1 == NULL && l2 == NULL && flag == 1) {
        //     ll = new ListNode(1);
        //     return llh->next;
        // }
        while (l1) {
            l1->val = l1->val + flag;
            flag = l1->val / 10;
            l1->val = l1->val % 10;
            if (l1->next == NULL) {
                if (flag) {
                    ListNode *last = new ListNode(1);
                    l1->next = last;
                }
                return llh->next;
            }
            l1 = l1->next;
            //ll = ll->next;
        }
        return llh->next;
    }
};