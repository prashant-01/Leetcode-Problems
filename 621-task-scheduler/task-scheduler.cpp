class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        for(auto c:tasks)mp[c]++;
        for(auto i:mp)pq.push(i.second);
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }
            for(auto i:temp){
                if(i>0){
                    pq.push(i);
                }
            }

            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};