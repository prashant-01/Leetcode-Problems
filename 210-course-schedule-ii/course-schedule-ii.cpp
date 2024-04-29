class Solution {
public:
    bool dfs(vector<int>adj[] , vector<int>&vis , vector<int>&pathVis , stack<int>&s , int node){
        vis[node]=1;
        pathVis[node]=1;
        for(auto child : adj[node]){
            if(!vis[child]){
                bool res = dfs(adj , vis , pathVis , s , child);
                if(res)return true;
            }
            else if(pathVis[child]){
                return true;
            }
        }
        pathVis[node]=0;
        s.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses] , vis(numCourses , 0) , pathVis(numCourses , 0) , ans;
        stack<int>s;
        for(int i=0 ; i<prerequisites.size() ; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0 ; i<numCourses ; i++){
            if(!vis[i]){
                if(dfs(adj , vis , pathVis , s , i))return ans;
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};