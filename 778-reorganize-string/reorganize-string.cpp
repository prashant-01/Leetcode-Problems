class Compare {
    public :
    bool operator()(pair<char , int>a , pair<char , int>b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        int k=1;
        unordered_map<char , int>count;
        for(auto c : s)count[c]++;
        queue<pair<char , int>>q;
        priority_queue<pair<char , int> , vector<pair<char , int>> , Compare>maxHeap;
        for(auto entry : count)maxHeap.push({ entry.first , entry.second });
        while(!maxHeap.empty()){
            pair<char , int>p = maxHeap.top();
            maxHeap.pop();
            ans.push_back(p.first);
            q.push({ p.first , p.second-1 });
            if(q.size() > k){
                p = q.front();
                q.pop();
                if(p.second)maxHeap.push(p);
            }
        }
        return ans.size() == s.size() ? ans : "";
    }
};