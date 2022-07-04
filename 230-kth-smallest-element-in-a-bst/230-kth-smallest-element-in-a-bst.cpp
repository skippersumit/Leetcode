/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(TreeNode *root, int k, int &counter, int &ans)
        {
            if (root == NULL) return;
            solve(root->left, k, counter, ans);

            if (k == counter)
            {
                ans = root->val;
                counter++;
                return;
            }
            else
                counter++;
            solve(root->right, k, counter, ans);
        }

    int kthSmallest(TreeNode *root, int k)
    {
        int counter = 1;
        int ans = -1;
        solve(root, k, counter, ans);
        return ans;
    }
};