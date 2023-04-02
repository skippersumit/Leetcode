class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long c) {
        sort(p.begin(),p.end());
        vector<int>an;
        for(int i=0;i<s.size();i++){
            int d=0;
            long long g=c/s[i];
            if(c%s[i])g++;
            int f=lower_bound(p.begin(),p.end(),g)-p.begin();
            d += p.size()-f;
            an.push_back(d);
        }
        return an;
    }
};