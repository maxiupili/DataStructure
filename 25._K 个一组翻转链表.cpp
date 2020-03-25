/**
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        //cout<< head->val;
        ListNode *pLF, *pMV;
        ListNode *head2 = new ListNode(0); //新的空头部用来指向第一个元素
        head2->next = ((head != NULL)? head : NULL);
        int flag = 0;
        pLF = head2;
        pMV = head2;

        while (pMV->next != NULL) {
            for (int i = 0; i < k; i++) {
                if (pMV->next != NULL) {
                    pMV = pMV->next;
                } else {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 1) {
                break;
            }
            //head = reversePartOfKGroup(head, pLF, pMV);

            ListNode *pfffff;
            ListNode *pf = ((pLF->next != NULL) ? pLF->next: NULL);
            pLF->next = pMV;
            ListNode *pfn = ((pf->next != NULL) ? pf->next: NULL);
            pf->next = ((pMV->next != NULL) ? pMV->next: NULL); // end
            pfffff = pf;
            ListNode *ptmp;
            while (pfn != pMV) {
                if (pfn->next != NULL) {
                    ptmp = pfn->next;
                    pfn->next = pf;
                    pf = pfn;
                    pfn = ptmp;
                }
            }
            pMV->next = pf;
            pLF = pfffff;
            pMV = pfffff;

            
            


        }
        return head2->next;
    }

    // ListNode *reversePartOfKGroup(ListNode *head, ListNode *pLF, ListNode *pLE) {
    //     ListNode *pf = ((pLF->next != NULL) ? pLF->next: NULL);
    //     pLF->next = pLE;
    //     ListNode *pfn = ((pf->next != NULL) ? pf->next: NULL);
    //     pf->next = ((pLE->next != NULL) ? pLE->next: NULL);
    //     ListNode *ptmp;
    //     while (pfn != pLE) {
    //         if (pfn->next != NULL) {
    //             ptmp = pfn->next;
    //             pfn->next = pf;
    //             pf = pfn;
    //             pfn = ptmp;
    //         }
    //     }
    //     pLE->next = pf;
    //     return head;
    // }
};