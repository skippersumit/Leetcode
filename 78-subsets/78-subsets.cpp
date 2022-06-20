class Solution {
public:
    void generateSubsets(vector<int>& nums, int id,vector<int>temp,vector<vector<int>> &ans){
        if(id == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        //pick
        temp.push_back(nums[id]);
        generateSubsets(nums,id+1,temp,ans);
        
        //not pick
        temp.pop_back();
        generateSubsets(nums,id+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        generateSubsets(nums,0,temp,ans);
        
        return ans;
    }
};