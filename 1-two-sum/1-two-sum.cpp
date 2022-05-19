class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++)
            arr[i]=make_pair(nums[i],i);
        sort(arr.begin(),arr.end());
        int l = 0,r = n-1;
        while(l<r)
        {
            int L = arr[l].first;
            int R = arr[r].first;
            if(L + R == target)
            {
                if(arr[l].second<arr[r].second)
                    return vector<int>{arr[l].second,arr[r].second};
                else
                    return vector<int>{arr[r].second,arr[l].second};
            }    
            else if(L+R < target)
                l++;
            else if(L+R > target)
                r--;
        }
        return vector<int>();
    }
};