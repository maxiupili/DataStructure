/**
 * Definition for singly-linked list.

 */
#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vl1, vl2;
        ListNode *tmp = l1;
        while (tmp != NULL)
        {
            vl1.push_back(tmp->val);
            tmp = tmp->next;
            /* code */
        }
        tmp = l2;
        while (tmp != NULL)
        {
            vl2.push_back(tmp->val);
            tmp = tmp->next;
            /* code */
        }
        int s1 = vl1.size();
        int s2 = vl2.size();
        ListNode *head = new ListNode(0);
        int sum;
        int flag = 0;
        while (s1 != 0 || s2 != 0) {
            if (s1 == 0) {
                sum = vl2[--s2] + flag;
                flag = sum / 10;
                sum = sum % 10;
            } else if (s2 == 0) {
                sum = vl1[--s1] + flag;
                flag = sum / 10;
                sum = sum % 10;
            } else {
                sum = vl1[--s1] + vl2[--s2] + flag;
                flag = sum / 10;
                sum = sum % 10;
            }
            ListNode *pTmp = new ListNode(sum);
            pTmp->next = head->next;
            head->next = pTmp;
        }
        if (flag != 0) {
            ListNode *pTmp = new ListNode(flag);
            pTmp->next = head->next;
            head->next = pTmp;
        }

        return head->next;
    }
};