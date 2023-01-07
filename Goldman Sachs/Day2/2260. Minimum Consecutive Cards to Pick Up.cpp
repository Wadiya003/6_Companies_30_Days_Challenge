class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,pair<int,int>>m;
        int ans=INT_MAX;
        ///store last ind and min diff btw two same cards
        for(int i=0;i<cards.size();i++){
            if(m.find(cards[i])!=m.end()){
                int a1=m[cards[i]].first;
                int a2=i;
                if(m[cards[i]].second==0){
                    m[cards[i]]={i,(a2-a1+1)};
                }
                else if(abs(a1-a2)<m[cards[i]].second){
                    m[cards[i]]={i,(a2-a1+1)};
                }
                else if(abs(a1-a2)>=m[cards[i]].second){
                    int diff=m[cards[i]].second;
                    m[cards[i]]={i,diff};
                }
            }
            else{
                m[cards[i]]={i,0};//1,0,0
                //0,4,4
                //1,2,3
                //2,5,3

            }
        }
        for(auto m:m){
            if(m.second.second!=0)
            ans=min(ans,m.second.second);
        }
        return ans==INT_MAX?-1:ans;
    }
};