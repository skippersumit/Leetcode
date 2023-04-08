class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        int val = log2(n);
        return pow(2,val) == n;
    }
};