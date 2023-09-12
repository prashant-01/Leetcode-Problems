class Solution {
public:
    void solve(int n , string s , int o , int c , vector<string>&ans){
        if(o == n && c == n){
            ans.push_back(s);return ;
        }
        if(o-c < 0)return ;
        if(o < n)solve(n , s+'(' , o+1 , c , ans);
        if(c < n)solve(n , s+')' , o , c+1 , ans);
    }
    vector<string> generateParenthesis(int n) {
        string s="(";
        vector<string>ans;
        solve(n , s , 1 , 0 , ans);
        return ans;
    }
};