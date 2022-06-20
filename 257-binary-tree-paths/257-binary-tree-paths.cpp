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
    private:
    void dfs(TreeNode* root, string path, vector<string> &paths){
        path += to_string(root->val);
        if(root->left == NULL and root->right == NULL){
            paths.push_back(path);
            return;
        }
        if(root->left != NULL){
            dfs(root->left,path+"->",paths);
        }
        if(root->right != NULL){
            dfs(root->right,path+"->",paths);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        if(root == NULL) return paths;
        
        dfs(root,"",paths);
        
        return paths;
    }
};