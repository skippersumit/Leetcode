class Solution {
public:
    int bulbSwitch(int n) {
        long long i = 1;
        int cnt = 0;
        
        while((i*i) <= n){
            i++;
            cnt++;
        }
        return cnt;
    }
};