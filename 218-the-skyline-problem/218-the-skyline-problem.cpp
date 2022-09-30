class Solution
{
    public:
        vector<vector < int>> getSkyline(vector<vector < int>> &b)
        {
            int i = 0, x = b[0][0];	// x- Sweep Line starting from first rectangle
            vector<vector < int>> res;
            priority_queue<vector < int>> pq;
            res.push_back({ -1,
                -1 });
            while (i < b.size() || !pq.empty())
            {
               	// Push all the rectangle starting at current Sweep Line Position
                while (i < b.size() && b[i][0] == x) pq.push({ b[i][2],
                    b[i][0],
                    b[i][1] }), i++;
               	// Remove all rectangles which are behind the sweep line
                while (!pq.empty() && pq.top()[2] <= x) pq.pop();

                if (!pq.empty() && (res.back()[1] != pq.top()[0])) res.push_back({ x,
                    pq.top()[0] });	// Skyline Changed
                else if (pq.empty() && i > 0 && res.back()[1] != 0) res.push_back({ x,
                    0 });	// Skyline Height became 0
               	// Now update sweep line value
                if (i < b.size() && !pq.empty()) x = min(b[i][0], pq.top()[2]);
                else if (!pq.empty()) x = pq.top()[2];
                else if (i < b.size()) x = b[i][0];
            }
            res.erase(res.begin());
            return res;
        }
};