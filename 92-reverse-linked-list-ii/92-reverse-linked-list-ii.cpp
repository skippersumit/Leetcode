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
    ListNode* reverse(ListNode* head, int n){
        if(!head) return NULL;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while(n--){
            ListNode* tmp = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = tmp;
        }
        head->next = nxt;
        return cur;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        if(left == 1) return reverse(head, right-left );
        
        ListNode* cur = head;
        int i=1;
        
        while(++i < left){
            cur = cur->next;
        }
        
        cur->next = reverse(cur->next,right-left);
        
        return head;
    }
};