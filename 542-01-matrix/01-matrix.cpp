class Solution {
public:
    void bfs(vector<vector<int>>& mat , vector<vector<int>>& vis , vector<vector<int>>& ans , 
    queue<pair<pair<int , int> , int>>q){
        int m=mat.size() , n=mat[0].size();
        while(!q.empty()){
            int i = q.front().first.first , j = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            if(i<0 || j<0 || i>=m || j>=n || vis[i][j])continue;
            ans[i][j]=dis;
            vis[i][j]=1;
            q.push({ {i+1 , j} , dis+1 });
            q.push({ {i , j+1} , dis+1 });
            q.push({ {i-1 , j} , dis+1 });
            q.push({ {i , j-1} , dis+1 });
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size() , n=mat[0].size();
        vector<vector<int>>ans(m , vector<int>(n , 0)) , vis(m , vector<int>(n , 0));
        queue<pair<pair<int , int> , int>>q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j] == 0)
                    q.push({ { i , j } , 0 }); 
            }
        }
        bfs(mat , vis , ans , q);
        return ans;
    }
};