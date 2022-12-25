class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i], nums[i] = sum;
        for (int i = 0; i < queries.size(); i++)
            queries[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        return queries;
    }
};