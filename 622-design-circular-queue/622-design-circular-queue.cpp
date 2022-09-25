class Node
{
    public:
        int val;
    Node * next;
    Node()
    {
        val = -1;
        next = nullptr;
    }
    Node(int _val)
    {
        val = _val;
        next = nullptr;
    }
};
class MyCircularQueue
{
    int size;
    int current;
    Node * head;
    Node * tail;
    public:
        MyCircularQueue(int k)
        {
            size = k;
            current = 0;
            head = nullptr;
            tail = nullptr;
        }

    bool enQueue(int value)
    {
        if (current >= size) return false;
        if (current == 0)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            cout << current << endl;
            tail->next = new Node(value);
            tail = tail->next;
        }
        current++;
        return true;
    }

    bool deQueue()
    {
        if (current == 0) return false;
        if (current == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        current--;
        return true;
    }

    int Front()
    {
        if (current == 0) return -1;
        return head->val;
    }

    int Rear()
    {
        if (current == 0) return -1;
        return tail->val;
    }

    bool isEmpty()
    {
        return current == 0;
    }

    bool isFull()
    {
        return current == size;
    }
};

/**
 *Your MyCircularQueue object will be instantiated and called as such:
 *MyCircularQueue* obj = new MyCircularQueue(k);
 *bool param_1 = obj->enQueue(value);
 *bool param_2 = obj->deQueue();
 *int param_3 = obj->Front();
 *int param_4 = obj->Rear();
 *bool param_5 = obj->isEmpty();
 *bool param_6 = obj->isFull();
 */