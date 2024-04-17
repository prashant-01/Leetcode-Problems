class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size() , j=0;
        vector<pair<int , int>>v;
        priority_queue<int>maxHeap;
        for(int i=0 ; i<n ; i++)
            v.push_back({ capital[i] , profits[i] });
        sort(v.begin() , v.end());
        while(k--){
            while(j<n && v[j].first <= w)
                maxHeap.push(v[j++].second);
            if(maxHeap.empty())break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};