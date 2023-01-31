class comp{
  public:
     bool operator()(pair<int,string> &a, pair<int,string> &b){
            if(a.first < b.first) return true;
            else if(a.first == b.first) return a.second > b.second;
            return false;
        }
};
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        unordered_map<string,priority_queue<pair<int,string>, vector<pair<int,string>>,comp>>m;
        for(int i=0;i<creators.size();i++){
            m[creators[i]].push(make_pair(views[i],ids[i]));
        }
        unordered_map<string,long long> sum;
        int n = views.size();
        for(int i = 0; i < n; i++){
            sum[creators[i]] += views[i];
        }
        //get the graetest sum
        long long highest = INT_MIN;
        for(auto s: sum){
            if(s.second > highest)
                highest = s.second;
        }

        for(auto s: sum){
            //get all with same total sum
            if(s.second == highest){
                ans.push_back({s.first, m[s.first].top().second});
            }
        }
       
        return ans;  
    }

};


