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
    int carry = 1;
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        plusOneHelper(head);
        if(carry == 1){
            dummy->val = 1;
            return dummy;
        }
        return head;
    }
    
    void plusOneHelper(ListNode* head){
        if(head == NULL)
            return;
        plusOneHelper(head->next);
        int val = head->val + carry;
        carry = val / 10;
        head->val = val % 10;
        if(carry == 0)
            return;
    }
};
