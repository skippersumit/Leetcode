class Solution
{
    public:
        int minOperations(vector<int> &nums, int x)
        {
            int n = nums.size();
            vector<int> prefix_sum(n);
            unordered_map<int, int> records;	// the hashmap save prefix_sum to index

            prefix_sum[0] = nums[0];
            records.insert({ prefix_sum[0], 0 });
            for (int i = 1; i < n; i++)
            {
                prefix_sum[i] = prefix_sum[i - 1] + nums[i];
                records.insert({ prefix_sum[i], i });
            }
            int target = prefix_sum.back() - x;
            if (target < 0)
            {
                return -1;
            }
            int minimum_step = INT_MAX;
           	// we need to find a region where the region sum is target
            for (int back_index = n - 1; back_index >= 0; back_index--)
            {

                int expect = prefix_sum[back_index] - target;

                if (expect == 0)
                {
                    int step = n - back_index - 1;
                    minimum_step = min(minimum_step, step);
                }
                else
                {
                    if (records.count(expect) == 1)
                    {
                       	// yes, we can find the expect, then let's see how many steps it costs:
                        int step = n - back_index - 1 + records[expect] + 1;
                        minimum_step = min(minimum_step, step);
                    }
                }
            }
            if (minimum_step == INT_MAX)
            {
                return -1;
            }
            return minimum_step;
        }
};