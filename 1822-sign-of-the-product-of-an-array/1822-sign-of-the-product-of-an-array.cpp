class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool iszero = false;
        int pos = 0, neg = 0;
        
        for(auto x: nums){
            if(x==0) iszero = true;
            else if(x < 0) neg += 1;
            else pos += 1;
        }
        
        if(iszero) return 0;
        
        return (neg%2 == 0)? 1 : -1;
    }
};