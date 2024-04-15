typedef pair<int , pair<int , int>> P;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        set<P>s;
        set<P>::iterator itr;
        s.insert({ nums1[0] + nums2[0] ,  { 0 , 0 } });
        while(k-- && !s.empty()){
            itr = s.begin();
            P p = *itr;
            s.erase(itr);
            ans.push_back({ nums1[p.second.first] , nums2[p.second.second] });
            if(p.second.second + 1 < nums2.size()){
                s.insert({ nums1[p.second.first] + nums2[p.second.second + 1] , {p.second.first , p.second.second + 1} });
            }
            if(p.second.first + 1 < nums1.size()){
                s.insert({ nums1[p.second.first + 1] + nums2[p.second.second] , {p.second.first + 1 , p.second.second} });
            }
        }
        return ans;
    }
};