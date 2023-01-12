class Solution {
public:
    int M=1e9+7;
    int rev(int n){
    int reverse=0,remainder;
    while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
    }
    return reverse;
    }
    int countNicePairs(vector<int>& nums) {
       int res=0;
       for(int i=0;i<nums.size();i++){
           nums[i]=nums[i]-rev(nums[i]);
       }
        unordered_map<int,int>m;
        for(auto n:nums){
            if(m.find(n)==m.end())
            m[n]=0;
            else{
            m[n]++;
            res+=m[n];
            res%=M;
            }
        }
    return res;
    }
};