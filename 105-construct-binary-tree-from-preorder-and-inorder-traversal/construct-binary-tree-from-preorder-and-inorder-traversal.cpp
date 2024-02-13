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
        for( int i=0 ; i< inorder.size() ; i++ ){
            if( inorder[i] == element )return i;
        }
        return -1;
    }
    TreeNode* solve( vector<int>& preorder, int &preOrderIndex , vector<int>& inorder , int inOrderStart , int inOrderEnd ){
        if( preOrderIndex >= preorder.size() || inOrderStart > inOrderEnd || 
        inOrderStart >= inorder.size() || inOrderEnd < 0 )return NULL ;

        int element = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(element);

        int pos = findPos( inorder , element );
        root->left = solve( preorder , preOrderIndex , inorder , inOrderStart , pos-1 );
        root->right = solve( preorder , preOrderIndex , inorder , pos+1 , inOrderEnd );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0 , inOrderStart=0 , inOrderEnd=preorder.size()-1;
        TreeNode* root = solve( preorder , preOrderIndex , inorder , inOrderStart , inOrderEnd );
        return root;
    }
};