class Solution
{
    public:
        int minRefuelStops(int target, int startFuel, vector<vector < int>> &stations)
        {
            int n = stations.size();
            int i = 0;
            int ans = 0;
            int curr_fuel = startFuel;
            priority_queue<int> pq;

            for (ans = 0; curr_fuel < target; ans++)
            {
                while (i < n && stations[i][0] <= curr_fuel)
                {
                    pq.push(stations[i++][1]);
                }

                if (pq.empty())
                {
                    return -1;
                }

                curr_fuel += pq.top();
                pq.pop();
            }
            return ans;
        }
};