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
    void inorder(TreeNode* root,vector<int >&arr)
    {
        if(root==NULL)
        return;
        inorder(root->left,arr);
        if(root->left==NULL && root->right==NULL)
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>arr1,arr2;
        inorder(root1,arr1);
        inorder(root2,arr2);

        if(arr1==arr2)
        return true;
        else
        return false;    
    }
};