class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>map;
        for (auto x : nums)
            map[x]++;

        int c = 0, mc = 0;

        for (auto x : nums) {
            if (map[x - 1] > 0)continue;
            int i = x;
            while (map[i] != 0) {++c; ++i;}                                                 
			mc = c > mc ? c : mc;
            c = 0;
        }
        return mc;
    }
};