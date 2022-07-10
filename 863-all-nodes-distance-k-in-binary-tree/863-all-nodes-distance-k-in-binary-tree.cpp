/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        vector<int> bfs(int u, map<int, vector < int>> &g, int n, int k)
        {
            queue<int> q;
            q.push(u);
            vector<bool> vis(n, false);
            vis[u] = true;
            int cnt = 0;
            while (!q.empty())
            {
                cnt++;
                int x = q.size();
                if (cnt == k + 1)
                {
                    break;
                }
                while (x--)
                {
                    int u = q.front();
                    q.pop();
                    for (auto v: g[u])
                    {
                        if (!vis[v])
                        {
                            q.push(v);
                            vis[v] = true;
                        }
                    }
                }
            }
            vector<int> tp;
            while (!q.empty())
            {
                tp.push_back(q.front());
                q.pop();
            }
            return tp;
        }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        queue<TreeNode*> q;
        map<int, vector < int>> g;
        q.push(root);
        int cnt = 0;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            cnt++;
            if (u->left)
            {
                g[u->val].push_back(u->left->val);
                g[u->left->val].push_back(u->val);
                q.push(u->left);
            }
            if (u->right)
            {
                g[u->val].push_back(u->right->val);
                g[u->right->val].push_back(u->val);
                q.push(u->right);
            }
        }
        return bfs(target->val, g, cnt, k);
    }
};