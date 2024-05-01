class Solution {
public:
    typedef pair<int , pair<int , int>>P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])return -1;
        int m=grid.size() , n=grid[0].size();
        vector<vector<int>>ans(m , vector<int>(n , INT_MAX));
        // vector<vector<pair<int , int>>>parent(m , vector<pair<int , int>>(n));
        ans[0][0]=0;
        // parent[0][0]={ 0 , 0 };
        priority_queue<P , vector<P> , greater<P>>pq;
        pq.push({ 0 , { 0 , 0 } });
        while(!pq.empty()){
            P p=pq.top();pq.pop();
            int dis=p.first;
            int i=p.second.first , j=p.second.second;
            for(int r=-1 ; r<=1 ; r++){
                for(int c=-1 ; c<=1 ; c++){
                    if(i+r<0 || j+c<0 || i+r>=m || j+c>=n || grid[i+r][j+c])continue;
                    if(ans[i][j] + 1 < ans[i+r][j+c]){
                        ans[i+r][j+c] = ans[i][j] + 1;
                        // parent[i+r][j+c]={ i , j };
                        pq.push({ ans[i+r][j+c] , { i+r , j+c } });
                    }
                }
            }
        }
        return ans[n-1][n-1] == INT_MAX ? -1 : ans[n-1][n-1]+1 ;
    }
};