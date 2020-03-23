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
        ListNode *head2 = new ListNode(0);
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