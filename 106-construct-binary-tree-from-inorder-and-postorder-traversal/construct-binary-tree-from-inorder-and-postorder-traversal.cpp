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
    int findPos( vector<int>& inorder , int element ){
        for( int i=0 ; i < inorder.size() ; i++ ){
            if( inorder[i] == element )return i;
        }
        return -1;
    }
    TreeNode* solve( vector<int>& postorder , int &postOrderIndex , vector<int>& inorder,
    int inOrderStart , int inOrderEnd ){
        // base case
        if( postOrderIndex < 0 || inOrderStart > inOrderEnd )return NULL;

        int element = postorder[postOrderIndex--];
        TreeNode* root = new TreeNode(element);

        int pos = findPos( inorder , element );
        root->right = solve( postorder , postOrderIndex , inorder , pos+1 , inOrderEnd );
        root->left = solve( postorder , postOrderIndex , inorder , inOrderStart , pos-1 );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex = postorder.size()-1 , inOrderStart = 0 , inOrderEnd = inorder.size() - 1;
        TreeNode* root = solve( postorder , postOrderIndex , inorder , inOrderStart , inOrderEnd );
        return root;
    }
};