class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        int cnt=0;
        sort(special.begin(),special.end());
        int diff = 0;
        
         if(top > special[n-1])
            diff = top - special[n-1];
        cnt = max(cnt,diff);
        
        if(bottom < special[0])
            diff = special[0] - bottom;
        cnt = max(diff,cnt);
      
        for(int i = 0;i < n-1;i++){
            cnt = max(cnt,special[i+1] - special[i]-1);
        }
        return cnt;
    }
};