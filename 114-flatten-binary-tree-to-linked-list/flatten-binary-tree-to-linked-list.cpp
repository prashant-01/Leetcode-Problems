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
    TreeNode* find_pre( TreeNode* curr ){
        TreeNode* pre = curr->left;
        while( pre->right  ){
            pre = pre->right;
        }
        return pre;
    }
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* pre;
        while( curr != NULL ){
            if( curr->left ){
                pre = find_pre(curr);
                pre->right=curr->right;
                curr->right=curr->left;
            }
            curr=curr->right; 
        }

        // left pointer null
        curr = root;
        while( curr != NULL ){
            curr->left = NULL;
            curr=curr->right;
        }
    }
};