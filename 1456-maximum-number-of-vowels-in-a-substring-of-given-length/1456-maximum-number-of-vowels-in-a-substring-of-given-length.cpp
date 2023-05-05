class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c =='i'|| c=='o' || c == 'u' ) return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        
        for(int i=0;i<k;i++){
            if(isvowel(s[i])) ans++;
        }
        
        int prevans = ans;
        for(int i=k;i<s.length();i++){
            int cur = prevans;
            
            if(isvowel(s[i])) cur++;
            if(isvowel(s[i-k])) cur--;
            
            prevans = cur;
            ans = max(cur,ans);
        }
        
        return ans;
    }
};