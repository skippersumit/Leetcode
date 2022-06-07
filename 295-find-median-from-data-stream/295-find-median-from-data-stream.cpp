class MedianFinder
{
    public:
        priority_queue<int> p;
    priority_queue<int, vector < int>, greater < int>> q;
    MedianFinder() {}

    void addNum(int num)
    {
        p.push(num);
        q.push(p.top());
        p.pop();

        if (q.size() > p.size())
        {
            p.push(q.top());
            q.pop();
        }
    }

    double findMedian()
    {
        if (p.size() > q.size())
        {
            return p.top();
        }
        else
        {
            return (q.top() + p.top()) / 2.0;
        }
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */