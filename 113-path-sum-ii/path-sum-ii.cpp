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
    bool isLeafNode( TreeNode* root ) {
        return (root->left == NULL && root->right == NULL);
    }

    void solve( TreeNode* root, int targetSum , int &currSum , vector<int>&v , vector<vector<int>>&ans  ){
        if( root == NULL )return;
        if( isLeafNode( root ) ){
            v.push_back( root->val );
            // for(int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
            // cout << endl;

            currSum += root->val;
            // cout << currSum << endl;
            if( currSum == targetSum ){
                ans.push_back(v);
            }
            v.pop_back();
            currSum -= root->val;
            return;
        }

        v.push_back(root->val);
        currSum += root->val;
        solve( root->left , targetSum , currSum , v , ans );
        solve( root->right , targetSum , currSum , v , ans );
        v.pop_back();
        currSum -= root->val;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        vector<vector<int>>ans;
        int currSum=0;
        solve( root , targetSum , currSum , v , ans );
        return ans;
    }
};