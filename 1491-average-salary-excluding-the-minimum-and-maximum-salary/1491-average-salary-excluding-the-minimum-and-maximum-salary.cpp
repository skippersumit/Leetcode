class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int n = salary.size();
        
        int mn = INT_MAX, mx = INT_MIN;
        for(auto x: salary){
            sum += x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        
        sum -= (mn*1.00 + mx*1.00);
        
        
        return sum/(n-2);
    }
};