/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> temp;
    int a = 0;
    map<int, int> m;
    void traverse(TreeNode *root)
    {
        if (root == NULL)
        {

            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            temp.push_back(root->val);
            m[root->val]++;

            int odd = 0;
            for (int i = 0; i < 10; i++)
            {
                if (m[i])
                {
                    if (m[i] % 2 == 1) odd++;
                }
            }
            if (odd <= 1) a++;
            m[root->val]--;
            temp.pop_back();
            return;
        }

        temp.push_back(root->val);
        m[root->val]++;

        traverse(root->left);

        traverse(root->right);
        temp.pop_back();
        m[root->val]--;

        return;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        traverse(root);

        return a;
    }
};