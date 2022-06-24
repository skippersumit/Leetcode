class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k)
        {
            int sum = 0;
            unordered_map<int, int> mp;
            mp[sum] = 1;
            int ans = 0;
            for (int num: nums)
            {
                sum += num;
                ans += mp[sum - k];
                mp[sum]++;
            }
            return ans;
        }
};