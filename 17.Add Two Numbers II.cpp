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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        
        int carry = 0;
        
        while(r1 != NULL || r2 != NULL){
            int x = (r1 != NULL) ? r1->val : 0;
            int y = (r2 != NULL) ? r2->val : 0;
            int sum = x + y + carry;
            head->next = new ListNode(sum%10);
            carry = sum/10;
            head = head->next;
            if(r1 != NULL) r1 = r1->next;
            if(r2 != NULL) r2 = r2->next;
        }
        if(carry == 1)
            head->next = new ListNode(carry);
        
        ListNode* result = reverse(dummy->next);
        return result;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* next;
        ListNode* prev = NULL;
        
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};
