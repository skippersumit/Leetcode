class Solution
{
    struct comp
    {
        bool operator()(pair<char, int> &a, pair<char, int> &b)
        {
            return a.second < b.second;
        }
    };
    public:
        string reorganizeString(string s)
        {
            unordered_map<char, int> freq;

            for (auto &ch: s)
            {
                freq[ch]++;
            }

            priority_queue<pair<char, int>, vector< pair<char, int>>, comp> pq;

            for (auto &iter: freq)
            {
                pq.push({ iter.first,
                    iter.second });
            }

            string ans;

            while (pq.size() > 1)
            {
               	// take alternate characters

                auto top1 = pq.top();
                pq.pop();
                auto top2 = pq.top();
                pq.pop();

                ans += top1.first;
                ans += top2.first;

                top1.second--;
                top2.second--;

                if (top1.second > 0)
                {
                    pq.push(top1);
                }
                if (top2.second > 0)
                {
                    pq.push(top2);
                }
            }

            if (!pq.empty())
            {
                if (pq.top().second > 1)
                {
                    return "";
                }
                ans += pq.top().first;
            }

            return ans;
        }
};