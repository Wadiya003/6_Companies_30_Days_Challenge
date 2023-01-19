class cmp{
    public:
    bool operator()(const pair<int, string>&p1,const pair<int, string>&p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
};
class Solution {
public:
 
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>fre;
        for(auto w:words){
            fre[w]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>, cmp>p;
        for(auto f:fre){
            p.push({f.second,f.first});   
              if(p.size()>k){
                 p.pop();
              }
        }
        vector<string>ans(k);
        int m = k-1;
        while(p.size() > 0) {
        ans[m--] = p.top().second;
        p.pop();
        }
        return ans;
    }
};