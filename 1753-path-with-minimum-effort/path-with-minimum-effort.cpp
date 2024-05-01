class Solution {
public:
typedef pair<int , pair<int , int>> P;
    void process(vector<vector<int>>& heights , vector<vector<int>>& ans , int i , int j){
        
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size() , n=heights[0].size();
        vector<vector<int>>ans(m , vector<int>(n , INT_MAX));
        ans[0][0]=0;
        priority_queue<P , vector<P> , greater<P>>pq;
        pq.push({ 0 , { 0 , 0 } });
        vector<int>dr = { 1 , 0 , -1 , 0 } , dc = { 0 , 1 , 0 , -1 };
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int diff = it.first;
            int i=it.second.first , j=it.second.second;
            for(int k=0 ; k<4 ; k++){
                int newR = i+dr[k] , newC = j+dc[k];
                if(newR<0 || newC<0 || newR>=m || newC>=n)continue;
                int currDiff = max(diff , abs(heights[newR][newC]-heights[i][j]));
                if(currDiff < ans[newR][newC]){
                    ans[newR][newC] = currDiff;
                    pq.push({ currDiff , { newR , newC } });
                }
            }
        }
        return ans[m-1][n-1];
    }
};