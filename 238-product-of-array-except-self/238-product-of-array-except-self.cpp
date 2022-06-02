class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixProductLR(n),prefixProductRL(n);
        prefixProductLR[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixProductLR[i] = prefixProductLR[i-1]*nums[i];
        }
        prefixProductRL[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefixProductRL[i] = prefixProductRL[i+1]*nums[i];
        }
        
        vector<int>ans(n);
        for(int i=1;i<n-1;i++){
            ans[i] = prefixProductLR[i-1]*prefixProductRL[i+1];
        }
        ans[0] = prefixProductRL[1];
        ans[n-1] = prefixProductLR[n-2];
        return ans;
    }
};