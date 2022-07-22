class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
            int k = 0, j = nums.size() - 1, cnt = 0;
            for (auto x: nums)
                if (x == val) cnt++;
            for (int i = 0; i < nums.size() and j > i;)
            {
                if (nums[i] == val and nums[j] != val)
                {
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                }
                else if (nums[i] == val and nums[j] == val)
                {
                    j--;
                }
                else
                {
                    swap(nums[k],nums[i]);
                    // nums[k++] = nums[i];
                    i++;
                }
            }
            for (auto x: nums)
                cout<<x<<" ";
            return nums.size() - cnt;
        }
};