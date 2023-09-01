class Solution {
public:
    int solve(vector<vector<int>>& matrix , vector<vector<optional<int>>>& dp , int n , int i , int j){
        if(j<0 || j >= n)return INT_MAX;
        if(i < 0)return 0;
        if(dp[i][j] != nullopt)return dp[i][j].value_or(0);

        int mn=INT_MAX , ans;
        ans=solve(matrix , dp , n , i-1 , j-1);if(ans != INT_MAX)mn=min(mn , ans+matrix[i][j]);
        ans=solve(matrix , dp , n , i-1 , j);if(ans != INT_MAX)mn=min(mn , ans+matrix[i][j]);
        ans=solve(matrix , dp , n , i-1 , j+1);if(ans != INT_MAX)mn=min(mn , ans+matrix[i][j]);
        dp[i][j]=mn;return mn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size() , minSum=INT_MAX; 
        vector<vector<optional<int>>> dp(n, vector<optional<int>>(n, nullopt));
        for(int j=0;j<n;j++)minSum=min(minSum , solve(matrix , dp , n , n-1 , j));
        return minSum;
    }
};