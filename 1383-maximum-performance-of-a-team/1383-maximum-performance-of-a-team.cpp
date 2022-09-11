class Solution
{
    public:
        int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
        {
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < speed.size(); i++)
                pq.push({ efficiency[i], i });
            multiset<int> s;
            long long sum = 0, ans = 0;
            while (!pq.empty())
            {
                sum += speed[pq.top().second];
                s.insert(speed[pq.top().second]);
                if (s.size() > k)
                {
                    sum -= *s.begin();
                    s.erase(s.begin());
                }
                ans = max(ans, sum *pq.top().first);
                pq.pop();
            }
            int mod = 1e9 + 7;
            return ans % mod;
        }
};