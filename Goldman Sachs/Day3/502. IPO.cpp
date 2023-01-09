class Solution {
public:
   int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       vector<pair<int,int>>combine;
       for(int i=0;i<profits.size();i++){
           combine.push_back({capital[i],profits[i]});
        } 
       sort(combine.begin(),combine.end());
       int ans=0;
       priority_queue<int>pq;
       int i=0;
       while(i<combine.size() && k){
           if(w>=combine[i].first){
               pq.push(combine[i++].second);
           }
           else{
               if(pq.empty())
               return w;
               w+=pq.top();
               pq.pop();
               k--;
           }
       }
       while(k-- && !pq.empty()){
            w+=pq.top();
            pq.pop();
       }
       return w;
    }
};
        