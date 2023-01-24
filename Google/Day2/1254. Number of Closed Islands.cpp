class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
           return false;
		if(grid[i][j]==1)
            return true;
		grid[i][j]=1;

		bool dx1=dfs(grid,i-1, j);
        bool dx2=dfs(grid,i, j-1);
        bool dy1=dfs(grid,i+1, j);
        bool dy2=dfs(grid,i, j+1);
		return (dx1&&dx2&&dy1&&dy2);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>v(m, vector<int>(n, 0));
		int ans=0;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(grid[i][j]==0){
					if(dfs(grid,i, j)){
                        ans++;
                    }
				}
			}
		}
		return ans;
    }
};