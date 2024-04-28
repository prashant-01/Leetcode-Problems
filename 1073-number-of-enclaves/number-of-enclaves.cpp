class Solution {
public:
    void bfs(vector<vector<int>>grid , vector<vector<int>>&vis , queue<pair<int , int>>&q){
        int m=grid.size() , n=grid[0].size();
        while(!q.empty()){
            int i=q.front().first , j=q.front().second;
            q.pop();
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0 || vis[i][j])continue;
            vis[i][j]=1;
            q.push({i+1 , j});
            q.push({i , j+1});
            q.push({i-1 , j});
            q.push({i , j-1});
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size() , ans=0;
        vector<vector<int>>vis(m , vector<int>(n , 0));
        queue<pair<int , int>>q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j] == 1)
                    q.push({i , j});
            }
        }
        bfs(grid , vis , q);
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!vis[i][j] && grid[i][j] == 1)ans++;
            }
        }
        return ans;
    }
};