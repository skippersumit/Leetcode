class Solution
{
    public:
    bool isClosing(char ch)
    {
        if (ch == ')' || ch == '}' || ch == ']')
            return true;
        return false;
    }
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (isClosing(ch))
            {
                if (st.size() == 0)
                    return false;
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(')
                {
                    cout << 1 << endl;
                    return false;
                }
                else if (ch == '}' && top != '{')
                {
                    cout << 2 << endl;
                    return false;
                }
                else if (ch == ']' && top != '[')
                {
                    cout << 3 << endl;
                    return false;
                }
            }
            else
            {
                st.push(ch);
            }
        }
        return st.size() == 0 ? true : false;
    }
};