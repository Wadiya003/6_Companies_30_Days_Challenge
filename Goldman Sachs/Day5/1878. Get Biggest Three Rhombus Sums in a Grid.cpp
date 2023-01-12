class Solution {
public:
    bool valid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>ans;
        set<int>s;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                s.insert(grid[i][j]);
            }
        }
        for(int i=1; i<=50; i++){
            for(int j=0; j<grid.size(); j++){
                for(int k=0; k<grid[0].size(); k++){
                    if(valid(j-i, k, grid.size(), grid[0].size()) && valid(j, k-i, grid.size(), grid[0].size()) && valid(j+i, k, grid.size(), grid[0].size()) && valid(j, k+i, grid.size(), grid[0].size())){
                        int sum=grid[j-i][k]+grid[j+i][k]+grid[j][k-i]+grid[j][k+i];
                        for(int x=1; x<i; x++){
                            sum+=grid[j-x][k+i-x];
                        }
                        for(int x=1; x<i; x++){
                            sum+=grid[j-x][k-i+x];
                        }
                        for(int x=1; x<i; x++){
                            sum+=grid[j+x][k+i-x];
                        }
                        for(int x=1; x<i; x++){
                            sum+=grid[j+x][k-i+x];
                        }
                        s.insert(sum);
                    }
                }
            }
        }
        vector<int>v;
        for(auto it: s){
            v.push_back(it);
        }
        reverse(v.begin(), v.end());
        if(v.size()<3){return v;}
        for(int i=0; i<3; i++){ans.push_back(v[i]);}
        return ans;
    }
};