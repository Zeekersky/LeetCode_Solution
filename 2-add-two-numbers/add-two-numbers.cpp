/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *result = new ListNode();
        ListNode *temp3 = result;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL)
        {
            if (temp1 != NULL && temp2 != NULL)
            {
                int sum = temp1->val + temp2->val + carry;
                carry = sum / 10;
                temp3->val = sum % 10;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1 != NULL && temp2 == NULL)
            {
                int sum = temp1->val + carry;
                carry = sum / 10;
                temp3->val = sum % 10;
                temp1 = temp1->next;
            }
            else if (temp1 == NULL && temp2 != NULL)
            {
                int sum = temp2->val + carry;
                carry = sum / 10;
                temp3->val = sum % 10;
                temp2 = temp2->next;
            }

            if (temp1 != NULL || temp2 != NULL)
            {
                temp3->next = new ListNode();
                temp3 = temp3->next;
            }
        }
        if (carry != 0)
        {
            temp3->next = new ListNode();
            temp3 = temp3->next;
            temp3->val = carry;
        }
        else
            temp3->next = NULL;
        return result;
    }
};