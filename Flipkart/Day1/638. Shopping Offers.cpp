class Solution {
public:
    map< pair<int,vector<int>>,int>mp; //memo part
   
     
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs,int s){
        if(s==special.size()){ //couldnot choose any offers
            int cost=0;
            for(int i=0;i<needs.size();++i){
                cost+=needs[i]*price[i];
            }
            return cost;
        }
        if(mp.find({s,needs})!=mp.end()) return mp[{s,needs}];
        vector<int>need=needs; //clone need vector //since changing everytime 
        for(int j=0;j<needs.size();++j){
            need[j]=needs[j]-special[s][j];
            if(need[j]<0) return mp[{s,needs}]=solve(price,special,needs,s+1);
        }
        return mp[{s,needs}]=min(solve(price,special,needs,s+1),solve(price,special,need,s)+special[s][price.size()]);          // either choose it or don't choose
    }
    
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)     {
        return solve(price, special , needs, 0);
    }
};   