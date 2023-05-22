typedef pair<int,int> p;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>m;
        priority_queue<p,vector<p>,greater<p>>q;
        for(auto it:nums) {
            m[it]++;
        }
        for(auto it:m) {
            q.push({it.second,it.first});
            if(q.size()>k) {
                q.pop();
            }
        }
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};