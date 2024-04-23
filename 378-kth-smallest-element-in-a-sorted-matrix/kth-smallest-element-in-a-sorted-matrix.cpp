// class Solution {
// public:
//     typedef pair<int , int>P;
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size() , ans;
//         auto compare = [matrix](P a , P b){
//             return matrix[a.first][a.second] > matrix[b.first][b.second];
//         };
//         priority_queue<P , vector<P>, decltype(compare)>minHeap(compare);
//         for(int i=0 ; i<n ; i++)minHeap.push({ i , 0 });
//         while(k--){
//             P p = minHeap.top();
//             minHeap.pop();
//             ans=matrix[p.first][p.second];
//             if(p.second+1 < n)minHeap.push({ p.first , p.second + 1 });
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int>max_h;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                max_h.push(matrix[i][j]);
                if(max_h.size()>k)
                max_h.pop();
            }
        }
        return max_h.top();
    }
};