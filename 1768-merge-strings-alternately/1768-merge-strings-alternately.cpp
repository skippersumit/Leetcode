class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        
        int n = word1.size(), m = word2.size();
        for(int i=0,j=0;i<n || j<m;i++,j++){
            if(i<n){
                ans += word1[i];
            }
            if(j<m){
                ans += word2[j];
            }
        }
        
        return ans;
    }
};