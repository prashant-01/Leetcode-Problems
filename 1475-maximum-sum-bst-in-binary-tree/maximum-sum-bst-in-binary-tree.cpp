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
    struct NodeData{
        int maxVal;
        int minVal;
        int sum;
        bool isBST;
        NodeData( int maxVal , int minVal , int sum , bool isBST ){
            this->maxVal = maxVal;
            this->minVal = minVal;
            this->sum = sum;
            this->isBST = isBST;
        }
    };

    int maxSum=0;
    NodeData* solve( TreeNode* root ){
        if( root == NULL ){
            NodeData* temp = new NodeData( -100000 , 100000 , 0 , true ) ;
            return temp;
        }
        NodeData* leftData = solve( root->left );
        NodeData* rightData = solve( root->right );

        bool isRootBST = leftData->isBST && rightData->isBST && (leftData->maxVal < root->val && rightData->minVal > root->val);

        int sum = leftData->sum + rightData->sum + root->val;
        if( isRootBST ){
            maxSum = max( maxSum , sum );
        }
        NodeData* rootData = new NodeData( max( rightData->maxVal , root->val ) , 
        min( leftData->minVal , root->val ) , sum , isRootBST );
        return rootData;
    }

    int maxSumBST(TreeNode* root) {
        NodeData* ans = solve( root );
        return maxSum;
    }
};