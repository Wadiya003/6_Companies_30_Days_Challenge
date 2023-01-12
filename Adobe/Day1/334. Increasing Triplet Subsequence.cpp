class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         int n = nums.size();
         int first = INT_MAX;
         int second = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            //first contains the smallest first number
            if(nums[i] <= first)
            {
                first = nums[i];
            }
            //second contains the second smlaeest number
            else if(nums[i] <= second)
            {
                second = nums[i];
            }
            //if the nums[i] is neither smaller than first nor second then we found thrid              number 
            else
                return true;
        }
        
        return false;
    }
};