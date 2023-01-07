class Solution {
public:
    bool isPossible(vector<int>& nums) {
        //count freq and store in map
        unordered_map<int,int> freq;
        unordered_map<int,int> can_fit_in_existing;
        for(int n: nums) 
            freq[n]++;
        for(int n: nums){
            if(freq[n] == 0) continue;
            if(can_fit_in_existing[n] > 0){
                can_fit_in_existing[n]--;
                freq[n]--;
                can_fit_in_existing[n+1]++;
            }
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                can_fit_in_existing[n+3]++;
            }
            else{
                return false;
            }
        }
        
        return true;

    }
};