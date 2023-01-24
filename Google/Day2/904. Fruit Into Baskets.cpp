class Solution {
public:
//Find the longest continuous sub array that has exactly 2 distinct elements.
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int ans=0;
        int l=0,r=0;
        while(r<fruits.size()){

             m[fruits[r]]+=1;
            
            if(m.size()<=2){
                ans=max(ans, r-l+1);
            }else{
                while(m.size()>2){
                    m[fruits[l]]-=1;
                    if(m[fruits[l]]==0)
                        m.erase(fruits[l]);
                    l++;
                }
                ans=max(ans, r-l+1);
                
            }
            r++;
        }
        return ans;
    }
};
