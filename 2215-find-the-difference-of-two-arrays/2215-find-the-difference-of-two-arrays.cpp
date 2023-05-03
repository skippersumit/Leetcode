class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1,s2;
        
        unordered_set<int>p,q;
        vector<vector<int>>ans;
        for(auto x: nums2){
            s2.insert(x);
        }
        for(auto x: nums1){
            s1.insert(x);
        }
        
        vector<int>arr1, arr2;
        for(auto x: nums1){
            if(s2.find(x) == s2.end()){
                p.insert(x);
            }
                
        }
        for(auto x: nums2){
            if(s1.find(x) == s1.end())
                q.insert(x);
        }
        
        for(auto it=p.begin();it!=p.end();it++){
            arr1.push_back(*it);
        }
        for(auto it=q.begin();it!=q.end();it++){
            arr2.push_back(*it);
        }
        
        ans.push_back(arr1);
        ans.push_back(arr2);

        
        return ans;
    }
};