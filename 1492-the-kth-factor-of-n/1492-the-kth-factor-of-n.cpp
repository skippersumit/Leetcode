class Solution {
public:
    
    void calculateFact(int n, vector<int>&fact){
        for(int i=1;i<=n;i++){
            if(n%i == 0){
                fact.emplace_back(i);
            }
        }
    }
    int kthFactor(int n, int k) {
        vector<int>fact;
        
        calculateFact(n, fact);
        
        return (fact.size() >= k) ? fact[k-1] : -1;
    }
};