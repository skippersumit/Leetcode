class MedianFinder
{
    public:
        priority_queue<int> maxq;
    priority_queue<int, vector < int>, greater < int>> minq;
    MedianFinder() {}

    void addNum(int num)
    {
        maxq.push(num);
        minq.push(maxq.top());
        maxq.pop();

        if (minq.size() > maxq.size())
        {
            maxq.push(minq.top());
            minq.pop();
        }
    }

    double findMedian()
    {
        if (maxq.size() > minq.size())
        {
            return maxq.top();
        }
        else
        {
            return (minq.top() + maxq.top()) / 2.0;
        }
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */