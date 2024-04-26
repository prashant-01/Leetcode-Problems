class Solution {
public:
    // pair of ( pair of coordinates[i , j] , time )
    typedef pair<pair<int , int> , int> P;
    int ans=0;
    void bfs(vector<vector<int>>& grid){
        int m=grid.size() , n=grid[0].size();
        vector<vector<int>>vis(m , (vector<int> (n , 0)));
        queue<P>q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 2){
                    q.push({ { i , j } , 0 });
                }
            }
        }
        while(!q.empty()){
            P p = q.front();
            q.pop();
            int i=p.first.first , j=p.first.second , t=p.second;
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0 || vis[i][j])continue;
            vis[i][j]=1;
            grid[i][j]=2;
            
            q.push({ { i+1 , j } , t+1 });
            q.push({ { i , j+1 } , t+1 });
            q.push({ { i-1 , j } , t+1 });
            q.push({ { i , j-1 } , t+1 });
            ans = max(ans , t);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size();
        bfs(grid);
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1)return -1;
            }
        }
        return ans;
    }
};