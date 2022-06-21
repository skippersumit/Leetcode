class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, n = chars.size();
        int index = 0;
        while(i<n){
            int j=i;
            while(j<n and chars[j]==chars[i])
                j++;
            
            chars[index++] = chars[i];
            if(j-i>1){
                string count = to_string( j-i);
                for(char c: count){
                    chars[index++] = c;
                }
            }
            i=j;
        }
        return index;
    }
};