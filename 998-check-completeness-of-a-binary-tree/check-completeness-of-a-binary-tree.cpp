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
    int countNodes(TreeNode* root){
        if(root == NULL)return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCBT(TreeNode* root , int index , int n){
        if(root == NULL)return true;
        else if(index >= n)return false;
        else{
            int left = isCBT(root->left , 2*index + 1 , n);
            int right = isCBT(root->right , 2*index + 2 , n);
            return (left && right);
        }
    }
    bool isCompleteTree(TreeNode* root) {
        int n = countNodes(root);
        return isCBT(root , 0 , n);
    }
};