// class Compare{
//     public :
//     bool operator()(pair< int , vector<int> >& p1 , pair< int , vector<int> >& p2){
//         return p1.first - p2.first;
//     }
// };
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair< int , vector<int>>>s;
        set<pair< int , vector<int>>>::iterator itr;
        vector<int>indices(mat.size() , 0);
        int sum=0;
        for(int i=0 ; i<mat.size() ; i++)sum += mat[i][0];
        s.insert({sum , indices});

        // k itertion
        while(k>1){
           itr = s.begin();
           pair<int, vector<int>> a = (*itr);
           s.erase(itr);
            // all possible combinations
            for(int i=0;i<mat.size();i++){
                if(a.second[i]+1 < mat[i].size()){
                    a.first +=  mat[i][a.second[i]+1] - mat[i][a.second[i]];
                    a.second[i]++;
                    s.insert(a);
                    a.second[i]--;
                    a.first += mat[i][a.second[i]] - mat[i][a.second[i]+1];
                }
            }
            k--;
        }
        itr = s.begin();
        int ans = (*itr).first;
        return ans;
    }
};