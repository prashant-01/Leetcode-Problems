class Solution {
public:
    typedef pair<int , pair<int , int>>P;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        set<P>s;
        set<P>::iterator itr;
        s.insert({ matrix[0][0] , { 0 , 0 } });
        while(k > 1 && !s.empty()){
            itr = s.begin();
            P p = *itr;
            s.erase(itr);
            if(p.second.second + 1 < n)
                s.insert({ matrix[p.second.first][p.second.second + 1] , { p.second.first , p.second.second + 1 } });
            if(p.second.first + 1 < n)
                s.insert({ matrix[p.second.first + 1][p.second.second] , { p.second.first + 1 , p.second.second } });
            k--;
        }
        itr = s.begin();
        return (*itr).first;
    }
};