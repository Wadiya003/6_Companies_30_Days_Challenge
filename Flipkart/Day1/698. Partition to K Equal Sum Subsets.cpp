class Solution {
public:
    vector<bool> vis;
    bool backtrack(vector<int>&nums, int i,int n , int k , int S, int sum){
        if(i==n){
            return false;
        }
        if(k==1){
            return true;
        }
        if(sum==S){
            return backtrack(nums,0,n,k-1,0,sum);
        }
        for(int j = i; j < n; j++)
        {
            if(vis[j] == false && S+ nums[j] <= sum)
            {
                vis[j] = true;
                S+= nums[j];
                //include if true
                if(backtrack(nums, j + 1, n, k, S,sum))
                    return true;
                //backtrack
                vis[j] = false;
                S-= nums[j];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums)
        {
            sum += x;
        }
        if(sum % k)
            return false;
        sum /= k;
        vis.assign(n, false);
        return backtrack(nums, 0, n, k, 0, sum);
    }
};