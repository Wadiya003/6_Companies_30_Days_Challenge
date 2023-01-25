class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
       vector<pair<int,int>> adj[n+1];
        //make adjacency list
        for(int i=0;i<times.size();i++)
            adj[times[i][0]].push_back(make_pair(times[i][2],times[i][1]));
        //distance calculate for signal
        vector<int> dist(n+1, INT_MAX);
        //pair of tot time and node ,sort this in increasing order
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push(make_pair(0, k));  
        while(!pq.empty()){
            pair<int,int>temp=pq.top();pq.pop();
            //traverse for all neighbours of a particular node with less time 
            for(auto adjacent:adj[temp.second]){
                int tot = dist[temp.second] + adjacent.first;
                //if the time to get to that node is less than the previous time ( for any                          previous signal) then update 
                if (tot < dist[adjacent.second]) {
                    dist[adjacent.second] = tot;
                    pq.push(make_pair(tot, adjacent.second));
                }
              }
           }
        int ans = INT_MIN;
        for (int i = 1; i < dist.size(); ++i) {
            if (ans < dist[i]) {
                ans = dist[i];
            }
        }
        return ans == INT_MAX? -1 : ans;
    
         }
    
};