class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans=0;
        vector<vector<int>> graph(n, vector<int>(n, 1e9));
        for(auto e : edges) 
        graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];
        for(int i=0; i<n; i++) 
        graph[i][i] = 0;
        
        for(int i=0; i<n; i++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][i] + graph[i][j]);
                }
            }
        }
        int maxx = INT_MAX;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j : graph[i]) {
                if(j <= distanceThreshold) cnt++;
            }
            if(cnt <= maxx) ans = i, maxx = cnt;   
        }
                return ans;
    }
};
