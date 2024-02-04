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
    int height( TreeNode* root ){
        if( root == NULL )return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int rootHeight = 1 + max( leftHeight , rightHeight );
        return rootHeight;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        bool checkRoot = abs(height( root->left ) - height( root->right )) <= 1 ? true : false;
        bool checkLeft = isBalanced( root->left );
        bool checkRight = isBalanced( root->right );
        return ( checkRoot && checkLeft && checkRight ) ? true : false ;
    }
};