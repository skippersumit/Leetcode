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
    bool areIdentical(TreeNode* r1, TreeNode* r2){
        return (!r1 and !r2) or (
            r1 
            and r2
            and (r1->val == r2->val)
            and areIdentical(r1->left,r2->left)
            and areIdentical(r1->right,r2->right)
        );
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return areIdentical(root,subRoot)
            or (root->left and isSubtree(root->left,subRoot))
            or (root->right and isSubtree(root->right,subRoot));
    }
};