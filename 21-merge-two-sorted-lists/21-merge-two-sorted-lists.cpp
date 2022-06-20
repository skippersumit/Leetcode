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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode *head = dummy;
        while(l1 != NULL and l2 != NULL){
            if(l1->val < l2->val){
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        
        if(l1 != NULL){
            dummy->next = l1;
        } else {
            dummy->next = l2; 
        }
        
        return head->next;
    }
};