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
    bool isBST( TreeNode* root , long long mx , long long mn ){
        if( root == NULL )return true;
        bool checkRoot = root->val > mn && root->val < mx ;
        bool checkLeft = isBST( root->left , root->val , mn );
        bool checkRight = isBST( root->right , mx , root->val );
        return checkRoot && checkLeft && checkRight ;
    }
    bool isValidBST(TreeNode* root) {
        if( root->left == NULL && root->right == NULL )return true;
        long long int mn = -1000000000000, mx = 1000000000000;
        return isBST( root , mx , mn );
    }
};