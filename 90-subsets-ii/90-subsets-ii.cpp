class Solution
{
    public:
        void generateSubsets(vector<int> &nums, int index, vector<int> temp, vector< vector< int>> &ans)
        {
            if (index >= nums.size())
            {
                ans.push_back(temp);
                return;
            }

           	//pick
            temp.push_back(nums[index]);
            generateSubsets(nums, index + 1, temp, ans);
            temp.pop_back();

           	//not pick
            while (index + 1 < nums.size() and nums[index] == nums[index + 1])
                index++;

            generateSubsets(nums, index + 1, temp, ans);
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector < int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        generateSubsets(nums, 0, temp, ans);

        return ans;
    }
};