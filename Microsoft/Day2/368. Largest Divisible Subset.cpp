class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]+1>dp[i] && nums[i]%nums[j]==0){
                    dp[i]=dp[j]+1;
                }
            }
        }
        // find the maximum legth from dp table
        int max_length = *max_element(dp.begin(), dp.end());
        // find the index of maximum length
        int max_idx = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[i] ==  max_length)
            {
                max_idx = i;
                break;
            }
        }
        int i = max_idx;
        ans.push_back(nums[i]);
        int pre = nums[i];
        max_length--;
        i--;
        while(i >= 0 && max_length)
        {
            if(dp[i] == max_length && pre % nums[i] == 0)
            {
                ans.push_back(nums[i]);
                pre = nums[i];
                max_length--;
            }
            i--;
        }
        return ans;
    }
};