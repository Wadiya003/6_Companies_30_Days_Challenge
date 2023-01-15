typedef pair<string, int> pi;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        for (vector<int> v: queries){
        priority_queue<pi,vector<pi>,greater<pi>>pq;
            for(int i=0;i<n;i++){
                pq.push({(nums[i].substr(nums[i].size()-v[1])),i});
            }
        for(int i = 0; i < v[0]-1; i++){ 
        pq.pop(); 
        } 
        int kth=pq.top().second;
        ans.push_back(kth);
        }
        return ans;
    }
};
            
        