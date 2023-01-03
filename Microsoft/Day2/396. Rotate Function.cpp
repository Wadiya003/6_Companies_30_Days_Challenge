class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    
        long long sum = 0,first_window = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            first_window += i*nums[i];
        }
        long long maxx = first_window;
        for(int i= n-1;i>=0;i--)
        {
            first_window += sum -(nums[i]*n);
            maxx = max(first_window,maxx);
        }
        return maxx;
    }   
};
     