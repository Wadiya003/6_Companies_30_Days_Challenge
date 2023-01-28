class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> v[n];
        for(auto f:flights){
            v[f[0]].push_back({f[1],f[2]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,src,0});//cost,src,k
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int cost=p[0];
            int cur=p[1];
            int stop=p[2];
            //end case
            if(cur==dst)
            return cost;
            //previously reached this node with less stops
            if(dist[cur]<stop)
            continue;
            //stops more than k
            if(stop>k)
            continue;

            dist[cur]=stop;
             for( auto node : v[cur] )
                pq.push( { cost+node.second, node.first, stop+1 });
        }
        return -1;
        
    }
};