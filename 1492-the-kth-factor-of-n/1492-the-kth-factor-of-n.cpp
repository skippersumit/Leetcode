class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> half1,half2;
        
        int srqt = sqrt(n);
        
        for(int i=1;i<=srqt;i++){
            if(n%i == 0){
                half1.emplace_back(i);
                if( i != n/i){
                    half2.emplace_back(n/i);
                }
            }
        }
        
        if(half1.size() + half2.size() < k) return -1;
        
        if(half1.size() < k){
            return half2[half2.size() - k + half1.size()];
        }
        return half1[k-1];
    }
};