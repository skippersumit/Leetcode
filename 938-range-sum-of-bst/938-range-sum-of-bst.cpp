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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if(root == NULL) return sum;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            
            if(cur->val >= low and cur->val <= high){
                sum += cur->val;
            }
            
            if(cur->left != NULL and cur->val > low)
                q.push(cur->left);
            
            if(cur->right != NULL and cur->val < high)
                q.push(cur->right);
        }
        
        return sum;
    }
};