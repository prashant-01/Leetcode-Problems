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
    bool isBalance = true;
    int height( TreeNode* root ){
        if( root == NULL )return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if( isBalance ){
            isBalance = abs( leftHeight - rightHeight ) <= 1 ;
        }
        return 1 + max( leftHeight , rightHeight );
    }
    bool isBalanced(TreeNode* root) {
        int h = height( root );
        return isBalance ;
    }
};