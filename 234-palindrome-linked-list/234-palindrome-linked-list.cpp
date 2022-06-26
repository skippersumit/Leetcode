/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        bool isPalindrome(ListNode *head)
        {
            string s = "";
            ListNode *curr = head;
            while (curr)
            {
                s += curr->val - '0';
                curr = curr->next;
            }
            string t = s;
            reverse(t.begin(), t.end());
            if (s == t) return 1;
            return 0;
        }
};