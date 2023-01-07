class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            int same=1;
            unordered_map<double,int>m;
            for(int j=i+1;j<points.size();j++){
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                same++;
            }
            else if(points[i][0] == points[j][0]){
                m[INT_MAX]++;
            }
            else{
                double slope = double(points[i][1] - points[j][1]) / double(points[i][0]- points[j][0]);
                m[slope]++;
            }
            }
        int compare=0;
        for(auto mm:m){
        compare=max(compare,mm.second);
        }
        compare+=same;
        res=max(compare,res);
        }
       
        return res;

    }
};