class Solution {
public:
    
    bool isPalindrome(string s) {
        for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while (i < j && !std::isalnum(s[i]))
                ++i;
            while (i < j && !std::isalnum(s[j]))
                --j;
            if (i == j)
                break;
            if (std::tolower(s[i]) != std::tolower(s[j]))
                return false;
        }
        return true;
    }
};