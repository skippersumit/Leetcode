class Solution {
public:
    static bool compare(const vector<int>&a, const vector<int>&b){
        return a[1] > b[1];
        }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
            
        for(auto box: boxTypes){
            ans += min(truckSize, box[0]) * box[1];
            truckSize -= min(truckSize, box[0]);
        }
            
        
        return ans;
    }
};