class Solution {
public:
    int solve(vector<int>nums , int i , vector<int>&v , vector<vector<int>>&ans){
        if(i == nums.size()){
            ans.push_back(v);
            return 1;
        }
        v.push_back(nums[i]);
        int c1 = solve(nums , i+1 , v , ans);
        v.pop_back();
        int c2 = solve(nums , i+1 , v , ans);
        return c1 + c2;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        cout << solve(nums , 0 , v , ans) << endl;;
        return ans;
    }
};