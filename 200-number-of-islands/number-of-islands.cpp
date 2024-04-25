class Solution {
public:
    void dfs(vector<vector<char>>& grid , vector<vector<int>>&vis , int i , int j , int n , int m){
        vis[i][j]=1;
        if(i+1 < n){
            if(!vis[i+1][j] && grid[i+1][j] == '1'){
                vis[i+1][j]=1;
                dfs(grid , vis , i+1 , j , n , m);
            }
        }
        if(i-1 >= 0){
            if(!vis[i-1][j] && grid[i-1][j] == '1'){
                vis[i-1][j]=1;
                dfs(grid , vis , i-1 , j , n , m);
            }
        }
        if(j+1 < m){
            if(!vis[i][j+1] && grid[i][j+1] == '1'){
                vis[i][j+1]=1;
                dfs(grid , vis , i , j+1 , n , m);
            }
        }
        if(j-1 >= 0){
            if(!vis[i][j-1] && grid[i][j-1] == '1'){
                vis[i][j-1]=1;
                dfs(grid , vis , i , j-1 , n , m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size() , m=grid[0].size() , islands=0;
        vector<vector<int>>vis(n , vector<int>(m , 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    dfs(grid , vis , i , j , n , m);
                }
            }
        }
        return islands;
    }
};