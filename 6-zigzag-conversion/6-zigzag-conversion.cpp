#define col 1001
class Solution {
public:
    string convert(string s, int r) {
        if(r == 1) return s;
        int i=0, j=0,k=0;
        vector<vector<char>>dp(r,vector<char>(col,'-'));
        while(k<s.length()){
            
            while(i<r and k<s.length()){
                dp[i][j] = s[k];
                i++;
                k++;
            }
            i=r-2,j++;
            while(i>0 and j>=0 and k<s.length()){
                dp[i][j] = s[k];
                i--;
                j++;
                k++;
            }        }
        
        string ans = "";
        for(int p=0;p<r;p++){
            for(int q=0;q<col;q++){
                if(dp[p][q] != '-')
                    ans += dp[p][q];
            }
            cout<<endl;
        }
        
        return ans;
    }
};