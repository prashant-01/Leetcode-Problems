class Solution {
public:
    void bfs(vector<vector<int>>& grid , int initialColor , int color , int sr , int sc){
        int n=grid.size() , m=grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        queue<pair<int , int>>q;
        q.push({sr , sc});
        while(!q.empty()){
            pair<int , int>p = q.front();
            q.pop();
            int i=p.first , j=p.second;
            if(i<0 || j <0 || i>=n || j>=m || grid[i][j] != initialColor || vis[i][j])continue;
            vis[i][j]=1;
            grid[i][j]=color;
            q.push({i + 1 , j });
            q.push({i , j + 1 });
            q.push({i - 1 , j });
            q.push({i , j - 1 });
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size() , m=image[0].size() , initialColor=image[sr][sc];
        bfs(image , initialColor , color , sr , sc);
        return image;
    }
};