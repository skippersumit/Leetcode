class Solution
{
    public:

        int longestValidParentheses(string str)
        {
            stack<int> st;
            int ans = 0;
            st.push(-1);

            for (int i = 0; i < str.size(); i++)
            {
                int t = st.top();

                if (t != -1 && str[i] == ')' && str[t] == '(')
                {
                    st.pop();
                    ans = max(ans, i - st.top());
                }
                else
                    st.push(i);
            }
            return ans;
        }
};