/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
            unordered_map<Node*, Node*> mp;  // to store mapping of every nodes in two LLs
            Node *curr = head;

            Node *nHead = new Node(-1);   // new head of new LL
            Node *prev = nHead;

           	//creates a new Linklist with nHead->next as head
            while (curr != NULL)
            {
                Node *newNode = new Node(curr->val);

                prev->next = newNode;
                mp[curr] = newNode;

                prev = prev->next;
                curr = curr->next;
            }

            nHead = nHead->next;
            Node *c1 = head;
            Node *c2 = nHead;

            while (c1 != NULL)
            {
                c2->random = (c1->random != NULL ? mp[c1->random] : NULL);

                c1 = c1->next;
                c2 = c2->next;
            }

            return nHead;
        }
};