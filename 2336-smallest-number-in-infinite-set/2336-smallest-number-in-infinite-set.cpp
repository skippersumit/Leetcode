class SmallestInfiniteSet
{
    public:
        set<int> pq;
    SmallestInfiniteSet()
    {
        for (int i = 1; i < 1001; i++) pq.insert(i);
    }

    int popSmallest()
    {
        int x = *pq.begin();
        pq.erase(x);
        return x;
    }

    void addBack(int num)
    {
        pq.insert(num);
    }
};

/**
 *Your SmallestInfiniteSet object will be instantiated and called as such:
 *SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 *int param_1 = obj->popSmallest();
 *obj->addBack(num);
 */