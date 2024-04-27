class Solution {
public:
    void bfs(vector<vector<char>>& board , int sr , int sc , vector<vector<int>>&vis){
        int m=board.size() , n=board[0].size();
        queue<pair<int , int>>q;
        q.push({sr , sc});
        while(!q.empty()){
            int i = q.front().first , j = q.front().second;
            q.pop();
            if(i<0|| j<0 || i>=m || j>=n || board[i][j] == 'X' || vis[i][j])continue;
            vis[i][j]=1;
            q.push({i+1 , j});
            q.push({i , j+1});
            q.push({i-1 , j});
            q.push({i , j-1});
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size() , n=board[0].size();
        vector<vector<int>>vis(m , vector<int>(n , 0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j] == 'O'){
                    bfs(board , i , j , vis);
                    cout << "hii" << endl;
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};