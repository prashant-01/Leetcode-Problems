class Solution {
public:
    bool dfs(vector<vector<int>>& graph , vector<int>&vis , vector<int>&pathVis , vector<int>&check , int node){
        vis[node]=1;
        pathVis[node]=1;
        for(auto child : graph[node]){
            if(!vis[child]){
                bool res = dfs(graph , vis , pathVis , check , child);
                if(res)return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n , 0) , pathVis(n , 0) , check(n , 0) , ans;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(graph , vis , pathVis , check , i);
            }
        }
        for(int i=0 ; i<n ; i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};