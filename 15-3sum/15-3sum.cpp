class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            vector<vector < int>> v;
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int left, right, sum = 0;
            for (int i = 0; i < n - 2; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                left = i + 1;
                right = n - 1;
                while (left < right)
                {
                    sum = nums[i] + nums[left] + nums[right];
                    if (sum > 0) right--;
                    else if (sum < 0) left++;
                    else
                    {
                        int x = 0, y = 0;
                        v.push_back({ nums[i],
                            nums[left],
                            nums[right] });
                        left++;
                        while (nums[left] == nums[left - 1] && left < right) left++;
                    }
                }
            }
            return v;
        }
};