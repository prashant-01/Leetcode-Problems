class Solution {
public:
    int solve(vector<vector<int>>& triangle , vector<vector<int>>&dp , int m , 
    int i , int j){
        if(i == m)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        int ans , mn=INT_MAX;
        ans = solve(triangle , dp , m , i+1 , j) + triangle[i][j];
        mn=min(mn , ans);
        ans = solve(triangle , dp , m , i+1 , j+1) + triangle[i][j];
        mn=min(mn , ans);
        return dp[i][j]=mn;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m , vector<int>(m , -1));
        return solve(triangle , dp , m , 0 , 0);
    }
};