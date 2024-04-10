class compare {
    public :
    bool operator()(pair<char , int>a , pair<char , int>b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char , int>count;
        for(auto c : s)count[c]++;
        pair<char , int>p;
        priority_queue<pair<char , int> , vector<pair<char , int>> , compare>maxHeap;
        for(auto entry : count)
            maxHeap.push(make_pair(entry.first , entry.second));
        while(!maxHeap.empty()){
            p = maxHeap.top();
            int i = p.second;
            while(i-- > 0)ans.push_back(p.first);
            maxHeap.pop();
        }
        return ans;
    }
};