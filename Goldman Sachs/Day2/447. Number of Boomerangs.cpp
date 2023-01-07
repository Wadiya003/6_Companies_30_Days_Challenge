class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        map<vector<int>, vector<int>>m;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(i!=j){
                    int dis=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                    m[points[i]].push_back(dis);
                }
            }
        }
        int ans=0;
        for(auto m:m){
            unordered_map<int,int>cnt;
            for(auto i:m.second){
                //get count of distances between points
                cnt[i]++;
            }
            for(auto c:cnt){
                //get number of pairs
                ans+=c.second*(c.second-1);
            }
        }
        return ans;
    }
};