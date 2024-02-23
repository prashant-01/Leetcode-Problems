/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* node;
    void lca( TreeNode* root, TreeNode* p, TreeNode* q ){
        if( root == NULL )return;
        if( root->val >= p->val && root->val >= q->val ){
            lca( root->left , p , q );
        }
        if( root->val <= p->val && root->val <= q->val ){
            lca( root->right , p , q );
        }
        if( (root->val >= p->val && root->val <= q->val)  || (root->val <= p->val && root->val >= q->val) ){
            // lca is found
            node = root;
            return;
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca( root , p , q );
        return node;
    }
};