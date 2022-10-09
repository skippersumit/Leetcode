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
    void find(TreeNode* root, int k, map<int, int>& m, bool& ans){
        if(root == NULL) return;
        
        find(root->left, k, m, ans);
    
        int diff = k - root->val;
        if(m.find(diff) != m.end()){
           
            ans = true;
        }
        
        m[root->val]++;
        
        find(root->right, k, m, ans);
    }
    
    bool findTarget(TreeNode* root, int k) {
        map<int, int> m;
        bool ans = false;
        
        find(root, k, m, ans);
        
        return ans;
    }
};