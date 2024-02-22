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
    TreeNode* node = NULL ;
    bool findNode( TreeNode* root , int val ){
        if( root == NULL )return false;
        if( root->val == val ){
            node = root;
            return true;
        }
        if( val < root->val ){
            findNode( root->left , val);
        }
        if( val > root->val ){
            findNode( root->right , val);
        }
        return false;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        findNode( root , val );
        return node;
    }
};