/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     const int MOD = 1e9 + 7;
    int total(TreeNode *root){
        if (!root) return 0;
        root -> val += total(root -> left) + total(root -> right);
        return root -> val;
    }
    void FindMax(TreeNode *root, int count, long long int &maxi){
        if (!root) return;
        long long int temp;
        temp = (long long int)root -> val * (long long int)(count - root -> val);
        maxi = max(maxi, temp);
        FindMax(root -> left, count, maxi);
        FindMax(root -> right, count, maxi);
    }
    int maxProduct(TreeNode* root) {
        long long int maxi = 0;
        FindMax(root, total(root), maxi);
        return int(maxi % MOD);
    }
};