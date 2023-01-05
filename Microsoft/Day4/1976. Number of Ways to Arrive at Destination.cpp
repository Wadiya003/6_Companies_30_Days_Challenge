class Solution {
public:
    long long INF = 1e15;
    long long MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> graph(n+1);
        vector <long long> dp(n+1, 0);
        vector <long long> dist(n+1, INF);
        priority_queue<pair<long long, long long>>pq;
        for(auto& road: roads) {
            long long u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }   
        dist[0]=0;
        dp[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long nn = pq.top().second;
            long long ww = -pq.top().first;
            pq.pop();

            if(dist[nn] < ww) continue;
            for(auto key: graph[nn]) {
                long long node = key.first;
                long long weight = key.second;
                if(ww + weight == dist[node]) {
                    dp[node] = (dp[node] + dp[nn])%MOD;
                }
                if(ww + weight < dist[node]) {
                    dp[node] = dp[nn]%MOD;
                    dist[node] = ww + weight;
                    pq.push({-dist[node], node});
                }
            }
        }
        return dp[n-1];
    }
};