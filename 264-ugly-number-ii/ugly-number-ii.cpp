class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n , 0);
        dp[0]=1;
        int c2=0 , c3=0 , c5=0;
        for(int i=1; i<n; i++){
            int nextMultipleOf2 = dp[c2]*2;
            int nextMultipleOf3 = dp[c3]*3;
            int nextMultipleOf5 = dp[c5]*5;

            dp[i] = min(nextMultipleOf2 , min(nextMultipleOf3 , nextMultipleOf5));

            if(dp[i] == nextMultipleOf2)c2++;
            if(dp[i] == nextMultipleOf3)c3++;
            if(dp[i] == nextMultipleOf5)c5++;
        }
        return dp[n-1];
    }
};