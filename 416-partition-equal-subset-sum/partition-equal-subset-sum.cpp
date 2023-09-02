class Solution {
public:
    int solve(vector<int>& nums , int i , int sumPartition1 , int totalSum ,
    vector<vector<int>>&dp){
        if(sumPartition1 * 2 == totalSum)return 1;
        if(sumPartition1 * 2 > totalSum)return 0;
        if( i == nums.size()){
            if(totalSum != 2*sumPartition1)return 0;
        }
        if(dp[i][sumPartition1] != -1)return dp[i][sumPartition1];
        bool caseA = solve(nums , i+1 , sumPartition1 , totalSum , dp);
        bool caseB = solve(nums , i+1 , sumPartition1 + nums[i] , totalSum , dp);

        return dp[i][sumPartition1] = caseA || caseB;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=accumulate(nums.begin() , nums.end() , 0);
        vector<vector<int>>dp(nums.size() , vector<int>(totalSum/2 + 1 , -1));
        return solve(nums , 0 , 0 , totalSum , dp);
    }
};