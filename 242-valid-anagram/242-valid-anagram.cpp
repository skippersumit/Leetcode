class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>charFreq(256,0);
        if(s.length() != t.length())
            return false;
        for(char c: s){
            charFreq[c-'a']++;
        }
        for(char c: t){
            charFreq[c-'a']--;
        }
        for(int i=0;i<256;i++){
            if(charFreq[i] != 0)
                return false;
        }
        return true;
    }
};