class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        int ans = 0;
        int prevSum = satisfaction[n-1];
        int eleSum = satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            eleSum += satisfaction[i];
            prevSum = prevSum + eleSum;
            ans = max(ans,prevSum);
        }
        return ans;
    }
};