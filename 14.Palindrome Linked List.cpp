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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = head;
        ListNode* sec = reverse(slow);
        
        while(sec != NULL && fast != NULL){
            if(sec->val != fast->val)
                return false;
            sec = sec ->next;
            fast = fast->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* next;

        while(curr != NULL){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};
