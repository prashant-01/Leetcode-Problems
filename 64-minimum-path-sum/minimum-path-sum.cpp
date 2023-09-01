class Solution {
public:
    int solve(int m , int n , int i , int j , vector<vector<int>>&dp , vector<vector<int>>& grid){
        if(i < 0 || j < 0)return INT_MAX;
        if(i == 0 && j == 0)return grid[0][0];
        if(dp[i][j])return dp[i][j];
        int mn=INT_MAX;
        int a=solve(m , n , i-1 , j , dp , grid);
        if(a != INT_MAX)mn=min(mn , a+grid[i][j]);
        
        int b=solve(m , n , i , j-1 , dp , grid);
        if(b != INT_MAX)mn=min(mn , b+grid[i][j]);
        return dp[i][j]=mn;

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        return solve(m , n , m-1 , n-1 , dp , grid);
    }
};