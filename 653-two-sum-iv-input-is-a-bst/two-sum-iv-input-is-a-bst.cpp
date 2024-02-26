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
    vector<int>inorder;
    void inorderTraverse( TreeNode* root ){
        if( root == NULL )return ;
        inorderTraverse( root->left );
        inorder.push_back(root->val);
        inorderTraverse( root->right );
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        inorderTraverse(root);
        int i=0 , j=inorder.size()-1;
        while( i<j ){
            if( (inorder[i] + inorder[j]) > k )j--;
            else if( (inorder[i] + inorder[j]) < k )i++;
            else return true;
        }
        return false;
    }
};