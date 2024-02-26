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
    TreeNode* createBST( TreeNode* root , vector<int>& preorder , int &i , long long int mn , long long int mx ){
        if( i >= preorder.size() )return NULL;
        if( preorder[i] > mn && preorder[i] < mx ){
            root = new TreeNode(preorder[i]);
            i++;
        }
        if( root != NULL ){
            root->left = createBST( root->left , preorder , i , mn , root->val );
            root->right = createBST( root->right , preorder , i , root->val , mx );
        }
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        int i=0;
        return createBST( root , preorder , i , -1000000000000 , 1000000000000 );
    }
};