class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        dp[0][0]=1;bool check = false;
        for(int j=1 ; j<=n ; j++){
            if(p[j-1] != '*')check=true;
            if(check)dp[0][j]=0;
            else dp[0][j]=1;
        }
        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j]=(dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1]);
                else dp[i][j]=0;
            }
        }
        return dp[m][n];
    }
};