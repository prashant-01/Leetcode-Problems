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
    int ans;
    void inOrder( TreeNode* root , int &k ){
        if( root == NULL )return;
        inOrder( root->left , k );
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        inOrder( root->right , k );
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder( root , k );
        return ans;
    }
};