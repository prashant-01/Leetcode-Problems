class Solution {
public:
    typedef pair<int , int>P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        vector<P>adj[n];
        for(int i=0 ; i<m ; i++)
            adj[flights[i][0]].push_back({ flights[i][1] , flights[i][2] });
        vector<int>price(n , INT_MAX);
        price[src]=0;
        // { stops , { src , price } }
        queue<pair<int , P>>q;
        q.push({ 0 , { src , 0 } });

        while(!q.empty()){
            auto it = q.front();q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)continue;
            for(auto c : adj[node]){
                int adjNode = c.first;
                int edgeWeight = c.second;
                if( cost + edgeWeight < price[adjNode] && stops <= k){
                    price[adjNode]=cost + edgeWeight;
                    q.push({ stops+1 , { adjNode , price[adjNode] } });
                }
            }
        }
        if(price[dst] == INT_MAX)return -1;
        return price[dst];
    }
};