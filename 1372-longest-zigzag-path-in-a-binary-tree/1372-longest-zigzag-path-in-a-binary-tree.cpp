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
    int res = 0;
    void fun(TreeNode* root, bool left, int pathLen){
        if(!root) return;
        res = max(res, pathLen);
        
        if(left){
            fun(root->left,false,pathLen+1);
            fun(root->right,true,1);
        } else {
            fun(root->right,true,pathLen+1);
            fun(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL) return 0;
        fun(root,true,0);
        fun(root,false,0);
        return res;
    }
};