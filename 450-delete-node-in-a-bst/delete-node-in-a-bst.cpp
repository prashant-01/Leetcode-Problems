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
    TreeNode* minVal( TreeNode* root ){
        TreeNode* temp = root;
        while( temp->left != NULL )temp = temp->left;
        return temp;
    }
    TreeNode* deleteNodeBST( TreeNode* root , int val ){
        if( root == NULL )return root;
        if( root->val == val ){

            // 0 child case 
            if( root->left == NULL && root->right == NULL ){
                delete root;
                return NULL;
            }

            // 1 child case - left wala
            if( root->left != NULL && root->right == NULL ){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 1 child case - right wala
            if( root->left == NULL && root->right != NULL ){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 child case
            if( root->left != NULL && root->right != NULL ){
                // find min val from right subtree
                int mini = minVal( root->right )->val;
                root->val = mini;
                root->right = deleteNodeBST( root->right , mini );
            }
        }
        if( val < root-> val ){
            root->left = deleteNodeBST( root->left , val );
        }
        if( val > root-> val ){
            root->right = deleteNodeBST( root->right , val );
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = deleteNodeBST( root , key );
        return root;
    }
};