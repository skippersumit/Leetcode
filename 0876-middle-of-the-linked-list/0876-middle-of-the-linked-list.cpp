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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL)
            return head;
        ListNode *temp=head;
        int sum=0;
        while(temp!=0){
            sum++;
            temp=temp->next;
        }
        int f=0;temp=head;
        while(temp!=0){
            f++;
            temp=temp->next;
            if(f==sum/2)
                break;
        }
        head=temp;
        return head;
    }
};