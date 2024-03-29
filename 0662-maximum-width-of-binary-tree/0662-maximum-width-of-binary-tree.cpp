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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> widths;
        if (!root) return 0;
        
        int max_width = 1;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int level_size = q.size();
            int leftmost_pos = 0, rightmost_pos = 0;
            int level_offset = 0;
            long long int level_min_pos = q.front().second;
            
            
            for (int i = 0; i < level_size; i++) {
                auto node_pos_pair = q.front();
                TreeNode* node = node_pos_pair.first;
                long long int pos = node_pos_pair.second - level_min_pos;
                q.pop();
                
                
                if (i == 0)
                    leftmost_pos = pos;
                
                if (i == level_size-1)
                    rightmost_pos = pos;

                if (node->left)
                    q.push({node->left, 2 * pos + 1});
                
                if (node->right)
                    q.push({node->right, 2 * pos + 2});
            }
            
            int width = rightmost_pos - leftmost_pos + 1;
            max_width = max(max_width, width);
        }

        return max_width;  
    }
};