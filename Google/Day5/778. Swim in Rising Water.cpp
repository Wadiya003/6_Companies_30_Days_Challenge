class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
    
        q.push({grid[0][0], {0, 0}});
        vis[0][0]=true;
        int res = 0;
        while (!q.empty()) {
            int time=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            res = max(res, time);
            //end case
            if (i== n - 1 && j == m - 1) 
            return res;
            int dir[] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int u = i + dir[k];
                int v = j + dir[k + 1];
                if (u>=0 and u<n and v>=0 and v<n and !vis[u][v]) {
                    q.push({grid[u][v], {u, v}});
                    vis[u][v]=true;
                }
            }
        }
        return -1;
    }
};